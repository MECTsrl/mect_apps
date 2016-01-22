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
#include "automation.h"
 
u_int32_t PRODUCT_ID = 0;
u_int32_t SERIAL_NUMBER = 0;
u_int32_t TEST_STEP = 0;
u_int32_t TEST_DATE = 0;
u_int32_t TEST_TIME = 0;
u_int32_t TEST_DURATION = 0;
int DO_REMOTE = 0;
int DO_TEST = 0;
u_int16_t STATUS = 0;
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
int OK_AnIn_1 = 0;
int OK_AnIn_2 = 0;
int OK_AnIn_3 = 0;
int OK_AnIn_4 = 0;
int OK_AnIn_5 = 0;
int OK_AnIn_6 = 0;
int OK_AnIn_7 = 0;
int OK_AnIn_8 = 0;
int OK_AnIn_9 = 0;
int OK_AnIn_10 = 0;
int OK_AnIn_11 = 0;
int OK_AnIn_12 = 0;
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
int16_t RES_AnOut_1 = 0;
int16_t RES_AnOut_2 = 0;
int16_t RES_AnOut_3 = 0;
int16_t RES_AnOut_4 = 0;
int16_t RES_AnOutStts_1 = 0;
int16_t RES_AnOutStts_2 = 0;
int16_t RES_AnOutStts_3 = 0;
int16_t RES_AnOutStts_4 = 0;
int OK_AnOut_1 = 0;
int OK_AnOut_2 = 0;
int OK_AnOut_3 = 0;
int OK_AnOut_4 = 0;
int TST_Tamb = 0;
int TST_RPM = 0;
int TST_VCC_set = 0;
int TST_mA_max = 0;
int TST_VCC_fbk = 0;
int TST_mA_fbk = 0;
int TST_FWrevision = 0;
int TST_HWconfig = 0;
int16_t VAL_Tamb = 0;
u_int16_t VAL_RPM = 0;
int16_t VAL_VCC_set = 0;
int16_t VAL_mA_max = 0;
int16_t VAL_VCC_fbk = 0;
int16_t VAL_mA_fbk = 0;
u_int16_t VAL_FWrevision = 0;
u_int16_t VAL_HWconfig = 0;
int16_t RES_Tamb = 0;
u_int16_t RES_RPM = 0;
int16_t RES_VCC_set = 0;
int16_t RES_mA_max = 0;
int16_t RES_VCC_fbk = 0;
int16_t RES_mA_fbk = 0;
u_int16_t RES_FWrevision = 0;
u_int16_t RES_HWconfig = 0;
int OK_Tamb = 0;
int OK_RPM = 0;
int OK_VCC_set = 0;
int OK_mA_max = 0;
int OK_VCC_fbk = 0;
int OK_mA_fbk = 0;
int OK_FWrevision = 0;
int OK_HWconfig = 0;
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
int START2_REMOTE = 0;
int START2_TEST = 0;
int TST2_DigIn_1 = 0;
int TST2_DigIn_2 = 0;
int TST2_DigIn_3 = 0;
int TST2_DigIn_4 = 0;
int TST2_DigIn_5 = 0;
int TST2_DigIn_6 = 0;
int TST2_DigIn_7 = 0;
int TST2_DigIn_8 = 0;
int TST2_DigIn_9 = 0;
int TST2_DigIn_10 = 0;
int TST2_DigIn_11 = 0;
int TST2_DigIn_12 = 0;
int TST2_DigIn_13 = 0;
int TST2_DigIn_14 = 0;
int TST2_DigIn_15 = 0;
int TST2_DigIn_16 = 0;
int VAL2_DigIn_1 = 0;
int VAL2_DigIn_2 = 0;
int VAL2_DigIn_3 = 0;
int VAL2_DigIn_4 = 0;
int VAL2_DigIn_5 = 0;
int VAL2_DigIn_6 = 0;
int VAL2_DigIn_7 = 0;
int VAL2_DigIn_8 = 0;
int VAL2_DigIn_9 = 0;
int VAL2_DigIn_10 = 0;
int VAL2_DigIn_11 = 0;
int VAL2_DigIn_12 = 0;
int VAL2_DigIn_13 = 0;
int VAL2_DigIn_14 = 0;
int VAL2_DigIn_15 = 0;
int VAL2_DigIn_16 = 0;
int RES2_DigIn_1 = 0;
int RES2_DigIn_2 = 0;
int RES2_DigIn_3 = 0;
int RES2_DigIn_4 = 0;
int RES2_DigIn_5 = 0;
int RES2_DigIn_6 = 0;
int RES2_DigIn_7 = 0;
int RES2_DigIn_8 = 0;
int RES2_DigIn_9 = 0;
int RES2_DigIn_10 = 0;
int RES2_DigIn_11 = 0;
int RES2_DigIn_12 = 0;
int RES2_DigIn_13 = 0;
int RES2_DigIn_14 = 0;
int RES2_DigIn_15 = 0;
int RES2_DigIn_16 = 0;
int TST2_DigOut_1 = 0;
int TST2_DigOut_2 = 0;
int TST2_DigOut_3 = 0;
int TST2_DigOut_4 = 0;
int TST2_DigOut_5 = 0;
int TST2_DigOut_6 = 0;
int TST2_DigOut_7 = 0;
int TST2_DigOut_8 = 0;
int TST2_DigOut_9 = 0;
int TST2_DigOut_10 = 0;
int TST2_DigOut_11 = 0;
int TST2_DigOut_12 = 0;
int TST2_DigOut_13 = 0;
int TST2_DigOut_14 = 0;
int TST2_DigOut_15 = 0;
int TST2_DigOut_16 = 0;
int VAL2_DigOut_1 = 0;
int VAL2_DigOut_2 = 0;
int VAL2_DigOut_3 = 0;
int VAL2_DigOut_4 = 0;
int VAL2_DigOut_5 = 0;
int VAL2_DigOut_6 = 0;
int VAL2_DigOut_7 = 0;
int VAL2_DigOut_8 = 0;
int VAL2_DigOut_9 = 0;
int VAL2_DigOut_10 = 0;
int VAL2_DigOut_11 = 0;
int VAL2_DigOut_12 = 0;
int VAL2_DigOut_13 = 0;
int VAL2_DigOut_14 = 0;
int VAL2_DigOut_15 = 0;
int VAL2_DigOut_16 = 0;
int RES2_DigOut_1 = 0;
int RES2_DigOut_2 = 0;
int RES2_DigOut_3 = 0;
int RES2_DigOut_4 = 0;
int RES2_DigOut_5 = 0;
int RES2_DigOut_6 = 0;
int RES2_DigOut_7 = 0;
int RES2_DigOut_8 = 0;
int RES2_DigOut_9 = 0;
int RES2_DigOut_10 = 0;
int RES2_DigOut_11 = 0;
int RES2_DigOut_12 = 0;
int RES2_DigOut_13 = 0;
int RES2_DigOut_14 = 0;
int RES2_DigOut_15 = 0;
int RES2_DigOut_16 = 0;
int TST2_AnIn_1 = 0;
int TST2_AnIn_2 = 0;
int TST2_AnIn_3 = 0;
int TST2_AnIn_4 = 0;
int TST2_AnIn_5 = 0;
int TST2_AnIn_6 = 0;
int TST2_AnIn_7 = 0;
int TST2_AnIn_8 = 0;
int TST2_AnIn_9 = 0;
int TST2_AnIn_10 = 0;
int TST2_AnIn_11 = 0;
int TST2_AnIn_12 = 0;
int16_t VAL2_AnIn_1 = 0;
int16_t VAL2_AnIn_2 = 0;
int16_t VAL2_AnIn_3 = 0;
int16_t VAL2_AnIn_4 = 0;
int16_t VAL2_AnIn_5 = 0;
int16_t VAL2_AnIn_6 = 0;
int16_t VAL2_AnIn_7 = 0;
int16_t VAL2_AnIn_8 = 0;
int16_t VAL2_AnIn_9 = 0;
int16_t VAL2_AnIn_10 = 0;
int16_t VAL2_AnIn_11 = 0;
int16_t VAL2_AnIn_12 = 0;
u_int16_t VAL2_AnInConf_1 = 0;
u_int16_t VAL2_AnInConf_2 = 0;
u_int16_t VAL2_AnInConf_3 = 0;
u_int16_t VAL2_AnInConf_4 = 0;
u_int16_t VAL2_AnInConf_5 = 0;
u_int16_t VAL2_AnInConf_6 = 0;
u_int16_t VAL2_AnInConf_7 = 0;
u_int16_t VAL2_AnInConf_8 = 0;
u_int16_t VAL2_AnInConf_9 = 0;
u_int16_t VAL2_AnInConf_10 = 0;
u_int16_t VAL2_AnInConf_11 = 0;
u_int16_t VAL2_AnInConf_12 = 0;
u_int16_t VAL2_AnInFltr_1 = 0;
u_int16_t VAL2_AnInFltr_2 = 0;
u_int16_t VAL2_AnInFltr_3 = 0;
u_int16_t VAL2_AnInFltr_4 = 0;
u_int16_t VAL2_AnInFltr_5 = 0;
u_int16_t VAL2_AnInFltr_6 = 0;
u_int16_t VAL2_AnInFltr_7 = 0;
u_int16_t VAL2_AnInFltr_8 = 0;
u_int16_t VAL2_AnInFltr_9 = 0;
u_int16_t VAL2_AnInFltr_10 = 0;
u_int16_t VAL2_AnInFltr_11 = 0;
u_int16_t VAL2_AnInFltr_12 = 0;
int16_t RES2_AnIn_1 = 0;
int16_t RES2_AnIn_2 = 0;
int16_t RES2_AnIn_3 = 0;
int16_t RES2_AnIn_4 = 0;
int16_t RES2_AnIn_5 = 0;
int16_t RES2_AnIn_6 = 0;
int16_t RES2_AnIn_7 = 0;
int16_t RES2_AnIn_8 = 0;
int16_t RES2_AnIn_9 = 0;
int16_t RES2_AnIn_10 = 0;
int16_t RES2_AnIn_11 = 0;
int16_t RES2_AnIn_12 = 0;
int16_t RES2_AnInStts_1 = 0;
int16_t RES2_AnInStts_2 = 0;
int16_t RES2_AnInStts_3 = 0;
int16_t RES2_AnInStts_4 = 0;
int16_t RES2_AnInStts_5 = 0;
int16_t RES2_AnInStts_6 = 0;
int16_t RES2_AnInStts_7 = 0;
int16_t RES2_AnInStts_8 = 0;
int16_t RES2_AnInStts_9 = 0;
int16_t RES2_AnInStts_10 = 0;
int16_t RES2_AnInStts_11 = 0;
int16_t RES2_AnInStts_12 = 0;
int TST2_AnOut_1 = 0;
int TST2_AnOut_2 = 0;
int TST2_AnOut_3 = 0;
int TST2_AnOut_4 = 0;
int16_t VAL2_AnOut_1 = 0;
int16_t VAL2_AnOut_2 = 0;
int16_t VAL2_AnOut_3 = 0;
int16_t VAL2_AnOut_4 = 0;
u_int16_t VAL2_AnOutConf_1 = 0;
u_int16_t VAL2_AnOutConf_2 = 0;
u_int16_t VAL2_AnOutConf_3 = 0;
u_int16_t VAL2_AnOutConf_4 = 0;
int16_t RES2_AnOutStts_1 = 0;
int16_t RES2_AnOutStts_2 = 0;
int16_t RES2_AnOutStts_3 = 0;
int16_t RES2_AnOutStts_4 = 0;
int TST2_Tamb = 0;
int TST2_RPM = 0;
int TST2_FWrevision = 0;
int TST2_HWconfig = 0;
int16_t VAL2_Tamb = 0;
u_int16_t VAL2_RPM = 0;
u_int16_t VAL2_FWrevision = 0;
u_int16_t VAL2_HWconfig = 0;
int16_t RES2_Tamb = 0;
u_int16_t RES2_RPM = 0;
u_int16_t RES2_FWrevision = 0;
u_int16_t RES2_HWconfig = 0;
int TST2_RTUS_WR = 0;
int TST2_RTUS_RD = 0;
int TST2_RTU1_WR = 0;
int TST2_RTU1_RD = 0;
int TST2_RTU3_WR = 0;
int TST2_RTU3_RD = 0;
int TST2_CAN1_WR = 0;
int TST2_CAN1_RD = 0;
int VAL2_RTUS_WR = 0;
int VAL2_RTUS_RD = 0;
int VAL2_RTU1_WR = 0;
int VAL2_RTU1_RD = 0;
int VAL2_RTU3_WR = 0;
int VAL2_RTU3_RD = 0;
int VAL2_CAN1_WR = 0;
int VAL2_CAN1_RD = 0;
int RES2_RTUS_WR = 0;
int RES2_RTUS_RD = 0;
int RES2_RTU1_WR = 0;
int RES2_RTU1_RD = 0;
int RES2_RTU3_WR = 0;
int RES2_RTU3_RD = 0;
int RES2_CAN1_WR = 0;
int RES2_CAN1_RD = 0;
int STATUS2_LOCAL = 0;
int STATUS2_REMOTE = 0;
int STATUS2_DONE = 0;
int STARTx_REMOTE = 0;
int STARTx_TEST = 0;
int TSTx_DigIn_1 = 0;
int TSTx_DigIn_2 = 0;
int TSTx_DigIn_3 = 0;
int TSTx_DigIn_4 = 0;
int TSTx_DigIn_5 = 0;
int TSTx_DigIn_6 = 0;
int TSTx_DigIn_7 = 0;
int TSTx_DigIn_8 = 0;
int TSTx_DigIn_9 = 0;
int TSTx_DigIn_10 = 0;
int TSTx_DigIn_11 = 0;
int TSTx_DigIn_12 = 0;
int TSTx_DigIn_13 = 0;
int TSTx_DigIn_14 = 0;
int TSTx_DigIn_15 = 0;
int TSTx_DigIn_16 = 0;
int VALx_DigIn_1 = 0;
int VALx_DigIn_2 = 0;
int VALx_DigIn_3 = 0;
int VALx_DigIn_4 = 0;
int VALx_DigIn_5 = 0;
int VALx_DigIn_6 = 0;
int VALx_DigIn_7 = 0;
int VALx_DigIn_8 = 0;
int VALx_DigIn_9 = 0;
int VALx_DigIn_10 = 0;
int VALx_DigIn_11 = 0;
int VALx_DigIn_12 = 0;
int VALx_DigIn_13 = 0;
int VALx_DigIn_14 = 0;
int VALx_DigIn_15 = 0;
int VALx_DigIn_16 = 0;
int RESx_DigIn_1 = 0;
int RESx_DigIn_2 = 0;
int RESx_DigIn_3 = 0;
int RESx_DigIn_4 = 0;
int RESx_DigIn_5 = 0;
int RESx_DigIn_6 = 0;
int RESx_DigIn_7 = 0;
int RESx_DigIn_8 = 0;
int RESx_DigIn_9 = 0;
int RESx_DigIn_10 = 0;
int RESx_DigIn_11 = 0;
int RESx_DigIn_12 = 0;
int RESx_DigIn_13 = 0;
int RESx_DigIn_14 = 0;
int RESx_DigIn_15 = 0;
int RESx_DigIn_16 = 0;
int TSTx_DigOut_1 = 0;
int TSTx_DigOut_2 = 0;
int TSTx_DigOut_3 = 0;
int TSTx_DigOut_4 = 0;
int TSTx_DigOut_5 = 0;
int TSTx_DigOut_6 = 0;
int TSTx_DigOut_7 = 0;
int TSTx_DigOut_8 = 0;
int TSTx_DigOut_9 = 0;
int TSTx_DigOut_10 = 0;
int TSTx_DigOut_11 = 0;
int TSTx_DigOut_12 = 0;
int TSTx_DigOut_13 = 0;
int TSTx_DigOut_14 = 0;
int TSTx_DigOut_15 = 0;
int TSTx_DigOut_16 = 0;
int VALx_DigOut_1 = 0;
int VALx_DigOut_2 = 0;
int VALx_DigOut_3 = 0;
int VALx_DigOut_4 = 0;
int VALx_DigOut_5 = 0;
int VALx_DigOut_6 = 0;
int VALx_DigOut_7 = 0;
int VALx_DigOut_8 = 0;
int VALx_DigOut_9 = 0;
int VALx_DigOut_10 = 0;
int VALx_DigOut_11 = 0;
int VALx_DigOut_12 = 0;
int VALx_DigOut_13 = 0;
int VALx_DigOut_14 = 0;
int VALx_DigOut_15 = 0;
int VALx_DigOut_16 = 0;
int RESx_DigOut_1 = 0;
int RESx_DigOut_2 = 0;
int RESx_DigOut_3 = 0;
int RESx_DigOut_4 = 0;
int RESx_DigOut_5 = 0;
int RESx_DigOut_6 = 0;
int RESx_DigOut_7 = 0;
int RESx_DigOut_8 = 0;
int RESx_DigOut_9 = 0;
int RESx_DigOut_10 = 0;
int RESx_DigOut_11 = 0;
int RESx_DigOut_12 = 0;
int RESx_DigOut_13 = 0;
int RESx_DigOut_14 = 0;
int RESx_DigOut_15 = 0;
int RESx_DigOut_16 = 0;
int TSTx_AnIn_1 = 0;
int TSTx_AnIn_2 = 0;
int TSTx_AnIn_3 = 0;
int TSTx_AnIn_4 = 0;
int TSTx_AnIn_5 = 0;
int TSTx_AnIn_6 = 0;
int TSTx_AnIn_7 = 0;
int TSTx_AnIn_8 = 0;
int TSTx_AnIn_9 = 0;
int TSTx_AnIn_10 = 0;
int TSTx_AnIn_11 = 0;
int TSTx_AnIn_12 = 0;
int16_t VALx_AnIn_1 = 0;
int16_t VALx_AnIn_2 = 0;
int16_t VALx_AnIn_3 = 0;
int16_t VALx_AnIn_4 = 0;
int16_t VALx_AnIn_5 = 0;
int16_t VALx_AnIn_6 = 0;
int16_t VALx_AnIn_7 = 0;
int16_t VALx_AnIn_8 = 0;
int16_t VALx_AnIn_9 = 0;
int16_t VALx_AnIn_10 = 0;
int16_t VALx_AnIn_11 = 0;
int16_t VALx_AnIn_12 = 0;
u_int16_t VALx_AnInConf_1 = 0;
u_int16_t VALx_AnInConf_2 = 0;
u_int16_t VALx_AnInConf_3 = 0;
u_int16_t VALx_AnInConf_4 = 0;
u_int16_t VALx_AnInConf_5 = 0;
u_int16_t VALx_AnInConf_6 = 0;
u_int16_t VALx_AnInConf_7 = 0;
u_int16_t VALx_AnInConf_8 = 0;
u_int16_t VALx_AnInConf_9 = 0;
u_int16_t VALx_AnInConf_10 = 0;
u_int16_t VALx_AnInConf_11 = 0;
u_int16_t VALx_AnInConf_12 = 0;
u_int16_t VALx_AnInFltr_1 = 0;
u_int16_t VALx_AnInFltr_2 = 0;
u_int16_t VALx_AnInFltr_3 = 0;
u_int16_t VALx_AnInFltr_4 = 0;
u_int16_t VALx_AnInFltr_5 = 0;
u_int16_t VALx_AnInFltr_6 = 0;
u_int16_t VALx_AnInFltr_7 = 0;
u_int16_t VALx_AnInFltr_8 = 0;
u_int16_t VALx_AnInFltr_9 = 0;
u_int16_t VALx_AnInFltr_10 = 0;
u_int16_t VALx_AnInFltr_11 = 0;
u_int16_t VALx_AnInFltr_12 = 0;
int16_t RESx_AnIn_1 = 0;
int16_t RESx_AnIn_2 = 0;
int16_t RESx_AnIn_3 = 0;
int16_t RESx_AnIn_4 = 0;
int16_t RESx_AnIn_5 = 0;
int16_t RESx_AnIn_6 = 0;
int16_t RESx_AnIn_7 = 0;
int16_t RESx_AnIn_8 = 0;
int16_t RESx_AnIn_9 = 0;
int16_t RESx_AnIn_10 = 0;
int16_t RESx_AnIn_11 = 0;
int16_t RESx_AnIn_12 = 0;
int16_t RESx_AnInStts_1 = 0;
int16_t RESx_AnInStts_2 = 0;
int16_t RESx_AnInStts_3 = 0;
int16_t RESx_AnInStts_4 = 0;
int16_t RESx_AnInStts_5 = 0;
int16_t RESx_AnInStts_6 = 0;
int16_t RESx_AnInStts_7 = 0;
int16_t RESx_AnInStts_8 = 0;
int16_t RESx_AnInStts_9 = 0;
int16_t RESx_AnInStts_10 = 0;
int16_t RESx_AnInStts_11 = 0;
int16_t RESx_AnInStts_12 = 0;
int TSTx_AnOut_1 = 0;
int TSTx_AnOut_2 = 0;
int TSTx_AnOut_3 = 0;
int TSTx_AnOut_4 = 0;
int16_t VALx_AnOut_1 = 0;
int16_t VALx_AnOut_2 = 0;
int16_t VALx_AnOut_3 = 0;
int16_t VALx_AnOut_4 = 0;
u_int16_t VALx_AnOutConf_1 = 0;
u_int16_t VALx_AnOutConf_2 = 0;
u_int16_t VALx_AnOutConf_3 = 0;
u_int16_t VALx_AnOutConf_4 = 0;
int16_t RESx_AnOutStts_1 = 0;
int16_t RESx_AnOutStts_2 = 0;
int16_t RESx_AnOutStts_3 = 0;
int16_t RESx_AnOutStts_4 = 0;
int TSTx_Tamb = 0;
int TSTx_RPM = 0;
int TSTx_FWrevision = 0;
int TSTx_HWconfig = 0;
int16_t VALx_Tamb = 0;
u_int16_t VALx_RPM = 0;
u_int16_t VALx_FWrevision = 0;
u_int16_t VALx_HWconfig = 0;
int16_t RESx_Tamb = 0;
u_int16_t RESx_RPM = 0;
u_int16_t RESx_FWrevision = 0;
u_int16_t RESx_HWconfig = 0;
int TSTx_RTUS_WR = 0;
int TSTx_RTUS_RD = 0;
int TSTx_RTU1_WR = 0;
int TSTx_RTU1_RD = 0;
int TSTx_RTU3_WR = 0;
int TSTx_RTU3_RD = 0;
int TSTx_CAN1_WR = 0;
int TSTx_CAN1_RD = 0;
int VALx_RTUS_WR = 0;
int VALx_RTUS_RD = 0;
int VALx_RTU1_WR = 0;
int VALx_RTU1_RD = 0;
int VALx_RTU3_WR = 0;
int VALx_RTU3_RD = 0;
int VALx_CAN1_WR = 0;
int VALx_CAN1_RD = 0;
int RESx_RTUS_WR = 0;
int RESx_RTUS_RD = 0;
int RESx_RTU1_WR = 0;
int RESx_RTU1_RD = 0;
int RESx_RTU3_WR = 0;
int RESx_RTU3_RD = 0;
int RESx_CAN1_WR = 0;
int RESx_CAN1_RD = 0;
int STATUSx_LOCAL = 0;
int STATUSx_REMOTE = 0;
int STATUSx_DONE = 0;
int RTU_DigIn_1 = 0;
int RTU_DigIn_2 = 0;
int RTU_DigIn_3 = 0;
int RTU_DigIn_4 = 0;
int RTU_DigIn_5 = 0;
int RTU_DigIn_6 = 0;
int RTU_DigIn_7 = 0;
int RTU_DigIn_8 = 0;
int RTU_DigIn_9 = 0;
int RTU_DigIn_10 = 0;
int RTU_DigIn_11 = 0;
int RTU_DigIn_12 = 0;
int RTU_DigIn_13 = 0;
int RTU_DigIn_14 = 0;
int RTU_DigIn_15 = 0;
int RTU_DigIn_16 = 0;
int16_t RTU_AnIn_1 = 0;
int16_t RTU_AnIn_2 = 0;
int16_t RTU_Tamb = 0;
int RTU_DigOut_1 = 0;
int RTU_DigOut_2 = 0;
int RTU_DigOut_3 = 0;
int RTU_DigOut_4 = 0;
int RTU_DigOut_5 = 0;
int RTU_DigOut_6 = 0;
int RTU_DigOut_7 = 0;
int RTU_DigOut_8 = 0;
int RTU_DigOut_9 = 0;
int RTU_DigOut_10 = 0;
int RTU_DigOut_11 = 0;
int RTU_DigOut_12 = 0;
int RTU_DigOut_13 = 0;
int RTU_DigOut_14 = 0;
int RTU_DigOut_15 = 0;
int RTU_DigOut_16 = 0;
int16_t RTU_AnOutConf_X = 0;
int16_t RTU_AnOut_1 = 0;
int16_t RTU_AnOut_2 = 0;
int16_t RTU_AnOut_3 = 0;
int16_t RTU_AnOut_4 = 0;
int16_t RTU_AnOut_5 = 0;
int16_t RTU_AnOut_6 = 0;
int16_t RTU_AnOut_7 = 0;
int16_t RTU_AnOut_8 = 0;
u_int16_t RTU_AnInConf_1 = 0;
u_int16_t RTU_AnInConf_2 = 0;
u_int32_t RTU_HeartBeat = 0;
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
u_int16_t PLC_AnOutConf_2 = 0;
u_int16_t PLC_AnOutConf_3 = 0;
u_int16_t PLC_AnOutConf_4 = 0;
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
int16_t PLC_AnIn_3 = 0;
int16_t PLC_AnIn_4 = 0;
int16_t PLC_AnIn_5 = 0;
int16_t PLC_Tamb = 0;
u_int32_t PLC_Encoder = 0;
u_int32_t PLC_Capture = 0;
int PLC_DigOut_1 = 0;
int PLC_DigOut_2 = 0;
int PLC_DigOut_3 = 0;
int PLC_DigOut_4 = 0;
int PLC_DigOut_5 = 0;
int PLC_DigOut_6 = 0;
int PLC_DigOut_7 = 0;
int PLC_DigOut_8 = 0;
int16_t PLC_AnOut_1 = 0;
int16_t PLC_AnOut_2 = 0;
int16_t PLC_AnOut_3 = 0;
int16_t PLC_AnOut_4 = 0;
u_int16_t PLC_EncoderStart = 0;
u_int16_t PLC_EncoderReset = 0;
u_int16_t PLC_Heartbeat = 0;
u_int16_t PLC_StatusReg = 0;
u_int16_t PLC_AnIn1Filter = 0;
u_int16_t PLC_AnIn2Filter = 0;
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


