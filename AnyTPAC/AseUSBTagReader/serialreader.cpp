#include "serialreader.h"

#include <QByteArray >
#include <QTime>
#include <QChar>
#include <QMutexLocker>
#include <stdio.h>

#define SYNC_COMMAND_TIMEOUT    2000
#define SEND_COMMAND_TIMEOUT    500
#define RECEIVE_COMMAND_TIMEOUT 500
#define SEND_WRITE_PAUSE        40
#define SEND_READ_PAUSE         20
#define SENDER_INTERVAL         100


// Parameters for SL2S2602 ICODE SLIX2 (see ICODE_SLIX2.pdf in doc folder)
const   char        cCR = 13;                                       // CR Char
const   int         nBytesPerBlock = 4;                             // Bytes per Block in User Area
const   int         nBitsPerBlock = 8 * nBytesPerBlock;             // Bits per Block in User Area
const   int         nMaxUserAreaBits = 2560;                        // Available Bits   in User Area
const   int         nMaxUserAreaBytes = nMaxUserAreaBits / 8;       // Available Bytes  in User Area
const   int         nMaxUserAreaBlocks = (nMaxUserAreaBytes / nBytesPerBlock) - 1;  // Available User Block (last block is reserved for Counter feature)

SerialReader::SerialReader(QString serialDevice, QObject *parent) :
    QObject(parent)
{
    myDevice = serialDevice;
    portOpen = false;
    // serialDevice = 0;
    currentTagID.clear();
    tagPresent = false;
    currentCommand = cmdNone;
    readPoint = 0;
    timerId = 0;
    myStatus = senderZero;
    lastReply.clear();
    useSyncCommands = true;
    currentTagType = 0;
    currentTagIdLen = 0;
    versionString.clear();
    comErrors = 0;
}

SerialReader::~SerialReader()
{
    // Close Device
    if (serialDevice.isOpen())  {
        serialDevice.close();
    }
}

void SerialReader::openSerialPort()
{
    serialDevice.setPortName(myDevice);
    serialDevice.setBaudRate(QSerialPort::Baud9600);
    serialDevice.setDataBits(QSerialPort::Data8);
    serialDevice.setParity(QSerialPort::NoParity);
    serialDevice.setStopBits(QSerialPort::OneStop);
    serialDevice.setFlowControl(QSerialPort::NoFlowControl);
    portOpen = serialDevice.open(QIODevice::ReadWrite);
    // connect(&serialDevice, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(this, SIGNAL(replyReady(int)), this, SLOT(parseReply(int)));
    myStatus = senderIdle;
    timerId = startTimer(SENDER_INTERVAL);

}

