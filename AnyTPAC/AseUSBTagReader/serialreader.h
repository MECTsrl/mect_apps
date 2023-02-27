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
    explicit SerialReader(QObject *parent = 0);
    bool    openSerialPort(QString serialDevice);
    bool    sendSerialCommand(QString serialCommand);
    bool    isOpen();

signals:
    
public slots:

private slots:
    void    readData();

private:
    QSerialPort serial;
    char        readerCommand[BUF_SIZE + 1];
    char        readerAnswer[BUF_SIZE + 1];
};

#endif // SERIALREADER_H
