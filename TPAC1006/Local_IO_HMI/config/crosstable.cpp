/*Created by MectConfigurator v2.x
INT       <-> int16_t
UINT      <-> u_int16_t
DINT      <-> int32_t
UDINT     <-> u_int32_t
REAL      <-> float
BIT       <-> int
BYTE_BIT  <-> int
WORD_BIT  <-> int
DWORD_BIT <-> int
*/ 
#include "crosstable.h"
#include "cross_table_utility.h"
 
u_int16_t STATUS = 0;
u_int16_t RTU_HEARTBEAT = 0;
int RTU_RTU_WR = 0;
int RTU_RTU_RD = 0;
u_int16_t TEST_COMMAND = 0;
int TST_DigIn_1 = 0;
int TST_DigIn_2 = 0;
int TST_DigIn_3 = 0;
int TST_DigIn_4 = 0;
int TST_DigIn_5 = 0;
int TST_DigIn_6 = 0;
int TST_DigIn_7 = 0;
int TST_DigIn_8 = 0;
int TST_DigIn_9 = 0;
int TST_DigIn_10 = 0;
int TST_DigIn_11 = 0;
int TST_DigIn_12 = 0;
int TST_DigIn_13 = 0;
int TST_DigIn_14 = 0;
int TST_DigIn_15 = 0;
int TST_DigIn_16 = 0;
int VAL_DigIn_1 = 0;
int VAL_DigIn_2 = 0;
int VAL_DigIn_3 = 0;
int VAL_DigIn_4 = 0;
int VAL_DigIn_5 = 0;
int VAL_DigIn_6 = 0;
int VAL_DigIn_7 = 0;
int VAL_DigIn_8 = 0;
int VAL_DigIn_9 = 0;
int VAL_DigIn_10 = 0;
int VAL_DigIn_11 = 0;
int VAL_DigIn_12 = 0;
int VAL_DigIn_13 = 0;
int VAL_DigIn_14 = 0;
int VAL_DigIn_15 = 0;
int VAL_DigIn_16 = 0;
int RES_DigIn_1 = 0;
int RES_DigIn_2 = 0;
int RES_DigIn_3 = 0;
int RES_DigIn_4 = 0;
int RES_DigIn_5 = 0;
int RES_DigIn_6 = 0;
int RES_DigIn_7 = 0;
int RES_DigIn_8 = 0;
int RES_DigIn_9 = 0;
int RES_DigIn_10 = 0;
int RES_DigIn_11 = 0;
int RES_DigIn_12 = 0;
int RES_DigIn_13 = 0;
int RES_DigIn_14 = 0;
int RES_DigIn_15 = 0;
int RES_DigIn_16 = 0;
int TST_DigOut_1 = 0;
int TST_DigOut_2 = 0;
int TST_DigOut_3 = 0;
int TST_DigOut_4 = 0;
int TST_DigOut_5 = 0;
int TST_DigOut_6 = 0;
int TST_DigOut_7 = 0;
int TST_DigOut_8 = 0;
int TST_DigOut_9 = 0;
int TST_DigOut_10 = 0;
int TST_DigOut_11 = 0;
int TST_DigOut_12 = 0;
int TST_DigOut_13 = 0;
int TST_DigOut_14 = 0;
int TST_DigOut_15 = 0;
int TST_DigOut_16 = 0;
int VAL_DigOut_1 = 0;
int VAL_DigOut_2 = 0;
int VAL_DigOut_3 = 0;
int VAL_DigOut_4 = 0;
int VAL_DigOut_5 = 0;
int VAL_DigOut_6 = 0;
int VAL_DigOut_7 = 0;
int VAL_DigOut_8 = 0;
int VAL_DigOut_9 = 0;
int VAL_DigOut_10 = 0;
int VAL_DigOut_11 = 0;
int VAL_DigOut_12 = 0;
int VAL_DigOut_13 = 0;
int VAL_DigOut_14 = 0;
int VAL_DigOut_15 = 0;
int VAL_DigOut_16 = 0;
int TST_AnIn_1 = 0;
int TST_AnIn_2 = 0;
int TST_AnIn_3 = 0;
int TST_AnIn_4 = 0;
int TST_AnIn_5 = 0;
int TST_AnIn_6 = 0;
int TST_AnIn_7 = 0;
int TST_AnIn_8 = 0;
int TST_AnIn_9 = 0;
int TST_AnIn_10 = 0;
int TST_AnIn_11 = 0;
int TST_AnIn_12 = 0;
int16_t VAL_AnIn_1 = 0;
int16_t VAL_AnIn_2 = 0;
int16_t VAL_AnIn_3 = 0;
int16_t VAL_AnIn_4 = 0;
int16_t VAL_AnIn_5 = 0;
int16_t VAL_AnIn_6 = 0;
int16_t VAL_AnIn_7 = 0;
int16_t VAL_AnIn_8 = 0;
int16_t VAL_AnIn_9 = 0;
int16_t VAL_AnIn_10 = 0;
int16_t VAL_AnIn_11 = 0;
int16_t VAL_AnIn_12 = 0;
u_int16_t VAL_AnInConf_1 = 0;
u_int16_t VAL_AnInConf_2 = 0;
u_int16_t VAL_AnInConf_3 = 0;
u_int16_t VAL_AnInConf_4 = 0;
u_int16_t VAL_AnInConf_5 = 0;
u_int16_t VAL_AnInConf_6 = 0;
u_int16_t VAL_AnInConf_7 = 0;
u_int16_t VAL_AnInConf_8 = 0;
u_int16_t VAL_AnInConf_9 = 0;
u_int16_t VAL_AnInConf_10 = 0;
u_int16_t VAL_AnInConf_11 = 0;
u_int16_t VAL_AnInConf_12 = 0;
u_int16_t VAL_AnInFltr_1 = 0;
u_int16_t VAL_AnInFltr_2 = 0;
u_int16_t VAL_AnInFltr_3 = 0;
u_int16_t VAL_AnInFltr_4 = 0;
u_int16_t VAL_AnInFltr_5 = 0;
u_int16_t VAL_AnInFltr_6 = 0;
u_int16_t VAL_AnInFltr_7 = 0;
u_int16_t VAL_AnInFltr_8 = 0;
u_int16_t VAL_AnInFltr_9 = 0;
u_int16_t VAL_AnInFltr_10 = 0;
u_int16_t VAL_AnInFltr_11 = 0;
u_int16_t VAL_AnInFltr_12 = 0;
int16_t RES_AnIn_1 = 0;
int16_t RES_AnIn_2 = 0;
int16_t RES_AnIn_3 = 0;
int16_t RES_AnIn_4 = 0;
int16_t RES_AnIn_5 = 0;
int16_t RES_AnIn_6 = 0;
int16_t RES_AnIn_7 = 0;
int16_t RES_AnIn_8 = 0;
int16_t RES_AnIn_9 = 0;
int16_t RES_AnIn_10 = 0;
int16_t RES_AnIn_11 = 0;
int16_t RES_AnIn_12 = 0;
int16_t RES_AnInStts_1 = 0;
int16_t RES_AnInStts_2 = 0;
int16_t RES_AnInStts_3 = 0;
int16_t RES_AnInStts_4 = 0;
int16_t RES_AnInStts_5 = 0;
int16_t RES_AnInStts_6 = 0;
int16_t RES_AnInStts_7 = 0;
int16_t RES_AnInStts_8 = 0;
int16_t RES_AnInStts_9 = 0;
int16_t RES_AnInStts_10 = 0;
int16_t RES_AnInStts_11 = 0;
int16_t RES_AnInStts_12 = 0;
int TST_AnOut_1 = 0;
int TST_AnOut_2 = 0;
int TST_AnOut_3 = 0;
int TST_AnOut_4 = 0;
int16_t VAL_AnOut_1 = 0;
int16_t VAL_AnOut_2 = 0;
int16_t VAL_AnOut_3 = 0;
int16_t VAL_AnOut_4 = 0;
u_int16_t VAL_AnOutConf_1 = 0;
u_int16_t VAL_AnOutConf_2 = 0;
u_int16_t VAL_AnOutConf_3 = 0;
u_int16_t VAL_AnOutConf_4 = 0;
int16_t RES_AnOutStts_1 = 0;
int16_t RES_AnOutStts_2 = 0;
int16_t RES_AnOutStts_3 = 0;
int16_t RES_AnOutStts_4 = 0;
int TST_Tamb = 0;
int TST_RPM = 0;
int TST_FWrevision = 0;
int TST_HWconfig = 0;
int16_t VAL_Tamb = 0;
u_int16_t VAL_RPM = 0;
u_int16_t VAL_FWrevision = 0;
u_int16_t VAL_HWconfig = 0;
int16_t RES_Tamb = 0;
u_int16_t RES_RPM = 0;
u_int16_t RES_FWrevision = 0;
u_int16_t RES_HWconfig = 0;
int TST_RTUS_WR = 0;
int TST_RTUS_RD = 0;
int TST_RTU_WR = 0;
int TST_RTU_RD = 0;
int TST_RTU3_WR = 0;
int TST_RTU3_RD = 0;
int TST_CAN_WR = 0;
int TST_CAN_RD = 0;
int VAL_RTUS_WR = 0;
int VAL_RTUS_RD = 0;
int VAL_RTU_WR = 0;
int VAL_RTU_RD = 0;
int VAL_RTU3_WR = 0;
int VAL_RTU3_RD = 0;
int VAL_CAN_WR = 0;
int VAL_CAN_RD = 0;
int RES_RTUS_WR = 0;
int RES_RTUS_RD = 0;
int RES_RTU_WR = 0;
int RES_RTU_RD = 0;
int RES_RTU3_WR = 0;
int RES_RTU3_RD = 0;
int RES_CAN_WR = 0;
int RES_CAN_RD = 0;
u_int16_t TEST_STATUS = 0;
u_int32_t RTU0_TYPE_PORT = 0;
u_int32_t RTU0_BAUDRATE = 0;
u_int32_t RTU0_STATUS = 0;
u_int32_t RTU0_READS = 0;
u_int32_t RTU0_WRITES = 0;
u_int32_t RTU0_TIMEOUTS = 0;
u_int32_t RTU0_COMM_ERRORS = 0;
u_int32_t RTU0_LAST_ERROR = 0;
u_int32_t RTU0_WRITE_QUEUE = 0;
u_int32_t RTU0_READ_QUEUE = 0;
u_int32_t RTU1_TYPE_PORT = 0;
u_int32_t RTU1_BAUDRATE = 0;
u_int32_t RTU1_STATUS = 0;
u_int32_t RTU1_READS = 0;
u_int32_t RTU1_WRITES = 0;
u_int32_t RTU1_TIMEOUTS = 0;
u_int32_t RTU1_COMM_ERRORS = 0;
u_int32_t RTU1_LAST_ERROR = 0;
u_int32_t RTU1_WRITE_QUEUE = 0;
u_int32_t RTU1_READ_QUEUE = 0;
u_int32_t RTU3_TYPE_PORT = 0;
u_int32_t RTU3_BAUDRATE = 0;
u_int32_t RTU3_STATUS = 0;
u_int32_t RTU3_READS = 0;
u_int32_t RTU3_WRITES = 0;
u_int32_t RTU3_TIMEOUTS = 0;
u_int32_t RTU3_COMM_ERRORS = 0;
u_int32_t RTU3_LAST_ERROR = 0;
u_int32_t RTU3_WRITE_QUEUE = 0;
u_int32_t RTU3_READ_QUEUE = 0;
u_int32_t CAN0_TYPE_PORT = 0;
u_int32_t CAN0_BAUDRATE = 0;
u_int32_t CAN0_STATUS = 0;
u_int32_t CAN0_READS = 0;
u_int32_t CAN0_WRITES = 0;
u_int32_t CAN0_TIMEOUTS = 0;
u_int32_t CAN0_COMM_ERRORS = 0;
u_int32_t CAN0_LAST_ERROR = 0;
u_int32_t CAN0_WRITE_QUEUE = 0;
u_int32_t CAN0_READ_QUEUE = 0;
u_int32_t CAN1_TYPE_PORT = 0;
u_int32_t CAN1_BAUDRATE = 0;
u_int32_t CAN1_STATUS = 0;
u_int32_t CAN1_READS = 0;
u_int32_t CAN1_WRITES = 0;
u_int32_t CAN1_TIMEOUTS = 0;
u_int32_t CAN1_COMM_ERRORS = 0;
u_int32_t CAN1_LAST_ERROR = 0;
u_int32_t CAN1_WRITE_QUEUE = 0;
u_int32_t CAN1_READ_QUEUE = 0;
u_int32_t TCPS_TYPE_PORT = 0;
u_int32_t TCPS_IP_ADDRESS = 0;
u_int32_t TCPS_STATUS = 0;
u_int32_t TCPS_READS = 0;
u_int32_t TCPS_WRITES = 0;
u_int32_t TCPS_TIMEOUTS = 0;
u_int32_t TCPS_COMM_ERRORS = 0;
u_int32_t TCPS_LAST_ERROR = 0;
u_int32_t TCPS_WRITE_QUEUE = 0;
u_int32_t TCPS_READ_QUEUE = 0;
u_int32_t TCP0_TYPE_PORT = 0;
u_int32_t TCP0_IP_ADDRESS = 0;
u_int32_t TCP0_STATUS = 0;
u_int32_t TCP0_READS = 0;
u_int32_t TCP0_WRITES = 0;
u_int32_t TCP0_TIMEOUTS = 0;
u_int32_t TCP0_COMM_ERRORS = 0;
u_int32_t TCP0_LAST_ERROR = 0;
u_int32_t TCP0_WRITE_QUEUE = 0;
u_int32_t TCP0_READ_QUEUE = 0;
u_int32_t TCP1_TYPE_PORT = 0;
u_int32_t TCP1_IP_ADDRESS = 0;
u_int32_t TCP1_STATUS = 0;
u_int32_t TCP1_READS = 0;
u_int32_t TCP1_WRITES = 0;
u_int32_t TCP1_TIMEOUTS = 0;
u_int32_t TCP1_COMM_ERRORS = 0;
u_int32_t TCP1_LAST_ERROR = 0;
u_int32_t TCP1_WRITE_QUEUE = 0;
u_int32_t TCP1_READ_QUEUE = 0;
u_int32_t TCP2_TYPE_PORT = 0;
u_int32_t TCP2_IP_ADDRESS = 0;
u_int32_t TCP2_STATUS = 0;
u_int32_t TCP2_READS = 0;
u_int32_t TCP2_WRITES = 0;
u_int32_t TCP2_TIMEOUTS = 0;
u_int32_t TCP2_COMM_ERRORS = 0;
u_int32_t TCP2_LAST_ERROR = 0;
u_int32_t TCP2_WRITE_QUEUE = 0;
u_int32_t TCP2_READ_QUEUE = 0;
u_int32_t TCP3_TYPE_PORT = 0;
u_int32_t TCP3_IP_ADDRESS = 0;
u_int32_t TCP3_STATUS = 0;
u_int32_t TCP3_READS = 0;
u_int32_t TCP3_WRITES = 0;
u_int32_t TCP3_TIMEOUTS = 0;
u_int32_t TCP3_COMM_ERRORS = 0;
u_int32_t TCP3_LAST_ERROR = 0;
u_int32_t TCP3_WRITE_QUEUE = 0;
u_int32_t TCP3_READ_QUEUE = 0;
u_int32_t TCP4_TYPE_PORT = 0;
u_int32_t TCP4_IP_ADDRESS = 0;
u_int32_t TCP4_STATUS = 0;
u_int32_t TCP4_READS = 0;
u_int32_t TCP4_WRITES = 0;
u_int32_t TCP4_TIMEOUTS = 0;
u_int32_t TCP4_COMM_ERRORS = 0;
u_int32_t TCP4_LAST_ERROR = 0;
u_int32_t TCP4_WRITE_QUEUE = 0;
u_int32_t TCP4_READ_QUEUE = 0;
u_int32_t TCP5_TYPE_PORT = 0;
u_int32_t TCP5_IP_ADDRESS = 0;
u_int32_t TCP5_STATUS = 0;
u_int32_t TCP5_READS = 0;
u_int32_t TCP5_WRITES = 0;
u_int32_t TCP5_TIMEOUTS = 0;
u_int32_t TCP5_COMM_ERRORS = 0;
u_int32_t TCP5_LAST_ERROR = 0;
u_int32_t TCP5_WRITE_QUEUE = 0;
u_int32_t TCP5_READ_QUEUE = 0;
u_int32_t TCP6_TYPE_PORT = 0;
u_int32_t TCP6_IP_ADDRESS = 0;
u_int32_t TCP6_STATUS = 0;
u_int32_t TCP6_READS = 0;
u_int32_t TCP6_WRITES = 0;
u_int32_t TCP6_TIMEOUTS = 0;
u_int32_t TCP6_COMM_ERRORS = 0;
u_int32_t TCP6_LAST_ERROR = 0;
u_int32_t TCP6_WRITE_QUEUE = 0;
u_int32_t TCP6_READ_QUEUE = 0;
u_int32_t TCP7_TYPE_PORT = 0;
u_int32_t TCP7_IP_ADDRESS = 0;
u_int32_t TCP7_STATUS = 0;
u_int32_t TCP7_READS = 0;
u_int32_t TCP7_WRITES = 0;
u_int32_t TCP7_TIMEOUTS = 0;
u_int32_t TCP7_COMM_ERRORS = 0;
u_int32_t TCP7_LAST_ERROR = 0;
u_int32_t TCP7_WRITE_QUEUE = 0;
u_int32_t TCP7_READ_QUEUE = 0;
u_int32_t TCP8_TYPE_PORT = 0;
u_int32_t TCP8_IP_ADDRESS = 0;
u_int32_t TCP8_STATUS = 0;
u_int32_t TCP8_READS = 0;
u_int32_t TCP8_WRITES = 0;
u_int32_t TCP8_TIMEOUTS = 0;
u_int32_t TCP8_COMM_ERRORS = 0;
u_int32_t TCP8_LAST_ERROR = 0;
u_int32_t TCP8_WRITE_QUEUE = 0;
u_int32_t TCP8_READ_QUEUE = 0;
u_int32_t TCP9_TYPE_PORT = 0;
u_int32_t TCP9_IP_ADDRESS = 0;
u_int32_t TCP9_STATUS = 0;
u_int32_t TCP9_READS = 0;
u_int32_t TCP9_WRITES = 0;
u_int32_t TCP9_TIMEOUTS = 0;
u_int32_t TCP9_COMM_ERRORS = 0;
u_int32_t TCP9_LAST_ERROR = 0;
u_int32_t TCP9_WRITE_QUEUE = 0;
u_int32_t TCP9_READ_QUEUE = 0;
u_int32_t NODE_01_DEV_NODE = 0;
u_int32_t NODE_01_STATUS = 0;
u_int32_t NODE_02_DEV_NODE = 0;
u_int32_t NODE_02_STATUS = 0;
u_int32_t NODE_03_DEV_NODE = 0;
u_int32_t NODE_03_STATUS = 0;
u_int32_t NODE_04_DEV_NODE = 0;
u_int32_t NODE_04_STATUS = 0;
u_int32_t NODE_05_DEV_NODE = 0;
u_int32_t NODE_05_STATUS = 0;
u_int32_t NODE_06_DEV_NODE = 0;
u_int32_t NODE_06_STATUS = 0;
u_int32_t NODE_07_DEV_NODE = 0;
u_int32_t NODE_07_STATUS = 0;
u_int32_t NODE_08_DEV_NODE = 0;
u_int32_t NODE_08_STATUS = 0;
u_int32_t NODE_09_DEV_NODE = 0;
u_int32_t NODE_09_STATUS = 0;
u_int32_t NODE_10_DEV_NODE = 0;
u_int32_t NODE_10_STATUS = 0;
u_int32_t NODE_11_DEV_NODE = 0;
u_int32_t NODE_11_STATUS = 0;
u_int32_t NODE_12_DEV_NODE = 0;
u_int32_t NODE_12_STATUS = 0;
u_int32_t NODE_13_DEV_NODE = 0;
u_int32_t NODE_13_STATUS = 0;
u_int32_t NODE_14_DEV_NODE = 0;
u_int32_t NODE_14_STATUS = 0;
u_int32_t NODE_15_DEV_NODE = 0;
u_int32_t NODE_15_STATUS = 0;
u_int32_t NODE_16_DEV_NODE = 0;
u_int32_t NODE_16_STATUS = 0;
int PLC_DigIn_1 = 0;
int PLC_DigIn_2 = 0;
int PLC_DigIn_3 = 0;
int PLC_DigIn_4 = 0;
int PLC_DigIn_5 = 0;
int PLC_DigIn_6 = 0;
int PLC_DigIn_7 = 0;
int PLC_DigIn_8 = 0;
int PLC_DigIn_9 = 0;
int PLC_DigIn_17 = 0;
int PLC_DigIn_25 = 0;
int PLC_DigOut_1 = 0;
int PLC_DigOut_2 = 0;
int PLC_DigOut_3 = 0;
int PLC_DigOut_4 = 0;
int PLC_DigOut_5 = 0;
int PLC_DigOut_6 = 0;
int PLC_DigOut_7 = 0;
int PLC_DigOut_8 = 0;
int PLC_DigOut_9 = 0;
int PLC_DigOut_10 = 0;
int PLC_DigOut_11 = 0;
int PLC_DigOut_12 = 0;
int16_t PLC_AnIn_1 = 0;
int16_t PLC_AnIn_2 = 0;
int16_t PLC_AnIn_3 = 0;
int16_t PLC_AnIn_4 = 0;
int16_t PLC_Tamb = 0;
u_int16_t PLC_EncoderLo = 0;
u_int16_t PLC_EncoderHi = 0;
u_int16_t PLC_StatusReg = 0;
u_int16_t PLC_RPM = 0;
int16_t PLC_AnOut_1 = 0;
int16_t PLC_AnOut_2 = 0;
u_int16_t PLC_AnInConf = 0;
u_int16_t PLC_AnOutConf = 0;
u_int16_t PLC_ControlWord = 0;
u_int16_t PLC_EncPreset_Lo = 0;
u_int16_t PLC_EncPreset_Hi = 0;
int CH0_NETRUN = 0;
int CH0_NETGOOD = 0;
u_int32_t CH0_NETERR = 0;
int CH0_NETRST = 0;
int CH0_NETDIS = 0;
int CH0_01_NODERUN = 0;
int CH0_01_NODEGOOD = 0;
u_int32_t CH0_01_NODEERR = 0;
int CH0_01_NODERST = 0;
int CH0_01_NODEDIS = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;
u_int16_t PLC_Version = 0;
u_int16_t PLC_EngineStatus = 0;
int PLC_ResetValues = 0;


int doWrite_STATUS(u_int16_t value)
{
return doWrite(ID_STATUS,  &value);
}


int addWrite_STATUS(u_int16_t value)
{
return addWrite(ID_STATUS, &value);
}


int getStatus_STATUS()
{
return getStatus(ID_STATUS);
}


int doWrite_RTU_HEARTBEAT(u_int16_t value)
{
return doWrite(ID_RTU_HEARTBEAT,  &value);
}


int addWrite_RTU_HEARTBEAT(u_int16_t value)
{
return addWrite(ID_RTU_HEARTBEAT, &value);
}


int getStatus_RTU_HEARTBEAT()
{
return getStatus(ID_RTU_HEARTBEAT);
}


int doWrite_RTU_RTU_WR(int value)
{
return doWrite(ID_RTU_RTU_WR,  &value);
}


int addWrite_RTU_RTU_WR(int value)
{
return addWrite(ID_RTU_RTU_WR, &value);
}


int getStatus_RTU_RTU_WR()
{
return getStatus(ID_RTU_RTU_WR);
}


int doWrite_RTU_RTU_RD(int value)
{
return doWrite(ID_RTU_RTU_RD,  &value);
}


int addWrite_RTU_RTU_RD(int value)
{
return addWrite(ID_RTU_RTU_RD, &value);
}


int getStatus_RTU_RTU_RD()
{
return getStatus(ID_RTU_RTU_RD);
}


int doWrite_TEST_COMMAND(u_int16_t value)
{
return doWrite(ID_TEST_COMMAND,  &value);
}


int addWrite_TEST_COMMAND(u_int16_t value)
{
return addWrite(ID_TEST_COMMAND, &value);
}


int getStatus_TEST_COMMAND()
{
return getStatus(ID_TEST_COMMAND);
}


int doWrite_TST_DigIn_1(int value)
{
return doWrite(ID_TST_DigIn_1,  &value);
}


int addWrite_TST_DigIn_1(int value)
{
return addWrite(ID_TST_DigIn_1, &value);
}


int getStatus_TST_DigIn_1()
{
return getStatus(ID_TST_DigIn_1);
}


int doWrite_TST_DigIn_2(int value)
{
return doWrite(ID_TST_DigIn_2,  &value);
}


int addWrite_TST_DigIn_2(int value)
{
return addWrite(ID_TST_DigIn_2, &value);
}


int getStatus_TST_DigIn_2()
{
return getStatus(ID_TST_DigIn_2);
}


int doWrite_TST_DigIn_3(int value)
{
return doWrite(ID_TST_DigIn_3,  &value);
}


int addWrite_TST_DigIn_3(int value)
{
return addWrite(ID_TST_DigIn_3, &value);
}


int getStatus_TST_DigIn_3()
{
return getStatus(ID_TST_DigIn_3);
}


int doWrite_TST_DigIn_4(int value)
{
return doWrite(ID_TST_DigIn_4,  &value);
}


int addWrite_TST_DigIn_4(int value)
{
return addWrite(ID_TST_DigIn_4, &value);
}


int getStatus_TST_DigIn_4()
{
return getStatus(ID_TST_DigIn_4);
}


int doWrite_TST_DigIn_5(int value)
{
return doWrite(ID_TST_DigIn_5,  &value);
}


int addWrite_TST_DigIn_5(int value)
{
return addWrite(ID_TST_DigIn_5, &value);
}


int getStatus_TST_DigIn_5()
{
return getStatus(ID_TST_DigIn_5);
}


int doWrite_TST_DigIn_6(int value)
{
return doWrite(ID_TST_DigIn_6,  &value);
}


