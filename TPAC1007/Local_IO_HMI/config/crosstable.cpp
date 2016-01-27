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
 
int START_REMOTE = 0;
int START_TEST = 0;
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
int STATUS_LOCAL = 0;
int STATUS_REMOTE = 0;
int STATUS_DONE = 0;
u_int16_t PLC_FWrevision = 0;
u_int16_t PLC_HWconfig = 0;
int PLC_DigDir_1 = 0;
int PLC_DigDir_2 = 0;
int PLC_DigDir_3 = 0;
int PLC_DigDir_4 = 0;
int PLC_DigDir_5 = 0;
int PLC_DigDir_6 = 0;
int PLC_DigDir_7 = 0;
int PLC_DigDir_8 = 0;
u_int16_t PLC_AnInConf_1 = 0;
u_int16_t PLC_AnInConf_2 = 0;
u_int16_t PLC_AnOutConf_1 = 0;
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
int16_t PLC_AnIn_1 = 0;
int16_t PLC_AnIn_2 = 0;
int16_t PLC_Tamb = 0;
u_int32_t PLC_Encoder = 0;
int PLC_DigOut_1 = 0;
int PLC_DigOut_2 = 0;
int PLC_DigOut_3 = 0;
int PLC_DigOut_4 = 0;
int PLC_DigOut_5 = 0;
int PLC_DigOut_6 = 0;
int PLC_DigOut_7 = 0;
int PLC_DigOut_8 = 0;
int16_t PLC_AnOut_1 = 0;
u_int16_t PLC_EncEnable = 0;
u_int16_t PLC_EncoderReset = 0;
u_int16_t PLC_Reserved_16 = 0;
u_int16_t PLC_Reserved_17 = 0;
u_int16_t PLC_Reserved_18 = 0;
u_int16_t PLC_Reserved_19 = 0;
u_int16_t PLC_Heartbeat = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;


int doWrite_START_REMOTE(int value)
{
return doWrite(ID_START_REMOTE,  &value);
}


int addWrite_START_REMOTE(int value)
{
return addWrite(ID_START_REMOTE, &value);
}


int getStatus_START_REMOTE()
{
return getStatus(ID_START_REMOTE);
}


int doWrite_START_TEST(int value)
{
return doWrite(ID_START_TEST,  &value);
}


int addWrite_START_TEST(int value)
{
return addWrite(ID_START_TEST, &value);
}


