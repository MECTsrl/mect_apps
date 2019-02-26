#include "mectcomm.h"
//logList include
#include <QDateTime>
#include <QListIterator>
#include <QtGlobal>
#include <QDebug>
#include <QObject>
#include <cmath>

#define LASTCHAR 19
//

#define MIN_BUFFER_CHECK 300 //Circular Buffer

#define MAX_DATA		    8000u	/* Max. count of data bytes per block	*/
#define VIS_TCP_TIMEOUT 		8000 // Communication time out
#define VMM_GUID				16u 	/* Size of project GUID 			*/
#define CT_INDEX_SIZE			32u 	/* Size of project GUID 			*/

// ----------------------------------------------------------------------------
// Commands
//
#define CMD_GET_STATE				0x00u		/* Remember to change the	*/
#define CMD_NOT_IMPLEMENTED 		0x01u		/* string array in vmmDef.h */
#define CMD_LOGIN					0x02u		/* also after changing a	*/
#define CMD_LOGOUT					0x03u		/* command value!			*/
#define CMD_WARM_START				0x04u
#define CMD_COLD_START				0x05u
#define CMD_START_ALL_TASKS 		0x06u
#define CMD_STOP_ALL_TASKS			0x07u
#define CMD_START_TASK				0x08u
#define CMD_STOP_TASK				0x09u
#define CMD_OPEN_DEBUG_SESSION		0x0Au
#define CMD_CLOSE_DEBUG_SESSION 	0x0Bu
#define CMD_SET_BREAKPOINT			0x0Cu
#define CMD_CLEAR_BREAKPOINT		0x0Du
#define CMD_CLEAR_ALL_BREAKPOINTS	0x0Eu
#define CMD_SINGLE_STEP 			0x0Fu
#define CMD_CONTINUE				0x10u
#define CMD_GET_VALUE				0x11u
#define CMD_SET_VALUE				0x12u
#define CMD_DOWNLOAD_CONFIG 		0x13u
#define CMD_DOWNLOAD_INITIAL		0x14u
#define CMD_DOWNLOAD_CODE			0x15u
#define CMD_DOWNLOAD_CUSTOM 		0x16u
#define CMD_DOWNLOAD_FINISH 		0x17u
#define CMD_START_RESOURCE			0x18u
#define CMD_STOP_RESOURCE			0x19u
#define CMD_DOWNLOAD_END			0x1Au
#define CMD_DOWNLOAD_BEGIN			0x1Bu
#define CMD_INITIALIZE_CLEAR		0x1Cu
#define CMD_CLEAR_FLASH 			0x1Du
#define CMD_DBI_GET_CHILDREN		0x1Eu
#define CMD_DBI_GET_ADDRESS 		0x1Fu
#define CMD_DOWNLOAD_DEBUG			0x20u
#define CMD_DBI_GET_TASKNR			0x21u
#define CMD_GET_PROJ_VERSION		0x22u
#define CMD_GET_PROJ_INFO			0x23u
#define CMD_LOAD_PROJECT			0x24u
#define CMD_SAVE_PROJECT			0x25u
#define CMD_CUSTOM					0x26u
#define CMD_LOAD_FILE				0x27u
#define CMD_SAVE_FILE				0x28u
#define CMD_DIR_CONTENT 			0x29u
#define CMD_OC_BEGIN				0x2Au
#define CMD_OC_CODE 				0x2Bu
#define CMD_OC_DEBUG				0x2Cu
#define CMD_OC_CUSTOM				0x2Du
#define CMD_OC_INITIAL				0x2Eu
#define CMD_OC_COMMIT				0x2Fu
#define CMD_OC_END					0x30u
#define CMD_OC_CONFIG				0x31u
#define CMD_OC_FINISH				0x32u
#define CMD_FLASH					0x33u
#define CMD_DEL_FILE				0x34u
#define CMD_GET_CONFIG				0x35u
#define CMD_RET_WRITE				0x36u
#define CMD_RET_CYCLE				0x37u
#define CMD_FW_DOWNLOAD 			0x38u
#define CMD_FW_EXECUTE				0x39u
#define CMD_FW_RESULT				0x3Au
#define CMD_RET_UPLOAD				0x3Bu
#define CMD_RET_DOWNLOAD			0x3Cu
#define CMD_IEC_UPLOAD				0x3Du
#define CMD_IEC_DOWNLOAD			0x3Eu
#define CMD_GET_INSTKEY 			0x3Fu
#define CMD_SET_LICKEY				0x40u
#define CMD_GET_SERIALNO			0x41u
#define CMD_GET_FEATURE 			0x42u
#define CMD_GET_TYPE				0x43u
#define CMD_GET_VERSION 			0x44u
#define CMD_SET_LICEX				0x45u
#define CMD_DOWNLOAD_IOL			0x46u
#define CMD_DOWNLOAD_CLEAR			0x47u

#define CMD_CT_GET_NAME				0x50u

#define LAST_CMD_VALUE				CMD_DOWNLOAD_CLEAR

static const char *cmdTextArray[] = {	\
        "State",			\
/* max. 8 chars */	"NYI",	\
        "Login",			\
        "Logout",			\
        "WrmStart", 		\
        "CldStart", 		\
        "StartAll", 		\
        "StopAll",			\
        "StartTsk", 		\
        "StopTask", 		\
        "OpenDbg",			\
        "CloseDbg", 		\
        "SetBP",			\
        "ClearBP",			\
        "ClearAll", 		\
        "SinglStp", 		\
        "Continue", 		\
        "GetValue", 		\
        "SetValue", 		\
        "DwnConf",			\
        "DwnInit",			\
        "DwnCode",			\
        "DwnCust",			\
        "DwnFin",			\
        "StartRes", 		\
        "StopRes",			\
        "DwnEnd",			\
        "DwnBegin", 		\
        "InitClr",			\
        "ClrFlash", 		\
        "DBIGChil", 		\
        "DBIGAddr", 		\
        "DwnDebug", 		\
        "GetTskNr", 		\
        "GetPrjVr", 		\
        "GetPrjIn", 		\
        "LoadPrj",			\
        "SavePrj",			\
        "Custom",			\
        "LoadFile", 		\
        "SaveFile", 		\
        "DirCont",			\
        "OcBegin",			\
        "OcCode",			\
        "OcDebug",			\
        "OcCustom", 		\
        "OcInit",			\
        "OcCommit", 		\
        "OcEnd",			\
        "OcConfig", 		\
        "OcFinish", 		\
        "Flash",			\
        "DelFile",			\
        "GetConf",			\
        "RetWrite", 		\
        "RetCycle", 		\
        "FWDown",			\
        "FWExec",			\
        "FWResult", 		\
        "RetUpld",			\
        "RetDown",			\
        "IECUpld",			\
        "IECDown",			\
        "GetIKey",			\
        "SetLKey",			\
        "GetSNo",			\
        "GetFeat",			\
        "GetType",			\
        "GetVers",			\
/* max. 8 chars */		"SetLicEx", 		\
        "ConfigIO", 		\
        "ClearCtl"			\
    };

