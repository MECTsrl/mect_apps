#ifndef TAGREADER_H
#define TAGREADER_H

#include <QObject>
#include <QString>
#include <QElapsedTimer>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


#define     BUF_SIZE            1024

class tagReader : public QObject
{
    Q_OBJECT
public:
    explicit tagReader(QObject *parent = 0);
    //-------------------------------------------
    // Public Usage Methods
    //-------------------------------------------
    bool        openSerialPort(QString deviceName);                                 // Open Serial Port
    bool        isOpen()                    const { return portOpen;    }           // Open Status Flag
    QString     getLastTagID()              const { return lastTagID;   }           // Last Tag ID
    qint64      getElapsedTime()            const { return elTime;      }           // Last read Time
    int         getReadLoops()              const { return readLoops;    }          // Last read Loops

signals:
    void        readNewTag(QString newTag);

public slots:

private slots:
    void        readData();

private:
    //-------------------------------------------
    // Private Functions
    //-------------------------------------------
    void                clearBuffers();

    //-------------------------------------------
    // Private Variables
    //-------------------------------------------
    QSerialPort         serialDevice;
    QString             myDevice;
    bool                portOpen;
    unsigned char       readerAnswer[BUF_SIZE + 1];
    unsigned char       *readPoint;
    int                 lineLength;
    int                 readLoops;
    QString             lastTagID;
    QElapsedTimer       watchDogTimer;
    qint64              elTime;

};

#endif // TAGREADER_H
