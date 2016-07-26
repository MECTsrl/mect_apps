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
 
int DINP_TE3_00 = 0;
int DINP_TE3_01 = 0;
int DINP_TE3_02 = 0;
int DINP_TE3_03 = 0;
int DINP_TE3_04 = 0;
int DINP_TE3_05 = 0;
int DINP_TE3_06 = 0;
int DINP_TE3_07 = 0;
int DINP_TE3_08 = 0;
int DINP_TE3_09 = 0;
int DINP_TE3_0A = 0;
int DINP_TE3_0B = 0;
int DINP_TE3_0C = 0;
int DINP_TE3_0D = 0;
int DINP_TE3_0E = 0;
int DINP_TE3_0F = 0;
int DOUT_TE0_00 = 0;
int DOUT_TE0_01 = 0;
int DOUT_TE0_02 = 0;
int DOUT_TE0_03 = 0;
int DOUT_TE0_04 = 0;
int DOUT_TE0_05 = 0;
int DOUT_TE0_06 = 0;
int DOUT_TE0_07 = 0;
int DOUT_TE0_08 = 0;
int DOUT_TE0_09 = 0;
int DOUT_TE0_0A = 0;
int DOUT_TE0_0B = 0;
int DOUT_TE0_0C = 0;
int DOUT_TE0_0D = 0;
int DOUT_TE0_0E = 0;
int DOUT_TE0_0F = 0;
int DOUT_TE1_00 = 0;
int DOUT_TE1_01 = 0;
int DOUT_TE1_02 = 0;
int DOUT_TE1_03 = 0;
int DOUT_TE1_04 = 0;
int DOUT_TE1_05 = 0;
int DOUT_TE1_06 = 0;
int DOUT_TE1_07 = 0;
int DOUT_TE1_08 = 0;
int DOUT_TE1_09 = 0;
int DOUT_TE1_0A = 0;
int DOUT_TE1_0B = 0;
int DOUT_TE1_0C = 0;
int DOUT_TE1_0D = 0;
int DOUT_TE1_0E = 0;
int DOUT_TE1_0F = 0;
int16_t ANIN0_TE2_00 = 0;
int16_t ANIN0_TE2_01 = 0;
int16_t ANIN0_TE2_02 = 0;
int16_t ANIN0_TE2_03 = 0;
int CH1_NETRUN = 0;
int CH1_NETGOOD = 0;
u_int32_t CH1_NETERR = 0;
int CH1_NETRST = 0;
int CH1_NETDIS = 0;
int CH1_01_NODERUN = 0;
int CH1_01_NODEGOOD = 0;
u_int32_t CH1_01_NODEERR = 0;
int CH1_01_NODERST = 0;
int CH1_01_NODEDIS = 0;
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
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;
u_int16_t PLC_Version = 0;
u_int16_t PLC_EngineStatus = 0;
int PLC_ResetValues = 0;
int PLC_buzzerOn = 0;


int doWrite_DINP_TE3_00(int value)
{
return doWrite(ID_DINP_TE3_00,  &value);
}


int addWrite_DINP_TE3_00(int value)
{
return addWrite(ID_DINP_TE3_00, &value);
}


int getStatus_DINP_TE3_00()
{
return getStatus(ID_DINP_TE3_00);
}


int doWrite_DINP_TE3_01(int value)
{
return doWrite(ID_DINP_TE3_01,  &value);
}


int addWrite_DINP_TE3_01(int value)
{
return addWrite(ID_DINP_TE3_01, &value);
}


int getStatus_DINP_TE3_01()
{
return getStatus(ID_DINP_TE3_01);
}


int doWrite_DINP_TE3_02(int value)
{
return doWrite(ID_DINP_TE3_02,  &value);
}


int addWrite_DINP_TE3_02(int value)
{
return addWrite(ID_DINP_TE3_02, &value);
}


int getStatus_DINP_TE3_02()
{
return getStatus(ID_DINP_TE3_02);
}


