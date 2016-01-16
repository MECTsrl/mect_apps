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
 
u_int32_t PRODUCT_ID = 0;
u_int32_t SERIAL_NUMBER = 0;
u_int32_t TEST_STEP = 0;
u_int32_t TEST_DATE = 0;
u_int32_t TEST_TIME = 0;
u_int32_t TEST_DURATION = 0;
int GO = 0;
int RESET = 0;
int START = 0;
int STOP = 0;
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
int OK_DigIn_1 = 0;
int OK_DigIn_2 = 0;
int OK_DigIn_3 = 0;
int OK_DigIn_4 = 0;
int OK_DigIn_5 = 0;
int OK_DigIn_6 = 0;
int OK_DigIn_7 = 0;
int OK_DigIn_8 = 0;
int OK_DigIn_9 = 0;
int OK_DigIn_10 = 0;
int OK_DigIn_11 = 0;
int OK_DigIn_12 = 0;
int OK_DigIn_13 = 0;
int OK_DigIn_14 = 0;
int OK_DigIn_15 = 0;
int OK_DigIn_16 = 0;
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
int RES_DigOut_1 = 0;
int RES_DigOut_2 = 0;
int RES_DigOut_3 = 0;
int RES_DigOut_4 = 0;
int RES_DigOut_5 = 0;
int RES_DigOut_6 = 0;
int RES_DigOut_7 = 0;
int RES_DigOut_8 = 0;
int RES_DigOut_9 = 0;
int RES_DigOut_10 = 0;
int RES_DigOut_11 = 0;
int RES_DigOut_12 = 0;
int RES_DigOut_13 = 0;
int RES_DigOut_14 = 0;
int RES_DigOut_15 = 0;
int RES_DigOut_16 = 0;
int OK_DigOut_1 = 0;
int OK_DigOut_2 = 0;
int OK_DigOut_3 = 0;
int OK_DigOut_4 = 0;
int OK_DigOut_5 = 0;
int OK_DigOut_6 = 0;
int OK_DigOut_7 = 0;
int OK_DigOut_8 = 0;
int OK_DigOut_9 = 0;
int OK_DigOut_10 = 0;
int OK_DigOut_11 = 0;
int OK_DigOut_12 = 0;
int OK_DigOut_13 = 0;
int OK_DigOut_14 = 0;
int OK_DigOut_15 = 0;
int OK_DigOut_16 = 0;
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
int16_t OK_AnIn_1 = 0;
int16_t OK_AnIn_2 = 0;
int16_t OK_AnIn_3 = 0;
int16_t OK_AnIn_4 = 0;
int16_t OK_AnIn_5 = 0;
int16_t OK_AnIn_6 = 0;
int16_t OK_AnIn_7 = 0;
int16_t OK_AnIn_8 = 0;
int16_t OK_AnIn_9 = 0;
int16_t OK_AnIn_10 = 0;
int16_t OK_AnIn_11 = 0;
int16_t OK_AnIn_12 = 0;
int TST_AnOut_1 = 0;
int TST_AnOut_2 = 0;
int TST_AnOut_3 = 0;
int TST_AnOut_4 = 0;
int TST_AnOut_5 = 0;
int TST_AnOut_6 = 0;
int TST_AnOut_7 = 0;
int TST_AnOut_8 = 0;
int16_t VAL_AnOut_1 = 0;
int16_t VAL_AnOut_2 = 0;
int16_t VAL_AnOut_3 = 0;
int16_t VAL_AnOut_4 = 0;
int16_t VAL_AnOut_5 = 0;
int16_t VAL_AnOut_6 = 0;
int16_t VAL_AnOut_7 = 0;
int16_t VAL_AnOut_8 = 0;
u_int16_t VAL_AnOutConf_1 = 0;
u_int16_t VAL_AnOutConf_2 = 0;
u_int16_t VAL_AnOutConf_3 = 0;
u_int16_t VAL_AnOutConf_4 = 0;
u_int16_t VAL_AnOutConf_5 = 0;
u_int16_t VAL_AnOutConf_6 = 0;
u_int16_t VAL_AnOutConf_7 = 0;
u_int16_t VAL_AnOutConf_8 = 0;
int16_t RES_AnOut_1 = 0;
int16_t RES_AnOut_2 = 0;
int16_t RES_AnOut_3 = 0;
int16_t RES_AnOut_4 = 0;
int16_t RES_AnOut_5 = 0;
int16_t RES_AnOut_6 = 0;
int16_t RES_AnOut_7 = 0;
int16_t RES_AnOut_8 = 0;
int16_t OK_AnOut_1 = 0;
int16_t OK_AnOut_2 = 0;
int16_t OK_AnOut_3 = 0;
int16_t OK_AnOut_4 = 0;
int16_t OK_AnOut_5 = 0;
int16_t OK_AnOut_6 = 0;
int16_t OK_AnOut_7 = 0;
int16_t OK_AnOut_8 = 0;
int TST_Tamb = 0;
int TST_RPM = 0;
int TST_VCC_set = 0;
int TST_VCC_fbk = 0;
int TST_mA_fbk = 0;
int TST_FWrevision = 0;
int TST_HWconfig = 0;
int16_t VAL_Tamb = 0;
u_int16_t VAL_RPM = 0;
int16_t VAL_VCC_set = 0;
int16_t VAL_VCC_fbk = 0;
int16_t VAL_mA_fbk = 0;
u_int16_t VAL_FWrevision = 0;
u_int16_t VAL_HWconfig = 0;
int16_t RES_Tamb = 0;
u_int16_t RES_RPM = 0;
int16_t RES_VCC_set = 0;
int16_t RES_VCC_fbk = 0;
int16_t RES_mA_fbk = 0;
u_int16_t RES_FWrevision = 0;
u_int16_t RES_HWconfig = 0;
int16_t OK_Tamb = 0;
u_int16_t OK_RPM = 0;
int16_t OK_VCC_set = 0;
int16_t OK_VCC_fbk = 0;
int16_t OK_mA_fbk = 0;
u_int16_t OK_FWrevision = 0;
u_int16_t OK_HWconfig = 0;
int TST_RTUS_WR = 0;
int TST_RTUS_RD = 0;
int TST_RTU1_WR = 0;
int TST_RTU1_RD = 0;
int TST_RTU3_WR = 0;
int TST_RTU3_RD = 0;
int TST_CAN1_WR = 0;
int TST_CAN1_RD = 0;
int VAL_RTUS_WR = 0;
int VAL_RTUS_RD = 0;
int VAL_RTU1_WR = 0;
int VAL_RTU1_RD = 0;
int VAL_RTU3_WR = 0;
int VAL_RTU3_RD = 0;
int VAL_CAN1_WR = 0;
int VAL_CAN1_RD = 0;
int RES_RTUS_WR = 0;
int RES_RTUS_RD = 0;
int RES_RTU1_WR = 0;
int RES_RTU1_RD = 0;
int RES_RTU3_WR = 0;
int RES_RTU3_RD = 0;
int RES_CAN1_WR = 0;
int RES_CAN1_RD = 0;
int OK_RTUS_WR = 0;
int OK_RTUS_RD = 0;
int OK_RTU1_WR = 0;
int OK_RTU1_RD = 0;
int OK_RTU3_WR = 0;
int OK_RTU3_RD = 0;
int OK_CAN1_WR = 0;
int OK_CAN1_RD = 0;
int PLC_DigIn_1 = 0;
int PLC_DigIn_2 = 0;
int PLC_DigIn_3 = 0;
int PLC_DigIn_4 = 0;
int PLC_DigIn_5 = 0;
int PLC_DigIn_6 = 0;
int PLC_DigIn_7 = 0;
int PLC_DigIn_8 = 0;
int PLC_DigIn_9 = 0;
int PLC_DigIn_10 = 0;
int PLC_DigIn_11 = 0;
int PLC_DigIn_12 = 0;
int PLC_DigIn_13 = 0;
int PLC_DigIn_14 = 0;
int PLC_DigIn_15 = 0;
int PLC_DigIn_16 = 0;
int16_t PLC_AnIn_1 = 0;
int16_t PLC_AnIn_2 = 0;
int16_t PLC_Tamb = 0;
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
int PLC_DigOut_13 = 0;
int PLC_DigOut_14 = 0;
int PLC_DigOut_15 = 0;
int PLC_DigOut_16 = 0;
int16_t PLC_AnOutConf_X = 0;
int16_t PLC_AnOut_1 = 0;
int16_t PLC_AnOut_2 = 0;
int16_t PLC_AnOut_3 = 0;
int16_t PLC_AnOut_4 = 0;
int16_t PLC_AnOut_5 = 0;
int16_t PLC_AnOut_6 = 0;
int16_t PLC_AnOut_7 = 0;
int16_t PLC_AnOut_8 = 0;
u_int16_t PLC_AnInConf_1 = 0;
u_int16_t PLC_AnInConf_2 = 0;
u_int32_t PLC_HeartBeat = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;