int addWrite_TST_DigIn_6(int value)
{
return addWrite(ID_TST_DigIn_6, &value);
}


int getStatus_TST_DigIn_6()
{
return getStatus(ID_TST_DigIn_6);
}


int doWrite_TST_DigIn_7(int value)
{
return doWrite(ID_TST_DigIn_7,  &value);
}


int addWrite_TST_DigIn_7(int value)
{
return addWrite(ID_TST_DigIn_7, &value);
}


int getStatus_TST_DigIn_7()
{
return getStatus(ID_TST_DigIn_7);
}


int doWrite_TST_DigIn_8(int value)
{
return doWrite(ID_TST_DigIn_8,  &value);
}


int addWrite_TST_DigIn_8(int value)
{
return addWrite(ID_TST_DigIn_8, &value);
}


int getStatus_TST_DigIn_8()
{
return getStatus(ID_TST_DigIn_8);
}


int doWrite_TST_DigIn_9(int value)
{
return doWrite(ID_TST_DigIn_9,  &value);
}


int addWrite_TST_DigIn_9(int value)
{
return addWrite(ID_TST_DigIn_9, &value);
}


int getStatus_TST_DigIn_9()
{
return getStatus(ID_TST_DigIn_9);
}


int doWrite_TST_DigIn_10(int value)
{
return doWrite(ID_TST_DigIn_10,  &value);
}


int addWrite_TST_DigIn_10(int value)
{
return addWrite(ID_TST_DigIn_10, &value);
}


int getStatus_TST_DigIn_10()
{
return getStatus(ID_TST_DigIn_10);
}


int doWrite_TST_DigIn_11(int value)
{
return doWrite(ID_TST_DigIn_11,  &value);
}


int addWrite_TST_DigIn_11(int value)
{
return addWrite(ID_TST_DigIn_11, &value);
}


int getStatus_TST_DigIn_11()
{
return getStatus(ID_TST_DigIn_11);
}


int doWrite_TST_DigIn_12(int value)
{
return doWrite(ID_TST_DigIn_12,  &value);
}


int addWrite_TST_DigIn_12(int value)
{
return addWrite(ID_TST_DigIn_12, &value);
}


int getStatus_TST_DigIn_12()
{
return getStatus(ID_TST_DigIn_12);
}


int doWrite_TST_DigIn_13(int value)
{
return doWrite(ID_TST_DigIn_13,  &value);
}


int addWrite_TST_DigIn_13(int value)
{
return addWrite(ID_TST_DigIn_13, &value);
}


int getStatus_TST_DigIn_13()
{
return getStatus(ID_TST_DigIn_13);
}


int doWrite_TST_DigIn_14(int value)
{
return doWrite(ID_TST_DigIn_14,  &value);
}


int addWrite_TST_DigIn_14(int value)
{
return addWrite(ID_TST_DigIn_14, &value);
}


int getStatus_TST_DigIn_14()
{
return getStatus(ID_TST_DigIn_14);
}


int doWrite_TST_DigIn_15(int value)
{
return doWrite(ID_TST_DigIn_15,  &value);
}


int addWrite_TST_DigIn_15(int value)
{
return addWrite(ID_TST_DigIn_15, &value);
}


int getStatus_TST_DigIn_15()
{
return getStatus(ID_TST_DigIn_15);
}


int doWrite_TST_DigIn_16(int value)
{
return doWrite(ID_TST_DigIn_16,  &value);
}


int addWrite_TST_DigIn_16(int value)
{
return addWrite(ID_TST_DigIn_16, &value);
}


int getStatus_TST_DigIn_16()
{
return getStatus(ID_TST_DigIn_16);
}


int doWrite_VAL_DigIn_1(int value)
{
return doWrite(ID_VAL_DigIn_1,  &value);
}


int addWrite_VAL_DigIn_1(int value)
{
return addWrite(ID_VAL_DigIn_1, &value);
}


int getStatus_VAL_DigIn_1()
{
return getStatus(ID_VAL_DigIn_1);
}


int doWrite_VAL_DigIn_2(int value)
{
return doWrite(ID_VAL_DigIn_2,  &value);
}


int addWrite_VAL_DigIn_2(int value)
{
return addWrite(ID_VAL_DigIn_2, &value);
}


int getStatus_VAL_DigIn_2()
{
return getStatus(ID_VAL_DigIn_2);
}


int doWrite_VAL_DigIn_3(int value)
{
return doWrite(ID_VAL_DigIn_3,  &value);
}


int addWrite_VAL_DigIn_3(int value)
{
return addWrite(ID_VAL_DigIn_3, &value);
}


int getStatus_VAL_DigIn_3()
{
return getStatus(ID_VAL_DigIn_3);
}


int doWrite_VAL_DigIn_4(int value)
{
return doWrite(ID_VAL_DigIn_4,  &value);
}


int addWrite_VAL_DigIn_4(int value)
{
return addWrite(ID_VAL_DigIn_4, &value);
}


int getStatus_VAL_DigIn_4()
{
return getStatus(ID_VAL_DigIn_4);
}


int doWrite_VAL_DigIn_5(int value)
{
return doWrite(ID_VAL_DigIn_5,  &value);
}


int addWrite_VAL_DigIn_5(int value)
{
return addWrite(ID_VAL_DigIn_5, &value);
}


int getStatus_VAL_DigIn_5()
{
return getStatus(ID_VAL_DigIn_5);
}


int doWrite_VAL_DigIn_6(int value)
{
return doWrite(ID_VAL_DigIn_6,  &value);
}


int addWrite_VAL_DigIn_6(int value)
{
return addWrite(ID_VAL_DigIn_6, &value);
}


int getStatus_VAL_DigIn_6()
{
return getStatus(ID_VAL_DigIn_6);
}


int doWrite_VAL_DigIn_7(int value)
{
return doWrite(ID_VAL_DigIn_7,  &value);
}


int addWrite_VAL_DigIn_7(int value)
{
return addWrite(ID_VAL_DigIn_7, &value);
}


int getStatus_VAL_DigIn_7()
{
return getStatus(ID_VAL_DigIn_7);
}


int doWrite_VAL_DigIn_8(int value)
{
return doWrite(ID_VAL_DigIn_8,  &value);
}


int addWrite_VAL_DigIn_8(int value)
{
return addWrite(ID_VAL_DigIn_8, &value);
}


int getStatus_VAL_DigIn_8()
{
return getStatus(ID_VAL_DigIn_8);
}


int doWrite_VAL_DigIn_9(int value)
{
return doWrite(ID_VAL_DigIn_9,  &value);
}


int addWrite_VAL_DigIn_9(int value)
{
return addWrite(ID_VAL_DigIn_9, &value);
}


int getStatus_VAL_DigIn_9()
{
return getStatus(ID_VAL_DigIn_9);
}


int doWrite_VAL_DigIn_10(int value)
{
return doWrite(ID_VAL_DigIn_10,  &value);
}


int addWrite_VAL_DigIn_10(int value)
{
return addWrite(ID_VAL_DigIn_10, &value);
}


int getStatus_VAL_DigIn_10()
{
return getStatus(ID_VAL_DigIn_10);
}


int doWrite_VAL_DigIn_11(int value)
{
return doWrite(ID_VAL_DigIn_11,  &value);
}


int addWrite_VAL_DigIn_11(int value)
{
return addWrite(ID_VAL_DigIn_11, &value);
}


int getStatus_VAL_DigIn_11()
{
return getStatus(ID_VAL_DigIn_11);
}


int doWrite_VAL_DigIn_12(int value)
{
return doWrite(ID_VAL_DigIn_12,  &value);
}


int addWrite_VAL_DigIn_12(int value)
{
return addWrite(ID_VAL_DigIn_12, &value);
}


int getStatus_VAL_DigIn_12()
{
return getStatus(ID_VAL_DigIn_12);
}


int doWrite_VAL_DigIn_13(int value)
{
return doWrite(ID_VAL_DigIn_13,  &value);
}


int addWrite_VAL_DigIn_13(int value)
{
return addWrite(ID_VAL_DigIn_13, &value);
}


int getStatus_VAL_DigIn_13()
{
return getStatus(ID_VAL_DigIn_13);
}


int doWrite_VAL_DigIn_14(int value)
{
return doWrite(ID_VAL_DigIn_14,  &value);
}


int addWrite_VAL_DigIn_14(int value)
{
return addWrite(ID_VAL_DigIn_14, &value);
}


int getStatus_VAL_DigIn_14()
{
return getStatus(ID_VAL_DigIn_14);
}


int doWrite_VAL_DigIn_15(int value)
{
return doWrite(ID_VAL_DigIn_15,  &value);
}


int addWrite_VAL_DigIn_15(int value)
{
return addWrite(ID_VAL_DigIn_15, &value);
}


int getStatus_VAL_DigIn_15()
{
return getStatus(ID_VAL_DigIn_15);
}


int doWrite_VAL_DigIn_16(int value)
{
return doWrite(ID_VAL_DigIn_16,  &value);
}


int addWrite_VAL_DigIn_16(int value)
{
return addWrite(ID_VAL_DigIn_16, &value);
}


int getStatus_VAL_DigIn_16()
{
return getStatus(ID_VAL_DigIn_16);
}


int doWrite_RES_DigIn_1(int value)
{
return doWrite(ID_RES_DigIn_1,  &value);
}


int addWrite_RES_DigIn_1(int value)
{
return addWrite(ID_RES_DigIn_1, &value);
}


int getStatus_RES_DigIn_1()
{
return getStatus(ID_RES_DigIn_1);
}


int doWrite_RES_DigIn_2(int value)
{
return doWrite(ID_RES_DigIn_2,  &value);
}


int addWrite_RES_DigIn_2(int value)
{
return addWrite(ID_RES_DigIn_2, &value);
}


int getStatus_RES_DigIn_2()
{
return getStatus(ID_RES_DigIn_2);
}


int doWrite_RES_DigIn_3(int value)
{
return doWrite(ID_RES_DigIn_3,  &value);
}


int addWrite_RES_DigIn_3(int value)
{
return addWrite(ID_RES_DigIn_3, &value);
}


int getStatus_RES_DigIn_3()
{
return getStatus(ID_RES_DigIn_3);
}


int doWrite_RES_DigIn_4(int value)
{
return doWrite(ID_RES_DigIn_4,  &value);
}


int addWrite_RES_DigIn_4(int value)
{
return addWrite(ID_RES_DigIn_4, &value);
}


int getStatus_RES_DigIn_4()
{
return getStatus(ID_RES_DigIn_4);
}


int doWrite_RES_DigIn_5(int value)
{
return doWrite(ID_RES_DigIn_5,  &value);
}


int addWrite_RES_DigIn_5(int value)
{
return addWrite(ID_RES_DigIn_5, &value);
}


int getStatus_RES_DigIn_5()
{
return getStatus(ID_RES_DigIn_5);
}


int doWrite_RES_DigIn_6(int value)
{
return doWrite(ID_RES_DigIn_6,  &value);
}


int addWrite_RES_DigIn_6(int value)
{
return addWrite(ID_RES_DigIn_6, &value);
}


int getStatus_RES_DigIn_6()
{
return getStatus(ID_RES_DigIn_6);
}


int doWrite_RES_DigIn_7(int value)
{
return doWrite(ID_RES_DigIn_7,  &value);
}


int addWrite_RES_DigIn_7(int value)
{
return addWrite(ID_RES_DigIn_7, &value);
}


int getStatus_RES_DigIn_7()
{
return getStatus(ID_RES_DigIn_7);
}


int doWrite_RES_DigIn_8(int value)
{
return doWrite(ID_RES_DigIn_8,  &value);
}


int addWrite_RES_DigIn_8(int value)
{
return addWrite(ID_RES_DigIn_8, &value);
}


int getStatus_RES_DigIn_8()
{
return getStatus(ID_RES_DigIn_8);
}


int doWrite_RES_DigIn_9(int value)
{
return doWrite(ID_RES_DigIn_9,  &value);
}


int addWrite_RES_DigIn_9(int value)
{
return addWrite(ID_RES_DigIn_9, &value);
}


int getStatus_RES_DigIn_9()
{
return getStatus(ID_RES_DigIn_9);
}


int doWrite_RES_DigIn_10(int value)
{
return doWrite(ID_RES_DigIn_10,  &value);
}


int addWrite_RES_DigIn_10(int value)
{
return addWrite(ID_RES_DigIn_10, &value);
}


int getStatus_RES_DigIn_10()
{
return getStatus(ID_RES_DigIn_10);
}


int doWrite_RES_DigIn_11(int value)
{
return doWrite(ID_RES_DigIn_11,  &value);
}


int addWrite_RES_DigIn_11(int value)
{
return addWrite(ID_RES_DigIn_11, &value);
}


int getStatus_RES_DigIn_11()
{
return getStatus(ID_RES_DigIn_11);
}


int doWrite_RES_DigIn_12(int value)
{
return doWrite(ID_RES_DigIn_12,  &value);
}


int addWrite_RES_DigIn_12(int value)
{
return addWrite(ID_RES_DigIn_12, &value);
}


int getStatus_RES_DigIn_12()
{
return getStatus(ID_RES_DigIn_12);
}


int doWrite_RES_DigIn_13(int value)
{
return doWrite(ID_RES_DigIn_13,  &value);
}


int addWrite_RES_DigIn_13(int value)
{
return addWrite(ID_RES_DigIn_13, &value);
}


int getStatus_RES_DigIn_13()
{
return getStatus(ID_RES_DigIn_13);
}


int doWrite_RES_DigIn_14(int value)
{
return doWrite(ID_RES_DigIn_14,  &value);
}


int addWrite_RES_DigIn_14(int value)
{
return addWrite(ID_RES_DigIn_14, &value);
}


int getStatus_RES_DigIn_14()
{
return getStatus(ID_RES_DigIn_14);
}


int doWrite_RES_DigIn_15(int value)
{
return doWrite(ID_RES_DigIn_15,  &value);
}


int addWrite_RES_DigIn_15(int value)
{
return addWrite(ID_RES_DigIn_15, &value);
}


int getStatus_RES_DigIn_15()
{
return getStatus(ID_RES_DigIn_15);
}


int doWrite_RES_DigIn_16(int value)
{
return doWrite(ID_RES_DigIn_16,  &value);
}


int addWrite_RES_DigIn_16(int value)
{
return addWrite(ID_RES_DigIn_16, &value);
}


int getStatus_RES_DigIn_16()
{
return getStatus(ID_RES_DigIn_16);
}


int doWrite_TST_DigOut_1(int value)
{
return doWrite(ID_TST_DigOut_1,  &value);
}


int addWrite_TST_DigOut_1(int value)
{
return addWrite(ID_TST_DigOut_1, &value);
}


int getStatus_TST_DigOut_1()
{
return getStatus(ID_TST_DigOut_1);
}


int doWrite_TST_DigOut_2(int value)
{
return doWrite(ID_TST_DigOut_2,  &value);
}


int addWrite_TST_DigOut_2(int value)
{
return addWrite(ID_TST_DigOut_2, &value);
}


int getStatus_TST_DigOut_2()
{
return getStatus(ID_TST_DigOut_2);
}


int doWrite_TST_DigOut_3(int value)
{
return doWrite(ID_TST_DigOut_3,  &value);
}


int addWrite_TST_DigOut_3(int value)
{
return addWrite(ID_TST_DigOut_3, &value);
}


int getStatus_TST_DigOut_3()
{
return getStatus(ID_TST_DigOut_3);
}


int doWrite_TST_DigOut_4(int value)
{
return doWrite(ID_TST_DigOut_4,  &value);
}


int addWrite_TST_DigOut_4(int value)
{
return addWrite(ID_TST_DigOut_4, &value);
}


int getStatus_TST_DigOut_4()
{
return getStatus(ID_TST_DigOut_4);
}


int doWrite_TST_DigOut_5(int value)
{
return doWrite(ID_TST_DigOut_5,  &value);
}


int addWrite_TST_DigOut_5(int value)
{
return addWrite(ID_TST_DigOut_5, &value);
}


int getStatus_TST_DigOut_5()
{
return getStatus(ID_TST_DigOut_5);
}


int doWrite_TST_DigOut_6(int value)
{
return doWrite(ID_TST_DigOut_6,  &value);
}


int addWrite_TST_DigOut_6(int value)
{
return addWrite(ID_TST_DigOut_6, &value);
}


int getStatus_TST_DigOut_6()
{
return getStatus(ID_TST_DigOut_6);
}


int doWrite_TST_DigOut_7(int value)
{
return doWrite(ID_TST_DigOut_7,  &value);
}


int addWrite_TST_DigOut_7(int value)
{
return addWrite(ID_TST_DigOut_7, &value);
}


int getStatus_TST_DigOut_7()
{
return getStatus(ID_TST_DigOut_7);
}


int doWrite_TST_DigOut_8(int value)
{
return doWrite(ID_TST_DigOut_8,  &value);
}


int addWrite_TST_DigOut_8(int value)
{
return addWrite(ID_TST_DigOut_8, &value);
}


int getStatus_TST_DigOut_8()
{
return getStatus(ID_TST_DigOut_8);
}


int doWrite_TST_DigOut_9(int value)
{
return doWrite(ID_TST_DigOut_9,  &value);
}


int addWrite_TST_DigOut_9(int value)
{
return addWrite(ID_TST_DigOut_9, &value);
}


int getStatus_TST_DigOut_9()
{
return getStatus(ID_TST_DigOut_9);
}


int doWrite_TST_DigOut_10(int value)
{
return doWrite(ID_TST_DigOut_10,  &value);
}


int addWrite_TST_DigOut_10(int value)
{
return addWrite(ID_TST_DigOut_10, &value);
}


int getStatus_TST_DigOut_10()
{
return getStatus(ID_TST_DigOut_10);
}


int doWrite_TST_DigOut_11(int value)
{
return doWrite(ID_TST_DigOut_11,  &value);
}


int addWrite_TST_DigOut_11(int value)
{
return addWrite(ID_TST_DigOut_11, &value);
}


int getStatus_TST_DigOut_11()
{
return getStatus(ID_TST_DigOut_11);
}


int doWrite_TST_DigOut_12(int value)
{
return doWrite(ID_TST_DigOut_12,  &value);
}


int addWrite_TST_DigOut_12(int value)
{
return addWrite(ID_TST_DigOut_12, &value);
}


int getStatus_TST_DigOut_12()
{
return getStatus(ID_TST_DigOut_12);
}


int doWrite_TST_DigOut_13(int value)
{
return doWrite(ID_TST_DigOut_13,  &value);
}


int addWrite_TST_DigOut_13(int value)
{
return addWrite(ID_TST_DigOut_13, &value);
}


int getStatus_TST_DigOut_13()
{
return getStatus(ID_TST_DigOut_13);
}


int doWrite_TST_DigOut_14(int value)
{
return doWrite(ID_TST_DigOut_14,  &value);
}


int addWrite_TST_DigOut_14(int value)
{
return addWrite(ID_TST_DigOut_14, &value);
}


int getStatus_TST_DigOut_14()
{
return getStatus(ID_TST_DigOut_14);
}


int doWrite_TST_DigOut_15(int value)
{
return doWrite(ID_TST_DigOut_15,  &value);
}


int addWrite_TST_DigOut_15(int value)
{
return addWrite(ID_TST_DigOut_15, &value);
}


int getStatus_TST_DigOut_15()
{
return getStatus(ID_TST_DigOut_15);
}


int doWrite_TST_DigOut_16(int value)
{
return doWrite(ID_TST_DigOut_16,  &value);
}


int addWrite_TST_DigOut_16(int value)
{
return addWrite(ID_TST_DigOut_16, &value);
}


int getStatus_TST_DigOut_16()
{
return getStatus(ID_TST_DigOut_16);
}


int doWrite_VAL_DigOut_1(int value)
{
return doWrite(ID_VAL_DigOut_1,  &value);
}


int addWrite_VAL_DigOut_1(int value)
{
return addWrite(ID_VAL_DigOut_1, &value);
}


int getStatus_VAL_DigOut_1()
{
return getStatus(ID_VAL_DigOut_1);
}


int doWrite_VAL_DigOut_2(int value)
{
return doWrite(ID_VAL_DigOut_2,  &value);
}


int addWrite_VAL_DigOut_2(int value)
{
return addWrite(ID_VAL_DigOut_2, &value);
}


int getStatus_VAL_DigOut_2()
{
return getStatus(ID_VAL_DigOut_2);
}


int doWrite_VAL_DigOut_3(int value)
{
return doWrite(ID_VAL_DigOut_3,  &value);
}


int addWrite_VAL_DigOut_3(int value)
{
return addWrite(ID_VAL_DigOut_3, &value);
}


int getStatus_VAL_DigOut_3()
{
return getStatus(ID_VAL_DigOut_3);
}


int doWrite_VAL_DigOut_4(int value)
{
return doWrite(ID_VAL_DigOut_4,  &value);
}


int addWrite_VAL_DigOut_4(int value)
{
return addWrite(ID_VAL_DigOut_4, &value);
}


int getStatus_VAL_DigOut_4()
{
return getStatus(ID_VAL_DigOut_4);
}


int doWrite_VAL_DigOut_5(int value)
{
return doWrite(ID_VAL_DigOut_5,  &value);
}


int addWrite_VAL_DigOut_5(int value)
{
return addWrite(ID_VAL_DigOut_5, &value);
}


int getStatus_VAL_DigOut_5()
{
return getStatus(ID_VAL_DigOut_5);
}


int doWrite_VAL_DigOut_6(int value)
{
return doWrite(ID_VAL_DigOut_6,  &value);
}


int addWrite_VAL_DigOut_6(int value)
{
return addWrite(ID_VAL_DigOut_6, &value);
}


int getStatus_VAL_DigOut_6()
{
return getStatus(ID_VAL_DigOut_6);
}


int doWrite_VAL_DigOut_7(int value)
{
return doWrite(ID_VAL_DigOut_7,  &value);
}


int addWrite_VAL_DigOut_7(int value)
{
return addWrite(ID_VAL_DigOut_7, &value);
}


int getStatus_VAL_DigOut_7()
{
return getStatus(ID_VAL_DigOut_7);
}


int doWrite_VAL_DigOut_8(int value)
{
return doWrite(ID_VAL_DigOut_8,  &value);
}


int addWrite_VAL_DigOut_8(int value)
{
return addWrite(ID_VAL_DigOut_8, &value);
}


int getStatus_VAL_DigOut_8()
{
return getStatus(ID_VAL_DigOut_8);
}


int doWrite_VAL_DigOut_9(int value)
{
return doWrite(ID_VAL_DigOut_9,  &value);
}


int addWrite_VAL_DigOut_9(int value)
{
return addWrite(ID_VAL_DigOut_9, &value);
}


int getStatus_VAL_DigOut_9()
{
return getStatus(ID_VAL_DigOut_9);
}


int doWrite_VAL_DigOut_10(int value)
{
return doWrite(ID_VAL_DigOut_10,  &value);
}


int addWrite_VAL_DigOut_10(int value)
{
return addWrite(ID_VAL_DigOut_10, &value);
}


int getStatus_VAL_DigOut_10()
{
return getStatus(ID_VAL_DigOut_10);
}


int doWrite_VAL_DigOut_11(int value)
{
return doWrite(ID_VAL_DigOut_11,  &value);
}


int addWrite_VAL_DigOut_11(int value)
{
return addWrite(ID_VAL_DigOut_11, &value);
}


int getStatus_VAL_DigOut_11()
{
return getStatus(ID_VAL_DigOut_11);
}


int doWrite_VAL_DigOut_12(int value)
{
return doWrite(ID_VAL_DigOut_12,  &value);
}


int addWrite_VAL_DigOut_12(int value)
{
return addWrite(ID_VAL_DigOut_12, &value);
}


int getStatus_VAL_DigOut_12()
{
return getStatus(ID_VAL_DigOut_12);
}


int doWrite_VAL_DigOut_13(int value)
{
return doWrite(ID_VAL_DigOut_13,  &value);
}


int addWrite_VAL_DigOut_13(int value)
{
return addWrite(ID_VAL_DigOut_13, &value);
}


int getStatus_VAL_DigOut_13()
{
return getStatus(ID_VAL_DigOut_13);
}


int doWrite_VAL_DigOut_14(int value)
{
return doWrite(ID_VAL_DigOut_14,  &value);
}


int addWrite_VAL_DigOut_14(int value)
{
return addWrite(ID_VAL_DigOut_14, &value);
}


int getStatus_VAL_DigOut_14()
{
return getStatus(ID_VAL_DigOut_14);
}


int doWrite_VAL_DigOut_15(int value)
{
return doWrite(ID_VAL_DigOut_15,  &value);
}


int addWrite_VAL_DigOut_15(int value)
{
return addWrite(ID_VAL_DigOut_15, &value);
}


int getStatus_VAL_DigOut_15()
{
return getStatus(ID_VAL_DigOut_15);
}


int doWrite_VAL_DigOut_16(int value)
{
return doWrite(ID_VAL_DigOut_16,  &value);
}


int addWrite_VAL_DigOut_16(int value)
{
return addWrite(ID_VAL_DigOut_16, &value);
}


int getStatus_VAL_DigOut_16()
{
return getStatus(ID_VAL_DigOut_16);
}


int doWrite_TST_AnIn_1(int value)
{
return doWrite(ID_TST_AnIn_1,  &value);
}


int addWrite_TST_AnIn_1(int value)
{
return addWrite(ID_TST_AnIn_1, &value);
}


int getStatus_TST_AnIn_1()
{
return getStatus(ID_TST_AnIn_1);
}


int doWrite_TST_AnIn_2(int value)
{
return doWrite(ID_TST_AnIn_2,  &value);
}


int addWrite_TST_AnIn_2(int value)
{
return addWrite(ID_TST_AnIn_2, &value);
}


int getStatus_TST_AnIn_2()
{
return getStatus(ID_TST_AnIn_2);
}


int doWrite_TST_AnIn_3(int value)
{
return doWrite(ID_TST_AnIn_3,  &value);
}


int addWrite_TST_AnIn_3(int value)
{
return addWrite(ID_TST_AnIn_3, &value);
}


int getStatus_TST_AnIn_3()
{
return getStatus(ID_TST_AnIn_3);
}


int doWrite_TST_AnIn_4(int value)
{
return doWrite(ID_TST_AnIn_4,  &value);
}