int doWrite_DINP_TE3_03(int value)
{
return doWrite(ID_DINP_TE3_03,  &value);
}


int addWrite_DINP_TE3_03(int value)
{
return addWrite(ID_DINP_TE3_03, &value);
}


int getStatus_DINP_TE3_03()
{
return getStatus(ID_DINP_TE3_03);
}


int doWrite_DINP_TE3_04(int value)
{
return doWrite(ID_DINP_TE3_04,  &value);
}


int addWrite_DINP_TE3_04(int value)
{
return addWrite(ID_DINP_TE3_04, &value);
}


int getStatus_DINP_TE3_04()
{
return getStatus(ID_DINP_TE3_04);
}


int doWrite_DINP_TE3_05(int value)
{
return doWrite(ID_DINP_TE3_05,  &value);
}


int addWrite_DINP_TE3_05(int value)
{
return addWrite(ID_DINP_TE3_05, &value);
}


int getStatus_DINP_TE3_05()
{
return getStatus(ID_DINP_TE3_05);
}


int doWrite_DINP_TE3_06(int value)
{
return doWrite(ID_DINP_TE3_06,  &value);
}


int addWrite_DINP_TE3_06(int value)
{
return addWrite(ID_DINP_TE3_06, &value);
}


int getStatus_DINP_TE3_06()
{
return getStatus(ID_DINP_TE3_06);
}


int doWrite_DINP_TE3_07(int value)
{
return doWrite(ID_DINP_TE3_07,  &value);
}


int addWrite_DINP_TE3_07(int value)
{
return addWrite(ID_DINP_TE3_07, &value);
}


int getStatus_DINP_TE3_07()
{
return getStatus(ID_DINP_TE3_07);
}


int doWrite_DINP_TE3_08(int value)
{
return doWrite(ID_DINP_TE3_08,  &value);
}


int addWrite_DINP_TE3_08(int value)
{
return addWrite(ID_DINP_TE3_08, &value);
}


int getStatus_DINP_TE3_08()
{
return getStatus(ID_DINP_TE3_08);
}


int doWrite_DINP_TE3_09(int value)
{
return doWrite(ID_DINP_TE3_09,  &value);
}


int addWrite_DINP_TE3_09(int value)
{
return addWrite(ID_DINP_TE3_09, &value);
}


int getStatus_DINP_TE3_09()
{
return getStatus(ID_DINP_TE3_09);
}


int doWrite_DINP_TE3_0A(int value)
{
return doWrite(ID_DINP_TE3_0A,  &value);
}


int addWrite_DINP_TE3_0A(int value)
{
return addWrite(ID_DINP_TE3_0A, &value);
}


int getStatus_DINP_TE3_0A()
{
return getStatus(ID_DINP_TE3_0A);
}


int doWrite_DINP_TE3_0B(int value)
{
return doWrite(ID_DINP_TE3_0B,  &value);
}


int addWrite_DINP_TE3_0B(int value)
{
return addWrite(ID_DINP_TE3_0B, &value);
}


int getStatus_DINP_TE3_0B()
{
return getStatus(ID_DINP_TE3_0B);
}


int doWrite_DINP_TE3_0C(int value)
{
return doWrite(ID_DINP_TE3_0C,  &value);
}


int addWrite_DINP_TE3_0C(int value)
{
return addWrite(ID_DINP_TE3_0C, &value);
}


int getStatus_DINP_TE3_0C()
{
return getStatus(ID_DINP_TE3_0C);
}


int doWrite_DINP_TE3_0D(int value)
{
return doWrite(ID_DINP_TE3_0D,  &value);
}


int addWrite_DINP_TE3_0D(int value)
{
return addWrite(ID_DINP_TE3_0D, &value);
}


int getStatus_DINP_TE3_0D()
{
return getStatus(ID_DINP_TE3_0D);
}


int doWrite_DINP_TE3_0E(int value)
{
return doWrite(ID_DINP_TE3_0E,  &value);
}


