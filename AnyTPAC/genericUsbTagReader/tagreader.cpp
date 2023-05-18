#include "tagreader.h"

#include <QDebug>
#include <QTime>

// Info for qDebug
#define LOG_STRING      "[%s] %s(%d):\t"
#define LOG_POINT       QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(), __func__, __LINE__

const   char    cCR = 13;                                   // CR Char
const   int     nReceiveTimeout = 3000;                     // Reply Time-out from reader

tagReader::tagReader(QObject *parent) :
    QObject(parent)
{
    lastTagID.clear();
    readLoops = 0;
    elTime = 0;
    readPoint = &readerAnswer[0];
    memset(&readerAnswer[0], 0, BUF_SIZE);
    lineLength = 0;
}

bool    tagReader::openSerialPort(QString deviceName)
// Open Serial Port
{
    serialDevice.setPortName(deviceName);
    serialDevice.setBaudRate(QSerialPort::Baud9600);
    serialDevice.setDataBits(QSerialPort::Data8);
    serialDevice.setParity(QSerialPort::NoParity);
    serialDevice.setStopBits(QSerialPort::OneStop);
    serialDevice.setFlowControl(QSerialPort::NoFlowControl);
    portOpen = serialDevice.open(QIODevice::ReadWrite);
    sleep(1);
    if (portOpen)  {
        connect(&serialDevice, SIGNAL(readyRead()), this, SLOT(readData()));
    }
    else  {
    }
    return portOpen;
}

void    tagReader::clearBuffers()
{
    serialDevice.clear();
    readPoint = &readerAnswer[0];
    memset(&readerAnswer[0], 0, BUF_SIZE);
    lineLength = 0;
}

void    tagReader::readData()
{
    qint64      nReadyChars = serialDevice.bytesAvailable();
    qint64      nCharsRead = 0;

    if (lineLength == 0)  {
        lastTagID.clear();
        watchDogTimer.restart();
        readLoops = 0;
        elTime = 0;
    }
    if (nReadyChars)  {
        if (lineLength < BUF_SIZE && watchDogTimer.isValid() && ! watchDogTimer.hasExpired(nReceiveTimeout)) {
            nCharsRead = serialDevice.read((char *) readPoint, nReadyChars);
            elTime += watchDogTimer.elapsed();
            if (nCharsRead > 0)  {
                readPoint += (int) nCharsRead;
                lineLength += (int) nCharsRead;
                readLoops++;
                if (lineLength > 0)  {
                    if (readerAnswer[lineLength - 1] == cCR)  {
                        // answer complete from reader, remove CR
                        readerAnswer[lineLength - 1] = 0;
                        lastTagID = QString((char *) readerAnswer);
                        qDebug(LOG_STRING"String Completed:[%s] - Len:[%d] - Elapsed:[%lli]ms Loops:[%d]", LOG_POINT, lastTagID.toLatin1().data(), lastTagID.length(), elTime, readLoops);
                        watchDogTimer.invalidate();
                        emit readNewTag(lastTagID);
                        clearBuffers();
                    }
                    else  {
                        qDebug(LOG_STRING"Buffered Chars:[%s] - Len:[%d] Elapsed:[%lli]ms Loop:[%d]", LOG_POINT, readerAnswer, lineLength, elTime, readLoops);
                    }
                }
            }
        }
    }
}