static const char *cmdText(unsigned n)
{
    if (n <= LAST_CMD_VALUE) {
        return cmdTextArray[n];
    }
    return "wrong cmd";
}

// ----------------------------------------------------------------------------
// DBI data type masks

#define DBI_DTM_ARRAY				0x80u
#define DBI_DTM_OBJECT				0x40u
#define DBI_DTM_SIMPLE				0x20u


// ----------------------------------------------------------------------------
// DBI Data types

#define DBI_DT_UNKNOWN				0x1fu

#define DBI_DT_BOOL 				0x01u

#define DBI_DT_BYTE 				0x02u
#define DBI_DT_WORD 				0x03u
#define DBI_DT_DWORD				0x04u
#define DBI_DT_LWORD				0x05u

#define DBI_DT_USINT				0x06u
#define DBI_DT_UINT 				0x07u
#define DBI_DT_UDINT				0x08u
#define DBI_DT_ULINT				0x09u

#define DBI_DT_SINT 				0x0au
#define DBI_DT_INT					0x0bu
#define DBI_DT_DINT 				0x0cu
#define DBI_DT_LINT 				0x0du

#define DBI_DT_REAL 				0x0eu
#define DBI_DT_LREAL				0x0fu

#define DBI_DT_STRING				0x10u

#define DBI_DT_TIME 				0x11u

// ----------------------------------------------------------------------------
// General communication structures

#pragma pack(1) // <---= structures in this file MUST be compiled with one byte alignment!



struct XCommand
{
    unsigned char	byCommand;          /* Command or reply ID			*/
    unsigned char	bySequence;         /* Sequence number					*/

    unsigned char	pData[MAX_DATA];	/* Data buffer					*/
};

#define HD_COMMAND		(2 * sizeof(unsigned char))

struct XBlock
{
    unsigned short	uBlock;             /* Block number 					*/
    unsigned short	uLen;               /* Data length						*/
    unsigned char	byLast;             /* Last block in sequence			*/
    unsigned char	usSource;           /* Block source - VMM intern!		*/

    struct XCommand CMD;                /* Command / reply				*/
};

#define HD_BLOCK		(2 * sizeof(unsigned short) + 2 * sizeof(unsigned char) + HD_COMMAND)

struct XFrame
{
    unsigned char	byType;             /* Block type						*/
    unsigned char	byCRC;              /* Check sum						*/

    struct XBlock  	BLK;                /* Command / reply block 		*/
};

#define HD_FRAME		(2 * sizeof(unsigned char) + HD_BLOCK)

// ----------------------------------------------------------------------------
// Specific communication structures

struct XConfig
{
    unsigned char   usBigEndian;	/* TRUE, if target is Big Endian	*/
    unsigned char   usDummy;		/* Alignment dummy					*/
    unsigned short	uFirmware;      /* Firmware version 				*/
    unsigned short	uMaxData;		/* Comm. Buffer size (MAX_DATA) 	*/
    unsigned short	uAddConfig;     /* Size of Additional Config. Data	*/

    unsigned char	Reserved[100];  /* Reservered for future ussage 	*/
};

struct XGuid
{
    unsigned char	guid[VMM_GUID];  /* Project Global Unique ID */
};

struct XIndex
{
    unsigned char	index[CT_INDEX_SIZE];  /*CrossTable index struct */
};

#define VMM_XV_BITMASK				0x0fu		/* To extract bit offset	*/
#define VMM_XV_TYPEMASK 			0xf0u		/* To extract var. type 	*/

#define VMM_XV_SMALL				0x20u		/* Variable is small type	*/
#define VMM_XV_MEDIUM				0x40u		/* Variable is medium type	*/
#define VMM_XV_LARGE				0x80u		/* Variable is large type	*/

struct	XVariableS
{
    unsigned char	usType;         /* Type (S,M,L) and bit offset		*/
    unsigned char	usSegment;      /* Segment number of the variable	*/
    unsigned char	usOffset;		/* Offset in the segment			*/
    unsigned char	usLen;          /* Size of var. in bytes, 1 for bit */
};

struct	XVariableM
{
    unsigned char	usType;         /* Type (S,M,L) and bit offset		*/
    unsigned char	usSegment;      /* Segment number of the variable	*/
    unsigned short	uOffset;		/* Offset in the segment			*/
    unsigned short	uLen;			/* Size of var. in bytes, 1 for bit */
};

struct	XVariableL
{
    unsigned char	usType;         /* Type (S,M,L) and bit offset		*/
    unsigned char	byDummy;		/* Alignment - Dummy				*/
    unsigned short	uLen;			/* Size of var. in bytes, 1 for bit */
    unsigned        ulOffset;		/* Offset in the segment			*/
    unsigned short	uSegment;		/* Segment number of the variable	*/
};

struct  XVariable
{
    unsigned int    ulOffset;		/* Offset in the segment			*/
    unsigned short	uLen;			/* Size of var. in bytes, 1 for bit */
    unsigned short	uSegment;		/* Segment number of the variable	*/
    unsigned char	byBit;          /* Bit offset						*/
    unsigned char	byDummy;		/* Alignment - Dummy				*/

};

struct  XValue
{
    struct XVariable	VAR;    	/* Variable description 			*/
    uint32_t value;  /* Placeholder for variable value	*/
};

#pragma pack()

////////////////////////////////////////
/////////////LogList Struct/////////////
////////////////////////////////////////

////////////////////////////////////////
////////////////////////////////////////





