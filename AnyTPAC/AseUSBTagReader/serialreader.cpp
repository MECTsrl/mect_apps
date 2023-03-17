#include "serialreader.h"

#include <QByteArray >
#include <QTime>
#include <QChar>
#include <QLatin1Char>
#include <QMutexLocker>
#include <stdio.h>

#define SYNC_COMMAND_TIMEOUT    2000
#define SEND_COMMAND_TIMEOUT    500
#define RECEIVE_COMMAND_TIMEOUT 500
#define SEND_WRITE_PAUSE        40
#define SEND_READ_PAUSE         20
#define SENDER_INTERVAL         100
#define MAX_IDLE_TIME           2000
#define MAX_READ_ERRORS         10
#define MAX_WRITE_ERRORS        20

// Info for qDebug
#define LOG_STRING      "[%s] %s(%d):\t"
#define LOG_POINT       QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(), __func__, __LINE__



// Parameters for SL2S2602 ICODE SLIX2 (see ICODE_SLIX2.pdf in doc folder)
const   char    cCR = 13;                                               // CR Char
const   int     nBytesPerPage = 4;                                      // Bytes per Page in User Area (both Tag Types)
const   int     nBitsPerPage = 8 * nBytesPerPage;                       // Bits per Page in User Area
// ISO 15693 SLI-X Blocks
const   int     nMax_15693_UserAreaBits = 2560;                         // Available Bits   in User Area for ISO 15693 SLI-X
const   int     nMax_15693_UserAreaBytes = nMax_15693_UserAreaBits / 8; // Available Bytes  in User Area for ISO 15693 SLI-X = 320
const   int     nMax_15693_UserAreaBlocks = (nMax_15693_UserAreaBytes / nBytesPerPage) - 1;  // Available User Block for ISO 15693 SLI-X = 79 (last block is reserved for Counter feature)
// ISO 14443A / MIFARE NTAG213
const   int     nMax_MIFARE_UserAreaBytes = 144;                        // Available Bytes  in User Area for MIFARE NTAG213
const   int     nMax_MIFARE_UserAreaPages = 36;                         // Available Pages in User Area for MIFARE NTAG213
const   int     n_MIFARE_FirstPage = 4;                                 // First writable page for MIFARE NTAG213

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
    blockStringValue.clear();
    defBlockSizeString = QString("%1") .arg(nBytesPerPage, 2, 16, QLatin1Char('0')).toUpper();
    parseReplyOk = false;
    readerIsReading = false;
    readerIsWriting = false;
    crcEnabled = false;
    tagPollingms = MAX_IDLE_TIME;
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
    sleep(1);
    connect(&serialDevice, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(this, SIGNAL(replyReady(int)), this, SLOT(parseReply(int)));
    sleep(1);
    changeStatus(senderIdle);
    timerId = startTimer(SENDER_INTERVAL);

}

