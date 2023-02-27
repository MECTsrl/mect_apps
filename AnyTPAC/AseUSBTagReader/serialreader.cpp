#include "serialreader.h"

#include <QChar>
#include <QByteArray >
#include <QElapsedTimer>
#include <QTime>

const    char        cCR = 13;                       // Carattere CR

SerialReader::SerialReader(QObject *parent) :
    QObject(parent)
{
    // QObject::connect(&serial, SIGNAL(readyRead()), this, SLOT(readData()));
}

bool    SerialReader::openSerialPort(QString serialDevice)
{
    serial.setPortName(serialDevice);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    return (serial.open(QIODevice::ReadWrite));
}

bool    SerialReader::sendSerialCommand(QString serialCommand)
{

    QElapsedTimer   watchDogTimer;

    int     nChars2Send = serialCommand.length();

    serial.clear();
    memset(&readerCommand[0], 0, BUF_SIZE);
    memset(&readerAnswer[0], 0, BUF_SIZE);

    strncpy(readerCommand, serialCommand.toLatin1().data(), nChars2Send);
    readerCommand[nChars2Send++] = cCR;
    watchDogTimer.start();
    qint64 written = serial.write(readerCommand, nChars2Send);
    serial.waitForBytesWritten(10000);
    qDebug("[%s] sendSerialCommand(): Sent[%s] Chars[%d]", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data() ,readerCommand, nChars2Send);
    serial.waitForReadyRead(10000);
    qint64 lineLength = serial.readLine(readerAnswer, BUF_SIZE);
    qDebug("[%s] readData(): Received [%s] Chars[%lli] Elapsed[%lli] ms", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(), readerAnswer, lineLength, watchDogTimer.elapsed());
    return (written = serialCommand.length());
}

void    SerialReader::readData()
{
    const QByteArray data = serial.readAll();
    qDebug("readData(): Received [%s]", data.data());
}

bool    SerialReader::isOpen()
{
    return serial.isOpen();
}