int addWrite_TST_AnIn_4(int value)
{
return addWrite(ID_TST_AnIn_4, &value);
}


int getStatus_TST_AnIn_4()
{
return getStatus(ID_TST_AnIn_4);
}


int doWrite_TST_AnIn_5(int value)
{
return doWrite(ID_TST_AnIn_5,  &value);
}


int addWrite_TST_AnIn_5(int value)
{
return addWrite(ID_TST_AnIn_5, &value);
}


int getStatus_TST_AnIn_5()
{
return getStatus(ID_TST_AnIn_5);
}


int doWrite_TST_AnIn_6(int value)
{
return doWrite(ID_TST_AnIn_6,  &value);
}


int addWrite_TST_AnIn_6(int value)
{
return addWrite(ID_TST_AnIn_6, &value);
}


int getStatus_TST_AnIn_6()
{
return getStatus(ID_TST_AnIn_6);
}


int doWrite_TST_AnIn_7(int value)
{
return doWrite(ID_TST_AnIn_7,  &value);
}


int addWrite_TST_AnIn_7(int value)
{
return addWrite(ID_TST_AnIn_7, &value);
}


int getStatus_TST_AnIn_7()
{
return getStatus(ID_TST_AnIn_7);
}


int doWrite_TST_AnIn_8(int value)
{
return doWrite(ID_TST_AnIn_8,  &value);
}


int addWrite_TST_AnIn_8(int value)
{
return addWrite(ID_TST_AnIn_8, &value);
}


int getStatus_TST_AnIn_8()
{
return getStatus(ID_TST_AnIn_8);
}


int doWrite_TST_AnIn_9(int value)
{
return doWrite(ID_TST_AnIn_9,  &value);
}


int addWrite_TST_AnIn_9(int value)
{
return addWrite(ID_TST_AnIn_9, &value);
}


int getStatus_TST_AnIn_9()
{
return getStatus(ID_TST_AnIn_9);
}


int doWrite_TST_AnIn_10(int value)
{
return doWrite(ID_TST_AnIn_10,  &value);
}


int addWrite_TST_AnIn_10(int value)
{
return addWrite(ID_TST_AnIn_10, &value);
}


int getStatus_TST_AnIn_10()
{
return getStatus(ID_TST_AnIn_10);
}


int doWrite_TST_AnIn_11(int value)
{
return doWrite(ID_TST_AnIn_11,  &value);
}


int addWrite_TST_AnIn_11(int value)
{
return addWrite(ID_TST_AnIn_11, &value);
}


int getStatus_TST_AnIn_11()
{
return getStatus(ID_TST_AnIn_11);
}


int doWrite_TST_AnIn_12(int value)
{
return doWrite(ID_TST_AnIn_12,  &value);
}


int addWrite_TST_AnIn_12(int value)
{
return addWrite(ID_TST_AnIn_12, &value);
}


int getStatus_TST_AnIn_12()
{
return getStatus(ID_TST_AnIn_12);
}


int doWrite_VAL_AnIn_1(int16_t value)
{
return doWrite(ID_VAL_AnIn_1,  &value);
}


int addWrite_VAL_AnIn_1(int16_t value)
{
return addWrite(ID_VAL_AnIn_1, &value);
}


int getStatus_VAL_AnIn_1()
{
return getStatus(ID_VAL_AnIn_1);
}


int doWrite_VAL_AnIn_2(int16_t value)
{
return doWrite(ID_VAL_AnIn_2,  &value);
}


int addWrite_VAL_AnIn_2(int16_t value)
{
return addWrite(ID_VAL_AnIn_2, &value);
}


int getStatus_VAL_AnIn_2()
{
return getStatus(ID_VAL_AnIn_2);
}


int doWrite_VAL_AnIn_3(int16_t value)
{
return doWrite(ID_VAL_AnIn_3,  &value);
}


int addWrite_VAL_AnIn_3(int16_t value)
{
return addWrite(ID_VAL_AnIn_3, &value);
}


int getStatus_VAL_AnIn_3()
{
return getStatus(ID_VAL_AnIn_3);
}


int doWrite_VAL_AnIn_4(int16_t value)
{
return doWrite(ID_VAL_AnIn_4,  &value);
}


int addWrite_VAL_AnIn_4(int16_t value)
{
return addWrite(ID_VAL_AnIn_4, &value);
}


int getStatus_VAL_AnIn_4()
{
return getStatus(ID_VAL_AnIn_4);
}


int doWrite_VAL_AnIn_5(int16_t value)
{
return doWrite(ID_VAL_AnIn_5,  &value);
}


int addWrite_VAL_AnIn_5(int16_t value)
{
return addWrite(ID_VAL_AnIn_5, &value);
}


int getStatus_VAL_AnIn_5()
{
return getStatus(ID_VAL_AnIn_5);
}


int doWrite_VAL_AnIn_6(int16_t value)
{
return doWrite(ID_VAL_AnIn_6,  &value);
}


int addWrite_VAL_AnIn_6(int16_t value)
{
return addWrite(ID_VAL_AnIn_6, &value);
}


int getStatus_VAL_AnIn_6()
{
return getStatus(ID_VAL_AnIn_6);
}


int doWrite_VAL_AnIn_7(int16_t value)
{
return doWrite(ID_VAL_AnIn_7,  &value);
}


int addWrite_VAL_AnIn_7(int16_t value)
{
return addWrite(ID_VAL_AnIn_7, &value);
}


int getStatus_VAL_AnIn_7()
{
return getStatus(ID_VAL_AnIn_7);
}


int doWrite_VAL_AnIn_8(int16_t value)
{
return doWrite(ID_VAL_AnIn_8,  &value);
}


int addWrite_VAL_AnIn_8(int16_t value)
{
return addWrite(ID_VAL_AnIn_8, &value);
}


int getStatus_VAL_AnIn_8()
{
return getStatus(ID_VAL_AnIn_8);
}


int doWrite_VAL_AnIn_9(int16_t value)
{
return doWrite(ID_VAL_AnIn_9,  &value);
}


int addWrite_VAL_AnIn_9(int16_t value)
{
return addWrite(ID_VAL_AnIn_9, &value);
}


int getStatus_VAL_AnIn_9()
{
return getStatus(ID_VAL_AnIn_9);
}


int doWrite_VAL_AnIn_10(int16_t value)
{
return doWrite(ID_VAL_AnIn_10,  &value);
}


int addWrite_VAL_AnIn_10(int16_t value)
{
return addWrite(ID_VAL_AnIn_10, &value);
}


int getStatus_VAL_AnIn_10()
{
return getStatus(ID_VAL_AnIn_10);
}


int doWrite_VAL_AnIn_11(int16_t value)
{
return doWrite(ID_VAL_AnIn_11,  &value);
}


int addWrite_VAL_AnIn_11(int16_t value)
{
return addWrite(ID_VAL_AnIn_11, &value);
}


int getStatus_VAL_AnIn_11()
{
return getStatus(ID_VAL_AnIn_11);
}


int doWrite_VAL_AnIn_12(int16_t value)
{
return doWrite(ID_VAL_AnIn_12,  &value);
}


int addWrite_VAL_AnIn_12(int16_t value)
{
return addWrite(ID_VAL_AnIn_12, &value);
}


int getStatus_VAL_AnIn_12()
{
return getStatus(ID_VAL_AnIn_12);
}


int doWrite_VAL_AnInConf_1(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_1,  &value);
}


int addWrite_VAL_AnInConf_1(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_1, &value);
}


int getStatus_VAL_AnInConf_1()
{
return getStatus(ID_VAL_AnInConf_1);
}


int doWrite_VAL_AnInConf_2(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_2,  &value);
}


int addWrite_VAL_AnInConf_2(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_2, &value);
}


int getStatus_VAL_AnInConf_2()
{
return getStatus(ID_VAL_AnInConf_2);
}


int doWrite_VAL_AnInConf_3(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_3,  &value);
}


int addWrite_VAL_AnInConf_3(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_3, &value);
}


int getStatus_VAL_AnInConf_3()
{
return getStatus(ID_VAL_AnInConf_3);
}


int doWrite_VAL_AnInConf_4(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_4,  &value);
}


int addWrite_VAL_AnInConf_4(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_4, &value);
}


int getStatus_VAL_AnInConf_4()
{
return getStatus(ID_VAL_AnInConf_4);
}


int doWrite_VAL_AnInConf_5(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_5,  &value);
}


int addWrite_VAL_AnInConf_5(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_5, &value);
}


int getStatus_VAL_AnInConf_5()
{
return getStatus(ID_VAL_AnInConf_5);
}


int doWrite_VAL_AnInConf_6(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_6,  &value);
}


int addWrite_VAL_AnInConf_6(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_6, &value);
}


int getStatus_VAL_AnInConf_6()
{
return getStatus(ID_VAL_AnInConf_6);
}


int doWrite_VAL_AnInConf_7(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_7,  &value);
}


int addWrite_VAL_AnInConf_7(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_7, &value);
}


int getStatus_VAL_AnInConf_7()
{
return getStatus(ID_VAL_AnInConf_7);
}


int doWrite_VAL_AnInConf_8(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_8,  &value);
}


int addWrite_VAL_AnInConf_8(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_8, &value);
}


int getStatus_VAL_AnInConf_8()
{
return getStatus(ID_VAL_AnInConf_8);
}


int doWrite_VAL_AnInConf_9(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_9,  &value);
}


int addWrite_VAL_AnInConf_9(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_9, &value);
}


int getStatus_VAL_AnInConf_9()
{
return getStatus(ID_VAL_AnInConf_9);
}


int doWrite_VAL_AnInConf_10(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_10,  &value);
}


int addWrite_VAL_AnInConf_10(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_10, &value);
}


int getStatus_VAL_AnInConf_10()
{
return getStatus(ID_VAL_AnInConf_10);
}


int doWrite_VAL_AnInConf_11(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_11,  &value);
}


int addWrite_VAL_AnInConf_11(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_11, &value);
}


int getStatus_VAL_AnInConf_11()
{
return getStatus(ID_VAL_AnInConf_11);
}


int doWrite_VAL_AnInConf_12(u_int16_t value)
{
return doWrite(ID_VAL_AnInConf_12,  &value);
}


int addWrite_VAL_AnInConf_12(u_int16_t value)
{
return addWrite(ID_VAL_AnInConf_12, &value);
}


int getStatus_VAL_AnInConf_12()
{
return getStatus(ID_VAL_AnInConf_12);
}


int doWrite_VAL_AnInFltr_1(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_1,  &value);
}


int addWrite_VAL_AnInFltr_1(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_1, &value);
}


int getStatus_VAL_AnInFltr_1()
{
return getStatus(ID_VAL_AnInFltr_1);
}


int doWrite_VAL_AnInFltr_2(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_2,  &value);
}


int addWrite_VAL_AnInFltr_2(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_2, &value);
}


int getStatus_VAL_AnInFltr_2()
{
return getStatus(ID_VAL_AnInFltr_2);
}


int doWrite_VAL_AnInFltr_3(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_3,  &value);
}


int addWrite_VAL_AnInFltr_3(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_3, &value);
}


int getStatus_VAL_AnInFltr_3()
{
return getStatus(ID_VAL_AnInFltr_3);
}


int doWrite_VAL_AnInFltr_4(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_4,  &value);
}


int addWrite_VAL_AnInFltr_4(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_4, &value);
}


int getStatus_VAL_AnInFltr_4()
{
return getStatus(ID_VAL_AnInFltr_4);
}


int doWrite_VAL_AnInFltr_5(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_5,  &value);
}


int addWrite_VAL_AnInFltr_5(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_5, &value);
}


int getStatus_VAL_AnInFltr_5()
{
return getStatus(ID_VAL_AnInFltr_5);
}


int doWrite_VAL_AnInFltr_6(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_6,  &value);
}


int addWrite_VAL_AnInFltr_6(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_6, &value);
}


int getStatus_VAL_AnInFltr_6()
{
return getStatus(ID_VAL_AnInFltr_6);
}


int doWrite_VAL_AnInFltr_7(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_7,  &value);
}


int addWrite_VAL_AnInFltr_7(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_7, &value);
}


int getStatus_VAL_AnInFltr_7()
{
return getStatus(ID_VAL_AnInFltr_7);
}


int doWrite_VAL_AnInFltr_8(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_8,  &value);
}


int addWrite_VAL_AnInFltr_8(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_8, &value);
}


int getStatus_VAL_AnInFltr_8()
{
return getStatus(ID_VAL_AnInFltr_8);
}


int doWrite_VAL_AnInFltr_9(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_9,  &value);
}


int addWrite_VAL_AnInFltr_9(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_9, &value);
}


int getStatus_VAL_AnInFltr_9()
{
return getStatus(ID_VAL_AnInFltr_9);
}


int doWrite_VAL_AnInFltr_10(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_10,  &value);
}


int addWrite_VAL_AnInFltr_10(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_10, &value);
}


int getStatus_VAL_AnInFltr_10()
{
return getStatus(ID_VAL_AnInFltr_10);
}


int doWrite_VAL_AnInFltr_11(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_11,  &value);
}


int addWrite_VAL_AnInFltr_11(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_11, &value);
}


int getStatus_VAL_AnInFltr_11()
{
return getStatus(ID_VAL_AnInFltr_11);
}


int doWrite_VAL_AnInFltr_12(u_int16_t value)
{
return doWrite(ID_VAL_AnInFltr_12,  &value);
}


int addWrite_VAL_AnInFltr_12(u_int16_t value)
{
return addWrite(ID_VAL_AnInFltr_12, &value);
}


int getStatus_VAL_AnInFltr_12()
{
return getStatus(ID_VAL_AnInFltr_12);
}


int doWrite_RES_AnIn_1(int16_t value)
{
return doWrite(ID_RES_AnIn_1,  &value);
}


int addWrite_RES_AnIn_1(int16_t value)
{
return addWrite(ID_RES_AnIn_1, &value);
}


int getStatus_RES_AnIn_1()
{
return getStatus(ID_RES_AnIn_1);
}


int doWrite_RES_AnIn_2(int16_t value)
{
return doWrite(ID_RES_AnIn_2,  &value);
}


int addWrite_RES_AnIn_2(int16_t value)
{
return addWrite(ID_RES_AnIn_2, &value);
}


int getStatus_RES_AnIn_2()
{
return getStatus(ID_RES_AnIn_2);
}


int doWrite_RES_AnIn_3(int16_t value)
{
return doWrite(ID_RES_AnIn_3,  &value);
}


int addWrite_RES_AnIn_3(int16_t value)
{
return addWrite(ID_RES_AnIn_3, &value);
}


int getStatus_RES_AnIn_3()
{
return getStatus(ID_RES_AnIn_3);
}


int doWrite_RES_AnIn_4(int16_t value)
{
return doWrite(ID_RES_AnIn_4,  &value);
}


int addWrite_RES_AnIn_4(int16_t value)
{
return addWrite(ID_RES_AnIn_4, &value);
}


int getStatus_RES_AnIn_4()
{
return getStatus(ID_RES_AnIn_4);
}


int doWrite_RES_AnIn_5(int16_t value)
{
return doWrite(ID_RES_AnIn_5,  &value);
}


int addWrite_RES_AnIn_5(int16_t value)
{
return addWrite(ID_RES_AnIn_5, &value);
}


int getStatus_RES_AnIn_5()
{
return getStatus(ID_RES_AnIn_5);
}


int doWrite_RES_AnIn_6(int16_t value)
{
return doWrite(ID_RES_AnIn_6,  &value);
}


int addWrite_RES_AnIn_6(int16_t value)
{
return addWrite(ID_RES_AnIn_6, &value);
}


int getStatus_RES_AnIn_6()
{
return getStatus(ID_RES_AnIn_6);
}


int doWrite_RES_AnIn_7(int16_t value)
{
return doWrite(ID_RES_AnIn_7,  &value);
}


int addWrite_RES_AnIn_7(int16_t value)
{
return addWrite(ID_RES_AnIn_7, &value);
}


int getStatus_RES_AnIn_7()
{
return getStatus(ID_RES_AnIn_7);
}


int doWrite_RES_AnIn_8(int16_t value)
{
return doWrite(ID_RES_AnIn_8,  &value);
}


int addWrite_RES_AnIn_8(int16_t value)
{
return addWrite(ID_RES_AnIn_8, &value);
}


int getStatus_RES_AnIn_8()
{
return getStatus(ID_RES_AnIn_8);
}


int doWrite_RES_AnIn_9(int16_t value)
{
return doWrite(ID_RES_AnIn_9,  &value);
}


int addWrite_RES_AnIn_9(int16_t value)
{
return addWrite(ID_RES_AnIn_9, &value);
}


int getStatus_RES_AnIn_9()
{
return getStatus(ID_RES_AnIn_9);
}


int doWrite_RES_AnIn_10(int16_t value)
{
return doWrite(ID_RES_AnIn_10,  &value);
}


int addWrite_RES_AnIn_10(int16_t value)
{
return addWrite(ID_RES_AnIn_10, &value);
}


int getStatus_RES_AnIn_10()
{
return getStatus(ID_RES_AnIn_10);
}


int doWrite_RES_AnIn_11(int16_t value)
{
return doWrite(ID_RES_AnIn_11,  &value);
}


int addWrite_RES_AnIn_11(int16_t value)
{
return addWrite(ID_RES_AnIn_11, &value);
}


int getStatus_RES_AnIn_11()
{
return getStatus(ID_RES_AnIn_11);
}


int doWrite_RES_AnIn_12(int16_t value)
{
return doWrite(ID_RES_AnIn_12,  &value);
}


int addWrite_RES_AnIn_12(int16_t value)
{
return addWrite(ID_RES_AnIn_12, &value);
}


int getStatus_RES_AnIn_12()
{
return getStatus(ID_RES_AnIn_12);
}


int doWrite_RES_AnInStts_1(int16_t value)
{
return doWrite(ID_RES_AnInStts_1,  &value);
}


int addWrite_RES_AnInStts_1(int16_t value)
{
return addWrite(ID_RES_AnInStts_1, &value);
}


int getStatus_RES_AnInStts_1()
{
return getStatus(ID_RES_AnInStts_1);
}


int doWrite_RES_AnInStts_2(int16_t value)
{
return doWrite(ID_RES_AnInStts_2,  &value);
}


int addWrite_RES_AnInStts_2(int16_t value)
{
return addWrite(ID_RES_AnInStts_2, &value);
}


int getStatus_RES_AnInStts_2()
{
return getStatus(ID_RES_AnInStts_2);
}


int doWrite_RES_AnInStts_3(int16_t value)
{
return doWrite(ID_RES_AnInStts_3,  &value);
}


int addWrite_RES_AnInStts_3(int16_t value)
{
return addWrite(ID_RES_AnInStts_3, &value);
}


int getStatus_RES_AnInStts_3()
{
return getStatus(ID_RES_AnInStts_3);
}


int doWrite_RES_AnInStts_4(int16_t value)
{
return doWrite(ID_RES_AnInStts_4,  &value);
}


int addWrite_RES_AnInStts_4(int16_t value)
{
return addWrite(ID_RES_AnInStts_4, &value);
}


int getStatus_RES_AnInStts_4()
{
return getStatus(ID_RES_AnInStts_4);
}


int doWrite_RES_AnInStts_5(int16_t value)
{
return doWrite(ID_RES_AnInStts_5,  &value);
}


int addWrite_RES_AnInStts_5(int16_t value)
{
return addWrite(ID_RES_AnInStts_5, &value);
}


int getStatus_RES_AnInStts_5()
{
return getStatus(ID_RES_AnInStts_5);
}


int doWrite_RES_AnInStts_6(int16_t value)
{
return doWrite(ID_RES_AnInStts_6,  &value);
}


int addWrite_RES_AnInStts_6(int16_t value)
{
return addWrite(ID_RES_AnInStts_6, &value);
}


int getStatus_RES_AnInStts_6()
{
return getStatus(ID_RES_AnInStts_6);
}


int doWrite_RES_AnInStts_7(int16_t value)
{
return doWrite(ID_RES_AnInStts_7,  &value);
}


int addWrite_RES_AnInStts_7(int16_t value)
{
return addWrite(ID_RES_AnInStts_7, &value);
}


int getStatus_RES_AnInStts_7()
{
return getStatus(ID_RES_AnInStts_7);
}


int doWrite_RES_AnInStts_8(int16_t value)
{
return doWrite(ID_RES_AnInStts_8,  &value);
}


int addWrite_RES_AnInStts_8(int16_t value)
{
return addWrite(ID_RES_AnInStts_8, &value);
}


int getStatus_RES_AnInStts_8()
{
return getStatus(ID_RES_AnInStts_8);
}


int doWrite_RES_AnInStts_9(int16_t value)
{
return doWrite(ID_RES_AnInStts_9,  &value);
}


int addWrite_RES_AnInStts_9(int16_t value)
{
return addWrite(ID_RES_AnInStts_9, &value);
}


int getStatus_RES_AnInStts_9()
{
return getStatus(ID_RES_AnInStts_9);
}


int doWrite_RES_AnInStts_10(int16_t value)
{
return doWrite(ID_RES_AnInStts_10,  &value);
}


int addWrite_RES_AnInStts_10(int16_t value)
{
return addWrite(ID_RES_AnInStts_10, &value);
}


int getStatus_RES_AnInStts_10()
{
return getStatus(ID_RES_AnInStts_10);
}


int doWrite_RES_AnInStts_11(int16_t value)
{
return doWrite(ID_RES_AnInStts_11,  &value);
}


int addWrite_RES_AnInStts_11(int16_t value)
{
return addWrite(ID_RES_AnInStts_11, &value);
}


int getStatus_RES_AnInStts_11()
{
return getStatus(ID_RES_AnInStts_11);
}


int doWrite_RES_AnInStts_12(int16_t value)
{
return doWrite(ID_RES_AnInStts_12,  &value);
}


int addWrite_RES_AnInStts_12(int16_t value)
{
return addWrite(ID_RES_AnInStts_12, &value);
}


int getStatus_RES_AnInStts_12()
{
return getStatus(ID_RES_AnInStts_12);
}


int doWrite_TST_AnOut_1(int value)
{
return doWrite(ID_TST_AnOut_1,  &value);
}


int addWrite_TST_AnOut_1(int value)
{
return addWrite(ID_TST_AnOut_1, &value);
}


int getStatus_TST_AnOut_1()
{
return getStatus(ID_TST_AnOut_1);
}


int doWrite_TST_AnOut_2(int value)
{
return doWrite(ID_TST_AnOut_2,  &value);
}


int addWrite_TST_AnOut_2(int value)
{
return addWrite(ID_TST_AnOut_2, &value);
}


int getStatus_TST_AnOut_2()
{
return getStatus(ID_TST_AnOut_2);
}


int doWrite_TST_AnOut_3(int value)
{
return doWrite(ID_TST_AnOut_3,  &value);
}


int addWrite_TST_AnOut_3(int value)
{
return addWrite(ID_TST_AnOut_3, &value);
}


int getStatus_TST_AnOut_3()
{
return getStatus(ID_TST_AnOut_3);
}


int doWrite_TST_AnOut_4(int value)
{
return doWrite(ID_TST_AnOut_4,  &value);
}


int addWrite_TST_AnOut_4(int value)
{
return addWrite(ID_TST_AnOut_4, &value);
}


int getStatus_TST_AnOut_4()
{
return getStatus(ID_TST_AnOut_4);
}


int doWrite_VAL_AnOut_1(int16_t value)
{
return doWrite(ID_VAL_AnOut_1,  &value);
}


int addWrite_VAL_AnOut_1(int16_t value)
{
return addWrite(ID_VAL_AnOut_1, &value);
}


int getStatus_VAL_AnOut_1()
{
return getStatus(ID_VAL_AnOut_1);
}


int doWrite_VAL_AnOut_2(int16_t value)
{
return doWrite(ID_VAL_AnOut_2,  &value);
}


int addWrite_VAL_AnOut_2(int16_t value)
{
return addWrite(ID_VAL_AnOut_2, &value);
}


int getStatus_VAL_AnOut_2()
{
return getStatus(ID_VAL_AnOut_2);
}


int doWrite_VAL_AnOut_3(int16_t value)
{
return doWrite(ID_VAL_AnOut_3,  &value);
}


int addWrite_VAL_AnOut_3(int16_t value)
{
return addWrite(ID_VAL_AnOut_3, &value);
}


int getStatus_VAL_AnOut_3()
{
return getStatus(ID_VAL_AnOut_3);
}


int doWrite_VAL_AnOut_4(int16_t value)
{
return doWrite(ID_VAL_AnOut_4,  &value);
}


int addWrite_VAL_AnOut_4(int16_t value)
{
return addWrite(ID_VAL_AnOut_4, &value);
}


int getStatus_VAL_AnOut_4()
{
return getStatus(ID_VAL_AnOut_4);
}


int doWrite_VAL_AnOutConf_1(u_int16_t value)
{
return doWrite(ID_VAL_AnOutConf_1,  &value);
}


int addWrite_VAL_AnOutConf_1(u_int16_t value)
{
return addWrite(ID_VAL_AnOutConf_1, &value);
}


int getStatus_VAL_AnOutConf_1()
{
return getStatus(ID_VAL_AnOutConf_1);
}


int doWrite_VAL_AnOutConf_2(u_int16_t value)
{
return doWrite(ID_VAL_AnOutConf_2,  &value);
}


int addWrite_VAL_AnOutConf_2(u_int16_t value)
{
return addWrite(ID_VAL_AnOutConf_2, &value);
}


int getStatus_VAL_AnOutConf_2()
{
return getStatus(ID_VAL_AnOutConf_2);
}


int doWrite_VAL_AnOutConf_3(u_int16_t value)
{
return doWrite(ID_VAL_AnOutConf_3,  &value);
}


int addWrite_VAL_AnOutConf_3(u_int16_t value)
{
return addWrite(ID_VAL_AnOutConf_3, &value);
}


int getStatus_VAL_AnOutConf_3()
{
return getStatus(ID_VAL_AnOutConf_3);
}


int doWrite_VAL_AnOutConf_4(u_int16_t value)
{
return doWrite(ID_VAL_AnOutConf_4,  &value);
}