int doWrite_PRODUCT_ID(u_int32_t value)
{
return writeVarByCtIndex(ID_PRODUCT_ID,  &value);
}


int addWrite_PRODUCT_ID(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_PRODUCT_ID, &value, NULL, 0) == ERROR);
}


int doWrite_SERIAL_NUMBER(u_int32_t value)
{
return writeVarByCtIndex(ID_SERIAL_NUMBER,  &value);
}


int addWrite_SERIAL_NUMBER(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_SERIAL_NUMBER, &value, NULL, 0) == ERROR);
}


int doWrite_TEST_STEP(u_int32_t value)
{
return writeVarByCtIndex(ID_TEST_STEP,  &value);
}


int addWrite_TEST_STEP(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_TEST_STEP, &value, NULL, 0) == ERROR);
}


int doWrite_TEST_DATE(u_int32_t value)
{
return writeVarByCtIndex(ID_TEST_DATE,  &value);
}


int addWrite_TEST_DATE(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_TEST_DATE, &value, NULL, 0) == ERROR);
}


int doWrite_TEST_TIME(u_int32_t value)
{
return writeVarByCtIndex(ID_TEST_TIME,  &value);
}


int addWrite_TEST_TIME(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_TEST_TIME, &value, NULL, 0) == ERROR);
}


int doWrite_TEST_DURATION(u_int32_t value)
{
return writeVarByCtIndex(ID_TEST_DURATION,  &value);
}


int addWrite_TEST_DURATION(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_TEST_DURATION, &value, NULL, 0) == ERROR);
}


int doWrite_GO(int value)
{
return writeVarByCtIndex(ID_GO,  &value);
}


int addWrite_GO(int value)
{
return (prepareWriteVarByCtIndex(ID_GO, &value, NULL, 0) == ERROR);
}


int doWrite_RESET(int value)
{
return writeVarByCtIndex(ID_RESET,  &value);
}


int addWrite_RESET(int value)
{
return (prepareWriteVarByCtIndex(ID_RESET, &value, NULL, 0) == ERROR);
}


int doWrite_START(int value)
{
return writeVarByCtIndex(ID_START,  &value);
}


int addWrite_START(int value)
{
return (prepareWriteVarByCtIndex(ID_START, &value, NULL, 0) == ERROR);
}


int doWrite_STOP(int value)
{
return writeVarByCtIndex(ID_STOP,  &value);
}


int addWrite_STOP(int value)
{
return (prepareWriteVarByCtIndex(ID_STOP, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_1(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_1,  &value);
}


int addWrite_TST_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_2(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_2,  &value);
}


int addWrite_TST_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_3(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_3,  &value);
}


int addWrite_TST_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_4(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_4,  &value);
}


int addWrite_TST_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_5(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_5,  &value);
}


int addWrite_TST_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_6(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_6,  &value);
}


int addWrite_TST_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_7(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_7,  &value);
}


int addWrite_TST_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_8(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_8,  &value);
}


int addWrite_TST_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_9(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_9,  &value);
}


int addWrite_TST_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_10(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_10,  &value);
}


int addWrite_TST_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_11(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_11,  &value);
}


int addWrite_TST_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_12(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_12,  &value);
}


int addWrite_TST_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_13(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_13,  &value);
}


int addWrite_TST_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_14(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_14,  &value);
}


int addWrite_TST_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_15(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_15,  &value);
}


int addWrite_TST_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigIn_16(int value)
{
return writeVarByCtIndex(ID_TST_DigIn_16,  &value);
}


int addWrite_TST_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_1(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_1,  &value);
}


int addWrite_VAL_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_2(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_2,  &value);
}


int addWrite_VAL_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_3(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_3,  &value);
}


int addWrite_VAL_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_4(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_4,  &value);
}


int addWrite_VAL_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_5(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_5,  &value);
}


int addWrite_VAL_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_6(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_6,  &value);
}


int addWrite_VAL_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_7(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_7,  &value);
}


int addWrite_VAL_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_8(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_8,  &value);
}


int addWrite_VAL_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_9(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_9,  &value);
}


int addWrite_VAL_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_10(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_10,  &value);
}


int addWrite_VAL_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_11(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_11,  &value);
}


int addWrite_VAL_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_12(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_12,  &value);
}


int addWrite_VAL_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_13(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_13,  &value);
}


int addWrite_VAL_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_14(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_14,  &value);
}


int addWrite_VAL_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_15(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_15,  &value);
}


int addWrite_VAL_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigIn_16(int value)
{
return writeVarByCtIndex(ID_VAL_DigIn_16,  &value);
}