void    SerialReader::clearBuffers()
{
    serialDevice.clear();
    readPoint = &readerAnswer[0];
    memset(&readerCommand[0], 0, BUF_SIZE);
    memset(&readerAnswer[0], 0, BUF_SIZE);
    lineLength = 0;
    lastReply.clear();
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
        // Mark current command as Sync Command
        syncCommand = true;
        // Change Status to Writing
        changeStatus(senderWriting);
        // Sync Send
        memcpy(readerCommand,  serialCommand.toLatin1().data(), nChars2Send);
        readerCommand[nChars2Send++] = cCR;
        watchDogTimer.start();
        qint64 written = serialDevice.write((char *) readerCommand, nChars2Send);
        if (serialDevice.waitForBytesWritten(SEND_WRITE_PAUSE))  {
            qDebug(LOG_STRING"Sent[%s] Chars[%d]", LOG_POINT,readerCommand, nChars2Send);
            fRes = (written == nChars2Send);
        }
        else  {
            qCritical(LOG_STRING"Error sending Command [%s]", LOG_POINT, readerCommand);
        }
        usleep(SEND_WRITE_PAUSE * 1000);

        // Sync Receive
        // Change Status to Reading
        if (fRes)  {
            fRes = false;
            changeStatus(senderReading);
            if (serialDevice.waitForReadyRead(RECEIVE_COMMAND_TIMEOUT))  {
                unsigned char *p = &readerAnswer[0];
                while ((lineLength < BUF_SIZE) && ! watchDogTimer.hasExpired(SYNC_COMMAND_TIMEOUT))  {
                    nCharsRead = (int) serialDevice.read((char *)p, BUF_SIZE);
                    p += nCharsRead;
                    lineLength += nCharsRead;
                    nReadLoop++;
                    // Condizione di uscita finale dal Loop di lettura
                    if ((lineLength > 0 && readerAnswer[lineLength - 1] == cCR) || nCharsRead < 0)  {
                        if (readerAnswer[lineLength - 1] == cCR)  {
                            readerAnswer[lineLength - 1] = 0;
                            lastReply = QString((char *)readerAnswer);
                            fRes = true;
                        }
                        break;
                    }
                    // Sleep for some msec
                    usleep(SEND_READ_PAUSE * 1000);
                }
                // qint64 lineLength = serial->readLine(readerAnswer, BUF_SIZE);
                qDebug(LOG_STRING"Received [%s] Chars[%d] Elapsed[%lli] ms Loops[%d]",
                                LOG_POINT,
                                readerAnswer,
                                lineLength,
                                watchDogTimer.elapsed(),
                                nReadLoop);
            }
            else  {
                qCritical(LOG_STRING"No Answer from Reader", LOG_POINT);
            }
        }
        // Unlock Mutex
        mutexCoda.unlock();
    }
    // Check final status
    if (myStatus == senderReading && fRes)  {
        // if received, run the parser Async
        if (currentCommand != cmdReadBlock && currentCommand != cmdWriteBlock)  {
            emit replyReady((int) currentCommand);
        }
    }
    else  {
        changeStatus(senderError);
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
        // Mark current command as Async Command
        syncCommand = false;
        changeStatus(senderWriting);
        memcpy(readerCommand, serialCommand.toLatin1().data(), nChars2Send);
        readerCommand[nChars2Send++] = cCR;
        watchDogTimer.restart();
        qint64 written = serialDevice.write((char *)readerCommand, nChars2Send);
        serialDevice.waitForBytesWritten(SEND_WRITE_PAUSE);
        qDebug(LOG_STRING"Sent[%s] Chars[%d]", LOG_POINT, readerCommand, nChars2Send);
        if (written == nChars2Send)  {
            changeStatus(senderReading);
            fRes = true;
        }
        else if (written < 0)  {
            changeStatus(senderError);
        }
        // Unlock Mutex
        mutexCoda.unlock();
    }
    return fRes;
}

void    SerialReader::readData()
{

    qint64      nReadyChars = serialDevice.bytesAvailable();
    qint64      nCharsRead = 0;

    if (syncCommand)  {
        // If sync Command do nothing
        return;
    }
    // Some data to read and a async command is pending
    if (nReadyChars && currentCommand != cmdNone)  {
        qDebug(LOG_STRING"Bytes Available: [%lli]", LOG_POINT, nReadyChars);

        if ((lineLength < BUF_SIZE) && ! watchDogTimer.hasExpired(SEND_COMMAND_TIMEOUT)) {
            nCharsRead = serialDevice.read((char *) readPoint, nReadyChars);
            if (nCharsRead > 0)  {
                readPoint += (int) nCharsRead;
                lineLength += (int) nCharsRead;
                if (lineLength > 0 && readerAnswer[lineLength - 1] == cCR)  {
                    // answer complete from reader, remove CR
                    readerAnswer[lineLength - 1] = 0;
                    lastReply = QString((char *) readerAnswer);
                    emit replyReady((int) currentCommand);
                    currentCommand = cmdNone;
                }
            }
        }
        else {
            // Abort Command
            changeStatus(senderError);
        }
    }
    return;
}

bool    SerialReader::isOpen()
{
    return (portOpen && serialDevice.isOpen());
}

bool    SerialReader::sendReaderCommand(enum commandReader commandType, QString myCommand, bool sendSync)
// send Command to Reader
{
    bool        fRes = false;
    currentCommand = commandType;
    idleTimer.invalidate();
    if (sendSync)  {
        fRes = sendSyncSerialCommand(myCommand);
    }
    else  {
        fRes = sendAsyncSerialCommand(myCommand);
    }
    return fRes;
}