int doWrite_DO_REMOTE(int value)
{
return writeVarByCtIndex(ID_DO_REMOTE,  &value);
}


int addWrite_DO_REMOTE(int value)
{
return (prepareWriteVarByCtIndex(ID_DO_REMOTE, &value, NULL, 0) == ERROR);
}


int doWrite_DO_TEST(int value)
{
return writeVarByCtIndex(ID_DO_TEST,  &value);
}


int addWrite_DO_TEST(int value)
{
return (prepareWriteVarByCtIndex(ID_DO_TEST, &value, NULL, 0) == ERROR);
}


int doWrite_STATUS(u_int16_t value)
{
return writeVarByCtIndex(ID_STATUS,  &value);
}


int addWrite_STATUS(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_STATUS, &value, NULL, 0) == ERROR);
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


int doWrite_VAL_AnInFltr_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_1,  &value);
}


int addWrite_VAL_AnInFltr_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_2,  &value);
}


int addWrite_VAL_AnInFltr_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_3,  &value);
}


int addWrite_VAL_AnInFltr_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_4,  &value);
}


int addWrite_VAL_AnInFltr_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_5(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_5,  &value);
}


int addWrite_VAL_AnInFltr_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_6(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_6,  &value);
}


int addWrite_VAL_AnInFltr_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_7(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_7,  &value);
}


int addWrite_VAL_AnInFltr_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_8(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_8,  &value);
}


int addWrite_VAL_AnInFltr_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_9(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_9,  &value);
}


int addWrite_VAL_AnInFltr_9(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_10(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_10,  &value);
}


int addWrite_VAL_AnInFltr_10(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_11(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_11,  &value);
}


int addWrite_VAL_AnInFltr_11(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL_AnInFltr_12(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL_AnInFltr_12,  &value);
}


int addWrite_VAL_AnInFltr_12(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_AnInFltr_12, &value, NULL, 0) == ERROR);
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


int doWrite_RES_AnInStts_1(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_1,  &value);
}


int addWrite_RES_AnInStts_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_2(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_2,  &value);
}


int addWrite_RES_AnInStts_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_3(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_3,  &value);
}


int addWrite_RES_AnInStts_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_4(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_4,  &value);
}


int addWrite_RES_AnInStts_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_5(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_5,  &value);
}


int addWrite_RES_AnInStts_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_6(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_6,  &value);
}


int addWrite_RES_AnInStts_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_7(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_7,  &value);
}


int addWrite_RES_AnInStts_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_8(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_8,  &value);
}


int addWrite_RES_AnInStts_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_9(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_9,  &value);
}


int addWrite_RES_AnInStts_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_10(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_10,  &value);
}


int addWrite_RES_AnInStts_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_11(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_11,  &value);
}


int addWrite_RES_AnInStts_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnInStts_12(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnInStts_12,  &value);
}


int addWrite_RES_AnInStts_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnInStts_12, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_1(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_1,  &value);
}


int addWrite_OK_AnIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_2(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_2,  &value);
}


int addWrite_OK_AnIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_3(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_3,  &value);
}


int addWrite_OK_AnIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_4(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_4,  &value);
}


int addWrite_OK_AnIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_5(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_5,  &value);
}


int addWrite_OK_AnIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_6(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_6,  &value);
}


int addWrite_OK_AnIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_7(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_7,  &value);
}


int addWrite_OK_AnIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_8(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_8,  &value);
}


int addWrite_OK_AnIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_9(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_9,  &value);
}


int addWrite_OK_AnIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_10(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_10,  &value);
}


int addWrite_OK_AnIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_11(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_11,  &value);
}


int addWrite_OK_AnIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnIn_12(int value)
{
return writeVarByCtIndex(ID_OK_AnIn_12,  &value);
}


int addWrite_OK_AnIn_12(int value)
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


int doWrite_RES_AnOutStts_1(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOutStts_1,  &value);
}


int addWrite_RES_AnOutStts_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOutStts_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOutStts_2(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOutStts_2,  &value);
}


int addWrite_RES_AnOutStts_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOutStts_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOutStts_3(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOutStts_3,  &value);
}


int addWrite_RES_AnOutStts_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOutStts_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES_AnOutStts_4(int16_t value)
{
return writeVarByCtIndex(ID_RES_AnOutStts_4,  &value);
}


int addWrite_RES_AnOutStts_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_AnOutStts_4, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_1(int value)
{
return writeVarByCtIndex(ID_OK_AnOut_1,  &value);
}


int addWrite_OK_AnOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_2(int value)
{
return writeVarByCtIndex(ID_OK_AnOut_2,  &value);
}


int addWrite_OK_AnOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_3(int value)
{
return writeVarByCtIndex(ID_OK_AnOut_3,  &value);
}


int addWrite_OK_AnOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_OK_AnOut_4(int value)
{
return writeVarByCtIndex(ID_OK_AnOut_4,  &value);
}


int addWrite_OK_AnOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_AnOut_4, &value, NULL, 0) == ERROR);
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


int doWrite_TST_mA_max(int value)
{
return writeVarByCtIndex(ID_TST_mA_max,  &value);
}


int addWrite_TST_mA_max(int value)
{
return (prepareWriteVarByCtIndex(ID_TST_mA_max, &value, NULL, 0) == ERROR);
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


int doWrite_VAL_mA_max(int16_t value)
{
return writeVarByCtIndex(ID_VAL_mA_max,  &value);
}


int addWrite_VAL_mA_max(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL_mA_max, &value, NULL, 0) == ERROR);
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


int doWrite_RES_mA_max(int16_t value)
{
return writeVarByCtIndex(ID_RES_mA_max,  &value);
}


int addWrite_RES_mA_max(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES_mA_max, &value, NULL, 0) == ERROR);
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