// ----------------------------------------------------------------------------
// communication via TCP/IP to MECT TP/TPAC/TPLC at given address and port
// usage:
//     1) x = new mectComm();
//     2) X->startConnect(QList,IDs,Address,Port,Period_ms)
//     3) x->startTimerMect();
//     4) x->getValue(193, value);
//     5) x->doWrite(193, value + 1);
//
void  mectComm::startConnect(QList<uint16_t > IDs,
                            QObject *parent = 0,//nullptr,
                            const QHostAddress &address = QHostAddress("192.168.5.165"),
                            quint16 port = 17290,
                            int period_ms = 500)
{
   this->IDs=IDs;
   this->parent=parent;
   this->address=address;
   this->port=port;
   this->period_ms=(period_ms >= 100)?period_ms:100;
   this->tcpSocket=(new QTcpSocket(this));

    status = MectComm_Idle;
    //////////
    sequence = 0;
    //QueryFlag=0;
    dataCount=0;

    //////////
    for (uint16_t n = 0; n <= DimCrossTable; ++n) {
        values[n] = 0;
    }
    reads = writes = commands = errors = 0;
    tcpSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    tcpSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);

    //timerId = startTimer(200);
    //if(hostFlag)
   // timerId = startTimer(this->period_ms);
}

void mectComm::startTimerMect(){
    timerId = startTimer(this->period_ms);
}

void mectComm::stopTimerMect(){
    killTimer(timerId);
    tcpSocket->close();
}
// ----------------------------------------------------------------------------

mectComm::~mectComm()
{
    killTimer(timerId);

    switch (status) {

    case MectComm_Idle:
        break;

    case MectComm_Connected:
        break;

    case MectComm_Ready:
        break;

    case MectComm_Error:
        break;

    default:
        ;
    }
    tcpSocket->abort();
}

// ----------------------------------------------------------------------------

void mectComm::timerEvent(QTimerEvent *event)
{
    if (event->timerId() != timerId) {
        qDebug() << "got spurious timerEvent ID:" << event->timerId();
        return;
    }

    switch (status) {

    case MectComm_Idle:
        if (! connect()) {
            break;
        }
        status = MectComm_Connected;
        break;

    case MectComm_Connected:
    {
        // 1. get config
        struct XConfig config;
        if (! getConfig(config)) {
            break;
        }
        qDebug() << address <<endl
                 << "getConfig(): ok"
                 << ", usBigEndian=" << config.usBigEndian
                 << ", uFirmware=" << config.uFirmware
                 << ", uMaxData=" << config.uMaxData
                 << ", uAddConfig=" << config.uAddConfig
                ;

        // 2. get project version
        struct XGuid guid;
        if (! getProjectVersion(guid)) {
            break;
        }
        qDebug() << "getProjectVersion(): ok"
                 << ", guid=" << guid.guid
                ;

        // 3. login
        if (! doLogin(guid)) {
            break;
        }
        qDebug() << "doLogin(): ok";


        //custom CMD
         struct XIndex index;
         memcpy(&index, "193", sizeof(struct XGuid));
        if (! customCMD(index)) {
            break;
        }
        qDebug() << "customCMD(): ok";


        //custom CMD

//        // 4. get project children at root level
//        struct XBlock children;
//        if (! getRootChildren(children)) {
//            break;
//        }
//        qDebug() << "getRootChildren(): ok, uLen=" << children.uLen;
//        {
//            unsigned n = 0;
//            unsigned skip = 0;

//            variables.clear();
//            while (skip < children.uLen) {
//                n += 1;
//                struct XDBIVar *ptr = (struct XDBIVar *)&children.CMD.pData[skip];
//                char *name = (char *)&children.CMD.pData[skip + sizeof(struct XDBIVar)];

//                switch(ptr->usType & 0xE0u) {
//                case DBI_DTM_SIMPLE: {
//                    struct mectVariable tmp;
//                    QString qname = QString(name);
//                    QString qtype;

//                    switch(ptr->usType & ~0xE0u)
//                    {
//                        case DBI_DT_BOOL	: qtype = QString("bool");		break;
//                        case DBI_DT_BYTE	: qtype = QString("byte");		break;
//                        case DBI_DT_WORD	: qtype = QString("word");		break;
//                        case DBI_DT_DWORD	: qtype = QString("dword");		break;
//                        case DBI_DT_LWORD	: qtype = QString("lword");		break;
//                        case DBI_DT_USINT	: qtype = QString("usint");		break;
//                        case DBI_DT_UINT	: qtype = QString("uint");		break;
//                        case DBI_DT_UDINT	: qtype = QString("udint");		break;
//                        case DBI_DT_ULINT	: qtype = QString("ulint");		break;
//                        case DBI_DT_SINT	: qtype = QString("sint");		break;
//                        case DBI_DT_INT 	: qtype = QString("int"); 		break;
//                        case DBI_DT_DINT	: qtype = QString("dint");		break;
//                        case DBI_DT_LINT	: qtype = QString("lint");		break;
//                        case DBI_DT_REAL	: qtype = QString("real");		break;
//                        case DBI_DT_LREAL	: qtype = QString("lreal");		break;
//                        case DBI_DT_STRING	: qtype = QString("string");   break;
//                        case DBI_DT_TIME	: qtype = QString("time");		break;
//                        default 			: qtype = QString("???");
//                    }
//                /*   qDebug() << QString("#%1 VARIABLE %2 type=0x%3(%4) inst=%5 offs=%6 len=%7 bit=%8")
//                               .arg(n)
//                               .arg(qname)
//                               .arg(ptr->usType, 0, 16)
//                              .arg(qtype)
//                               .arg(ptr->uInst)
//                               .arg(ptr->ulOffset)
//                               .arg(ptr->uLen)
//                               .arg(ptr->usBit)
//                               ;*/


//                    if (ptr->uInst <= 1) {
//                        uint16_t ID = ptr->ulOffset / 4;


//                     //  for (int i = 0; i < IDs.count(); ++i) {
//                       //     if (ID == IDs[i]) {
//                                tmp.name = qname;
//                                tmp.ID = ID;
//                                memcpy(&tmp.dbi, ptr, sizeof(struct XDBIVar));
//                                variables.append(tmp);
//                                allVariables.append(qname);
//                               /* qDebug() << QString("=+++> variables[%1]: ID=%2 name=%3 type=%4 usType=0x%5 inst=%6 offs=%7 len=%8 bit=%9")
//                                            .arg(variables.count() - 1)
//                                            .arg(tmp.ID)
//                                            .arg(tmp.name)
//                                            .arg(qtype)
//                                            .arg(tmp.dbi.usType, 0, 16)
//                                            .arg(tmp.dbi.uInst)
//                                            .arg(tmp.dbi.ulOffset)
//                                            .arg(tmp.dbi.uLen)
//                                            .arg(tmp.dbi.usBit)
//                                            ;*/
//                               // break;
//                           // }
//                        //}
//                    }
//                }   break;

//                case DBI_DTM_OBJECT:
////                    qDebug() << QString("#%1 OBJECT %2")
////                                .arg(n)
////                                .arg(QString(name));
//                    break;

//                case DBI_DTM_ARRAY:
////                    qDebug() << QString("#%1 ARRAY %2 [%3]")
////                                .arg(n)
////                                .arg(QString(name))
////                                .arg(ptr->uLen);
//                    break;

//                default:
//                    qDebug() << QString("#%1 INVALID %2");
//                }
//                skip += sizeof(struct XDBIVar) + ptr->usNameSize + 1;
//            }
//        }
//        emit crossTableVarReady();
//        // 5. change status
//        status = MectComm_Ready;
//        break;
//    }


    case MectComm_Ready:
        if (! readAll()) {
            status = MectComm_Error;
            break;
        }
        break;

    case MectComm_Error:
        // from readAll() or doWrite()
        status = MectComm_Idle;
        break;

    default:
        ;
    }
 }
}