void    SerialReader::parseReply(int commandPending)
{
    qint64      replyTime = watchDogTimer.isValid() ? watchDogTimer.elapsed() : 0;
    QString     currentAnswer((char *)readerAnswer);
    bool        commandCorrect = currentAnswer.left(2) == "00";
    bool        commandOk = currentAnswer.mid(2, 2) == "01";
    enum senderStates   newStatus = senderError;

    changeStatus(senderParsing);
    qDebug(LOG_STRING"Elapsed:[%lli] Command:[%s] Reply:[%s] Correct:[%d] Ok:[%d]",
                        LOG_POINT,
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
                    parseReplyOk = true;
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
            qDebug(LOG_STRING"Set Tag Filter, switch to senderWaiting", LOG_POINT);
            parseReplyOk = true;
            newStatus = senderWaitingCommand;
        }
        else  {
            currentCommand = cmdNone;
            newStatus = senderSetTagFilter;
        }
        break;

    case cmdSearchTags:
        if (commandCorrect)  {
            parseReplyOk = true;
            if (currentAnswer.mid(2, 2) == "00")  {
                // No Tag
                tagPresent = false;
                currentTagID.clear();
                currentTagType = 0;
                currentTagIdLen = 0;
                currentTagIdBits = 0;
                emit noTag();
            }
            else  if (commandOk) {
                // Parse Tag Type
                QString previousTagId = currentTagID;
                tagPresent = parseTagID(currentAnswer.mid(4), currentTagType, currentTagIdBits, currentTagIdLen, currentTagID);
                // Signal new target only if different from previous
                if (currentTagID != previousTagId)  {
                    emit tagFound(currentTagID);
                }
            }
            newStatus = senderWaitingCommand;
        }
        break;

    case cmdReadPages:
        if (commandCorrect && commandOk)  {
            parseReplyOk = true;
        }
        // Stay in reading
        newStatus = senderReading;
        break;

    case cmdReadBlock:
        if (commandCorrect && commandOk)  {
            // Blocks are read 4 bytes a time ---> 8 Chars
            if (currentAnswer.mid(4, 2) == defBlockSizeString)  {
                parseReplyOk = true;
                blockStringValue = currentAnswer.mid(6, (2 * nBytesPerPage));
            }
        }
        // Stay in reading
        newStatus = senderReading;
        break;

    case cmdWriteBlock:
        if (commandCorrect && commandOk)  {
            parseReplyOk = true;
        }
        break;

    case cmdNone:
    default:
        qCritical(LOG_STRING"Command:[%d] not parsed, Reply:[%s]",
                            LOG_POINT,
                            commandPending,
                            readerAnswer);
    }
    // Change Status if needed
    if (myStatus != newStatus)  {
        changeStatus(newStatus);
    }
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
    qDebug(LOG_STRING"TagType:[0x%X] Tag Bits:[0x%X] Id Len:[%d] Tag ID:[%s]", LOG_POINT, tagType, tagIdbits, tagLen, tagID.toLatin1().data());
    return isOk;
}

bool  SerialReader::parseReaderString(QString readerString, QString &userString)
{
    bool    okLen = false;
    uint    userLen;

    // Decode String Length
    userLen = readerString.left(2).toUInt(&okLen, 16);
    // Clear User String
    userString.clear();
    // Compose User String
    if (okLen)  {
        unsigned char localBuffer[BUF_SIZE];
        memset(localBuffer, 0, BUF_SIZE);
        readerString2Bytes(readerString.mid(2), &localBuffer[0], userLen);
        userString = QString((char *) localBuffer);
    }
    qDebug(LOG_STRING"Len:[%u] Ok: [%d] Version:[%s]", LOG_POINT, userLen, okLen, userString.toLatin1().data());
    return okLen;
}