int addWrite_VAL_AnOutConf_4(u_int16_t value)
{
return addWrite(ID_VAL_AnOutConf_4, &value);
}


int getStatus_VAL_AnOutConf_4()
{
return getStatus(ID_VAL_AnOutConf_4);
}


int doWrite_RES_AnOutStts_1(int16_t value)
{
return doWrite(ID_RES_AnOutStts_1,  &value);
}


int addWrite_RES_AnOutStts_1(int16_t value)
{
return addWrite(ID_RES_AnOutStts_1, &value);
}


int getStatus_RES_AnOutStts_1()
{
return getStatus(ID_RES_AnOutStts_1);
}


int doWrite_RES_AnOutStts_2(int16_t value)
{
return doWrite(ID_RES_AnOutStts_2,  &value);
}


int addWrite_RES_AnOutStts_2(int16_t value)
{
return addWrite(ID_RES_AnOutStts_2, &value);
}


int getStatus_RES_AnOutStts_2()
{
return getStatus(ID_RES_AnOutStts_2);
}


int doWrite_RES_AnOutStts_3(int16_t value)
{
return doWrite(ID_RES_AnOutStts_3,  &value);
}


int addWrite_RES_AnOutStts_3(int16_t value)
{
return addWrite(ID_RES_AnOutStts_3, &value);
}


int getStatus_RES_AnOutStts_3()
{
return getStatus(ID_RES_AnOutStts_3);
}


int doWrite_RES_AnOutStts_4(int16_t value)
{
return doWrite(ID_RES_AnOutStts_4,  &value);
}


int addWrite_RES_AnOutStts_4(int16_t value)
{
return addWrite(ID_RES_AnOutStts_4, &value);
}


int getStatus_RES_AnOutStts_4()
{
return getStatus(ID_RES_AnOutStts_4);
}


int doWrite_TST_Tamb(int value)
{
return doWrite(ID_TST_Tamb,  &value);
}


int addWrite_TST_Tamb(int value)
{
return addWrite(ID_TST_Tamb, &value);
}


int getStatus_TST_Tamb()
{
return getStatus(ID_TST_Tamb);
}


int doWrite_TST_RPM(int value)
{
return doWrite(ID_TST_RPM,  &value);
}


int addWrite_TST_RPM(int value)
{
return addWrite(ID_TST_RPM, &value);
}


int getStatus_TST_RPM()
{
return getStatus(ID_TST_RPM);
}


int doWrite_TST_FWrevision(int value)
{
return doWrite(ID_TST_FWrevision,  &value);
}


int addWrite_TST_FWrevision(int value)
{
return addWrite(ID_TST_FWrevision, &value);
}


int getStatus_TST_FWrevision()
{
return getStatus(ID_TST_FWrevision);
}


int doWrite_TST_HWconfig(int value)
{
return doWrite(ID_TST_HWconfig,  &value);
}


int addWrite_TST_HWconfig(int value)
{
return addWrite(ID_TST_HWconfig, &value);
}


int getStatus_TST_HWconfig()
{
return getStatus(ID_TST_HWconfig);
}


int doWrite_VAL_Tamb(int16_t value)
{
return doWrite(ID_VAL_Tamb,  &value);
}


int addWrite_VAL_Tamb(int16_t value)
{
return addWrite(ID_VAL_Tamb, &value);
}


int getStatus_VAL_Tamb()
{
return getStatus(ID_VAL_Tamb);
}


int doWrite_VAL_RPM(u_int16_t value)
{
return doWrite(ID_VAL_RPM,  &value);
}


int addWrite_VAL_RPM(u_int16_t value)
{
return addWrite(ID_VAL_RPM, &value);
}


int getStatus_VAL_RPM()
{
return getStatus(ID_VAL_RPM);
}


int doWrite_VAL_FWrevision(u_int16_t value)
{
return doWrite(ID_VAL_FWrevision,  &value);
}


int addWrite_VAL_FWrevision(u_int16_t value)
{
return addWrite(ID_VAL_FWrevision, &value);
}


int getStatus_VAL_FWrevision()
{
return getStatus(ID_VAL_FWrevision);
}


int doWrite_VAL_HWconfig(u_int16_t value)
{
return doWrite(ID_VAL_HWconfig,  &value);
}


int addWrite_VAL_HWconfig(u_int16_t value)
{
return addWrite(ID_VAL_HWconfig, &value);
}


int getStatus_VAL_HWconfig()
{
return getStatus(ID_VAL_HWconfig);
}


int doWrite_RES_Tamb(int16_t value)
{
return doWrite(ID_RES_Tamb,  &value);
}


int addWrite_RES_Tamb(int16_t value)
{
return addWrite(ID_RES_Tamb, &value);
}


int getStatus_RES_Tamb()
{
return getStatus(ID_RES_Tamb);
}


int doWrite_RES_RPM(u_int16_t value)
{
return doWrite(ID_RES_RPM,  &value);
}


int addWrite_RES_RPM(u_int16_t value)
{
return addWrite(ID_RES_RPM, &value);
}


int getStatus_RES_RPM()
{
return getStatus(ID_RES_RPM);
}


int doWrite_RES_FWrevision(u_int16_t value)
{
return doWrite(ID_RES_FWrevision,  &value);
}


int addWrite_RES_FWrevision(u_int16_t value)
{
return addWrite(ID_RES_FWrevision, &value);
}


int getStatus_RES_FWrevision()
{
return getStatus(ID_RES_FWrevision);
}


int doWrite_RES_HWconfig(u_int16_t value)
{
return doWrite(ID_RES_HWconfig,  &value);
}


int addWrite_RES_HWconfig(u_int16_t value)
{
return addWrite(ID_RES_HWconfig, &value);
}


int getStatus_RES_HWconfig()
{
return getStatus(ID_RES_HWconfig);
}


int doWrite_TST_RTUS_WR(int value)
{
return doWrite(ID_TST_RTUS_WR,  &value);
}


int addWrite_TST_RTUS_WR(int value)
{
return addWrite(ID_TST_RTUS_WR, &value);
}


int getStatus_TST_RTUS_WR()
{
return getStatus(ID_TST_RTUS_WR);
}


int doWrite_TST_RTUS_RD(int value)
{
return doWrite(ID_TST_RTUS_RD,  &value);
}


int addWrite_TST_RTUS_RD(int value)
{
return addWrite(ID_TST_RTUS_RD, &value);
}


int getStatus_TST_RTUS_RD()
{
return getStatus(ID_TST_RTUS_RD);
}


int doWrite_TST_RTU_WR(int value)
{
return doWrite(ID_TST_RTU_WR,  &value);
}


int addWrite_TST_RTU_WR(int value)
{
return addWrite(ID_TST_RTU_WR, &value);
}


int getStatus_TST_RTU_WR()
{
return getStatus(ID_TST_RTU_WR);
}


int doWrite_TST_RTU_RD(int value)
{
return doWrite(ID_TST_RTU_RD,  &value);
}


int addWrite_TST_RTU_RD(int value)
{
return addWrite(ID_TST_RTU_RD, &value);
}


int getStatus_TST_RTU_RD()
{
return getStatus(ID_TST_RTU_RD);
}


int doWrite_TST_RTU3_WR(int value)
{
return doWrite(ID_TST_RTU3_WR,  &value);
}


int addWrite_TST_RTU3_WR(int value)
{
return addWrite(ID_TST_RTU3_WR, &value);
}


int getStatus_TST_RTU3_WR()
{
return getStatus(ID_TST_RTU3_WR);
}


int doWrite_TST_RTU3_RD(int value)
{
return doWrite(ID_TST_RTU3_RD,  &value);
}


int addWrite_TST_RTU3_RD(int value)
{
return addWrite(ID_TST_RTU3_RD, &value);
}


int getStatus_TST_RTU3_RD()
{
return getStatus(ID_TST_RTU3_RD);
}


int doWrite_TST_CAN_WR(int value)
{
return doWrite(ID_TST_CAN_WR,  &value);
}


int addWrite_TST_CAN_WR(int value)
{
return addWrite(ID_TST_CAN_WR, &value);
}


int getStatus_TST_CAN_WR()
{
return getStatus(ID_TST_CAN_WR);
}


int doWrite_TST_CAN_RD(int value)
{
return doWrite(ID_TST_CAN_RD,  &value);
}


int addWrite_TST_CAN_RD(int value)
{
return addWrite(ID_TST_CAN_RD, &value);
}


int getStatus_TST_CAN_RD()
{
return getStatus(ID_TST_CAN_RD);
}


int doWrite_VAL_RTUS_WR(int value)
{
return doWrite(ID_VAL_RTUS_WR,  &value);
}


int addWrite_VAL_RTUS_WR(int value)
{
return addWrite(ID_VAL_RTUS_WR, &value);
}


int getStatus_VAL_RTUS_WR()
{
return getStatus(ID_VAL_RTUS_WR);
}


int doWrite_VAL_RTUS_RD(int value)
{
return doWrite(ID_VAL_RTUS_RD,  &value);
}


int addWrite_VAL_RTUS_RD(int value)
{
return addWrite(ID_VAL_RTUS_RD, &value);
}


int getStatus_VAL_RTUS_RD()
{
return getStatus(ID_VAL_RTUS_RD);
}


int doWrite_VAL_RTU_WR(int value)
{
return doWrite(ID_VAL_RTU_WR,  &value);
}


int addWrite_VAL_RTU_WR(int value)
{
return addWrite(ID_VAL_RTU_WR, &value);
}


int getStatus_VAL_RTU_WR()
{
return getStatus(ID_VAL_RTU_WR);
}


int doWrite_VAL_RTU_RD(int value)
{
return doWrite(ID_VAL_RTU_RD,  &value);
}


int addWrite_VAL_RTU_RD(int value)
{
return addWrite(ID_VAL_RTU_RD, &value);
}


int getStatus_VAL_RTU_RD()
{
return getStatus(ID_VAL_RTU_RD);
}


int doWrite_VAL_RTU3_WR(int value)
{
return doWrite(ID_VAL_RTU3_WR,  &value);
}


int addWrite_VAL_RTU3_WR(int value)
{
return addWrite(ID_VAL_RTU3_WR, &value);
}


int getStatus_VAL_RTU3_WR()
{
return getStatus(ID_VAL_RTU3_WR);
}


int doWrite_VAL_RTU3_RD(int value)
{
return doWrite(ID_VAL_RTU3_RD,  &value);
}


int addWrite_VAL_RTU3_RD(int value)
{
return addWrite(ID_VAL_RTU3_RD, &value);
}


int getStatus_VAL_RTU3_RD()
{
return getStatus(ID_VAL_RTU3_RD);
}


int doWrite_VAL_CAN_WR(int value)
{
return doWrite(ID_VAL_CAN_WR,  &value);
}


int addWrite_VAL_CAN_WR(int value)
{
return addWrite(ID_VAL_CAN_WR, &value);
}


int getStatus_VAL_CAN_WR()
{
return getStatus(ID_VAL_CAN_WR);
}


int doWrite_VAL_CAN_RD(int value)
{
return doWrite(ID_VAL_CAN_RD,  &value);
}


int addWrite_VAL_CAN_RD(int value)
{
return addWrite(ID_VAL_CAN_RD, &value);
}


int getStatus_VAL_CAN_RD()
{
return getStatus(ID_VAL_CAN_RD);
}


int doWrite_RES_RTUS_WR(int value)
{
return doWrite(ID_RES_RTUS_WR,  &value);
}


int addWrite_RES_RTUS_WR(int value)
{
return addWrite(ID_RES_RTUS_WR, &value);
}


int getStatus_RES_RTUS_WR()
{
return getStatus(ID_RES_RTUS_WR);
}


int doWrite_RES_RTUS_RD(int value)
{
return doWrite(ID_RES_RTUS_RD,  &value);
}


int addWrite_RES_RTUS_RD(int value)
{
return addWrite(ID_RES_RTUS_RD, &value);
}


int getStatus_RES_RTUS_RD()
{
return getStatus(ID_RES_RTUS_RD);
}


int doWrite_RES_RTU_WR(int value)
{
return doWrite(ID_RES_RTU_WR,  &value);
}


int addWrite_RES_RTU_WR(int value)
{
return addWrite(ID_RES_RTU_WR, &value);
}


int getStatus_RES_RTU_WR()
{
return getStatus(ID_RES_RTU_WR);
}


int doWrite_RES_RTU_RD(int value)
{
return doWrite(ID_RES_RTU_RD,  &value);
}


int addWrite_RES_RTU_RD(int value)
{
return addWrite(ID_RES_RTU_RD, &value);
}


int getStatus_RES_RTU_RD()
{
return getStatus(ID_RES_RTU_RD);
}


int doWrite_RES_RTU3_WR(int value)
{
return doWrite(ID_RES_RTU3_WR,  &value);
}


int addWrite_RES_RTU3_WR(int value)
{
return addWrite(ID_RES_RTU3_WR, &value);
}


int getStatus_RES_RTU3_WR()
{
return getStatus(ID_RES_RTU3_WR);
}


int doWrite_RES_RTU3_RD(int value)
{
return doWrite(ID_RES_RTU3_RD,  &value);
}


int addWrite_RES_RTU3_RD(int value)
{
return addWrite(ID_RES_RTU3_RD, &value);
}


int getStatus_RES_RTU3_RD()
{
return getStatus(ID_RES_RTU3_RD);
}


int doWrite_RES_CAN_WR(int value)
{
return doWrite(ID_RES_CAN_WR,  &value);
}


int addWrite_RES_CAN_WR(int value)
{
return addWrite(ID_RES_CAN_WR, &value);
}


int getStatus_RES_CAN_WR()
{
return getStatus(ID_RES_CAN_WR);
}


int doWrite_RES_CAN_RD(int value)
{
return doWrite(ID_RES_CAN_RD,  &value);
}


int addWrite_RES_CAN_RD(int value)
{
return addWrite(ID_RES_CAN_RD, &value);
}


int getStatus_RES_CAN_RD()
{
return getStatus(ID_RES_CAN_RD);
}


int doWrite_TEST_STATUS(u_int16_t value)
{
return doWrite(ID_TEST_STATUS,  &value);
}


int addWrite_TEST_STATUS(u_int16_t value)
{
return addWrite(ID_TEST_STATUS, &value);
}


int getStatus_TEST_STATUS()
{
return getStatus(ID_TEST_STATUS);
}


int doWrite_RTU0_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_RTU0_TYPE_PORT,  &value);
}


int addWrite_RTU0_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_RTU0_TYPE_PORT, &value);
}


int getStatus_RTU0_TYPE_PORT()
{
return getStatus(ID_RTU0_TYPE_PORT);
}


int doWrite_RTU0_BAUDRATE(u_int32_t value)
{
return doWrite(ID_RTU0_BAUDRATE,  &value);
}


int addWrite_RTU0_BAUDRATE(u_int32_t value)
{
return addWrite(ID_RTU0_BAUDRATE, &value);
}


int getStatus_RTU0_BAUDRATE()
{
return getStatus(ID_RTU0_BAUDRATE);
}


int doWrite_RTU0_STATUS(u_int32_t value)
{
return doWrite(ID_RTU0_STATUS,  &value);
}


int addWrite_RTU0_STATUS(u_int32_t value)
{
return addWrite(ID_RTU0_STATUS, &value);
}


int getStatus_RTU0_STATUS()
{
return getStatus(ID_RTU0_STATUS);
}


int doWrite_RTU0_READS(u_int32_t value)
{
return doWrite(ID_RTU0_READS,  &value);
}


int addWrite_RTU0_READS(u_int32_t value)
{
return addWrite(ID_RTU0_READS, &value);
}


int getStatus_RTU0_READS()
{
return getStatus(ID_RTU0_READS);
}


int doWrite_RTU0_WRITES(u_int32_t value)
{
return doWrite(ID_RTU0_WRITES,  &value);
}


int addWrite_RTU0_WRITES(u_int32_t value)
{
return addWrite(ID_RTU0_WRITES, &value);
}


int getStatus_RTU0_WRITES()
{
return getStatus(ID_RTU0_WRITES);
}


int doWrite_RTU0_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_RTU0_TIMEOUTS,  &value);
}


int addWrite_RTU0_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_RTU0_TIMEOUTS, &value);
}


int getStatus_RTU0_TIMEOUTS()
{
return getStatus(ID_RTU0_TIMEOUTS);
}


int doWrite_RTU0_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_RTU0_COMM_ERRORS,  &value);
}


int addWrite_RTU0_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_RTU0_COMM_ERRORS, &value);
}


int getStatus_RTU0_COMM_ERRORS()
{
return getStatus(ID_RTU0_COMM_ERRORS);
}


int doWrite_RTU0_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_RTU0_LAST_ERROR,  &value);
}


int addWrite_RTU0_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_RTU0_LAST_ERROR, &value);
}


int getStatus_RTU0_LAST_ERROR()
{
return getStatus(ID_RTU0_LAST_ERROR);
}


int doWrite_RTU0_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU0_WRITE_QUEUE,  &value);
}


int addWrite_RTU0_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU0_WRITE_QUEUE, &value);
}


int getStatus_RTU0_WRITE_QUEUE()
{
return getStatus(ID_RTU0_WRITE_QUEUE);
}


int doWrite_RTU0_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU0_READ_QUEUE,  &value);
}


int addWrite_RTU0_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU0_READ_QUEUE, &value);
}


int getStatus_RTU0_READ_QUEUE()
{
return getStatus(ID_RTU0_READ_QUEUE);
}


int doWrite_RTU1_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_RTU1_TYPE_PORT,  &value);
}


int addWrite_RTU1_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_RTU1_TYPE_PORT, &value);
}


int getStatus_RTU1_TYPE_PORT()
{
return getStatus(ID_RTU1_TYPE_PORT);
}


int doWrite_RTU1_BAUDRATE(u_int32_t value)
{
return doWrite(ID_RTU1_BAUDRATE,  &value);
}


int addWrite_RTU1_BAUDRATE(u_int32_t value)
{
return addWrite(ID_RTU1_BAUDRATE, &value);
}


int getStatus_RTU1_BAUDRATE()
{
return getStatus(ID_RTU1_BAUDRATE);
}


int doWrite_RTU1_STATUS(u_int32_t value)
{
return doWrite(ID_RTU1_STATUS,  &value);
}


int addWrite_RTU1_STATUS(u_int32_t value)
{
return addWrite(ID_RTU1_STATUS, &value);
}


int getStatus_RTU1_STATUS()
{
return getStatus(ID_RTU1_STATUS);
}


int doWrite_RTU1_READS(u_int32_t value)
{
return doWrite(ID_RTU1_READS,  &value);
}


int addWrite_RTU1_READS(u_int32_t value)
{
return addWrite(ID_RTU1_READS, &value);
}


int getStatus_RTU1_READS()
{
return getStatus(ID_RTU1_READS);
}


int doWrite_RTU1_WRITES(u_int32_t value)
{
return doWrite(ID_RTU1_WRITES,  &value);
}


int addWrite_RTU1_WRITES(u_int32_t value)
{
return addWrite(ID_RTU1_WRITES, &value);
}


int getStatus_RTU1_WRITES()
{
return getStatus(ID_RTU1_WRITES);
}


int doWrite_RTU1_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_RTU1_TIMEOUTS,  &value);
}


int addWrite_RTU1_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_RTU1_TIMEOUTS, &value);
}


int getStatus_RTU1_TIMEOUTS()
{
return getStatus(ID_RTU1_TIMEOUTS);
}


int doWrite_RTU1_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_RTU1_COMM_ERRORS,  &value);
}


int addWrite_RTU1_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_RTU1_COMM_ERRORS, &value);
}


int getStatus_RTU1_COMM_ERRORS()
{
return getStatus(ID_RTU1_COMM_ERRORS);
}


int doWrite_RTU1_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_RTU1_LAST_ERROR,  &value);
}


int addWrite_RTU1_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_RTU1_LAST_ERROR, &value);
}


int getStatus_RTU1_LAST_ERROR()
{
return getStatus(ID_RTU1_LAST_ERROR);
}


int doWrite_RTU1_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU1_WRITE_QUEUE,  &value);
}


int addWrite_RTU1_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU1_WRITE_QUEUE, &value);
}


int getStatus_RTU1_WRITE_QUEUE()
{
return getStatus(ID_RTU1_WRITE_QUEUE);
}


int doWrite_RTU1_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU1_READ_QUEUE,  &value);
}


int addWrite_RTU1_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU1_READ_QUEUE, &value);
}


int getStatus_RTU1_READ_QUEUE()
{
return getStatus(ID_RTU1_READ_QUEUE);
}


int doWrite_RTU3_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_RTU3_TYPE_PORT,  &value);
}


int addWrite_RTU3_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_RTU3_TYPE_PORT, &value);
}


int getStatus_RTU3_TYPE_PORT()
{
return getStatus(ID_RTU3_TYPE_PORT);
}


int doWrite_RTU3_BAUDRATE(u_int32_t value)
{
return doWrite(ID_RTU3_BAUDRATE,  &value);
}


int addWrite_RTU3_BAUDRATE(u_int32_t value)
{
return addWrite(ID_RTU3_BAUDRATE, &value);
}


int getStatus_RTU3_BAUDRATE()
{
return getStatus(ID_RTU3_BAUDRATE);
}


int doWrite_RTU3_STATUS(u_int32_t value)
{
return doWrite(ID_RTU3_STATUS,  &value);
}


int addWrite_RTU3_STATUS(u_int32_t value)
{
return addWrite(ID_RTU3_STATUS, &value);
}


int getStatus_RTU3_STATUS()
{
return getStatus(ID_RTU3_STATUS);
}


int doWrite_RTU3_READS(u_int32_t value)
{
return doWrite(ID_RTU3_READS,  &value);
}


int addWrite_RTU3_READS(u_int32_t value)
{
return addWrite(ID_RTU3_READS, &value);
}


int getStatus_RTU3_READS()
{
return getStatus(ID_RTU3_READS);
}


int doWrite_RTU3_WRITES(u_int32_t value)
{
return doWrite(ID_RTU3_WRITES,  &value);
}


int addWrite_RTU3_WRITES(u_int32_t value)
{
return addWrite(ID_RTU3_WRITES, &value);
}


int getStatus_RTU3_WRITES()
{
return getStatus(ID_RTU3_WRITES);
}


int doWrite_RTU3_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_RTU3_TIMEOUTS,  &value);
}


int addWrite_RTU3_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_RTU3_TIMEOUTS, &value);
}


int getStatus_RTU3_TIMEOUTS()
{
return getStatus(ID_RTU3_TIMEOUTS);
}


int doWrite_RTU3_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_RTU3_COMM_ERRORS,  &value);
}


int addWrite_RTU3_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_RTU3_COMM_ERRORS, &value);
}


int getStatus_RTU3_COMM_ERRORS()
{
return getStatus(ID_RTU3_COMM_ERRORS);
}


int doWrite_RTU3_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_RTU3_LAST_ERROR,  &value);
}


int addWrite_RTU3_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_RTU3_LAST_ERROR, &value);
}


int getStatus_RTU3_LAST_ERROR()
{
return getStatus(ID_RTU3_LAST_ERROR);
}


int doWrite_RTU3_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU3_WRITE_QUEUE,  &value);
}


int addWrite_RTU3_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU3_WRITE_QUEUE, &value);
}


int getStatus_RTU3_WRITE_QUEUE()
{
return getStatus(ID_RTU3_WRITE_QUEUE);
}


int doWrite_RTU3_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU3_READ_QUEUE,  &value);
}


int addWrite_RTU3_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU3_READ_QUEUE, &value);
}


int getStatus_RTU3_READ_QUEUE()
{
return getStatus(ID_RTU3_READ_QUEUE);
}


int doWrite_CAN0_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_CAN0_TYPE_PORT,  &value);
}


int addWrite_CAN0_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_CAN0_TYPE_PORT, &value);
}


int getStatus_CAN0_TYPE_PORT()
{
return getStatus(ID_CAN0_TYPE_PORT);
}


int doWrite_CAN0_BAUDRATE(u_int32_t value)
{
return doWrite(ID_CAN0_BAUDRATE,  &value);
}


int addWrite_CAN0_BAUDRATE(u_int32_t value)
{
return addWrite(ID_CAN0_BAUDRATE, &value);
}


int getStatus_CAN0_BAUDRATE()
{
return getStatus(ID_CAN0_BAUDRATE);
}


int doWrite_CAN0_STATUS(u_int32_t value)
{
return doWrite(ID_CAN0_STATUS,  &value);
}


int addWrite_CAN0_STATUS(u_int32_t value)
{
return addWrite(ID_CAN0_STATUS, &value);
}


int getStatus_CAN0_STATUS()
{
return getStatus(ID_CAN0_STATUS);
}


int doWrite_CAN0_READS(u_int32_t value)
{
return doWrite(ID_CAN0_READS,  &value);
}


int addWrite_CAN0_READS(u_int32_t value)
{
return addWrite(ID_CAN0_READS, &value);
}


int getStatus_CAN0_READS()
{
return getStatus(ID_CAN0_READS);
}


int doWrite_CAN0_WRITES(u_int32_t value)
{
return doWrite(ID_CAN0_WRITES,  &value);
}


int addWrite_CAN0_WRITES(u_int32_t value)
{
return addWrite(ID_CAN0_WRITES, &value);
}


int getStatus_CAN0_WRITES()
{
return getStatus(ID_CAN0_WRITES);
}


int doWrite_CAN0_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_CAN0_TIMEOUTS,  &value);
}


int addWrite_CAN0_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_CAN0_TIMEOUTS, &value);
}


int getStatus_CAN0_TIMEOUTS()
{
return getStatus(ID_CAN0_TIMEOUTS);
}


int doWrite_CAN0_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_CAN0_COMM_ERRORS,  &value);
}


int addWrite_CAN0_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_CAN0_COMM_ERRORS, &value);
}


int getStatus_CAN0_COMM_ERRORS()
{
return getStatus(ID_CAN0_COMM_ERRORS);
}


int doWrite_CAN0_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_CAN0_LAST_ERROR,  &value);
}


int addWrite_CAN0_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_CAN0_LAST_ERROR, &value);
}


int getStatus_CAN0_LAST_ERROR()
{
return getStatus(ID_CAN0_LAST_ERROR);
}


int doWrite_CAN0_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_CAN0_WRITE_QUEUE,  &value);
}


