#include "mectcomm.h"

#define MAX_DATA		    8000u	/* Max. count of data bytes per block	*/
#define VIS_TCP_TIMEOUT 		6000 // Communication time out
#define VMM_GUID				16u 	/* Size of project GUID 			*/

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
        qDebug() << "getConfig(): ok"
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

        // 4. get project children at root level
        struct XBlock children;
        if (! getRootChildren(children)) {
            break;
        }
        qDebug() << "getRootChildren(): ok, uLen=" << children.uLen;
        {
            unsigned n = 0;
            unsigned skip = 0;

            variables.clear();
            while (skip < children.uLen) {
                n += 1;
                struct XDBIVar *ptr = (struct XDBIVar *)&children.CMD.pData[skip];
                char *name = (char *)&children.CMD.pData[skip + sizeof(struct XDBIVar)];

                switch(ptr->usType & 0xE0u) {
                case DBI_DTM_SIMPLE: {
                    struct mectVariable tmp;
                    QString qname = QString(name);
                    QString qtype;

                    switch(ptr->usType & ~0xE0u)
                    {
                        case DBI_DT_BOOL	: qtype = QString("bool");		break;
                        case DBI_DT_BYTE	: qtype = QString("byte");		break;
                        case DBI_DT_WORD	: qtype = QString("word");		break;
                        case DBI_DT_DWORD	: qtype = QString("dword");		break;
                        case DBI_DT_LWORD	: qtype = QString("lword");		break;
                        case DBI_DT_USINT	: qtype = QString("usint");		break;
                        case DBI_DT_UINT	: qtype = QString("uint");		break;
                        case DBI_DT_UDINT	: qtype = QString("udint");		break;
                        case DBI_DT_ULINT	: qtype = QString("ulint");		break;
                        case DBI_DT_SINT	: qtype = QString("sint");		break;
                        case DBI_DT_INT 	: qtype = QString("int"); 		break;
                        case DBI_DT_DINT	: qtype = QString("dint");		break;
                        case DBI_DT_LINT	: qtype = QString("lint");		break;
                        case DBI_DT_REAL	: qtype = QString("real");		break;
                        case DBI_DT_LREAL	: qtype = QString("lreal");		break;
                        case DBI_DT_STRING	: qtype = QString("string");   break;
                        case DBI_DT_TIME	: qtype = QString("time");		break;
                        default 			: qtype = QString("???");
                    }
//                    qDebug() << QString("#%1 VARIABLE %2 type=0x%3(%4) inst=%5 offs=%6 len=%7 bit=%8")
//                                .arg(n)
//                                .arg(qname)
//                                .arg(ptr->usType, 0, 16)
//                                .arg(qtype)
//                                .arg(ptr->uInst)
//                                .arg(ptr->ulOffset)
//                                .arg(ptr->uLen)
//                                .arg(ptr->usBit);

                    if (ptr->uInst <= 1) {
                        uint16_t ID = ptr->ulOffset / 4;

                        for (int i = 0; i < IDs.count(); ++i) {
                            if (ID == IDs[i]) {
                                tmp.name = qname;
                                tmp.ID = ID;
                                memcpy(&tmp.dbi, ptr, sizeof(struct XDBIVar));
                                variables.append(tmp);
                                qDebug() << QString("=---> variables[%1]: ID=%2 name=%3 type=%4 inst=%5 offs=%6 len=%7 bit=%8")
                                            .arg(variables.count() - 1)
                                            .arg(tmp.ID)
                                            .arg(tmp.name)
                                            .arg(qtype)
                                            .arg(tmp.dbi.uInst)
                                            .arg(tmp.dbi.ulOffset)
                                            .arg(tmp.dbi.uLen)
                                            .arg(tmp.dbi.usBit)
                                            ;
                                break;
                            }
                        }
                    }
                }   break;

                case DBI_DTM_OBJECT:
//                    qDebug() << QString("#%1 OBJECT %2")
//                                .arg(n)
//                                .arg(QString(name));
                    break;

                case DBI_DTM_ARRAY:
//                    qDebug() << QString("#%1 ARRAY %2 [%3]")
//                                .arg(n)
//                                .arg(QString(name))
//                                .arg(ptr->uLen);
                    break;

                default:
                    qDebug() << QString("#%1 INVALID %2");
                }
                skip += sizeof(struct XDBIVar) + ptr->usNameSize + 1;
            }
        }

        // 5. change status
        status = MectComm_Ready;
        break;
    }

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
            }
            command.uLen += sizeof(XVariableS);
        }
        else if (uDataOffset <= 0xFFffu && uDataInst <= 0xffu) {
            if ((command.uLen + sizeof(XVariableM)) <= MAX_DATA) {
                struct XVariableM *ptrM = (struct XVariableM *)&command.CMD.pData[command.uLen];

                ptrM->usType	= (unsigned char)(VMM_XV_MEDIUM | (uDataBit & VMM_XV_BITMASK));
                ptrM->uOffset 	= (unsigned short)uDataOffset;
                ptrM->uLen		= uDataLen;
                ptrM->usSegment	= (unsigned char)uDataInst;
            }
            command.uLen += sizeof(XVariableM);
        }
        else {
            if ((command.uLen + sizeof(XVariableL)) <= MAX_DATA) {
                struct XVariableL *ptrL = (struct XVariableL *)&command.CMD.pData[command.uLen];

                ptrL->usType	= (unsigned char)(VMM_XV_LARGE | (uDataBit & VMM_XV_BITMASK));
                ptrL->ulOffset 	= uDataOffset;
                ptrL->uLen		= uDataLen;
                ptrL->uSegment	= uDataInst;
            }
            command.uLen += sizeof(XVariableL);
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

    if (! doSend(command)) {
        retval = false;
        qDebug() << QString("doCommand(), send error: command=%1").arg(cmdText(command.CMD.byCommand));
        goto exit_function;
    }
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
    if (reply.CMD.byCommand & 0x80u) {
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
    if (! tcpSocket->waitForReadyRead(VIS_TCP_TIMEOUT)) {
        qDebug() << "doRecv() timeout";
        return false;
    }
    qint64 maxlen = HD_BLOCK + MAX_DATA;
    qint64 len = 0;
    qint64 retval;
    char *ptr = (char *)&reply;

    retval = tcpSocket->read(ptr, maxlen);
    if (retval < 0) {
        qDebug() << "doRecv() communication error";
        return false;
    }
    if (retval < HD_BLOCK) {
        qDebug() << "doRecv() error retval=" << retval;
        return false;
    }
    len = retval;
    maxlen = HD_BLOCK + reply.uLen;
    while (len < maxlen) {
        if (! tcpSocket->waitForReadyRead(VIS_TCP_TIMEOUT)) {
            qDebug() << "doRecv() timeout";
            return false;
        }
        retval = tcpSocket->read(&ptr[len], (maxlen - len));
        if (retval < 0) {
            qDebug() << "doRecv() communication error";
            return false;
        }
        if (retval <= 0) {
            qDebug() << "doRecv() error retval=" << retval << " len=" << len;
            return false;
        }
        len += retval;
    }
    return true;
}

// ----------------------------------------------------------------------------