int addWrite_DINP_TE3_0E(int value)
{
return addWrite(ID_DINP_TE3_0E, &value);
}


int getStatus_DINP_TE3_0E()
{
return getStatus(ID_DINP_TE3_0E);
}


int doWrite_DINP_TE3_0F(int value)
{
return doWrite(ID_DINP_TE3_0F,  &value);
}


int addWrite_DINP_TE3_0F(int value)
{
return addWrite(ID_DINP_TE3_0F, &value);
}


int getStatus_DINP_TE3_0F()
{
return getStatus(ID_DINP_TE3_0F);
}


int doWrite_DOUT_TE0_00(int value)
{
return doWrite(ID_DOUT_TE0_00,  &value);
}


int addWrite_DOUT_TE0_00(int value)
{
return addWrite(ID_DOUT_TE0_00, &value);
}


int getStatus_DOUT_TE0_00()
{
return getStatus(ID_DOUT_TE0_00);
}


int doWrite_DOUT_TE0_01(int value)
{
return doWrite(ID_DOUT_TE0_01,  &value);
}


int addWrite_DOUT_TE0_01(int value)
{
return addWrite(ID_DOUT_TE0_01, &value);
}


int getStatus_DOUT_TE0_01()
{
return getStatus(ID_DOUT_TE0_01);
}


int doWrite_DOUT_TE0_02(int value)
{
return doWrite(ID_DOUT_TE0_02,  &value);
}


int addWrite_DOUT_TE0_02(int value)
{
return addWrite(ID_DOUT_TE0_02, &value);
}


int getStatus_DOUT_TE0_02()
{
return getStatus(ID_DOUT_TE0_02);
}


int doWrite_DOUT_TE0_03(int value)
{
return doWrite(ID_DOUT_TE0_03,  &value);
}


int addWrite_DOUT_TE0_03(int value)
{
return addWrite(ID_DOUT_TE0_03, &value);
}


int getStatus_DOUT_TE0_03()
{
return getStatus(ID_DOUT_TE0_03);
}


int doWrite_DOUT_TE0_04(int value)
{
return doWrite(ID_DOUT_TE0_04,  &value);
}


int addWrite_DOUT_TE0_04(int value)
{
return addWrite(ID_DOUT_TE0_04, &value);
}


int getStatus_DOUT_TE0_04()
{
return getStatus(ID_DOUT_TE0_04);
}


int doWrite_DOUT_TE0_05(int value)
{
return doWrite(ID_DOUT_TE0_05,  &value);
}


int addWrite_DOUT_TE0_05(int value)
{
return addWrite(ID_DOUT_TE0_05, &value);
}


int getStatus_DOUT_TE0_05()
{
return getStatus(ID_DOUT_TE0_05);
}


int doWrite_DOUT_TE0_06(int value)
{
return doWrite(ID_DOUT_TE0_06,  &value);
}


int addWrite_DOUT_TE0_06(int value)
{
return addWrite(ID_DOUT_TE0_06, &value);
}


int getStatus_DOUT_TE0_06()
{
return getStatus(ID_DOUT_TE0_06);
}


int doWrite_DOUT_TE0_07(int value)
{
return doWrite(ID_DOUT_TE0_07,  &value);
}


int addWrite_DOUT_TE0_07(int value)
{
return addWrite(ID_DOUT_TE0_07, &value);
}


int getStatus_DOUT_TE0_07()
{
return getStatus(ID_DOUT_TE0_07);
}


int doWrite_DOUT_TE0_08(int value)
{
return doWrite(ID_DOUT_TE0_08,  &value);
}


int addWrite_DOUT_TE0_08(int value)
{
return addWrite(ID_DOUT_TE0_08, &value);
}


int getStatus_DOUT_TE0_08()
{
return getStatus(ID_DOUT_TE0_08);
}


int doWrite_DOUT_TE0_09(int value)
{
return doWrite(ID_DOUT_TE0_09,  &value);
}


int addWrite_DOUT_TE0_09(int value)
{
return addWrite(ID_DOUT_TE0_09, &value);
}