int addWrite_CAN0_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_CAN0_WRITE_QUEUE, &value);
}


int getStatus_CAN0_WRITE_QUEUE()
{
return getStatus(ID_CAN0_WRITE_QUEUE);
}


int doWrite_CAN0_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_CAN0_READ_QUEUE,  &value);
}


int addWrite_CAN0_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_CAN0_READ_QUEUE, &value);
}


int getStatus_CAN0_READ_QUEUE()
{
return getStatus(ID_CAN0_READ_QUEUE);
}


int doWrite_CAN1_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_CAN1_TYPE_PORT,  &value);
}


int addWrite_CAN1_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_CAN1_TYPE_PORT, &value);
}


int getStatus_CAN1_TYPE_PORT()
{
return getStatus(ID_CAN1_TYPE_PORT);
}


int doWrite_CAN1_BAUDRATE(u_int32_t value)
{
return doWrite(ID_CAN1_BAUDRATE,  &value);
}


int addWrite_CAN1_BAUDRATE(u_int32_t value)
{
return addWrite(ID_CAN1_BAUDRATE, &value);
}


int getStatus_CAN1_BAUDRATE()
{
return getStatus(ID_CAN1_BAUDRATE);
}


int doWrite_CAN1_STATUS(u_int32_t value)
{
return doWrite(ID_CAN1_STATUS,  &value);
}


int addWrite_CAN1_STATUS(u_int32_t value)
{
return addWrite(ID_CAN1_STATUS, &value);
}


int getStatus_CAN1_STATUS()
{
return getStatus(ID_CAN1_STATUS);
}


int doWrite_CAN1_READS(u_int32_t value)
{
return doWrite(ID_CAN1_READS,  &value);
}


int addWrite_CAN1_READS(u_int32_t value)
{
return addWrite(ID_CAN1_READS, &value);
}


int getStatus_CAN1_READS()
{
return getStatus(ID_CAN1_READS);
}


int doWrite_CAN1_WRITES(u_int32_t value)
{
return doWrite(ID_CAN1_WRITES,  &value);
}


int addWrite_CAN1_WRITES(u_int32_t value)
{
return addWrite(ID_CAN1_WRITES, &value);
}


int getStatus_CAN1_WRITES()
{
return getStatus(ID_CAN1_WRITES);
}


int doWrite_CAN1_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_CAN1_TIMEOUTS,  &value);
}


int addWrite_CAN1_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_CAN1_TIMEOUTS, &value);
}


int getStatus_CAN1_TIMEOUTS()
{
return getStatus(ID_CAN1_TIMEOUTS);
}


int doWrite_CAN1_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_CAN1_COMM_ERRORS,  &value);
}


int addWrite_CAN1_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_CAN1_COMM_ERRORS, &value);
}


int getStatus_CAN1_COMM_ERRORS()
{
return getStatus(ID_CAN1_COMM_ERRORS);
}


int doWrite_CAN1_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_CAN1_LAST_ERROR,  &value);
}


int addWrite_CAN1_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_CAN1_LAST_ERROR, &value);
}


int getStatus_CAN1_LAST_ERROR()
{
return getStatus(ID_CAN1_LAST_ERROR);
}


int doWrite_CAN1_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_CAN1_WRITE_QUEUE,  &value);
}


int addWrite_CAN1_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_CAN1_WRITE_QUEUE, &value);
}


int getStatus_CAN1_WRITE_QUEUE()
{
return getStatus(ID_CAN1_WRITE_QUEUE);
}


int doWrite_CAN1_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_CAN1_READ_QUEUE,  &value);
}


int addWrite_CAN1_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_CAN1_READ_QUEUE, &value);
}


int getStatus_CAN1_READ_QUEUE()
{
return getStatus(ID_CAN1_READ_QUEUE);
}


int doWrite_TCPS_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCPS_TYPE_PORT,  &value);
}


int addWrite_TCPS_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCPS_TYPE_PORT, &value);
}


int getStatus_TCPS_TYPE_PORT()
{
return getStatus(ID_TCPS_TYPE_PORT);
}


int doWrite_TCPS_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCPS_IP_ADDRESS,  &value);
}


int addWrite_TCPS_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCPS_IP_ADDRESS, &value);
}


int getStatus_TCPS_IP_ADDRESS()
{
return getStatus(ID_TCPS_IP_ADDRESS);
}


int doWrite_TCPS_STATUS(u_int32_t value)
{
return doWrite(ID_TCPS_STATUS,  &value);
}


int addWrite_TCPS_STATUS(u_int32_t value)
{
return addWrite(ID_TCPS_STATUS, &value);
}


int getStatus_TCPS_STATUS()
{
return getStatus(ID_TCPS_STATUS);
}


int doWrite_TCPS_READS(u_int32_t value)
{
return doWrite(ID_TCPS_READS,  &value);
}


int addWrite_TCPS_READS(u_int32_t value)
{
return addWrite(ID_TCPS_READS, &value);
}


int getStatus_TCPS_READS()
{
return getStatus(ID_TCPS_READS);
}


int doWrite_TCPS_WRITES(u_int32_t value)
{
return doWrite(ID_TCPS_WRITES,  &value);
}


int addWrite_TCPS_WRITES(u_int32_t value)
{
return addWrite(ID_TCPS_WRITES, &value);
}


int getStatus_TCPS_WRITES()
{
return getStatus(ID_TCPS_WRITES);
}


int doWrite_TCPS_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCPS_TIMEOUTS,  &value);
}


int addWrite_TCPS_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCPS_TIMEOUTS, &value);
}


int getStatus_TCPS_TIMEOUTS()
{
return getStatus(ID_TCPS_TIMEOUTS);
}


int doWrite_TCPS_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCPS_COMM_ERRORS,  &value);
}


int addWrite_TCPS_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCPS_COMM_ERRORS, &value);
}


int getStatus_TCPS_COMM_ERRORS()
{
return getStatus(ID_TCPS_COMM_ERRORS);
}


int doWrite_TCPS_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCPS_LAST_ERROR,  &value);
}


int addWrite_TCPS_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCPS_LAST_ERROR, &value);
}


int getStatus_TCPS_LAST_ERROR()
{
return getStatus(ID_TCPS_LAST_ERROR);
}


int doWrite_TCPS_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCPS_WRITE_QUEUE,  &value);
}


int addWrite_TCPS_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCPS_WRITE_QUEUE, &value);
}


int getStatus_TCPS_WRITE_QUEUE()
{
return getStatus(ID_TCPS_WRITE_QUEUE);
}


int doWrite_TCPS_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCPS_READ_QUEUE,  &value);
}


int addWrite_TCPS_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCPS_READ_QUEUE, &value);
}


int getStatus_TCPS_READ_QUEUE()
{
return getStatus(ID_TCPS_READ_QUEUE);
}


int doWrite_TCP0_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP0_TYPE_PORT,  &value);
}


int addWrite_TCP0_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP0_TYPE_PORT, &value);
}


int getStatus_TCP0_TYPE_PORT()
{
return getStatus(ID_TCP0_TYPE_PORT);
}


int doWrite_TCP0_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP0_IP_ADDRESS,  &value);
}


int addWrite_TCP0_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP0_IP_ADDRESS, &value);
}


int getStatus_TCP0_IP_ADDRESS()
{
return getStatus(ID_TCP0_IP_ADDRESS);
}


int doWrite_TCP0_STATUS(u_int32_t value)
{
return doWrite(ID_TCP0_STATUS,  &value);
}


int addWrite_TCP0_STATUS(u_int32_t value)
{
return addWrite(ID_TCP0_STATUS, &value);
}


int getStatus_TCP0_STATUS()
{
return getStatus(ID_TCP0_STATUS);
}


int doWrite_TCP0_READS(u_int32_t value)
{
return doWrite(ID_TCP0_READS,  &value);
}


int addWrite_TCP0_READS(u_int32_t value)
{
return addWrite(ID_TCP0_READS, &value);
}


int getStatus_TCP0_READS()
{
return getStatus(ID_TCP0_READS);
}


int doWrite_TCP0_WRITES(u_int32_t value)
{
return doWrite(ID_TCP0_WRITES,  &value);
}


int addWrite_TCP0_WRITES(u_int32_t value)
{
return addWrite(ID_TCP0_WRITES, &value);
}


int getStatus_TCP0_WRITES()
{
return getStatus(ID_TCP0_WRITES);
}


int doWrite_TCP0_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP0_TIMEOUTS,  &value);
}


int addWrite_TCP0_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP0_TIMEOUTS, &value);
}


int getStatus_TCP0_TIMEOUTS()
{
return getStatus(ID_TCP0_TIMEOUTS);
}


int doWrite_TCP0_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP0_COMM_ERRORS,  &value);
}


int addWrite_TCP0_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP0_COMM_ERRORS, &value);
}


int getStatus_TCP0_COMM_ERRORS()
{
return getStatus(ID_TCP0_COMM_ERRORS);
}


int doWrite_TCP0_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP0_LAST_ERROR,  &value);
}


int addWrite_TCP0_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP0_LAST_ERROR, &value);
}


int getStatus_TCP0_LAST_ERROR()
{
return getStatus(ID_TCP0_LAST_ERROR);
}


int doWrite_TCP0_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP0_WRITE_QUEUE,  &value);
}


int addWrite_TCP0_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP0_WRITE_QUEUE, &value);
}


int getStatus_TCP0_WRITE_QUEUE()
{
return getStatus(ID_TCP0_WRITE_QUEUE);
}


int doWrite_TCP0_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP0_READ_QUEUE,  &value);
}


int addWrite_TCP0_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP0_READ_QUEUE, &value);
}


int getStatus_TCP0_READ_QUEUE()
{
return getStatus(ID_TCP0_READ_QUEUE);
}


int doWrite_TCP1_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP1_TYPE_PORT,  &value);
}


int addWrite_TCP1_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP1_TYPE_PORT, &value);
}


int getStatus_TCP1_TYPE_PORT()
{
return getStatus(ID_TCP1_TYPE_PORT);
}


int doWrite_TCP1_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP1_IP_ADDRESS,  &value);
}


int addWrite_TCP1_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP1_IP_ADDRESS, &value);
}


int getStatus_TCP1_IP_ADDRESS()
{
return getStatus(ID_TCP1_IP_ADDRESS);
}


int doWrite_TCP1_STATUS(u_int32_t value)
{
return doWrite(ID_TCP1_STATUS,  &value);
}


int addWrite_TCP1_STATUS(u_int32_t value)
{
return addWrite(ID_TCP1_STATUS, &value);
}


int getStatus_TCP1_STATUS()
{
return getStatus(ID_TCP1_STATUS);
}


int doWrite_TCP1_READS(u_int32_t value)
{
return doWrite(ID_TCP1_READS,  &value);
}


int addWrite_TCP1_READS(u_int32_t value)
{
return addWrite(ID_TCP1_READS, &value);
}


int getStatus_TCP1_READS()
{
return getStatus(ID_TCP1_READS);
}


int doWrite_TCP1_WRITES(u_int32_t value)
{
return doWrite(ID_TCP1_WRITES,  &value);
}


int addWrite_TCP1_WRITES(u_int32_t value)
{
return addWrite(ID_TCP1_WRITES, &value);
}


int getStatus_TCP1_WRITES()
{
return getStatus(ID_TCP1_WRITES);
}


int doWrite_TCP1_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP1_TIMEOUTS,  &value);
}


int addWrite_TCP1_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP1_TIMEOUTS, &value);
}


int getStatus_TCP1_TIMEOUTS()
{
return getStatus(ID_TCP1_TIMEOUTS);
}


int doWrite_TCP1_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP1_COMM_ERRORS,  &value);
}


int addWrite_TCP1_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP1_COMM_ERRORS, &value);
}


int getStatus_TCP1_COMM_ERRORS()
{
return getStatus(ID_TCP1_COMM_ERRORS);
}


int doWrite_TCP1_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP1_LAST_ERROR,  &value);
}


int addWrite_TCP1_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP1_LAST_ERROR, &value);
}


int getStatus_TCP1_LAST_ERROR()
{
return getStatus(ID_TCP1_LAST_ERROR);
}


int doWrite_TCP1_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP1_WRITE_QUEUE,  &value);
}


int addWrite_TCP1_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP1_WRITE_QUEUE, &value);
}


int getStatus_TCP1_WRITE_QUEUE()
{
return getStatus(ID_TCP1_WRITE_QUEUE);
}


int doWrite_TCP1_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP1_READ_QUEUE,  &value);
}


int addWrite_TCP1_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP1_READ_QUEUE, &value);
}


int getStatus_TCP1_READ_QUEUE()
{
return getStatus(ID_TCP1_READ_QUEUE);
}


int doWrite_TCP2_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP2_TYPE_PORT,  &value);
}


int addWrite_TCP2_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP2_TYPE_PORT, &value);
}


int getStatus_TCP2_TYPE_PORT()
{
return getStatus(ID_TCP2_TYPE_PORT);
}


int doWrite_TCP2_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP2_IP_ADDRESS,  &value);
}


int addWrite_TCP2_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP2_IP_ADDRESS, &value);
}


int getStatus_TCP2_IP_ADDRESS()
{
return getStatus(ID_TCP2_IP_ADDRESS);
}


int doWrite_TCP2_STATUS(u_int32_t value)
{
return doWrite(ID_TCP2_STATUS,  &value);
}


int addWrite_TCP2_STATUS(u_int32_t value)
{
return addWrite(ID_TCP2_STATUS, &value);
}


int getStatus_TCP2_STATUS()
{
return getStatus(ID_TCP2_STATUS);
}


int doWrite_TCP2_READS(u_int32_t value)
{
return doWrite(ID_TCP2_READS,  &value);
}


int addWrite_TCP2_READS(u_int32_t value)
{
return addWrite(ID_TCP2_READS, &value);
}


int getStatus_TCP2_READS()
{
return getStatus(ID_TCP2_READS);
}


int doWrite_TCP2_WRITES(u_int32_t value)
{
return doWrite(ID_TCP2_WRITES,  &value);
}


int addWrite_TCP2_WRITES(u_int32_t value)
{
return addWrite(ID_TCP2_WRITES, &value);
}


int getStatus_TCP2_WRITES()
{
return getStatus(ID_TCP2_WRITES);
}


int doWrite_TCP2_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP2_TIMEOUTS,  &value);
}


int addWrite_TCP2_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP2_TIMEOUTS, &value);
}


int getStatus_TCP2_TIMEOUTS()
{
return getStatus(ID_TCP2_TIMEOUTS);
}


int doWrite_TCP2_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP2_COMM_ERRORS,  &value);
}


int addWrite_TCP2_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP2_COMM_ERRORS, &value);
}


int getStatus_TCP2_COMM_ERRORS()
{
return getStatus(ID_TCP2_COMM_ERRORS);
}


int doWrite_TCP2_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP2_LAST_ERROR,  &value);
}


int addWrite_TCP2_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP2_LAST_ERROR, &value);
}


int getStatus_TCP2_LAST_ERROR()
{
return getStatus(ID_TCP2_LAST_ERROR);
}


int doWrite_TCP2_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP2_WRITE_QUEUE,  &value);
}


int addWrite_TCP2_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP2_WRITE_QUEUE, &value);
}


int getStatus_TCP2_WRITE_QUEUE()
{
return getStatus(ID_TCP2_WRITE_QUEUE);
}


int doWrite_TCP2_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP2_READ_QUEUE,  &value);
}


int addWrite_TCP2_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP2_READ_QUEUE, &value);
}


int getStatus_TCP2_READ_QUEUE()
{
return getStatus(ID_TCP2_READ_QUEUE);
}


int doWrite_TCP3_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP3_TYPE_PORT,  &value);
}


int addWrite_TCP3_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP3_TYPE_PORT, &value);
}


int getStatus_TCP3_TYPE_PORT()
{
return getStatus(ID_TCP3_TYPE_PORT);
}


int doWrite_TCP3_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP3_IP_ADDRESS,  &value);
}


int addWrite_TCP3_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP3_IP_ADDRESS, &value);
}


int getStatus_TCP3_IP_ADDRESS()
{
return getStatus(ID_TCP3_IP_ADDRESS);
}


int doWrite_TCP3_STATUS(u_int32_t value)
{
return doWrite(ID_TCP3_STATUS,  &value);
}


int addWrite_TCP3_STATUS(u_int32_t value)
{
return addWrite(ID_TCP3_STATUS, &value);
}


int getStatus_TCP3_STATUS()
{
return getStatus(ID_TCP3_STATUS);
}


int doWrite_TCP3_READS(u_int32_t value)
{
return doWrite(ID_TCP3_READS,  &value);
}


int addWrite_TCP3_READS(u_int32_t value)
{
return addWrite(ID_TCP3_READS, &value);
}


int getStatus_TCP3_READS()
{
return getStatus(ID_TCP3_READS);
}


int doWrite_TCP3_WRITES(u_int32_t value)
{
return doWrite(ID_TCP3_WRITES,  &value);
}


int addWrite_TCP3_WRITES(u_int32_t value)
{
return addWrite(ID_TCP3_WRITES, &value);
}


int getStatus_TCP3_WRITES()
{
return getStatus(ID_TCP3_WRITES);
}


int doWrite_TCP3_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP3_TIMEOUTS,  &value);
}


int addWrite_TCP3_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP3_TIMEOUTS, &value);
}


int getStatus_TCP3_TIMEOUTS()
{
return getStatus(ID_TCP3_TIMEOUTS);
}


int doWrite_TCP3_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP3_COMM_ERRORS,  &value);
}


int addWrite_TCP3_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP3_COMM_ERRORS, &value);
}


int getStatus_TCP3_COMM_ERRORS()
{
return getStatus(ID_TCP3_COMM_ERRORS);
}


int doWrite_TCP3_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP3_LAST_ERROR,  &value);
}


int addWrite_TCP3_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP3_LAST_ERROR, &value);
}


int getStatus_TCP3_LAST_ERROR()
{
return getStatus(ID_TCP3_LAST_ERROR);
}


int doWrite_TCP3_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP3_WRITE_QUEUE,  &value);
}


int addWrite_TCP3_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP3_WRITE_QUEUE, &value);
}


int getStatus_TCP3_WRITE_QUEUE()
{
return getStatus(ID_TCP3_WRITE_QUEUE);
}


int doWrite_TCP3_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP3_READ_QUEUE,  &value);
}


int addWrite_TCP3_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP3_READ_QUEUE, &value);
}


int getStatus_TCP3_READ_QUEUE()
{
return getStatus(ID_TCP3_READ_QUEUE);
}


int doWrite_TCP4_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP4_TYPE_PORT,  &value);
}


int addWrite_TCP4_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP4_TYPE_PORT, &value);
}


int getStatus_TCP4_TYPE_PORT()
{
return getStatus(ID_TCP4_TYPE_PORT);
}


int doWrite_TCP4_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP4_IP_ADDRESS,  &value);
}


int addWrite_TCP4_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP4_IP_ADDRESS, &value);
}


int getStatus_TCP4_IP_ADDRESS()
{
return getStatus(ID_TCP4_IP_ADDRESS);
}


int doWrite_TCP4_STATUS(u_int32_t value)
{
return doWrite(ID_TCP4_STATUS,  &value);
}


int addWrite_TCP4_STATUS(u_int32_t value)
{
return addWrite(ID_TCP4_STATUS, &value);
}


int getStatus_TCP4_STATUS()
{
return getStatus(ID_TCP4_STATUS);
}


int doWrite_TCP4_READS(u_int32_t value)
{
return doWrite(ID_TCP4_READS,  &value);
}


int addWrite_TCP4_READS(u_int32_t value)
{
return addWrite(ID_TCP4_READS, &value);
}


int getStatus_TCP4_READS()
{
return getStatus(ID_TCP4_READS);
}


int doWrite_TCP4_WRITES(u_int32_t value)
{
return doWrite(ID_TCP4_WRITES,  &value);
}


int addWrite_TCP4_WRITES(u_int32_t value)
{
return addWrite(ID_TCP4_WRITES, &value);
}


int getStatus_TCP4_WRITES()
{
return getStatus(ID_TCP4_WRITES);
}


int doWrite_TCP4_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP4_TIMEOUTS,  &value);
}


int addWrite_TCP4_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP4_TIMEOUTS, &value);
}


int getStatus_TCP4_TIMEOUTS()
{
return getStatus(ID_TCP4_TIMEOUTS);
}


int doWrite_TCP4_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP4_COMM_ERRORS,  &value);
}


int addWrite_TCP4_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP4_COMM_ERRORS, &value);
}


int getStatus_TCP4_COMM_ERRORS()
{
return getStatus(ID_TCP4_COMM_ERRORS);
}


int doWrite_TCP4_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP4_LAST_ERROR,  &value);
}


int addWrite_TCP4_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP4_LAST_ERROR, &value);
}


int getStatus_TCP4_LAST_ERROR()
{
return getStatus(ID_TCP4_LAST_ERROR);
}


int doWrite_TCP4_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP4_WRITE_QUEUE,  &value);
}


int addWrite_TCP4_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP4_WRITE_QUEUE, &value);
}


int getStatus_TCP4_WRITE_QUEUE()
{
return getStatus(ID_TCP4_WRITE_QUEUE);
}


int doWrite_TCP4_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP4_READ_QUEUE,  &value);
}


int addWrite_TCP4_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP4_READ_QUEUE, &value);
}


int getStatus_TCP4_READ_QUEUE()
{
return getStatus(ID_TCP4_READ_QUEUE);
}


int doWrite_TCP5_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP5_TYPE_PORT,  &value);
}


int addWrite_TCP5_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP5_TYPE_PORT, &value);
}


int getStatus_TCP5_TYPE_PORT()
{
return getStatus(ID_TCP5_TYPE_PORT);
}


int doWrite_TCP5_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP5_IP_ADDRESS,  &value);
}


int addWrite_TCP5_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP5_IP_ADDRESS, &value);
}


int getStatus_TCP5_IP_ADDRESS()
{
return getStatus(ID_TCP5_IP_ADDRESS);
}


int doWrite_TCP5_STATUS(u_int32_t value)
{
return doWrite(ID_TCP5_STATUS,  &value);
}


int addWrite_TCP5_STATUS(u_int32_t value)
{
return addWrite(ID_TCP5_STATUS, &value);
}


int getStatus_TCP5_STATUS()
{
return getStatus(ID_TCP5_STATUS);
}


int doWrite_TCP5_READS(u_int32_t value)
{
return doWrite(ID_TCP5_READS,  &value);
}


int addWrite_TCP5_READS(u_int32_t value)
{
return addWrite(ID_TCP5_READS, &value);
}


int getStatus_TCP5_READS()
{
return getStatus(ID_TCP5_READS);
}


int doWrite_TCP5_WRITES(u_int32_t value)
{
return doWrite(ID_TCP5_WRITES,  &value);
}


int addWrite_TCP5_WRITES(u_int32_t value)
{
return addWrite(ID_TCP5_WRITES, &value);
}


int getStatus_TCP5_WRITES()
{
return getStatus(ID_TCP5_WRITES);
}


int doWrite_TCP5_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP5_TIMEOUTS,  &value);
}


int addWrite_TCP5_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP5_TIMEOUTS, &value);
}


int getStatus_TCP5_TIMEOUTS()
{
return getStatus(ID_TCP5_TIMEOUTS);
}


int doWrite_TCP5_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP5_COMM_ERRORS,  &value);
}


int addWrite_TCP5_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP5_COMM_ERRORS, &value);
}


int getStatus_TCP5_COMM_ERRORS()
{
return getStatus(ID_TCP5_COMM_ERRORS);
}


int doWrite_TCP5_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP5_LAST_ERROR,  &value);
}


int addWrite_TCP5_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP5_LAST_ERROR, &value);
}


int getStatus_TCP5_LAST_ERROR()
{
return getStatus(ID_TCP5_LAST_ERROR);
}


int doWrite_TCP5_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP5_WRITE_QUEUE,  &value);
}


int addWrite_TCP5_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP5_WRITE_QUEUE, &value);
}


int getStatus_TCP5_WRITE_QUEUE()
{
return getStatus(ID_TCP5_WRITE_QUEUE);
}


int doWrite_TCP5_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP5_READ_QUEUE,  &value);
}


int addWrite_TCP5_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP5_READ_QUEUE, &value);
}


int getStatus_TCP5_READ_QUEUE()
{
return getStatus(ID_TCP5_READ_QUEUE);
}


int doWrite_TCP6_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP6_TYPE_PORT,  &value);
}


int addWrite_TCP6_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP6_TYPE_PORT, &value);
}


int getStatus_TCP6_TYPE_PORT()
{
return getStatus(ID_TCP6_TYPE_PORT);
}


int doWrite_TCP6_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP6_IP_ADDRESS,  &value);
}


int addWrite_TCP6_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP6_IP_ADDRESS, &value);
}


int getStatus_TCP6_IP_ADDRESS()
{
return getStatus(ID_TCP6_IP_ADDRESS);
}


int doWrite_TCP6_STATUS(u_int32_t value)
{
return doWrite(ID_TCP6_STATUS,  &value);
}


int addWrite_TCP6_STATUS(u_int32_t value)
{
return addWrite(ID_TCP6_STATUS, &value);
}


int getStatus_TCP6_STATUS()
{
return getStatus(ID_TCP6_STATUS);
}


int doWrite_TCP6_READS(u_int32_t value)
{
return doWrite(ID_TCP6_READS,  &value);
}


int addWrite_TCP6_READS(u_int32_t value)
{
return addWrite(ID_TCP6_READS, &value);
}


int getStatus_TCP6_READS()
{
return getStatus(ID_TCP6_READS);
}


int doWrite_TCP6_WRITES(u_int32_t value)
{
return doWrite(ID_TCP6_WRITES,  &value);
}


int addWrite_TCP6_WRITES(u_int32_t value)
{
return addWrite(ID_TCP6_WRITES, &value);
}


int getStatus_TCP6_WRITES()
{
return getStatus(ID_TCP6_WRITES);
}


int doWrite_TCP6_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP6_TIMEOUTS,  &value);
}


int addWrite_TCP6_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP6_TIMEOUTS, &value);
}


int getStatus_TCP6_TIMEOUTS()
{
return getStatus(ID_TCP6_TIMEOUTS);
}