bool    SerialReader::sendSyncSerialCommand(QString serialCommand)
{
    // Flags to handle Send
    int     nChars2Send = serialCommand.length();
    bool    fRes = false;
    // Flags to handle Receive
    int     nCharsRead = 0;
    int     lineLength = 0;
    int     nReadLoop = 0;

    // Tries to Lock Mutex
    if (mutexCoda.tryLock(SEND_COMMAND_TIMEOUT))  {
        // Change Status to Writing
        myStatus = senderWriting;
        // Clear Device and Buffers
        serialDevice.clear();
        memset(&readerCommand[0], 0, BUF_SIZE);
        memset(&readerAnswer[0], 0, BUF_SIZE);

        // Sync Send
        strncpy(readerCommand, serialCommand.toLatin1().data(), nChars2Send);
        readerCommand[nChars2Send++] = cCR;
        watchDogTimer.start();
        qint64 written = serialDevice.write(readerCommand, nChars2Send);
        if (serialDevice.waitForBytesWritten(SEND_WRITE_PAUSE))  {
            qDebug("[%s] sendSyncSerialCommand(): Sent[%s] Chars[%d]", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data() ,readerCommand, nChars2Send);
            fRes = (written == nChars2Send);
        }
        else  {
            qCritical("[%s] sendSyncSerialCommand(): Error sending Command [%s]",
                            QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(),
                            readerCommand);
        }
        usleep(SEND_WRITE_PAUSE * 1000);

        // Sync Receive
        // Change Status to Reading
        if (fRes)  {
            fRes = false;
            myStatus = senderReading;
            if (serialDevice.waitForReadyRead(RECEIVE_COMMAND_TIMEOUT))  {
                char *p = &readerAnswer[0];
                while ((lineLength < BUF_SIZE) && ! watchDogTimer.hasExpired(SYNC_COMMAND_TIMEOUT))  {
                    nCharsRead = (int) serialDevice.read(p, BUF_SIZE);
                    p += nCharsRead;
                    lineLength += nCharsRead;
                    nReadLoop++;
                    // Condizione di uscita finale dal Loop di lettura
                    if ((lineLength > 0 && readerAnswer[lineLength - 1] == cCR) || nCharsRead < 0)  {
                        if (readerAnswer[lineLength - 1] == cCR)  {
                            readerAnswer[lineLength - 1] = 0;
                            lastReply = QString(readerAnswer);
                            fRes = true;
                        }
                        break;
                    }
                    // Sleep for some msec
                    usleep(SEND_READ_PAUSE * 1000);
                }
                // qint64 lineLength = serial->readLine(readerAnswer, BUF_SIZE);
                qDebug("[%s] sendSyncSerialCommand(): Received [%s] Chars[%d] Elapsed[%lli] ms Loops[%d]",
                                QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(),
                                readerAnswer,
                                lineLength,
                                watchDogTimer.elapsed(),
                                nReadLoop);
            }
            else  {
                qCritical("[%s] sendSyncSerialCommand(): No Answer from Reader",
                                QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data());
            }
        }
        // Unlock Mutex
        mutexCoda.unlock();
    }
    // Check final status
    if (myStatus == senderReading && fRes)  {
        // if received, run the parser
        if (currentCommand != cmdReadBlock && currentCommand != cmdWriteBlock)  {
            emit replyReady((int) currentCommand);
        }
    }
    else  {
        myStatus = senderError;
        comErrors++;
    }
    return fRes;
}

bool    SerialReader::sendAsyncSerialCommand(QString serialCommand)
{

    // Flags to handle Send
    int     nChars2Send = serialCommand.length();
    bool    fRes = false;

    // Tries to Lock Mutex
    if (mutexCoda.tryLock(SEND_COMMAND_TIMEOUT))  {
        myStatus = senderWriting;
        serialDevice.clear();
        readPoint = &readerAnswer[0];
        lineLength = 0;
        lastReply.clear();
        memset(&readerCommand[0], 0, BUF_SIZE);
        memset(&readerAnswer[0], 0, BUF_SIZE);

        strncpy(readerCommand, serialCommand.toLatin1().data(), nChars2Send);
        readerCommand[nChars2Send++] = cCR;
        watchDogTimer.restart();
        qint64 written = serialDevice.write(readerCommand, nChars2Send);
        serialDevice.waitForBytesWritten(SEND_WRITE_PAUSE);
        qDebug("[%s] sendAsyncSerialCommand(): Sent[%s] Chars[%d]", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data() ,readerCommand, nChars2Send);
        if (written == nChars2Send)  {
            myStatus = senderReading;
            fRes = true;
        }
        else if (written < 0)  {
            myStatus = senderError;
            comErrors++;
        }
        // Unlock Mutex
        mutexCoda.unlock();
    }
    return fRes;
}

void    SerialReader::readData()
{

    int     nCharsRead = 0;
    if ((lineLength < BUF_SIZE) && ! watchDogTimer.hasExpired(SEND_COMMAND_TIMEOUT)) {
        if (serialDevice.waitForReadyRead(SEND_READ_PAUSE))  {
            nCharsRead = (int) serialDevice.read(readPoint, BUF_SIZE);
            fprintf(stderr, "R:[%d]", lineLength);
            if (nCharsRead > 0)  {
                readPoint += nCharsRead;
                lineLength += nCharsRead;
                if (lineLength > 0 && readerAnswer[lineLength - 1] == cCR)  {

                    readerAnswer[lineLength - 1] = 0;
                    lastReply = QString(readerAnswer);
                    emit replyReady((int) currentCommand);
                    currentCommand = cmdNone;
                }
            }
        }
    }
}

bool    SerialReader::isOpen()
{
    return (portOpen && serialDevice.isOpen());
}