void SerialReader::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    // qDebug(LOG_STRING"Status: [%s]", LOG_POINT, getStatusDesc(myStatus).toLatin1().data());

    // Initial state of the reader after opening Serial Device
    if (myStatus == senderIdle)  {
        changeStatus(senderGetVersion);
    }
    // Request for firmware version to verify communication
    else if (myStatus == senderGetVersion)  {
        if (currentCommand == cmdNone)  {
            // This command is syncronuos to trap Send Errors
            if (sendReaderCommand(cmdGetVersion, "0004FF", true))  {
                qDebug(LOG_STRING"Get Version Ok", LOG_POINT);
            }
            else  {
                // Try Again
                currentCommand = cmdNone;
            }
        }
    }
    // Setting the Filter on the type of Tag to search for (MIFARE and ISO15693 only)
    else if (myStatus == senderSetTagFilter)  {
        if (currentCommand == cmdNone)  {
            //            tagFilter |= NO_LF;                         // 0x00000000
            //            tagFilter |= TAGMASK(HFTAG_MIFARE);         // 0x01
            //            tagFilter |= TAGMASK(HFTAG_ISO15693);       // 0x04
            // Tag Filter for: NO LF + HF: HFTAG_MIFARE + HFTAG_ISO15693
            if (sendReaderCommand(cmdSetTagFilter, "05020000000005000000", true))  {
                qDebug(LOG_STRING"Set Tag Filter Ok", LOG_POINT);
            }
            else  {
                currentCommand = cmdNone;
            }
        }
    }
    // Reader is Idle, switch to Tag Searching is MAX_IDLE_TIME has expired
    else if (myStatus == senderWaitingCommand)  {
        // Check idleTimer to start new searchTag
        if (idleTimer.isValid())  {
            if (idleTimer.hasExpired(tagPollingms) && not isBusy())  {
                searchTag();
            }
        }
        else  {
            idleTimer.restart();
        }
    }
    // Parsing in progress, do nothing
    else if (myStatus == senderParsing)  {
        // Do Nothing
    }
    else if (myStatus == senderParseOk)   {
        // Switch to Next Command or Idle State
    }
    else if (myStatus == senderParseFail)  {
        // Handle Error
    }
    // Error sending command to reader, Try again
    else if (myStatus == senderError)  {
        // How to Reset Error ?
        qWarning(LOG_STRING"Transition from Error to Waiting!", LOG_POINT);
        if (currentCommand == cmdSetTagFilter)  {
            currentCommand = cmdNone;
            changeStatus(senderSetTagFilter);
        }
        else  if (currentCommand == cmdGetVersion) {
            currentCommand = cmdNone;
            changeStatus(senderGetVersion);
        }
        else  {
            changeStatus(senderWaitingCommand);
        }
    }
}

void    SerialReader::changeStatus(enum senderStates newStatus)
{
    // TODO: Refine checks
    // Controls for current status
    switch (myStatus) {
    case senderZero:
        currentCommand = cmdNone;
        break;

    case senderIdle:
        break;

    case senderGetVersion:
        break;

    case senderSetTagFilter:
        break;

    case senderWaitingCommand:

    case senderWriting:
        break;

    case senderReading:
        break;

    case senderParsing:
        break;

    case senderParseOk:
        break;

    case senderParseFail:
        break;

    case senderError:
        break;

    default:
        break;
    }
    // Controls for destination status
    switch (newStatus) {
    case senderZero:
        break;

    case senderIdle:
        break;

    case senderGetVersion:
        currentCommand = cmdNone;
        break;

    case senderSetTagFilter:
        currentCommand = cmdNone;
        break;

    case senderWaitingCommand:
        idleTimer.restart();
        break;

    case senderWriting:
        // Clear Device and Buffers
        clearBuffers();
        break;

    case senderReading:
        break;

    case senderParsing:
        parseReplyOk = false;
        watchDogTimer.invalidate();
        blockStringValue.clear();
        break;

    case senderParseOk:
        break;

    case senderParseFail:
    case senderError:
        qWarning(LOG_STRING"Transition from [%s] to [%s]",
                        LOG_POINT,
                        getStatusDesc(myStatus).toLatin1().data(),
                        getStatusDesc(newStatus).toLatin1().data());
        comErrors++;
        // Clear Device and Buffers
        clearBuffers();
        break;

    default:
        break;
    }
    // Finally Change Status
    myStatus = newStatus;
}

QString     SerialReader::bytes2readerString(unsigned char *buffer, int nBytes)
{
    QString readerString;

    for (int nByte = 0; nByte < nBytes; nByte++)  {
        unsigned char uChar = *buffer;
        readerString.append((QString("%1") .arg((int) uChar, 2, 16, QLatin1Char('0'))).toUpper());
        buffer++;
    }
    return readerString;
}