// ----------------------------------------------------------------------------
QList <QString> mectComm::getVariableList(){
    return allVariables;
}
uint16_t mectComm::getVariableID(QString varName){

    for(int index=0;index<variables.count();index++){
        if(varName==variables.at(index).name){
            return variables.at(index).ID;
        }
    }

    return 0;////// da rivedere
}

// ----------------------------------------------------------------------------


bool mectComm::connect(void)
{
    bool retval;

    tcpSocket->abort();
    tcpSocket->connectToHost(address, port);
    if (! tcpSocket->waitForConnected(VIS_TCP_TIMEOUT)) {
        qDebug() << "connection timeout to: " << address << ":" << port;
        tcpSocket->abort();
        retval = false;
        goto exit_function;
    }
    retval = true;

exit_function:
    return retval;
}

// ----------------------------------------------------------------------------

bool mectComm::getConfig(struct XConfig &config)
{
    bool retval;
    XBlock command, reply;

    command.CMD.byCommand = CMD_GET_CONFIG;
    command.uBlock = 1;
    command.uLen = 0;
    command.byLast = 1;
    command.usSource = 0;

    if (! doCommand(command, reply) || reply.uLen != sizeof(struct XConfig)) {
        retval = false;
        goto exit_function;
    }
    memcpy(&config, &reply.CMD.pData[0], sizeof(struct XConfig));
    retval = true;

exit_function:
    return retval;
}

bool mectComm::getProjectVersion(XGuid &guid)
{
    bool retval;
    XBlock command, reply;

    command.CMD.byCommand = CMD_GET_PROJ_VERSION;
    command.uBlock = 1;
    command.uLen = 0;
    command.byLast = 1;
    command.usSource = 0;

    if (! doCommand(command, reply) || reply.uLen != sizeof(struct XGuid)) {
        retval = false;
        goto exit_function;
    }
    memcpy(&guid, &reply.CMD.pData[0], sizeof(struct XGuid));
    retval = true;

exit_function:
    return retval;
}

bool mectComm::getRootChildren(XBlock &children)
{
    bool retval;
    XBlock command;
    struct XDBIVar *ptr;

    command.CMD.byCommand = CMD_DBI_GET_CHILDREN;
    command.uBlock = 1;
    command.uLen = sizeof(struct XDBIVar) + 0 + 1;
    command.byLast = 1;
    command.usSource = 0;

    ptr = (struct XDBIVar *)&command.CMD.pData[0];
    ptr->usNameSize = 0;
    ptr->uInst = 0xffff;

    if (! doCommand(command, children)) {
        retval = false;
        goto exit_function;
    }
    retval = true;

exit_function:
    return retval;
}

bool mectComm::customCMD(XIndex &index)
{
    bool retval;
    XBlock command, reply;;


    command.CMD.byCommand = CMD_CT_GET_NAME;
    command.uBlock = 1;
    command.uLen =  1;
    command.byLast = 1;
    command.usSource = 0;


    memcpy(&command.CMD.pData[0], &index, sizeof(struct XIndex));
    qDebug()<<&command.CMD.pData;
    qDebug()<<&index;
    if (! doCommand(command,reply)) {
        retval = false;
        goto exit_function;
    }
    retval = true;

exit_function:
    return retval;
}



bool mectComm::doLogin(XGuid &guid)
{
    bool retval;
    XBlock command, reply;

    command.CMD.byCommand = CMD_LOGIN;
    command.uBlock = 1;
    command.uLen = sizeof(struct XGuid);
    command.byLast = 1;
    command.usSource = 0;
    memcpy(&command.CMD.pData[0], &guid, sizeof(struct XGuid));

    if (! doCommand(command, reply) || reply.uLen != 0) {
        retval = false;
        goto exit_function;
    }
    retval = true;

exit_function:
    return retval;
}

bool mectComm::doLogout()
{
    bool retval;
    XBlock command, reply;

    command.CMD.byCommand = CMD_LOGOUT;
    command.uBlock = 1;
    command.uLen = 0;
    command.byLast = 1;
    command.usSource = 0;

    if (! doCommand(command, reply) || reply.uLen != sizeof(struct XGuid)) {
        retval = false;
        goto exit_function;
    }
    retval = true;

exit_function:
    return retval;
}

