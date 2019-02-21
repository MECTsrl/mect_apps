#ifndef MECTCOMM_H
#define MECTCOMM_H
typedef unsigned short uint16_t;

#include <stdint.h>
#include <QObject>
#include <QHostAddress>
#include <QEvent>
#include <QTcpSocket>
#include <QMutex>
//LogList include
#include <QString>
#include <QList>
#include <QTextStream>
#include <QDateTime>
#include <QtGlobal>
#include <QCoreApplication>
#include <QStringList>
//

//HTTP include
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkConfigurationManager>
//

#define SizeBuffer 1024

enum mectCommStatus {MectComm_Idle = 0, MectComm_Connected, MectComm_Ready, MectComm_Error};
#define DimCrossTable   5472

#pragma pack(1)
struct XBlock;
struct XConfig;
struct XGuid;
struct XVariableSML;
struct XIndex;

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
#pragma pack()
////////////////////////////////////////
/////////////LogList Struct/////////////
////////////////////////////////////////
struct mectNameValue{
    QString name;
    QString value;
};
struct mectLogRow{
    QDateTime dateTime;
    QList <mectNameValue> columns;
};

struct varPoint{
    QDateTime X;
    double Y;
};

struct query{
    QDateTime from;
    QDateTime to;
    QList <QString> variables;
};
////////////////////////////////////////
////////////////////////////////////////

class mectComm : public QObject
{
    Q_OBJECT
public:

    ~mectComm();

    // getters and setters for configurable attributes
    QList<uint16_t > getIDs() { return IDs; }
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

    float getFValue(uint32_t value)
    {
      /*  {
            union  {
                uint32_t v;
                struct  {
                    qint8 sign : 1;
                    qint8 exponent: 5;
                    qint16 fraction: 10;
                } frep;
            } halfPrecisionFloat;

            union  {
                float v;
                struct  {
                    qint8 sign : 1;
                    qint8 exponent: 8;
                    qint16 fraction: 23;
                } frep;
            } singlePrecisionFloat;

            halfPrecisionFloat.v = result;
            singlePrecisionFloat.frep.sign = halfPrecisionFloat.frep.sign;
            singlePrecisionFloat.frep.exponent = halfPrecisionFloat.frep.exponent;
            singlePrecisionFloat.frep.fraction = halfPrecisionFloat.frep.fraction;

            return singlePrecisionFloat.v;
        }*/
        union X
        {
            float f;
            uint32_t u;
        };
        X x;
        x.u=value;
        return x.f;

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

    QList<QString> getVariableList();
    uint16_t getVariableID(QString varName);
    void startTimerMect();
    void stopTimerMect();
    void startConnect (QList<uint16_t > IDs,
                       QObject *parent, //nullptr,
                       const QHostAddress &address ,
                       quint16 port,
                       int period_ms);

    ////////////////////////////////////////////////
    /////////////CircularBuffer Public Methods//////
    ////////////////////////////////////////////////
    void initBuffer();
    void writeXTime(double input, double timeIn, int index);
    double readY(int index);
    double readTime(int index);
    bool checkIndex();
    void readBufferPoints(double &x, double &y, int index);
    unsigned readIndex;
    unsigned readIndexTime;
    unsigned writeIndex;
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////


    ////////////////////////////////////////////////
    /////////////LogList Public Methods/////////////
    ////////////////////////////////////////////////
    void setLogList(mectLogRow rowStruct);


    bool readLog(QString replyText);
    int getVariableData(int rowIndexVar);
    QString getVariableValue(int rowIndexVar, QString varName);

    QString getLogList();
    QList<QString> getQueryVariables();
    QDateTime getQueryDateFrom();
    QDateTime getQueryDateTo();
    int getQueryCount();
    void setdateCounter();
    int getdateCounter();
    void clearLogList();
    void clearDateCounter();
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////


    bool requestVariableList(QString IP);
    bool openConnection(QString IP);
    bool requestValueList(QString IP,QDateTime fromDate,QDateTime toDate, QString delta_Ts,QStringList varList);
    bool getVariableList(QStringList &variableList);
    bool getValueVector(QStringList varList, QList<QList<varPoint> > &dataStruct);
    bool getDataCount(int &dataCount);



protected:
      void timerEvent(QTimerEvent *event);

signals:
      void crossTableVarReady();
      void dataReady();
      void variablesReady();
      void errorSignal(QString errorCode);
      void dataStructReady();

public slots:
      ////////////////////////////////////////////////
      /////////////HTTP&JSON Private Methods//////////
      ////////////////////////////////////////////////
      void requestShowPage(QUrl newUrl);
      bool doLogout(void);
      ////////////////////////////////////////////////
      ////////////////////////////////////////////////


private:
    // must be first
    QList<uint16_t > IDs;
    QObject * parent;
    QMutex mutex;

    // configurable attributes

    QHostAddress address;
    quint16 port;
    int period_ms;

    // private visible attributes
    enum mectCommStatus status;// = MectComm_Idle;
    uint32_t values[1 + DimCrossTable];
    quint64 reads, writes, commands, errors;

    // private unvisible attributes
    int timerId;
    QTcpSocket *tcpSocket ;//= nullptr;
    QList<struct mectVariable> variables;
    QList <QString> allVariables;
    unsigned char sequence;// = 0;

    // private methods
    bool connect(void);
    bool doSend(struct XBlock &command);
    bool doRecv(struct XBlock &reply);
    bool doCommand(struct XBlock &command, struct XBlock &reply);
    bool doLogin(struct XGuid &guid);

    bool getConfig(struct XConfig &config);
    bool getProjectVersion(struct XGuid &guid);
    bool getRootChildren(struct XBlock &children);
    bool readAll(void);
    bool customCMD(XIndex &index);

    /////////////////////////////////////////////////
    /////////////CircularBuffer Private Methods&Var//
    /////////////////////////////////////////////////
    double bufferX[24][SizeBuffer];
    double bufferTime[24][SizeBuffer];
    /////////////////////////////////////////////////
    /////////////////////////////////////////////////


    ////////////////////////////////////////////////
    /////////////LogList Private Methods&Vars///////
    ////////////////////////////////////////////////
     QList  <mectLogRow> rows;
     mectNameValue setNameValue(QString name,QString value);

     //mectLogRow setLogColumns(QDateTime T,QString name,int variable_count, QtJson::JsonObject *nested1);
     bool dateControl(QDateTime date);
     mectLogRow tmpLowRow;
     query Query;
     int dataCount;//=0;

     ////////////////////////////////////////////////
     ////////////////////////////////////////////////
     QNetworkAccessManager *manager;
     private slots:
     ////////////////////////////////////////////////
     /////////////HTTP&JSON Private Methods//////////
     ////////////////////////////////////////////////
     void requestReceived(QNetworkReply *reply);
     ////////////////////////////////////////////////
     ////////////////////////////////////////////////


};

#endif // MECTCOMM_H