int addWrite_VAL_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_1(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_1,  &value);
}


int addWrite_RES_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_2(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_2,  &value);
}


int addWrite_RES_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_3(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_3,  &value);
}


int addWrite_RES_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_4(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_4,  &value);
}


int addWrite_RES_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_5(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_5,  &value);
}


int addWrite_RES_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_6(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_6,  &value);
}


int addWrite_RES_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_7(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_7,  &value);
}


int addWrite_RES_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_8(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_8,  &value);
}


int addWrite_RES_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_9(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_9,  &value);
}


int addWrite_RES_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_10(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_10,  &value);
}


int addWrite_RES_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_11(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_11,  &value);
}


int addWrite_RES_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_12(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_12,  &value);
}


int addWrite_RES_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_13(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_13,  &value);
}


int addWrite_RES_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_14(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_14,  &value);
}


int addWrite_RES_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_15(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_15,  &value);
}


int addWrite_RES_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigIn_16(int value)
{
return writeVarByCtIndex(ID_RES_DigIn_16,  &value);
}


int addWrite_RES_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_1(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_1,  &value);
}


int addWrite_OK_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_2(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_2,  &value);
}


int addWrite_OK_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_3(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_3,  &value);
}


int addWrite_OK_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_4(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_4,  &value);
}


int addWrite_OK_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_5(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_5,  &value);
}


int addWrite_OK_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_6(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_6,  &value);
}


int addWrite_OK_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_7(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_7,  &value);
}


int addWrite_OK_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_8(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_8,  &value);
}


int addWrite_OK_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_9(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_9,  &value);
}


int addWrite_OK_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_10(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_10,  &value);
}


int addWrite_OK_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_11(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_11,  &value);
}


int addWrite_OK_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_12(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_12,  &value);
}


int addWrite_OK_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_13(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_13,  &value);
}


int addWrite_OK_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_14(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_14,  &value);
}


int addWrite_OK_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_15(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_15,  &value);
}


int addWrite_OK_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigIn_16(int value)
{
return writeVarByCtIndex(ID_OK_DigIn_16,  &value);
}


int addWrite_OK_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_1(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_1,  &value);
}


int addWrite_TST_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_2(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_2,  &value);
}


int addWrite_TST_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_3(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_3,  &value);
}


int addWrite_TST_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_4(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_4,  &value);
}


int addWrite_TST_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_5(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_5,  &value);
}


int addWrite_TST_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_6(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_6,  &value);
}


int addWrite_TST_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_7(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_7,  &value);
}


int addWrite_TST_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_8(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_8,  &value);
}


int addWrite_TST_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_9(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_9,  &value);
}


int addWrite_TST_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_10(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_10,  &value);
}


int addWrite_TST_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_11(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_11,  &value);
}


int addWrite_TST_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_12(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_12,  &value);
}


int addWrite_TST_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_13(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_13,  &value);
}


int addWrite_TST_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_14(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_14,  &value);
}


int addWrite_TST_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_15(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_15,  &value);
}


int addWrite_TST_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_TST_DigOut_16(int value)
{
return writeVarByCtIndex(ID_TST_DigOut_16,  &value);
}


int addWrite_TST_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_1(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_1,  &value);
}


int addWrite_VAL_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_2(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_2,  &value);
}


int addWrite_VAL_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_3(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_3,  &value);
}


int addWrite_VAL_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_4(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_4,  &value);
}


int addWrite_VAL_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_5(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_5,  &value);
}


int addWrite_VAL_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_6(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_6,  &value);
}


int addWrite_VAL_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_7(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_7,  &value);
}


int addWrite_VAL_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_8(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_8,  &value);
}


int addWrite_VAL_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_9(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_9,  &value);
}


int addWrite_VAL_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_10(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_10,  &value);
}


int addWrite_VAL_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_11(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_11,  &value);
}


int addWrite_VAL_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_12(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_12,  &value);
}


int addWrite_VAL_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_13(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_13,  &value);
}


int addWrite_VAL_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_14(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_14,  &value);
}


int addWrite_VAL_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_15(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_15,  &value);
}


int addWrite_VAL_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_DigOut_16(int value)
{
return writeVarByCtIndex(ID_VAL_DigOut_16,  &value);
}


int addWrite_VAL_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_1(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_1,  &value);
}


int addWrite_RES_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_2(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_2,  &value);
}


int addWrite_RES_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_3(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_3,  &value);
}


int addWrite_RES_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_4(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_4,  &value);
}


int addWrite_RES_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_5(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_5,  &value);
}


int addWrite_RES_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_6(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_6,  &value);
}


int addWrite_RES_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_7(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_7,  &value);
}


int addWrite_RES_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_8(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_8,  &value);
}


int addWrite_RES_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_9(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_9,  &value);
}


int addWrite_RES_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_10(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_10,  &value);
}


int addWrite_RES_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_11(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_11,  &value);
}


int addWrite_RES_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_12(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_12,  &value);
}


int addWrite_RES_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_13(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_13,  &value);
}


int addWrite_RES_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_14(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_14,  &value);
}


int addWrite_RES_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_15(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_15,  &value);
}


int addWrite_RES_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_RES_DigOut_16(int value)
{
return writeVarByCtIndex(ID_RES_DigOut_16,  &value);
}


int addWrite_RES_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_1(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_1,  &value);
}


int addWrite_OK_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_2(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_2,  &value);
}


int addWrite_OK_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_3(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_3,  &value);
}


int addWrite_OK_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_4(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_4,  &value);
}


int addWrite_OK_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_5(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_5,  &value);
}


int addWrite_OK_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_6(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_6,  &value);
}


int addWrite_OK_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_7(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_7,  &value);
}


int addWrite_OK_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_8(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_8,  &value);
}


int addWrite_OK_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_9(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_9,  &value);
}


int addWrite_OK_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_10(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_10,  &value);
}


int addWrite_OK_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_11(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_11,  &value);
}


int addWrite_OK_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_12(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_12,  &value);
}


int addWrite_OK_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_13(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_13,  &value);
}


int addWrite_OK_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_14(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_14,  &value);
}


int addWrite_OK_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_15(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_15,  &value);
}


int addWrite_OK_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_OK_DigOut_16(int value)
{
return writeVarByCtIndex(ID_OK_DigOut_16,  &value);
}


int addWrite_OK_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_1(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_1,  &value);
}


int addWrite_TST_AnIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_2(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_2,  &value);
}


int addWrite_TST_AnIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_3(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_3,  &value);
}


int addWrite_TST_AnIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_4(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_4,  &value);
}


int addWrite_TST_AnIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_5(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_5,  &value);
}


int addWrite_TST_AnIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_6(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_6,  &value);
}


int addWrite_TST_AnIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_7(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_7,  &value);
}


int addWrite_TST_AnIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_8(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_8,  &value);
}