int getStatus_DOUT_TE0_09()
{
return getStatus(ID_DOUT_TE0_09);
}


int doWrite_DOUT_TE0_0A(int value)
{
return doWrite(ID_DOUT_TE0_0A,  &value);
}


int addWrite_DOUT_TE0_0A(int value)
{
return addWrite(ID_DOUT_TE0_0A, &value);
}


int getStatus_DOUT_TE0_0A()
{
return getStatus(ID_DOUT_TE0_0A);
}


int doWrite_DOUT_TE0_0B(int value)
{
return doWrite(ID_DOUT_TE0_0B,  &value);
}


int addWrite_DOUT_TE0_0B(int value)
{
return addWrite(ID_DOUT_TE0_0B, &value);
}


int getStatus_DOUT_TE0_0B()
{
return getStatus(ID_DOUT_TE0_0B);
}


int doWrite_DOUT_TE0_0C(int value)
{
return doWrite(ID_DOUT_TE0_0C,  &value);
}


int addWrite_DOUT_TE0_0C(int value)
{
return addWrite(ID_DOUT_TE0_0C, &value);
}


int getStatus_DOUT_TE0_0C()
{
return getStatus(ID_DOUT_TE0_0C);
}


int doWrite_DOUT_TE0_0D(int value)
{
return doWrite(ID_DOUT_TE0_0D,  &value);
}


int addWrite_DOUT_TE0_0D(int value)
{
return addWrite(ID_DOUT_TE0_0D, &value);
}


int getStatus_DOUT_TE0_0D()
{
return getStatus(ID_DOUT_TE0_0D);
}


int doWrite_DOUT_TE0_0E(int value)
{
return doWrite(ID_DOUT_TE0_0E,  &value);
}


int addWrite_DOUT_TE0_0E(int value)
{
return addWrite(ID_DOUT_TE0_0E, &value);
}


int getStatus_DOUT_TE0_0E()
{
return getStatus(ID_DOUT_TE0_0E);
}


int doWrite_DOUT_TE0_0F(int value)
{
return doWrite(ID_DOUT_TE0_0F,  &value);
}


int addWrite_DOUT_TE0_0F(int value)
{
return addWrite(ID_DOUT_TE0_0F, &value);
}


int getStatus_DOUT_TE0_0F()
{
return getStatus(ID_DOUT_TE0_0F);
}


int doWrite_DOUT_TE1_00(int value)
{
return doWrite(ID_DOUT_TE1_00,  &value);
}


int addWrite_DOUT_TE1_00(int value)
{
return addWrite(ID_DOUT_TE1_00, &value);
}


int getStatus_DOUT_TE1_00()
{
return getStatus(ID_DOUT_TE1_00);
}


int doWrite_DOUT_TE1_01(int value)
{
return doWrite(ID_DOUT_TE1_01,  &value);
}


int addWrite_DOUT_TE1_01(int value)
{
return addWrite(ID_DOUT_TE1_01, &value);
}


int getStatus_DOUT_TE1_01()
{
return getStatus(ID_DOUT_TE1_01);
}


int doWrite_DOUT_TE1_02(int value)
{
return doWrite(ID_DOUT_TE1_02,  &value);
}


int addWrite_DOUT_TE1_02(int value)
{
return addWrite(ID_DOUT_TE1_02, &value);
}


int getStatus_DOUT_TE1_02()
{
return getStatus(ID_DOUT_TE1_02);
}


int doWrite_DOUT_TE1_03(int value)
{
return doWrite(ID_DOUT_TE1_03,  &value);
}


int addWrite_DOUT_TE1_03(int value)
{
return addWrite(ID_DOUT_TE1_03, &value);
}


int getStatus_DOUT_TE1_03()
{
return getStatus(ID_DOUT_TE1_03);
}


int doWrite_DOUT_TE1_04(int value)
{
return doWrite(ID_DOUT_TE1_04,  &value);
}