bool mectComm::readAll()
{
    bool retval = false;
    XBlock command, reply;
    unsigned reply_uLen = 0;

    command.CMD.byCommand = CMD_GET_VALUE;
    command.uBlock = 1;
    command.uLen = 0;
    command.byLast = 1;
    command.usSource = 0;

    for (int i = 0; i < variables.count(); ++i) {
        // compute varsize
        unsigned short uDataLen = variables[i].dbi.uLen;
        unsigned uDataOffset = variables[i].dbi.ulOffset;
        unsigned short uDataInst = variables[i].dbi.uInst;
        unsigned char uDataBit = variables[i].dbi.usBit;

        if ((variables[i].dbi.usType & ~0xE0u) == DBI_DT_STRING) {
            uDataLen += 2;
        }
        if (uDataOffset <= 0xffu && uDataLen <= 0xffu && uDataInst <= 0xffu) {
            if ((command.uLen + sizeof(XVariableS)) <= MAX_DATA) {
                struct XVariableS *ptrS = (struct XVariableS *)&command.CMD.pData[command.uLen];

                ptrS->usType	= (unsigned char)(VMM_XV_SMALL | (uDataBit & VMM_XV_BITMASK));
                ptrS->usOffset 	= (unsigned char)uDataOffset;
                ptrS->usLen		= (unsigned char)uDataLen;
                ptrS->usSegment	= (unsigned char)uDataInst;
                command.uLen += sizeof(XVariableS);
            } else {
                qDebug() << "readAll(): cannot ask for " << variables[i].name;
            }
        }
        else if (uDataOffset <= 0xFFffu && uDataInst <= 0xffu) {
            if ((command.uLen + sizeof(XVariableM)) <= MAX_DATA) {
                struct XVariableM *ptrM = (struct XVariableM *)&command.CMD.pData[command.uLen];

                ptrM->usType	= (unsigned char)(VMM_XV_MEDIUM | (uDataBit & VMM_XV_BITMASK));
                ptrM->uOffset 	= (unsigned short)uDataOffset;
                ptrM->uLen		= uDataLen;
                ptrM->usSegment	= (unsigned char)uDataInst;
                command.uLen += sizeof(XVariableM);
            } else {
                qDebug() << "readAll(): cannot ask for " << variables[i].name;
            }
        }
        else {
            if ((command.uLen + sizeof(XVariableL)) <= MAX_DATA) {
                struct XVariableL *ptrL = (struct XVariableL *)&command.CMD.pData[command.uLen];

                ptrL->usType	= (unsigned char)(VMM_XV_LARGE | (uDataBit & VMM_XV_BITMASK));
                ptrL->ulOffset 	= uDataOffset;
                ptrL->uLen		= uDataLen;
                ptrL->uSegment	= uDataInst;
                command.uLen += sizeof(XVariableL);
            } else {
                qDebug() << "readAll(): cannot ask for " << variables[i].name;
            }
        }

        reply_uLen += (uDataLen == 0) ? 1 : uDataLen;
        if (command.uLen > MAX_DATA || reply_uLen > MAX_DATA) {
            qDebug() << "readAll() error: too many variables";
            goto exit_function;
        }
    }

    retval = doCommand(command, reply);
    ++reads;
    if (retval) {
        unsigned x = 0;

        for (int i = 0; i < variables.count(); ++i) {
            unsigned n = variables[i].ID;

            if (n > DimCrossTable) {
                qDebug() << QString("readAll() error: variable %1 has wrong ID %2")
                    .arg(variables[i].name).arg(QString::number(n));
                goto exit_function;
            }
            switch(variables[i].dbi.usType & ~0xE0u) {
            case DBI_DT_BOOL:
                values[n] = (reply.CMD.pData[x] != 0);
                x += 1;
                break;
            case DBI_DT_BYTE:
            case DBI_DT_USINT:
                values[n] = reply.CMD.pData[x];
                x += 1;
                break;
            case DBI_DT_WORD:
            case DBI_DT_UINT:
            case DBI_DT_INT:
                values[n] = reply.CMD.pData[x] + (reply.CMD.pData[x + 1] << 8);
                x += 2;
                break;
            case DBI_DT_DWORD:
            case DBI_DT_UDINT:
            case DBI_DT_DINT:
            case DBI_DT_REAL:
                values[n] = reply.CMD.pData[x] + (reply.CMD.pData[x + 1] << 8)
                          + (reply.CMD.pData[x + 2] << 16) + (reply.CMD.pData[x + 3] << 24);
                x += 4;
                break;
            default:
                qDebug() << QString("readAll() error: variable %1 has unknown type %2")
                    .arg(variables[i].name).arg(QString::number(variables[i].dbi.usType & ~0xE0u));
                goto exit_function;
            }
        }
    }

exit_function:
    return retval;
}

bool mectComm::doWrite(uint16_t ID, uint32_t value)
{
    bool retval;
    XBlock command, reply;
    int j = -1;

    for (int i = 0; i < variables.count(); ++i) {
        if (ID == variables[i].ID) {
            j = i;
            break;
        }
    }
    if (j < 0) {
        qDebug() << QString("doWrite(): wrong ID=%1").arg(ID);
        retval = false;
        goto exit_function;
    }
    command.uBlock = 1;
    command.uLen = sizeof(struct XValue);
    command.byLast = 1;
    command.usSource = 0;
    command.CMD.byCommand = CMD_SET_VALUE;

    struct XValue *ptr;
    ptr = (struct XValue *)&command.CMD.pData[0];
    ptr->VAR.uLen = variables[j].dbi.uLen;
    ptr->VAR.ulOffset = variables[j].dbi.ulOffset;
    ptr->VAR.uSegment = variables[j].dbi.uInst;
    ptr->VAR.byBit = variables[j].dbi.usBit;
    ptr->VAR.byDummy = 0;
    ptr->value = value;

    qDebug() << QString("doWrite(ID=%1, value=%2): name=%3 type=%4 inst=%5 offs=%6 len=%7 bit=%8")
                .arg(ID)
                .arg(value)
                .arg(variables[j].name)
                .arg(variables[j].dbi.usType)
                .arg(variables[j].dbi.uInst)
                .arg(variables[j].dbi.ulOffset)
                .arg(variables[j].dbi.uLen)
                .arg(variables[j].dbi.usBit)
                ;
    retval = doCommand(command, reply);
    if (! retval) {
        status = MectComm_Error;
    }

exit_function:
    ++writes;
    return retval;
}

// ----------------------------------------------------------------------------

