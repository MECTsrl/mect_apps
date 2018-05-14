#ifndef MECTCOMM_H
#define MECTCOMM_H

#include <QObject>
#include <QHostAddress>
#include <QEvent>
#include <QTcpSocket>
#include <QMutex>

enum mectCommStatus {MectComm_Idle = 0, MectComm_Connected, MectComm_Ready, MectComm_Error};
#define DimCrossTable   5472

struct XBlock;
struct XConfig;
struct XGuid;
struct XVariableSML;

struct XDBIVar	/* --> aligned (2) */
{
    unsigned char	usType;         /* Type of variable 				*/
    unsigned char	usNameSize;     /* Size of name (without ZB!)		*/
    unsigned short	uInst;          /* Segment / instance number		*/
    unsigned    	ulOffset;		/* Variable offset					*/
    unsigned short	uLen;			/* Size / number elem / string size */
    unsigned char	usBit;          /* Bit offset						*/
    unsigned char	usDummy;		/* Alignment dummy					*/

};

struct mectVariable {
    QString name;
    uint16_t ID;
    struct XDBIVar dbi;
};

class mectComm : public QObject
{
    Q_OBJECT
public:

    // communication via TCP/IP to MECT TP/TPAC/TPLC at given address and port
    // usage:
    //     1) x = new mectComm();
    //     2) x->start();
    //     3) x->getValue(193, value);
    //     4) x->doWrite(193, value + 1);
    //
    explicit mectComm(QList<uint16_t> IDs,
                      QObject *parent = nullptr,
                      const QHostAddress &address = QHostAddress("192.168.5.211"),
                      quint16 port = 17290,
                      int period_ms = 500)
        : IDs{IDs}
        , parent{parent}
        , address{address}
        , port{port}
        , period_ms{ (period_ms >= 100)?period_ms:100 }
        , tcpSocket(new QTcpSocket(this))
    {
        status = MectComm_Idle;
        for (uint16_t n = 0; n <= DimCrossTable; ++n) {
            values[n] = 0;
        }
        reads = writes = commands = errors = 0;
        tcpSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
        tcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);

        timerId = startTimer(this->period_ms);
    }
    ~mectComm();

    // getters and setters for configurable attributes
    QList<uint16_t> getIDs() { return IDs; }
    QHostAddress getAddress() { return address; }
    quint16 getPort() { return port; }
    int getPeriod() { return period_ms; }

    // getters for private visible attributes
    enum mectCommStatus getStatus() { return status; }
    QString getStatusString()
    {
        switch (status) {
        case MectComm_Idle: return "IDLE";
        case MectComm_Connected: return "CONNECTED";
        case MectComm_Ready: return "READY";
        case MectComm_Error: return "ERROR";
        default: return "?";
        }
    }
    uint32_t getValue(uint16_t n)
    {
        uint32_t value = 0;

        if (n <= DimCrossTable)
            value = values[n];

        return value;
    }
    void getStatistics(quint64 &reads, quint64 &writes, quint64 &commands, quint64 &errors)
    {
        reads = this->reads;
        writes = this->writes;
        commands = this->commands;
        errors = this->errors;
    }

    //
    bool doWrite(uint16_t ID, uint32_t value);

protected:
      void timerEvent(QTimerEvent *event);

signals:

public slots:

private:
    // must be first
    QList<uint16_t> IDs;
    QObject * parent;
    QMutex mutex;

    // configurable attributes

    QHostAddress address;
    quint16 port;
    int period_ms;

    // private visible attributes
    enum mectCommStatus status = MectComm_Idle;
    uint32_t values[1 + DimCrossTable];
    quint64 reads, writes, commands, errors;

    // private unvisible attributes
    int timerId;
    QTcpSocket *tcpSocket = nullptr;
    QList<struct mectVariable> variables;
    unsigned char sequence = 0;

    // private methods
    bool connect(void);
    bool doSend(struct XBlock &command);
    bool doRecv(struct XBlock &reply);
    bool doCommand(struct XBlock &command, struct XBlock &reply);
    bool doLogin(struct XGuid &guid);
    bool doLogout(void);
    bool getConfig(struct XConfig &config);
    bool getProjectVersion(struct XGuid &guid);
    bool getRootChildren(struct XBlock &children);
    bool readAll(void);
};

#endif // MECTCOMM_H
