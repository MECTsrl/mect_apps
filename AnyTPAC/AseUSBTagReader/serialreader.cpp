#include "serialreader.h"

#include <QChar>
#include <QByteArray >
#include <QElapsedTimer>
#include <QTime>

const    char        cCR = 13;                       // Carattere CR

SerialReader::SerialReader(QString serialDevice, QObject *parent) :
    QObject(parent)
{
    myDevice = serialDevice;
    portOpen = false;
    serial = 0;
}

SerialReader::~SerialReader()
{
    if (serial != 0)  {
        // Close Device
        if (serial->isOpen())  {
            serial->close();
        }
        serial->deleteLater();
    }
}

void SerialReader::openSerialPort()
{
    serial = new QSerialPort(this);
    serial->setPortName(myDevice);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    portOpen = serial->open(QIODevice::ReadWrite);
    // QObject::connect(&serial, SIGNAL(readyRead()), this, SLOT(readData()));
}

int SerialReader::getSerialDeviceID()
{
    return (int) serial->handle();
}

bool    SerialReader::sendSerialCommand(QString serialCommand)
{

    QElapsedTimer   watchDogTimer;

    int     nChars2Send = serialCommand.length();

    serial->clear();
    memset(&readerCommand[0], 0, BUF_SIZE);
    memset(&readerAnswer[0], 0, BUF_SIZE);

    strncpy(readerCommand, serialCommand.toLatin1().data(), nChars2Send);
    readerCommand[nChars2Send++] = cCR;
    watchDogTimer.start();
    qint64 written = serial->write(readerCommand, nChars2Send);
    serial->waitForBytesWritten(10000);
    qDebug("[%s] sendSerialCommand(): Sent[%s] Chars[%d]", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data() ,readerCommand, nChars2Send);
    serial->waitForReadyRead(10000);
    qint64 lineLength = serial->readLine(readerAnswer, BUF_SIZE);
    qDebug("[%s] readData(): Received [%s] Chars[%lli] Elapsed[%lli] ms", QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(), readerAnswer, lineLength, watchDogTimer.elapsed());
    return (written = serialCommand.length());
}

void    SerialReader::readData()
{
    const QByteArray data = serial->readAll();
    qDebug("readData(): Received [%s]", data.data());
}

bool    SerialReader::isOpen()
{
    return (portOpen && serial->isOpen());
}