bool mectComm::doCommand(struct XBlock &command, struct XBlock &reply)
{
    bool retval;

    mutex.lock();

    command.CMD.bySequence = ++sequence;

  // qDebug()<<"Command==>"<<command.byLast<<" "<<command.CMD.byCommand<<" "<<command.uBlock<<" "<<command.uLen<<" "<<command.usSource<<" ";
    if (! doSend(command)) {
        retval = false;
        qDebug() << QString("doCommand(), send error: command=%1").arg(cmdText(command.CMD.byCommand));
        goto exit_function;
    }
    //qDebug()<<"Reply==>"<<reply.byLast<<" "<<reply.CMD.byCommand<<" "<<reply.uBlock<<" "<<reply.uLen<<" "<<reply.usSource<<" ";
    if (! doRecv(reply)) {
        retval = false;
        qDebug() << QString("doCommand(), recv error: command=%1").arg(cmdText(command.CMD.byCommand));
        goto exit_function;
    }
    // check reply: received command must equal the sent command
    if ((reply.CMD.byCommand & 0x7fu) != (command.CMD.byCommand & 0x7fu)) {
        retval = false; // ERR_INVALID_COMMAND
        qDebug() << QString("doCommand() ERR_INVALID_COMMAND: command=%1 recv=%2")
                 .arg(cmdText(command.CMD.byCommand)).arg(reply.CMD.byCommand & 0x7fu);
        goto exit_function;
    }
    // check reply: a negative command signals an error from the RTS.
    if (reply.CMD.byCommand & 0x80u)                                    // ///////// c'è solo l'and & e niente altro
    {
        qDebug()<<(reply.CMD.byCommand & 0x80u) << QString("<-------")<<(command.CMD.byCommand & 0x80u);
        retval = false; // error code is in reply.CMD.pData[0..1]
        unsigned short errcode = reply.CMD.pData[0] + (reply.CMD.pData[1] << 8);
        qDebug() << QString("doCommand() ERROR: command=%1 errcode=0x%2")
                 .arg(cmdText(command.CMD.byCommand)).arg(errcode, 0, 16);
        goto exit_function;
    }
    retval = true;

exit_function:
    ++commands;
    if (!retval)
        ++errors;

    mutex.unlock();
    return retval;
}

bool mectComm::doSend(struct XBlock &command)
{
    qint64 len = HD_BLOCK + command.uLen;
    qint64 retval = tcpSocket->write((char *)&command, len);

    if (retval < 0) {
        qDebug() << "doSend() communication error";
        return false;
    }
    if (retval != len) {
        qDebug() << "doSend() error retval=" << retval << " expected=" << len;
        return false;
    }
    tcpSocket->flush();
    return true;
}

bool mectComm::doRecv(struct XBlock &reply)
{
    //QCoreApplication::processEvents();VIS_TCP_TIMEOUT
    if (! tcpSocket->waitForReadyRead(VIS_TCP_TIMEOUT)) {
        qDebug() << "doRecv() timeout";
        tcpSocket->abort();
        return false;
    }
    qint64 maxlen = HD_BLOCK + MAX_DATA;
    qint64 len = 0;
    qint64 retval;
    char *ptr = (char *)&reply;

    retval = tcpSocket->read(ptr, maxlen);
    if (retval < 0) {
        qDebug() << "doRecv() communication error";
        tcpSocket->abort();
        return false;
    }
   if (retval < (qint64)HD_BLOCK) {
        qDebug() << "doRecv() error retval=" << retval;
        tcpSocket->abort();
        return false;
    }
    len = retval;
    maxlen = HD_BLOCK + reply.uLen;

    while (len < maxlen) {
        //QCoreApplication::processEvents();
        if (! tcpSocket->waitForReadyRead(VIS_TCP_TIMEOUT)) {
            qDebug() << "doRecv() timeout";
            tcpSocket->abort();
            return false;
        }
        retval = tcpSocket->read(&ptr[len], (maxlen - len));
        if (retval < 0) {
            qDebug() << "doRecv() communication error";
            tcpSocket->abort();
            return false;
        }
        if (retval <= 0) {
            qDebug() << "doRecv() error retval=" << retval << " len=" << len;
            tcpSocket->abort();
            return false;
        }
        len += retval;
    }
    return true;
}

// ----------------------------------------------------------------------------


////////////////////////////////////////////////
/////////////CircularBuffer Methods/////////////
////////////////////////////////////////////////
void mectComm::initBuffer()
{
  readIndex=0;
  readIndexTime=0;
  writeIndex = 0;
}

void mectComm::writeXTime(double data, double timeIn,int index)
{
    if(writeIndex == SizeBuffer)
    {
        writeIndex = 0;
    }
    bufferX[index][writeIndex]=data;
    bufferTime[index][writeIndex]=timeIn;
   // qDebug()<<writeIndex<<"---"<<bufferX[writeIndex]<<"****";
    writeIndex++;

}

double mectComm::readY(int index)
{
    if(readIndex == SizeBuffer)
    {
        readIndex = 0;
    }
    double val = bufferX[index][readIndex];
   // qDebug()<<readIndex<<"++++"<<bufferX[readIndex]<<"....";
    readIndex++;
    return val;
}

double mectComm::readTime(int index)
{
    if(readIndexTime == SizeBuffer)
    {
        readIndexTime = 0;
    }
    int val = bufferTime[index][readIndexTime];
    readIndexTime++;

    return val;
}

bool mectComm::checkIndex()
{    static bool x;
    if(writeIndex==MIN_BUFFER_CHECK)
    {x=true;}
   else
    {x=false;}
     return x;
}


void mectComm::readBufferPoints(double &x,double &y,int index)
{
 x=readTime(index);
 y=readY(index);
}
////////////////////////////////////////////////
////////////////////////////////////////////////




////////////////////////////////////////////////
/////////////LogList Methods////////////////////
////////////////////////////////////////////////
void mectComm::setLogList(mectLogRow rowStruct)
{
    rows.append(rowStruct);
}

void mectComm::clearLogList()
{
  for(int i=0;i<rows.count();i++){
  for(int j=0;j<rows[j].columns.count();j++)
  {
       rows[j].columns.removeAt(j);
       rows[j].columns.clear();
  }
  rows.removeAt(i);
  rows.clear();
}
  clearDateCounter();
}

mectNameValue mectComm::setNameValue(QString name,QString value)
{
  mectNameValue MectNameValue;//= new mectNameValue();
  MectNameValue.name=name;
  MectNameValue.value=value;
  return MectNameValue;
}

QString mectComm::getLogList()
{
    QString tmp=0;
    if(rows.count()>0){
    for(int i=0;i<rows.count();i++)
    {
       tmp=tmp+ rows[i].dateTime.toString()+"\n";
        for(int j=0;j<rows[i].columns.count();j++)
        {
        tmp+=rows[i].columns[j].name+ " " +rows[i].columns[j].value+"\n";
        }
     }
    }else{
        qDebug()<<"MectComm::getLogList() Error: List is empty";
        emit errorSignal ("MectComm::getLogList() Error: List is empty");
    }
    return tmp;
}