int doWrite_TCP6_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP6_COMM_ERRORS,  &value);
}


int addWrite_TCP6_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP6_COMM_ERRORS, &value);
}


int getStatus_TCP6_COMM_ERRORS()
{
return getStatus(ID_TCP6_COMM_ERRORS);
}


int doWrite_TCP6_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP6_LAST_ERROR,  &value);
}


int addWrite_TCP6_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP6_LAST_ERROR, &value);
}


int getStatus_TCP6_LAST_ERROR()
{
return getStatus(ID_TCP6_LAST_ERROR);
}


int doWrite_TCP6_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP6_WRITE_QUEUE,  &value);
}


int addWrite_TCP6_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP6_WRITE_QUEUE, &value);
}


int getStatus_TCP6_WRITE_QUEUE()
{
return getStatus(ID_TCP6_WRITE_QUEUE);
}


int doWrite_TCP6_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP6_READ_QUEUE,  &value);
}


int addWrite_TCP6_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP6_READ_QUEUE, &value);
}


int getStatus_TCP6_READ_QUEUE()
{
return getStatus(ID_TCP6_READ_QUEUE);
}


int doWrite_TCP7_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP7_TYPE_PORT,  &value);
}


int addWrite_TCP7_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP7_TYPE_PORT, &value);
}


int getStatus_TCP7_TYPE_PORT()
{
return getStatus(ID_TCP7_TYPE_PORT);
}


int doWrite_TCP7_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP7_IP_ADDRESS,  &value);
}


int addWrite_TCP7_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP7_IP_ADDRESS, &value);
}


int getStatus_TCP7_IP_ADDRESS()
{
return getStatus(ID_TCP7_IP_ADDRESS);
}


int doWrite_TCP7_STATUS(u_int32_t value)
{
return doWrite(ID_TCP7_STATUS,  &value);
}


int addWrite_TCP7_STATUS(u_int32_t value)
{
return addWrite(ID_TCP7_STATUS, &value);
}


int getStatus_TCP7_STATUS()
{
return getStatus(ID_TCP7_STATUS);
}


int doWrite_TCP7_READS(u_int32_t value)
{
return doWrite(ID_TCP7_READS,  &value);
}


int addWrite_TCP7_READS(u_int32_t value)
{
return addWrite(ID_TCP7_READS, &value);
}


int getStatus_TCP7_READS()
{
return getStatus(ID_TCP7_READS);
}


int doWrite_TCP7_WRITES(u_int32_t value)
{
return doWrite(ID_TCP7_WRITES,  &value);
}


int addWrite_TCP7_WRITES(u_int32_t value)
{
return addWrite(ID_TCP7_WRITES, &value);
}


int getStatus_TCP7_WRITES()
{
return getStatus(ID_TCP7_WRITES);
}


int doWrite_TCP7_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP7_TIMEOUTS,  &value);
}


int addWrite_TCP7_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP7_TIMEOUTS, &value);
}


int getStatus_TCP7_TIMEOUTS()
{
return getStatus(ID_TCP7_TIMEOUTS);
}


int doWrite_TCP7_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP7_COMM_ERRORS,  &value);
}


int addWrite_TCP7_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP7_COMM_ERRORS, &value);
}


int getStatus_TCP7_COMM_ERRORS()
{
return getStatus(ID_TCP7_COMM_ERRORS);
}


int doWrite_TCP7_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP7_LAST_ERROR,  &value);
}


int addWrite_TCP7_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP7_LAST_ERROR, &value);
}


int getStatus_TCP7_LAST_ERROR()
{
return getStatus(ID_TCP7_LAST_ERROR);
}


int doWrite_TCP7_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP7_WRITE_QUEUE,  &value);
}


int addWrite_TCP7_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP7_WRITE_QUEUE, &value);
}


int getStatus_TCP7_WRITE_QUEUE()
{
return getStatus(ID_TCP7_WRITE_QUEUE);
}


int doWrite_TCP7_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP7_READ_QUEUE,  &value);
}


int addWrite_TCP7_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP7_READ_QUEUE, &value);
}


int getStatus_TCP7_READ_QUEUE()
{
return getStatus(ID_TCP7_READ_QUEUE);
}


int doWrite_TCP8_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP8_TYPE_PORT,  &value);
}


int addWrite_TCP8_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP8_TYPE_PORT, &value);
}


int getStatus_TCP8_TYPE_PORT()
{
return getStatus(ID_TCP8_TYPE_PORT);
}


int doWrite_TCP8_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP8_IP_ADDRESS,  &value);
}


int addWrite_TCP8_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP8_IP_ADDRESS, &value);
}


int getStatus_TCP8_IP_ADDRESS()
{
return getStatus(ID_TCP8_IP_ADDRESS);
}


int doWrite_TCP8_STATUS(u_int32_t value)
{
return doWrite(ID_TCP8_STATUS,  &value);
}


int addWrite_TCP8_STATUS(u_int32_t value)
{
return addWrite(ID_TCP8_STATUS, &value);
}


int getStatus_TCP8_STATUS()
{
return getStatus(ID_TCP8_STATUS);
}


int doWrite_TCP8_READS(u_int32_t value)
{
return doWrite(ID_TCP8_READS,  &value);
}


int addWrite_TCP8_READS(u_int32_t value)
{
return addWrite(ID_TCP8_READS, &value);
}


int getStatus_TCP8_READS()
{
return getStatus(ID_TCP8_READS);
}


int doWrite_TCP8_WRITES(u_int32_t value)
{
return doWrite(ID_TCP8_WRITES,  &value);
}


int addWrite_TCP8_WRITES(u_int32_t value)
{
return addWrite(ID_TCP8_WRITES, &value);
}


int getStatus_TCP8_WRITES()
{
return getStatus(ID_TCP8_WRITES);
}


int doWrite_TCP8_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP8_TIMEOUTS,  &value);
}


int addWrite_TCP8_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP8_TIMEOUTS, &value);
}


int getStatus_TCP8_TIMEOUTS()
{
return getStatus(ID_TCP8_TIMEOUTS);
}


int doWrite_TCP8_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP8_COMM_ERRORS,  &value);
}


int addWrite_TCP8_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP8_COMM_ERRORS, &value);
}


int getStatus_TCP8_COMM_ERRORS()
{
return getStatus(ID_TCP8_COMM_ERRORS);
}


int doWrite_TCP8_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP8_LAST_ERROR,  &value);
}


int addWrite_TCP8_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP8_LAST_ERROR, &value);
}


int getStatus_TCP8_LAST_ERROR()
{
return getStatus(ID_TCP8_LAST_ERROR);
}


int doWrite_TCP8_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP8_WRITE_QUEUE,  &value);
}


int addWrite_TCP8_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP8_WRITE_QUEUE, &value);
}


int getStatus_TCP8_WRITE_QUEUE()
{
return getStatus(ID_TCP8_WRITE_QUEUE);
}


int doWrite_TCP8_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP8_READ_QUEUE,  &value);
}


int addWrite_TCP8_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP8_READ_QUEUE, &value);
}


int getStatus_TCP8_READ_QUEUE()
{
return getStatus(ID_TCP8_READ_QUEUE);
}


int doWrite_TCP9_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCP9_TYPE_PORT,  &value);
}


int addWrite_TCP9_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCP9_TYPE_PORT, &value);
}


int getStatus_TCP9_TYPE_PORT()
{
return getStatus(ID_TCP9_TYPE_PORT);
}


int doWrite_TCP9_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCP9_IP_ADDRESS,  &value);
}


int addWrite_TCP9_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCP9_IP_ADDRESS, &value);
}


int getStatus_TCP9_IP_ADDRESS()
{
return getStatus(ID_TCP9_IP_ADDRESS);
}


int doWrite_TCP9_STATUS(u_int32_t value)
{
return doWrite(ID_TCP9_STATUS,  &value);
}


int addWrite_TCP9_STATUS(u_int32_t value)
{
return addWrite(ID_TCP9_STATUS, &value);
}


int getStatus_TCP9_STATUS()
{
return getStatus(ID_TCP9_STATUS);
}


int doWrite_TCP9_READS(u_int32_t value)
{
return doWrite(ID_TCP9_READS,  &value);
}


int addWrite_TCP9_READS(u_int32_t value)
{
return addWrite(ID_TCP9_READS, &value);
}


int getStatus_TCP9_READS()
{
return getStatus(ID_TCP9_READS);
}


int doWrite_TCP9_WRITES(u_int32_t value)
{
return doWrite(ID_TCP9_WRITES,  &value);
}


int addWrite_TCP9_WRITES(u_int32_t value)
{
return addWrite(ID_TCP9_WRITES, &value);
}


int getStatus_TCP9_WRITES()
{
return getStatus(ID_TCP9_WRITES);
}


int doWrite_TCP9_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCP9_TIMEOUTS,  &value);
}


int addWrite_TCP9_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCP9_TIMEOUTS, &value);
}


int getStatus_TCP9_TIMEOUTS()
{
return getStatus(ID_TCP9_TIMEOUTS);
}


int doWrite_TCP9_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCP9_COMM_ERRORS,  &value);
}


int addWrite_TCP9_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCP9_COMM_ERRORS, &value);
}


int getStatus_TCP9_COMM_ERRORS()
{
return getStatus(ID_TCP9_COMM_ERRORS);
}


int doWrite_TCP9_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCP9_LAST_ERROR,  &value);
}


int addWrite_TCP9_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCP9_LAST_ERROR, &value);
}


int getStatus_TCP9_LAST_ERROR()
{
return getStatus(ID_TCP9_LAST_ERROR);
}


int doWrite_TCP9_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP9_WRITE_QUEUE,  &value);
}


int addWrite_TCP9_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP9_WRITE_QUEUE, &value);
}


int getStatus_TCP9_WRITE_QUEUE()
{
return getStatus(ID_TCP9_WRITE_QUEUE);
}


int doWrite_TCP9_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCP9_READ_QUEUE,  &value);
}


int addWrite_TCP9_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCP9_READ_QUEUE, &value);
}


int getStatus_TCP9_READ_QUEUE()
{
return getStatus(ID_TCP9_READ_QUEUE);
}


int doWrite_NODE_01_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_01_DEV_NODE,  &value);
}


int addWrite_NODE_01_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_01_DEV_NODE, &value);
}


int getStatus_NODE_01_DEV_NODE()
{
return getStatus(ID_NODE_01_DEV_NODE);
}


int doWrite_NODE_01_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_01_STATUS,  &value);
}


int addWrite_NODE_01_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_01_STATUS, &value);
}


int getStatus_NODE_01_STATUS()
{
return getStatus(ID_NODE_01_STATUS);
}


int doWrite_NODE_02_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_02_DEV_NODE,  &value);
}


int addWrite_NODE_02_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_02_DEV_NODE, &value);
}


int getStatus_NODE_02_DEV_NODE()
{
return getStatus(ID_NODE_02_DEV_NODE);
}


int doWrite_NODE_02_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_02_STATUS,  &value);
}


int addWrite_NODE_02_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_02_STATUS, &value);
}


int getStatus_NODE_02_STATUS()
{
return getStatus(ID_NODE_02_STATUS);
}


int doWrite_NODE_03_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_03_DEV_NODE,  &value);
}


int addWrite_NODE_03_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_03_DEV_NODE, &value);
}


int getStatus_NODE_03_DEV_NODE()
{
return getStatus(ID_NODE_03_DEV_NODE);
}


int doWrite_NODE_03_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_03_STATUS,  &value);
}


int addWrite_NODE_03_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_03_STATUS, &value);
}


int getStatus_NODE_03_STATUS()
{
return getStatus(ID_NODE_03_STATUS);
}


int doWrite_NODE_04_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_04_DEV_NODE,  &value);
}


int addWrite_NODE_04_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_04_DEV_NODE, &value);
}


int getStatus_NODE_04_DEV_NODE()
{
return getStatus(ID_NODE_04_DEV_NODE);
}


int doWrite_NODE_04_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_04_STATUS,  &value);
}


int addWrite_NODE_04_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_04_STATUS, &value);
}


int getStatus_NODE_04_STATUS()
{
return getStatus(ID_NODE_04_STATUS);
}


int doWrite_NODE_05_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_05_DEV_NODE,  &value);
}


int addWrite_NODE_05_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_05_DEV_NODE, &value);
}


int getStatus_NODE_05_DEV_NODE()
{
return getStatus(ID_NODE_05_DEV_NODE);
}


int doWrite_NODE_05_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_05_STATUS,  &value);
}


int addWrite_NODE_05_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_05_STATUS, &value);
}


int getStatus_NODE_05_STATUS()
{
return getStatus(ID_NODE_05_STATUS);
}


int doWrite_NODE_06_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_06_DEV_NODE,  &value);
}


int addWrite_NODE_06_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_06_DEV_NODE, &value);
}


int getStatus_NODE_06_DEV_NODE()
{
return getStatus(ID_NODE_06_DEV_NODE);
}


int doWrite_NODE_06_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_06_STATUS,  &value);
}


int addWrite_NODE_06_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_06_STATUS, &value);
}


int getStatus_NODE_06_STATUS()
{
return getStatus(ID_NODE_06_STATUS);
}


int doWrite_NODE_07_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_07_DEV_NODE,  &value);
}


int addWrite_NODE_07_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_07_DEV_NODE, &value);
}


int getStatus_NODE_07_DEV_NODE()
{
return getStatus(ID_NODE_07_DEV_NODE);
}


int doWrite_NODE_07_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_07_STATUS,  &value);
}


int addWrite_NODE_07_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_07_STATUS, &value);
}


int getStatus_NODE_07_STATUS()
{
return getStatus(ID_NODE_07_STATUS);
}


int doWrite_NODE_08_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_08_DEV_NODE,  &value);
}


int addWrite_NODE_08_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_08_DEV_NODE, &value);
}


int getStatus_NODE_08_DEV_NODE()
{
return getStatus(ID_NODE_08_DEV_NODE);
}


int doWrite_NODE_08_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_08_STATUS,  &value);
}


int addWrite_NODE_08_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_08_STATUS, &value);
}


int getStatus_NODE_08_STATUS()
{
return getStatus(ID_NODE_08_STATUS);
}


int doWrite_NODE_09_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_09_DEV_NODE,  &value);
}


int addWrite_NODE_09_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_09_DEV_NODE, &value);
}


int getStatus_NODE_09_DEV_NODE()
{
return getStatus(ID_NODE_09_DEV_NODE);
}


int doWrite_NODE_09_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_09_STATUS,  &value);
}


int addWrite_NODE_09_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_09_STATUS, &value);
}


int getStatus_NODE_09_STATUS()
{
return getStatus(ID_NODE_09_STATUS);
}


int doWrite_NODE_10_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_10_DEV_NODE,  &value);
}


int addWrite_NODE_10_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_10_DEV_NODE, &value);
}


int getStatus_NODE_10_DEV_NODE()
{
return getStatus(ID_NODE_10_DEV_NODE);
}


int doWrite_NODE_10_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_10_STATUS,  &value);
}


int addWrite_NODE_10_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_10_STATUS, &value);
}


int getStatus_NODE_10_STATUS()
{
return getStatus(ID_NODE_10_STATUS);
}


int doWrite_NODE_11_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_11_DEV_NODE,  &value);
}


int addWrite_NODE_11_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_11_DEV_NODE, &value);
}


int getStatus_NODE_11_DEV_NODE()
{
return getStatus(ID_NODE_11_DEV_NODE);
}


int doWrite_NODE_11_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_11_STATUS,  &value);
}


int addWrite_NODE_11_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_11_STATUS, &value);
}


int getStatus_NODE_11_STATUS()
{
return getStatus(ID_NODE_11_STATUS);
}


int doWrite_NODE_12_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_12_DEV_NODE,  &value);
}


int addWrite_NODE_12_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_12_DEV_NODE, &value);
}


int getStatus_NODE_12_DEV_NODE()
{
return getStatus(ID_NODE_12_DEV_NODE);
}


int doWrite_NODE_12_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_12_STATUS,  &value);
}


int addWrite_NODE_12_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_12_STATUS, &value);
}


int getStatus_NODE_12_STATUS()
{
return getStatus(ID_NODE_12_STATUS);
}


int doWrite_NODE_13_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_13_DEV_NODE,  &value);
}


int addWrite_NODE_13_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_13_DEV_NODE, &value);
}


int getStatus_NODE_13_DEV_NODE()
{
return getStatus(ID_NODE_13_DEV_NODE);
}


int doWrite_NODE_13_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_13_STATUS,  &value);
}


int addWrite_NODE_13_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_13_STATUS, &value);
}


int getStatus_NODE_13_STATUS()
{
return getStatus(ID_NODE_13_STATUS);
}


int doWrite_NODE_14_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_14_DEV_NODE,  &value);
}


int addWrite_NODE_14_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_14_DEV_NODE, &value);
}


int getStatus_NODE_14_DEV_NODE()
{
return getStatus(ID_NODE_14_DEV_NODE);
}


int doWrite_NODE_14_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_14_STATUS,  &value);
}


int addWrite_NODE_14_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_14_STATUS, &value);
}


int getStatus_NODE_14_STATUS()
{
return getStatus(ID_NODE_14_STATUS);
}


int doWrite_NODE_15_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_15_DEV_NODE,  &value);
}


int addWrite_NODE_15_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_15_DEV_NODE, &value);
}


int getStatus_NODE_15_DEV_NODE()
{
return getStatus(ID_NODE_15_DEV_NODE);
}


int doWrite_NODE_15_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_15_STATUS,  &value);
}


int addWrite_NODE_15_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_15_STATUS, &value);
}


int getStatus_NODE_15_STATUS()
{
return getStatus(ID_NODE_15_STATUS);
}


int doWrite_NODE_16_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_16_DEV_NODE,  &value);
}


int addWrite_NODE_16_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_16_DEV_NODE, &value);
}


int getStatus_NODE_16_DEV_NODE()
{
return getStatus(ID_NODE_16_DEV_NODE);
}


int doWrite_NODE_16_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_16_STATUS,  &value);
}


int addWrite_NODE_16_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_16_STATUS, &value);
}


int getStatus_NODE_16_STATUS()
{
return getStatus(ID_NODE_16_STATUS);
}


int doWrite_PLC_DigIn_1(int value)
{
return doWrite(ID_PLC_DigIn_1,  &value);
}


int addWrite_PLC_DigIn_1(int value)
{
return addWrite(ID_PLC_DigIn_1, &value);
}


int getStatus_PLC_DigIn_1()
{
return getStatus(ID_PLC_DigIn_1);
}


int doWrite_PLC_DigIn_2(int value)
{
return doWrite(ID_PLC_DigIn_2,  &value);
}


int addWrite_PLC_DigIn_2(int value)
{
return addWrite(ID_PLC_DigIn_2, &value);
}


int getStatus_PLC_DigIn_2()
{
return getStatus(ID_PLC_DigIn_2);
}


int doWrite_PLC_DigIn_3(int value)
{
return doWrite(ID_PLC_DigIn_3,  &value);
}


int addWrite_PLC_DigIn_3(int value)
{
return addWrite(ID_PLC_DigIn_3, &value);
}


int getStatus_PLC_DigIn_3()
{
return getStatus(ID_PLC_DigIn_3);
}


int doWrite_PLC_DigIn_4(int value)
{
return doWrite(ID_PLC_DigIn_4,  &value);
}


int addWrite_PLC_DigIn_4(int value)
{
return addWrite(ID_PLC_DigIn_4, &value);
}


int getStatus_PLC_DigIn_4()
{
return getStatus(ID_PLC_DigIn_4);
}


int doWrite_PLC_DigIn_5(int value)
{
return doWrite(ID_PLC_DigIn_5,  &value);
}


int addWrite_PLC_DigIn_5(int value)
{
return addWrite(ID_PLC_DigIn_5, &value);
}


int getStatus_PLC_DigIn_5()
{
return getStatus(ID_PLC_DigIn_5);
}


int doWrite_PLC_DigIn_6(int value)
{
return doWrite(ID_PLC_DigIn_6,  &value);
}


int addWrite_PLC_DigIn_6(int value)
{
return addWrite(ID_PLC_DigIn_6, &value);
}


int getStatus_PLC_DigIn_6()
{
return getStatus(ID_PLC_DigIn_6);
}


int doWrite_PLC_DigIn_7(int value)
{
return doWrite(ID_PLC_DigIn_7,  &value);
}


int addWrite_PLC_DigIn_7(int value)
{
return addWrite(ID_PLC_DigIn_7, &value);
}


int getStatus_PLC_DigIn_7()
{
return getStatus(ID_PLC_DigIn_7);
}


int doWrite_PLC_DigIn_8(int value)
{
return doWrite(ID_PLC_DigIn_8,  &value);
}


int addWrite_PLC_DigIn_8(int value)
{
return addWrite(ID_PLC_DigIn_8, &value);
}


int getStatus_PLC_DigIn_8()
{
return getStatus(ID_PLC_DigIn_8);
}


int doWrite_PLC_DigIn_9(int value)
{
return doWrite(ID_PLC_DigIn_9,  &value);
}


int addWrite_PLC_DigIn_9(int value)
{
return addWrite(ID_PLC_DigIn_9, &value);
}


int getStatus_PLC_DigIn_9()
{
return getStatus(ID_PLC_DigIn_9);
}


int doWrite_PLC_DigIn_17(int value)
{
return doWrite(ID_PLC_DigIn_17,  &value);
}


int addWrite_PLC_DigIn_17(int value)
{
return addWrite(ID_PLC_DigIn_17, &value);
}


int getStatus_PLC_DigIn_17()
{
return getStatus(ID_PLC_DigIn_17);
}


int doWrite_PLC_DigIn_25(int value)
{
return doWrite(ID_PLC_DigIn_25,  &value);
}


int addWrite_PLC_DigIn_25(int value)
{
return addWrite(ID_PLC_DigIn_25, &value);
}


int getStatus_PLC_DigIn_25()
{
return getStatus(ID_PLC_DigIn_25);
}


int doWrite_PLC_DigOut_1(int value)
{
return doWrite(ID_PLC_DigOut_1,  &value);
}


int addWrite_PLC_DigOut_1(int value)
{
return addWrite(ID_PLC_DigOut_1, &value);
}


int getStatus_PLC_DigOut_1()
{
return getStatus(ID_PLC_DigOut_1);
}


int doWrite_PLC_DigOut_2(int value)
{
return doWrite(ID_PLC_DigOut_2,  &value);
}


int addWrite_PLC_DigOut_2(int value)
{
return addWrite(ID_PLC_DigOut_2, &value);
}


int getStatus_PLC_DigOut_2()
{
return getStatus(ID_PLC_DigOut_2);
}


int doWrite_PLC_DigOut_3(int value)
{
return doWrite(ID_PLC_DigOut_3,  &value);
}


int addWrite_PLC_DigOut_3(int value)
{
return addWrite(ID_PLC_DigOut_3, &value);
}


int getStatus_PLC_DigOut_3()
{
return getStatus(ID_PLC_DigOut_3);
}


int doWrite_PLC_DigOut_4(int value)
{
return doWrite(ID_PLC_DigOut_4,  &value);
}


int addWrite_PLC_DigOut_4(int value)
{
return addWrite(ID_PLC_DigOut_4, &value);
}


int getStatus_PLC_DigOut_4()
{
return getStatus(ID_PLC_DigOut_4);
}


int doWrite_PLC_DigOut_5(int value)
{
return doWrite(ID_PLC_DigOut_5,  &value);
}


int addWrite_PLC_DigOut_5(int value)
{
return addWrite(ID_PLC_DigOut_5, &value);
}


int getStatus_PLC_DigOut_5()
{
return getStatus(ID_PLC_DigOut_5);
}


int doWrite_PLC_DigOut_6(int value)
{
return doWrite(ID_PLC_DigOut_6,  &value);
}


int addWrite_PLC_DigOut_6(int value)
{
return addWrite(ID_PLC_DigOut_6, &value);
}


int getStatus_PLC_DigOut_6()
{
return getStatus(ID_PLC_DigOut_6);
}


int doWrite_PLC_DigOut_7(int value)
{
return doWrite(ID_PLC_DigOut_7,  &value);
}


int addWrite_PLC_DigOut_7(int value)
{
return addWrite(ID_PLC_DigOut_7, &value);
}


int getStatus_PLC_DigOut_7()
{
return getStatus(ID_PLC_DigOut_7);
}


int doWrite_PLC_DigOut_8(int value)
{
return doWrite(ID_PLC_DigOut_8,  &value);
}


int addWrite_PLC_DigOut_8(int value)
{
return addWrite(ID_PLC_DigOut_8, &value);
}


int getStatus_PLC_DigOut_8()
{
return getStatus(ID_PLC_DigOut_8);
}


int doWrite_PLC_DigOut_9(int value)
{
return doWrite(ID_PLC_DigOut_9,  &value);
}


int addWrite_PLC_DigOut_9(int value)
{
return addWrite(ID_PLC_DigOut_9, &value);
}


int getStatus_PLC_DigOut_9()
{
return getStatus(ID_PLC_DigOut_9);
}


int doWrite_PLC_DigOut_10(int value)
{
return doWrite(ID_PLC_DigOut_10,  &value);
}


int addWrite_PLC_DigOut_10(int value)
{
return addWrite(ID_PLC_DigOut_10, &value);
}


int getStatus_PLC_DigOut_10()
{
return getStatus(ID_PLC_DigOut_10);
}


int doWrite_PLC_DigOut_11(int value)
{
return doWrite(ID_PLC_DigOut_11,  &value);
}


int addWrite_PLC_DigOut_11(int value)
{
return addWrite(ID_PLC_DigOut_11, &value);
}


int getStatus_PLC_DigOut_11()
{
return getStatus(ID_PLC_DigOut_11);
}


int doWrite_PLC_DigOut_12(int value)
{
return doWrite(ID_PLC_DigOut_12,  &value);
}


int addWrite_PLC_DigOut_12(int value)
{
return addWrite(ID_PLC_DigOut_12, &value);
}


int getStatus_PLC_DigOut_12()
{
return getStatus(ID_PLC_DigOut_12);
}


int doWrite_PLC_AnIn_1(int16_t value)
{
return doWrite(ID_PLC_AnIn_1,  &value);
}