void        SerialReader::readerString2Bytes(QString readerString, unsigned char *buffer, uint userLen)
{
    bool            isOk = false;
    unsigned char   *p;
    unsigned char   uChar;
    QString         byteString;

    p = buffer;
    for (uint nChar = 0; nChar < userLen; nChar++)  {
        byteString = readerString.mid((nChar * 2), 2);
        uChar = (unsigned char) byteString.toUInt(&isOk, 16);
        if (isOk)  {
            *p = uChar;
        }
        else  {
            *p = 0;
        }
        p++;
    }
}

u_int16_t SerialReader::updateCRC(u_int16_t CRC, unsigned char Byte)
{
    // Update CCITT CRC (reverse polynom 0x8408)
    Byte ^= (unsigned char) CRC;
    Byte ^= (unsigned char)(Byte << 4);
    return  (u_int16_t) (((Byte << 8) | (CRC >> 8)) ^ (Byte >> 4) ^ (Byte << 3));
}

bool        SerialReader::read_15693_Block(int currentBlock, QString &dataBuffer)
{
    bool        fRes = false;
    QString     blockNumber = QString("%1") .arg(currentBlock, 2, 16, QLatin1Char('0')).toUpper();
    QString     readBlockCommand = QString("0D05%1FF") .arg(blockNumber);

    currentCommand = cmdReadBlock;
    if (sendSyncSerialCommand(readBlockCommand))  {
        parseReply(cmdReadBlock);
        if (parseReplyOk && blockStringValue.length() == (2 * nBytesPerPage))  {
            dataBuffer.append(blockStringValue);
            fRes = true;
        }
        qDebug(LOG_STRING"Current Block:[%d] Block Value:[%s] Ok:[%d]", LOG_POINT,
                    currentBlock, blockStringValue.toLatin1().data(), fRes);
    }
    return fRes;
}

bool        SerialReader::read_MIFARE_Pages(int nStartPage, int nPages, QString &dataBuffer)
{
    bool        fRes = false;
    QString     startPage = QString("%1") .arg(nStartPage, 2, 16, QLatin1Char('0')).toUpper();
    QString     numPages  = QString("%1") .arg(nPages, 2, 16, QLatin1Char('0')).toUpper();
    QString     readPagesCommand = QString("0C05%1%2") .arg(startPage) .arg(numPages);

    currentCommand = cmdReadPages;
    if (sendSyncSerialCommand(readPagesCommand ))  {
        parseReply(cmdReadPages);
        if (parseReplyOk)  {
            dataBuffer = lastReply.mid(4);
            fRes = true;
        }
        qDebug(LOG_STRING"Start Page:[%d] Pages[%d] Block Value:[%s] Ok:[%d]", LOG_POINT,
                    nStartPage, nPages, dataBuffer.toLatin1().data(), fRes);
    }
    return fRes;
    return fRes;
}

bool        SerialReader::write_MIFARE_Page(int nPage, const QString &block2Write)
{
    bool        fRes = false;
    QString     numPage = QString("%1") .arg(nPage, 2, 16, QLatin1Char('0')).toUpper();
    QString     writePageCommand = QString("0C01%1%2") .arg(numPage) .arg(block2Write);

    currentCommand = cmdWriteBlock;
    if (sendSyncSerialCommand(writePageCommand))  {
        parseReply(cmdWriteBlock);
        if (parseReplyOk)  {
            fRes = true;
        }
        qDebug(LOG_STRING"Current Page:[%d] Block Value:[%s] Ok:[%d]", LOG_POINT,
                            nPage, block2Write.toLatin1().data(), fRes);
    }
    return fRes;
}

bool        SerialReader::write_15693_Block(int currentBlock, const QString &block2Write)
{
    bool        fRes = false;
    QString     blockNumber = QString("%1") .arg(currentBlock, 2, 16, QLatin1Char('0')).toUpper();
    QString     writeBlockCommand = QString("0D07%1%2%3") .arg(blockNumber) .arg(defBlockSizeString) .arg(block2Write);

    currentCommand = cmdWriteBlock;
    if (sendSyncSerialCommand(writeBlockCommand))  {
        parseReply(cmdWriteBlock);
        if (parseReplyOk)  {
            fRes = true;
        }
        qDebug(LOG_STRING"Current Block:[%d] Block Value:[%s] Ok:[%d]", LOG_POINT,
                            currentBlock, block2Write.toLatin1().data(), fRes);
    }
    return fRes;
}