int doWrite_OK_Tamb(int value)
{
return writeVarByCtIndex(ID_OK_Tamb,  &value);
}


int addWrite_OK_Tamb(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_OK_RPM(int value)
{
return writeVarByCtIndex(ID_OK_RPM,  &value);
}


int addWrite_OK_RPM(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_OK_VCC_set(int value)
{
return writeVarByCtIndex(ID_OK_VCC_set,  &value);
}


int addWrite_OK_VCC_set(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_VCC_set, &value, NULL, 0) == ERROR);
}


int doWrite_OK_mA_max(int value)
{
return writeVarByCtIndex(ID_OK_mA_max,  &value);
}


int addWrite_OK_mA_max(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_mA_max, &value, NULL, 0) == ERROR);
}


int doWrite_OK_VCC_fbk(int value)
{
return writeVarByCtIndex(ID_OK_VCC_fbk,  &value);
}


int addWrite_OK_VCC_fbk(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_VCC_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_OK_mA_fbk(int value)
{
return writeVarByCtIndex(ID_OK_mA_fbk,  &value);
}


int addWrite_OK_mA_fbk(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_mA_fbk, &value, NULL, 0) == ERROR);
}


int doWrite_OK_FWrevision(int value)
{
return writeVarByCtIndex(ID_OK_FWrevision,  &value);
}


int addWrite_OK_FWrevision(int value)
{
return (prepareWriteVarByCtIndex(ID_OK_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_OK_HWconfig(int value)
{
return writeVarByCtIndex(ID_OK_HWconfig,  &value);
}


int addWrite_OK_HWconfig(int value)
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


int doWrite_START2_REMOTE(int value)
{
return writeVarByCtIndex(ID_START2_REMOTE,  &value);
}


int addWrite_START2_REMOTE(int value)
{
return (prepareWriteVarByCtIndex(ID_START2_REMOTE, &value, NULL, 0) == ERROR);
}


int doWrite_START2_TEST(int value)
{
return writeVarByCtIndex(ID_START2_TEST,  &value);
}


int addWrite_START2_TEST(int value)
{
return (prepareWriteVarByCtIndex(ID_START2_TEST, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_1(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_1,  &value);
}


int addWrite_TST2_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_2(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_2,  &value);
}


int addWrite_TST2_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_3(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_3,  &value);
}


int addWrite_TST2_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_4(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_4,  &value);
}


int addWrite_TST2_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_5(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_5,  &value);
}


int addWrite_TST2_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_6(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_6,  &value);
}


int addWrite_TST2_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_7(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_7,  &value);
}


int addWrite_TST2_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_8(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_8,  &value);
}


int addWrite_TST2_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_9(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_9,  &value);
}


int addWrite_TST2_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_10(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_10,  &value);
}


int addWrite_TST2_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_11(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_11,  &value);
}


int addWrite_TST2_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_12(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_12,  &value);
}


int addWrite_TST2_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_13(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_13,  &value);
}


int addWrite_TST2_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_14(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_14,  &value);
}


int addWrite_TST2_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_15(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_15,  &value);
}


int addWrite_TST2_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigIn_16(int value)
{
return writeVarByCtIndex(ID_TST2_DigIn_16,  &value);
}


int addWrite_TST2_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_1(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_1,  &value);
}


int addWrite_VAL2_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_2(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_2,  &value);
}


int addWrite_VAL2_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_3(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_3,  &value);
}


int addWrite_VAL2_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_4(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_4,  &value);
}


int addWrite_VAL2_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_5(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_5,  &value);
}


int addWrite_VAL2_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_6(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_6,  &value);
}


int addWrite_VAL2_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_7(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_7,  &value);
}


int addWrite_VAL2_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_8(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_8,  &value);
}


int addWrite_VAL2_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_9(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_9,  &value);
}


int addWrite_VAL2_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_10(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_10,  &value);
}


int addWrite_VAL2_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_11(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_11,  &value);
}


int addWrite_VAL2_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_12(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_12,  &value);
}


int addWrite_VAL2_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_13(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_13,  &value);
}


int addWrite_VAL2_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_14(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_14,  &value);
}


int addWrite_VAL2_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_15(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_15,  &value);
}


int addWrite_VAL2_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigIn_16(int value)
{
return writeVarByCtIndex(ID_VAL2_DigIn_16,  &value);
}


int addWrite_VAL2_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_1(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_1,  &value);
}


int addWrite_RES2_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_2(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_2,  &value);
}


int addWrite_RES2_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_3(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_3,  &value);
}


int addWrite_RES2_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_4(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_4,  &value);
}


int addWrite_RES2_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_5(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_5,  &value);
}


int addWrite_RES2_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_6(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_6,  &value);
}


int addWrite_RES2_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_7(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_7,  &value);
}


int addWrite_RES2_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_8(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_8,  &value);
}


int addWrite_RES2_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_9(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_9,  &value);
}


int addWrite_RES2_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_10(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_10,  &value);
}


int addWrite_RES2_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_11(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_11,  &value);
}


int addWrite_RES2_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_12(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_12,  &value);
}


int addWrite_RES2_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_13(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_13,  &value);
}


int addWrite_RES2_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_14(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_14,  &value);
}


int addWrite_RES2_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_15(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_15,  &value);
}


int addWrite_RES2_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigIn_16(int value)
{
return writeVarByCtIndex(ID_RES2_DigIn_16,  &value);
}


int addWrite_RES2_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_1(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_1,  &value);
}


int addWrite_TST2_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_2(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_2,  &value);
}


int addWrite_TST2_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_3(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_3,  &value);
}


int addWrite_TST2_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_4(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_4,  &value);
}


int addWrite_TST2_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_5(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_5,  &value);
}


int addWrite_TST2_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_6(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_6,  &value);
}


int addWrite_TST2_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_7(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_7,  &value);
}


int addWrite_TST2_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_8(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_8,  &value);
}


int addWrite_TST2_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_9(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_9,  &value);
}


int addWrite_TST2_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_10(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_10,  &value);
}


int addWrite_TST2_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_11(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_11,  &value);
}


int addWrite_TST2_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_12(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_12,  &value);
}


int addWrite_TST2_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_13(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_13,  &value);
}


int addWrite_TST2_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_14(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_14,  &value);
}


int addWrite_TST2_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_15(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_15,  &value);
}


int addWrite_TST2_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_DigOut_16(int value)
{
return writeVarByCtIndex(ID_TST2_DigOut_16,  &value);
}


int addWrite_TST2_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_1(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_1,  &value);
}


int addWrite_VAL2_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_2(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_2,  &value);
}


int addWrite_VAL2_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_3(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_3,  &value);
}


int addWrite_VAL2_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_4(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_4,  &value);
}


int addWrite_VAL2_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_5(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_5,  &value);
}


int addWrite_VAL2_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_6(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_6,  &value);
}


int addWrite_VAL2_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_7(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_7,  &value);
}


int addWrite_VAL2_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_8(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_8,  &value);
}


int addWrite_VAL2_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_9(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_9,  &value);
}


int addWrite_VAL2_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_10(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_10,  &value);
}


int addWrite_VAL2_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_11(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_11,  &value);
}


int addWrite_VAL2_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_12(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_12,  &value);
}


int addWrite_VAL2_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_13(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_13,  &value);
}


int addWrite_VAL2_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_14(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_14,  &value);
}


int addWrite_VAL2_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_15(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_15,  &value);
}


int addWrite_VAL2_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_DigOut_16(int value)
{
return writeVarByCtIndex(ID_VAL2_DigOut_16,  &value);
}


int addWrite_VAL2_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_1(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_1,  &value);
}


int addWrite_RES2_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_2(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_2,  &value);
}


int addWrite_RES2_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_3(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_3,  &value);
}


int addWrite_RES2_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_4(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_4,  &value);
}


int addWrite_RES2_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_5(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_5,  &value);
}


int addWrite_RES2_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_6(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_6,  &value);
}


int addWrite_RES2_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_7(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_7,  &value);
}


int addWrite_RES2_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_8(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_8,  &value);
}


int addWrite_RES2_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_9(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_9,  &value);
}


int addWrite_RES2_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_10(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_10,  &value);
}


int addWrite_RES2_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_11(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_11,  &value);
}


int addWrite_RES2_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_12(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_12,  &value);
}


int addWrite_RES2_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_13(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_13,  &value);
}


int addWrite_RES2_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_14(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_14,  &value);
}


int addWrite_RES2_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_15(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_15,  &value);
}


int addWrite_RES2_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_DigOut_16(int value)
{
return writeVarByCtIndex(ID_RES2_DigOut_16,  &value);
}


int addWrite_RES2_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_1(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_1,  &value);
}


int addWrite_TST2_AnIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_2(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_2,  &value);
}


int addWrite_TST2_AnIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_3(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_3,  &value);
}


int addWrite_TST2_AnIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_4(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_4,  &value);
}


int addWrite_TST2_AnIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_5(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_5,  &value);
}


int addWrite_TST2_AnIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_6(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_6,  &value);
}


int addWrite_TST2_AnIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_7(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_7,  &value);
}


int addWrite_TST2_AnIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_8(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_8,  &value);
}


int addWrite_TST2_AnIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_9(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_9,  &value);
}


int addWrite_TST2_AnIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_10(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_10,  &value);
}


int addWrite_TST2_AnIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_11(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_11,  &value);
}


int addWrite_TST2_AnIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnIn_12(int value)
{
return writeVarByCtIndex(ID_TST2_AnIn_12,  &value);
}


int addWrite_TST2_AnIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_1,  &value);
}


int addWrite_VAL2_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_2,  &value);
}


int addWrite_VAL2_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_3,  &value);
}


int addWrite_VAL2_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_4,  &value);
}


int addWrite_VAL2_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_5,  &value);
}


int addWrite_VAL2_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_6,  &value);
}


int addWrite_VAL2_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_7,  &value);
}


int addWrite_VAL2_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_8,  &value);
}


int addWrite_VAL2_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_9(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_9,  &value);
}


int addWrite_VAL2_AnIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_10(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_10,  &value);
}


int addWrite_VAL2_AnIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_11(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_11,  &value);
}


int addWrite_VAL2_AnIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnIn_12(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnIn_12,  &value);
}


int addWrite_VAL2_AnIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_1,  &value);
}


int addWrite_VAL2_AnInConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_2,  &value);
}


int addWrite_VAL2_AnInConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_3,  &value);
}


int addWrite_VAL2_AnInConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_4,  &value);
}


int addWrite_VAL2_AnInConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_5(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_5,  &value);
}


int addWrite_VAL2_AnInConf_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_6(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_6,  &value);
}


int addWrite_VAL2_AnInConf_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_7(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_7,  &value);
}


int addWrite_VAL2_AnInConf_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_8(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_8,  &value);
}


int addWrite_VAL2_AnInConf_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_9(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_9,  &value);
}


int addWrite_VAL2_AnInConf_9(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_10(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_10,  &value);
}


int addWrite_VAL2_AnInConf_10(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_11(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_11,  &value);
}


int addWrite_VAL2_AnInConf_11(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInConf_12(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInConf_12,  &value);
}


int addWrite_VAL2_AnInConf_12(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInConf_12, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_1,  &value);
}


int addWrite_VAL2_AnInFltr_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_2,  &value);
}


int addWrite_VAL2_AnInFltr_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_3,  &value);
}


int addWrite_VAL2_AnInFltr_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_4,  &value);
}


int addWrite_VAL2_AnInFltr_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_5(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_5,  &value);
}


int addWrite_VAL2_AnInFltr_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_5, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_6(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_6,  &value);
}


int addWrite_VAL2_AnInFltr_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_6, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_7(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_7,  &value);
}


int addWrite_VAL2_AnInFltr_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_7, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_8(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_8,  &value);
}


int addWrite_VAL2_AnInFltr_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_8, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_9(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_9,  &value);
}


int addWrite_VAL2_AnInFltr_9(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_9, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_10(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_10,  &value);
}


int addWrite_VAL2_AnInFltr_10(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_10, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_11(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_11,  &value);
}


int addWrite_VAL2_AnInFltr_11(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_11, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnInFltr_12(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnInFltr_12,  &value);
}


int addWrite_VAL2_AnInFltr_12(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnInFltr_12, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_1,  &value);
}


int addWrite_RES2_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_2,  &value);
}


int addWrite_RES2_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_3,  &value);
}


int addWrite_RES2_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_4,  &value);
}


int addWrite_RES2_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_5,  &value);
}


int addWrite_RES2_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_6,  &value);
}


int addWrite_RES2_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_7,  &value);
}


int addWrite_RES2_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_8,  &value);
}


int addWrite_RES2_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_9(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_9,  &value);
}


int addWrite_RES2_AnIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_10(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_10,  &value);
}


int addWrite_RES2_AnIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_11(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_11,  &value);
}


int addWrite_RES2_AnIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnIn_12(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnIn_12,  &value);
}


int addWrite_RES2_AnIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_1(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_1,  &value);
}


int addWrite_RES2_AnInStts_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_2(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_2,  &value);
}


int addWrite_RES2_AnInStts_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_3(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_3,  &value);
}


int addWrite_RES2_AnInStts_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_4(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_4,  &value);
}


int addWrite_RES2_AnInStts_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_5(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_5,  &value);
}


int addWrite_RES2_AnInStts_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_5, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_6(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_6,  &value);
}


int addWrite_RES2_AnInStts_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_6, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_7(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_7,  &value);
}


int addWrite_RES2_AnInStts_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_7, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_8(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_8,  &value);
}


int addWrite_RES2_AnInStts_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_8, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_9(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_9,  &value);
}


int addWrite_RES2_AnInStts_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_9, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_10(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_10,  &value);
}


int addWrite_RES2_AnInStts_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_10, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_11(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_11,  &value);
}


int addWrite_RES2_AnInStts_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_11, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnInStts_12(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnInStts_12,  &value);
}


int addWrite_RES2_AnInStts_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnInStts_12, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnOut_1(int value)
{
return writeVarByCtIndex(ID_TST2_AnOut_1,  &value);
}


int addWrite_TST2_AnOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnOut_2(int value)
{
return writeVarByCtIndex(ID_TST2_AnOut_2,  &value);
}


int addWrite_TST2_AnOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnOut_3(int value)
{
return writeVarByCtIndex(ID_TST2_AnOut_3,  &value);
}


int addWrite_TST2_AnOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_AnOut_4(int value)
{
return writeVarByCtIndex(ID_TST2_AnOut_4,  &value);
}


int addWrite_TST2_AnOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOut_1,  &value);
}


int addWrite_VAL2_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOut_2,  &value);
}


int addWrite_VAL2_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOut_3,  &value);
}


int addWrite_VAL2_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOut_4,  &value);
}


int addWrite_VAL2_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOutConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOutConf_1,  &value);
}


int addWrite_VAL2_AnOutConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOutConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOutConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOutConf_2,  &value);
}


int addWrite_VAL2_AnOutConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOutConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOutConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOutConf_3,  &value);
}


int addWrite_VAL2_AnOutConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOutConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_AnOutConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_AnOutConf_4,  &value);
}


int addWrite_VAL2_AnOutConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_AnOutConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnOutStts_1(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnOutStts_1,  &value);
}


int addWrite_RES2_AnOutStts_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnOutStts_1, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnOutStts_2(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnOutStts_2,  &value);
}


int addWrite_RES2_AnOutStts_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnOutStts_2, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnOutStts_3(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnOutStts_3,  &value);
}


int addWrite_RES2_AnOutStts_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnOutStts_3, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_AnOutStts_4(int16_t value)
{
return writeVarByCtIndex(ID_RES2_AnOutStts_4,  &value);
}


int addWrite_RES2_AnOutStts_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_AnOutStts_4, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_Tamb(int value)
{
return writeVarByCtIndex(ID_TST2_Tamb,  &value);
}


int addWrite_TST2_Tamb(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_RPM(int value)
{
return writeVarByCtIndex(ID_TST2_RPM,  &value);
}


int addWrite_TST2_RPM(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_FWrevision(int value)
{
return writeVarByCtIndex(ID_TST2_FWrevision,  &value);
}


int addWrite_TST2_FWrevision(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_HWconfig(int value)
{
return writeVarByCtIndex(ID_TST2_HWconfig,  &value);
}


int addWrite_TST2_HWconfig(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_VAL2_Tamb,  &value);
}


int addWrite_VAL2_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_RPM,  &value);
}


