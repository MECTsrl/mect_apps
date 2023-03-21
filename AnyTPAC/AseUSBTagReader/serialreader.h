#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QString>
#include <QElapsedTimer>
#include <QMutex>
#include <QTimerEvent>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#define     BUF_SIZE            1024

#define     RECEIVE_COMMAND_TIMEOUT 500 // Reply Time-out from reader

#define     HFTAG_MIFARE        0x80	// "ISO14443A/MIFARE"
#define     HFTAG_ISO15693      0x82	// "ISO15693"
#define     TAGMASK(Tagtype)    (1 << (Tagtype & 0x1F))


class SerialReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialReader(QString myDevice, QObject *parent = 0);
    ~SerialReader();
    //-------------------------------------------
    // Public Enums for Class
    //-------------------------------------------
    // Command to Reader
    enum commandReader  {
        cmdNone = 0,
        cmdGetVersion,
        cmdSetTagFilter,
        cmdSearchTags,
        cmdReadBlock,
        cmdReadPages,
        cmdWriteBlock
    };
    // State machine states (handled in the Timer event)
    enum senderStates {
        senderZero = 0,
        senderIdle,
        senderGetVersion,
        senderSetTagFilter,
        senderWaitingCommand,
        senderWriting,
        senderReading,
        senderParsing,
        senderParseOk,
        senderParseFail,
        senderError
    };
    //-------------------------------------------
    // Public Usage Methods
    //-------------------------------------------
    bool        openSerialPort();                                       // Open Serial Port (the device name is specified in the Constructor)
    void        setCRCEnabled(bool addCRC)  { crcEnabled = addCRC; }    // Add 16 Bit CRC to Data
    void        setTagPollingIntervalms(int pollInterval_ms) { if (pollInterval_ms > RECEIVE_COMMAND_TIMEOUT) tagPollingms = pollInterval_ms; }    // set Tag Polling interval in ms
    int         getTagPollingIntervalms()   const { return tagPollingms; }                          // get Tag Polling interval in ms
    bool        readTagMemory(unsigned char *userArea, int nBytes);     // Read User Memory Area of Current Tag
    bool        writeTagMemory(unsigned char *userArea, int nBytes);    // Write User Memory Area of Current Tag
    u_int16_t   calculateCRC(unsigned char *userArea, int nBytes);      // Computes the CRC of a byte buffer, one byte at a time
    // Status and Current Tag Info
    bool        isOpen();
    bool        isBusy()                    const { return readerIsReading || readerIsWriting; } // Returns true if a Read or Write Tag is pending
    bool        isCRCEnabled()              const { return crcEnabled; }            // Returns true if CRC is added to Written data
    int         getSerialDeviceID()         const { return (int) serialDevice.handle(); }  // Device Handle
    int         getCommErrors()             const { return comErrors;       }       // Communication Errors
    QString     getVersionString()          const { return versionString;   }       // Driver Version String
    QString     lastTagID()                 const { return currentTagID;    }       // Last Tag ID
    bool        isTagPresent()              const { return tagPresent;      }       // True if Tag is present
    uint        getTagType()                const { return currentTagType;  }       // Last Tag Type found
    uint        getTagIdLen()               const { return currentTagIdLen; }       // Last Tag ID Len
    uint        getTagIdBits()              const { return currentTagIdBits;}       // Last Tag ID Bits
    enum commandReader lastCommand()        const { return currentCommand;  }       // Last Command Sent to Reader
    enum senderStates  readerStatus()       const { return myStatus;        }       // Serial Interface status
    // Descriptions
    QString getCommandDesc(enum commandReader cmd) const
    {
        QString retval;

        switch (cmd) {
        case    cmdNone:            retval = "No Command";                  break;
        case    cmdGetVersion:      retval = "Get Version String";          break;
        case    cmdSetTagFilter:    retval = "Set Tag Filter";              break;
        case    cmdSearchTags:      retval = "Search Tags";                 break;
        case    cmdReadBlock:       retval = "Read  Block";                 break;
        case    cmdReadPages:       retval = "Read  Pages";                 break;
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
        case    senderGetVersion:   retval = "Get Firmware Version";        break;
        case    senderSetTagFilter: retval = "Setting Tag Filter";          break;
        case    senderWaitingCommand:   retval = "Waiting Command";         break;
        case    senderWriting:      retval = "Sending Command";             break;
        case    senderReading:      retval = "Reading Answer";              break;
        case    senderParsing:      retval = "Parsing Reply";               break;
        case    senderParseOk:      retval = "Parsed Ok";                   break;
        case    senderParseFail:    retval = "Parsed Fail";                 break;
        case    senderError:        retval = "Error";                       break;
        default:                    retval = "?";
        }
        return retval;
    }           // Status Description

