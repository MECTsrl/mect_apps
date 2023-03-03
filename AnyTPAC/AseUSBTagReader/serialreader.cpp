#include "serialreader.h"

#include <QByteArray >
#include <QTime>
#include <QMutexLocker>
#include <stdio.h>

#define SEND_COMMAND_TIMEOUT   2000
#define SEND_WRITE_PAUSE        20
#define SEND_READ_PAUSE         20
#define SENDER_INTERVAL         200

const    char        cCR = 13;                       // Carattere CR

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
    connect(this, SIGNAL(replyReady(commandReader,QString)), this, SLOT(parseReply(commandReader,QString)));
    myStatus = senderIdle;
    timerId = startTimer(SENDER_INTERVAL);

}

int SerialReader::getSerialDeviceID()
{
    return (int) serialDevice.handle();
}

bool    SerialReader::sendSerialCommand(QString serialCommand)
{

    QMutexLocker locker(&mutexCoda);

    int     nChars2Send = serialCommand.length();
    bool    fRes = false;

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
    qDebug("[%s] sendSerialCommand(): Sent[%s] Chars[%d]", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data() ,readerCommand, nChars2Send);
    //    // serial.waitForBytesWritten(10000);
    //    int     nReadLoop = 0;
    //    while ()  {
    //        nCharsRead = (int) serial.read(readPoint, BUF_SIZE);
    //        readPoint += nCharsRead;
    //        lineLength += nCharsRead;
    //        nReadLoop++;
    //        // Condizione di uscita per andare al Parser della Risposta
    //        if ((lineLength > 0 && readerAnswer[lineLength - 1] == cCR) || nCharsRead < 0)  {
    //            break;
    //        }
    //    }
    //    // qint64 lineLength = serial.readLine(readerAnswer, BUF_SIZE);
    //    qDebug("[%s] readData(): Received [%s] Chars[%d] Elapsed[%lli] ms Loops[%d]",
    //                    QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(),
    //                    readerAnswer,
    //                    lineLength,
    //                    watchDogTimer.elapsed(),
    //                    nReadLoop);
    if (written == nChars2Send)  {
        myStatus = senderReading;
        fRes = true;
    }
    else if (written < 0)  {
        myStatus = senderError;
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
                    emit replyReady(currentCommand, lastReply);
                    myStatus = senderParsing;
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
    currentCommand = commandType;
    return (sendSerialCommand(myCommand));
}

void    SerialReader::parseReply(commandReader commandPending, QString readerReply)
{
    QString     recTime = QTime::currentTime().toString("HH:mm:ss.zzz");
    qint64      replyTime = watchDogTimer.isValid() ? watchDogTimer.elapsed() : 0;


    watchDogTimer.invalidate();
    qDebug("[%s] parseReply(): Elapsed:[%lli] Command:[%s] Reply:[%s]",
                        recTime.toLatin1().data(),
                        replyTime,
                        getCommandDesc(commandPending).toLatin1().data(),
                        readerReply.toLatin1().data());
    // Parsing reply
    switch (commandPending) {
    case cmdSetTagFilter:
        break;
    case cmdSearchTags:
        break;
    case cmdReadBlock:
        break;
    case cmdWriteBlock:
        break;
    case cmdNone:
    default:
        qCritical("parseReply(): Command:[%d] not parsed, Reply:[%s]", commandPending, readerReply.toLatin1().data());
    }
}


void SerialReader::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    QMutexLocker locker(&mutexCoda);

    if (myStatus == senderReading)  {
        fprintf(stderr, "*");
        readData();
    }
}