int mectComm::getVariableData(int rowIndexVar )
{
 if(rowIndexVar>rows.count())
   {
     qDebug()<<"DateTime Index ERROR";
     emit errorSignal ("MectComm::getVariableData() Error: DateTime Index ERROR");
     return -1;
   }
 else
   {
   return rows[rowIndexVar].dateTime.toTime_t();
   }
 }

QString mectComm::getVariableValue(int rowIndexVar, QString varName){

  QString noVal="noValue";
  int noValCount=0;


  if(rowIndexVar>rows.count())
    {
      qDebug()<<"Value Index ERROR";
      emit errorSignal ("MectComm::getVariableValue() Error : Value Index ERROR");
      //return noVal;
    }
  else
  {

      for(int colIndexVar=0;colIndexVar<rows[rowIndexVar].columns.count()+1;colIndexVar++)
        {

          if(noValCount==rows[rowIndexVar].columns.count())
            {
               //qDebug()<<"noval- "<<colIndexVar;

              return noVal;
            }
          else if(varName==rows[rowIndexVar].columns[colIndexVar].name)
            {

             //qDebug()<<rows[rowIndexVar].columns[colIndexVar].value<<"--"<<colIndexVar;
              return rows[rowIndexVar].columns[colIndexVar].value;
            }
          noValCount++;
        }
    }
  return noVal;
}


QDateTime mectComm::getQueryDateFrom(){
return Query.from;
}

QDateTime mectComm::getQueryDateTo(){
  return Query.to;
}

QList <QString> mectComm::getQueryVariables(){

 return Query.variables;

}

int mectComm::getQueryCount(){

    if(Query.variables.count()>=0){

        return Query.variables.count();

    }else{
        qDebug()<<"MectComm::getQueryCount(): Query.variables.count() is : "<<Query.variables.count();
        emit errorSignal ("MectComm::getQueryCount() Error : Query.variables.count() is :" + Query.variables.count());
        return 0;
    }
}


bool mectComm::dateControl(QDateTime date)
{
  if((date.toMSecsSinceEpoch()>=Query.from.toMSecsSinceEpoch() &&
      date.toMSecsSinceEpoch()<=Query.to.toMSecsSinceEpoch())==true){
      return true;
    }else{
      return false;
    }
}

void mectComm::setdateCounter()
{
  dataCount++;
}

int mectComm::getdateCounter()
{
    if(dataCount>=0){

    return dataCount;

    }else{
        qDebug()<<"Error: dataCount is : "<<dataCount;
        emit errorSignal ("MectComm::getdateCounter() Error : dataCount is :" + dataCount);
        return 0;
    }
}
void mectComm::clearDateCounter()
{
  dataCount=0;
}

/////////////////////////////////////////
//////////JSON PARSER////////////////////
/////////////////////////////////////////
bool mectComm::readLog(QString replyText)
{

    QTextStream line(&replyText);
    QString currentData;
    QDateTime currentDate;

    bool arrayFlag=false;
    QDateTime tmp;



    line>>currentData;

    if(currentData=="{"){
        line>>currentData;
    }
    else{

        return false;
    }

    if(currentData=="\"query\":"){
        line>>currentData;

        if(currentData=="{"){
            line>>currentData;
        }else{

            return false;
        }

        if(currentData=="\"QUERY_STRING\":"){
            line>>currentData;
            line>>currentData;
        }else{

            return false;
        }

        if(currentData=="\"from\":"){

            line>>currentData;
            tmp=QDateTime::fromString(currentData,"\"yyyy-MM-ddTHH:mm:ss\",");
            if(tmp.isValid())
                Query.from=tmp;

            line>>currentData;
        }else{

            return false;
        }
        if(currentData=="\"to\":"){

            line>>currentData;
            tmp=QDateTime::fromString(currentData,"\"yyyy-MM-ddTHH:mm:ss\",");
            if(tmp.isValid())
                Query.to=tmp;
            line>>currentData;

        }else{

            return false;
        }

        if(currentData=="\"variables\":"){

            line>>currentData;

            if(currentData=="["){

                line>>currentData;

                while(currentData!="]"){

                    currentData.remove("\"");
                    currentData.remove(",");

                    //if(currentData!=""){

                    Query.variables.append(currentData);

                    // }

                    line>>currentData;
                }
                line>>currentData;
            }else{

                return false;
            }
        }
        else{

            return false;
        }
    }
    else{

        return false;
    }

    if(currentData=="}"){
        line>>currentData;
    }
    else{

        return false;
    }


    if(currentData=="}"&& queryChar){

        emit variablesReady();
        return true;

    }else {

        while(!line.atEnd ()){

            line>>currentData;

            if(arrayFlag){

                if(currentData[0]=='['){

                    currentData.remove("[");
                    currentData.remove("]");

                    QStringList dataList = currentData.split(",");
                    //qDebug()<<dataList;

                    mectLogRow MectLogRow;
                    MectLogRow.dateTime=currentDate;

                    for(int i=0;i<dataList.count();i++)
                    {
                        if(dataList.at(i)!=""){

                            //qDebug()<<Query.variables[i];
                            MectLogRow.columns.append(setNameValue(Query.variables[i],dataList.at(i)));
                            //
                        }
                    }
                    setLogList(MectLogRow);
                    arrayFlag=false;
                }
            }else{

                QDateTime date=QDateTime::fromString(currentData,"\"yyyy-MM-ddTHH:mm:ss\":");

                if(date.isValid()){

                    if(dateControl(date)){
                        setdateCounter();
                        currentDate=date;
                        arrayFlag=true;
                    }
                }
                QCoreApplication::processEvents();
            }
        }

        emit dataReady ();
        return true;
    }

    return false;
}
////////////////////////////////////////////////
////////////////////////////////////////////////