int addWrite_DOUT_TE1_04(int value)
{
return addWrite(ID_DOUT_TE1_04, &value);
}


int getStatus_DOUT_TE1_04()
{
return getStatus(ID_DOUT_TE1_04);
}


int doWrite_DOUT_TE1_05(int value)
{
return doWrite(ID_DOUT_TE1_05,  &value);
}


int addWrite_DOUT_TE1_05(int value)
{
return addWrite(ID_DOUT_TE1_05, &value);
}


int getStatus_DOUT_TE1_05()
{
return getStatus(ID_DOUT_TE1_05);
}


int doWrite_DOUT_TE1_06(int value)
{
return doWrite(ID_DOUT_TE1_06,  &value);
}


int addWrite_DOUT_TE1_06(int value)
{
return addWrite(ID_DOUT_TE1_06, &value);
}


int getStatus_DOUT_TE1_06()
{
return getStatus(ID_DOUT_TE1_06);
}


int doWrite_DOUT_TE1_07(int value)
{
return doWrite(ID_DOUT_TE1_07,  &value);
}


int addWrite_DOUT_TE1_07(int value)
{
return addWrite(ID_DOUT_TE1_07, &value);
}


int getStatus_DOUT_TE1_07()
{
return getStatus(ID_DOUT_TE1_07);
}


int doWrite_DOUT_TE1_08(int value)
{
return doWrite(ID_DOUT_TE1_08,  &value);
}


int addWrite_DOUT_TE1_08(int value)
{
return addWrite(ID_DOUT_TE1_08, &value);
}


int getStatus_DOUT_TE1_08()
{
return getStatus(ID_DOUT_TE1_08);
}


int doWrite_DOUT_TE1_09(int value)
{
return doWrite(ID_DOUT_TE1_09,  &value);
}


int addWrite_DOUT_TE1_09(int value)
{
return addWrite(ID_DOUT_TE1_09, &value);
}


int getStatus_DOUT_TE1_09()
{
return getStatus(ID_DOUT_TE1_09);
}


int doWrite_DOUT_TE1_0A(int value)
{
return doWrite(ID_DOUT_TE1_0A,  &value);
}


int addWrite_DOUT_TE1_0A(int value)
{
return addWrite(ID_DOUT_TE1_0A, &value);
}


int getStatus_DOUT_TE1_0A()
{
return getStatus(ID_DOUT_TE1_0A);
}


int doWrite_DOUT_TE1_0B(int value)
{
return doWrite(ID_DOUT_TE1_0B,  &value);
}


int addWrite_DOUT_TE1_0B(int value)
{
return addWrite(ID_DOUT_TE1_0B, &value);
}


int getStatus_DOUT_TE1_0B()
{
return getStatus(ID_DOUT_TE1_0B);
}


int doWrite_DOUT_TE1_0C(int value)
{
return doWrite(ID_DOUT_TE1_0C,  &value);
}


int addWrite_DOUT_TE1_0C(int value)
{
return addWrite(ID_DOUT_TE1_0C, &value);
}


int getStatus_DOUT_TE1_0C()
{
return getStatus(ID_DOUT_TE1_0C);
}


int doWrite_DOUT_TE1_0D(int value)
{
return doWrite(ID_DOUT_TE1_0D,  &value);
}


int addWrite_DOUT_TE1_0D(int value)
{
return addWrite(ID_DOUT_TE1_0D, &value);
}


int getStatus_DOUT_TE1_0D()
{
return getStatus(ID_DOUT_TE1_0D);
}


int doWrite_DOUT_TE1_0E(int value)
{
return doWrite(ID_DOUT_TE1_0E,  &value);
}


int addWrite_DOUT_TE1_0E(int value)
{
return addWrite(ID_DOUT_TE1_0E, &value);
}


int getStatus_DOUT_TE1_0E()
{
return getStatus(ID_DOUT_TE1_0E);
}


int doWrite_DOUT_TE1_0F(int value)
{
return doWrite(ID_DOUT_TE1_0F,  &value);
}