int addWrite_VAL2_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_FWrevision,  &value);
}


int addWrite_VAL2_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_VAL2_HWconfig,  &value);
}


int addWrite_VAL2_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_RES2_Tamb,  &value);
}


int addWrite_RES2_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_RES2_RPM,  &value);
}


int addWrite_RES2_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_RES2_FWrevision,  &value);
}


int addWrite_RES2_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_RES2_HWconfig,  &value);
}


int addWrite_RES2_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RES2_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_TST2_RTUS_WR,  &value);
}


int addWrite_TST2_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_TST2_RTUS_RD,  &value);
}


int addWrite_TST2_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_TST2_RTU1_WR,  &value);
}


int addWrite_TST2_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_TST2_RTU1_RD,  &value);
}


int addWrite_TST2_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_TST2_RTU3_WR,  &value);
}


int addWrite_TST2_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_TST2_RTU3_RD,  &value);
}


int addWrite_TST2_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_TST2_CAN1_WR,  &value);
}


int addWrite_TST2_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TST2_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_TST2_CAN1_RD,  &value);
}


int addWrite_TST2_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TST2_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_VAL2_RTUS_WR,  &value);
}


int addWrite_VAL2_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_VAL2_RTUS_RD,  &value);
}


int addWrite_VAL2_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_VAL2_RTU1_WR,  &value);
}


int addWrite_VAL2_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_VAL2_RTU1_RD,  &value);
}


int addWrite_VAL2_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_VAL2_RTU3_WR,  &value);
}


int addWrite_VAL2_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_VAL2_RTU3_RD,  &value);
}


int addWrite_VAL2_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_VAL2_CAN1_WR,  &value);
}


int addWrite_VAL2_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VAL2_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_VAL2_CAN1_RD,  &value);
}


int addWrite_VAL2_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VAL2_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_RES2_RTUS_WR,  &value);
}


int addWrite_RES2_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_RES2_RTUS_RD,  &value);
}


int addWrite_RES2_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_RES2_RTU1_WR,  &value);
}


int addWrite_RES2_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_RES2_RTU1_RD,  &value);
}


int addWrite_RES2_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_RES2_RTU3_WR,  &value);
}


int addWrite_RES2_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_RES2_RTU3_RD,  &value);
}


int addWrite_RES2_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_RES2_CAN1_WR,  &value);
}


int addWrite_RES2_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RES2_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_RES2_CAN1_RD,  &value);
}


int addWrite_RES2_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RES2_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_STATUS2_LOCAL(int value)
{
return writeVarByCtIndex(ID_STATUS2_LOCAL,  &value);
}


int addWrite_STATUS2_LOCAL(int value)
{
return (prepareWriteVarByCtIndex(ID_STATUS2_LOCAL, &value, NULL, 0) == ERROR);
}


int doWrite_STATUS2_REMOTE(int value)
{
return writeVarByCtIndex(ID_STATUS2_REMOTE,  &value);
}


int addWrite_STATUS2_REMOTE(int value)
{
return (prepareWriteVarByCtIndex(ID_STATUS2_REMOTE, &value, NULL, 0) == ERROR);
}


int doWrite_STATUS2_DONE(int value)
{
return writeVarByCtIndex(ID_STATUS2_DONE,  &value);
}


int addWrite_STATUS2_DONE(int value)
{
return (prepareWriteVarByCtIndex(ID_STATUS2_DONE, &value, NULL, 0) == ERROR);
}


int doWrite_STARTx_REMOTE(int value)
{
return writeVarByCtIndex(ID_STARTx_REMOTE,  &value);
}


int addWrite_STARTx_REMOTE(int value)
{
return (prepareWriteVarByCtIndex(ID_STARTx_REMOTE, &value, NULL, 0) == ERROR);
}


int doWrite_STARTx_TEST(int value)
{
return writeVarByCtIndex(ID_STARTx_TEST,  &value);
}


int addWrite_STARTx_TEST(int value)
{
return (prepareWriteVarByCtIndex(ID_STARTx_TEST, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_1(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_1,  &value);
}


int addWrite_TSTx_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_2(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_2,  &value);
}


int addWrite_TSTx_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_3(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_3,  &value);
}


int addWrite_TSTx_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_4(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_4,  &value);
}


int addWrite_TSTx_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_5(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_5,  &value);
}


int addWrite_TSTx_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_6(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_6,  &value);
}


int addWrite_TSTx_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_7(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_7,  &value);
}


int addWrite_TSTx_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_8(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_8,  &value);
}


int addWrite_TSTx_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_9(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_9,  &value);
}


int addWrite_TSTx_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_10(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_10,  &value);
}


int addWrite_TSTx_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_11(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_11,  &value);
}


int addWrite_TSTx_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_12(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_12,  &value);
}


int addWrite_TSTx_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_13(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_13,  &value);
}


int addWrite_TSTx_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_14(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_14,  &value);
}


int addWrite_TSTx_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_15(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_15,  &value);
}


int addWrite_TSTx_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigIn_16(int value)
{
return writeVarByCtIndex(ID_TSTx_DigIn_16,  &value);
}


int addWrite_TSTx_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_1(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_1,  &value);
}


int addWrite_VALx_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_2(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_2,  &value);
}


int addWrite_VALx_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_3(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_3,  &value);
}


int addWrite_VALx_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_4(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_4,  &value);
}


int addWrite_VALx_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_5(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_5,  &value);
}


int addWrite_VALx_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_6(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_6,  &value);
}


int addWrite_VALx_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_7(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_7,  &value);
}


int addWrite_VALx_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_8(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_8,  &value);
}


int addWrite_VALx_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_9(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_9,  &value);
}


int addWrite_VALx_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_10(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_10,  &value);
}


int addWrite_VALx_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_11(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_11,  &value);
}


int addWrite_VALx_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_12(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_12,  &value);
}


int addWrite_VALx_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_13(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_13,  &value);
}


int addWrite_VALx_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_14(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_14,  &value);
}


int addWrite_VALx_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_15(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_15,  &value);
}


int addWrite_VALx_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigIn_16(int value)
{
return writeVarByCtIndex(ID_VALx_DigIn_16,  &value);
}


int addWrite_VALx_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_1(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_1,  &value);
}


int addWrite_RESx_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_2(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_2,  &value);
}


int addWrite_RESx_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_3(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_3,  &value);
}


int addWrite_RESx_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_4(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_4,  &value);
}


int addWrite_RESx_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_5(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_5,  &value);
}


int addWrite_RESx_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_6(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_6,  &value);
}


int addWrite_RESx_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_7(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_7,  &value);
}


int addWrite_RESx_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_8(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_8,  &value);
}


int addWrite_RESx_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_9(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_9,  &value);
}


int addWrite_RESx_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_10(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_10,  &value);
}


int addWrite_RESx_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_11(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_11,  &value);
}


int addWrite_RESx_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_12(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_12,  &value);
}


int addWrite_RESx_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_13(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_13,  &value);
}


int addWrite_RESx_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_14(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_14,  &value);
}


int addWrite_RESx_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_15(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_15,  &value);
}


int addWrite_RESx_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigIn_16(int value)
{
return writeVarByCtIndex(ID_RESx_DigIn_16,  &value);
}


int addWrite_RESx_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_1(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_1,  &value);
}


int addWrite_TSTx_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_2(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_2,  &value);
}


int addWrite_TSTx_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_3(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_3,  &value);
}


int addWrite_TSTx_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_4(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_4,  &value);
}


int addWrite_TSTx_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_5(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_5,  &value);
}


int addWrite_TSTx_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_6(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_6,  &value);
}


int addWrite_TSTx_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_7(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_7,  &value);
}


int addWrite_TSTx_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_8(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_8,  &value);
}


int addWrite_TSTx_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_9(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_9,  &value);
}


int addWrite_TSTx_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_10(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_10,  &value);
}


int addWrite_TSTx_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_11(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_11,  &value);
}


int addWrite_TSTx_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_12(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_12,  &value);
}


int addWrite_TSTx_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_13(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_13,  &value);
}


int addWrite_TSTx_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_14(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_14,  &value);
}


int addWrite_TSTx_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_15(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_15,  &value);
}


int addWrite_TSTx_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_DigOut_16(int value)
{
return writeVarByCtIndex(ID_TSTx_DigOut_16,  &value);
}


int addWrite_TSTx_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_1(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_1,  &value);
}


int addWrite_VALx_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_2(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_2,  &value);
}


int addWrite_VALx_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_3(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_3,  &value);
}


int addWrite_VALx_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_4(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_4,  &value);
}


int addWrite_VALx_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_5(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_5,  &value);
}


int addWrite_VALx_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_6(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_6,  &value);
}


int addWrite_VALx_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_7(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_7,  &value);
}


int addWrite_VALx_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_8(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_8,  &value);
}


int addWrite_VALx_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_9(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_9,  &value);
}


int addWrite_VALx_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_10(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_10,  &value);
}


int addWrite_VALx_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_11(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_11,  &value);
}


int addWrite_VALx_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_12(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_12,  &value);
}


int addWrite_VALx_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_13(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_13,  &value);
}


int addWrite_VALx_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_14(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_14,  &value);
}


int addWrite_VALx_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_15(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_15,  &value);
}


int addWrite_VALx_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_DigOut_16(int value)
{
return writeVarByCtIndex(ID_VALx_DigOut_16,  &value);
}


int addWrite_VALx_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_1(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_1,  &value);
}


int addWrite_RESx_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_2(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_2,  &value);
}


int addWrite_RESx_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_3(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_3,  &value);
}


int addWrite_RESx_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_4(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_4,  &value);
}


int addWrite_RESx_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_5(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_5,  &value);
}


int addWrite_RESx_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_6(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_6,  &value);
}


int addWrite_RESx_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_7(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_7,  &value);
}


int addWrite_RESx_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_8(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_8,  &value);
}


int addWrite_RESx_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_9(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_9,  &value);
}


int addWrite_RESx_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_10(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_10,  &value);
}


int addWrite_RESx_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_11(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_11,  &value);
}


int addWrite_RESx_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_12(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_12,  &value);
}


int addWrite_RESx_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_13(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_13,  &value);
}


int addWrite_RESx_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_14(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_14,  &value);
}


int addWrite_RESx_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_15(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_15,  &value);
}


int addWrite_RESx_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_DigOut_16(int value)
{
return writeVarByCtIndex(ID_RESx_DigOut_16,  &value);
}


int addWrite_RESx_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_1(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_1,  &value);
}


int addWrite_TSTx_AnIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_2(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_2,  &value);
}


int addWrite_TSTx_AnIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_3(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_3,  &value);
}


int addWrite_TSTx_AnIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_4(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_4,  &value);
}


int addWrite_TSTx_AnIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_5(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_5,  &value);
}


int addWrite_TSTx_AnIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_6(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_6,  &value);
}


int addWrite_TSTx_AnIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_7(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_7,  &value);
}


int addWrite_TSTx_AnIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_8(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_8,  &value);
}


int addWrite_TSTx_AnIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_9(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_9,  &value);
}


int addWrite_TSTx_AnIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_10(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_10,  &value);
}


int addWrite_TSTx_AnIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_11(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_11,  &value);
}


int addWrite_TSTx_AnIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnIn_12(int value)
{
return writeVarByCtIndex(ID_TSTx_AnIn_12,  &value);
}


int addWrite_TSTx_AnIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_1,  &value);
}


int addWrite_VALx_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_2,  &value);
}


int addWrite_VALx_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_3,  &value);
}


int addWrite_VALx_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_4,  &value);
}


int addWrite_VALx_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_5,  &value);
}


int addWrite_VALx_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_6,  &value);
}


int addWrite_VALx_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_7,  &value);
}


int addWrite_VALx_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_8,  &value);
}


int addWrite_VALx_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_9(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_9,  &value);
}


int addWrite_VALx_AnIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_10(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_10,  &value);
}


int addWrite_VALx_AnIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_11(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_11,  &value);
}


int addWrite_VALx_AnIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnIn_12(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnIn_12,  &value);
}


int addWrite_VALx_AnIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_1,  &value);
}


int addWrite_VALx_AnInConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_2,  &value);
}


int addWrite_VALx_AnInConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_3,  &value);
}


int addWrite_VALx_AnInConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_4,  &value);
}


int addWrite_VALx_AnInConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_5(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_5,  &value);
}


int addWrite_VALx_AnInConf_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_5, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_6(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_6,  &value);
}


int addWrite_VALx_AnInConf_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_6, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_7(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_7,  &value);
}


int addWrite_VALx_AnInConf_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_7, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_8(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_8,  &value);
}


int addWrite_VALx_AnInConf_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_8, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_9(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_9,  &value);
}


int addWrite_VALx_AnInConf_9(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_9, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_10(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_10,  &value);
}


int addWrite_VALx_AnInConf_10(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_10, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_11(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_11,  &value);
}


int addWrite_VALx_AnInConf_11(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_11, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInConf_12(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInConf_12,  &value);
}


int addWrite_VALx_AnInConf_12(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInConf_12, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_1,  &value);
}


int addWrite_VALx_AnInFltr_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_1, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_2,  &value);
}


int addWrite_VALx_AnInFltr_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_2, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_3,  &value);
}


int addWrite_VALx_AnInFltr_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_3, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_4,  &value);
}


int addWrite_VALx_AnInFltr_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_4, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_5(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_5,  &value);
}


int addWrite_VALx_AnInFltr_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_5, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_6(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_6,  &value);
}


int addWrite_VALx_AnInFltr_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_6, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_7(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_7,  &value);
}


int addWrite_VALx_AnInFltr_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_7, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_8(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_8,  &value);
}


int addWrite_VALx_AnInFltr_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_8, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_9(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_9,  &value);
}


int addWrite_VALx_AnInFltr_9(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_9, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_10(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_10,  &value);
}


int addWrite_VALx_AnInFltr_10(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_10, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_11(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_11,  &value);
}


int addWrite_VALx_AnInFltr_11(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_11, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnInFltr_12(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnInFltr_12,  &value);
}


int addWrite_VALx_AnInFltr_12(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnInFltr_12, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_1,  &value);
}


int addWrite_RESx_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_2,  &value);
}


int addWrite_RESx_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_3,  &value);
}


int addWrite_RESx_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_4,  &value);
}


int addWrite_RESx_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_5,  &value);
}


int addWrite_RESx_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_6,  &value);
}


int addWrite_RESx_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_7,  &value);
}


int addWrite_RESx_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_8,  &value);
}


int addWrite_RESx_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_9(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_9,  &value);
}


int addWrite_RESx_AnIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_10(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_10,  &value);
}


int addWrite_RESx_AnIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_11(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_11,  &value);
}


int addWrite_RESx_AnIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnIn_12(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnIn_12,  &value);
}


int addWrite_RESx_AnIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_1(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_1,  &value);
}


int addWrite_RESx_AnInStts_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_1, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_2(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_2,  &value);
}


int addWrite_RESx_AnInStts_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_2, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_3(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_3,  &value);
}


int addWrite_RESx_AnInStts_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_3, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_4(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_4,  &value);
}


int addWrite_RESx_AnInStts_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_4, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_5(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_5,  &value);
}


int addWrite_RESx_AnInStts_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_5, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_6(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_6,  &value);
}


int addWrite_RESx_AnInStts_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_6, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_7(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_7,  &value);
}


int addWrite_RESx_AnInStts_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_7, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_8(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_8,  &value);
}


int addWrite_RESx_AnInStts_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_8, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_9(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_9,  &value);
}


int addWrite_RESx_AnInStts_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_9, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_10(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_10,  &value);
}


int addWrite_RESx_AnInStts_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_10, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_11(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_11,  &value);
}


int addWrite_RESx_AnInStts_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_11, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnInStts_12(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnInStts_12,  &value);
}


int addWrite_RESx_AnInStts_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnInStts_12, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnOut_1(int value)
{
return writeVarByCtIndex(ID_TSTx_AnOut_1,  &value);
}


int addWrite_TSTx_AnOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnOut_2(int value)
{
return writeVarByCtIndex(ID_TSTx_AnOut_2,  &value);
}


int addWrite_TSTx_AnOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnOut_3(int value)
{
return writeVarByCtIndex(ID_TSTx_AnOut_3,  &value);
}