////////////////////////////////////////////////
/////////////HTTP&JSON Methods//////////////////
////////////////////////////////////////////////
void mectComm::requestShowPage(QUrl newUrl)
{
   qDebug()<<"Download Page constructor called";
   int pos=newUrl.toString().count();
   qDebug()<<newUrl;
   if(newUrl.toString().at(pos-1)=='*'){
       queryChar=true;
   }else{
       queryChar=false;
   }
   manager = new QNetworkAccessManager(this);
   manager->get(QNetworkRequest(QUrl(newUrl)));
   QObject::connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestReceived(QNetworkReply*)));

}


void mectComm::requestReceived(QNetworkReply *reply)
{
     qDebug()<<"Page call finished";

     if(reply->error() == QNetworkReply::NoError)
     {
         // Get the http status code
         int v = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

         if (v >= 200 && v < 300) // Success
         {
             readLog(reply->readAll());//JSon Parser
         }
         else if (v >= 300 && v < 400 ) // Redirection
         {
             // Get the redirection url
             QUrl newUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
             // Because the redirection url can be relative,
             // we have to use the previous one to resolve it
             newUrl = reply->url().resolved(newUrl);

             QNetworkAccessManager *manager = reply->manager();
             QNetworkRequest redirection(newUrl);
             //QNetworkReply *newReply = manager->get(redirection);
             reply=  manager->get(redirection);

             return; // to keep the manager for the next request
         }
         else
         {
             // Error
             qDebug()<<reply->errorString();
             emit errorSignal("HTTP-Request error: "+ reply->errorString());
         }

         reply->manager()->deleteLater();
     }else{

         qDebug()<<reply->errorString();
         emit errorSignal("HTTP-Request error: "+ reply->errorString());

     }

}

bool mectComm::openConnection(QString IP){

    QHostAddress currentIP;

    if(currentIP.setAddress (IP)){

    QString currentURL="http://"+IP+"/get_log.cgi";

    QUrl currentUrl(currentURL);

    requestShowPage (currentUrl);

    return true;

   }else{

        emit errorSignal ("mectComm::requestVariableList: \n Wrong IP");
        return false;
   }

}

bool mectComm::requestVariableList(QString IP){

    QHostAddress currentIP;

    if(currentIP.setAddress (IP)){

    QString currentURL="http://"+IP+"/get_log.cgi?vars=*";

    QUrl currentUrl(currentURL);

    requestShowPage (currentUrl);

    return true;

   }else{

        emit errorSignal ("mectComm::requestVariableList: \nWrong IP");
        return false;
   }
}


bool mectComm::requestValueList(QString IP,QDateTime fromDate,QDateTime toDate, QString delta_Ts,QStringList varList){

    clearLogList();


    QHostAddress currentIP;

    if(currentIP.setAddress (IP)){

        if(varList.count()>0){


            if(toDate>fromDate){


            QString from=fromDate.toTimeSpec(Qt::OffsetFromUTC).toString(Qt::ISODate);
            QString to=toDate.toTimeSpec(Qt::OffsetFromUTC).toString(Qt::ISODate);

            if(delta_Ts.toInt ()>0){

                QString newUrl="http://"+IP+"/get_log.cgi"+"?from="+from+"&to="+to+"&delta_s="+delta_Ts+"&vars=";


                for(int i=0;i<varList.count();i++){

                    newUrl.append (varList.at(i));
                    newUrl.append (",");
                }

                QUrl currentUrl(newUrl);
                qDebug()<<currentUrl;

                Query.variables.clear ();

                requestShowPage (currentUrl);

                return true;


            }else{
                emit errorSignal ("mectComm::requestValueList(): \n Wrong Delta_Ts");
                return false;
            }
            }else{
                emit errorSignal ("mectComm::requestValueList(): \n to date time <= from date time");
                return false;
            }
        }else{

            emit errorSignal ("mectComm::requestValueList(): \n variable List is Empty");
            return false;
        }

    }else{

        emit errorSignal ("mectComm::requestVariableList: \n Wrong IP");
        return false;
    }
}


bool mectComm::getVariableList(QStringList &variableList){

    variableList.clear();

    if(!Query.variables.isEmpty ()){

        variableList=Query.variables;
        return 0;
    }else{
        qDebug()<<"MectComm::getVariableList(QStringList): Query.variables List is Empty ";
        emit errorSignal ("MectComm::getQueryVariables(QStringList) Error : \n Query.variables List is Empty");
        return 1;
    }
}

bool mectComm::getDataCount(int &dataCount){

    if(this->dataCount>0){
        dataCount=this->dataCount;
        return 0;
    }else{
        qDebug()<<"MectComm::getDataCount(int): data Count is not valid [ "<<QString::number (dataCount)<<" ]";
        emit errorSignal ("MectComm::getDataCount(int): data Count is not valid [ "+ QString::number (dataCount)+" ]");
        return 1;
    }
}


 bool mectComm::getValueVector(QStringList varList,QList <QList<varPoint > > &dataStruct)
 {
     dataStruct.clear ();
     QList<varPoint> tmpListStruct;
     int i=0;
     int j=0;
     varPoint tmpVar;

     tmpListStruct.clear ();

     for(int j=0;j<varList.count();j++){

         dataStruct.append (tmpListStruct);

     }
     if( ! rows.isEmpty () )  {

         for(j=0;j<rows.count ();j++){

             tmpVar.X=rows[j].dateTime;


             for(i=0;i<rows[j].columns.count ();i++){


                 int nPos=varList.indexOf(rows[j].columns[i].name);
                 if( nPos>=0 && nPos<varList.count() ) {
                     bool fOk;

                     tmpVar.Y=rows[j].columns[i].value.toDouble (&fOk);

                     if(!fOk){
                         tmpVar.Y=NAN;
                     }
                     //qDebug()<<varList.at(nPos)<<" X = "<<tmpVar.X << " Y= "<<tmpVar.Y;
                     dataStruct[nPos].append (tmpVar);
                 }
             }
         }
         if(!dataStruct.isEmpty() ) {
             emit dataStructReady();
             return true;
         }
         else{
             qDebug()<<"getValueVector(QStringList,QList <QList<varPoint > >): QList <QList<varPoint > > is Empty ";
             emit errorSignal ("getValueVector(QStringList,QList <QList<varPoint > >):\n QList <QList<varPoint > >  is Empty ");
             return false;
         }
     }else{
         qDebug()<<"getValueVector(QStringList,QList <QList<varPoint > >): No points ";
         emit errorSignal ("getValueVector(QStringList,QList <QList<varPoint > >):\n No points, Try to change the date");
         return false;
     }

 }