int addWrite_DOUT_TE1_0F(int value)
{
return addWrite(ID_DOUT_TE1_0F, &value);
}


int getStatus_DOUT_TE1_0F()
{
return getStatus(ID_DOUT_TE1_0F);
}


int doWrite_ANIN0_TE2_00(int16_t value)
{
return doWrite(ID_ANIN0_TE2_00,  &value);
}


int addWrite_ANIN0_TE2_00(int16_t value)
{
return addWrite(ID_ANIN0_TE2_00, &value);
}


int getStatus_ANIN0_TE2_00()
{
return getStatus(ID_ANIN0_TE2_00);
}


int doWrite_ANIN0_TE2_01(int16_t value)
{
return doWrite(ID_ANIN0_TE2_01,  &value);
}


int addWrite_ANIN0_TE2_01(int16_t value)
{
return addWrite(ID_ANIN0_TE2_01, &value);
}


int getStatus_ANIN0_TE2_01()
{
return getStatus(ID_ANIN0_TE2_01);
}


int doWrite_ANIN0_TE2_02(int16_t value)
{
return doWrite(ID_ANIN0_TE2_02,  &value);
}


int addWrite_ANIN0_TE2_02(int16_t value)
{
return addWrite(ID_ANIN0_TE2_02, &value);
}


int getStatus_ANIN0_TE2_02()
{
return getStatus(ID_ANIN0_TE2_02);
}


int doWrite_ANIN0_TE2_03(int16_t value)
{
return doWrite(ID_ANIN0_TE2_03,  &value);
}


int addWrite_ANIN0_TE2_03(int16_t value)
{
return addWrite(ID_ANIN0_TE2_03, &value);
}


int getStatus_ANIN0_TE2_03()
{
return getStatus(ID_ANIN0_TE2_03);
}


int doWrite_CH1_NETRUN(int value)
{
return doWrite(ID_CH1_NETRUN,  &value);
}


int addWrite_CH1_NETRUN(int value)
{
return addWrite(ID_CH1_NETRUN, &value);
}


int getStatus_CH1_NETRUN()
{
return getStatus(ID_CH1_NETRUN);
}


int doWrite_CH1_NETGOOD(int value)
{
return doWrite(ID_CH1_NETGOOD,  &value);
}


int addWrite_CH1_NETGOOD(int value)
{
return addWrite(ID_CH1_NETGOOD, &value);
}


int getStatus_CH1_NETGOOD()
{
return getStatus(ID_CH1_NETGOOD);
}


int doWrite_CH1_NETERR(u_int32_t value)
{
return doWrite(ID_CH1_NETERR,  &value);
}


int addWrite_CH1_NETERR(u_int32_t value)
{
return addWrite(ID_CH1_NETERR, &value);
}


int getStatus_CH1_NETERR()
{
return getStatus(ID_CH1_NETERR);
}


int doWrite_CH1_NETRST(int value)
{
return doWrite(ID_CH1_NETRST,  &value);
}


int addWrite_CH1_NETRST(int value)
{
return addWrite(ID_CH1_NETRST, &value);
}


int getStatus_CH1_NETRST()
{
return getStatus(ID_CH1_NETRST);
}


int doWrite_CH1_NETDIS(int value)
{
return doWrite(ID_CH1_NETDIS,  &value);
}


int addWrite_CH1_NETDIS(int value)
{
return addWrite(ID_CH1_NETDIS, &value);
}


int getStatus_CH1_NETDIS()
{
return getStatus(ID_CH1_NETDIS);
}


int doWrite_CH1_01_NODERUN(int value)
{
return doWrite(ID_CH1_01_NODERUN,  &value);
}


int addWrite_CH1_01_NODERUN(int value)
{
return addWrite(ID_CH1_01_NODERUN, &value);
}


int getStatus_CH1_01_NODERUN()
{
return getStatus(ID_CH1_01_NODERUN);
}