int addWrite_TSTx_AnOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_AnOut_4(int value)
{
return writeVarByCtIndex(ID_TSTx_AnOut_4,  &value);
}


int addWrite_TSTx_AnOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOut_1,  &value);
}


int addWrite_VALx_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOut_2,  &value);
}


int addWrite_VALx_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOut_3,  &value);
}


int addWrite_VALx_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOut_4,  &value);
}


int addWrite_VALx_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOutConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOutConf_1,  &value);
}


int addWrite_VALx_AnOutConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOutConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOutConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOutConf_2,  &value);
}


int addWrite_VALx_AnOutConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOutConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOutConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOutConf_3,  &value);
}


int addWrite_VALx_AnOutConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOutConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_AnOutConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_AnOutConf_4,  &value);
}


int addWrite_VALx_AnOutConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_AnOutConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnOutStts_1(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnOutStts_1,  &value);
}


int addWrite_RESx_AnOutStts_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnOutStts_1, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnOutStts_2(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnOutStts_2,  &value);
}


int addWrite_RESx_AnOutStts_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnOutStts_2, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnOutStts_3(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnOutStts_3,  &value);
}


int addWrite_RESx_AnOutStts_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnOutStts_3, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_AnOutStts_4(int16_t value)
{
return writeVarByCtIndex(ID_RESx_AnOutStts_4,  &value);
}


int addWrite_RESx_AnOutStts_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_AnOutStts_4, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_Tamb(int value)
{
return writeVarByCtIndex(ID_TSTx_Tamb,  &value);
}


int addWrite_TSTx_Tamb(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_RPM(int value)
{
return writeVarByCtIndex(ID_TSTx_RPM,  &value);
}


int addWrite_TSTx_RPM(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_FWrevision(int value)
{
return writeVarByCtIndex(ID_TSTx_FWrevision,  &value);
}


int addWrite_TSTx_FWrevision(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_HWconfig(int value)
{
return writeVarByCtIndex(ID_TSTx_HWconfig,  &value);
}


int addWrite_TSTx_HWconfig(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_VALx_Tamb,  &value);
}


int addWrite_VALx_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_RPM,  &value);
}


int addWrite_VALx_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_FWrevision,  &value);
}


int addWrite_VALx_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_VALx_HWconfig,  &value);
}


int addWrite_VALx_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VALx_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_RESx_Tamb,  &value);
}


int addWrite_RESx_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_RESx_RPM,  &value);
}


int addWrite_RESx_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_RESx_FWrevision,  &value);
}


int addWrite_RESx_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_RESx_HWconfig,  &value);
}


int addWrite_RESx_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RESx_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_TSTx_RTUS_WR,  &value);
}


int addWrite_TSTx_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_TSTx_RTUS_RD,  &value);
}


int addWrite_TSTx_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_TSTx_RTU1_WR,  &value);
}


int addWrite_TSTx_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_TSTx_RTU1_RD,  &value);
}


int addWrite_TSTx_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_TSTx_RTU3_WR,  &value);
}


int addWrite_TSTx_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_TSTx_RTU3_RD,  &value);
}


int addWrite_TSTx_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_TSTx_CAN1_WR,  &value);
}


int addWrite_TSTx_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_TSTx_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_TSTx_CAN1_RD,  &value);
}


int addWrite_TSTx_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_TSTx_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_VALx_RTUS_WR,  &value);
}


int addWrite_VALx_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_VALx_RTUS_RD,  &value);
}


int addWrite_VALx_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_VALx_RTU1_WR,  &value);
}


int addWrite_VALx_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_VALx_RTU1_RD,  &value);
}


int addWrite_VALx_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_VALx_RTU3_WR,  &value);
}


int addWrite_VALx_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_VALx_RTU3_RD,  &value);
}


int addWrite_VALx_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_VALx_CAN1_WR,  &value);
}


int addWrite_VALx_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_VALx_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_VALx_CAN1_RD,  &value);
}


int addWrite_VALx_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_VALx_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_RTUS_WR(int value)
{
return writeVarByCtIndex(ID_RESx_RTUS_WR,  &value);
}


int addWrite_RESx_RTUS_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_RTUS_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_RTUS_RD(int value)
{
return writeVarByCtIndex(ID_RESx_RTUS_RD,  &value);
}


int addWrite_RESx_RTUS_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_RTUS_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_RTU1_WR(int value)
{
return writeVarByCtIndex(ID_RESx_RTU1_WR,  &value);
}


int addWrite_RESx_RTU1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_RTU1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_RTU1_RD(int value)
{
return writeVarByCtIndex(ID_RESx_RTU1_RD,  &value);
}


int addWrite_RESx_RTU1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_RTU1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_RTU3_WR(int value)
{
return writeVarByCtIndex(ID_RESx_RTU3_WR,  &value);
}


int addWrite_RESx_RTU3_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_RTU3_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_RTU3_RD(int value)
{
return writeVarByCtIndex(ID_RESx_RTU3_RD,  &value);
}


int addWrite_RESx_RTU3_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_RTU3_RD, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_CAN1_WR(int value)
{
return writeVarByCtIndex(ID_RESx_CAN1_WR,  &value);
}


int addWrite_RESx_CAN1_WR(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_CAN1_WR, &value, NULL, 0) == ERROR);
}


int doWrite_RESx_CAN1_RD(int value)
{
return writeVarByCtIndex(ID_RESx_CAN1_RD,  &value);
}


int addWrite_RESx_CAN1_RD(int value)
{
return (prepareWriteVarByCtIndex(ID_RESx_CAN1_RD, &value, NULL, 0) == ERROR);
}


int doWrite_STATUSx_LOCAL(int value)
{
return writeVarByCtIndex(ID_STATUSx_LOCAL,  &value);
}


int addWrite_STATUSx_LOCAL(int value)
{
return (prepareWriteVarByCtIndex(ID_STATUSx_LOCAL, &value, NULL, 0) == ERROR);
}


int doWrite_STATUSx_REMOTE(int value)
{
return writeVarByCtIndex(ID_STATUSx_REMOTE,  &value);
}


int addWrite_STATUSx_REMOTE(int value)
{
return (prepareWriteVarByCtIndex(ID_STATUSx_REMOTE, &value, NULL, 0) == ERROR);
}


int doWrite_STATUSx_DONE(int value)
{
return writeVarByCtIndex(ID_STATUSx_DONE,  &value);
}


int addWrite_STATUSx_DONE(int value)
{
return (prepareWriteVarByCtIndex(ID_STATUSx_DONE, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_1(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_1,  &value);
}


int addWrite_RTU_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_2(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_2,  &value);
}


int addWrite_RTU_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_3(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_3,  &value);
}


int addWrite_RTU_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_4(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_4,  &value);
}


int addWrite_RTU_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_5(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_5,  &value);
}


int addWrite_RTU_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_6(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_6,  &value);
}


int addWrite_RTU_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_7(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_7,  &value);
}


int addWrite_RTU_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_8(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_8,  &value);
}


int addWrite_RTU_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_9(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_9,  &value);
}


int addWrite_RTU_DigIn_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_10(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_10,  &value);
}


int addWrite_RTU_DigIn_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_11(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_11,  &value);
}


int addWrite_RTU_DigIn_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_12(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_12,  &value);
}


int addWrite_RTU_DigIn_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_13(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_13,  &value);
}


int addWrite_RTU_DigIn_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_14(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_14,  &value);
}


int addWrite_RTU_DigIn_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_15(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_15,  &value);
}


int addWrite_RTU_DigIn_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigIn_16(int value)
{
return writeVarByCtIndex(ID_RTU_DigIn_16,  &value);
}


int addWrite_RTU_DigIn_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnIn_1,  &value);
}


int addWrite_RTU_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnIn_2,  &value);
}


int addWrite_RTU_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_RTU_Tamb,  &value);
}


int addWrite_RTU_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_1(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_1,  &value);
}


int addWrite_RTU_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_2(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_2,  &value);
}


int addWrite_RTU_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_3(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_3,  &value);
}


int addWrite_RTU_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_4(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_4,  &value);
}


int addWrite_RTU_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_5(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_5,  &value);
}


int addWrite_RTU_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_6(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_6,  &value);
}


int addWrite_RTU_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_7(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_7,  &value);
}


int addWrite_RTU_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_8(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_8,  &value);
}


int addWrite_RTU_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_9(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_9,  &value);
}


int addWrite_RTU_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_10(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_10,  &value);
}


int addWrite_RTU_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_11(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_11,  &value);
}


int addWrite_RTU_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_12(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_12,  &value);
}


int addWrite_RTU_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_13(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_13,  &value);
}


int addWrite_RTU_DigOut_13(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_14(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_14,  &value);
}


int addWrite_RTU_DigOut_14(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_15(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_15,  &value);
}


int addWrite_RTU_DigOut_15(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_DigOut_16(int value)
{
return writeVarByCtIndex(ID_RTU_DigOut_16,  &value);
}


int addWrite_RTU_DigOut_16(int value)
{
return (prepareWriteVarByCtIndex(ID_RTU_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOutConf_X(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOutConf_X,  &value);
}


int addWrite_RTU_AnOutConf_X(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOutConf_X, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_1,  &value);
}


int addWrite_RTU_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_2,  &value);
}


int addWrite_RTU_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_3,  &value);
}


int addWrite_RTU_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_4,  &value);
}


int addWrite_RTU_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_5(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_5,  &value);
}


int addWrite_RTU_AnOut_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_6(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_6,  &value);
}


int addWrite_RTU_AnOut_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_7(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_7,  &value);
}


int addWrite_RTU_AnOut_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnOut_8(int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnOut_8,  &value);
}


int addWrite_RTU_AnOut_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnInConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnInConf_1,  &value);
}


int addWrite_RTU_AnInConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnInConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_AnInConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_RTU_AnInConf_2,  &value);
}


int addWrite_RTU_AnInConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_AnInConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_RTU_HeartBeat(u_int32_t value)
{
return writeVarByCtIndex(ID_RTU_HeartBeat,  &value);
}


int addWrite_RTU_HeartBeat(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_RTU_HeartBeat, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_FWrevision(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_FWrevision,  &value);
}


int addWrite_PLC_FWrevision(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_FWrevision, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_HWconfig(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_HWconfig,  &value);
}


int addWrite_PLC_HWconfig(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_HWconfig, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_1(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_1,  &value);
}


int addWrite_PLC_DigDir_1(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_2(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_2,  &value);
}


int addWrite_PLC_DigDir_2(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_3(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_3,  &value);
}


int addWrite_PLC_DigDir_3(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_4(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_4,  &value);
}


int addWrite_PLC_DigDir_4(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_5(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_5,  &value);
}


int addWrite_PLC_DigDir_5(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_6(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_6,  &value);
}


int addWrite_PLC_DigDir_6(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_7(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_7,  &value);
}


int addWrite_PLC_DigDir_7(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_8(int value)
{
return writeVarByCtIndex(ID_PLC_DigDir_8,  &value);
}


int addWrite_PLC_DigDir_8(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_8, &value, NULL, 0) == ERROR);
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


int doWrite_PLC_AnOutConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_1,  &value);
}


int addWrite_PLC_AnOutConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_2,  &value);
}


int addWrite_PLC_AnOutConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_3,  &value);
}


int addWrite_PLC_AnOutConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_4,  &value);
}


int addWrite_PLC_AnOutConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_4, &value, NULL, 0) == ERROR);
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


int doWrite_PLC_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_3,  &value);
}


int addWrite_PLC_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_4,  &value);
}


int addWrite_PLC_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_5,  &value);
}


int addWrite_PLC_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_PLC_Tamb,  &value);
}


int addWrite_PLC_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_Encoder(u_int32_t value)
{
return writeVarByCtIndex(ID_PLC_Encoder,  &value);
}


int addWrite_PLC_Encoder(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_Encoder, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_Capture(u_int32_t value)
{
return writeVarByCtIndex(ID_PLC_Capture,  &value);
}


int addWrite_PLC_Capture(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_Capture, &value, NULL, 0) == ERROR);
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


int doWrite_PLC_EncoderStart(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncoderStart,  &value);
}


int addWrite_PLC_EncoderStart(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncoderStart, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_EncoderReset(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncoderReset,  &value);
}


int addWrite_PLC_EncoderReset(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncoderReset, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_Heartbeat(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_Heartbeat,  &value);
}


int addWrite_PLC_Heartbeat(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_Heartbeat, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_StatusReg(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_StatusReg,  &value);
}


int addWrite_PLC_StatusReg(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_StatusReg, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn1Filter(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn1Filter,  &value);
}


int addWrite_PLC_AnIn1Filter(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn1Filter, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn2Filter(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn2Filter,  &value);
}


int addWrite_PLC_AnIn2Filter(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn2Filter, &value, NULL, 0) == ERROR);
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
    static bool first = true;