int addWrite_TST_AnIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_9(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_9,  &value);
}


int addWrite_TST_AnIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_10(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_10,  &value);
}


int addWrite_TST_AnIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_11(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_11,  &value);
}


int addWrite_TST_AnIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnIn_12(int value)
{
return writeVarByCtIndex(ID_TST_AnIn_12,  &value);
}


int addWrite_TST_AnIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_1,  &value);
}


int addWrite_VAL_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_2,  &value);
}


int addWrite_VAL_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_3,  &value);
}


int addWrite_VAL_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_4,  &value);
}


int addWrite_VAL_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_5,  &value);
}


int addWrite_VAL_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_6,  &value);
}


int addWrite_VAL_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_7,  &value);
}


int addWrite_VAL_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_8,  &value);
}


int addWrite_VAL_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_9(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_9,  &value);
}


int addWrite_VAL_AnIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_10(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_10,  &value);
}


int addWrite_VAL_AnIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_11(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_11,  &value);
}


int addWrite_VAL_AnIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnIn_12(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnIn_12,  &value);
}


int addWrite_VAL_AnIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_1,  &value);
}


int addWrite_VAL_AnInConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_2,  &value);
}


int addWrite_VAL_AnInConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_3,  &value);
}


int addWrite_VAL_AnInConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_4,  &value);
}


int addWrite_VAL_AnInConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_5(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_5,  &value);
}


int addWrite_VAL_AnInConf_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_6(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_6,  &value);
}


int addWrite_VAL_AnInConf_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_7(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_7,  &value);
}


int addWrite_VAL_AnInConf_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_8(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_8,  &value);
}


int addWrite_VAL_AnInConf_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_9(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_9,  &value);
}


int addWrite_VAL_AnInConf_9(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_10(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_10,  &value);
}


int addWrite_VAL_AnInConf_10(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_11(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_11,  &value);
}


int addWrite_VAL_AnInConf_11(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInConf_12(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInConf_12,  &value);
}


int addWrite_VAL_AnInConf_12(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInConf_12, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_1,  &value);
}


int addWrite_RES_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_2,  &value);
}


int addWrite_RES_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_3,  &value);
}


int addWrite_RES_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_4,  &value);
}


int addWrite_RES_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_5,  &value);
}


int addWrite_RES_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_6,  &value);
}


int addWrite_RES_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_7,  &value);
}


int addWrite_RES_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_8,  &value);
}


int addWrite_RES_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_9(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_9,  &value);
}


int addWrite_RES_AnIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_10(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_10,  &value);
}


int addWrite_RES_AnIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_11(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_11,  &value);
}


int addWrite_RES_AnIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnIn_12(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnIn_12,  &value);
}


int addWrite_RES_AnIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_1,  &value);
}


int addWrite_OK_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_2,  &value);
}


int addWrite_OK_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_3,  &value);
}


int addWrite_OK_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_4,  &value);
}


int addWrite_OK_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_5,  &value);
}


int addWrite_OK_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_6,  &value);
}


int addWrite_OK_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_7,  &value);
}


int addWrite_OK_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_8,  &value);
}


int addWrite_OK_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_9(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_9,  &value);
}


int addWrite_OK_AnIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_10(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_10,  &value);
}


int addWrite_OK_AnIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_11(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_11,  &value);
}


int addWrite_OK_AnIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_12(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnIn_12,  &value);
}


int addWrite_OK_AnIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_1(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_1,  &value);
}


int addWrite_TST_AnOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_2(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_2,  &value);
}


int addWrite_TST_AnOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_3(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_3,  &value);
}


int addWrite_TST_AnOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_4(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_4,  &value);
}


int addWrite_TST_AnOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_5(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_5,  &value);
}


int addWrite_TST_AnOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_6(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_6,  &value);
}


int addWrite_TST_AnOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_7(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_7,  &value);
}


int addWrite_TST_AnOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_TST_AnOut_8(int value)
{
return writeVarByCtIndex(ID_TST_AnOut_8,  &value);
}


int addWrite_TST_AnOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_AnOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_1,  &value);
}


int addWrite_VAL_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_2,  &value);
}


int addWrite_VAL_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_3,  &value);
}


int addWrite_VAL_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_4,  &value);
}


int addWrite_VAL_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_5(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_5,  &value);
}


int addWrite_VAL_AnOut_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_6(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_6,  &value);
}


int addWrite_VAL_AnOut_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_7(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_7,  &value);
}


int addWrite_VAL_AnOut_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOut_8(int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOut_8,  &value);
}


int addWrite_VAL_AnOut_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_1,  &value);
}


int addWrite_VAL_AnOutConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_2,  &value);
}


int addWrite_VAL_AnOutConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_3,  &value);
}


int addWrite_VAL_AnOutConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_4,  &value);
}


int addWrite_VAL_AnOutConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_5(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_5,  &value);
}


int addWrite_VAL_AnOutConf_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_6(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_6,  &value);
}


int addWrite_VAL_AnOutConf_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_7(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_7,  &value);
}


int addWrite_VAL_AnOutConf_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnOutConf_8(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnOutConf_8,  &value);
}


int addWrite_VAL_AnOutConf_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnOutConf_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_1,  &value);
}


int addWrite_RES_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_2,  &value);
}


int addWrite_RES_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_3,  &value);
}


int addWrite_RES_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_4,  &value);
}


int addWrite_RES_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_5(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_5,  &value);
}


int addWrite_RES_AnOut_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_6(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_6,  &value);
}


int addWrite_RES_AnOut_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_7(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_7,  &value);
}


int addWrite_RES_AnOut_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOut_8(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOut_8,  &value);
}


int addWrite_RES_AnOut_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_1,  &value);
}


int addWrite_OK_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_2,  &value);
}


int addWrite_OK_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_3,  &value);
}


int addWrite_OK_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_4,  &value);
}


int addWrite_OK_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_5(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_5,  &value);
}


int addWrite_OK_AnOut_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_6(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_6,  &value);
}


int addWrite_OK_AnOut_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_7(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_7,  &value);
}


int addWrite_OK_AnOut_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_8(int16_t value)
{
return writeVarByCtIndex(ID_OK_AnOut_8,  &value);
}


int addWrite_OK_AnOut_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_TST_Tamb(int value)
{
return writeVarByCtIndex(ID_TST_Tamb,  &value);
}


int addWrite_TST_Tamb(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_TST_RPM(int value)
{
return writeVarByCtIndex(ID_TST_RPM,  &value);
}


int addWrite_TST_RPM(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_TST_VCC_set(int value)
{
return writeVarByCtIndex(ID_TST_VCC_set,  &value);
}


int addWrite_TST_VCC_set(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_VCC_set, &value, NULL, 0) == ERROR);
}


