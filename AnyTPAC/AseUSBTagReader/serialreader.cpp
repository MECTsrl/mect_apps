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
    defBlockSizeString = QString("%1") .arg(nBytesPerPage, 2, 16, QLatin1Char('0'));
    parseReplyOk = false;
    readerIsReading = false;
    readerIsWriting = false;
    crcEnabled = false;
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
    sleep(2);
    connect(&serialDevice, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(this, SIGNAL(replyReady(int)), this, SLOT(parseReply(int)));
    changeStatus(senderIdle);
    sleep(2);
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
        // Clear Device and Buffers
        clearBuffers();
        // Sync Send
        memcpy(readerCommand,  serialCommand.toLatin1().data(), nChars2Send);
        readerCommand[nChars2Send++] = cCR;
        watchDogTimer.start();
        qint64 written = serialDevice.write((char *) readerCommand, nChars2Send);
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
        // if received, run the parser Async
        if (currentCommand != cmdReadBlock && currentCommand != cmdWriteBlock)  {
            emit replyReady((int) currentCommand);
        }
    }
    else  {
        changeStatus(senderError);
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
        // Mark current command as Async Command
        syncCommand = false;
        changeStatus(senderWriting);
        // Clear Device and Buffers
        clearBuffers();

        memcpy(readerCommand, serialCommand.toLatin1().data(), nChars2Send);
        readerCommand[nChars2Send++] = cCR;
        watchDogTimer.restart();
        qint64 written = serialDevice.write((char *)readerCommand, nChars2Send);
        serialDevice.waitForBytesWritten(SEND_WRITE_PAUSE);
        qDebug("[%s] sendAsyncSerialCommand(): Sent[%s] Chars[%d]", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data() ,readerCommand, nChars2Send);
        if (written == nChars2Send)  {
            changeStatus(senderReading);
            fRes = true;
        }
        else if (written < 0)  {
            changeStatus(senderError);
            comErrors++;
        }
        // Unlock Mutex
        mutexCoda.unlock();
    }
    return fRes;
}

void    SerialReader::readData()
{

    if (syncCommand)  {
        return;
    }
    qint64     nReadyChars = serialDevice.bytesAvailable();
    if (nReadyChars)  {
        qDebug("readData():  Bytes Available: [%lli]", nReadyChars);

    }
    return;

    //    if ((lineLength < BUF_SIZE) && ! watchDogTimer.hasExpired(SEND_COMMAND_TIMEOUT)) {
    //        if (serialDevice.waitForReadyRead(SEND_READ_PAUSE))  {
    //            nCharsRead = (int) serialDevice.read(readPoint, BUF_SIZE);
    //            fprintf(stderr, "R:[%d]", lineLength);
    //            if (nCharsRead > 0)  {
    //                readPoint += nCharsRead;
    //                lineLength += nCharsRead;
    //                if (lineLength > 0 && readerAnswer[lineLength - 1] == cCR)  {

    //                    readerAnswer[lineLength - 1] = 0;
    //                    lastReply = QString(readerAnswer);
    //                    emit replyReady((int) currentCommand);
    //                    currentCommand = cmdNone;
    //                }
    //            }
    //        }
    //    }
}

bool    SerialReader::isOpen()
{
    return (portOpen && serialDevice.isOpen());
}

bool    SerialReader::sendReaderCommand(enum commandReader commandType, QString myCommand, bool syncCommand)
// send Command to Reader
{
    bool        fRes = false;
    currentCommand = commandType;
    idleTimer.invalidate();
    if (syncCommand)  {
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
    QString     currentAnswer((char *)readerAnswer);
    bool        commandCorrect = currentAnswer.left(2) == "00";
    bool        commandOk = currentAnswer.mid(2, 2) == "01";
    enum senderStates   newStatus = senderError;

    changeStatus(senderParsing);
    parseReplyOk = false;
    watchDogTimer.invalidate();
    blockStringValue.clear();
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
            qDebug("[%s] parseReply(): Set Tag Filter, switch to senderWaiting",
                            recTime.toLatin1().data());
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

    case cmdReadBlock:
        if (commandCorrect && commandOk)  {
            // Blocks are read 4 bytes a time ---> 8 Chars
            if (currentAnswer.mid(4, 2) == defBlockSizeString)  {
                parseReplyOk = true;
                blockStringValue = currentAnswer.mid(6, (2 * nBytesPerPage));
            }
        }
        // Direct jump to the next command
        newStatus = senderWaitingCommand;
        break;

    case cmdWriteBlock:
        if (commandCorrect && commandOk)  {
            parseReplyOk = true;
        }
        break;

    case cmdNone:
    default:
        qCritical("[%s] parseReply(): Command:[%d] not parsed, Reply:[%s]",
                            recTime.toLatin1().data(),
                            commandPending,
                            readerAnswer);
    }
    changeStatus(newStatus);
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
    qDebug("parseReaderString: Len:[%u] Version:[%s]", userLen, userString.toLatin1().data());
    return isOk;
}