int getStatus_START_TEST()
{
return getStatus(ID_START_TEST);
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


int doWrite_RES_DigOut_1(int value)
{
return doWrite(ID_RES_DigOut_1,  &value);
}


int addWrite_RES_DigOut_1(int value)
{
return addWrite(ID_RES_DigOut_1, &value);
}


int getStatus_RES_DigOut_1()
{
return getStatus(ID_RES_DigOut_1);
}


int doWrite_RES_DigOut_2(int value)
{
return doWrite(ID_RES_DigOut_2,  &value);
}


int addWrite_RES_DigOut_2(int value)
{
return addWrite(ID_RES_DigOut_2, &value);
}


int getStatus_RES_DigOut_2()
{
return getStatus(ID_RES_DigOut_2);
}


int doWrite_RES_DigOut_3(int value)
{
return doWrite(ID_RES_DigOut_3,  &value);
}


int addWrite_RES_DigOut_3(int value)
{
return addWrite(ID_RES_DigOut_3, &value);
}


int getStatus_RES_DigOut_3()
{
return getStatus(ID_RES_DigOut_3);
}


int doWrite_RES_DigOut_4(int value)
{
return doWrite(ID_RES_DigOut_4,  &value);
}


int addWrite_RES_DigOut_4(int value)
{
return addWrite(ID_RES_DigOut_4, &value);
}


int getStatus_RES_DigOut_4()
{
return getStatus(ID_RES_DigOut_4);
}


int doWrite_RES_DigOut_5(int value)
{
return doWrite(ID_RES_DigOut_5,  &value);
}


int addWrite_RES_DigOut_5(int value)
{
return addWrite(ID_RES_DigOut_5, &value);
}


int getStatus_RES_DigOut_5()
{
return getStatus(ID_RES_DigOut_5);
}


int doWrite_RES_DigOut_6(int value)
{
return doWrite(ID_RES_DigOut_6,  &value);
}


int addWrite_RES_DigOut_6(int value)
{
return addWrite(ID_RES_DigOut_6, &value);
}


int getStatus_RES_DigOut_6()
{
return getStatus(ID_RES_DigOut_6);
}


int doWrite_RES_DigOut_7(int value)
{
return doWrite(ID_RES_DigOut_7,  &value);
}


int addWrite_RES_DigOut_7(int value)
{
return addWrite(ID_RES_DigOut_7, &value);
}


int getStatus_RES_DigOut_7()
{
return getStatus(ID_RES_DigOut_7);
}


int doWrite_RES_DigOut_8(int value)
{
return doWrite(ID_RES_DigOut_8,  &value);
}


int addWrite_RES_DigOut_8(int value)
{
return addWrite(ID_RES_DigOut_8, &value);
}


int getStatus_RES_DigOut_8()
{
return getStatus(ID_RES_DigOut_8);
}


int doWrite_RES_DigOut_9(int value)
{
return doWrite(ID_RES_DigOut_9,  &value);
}


int addWrite_RES_DigOut_9(int value)
{
return addWrite(ID_RES_DigOut_9, &value);
}


int getStatus_RES_DigOut_9()
{
return getStatus(ID_RES_DigOut_9);
}


int doWrite_RES_DigOut_10(int value)
{
return doWrite(ID_RES_DigOut_10,  &value);
}


int addWrite_RES_DigOut_10(int value)
{
return addWrite(ID_RES_DigOut_10, &value);
}


int getStatus_RES_DigOut_10()
{
return getStatus(ID_RES_DigOut_10);
}


int doWrite_RES_DigOut_11(int value)
{
return doWrite(ID_RES_DigOut_11,  &value);
}


int addWrite_RES_DigOut_11(int value)
{
return addWrite(ID_RES_DigOut_11, &value);
}


int getStatus_RES_DigOut_11()
{
return getStatus(ID_RES_DigOut_11);
}


int doWrite_RES_DigOut_12(int value)
{
return doWrite(ID_RES_DigOut_12,  &value);
}


int addWrite_RES_DigOut_12(int value)
{
return addWrite(ID_RES_DigOut_12, &value);
}


int getStatus_RES_DigOut_12()
{
return getStatus(ID_RES_DigOut_12);
}


int doWrite_RES_DigOut_13(int value)
{
return doWrite(ID_RES_DigOut_13,  &value);
}


int addWrite_RES_DigOut_13(int value)
{
return addWrite(ID_RES_DigOut_13, &value);
}


int getStatus_RES_DigOut_13()
{
return getStatus(ID_RES_DigOut_13);
}


int doWrite_RES_DigOut_14(int value)
{
return doWrite(ID_RES_DigOut_14,  &value);
}


int addWrite_RES_DigOut_14(int value)
{
return addWrite(ID_RES_DigOut_14, &value);
}


int getStatus_RES_DigOut_14()
{
return getStatus(ID_RES_DigOut_14);
}


int doWrite_RES_DigOut_15(int value)
{
return doWrite(ID_RES_DigOut_15,  &value);
}


int addWrite_RES_DigOut_15(int value)
{
return addWrite(ID_RES_DigOut_15, &value);
}


int getStatus_RES_DigOut_15()
{
return getStatus(ID_RES_DigOut_15);
}


int doWrite_RES_DigOut_16(int value)
{
return doWrite(ID_RES_DigOut_16,  &value);
}


int addWrite_RES_DigOut_16(int value)
{
return addWrite(ID_RES_DigOut_16, &value);
}


int getStatus_RES_DigOut_16()
{
return getStatus(ID_RES_DigOut_16);
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


int doWrite_STATUS_LOCAL(int value)
{
return doWrite(ID_STATUS_LOCAL,  &value);
}


int addWrite_STATUS_LOCAL(int value)
{
return addWrite(ID_STATUS_LOCAL, &value);
}


int getStatus_STATUS_LOCAL()
{
return getStatus(ID_STATUS_LOCAL);
}


int doWrite_STATUS_REMOTE(int value)
{
return doWrite(ID_STATUS_REMOTE,  &value);
}


int addWrite_STATUS_REMOTE(int value)
{
return addWrite(ID_STATUS_REMOTE, &value);
}


int getStatus_STATUS_REMOTE()
{
return getStatus(ID_STATUS_REMOTE);
}


int doWrite_STATUS_DONE(int value)
{
return doWrite(ID_STATUS_DONE,  &value);
}


int addWrite_STATUS_DONE(int value)
{
return addWrite(ID_STATUS_DONE, &value);
}


int getStatus_STATUS_DONE()
{
return getStatus(ID_STATUS_DONE);
}


int doWrite_PLC_FWrevision(u_int16_t value)
{
return doWrite(ID_PLC_FWrevision,  &value);
}


int addWrite_PLC_FWrevision(u_int16_t value)
{
return addWrite(ID_PLC_FWrevision, &value);
}


int getStatus_PLC_FWrevision()
{
return getStatus(ID_PLC_FWrevision);
}


int doWrite_PLC_HWconfig(u_int16_t value)
{
return doWrite(ID_PLC_HWconfig,  &value);
}


int addWrite_PLC_HWconfig(u_int16_t value)
{
return addWrite(ID_PLC_HWconfig, &value);
}


int getStatus_PLC_HWconfig()
{
return getStatus(ID_PLC_HWconfig);
}


int doWrite_PLC_DigDir_1(int value)
{
return doWrite(ID_PLC_DigDir_1,  &value);
}


int addWrite_PLC_DigDir_1(int value)
{
return addWrite(ID_PLC_DigDir_1, &value);
}


int getStatus_PLC_DigDir_1()
{
return getStatus(ID_PLC_DigDir_1);
}


int doWrite_PLC_DigDir_2(int value)
{
return doWrite(ID_PLC_DigDir_2,  &value);
}


int addWrite_PLC_DigDir_2(int value)
{
return addWrite(ID_PLC_DigDir_2, &value);
}


int getStatus_PLC_DigDir_2()
{
return getStatus(ID_PLC_DigDir_2);
}


int doWrite_PLC_DigDir_3(int value)
{
return doWrite(ID_PLC_DigDir_3,  &value);
}


int addWrite_PLC_DigDir_3(int value)
{
return addWrite(ID_PLC_DigDir_3, &value);
}


int getStatus_PLC_DigDir_3()
{
return getStatus(ID_PLC_DigDir_3);
}


int doWrite_PLC_DigDir_4(int value)
{
return doWrite(ID_PLC_DigDir_4,  &value);
}


int addWrite_PLC_DigDir_4(int value)
{
return addWrite(ID_PLC_DigDir_4, &value);
}


int getStatus_PLC_DigDir_4()
{
return getStatus(ID_PLC_DigDir_4);
}


int doWrite_PLC_DigDir_5(int value)
{
return doWrite(ID_PLC_DigDir_5,  &value);
}


int addWrite_PLC_DigDir_5(int value)
{
return addWrite(ID_PLC_DigDir_5, &value);
}


int getStatus_PLC_DigDir_5()
{
return getStatus(ID_PLC_DigDir_5);
}


int doWrite_PLC_DigDir_6(int value)
{
return doWrite(ID_PLC_DigDir_6,  &value);
}


int addWrite_PLC_DigDir_6(int value)
{
return addWrite(ID_PLC_DigDir_6, &value);
}


int getStatus_PLC_DigDir_6()
{
return getStatus(ID_PLC_DigDir_6);
}


int doWrite_PLC_DigDir_7(int value)
{
return doWrite(ID_PLC_DigDir_7,  &value);
}


int addWrite_PLC_DigDir_7(int value)
{
return addWrite(ID_PLC_DigDir_7, &value);
}


int getStatus_PLC_DigDir_7()
{
return getStatus(ID_PLC_DigDir_7);
}


int doWrite_PLC_DigDir_8(int value)
{
return doWrite(ID_PLC_DigDir_8,  &value);
}


int addWrite_PLC_DigDir_8(int value)
{
return addWrite(ID_PLC_DigDir_8, &value);
}


int getStatus_PLC_DigDir_8()
{
return getStatus(ID_PLC_DigDir_8);
}


int doWrite_PLC_AnInConf_1(u_int16_t value)
{
return doWrite(ID_PLC_AnInConf_1,  &value);
}


int addWrite_PLC_AnInConf_1(u_int16_t value)
{
return addWrite(ID_PLC_AnInConf_1, &value);
}


int getStatus_PLC_AnInConf_1()
{
return getStatus(ID_PLC_AnInConf_1);
}


int doWrite_PLC_AnInConf_2(u_int16_t value)
{
return doWrite(ID_PLC_AnInConf_2,  &value);
}


int addWrite_PLC_AnInConf_2(u_int16_t value)
{
return addWrite(ID_PLC_AnInConf_2, &value);
}


int getStatus_PLC_AnInConf_2()
{
return getStatus(ID_PLC_AnInConf_2);
}


int doWrite_PLC_AnOutConf_1(u_int16_t value)
{
return doWrite(ID_PLC_AnOutConf_1,  &value);
}


int addWrite_PLC_AnOutConf_1(u_int16_t value)
{
return addWrite(ID_PLC_AnOutConf_1, &value);
}


int getStatus_PLC_AnOutConf_1()
{
return getStatus(ID_PLC_AnOutConf_1);
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


int doWrite_PLC_DigIn_10(int value)
{
return doWrite(ID_PLC_DigIn_10,  &value);
}


int addWrite_PLC_DigIn_10(int value)
{
return addWrite(ID_PLC_DigIn_10, &value);
}


int getStatus_PLC_DigIn_10()
{
return getStatus(ID_PLC_DigIn_10);
}


int doWrite_PLC_DigIn_11(int value)
{
return doWrite(ID_PLC_DigIn_11,  &value);
}


int addWrite_PLC_DigIn_11(int value)
{
return addWrite(ID_PLC_DigIn_11, &value);
}


int getStatus_PLC_DigIn_11()
{
return getStatus(ID_PLC_DigIn_11);
}


int doWrite_PLC_DigIn_12(int value)
{
return doWrite(ID_PLC_DigIn_12,  &value);
}


int addWrite_PLC_DigIn_12(int value)
{
return addWrite(ID_PLC_DigIn_12, &value);
}


int getStatus_PLC_DigIn_12()
{
return getStatus(ID_PLC_DigIn_12);
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


int doWrite_PLC_Encoder(u_int32_t value)
{
return doWrite(ID_PLC_Encoder,  &value);
}


int addWrite_PLC_Encoder(u_int32_t value)
{
return addWrite(ID_PLC_Encoder, &value);
}


int getStatus_PLC_Encoder()
{
return getStatus(ID_PLC_Encoder);
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


int doWrite_PLC_EncEnable(u_int16_t value)
{
return doWrite(ID_PLC_EncEnable,  &value);
}


int addWrite_PLC_EncEnable(u_int16_t value)
{
return addWrite(ID_PLC_EncEnable, &value);
}


int getStatus_PLC_EncEnable()
{
return getStatus(ID_PLC_EncEnable);
}


int doWrite_PLC_EncoderReset(u_int16_t value)
{
return doWrite(ID_PLC_EncoderReset,  &value);
}


int addWrite_PLC_EncoderReset(u_int16_t value)
{
return addWrite(ID_PLC_EncoderReset, &value);
}


int getStatus_PLC_EncoderReset()
{
return getStatus(ID_PLC_EncoderReset);
}


int doWrite_PLC_Reserved_16(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_16,  &value);
}


int addWrite_PLC_Reserved_16(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_16, &value);
}


int getStatus_PLC_Reserved_16()
{
return getStatus(ID_PLC_Reserved_16);
}


int doWrite_PLC_Reserved_17(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_17,  &value);
}


int addWrite_PLC_Reserved_17(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_17, &value);
}


int getStatus_PLC_Reserved_17()
{
return getStatus(ID_PLC_Reserved_17);
}


int doWrite_PLC_Reserved_18(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_18,  &value);
}