int doWrite_TST_VCC_fbk(int value)
{
return writeVarByCtIndex(ID_TST_VCC_fbk,  &value);
}


int addWrite_TST_VCC_fbk(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_VCC_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_TST_mA_fbk(int value)
{
return writeVarByCtIndex(ID_TST_mA_fbk,  &value);
}


int addWrite_TST_mA_fbk(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_mA_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_TST_FWrevision(int value)
{
return writeVarByCtIndex(ID_TST_FWrevision,  &value);
}


int addWrite_TST_FWrevision(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_TST_HWconfig(int value)
{
return writeVarByCtIndex(ID_TST_HWconfig,  &value);
}


int addWrite_TST_HWconfig(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_VAL_Tamb,  &value);
}


int addWrite_VAL_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_RPM,  &value);
}


int addWrite_VAL_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_VCC_set(int16_t value)
{
return writeVarByCtIndex(ID_VAL_VCC_set,  &value);
}


int addWrite_VAL_VCC_set(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_VCC_set, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_VCC_fbk(int16_t value)
{
return writeVarByCtIndex(ID_VAL_VCC_fbk,  &value);
}


int addWrite_VAL_VCC_fbk(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_VCC_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_mA_fbk(int16_t value)
{
return writeVarByCtIndex(ID_VAL_mA_fbk,  &value);
}


int addWrite_VAL_mA_fbk(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_mA_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_FWrevision,  &value);
}


int addWrite_VAL_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_HWconfig,  &value);
}


int addWrite_VAL_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_RES_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_RES_Tamb,  &value);
}


int addWrite_RES_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_RES_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_RES_RPM,  &value);
}


int addWrite_RES_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_RES_VCC_set(int16_t value)
{
return writeVarByCtIndex(ID_RES_VCC_set,  &value);
}


int addWrite_RES_VCC_set(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_VCC_set, &value, NULL, 0) == ERROR);
}


int doWrite_RES_VCC_fbk(int16_t value)
{
return writeVarByCtIndex(ID_RES_VCC_fbk,  &value);
}


int addWrite_RES_VCC_fbk(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_VCC_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_RES_mA_fbk(int16_t value)
{
return writeVarByCtIndex(ID_RES_mA_fbk,  &value);
}


int addWrite_RES_mA_fbk(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_mA_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_RES_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_RES_FWrevision,  &value);
}


int addWrite_RES_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_RES_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_RES_HWconfig,  &value);
}


int addWrite_RES_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_OK_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_OK_Tamb,  &value);
}


int addWrite_OK_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_OK_RPM,  &value);
}


int addWrite_OK_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_OK_VCC_set(int16_t value)
{
return writeVarByCtIndex(ID_OK_VCC_set,  &value);
}


int addWrite_OK_VCC_set(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_VCC_set, &value, NULL, 0) == ERROR);
}


int doWrite_OK_VCC_fbk(int16_t value)
{
return writeVarByCtIndex(ID_OK_VCC_fbk,  &value);
}


int addWrite_OK_VCC_fbk(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_VCC_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_OK_mA_fbk(int16_t value)
{
return writeVarByCtIndex(ID_OK_mA_fbk,  &value);
}


int addWrite_OK_mA_fbk(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_mA_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_OK_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_OK_FWrevision,  &value);
}


int addWrite_OK_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_OK_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_OK_HWconfig,  &value);
}


int addWrite_OK_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_OK_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_TST_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_TST_RTUS_WR,  &value);
}


int addWrite_TST_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_TST_RTUS_RD,  &value);
}


int addWrite_TST_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TST_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_TST_RTU1_WR,  &value);
}


int addWrite_TST_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_TST_RTU1_RD,  &value);
}


int addWrite_TST_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TST_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_TST_RTU3_WR,  &value);
}


int addWrite_TST_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_TST_RTU3_RD,  &value);
}


int addWrite_TST_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TST_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_TST_CAN1_WR,  &value);
}


int addWrite_TST_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_TST_CAN1_RD,  &value);
}


int addWrite_TST_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_VAL_RTUS_WR,  &value);
}


int addWrite_VAL_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_VAL_RTUS_RD,  &value);
}


int addWrite_VAL_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_VAL_RTU1_WR,  &value);
}


int addWrite_VAL_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_VAL_RTU1_RD,  &value);
}


int addWrite_VAL_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_VAL_RTU3_WR,  &value);
}


int addWrite_VAL_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_VAL_RTU3_RD,  &value);
}


int addWrite_VAL_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_VAL_CAN1_WR,  &value);
}


int addWrite_VAL_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_VAL_CAN1_RD,  &value);
}


int addWrite_VAL_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_RES_RTUS_WR,  &value);
}


int addWrite_RES_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_RES_RTUS_RD,  &value);
}


int addWrite_RES_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_RES_RTU1_WR,  &value);
}


int addWrite_RES_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_RES_RTU1_RD,  &value);
}


int addWrite_RES_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_RES_RTU3_WR,  &value);
}


int addWrite_RES_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_RES_RTU3_RD,  &value);
}


int addWrite_RES_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_RES_CAN1_WR,  &value);
}


int addWrite_RES_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_RES_CAN1_RD,  &value);
}


int addWrite_RES_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_OK_RTUS_WR,  &value);
}


int addWrite_OK_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_OK_RTUS_RD,  &value);
}


int addWrite_OK_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_OK_RTU1_WR,  &value);
}


int addWrite_OK_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_OK_RTU1_RD,  &value);
}


int addWrite_OK_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_OK_RTU3_WR,  &value);
}


int addWrite_OK_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_OK_RTU3_RD,  &value);
}


int addWrite_OK_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_OK_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_OK_CAN1_WR,  &value);
}


int addWrite_OK_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_OK_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_OK_CAN1_RD,  &value);
}


int addWrite_OK_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_1(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_1,  &value);
}


int addWrite_PLC_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_2(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_2,  &value);
}


int addWrite_PLC_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_3(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_3,  &value);
}


int addWrite_PLC_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_4(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_4,  &value);
}


int addWrite_PLC_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_5(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_5,  &value);
}


int addWrite_PLC_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_6(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_6,  &value);
}


int addWrite_PLC_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_7(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_7,  &value);
}


int addWrite_PLC_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_8(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_8,  &value);
}


int addWrite_PLC_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_9(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_9,  &value);
}


int addWrite_PLC_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_10(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_10,  &value);
}


int addWrite_PLC_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_11(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_11,  &value);
}


int addWrite_PLC_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_12(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_12,  &value);
}


int addWrite_PLC_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_13(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_13,  &value);
}


int addWrite_PLC_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_14(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_14,  &value);
}


int addWrite_PLC_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_15(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_15,  &value);
}


int addWrite_PLC_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_16(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_16,  &value);
}