int addWrite_PLC_AnIn_1(int16_t value)
{
return addWrite(ID_PLC_AnIn_1, &value);
}


int getStatus_PLC_AnIn_1()
{
return getStatus(ID_PLC_AnIn_1);
}


int doWrite_PLC_AnIn_2(int16_t value)
{
return doWrite(ID_PLC_AnIn_2,  &value);
}


int addWrite_PLC_AnIn_2(int16_t value)
{
return addWrite(ID_PLC_AnIn_2, &value);
}


int getStatus_PLC_AnIn_2()
{
return getStatus(ID_PLC_AnIn_2);
}


int doWrite_PLC_AnIn_3(int16_t value)
{
return doWrite(ID_PLC_AnIn_3,  &value);
}


int addWrite_PLC_AnIn_3(int16_t value)
{
return addWrite(ID_PLC_AnIn_3, &value);
}


int getStatus_PLC_AnIn_3()
{
return getStatus(ID_PLC_AnIn_3);
}


int doWrite_PLC_AnIn_4(int16_t value)
{
return doWrite(ID_PLC_AnIn_4,  &value);
}


int addWrite_PLC_AnIn_4(int16_t value)
{
return addWrite(ID_PLC_AnIn_4, &value);
}


int getStatus_PLC_AnIn_4()
{
return getStatus(ID_PLC_AnIn_4);
}


int doWrite_PLC_Tamb(int16_t value)
{
return doWrite(ID_PLC_Tamb,  &value);
}


int addWrite_PLC_Tamb(int16_t value)
{
return addWrite(ID_PLC_Tamb, &value);
}


int getStatus_PLC_Tamb()
{
return getStatus(ID_PLC_Tamb);
}


int doWrite_PLC_EncoderLo(u_int16_t value)
{
return doWrite(ID_PLC_EncoderLo,  &value);
}


int addWrite_PLC_EncoderLo(u_int16_t value)
{
return addWrite(ID_PLC_EncoderLo, &value);
}


int getStatus_PLC_EncoderLo()
{
return getStatus(ID_PLC_EncoderLo);
}


int doWrite_PLC_EncoderHi(u_int16_t value)
{
return doWrite(ID_PLC_EncoderHi,  &value);
}


int addWrite_PLC_EncoderHi(u_int16_t value)
{
return addWrite(ID_PLC_EncoderHi, &value);
}


int getStatus_PLC_EncoderHi()
{
return getStatus(ID_PLC_EncoderHi);
}


int doWrite_PLC_StatusReg(u_int16_t value)
{
return doWrite(ID_PLC_StatusReg,  &value);
}


int addWrite_PLC_StatusReg(u_int16_t value)
{
return addWrite(ID_PLC_StatusReg, &value);
}


int getStatus_PLC_StatusReg()
{
return getStatus(ID_PLC_StatusReg);
}


int doWrite_PLC_RPM(u_int16_t value)
{
return doWrite(ID_PLC_RPM,  &value);
}


int addWrite_PLC_RPM(u_int16_t value)
{
return addWrite(ID_PLC_RPM, &value);
}


int getStatus_PLC_RPM()
{
return getStatus(ID_PLC_RPM);
}


int doWrite_PLC_AnOut_1(int16_t value)
{
return doWrite(ID_PLC_AnOut_1,  &value);
}


int addWrite_PLC_AnOut_1(int16_t value)
{
return addWrite(ID_PLC_AnOut_1, &value);
}


int getStatus_PLC_AnOut_1()
{
return getStatus(ID_PLC_AnOut_1);
}


int doWrite_PLC_AnOut_2(int16_t value)
{
return doWrite(ID_PLC_AnOut_2,  &value);
}


int addWrite_PLC_AnOut_2(int16_t value)
{
return addWrite(ID_PLC_AnOut_2, &value);
}


int getStatus_PLC_AnOut_2()
{
return getStatus(ID_PLC_AnOut_2);
}


int doWrite_PLC_AnInConf(u_int16_t value)
{
return doWrite(ID_PLC_AnInConf,  &value);
}


int addWrite_PLC_AnInConf(u_int16_t value)
{
return addWrite(ID_PLC_AnInConf, &value);
}


int getStatus_PLC_AnInConf()
{
return getStatus(ID_PLC_AnInConf);
}


int doWrite_PLC_AnOutConf(u_int16_t value)
{
return doWrite(ID_PLC_AnOutConf,  &value);
}


int addWrite_PLC_AnOutConf(u_int16_t value)
{
return addWrite(ID_PLC_AnOutConf, &value);
}


int getStatus_PLC_AnOutConf()
{
return getStatus(ID_PLC_AnOutConf);
}


int doWrite_PLC_ControlWord(u_int16_t value)
{
return doWrite(ID_PLC_ControlWord,  &value);
}


int addWrite_PLC_ControlWord(u_int16_t value)
{
return addWrite(ID_PLC_ControlWord, &value);
}


int getStatus_PLC_ControlWord()
{
return getStatus(ID_PLC_ControlWord);
}


int doWrite_PLC_EncPreset_Lo(u_int16_t value)
{
return doWrite(ID_PLC_EncPreset_Lo,  &value);
}


int addWrite_PLC_EncPreset_Lo(u_int16_t value)
{
return addWrite(ID_PLC_EncPreset_Lo, &value);
}


int getStatus_PLC_EncPreset_Lo()
{
return getStatus(ID_PLC_EncPreset_Lo);
}


int doWrite_PLC_EncPreset_Hi(u_int16_t value)
{
return doWrite(ID_PLC_EncPreset_Hi,  &value);
}


int addWrite_PLC_EncPreset_Hi(u_int16_t value)
{
return addWrite(ID_PLC_EncPreset_Hi, &value);
}


int getStatus_PLC_EncPreset_Hi()
{
return getStatus(ID_PLC_EncPreset_Hi);
}


int doWrite_CH0_NETRUN(int value)
{
return doWrite(ID_CH0_NETRUN,  &value);
}


int addWrite_CH0_NETRUN(int value)
{
return addWrite(ID_CH0_NETRUN, &value);
}


int getStatus_CH0_NETRUN()
{
return getStatus(ID_CH0_NETRUN);
}


int doWrite_CH0_NETGOOD(int value)
{
return doWrite(ID_CH0_NETGOOD,  &value);
}


int addWrite_CH0_NETGOOD(int value)
{
return addWrite(ID_CH0_NETGOOD, &value);
}


int getStatus_CH0_NETGOOD()
{
return getStatus(ID_CH0_NETGOOD);
}


int doWrite_CH0_NETERR(u_int32_t value)
{
return doWrite(ID_CH0_NETERR,  &value);
}


int addWrite_CH0_NETERR(u_int32_t value)
{
return addWrite(ID_CH0_NETERR, &value);
}


int getStatus_CH0_NETERR()
{
return getStatus(ID_CH0_NETERR);
}


int doWrite_CH0_NETRST(int value)
{
return doWrite(ID_CH0_NETRST,  &value);
}


int addWrite_CH0_NETRST(int value)
{
return addWrite(ID_CH0_NETRST, &value);
}


int getStatus_CH0_NETRST()
{
return getStatus(ID_CH0_NETRST);
}


int doWrite_CH0_NETDIS(int value)
{
return doWrite(ID_CH0_NETDIS,  &value);
}


int addWrite_CH0_NETDIS(int value)
{
return addWrite(ID_CH0_NETDIS, &value);
}


int getStatus_CH0_NETDIS()
{
return getStatus(ID_CH0_NETDIS);
}


int doWrite_CH0_01_NODERUN(int value)
{
return doWrite(ID_CH0_01_NODERUN,  &value);
}


int addWrite_CH0_01_NODERUN(int value)
{
return addWrite(ID_CH0_01_NODERUN, &value);
}


int getStatus_CH0_01_NODERUN()
{
return getStatus(ID_CH0_01_NODERUN);
}


int doWrite_CH0_01_NODEGOOD(int value)
{
return doWrite(ID_CH0_01_NODEGOOD,  &value);
}


int addWrite_CH0_01_NODEGOOD(int value)
{
return addWrite(ID_CH0_01_NODEGOOD, &value);
}


int getStatus_CH0_01_NODEGOOD()
{
return getStatus(ID_CH0_01_NODEGOOD);
}


int doWrite_CH0_01_NODEERR(u_int32_t value)
{
return doWrite(ID_CH0_01_NODEERR,  &value);
}


int addWrite_CH0_01_NODEERR(u_int32_t value)
{
return addWrite(ID_CH0_01_NODEERR, &value);
}


int getStatus_CH0_01_NODEERR()
{
return getStatus(ID_CH0_01_NODEERR);
}


int doWrite_CH0_01_NODERST(int value)
{
return doWrite(ID_CH0_01_NODERST,  &value);
}


int addWrite_CH0_01_NODERST(int value)
{
return addWrite(ID_CH0_01_NODERST, &value);
}


int getStatus_CH0_01_NODERST()
{
return getStatus(ID_CH0_01_NODERST);
}


int doWrite_CH0_01_NODEDIS(int value)
{
return doWrite(ID_CH0_01_NODEDIS,  &value);
}


int addWrite_CH0_01_NODEDIS(int value)
{
return addWrite(ID_CH0_01_NODEDIS, &value);
}


int getStatus_CH0_01_NODEDIS()
{
return getStatus(ID_CH0_01_NODEDIS);
}


int doWrite_PLC_time(float value)
{
return doWrite(ID_PLC_time,  &value);
}


int addWrite_PLC_time(float value)
{
return addWrite(ID_PLC_time, &value);
}


int getStatus_PLC_time()
{
return getStatus(ID_PLC_time);
}


int doWrite_PLC_timeMin(float value)
{
return doWrite(ID_PLC_timeMin,  &value);
}


int addWrite_PLC_timeMin(float value)
{
return addWrite(ID_PLC_timeMin, &value);
}


int getStatus_PLC_timeMin()
{
return getStatus(ID_PLC_timeMin);
}


int doWrite_PLC_timeMax(float value)
{
return doWrite(ID_PLC_timeMax,  &value);
}


int addWrite_PLC_timeMax(float value)
{
return addWrite(ID_PLC_timeMax, &value);
}


int getStatus_PLC_timeMax()
{
return getStatus(ID_PLC_timeMax);
}


int doWrite_PLC_timeWin(float value)
{
return doWrite(ID_PLC_timeWin,  &value);
}


int addWrite_PLC_timeWin(float value)
{
return addWrite(ID_PLC_timeWin, &value);
}


int getStatus_PLC_timeWin()
{
return getStatus(ID_PLC_timeWin);
}


int doWrite_PLC_Version(u_int16_t value)
{
return doWrite(ID_PLC_Version,  &value);
}


int addWrite_PLC_Version(u_int16_t value)
{
return addWrite(ID_PLC_Version, &value);
}


int getStatus_PLC_Version()
{
return getStatus(ID_PLC_Version);
}


int doWrite_PLC_EngineStatus(u_int16_t value)
{
return doWrite(ID_PLC_EngineStatus,  &value);
}


int addWrite_PLC_EngineStatus(u_int16_t value)
{
return addWrite(ID_PLC_EngineStatus, &value);
}


int getStatus_PLC_EngineStatus()
{
return getStatus(ID_PLC_EngineStatus);
}


int doWrite_PLC_ResetValues(int value)
{
return doWrite(ID_PLC_ResetValues,  &value);
}


int addWrite_PLC_ResetValues(int value)
{
return addWrite(ID_PLC_ResetValues, &value);
}


int getStatus_PLC_ResetValues()
{
return getStatus(ID_PLC_ResetValues);
}