int addWrite_PLC_Reserved_18(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_18, &value);
}


int getStatus_PLC_Reserved_18()
{
return getStatus(ID_PLC_Reserved_18);
}


int doWrite_PLC_Reserved_19(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_19,  &value);
}


int addWrite_PLC_Reserved_19(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_19, &value);
}


int getStatus_PLC_Reserved_19()
{
return getStatus(ID_PLC_Reserved_19);
}


int doWrite_PLC_Heartbeat(u_int16_t value)
{
return doWrite(ID_PLC_Heartbeat,  &value);
}


int addWrite_PLC_Heartbeat(u_int16_t value)
{
return addWrite(ID_PLC_Heartbeat, &value);
}


int getStatus_PLC_Heartbeat()
{
return getStatus(ID_PLC_Heartbeat);
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


int update_all(void)
{
int retval = 0;
retval += readFromDb(ID_START_REMOTE, &START_REMOTE);
retval += readFromDb(ID_START_TEST, &START_TEST);
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
retval += readFromDb(ID_STATUS_LOCAL, &STATUS_LOCAL);
retval += readFromDb(ID_STATUS_REMOTE, &STATUS_REMOTE);
retval += readFromDb(ID_STATUS_DONE, &STATUS_DONE);
retval += readFromDb(ID_PLC_FWrevision, &PLC_FWrevision);
retval += readFromDb(ID_PLC_HWconfig, &PLC_HWconfig);
retval += readFromDb(ID_PLC_DigDir_1, &PLC_DigDir_1);
retval += readFromDb(ID_PLC_DigDir_2, &PLC_DigDir_2);
retval += readFromDb(ID_PLC_DigDir_3, &PLC_DigDir_3);
retval += readFromDb(ID_PLC_DigDir_4, &PLC_DigDir_4);
retval += readFromDb(ID_PLC_DigDir_5, &PLC_DigDir_5);
retval += readFromDb(ID_PLC_DigDir_6, &PLC_DigDir_6);
retval += readFromDb(ID_PLC_DigDir_7, &PLC_DigDir_7);
retval += readFromDb(ID_PLC_DigDir_8, &PLC_DigDir_8);
retval += readFromDb(ID_PLC_AnInConf_1, &PLC_AnInConf_1);
retval += readFromDb(ID_PLC_AnInConf_2, &PLC_AnInConf_2);
retval += readFromDb(ID_PLC_AnOutConf_1, &PLC_AnOutConf_1);
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
retval += readFromDb(ID_PLC_AnIn_1, &PLC_AnIn_1);
retval += readFromDb(ID_PLC_AnIn_2, &PLC_AnIn_2);
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
retval += readFromDb(ID_PLC_Encoder, &PLC_Encoder);
retval += readFromDb(ID_PLC_DigOut_1, &PLC_DigOut_1);
retval += readFromDb(ID_PLC_DigOut_2, &PLC_DigOut_2);
retval += readFromDb(ID_PLC_DigOut_3, &PLC_DigOut_3);
retval += readFromDb(ID_PLC_DigOut_4, &PLC_DigOut_4);
retval += readFromDb(ID_PLC_DigOut_5, &PLC_DigOut_5);
retval += readFromDb(ID_PLC_DigOut_6, &PLC_DigOut_6);
retval += readFromDb(ID_PLC_DigOut_7, &PLC_DigOut_7);
retval += readFromDb(ID_PLC_DigOut_8, &PLC_DigOut_8);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_EncEnable, &PLC_EncEnable);
retval += readFromDb(ID_PLC_EncoderReset, &PLC_EncoderReset);
retval += readFromDb(ID_PLC_Reserved_16, &PLC_Reserved_16);
retval += readFromDb(ID_PLC_Reserved_17, &PLC_Reserved_17);
retval += readFromDb(ID_PLC_Reserved_18, &PLC_Reserved_18);
retval += readFromDb(ID_PLC_Reserved_19, &PLC_Reserved_19);
retval += readFromDb(ID_PLC_Heartbeat, &PLC_Heartbeat);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
return retval;
}
