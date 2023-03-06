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
        cmdGetVersion,
        cmdSetTagFilter,
        cmdSearchTags,
        cmdReadBlock,
        cmdWriteBlock
    };

    enum senderStates {
        senderZero = 0,
        senderIdle,
        senderSetTagFilter,
        senderWaiting,
        senderWriting,
        senderReading,
        senderParsing,
        senderError
    };

    bool    isOpen();
    int     getSerialDeviceID();
    QString getVersionString()          const { return versionString;   }       // Driver Version String
    QString lastTagID()                 const { return currentTagID;    }       // Last Tag ID
    bool    isTagPresent()              const { return tagPresent;      }       // True if Tag is present
    uint    getTagType()                const { return currentTagType;  }       // Last Tag Type found
    uint    getTagIdLen()               const { return currentTagIdLen; }       // Last Tag ID Len
    uint    getTagIdBits()              const { return currentTagIdBits;}       // Last Tag ID Bits
    enum commandReader lastCommand()    const { return currentCommand;  }       // Last Command Sent to Reader
    enum senderStates  readerStatus()   const { return myStatus;        }       // Serial Interface status

    QString getCommandDesc(enum commandReader cmd) const
    {
        QString retval;

        switch (cmd) {
        case    cmdNone:            retval = "No Command";                  break;
        case    cmdGetVersion:      retval = "Get Version String";          break;
        case    cmdSetTagFilter:    retval = "Set Tag Filter";              break;
        case    cmdSearchTags:      retval = "Search Tags";                 break;
        case    cmdReadBlock:       retval = "Read  Block";                 break;
        case    cmdWriteBlock:      retval = "Write Block";                 break;
        default:                    retval = "?";
        }
        return retval;
    }           // Command Description
    QString getStatusDesc(enum senderStates status)  const
    {
        QString retval;

        switch (status) {
        case    senderZero:         retval = "Not Open";                    break;
        case    senderIdle:         retval = "Idle";                        break;
        case    senderSetTagFilter: retval = "Setting Tag Filter";          break;
        case    senderWaiting:      retval = "Waiting Command";             break;
        case    senderWriting:      retval = "Sending Command";             break;
        case    senderReading:      retval = "Reading Answer";              break;
        case    senderParsing:      retval = "Parsing";                     break;
        case    senderError:        retval = "Error";                       break;
        default:                    retval = "?";
        }
        return retval;
    }           // Status Description
    bool    isSync()                    const { return useSyncCommands; }       // True if Command are sent in sync mode
    bool    sendReaderCommand(enum commandReader commandType, QString myCommand);   // send Command to Reader

protected:
    void timerEvent(QTimerEvent *event);

signals:
    void    replyReady(int commandPending);
    
public slots:
    void    openSerialPort();

private slots:
    void    readData();
    void    parseReply(int commandPending);

private:
    //-------------------------------------------
    // Privata Functions
    //-------------------------------------------
    bool                sendAsyncSerialCommand(QString serialCommand);
    bool                sendSyncSerialCommand(QString serialCommand);
    bool                parseTagID(QString tagString, uint &tagType, uint &tagIdbits, uint &tagLen, QString &tagID);
    bool                parseVersionString(QString readerString, uint lenSrt, QString &versionString);
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
    bool                useSyncCommands;
    QString             versionString;
    // Buffers and Tag IDs
    uint                currentTagType;
    uint                currentTagIdBits;
    uint                currentTagIdLen;
    QString             currentTagID;
    QString             lastReply;
    char                readerCommand[BUF_SIZE + 1];
    char                readerAnswer[BUF_SIZE + 1];
    char                *readPoint;
    int                 lineLength;
};

#endif // SERIALREADER_H
