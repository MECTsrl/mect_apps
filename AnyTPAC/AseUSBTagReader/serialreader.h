#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QString>
#include <QElapsedTimer>
#include <QMutex>
#include <QTimerEvent>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#define  BUF_SIZE           1024


class SerialReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialReader(QString myDevice, QObject *parent = 0);
    ~SerialReader();
    enum commandReader  {
        cmdNone = 0,
        cmdSetTagFilter,
        cmdSearchTags,
        cmdReadBlock,
        cmdWriteBlock
    };

    enum senderStates {
        senderZero = 0,
        senderIdle,
        senderWaiting,
        senderWriting,
        senderReading,
        senderParsing,
        senderError
    };

    bool    isOpen();
    int     getSerialDeviceID();
    QString lastTagID()                 const { return currentTagID;    }       // Last Tag ID
    bool    isTagPresent()              const { return tagPresent;      }       // True if Tag is present
    enum commandReader lastCommand()    const { return currentCommand;  }       // Last Command Sent to Reader
    enum senderStates  readerStatus()   const { return myStatus;        }       // Serial Interface status

    QString getCommandDesc(enum commandReader cmd) const
    {
        QString retval;

        switch (cmd) {
        case    cmdNone:            retval = "No Command";                  break;
        case    cmdSetTagFilter:    retval = "Set Tag Filter";              break;
        case    cmdSearchTags:      retval = "Search Tags";                 break;
        case    cmdReadBlock:       retval = "Read  Block";                 break;
        case    cmdWriteBlock:      retval = "Write Block";                 break;
        default:                    retval = "?";
        }
        return retval;
    }           // Last Command Description

    bool    sendReaderCommand(enum commandReader commandType, QString myCommand);   // send Command to Reader

protected:
    void timerEvent(QTimerEvent *event);

signals:
    void    replyReady(enum commandReader commandPending, QString readerReply);
    
public slots:
    void    openSerialPort();

private slots:
    void    readData();
    void    parseReply(enum commandReader commandPending, QString readerReply);

private:
    //-------------------------------------------
    // Privata Functions
    //-------------------------------------------
    bool                sendSerialCommand(QString serialCommand);

    //-------------------------------------------
    // Privata Variables
    //-------------------------------------------
    // Timera and Mutex
    int                 timerId;            // Module Timer
    QMutex              mutexCoda;          // Mutex on Buffers and Internal Status
    // Status Flags and Commands
    bool                portOpen;
    bool                tagPresent;
    QSerialPort         serialDevice;
    QString             myDevice;
    QElapsedTimer       watchDogTimer;
    enum commandReader  currentCommand;
    enum senderStates   myStatus;
    // Buffers and Tag IDs
    QString             currentTagID;
    QString             lastReply;
    char                readerCommand[BUF_SIZE + 1];
    char                readerAnswer[BUF_SIZE + 1];
    char                *readPoint;
    int                 lineLength;
};

#endif // SERIALREADER_H