bool    SerialReader::sendReaderCommand(enum commandReader commandType, QString myCommand)
// send Command to Reader
{
    bool        fRes = false;
    currentCommand = commandType;
    if (useSyncCommands)  {
        fRes = sendSyncSerialCommand(myCommand);
    }
    else  {
        fRes = sendAsyncSerialCommand(myCommand);
    }
    return fRes;
}

void    SerialReader::parseReply(int commandPending)
{
    QString     recTime = QTime::currentTime().toString("HH:mm:ss.zzz");
    qint64      replyTime = watchDogTimer.isValid() ? watchDogTimer.elapsed() : 0;
    QString     currentAnswer(readerAnswer);
    bool        commandCorrect = currentAnswer.left(2) == "00";
    bool        commandOk = currentAnswer.mid(2, 2) == "01";
    enum senderStates   newStatus = senderError;

    myStatus = senderParsing;
    watchDogTimer.invalidate();
    qDebug("[%s] parseReply(): Elapsed:[%lli] Command:[%s] Reply:[%s] Correct:[%d] Ok:[%d]",
                        recTime.toLatin1().data(),
                        replyTime,
                        getCommandDesc((enum commandReader) commandPending).toLatin1().data(),
                        readerAnswer,
                        commandCorrect,
                        commandOk
           );

    // Parsing reply
    switch (commandPending) {
    case cmdGetVersion:
        currentCommand = cmdNone;
        if (commandCorrect)  {
            if (currentAnswer.length() > 2)  {
                if (parseReaderString(currentAnswer.mid(2), versionString))  {
                    newStatus = senderSetTagFilter;
                }
            }
            else  {
                newStatus = senderGetVersion;
            }
        }
        else  {
            newStatus = senderGetVersion;
        }
        break;

    case cmdSetTagFilter:
        if (commandCorrect)  {
            qDebug("[%s] parseReply(): Set Tag Filter, switch to senderWaiting",
                            recTime.toLatin1().data());
            newStatus = senderWaiting;
        }
        else  {
            currentCommand = cmdNone;
            newStatus = senderSetTagFilter;
        }
        break;

    case cmdSearchTags:
        if (commandCorrect)  {
            if (currentAnswer.mid(2, 2) == "00")  {
                // No Tag
                tagPresent = false;
                currentTagID.clear();
                currentTagType = 0;
                currentTagIdLen = 0;
                currentTagIdBits = 0;
            }
            else  if (commandOk) {
                // Parse Tag Type
                tagPresent = parseTagID(currentAnswer.mid(4), currentTagType, currentTagIdBits, currentTagIdLen, currentTagID);
            }
            newStatus = senderWaiting;
        }
        break;

    case cmdReadBlock:
        break;

    case cmdWriteBlock:
        break;

    case cmdNone:
    default:
        qCritical("[%s] parseReply(): Command:[%d] not parsed, Reply:[%s]",
                            recTime.toLatin1().data(),
                            commandPending,
                            readerAnswer);
    }
    myStatus = newStatus;
}

bool  SerialReader::parseTagID(QString tagString, uint &tagType, uint &tagIdbits, uint &tagLen, QString &tagID)
{
    bool    isOk = false;

    tagID.clear();

    // Tag Type
    tagType = tagString.left(2).toUInt(&isOk, 16);
    // Tag Bits
    tagIdbits = tagString.mid(2, 2).toUInt(&isOk, 16);
    // Len Id
    tagLen = tagString.mid(4, 2).toUInt(&isOk, 16);
    // Tag ID
    int nLen = tagLen * 2;
    tagID = tagString.mid(6, nLen);
    qDebug("parseTagID: TagType:[0x%X] Tag Bits:[0x%X] Id Len:[%d] Tag ID:[%s]", tagType, tagIdbits, tagLen, tagID.toLatin1().data());
    return isOk;
}

bool  SerialReader::parseReaderString(QString readerString, QString &userString)
{
    bool    isOk = false;
    QString byteString;

    bool    okLen = false;
    uint    userLen;

    // Decode String Length
    userLen = readerString.left(2).toUInt(&okLen, 16);
    // Clear User String
    userString.clear();
    // Compose User String
    if (okLen)  {
        for (uint nChar = 0; nChar < userLen; nChar++)  {
            byteString = readerString.mid(( 2 + (nChar * 2)), 2);
            uint    uChar;
            uChar = byteString.toUInt(&isOk, 16);
            if (isOk)  {
                userString.append(QChar(uChar));
            }
        }
    }
    qDebug("parseReaderString: Len:[%u] Version:[%s]", userLen, userString.toLatin1().data());

    return isOk;
}