int addWrite_PLC_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_1,  &value);
}


int addWrite_PLC_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_2,  &value);
}


int addWrite_PLC_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_PLC_Tamb,  &value);
}


int addWrite_PLC_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_1(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_1,  &value);
}


int addWrite_PLC_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_2(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_2,  &value);
}


int addWrite_PLC_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_3(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_3,  &value);
}


int addWrite_PLC_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_4(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_4,  &value);
}


int addWrite_PLC_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_5(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_5,  &value);
}


int addWrite_PLC_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_6(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_6,  &value);
}


int addWrite_PLC_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_7(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_7,  &value);
}


int addWrite_PLC_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_8(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_8,  &value);
}


int addWrite_PLC_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_9(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_9,  &value);
}


int addWrite_PLC_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_10(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_10,  &value);
}


int addWrite_PLC_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_11(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_11,  &value);
}


int addWrite_PLC_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_12(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_12,  &value);
}


int addWrite_PLC_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_13(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_13,  &value);
}


int addWrite_PLC_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_14(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_14,  &value);
}


int addWrite_PLC_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_15(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_15,  &value);
}


int addWrite_PLC_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_16(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_16,  &value);
}


int addWrite_PLC_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_X(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_X,  &value);
}


int addWrite_PLC_AnOutConf_X(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_X, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_1,  &value);
}


int addWrite_PLC_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_2,  &value);
}


int addWrite_PLC_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_3,  &value);
}


int addWrite_PLC_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_4,  &value);
}


int addWrite_PLC_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_5(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_5,  &value);
}


int addWrite_PLC_AnOut_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_6(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_6,  &value);
}


int addWrite_PLC_AnOut_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_7(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_7,  &value);
}


int addWrite_PLC_AnOut_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_8(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_8,  &value);
}


int addWrite_PLC_AnOut_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_1,  &value);
}


int addWrite_PLC_AnInConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_2,  &value);
}


int addWrite_PLC_AnInConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_HeartBeat(u_int32_t value)
{
return writeVarByCtIndex(ID_PLC_HeartBeat,  &value);
}


