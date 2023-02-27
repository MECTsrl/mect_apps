#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#define  BUF_SIZE           1024


class SerialReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialReader(QString myDevice, QObject *parent = 0);
    ~SerialReader();
    bool    sendSerialCommand(QString serialCommand);
    bool    isOpen();
    int     getSerialDeviceID();

signals:
    
public slots:
    void    openSerialPort();

private slots:
    void    readData();

private:
    bool        portOpen;
    QSerialPort *serial;
    QString     myDevice;
    char        readerCommand[BUF_SIZE + 1];
    char        readerAnswer[BUF_SIZE + 1];
};

#endif // SERIALREADER_H