void SerialReader::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    if (myStatus == senderIdle)  {
        myStatus = senderGetVersion;
        currentCommand = cmdNone;
    }
    else if (myStatus == senderGetVersion)  {
        if (currentCommand == cmdNone)  {
            if (sendReaderCommand(cmdGetVersion, "0004FF"))  {
                qDebug("[%s] SerialReader::timerEvent(): Get Version Ok",
                       QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data());
            }
            else  {
                currentCommand = cmdNone;
            }
        }
    }
    else if (myStatus == senderSetTagFilter)  {
        if (currentCommand == cmdNone)  {
            if (sendReaderCommand(cmdSetTagFilter, "05020000000005000000"))  {
                qDebug("[%s] SerialReader::timerEvent(): Set Tag Filter Ok",
                       QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data());
            }
            else  {
                currentCommand = cmdNone;
            }
        }
    }
    else if (myStatus == senderError)  {
        // How to Reset Error ?
        qWarning("[%s] SerialReader::timerEvent(): Transition from Error to Waiting!",
                            QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data());
        if (currentCommand == cmdSetTagFilter)  {
            currentCommand = cmdNone;
            myStatus = senderSetTagFilter;
        }
        else  if (currentCommand == cmdGetVersion) {
            currentCommand = cmdNone;
            myStatus = senderGetVersion;
        }
        else  {
            myStatus = senderWaiting;
        }
    }
    if (useSyncCommands)  {
        return;
    }
    // QMutexLocker locker(&mutexCoda);

    if (myStatus == senderReading)  {
        fprintf(stderr, "*");
        readData();
    }
}

bool        SerialReader::readTagBlock(int currentBlock, char *buffer)
{
    QString readerCommand = QString("0D05%100") .arg(currentBlock, 2, 16);

    QChar ch;

    for (int nByte = 0; nByte < nBytesPerBlock; nByte++)  {
        // TO DO: Split of command
    }
    currentCommand = cmdReadBlock;

}

bool        SerialReader::writeTagBlock(int currentBlock, char *buffer)
{
    currentCommand = cmdWriteBlock;

}

//------------------------------------------------------------
// SerialReader exported public commands
//------------------------------------------------------------
bool        SerialReader::searchTag()
// Search Tag near reader
{
    return sendReaderCommand(SerialReader::cmdSearchTags, "050010");
}

bool        SerialReader::readTagMemory(char *userArea, int nBytes)
// Read User Memory Area of Current Tag
{
    bool    fRes = false;
    int     nBlock = 0;
    int     nBlocks = nBytes / nBytesPerBlock;
    int     nErrors = 0;
    char    localBuffer[nMaxUserAreaBytes];
    char    *p;

    // Check Size
    if (nBlocks > nMaxUserAreaBlocks)  {
        qCritical("readTagMemory(): Size of the User Area exceeds the space available on Tag: Requested [%d]B vs Available [%d]",
                            nBytes,
                            nMaxUserAreaBlocks * nBytesPerBlock);
        goto exitReadTag;
    }
    // Clear Buffer
    p = &localBuffer[0];;
    memset(p, 0, nMaxUserAreaBytes);
    // Reading Loop
    nBlock = 0;
    while (nBlock < nBlocks)  {
        fRes = readTagBlock(nBlock, p);
        if (fRes)  {
            nBlock++;
            p += (nBlock * nBytesPerBlock);
        }
        else  {
            ++nErrors;
        }
    }
    // All ok, copy of the read data on the user area
    if (fRes)  {
        memcpy(userArea, localBuffer, nBytes);
    }

exitReadTag:
    return fRes;
}

bool        SerialReader::writeTagMemory(char *userArea, int nBytes)
// Write User Memory Area of Current Tag
{
    bool    fRes = false;
    int     nBlock = 0;
    int     nBlocks = nBytes / nBytesPerBlock;
    char    *p;

    p = userArea;
    for (nBlock = 0; nBlock < nBlocks; nBlock++)  {
        p += (nBlock * nBytesPerBlock);
    }
    return fRes;
}