int doWrite_CH1_01_NODEGOOD(int value)
{
return doWrite(ID_CH1_01_NODEGOOD,  &value);
}


int addWrite_CH1_01_NODEGOOD(int value)
{
return addWrite(ID_CH1_01_NODEGOOD, &value);
}


int getStatus_CH1_01_NODEGOOD()
{
return getStatus(ID_CH1_01_NODEGOOD);
}


int doWrite_CH1_01_NODEERR(u_int32_t value)
{
return doWrite(ID_CH1_01_NODEERR,  &value);
}


int addWrite_CH1_01_NODEERR(u_int32_t value)
{
return addWrite(ID_CH1_01_NODEERR, &value);
}


int getStatus_CH1_01_NODEERR()
{
return getStatus(ID_CH1_01_NODEERR);
}


int doWrite_CH1_01_NODERST(int value)
{
return doWrite(ID_CH1_01_NODERST,  &value);
}


int addWrite_CH1_01_NODERST(int value)
{
return addWrite(ID_CH1_01_NODERST, &value);
}


int getStatus_CH1_01_NODERST()
{
return getStatus(ID_CH1_01_NODERST);
}


int doWrite_CH1_01_NODEDIS(int value)
{
return doWrite(ID_CH1_01_NODEDIS,  &value);
}


int addWrite_CH1_01_NODEDIS(int value)
{
return addWrite(ID_CH1_01_NODEDIS, &value);
}