//------------------------------------------------------------
// SerialReader exported public commands
//------------------------------------------------------------
u_int16_t   SerialReader::calculateCRC(unsigned char *userArea, int nBytes)
// Computes the CRC of a byte buffer, one byte at a time
{
    unsigned char *p = 0;
    u_int16_t   finalCRC = 0xFFFF;
    p = userArea;

    for (int nChar = 0; nChar < nBytes; nChar++)  {
        unsigned char uChar =  *p;
        finalCRC = updateCRC(finalCRC, uChar);
        p++;
    }
    return finalCRC;
}

bool        SerialReader::searchTag()
// Search Tag near reader
{
    return sendReaderCommand(SerialReader::cmdSearchTags, "050010", false);
}

bool        SerialReader::readTagMemory(unsigned char *userArea, int nBytes)
// Read User Memory Area of Current Tag
{
    bool            fRes = false;
    int             nBlock = 0;
    int             nBlocks = 0;
    int             nErrors = 0;
    unsigned char   localBuffer[nMax_15693_UserAreaBytes];
    QString         localString;
    unsigned char   *p;
    u_int16_t       localCRC = 0;
    u_int16_t       remoteCRC = 0;
    int             nMaxBlocks = currentTagType == HFTAG_MIFARE ? nMax_MIFARE_UserAreaPages : nMax_15693_UserAreaBlocks;

    // Check Size
    if (crcEnabled)  {
        nBytes += sizeof(remoteCRC);
    }
    else {
        localCRC = 0;
    }
    nBlocks = (nBytes + nBytesPerPage - 1) / nBytesPerPage;       // Ceil Round-Up...
    if (nBlocks > nMaxBlocks || nBytes <= 0)  {
        qCritical(LOG_STRING"Size of the User Area exceeds the space available on Tag: Requested [%d]B vs Available [%d]",
                            LOG_POINT,
                            nBytes,
                            nMaxBlocks * nBytesPerPage);
        goto exitReadTag;
    }
    // Used to Stop Tag Polling
    readerIsReading = true;
    // Clear Buffer
    p = &localBuffer[0];
    memset(p, 0, nMax_15693_UserAreaBytes);
    localString.clear();
    if (currentTagType == HFTAG_MIFARE)  {
        // Read HFTAG_MIFARE User Pages
        currentCommand = cmdReadPages;
        while (nErrors < MAX_READ_ERRORS)  {
            fRes = read_MIFARE_Pages(n_MIFARE_FirstPage, nBlocks, localString);
            if (fRes)  {
                break;
            }
            else  {
                ++nErrors;
                // Pause
                usleep(SEND_WRITE_PAUSE * 1000);
            }
        }
    }
    else if (currentTagType == HFTAG_ISO15693)  {
        // Read HFTAG_ISO15693 User Pages
        currentCommand = cmdReadBlock;
        nBlock = 0;
        while (nBlock < nBlocks && nErrors < MAX_READ_ERRORS)  {
            fRes = read_15693_Block(nBlock, localString);
            if (fRes)  {
                nBlock++;
            }
            else  {
                ++nErrors;
            }
            // Pause
            usleep(SEND_WRITE_PAUSE * 1000);
        }
    }
    // All ok, copy of the read data on the user area
    if (fRes)  {
        // Decode localString
        memcpy(userArea, localBuffer, nBytes);
        qDebug(LOG_STRING"Copied [%d]bytes. Last Block:[%d/%d] Errors:[%d]", LOG_POINT, nBytes, nBlock, nBlocks, nErrors);
    }
    else {
        qCritical(LOG_STRING"Error Reading User Area. Last Block:[%d] Errors:[%d]", LOG_POINT, nBlock, nErrors);
    }

exitReadTag:
    currentCommand = cmdNone;
    readerIsReading = false;
    changeStatus(senderWaitingCommand);
    emit tagMemoryRead(fRes);
    return fRes;
}