int addWrite_PLC_HeartBeat(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_HeartBeat, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_time(float value)
{
return writeVarByCtIndex(ID_PLC_time,  &value);
}


int addWrite_PLC_time(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_time, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_timeMin(float value)
{
return writeVarByCtIndex(ID_PLC_timeMin,  &value);
}


int addWrite_PLC_timeMin(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_timeMin, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_timeMax(float value)
{
return writeVarByCtIndex(ID_PLC_timeMax,  &value);
}


int addWrite_PLC_timeMax(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_timeMax, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_timeWin(float value)
{
return writeVarByCtIndex(ID_PLC_timeWin,  &value);
}


int addWrite_PLC_timeWin(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_timeWin, &value, NULL, 0) == ERROR);
}


int update_all(void)
{
int retval = 0;
retval += readFromDb(ID_PRODUCT_ID, &PRODUCT_ID);
retval += readFromDb(ID_SERIAL_NUMBER, &SERIAL_NUMBER);
retval += readFromDb(ID_TEST_STEP, &TEST_STEP);
retval += readFromDb(ID_TEST_DATE, &TEST_DATE);
retval += readFromDb(ID_TEST_TIME, &TEST_TIME);
retval += readFromDb(ID_TEST_DURATION, &TEST_DURATION);
retval += readFromDb(ID_GO, &GO);
retval += readFromDb(ID_RESET, &RESET);
retval += readFromDb(ID_START, &START);
retval += readFromDb(ID_STOP, &STOP);
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
retval += readFromDb(ID_OK_DigIn_1, &OK_DigIn_1);
retval += readFromDb(ID_OK_DigIn_2, &OK_DigIn_2);
retval += readFromDb(ID_OK_DigIn_3, &OK_DigIn_3);
retval += readFromDb(ID_OK_DigIn_4, &OK_DigIn_4);
retval += readFromDb(ID_OK_DigIn_5, &OK_DigIn_5);
retval += readFromDb(ID_OK_DigIn_6, &OK_DigIn_6);
retval += readFromDb(ID_OK_DigIn_7, &OK_DigIn_7);
retval += readFromDb(ID_OK_DigIn_8, &OK_DigIn_8);
retval += readFromDb(ID_OK_DigIn_9, &OK_DigIn_9);
retval += readFromDb(ID_OK_DigIn_10, &OK_DigIn_10);
retval += readFromDb(ID_OK_DigIn_11, &OK_DigIn_11);
retval += readFromDb(ID_OK_DigIn_12, &OK_DigIn_12);
retval += readFromDb(ID_OK_DigIn_13, &OK_DigIn_13);
retval += readFromDb(ID_OK_DigIn_14, &OK_DigIn_14);
retval += readFromDb(ID_OK_DigIn_15, &OK_DigIn_15);
retval += readFromDb(ID_OK_DigIn_16, &OK_DigIn_16);
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
retval += readFromDb(ID_RES_DigOut_1, &RES_DigOut_1);
retval += readFromDb(ID_RES_DigOut_2, &RES_DigOut_2);
retval += readFromDb(ID_RES_DigOut_3, &RES_DigOut_3);
retval += readFromDb(ID_RES_DigOut_4, &RES_DigOut_4);
retval += readFromDb(ID_RES_DigOut_5, &RES_DigOut_5);
retval += readFromDb(ID_RES_DigOut_6, &RES_DigOut_6);
retval += readFromDb(ID_RES_DigOut_7, &RES_DigOut_7);
retval += readFromDb(ID_RES_DigOut_8, &RES_DigOut_8);
retval += readFromDb(ID_RES_DigOut_9, &RES_DigOut_9);
retval += readFromDb(ID_RES_DigOut_10, &RES_DigOut_10);
retval += readFromDb(ID_RES_DigOut_11, &RES_DigOut_11);
retval += readFromDb(ID_RES_DigOut_12, &RES_DigOut_12);
retval += readFromDb(ID_RES_DigOut_13, &RES_DigOut_13);
retval += readFromDb(ID_RES_DigOut_14, &RES_DigOut_14);
retval += readFromDb(ID_RES_DigOut_15, &RES_DigOut_15);
retval += readFromDb(ID_RES_DigOut_16, &RES_DigOut_16);
retval += readFromDb(ID_OK_DigOut_1, &OK_DigOut_1);
retval += readFromDb(ID_OK_DigOut_2, &OK_DigOut_2);
retval += readFromDb(ID_OK_DigOut_3, &OK_DigOut_3);
retval += readFromDb(ID_OK_DigOut_4, &OK_DigOut_4);
retval += readFromDb(ID_OK_DigOut_5, &OK_DigOut_5);
retval += readFromDb(ID_OK_DigOut_6, &OK_DigOut_6);
retval += readFromDb(ID_OK_DigOut_7, &OK_DigOut_7);
retval += readFromDb(ID_OK_DigOut_8, &OK_DigOut_8);
retval += readFromDb(ID_OK_DigOut_9, &OK_DigOut_9);
retval += readFromDb(ID_OK_DigOut_10, &OK_DigOut_10);
retval += readFromDb(ID_OK_DigOut_11, &OK_DigOut_11);
retval += readFromDb(ID_OK_DigOut_12, &OK_DigOut_12);
retval += readFromDb(ID_OK_DigOut_13, &OK_DigOut_13);
retval += readFromDb(ID_OK_DigOut_14, &OK_DigOut_14);
retval += readFromDb(ID_OK_DigOut_15, &OK_DigOut_15);
retval += readFromDb(ID_OK_DigOut_16, &OK_DigOut_16);
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
retval += readFromDb(ID_OK_AnIn_1, &OK_AnIn_1);
retval += readFromDb(ID_OK_AnIn_2, &OK_AnIn_2);
retval += readFromDb(ID_OK_AnIn_3, &OK_AnIn_3);
retval += readFromDb(ID_OK_AnIn_4, &OK_AnIn_4);
retval += readFromDb(ID_OK_AnIn_5, &OK_AnIn_5);
retval += readFromDb(ID_OK_AnIn_6, &OK_AnIn_6);
retval += readFromDb(ID_OK_AnIn_7, &OK_AnIn_7);
retval += readFromDb(ID_OK_AnIn_8, &OK_AnIn_8);
retval += readFromDb(ID_OK_AnIn_9, &OK_AnIn_9);
retval += readFromDb(ID_OK_AnIn_10, &OK_AnIn_10);
retval += readFromDb(ID_OK_AnIn_11, &OK_AnIn_11);
retval += readFromDb(ID_OK_AnIn_12, &OK_AnIn_12);
retval += readFromDb(ID_TST_AnOut_1, &TST_AnOut_1);
retval += readFromDb(ID_TST_AnOut_2, &TST_AnOut_2);
retval += readFromDb(ID_TST_AnOut_3, &TST_AnOut_3);
retval += readFromDb(ID_TST_AnOut_4, &TST_AnOut_4);
retval += readFromDb(ID_TST_AnOut_5, &TST_AnOut_5);
retval += readFromDb(ID_TST_AnOut_6, &TST_AnOut_6);
retval += readFromDb(ID_TST_AnOut_7, &TST_AnOut_7);
retval += readFromDb(ID_TST_AnOut_8, &TST_AnOut_8);
retval += readFromDb(ID_VAL_AnOut_1, &VAL_AnOut_1);
retval += readFromDb(ID_VAL_AnOut_2, &VAL_AnOut_2);
retval += readFromDb(ID_VAL_AnOut_3, &VAL_AnOut_3);
retval += readFromDb(ID_VAL_AnOut_4, &VAL_AnOut_4);
retval += readFromDb(ID_VAL_AnOut_5, &VAL_AnOut_5);
retval += readFromDb(ID_VAL_AnOut_6, &VAL_AnOut_6);
retval += readFromDb(ID_VAL_AnOut_7, &VAL_AnOut_7);
retval += readFromDb(ID_VAL_AnOut_8, &VAL_AnOut_8);
retval += readFromDb(ID_VAL_AnOutConf_1, &VAL_AnOutConf_1);
retval += readFromDb(ID_VAL_AnOutConf_2, &VAL_AnOutConf_2);
retval += readFromDb(ID_VAL_AnOutConf_3, &VAL_AnOutConf_3);
retval += readFromDb(ID_VAL_AnOutConf_4, &VAL_AnOutConf_4);
retval += readFromDb(ID_VAL_AnOutConf_5, &VAL_AnOutConf_5);
retval += readFromDb(ID_VAL_AnOutConf_6, &VAL_AnOutConf_6);
retval += readFromDb(ID_VAL_AnOutConf_7, &VAL_AnOutConf_7);
retval += readFromDb(ID_VAL_AnOutConf_8, &VAL_AnOutConf_8);
retval += readFromDb(ID_RES_AnOut_1, &RES_AnOut_1);
retval += readFromDb(ID_RES_AnOut_2, &RES_AnOut_2);
retval += readFromDb(ID_RES_AnOut_3, &RES_AnOut_3);
retval += readFromDb(ID_RES_AnOut_4, &RES_AnOut_4);
retval += readFromDb(ID_RES_AnOut_5, &RES_AnOut_5);
retval += readFromDb(ID_RES_AnOut_6, &RES_AnOut_6);
retval += readFromDb(ID_RES_AnOut_7, &RES_AnOut_7);
retval += readFromDb(ID_RES_AnOut_8, &RES_AnOut_8);
retval += readFromDb(ID_OK_AnOut_1, &OK_AnOut_1);
retval += readFromDb(ID_OK_AnOut_2, &OK_AnOut_2);
retval += readFromDb(ID_OK_AnOut_3, &OK_AnOut_3);
retval += readFromDb(ID_OK_AnOut_4, &OK_AnOut_4);
retval += readFromDb(ID_OK_AnOut_5, &OK_AnOut_5);
retval += readFromDb(ID_OK_AnOut_6, &OK_AnOut_6);
retval += readFromDb(ID_OK_AnOut_7, &OK_AnOut_7);
retval += readFromDb(ID_OK_AnOut_8, &OK_AnOut_8);
retval += readFromDb(ID_TST_Tamb, &TST_Tamb);
retval += readFromDb(ID_TST_RPM, &TST_RPM);
retval += readFromDb(ID_TST_VCC_set, &TST_VCC_set);
retval += readFromDb(ID_TST_VCC_fbk, &TST_VCC_fbk);
retval += readFromDb(ID_TST_mA_fbk, &TST_mA_fbk);
retval += readFromDb(ID_TST_FWrevision, &TST_FWrevision);
retval += readFromDb(ID_TST_HWconfig, &TST_HWconfig);
retval += readFromDb(ID_VAL_Tamb, &VAL_Tamb);
retval += readFromDb(ID_VAL_RPM, &VAL_RPM);
retval += readFromDb(ID_VAL_VCC_set, &VAL_VCC_set);
retval += readFromDb(ID_VAL_VCC_fbk, &VAL_VCC_fbk);
retval += readFromDb(ID_VAL_mA_fbk, &VAL_mA_fbk);
retval += readFromDb(ID_VAL_FWrevision, &VAL_FWrevision);
retval += readFromDb(ID_VAL_HWconfig, &VAL_HWconfig);
retval += readFromDb(ID_RES_Tamb, &RES_Tamb);
retval += readFromDb(ID_RES_RPM, &RES_RPM);
retval += readFromDb(ID_RES_VCC_set, &RES_VCC_set);
retval += readFromDb(ID_RES_VCC_fbk, &RES_VCC_fbk);
retval += readFromDb(ID_RES_mA_fbk, &RES_mA_fbk);
retval += readFromDb(ID_RES_FWrevision, &RES_FWrevision);
retval += readFromDb(ID_RES_HWconfig, &RES_HWconfig);
retval += readFromDb(ID_OK_Tamb, &OK_Tamb);
retval += readFromDb(ID_OK_RPM, &OK_RPM);
retval += readFromDb(ID_OK_VCC_set, &OK_VCC_set);
retval += readFromDb(ID_OK_VCC_fbk, &OK_VCC_fbk);
retval += readFromDb(ID_OK_mA_fbk, &OK_mA_fbk);
retval += readFromDb(ID_OK_FWrevision, &OK_FWrevision);
retval += readFromDb(ID_OK_HWconfig, &OK_HWconfig);
retval += readFromDb(ID_TST_RTUS_WR, &TST_RTUS_WR);
retval += readFromDb(ID_TST_RTUS_RD, &TST_RTUS_RD);
retval += readFromDb(ID_TST_RTU1_WR, &TST_RTU1_WR);
retval += readFromDb(ID_TST_RTU1_RD, &TST_RTU1_RD);
retval += readFromDb(ID_TST_RTU3_WR, &TST_RTU3_WR);
retval += readFromDb(ID_TST_RTU3_RD, &TST_RTU3_RD);
retval += readFromDb(ID_TST_CAN1_WR, &TST_CAN1_WR);
retval += readFromDb(ID_TST_CAN1_RD, &TST_CAN1_RD);
retval += readFromDb(ID_VAL_RTUS_WR, &VAL_RTUS_WR);
retval += readFromDb(ID_VAL_RTUS_RD, &VAL_RTUS_RD);
retval += readFromDb(ID_VAL_RTU1_WR, &VAL_RTU1_WR);
retval += readFromDb(ID_VAL_RTU1_RD, &VAL_RTU1_RD);
retval += readFromDb(ID_VAL_RTU3_WR, &VAL_RTU3_WR);
retval += readFromDb(ID_VAL_RTU3_RD, &VAL_RTU3_RD);
retval += readFromDb(ID_VAL_CAN1_WR, &VAL_CAN1_WR);
retval += readFromDb(ID_VAL_CAN1_RD, &VAL_CAN1_RD);
retval += readFromDb(ID_RES_RTUS_WR, &RES_RTUS_WR);
retval += readFromDb(ID_RES_RTUS_RD, &RES_RTUS_RD);
retval += readFromDb(ID_RES_RTU1_WR, &RES_RTU1_WR);
retval += readFromDb(ID_RES_RTU1_RD, &RES_RTU1_RD);
retval += readFromDb(ID_RES_RTU3_WR, &RES_RTU3_WR);
retval += readFromDb(ID_RES_RTU3_RD, &RES_RTU3_RD);
retval += readFromDb(ID_RES_CAN1_WR, &RES_CAN1_WR);
retval += readFromDb(ID_RES_CAN1_RD, &RES_CAN1_RD);
retval += readFromDb(ID_OK_RTUS_WR, &OK_RTUS_WR);
retval += readFromDb(ID_OK_RTUS_RD, &OK_RTUS_RD);
retval += readFromDb(ID_OK_RTU1_WR, &OK_RTU1_WR);
retval += readFromDb(ID_OK_RTU1_RD, &OK_RTU1_RD);
retval += readFromDb(ID_OK_RTU3_WR, &OK_RTU3_WR);
retval += readFromDb(ID_OK_RTU3_RD, &OK_RTU3_RD);
retval += readFromDb(ID_OK_CAN1_WR, &OK_CAN1_WR);
retval += readFromDb(ID_OK_CAN1_RD, &OK_CAN1_RD);
retval += readFromDb(ID_PLC_DigIn_1, &PLC_DigIn_1);
retval += readFromDb(ID_PLC_DigIn_2, &PLC_DigIn_2);
retval += readFromDb(ID_PLC_DigIn_3, &PLC_DigIn_3);
retval += readFromDb(ID_PLC_DigIn_4, &PLC_DigIn_4);
retval += readFromDb(ID_PLC_DigIn_5, &PLC_DigIn_5);
retval += readFromDb(ID_PLC_DigIn_6, &PLC_DigIn_6);
retval += readFromDb(ID_PLC_DigIn_7, &PLC_DigIn_7);
retval += readFromDb(ID_PLC_DigIn_8, &PLC_DigIn_8);
retval += readFromDb(ID_PLC_DigIn_9, &PLC_DigIn_9);
retval += readFromDb(ID_PLC_DigIn_10, &PLC_DigIn_10);
retval += readFromDb(ID_PLC_DigIn_11, &PLC_DigIn_11);
retval += readFromDb(ID_PLC_DigIn_12, &PLC_DigIn_12);
retval += readFromDb(ID_PLC_DigIn_13, &PLC_DigIn_13);
retval += readFromDb(ID_PLC_DigIn_14, &PLC_DigIn_14);
retval += readFromDb(ID_PLC_DigIn_15, &PLC_DigIn_15);
retval += readFromDb(ID_PLC_DigIn_16, &PLC_DigIn_16);
retval += readFromDb(ID_PLC_AnIn_1, &PLC_AnIn_1);
retval += readFromDb(ID_PLC_AnIn_2, &PLC_AnIn_2);
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
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
retval += readFromDb(ID_PLC_DigOut_13, &PLC_DigOut_13);
retval += readFromDb(ID_PLC_DigOut_14, &PLC_DigOut_14);
retval += readFromDb(ID_PLC_DigOut_15, &PLC_DigOut_15);
retval += readFromDb(ID_PLC_DigOut_16, &PLC_DigOut_16);
retval += readFromDb(ID_PLC_AnOutConf_X, &PLC_AnOutConf_X);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_AnOut_2, &PLC_AnOut_2);
retval += readFromDb(ID_PLC_AnOut_3, &PLC_AnOut_3);
retval += readFromDb(ID_PLC_AnOut_4, &PLC_AnOut_4);
retval += readFromDb(ID_PLC_AnOut_5, &PLC_AnOut_5);
retval += readFromDb(ID_PLC_AnOut_6, &PLC_AnOut_6);
retval += readFromDb(ID_PLC_AnOut_7, &PLC_AnOut_7);
retval += readFromDb(ID_PLC_AnOut_8, &PLC_AnOut_8);
retval += readFromDb(ID_PLC_AnInConf_1, &PLC_AnInConf_1);
retval += readFromDb(ID_PLC_AnInConf_2, &PLC_AnInConf_2);
retval += readFromDb(ID_PLC_HeartBeat, &PLC_HeartBeat);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
return retval;
}