int retval = 0;
retval += readFromDb(ID_PRODUCT_ID, &PRODUCT_ID);
retval += readFromDb(ID_SERIAL_NUMBER, &SERIAL_NUMBER);
retval += readFromDb(ID_TEST_STEP, &TEST_STEP);
retval += readFromDb(ID_TEST_DATE, &TEST_DATE);
retval += readFromDb(ID_TEST_TIME, &TEST_TIME);
retval += readFromDb(ID_TEST_DURATION, &TEST_DURATION);
retval += readFromDb(ID_DO_REMOTE, &DO_REMOTE);
retval += readFromDb(ID_DO_TEST, &DO_TEST);
retval += readFromDb(ID_STATUS, &STATUS);
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
retval += readFromDb(ID_VAL_AnOut_1, &VAL_AnOut_1);
retval += readFromDb(ID_VAL_AnOut_2, &VAL_AnOut_2);
retval += readFromDb(ID_VAL_AnOut_3, &VAL_AnOut_3);
retval += readFromDb(ID_VAL_AnOut_4, &VAL_AnOut_4);
retval += readFromDb(ID_VAL_AnOutConf_1, &VAL_AnOutConf_1);
retval += readFromDb(ID_VAL_AnOutConf_2, &VAL_AnOutConf_2);
retval += readFromDb(ID_VAL_AnOutConf_3, &VAL_AnOutConf_3);
retval += readFromDb(ID_VAL_AnOutConf_4, &VAL_AnOutConf_4);
retval += readFromDb(ID_RES_AnOut_1, &RES_AnOut_1);
retval += readFromDb(ID_RES_AnOut_2, &RES_AnOut_2);
retval += readFromDb(ID_RES_AnOut_3, &RES_AnOut_3);
retval += readFromDb(ID_RES_AnOut_4, &RES_AnOut_4);
retval += readFromDb(ID_RES_AnOutStts_1, &RES_AnOutStts_1);
retval += readFromDb(ID_RES_AnOutStts_2, &RES_AnOutStts_2);
retval += readFromDb(ID_RES_AnOutStts_3, &RES_AnOutStts_3);
retval += readFromDb(ID_RES_AnOutStts_4, &RES_AnOutStts_4);
retval += readFromDb(ID_OK_AnOut_1, &OK_AnOut_1);
retval += readFromDb(ID_OK_AnOut_2, &OK_AnOut_2);
retval += readFromDb(ID_OK_AnOut_3, &OK_AnOut_3);
retval += readFromDb(ID_OK_AnOut_4, &OK_AnOut_4);
retval += readFromDb(ID_TST_Tamb, &TST_Tamb);
retval += readFromDb(ID_TST_RPM, &TST_RPM);
retval += readFromDb(ID_TST_VCC_set, &TST_VCC_set);
retval += readFromDb(ID_TST_mA_max, &TST_mA_max);
retval += readFromDb(ID_TST_VCC_fbk, &TST_VCC_fbk);
retval += readFromDb(ID_TST_mA_fbk, &TST_mA_fbk);
retval += readFromDb(ID_TST_FWrevision, &TST_FWrevision);
retval += readFromDb(ID_TST_HWconfig, &TST_HWconfig);
retval += readFromDb(ID_VAL_Tamb, &VAL_Tamb);
retval += readFromDb(ID_VAL_RPM, &VAL_RPM);
retval += readFromDb(ID_VAL_VCC_set, &VAL_VCC_set);
retval += readFromDb(ID_VAL_mA_max, &VAL_mA_max);
retval += readFromDb(ID_VAL_VCC_fbk, &VAL_VCC_fbk);
retval += readFromDb(ID_VAL_mA_fbk, &VAL_mA_fbk);
retval += readFromDb(ID_VAL_FWrevision, &VAL_FWrevision);
retval += readFromDb(ID_VAL_HWconfig, &VAL_HWconfig);
retval += readFromDb(ID_RES_Tamb, &RES_Tamb);
retval += readFromDb(ID_RES_RPM, &RES_RPM);
retval += readFromDb(ID_RES_VCC_set, &RES_VCC_set);
retval += readFromDb(ID_RES_mA_max, &RES_mA_max);
retval += readFromDb(ID_RES_VCC_fbk, &RES_VCC_fbk);
retval += readFromDb(ID_RES_mA_fbk, &RES_mA_fbk);
retval += readFromDb(ID_RES_FWrevision, &RES_FWrevision);
retval += readFromDb(ID_RES_HWconfig, &RES_HWconfig);
retval += readFromDb(ID_OK_Tamb, &OK_Tamb);
retval += readFromDb(ID_OK_RPM, &OK_RPM);
retval += readFromDb(ID_OK_VCC_set, &OK_VCC_set);
retval += readFromDb(ID_OK_mA_max, &OK_mA_max);
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
retval += readFromDb(ID_START2_REMOTE, &START2_REMOTE);
retval += readFromDb(ID_START2_TEST, &START2_TEST);
retval += readFromDb(ID_TST2_DigIn_1, &TST2_DigIn_1);
retval += readFromDb(ID_TST2_DigIn_2, &TST2_DigIn_2);
retval += readFromDb(ID_TST2_DigIn_3, &TST2_DigIn_3);
retval += readFromDb(ID_TST2_DigIn_4, &TST2_DigIn_4);
retval += readFromDb(ID_TST2_DigIn_5, &TST2_DigIn_5);
retval += readFromDb(ID_TST2_DigIn_6, &TST2_DigIn_6);
retval += readFromDb(ID_TST2_DigIn_7, &TST2_DigIn_7);
retval += readFromDb(ID_TST2_DigIn_8, &TST2_DigIn_8);
retval += readFromDb(ID_TST2_DigIn_9, &TST2_DigIn_9);
retval += readFromDb(ID_TST2_DigIn_10, &TST2_DigIn_10);
retval += readFromDb(ID_TST2_DigIn_11, &TST2_DigIn_11);
retval += readFromDb(ID_TST2_DigIn_12, &TST2_DigIn_12);
retval += readFromDb(ID_TST2_DigIn_13, &TST2_DigIn_13);
retval += readFromDb(ID_TST2_DigIn_14, &TST2_DigIn_14);
retval += readFromDb(ID_TST2_DigIn_15, &TST2_DigIn_15);
retval += readFromDb(ID_TST2_DigIn_16, &TST2_DigIn_16);
retval += readFromDb(ID_VAL2_DigIn_1, &VAL2_DigIn_1);
retval += readFromDb(ID_VAL2_DigIn_2, &VAL2_DigIn_2);
retval += readFromDb(ID_VAL2_DigIn_3, &VAL2_DigIn_3);
retval += readFromDb(ID_VAL2_DigIn_4, &VAL2_DigIn_4);
retval += readFromDb(ID_VAL2_DigIn_5, &VAL2_DigIn_5);
retval += readFromDb(ID_VAL2_DigIn_6, &VAL2_DigIn_6);
retval += readFromDb(ID_VAL2_DigIn_7, &VAL2_DigIn_7);
retval += readFromDb(ID_VAL2_DigIn_8, &VAL2_DigIn_8);
retval += readFromDb(ID_VAL2_DigIn_9, &VAL2_DigIn_9);
retval += readFromDb(ID_VAL2_DigIn_10, &VAL2_DigIn_10);
retval += readFromDb(ID_VAL2_DigIn_11, &VAL2_DigIn_11);
retval += readFromDb(ID_VAL2_DigIn_12, &VAL2_DigIn_12);
retval += readFromDb(ID_VAL2_DigIn_13, &VAL2_DigIn_13);
retval += readFromDb(ID_VAL2_DigIn_14, &VAL2_DigIn_14);
retval += readFromDb(ID_VAL2_DigIn_15, &VAL2_DigIn_15);
retval += readFromDb(ID_VAL2_DigIn_16, &VAL2_DigIn_16);
retval += readFromDb(ID_RES2_DigIn_1, &RES2_DigIn_1);
retval += readFromDb(ID_RES2_DigIn_2, &RES2_DigIn_2);
retval += readFromDb(ID_RES2_DigIn_3, &RES2_DigIn_3);
retval += readFromDb(ID_RES2_DigIn_4, &RES2_DigIn_4);
retval += readFromDb(ID_RES2_DigIn_5, &RES2_DigIn_5);
retval += readFromDb(ID_RES2_DigIn_6, &RES2_DigIn_6);
retval += readFromDb(ID_RES2_DigIn_7, &RES2_DigIn_7);
retval += readFromDb(ID_RES2_DigIn_8, &RES2_DigIn_8);
retval += readFromDb(ID_RES2_DigIn_9, &RES2_DigIn_9);
retval += readFromDb(ID_RES2_DigIn_10, &RES2_DigIn_10);
retval += readFromDb(ID_RES2_DigIn_11, &RES2_DigIn_11);
retval += readFromDb(ID_RES2_DigIn_12, &RES2_DigIn_12);
retval += readFromDb(ID_RES2_DigIn_13, &RES2_DigIn_13);
retval += readFromDb(ID_RES2_DigIn_14, &RES2_DigIn_14);
retval += readFromDb(ID_RES2_DigIn_15, &RES2_DigIn_15);
retval += readFromDb(ID_RES2_DigIn_16, &RES2_DigIn_16);
retval += readFromDb(ID_TST2_DigOut_1, &TST2_DigOut_1);
retval += readFromDb(ID_TST2_DigOut_2, &TST2_DigOut_2);
retval += readFromDb(ID_TST2_DigOut_3, &TST2_DigOut_3);
retval += readFromDb(ID_TST2_DigOut_4, &TST2_DigOut_4);
retval += readFromDb(ID_TST2_DigOut_5, &TST2_DigOut_5);
retval += readFromDb(ID_TST2_DigOut_6, &TST2_DigOut_6);
retval += readFromDb(ID_TST2_DigOut_7, &TST2_DigOut_7);
retval += readFromDb(ID_TST2_DigOut_8, &TST2_DigOut_8);
retval += readFromDb(ID_TST2_DigOut_9, &TST2_DigOut_9);
retval += readFromDb(ID_TST2_DigOut_10, &TST2_DigOut_10);
retval += readFromDb(ID_TST2_DigOut_11, &TST2_DigOut_11);
retval += readFromDb(ID_TST2_DigOut_12, &TST2_DigOut_12);
retval += readFromDb(ID_TST2_DigOut_13, &TST2_DigOut_13);
retval += readFromDb(ID_TST2_DigOut_14, &TST2_DigOut_14);
retval += readFromDb(ID_TST2_DigOut_15, &TST2_DigOut_15);
retval += readFromDb(ID_TST2_DigOut_16, &TST2_DigOut_16);
retval += readFromDb(ID_VAL2_DigOut_1, &VAL2_DigOut_1);
retval += readFromDb(ID_VAL2_DigOut_2, &VAL2_DigOut_2);
retval += readFromDb(ID_VAL2_DigOut_3, &VAL2_DigOut_3);
retval += readFromDb(ID_VAL2_DigOut_4, &VAL2_DigOut_4);
retval += readFromDb(ID_VAL2_DigOut_5, &VAL2_DigOut_5);
retval += readFromDb(ID_VAL2_DigOut_6, &VAL2_DigOut_6);
retval += readFromDb(ID_VAL2_DigOut_7, &VAL2_DigOut_7);
retval += readFromDb(ID_VAL2_DigOut_8, &VAL2_DigOut_8);
retval += readFromDb(ID_VAL2_DigOut_9, &VAL2_DigOut_9);
retval += readFromDb(ID_VAL2_DigOut_10, &VAL2_DigOut_10);
retval += readFromDb(ID_VAL2_DigOut_11, &VAL2_DigOut_11);
retval += readFromDb(ID_VAL2_DigOut_12, &VAL2_DigOut_12);
retval += readFromDb(ID_VAL2_DigOut_13, &VAL2_DigOut_13);
retval += readFromDb(ID_VAL2_DigOut_14, &VAL2_DigOut_14);
retval += readFromDb(ID_VAL2_DigOut_15, &VAL2_DigOut_15);
retval += readFromDb(ID_VAL2_DigOut_16, &VAL2_DigOut_16);
retval += readFromDb(ID_RES2_DigOut_1, &RES2_DigOut_1);
retval += readFromDb(ID_RES2_DigOut_2, &RES2_DigOut_2);
retval += readFromDb(ID_RES2_DigOut_3, &RES2_DigOut_3);
retval += readFromDb(ID_RES2_DigOut_4, &RES2_DigOut_4);
retval += readFromDb(ID_RES2_DigOut_5, &RES2_DigOut_5);
retval += readFromDb(ID_RES2_DigOut_6, &RES2_DigOut_6);
retval += readFromDb(ID_RES2_DigOut_7, &RES2_DigOut_7);
retval += readFromDb(ID_RES2_DigOut_8, &RES2_DigOut_8);
retval += readFromDb(ID_RES2_DigOut_9, &RES2_DigOut_9);
retval += readFromDb(ID_RES2_DigOut_10, &RES2_DigOut_10);
retval += readFromDb(ID_RES2_DigOut_11, &RES2_DigOut_11);
retval += readFromDb(ID_RES2_DigOut_12, &RES2_DigOut_12);
retval += readFromDb(ID_RES2_DigOut_13, &RES2_DigOut_13);
retval += readFromDb(ID_RES2_DigOut_14, &RES2_DigOut_14);
retval += readFromDb(ID_RES2_DigOut_15, &RES2_DigOut_15);
retval += readFromDb(ID_RES2_DigOut_16, &RES2_DigOut_16);
retval += readFromDb(ID_TST2_AnIn_1, &TST2_AnIn_1);
retval += readFromDb(ID_TST2_AnIn_2, &TST2_AnIn_2);
retval += readFromDb(ID_TST2_AnIn_3, &TST2_AnIn_3);
retval += readFromDb(ID_TST2_AnIn_4, &TST2_AnIn_4);
retval += readFromDb(ID_TST2_AnIn_5, &TST2_AnIn_5);
retval += readFromDb(ID_TST2_AnIn_6, &TST2_AnIn_6);
retval += readFromDb(ID_TST2_AnIn_7, &TST2_AnIn_7);
retval += readFromDb(ID_TST2_AnIn_8, &TST2_AnIn_8);
retval += readFromDb(ID_TST2_AnIn_9, &TST2_AnIn_9);
retval += readFromDb(ID_TST2_AnIn_10, &TST2_AnIn_10);
retval += readFromDb(ID_TST2_AnIn_11, &TST2_AnIn_11);
retval += readFromDb(ID_TST2_AnIn_12, &TST2_AnIn_12);
retval += readFromDb(ID_VAL2_AnIn_1, &VAL2_AnIn_1);
retval += readFromDb(ID_VAL2_AnIn_2, &VAL2_AnIn_2);
retval += readFromDb(ID_VAL2_AnIn_3, &VAL2_AnIn_3);
retval += readFromDb(ID_VAL2_AnIn_4, &VAL2_AnIn_4);
retval += readFromDb(ID_VAL2_AnIn_5, &VAL2_AnIn_5);
retval += readFromDb(ID_VAL2_AnIn_6, &VAL2_AnIn_6);
retval += readFromDb(ID_VAL2_AnIn_7, &VAL2_AnIn_7);
retval += readFromDb(ID_VAL2_AnIn_8, &VAL2_AnIn_8);
retval += readFromDb(ID_VAL2_AnIn_9, &VAL2_AnIn_9);
retval += readFromDb(ID_VAL2_AnIn_10, &VAL2_AnIn_10);
retval += readFromDb(ID_VAL2_AnIn_11, &VAL2_AnIn_11);
retval += readFromDb(ID_VAL2_AnIn_12, &VAL2_AnIn_12);
retval += readFromDb(ID_VAL2_AnInConf_1, &VAL2_AnInConf_1);
retval += readFromDb(ID_VAL2_AnInConf_2, &VAL2_AnInConf_2);
retval += readFromDb(ID_VAL2_AnInConf_3, &VAL2_AnInConf_3);
retval += readFromDb(ID_VAL2_AnInConf_4, &VAL2_AnInConf_4);
retval += readFromDb(ID_VAL2_AnInConf_5, &VAL2_AnInConf_5);
retval += readFromDb(ID_VAL2_AnInConf_6, &VAL2_AnInConf_6);
retval += readFromDb(ID_VAL2_AnInConf_7, &VAL2_AnInConf_7);
retval += readFromDb(ID_VAL2_AnInConf_8, &VAL2_AnInConf_8);
retval += readFromDb(ID_VAL2_AnInConf_9, &VAL2_AnInConf_9);
retval += readFromDb(ID_VAL2_AnInConf_10, &VAL2_AnInConf_10);
retval += readFromDb(ID_VAL2_AnInConf_11, &VAL2_AnInConf_11);
retval += readFromDb(ID_VAL2_AnInConf_12, &VAL2_AnInConf_12);
retval += readFromDb(ID_VAL2_AnInFltr_1, &VAL2_AnInFltr_1);
retval += readFromDb(ID_VAL2_AnInFltr_2, &VAL2_AnInFltr_2);
retval += readFromDb(ID_VAL2_AnInFltr_3, &VAL2_AnInFltr_3);
retval += readFromDb(ID_VAL2_AnInFltr_4, &VAL2_AnInFltr_4);
retval += readFromDb(ID_VAL2_AnInFltr_5, &VAL2_AnInFltr_5);
retval += readFromDb(ID_VAL2_AnInFltr_6, &VAL2_AnInFltr_6);
retval += readFromDb(ID_VAL2_AnInFltr_7, &VAL2_AnInFltr_7);
retval += readFromDb(ID_VAL2_AnInFltr_8, &VAL2_AnInFltr_8);
retval += readFromDb(ID_VAL2_AnInFltr_9, &VAL2_AnInFltr_9);
retval += readFromDb(ID_VAL2_AnInFltr_10, &VAL2_AnInFltr_10);
retval += readFromDb(ID_VAL2_AnInFltr_11, &VAL2_AnInFltr_11);
retval += readFromDb(ID_VAL2_AnInFltr_12, &VAL2_AnInFltr_12);
retval += readFromDb(ID_RES2_AnIn_1, &RES2_AnIn_1);
retval += readFromDb(ID_RES2_AnIn_2, &RES2_AnIn_2);
retval += readFromDb(ID_RES2_AnIn_3, &RES2_AnIn_3);
retval += readFromDb(ID_RES2_AnIn_4, &RES2_AnIn_4);
retval += readFromDb(ID_RES2_AnIn_5, &RES2_AnIn_5);
retval += readFromDb(ID_RES2_AnIn_6, &RES2_AnIn_6);
retval += readFromDb(ID_RES2_AnIn_7, &RES2_AnIn_7);
retval += readFromDb(ID_RES2_AnIn_8, &RES2_AnIn_8);
retval += readFromDb(ID_RES2_AnIn_9, &RES2_AnIn_9);
retval += readFromDb(ID_RES2_AnIn_10, &RES2_AnIn_10);
retval += readFromDb(ID_RES2_AnIn_11, &RES2_AnIn_11);
retval += readFromDb(ID_RES2_AnIn_12, &RES2_AnIn_12);
retval += readFromDb(ID_RES2_AnInStts_1, &RES2_AnInStts_1);
retval += readFromDb(ID_RES2_AnInStts_2, &RES2_AnInStts_2);
retval += readFromDb(ID_RES2_AnInStts_3, &RES2_AnInStts_3);
retval += readFromDb(ID_RES2_AnInStts_4, &RES2_AnInStts_4);
retval += readFromDb(ID_RES2_AnInStts_5, &RES2_AnInStts_5);
retval += readFromDb(ID_RES2_AnInStts_6, &RES2_AnInStts_6);
retval += readFromDb(ID_RES2_AnInStts_7, &RES2_AnInStts_7);
retval += readFromDb(ID_RES2_AnInStts_8, &RES2_AnInStts_8);
retval += readFromDb(ID_RES2_AnInStts_9, &RES2_AnInStts_9);
retval += readFromDb(ID_RES2_AnInStts_10, &RES2_AnInStts_10);
retval += readFromDb(ID_RES2_AnInStts_11, &RES2_AnInStts_11);
retval += readFromDb(ID_RES2_AnInStts_12, &RES2_AnInStts_12);
retval += readFromDb(ID_TST2_AnOut_1, &TST2_AnOut_1);
retval += readFromDb(ID_TST2_AnOut_2, &TST2_AnOut_2);
retval += readFromDb(ID_TST2_AnOut_3, &TST2_AnOut_3);
retval += readFromDb(ID_TST2_AnOut_4, &TST2_AnOut_4);
retval += readFromDb(ID_VAL2_AnOut_1, &VAL2_AnOut_1);
retval += readFromDb(ID_VAL2_AnOut_2, &VAL2_AnOut_2);
retval += readFromDb(ID_VAL2_AnOut_3, &VAL2_AnOut_3);
retval += readFromDb(ID_VAL2_AnOut_4, &VAL2_AnOut_4);
retval += readFromDb(ID_VAL2_AnOutConf_1, &VAL2_AnOutConf_1);
retval += readFromDb(ID_VAL2_AnOutConf_2, &VAL2_AnOutConf_2);
retval += readFromDb(ID_VAL2_AnOutConf_3, &VAL2_AnOutConf_3);
retval += readFromDb(ID_VAL2_AnOutConf_4, &VAL2_AnOutConf_4);
retval += readFromDb(ID_RES2_AnOutStts_1, &RES2_AnOutStts_1);
retval += readFromDb(ID_RES2_AnOutStts_2, &RES2_AnOutStts_2);
retval += readFromDb(ID_RES2_AnOutStts_3, &RES2_AnOutStts_3);
retval += readFromDb(ID_RES2_AnOutStts_4, &RES2_AnOutStts_4);
retval += readFromDb(ID_TST2_Tamb, &TST2_Tamb);
retval += readFromDb(ID_TST2_RPM, &TST2_RPM);
retval += readFromDb(ID_TST2_FWrevision, &TST2_FWrevision);
retval += readFromDb(ID_TST2_HWconfig, &TST2_HWconfig);
retval += readFromDb(ID_VAL2_Tamb, &VAL2_Tamb);
retval += readFromDb(ID_VAL2_RPM, &VAL2_RPM);
retval += readFromDb(ID_VAL2_FWrevision, &VAL2_FWrevision);
retval += readFromDb(ID_VAL2_HWconfig, &VAL2_HWconfig);
retval += readFromDb(ID_RES2_Tamb, &RES2_Tamb);
retval += readFromDb(ID_RES2_RPM, &RES2_RPM);
retval += readFromDb(ID_RES2_FWrevision, &RES2_FWrevision);
retval += readFromDb(ID_RES2_HWconfig, &RES2_HWconfig);
retval += readFromDb(ID_TST2_RTUS_WR, &TST2_RTUS_WR);
retval += readFromDb(ID_TST2_RTUS_RD, &TST2_RTUS_RD);
retval += readFromDb(ID_TST2_RTU1_WR, &TST2_RTU1_WR);
retval += readFromDb(ID_TST2_RTU1_RD, &TST2_RTU1_RD);
retval += readFromDb(ID_TST2_RTU3_WR, &TST2_RTU3_WR);
retval += readFromDb(ID_TST2_RTU3_RD, &TST2_RTU3_RD);
retval += readFromDb(ID_TST2_CAN1_WR, &TST2_CAN1_WR);
retval += readFromDb(ID_TST2_CAN1_RD, &TST2_CAN1_RD);
retval += readFromDb(ID_VAL2_RTUS_WR, &VAL2_RTUS_WR);
retval += readFromDb(ID_VAL2_RTUS_RD, &VAL2_RTUS_RD);
retval += readFromDb(ID_VAL2_RTU1_WR, &VAL2_RTU1_WR);
retval += readFromDb(ID_VAL2_RTU1_RD, &VAL2_RTU1_RD);
retval += readFromDb(ID_VAL2_RTU3_WR, &VAL2_RTU3_WR);
retval += readFromDb(ID_VAL2_RTU3_RD, &VAL2_RTU3_RD);
retval += readFromDb(ID_VAL2_CAN1_WR, &VAL2_CAN1_WR);
retval += readFromDb(ID_VAL2_CAN1_RD, &VAL2_CAN1_RD);
retval += readFromDb(ID_RES2_RTUS_WR, &RES2_RTUS_WR);
retval += readFromDb(ID_RES2_RTUS_RD, &RES2_RTUS_RD);
retval += readFromDb(ID_RES2_RTU1_WR, &RES2_RTU1_WR);
retval += readFromDb(ID_RES2_RTU1_RD, &RES2_RTU1_RD);
retval += readFromDb(ID_RES2_RTU3_WR, &RES2_RTU3_WR);
retval += readFromDb(ID_RES2_RTU3_RD, &RES2_RTU3_RD);
retval += readFromDb(ID_RES2_CAN1_WR, &RES2_CAN1_WR);
retval += readFromDb(ID_RES2_CAN1_RD, &RES2_CAN1_RD);
retval += readFromDb(ID_STATUS2_LOCAL, &STATUS2_LOCAL);
retval += readFromDb(ID_STATUS2_REMOTE, &STATUS2_REMOTE);
retval += readFromDb(ID_STATUS2_DONE, &STATUS2_DONE);
retval += readFromDb(ID_STARTx_REMOTE, &STARTx_REMOTE);
retval += readFromDb(ID_STARTx_TEST, &STARTx_TEST);
retval += readFromDb(ID_TSTx_DigIn_1, &TSTx_DigIn_1);
retval += readFromDb(ID_TSTx_DigIn_2, &TSTx_DigIn_2);
retval += readFromDb(ID_TSTx_DigIn_3, &TSTx_DigIn_3);
retval += readFromDb(ID_TSTx_DigIn_4, &TSTx_DigIn_4);
retval += readFromDb(ID_TSTx_DigIn_5, &TSTx_DigIn_5);
retval += readFromDb(ID_TSTx_DigIn_6, &TSTx_DigIn_6);
retval += readFromDb(ID_TSTx_DigIn_7, &TSTx_DigIn_7);
retval += readFromDb(ID_TSTx_DigIn_8, &TSTx_DigIn_8);
retval += readFromDb(ID_TSTx_DigIn_9, &TSTx_DigIn_9);
retval += readFromDb(ID_TSTx_DigIn_10, &TSTx_DigIn_10);
retval += readFromDb(ID_TSTx_DigIn_11, &TSTx_DigIn_11);
retval += readFromDb(ID_TSTx_DigIn_12, &TSTx_DigIn_12);
retval += readFromDb(ID_TSTx_DigIn_13, &TSTx_DigIn_13);
retval += readFromDb(ID_TSTx_DigIn_14, &TSTx_DigIn_14);
retval += readFromDb(ID_TSTx_DigIn_15, &TSTx_DigIn_15);
retval += readFromDb(ID_TSTx_DigIn_16, &TSTx_DigIn_16);
retval += readFromDb(ID_VALx_DigIn_1, &VALx_DigIn_1);
retval += readFromDb(ID_VALx_DigIn_2, &VALx_DigIn_2);
retval += readFromDb(ID_VALx_DigIn_3, &VALx_DigIn_3);
retval += readFromDb(ID_VALx_DigIn_4, &VALx_DigIn_4);
retval += readFromDb(ID_VALx_DigIn_5, &VALx_DigIn_5);
retval += readFromDb(ID_VALx_DigIn_6, &VALx_DigIn_6);
retval += readFromDb(ID_VALx_DigIn_7, &VALx_DigIn_7);
retval += readFromDb(ID_VALx_DigIn_8, &VALx_DigIn_8);
retval += readFromDb(ID_VALx_DigIn_9, &VALx_DigIn_9);
retval += readFromDb(ID_VALx_DigIn_10, &VALx_DigIn_10);
retval += readFromDb(ID_VALx_DigIn_11, &VALx_DigIn_11);
retval += readFromDb(ID_VALx_DigIn_12, &VALx_DigIn_12);
retval += readFromDb(ID_VALx_DigIn_13, &VALx_DigIn_13);
retval += readFromDb(ID_VALx_DigIn_14, &VALx_DigIn_14);
retval += readFromDb(ID_VALx_DigIn_15, &VALx_DigIn_15);
retval += readFromDb(ID_VALx_DigIn_16, &VALx_DigIn_16);
retval += readFromDb(ID_RESx_DigIn_1, &RESx_DigIn_1);
retval += readFromDb(ID_RESx_DigIn_2, &RESx_DigIn_2);
retval += readFromDb(ID_RESx_DigIn_3, &RESx_DigIn_3);
retval += readFromDb(ID_RESx_DigIn_4, &RESx_DigIn_4);
retval += readFromDb(ID_RESx_DigIn_5, &RESx_DigIn_5);
retval += readFromDb(ID_RESx_DigIn_6, &RESx_DigIn_6);
retval += readFromDb(ID_RESx_DigIn_7, &RESx_DigIn_7);
retval += readFromDb(ID_RESx_DigIn_8, &RESx_DigIn_8);
retval += readFromDb(ID_RESx_DigIn_9, &RESx_DigIn_9);
retval += readFromDb(ID_RESx_DigIn_10, &RESx_DigIn_10);
retval += readFromDb(ID_RESx_DigIn_11, &RESx_DigIn_11);
retval += readFromDb(ID_RESx_DigIn_12, &RESx_DigIn_12);
retval += readFromDb(ID_RESx_DigIn_13, &RESx_DigIn_13);
retval += readFromDb(ID_RESx_DigIn_14, &RESx_DigIn_14);
retval += readFromDb(ID_RESx_DigIn_15, &RESx_DigIn_15);
retval += readFromDb(ID_RESx_DigIn_16, &RESx_DigIn_16);
retval += readFromDb(ID_TSTx_DigOut_1, &TSTx_DigOut_1);
retval += readFromDb(ID_TSTx_DigOut_2, &TSTx_DigOut_2);
retval += readFromDb(ID_TSTx_DigOut_3, &TSTx_DigOut_3);
retval += readFromDb(ID_TSTx_DigOut_4, &TSTx_DigOut_4);
retval += readFromDb(ID_TSTx_DigOut_5, &TSTx_DigOut_5);
retval += readFromDb(ID_TSTx_DigOut_6, &TSTx_DigOut_6);
retval += readFromDb(ID_TSTx_DigOut_7, &TSTx_DigOut_7);
retval += readFromDb(ID_TSTx_DigOut_8, &TSTx_DigOut_8);
retval += readFromDb(ID_TSTx_DigOut_9, &TSTx_DigOut_9);
retval += readFromDb(ID_TSTx_DigOut_10, &TSTx_DigOut_10);
retval += readFromDb(ID_TSTx_DigOut_11, &TSTx_DigOut_11);
retval += readFromDb(ID_TSTx_DigOut_12, &TSTx_DigOut_12);
retval += readFromDb(ID_TSTx_DigOut_13, &TSTx_DigOut_13);
retval += readFromDb(ID_TSTx_DigOut_14, &TSTx_DigOut_14);
retval += readFromDb(ID_TSTx_DigOut_15, &TSTx_DigOut_15);
retval += readFromDb(ID_TSTx_DigOut_16, &TSTx_DigOut_16);
retval += readFromDb(ID_VALx_DigOut_1, &VALx_DigOut_1);
retval += readFromDb(ID_VALx_DigOut_2, &VALx_DigOut_2);
retval += readFromDb(ID_VALx_DigOut_3, &VALx_DigOut_3);
retval += readFromDb(ID_VALx_DigOut_4, &VALx_DigOut_4);
retval += readFromDb(ID_VALx_DigOut_5, &VALx_DigOut_5);
retval += readFromDb(ID_VALx_DigOut_6, &VALx_DigOut_6);
retval += readFromDb(ID_VALx_DigOut_7, &VALx_DigOut_7);
retval += readFromDb(ID_VALx_DigOut_8, &VALx_DigOut_8);
retval += readFromDb(ID_VALx_DigOut_9, &VALx_DigOut_9);
retval += readFromDb(ID_VALx_DigOut_10, &VALx_DigOut_10);
retval += readFromDb(ID_VALx_DigOut_11, &VALx_DigOut_11);
retval += readFromDb(ID_VALx_DigOut_12, &VALx_DigOut_12);
retval += readFromDb(ID_VALx_DigOut_13, &VALx_DigOut_13);
retval += readFromDb(ID_VALx_DigOut_14, &VALx_DigOut_14);
retval += readFromDb(ID_VALx_DigOut_15, &VALx_DigOut_15);
retval += readFromDb(ID_VALx_DigOut_16, &VALx_DigOut_16);
retval += readFromDb(ID_RESx_DigOut_1, &RESx_DigOut_1);
retval += readFromDb(ID_RESx_DigOut_2, &RESx_DigOut_2);
retval += readFromDb(ID_RESx_DigOut_3, &RESx_DigOut_3);
retval += readFromDb(ID_RESx_DigOut_4, &RESx_DigOut_4);
retval += readFromDb(ID_RESx_DigOut_5, &RESx_DigOut_5);
retval += readFromDb(ID_RESx_DigOut_6, &RESx_DigOut_6);
retval += readFromDb(ID_RESx_DigOut_7, &RESx_DigOut_7);
retval += readFromDb(ID_RESx_DigOut_8, &RESx_DigOut_8);
retval += readFromDb(ID_RESx_DigOut_9, &RESx_DigOut_9);
retval += readFromDb(ID_RESx_DigOut_10, &RESx_DigOut_10);
retval += readFromDb(ID_RESx_DigOut_11, &RESx_DigOut_11);
retval += readFromDb(ID_RESx_DigOut_12, &RESx_DigOut_12);
retval += readFromDb(ID_RESx_DigOut_13, &RESx_DigOut_13);
retval += readFromDb(ID_RESx_DigOut_14, &RESx_DigOut_14);
retval += readFromDb(ID_RESx_DigOut_15, &RESx_DigOut_15);
retval += readFromDb(ID_RESx_DigOut_16, &RESx_DigOut_16);
retval += readFromDb(ID_TSTx_AnIn_1, &TSTx_AnIn_1);
retval += readFromDb(ID_TSTx_AnIn_2, &TSTx_AnIn_2);
retval += readFromDb(ID_TSTx_AnIn_3, &TSTx_AnIn_3);
retval += readFromDb(ID_TSTx_AnIn_4, &TSTx_AnIn_4);
retval += readFromDb(ID_TSTx_AnIn_5, &TSTx_AnIn_5);
retval += readFromDb(ID_TSTx_AnIn_6, &TSTx_AnIn_6);
retval += readFromDb(ID_TSTx_AnIn_7, &TSTx_AnIn_7);
retval += readFromDb(ID_TSTx_AnIn_8, &TSTx_AnIn_8);
retval += readFromDb(ID_TSTx_AnIn_9, &TSTx_AnIn_9);
retval += readFromDb(ID_TSTx_AnIn_10, &TSTx_AnIn_10);
retval += readFromDb(ID_TSTx_AnIn_11, &TSTx_AnIn_11);
retval += readFromDb(ID_TSTx_AnIn_12, &TSTx_AnIn_12);
retval += readFromDb(ID_VALx_AnIn_1, &VALx_AnIn_1);
retval += readFromDb(ID_VALx_AnIn_2, &VALx_AnIn_2);
retval += readFromDb(ID_VALx_AnIn_3, &VALx_AnIn_3);
retval += readFromDb(ID_VALx_AnIn_4, &VALx_AnIn_4);
retval += readFromDb(ID_VALx_AnIn_5, &VALx_AnIn_5);
retval += readFromDb(ID_VALx_AnIn_6, &VALx_AnIn_6);
retval += readFromDb(ID_VALx_AnIn_7, &VALx_AnIn_7);
retval += readFromDb(ID_VALx_AnIn_8, &VALx_AnIn_8);
retval += readFromDb(ID_VALx_AnIn_9, &VALx_AnIn_9);
retval += readFromDb(ID_VALx_AnIn_10, &VALx_AnIn_10);
retval += readFromDb(ID_VALx_AnIn_11, &VALx_AnIn_11);
retval += readFromDb(ID_VALx_AnIn_12, &VALx_AnIn_12);
retval += readFromDb(ID_VALx_AnInConf_1, &VALx_AnInConf_1);
retval += readFromDb(ID_VALx_AnInConf_2, &VALx_AnInConf_2);
retval += readFromDb(ID_VALx_AnInConf_3, &VALx_AnInConf_3);
retval += readFromDb(ID_VALx_AnInConf_4, &VALx_AnInConf_4);
retval += readFromDb(ID_VALx_AnInConf_5, &VALx_AnInConf_5);
retval += readFromDb(ID_VALx_AnInConf_6, &VALx_AnInConf_6);
retval += readFromDb(ID_VALx_AnInConf_7, &VALx_AnInConf_7);
retval += readFromDb(ID_VALx_AnInConf_8, &VALx_AnInConf_8);
retval += readFromDb(ID_VALx_AnInConf_9, &VALx_AnInConf_9);
retval += readFromDb(ID_VALx_AnInConf_10, &VALx_AnInConf_10);
retval += readFromDb(ID_VALx_AnInConf_11, &VALx_AnInConf_11);
retval += readFromDb(ID_VALx_AnInConf_12, &VALx_AnInConf_12);
retval += readFromDb(ID_VALx_AnInFltr_1, &VALx_AnInFltr_1);
retval += readFromDb(ID_VALx_AnInFltr_2, &VALx_AnInFltr_2);
retval += readFromDb(ID_VALx_AnInFltr_3, &VALx_AnInFltr_3);
retval += readFromDb(ID_VALx_AnInFltr_4, &VALx_AnInFltr_4);
retval += readFromDb(ID_VALx_AnInFltr_5, &VALx_AnInFltr_5);
retval += readFromDb(ID_VALx_AnInFltr_6, &VALx_AnInFltr_6);
retval += readFromDb(ID_VALx_AnInFltr_7, &VALx_AnInFltr_7);
retval += readFromDb(ID_VALx_AnInFltr_8, &VALx_AnInFltr_8);
retval += readFromDb(ID_VALx_AnInFltr_9, &VALx_AnInFltr_9);
retval += readFromDb(ID_VALx_AnInFltr_10, &VALx_AnInFltr_10);
retval += readFromDb(ID_VALx_AnInFltr_11, &VALx_AnInFltr_11);
retval += readFromDb(ID_VALx_AnInFltr_12, &VALx_AnInFltr_12);
retval += readFromDb(ID_RESx_AnIn_1, &RESx_AnIn_1);
retval += readFromDb(ID_RESx_AnIn_2, &RESx_AnIn_2);
retval += readFromDb(ID_RESx_AnIn_3, &RESx_AnIn_3);
retval += readFromDb(ID_RESx_AnIn_4, &RESx_AnIn_4);
retval += readFromDb(ID_RESx_AnIn_5, &RESx_AnIn_5);
retval += readFromDb(ID_RESx_AnIn_6, &RESx_AnIn_6);
retval += readFromDb(ID_RESx_AnIn_7, &RESx_AnIn_7);
retval += readFromDb(ID_RESx_AnIn_8, &RESx_AnIn_8);
retval += readFromDb(ID_RESx_AnIn_9, &RESx_AnIn_9);
retval += readFromDb(ID_RESx_AnIn_10, &RESx_AnIn_10);
retval += readFromDb(ID_RESx_AnIn_11, &RESx_AnIn_11);
retval += readFromDb(ID_RESx_AnIn_12, &RESx_AnIn_12);
retval += readFromDb(ID_RESx_AnInStts_1, &RESx_AnInStts_1);
retval += readFromDb(ID_RESx_AnInStts_2, &RESx_AnInStts_2);
retval += readFromDb(ID_RESx_AnInStts_3, &RESx_AnInStts_3);
retval += readFromDb(ID_RESx_AnInStts_4, &RESx_AnInStts_4);
retval += readFromDb(ID_RESx_AnInStts_5, &RESx_AnInStts_5);
retval += readFromDb(ID_RESx_AnInStts_6, &RESx_AnInStts_6);
retval += readFromDb(ID_RESx_AnInStts_7, &RESx_AnInStts_7);
retval += readFromDb(ID_RESx_AnInStts_8, &RESx_AnInStts_8);
retval += readFromDb(ID_RESx_AnInStts_9, &RESx_AnInStts_9);
retval += readFromDb(ID_RESx_AnInStts_10, &RESx_AnInStts_10);
retval += readFromDb(ID_RESx_AnInStts_11, &RESx_AnInStts_11);
retval += readFromDb(ID_RESx_AnInStts_12, &RESx_AnInStts_12);
retval += readFromDb(ID_TSTx_AnOut_1, &TSTx_AnOut_1);
retval += readFromDb(ID_TSTx_AnOut_2, &TSTx_AnOut_2);
retval += readFromDb(ID_TSTx_AnOut_3, &TSTx_AnOut_3);
retval += readFromDb(ID_TSTx_AnOut_4, &TSTx_AnOut_4);
retval += readFromDb(ID_VALx_AnOut_1, &VALx_AnOut_1);
retval += readFromDb(ID_VALx_AnOut_2, &VALx_AnOut_2);
retval += readFromDb(ID_VALx_AnOut_3, &VALx_AnOut_3);
retval += readFromDb(ID_VALx_AnOut_4, &VALx_AnOut_4);
retval += readFromDb(ID_VALx_AnOutConf_1, &VALx_AnOutConf_1);
retval += readFromDb(ID_VALx_AnOutConf_2, &VALx_AnOutConf_2);
retval += readFromDb(ID_VALx_AnOutConf_3, &VALx_AnOutConf_3);
retval += readFromDb(ID_VALx_AnOutConf_4, &VALx_AnOutConf_4);
retval += readFromDb(ID_RESx_AnOutStts_1, &RESx_AnOutStts_1);
retval += readFromDb(ID_RESx_AnOutStts_2, &RESx_AnOutStts_2);
retval += readFromDb(ID_RESx_AnOutStts_3, &RESx_AnOutStts_3);
retval += readFromDb(ID_RESx_AnOutStts_4, &RESx_AnOutStts_4);
retval += readFromDb(ID_TSTx_Tamb, &TSTx_Tamb);
retval += readFromDb(ID_TSTx_RPM, &TSTx_RPM);
retval += readFromDb(ID_TSTx_FWrevision, &TSTx_FWrevision);
retval += readFromDb(ID_TSTx_HWconfig, &TSTx_HWconfig);
retval += readFromDb(ID_VALx_Tamb, &VALx_Tamb);
retval += readFromDb(ID_VALx_RPM, &VALx_RPM);
retval += readFromDb(ID_VALx_FWrevision, &VALx_FWrevision);
retval += readFromDb(ID_VALx_HWconfig, &VALx_HWconfig);
retval += readFromDb(ID_RESx_Tamb, &RESx_Tamb);
retval += readFromDb(ID_RESx_RPM, &RESx_RPM);
retval += readFromDb(ID_RESx_FWrevision, &RESx_FWrevision);
retval += readFromDb(ID_RESx_HWconfig, &RESx_HWconfig);
retval += readFromDb(ID_TSTx_RTUS_WR, &TSTx_RTUS_WR);
retval += readFromDb(ID_TSTx_RTUS_RD, &TSTx_RTUS_RD);
retval += readFromDb(ID_TSTx_RTU1_WR, &TSTx_RTU1_WR);
retval += readFromDb(ID_TSTx_RTU1_RD, &TSTx_RTU1_RD);
retval += readFromDb(ID_TSTx_RTU3_WR, &TSTx_RTU3_WR);
retval += readFromDb(ID_TSTx_RTU3_RD, &TSTx_RTU3_RD);
retval += readFromDb(ID_TSTx_CAN1_WR, &TSTx_CAN1_WR);
retval += readFromDb(ID_TSTx_CAN1_RD, &TSTx_CAN1_RD);
retval += readFromDb(ID_VALx_RTUS_WR, &VALx_RTUS_WR);
retval += readFromDb(ID_VALx_RTUS_RD, &VALx_RTUS_RD);
retval += readFromDb(ID_VALx_RTU1_WR, &VALx_RTU1_WR);
retval += readFromDb(ID_VALx_RTU1_RD, &VALx_RTU1_RD);
retval += readFromDb(ID_VALx_RTU3_WR, &VALx_RTU3_WR);
retval += readFromDb(ID_VALx_RTU3_RD, &VALx_RTU3_RD);
retval += readFromDb(ID_VALx_CAN1_WR, &VALx_CAN1_WR);
retval += readFromDb(ID_VALx_CAN1_RD, &VALx_CAN1_RD);
retval += readFromDb(ID_RESx_RTUS_WR, &RESx_RTUS_WR);
retval += readFromDb(ID_RESx_RTUS_RD, &RESx_RTUS_RD);
retval += readFromDb(ID_RESx_RTU1_WR, &RESx_RTU1_WR);
retval += readFromDb(ID_RESx_RTU1_RD, &RESx_RTU1_RD);
retval += readFromDb(ID_RESx_RTU3_WR, &RESx_RTU3_WR);
retval += readFromDb(ID_RESx_RTU3_RD, &RESx_RTU3_RD);
retval += readFromDb(ID_RESx_CAN1_WR, &RESx_CAN1_WR);
retval += readFromDb(ID_RESx_CAN1_RD, &RESx_CAN1_RD);
retval += readFromDb(ID_STATUSx_LOCAL, &STATUSx_LOCAL);
retval += readFromDb(ID_STATUSx_REMOTE, &STATUSx_REMOTE);
retval += readFromDb(ID_STATUSx_DONE, &STATUSx_DONE);
retval += readFromDb(ID_RTU_DigIn_1, &RTU_DigIn_1);
retval += readFromDb(ID_RTU_DigIn_2, &RTU_DigIn_2);
retval += readFromDb(ID_RTU_DigIn_3, &RTU_DigIn_3);
retval += readFromDb(ID_RTU_DigIn_4, &RTU_DigIn_4);
retval += readFromDb(ID_RTU_DigIn_5, &RTU_DigIn_5);
retval += readFromDb(ID_RTU_DigIn_6, &RTU_DigIn_6);
retval += readFromDb(ID_RTU_DigIn_7, &RTU_DigIn_7);
retval += readFromDb(ID_RTU_DigIn_8, &RTU_DigIn_8);
retval += readFromDb(ID_RTU_DigIn_9, &RTU_DigIn_9);
retval += readFromDb(ID_RTU_DigIn_10, &RTU_DigIn_10);
retval += readFromDb(ID_RTU_DigIn_11, &RTU_DigIn_11);
retval += readFromDb(ID_RTU_DigIn_12, &RTU_DigIn_12);
retval += readFromDb(ID_RTU_DigIn_13, &RTU_DigIn_13);
retval += readFromDb(ID_RTU_DigIn_14, &RTU_DigIn_14);
retval += readFromDb(ID_RTU_DigIn_15, &RTU_DigIn_15);
retval += readFromDb(ID_RTU_DigIn_16, &RTU_DigIn_16);
retval += readFromDb(ID_RTU_AnIn_1, &RTU_AnIn_1);
retval += readFromDb(ID_RTU_AnIn_2, &RTU_AnIn_2);
retval += readFromDb(ID_RTU_Tamb, &RTU_Tamb);
retval += readFromDb(ID_RTU_DigOut_1, &RTU_DigOut_1);
retval += readFromDb(ID_RTU_DigOut_2, &RTU_DigOut_2);
retval += readFromDb(ID_RTU_DigOut_3, &RTU_DigOut_3);
retval += readFromDb(ID_RTU_DigOut_4, &RTU_DigOut_4);
retval += readFromDb(ID_RTU_DigOut_5, &RTU_DigOut_5);
retval += readFromDb(ID_RTU_DigOut_6, &RTU_DigOut_6);
retval += readFromDb(ID_RTU_DigOut_7, &RTU_DigOut_7);
retval += readFromDb(ID_RTU_DigOut_8, &RTU_DigOut_8);
retval += readFromDb(ID_RTU_DigOut_9, &RTU_DigOut_9);
retval += readFromDb(ID_RTU_DigOut_10, &RTU_DigOut_10);
retval += readFromDb(ID_RTU_DigOut_11, &RTU_DigOut_11);
retval += readFromDb(ID_RTU_DigOut_12, &RTU_DigOut_12);
retval += readFromDb(ID_RTU_DigOut_13, &RTU_DigOut_13);
retval += readFromDb(ID_RTU_DigOut_14, &RTU_DigOut_14);
retval += readFromDb(ID_RTU_DigOut_15, &RTU_DigOut_15);
retval += readFromDb(ID_RTU_DigOut_16, &RTU_DigOut_16);
retval += readFromDb(ID_RTU_AnOutConf_X, &RTU_AnOutConf_X);
retval += readFromDb(ID_RTU_AnOut_1, &RTU_AnOut_1);
retval += readFromDb(ID_RTU_AnOut_2, &RTU_AnOut_2);
retval += readFromDb(ID_RTU_AnOut_3, &RTU_AnOut_3);
retval += readFromDb(ID_RTU_AnOut_4, &RTU_AnOut_4);
retval += readFromDb(ID_RTU_AnOut_5, &RTU_AnOut_5);
retval += readFromDb(ID_RTU_AnOut_6, &RTU_AnOut_6);
retval += readFromDb(ID_RTU_AnOut_7, &RTU_AnOut_7);
retval += readFromDb(ID_RTU_AnOut_8, &RTU_AnOut_8);
retval += readFromDb(ID_RTU_AnInConf_1, &RTU_AnInConf_1);
retval += readFromDb(ID_RTU_AnInConf_2, &RTU_AnInConf_2);
retval += readFromDb(ID_RTU_HeartBeat, &RTU_HeartBeat);
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
retval += readFromDb(ID_PLC_AnOutConf_2, &PLC_AnOutConf_2);
retval += readFromDb(ID_PLC_AnOutConf_3, &PLC_AnOutConf_3);
retval += readFromDb(ID_PLC_AnOutConf_4, &PLC_AnOutConf_4);
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
retval += readFromDb(ID_PLC_AnIn_3, &PLC_AnIn_3);
retval += readFromDb(ID_PLC_AnIn_4, &PLC_AnIn_4);
retval += readFromDb(ID_PLC_AnIn_5, &PLC_AnIn_5);
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
retval += readFromDb(ID_PLC_Encoder, &PLC_Encoder);
retval += readFromDb(ID_PLC_Capture, &PLC_Capture);
retval += readFromDb(ID_PLC_DigOut_1, &PLC_DigOut_1);
retval += readFromDb(ID_PLC_DigOut_2, &PLC_DigOut_2);
retval += readFromDb(ID_PLC_DigOut_3, &PLC_DigOut_3);
retval += readFromDb(ID_PLC_DigOut_4, &PLC_DigOut_4);
retval += readFromDb(ID_PLC_DigOut_5, &PLC_DigOut_5);
retval += readFromDb(ID_PLC_DigOut_6, &PLC_DigOut_6);
retval += readFromDb(ID_PLC_DigOut_7, &PLC_DigOut_7);
retval += readFromDb(ID_PLC_DigOut_8, &PLC_DigOut_8);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_AnOut_2, &PLC_AnOut_2);
retval += readFromDb(ID_PLC_AnOut_3, &PLC_AnOut_3);
retval += readFromDb(ID_PLC_AnOut_4, &PLC_AnOut_4);
retval += readFromDb(ID_PLC_EncoderStart, &PLC_EncoderStart);
retval += readFromDb(ID_PLC_EncoderReset, &PLC_EncoderReset);
retval += readFromDb(ID_PLC_Heartbeat, &PLC_Heartbeat);
retval += readFromDb(ID_PLC_StatusReg, &PLC_StatusReg);
retval += readFromDb(ID_PLC_AnIn1Filter, &PLC_AnIn1Filter);
retval += readFromDb(ID_PLC_AnIn2Filter, &PLC_AnIn2Filter);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);

if (first)
{
    first = false;
    setup();
}
loop();

return retval;
}