bool        SerialReader::writeTagMemory(unsigned char *userArea, int nBytes)
// Write User Memory Area of Current Tag
{
    bool            fRes = false;
    int             nBlock = 0;
    int             nBlocks2Write = 0;
    int             nTotalBytes = 0;
    int             nErrors = 0;
    int             nMaxBlocks = currentTagType == HFTAG_MIFARE ? nMax_MIFARE_UserAreaPages : nMax_15693_UserAreaBlocks;
    int             nStart = 0;
    u_int16_t       localCRC = 0;
    QString         data2Write = bytes2readerString(userArea, nBytes);
    QString         crcString;
    QString         szFiller;
    QString         blockStringValue;


    // Calculate CRC
    if (crcEnabled)  {
        localCRC = calculateCRC(userArea, nBytes);
        u_int16_t  lsbCRC = (localCRC & 0xFF);              // lsb
        u_int16_t  msbCRC =  ((localCRC >> 8) & 0xFF);      // msb
        crcString.append((QString("%1") .arg(lsbCRC, 2, 16, QLatin1Char('0'))).toUpper());
        crcString.append((QString("%1") .arg(msbCRC, 2, 16, QLatin1Char('0'))).toUpper());
        qDebug(LOG_STRING"CRC: [%X] lsb:[%X] msb:[%X] str:[%s]", LOG_POINT, localCRC, lsbCRC, msbCRC, crcString.toLatin1().data());
        data2Write.append(crcString);
        nBytes += sizeof(localCRC);
    }
    else {
        localCRC = 0;
    }
    // Check Size
    nBlocks2Write = (nBytes + nBytesPerPage - 1) / nBytesPerPage;       // Ceil Round-Up...
    if (nBlocks2Write > nMaxBlocks || nBytes <= 0)  {
        qCritical(LOG_STRING"Size of the User Area exceeds the space available on Tag: Requested [%d]B vs Available [%d]",
                            LOG_POINT,
                            nBytes,
                            nMaxBlocks * nBytesPerPage);
        goto exitWriteTag;
    }
    // Add Filler to Page Size
    nTotalBytes = (nBlocks2Write * nBytesPerPage);
    if (nBytes < nTotalBytes)  {
        szFiller.fill('0', 2 * (nTotalBytes - nBytes));
        data2Write.append(szFiller);
    }
    // Used to Stop Tag Polling
    readerIsWriting = true;
    currentCommand = cmdWriteBlock;
    nBlock = 0;
    if (currentTagType == HFTAG_MIFARE)  {
        // MIFARE Writing Loop
        while (nBlock < nBlocks2Write && nErrors < MAX_WRITE_ERRORS)  {
            blockStringValue = data2Write.mid(nStart, 2 * nBytesPerPage);
            fRes = write_MIFARE_Page(n_MIFARE_FirstPage + nBlock, blockStringValue);
            if (fRes)  {
                nBlock++;
                nStart += (2 * nBytesPerPage);
            }
            else  {
                nErrors++;
            }
            // Pause
            usleep(SEND_WRITE_PAUSE * 1000);
        }
    }
    else if (currentTagType == HFTAG_ISO15693)  {
        // ISO15693 Writing Loop
        while (nBlock < nBlocks2Write && nErrors < MAX_WRITE_ERRORS)  {
            blockStringValue = data2Write.mid(nStart, 2 * nBytesPerPage);
            fRes = write_15693_Block(nBlock, blockStringValue);
            if (fRes)  {
                nBlock++;
                nStart += (2 * nBytesPerPage);
            }
            else  {
                ++nErrors;
            }
            // Pause
            usleep(SEND_WRITE_PAUSE * 1000);
        }
    }
    // All ok, copy of the read data on the user area
    if (fRes)  {
        qDebug(LOG_STRING"Written [%d]bytes. Last Block:[%d/%d] Errors:[%d]", LOG_POINT, nBytes, nBlock, nBlocks2Write, nErrors);
    }
    else {
        qCritical(LOG_STRING"Error Writing User Area. Last Block:[%d] Errors:[%d]", LOG_POINT, nBlock, nErrors);
    }

exitWriteTag:
    currentCommand = cmdNone;
    readerIsWriting = false;
    changeStatus(senderWaitingCommand);
    emit tagMemoryWrite(fRes);
    return fRes;
}