void SerialReader::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    // Initial state of the reader after opening Serial Device
    if (myStatus == senderIdle)  {
        changeStatus(senderGetVersion);
        currentCommand = cmdNone;
    }
    // Request for firmware version to verify communication
    else if (myStatus == senderGetVersion)  {
        if (currentCommand == cmdNone)  {
            if (sendReaderCommand(cmdGetVersion, "0004FF", true))  {
                qDebug("[%s] SerialReader::timerEvent(): Get Version Ok",
                       QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data());
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
                qDebug("[%s] SerialReader::timerEvent(): Set Tag Filter Ok",
                       QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data());
            }
            else  {
                currentCommand = cmdNone;
            }
        }
    }
    // Reader is Idle, switch to Tag Searching is MAX_IDLE_TIME has expired
    else if (myStatus == senderWaitingCommand)  {
        if (idleTimer.isValid() && idleTimer.hasExpired(MAX_IDLE_TIME) && not isBusy())  {
            searchTag();
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
        qWarning("[%s] SerialReader::timerEvent(): Transition from Error to Waiting!",
                            QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data());
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

    //    if (useSyncCommands)  {
    //        return;
    //    }
    //    // QMutexLocker locker(&mutexCoda);

    //    if (myStatus == senderReading)  {
    //        fprintf(stderr, "*");
    //        readData();
    //    }
}

void    SerialReader::changeStatus(enum senderStates newStatus)
{
    // TODO: Refine checks
    // Controls for current status
    switch (myStatus) {
    case senderZero:
        break;
    case senderIdle:
        break;
    case senderGetVersion:
        break;
    case senderSetTagFilter:
        break;
    case senderWaitingCommand:
        idleTimer.restart();
        break;
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
        break;
    case senderSetTagFilter:
        break;
    case senderWaitingCommand:
        break;
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

    // Finally Change Status
    myStatus = newStatus;
}

QString     SerialReader::bytes2readerString(unsigned char *buffer, int nBytes)
{
    QString readerString;

    for (int nByte = 0; nByte < nBytes; nByte++)  {
        uint uChar = (uint) *buffer;
        readerString.append(QString("%1") .arg(uChar, 2, 16, QLatin1Char('0')));
        buffer++;
    }
    return readerString.toUpper();
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

bool        SerialReader::read_15693_Block(int currentBlock, unsigned char *buffer)
{
    bool        fRes = false;
    char        blockNumber[5];

    sprintf(blockNumber, "%2.2X00", currentBlock);
    QString     readBlockCommand = QString("0D05%1FF") .arg(blockNumber);

    currentCommand = cmdReadBlock;
    if (sendSyncSerialCommand(readBlockCommand))  {
        parseReply(cmdReadBlock);
        if (parseReplyOk && blockStringValue.length() == (2 * nBytesPerPage))  {
            readerString2Bytes(blockStringValue, buffer, nBytesPerPage);
            fRes = true;
        }
        //        qDebug("Read Tag Block(): Current Block:[%d] Block Value:[%s] Ok:[%d]",
        //                    currentBlock, blockStringValue.toLatin1().data(), fRes);
    }
    return fRes;
}

bool        SerialReader::write_15693_Block(int currentBlock, unsigned char *buffer)
{
    bool        fRes = false;
    char        blockNumber[5];

    sprintf(blockNumber, "%2.2X00", currentBlock);
    QString     writeBlockCommand = QString("0D07%1%2") .arg(blockNumber) .arg(defBlockSizeString);
    QString     block2Write = bytes2readerString(buffer, nBytesPerPage);

    writeBlockCommand.append(block2Write);
    currentCommand = cmdWriteBlock;
    if (sendSyncSerialCommand(writeBlockCommand))  {
        parseReply(cmdWriteBlock);
        if (parseReplyOk)  {
            fRes = true;
        }
        qDebug("Write Tag Block(): Current Block:[%d] Block Value:[%s] Ok:[%d]",
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
    unsigned char   *p;
    u_int16_t       localCRC = 0;
    u_int16_t       remoteCRC = 0;

    // Check Size
    if (crcEnabled)  {
        nBytes += sizeof(remoteCRC);
    }
    else {
        localCRC = 0;
    }
    nBlocks = (nBytes + nBytesPerPage - 1) / nBytesPerPage;       // Ceil Round-Up...
    if (nBlocks > nMax_15693_UserAreaBlocks || nBytes <= 0)  {
        qCritical("readTagMemory(): Size of the User Area exceeds the space available on Tag: Requested [%d]B vs Available [%d]",
                            nBytes,
                            nMax_15693_UserAreaBlocks * nBytesPerPage);
        goto exitReadTag;
    }
    // Used to Stop Tag Polling
    readerIsReading = true;
    currentCommand = cmdReadBlock;
    // Clear Buffer
    p = &localBuffer[0];
    memset(p, 0, nMax_15693_UserAreaBytes);
    // Read HFTAG_ISO15693 User Pages
    if (currentTagType == HFTAG_ISO15693)  {
        // Reading Loop
        nBlock = 0;
        while (nBlock < nBlocks && nErrors < MAX_READ_ERRORS)  {
            fRes = read_15693_Block(nBlock, p);
            if (fRes)  {
                nBlock++;
                p += (nBlock * nBytesPerPage);
            }
            else  {
                ++nErrors;
            }
            // Pause
            usleep(SEND_WRITE_PAUSE * 1000);
        }
    }
    // Read HFTAG_MIFARE User Pages
    else if (currentTagType == HFTAG_MIFARE)  {
        // TODO: Read MIFARE User Pages
    }
    // All ok, copy of the read data on the user area
    if (fRes)  {
        memcpy(userArea, localBuffer, nBytes);
        qDebug("readTagMemory(): Copied [%d]bytes. Last Block:[%d/%d] Errors:[%d]", nBytes, nBlock, nBlocks, nErrors);
    }
    else {
        qCritical("readTagMemory(): Error Reading User Area. Last Block:[%d] Errors:[%d]", nBlock, nErrors);
    }

exitReadTag:
    currentCommand = cmdNone;
    changeStatus(senderWaitingCommand);
    readerIsReading = false;
    emit tagMemoryRead(fRes);
    return fRes;
}

bool        SerialReader::writeTagMemory(unsigned char *userArea, int nBytes)
// Write User Memory Area of Current Tag
{
    bool            fRes = false;
    int             nBlock = 0;
    int             nBlocks = (nBytes + nBytesPerPage - 1) / nBytesPerPage;       // Ceil Round-Up...
    int             nErrors = 0;
    unsigned char   localBuffer[nMax_15693_UserAreaBytes];
    unsigned char   *p;
    u_int16_t       localCRC = 0;
    u_int16_t       remoteCRC = 0;

    // Check Size
    if (crcEnabled)  {
        localCRC = calculateCRC(userArea, nBytes);
        userArea[nBytes] = (unsigned char) (localCRC & 0xFF);               // lsb first
        userArea[nBytes + 1] = (unsigned char) ((localCRC >> 8) & 0xFF);    // msb
        nBytes += sizeof(remoteCRC);
    }
    else {
        localCRC = 0;
    }
    // Check Size
    if (nBlocks > nMax_15693_UserAreaBlocks || nBytes <= 0)  {
        qCritical("writeTagMemory(): Size of the User Area exceeds the space available on Tag: Requested [%d]B vs Available [%d]",
                            nBytes,
                            nMax_15693_UserAreaBlocks * nBytesPerPage);
        goto exitWriteTag;
    }
    // Used to Stop Tag Polling
    readerIsWriting = true;
    currentCommand = cmdWriteBlock;
    // Clear Buffer and copy locally
    p = &localBuffer[0];
    memset(p, 0, nMax_15693_UserAreaBytes);
    memcpy(p, userArea, nBytes);
    p = userArea;
    if (currentTagType == HFTAG_ISO15693)  {
        // Writing Loop
        nBlock = 0;
        while (nBlock < nBlocks && nErrors < MAX_WRITE_ERRORS)  {
            fRes = write_15693_Block(nBlock, p);
            if (fRes)  {
                nBlock++;
                p += (nBlock * nBytesPerPage);
            }
            else  {
                ++nErrors;
            }
            // Pause
            usleep(SEND_WRITE_PAUSE * 1000);
        }
    }
    else if (currentTagType == HFTAG_MIFARE)  {
        // TODO: Write MIFARE User Pages
    }
    // All ok, copy of the read data on the user area
    if (fRes)  {
        qDebug("writeTagMemory(): Written [%d]bytes. Last Block:[%d/%d] Errors:[%d]", nBytes, nBlock, nBlocks, nErrors);
    }
    else {
        qCritical("writeTagMemory(): Error Writing User Area. Last Block:[%d] Errors:[%d]", nBlock, nErrors);
    }

exitWriteTag:
    currentCommand = cmdNone;
    changeStatus(senderWaitingCommand);
    readerIsWriting = false;
    emit tagMemoryWrite(fRes);
    return fRes;
}