int update_all(void)
{
int retval = 0;
retval += readFromDb(ID_STATUS, &STATUS);
retval += readFromDb(ID_RTU_HEARTBEAT, &RTU_HEARTBEAT);
retval += readFromDb(ID_RTU_RTU_WR, &RTU_RTU_WR);
retval += readFromDb(ID_RTU_RTU_RD, &RTU_RTU_RD);
retval += readFromDb(ID_TEST_COMMAND, &TEST_COMMAND);
retval += readFromDb(ID_TST_DigIn_1, &TST_DigIn_1);
retval += readFromDb(ID_TST_DigIn_2, &TST_DigIn_2);
retval += readFromDb(ID_TST_DigIn_3, &TST_DigIn_3);
retval += readFromDb(ID_TST_DigIn_4, &TST_DigIn_4);
retval += readFromDb(ID_TST_DigIn_5, &TST_DigIn_5);
retval += readFromDb(ID_TST_DigIn_6, &TST_DigIn_6);
retval += readFromDb(ID_TST_DigIn_7, &TST_DigIn_7);
retval += readFromDb(ID_TST_DigIn_8, &TST_DigIn_8);
retval += readFromDb(ID_TST_DigIn_9, &TST_DigIn_9);
retval += readFromDb(ID_TST_DigIn_10, &TST_DigIn_10);
retval += readFromDb(ID_TST_DigIn_11, &TST_DigIn_11);
retval += readFromDb(ID_TST_DigIn_12, &TST_DigIn_12);
retval += readFromDb(ID_TST_DigIn_13, &TST_DigIn_13);
retval += readFromDb(ID_TST_DigIn_14, &TST_DigIn_14);
retval += readFromDb(ID_TST_DigIn_15, &TST_DigIn_15);
retval += readFromDb(ID_TST_DigIn_16, &TST_DigIn_16);
retval += readFromDb(ID_VAL_DigIn_1, &VAL_DigIn_1);
retval += readFromDb(ID_VAL_DigIn_2, &VAL_DigIn_2);
retval += readFromDb(ID_VAL_DigIn_3, &VAL_DigIn_3);
retval += readFromDb(ID_VAL_DigIn_4, &VAL_DigIn_4);
retval += readFromDb(ID_VAL_DigIn_5, &VAL_DigIn_5);
retval += readFromDb(ID_VAL_DigIn_6, &VAL_DigIn_6);
retval += readFromDb(ID_VAL_DigIn_7, &VAL_DigIn_7);
retval += readFromDb(ID_VAL_DigIn_8, &VAL_DigIn_8);
retval += readFromDb(ID_VAL_DigIn_9, &VAL_DigIn_9);
retval += readFromDb(ID_VAL_DigIn_10, &VAL_DigIn_10);
retval += readFromDb(ID_VAL_DigIn_11, &VAL_DigIn_11);
retval += readFromDb(ID_VAL_DigIn_12, &VAL_DigIn_12);
retval += readFromDb(ID_VAL_DigIn_13, &VAL_DigIn_13);
retval += readFromDb(ID_VAL_DigIn_14, &VAL_DigIn_14);
retval += readFromDb(ID_VAL_DigIn_15, &VAL_DigIn_15);
retval += readFromDb(ID_VAL_DigIn_16, &VAL_DigIn_16);
retval += readFromDb(ID_RES_DigIn_1, &RES_DigIn_1);
retval += readFromDb(ID_RES_DigIn_2, &RES_DigIn_2);
retval += readFromDb(ID_RES_DigIn_3, &RES_DigIn_3);
retval += readFromDb(ID_RES_DigIn_4, &RES_DigIn_4);
retval += readFromDb(ID_RES_DigIn_5, &RES_DigIn_5);
retval += readFromDb(ID_RES_DigIn_6, &RES_DigIn_6);
retval += readFromDb(ID_RES_DigIn_7, &RES_DigIn_7);
retval += readFromDb(ID_RES_DigIn_8, &RES_DigIn_8);
retval += readFromDb(ID_RES_DigIn_9, &RES_DigIn_9);
retval += readFromDb(ID_RES_DigIn_10, &RES_DigIn_10);
retval += readFromDb(ID_RES_DigIn_11, &RES_DigIn_11);
retval += readFromDb(ID_RES_DigIn_12, &RES_DigIn_12);
retval += readFromDb(ID_RES_DigIn_13, &RES_DigIn_13);
retval += readFromDb(ID_RES_DigIn_14, &RES_DigIn_14);
retval += readFromDb(ID_RES_DigIn_15, &RES_DigIn_15);
retval += readFromDb(ID_RES_DigIn_16, &RES_DigIn_16);
retval += readFromDb(ID_TST_DigOut_1, &TST_DigOut_1);
retval += readFromDb(ID_TST_DigOut_2, &TST_DigOut_2);
retval += readFromDb(ID_TST_DigOut_3, &TST_DigOut_3);
retval += readFromDb(ID_TST_DigOut_4, &TST_DigOut_4);
retval += readFromDb(ID_TST_DigOut_5, &TST_DigOut_5);
retval += readFromDb(ID_TST_DigOut_6, &TST_DigOut_6);
retval += readFromDb(ID_TST_DigOut_7, &TST_DigOut_7);
retval += readFromDb(ID_TST_DigOut_8, &TST_DigOut_8);
retval += readFromDb(ID_TST_DigOut_9, &TST_DigOut_9);
retval += readFromDb(ID_TST_DigOut_10, &TST_DigOut_10);
retval += readFromDb(ID_TST_DigOut_11, &TST_DigOut_11);
retval += readFromDb(ID_TST_DigOut_12, &TST_DigOut_12);
retval += readFromDb(ID_TST_DigOut_13, &TST_DigOut_13);
retval += readFromDb(ID_TST_DigOut_14, &TST_DigOut_14);
retval += readFromDb(ID_TST_DigOut_15, &TST_DigOut_15);
retval += readFromDb(ID_TST_DigOut_16, &TST_DigOut_16);
retval += readFromDb(ID_VAL_DigOut_1, &VAL_DigOut_1);
retval += readFromDb(ID_VAL_DigOut_2, &VAL_DigOut_2);
retval += readFromDb(ID_VAL_DigOut_3, &VAL_DigOut_3);
retval += readFromDb(ID_VAL_DigOut_4, &VAL_DigOut_4);
retval += readFromDb(ID_VAL_DigOut_5, &VAL_DigOut_5);
retval += readFromDb(ID_VAL_DigOut_6, &VAL_DigOut_6);
retval += readFromDb(ID_VAL_DigOut_7, &VAL_DigOut_7);
retval += readFromDb(ID_VAL_DigOut_8, &VAL_DigOut_8);
retval += readFromDb(ID_VAL_DigOut_9, &VAL_DigOut_9);
retval += readFromDb(ID_VAL_DigOut_10, &VAL_DigOut_10);
retval += readFromDb(ID_VAL_DigOut_11, &VAL_DigOut_11);
retval += readFromDb(ID_VAL_DigOut_12, &VAL_DigOut_12);
retval += readFromDb(ID_VAL_DigOut_13, &VAL_DigOut_13);
retval += readFromDb(ID_VAL_DigOut_14, &VAL_DigOut_14);
retval += readFromDb(ID_VAL_DigOut_15, &VAL_DigOut_15);
retval += readFromDb(ID_VAL_DigOut_16, &VAL_DigOut_16);
retval += readFromDb(ID_TST_AnIn_1, &TST_AnIn_1);
retval += readFromDb(ID_TST_AnIn_2, &TST_AnIn_2);
retval += readFromDb(ID_TST_AnIn_3, &TST_AnIn_3);
retval += readFromDb(ID_TST_AnIn_4, &TST_AnIn_4);
retval += readFromDb(ID_TST_AnIn_5, &TST_AnIn_5);
retval += readFromDb(ID_TST_AnIn_6, &TST_AnIn_6);
retval += readFromDb(ID_TST_AnIn_7, &TST_AnIn_7);
retval += readFromDb(ID_TST_AnIn_8, &TST_AnIn_8);
retval += readFromDb(ID_TST_AnIn_9, &TST_AnIn_9);
retval += readFromDb(ID_TST_AnIn_10, &TST_AnIn_10);
retval += readFromDb(ID_TST_AnIn_11, &TST_AnIn_11);
retval += readFromDb(ID_TST_AnIn_12, &TST_AnIn_12);
retval += readFromDb(ID_VAL_AnIn_1, &VAL_AnIn_1);
retval += readFromDb(ID_VAL_AnIn_2, &VAL_AnIn_2);
retval += readFromDb(ID_VAL_AnIn_3, &VAL_AnIn_3);
retval += readFromDb(ID_VAL_AnIn_4, &VAL_AnIn_4);
retval += readFromDb(ID_VAL_AnIn_5, &VAL_AnIn_5);
retval += readFromDb(ID_VAL_AnIn_6, &VAL_AnIn_6);
retval += readFromDb(ID_VAL_AnIn_7, &VAL_AnIn_7);
retval += readFromDb(ID_VAL_AnIn_8, &VAL_AnIn_8);
retval += readFromDb(ID_VAL_AnIn_9, &VAL_AnIn_9);
retval += readFromDb(ID_VAL_AnIn_10, &VAL_AnIn_10);
retval += readFromDb(ID_VAL_AnIn_11, &VAL_AnIn_11);
retval += readFromDb(ID_VAL_AnIn_12, &VAL_AnIn_12);
retval += readFromDb(ID_VAL_AnInConf_1, &VAL_AnInConf_1);
retval += readFromDb(ID_VAL_AnInConf_2, &VAL_AnInConf_2);
retval += readFromDb(ID_VAL_AnInConf_3, &VAL_AnInConf_3);
retval += readFromDb(ID_VAL_AnInConf_4, &VAL_AnInConf_4);
retval += readFromDb(ID_VAL_AnInConf_5, &VAL_AnInConf_5);
retval += readFromDb(ID_VAL_AnInConf_6, &VAL_AnInConf_6);
retval += readFromDb(ID_VAL_AnInConf_7, &VAL_AnInConf_7);
retval += readFromDb(ID_VAL_AnInConf_8, &VAL_AnInConf_8);
retval += readFromDb(ID_VAL_AnInConf_9, &VAL_AnInConf_9);
retval += readFromDb(ID_VAL_AnInConf_10, &VAL_AnInConf_10);
retval += readFromDb(ID_VAL_AnInConf_11, &VAL_AnInConf_11);
retval += readFromDb(ID_VAL_AnInConf_12, &VAL_AnInConf_12);
retval += readFromDb(ID_VAL_AnInFltr_1, &VAL_AnInFltr_1);
retval += readFromDb(ID_VAL_AnInFltr_2, &VAL_AnInFltr_2);
retval += readFromDb(ID_VAL_AnInFltr_3, &VAL_AnInFltr_3);
retval += readFromDb(ID_VAL_AnInFltr_4, &VAL_AnInFltr_4);
retval += readFromDb(ID_VAL_AnInFltr_5, &VAL_AnInFltr_5);
retval += readFromDb(ID_VAL_AnInFltr_6, &VAL_AnInFltr_6);
retval += readFromDb(ID_VAL_AnInFltr_7, &VAL_AnInFltr_7);
retval += readFromDb(ID_VAL_AnInFltr_8, &VAL_AnInFltr_8);
retval += readFromDb(ID_VAL_AnInFltr_9, &VAL_AnInFltr_9);
retval += readFromDb(ID_VAL_AnInFltr_10, &VAL_AnInFltr_10);
retval += readFromDb(ID_VAL_AnInFltr_11, &VAL_AnInFltr_11);
retval += readFromDb(ID_VAL_AnInFltr_12, &VAL_AnInFltr_12);
retval += readFromDb(ID_RES_AnIn_1, &RES_AnIn_1);
retval += readFromDb(ID_RES_AnIn_2, &RES_AnIn_2);
retval += readFromDb(ID_RES_AnIn_3, &RES_AnIn_3);
retval += readFromDb(ID_RES_AnIn_4, &RES_AnIn_4);
retval += readFromDb(ID_RES_AnIn_5, &RES_AnIn_5);
retval += readFromDb(ID_RES_AnIn_6, &RES_AnIn_6);
retval += readFromDb(ID_RES_AnIn_7, &RES_AnIn_7);
retval += readFromDb(ID_RES_AnIn_8, &RES_AnIn_8);
retval += readFromDb(ID_RES_AnIn_9, &RES_AnIn_9);
retval += readFromDb(ID_RES_AnIn_10, &RES_AnIn_10);
retval += readFromDb(ID_RES_AnIn_11, &RES_AnIn_11);
retval += readFromDb(ID_RES_AnIn_12, &RES_AnIn_12);
retval += readFromDb(ID_RES_AnInStts_1, &RES_AnInStts_1);
retval += readFromDb(ID_RES_AnInStts_2, &RES_AnInStts_2);
retval += readFromDb(ID_RES_AnInStts_3, &RES_AnInStts_3);
retval += readFromDb(ID_RES_AnInStts_4, &RES_AnInStts_4);
retval += readFromDb(ID_RES_AnInStts_5, &RES_AnInStts_5);
retval += readFromDb(ID_RES_AnInStts_6, &RES_AnInStts_6);
retval += readFromDb(ID_RES_AnInStts_7, &RES_AnInStts_7);
retval += readFromDb(ID_RES_AnInStts_8, &RES_AnInStts_8);
retval += readFromDb(ID_RES_AnInStts_9, &RES_AnInStts_9);
retval += readFromDb(ID_RES_AnInStts_10, &RES_AnInStts_10);
retval += readFromDb(ID_RES_AnInStts_11, &RES_AnInStts_11);
retval += readFromDb(ID_RES_AnInStts_12, &RES_AnInStts_12);
retval += readFromDb(ID_TST_AnOut_1, &TST_AnOut_1);
retval += readFromDb(ID_TST_AnOut_2, &TST_AnOut_2);
retval += readFromDb(ID_TST_AnOut_3, &TST_AnOut_3);
retval += readFromDb(ID_TST_AnOut_4, &TST_AnOut_4);
retval += readFromDb(ID_VAL_AnOut_1, &VAL_AnOut_1);
retval += readFromDb(ID_VAL_AnOut_2, &VAL_AnOut_2);
retval += readFromDb(ID_VAL_AnOut_3, &VAL_AnOut_3);
retval += readFromDb(ID_VAL_AnOut_4, &VAL_AnOut_4);
retval += readFromDb(ID_VAL_AnOutConf_1, &VAL_AnOutConf_1);
retval += readFromDb(ID_VAL_AnOutConf_2, &VAL_AnOutConf_2);
retval += readFromDb(ID_VAL_AnOutConf_3, &VAL_AnOutConf_3);
retval += readFromDb(ID_VAL_AnOutConf_4, &VAL_AnOutConf_4);
retval += readFromDb(ID_RES_AnOutStts_1, &RES_AnOutStts_1);
retval += readFromDb(ID_RES_AnOutStts_2, &RES_AnOutStts_2);
retval += readFromDb(ID_RES_AnOutStts_3, &RES_AnOutStts_3);
retval += readFromDb(ID_RES_AnOutStts_4, &RES_AnOutStts_4);
retval += readFromDb(ID_TST_Tamb, &TST_Tamb);
retval += readFromDb(ID_TST_RPM, &TST_RPM);
retval += readFromDb(ID_TST_FWrevision, &TST_FWrevision);
retval += readFromDb(ID_TST_HWconfig, &TST_HWconfig);
retval += readFromDb(ID_VAL_Tamb, &VAL_Tamb);
retval += readFromDb(ID_VAL_RPM, &VAL_RPM);
retval += readFromDb(ID_VAL_FWrevision, &VAL_FWrevision);
retval += readFromDb(ID_VAL_HWconfig, &VAL_HWconfig);
retval += readFromDb(ID_RES_Tamb, &RES_Tamb);
retval += readFromDb(ID_RES_RPM, &RES_RPM);
retval += readFromDb(ID_RES_FWrevision, &RES_FWrevision);
retval += readFromDb(ID_RES_HWconfig, &RES_HWconfig);
retval += readFromDb(ID_TST_RTUS_WR, &TST_RTUS_WR);
retval += readFromDb(ID_TST_RTUS_RD, &TST_RTUS_RD);
retval += readFromDb(ID_TST_RTU_WR, &TST_RTU_WR);
retval += readFromDb(ID_TST_RTU_RD, &TST_RTU_RD);
retval += readFromDb(ID_TST_RTU3_WR, &TST_RTU3_WR);
retval += readFromDb(ID_TST_RTU3_RD, &TST_RTU3_RD);
retval += readFromDb(ID_TST_CAN_WR, &TST_CAN_WR);
retval += readFromDb(ID_TST_CAN_RD, &TST_CAN_RD);
retval += readFromDb(ID_VAL_RTUS_WR, &VAL_RTUS_WR);
retval += readFromDb(ID_VAL_RTUS_RD, &VAL_RTUS_RD);
retval += readFromDb(ID_VAL_RTU_WR, &VAL_RTU_WR);
retval += readFromDb(ID_VAL_RTU_RD, &VAL_RTU_RD);
retval += readFromDb(ID_VAL_RTU3_WR, &VAL_RTU3_WR);
retval += readFromDb(ID_VAL_RTU3_RD, &VAL_RTU3_RD);
retval += readFromDb(ID_VAL_CAN_WR, &VAL_CAN_WR);
retval += readFromDb(ID_VAL_CAN_RD, &VAL_CAN_RD);
retval += readFromDb(ID_RES_RTUS_WR, &RES_RTUS_WR);
retval += readFromDb(ID_RES_RTUS_RD, &RES_RTUS_RD);
retval += readFromDb(ID_RES_RTU_WR, &RES_RTU_WR);
retval += readFromDb(ID_RES_RTU_RD, &RES_RTU_RD);
retval += readFromDb(ID_RES_RTU3_WR, &RES_RTU3_WR);
retval += readFromDb(ID_RES_RTU3_RD, &RES_RTU3_RD);
retval += readFromDb(ID_RES_CAN_WR, &RES_CAN_WR);
retval += readFromDb(ID_RES_CAN_RD, &RES_CAN_RD);
retval += readFromDb(ID_TEST_STATUS, &TEST_STATUS);
retval += readFromDb(ID_RTU0_TYPE_PORT, &RTU0_TYPE_PORT);
retval += readFromDb(ID_RTU0_BAUDRATE, &RTU0_BAUDRATE);
retval += readFromDb(ID_RTU0_STATUS, &RTU0_STATUS);
retval += readFromDb(ID_RTU0_READS, &RTU0_READS);
retval += readFromDb(ID_RTU0_WRITES, &RTU0_WRITES);
retval += readFromDb(ID_RTU0_TIMEOUTS, &RTU0_TIMEOUTS);
retval += readFromDb(ID_RTU0_COMM_ERRORS, &RTU0_COMM_ERRORS);
retval += readFromDb(ID_RTU0_LAST_ERROR, &RTU0_LAST_ERROR);
retval += readFromDb(ID_RTU0_WRITE_QUEUE, &RTU0_WRITE_QUEUE);
retval += readFromDb(ID_RTU0_READ_QUEUE, &RTU0_READ_QUEUE);
retval += readFromDb(ID_RTU1_TYPE_PORT, &RTU1_TYPE_PORT);
retval += readFromDb(ID_RTU1_BAUDRATE, &RTU1_BAUDRATE);
retval += readFromDb(ID_RTU1_STATUS, &RTU1_STATUS);
retval += readFromDb(ID_RTU1_READS, &RTU1_READS);
retval += readFromDb(ID_RTU1_WRITES, &RTU1_WRITES);
retval += readFromDb(ID_RTU1_TIMEOUTS, &RTU1_TIMEOUTS);
retval += readFromDb(ID_RTU1_COMM_ERRORS, &RTU1_COMM_ERRORS);
retval += readFromDb(ID_RTU1_LAST_ERROR, &RTU1_LAST_ERROR);
retval += readFromDb(ID_RTU1_WRITE_QUEUE, &RTU1_WRITE_QUEUE);
retval += readFromDb(ID_RTU1_READ_QUEUE, &RTU1_READ_QUEUE);
retval += readFromDb(ID_RTU3_TYPE_PORT, &RTU3_TYPE_PORT);
retval += readFromDb(ID_RTU3_BAUDRATE, &RTU3_BAUDRATE);
retval += readFromDb(ID_RTU3_STATUS, &RTU3_STATUS);
retval += readFromDb(ID_RTU3_READS, &RTU3_READS);
retval += readFromDb(ID_RTU3_WRITES, &RTU3_WRITES);
retval += readFromDb(ID_RTU3_TIMEOUTS, &RTU3_TIMEOUTS);
retval += readFromDb(ID_RTU3_COMM_ERRORS, &RTU3_COMM_ERRORS);
retval += readFromDb(ID_RTU3_LAST_ERROR, &RTU3_LAST_ERROR);
retval += readFromDb(ID_RTU3_WRITE_QUEUE, &RTU3_WRITE_QUEUE);
retval += readFromDb(ID_RTU3_READ_QUEUE, &RTU3_READ_QUEUE);
retval += readFromDb(ID_CAN0_TYPE_PORT, &CAN0_TYPE_PORT);
retval += readFromDb(ID_CAN0_BAUDRATE, &CAN0_BAUDRATE);
retval += readFromDb(ID_CAN0_STATUS, &CAN0_STATUS);
retval += readFromDb(ID_CAN0_READS, &CAN0_READS);
retval += readFromDb(ID_CAN0_WRITES, &CAN0_WRITES);
retval += readFromDb(ID_CAN0_TIMEOUTS, &CAN0_TIMEOUTS);
retval += readFromDb(ID_CAN0_COMM_ERRORS, &CAN0_COMM_ERRORS);
retval += readFromDb(ID_CAN0_LAST_ERROR, &CAN0_LAST_ERROR);
retval += readFromDb(ID_CAN0_WRITE_QUEUE, &CAN0_WRITE_QUEUE);
retval += readFromDb(ID_CAN0_READ_QUEUE, &CAN0_READ_QUEUE);
retval += readFromDb(ID_CAN1_TYPE_PORT, &CAN1_TYPE_PORT);
retval += readFromDb(ID_CAN1_BAUDRATE, &CAN1_BAUDRATE);
retval += readFromDb(ID_CAN1_STATUS, &CAN1_STATUS);
retval += readFromDb(ID_CAN1_READS, &CAN1_READS);
retval += readFromDb(ID_CAN1_WRITES, &CAN1_WRITES);
retval += readFromDb(ID_CAN1_TIMEOUTS, &CAN1_TIMEOUTS);
retval += readFromDb(ID_CAN1_COMM_ERRORS, &CAN1_COMM_ERRORS);
retval += readFromDb(ID_CAN1_LAST_ERROR, &CAN1_LAST_ERROR);
retval += readFromDb(ID_CAN1_WRITE_QUEUE, &CAN1_WRITE_QUEUE);
retval += readFromDb(ID_CAN1_READ_QUEUE, &CAN1_READ_QUEUE);
retval += readFromDb(ID_TCPS_TYPE_PORT, &TCPS_TYPE_PORT);
retval += readFromDb(ID_TCPS_IP_ADDRESS, &TCPS_IP_ADDRESS);
retval += readFromDb(ID_TCPS_STATUS, &TCPS_STATUS);
retval += readFromDb(ID_TCPS_READS, &TCPS_READS);
retval += readFromDb(ID_TCPS_WRITES, &TCPS_WRITES);
retval += readFromDb(ID_TCPS_TIMEOUTS, &TCPS_TIMEOUTS);
retval += readFromDb(ID_TCPS_COMM_ERRORS, &TCPS_COMM_ERRORS);
retval += readFromDb(ID_TCPS_LAST_ERROR, &TCPS_LAST_ERROR);
retval += readFromDb(ID_TCPS_WRITE_QUEUE, &TCPS_WRITE_QUEUE);
retval += readFromDb(ID_TCPS_READ_QUEUE, &TCPS_READ_QUEUE);
retval += readFromDb(ID_TCP0_TYPE_PORT, &TCP0_TYPE_PORT);
retval += readFromDb(ID_TCP0_IP_ADDRESS, &TCP0_IP_ADDRESS);
retval += readFromDb(ID_TCP0_STATUS, &TCP0_STATUS);
retval += readFromDb(ID_TCP0_READS, &TCP0_READS);
retval += readFromDb(ID_TCP0_WRITES, &TCP0_WRITES);
retval += readFromDb(ID_TCP0_TIMEOUTS, &TCP0_TIMEOUTS);
retval += readFromDb(ID_TCP0_COMM_ERRORS, &TCP0_COMM_ERRORS);
retval += readFromDb(ID_TCP0_LAST_ERROR, &TCP0_LAST_ERROR);
retval += readFromDb(ID_TCP0_WRITE_QUEUE, &TCP0_WRITE_QUEUE);
retval += readFromDb(ID_TCP0_READ_QUEUE, &TCP0_READ_QUEUE);
retval += readFromDb(ID_TCP1_TYPE_PORT, &TCP1_TYPE_PORT);
retval += readFromDb(ID_TCP1_IP_ADDRESS, &TCP1_IP_ADDRESS);
retval += readFromDb(ID_TCP1_STATUS, &TCP1_STATUS);
retval += readFromDb(ID_TCP1_READS, &TCP1_READS);
retval += readFromDb(ID_TCP1_WRITES, &TCP1_WRITES);
retval += readFromDb(ID_TCP1_TIMEOUTS, &TCP1_TIMEOUTS);
retval += readFromDb(ID_TCP1_COMM_ERRORS, &TCP1_COMM_ERRORS);
retval += readFromDb(ID_TCP1_LAST_ERROR, &TCP1_LAST_ERROR);
retval += readFromDb(ID_TCP1_WRITE_QUEUE, &TCP1_WRITE_QUEUE);
retval += readFromDb(ID_TCP1_READ_QUEUE, &TCP1_READ_QUEUE);
retval += readFromDb(ID_TCP2_TYPE_PORT, &TCP2_TYPE_PORT);
retval += readFromDb(ID_TCP2_IP_ADDRESS, &TCP2_IP_ADDRESS);
retval += readFromDb(ID_TCP2_STATUS, &TCP2_STATUS);
retval += readFromDb(ID_TCP2_READS, &TCP2_READS);
retval += readFromDb(ID_TCP2_WRITES, &TCP2_WRITES);
retval += readFromDb(ID_TCP2_TIMEOUTS, &TCP2_TIMEOUTS);
retval += readFromDb(ID_TCP2_COMM_ERRORS, &TCP2_COMM_ERRORS);
retval += readFromDb(ID_TCP2_LAST_ERROR, &TCP2_LAST_ERROR);
retval += readFromDb(ID_TCP2_WRITE_QUEUE, &TCP2_WRITE_QUEUE);
retval += readFromDb(ID_TCP2_READ_QUEUE, &TCP2_READ_QUEUE);
retval += readFromDb(ID_TCP3_TYPE_PORT, &TCP3_TYPE_PORT);
retval += readFromDb(ID_TCP3_IP_ADDRESS, &TCP3_IP_ADDRESS);
retval += readFromDb(ID_TCP3_STATUS, &TCP3_STATUS);
retval += readFromDb(ID_TCP3_READS, &TCP3_READS);
retval += readFromDb(ID_TCP3_WRITES, &TCP3_WRITES);
retval += readFromDb(ID_TCP3_TIMEOUTS, &TCP3_TIMEOUTS);
retval += readFromDb(ID_TCP3_COMM_ERRORS, &TCP3_COMM_ERRORS);
retval += readFromDb(ID_TCP3_LAST_ERROR, &TCP3_LAST_ERROR);
retval += readFromDb(ID_TCP3_WRITE_QUEUE, &TCP3_WRITE_QUEUE);
retval += readFromDb(ID_TCP3_READ_QUEUE, &TCP3_READ_QUEUE);
retval += readFromDb(ID_TCP4_TYPE_PORT, &TCP4_TYPE_PORT);
retval += readFromDb(ID_TCP4_IP_ADDRESS, &TCP4_IP_ADDRESS);
retval += readFromDb(ID_TCP4_STATUS, &TCP4_STATUS);
retval += readFromDb(ID_TCP4_READS, &TCP4_READS);
retval += readFromDb(ID_TCP4_WRITES, &TCP4_WRITES);
retval += readFromDb(ID_TCP4_TIMEOUTS, &TCP4_TIMEOUTS);
retval += readFromDb(ID_TCP4_COMM_ERRORS, &TCP4_COMM_ERRORS);
retval += readFromDb(ID_TCP4_LAST_ERROR, &TCP4_LAST_ERROR);
retval += readFromDb(ID_TCP4_WRITE_QUEUE, &TCP4_WRITE_QUEUE);
retval += readFromDb(ID_TCP4_READ_QUEUE, &TCP4_READ_QUEUE);
retval += readFromDb(ID_TCP5_TYPE_PORT, &TCP5_TYPE_PORT);
retval += readFromDb(ID_TCP5_IP_ADDRESS, &TCP5_IP_ADDRESS);
retval += readFromDb(ID_TCP5_STATUS, &TCP5_STATUS);
retval += readFromDb(ID_TCP5_READS, &TCP5_READS);
retval += readFromDb(ID_TCP5_WRITES, &TCP5_WRITES);
retval += readFromDb(ID_TCP5_TIMEOUTS, &TCP5_TIMEOUTS);
retval += readFromDb(ID_TCP5_COMM_ERRORS, &TCP5_COMM_ERRORS);
retval += readFromDb(ID_TCP5_LAST_ERROR, &TCP5_LAST_ERROR);
retval += readFromDb(ID_TCP5_WRITE_QUEUE, &TCP5_WRITE_QUEUE);
retval += readFromDb(ID_TCP5_READ_QUEUE, &TCP5_READ_QUEUE);
retval += readFromDb(ID_TCP6_TYPE_PORT, &TCP6_TYPE_PORT);
retval += readFromDb(ID_TCP6_IP_ADDRESS, &TCP6_IP_ADDRESS);
retval += readFromDb(ID_TCP6_STATUS, &TCP6_STATUS);
retval += readFromDb(ID_TCP6_READS, &TCP6_READS);
retval += readFromDb(ID_TCP6_WRITES, &TCP6_WRITES);
retval += readFromDb(ID_TCP6_TIMEOUTS, &TCP6_TIMEOUTS);
retval += readFromDb(ID_TCP6_COMM_ERRORS, &TCP6_COMM_ERRORS);
retval += readFromDb(ID_TCP6_LAST_ERROR, &TCP6_LAST_ERROR);
retval += readFromDb(ID_TCP6_WRITE_QUEUE, &TCP6_WRITE_QUEUE);
retval += readFromDb(ID_TCP6_READ_QUEUE, &TCP6_READ_QUEUE);
retval += readFromDb(ID_TCP7_TYPE_PORT, &TCP7_TYPE_PORT);
retval += readFromDb(ID_TCP7_IP_ADDRESS, &TCP7_IP_ADDRESS);
retval += readFromDb(ID_TCP7_STATUS, &TCP7_STATUS);
retval += readFromDb(ID_TCP7_READS, &TCP7_READS);
retval += readFromDb(ID_TCP7_WRITES, &TCP7_WRITES);
retval += readFromDb(ID_TCP7_TIMEOUTS, &TCP7_TIMEOUTS);
retval += readFromDb(ID_TCP7_COMM_ERRORS, &TCP7_COMM_ERRORS);
retval += readFromDb(ID_TCP7_LAST_ERROR, &TCP7_LAST_ERROR);
retval += readFromDb(ID_TCP7_WRITE_QUEUE, &TCP7_WRITE_QUEUE);
retval += readFromDb(ID_TCP7_READ_QUEUE, &TCP7_READ_QUEUE);
retval += readFromDb(ID_TCP8_TYPE_PORT, &TCP8_TYPE_PORT);
retval += readFromDb(ID_TCP8_IP_ADDRESS, &TCP8_IP_ADDRESS);
retval += readFromDb(ID_TCP8_STATUS, &TCP8_STATUS);
retval += readFromDb(ID_TCP8_READS, &TCP8_READS);
retval += readFromDb(ID_TCP8_WRITES, &TCP8_WRITES);
retval += readFromDb(ID_TCP8_TIMEOUTS, &TCP8_TIMEOUTS);
retval += readFromDb(ID_TCP8_COMM_ERRORS, &TCP8_COMM_ERRORS);
retval += readFromDb(ID_TCP8_LAST_ERROR, &TCP8_LAST_ERROR);
retval += readFromDb(ID_TCP8_WRITE_QUEUE, &TCP8_WRITE_QUEUE);
retval += readFromDb(ID_TCP8_READ_QUEUE, &TCP8_READ_QUEUE);
retval += readFromDb(ID_TCP9_TYPE_PORT, &TCP9_TYPE_PORT);
retval += readFromDb(ID_TCP9_IP_ADDRESS, &TCP9_IP_ADDRESS);
retval += readFromDb(ID_TCP9_STATUS, &TCP9_STATUS);
retval += readFromDb(ID_TCP9_READS, &TCP9_READS);
retval += readFromDb(ID_TCP9_WRITES, &TCP9_WRITES);
retval += readFromDb(ID_TCP9_TIMEOUTS, &TCP9_TIMEOUTS);
retval += readFromDb(ID_TCP9_COMM_ERRORS, &TCP9_COMM_ERRORS);
retval += readFromDb(ID_TCP9_LAST_ERROR, &TCP9_LAST_ERROR);
retval += readFromDb(ID_TCP9_WRITE_QUEUE, &TCP9_WRITE_QUEUE);
retval += readFromDb(ID_TCP9_READ_QUEUE, &TCP9_READ_QUEUE);
retval += readFromDb(ID_NODE_01_DEV_NODE, &NODE_01_DEV_NODE);
retval += readFromDb(ID_NODE_01_STATUS, &NODE_01_STATUS);
retval += readFromDb(ID_NODE_02_DEV_NODE, &NODE_02_DEV_NODE);
retval += readFromDb(ID_NODE_02_STATUS, &NODE_02_STATUS);
retval += readFromDb(ID_NODE_03_DEV_NODE, &NODE_03_DEV_NODE);
retval += readFromDb(ID_NODE_03_STATUS, &NODE_03_STATUS);
retval += readFromDb(ID_NODE_04_DEV_NODE, &NODE_04_DEV_NODE);
retval += readFromDb(ID_NODE_04_STATUS, &NODE_04_STATUS);
retval += readFromDb(ID_NODE_05_DEV_NODE, &NODE_05_DEV_NODE);
retval += readFromDb(ID_NODE_05_STATUS, &NODE_05_STATUS);
retval += readFromDb(ID_NODE_06_DEV_NODE, &NODE_06_DEV_NODE);
retval += readFromDb(ID_NODE_06_STATUS, &NODE_06_STATUS);
retval += readFromDb(ID_NODE_07_DEV_NODE, &NODE_07_DEV_NODE);
retval += readFromDb(ID_NODE_07_STATUS, &NODE_07_STATUS);
retval += readFromDb(ID_NODE_08_DEV_NODE, &NODE_08_DEV_NODE);
retval += readFromDb(ID_NODE_08_STATUS, &NODE_08_STATUS);
retval += readFromDb(ID_NODE_09_DEV_NODE, &NODE_09_DEV_NODE);
retval += readFromDb(ID_NODE_09_STATUS, &NODE_09_STATUS);
retval += readFromDb(ID_NODE_10_DEV_NODE, &NODE_10_DEV_NODE);
retval += readFromDb(ID_NODE_10_STATUS, &NODE_10_STATUS);
retval += readFromDb(ID_NODE_11_DEV_NODE, &NODE_11_DEV_NODE);
retval += readFromDb(ID_NODE_11_STATUS, &NODE_11_STATUS);
retval += readFromDb(ID_NODE_12_DEV_NODE, &NODE_12_DEV_NODE);
retval += readFromDb(ID_NODE_12_STATUS, &NODE_12_STATUS);
retval += readFromDb(ID_NODE_13_DEV_NODE, &NODE_13_DEV_NODE);
retval += readFromDb(ID_NODE_13_STATUS, &NODE_13_STATUS);
retval += readFromDb(ID_NODE_14_DEV_NODE, &NODE_14_DEV_NODE);
retval += readFromDb(ID_NODE_14_STATUS, &NODE_14_STATUS);
retval += readFromDb(ID_NODE_15_DEV_NODE, &NODE_15_DEV_NODE);
retval += readFromDb(ID_NODE_15_STATUS, &NODE_15_STATUS);
retval += readFromDb(ID_NODE_16_DEV_NODE, &NODE_16_DEV_NODE);
retval += readFromDb(ID_NODE_16_STATUS, &NODE_16_STATUS);
retval += readFromDb(ID_PLC_DigIn_1, &PLC_DigIn_1);
retval += readFromDb(ID_PLC_DigIn_2, &PLC_DigIn_2);
retval += readFromDb(ID_PLC_DigIn_3, &PLC_DigIn_3);
retval += readFromDb(ID_PLC_DigIn_4, &PLC_DigIn_4);
retval += readFromDb(ID_PLC_DigIn_5, &PLC_DigIn_5);
retval += readFromDb(ID_PLC_DigIn_6, &PLC_DigIn_6);
retval += readFromDb(ID_PLC_DigIn_7, &PLC_DigIn_7);
retval += readFromDb(ID_PLC_DigIn_8, &PLC_DigIn_8);
retval += readFromDb(ID_PLC_DigIn_9, &PLC_DigIn_9);
retval += readFromDb(ID_PLC_DigIn_17, &PLC_DigIn_17);
retval += readFromDb(ID_PLC_DigIn_25, &PLC_DigIn_25);
retval += readFromDb(ID_PLC_DigOut_1, &PLC_DigOut_1);
retval += readFromDb(ID_PLC_DigOut_2, &PLC_DigOut_2);
retval += readFromDb(ID_PLC_DigOut_3, &PLC_DigOut_3);
retval += readFromDb(ID_PLC_DigOut_4, &PLC_DigOut_4);
retval += readFromDb(ID_PLC_DigOut_5, &PLC_DigOut_5);
retval += readFromDb(ID_PLC_DigOut_6, &PLC_DigOut_6);
retval += readFromDb(ID_PLC_DigOut_7, &PLC_DigOut_7);
retval += readFromDb(ID_PLC_DigOut_8, &PLC_DigOut_8);
retval += readFromDb(ID_PLC_DigOut_9, &PLC_DigOut_9);
retval += readFromDb(ID_PLC_DigOut_10, &PLC_DigOut_10);
retval += readFromDb(ID_PLC_DigOut_11, &PLC_DigOut_11);
retval += readFromDb(ID_PLC_DigOut_12, &PLC_DigOut_12);
retval += readFromDb(ID_PLC_AnIn_1, &PLC_AnIn_1);
retval += readFromDb(ID_PLC_AnIn_2, &PLC_AnIn_2);
retval += readFromDb(ID_PLC_AnIn_3, &PLC_AnIn_3);
retval += readFromDb(ID_PLC_AnIn_4, &PLC_AnIn_4);
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
retval += readFromDb(ID_PLC_EncoderLo, &PLC_EncoderLo);
retval += readFromDb(ID_PLC_EncoderHi, &PLC_EncoderHi);
retval += readFromDb(ID_PLC_StatusReg, &PLC_StatusReg);
retval += readFromDb(ID_PLC_RPM, &PLC_RPM);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_AnOut_2, &PLC_AnOut_2);
retval += readFromDb(ID_PLC_AnInConf, &PLC_AnInConf);
retval += readFromDb(ID_PLC_AnOutConf, &PLC_AnOutConf);
retval += readFromDb(ID_PLC_ControlWord, &PLC_ControlWord);
retval += readFromDb(ID_PLC_EncPreset_Lo, &PLC_EncPreset_Lo);
retval += readFromDb(ID_PLC_EncPreset_Hi, &PLC_EncPreset_Hi);
retval += readFromDb(ID_CH0_NETRUN, &CH0_NETRUN);
retval += readFromDb(ID_CH0_NETGOOD, &CH0_NETGOOD);
retval += readFromDb(ID_CH0_NETERR, &CH0_NETERR);
retval += readFromDb(ID_CH0_NETRST, &CH0_NETRST);
retval += readFromDb(ID_CH0_NETDIS, &CH0_NETDIS);
retval += readFromDb(ID_CH0_01_NODERUN, &CH0_01_NODERUN);
retval += readFromDb(ID_CH0_01_NODEGOOD, &CH0_01_NODEGOOD);
retval += readFromDb(ID_CH0_01_NODEERR, &CH0_01_NODEERR);
retval += readFromDb(ID_CH0_01_NODERST, &CH0_01_NODERST);
retval += readFromDb(ID_CH0_01_NODEDIS, &CH0_01_NODEDIS);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
retval += readFromDb(ID_PLC_Version, &PLC_Version);
retval += readFromDb(ID_PLC_EngineStatus, &PLC_EngineStatus);
retval += readFromDb(ID_PLC_ResetValues, &PLC_ResetValues);
return retval;
}