protected:
    void    timerEvent(QTimerEvent *event);         // State machine management

signals:
    void    replyReady(int commandPending);         // A Reply from reader is ready to be parsed
    void    tagFound(QString tagID);                // Tag found with ID tagID
    void    noTag();                                // No Tag foung (Answer 0100 to cmdSearchTags)
    void    tagMemoryRead(bool readOK);             // Tag Memory Read completed
    void    tagMemoryWrite(bool writeOK);           // Tag Memory Write completed
    
public slots:

private slots:
    void    readData();
    void    parseReply(int commandPending);
    void    changeStatus(enum senderStates newStatus);

private:
    //-------------------------------------------
    // Private Functions
    //-------------------------------------------
    void                clearBuffers();
    bool                searchTag();                                            // Search a Tag near reader
    bool                sendReaderCommand(enum commandReader commandType, QString myCommand, bool sendSync = true);   // send Command to Reader
    bool                sendAsyncSerialCommand(QString serialCommand);
    bool                sendSyncSerialCommand(QString serialCommand);
    bool                parseTagID(QString tagString, uint &tagType, uint &tagIdbits, uint &tagLen, QString &tagID);
    bool                parseReaderString(QString readerString, QString &userString);
    QString             bytes2readerString(unsigned char *buffer, int nBytes);
    void                readerString2Bytes(QString readerString, unsigned char *buffer, uint userLen);
    bool                read_15693_Block(int currentBlock, QString &dataBuffer);
    bool                write_15693_Block(int currentBlock, const QString &block2Write);
    bool                read_MIFARE_Pages(int nStartPage, int nPages, QString &dataBuffer);
    bool                write_MIFARE_Page(int nPage, const QString &block2Write);
    u_int16_t           updateCRC(u_int16_t CRC, unsigned char Byte);
    //-------------------------------------------
    // Private Variables
    //-------------------------------------------
    // Timer  and Mutex
    int                 timerId;            // Module Timer
    QMutex              mutexCoda;          // Mutex on Buffers and Internal Status
    // Status Flags and Commands
    bool                portOpen;
    bool                tagPresent;
    bool                parseReplyOk;
    bool                readerIsReading;
    bool                readerIsWriting;
    bool                readerIsSearching;
    QSerialPort         serialDevice;
    QString             myDevice;
    QElapsedTimer       watchDogTimer;
    QElapsedTimer       idleTimer;
    enum commandReader  currentCommand;
    enum senderStates   myStatus;
    bool                isSyncCommand;
    QString             versionString;
    uint                comErrors;
    bool                crcEnabled;
    int                 tagPollingms;
    // Buffers and Tag IDs
    uint                currentTagType;
    uint                currentTagIdBits;
    uint                currentTagIdLen;
    QString             currentTagID;
    QString             lastReply;
    QString             blockStringValue;
    QString             defBlockSizeString;
    unsigned char       readerCommand[BUF_SIZE + 1];
    unsigned char       readerAnswer[BUF_SIZE + 1];
    unsigned char       *readPoint;
    int                 lineLength;
};

#endif // SERIALREADER_H