int getStatus_CH1_01_NODEDIS()
{
return getStatus(ID_CH1_01_NODEDIS);
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


int doWrite_PLC_buzzerOn(int value)
{
return doWrite(ID_PLC_buzzerOn,  &value);
}


int addWrite_PLC_buzzerOn(int value)
{
return addWrite(ID_PLC_buzzerOn, &value);
}


int getStatus_PLC_buzzerOn()
{
return getStatus(ID_PLC_buzzerOn);
}


int update_all(void)
{
int retval = 0;
retval += readFromDb(ID_DINP_TE3_00, &DINP_TE3_00);
retval += readFromDb(ID_DINP_TE3_01, &DINP_TE3_01);
retval += readFromDb(ID_DINP_TE3_02, &DINP_TE3_02);
retval += readFromDb(ID_DINP_TE3_03, &DINP_TE3_03);
retval += readFromDb(ID_DINP_TE3_04, &DINP_TE3_04);
retval += readFromDb(ID_DINP_TE3_05, &DINP_TE3_05);
retval += readFromDb(ID_DINP_TE3_06, &DINP_TE3_06);
retval += readFromDb(ID_DINP_TE3_07, &DINP_TE3_07);
retval += readFromDb(ID_DINP_TE3_08, &DINP_TE3_08);
retval += readFromDb(ID_DINP_TE3_09, &DINP_TE3_09);
retval += readFromDb(ID_DINP_TE3_0A, &DINP_TE3_0A);
retval += readFromDb(ID_DINP_TE3_0B, &DINP_TE3_0B);
retval += readFromDb(ID_DINP_TE3_0C, &DINP_TE3_0C);
retval += readFromDb(ID_DINP_TE3_0D, &DINP_TE3_0D);
retval += readFromDb(ID_DINP_TE3_0E, &DINP_TE3_0E);
retval += readFromDb(ID_DINP_TE3_0F, &DINP_TE3_0F);
retval += readFromDb(ID_DOUT_TE0_00, &DOUT_TE0_00);
retval += readFromDb(ID_DOUT_TE0_01, &DOUT_TE0_01);
retval += readFromDb(ID_DOUT_TE0_02, &DOUT_TE0_02);
retval += readFromDb(ID_DOUT_TE0_03, &DOUT_TE0_03);
retval += readFromDb(ID_DOUT_TE0_04, &DOUT_TE0_04);
retval += readFromDb(ID_DOUT_TE0_05, &DOUT_TE0_05);
retval += readFromDb(ID_DOUT_TE0_06, &DOUT_TE0_06);
retval += readFromDb(ID_DOUT_TE0_07, &DOUT_TE0_07);
retval += readFromDb(ID_DOUT_TE0_08, &DOUT_TE0_08);
retval += readFromDb(ID_DOUT_TE0_09, &DOUT_TE0_09);
retval += readFromDb(ID_DOUT_TE0_0A, &DOUT_TE0_0A);
retval += readFromDb(ID_DOUT_TE0_0B, &DOUT_TE0_0B);
retval += readFromDb(ID_DOUT_TE0_0C, &DOUT_TE0_0C);
retval += readFromDb(ID_DOUT_TE0_0D, &DOUT_TE0_0D);
retval += readFromDb(ID_DOUT_TE0_0E, &DOUT_TE0_0E);
retval += readFromDb(ID_DOUT_TE0_0F, &DOUT_TE0_0F);
retval += readFromDb(ID_DOUT_TE1_00, &DOUT_TE1_00);
retval += readFromDb(ID_DOUT_TE1_01, &DOUT_TE1_01);
retval += readFromDb(ID_DOUT_TE1_02, &DOUT_TE1_02);
retval += readFromDb(ID_DOUT_TE1_03, &DOUT_TE1_03);
retval += readFromDb(ID_DOUT_TE1_04, &DOUT_TE1_04);
retval += readFromDb(ID_DOUT_TE1_05, &DOUT_TE1_05);
retval += readFromDb(ID_DOUT_TE1_06, &DOUT_TE1_06);
retval += readFromDb(ID_DOUT_TE1_07, &DOUT_TE1_07);
retval += readFromDb(ID_DOUT_TE1_08, &DOUT_TE1_08);
retval += readFromDb(ID_DOUT_TE1_09, &DOUT_TE1_09);
retval += readFromDb(ID_DOUT_TE1_0A, &DOUT_TE1_0A);
retval += readFromDb(ID_DOUT_TE1_0B, &DOUT_TE1_0B);
retval += readFromDb(ID_DOUT_TE1_0C, &DOUT_TE1_0C);
retval += readFromDb(ID_DOUT_TE1_0D, &DOUT_TE1_0D);
retval += readFromDb(ID_DOUT_TE1_0E, &DOUT_TE1_0E);
retval += readFromDb(ID_DOUT_TE1_0F, &DOUT_TE1_0F);
retval += readFromDb(ID_ANIN0_TE2_00, &ANIN0_TE2_00);
retval += readFromDb(ID_ANIN0_TE2_01, &ANIN0_TE2_01);
retval += readFromDb(ID_ANIN0_TE2_02, &ANIN0_TE2_02);
retval += readFromDb(ID_ANIN0_TE2_03, &ANIN0_TE2_03);
retval += readFromDb(ID_CH1_NETRUN, &CH1_NETRUN);
retval += readFromDb(ID_CH1_NETGOOD, &CH1_NETGOOD);
retval += readFromDb(ID_CH1_NETERR, &CH1_NETERR);
retval += readFromDb(ID_CH1_NETRST, &CH1_NETRST);
retval += readFromDb(ID_CH1_NETDIS, &CH1_NETDIS);
retval += readFromDb(ID_CH1_01_NODERUN, &CH1_01_NODERUN);
retval += readFromDb(ID_CH1_01_NODEGOOD, &CH1_01_NODEGOOD);
retval += readFromDb(ID_CH1_01_NODEERR, &CH1_01_NODEERR);
retval += readFromDb(ID_CH1_01_NODERST, &CH1_01_NODERST);
retval += readFromDb(ID_CH1_01_NODEDIS, &CH1_01_NODEDIS);
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
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
retval += readFromDb(ID_PLC_Version, &PLC_Version);
retval += readFromDb(ID_PLC_EngineStatus, &PLC_EngineStatus);
retval += readFromDb(ID_PLC_ResetValues, &PLC_ResetValues);
retval += readFromDb(ID_PLC_buzzerOn, &PLC_buzzerOn);
return retval;
}
