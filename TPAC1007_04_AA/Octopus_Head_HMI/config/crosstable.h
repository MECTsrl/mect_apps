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
#ifndef CROSSTABLE_H
#define CROSSTABLE_H
#ifdef __cplusplus
extern "C" {
#endif
#include <sys/types.h>
 
#define ID_PRODUCT_ID 1
extern u_int32_t PRODUCT_ID;
int doWrite_PRODUCT_ID(u_int32_t value);
int prepareWrite_PRODUCT_ID(u_int32_t value);
 
#define ID_SERIAL_NUMBER 2
extern u_int32_t SERIAL_NUMBER;
int doWrite_SERIAL_NUMBER(u_int32_t value);
int prepareWrite_SERIAL_NUMBER(u_int32_t value);
 
#define ID_TEST_STEP 3
extern u_int32_t TEST_STEP;
int doWrite_TEST_STEP(u_int32_t value);
int prepareWrite_TEST_STEP(u_int32_t value);
 
#define ID_TEST_DATE 4
extern u_int32_t TEST_DATE;
int doWrite_TEST_DATE(u_int32_t value);
int prepareWrite_TEST_DATE(u_int32_t value);
 
#define ID_TEST_TIME 5
extern u_int32_t TEST_TIME;
int doWrite_TEST_TIME(u_int32_t value);
int prepareWrite_TEST_TIME(u_int32_t value);
 
#define ID_TEST_DURATION 6
extern u_int32_t TEST_DURATION;
int doWrite_TEST_DURATION(u_int32_t value);
int prepareWrite_TEST_DURATION(u_int32_t value);
 
#define ID_DO_REMOTE 193
extern int DO_REMOTE;
int doWrite_DO_REMOTE(int value);
int prepareWrite_DO_REMOTE(int value);
 
#define ID_DO_TEST 194
extern int DO_TEST;
int doWrite_DO_TEST(int value);
int prepareWrite_DO_TEST(int value);
 
#define ID_STATUS 195
extern u_int16_t STATUS;
int doWrite_STATUS(u_int16_t value);
int prepareWrite_STATUS(u_int16_t value);
 
#define ID_TST_DigIn_1 1001
extern int TST_DigIn_1;
int doWrite_TST_DigIn_1(int value);
int prepareWrite_TST_DigIn_1(int value);
 
#define ID_TST_DigIn_2 1002
extern int TST_DigIn_2;
int doWrite_TST_DigIn_2(int value);
int prepareWrite_TST_DigIn_2(int value);
 
#define ID_TST_DigIn_3 1003
extern int TST_DigIn_3;
int doWrite_TST_DigIn_3(int value);
int prepareWrite_TST_DigIn_3(int value);
 
#define ID_TST_DigIn_4 1004
extern int TST_DigIn_4;
int doWrite_TST_DigIn_4(int value);
int prepareWrite_TST_DigIn_4(int value);
 
#define ID_TST_DigIn_5 1005
extern int TST_DigIn_5;
int doWrite_TST_DigIn_5(int value);
int prepareWrite_TST_DigIn_5(int value);
 
#define ID_TST_DigIn_6 1006
extern int TST_DigIn_6;
int doWrite_TST_DigIn_6(int value);
int prepareWrite_TST_DigIn_6(int value);
 
#define ID_TST_DigIn_7 1007
extern int TST_DigIn_7;
int doWrite_TST_DigIn_7(int value);
int prepareWrite_TST_DigIn_7(int value);
 
#define ID_TST_DigIn_8 1008
extern int TST_DigIn_8;
int doWrite_TST_DigIn_8(int value);
int prepareWrite_TST_DigIn_8(int value);
 
#define ID_TST_DigIn_9 1009
extern int TST_DigIn_9;
int doWrite_TST_DigIn_9(int value);
int prepareWrite_TST_DigIn_9(int value);
 
#define ID_TST_DigIn_10 1010
extern int TST_DigIn_10;
int doWrite_TST_DigIn_10(int value);
int prepareWrite_TST_DigIn_10(int value);
 
#define ID_TST_DigIn_11 1011
extern int TST_DigIn_11;
int doWrite_TST_DigIn_11(int value);
int prepareWrite_TST_DigIn_11(int value);
 
#define ID_TST_DigIn_12 1012
extern int TST_DigIn_12;
int doWrite_TST_DigIn_12(int value);
int prepareWrite_TST_DigIn_12(int value);
 
#define ID_TST_DigIn_13 1013
extern int TST_DigIn_13;
int doWrite_TST_DigIn_13(int value);
int prepareWrite_TST_DigIn_13(int value);
 
#define ID_TST_DigIn_14 1014
extern int TST_DigIn_14;
int doWrite_TST_DigIn_14(int value);
int prepareWrite_TST_DigIn_14(int value);
 
#define ID_TST_DigIn_15 1015
extern int TST_DigIn_15;
int doWrite_TST_DigIn_15(int value);
int prepareWrite_TST_DigIn_15(int value);
 
#define ID_TST_DigIn_16 1016
extern int TST_DigIn_16;
int doWrite_TST_DigIn_16(int value);
int prepareWrite_TST_DigIn_16(int value);
 
#define ID_VAL_DigIn_1 1017
extern int VAL_DigIn_1;
int doWrite_VAL_DigIn_1(int value);
int prepareWrite_VAL_DigIn_1(int value);
 
#define ID_VAL_DigIn_2 1018
extern int VAL_DigIn_2;
int doWrite_VAL_DigIn_2(int value);
int prepareWrite_VAL_DigIn_2(int value);
 
#define ID_VAL_DigIn_3 1019
extern int VAL_DigIn_3;
int doWrite_VAL_DigIn_3(int value);
int prepareWrite_VAL_DigIn_3(int value);
 
#define ID_VAL_DigIn_4 1020
extern int VAL_DigIn_4;
int doWrite_VAL_DigIn_4(int value);
int prepareWrite_VAL_DigIn_4(int value);
 
#define ID_VAL_DigIn_5 1021
extern int VAL_DigIn_5;
int doWrite_VAL_DigIn_5(int value);
int prepareWrite_VAL_DigIn_5(int value);
 
#define ID_VAL_DigIn_6 1022
extern int VAL_DigIn_6;
int doWrite_VAL_DigIn_6(int value);
int prepareWrite_VAL_DigIn_6(int value);
 
#define ID_VAL_DigIn_7 1023
extern int VAL_DigIn_7;
int doWrite_VAL_DigIn_7(int value);
int prepareWrite_VAL_DigIn_7(int value);
 
#define ID_VAL_DigIn_8 1024
extern int VAL_DigIn_8;
int doWrite_VAL_DigIn_8(int value);
int prepareWrite_VAL_DigIn_8(int value);
 
#define ID_VAL_DigIn_9 1025
extern int VAL_DigIn_9;
int doWrite_VAL_DigIn_9(int value);
int prepareWrite_VAL_DigIn_9(int value);
 
#define ID_VAL_DigIn_10 1026
extern int VAL_DigIn_10;
int doWrite_VAL_DigIn_10(int value);
int prepareWrite_VAL_DigIn_10(int value);
 
#define ID_VAL_DigIn_11 1027
extern int VAL_DigIn_11;
int doWrite_VAL_DigIn_11(int value);
int prepareWrite_VAL_DigIn_11(int value);
 
#define ID_VAL_DigIn_12 1028
extern int VAL_DigIn_12;
int doWrite_VAL_DigIn_12(int value);
int prepareWrite_VAL_DigIn_12(int value);
 
#define ID_VAL_DigIn_13 1029
extern int VAL_DigIn_13;
int doWrite_VAL_DigIn_13(int value);
int prepareWrite_VAL_DigIn_13(int value);
 
#define ID_VAL_DigIn_14 1030
extern int VAL_DigIn_14;
int doWrite_VAL_DigIn_14(int value);
int prepareWrite_VAL_DigIn_14(int value);
 
#define ID_VAL_DigIn_15 1031
extern int VAL_DigIn_15;
int doWrite_VAL_DigIn_15(int value);
int prepareWrite_VAL_DigIn_15(int value);
 
#define ID_VAL_DigIn_16 1032
extern int VAL_DigIn_16;
int doWrite_VAL_DigIn_16(int value);
int prepareWrite_VAL_DigIn_16(int value);
 
#define ID_RES_DigIn_1 1033
extern int RES_DigIn_1;
int doWrite_RES_DigIn_1(int value);
int prepareWrite_RES_DigIn_1(int value);
 
#define ID_RES_DigIn_2 1034
extern int RES_DigIn_2;
int doWrite_RES_DigIn_2(int value);
int prepareWrite_RES_DigIn_2(int value);
 
#define ID_RES_DigIn_3 1035
extern int RES_DigIn_3;
int doWrite_RES_DigIn_3(int value);
int prepareWrite_RES_DigIn_3(int value);
 
#define ID_RES_DigIn_4 1036
extern int RES_DigIn_4;
int doWrite_RES_DigIn_4(int value);
int prepareWrite_RES_DigIn_4(int value);
 
#define ID_RES_DigIn_5 1037
extern int RES_DigIn_5;
int doWrite_RES_DigIn_5(int value);
int prepareWrite_RES_DigIn_5(int value);
 
#define ID_RES_DigIn_6 1038
extern int RES_DigIn_6;
int doWrite_RES_DigIn_6(int value);
int prepareWrite_RES_DigIn_6(int value);
 
#define ID_RES_DigIn_7 1039
extern int RES_DigIn_7;
int doWrite_RES_DigIn_7(int value);
int prepareWrite_RES_DigIn_7(int value);
 
#define ID_RES_DigIn_8 1040
extern int RES_DigIn_8;
int doWrite_RES_DigIn_8(int value);
int prepareWrite_RES_DigIn_8(int value);
 
#define ID_RES_DigIn_9 1041
extern int RES_DigIn_9;
int doWrite_RES_DigIn_9(int value);
int prepareWrite_RES_DigIn_9(int value);
 
#define ID_RES_DigIn_10 1042
extern int RES_DigIn_10;
int doWrite_RES_DigIn_10(int value);
int prepareWrite_RES_DigIn_10(int value);
 
#define ID_RES_DigIn_11 1043
extern int RES_DigIn_11;
int doWrite_RES_DigIn_11(int value);
int prepareWrite_RES_DigIn_11(int value);
 
#define ID_RES_DigIn_12 1044
extern int RES_DigIn_12;
int doWrite_RES_DigIn_12(int value);
int prepareWrite_RES_DigIn_12(int value);
 
#define ID_RES_DigIn_13 1045
extern int RES_DigIn_13;
int doWrite_RES_DigIn_13(int value);
int prepareWrite_RES_DigIn_13(int value);
 
#define ID_RES_DigIn_14 1046
extern int RES_DigIn_14;
int doWrite_RES_DigIn_14(int value);
int prepareWrite_RES_DigIn_14(int value);
 
#define ID_RES_DigIn_15 1047
extern int RES_DigIn_15;
int doWrite_RES_DigIn_15(int value);
int prepareWrite_RES_DigIn_15(int value);
 
#define ID_RES_DigIn_16 1048
extern int RES_DigIn_16;
int doWrite_RES_DigIn_16(int value);
int prepareWrite_RES_DigIn_16(int value);
 
#define ID_OK_DigIn_1 1049
extern int OK_DigIn_1;
int doWrite_OK_DigIn_1(int value);
int prepareWrite_OK_DigIn_1(int value);
 
#define ID_OK_DigIn_2 1050
extern int OK_DigIn_2;
int doWrite_OK_DigIn_2(int value);
int prepareWrite_OK_DigIn_2(int value);
 
#define ID_OK_DigIn_3 1051
extern int OK_DigIn_3;
int doWrite_OK_DigIn_3(int value);
int prepareWrite_OK_DigIn_3(int value);
 
#define ID_OK_DigIn_4 1052
extern int OK_DigIn_4;
int doWrite_OK_DigIn_4(int value);
int prepareWrite_OK_DigIn_4(int value);
 
#define ID_OK_DigIn_5 1053
extern int OK_DigIn_5;
int doWrite_OK_DigIn_5(int value);
int prepareWrite_OK_DigIn_5(int value);
 
#define ID_OK_DigIn_6 1054
extern int OK_DigIn_6;
int doWrite_OK_DigIn_6(int value);
int prepareWrite_OK_DigIn_6(int value);
 
#define ID_OK_DigIn_7 1055
extern int OK_DigIn_7;
int doWrite_OK_DigIn_7(int value);
int prepareWrite_OK_DigIn_7(int value);
 
#define ID_OK_DigIn_8 1056
extern int OK_DigIn_8;
int doWrite_OK_DigIn_8(int value);
int prepareWrite_OK_DigIn_8(int value);
 
#define ID_OK_DigIn_9 1057
extern int OK_DigIn_9;
int doWrite_OK_DigIn_9(int value);
int prepareWrite_OK_DigIn_9(int value);
 
#define ID_OK_DigIn_10 1058
extern int OK_DigIn_10;
int doWrite_OK_DigIn_10(int value);
int prepareWrite_OK_DigIn_10(int value);
 
#define ID_OK_DigIn_11 1059
extern int OK_DigIn_11;
int doWrite_OK_DigIn_11(int value);
int prepareWrite_OK_DigIn_11(int value);
 
#define ID_OK_DigIn_12 1060
extern int OK_DigIn_12;
int doWrite_OK_DigIn_12(int value);
int prepareWrite_OK_DigIn_12(int value);
 
#define ID_OK_DigIn_13 1061
extern int OK_DigIn_13;
int doWrite_OK_DigIn_13(int value);
int prepareWrite_OK_DigIn_13(int value);
 
#define ID_OK_DigIn_14 1062
extern int OK_DigIn_14;
int doWrite_OK_DigIn_14(int value);
int prepareWrite_OK_DigIn_14(int value);
 
#define ID_OK_DigIn_15 1063
extern int OK_DigIn_15;
int doWrite_OK_DigIn_15(int value);
int prepareWrite_OK_DigIn_15(int value);
 
#define ID_OK_DigIn_16 1064
extern int OK_DigIn_16;
int doWrite_OK_DigIn_16(int value);
int prepareWrite_OK_DigIn_16(int value);
 
#define ID_TST_DigOut_1 1065
extern int TST_DigOut_1;
int doWrite_TST_DigOut_1(int value);
int prepareWrite_TST_DigOut_1(int value);
 
#define ID_TST_DigOut_2 1066
extern int TST_DigOut_2;
int doWrite_TST_DigOut_2(int value);
int prepareWrite_TST_DigOut_2(int value);
 
#define ID_TST_DigOut_3 1067
extern int TST_DigOut_3;
int doWrite_TST_DigOut_3(int value);
int prepareWrite_TST_DigOut_3(int value);
 
#define ID_TST_DigOut_4 1068
extern int TST_DigOut_4;
int doWrite_TST_DigOut_4(int value);
int prepareWrite_TST_DigOut_4(int value);
 
#define ID_TST_DigOut_5 1069
extern int TST_DigOut_5;
int doWrite_TST_DigOut_5(int value);
int prepareWrite_TST_DigOut_5(int value);
 
#define ID_TST_DigOut_6 1070
extern int TST_DigOut_6;
int doWrite_TST_DigOut_6(int value);
int prepareWrite_TST_DigOut_6(int value);
 
#define ID_TST_DigOut_7 1071
extern int TST_DigOut_7;
int doWrite_TST_DigOut_7(int value);
int prepareWrite_TST_DigOut_7(int value);
 
#define ID_TST_DigOut_8 1072
extern int TST_DigOut_8;
int doWrite_TST_DigOut_8(int value);
int prepareWrite_TST_DigOut_8(int value);
 
#define ID_TST_DigOut_9 1073
extern int TST_DigOut_9;
int doWrite_TST_DigOut_9(int value);
int prepareWrite_TST_DigOut_9(int value);
 
#define ID_TST_DigOut_10 1074
extern int TST_DigOut_10;
int doWrite_TST_DigOut_10(int value);
int prepareWrite_TST_DigOut_10(int value);
 
#define ID_TST_DigOut_11 1075
extern int TST_DigOut_11;
int doWrite_TST_DigOut_11(int value);
int prepareWrite_TST_DigOut_11(int value);
 
#define ID_TST_DigOut_12 1076
extern int TST_DigOut_12;
int doWrite_TST_DigOut_12(int value);
int prepareWrite_TST_DigOut_12(int value);
 
#define ID_TST_DigOut_13 1077
extern int TST_DigOut_13;
int doWrite_TST_DigOut_13(int value);
int prepareWrite_TST_DigOut_13(int value);
 
#define ID_TST_DigOut_14 1078
extern int TST_DigOut_14;
int doWrite_TST_DigOut_14(int value);
int prepareWrite_TST_DigOut_14(int value);
 
#define ID_TST_DigOut_15 1079
extern int TST_DigOut_15;
int doWrite_TST_DigOut_15(int value);
int prepareWrite_TST_DigOut_15(int value);
 
#define ID_TST_DigOut_16 1080
extern int TST_DigOut_16;
int doWrite_TST_DigOut_16(int value);
int prepareWrite_TST_DigOut_16(int value);
 
#define ID_VAL_DigOut_1 1081
extern int VAL_DigOut_1;
int doWrite_VAL_DigOut_1(int value);
int prepareWrite_VAL_DigOut_1(int value);
 
#define ID_VAL_DigOut_2 1082
extern int VAL_DigOut_2;
int doWrite_VAL_DigOut_2(int value);
int prepareWrite_VAL_DigOut_2(int value);
 
#define ID_VAL_DigOut_3 1083
extern int VAL_DigOut_3;
int doWrite_VAL_DigOut_3(int value);
int prepareWrite_VAL_DigOut_3(int value);
 
#define ID_VAL_DigOut_4 1084
extern int VAL_DigOut_4;
int doWrite_VAL_DigOut_4(int value);
int prepareWrite_VAL_DigOut_4(int value);
 
#define ID_VAL_DigOut_5 1085
extern int VAL_DigOut_5;
int doWrite_VAL_DigOut_5(int value);
int prepareWrite_VAL_DigOut_5(int value);
 
#define ID_VAL_DigOut_6 1086
extern int VAL_DigOut_6;
int doWrite_VAL_DigOut_6(int value);
int prepareWrite_VAL_DigOut_6(int value);
 
#define ID_VAL_DigOut_7 1087
extern int VAL_DigOut_7;
int doWrite_VAL_DigOut_7(int value);
int prepareWrite_VAL_DigOut_7(int value);
 
#define ID_VAL_DigOut_8 1088
extern int VAL_DigOut_8;
int doWrite_VAL_DigOut_8(int value);
int prepareWrite_VAL_DigOut_8(int value);
 
#define ID_VAL_DigOut_9 1089
extern int VAL_DigOut_9;
int doWrite_VAL_DigOut_9(int value);
int prepareWrite_VAL_DigOut_9(int value);
 
#define ID_VAL_DigOut_10 1090
extern int VAL_DigOut_10;
int doWrite_VAL_DigOut_10(int value);
int prepareWrite_VAL_DigOut_10(int value);
 
#define ID_VAL_DigOut_11 1091
extern int VAL_DigOut_11;
int doWrite_VAL_DigOut_11(int value);
int prepareWrite_VAL_DigOut_11(int value);
 
#define ID_VAL_DigOut_12 1092
extern int VAL_DigOut_12;
int doWrite_VAL_DigOut_12(int value);
int prepareWrite_VAL_DigOut_12(int value);
 
#define ID_VAL_DigOut_13 1093
extern int VAL_DigOut_13;
int doWrite_VAL_DigOut_13(int value);
int prepareWrite_VAL_DigOut_13(int value);
 
#define ID_VAL_DigOut_14 1094
extern int VAL_DigOut_14;
int doWrite_VAL_DigOut_14(int value);
int prepareWrite_VAL_DigOut_14(int value);
 
#define ID_VAL_DigOut_15 1095
extern int VAL_DigOut_15;
int doWrite_VAL_DigOut_15(int value);
int prepareWrite_VAL_DigOut_15(int value);
 
#define ID_VAL_DigOut_16 1096
extern int VAL_DigOut_16;
int doWrite_VAL_DigOut_16(int value);
int prepareWrite_VAL_DigOut_16(int value);
 
#define ID_RES_DigOut_1 1097
extern int RES_DigOut_1;
int doWrite_RES_DigOut_1(int value);
int prepareWrite_RES_DigOut_1(int value);
 
#define ID_RES_DigOut_2 1098
extern int RES_DigOut_2;
int doWrite_RES_DigOut_2(int value);
int prepareWrite_RES_DigOut_2(int value);
 
#define ID_RES_DigOut_3 1099
extern int RES_DigOut_3;
int doWrite_RES_DigOut_3(int value);
int prepareWrite_RES_DigOut_3(int value);
 
#define ID_RES_DigOut_4 1100
extern int RES_DigOut_4;
int doWrite_RES_DigOut_4(int value);
int prepareWrite_RES_DigOut_4(int value);
 
#define ID_RES_DigOut_5 1101
extern int RES_DigOut_5;
int doWrite_RES_DigOut_5(int value);
int prepareWrite_RES_DigOut_5(int value);
 
#define ID_RES_DigOut_6 1102
extern int RES_DigOut_6;
int doWrite_RES_DigOut_6(int value);
int prepareWrite_RES_DigOut_6(int value);
 
#define ID_RES_DigOut_7 1103
extern int RES_DigOut_7;
int doWrite_RES_DigOut_7(int value);
int prepareWrite_RES_DigOut_7(int value);
 
#define ID_RES_DigOut_8 1104
extern int RES_DigOut_8;
int doWrite_RES_DigOut_8(int value);
int prepareWrite_RES_DigOut_8(int value);
 
#define ID_RES_DigOut_9 1105
extern int RES_DigOut_9;
int doWrite_RES_DigOut_9(int value);
int prepareWrite_RES_DigOut_9(int value);
 
#define ID_RES_DigOut_10 1106
extern int RES_DigOut_10;
int doWrite_RES_DigOut_10(int value);
int prepareWrite_RES_DigOut_10(int value);
 
#define ID_RES_DigOut_11 1107
extern int RES_DigOut_11;
int doWrite_RES_DigOut_11(int value);
int prepareWrite_RES_DigOut_11(int value);
 
#define ID_RES_DigOut_12 1108
extern int RES_DigOut_12;
int doWrite_RES_DigOut_12(int value);
int prepareWrite_RES_DigOut_12(int value);
 
#define ID_RES_DigOut_13 1109
extern int RES_DigOut_13;
int doWrite_RES_DigOut_13(int value);
int prepareWrite_RES_DigOut_13(int value);
 
#define ID_RES_DigOut_14 1110
extern int RES_DigOut_14;
int doWrite_RES_DigOut_14(int value);
int prepareWrite_RES_DigOut_14(int value);
 
#define ID_RES_DigOut_15 1111
extern int RES_DigOut_15;
int doWrite_RES_DigOut_15(int value);
int prepareWrite_RES_DigOut_15(int value);
 
#define ID_RES_DigOut_16 1112
extern int RES_DigOut_16;
int doWrite_RES_DigOut_16(int value);
int prepareWrite_RES_DigOut_16(int value);
 
#define ID_OK_DigOut_1 1113
extern int OK_DigOut_1;
int doWrite_OK_DigOut_1(int value);
int prepareWrite_OK_DigOut_1(int value);
 
#define ID_OK_DigOut_2 1114
extern int OK_DigOut_2;
int doWrite_OK_DigOut_2(int value);
int prepareWrite_OK_DigOut_2(int value);
 
#define ID_OK_DigOut_3 1115
extern int OK_DigOut_3;
int doWrite_OK_DigOut_3(int value);
int prepareWrite_OK_DigOut_3(int value);
 
#define ID_OK_DigOut_4 1116
extern int OK_DigOut_4;
int doWrite_OK_DigOut_4(int value);
int prepareWrite_OK_DigOut_4(int value);
 
#define ID_OK_DigOut_5 1117
extern int OK_DigOut_5;
int doWrite_OK_DigOut_5(int value);
int prepareWrite_OK_DigOut_5(int value);
 
#define ID_OK_DigOut_6 1118
extern int OK_DigOut_6;
int doWrite_OK_DigOut_6(int value);
int prepareWrite_OK_DigOut_6(int value);
 
#define ID_OK_DigOut_7 1119
extern int OK_DigOut_7;
int doWrite_OK_DigOut_7(int value);
int prepareWrite_OK_DigOut_7(int value);
 
#define ID_OK_DigOut_8 1120
extern int OK_DigOut_8;
int doWrite_OK_DigOut_8(int value);
int prepareWrite_OK_DigOut_8(int value);
 
#define ID_OK_DigOut_9 1121
extern int OK_DigOut_9;
int doWrite_OK_DigOut_9(int value);
int prepareWrite_OK_DigOut_9(int value);
 
#define ID_OK_DigOut_10 1122
extern int OK_DigOut_10;
int doWrite_OK_DigOut_10(int value);
int prepareWrite_OK_DigOut_10(int value);
 
#define ID_OK_DigOut_11 1123
extern int OK_DigOut_11;
int doWrite_OK_DigOut_11(int value);
int prepareWrite_OK_DigOut_11(int value);
 
#define ID_OK_DigOut_12 1124
extern int OK_DigOut_12;
int doWrite_OK_DigOut_12(int value);
int prepareWrite_OK_DigOut_12(int value);
 
#define ID_OK_DigOut_13 1125
extern int OK_DigOut_13;
int doWrite_OK_DigOut_13(int value);
int prepareWrite_OK_DigOut_13(int value);
 
#define ID_OK_DigOut_14 1126
extern int OK_DigOut_14;
int doWrite_OK_DigOut_14(int value);
int prepareWrite_OK_DigOut_14(int value);
 
#define ID_OK_DigOut_15 1127
extern int OK_DigOut_15;
int doWrite_OK_DigOut_15(int value);
int prepareWrite_OK_DigOut_15(int value);
 
#define ID_OK_DigOut_16 1128
extern int OK_DigOut_16;
int doWrite_OK_DigOut_16(int value);
int prepareWrite_OK_DigOut_16(int value);
 
#define ID_TST_AnIn_1 1129
extern int TST_AnIn_1;
int doWrite_TST_AnIn_1(int value);
int prepareWrite_TST_AnIn_1(int value);
 
#define ID_TST_AnIn_2 1130
extern int TST_AnIn_2;
int doWrite_TST_AnIn_2(int value);
int prepareWrite_TST_AnIn_2(int value);
 
#define ID_TST_AnIn_3 1131
extern int TST_AnIn_3;
int doWrite_TST_AnIn_3(int value);
int prepareWrite_TST_AnIn_3(int value);
 
#define ID_TST_AnIn_4 1132
extern int TST_AnIn_4;
int doWrite_TST_AnIn_4(int value);
int prepareWrite_TST_AnIn_4(int value);
 
#define ID_TST_AnIn_5 1133
extern int TST_AnIn_5;
int doWrite_TST_AnIn_5(int value);
int prepareWrite_TST_AnIn_5(int value);
 
#define ID_TST_AnIn_6 1134
extern int TST_AnIn_6;
int doWrite_TST_AnIn_6(int value);
int prepareWrite_TST_AnIn_6(int value);
 
#define ID_TST_AnIn_7 1135
extern int TST_AnIn_7;
int doWrite_TST_AnIn_7(int value);
int prepareWrite_TST_AnIn_7(int value);
 
#define ID_TST_AnIn_8 1136
extern int TST_AnIn_8;
int doWrite_TST_AnIn_8(int value);
int prepareWrite_TST_AnIn_8(int value);
 
#define ID_TST_AnIn_9 1137
extern int TST_AnIn_9;
int doWrite_TST_AnIn_9(int value);
int prepareWrite_TST_AnIn_9(int value);
 
#define ID_TST_AnIn_10 1138
extern int TST_AnIn_10;
int doWrite_TST_AnIn_10(int value);
int prepareWrite_TST_AnIn_10(int value);
 
#define ID_TST_AnIn_11 1139
extern int TST_AnIn_11;
int doWrite_TST_AnIn_11(int value);
int prepareWrite_TST_AnIn_11(int value);
 
#define ID_TST_AnIn_12 1140
extern int TST_AnIn_12;
int doWrite_TST_AnIn_12(int value);
int prepareWrite_TST_AnIn_12(int value);
 
#define ID_VAL_AnIn_1 1141
extern int16_t VAL_AnIn_1;
int doWrite_VAL_AnIn_1(int16_t value);
int prepareWrite_VAL_AnIn_1(int16_t value);
 
#define ID_VAL_AnIn_2 1142
extern int16_t VAL_AnIn_2;
int doWrite_VAL_AnIn_2(int16_t value);
int prepareWrite_VAL_AnIn_2(int16_t value);
 
#define ID_VAL_AnIn_3 1143
extern int16_t VAL_AnIn_3;
int doWrite_VAL_AnIn_3(int16_t value);
int prepareWrite_VAL_AnIn_3(int16_t value);
 
#define ID_VAL_AnIn_4 1144
extern int16_t VAL_AnIn_4;
int doWrite_VAL_AnIn_4(int16_t value);
int prepareWrite_VAL_AnIn_4(int16_t value);
 
#define ID_VAL_AnIn_5 1145
extern int16_t VAL_AnIn_5;
int doWrite_VAL_AnIn_5(int16_t value);
int prepareWrite_VAL_AnIn_5(int16_t value);
 
#define ID_VAL_AnIn_6 1146
extern int16_t VAL_AnIn_6;
int doWrite_VAL_AnIn_6(int16_t value);
int prepareWrite_VAL_AnIn_6(int16_t value);
 
#define ID_VAL_AnIn_7 1147
extern int16_t VAL_AnIn_7;
int doWrite_VAL_AnIn_7(int16_t value);
int prepareWrite_VAL_AnIn_7(int16_t value);
 
#define ID_VAL_AnIn_8 1148
extern int16_t VAL_AnIn_8;
int doWrite_VAL_AnIn_8(int16_t value);
int prepareWrite_VAL_AnIn_8(int16_t value);
 
#define ID_VAL_AnIn_9 1149
extern int16_t VAL_AnIn_9;
int doWrite_VAL_AnIn_9(int16_t value);
int prepareWrite_VAL_AnIn_9(int16_t value);
 
#define ID_VAL_AnIn_10 1150
extern int16_t VAL_AnIn_10;
int doWrite_VAL_AnIn_10(int16_t value);
int prepareWrite_VAL_AnIn_10(int16_t value);
 
#define ID_VAL_AnIn_11 1151
extern int16_t VAL_AnIn_11;
int doWrite_VAL_AnIn_11(int16_t value);
int prepareWrite_VAL_AnIn_11(int16_t value);
 
#define ID_VAL_AnIn_12 1152
extern int16_t VAL_AnIn_12;
int doWrite_VAL_AnIn_12(int16_t value);
int prepareWrite_VAL_AnIn_12(int16_t value);
 
#define ID_VAL_AnInConf_1 1153
extern u_int16_t VAL_AnInConf_1;
int doWrite_VAL_AnInConf_1(u_int16_t value);
int prepareWrite_VAL_AnInConf_1(u_int16_t value);
 
#define ID_VAL_AnInConf_2 1154
extern u_int16_t VAL_AnInConf_2;
int doWrite_VAL_AnInConf_2(u_int16_t value);
int prepareWrite_VAL_AnInConf_2(u_int16_t value);
 
#define ID_VAL_AnInConf_3 1155
extern u_int16_t VAL_AnInConf_3;
int doWrite_VAL_AnInConf_3(u_int16_t value);
int prepareWrite_VAL_AnInConf_3(u_int16_t value);
 
#define ID_VAL_AnInConf_4 1156
extern u_int16_t VAL_AnInConf_4;
int doWrite_VAL_AnInConf_4(u_int16_t value);
int prepareWrite_VAL_AnInConf_4(u_int16_t value);
 
#define ID_VAL_AnInConf_5 1157
extern u_int16_t VAL_AnInConf_5;
int doWrite_VAL_AnInConf_5(u_int16_t value);
int prepareWrite_VAL_AnInConf_5(u_int16_t value);
 
#define ID_VAL_AnInConf_6 1158
extern u_int16_t VAL_AnInConf_6;
int doWrite_VAL_AnInConf_6(u_int16_t value);
int prepareWrite_VAL_AnInConf_6(u_int16_t value);
 
#define ID_VAL_AnInConf_7 1159
extern u_int16_t VAL_AnInConf_7;
int doWrite_VAL_AnInConf_7(u_int16_t value);
int prepareWrite_VAL_AnInConf_7(u_int16_t value);
 
#define ID_VAL_AnInConf_8 1160
extern u_int16_t VAL_AnInConf_8;
int doWrite_VAL_AnInConf_8(u_int16_t value);
int prepareWrite_VAL_AnInConf_8(u_int16_t value);
 
#define ID_VAL_AnInConf_9 1161
extern u_int16_t VAL_AnInConf_9;
int doWrite_VAL_AnInConf_9(u_int16_t value);
int prepareWrite_VAL_AnInConf_9(u_int16_t value);
 
#define ID_VAL_AnInConf_10 1162
extern u_int16_t VAL_AnInConf_10;
int doWrite_VAL_AnInConf_10(u_int16_t value);
int prepareWrite_VAL_AnInConf_10(u_int16_t value);
 
#define ID_VAL_AnInConf_11 1163
extern u_int16_t VAL_AnInConf_11;
int doWrite_VAL_AnInConf_11(u_int16_t value);
int prepareWrite_VAL_AnInConf_11(u_int16_t value);
 
#define ID_VAL_AnInConf_12 1164
extern u_int16_t VAL_AnInConf_12;
int doWrite_VAL_AnInConf_12(u_int16_t value);
int prepareWrite_VAL_AnInConf_12(u_int16_t value);
 
#define ID_VAL_AnInFltr_1 1165
extern u_int16_t VAL_AnInFltr_1;
int doWrite_VAL_AnInFltr_1(u_int16_t value);
int prepareWrite_VAL_AnInFltr_1(u_int16_t value);
 
#define ID_VAL_AnInFltr_2 1166
extern u_int16_t VAL_AnInFltr_2;
int doWrite_VAL_AnInFltr_2(u_int16_t value);
int prepareWrite_VAL_AnInFltr_2(u_int16_t value);
 
#define ID_VAL_AnInFltr_3 1167
extern u_int16_t VAL_AnInFltr_3;
int doWrite_VAL_AnInFltr_3(u_int16_t value);
int prepareWrite_VAL_AnInFltr_3(u_int16_t value);
 
#define ID_VAL_AnInFltr_4 1168
extern u_int16_t VAL_AnInFltr_4;
int doWrite_VAL_AnInFltr_4(u_int16_t value);
int prepareWrite_VAL_AnInFltr_4(u_int16_t value);
 
#define ID_VAL_AnInFltr_5 1169
extern u_int16_t VAL_AnInFltr_5;
int doWrite_VAL_AnInFltr_5(u_int16_t value);
int prepareWrite_VAL_AnInFltr_5(u_int16_t value);
 
#define ID_VAL_AnInFltr_6 1170
extern u_int16_t VAL_AnInFltr_6;
int doWrite_VAL_AnInFltr_6(u_int16_t value);
int prepareWrite_VAL_AnInFltr_6(u_int16_t value);
 
#define ID_VAL_AnInFltr_7 1171
extern u_int16_t VAL_AnInFltr_7;
int doWrite_VAL_AnInFltr_7(u_int16_t value);
int prepareWrite_VAL_AnInFltr_7(u_int16_t value);
 
#define ID_VAL_AnInFltr_8 1172
extern u_int16_t VAL_AnInFltr_8;
int doWrite_VAL_AnInFltr_8(u_int16_t value);
int prepareWrite_VAL_AnInFltr_8(u_int16_t value);
 
#define ID_VAL_AnInFltr_9 1173
extern u_int16_t VAL_AnInFltr_9;
int doWrite_VAL_AnInFltr_9(u_int16_t value);
int prepareWrite_VAL_AnInFltr_9(u_int16_t value);
 
#define ID_VAL_AnInFltr_10 1174
extern u_int16_t VAL_AnInFltr_10;
int doWrite_VAL_AnInFltr_10(u_int16_t value);
int prepareWrite_VAL_AnInFltr_10(u_int16_t value);
 
#define ID_VAL_AnInFltr_11 1175
extern u_int16_t VAL_AnInFltr_11;
int doWrite_VAL_AnInFltr_11(u_int16_t value);
int prepareWrite_VAL_AnInFltr_11(u_int16_t value);
 
#define ID_VAL_AnInFltr_12 1176
extern u_int16_t VAL_AnInFltr_12;
int doWrite_VAL_AnInFltr_12(u_int16_t value);
int prepareWrite_VAL_AnInFltr_12(u_int16_t value);
 
#define ID_RES_AnIn_1 1177
extern int16_t RES_AnIn_1;
int doWrite_RES_AnIn_1(int16_t value);
int prepareWrite_RES_AnIn_1(int16_t value);
 
#define ID_RES_AnIn_2 1178
extern int16_t RES_AnIn_2;
int doWrite_RES_AnIn_2(int16_t value);
int prepareWrite_RES_AnIn_2(int16_t value);
 
#define ID_RES_AnIn_3 1179
extern int16_t RES_AnIn_3;
int doWrite_RES_AnIn_3(int16_t value);
int prepareWrite_RES_AnIn_3(int16_t value);
 
#define ID_RES_AnIn_4 1180
extern int16_t RES_AnIn_4;
int doWrite_RES_AnIn_4(int16_t value);
int prepareWrite_RES_AnIn_4(int16_t value);
 
#define ID_RES_AnIn_5 1181
extern int16_t RES_AnIn_5;
int doWrite_RES_AnIn_5(int16_t value);
int prepareWrite_RES_AnIn_5(int16_t value);
 
#define ID_RES_AnIn_6 1182
extern int16_t RES_AnIn_6;
int doWrite_RES_AnIn_6(int16_t value);
int prepareWrite_RES_AnIn_6(int16_t value);
 
#define ID_RES_AnIn_7 1183
extern int16_t RES_AnIn_7;
int doWrite_RES_AnIn_7(int16_t value);
int prepareWrite_RES_AnIn_7(int16_t value);
 
#define ID_RES_AnIn_8 1184
extern int16_t RES_AnIn_8;
int doWrite_RES_AnIn_8(int16_t value);
int prepareWrite_RES_AnIn_8(int16_t value);
 
#define ID_RES_AnIn_9 1185
extern int16_t RES_AnIn_9;
int doWrite_RES_AnIn_9(int16_t value);
int prepareWrite_RES_AnIn_9(int16_t value);
 
#define ID_RES_AnIn_10 1186
extern int16_t RES_AnIn_10;
int doWrite_RES_AnIn_10(int16_t value);
int prepareWrite_RES_AnIn_10(int16_t value);
 
#define ID_RES_AnIn_11 1187
extern int16_t RES_AnIn_11;
int doWrite_RES_AnIn_11(int16_t value);
int prepareWrite_RES_AnIn_11(int16_t value);
 
#define ID_RES_AnIn_12 1188
extern int16_t RES_AnIn_12;
int doWrite_RES_AnIn_12(int16_t value);
int prepareWrite_RES_AnIn_12(int16_t value);
 
#define ID_RES_AnInStts_1 1189
extern int16_t RES_AnInStts_1;
int doWrite_RES_AnInStts_1(int16_t value);
int prepareWrite_RES_AnInStts_1(int16_t value);
 
#define ID_RES_AnInStts_2 1190
extern int16_t RES_AnInStts_2;
int doWrite_RES_AnInStts_2(int16_t value);
int prepareWrite_RES_AnInStts_2(int16_t value);
 
#define ID_RES_AnInStts_3 1191
extern int16_t RES_AnInStts_3;
int doWrite_RES_AnInStts_3(int16_t value);
int prepareWrite_RES_AnInStts_3(int16_t value);
 
#define ID_RES_AnInStts_4 1192
extern int16_t RES_AnInStts_4;
int doWrite_RES_AnInStts_4(int16_t value);
int prepareWrite_RES_AnInStts_4(int16_t value);
 
#define ID_RES_AnInStts_5 1193
extern int16_t RES_AnInStts_5;
int doWrite_RES_AnInStts_5(int16_t value);
int prepareWrite_RES_AnInStts_5(int16_t value);
 
#define ID_RES_AnInStts_6 1194
extern int16_t RES_AnInStts_6;
int doWrite_RES_AnInStts_6(int16_t value);
int prepareWrite_RES_AnInStts_6(int16_t value);
 
#define ID_RES_AnInStts_7 1195
extern int16_t RES_AnInStts_7;
int doWrite_RES_AnInStts_7(int16_t value);
int prepareWrite_RES_AnInStts_7(int16_t value);
 
#define ID_RES_AnInStts_8 1196
extern int16_t RES_AnInStts_8;
int doWrite_RES_AnInStts_8(int16_t value);
int prepareWrite_RES_AnInStts_8(int16_t value);
 
#define ID_RES_AnInStts_9 1197
extern int16_t RES_AnInStts_9;
int doWrite_RES_AnInStts_9(int16_t value);
int prepareWrite_RES_AnInStts_9(int16_t value);
 
#define ID_RES_AnInStts_10 1198
extern int16_t RES_AnInStts_10;
int doWrite_RES_AnInStts_10(int16_t value);
int prepareWrite_RES_AnInStts_10(int16_t value);
 
#define ID_RES_AnInStts_11 1199
extern int16_t RES_AnInStts_11;
int doWrite_RES_AnInStts_11(int16_t value);
int prepareWrite_RES_AnInStts_11(int16_t value);
 
#define ID_RES_AnInStts_12 1200
extern int16_t RES_AnInStts_12;
int doWrite_RES_AnInStts_12(int16_t value);
int prepareWrite_RES_AnInStts_12(int16_t value);
 
#define ID_OK_AnIn_1 1201
extern int OK_AnIn_1;
int doWrite_OK_AnIn_1(int value);
int prepareWrite_OK_AnIn_1(int value);
 
#define ID_OK_AnIn_2 1202
extern int OK_AnIn_2;
int doWrite_OK_AnIn_2(int value);
int prepareWrite_OK_AnIn_2(int value);
 
#define ID_OK_AnIn_3 1203
extern int OK_AnIn_3;
int doWrite_OK_AnIn_3(int value);
int prepareWrite_OK_AnIn_3(int value);
 
#define ID_OK_AnIn_4 1204
extern int OK_AnIn_4;
int doWrite_OK_AnIn_4(int value);
int prepareWrite_OK_AnIn_4(int value);
 
#define ID_OK_AnIn_5 1205
extern int OK_AnIn_5;
int doWrite_OK_AnIn_5(int value);
int prepareWrite_OK_AnIn_5(int value);
 
#define ID_OK_AnIn_6 1206
extern int OK_AnIn_6;
int doWrite_OK_AnIn_6(int value);
int prepareWrite_OK_AnIn_6(int value);
 
#define ID_OK_AnIn_7 1207
extern int OK_AnIn_7;
int doWrite_OK_AnIn_7(int value);
int prepareWrite_OK_AnIn_7(int value);
 
#define ID_OK_AnIn_8 1208
extern int OK_AnIn_8;
int doWrite_OK_AnIn_8(int value);
int prepareWrite_OK_AnIn_8(int value);
 
#define ID_OK_AnIn_9 1209
extern int OK_AnIn_9;
int doWrite_OK_AnIn_9(int value);
int prepareWrite_OK_AnIn_9(int value);
 
#define ID_OK_AnIn_10 1210
extern int OK_AnIn_10;
int doWrite_OK_AnIn_10(int value);
int prepareWrite_OK_AnIn_10(int value);
 
#define ID_OK_AnIn_11 1211
extern int OK_AnIn_11;
int doWrite_OK_AnIn_11(int value);
int prepareWrite_OK_AnIn_11(int value);
 
#define ID_OK_AnIn_12 1212
extern int OK_AnIn_12;
int doWrite_OK_AnIn_12(int value);
int prepareWrite_OK_AnIn_12(int value);
 
#define ID_TST_AnOut_1 1213
extern int TST_AnOut_1;
int doWrite_TST_AnOut_1(int value);
int prepareWrite_TST_AnOut_1(int value);
 
#define ID_TST_AnOut_2 1214
extern int TST_AnOut_2;
int doWrite_TST_AnOut_2(int value);
int prepareWrite_TST_AnOut_2(int value);
 
#define ID_TST_AnOut_3 1215
extern int TST_AnOut_3;
int doWrite_TST_AnOut_3(int value);
int prepareWrite_TST_AnOut_3(int value);
 
#define ID_TST_AnOut_4 1216
extern int TST_AnOut_4;
int doWrite_TST_AnOut_4(int value);
int prepareWrite_TST_AnOut_4(int value);
 
#define ID_VAL_AnOut_1 1217
extern int16_t VAL_AnOut_1;
int doWrite_VAL_AnOut_1(int16_t value);
int prepareWrite_VAL_AnOut_1(int16_t value);
 
#define ID_VAL_AnOut_2 1218
extern int16_t VAL_AnOut_2;
int doWrite_VAL_AnOut_2(int16_t value);
int prepareWrite_VAL_AnOut_2(int16_t value);
 
#define ID_VAL_AnOut_3 1219
extern int16_t VAL_AnOut_3;
int doWrite_VAL_AnOut_3(int16_t value);
int prepareWrite_VAL_AnOut_3(int16_t value);
 
#define ID_VAL_AnOut_4 1220
extern int16_t VAL_AnOut_4;
int doWrite_VAL_AnOut_4(int16_t value);
int prepareWrite_VAL_AnOut_4(int16_t value);
 
#define ID_VAL_AnOutConf_1 1221
extern u_int16_t VAL_AnOutConf_1;
int doWrite_VAL_AnOutConf_1(u_int16_t value);
int prepareWrite_VAL_AnOutConf_1(u_int16_t value);
 
#define ID_VAL_AnOutConf_2 1222
extern u_int16_t VAL_AnOutConf_2;
int doWrite_VAL_AnOutConf_2(u_int16_t value);
int prepareWrite_VAL_AnOutConf_2(u_int16_t value);
 
#define ID_VAL_AnOutConf_3 1223
extern u_int16_t VAL_AnOutConf_3;
int doWrite_VAL_AnOutConf_3(u_int16_t value);
int prepareWrite_VAL_AnOutConf_3(u_int16_t value);
 
#define ID_VAL_AnOutConf_4 1224
extern u_int16_t VAL_AnOutConf_4;
int doWrite_VAL_AnOutConf_4(u_int16_t value);
int prepareWrite_VAL_AnOutConf_4(u_int16_t value);
 
#define ID_RES_AnOut_1 1225
extern int16_t RES_AnOut_1;
int doWrite_RES_AnOut_1(int16_t value);
int prepareWrite_RES_AnOut_1(int16_t value);
 
#define ID_RES_AnOut_2 1226
extern int16_t RES_AnOut_2;
int doWrite_RES_AnOut_2(int16_t value);
int prepareWrite_RES_AnOut_2(int16_t value);
 
#define ID_RES_AnOut_3 1227
extern int16_t RES_AnOut_3;
int doWrite_RES_AnOut_3(int16_t value);
int prepareWrite_RES_AnOut_3(int16_t value);
 
#define ID_RES_AnOut_4 1228
extern int16_t RES_AnOut_4;
int doWrite_RES_AnOut_4(int16_t value);
int prepareWrite_RES_AnOut_4(int16_t value);
 
#define ID_RES_AnOutStts_1 1229
extern int16_t RES_AnOutStts_1;
int doWrite_RES_AnOutStts_1(int16_t value);
int prepareWrite_RES_AnOutStts_1(int16_t value);
 
#define ID_RES_AnOutStts_2 1230
extern int16_t RES_AnOutStts_2;
int doWrite_RES_AnOutStts_2(int16_t value);
int prepareWrite_RES_AnOutStts_2(int16_t value);
 
#define ID_RES_AnOutStts_3 1231
extern int16_t RES_AnOutStts_3;
int doWrite_RES_AnOutStts_3(int16_t value);
int prepareWrite_RES_AnOutStts_3(int16_t value);
 
#define ID_RES_AnOutStts_4 1232
extern int16_t RES_AnOutStts_4;
int doWrite_RES_AnOutStts_4(int16_t value);
int prepareWrite_RES_AnOutStts_4(int16_t value);
 
#define ID_OK_AnOut_1 1233
extern int OK_AnOut_1;
int doWrite_OK_AnOut_1(int value);
int prepareWrite_OK_AnOut_1(int value);
 
#define ID_OK_AnOut_2 1234
extern int OK_AnOut_2;
int doWrite_OK_AnOut_2(int value);
int prepareWrite_OK_AnOut_2(int value);
 
#define ID_OK_AnOut_3 1235
extern int OK_AnOut_3;
int doWrite_OK_AnOut_3(int value);
int prepareWrite_OK_AnOut_3(int value);
 
#define ID_OK_AnOut_4 1236
extern int OK_AnOut_4;
int doWrite_OK_AnOut_4(int value);
int prepareWrite_OK_AnOut_4(int value);
 
#define ID_TST_Tamb 1237
extern int TST_Tamb;
int doWrite_TST_Tamb(int value);
int prepareWrite_TST_Tamb(int value);
 
#define ID_TST_RPM 1238
extern int TST_RPM;
int doWrite_TST_RPM(int value);
int prepareWrite_TST_RPM(int value);
 
#define ID_TST_VCC_set 1239
extern int TST_VCC_set;
int doWrite_TST_VCC_set(int value);
int prepareWrite_TST_VCC_set(int value);
 
#define ID_TST_mA_max 1240
extern int TST_mA_max;
int doWrite_TST_mA_max(int value);
int prepareWrite_TST_mA_max(int value);
 
#define ID_TST_VCC_fbk 1241
extern int TST_VCC_fbk;
int doWrite_TST_VCC_fbk(int value);
int prepareWrite_TST_VCC_fbk(int value);
 
#define ID_TST_mA_fbk 1242
extern int TST_mA_fbk;
int doWrite_TST_mA_fbk(int value);
int prepareWrite_TST_mA_fbk(int value);
 
#define ID_TST_FWrevision 1243
extern int TST_FWrevision;
int doWrite_TST_FWrevision(int value);
int prepareWrite_TST_FWrevision(int value);
 
#define ID_TST_HWconfig 1244
extern int TST_HWconfig;
int doWrite_TST_HWconfig(int value);
int prepareWrite_TST_HWconfig(int value);
 
#define ID_VAL_Tamb 1245
extern int16_t VAL_Tamb;
int doWrite_VAL_Tamb(int16_t value);
int prepareWrite_VAL_Tamb(int16_t value);
 
#define ID_VAL_RPM 1246
extern u_int16_t VAL_RPM;
int doWrite_VAL_RPM(u_int16_t value);
int prepareWrite_VAL_RPM(u_int16_t value);
 
#define ID_VAL_VCC_set 1247
extern int16_t VAL_VCC_set;
int doWrite_VAL_VCC_set(int16_t value);
int prepareWrite_VAL_VCC_set(int16_t value);
 
#define ID_VAL_mA_max 1248
extern int16_t VAL_mA_max;
int doWrite_VAL_mA_max(int16_t value);
int prepareWrite_VAL_mA_max(int16_t value);
 
#define ID_VAL_VCC_fbk 1249
extern int16_t VAL_VCC_fbk;
int doWrite_VAL_VCC_fbk(int16_t value);
int prepareWrite_VAL_VCC_fbk(int16_t value);
 
#define ID_VAL_mA_fbk 1250
extern int16_t VAL_mA_fbk;
int doWrite_VAL_mA_fbk(int16_t value);
int prepareWrite_VAL_mA_fbk(int16_t value);
 
#define ID_VAL_FWrevision 1251
extern u_int16_t VAL_FWrevision;
int doWrite_VAL_FWrevision(u_int16_t value);
int prepareWrite_VAL_FWrevision(u_int16_t value);
 
#define ID_VAL_HWconfig 1252
extern u_int16_t VAL_HWconfig;
int doWrite_VAL_HWconfig(u_int16_t value);
int prepareWrite_VAL_HWconfig(u_int16_t value);
 
#define ID_RES_Tamb 1253
extern int16_t RES_Tamb;
int doWrite_RES_Tamb(int16_t value);
int prepareWrite_RES_Tamb(int16_t value);
 
#define ID_RES_RPM 1254
extern u_int16_t RES_RPM;
int doWrite_RES_RPM(u_int16_t value);
int prepareWrite_RES_RPM(u_int16_t value);
 
#define ID_RES_VCC_set 1255
extern int16_t RES_VCC_set;
int doWrite_RES_VCC_set(int16_t value);
int prepareWrite_RES_VCC_set(int16_t value);
 
#define ID_RES_mA_max 1256
extern int16_t RES_mA_max;
int doWrite_RES_mA_max(int16_t value);
int prepareWrite_RES_mA_max(int16_t value);
 
#define ID_RES_VCC_fbk 1257
extern int16_t RES_VCC_fbk;
int doWrite_RES_VCC_fbk(int16_t value);
int prepareWrite_RES_VCC_fbk(int16_t value);
 
#define ID_RES_mA_fbk 1258
extern int16_t RES_mA_fbk;
int doWrite_RES_mA_fbk(int16_t value);
int prepareWrite_RES_mA_fbk(int16_t value);
 
#define ID_RES_FWrevision 1259
extern u_int16_t RES_FWrevision;
int doWrite_RES_FWrevision(u_int16_t value);
int prepareWrite_RES_FWrevision(u_int16_t value);
 
#define ID_RES_HWconfig 1260
extern u_int16_t RES_HWconfig;
int doWrite_RES_HWconfig(u_int16_t value);
int prepareWrite_RES_HWconfig(u_int16_t value);
 
#define ID_OK_Tamb 1261
extern int OK_Tamb;
int doWrite_OK_Tamb(int value);
int prepareWrite_OK_Tamb(int value);
 
#define ID_OK_RPM 1262
extern int OK_RPM;
int doWrite_OK_RPM(int value);
int prepareWrite_OK_RPM(int value);
 
#define ID_OK_VCC_set 1263
extern int OK_VCC_set;
int doWrite_OK_VCC_set(int value);
int prepareWrite_OK_VCC_set(int value);
 
#define ID_OK_mA_max 1264
extern int OK_mA_max;
int doWrite_OK_mA_max(int value);
int prepareWrite_OK_mA_max(int value);
 
#define ID_OK_VCC_fbk 1265
extern int OK_VCC_fbk;
int doWrite_OK_VCC_fbk(int value);
int prepareWrite_OK_VCC_fbk(int value);
 
#define ID_OK_mA_fbk 1266
extern int OK_mA_fbk;
int doWrite_OK_mA_fbk(int value);
int prepareWrite_OK_mA_fbk(int value);
 
#define ID_OK_FWrevision 1267
extern int OK_FWrevision;
int doWrite_OK_FWrevision(int value);
int prepareWrite_OK_FWrevision(int value);
 
#define ID_OK_HWconfig 1268
extern int OK_HWconfig;
int doWrite_OK_HWconfig(int value);
int prepareWrite_OK_HWconfig(int value);
 
#define ID_TST_RTUS_WR 1269
extern int TST_RTUS_WR;
int doWrite_TST_RTUS_WR(int value);
int prepareWrite_TST_RTUS_WR(int value);
 
#define ID_TST_RTUS_RD 1270
extern int TST_RTUS_RD;
int doWrite_TST_RTUS_RD(int value);
int prepareWrite_TST_RTUS_RD(int value);
 
#define ID_TST_RTU1_WR 1271
extern int TST_RTU1_WR;
int doWrite_TST_RTU1_WR(int value);
int prepareWrite_TST_RTU1_WR(int value);
 
#define ID_TST_RTU1_RD 1272
extern int TST_RTU1_RD;
int doWrite_TST_RTU1_RD(int value);
int prepareWrite_TST_RTU1_RD(int value);
 
#define ID_TST_RTU3_WR 1273
extern int TST_RTU3_WR;
int doWrite_TST_RTU3_WR(int value);
int prepareWrite_TST_RTU3_WR(int value);
 
#define ID_TST_RTU3_RD 1274
extern int TST_RTU3_RD;
int doWrite_TST_RTU3_RD(int value);
int prepareWrite_TST_RTU3_RD(int value);
 
#define ID_TST_CAN1_WR 1275
extern int TST_CAN1_WR;
int doWrite_TST_CAN1_WR(int value);
int prepareWrite_TST_CAN1_WR(int value);
 
#define ID_TST_CAN1_RD 1276
extern int TST_CAN1_RD;
int doWrite_TST_CAN1_RD(int value);
int prepareWrite_TST_CAN1_RD(int value);
 
#define ID_VAL_RTUS_WR 1277
extern int VAL_RTUS_WR;
int doWrite_VAL_RTUS_WR(int value);
int prepareWrite_VAL_RTUS_WR(int value);
 
#define ID_VAL_RTUS_RD 1278
extern int VAL_RTUS_RD;
int doWrite_VAL_RTUS_RD(int value);
int prepareWrite_VAL_RTUS_RD(int value);
 
#define ID_VAL_RTU1_WR 1279
extern int VAL_RTU1_WR;
int doWrite_VAL_RTU1_WR(int value);
int prepareWrite_VAL_RTU1_WR(int value);
 
#define ID_VAL_RTU1_RD 1280
extern int VAL_RTU1_RD;
int doWrite_VAL_RTU1_RD(int value);
int prepareWrite_VAL_RTU1_RD(int value);
 
#define ID_VAL_RTU3_WR 1281
extern int VAL_RTU3_WR;
int doWrite_VAL_RTU3_WR(int value);
int prepareWrite_VAL_RTU3_WR(int value);
 
#define ID_VAL_RTU3_RD 1282
extern int VAL_RTU3_RD;
int doWrite_VAL_RTU3_RD(int value);
int prepareWrite_VAL_RTU3_RD(int value);
 
#define ID_VAL_CAN1_WR 1283
extern int VAL_CAN1_WR;
int doWrite_VAL_CAN1_WR(int value);
int prepareWrite_VAL_CAN1_WR(int value);
 
#define ID_VAL_CAN1_RD 1284
extern int VAL_CAN1_RD;
int doWrite_VAL_CAN1_RD(int value);
int prepareWrite_VAL_CAN1_RD(int value);
 
#define ID_RES_RTUS_WR 1285
extern int RES_RTUS_WR;
int doWrite_RES_RTUS_WR(int value);
int prepareWrite_RES_RTUS_WR(int value);
 
#define ID_RES_RTUS_RD 1286
extern int RES_RTUS_RD;
int doWrite_RES_RTUS_RD(int value);
int prepareWrite_RES_RTUS_RD(int value);
 
#define ID_RES_RTU1_WR 1287
extern int RES_RTU1_WR;
int doWrite_RES_RTU1_WR(int value);
int prepareWrite_RES_RTU1_WR(int value);
 
#define ID_RES_RTU1_RD 1288
extern int RES_RTU1_RD;
int doWrite_RES_RTU1_RD(int value);
int prepareWrite_RES_RTU1_RD(int value);
 
#define ID_RES_RTU3_WR 1289
extern int RES_RTU3_WR;
int doWrite_RES_RTU3_WR(int value);
int prepareWrite_RES_RTU3_WR(int value);
 
#define ID_RES_RTU3_RD 1290
extern int RES_RTU3_RD;
int doWrite_RES_RTU3_RD(int value);
int prepareWrite_RES_RTU3_RD(int value);
 
#define ID_RES_CAN1_WR 1291
extern int RES_CAN1_WR;
int doWrite_RES_CAN1_WR(int value);
int prepareWrite_RES_CAN1_WR(int value);
 
#define ID_RES_CAN1_RD 1292
extern int RES_CAN1_RD;
int doWrite_RES_CAN1_RD(int value);
int prepareWrite_RES_CAN1_RD(int value);
 
#define ID_OK_RTUS_WR 1293
extern int OK_RTUS_WR;
int doWrite_OK_RTUS_WR(int value);
int prepareWrite_OK_RTUS_WR(int value);
 
#define ID_OK_RTUS_RD 1294
extern int OK_RTUS_RD;
int doWrite_OK_RTUS_RD(int value);
int prepareWrite_OK_RTUS_RD(int value);
 
#define ID_OK_RTU1_WR 1295
extern int OK_RTU1_WR;
int doWrite_OK_RTU1_WR(int value);
int prepareWrite_OK_RTU1_WR(int value);
 
#define ID_OK_RTU1_RD 1296
extern int OK_RTU1_RD;
int doWrite_OK_RTU1_RD(int value);
int prepareWrite_OK_RTU1_RD(int value);
 
#define ID_OK_RTU3_WR 1297
extern int OK_RTU3_WR;
int doWrite_OK_RTU3_WR(int value);
int prepareWrite_OK_RTU3_WR(int value);
 
#define ID_OK_RTU3_RD 1298
extern int OK_RTU3_RD;
int doWrite_OK_RTU3_RD(int value);
int prepareWrite_OK_RTU3_RD(int value);
 
#define ID_OK_CAN1_WR 1299
extern int OK_CAN1_WR;
int doWrite_OK_CAN1_WR(int value);
int prepareWrite_OK_CAN1_WR(int value);
 
#define ID_OK_CAN1_RD 1300
extern int OK_CAN1_RD;
int doWrite_OK_CAN1_RD(int value);
int prepareWrite_OK_CAN1_RD(int value);
 
#define ID_START2_REMOTE 2999
extern int START2_REMOTE;
int doWrite_START2_REMOTE(int value);
int prepareWrite_START2_REMOTE(int value);
 
#define ID_START2_TEST 3000
extern int START2_TEST;
int doWrite_START2_TEST(int value);
int prepareWrite_START2_TEST(int value);
 
#define ID_TST2_DigIn_1 3001
extern int TST2_DigIn_1;
int doWrite_TST2_DigIn_1(int value);
int prepareWrite_TST2_DigIn_1(int value);
 
#define ID_TST2_DigIn_2 3002
extern int TST2_DigIn_2;
int doWrite_TST2_DigIn_2(int value);
int prepareWrite_TST2_DigIn_2(int value);
 
#define ID_TST2_DigIn_3 3003
extern int TST2_DigIn_3;
int doWrite_TST2_DigIn_3(int value);
int prepareWrite_TST2_DigIn_3(int value);
 
#define ID_TST2_DigIn_4 3004
extern int TST2_DigIn_4;
int doWrite_TST2_DigIn_4(int value);
int prepareWrite_TST2_DigIn_4(int value);
 
#define ID_TST2_DigIn_5 3005
extern int TST2_DigIn_5;
int doWrite_TST2_DigIn_5(int value);
int prepareWrite_TST2_DigIn_5(int value);
 
#define ID_TST2_DigIn_6 3006
extern int TST2_DigIn_6;
int doWrite_TST2_DigIn_6(int value);
int prepareWrite_TST2_DigIn_6(int value);
 
#define ID_TST2_DigIn_7 3007
extern int TST2_DigIn_7;
int doWrite_TST2_DigIn_7(int value);
int prepareWrite_TST2_DigIn_7(int value);
 
#define ID_TST2_DigIn_8 3008
extern int TST2_DigIn_8;
int doWrite_TST2_DigIn_8(int value);
int prepareWrite_TST2_DigIn_8(int value);
 
#define ID_TST2_DigIn_9 3009
extern int TST2_DigIn_9;
int doWrite_TST2_DigIn_9(int value);
int prepareWrite_TST2_DigIn_9(int value);
 
#define ID_TST2_DigIn_10 3010
extern int TST2_DigIn_10;
int doWrite_TST2_DigIn_10(int value);
int prepareWrite_TST2_DigIn_10(int value);
 
#define ID_TST2_DigIn_11 3011
extern int TST2_DigIn_11;
int doWrite_TST2_DigIn_11(int value);
int prepareWrite_TST2_DigIn_11(int value);
 
#define ID_TST2_DigIn_12 3012
extern int TST2_DigIn_12;
int doWrite_TST2_DigIn_12(int value);
int prepareWrite_TST2_DigIn_12(int value);
 
#define ID_TST2_DigIn_13 3013
extern int TST2_DigIn_13;
int doWrite_TST2_DigIn_13(int value);
int prepareWrite_TST2_DigIn_13(int value);
 
#define ID_TST2_DigIn_14 3014
extern int TST2_DigIn_14;
int doWrite_TST2_DigIn_14(int value);
int prepareWrite_TST2_DigIn_14(int value);
 
#define ID_TST2_DigIn_15 3015
extern int TST2_DigIn_15;
int doWrite_TST2_DigIn_15(int value);
int prepareWrite_TST2_DigIn_15(int value);
 
#define ID_TST2_DigIn_16 3016
extern int TST2_DigIn_16;
int doWrite_TST2_DigIn_16(int value);
int prepareWrite_TST2_DigIn_16(int value);
 
#define ID_VAL2_DigIn_1 3017
extern int VAL2_DigIn_1;
int doWrite_VAL2_DigIn_1(int value);
int prepareWrite_VAL2_DigIn_1(int value);
 
#define ID_VAL2_DigIn_2 3018
extern int VAL2_DigIn_2;
int doWrite_VAL2_DigIn_2(int value);
int prepareWrite_VAL2_DigIn_2(int value);
 
#define ID_VAL2_DigIn_3 3019
extern int VAL2_DigIn_3;
int doWrite_VAL2_DigIn_3(int value);
int prepareWrite_VAL2_DigIn_3(int value);
 
#define ID_VAL2_DigIn_4 3020
extern int VAL2_DigIn_4;
int doWrite_VAL2_DigIn_4(int value);
int prepareWrite_VAL2_DigIn_4(int value);
 
#define ID_VAL2_DigIn_5 3021
extern int VAL2_DigIn_5;
int doWrite_VAL2_DigIn_5(int value);
int prepareWrite_VAL2_DigIn_5(int value);
 
#define ID_VAL2_DigIn_6 3022
extern int VAL2_DigIn_6;
int doWrite_VAL2_DigIn_6(int value);
int prepareWrite_VAL2_DigIn_6(int value);
 
#define ID_VAL2_DigIn_7 3023
extern int VAL2_DigIn_7;
int doWrite_VAL2_DigIn_7(int value);
int prepareWrite_VAL2_DigIn_7(int value);
 
#define ID_VAL2_DigIn_8 3024
extern int VAL2_DigIn_8;
int doWrite_VAL2_DigIn_8(int value);
int prepareWrite_VAL2_DigIn_8(int value);
 
#define ID_VAL2_DigIn_9 3025
extern int VAL2_DigIn_9;
int doWrite_VAL2_DigIn_9(int value);
int prepareWrite_VAL2_DigIn_9(int value);
 
#define ID_VAL2_DigIn_10 3026
extern int VAL2_DigIn_10;
int doWrite_VAL2_DigIn_10(int value);
int prepareWrite_VAL2_DigIn_10(int value);
 
#define ID_VAL2_DigIn_11 3027
extern int VAL2_DigIn_11;
int doWrite_VAL2_DigIn_11(int value);
int prepareWrite_VAL2_DigIn_11(int value);
 
#define ID_VAL2_DigIn_12 3028
extern int VAL2_DigIn_12;
int doWrite_VAL2_DigIn_12(int value);
int prepareWrite_VAL2_DigIn_12(int value);
 
#define ID_VAL2_DigIn_13 3029
extern int VAL2_DigIn_13;
int doWrite_VAL2_DigIn_13(int value);
int prepareWrite_VAL2_DigIn_13(int value);
 
#define ID_VAL2_DigIn_14 3030
extern int VAL2_DigIn_14;
int doWrite_VAL2_DigIn_14(int value);
int prepareWrite_VAL2_DigIn_14(int value);
 
#define ID_VAL2_DigIn_15 3031
extern int VAL2_DigIn_15;
int doWrite_VAL2_DigIn_15(int value);
int prepareWrite_VAL2_DigIn_15(int value);
 
#define ID_VAL2_DigIn_16 3032
extern int VAL2_DigIn_16;
int doWrite_VAL2_DigIn_16(int value);
int prepareWrite_VAL2_DigIn_16(int value);
 
#define ID_RES2_DigIn_1 3033
extern int RES2_DigIn_1;
int doWrite_RES2_DigIn_1(int value);
int prepareWrite_RES2_DigIn_1(int value);
 
#define ID_RES2_DigIn_2 3034
extern int RES2_DigIn_2;
int doWrite_RES2_DigIn_2(int value);
int prepareWrite_RES2_DigIn_2(int value);
 
#define ID_RES2_DigIn_3 3035
extern int RES2_DigIn_3;
int doWrite_RES2_DigIn_3(int value);
int prepareWrite_RES2_DigIn_3(int value);
 
#define ID_RES2_DigIn_4 3036
extern int RES2_DigIn_4;
int doWrite_RES2_DigIn_4(int value);
int prepareWrite_RES2_DigIn_4(int value);
 
#define ID_RES2_DigIn_5 3037
extern int RES2_DigIn_5;
int doWrite_RES2_DigIn_5(int value);
int prepareWrite_RES2_DigIn_5(int value);
 
#define ID_RES2_DigIn_6 3038
extern int RES2_DigIn_6;
int doWrite_RES2_DigIn_6(int value);
int prepareWrite_RES2_DigIn_6(int value);
 
#define ID_RES2_DigIn_7 3039
extern int RES2_DigIn_7;
int doWrite_RES2_DigIn_7(int value);
int prepareWrite_RES2_DigIn_7(int value);
 
#define ID_RES2_DigIn_8 3040
extern int RES2_DigIn_8;
int doWrite_RES2_DigIn_8(int value);
int prepareWrite_RES2_DigIn_8(int value);
 
#define ID_RES2_DigIn_9 3041
extern int RES2_DigIn_9;
int doWrite_RES2_DigIn_9(int value);
int prepareWrite_RES2_DigIn_9(int value);
 
#define ID_RES2_DigIn_10 3042
extern int RES2_DigIn_10;
int doWrite_RES2_DigIn_10(int value);
int prepareWrite_RES2_DigIn_10(int value);
 
#define ID_RES2_DigIn_11 3043
extern int RES2_DigIn_11;
int doWrite_RES2_DigIn_11(int value);
int prepareWrite_RES2_DigIn_11(int value);
 
#define ID_RES2_DigIn_12 3044
extern int RES2_DigIn_12;
int doWrite_RES2_DigIn_12(int value);
int prepareWrite_RES2_DigIn_12(int value);
 
#define ID_RES2_DigIn_13 3045
extern int RES2_DigIn_13;
int doWrite_RES2_DigIn_13(int value);
int prepareWrite_RES2_DigIn_13(int value);
 
#define ID_RES2_DigIn_14 3046
extern int RES2_DigIn_14;
int doWrite_RES2_DigIn_14(int value);
int prepareWrite_RES2_DigIn_14(int value);
 
#define ID_RES2_DigIn_15 3047
extern int RES2_DigIn_15;
int doWrite_RES2_DigIn_15(int value);
int prepareWrite_RES2_DigIn_15(int value);
 
#define ID_RES2_DigIn_16 3048
extern int RES2_DigIn_16;
int doWrite_RES2_DigIn_16(int value);
int prepareWrite_RES2_DigIn_16(int value);
 
#define ID_TST2_DigOut_1 3049
extern int TST2_DigOut_1;
int doWrite_TST2_DigOut_1(int value);
int prepareWrite_TST2_DigOut_1(int value);
 
#define ID_TST2_DigOut_2 3050
extern int TST2_DigOut_2;
int doWrite_TST2_DigOut_2(int value);
int prepareWrite_TST2_DigOut_2(int value);
 
#define ID_TST2_DigOut_3 3051
extern int TST2_DigOut_3;
int doWrite_TST2_DigOut_3(int value);
int prepareWrite_TST2_DigOut_3(int value);
 
#define ID_TST2_DigOut_4 3052
extern int TST2_DigOut_4;
int doWrite_TST2_DigOut_4(int value);
int prepareWrite_TST2_DigOut_4(int value);
 
#define ID_TST2_DigOut_5 3053
extern int TST2_DigOut_5;
int doWrite_TST2_DigOut_5(int value);
int prepareWrite_TST2_DigOut_5(int value);
 
#define ID_TST2_DigOut_6 3054
extern int TST2_DigOut_6;
int doWrite_TST2_DigOut_6(int value);
int prepareWrite_TST2_DigOut_6(int value);
 
#define ID_TST2_DigOut_7 3055
extern int TST2_DigOut_7;
int doWrite_TST2_DigOut_7(int value);
int prepareWrite_TST2_DigOut_7(int value);
 
#define ID_TST2_DigOut_8 3056
extern int TST2_DigOut_8;
int doWrite_TST2_DigOut_8(int value);
int prepareWrite_TST2_DigOut_8(int value);
 
#define ID_TST2_DigOut_9 3057
extern int TST2_DigOut_9;
int doWrite_TST2_DigOut_9(int value);
int prepareWrite_TST2_DigOut_9(int value);
 
#define ID_TST2_DigOut_10 3058
extern int TST2_DigOut_10;
int doWrite_TST2_DigOut_10(int value);
int prepareWrite_TST2_DigOut_10(int value);
 
#define ID_TST2_DigOut_11 3059
extern int TST2_DigOut_11;
int doWrite_TST2_DigOut_11(int value);
int prepareWrite_TST2_DigOut_11(int value);
 
#define ID_TST2_DigOut_12 3060
extern int TST2_DigOut_12;
int doWrite_TST2_DigOut_12(int value);
int prepareWrite_TST2_DigOut_12(int value);
 
#define ID_TST2_DigOut_13 3061
extern int TST2_DigOut_13;
int doWrite_TST2_DigOut_13(int value);
int prepareWrite_TST2_DigOut_13(int value);
 
#define ID_TST2_DigOut_14 3062
extern int TST2_DigOut_14;
int doWrite_TST2_DigOut_14(int value);
int prepareWrite_TST2_DigOut_14(int value);
 
#define ID_TST2_DigOut_15 3063
extern int TST2_DigOut_15;
int doWrite_TST2_DigOut_15(int value);
int prepareWrite_TST2_DigOut_15(int value);
 
#define ID_TST2_DigOut_16 3064
extern int TST2_DigOut_16;
int doWrite_TST2_DigOut_16(int value);
int prepareWrite_TST2_DigOut_16(int value);
 
#define ID_VAL2_DigOut_1 3065
extern int VAL2_DigOut_1;
int doWrite_VAL2_DigOut_1(int value);
int prepareWrite_VAL2_DigOut_1(int value);
 
#define ID_VAL2_DigOut_2 3066
extern int VAL2_DigOut_2;
int doWrite_VAL2_DigOut_2(int value);
int prepareWrite_VAL2_DigOut_2(int value);
 
#define ID_VAL2_DigOut_3 3067
extern int VAL2_DigOut_3;
int doWrite_VAL2_DigOut_3(int value);
int prepareWrite_VAL2_DigOut_3(int value);
 
#define ID_VAL2_DigOut_4 3068
extern int VAL2_DigOut_4;
int doWrite_VAL2_DigOut_4(int value);
int prepareWrite_VAL2_DigOut_4(int value);
 
#define ID_VAL2_DigOut_5 3069
extern int VAL2_DigOut_5;
int doWrite_VAL2_DigOut_5(int value);
int prepareWrite_VAL2_DigOut_5(int value);
 
#define ID_VAL2_DigOut_6 3070
extern int VAL2_DigOut_6;
int doWrite_VAL2_DigOut_6(int value);
int prepareWrite_VAL2_DigOut_6(int value);
 
#define ID_VAL2_DigOut_7 3071
extern int VAL2_DigOut_7;
int doWrite_VAL2_DigOut_7(int value);
int prepareWrite_VAL2_DigOut_7(int value);
 
#define ID_VAL2_DigOut_8 3072
extern int VAL2_DigOut_8;
int doWrite_VAL2_DigOut_8(int value);
int prepareWrite_VAL2_DigOut_8(int value);
 
#define ID_VAL2_DigOut_9 3073
extern int VAL2_DigOut_9;
int doWrite_VAL2_DigOut_9(int value);
int prepareWrite_VAL2_DigOut_9(int value);
 
#define ID_VAL2_DigOut_10 3074
extern int VAL2_DigOut_10;
int doWrite_VAL2_DigOut_10(int value);
int prepareWrite_VAL2_DigOut_10(int value);
 
#define ID_VAL2_DigOut_11 3075
extern int VAL2_DigOut_11;
int doWrite_VAL2_DigOut_11(int value);
int prepareWrite_VAL2_DigOut_11(int value);
 
#define ID_VAL2_DigOut_12 3076
extern int VAL2_DigOut_12;
int doWrite_VAL2_DigOut_12(int value);
int prepareWrite_VAL2_DigOut_12(int value);
 
#define ID_VAL2_DigOut_13 3077
extern int VAL2_DigOut_13;
int doWrite_VAL2_DigOut_13(int value);
int prepareWrite_VAL2_DigOut_13(int value);
 
#define ID_VAL2_DigOut_14 3078
extern int VAL2_DigOut_14;
int doWrite_VAL2_DigOut_14(int value);
int prepareWrite_VAL2_DigOut_14(int value);
 
#define ID_VAL2_DigOut_15 3079
extern int VAL2_DigOut_15;
int doWrite_VAL2_DigOut_15(int value);
int prepareWrite_VAL2_DigOut_15(int value);
 
#define ID_VAL2_DigOut_16 3080
extern int VAL2_DigOut_16;
int doWrite_VAL2_DigOut_16(int value);
int prepareWrite_VAL2_DigOut_16(int value);
 
#define ID_RES2_DigOut_1 3081
extern int RES2_DigOut_1;
int doWrite_RES2_DigOut_1(int value);
int prepareWrite_RES2_DigOut_1(int value);
 
#define ID_RES2_DigOut_2 3082
extern int RES2_DigOut_2;
int doWrite_RES2_DigOut_2(int value);
int prepareWrite_RES2_DigOut_2(int value);
 
#define ID_RES2_DigOut_3 3083
extern int RES2_DigOut_3;
int doWrite_RES2_DigOut_3(int value);
int prepareWrite_RES2_DigOut_3(int value);
 
#define ID_RES2_DigOut_4 3084
extern int RES2_DigOut_4;
int doWrite_RES2_DigOut_4(int value);
int prepareWrite_RES2_DigOut_4(int value);
 
#define ID_RES2_DigOut_5 3085
extern int RES2_DigOut_5;
int doWrite_RES2_DigOut_5(int value);
int prepareWrite_RES2_DigOut_5(int value);
 
#define ID_RES2_DigOut_6 3086
extern int RES2_DigOut_6;
int doWrite_RES2_DigOut_6(int value);
int prepareWrite_RES2_DigOut_6(int value);
 
#define ID_RES2_DigOut_7 3087
extern int RES2_DigOut_7;
int doWrite_RES2_DigOut_7(int value);
int prepareWrite_RES2_DigOut_7(int value);
 
#define ID_RES2_DigOut_8 3088
extern int RES2_DigOut_8;
int doWrite_RES2_DigOut_8(int value);
int prepareWrite_RES2_DigOut_8(int value);
 
#define ID_RES2_DigOut_9 3089
extern int RES2_DigOut_9;
int doWrite_RES2_DigOut_9(int value);
int prepareWrite_RES2_DigOut_9(int value);
 
#define ID_RES2_DigOut_10 3090
extern int RES2_DigOut_10;
int doWrite_RES2_DigOut_10(int value);
int prepareWrite_RES2_DigOut_10(int value);
 
#define ID_RES2_DigOut_11 3091
extern int RES2_DigOut_11;
int doWrite_RES2_DigOut_11(int value);
int prepareWrite_RES2_DigOut_11(int value);
 
#define ID_RES2_DigOut_12 3092
extern int RES2_DigOut_12;
int doWrite_RES2_DigOut_12(int value);
int prepareWrite_RES2_DigOut_12(int value);
 
#define ID_RES2_DigOut_13 3093
extern int RES2_DigOut_13;
int doWrite_RES2_DigOut_13(int value);
int prepareWrite_RES2_DigOut_13(int value);
 
#define ID_RES2_DigOut_14 3094
extern int RES2_DigOut_14;
int doWrite_RES2_DigOut_14(int value);
int prepareWrite_RES2_DigOut_14(int value);
 
#define ID_RES2_DigOut_15 3095
extern int RES2_DigOut_15;
int doWrite_RES2_DigOut_15(int value);
int prepareWrite_RES2_DigOut_15(int value);
 
#define ID_RES2_DigOut_16 3096
extern int RES2_DigOut_16;
int doWrite_RES2_DigOut_16(int value);
int prepareWrite_RES2_DigOut_16(int value);
 
#define ID_TST2_AnIn_1 3097
extern int TST2_AnIn_1;
int doWrite_TST2_AnIn_1(int value);
int prepareWrite_TST2_AnIn_1(int value);
 
#define ID_TST2_AnIn_2 3098
extern int TST2_AnIn_2;
int doWrite_TST2_AnIn_2(int value);
int prepareWrite_TST2_AnIn_2(int value);
 
#define ID_TST2_AnIn_3 3099
extern int TST2_AnIn_3;
int doWrite_TST2_AnIn_3(int value);
int prepareWrite_TST2_AnIn_3(int value);
 
#define ID_TST2_AnIn_4 3100
extern int TST2_AnIn_4;
int doWrite_TST2_AnIn_4(int value);
int prepareWrite_TST2_AnIn_4(int value);
 
#define ID_TST2_AnIn_5 3101
extern int TST2_AnIn_5;
int doWrite_TST2_AnIn_5(int value);
int prepareWrite_TST2_AnIn_5(int value);
 
#define ID_TST2_AnIn_6 3102
extern int TST2_AnIn_6;
int doWrite_TST2_AnIn_6(int value);
int prepareWrite_TST2_AnIn_6(int value);
 
#define ID_TST2_AnIn_7 3103
extern int TST2_AnIn_7;
int doWrite_TST2_AnIn_7(int value);
int prepareWrite_TST2_AnIn_7(int value);
 
#define ID_TST2_AnIn_8 3104
extern int TST2_AnIn_8;
int doWrite_TST2_AnIn_8(int value);
int prepareWrite_TST2_AnIn_8(int value);
 
#define ID_TST2_AnIn_9 3105
extern int TST2_AnIn_9;
int doWrite_TST2_AnIn_9(int value);
int prepareWrite_TST2_AnIn_9(int value);
 
#define ID_TST2_AnIn_10 3106
extern int TST2_AnIn_10;
int doWrite_TST2_AnIn_10(int value);
int prepareWrite_TST2_AnIn_10(int value);
 
#define ID_TST2_AnIn_11 3107
extern int TST2_AnIn_11;
int doWrite_TST2_AnIn_11(int value);
int prepareWrite_TST2_AnIn_11(int value);
 
#define ID_TST2_AnIn_12 3108
extern int TST2_AnIn_12;
int doWrite_TST2_AnIn_12(int value);
int prepareWrite_TST2_AnIn_12(int value);
 
#define ID_VAL2_AnIn_1 3109
extern int16_t VAL2_AnIn_1;
int doWrite_VAL2_AnIn_1(int16_t value);
int prepareWrite_VAL2_AnIn_1(int16_t value);
 
#define ID_VAL2_AnIn_2 3110
extern int16_t VAL2_AnIn_2;
int doWrite_VAL2_AnIn_2(int16_t value);
int prepareWrite_VAL2_AnIn_2(int16_t value);
 
#define ID_VAL2_AnIn_3 3111
extern int16_t VAL2_AnIn_3;
int doWrite_VAL2_AnIn_3(int16_t value);
int prepareWrite_VAL2_AnIn_3(int16_t value);
 
#define ID_VAL2_AnIn_4 3112
extern int16_t VAL2_AnIn_4;
int doWrite_VAL2_AnIn_4(int16_t value);
int prepareWrite_VAL2_AnIn_4(int16_t value);
 
#define ID_VAL2_AnIn_5 3113
extern int16_t VAL2_AnIn_5;
int doWrite_VAL2_AnIn_5(int16_t value);
int prepareWrite_VAL2_AnIn_5(int16_t value);
 
#define ID_VAL2_AnIn_6 3114
extern int16_t VAL2_AnIn_6;
int doWrite_VAL2_AnIn_6(int16_t value);
int prepareWrite_VAL2_AnIn_6(int16_t value);
 
#define ID_VAL2_AnIn_7 3115
extern int16_t VAL2_AnIn_7;
int doWrite_VAL2_AnIn_7(int16_t value);
int prepareWrite_VAL2_AnIn_7(int16_t value);
 
#define ID_VAL2_AnIn_8 3116
extern int16_t VAL2_AnIn_8;
int doWrite_VAL2_AnIn_8(int16_t value);
int prepareWrite_VAL2_AnIn_8(int16_t value);
 
#define ID_VAL2_AnIn_9 3117
extern int16_t VAL2_AnIn_9;
int doWrite_VAL2_AnIn_9(int16_t value);
int prepareWrite_VAL2_AnIn_9(int16_t value);
 
#define ID_VAL2_AnIn_10 3118
extern int16_t VAL2_AnIn_10;
int doWrite_VAL2_AnIn_10(int16_t value);
int prepareWrite_VAL2_AnIn_10(int16_t value);
 
#define ID_VAL2_AnIn_11 3119
extern int16_t VAL2_AnIn_11;
int doWrite_VAL2_AnIn_11(int16_t value);
int prepareWrite_VAL2_AnIn_11(int16_t value);
 
#define ID_VAL2_AnIn_12 3120
extern int16_t VAL2_AnIn_12;
int doWrite_VAL2_AnIn_12(int16_t value);
int prepareWrite_VAL2_AnIn_12(int16_t value);
 
#define ID_VAL2_AnInConf_1 3121
extern u_int16_t VAL2_AnInConf_1;
int doWrite_VAL2_AnInConf_1(u_int16_t value);
int prepareWrite_VAL2_AnInConf_1(u_int16_t value);
 
#define ID_VAL2_AnInConf_2 3122
extern u_int16_t VAL2_AnInConf_2;
int doWrite_VAL2_AnInConf_2(u_int16_t value);
int prepareWrite_VAL2_AnInConf_2(u_int16_t value);
 
#define ID_VAL2_AnInConf_3 3123
extern u_int16_t VAL2_AnInConf_3;
int doWrite_VAL2_AnInConf_3(u_int16_t value);
int prepareWrite_VAL2_AnInConf_3(u_int16_t value);
 
#define ID_VAL2_AnInConf_4 3124
extern u_int16_t VAL2_AnInConf_4;
int doWrite_VAL2_AnInConf_4(u_int16_t value);
int prepareWrite_VAL2_AnInConf_4(u_int16_t value);
 
#define ID_VAL2_AnInConf_5 3125
extern u_int16_t VAL2_AnInConf_5;
int doWrite_VAL2_AnInConf_5(u_int16_t value);
int prepareWrite_VAL2_AnInConf_5(u_int16_t value);
 
#define ID_VAL2_AnInConf_6 3126
extern u_int16_t VAL2_AnInConf_6;
int doWrite_VAL2_AnInConf_6(u_int16_t value);
int prepareWrite_VAL2_AnInConf_6(u_int16_t value);
 
#define ID_VAL2_AnInConf_7 3127
extern u_int16_t VAL2_AnInConf_7;
int doWrite_VAL2_AnInConf_7(u_int16_t value);
int prepareWrite_VAL2_AnInConf_7(u_int16_t value);
 
#define ID_VAL2_AnInConf_8 3128
extern u_int16_t VAL2_AnInConf_8;
int doWrite_VAL2_AnInConf_8(u_int16_t value);
int prepareWrite_VAL2_AnInConf_8(u_int16_t value);
 
#define ID_VAL2_AnInConf_9 3129
extern u_int16_t VAL2_AnInConf_9;
int doWrite_VAL2_AnInConf_9(u_int16_t value);
int prepareWrite_VAL2_AnInConf_9(u_int16_t value);
 
#define ID_VAL2_AnInConf_10 3130
extern u_int16_t VAL2_AnInConf_10;
int doWrite_VAL2_AnInConf_10(u_int16_t value);
int prepareWrite_VAL2_AnInConf_10(u_int16_t value);
 
#define ID_VAL2_AnInConf_11 3131
extern u_int16_t VAL2_AnInConf_11;
int doWrite_VAL2_AnInConf_11(u_int16_t value);
int prepareWrite_VAL2_AnInConf_11(u_int16_t value);
 
#define ID_VAL2_AnInConf_12 3132
extern u_int16_t VAL2_AnInConf_12;
int doWrite_VAL2_AnInConf_12(u_int16_t value);
int prepareWrite_VAL2_AnInConf_12(u_int16_t value);
 
#define ID_VAL2_AnInFltr_1 3133
extern u_int16_t VAL2_AnInFltr_1;
int doWrite_VAL2_AnInFltr_1(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_1(u_int16_t value);
 
#define ID_VAL2_AnInFltr_2 3134
extern u_int16_t VAL2_AnInFltr_2;
int doWrite_VAL2_AnInFltr_2(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_2(u_int16_t value);
 
#define ID_VAL2_AnInFltr_3 3135
extern u_int16_t VAL2_AnInFltr_3;
int doWrite_VAL2_AnInFltr_3(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_3(u_int16_t value);
 
#define ID_VAL2_AnInFltr_4 3136
extern u_int16_t VAL2_AnInFltr_4;
int doWrite_VAL2_AnInFltr_4(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_4(u_int16_t value);
 
#define ID_VAL2_AnInFltr_5 3137
extern u_int16_t VAL2_AnInFltr_5;
int doWrite_VAL2_AnInFltr_5(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_5(u_int16_t value);
 
#define ID_VAL2_AnInFltr_6 3138
extern u_int16_t VAL2_AnInFltr_6;
int doWrite_VAL2_AnInFltr_6(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_6(u_int16_t value);
 
#define ID_VAL2_AnInFltr_7 3139
extern u_int16_t VAL2_AnInFltr_7;
int doWrite_VAL2_AnInFltr_7(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_7(u_int16_t value);
 
#define ID_VAL2_AnInFltr_8 3140
extern u_int16_t VAL2_AnInFltr_8;
int doWrite_VAL2_AnInFltr_8(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_8(u_int16_t value);
 
#define ID_VAL2_AnInFltr_9 3141
extern u_int16_t VAL2_AnInFltr_9;
int doWrite_VAL2_AnInFltr_9(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_9(u_int16_t value);
 
#define ID_VAL2_AnInFltr_10 3142
extern u_int16_t VAL2_AnInFltr_10;
int doWrite_VAL2_AnInFltr_10(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_10(u_int16_t value);
 
#define ID_VAL2_AnInFltr_11 3143
extern u_int16_t VAL2_AnInFltr_11;
int doWrite_VAL2_AnInFltr_11(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_11(u_int16_t value);
 
#define ID_VAL2_AnInFltr_12 3144
extern u_int16_t VAL2_AnInFltr_12;
int doWrite_VAL2_AnInFltr_12(u_int16_t value);
int prepareWrite_VAL2_AnInFltr_12(u_int16_t value);
 
#define ID_RES2_AnIn_1 3145
extern int16_t RES2_AnIn_1;
int doWrite_RES2_AnIn_1(int16_t value);
int prepareWrite_RES2_AnIn_1(int16_t value);
 
#define ID_RES2_AnIn_2 3146
extern int16_t RES2_AnIn_2;
int doWrite_RES2_AnIn_2(int16_t value);
int prepareWrite_RES2_AnIn_2(int16_t value);
 
#define ID_RES2_AnIn_3 3147
extern int16_t RES2_AnIn_3;
int doWrite_RES2_AnIn_3(int16_t value);
int prepareWrite_RES2_AnIn_3(int16_t value);
 
#define ID_RES2_AnIn_4 3148
extern int16_t RES2_AnIn_4;
int doWrite_RES2_AnIn_4(int16_t value);
int prepareWrite_RES2_AnIn_4(int16_t value);
 
#define ID_RES2_AnIn_5 3149
extern int16_t RES2_AnIn_5;
int doWrite_RES2_AnIn_5(int16_t value);
int prepareWrite_RES2_AnIn_5(int16_t value);
 
#define ID_RES2_AnIn_6 3150
extern int16_t RES2_AnIn_6;
int doWrite_RES2_AnIn_6(int16_t value);
int prepareWrite_RES2_AnIn_6(int16_t value);
 
#define ID_RES2_AnIn_7 3151
extern int16_t RES2_AnIn_7;
int doWrite_RES2_AnIn_7(int16_t value);
int prepareWrite_RES2_AnIn_7(int16_t value);
 
#define ID_RES2_AnIn_8 3152
extern int16_t RES2_AnIn_8;
int doWrite_RES2_AnIn_8(int16_t value);
int prepareWrite_RES2_AnIn_8(int16_t value);
 
#define ID_RES2_AnIn_9 3153
extern int16_t RES2_AnIn_9;
int doWrite_RES2_AnIn_9(int16_t value);
int prepareWrite_RES2_AnIn_9(int16_t value);
 
#define ID_RES2_AnIn_10 3154
extern int16_t RES2_AnIn_10;
int doWrite_RES2_AnIn_10(int16_t value);
int prepareWrite_RES2_AnIn_10(int16_t value);
 
#define ID_RES2_AnIn_11 3155
extern int16_t RES2_AnIn_11;
int doWrite_RES2_AnIn_11(int16_t value);
int prepareWrite_RES2_AnIn_11(int16_t value);
 
#define ID_RES2_AnIn_12 3156
extern int16_t RES2_AnIn_12;
int doWrite_RES2_AnIn_12(int16_t value);
int prepareWrite_RES2_AnIn_12(int16_t value);
 
#define ID_RES2_AnInStts_1 3157
extern int16_t RES2_AnInStts_1;
int doWrite_RES2_AnInStts_1(int16_t value);
int prepareWrite_RES2_AnInStts_1(int16_t value);
 
#define ID_RES2_AnInStts_2 3158
extern int16_t RES2_AnInStts_2;
int doWrite_RES2_AnInStts_2(int16_t value);
int prepareWrite_RES2_AnInStts_2(int16_t value);
 
#define ID_RES2_AnInStts_3 3159
extern int16_t RES2_AnInStts_3;
int doWrite_RES2_AnInStts_3(int16_t value);
int prepareWrite_RES2_AnInStts_3(int16_t value);
 
#define ID_RES2_AnInStts_4 3160
extern int16_t RES2_AnInStts_4;
int doWrite_RES2_AnInStts_4(int16_t value);
int prepareWrite_RES2_AnInStts_4(int16_t value);
 
#define ID_RES2_AnInStts_5 3161
extern int16_t RES2_AnInStts_5;
int doWrite_RES2_AnInStts_5(int16_t value);
int prepareWrite_RES2_AnInStts_5(int16_t value);
 
#define ID_RES2_AnInStts_6 3162
extern int16_t RES2_AnInStts_6;
int doWrite_RES2_AnInStts_6(int16_t value);
int prepareWrite_RES2_AnInStts_6(int16_t value);
 
#define ID_RES2_AnInStts_7 3163
extern int16_t RES2_AnInStts_7;
int doWrite_RES2_AnInStts_7(int16_t value);
int prepareWrite_RES2_AnInStts_7(int16_t value);
 
#define ID_RES2_AnInStts_8 3164
extern int16_t RES2_AnInStts_8;
int doWrite_RES2_AnInStts_8(int16_t value);
int prepareWrite_RES2_AnInStts_8(int16_t value);
 
#define ID_RES2_AnInStts_9 3165
extern int16_t RES2_AnInStts_9;
int doWrite_RES2_AnInStts_9(int16_t value);
int prepareWrite_RES2_AnInStts_9(int16_t value);
 
#define ID_RES2_AnInStts_10 3166
extern int16_t RES2_AnInStts_10;
int doWrite_RES2_AnInStts_10(int16_t value);
int prepareWrite_RES2_AnInStts_10(int16_t value);
 
#define ID_RES2_AnInStts_11 3167
extern int16_t RES2_AnInStts_11;
int doWrite_RES2_AnInStts_11(int16_t value);
int prepareWrite_RES2_AnInStts_11(int16_t value);
 
#define ID_RES2_AnInStts_12 3168
extern int16_t RES2_AnInStts_12;
int doWrite_RES2_AnInStts_12(int16_t value);
int prepareWrite_RES2_AnInStts_12(int16_t value);
 
#define ID_TST2_AnOut_1 3169
extern int TST2_AnOut_1;
int doWrite_TST2_AnOut_1(int value);
int prepareWrite_TST2_AnOut_1(int value);
 
#define ID_TST2_AnOut_2 3170
extern int TST2_AnOut_2;
int doWrite_TST2_AnOut_2(int value);
int prepareWrite_TST2_AnOut_2(int value);
 
#define ID_TST2_AnOut_3 3171
extern int TST2_AnOut_3;
int doWrite_TST2_AnOut_3(int value);
int prepareWrite_TST2_AnOut_3(int value);
 
#define ID_TST2_AnOut_4 3172
extern int TST2_AnOut_4;
int doWrite_TST2_AnOut_4(int value);
int prepareWrite_TST2_AnOut_4(int value);
 
#define ID_VAL2_AnOut_1 3173
extern int16_t VAL2_AnOut_1;
int doWrite_VAL2_AnOut_1(int16_t value);
int prepareWrite_VAL2_AnOut_1(int16_t value);
 
#define ID_VAL2_AnOut_2 3174
extern int16_t VAL2_AnOut_2;
int doWrite_VAL2_AnOut_2(int16_t value);
int prepareWrite_VAL2_AnOut_2(int16_t value);
 
#define ID_VAL2_AnOut_3 3175
extern int16_t VAL2_AnOut_3;
int doWrite_VAL2_AnOut_3(int16_t value);
int prepareWrite_VAL2_AnOut_3(int16_t value);
 
#define ID_VAL2_AnOut_4 3176
extern int16_t VAL2_AnOut_4;
int doWrite_VAL2_AnOut_4(int16_t value);
int prepareWrite_VAL2_AnOut_4(int16_t value);
 
#define ID_VAL2_AnOutConf_1 3177
extern u_int16_t VAL2_AnOutConf_1;
int doWrite_VAL2_AnOutConf_1(u_int16_t value);
int prepareWrite_VAL2_AnOutConf_1(u_int16_t value);
 
#define ID_VAL2_AnOutConf_2 3178
extern u_int16_t VAL2_AnOutConf_2;
int doWrite_VAL2_AnOutConf_2(u_int16_t value);
int prepareWrite_VAL2_AnOutConf_2(u_int16_t value);
 
#define ID_VAL2_AnOutConf_3 3179
extern u_int16_t VAL2_AnOutConf_3;
int doWrite_VAL2_AnOutConf_3(u_int16_t value);
int prepareWrite_VAL2_AnOutConf_3(u_int16_t value);
 
#define ID_VAL2_AnOutConf_4 3180
extern u_int16_t VAL2_AnOutConf_4;
int doWrite_VAL2_AnOutConf_4(u_int16_t value);
int prepareWrite_VAL2_AnOutConf_4(u_int16_t value);
 
#define ID_RES2_AnOutStts_1 3181
extern int16_t RES2_AnOutStts_1;
int doWrite_RES2_AnOutStts_1(int16_t value);
int prepareWrite_RES2_AnOutStts_1(int16_t value);
 
#define ID_RES2_AnOutStts_2 3182
extern int16_t RES2_AnOutStts_2;
int doWrite_RES2_AnOutStts_2(int16_t value);
int prepareWrite_RES2_AnOutStts_2(int16_t value);
 
#define ID_RES2_AnOutStts_3 3183
extern int16_t RES2_AnOutStts_3;
int doWrite_RES2_AnOutStts_3(int16_t value);
int prepareWrite_RES2_AnOutStts_3(int16_t value);
 
#define ID_RES2_AnOutStts_4 3184
extern int16_t RES2_AnOutStts_4;
int doWrite_RES2_AnOutStts_4(int16_t value);
int prepareWrite_RES2_AnOutStts_4(int16_t value);
 
#define ID_TST2_Tamb 3185
extern int TST2_Tamb;
int doWrite_TST2_Tamb(int value);
int prepareWrite_TST2_Tamb(int value);
 
#define ID_TST2_RPM 3186
extern int TST2_RPM;
int doWrite_TST2_RPM(int value);
int prepareWrite_TST2_RPM(int value);
 
#define ID_TST2_FWrevision 3187
extern int TST2_FWrevision;
int doWrite_TST2_FWrevision(int value);
int prepareWrite_TST2_FWrevision(int value);
 
#define ID_TST2_HWconfig 3188
extern int TST2_HWconfig;
int doWrite_TST2_HWconfig(int value);
int prepareWrite_TST2_HWconfig(int value);
 
#define ID_VAL2_Tamb 3189
extern int16_t VAL2_Tamb;
int doWrite_VAL2_Tamb(int16_t value);
int prepareWrite_VAL2_Tamb(int16_t value);
 
#define ID_VAL2_RPM 3190
extern u_int16_t VAL2_RPM;
int doWrite_VAL2_RPM(u_int16_t value);
int prepareWrite_VAL2_RPM(u_int16_t value);
 
#define ID_VAL2_FWrevision 3191
extern u_int16_t VAL2_FWrevision;
int doWrite_VAL2_FWrevision(u_int16_t value);
int prepareWrite_VAL2_FWrevision(u_int16_t value);
 
#define ID_VAL2_HWconfig 3192
extern u_int16_t VAL2_HWconfig;
int doWrite_VAL2_HWconfig(u_int16_t value);
int prepareWrite_VAL2_HWconfig(u_int16_t value);
 
#define ID_RES2_Tamb 3193
extern int16_t RES2_Tamb;
int doWrite_RES2_Tamb(int16_t value);
int prepareWrite_RES2_Tamb(int16_t value);
 
#define ID_RES2_RPM 3194
extern u_int16_t RES2_RPM;
int doWrite_RES2_RPM(u_int16_t value);
int prepareWrite_RES2_RPM(u_int16_t value);
 
#define ID_RES2_FWrevision 3195
extern u_int16_t RES2_FWrevision;
int doWrite_RES2_FWrevision(u_int16_t value);
int prepareWrite_RES2_FWrevision(u_int16_t value);
 
#define ID_RES2_HWconfig 3196
extern u_int16_t RES2_HWconfig;
int doWrite_RES2_HWconfig(u_int16_t value);
int prepareWrite_RES2_HWconfig(u_int16_t value);
 
#define ID_TST2_RTUS_WR 3197
extern int TST2_RTUS_WR;
int doWrite_TST2_RTUS_WR(int value);
int prepareWrite_TST2_RTUS_WR(int value);
 
#define ID_TST2_RTUS_RD 3198
extern int TST2_RTUS_RD;
int doWrite_TST2_RTUS_RD(int value);
int prepareWrite_TST2_RTUS_RD(int value);
 
#define ID_TST2_RTU1_WR 3199
extern int TST2_RTU1_WR;
int doWrite_TST2_RTU1_WR(int value);
int prepareWrite_TST2_RTU1_WR(int value);
 
#define ID_TST2_RTU1_RD 3200
extern int TST2_RTU1_RD;
int doWrite_TST2_RTU1_RD(int value);
int prepareWrite_TST2_RTU1_RD(int value);
 
#define ID_TST2_RTU3_WR 3201
extern int TST2_RTU3_WR;
int doWrite_TST2_RTU3_WR(int value);
int prepareWrite_TST2_RTU3_WR(int value);
 
#define ID_TST2_RTU3_RD 3202
extern int TST2_RTU3_RD;
int doWrite_TST2_RTU3_RD(int value);
int prepareWrite_TST2_RTU3_RD(int value);
 
#define ID_TST2_CAN1_WR 3203
extern int TST2_CAN1_WR;
int doWrite_TST2_CAN1_WR(int value);
int prepareWrite_TST2_CAN1_WR(int value);
 
#define ID_TST2_CAN1_RD 3204
extern int TST2_CAN1_RD;
int doWrite_TST2_CAN1_RD(int value);
int prepareWrite_TST2_CAN1_RD(int value);
 
#define ID_VAL2_RTUS_WR 3205
extern int VAL2_RTUS_WR;
int doWrite_VAL2_RTUS_WR(int value);
int prepareWrite_VAL2_RTUS_WR(int value);
 
#define ID_VAL2_RTUS_RD 3206
extern int VAL2_RTUS_RD;
int doWrite_VAL2_RTUS_RD(int value);
int prepareWrite_VAL2_RTUS_RD(int value);
 
#define ID_VAL2_RTU1_WR 3207
extern int VAL2_RTU1_WR;
int doWrite_VAL2_RTU1_WR(int value);
int prepareWrite_VAL2_RTU1_WR(int value);
 
#define ID_VAL2_RTU1_RD 3208
extern int VAL2_RTU1_RD;
int doWrite_VAL2_RTU1_RD(int value);
int prepareWrite_VAL2_RTU1_RD(int value);
 
#define ID_VAL2_RTU3_WR 3209
extern int VAL2_RTU3_WR;
int doWrite_VAL2_RTU3_WR(int value);
int prepareWrite_VAL2_RTU3_WR(int value);
 
#define ID_VAL2_RTU3_RD 3210
extern int VAL2_RTU3_RD;
int doWrite_VAL2_RTU3_RD(int value);
int prepareWrite_VAL2_RTU3_RD(int value);
 
#define ID_VAL2_CAN1_WR 3211
extern int VAL2_CAN1_WR;
int doWrite_VAL2_CAN1_WR(int value);
int prepareWrite_VAL2_CAN1_WR(int value);
 
#define ID_VAL2_CAN1_RD 3212
extern int VAL2_CAN1_RD;
int doWrite_VAL2_CAN1_RD(int value);
int prepareWrite_VAL2_CAN1_RD(int value);
 
#define ID_RES2_RTUS_WR 3213
extern int RES2_RTUS_WR;
int doWrite_RES2_RTUS_WR(int value);
int prepareWrite_RES2_RTUS_WR(int value);
 
#define ID_RES2_RTUS_RD 3214
extern int RES2_RTUS_RD;
int doWrite_RES2_RTUS_RD(int value);
int prepareWrite_RES2_RTUS_RD(int value);
 
#define ID_RES2_RTU1_WR 3215
extern int RES2_RTU1_WR;
int doWrite_RES2_RTU1_WR(int value);
int prepareWrite_RES2_RTU1_WR(int value);
 
#define ID_RES2_RTU1_RD 3216
extern int RES2_RTU1_RD;
int doWrite_RES2_RTU1_RD(int value);
int prepareWrite_RES2_RTU1_RD(int value);
 
#define ID_RES2_RTU3_WR 3217
extern int RES2_RTU3_WR;
int doWrite_RES2_RTU3_WR(int value);
int prepareWrite_RES2_RTU3_WR(int value);
 
#define ID_RES2_RTU3_RD 3218
extern int RES2_RTU3_RD;
int doWrite_RES2_RTU3_RD(int value);
int prepareWrite_RES2_RTU3_RD(int value);
 
#define ID_RES2_CAN1_WR 3219
extern int RES2_CAN1_WR;
int doWrite_RES2_CAN1_WR(int value);
int prepareWrite_RES2_CAN1_WR(int value);
 
#define ID_RES2_CAN1_RD 3220
extern int RES2_CAN1_RD;
int doWrite_RES2_CAN1_RD(int value);
int prepareWrite_RES2_CAN1_RD(int value);
 
#define ID_STATUS2_LOCAL 3221
extern int STATUS2_LOCAL;
int doWrite_STATUS2_LOCAL(int value);
int prepareWrite_STATUS2_LOCAL(int value);
 
#define ID_STATUS2_REMOTE 3222
extern int STATUS2_REMOTE;
int doWrite_STATUS2_REMOTE(int value);
int prepareWrite_STATUS2_REMOTE(int value);
 
#define ID_STATUS2_DONE 3223
extern int STATUS2_DONE;
int doWrite_STATUS2_DONE(int value);
int prepareWrite_STATUS2_DONE(int value);
 
#define ID_STARTx_REMOTE 3999
extern int STARTx_REMOTE;
int doWrite_STARTx_REMOTE(int value);
int prepareWrite_STARTx_REMOTE(int value);
 
#define ID_STARTx_TEST 4000
extern int STARTx_TEST;
int doWrite_STARTx_TEST(int value);
int prepareWrite_STARTx_TEST(int value);
 
#define ID_TSTx_DigIn_1 4001
extern int TSTx_DigIn_1;
int doWrite_TSTx_DigIn_1(int value);
int prepareWrite_TSTx_DigIn_1(int value);
 
#define ID_TSTx_DigIn_2 4002
extern int TSTx_DigIn_2;
int doWrite_TSTx_DigIn_2(int value);
int prepareWrite_TSTx_DigIn_2(int value);
 
#define ID_TSTx_DigIn_3 4003
extern int TSTx_DigIn_3;
int doWrite_TSTx_DigIn_3(int value);
int prepareWrite_TSTx_DigIn_3(int value);
 
#define ID_TSTx_DigIn_4 4004
extern int TSTx_DigIn_4;
int doWrite_TSTx_DigIn_4(int value);
int prepareWrite_TSTx_DigIn_4(int value);
 
#define ID_TSTx_DigIn_5 4005
extern int TSTx_DigIn_5;
int doWrite_TSTx_DigIn_5(int value);
int prepareWrite_TSTx_DigIn_5(int value);
 
#define ID_TSTx_DigIn_6 4006
extern int TSTx_DigIn_6;
int doWrite_TSTx_DigIn_6(int value);
int prepareWrite_TSTx_DigIn_6(int value);
 
#define ID_TSTx_DigIn_7 4007
extern int TSTx_DigIn_7;
int doWrite_TSTx_DigIn_7(int value);
int prepareWrite_TSTx_DigIn_7(int value);
 
#define ID_TSTx_DigIn_8 4008
extern int TSTx_DigIn_8;
int doWrite_TSTx_DigIn_8(int value);
int prepareWrite_TSTx_DigIn_8(int value);
 
#define ID_TSTx_DigIn_9 4009
extern int TSTx_DigIn_9;
int doWrite_TSTx_DigIn_9(int value);
int prepareWrite_TSTx_DigIn_9(int value);
 
#define ID_TSTx_DigIn_10 4010
extern int TSTx_DigIn_10;
int doWrite_TSTx_DigIn_10(int value);
int prepareWrite_TSTx_DigIn_10(int value);
 
#define ID_TSTx_DigIn_11 4011
extern int TSTx_DigIn_11;
int doWrite_TSTx_DigIn_11(int value);
int prepareWrite_TSTx_DigIn_11(int value);
 
#define ID_TSTx_DigIn_12 4012
extern int TSTx_DigIn_12;
int doWrite_TSTx_DigIn_12(int value);
int prepareWrite_TSTx_DigIn_12(int value);
 
#define ID_TSTx_DigIn_13 4013
extern int TSTx_DigIn_13;
int doWrite_TSTx_DigIn_13(int value);
int prepareWrite_TSTx_DigIn_13(int value);
 
#define ID_TSTx_DigIn_14 4014
extern int TSTx_DigIn_14;
int doWrite_TSTx_DigIn_14(int value);
int prepareWrite_TSTx_DigIn_14(int value);
 
#define ID_TSTx_DigIn_15 4015
extern int TSTx_DigIn_15;
int doWrite_TSTx_DigIn_15(int value);
int prepareWrite_TSTx_DigIn_15(int value);
 
#define ID_TSTx_DigIn_16 4016
extern int TSTx_DigIn_16;
int doWrite_TSTx_DigIn_16(int value);
int prepareWrite_TSTx_DigIn_16(int value);
 
#define ID_VALx_DigIn_1 4017
extern int VALx_DigIn_1;
int doWrite_VALx_DigIn_1(int value);
int prepareWrite_VALx_DigIn_1(int value);
 
#define ID_VALx_DigIn_2 4018
extern int VALx_DigIn_2;
int doWrite_VALx_DigIn_2(int value);
int prepareWrite_VALx_DigIn_2(int value);
 
#define ID_VALx_DigIn_3 4019
extern int VALx_DigIn_3;
int doWrite_VALx_DigIn_3(int value);
int prepareWrite_VALx_DigIn_3(int value);
 
#define ID_VALx_DigIn_4 4020
extern int VALx_DigIn_4;
int doWrite_VALx_DigIn_4(int value);
int prepareWrite_VALx_DigIn_4(int value);
 
#define ID_VALx_DigIn_5 4021
extern int VALx_DigIn_5;
int doWrite_VALx_DigIn_5(int value);
int prepareWrite_VALx_DigIn_5(int value);
 
#define ID_VALx_DigIn_6 4022
extern int VALx_DigIn_6;
int doWrite_VALx_DigIn_6(int value);
int prepareWrite_VALx_DigIn_6(int value);
 
#define ID_VALx_DigIn_7 4023
extern int VALx_DigIn_7;
int doWrite_VALx_DigIn_7(int value);
int prepareWrite_VALx_DigIn_7(int value);
 
#define ID_VALx_DigIn_8 4024
extern int VALx_DigIn_8;
int doWrite_VALx_DigIn_8(int value);
int prepareWrite_VALx_DigIn_8(int value);
 
#define ID_VALx_DigIn_9 4025
extern int VALx_DigIn_9;
int doWrite_VALx_DigIn_9(int value);
int prepareWrite_VALx_DigIn_9(int value);
 
#define ID_VALx_DigIn_10 4026
extern int VALx_DigIn_10;
int doWrite_VALx_DigIn_10(int value);
int prepareWrite_VALx_DigIn_10(int value);
 
#define ID_VALx_DigIn_11 4027
extern int VALx_DigIn_11;
int doWrite_VALx_DigIn_11(int value);
int prepareWrite_VALx_DigIn_11(int value);
 
#define ID_VALx_DigIn_12 4028
extern int VALx_DigIn_12;
int doWrite_VALx_DigIn_12(int value);
int prepareWrite_VALx_DigIn_12(int value);
 
#define ID_VALx_DigIn_13 4029
extern int VALx_DigIn_13;
int doWrite_VALx_DigIn_13(int value);
int prepareWrite_VALx_DigIn_13(int value);
 
#define ID_VALx_DigIn_14 4030
extern int VALx_DigIn_14;
int doWrite_VALx_DigIn_14(int value);
int prepareWrite_VALx_DigIn_14(int value);
 
#define ID_VALx_DigIn_15 4031
extern int VALx_DigIn_15;
int doWrite_VALx_DigIn_15(int value);
int prepareWrite_VALx_DigIn_15(int value);
 
#define ID_VALx_DigIn_16 4032
extern int VALx_DigIn_16;
int doWrite_VALx_DigIn_16(int value);
int prepareWrite_VALx_DigIn_16(int value);
 
#define ID_RESx_DigIn_1 4033
extern int RESx_DigIn_1;
int doWrite_RESx_DigIn_1(int value);
int prepareWrite_RESx_DigIn_1(int value);
 
#define ID_RESx_DigIn_2 4034
extern int RESx_DigIn_2;
int doWrite_RESx_DigIn_2(int value);
int prepareWrite_RESx_DigIn_2(int value);
 
#define ID_RESx_DigIn_3 4035
extern int RESx_DigIn_3;
int doWrite_RESx_DigIn_3(int value);
int prepareWrite_RESx_DigIn_3(int value);
 
#define ID_RESx_DigIn_4 4036
extern int RESx_DigIn_4;
int doWrite_RESx_DigIn_4(int value);
int prepareWrite_RESx_DigIn_4(int value);
 
#define ID_RESx_DigIn_5 4037
extern int RESx_DigIn_5;
int doWrite_RESx_DigIn_5(int value);
int prepareWrite_RESx_DigIn_5(int value);
 
#define ID_RESx_DigIn_6 4038
extern int RESx_DigIn_6;
int doWrite_RESx_DigIn_6(int value);
int prepareWrite_RESx_DigIn_6(int value);
 
#define ID_RESx_DigIn_7 4039
extern int RESx_DigIn_7;
int doWrite_RESx_DigIn_7(int value);
int prepareWrite_RESx_DigIn_7(int value);
 
#define ID_RESx_DigIn_8 4040
extern int RESx_DigIn_8;
int doWrite_RESx_DigIn_8(int value);
int prepareWrite_RESx_DigIn_8(int value);
 
#define ID_RESx_DigIn_9 4041
extern int RESx_DigIn_9;
int doWrite_RESx_DigIn_9(int value);
int prepareWrite_RESx_DigIn_9(int value);
 
#define ID_RESx_DigIn_10 4042
extern int RESx_DigIn_10;
int doWrite_RESx_DigIn_10(int value);
int prepareWrite_RESx_DigIn_10(int value);
 
#define ID_RESx_DigIn_11 4043
extern int RESx_DigIn_11;
int doWrite_RESx_DigIn_11(int value);
int prepareWrite_RESx_DigIn_11(int value);
 
#define ID_RESx_DigIn_12 4044
extern int RESx_DigIn_12;
int doWrite_RESx_DigIn_12(int value);
int prepareWrite_RESx_DigIn_12(int value);
 
#define ID_RESx_DigIn_13 4045
extern int RESx_DigIn_13;
int doWrite_RESx_DigIn_13(int value);
int prepareWrite_RESx_DigIn_13(int value);
 
#define ID_RESx_DigIn_14 4046
extern int RESx_DigIn_14;
int doWrite_RESx_DigIn_14(int value);
int prepareWrite_RESx_DigIn_14(int value);
 
#define ID_RESx_DigIn_15 4047
extern int RESx_DigIn_15;
int doWrite_RESx_DigIn_15(int value);
int prepareWrite_RESx_DigIn_15(int value);
 
#define ID_RESx_DigIn_16 4048
extern int RESx_DigIn_16;
int doWrite_RESx_DigIn_16(int value);
int prepareWrite_RESx_DigIn_16(int value);
 
#define ID_TSTx_DigOut_1 4049
extern int TSTx_DigOut_1;
int doWrite_TSTx_DigOut_1(int value);
int prepareWrite_TSTx_DigOut_1(int value);
 
#define ID_TSTx_DigOut_2 4050
extern int TSTx_DigOut_2;
int doWrite_TSTx_DigOut_2(int value);
int prepareWrite_TSTx_DigOut_2(int value);
 
#define ID_TSTx_DigOut_3 4051
extern int TSTx_DigOut_3;
int doWrite_TSTx_DigOut_3(int value);
int prepareWrite_TSTx_DigOut_3(int value);
 
#define ID_TSTx_DigOut_4 4052
extern int TSTx_DigOut_4;
int doWrite_TSTx_DigOut_4(int value);
int prepareWrite_TSTx_DigOut_4(int value);
 
#define ID_TSTx_DigOut_5 4053
extern int TSTx_DigOut_5;
int doWrite_TSTx_DigOut_5(int value);
int prepareWrite_TSTx_DigOut_5(int value);
 
#define ID_TSTx_DigOut_6 4054
extern int TSTx_DigOut_6;
int doWrite_TSTx_DigOut_6(int value);
int prepareWrite_TSTx_DigOut_6(int value);
 
#define ID_TSTx_DigOut_7 4055
extern int TSTx_DigOut_7;
int doWrite_TSTx_DigOut_7(int value);
int prepareWrite_TSTx_DigOut_7(int value);
 
#define ID_TSTx_DigOut_8 4056
extern int TSTx_DigOut_8;
int doWrite_TSTx_DigOut_8(int value);
int prepareWrite_TSTx_DigOut_8(int value);
 
#define ID_TSTx_DigOut_9 4057
extern int TSTx_DigOut_9;
int doWrite_TSTx_DigOut_9(int value);
int prepareWrite_TSTx_DigOut_9(int value);
 
#define ID_TSTx_DigOut_10 4058
extern int TSTx_DigOut_10;
int doWrite_TSTx_DigOut_10(int value);
int prepareWrite_TSTx_DigOut_10(int value);
 
#define ID_TSTx_DigOut_11 4059
extern int TSTx_DigOut_11;
int doWrite_TSTx_DigOut_11(int value);
int prepareWrite_TSTx_DigOut_11(int value);
 
#define ID_TSTx_DigOut_12 4060
extern int TSTx_DigOut_12;
int doWrite_TSTx_DigOut_12(int value);
int prepareWrite_TSTx_DigOut_12(int value);
 
#define ID_TSTx_DigOut_13 4061
extern int TSTx_DigOut_13;
int doWrite_TSTx_DigOut_13(int value);
int prepareWrite_TSTx_DigOut_13(int value);
 
#define ID_TSTx_DigOut_14 4062
extern int TSTx_DigOut_14;
int doWrite_TSTx_DigOut_14(int value);
int prepareWrite_TSTx_DigOut_14(int value);
 
#define ID_TSTx_DigOut_15 4063
extern int TSTx_DigOut_15;
int doWrite_TSTx_DigOut_15(int value);
int prepareWrite_TSTx_DigOut_15(int value);
 
#define ID_TSTx_DigOut_16 4064
extern int TSTx_DigOut_16;
int doWrite_TSTx_DigOut_16(int value);
int prepareWrite_TSTx_DigOut_16(int value);
 
#define ID_VALx_DigOut_1 4065
extern int VALx_DigOut_1;
int doWrite_VALx_DigOut_1(int value);
int prepareWrite_VALx_DigOut_1(int value);
 
#define ID_VALx_DigOut_2 4066
extern int VALx_DigOut_2;
int doWrite_VALx_DigOut_2(int value);
int prepareWrite_VALx_DigOut_2(int value);
 
#define ID_VALx_DigOut_3 4067
extern int VALx_DigOut_3;
int doWrite_VALx_DigOut_3(int value);
int prepareWrite_VALx_DigOut_3(int value);
 
#define ID_VALx_DigOut_4 4068
extern int VALx_DigOut_4;
int doWrite_VALx_DigOut_4(int value);
int prepareWrite_VALx_DigOut_4(int value);
 
#define ID_VALx_DigOut_5 4069
extern int VALx_DigOut_5;
int doWrite_VALx_DigOut_5(int value);
int prepareWrite_VALx_DigOut_5(int value);
 
#define ID_VALx_DigOut_6 4070
extern int VALx_DigOut_6;
int doWrite_VALx_DigOut_6(int value);
int prepareWrite_VALx_DigOut_6(int value);
 
#define ID_VALx_DigOut_7 4071
extern int VALx_DigOut_7;
int doWrite_VALx_DigOut_7(int value);
int prepareWrite_VALx_DigOut_7(int value);
 
#define ID_VALx_DigOut_8 4072
extern int VALx_DigOut_8;
int doWrite_VALx_DigOut_8(int value);
int prepareWrite_VALx_DigOut_8(int value);
 
#define ID_VALx_DigOut_9 4073
extern int VALx_DigOut_9;
int doWrite_VALx_DigOut_9(int value);
int prepareWrite_VALx_DigOut_9(int value);
 
#define ID_VALx_DigOut_10 4074
extern int VALx_DigOut_10;
int doWrite_VALx_DigOut_10(int value);
int prepareWrite_VALx_DigOut_10(int value);
 
#define ID_VALx_DigOut_11 4075
extern int VALx_DigOut_11;
int doWrite_VALx_DigOut_11(int value);
int prepareWrite_VALx_DigOut_11(int value);
 
#define ID_VALx_DigOut_12 4076
extern int VALx_DigOut_12;
int doWrite_VALx_DigOut_12(int value);
int prepareWrite_VALx_DigOut_12(int value);
 
#define ID_VALx_DigOut_13 4077
extern int VALx_DigOut_13;
int doWrite_VALx_DigOut_13(int value);
int prepareWrite_VALx_DigOut_13(int value);
 
#define ID_VALx_DigOut_14 4078
extern int VALx_DigOut_14;
int doWrite_VALx_DigOut_14(int value);
int prepareWrite_VALx_DigOut_14(int value);
 
#define ID_VALx_DigOut_15 4079
extern int VALx_DigOut_15;
int doWrite_VALx_DigOut_15(int value);
int prepareWrite_VALx_DigOut_15(int value);
 
#define ID_VALx_DigOut_16 4080
extern int VALx_DigOut_16;
int doWrite_VALx_DigOut_16(int value);
int prepareWrite_VALx_DigOut_16(int value);
 
#define ID_RESx_DigOut_1 4081
extern int RESx_DigOut_1;
int doWrite_RESx_DigOut_1(int value);
int prepareWrite_RESx_DigOut_1(int value);
 
#define ID_RESx_DigOut_2 4082
extern int RESx_DigOut_2;
int doWrite_RESx_DigOut_2(int value);
int prepareWrite_RESx_DigOut_2(int value);
 
#define ID_RESx_DigOut_3 4083
extern int RESx_DigOut_3;
int doWrite_RESx_DigOut_3(int value);
int prepareWrite_RESx_DigOut_3(int value);
 
#define ID_RESx_DigOut_4 4084
extern int RESx_DigOut_4;
int doWrite_RESx_DigOut_4(int value);
int prepareWrite_RESx_DigOut_4(int value);
 
#define ID_RESx_DigOut_5 4085
extern int RESx_DigOut_5;
int doWrite_RESx_DigOut_5(int value);
int prepareWrite_RESx_DigOut_5(int value);
 
#define ID_RESx_DigOut_6 4086
extern int RESx_DigOut_6;
int doWrite_RESx_DigOut_6(int value);
int prepareWrite_RESx_DigOut_6(int value);
 
#define ID_RESx_DigOut_7 4087
extern int RESx_DigOut_7;
int doWrite_RESx_DigOut_7(int value);
int prepareWrite_RESx_DigOut_7(int value);
 
#define ID_RESx_DigOut_8 4088
extern int RESx_DigOut_8;
int doWrite_RESx_DigOut_8(int value);
int prepareWrite_RESx_DigOut_8(int value);
 
#define ID_RESx_DigOut_9 4089
extern int RESx_DigOut_9;
int doWrite_RESx_DigOut_9(int value);
int prepareWrite_RESx_DigOut_9(int value);
 
#define ID_RESx_DigOut_10 4090
extern int RESx_DigOut_10;
int doWrite_RESx_DigOut_10(int value);
int prepareWrite_RESx_DigOut_10(int value);
 
#define ID_RESx_DigOut_11 4091
extern int RESx_DigOut_11;
int doWrite_RESx_DigOut_11(int value);
int prepareWrite_RESx_DigOut_11(int value);
 
#define ID_RESx_DigOut_12 4092
extern int RESx_DigOut_12;
int doWrite_RESx_DigOut_12(int value);
int prepareWrite_RESx_DigOut_12(int value);
 
#define ID_RESx_DigOut_13 4093
extern int RESx_DigOut_13;
int doWrite_RESx_DigOut_13(int value);
int prepareWrite_RESx_DigOut_13(int value);
 
#define ID_RESx_DigOut_14 4094
extern int RESx_DigOut_14;
int doWrite_RESx_DigOut_14(int value);
int prepareWrite_RESx_DigOut_14(int value);
 
#define ID_RESx_DigOut_15 4095
extern int RESx_DigOut_15;
int doWrite_RESx_DigOut_15(int value);
int prepareWrite_RESx_DigOut_15(int value);
 
#define ID_RESx_DigOut_16 4096
extern int RESx_DigOut_16;
int doWrite_RESx_DigOut_16(int value);
int prepareWrite_RESx_DigOut_16(int value);
 
#define ID_TSTx_AnIn_1 4097
extern int TSTx_AnIn_1;
int doWrite_TSTx_AnIn_1(int value);
int prepareWrite_TSTx_AnIn_1(int value);
 
#define ID_TSTx_AnIn_2 4098
extern int TSTx_AnIn_2;
int doWrite_TSTx_AnIn_2(int value);
int prepareWrite_TSTx_AnIn_2(int value);
 
#define ID_TSTx_AnIn_3 4099
extern int TSTx_AnIn_3;
int doWrite_TSTx_AnIn_3(int value);
int prepareWrite_TSTx_AnIn_3(int value);
 
#define ID_TSTx_AnIn_4 4100
extern int TSTx_AnIn_4;
int doWrite_TSTx_AnIn_4(int value);
int prepareWrite_TSTx_AnIn_4(int value);
 
#define ID_TSTx_AnIn_5 4101
extern int TSTx_AnIn_5;
int doWrite_TSTx_AnIn_5(int value);
int prepareWrite_TSTx_AnIn_5(int value);
 
#define ID_TSTx_AnIn_6 4102
extern int TSTx_AnIn_6;
int doWrite_TSTx_AnIn_6(int value);
int prepareWrite_TSTx_AnIn_6(int value);
 
#define ID_TSTx_AnIn_7 4103
extern int TSTx_AnIn_7;
int doWrite_TSTx_AnIn_7(int value);
int prepareWrite_TSTx_AnIn_7(int value);
 
#define ID_TSTx_AnIn_8 4104
extern int TSTx_AnIn_8;
int doWrite_TSTx_AnIn_8(int value);
int prepareWrite_TSTx_AnIn_8(int value);
 
#define ID_TSTx_AnIn_9 4105
extern int TSTx_AnIn_9;
int doWrite_TSTx_AnIn_9(int value);
int prepareWrite_TSTx_AnIn_9(int value);
 
#define ID_TSTx_AnIn_10 4106
extern int TSTx_AnIn_10;
int doWrite_TSTx_AnIn_10(int value);
int prepareWrite_TSTx_AnIn_10(int value);
 
#define ID_TSTx_AnIn_11 4107
extern int TSTx_AnIn_11;
int doWrite_TSTx_AnIn_11(int value);
int prepareWrite_TSTx_AnIn_11(int value);
 
#define ID_TSTx_AnIn_12 4108
extern int TSTx_AnIn_12;
int doWrite_TSTx_AnIn_12(int value);
int prepareWrite_TSTx_AnIn_12(int value);
 
#define ID_VALx_AnIn_1 4109
extern int16_t VALx_AnIn_1;
int doWrite_VALx_AnIn_1(int16_t value);
int prepareWrite_VALx_AnIn_1(int16_t value);
 
#define ID_VALx_AnIn_2 4110
extern int16_t VALx_AnIn_2;
int doWrite_VALx_AnIn_2(int16_t value);
int prepareWrite_VALx_AnIn_2(int16_t value);
 
#define ID_VALx_AnIn_3 4111
extern int16_t VALx_AnIn_3;
int doWrite_VALx_AnIn_3(int16_t value);
int prepareWrite_VALx_AnIn_3(int16_t value);
 
#define ID_VALx_AnIn_4 4112
extern int16_t VALx_AnIn_4;
int doWrite_VALx_AnIn_4(int16_t value);
int prepareWrite_VALx_AnIn_4(int16_t value);
 
#define ID_VALx_AnIn_5 4113
extern int16_t VALx_AnIn_5;
int doWrite_VALx_AnIn_5(int16_t value);
int prepareWrite_VALx_AnIn_5(int16_t value);
 
#define ID_VALx_AnIn_6 4114
extern int16_t VALx_AnIn_6;
int doWrite_VALx_AnIn_6(int16_t value);
int prepareWrite_VALx_AnIn_6(int16_t value);
 
#define ID_VALx_AnIn_7 4115
extern int16_t VALx_AnIn_7;
int doWrite_VALx_AnIn_7(int16_t value);
int prepareWrite_VALx_AnIn_7(int16_t value);
 
#define ID_VALx_AnIn_8 4116
extern int16_t VALx_AnIn_8;
int doWrite_VALx_AnIn_8(int16_t value);
int prepareWrite_VALx_AnIn_8(int16_t value);
 
#define ID_VALx_AnIn_9 4117
extern int16_t VALx_AnIn_9;
int doWrite_VALx_AnIn_9(int16_t value);
int prepareWrite_VALx_AnIn_9(int16_t value);
 
#define ID_VALx_AnIn_10 4118
extern int16_t VALx_AnIn_10;
int doWrite_VALx_AnIn_10(int16_t value);
int prepareWrite_VALx_AnIn_10(int16_t value);
 
#define ID_VALx_AnIn_11 4119
extern int16_t VALx_AnIn_11;
int doWrite_VALx_AnIn_11(int16_t value);
int prepareWrite_VALx_AnIn_11(int16_t value);
 
#define ID_VALx_AnIn_12 4120
extern int16_t VALx_AnIn_12;
int doWrite_VALx_AnIn_12(int16_t value);
int prepareWrite_VALx_AnIn_12(int16_t value);
 
#define ID_VALx_AnInConf_1 4121
extern u_int16_t VALx_AnInConf_1;
int doWrite_VALx_AnInConf_1(u_int16_t value);
int prepareWrite_VALx_AnInConf_1(u_int16_t value);
 
#define ID_VALx_AnInConf_2 4122
extern u_int16_t VALx_AnInConf_2;
int doWrite_VALx_AnInConf_2(u_int16_t value);
int prepareWrite_VALx_AnInConf_2(u_int16_t value);
 
#define ID_VALx_AnInConf_3 4123
extern u_int16_t VALx_AnInConf_3;
int doWrite_VALx_AnInConf_3(u_int16_t value);
int prepareWrite_VALx_AnInConf_3(u_int16_t value);
 
#define ID_VALx_AnInConf_4 4124
extern u_int16_t VALx_AnInConf_4;
int doWrite_VALx_AnInConf_4(u_int16_t value);
int prepareWrite_VALx_AnInConf_4(u_int16_t value);
 
#define ID_VALx_AnInConf_5 4125
extern u_int16_t VALx_AnInConf_5;
int doWrite_VALx_AnInConf_5(u_int16_t value);
int prepareWrite_VALx_AnInConf_5(u_int16_t value);
 
#define ID_VALx_AnInConf_6 4126
extern u_int16_t VALx_AnInConf_6;
int doWrite_VALx_AnInConf_6(u_int16_t value);
int prepareWrite_VALx_AnInConf_6(u_int16_t value);
 
#define ID_VALx_AnInConf_7 4127
extern u_int16_t VALx_AnInConf_7;
int doWrite_VALx_AnInConf_7(u_int16_t value);
int prepareWrite_VALx_AnInConf_7(u_int16_t value);
 
#define ID_VALx_AnInConf_8 4128
extern u_int16_t VALx_AnInConf_8;
int doWrite_VALx_AnInConf_8(u_int16_t value);
int prepareWrite_VALx_AnInConf_8(u_int16_t value);
 
#define ID_VALx_AnInConf_9 4129
extern u_int16_t VALx_AnInConf_9;
int doWrite_VALx_AnInConf_9(u_int16_t value);
int prepareWrite_VALx_AnInConf_9(u_int16_t value);
 
#define ID_VALx_AnInConf_10 4130
extern u_int16_t VALx_AnInConf_10;
int doWrite_VALx_AnInConf_10(u_int16_t value);
int prepareWrite_VALx_AnInConf_10(u_int16_t value);
 
#define ID_VALx_AnInConf_11 4131
extern u_int16_t VALx_AnInConf_11;
int doWrite_VALx_AnInConf_11(u_int16_t value);
int prepareWrite_VALx_AnInConf_11(u_int16_t value);
 
#define ID_VALx_AnInConf_12 4132
extern u_int16_t VALx_AnInConf_12;
int doWrite_VALx_AnInConf_12(u_int16_t value);
int prepareWrite_VALx_AnInConf_12(u_int16_t value);
 
#define ID_VALx_AnInFltr_1 4133
extern u_int16_t VALx_AnInFltr_1;
int doWrite_VALx_AnInFltr_1(u_int16_t value);
int prepareWrite_VALx_AnInFltr_1(u_int16_t value);
 
#define ID_VALx_AnInFltr_2 4134
extern u_int16_t VALx_AnInFltr_2;
int doWrite_VALx_AnInFltr_2(u_int16_t value);
int prepareWrite_VALx_AnInFltr_2(u_int16_t value);
 
#define ID_VALx_AnInFltr_3 4135
extern u_int16_t VALx_AnInFltr_3;
int doWrite_VALx_AnInFltr_3(u_int16_t value);
int prepareWrite_VALx_AnInFltr_3(u_int16_t value);
 
#define ID_VALx_AnInFltr_4 4136
extern u_int16_t VALx_AnInFltr_4;
int doWrite_VALx_AnInFltr_4(u_int16_t value);
int prepareWrite_VALx_AnInFltr_4(u_int16_t value);
 
#define ID_VALx_AnInFltr_5 4137
extern u_int16_t VALx_AnInFltr_5;
int doWrite_VALx_AnInFltr_5(u_int16_t value);
int prepareWrite_VALx_AnInFltr_5(u_int16_t value);
 
#define ID_VALx_AnInFltr_6 4138
extern u_int16_t VALx_AnInFltr_6;
int doWrite_VALx_AnInFltr_6(u_int16_t value);
int prepareWrite_VALx_AnInFltr_6(u_int16_t value);
 
#define ID_VALx_AnInFltr_7 4139
extern u_int16_t VALx_AnInFltr_7;
int doWrite_VALx_AnInFltr_7(u_int16_t value);
int prepareWrite_VALx_AnInFltr_7(u_int16_t value);
 
#define ID_VALx_AnInFltr_8 4140
extern u_int16_t VALx_AnInFltr_8;
int doWrite_VALx_AnInFltr_8(u_int16_t value);
int prepareWrite_VALx_AnInFltr_8(u_int16_t value);
 
#define ID_VALx_AnInFltr_9 4141
extern u_int16_t VALx_AnInFltr_9;
int doWrite_VALx_AnInFltr_9(u_int16_t value);
int prepareWrite_VALx_AnInFltr_9(u_int16_t value);
 
#define ID_VALx_AnInFltr_10 4142
extern u_int16_t VALx_AnInFltr_10;
int doWrite_VALx_AnInFltr_10(u_int16_t value);
int prepareWrite_VALx_AnInFltr_10(u_int16_t value);
 
#define ID_VALx_AnInFltr_11 4143
extern u_int16_t VALx_AnInFltr_11;
int doWrite_VALx_AnInFltr_11(u_int16_t value);
int prepareWrite_VALx_AnInFltr_11(u_int16_t value);
 
#define ID_VALx_AnInFltr_12 4144
extern u_int16_t VALx_AnInFltr_12;
int doWrite_VALx_AnInFltr_12(u_int16_t value);
int prepareWrite_VALx_AnInFltr_12(u_int16_t value);
 
#define ID_RESx_AnIn_1 4145
extern int16_t RESx_AnIn_1;
int doWrite_RESx_AnIn_1(int16_t value);
int prepareWrite_RESx_AnIn_1(int16_t value);
 
#define ID_RESx_AnIn_2 4146
extern int16_t RESx_AnIn_2;
int doWrite_RESx_AnIn_2(int16_t value);
int prepareWrite_RESx_AnIn_2(int16_t value);
 
#define ID_RESx_AnIn_3 4147
extern int16_t RESx_AnIn_3;
int doWrite_RESx_AnIn_3(int16_t value);
int prepareWrite_RESx_AnIn_3(int16_t value);
 
#define ID_RESx_AnIn_4 4148
extern int16_t RESx_AnIn_4;
int doWrite_RESx_AnIn_4(int16_t value);
int prepareWrite_RESx_AnIn_4(int16_t value);
 
#define ID_RESx_AnIn_5 4149
extern int16_t RESx_AnIn_5;
int doWrite_RESx_AnIn_5(int16_t value);
int prepareWrite_RESx_AnIn_5(int16_t value);
 
#define ID_RESx_AnIn_6 4150
extern int16_t RESx_AnIn_6;
int doWrite_RESx_AnIn_6(int16_t value);
int prepareWrite_RESx_AnIn_6(int16_t value);
 
#define ID_RESx_AnIn_7 4151
extern int16_t RESx_AnIn_7;
int doWrite_RESx_AnIn_7(int16_t value);
int prepareWrite_RESx_AnIn_7(int16_t value);
 
#define ID_RESx_AnIn_8 4152
extern int16_t RESx_AnIn_8;
int doWrite_RESx_AnIn_8(int16_t value);
int prepareWrite_RESx_AnIn_8(int16_t value);
 
#define ID_RESx_AnIn_9 4153
extern int16_t RESx_AnIn_9;
int doWrite_RESx_AnIn_9(int16_t value);
int prepareWrite_RESx_AnIn_9(int16_t value);
 
#define ID_RESx_AnIn_10 4154
extern int16_t RESx_AnIn_10;
int doWrite_RESx_AnIn_10(int16_t value);
int prepareWrite_RESx_AnIn_10(int16_t value);
 
#define ID_RESx_AnIn_11 4155
extern int16_t RESx_AnIn_11;
int doWrite_RESx_AnIn_11(int16_t value);
int prepareWrite_RESx_AnIn_11(int16_t value);
 
#define ID_RESx_AnIn_12 4156
extern int16_t RESx_AnIn_12;
int doWrite_RESx_AnIn_12(int16_t value);
int prepareWrite_RESx_AnIn_12(int16_t value);
 
#define ID_RESx_AnInStts_1 4157
extern int16_t RESx_AnInStts_1;
int doWrite_RESx_AnInStts_1(int16_t value);
int prepareWrite_RESx_AnInStts_1(int16_t value);
 
#define ID_RESx_AnInStts_2 4158
extern int16_t RESx_AnInStts_2;
int doWrite_RESx_AnInStts_2(int16_t value);
int prepareWrite_RESx_AnInStts_2(int16_t value);
 
#define ID_RESx_AnInStts_3 4159
extern int16_t RESx_AnInStts_3;
int doWrite_RESx_AnInStts_3(int16_t value);
int prepareWrite_RESx_AnInStts_3(int16_t value);
 
#define ID_RESx_AnInStts_4 4160
extern int16_t RESx_AnInStts_4;
int doWrite_RESx_AnInStts_4(int16_t value);
int prepareWrite_RESx_AnInStts_4(int16_t value);
 
#define ID_RESx_AnInStts_5 4161
extern int16_t RESx_AnInStts_5;
int doWrite_RESx_AnInStts_5(int16_t value);
int prepareWrite_RESx_AnInStts_5(int16_t value);
 
#define ID_RESx_AnInStts_6 4162
extern int16_t RESx_AnInStts_6;
int doWrite_RESx_AnInStts_6(int16_t value);
int prepareWrite_RESx_AnInStts_6(int16_t value);
 
#define ID_RESx_AnInStts_7 4163
extern int16_t RESx_AnInStts_7;
int doWrite_RESx_AnInStts_7(int16_t value);
int prepareWrite_RESx_AnInStts_7(int16_t value);
 
#define ID_RESx_AnInStts_8 4164
extern int16_t RESx_AnInStts_8;
int doWrite_RESx_AnInStts_8(int16_t value);
int prepareWrite_RESx_AnInStts_8(int16_t value);
 
#define ID_RESx_AnInStts_9 4165
extern int16_t RESx_AnInStts_9;
int doWrite_RESx_AnInStts_9(int16_t value);
int prepareWrite_RESx_AnInStts_9(int16_t value);
 
#define ID_RESx_AnInStts_10 4166
extern int16_t RESx_AnInStts_10;
int doWrite_RESx_AnInStts_10(int16_t value);
int prepareWrite_RESx_AnInStts_10(int16_t value);
 
#define ID_RESx_AnInStts_11 4167
extern int16_t RESx_AnInStts_11;
int doWrite_RESx_AnInStts_11(int16_t value);
int prepareWrite_RESx_AnInStts_11(int16_t value);
 
#define ID_RESx_AnInStts_12 4168
extern int16_t RESx_AnInStts_12;
int doWrite_RESx_AnInStts_12(int16_t value);
int prepareWrite_RESx_AnInStts_12(int16_t value);
 
#define ID_TSTx_AnOut_1 4169
extern int TSTx_AnOut_1;
int doWrite_TSTx_AnOut_1(int value);
int prepareWrite_TSTx_AnOut_1(int value);
 
#define ID_TSTx_AnOut_2 4170
extern int TSTx_AnOut_2;
int doWrite_TSTx_AnOut_2(int value);
int prepareWrite_TSTx_AnOut_2(int value);
 
#define ID_TSTx_AnOut_3 4171
extern int TSTx_AnOut_3;
int doWrite_TSTx_AnOut_3(int value);
int prepareWrite_TSTx_AnOut_3(int value);
 
#define ID_TSTx_AnOut_4 4172
extern int TSTx_AnOut_4;
int doWrite_TSTx_AnOut_4(int value);
int prepareWrite_TSTx_AnOut_4(int value);
 
#define ID_VALx_AnOut_1 4173
extern int16_t VALx_AnOut_1;
int doWrite_VALx_AnOut_1(int16_t value);
int prepareWrite_VALx_AnOut_1(int16_t value);
 
#define ID_VALx_AnOut_2 4174
extern int16_t VALx_AnOut_2;
int doWrite_VALx_AnOut_2(int16_t value);
int prepareWrite_VALx_AnOut_2(int16_t value);
 
#define ID_VALx_AnOut_3 4175
extern int16_t VALx_AnOut_3;
int doWrite_VALx_AnOut_3(int16_t value);
int prepareWrite_VALx_AnOut_3(int16_t value);
 
#define ID_VALx_AnOut_4 4176
extern int16_t VALx_AnOut_4;
int doWrite_VALx_AnOut_4(int16_t value);
int prepareWrite_VALx_AnOut_4(int16_t value);
 
#define ID_VALx_AnOutConf_1 4177
extern u_int16_t VALx_AnOutConf_1;
int doWrite_VALx_AnOutConf_1(u_int16_t value);
int prepareWrite_VALx_AnOutConf_1(u_int16_t value);
 
#define ID_VALx_AnOutConf_2 4178
extern u_int16_t VALx_AnOutConf_2;
int doWrite_VALx_AnOutConf_2(u_int16_t value);
int prepareWrite_VALx_AnOutConf_2(u_int16_t value);
 
#define ID_VALx_AnOutConf_3 4179
extern u_int16_t VALx_AnOutConf_3;
int doWrite_VALx_AnOutConf_3(u_int16_t value);
int prepareWrite_VALx_AnOutConf_3(u_int16_t value);
 
#define ID_VALx_AnOutConf_4 4180
extern u_int16_t VALx_AnOutConf_4;
int doWrite_VALx_AnOutConf_4(u_int16_t value);
int prepareWrite_VALx_AnOutConf_4(u_int16_t value);
 
#define ID_RESx_AnOutStts_1 4181
extern int16_t RESx_AnOutStts_1;
int doWrite_RESx_AnOutStts_1(int16_t value);
int prepareWrite_RESx_AnOutStts_1(int16_t value);
 
#define ID_RESx_AnOutStts_2 4182
extern int16_t RESx_AnOutStts_2;
int doWrite_RESx_AnOutStts_2(int16_t value);
int prepareWrite_RESx_AnOutStts_2(int16_t value);
 
#define ID_RESx_AnOutStts_3 4183
extern int16_t RESx_AnOutStts_3;
int doWrite_RESx_AnOutStts_3(int16_t value);
int prepareWrite_RESx_AnOutStts_3(int16_t value);
 
#define ID_RESx_AnOutStts_4 4184
extern int16_t RESx_AnOutStts_4;
int doWrite_RESx_AnOutStts_4(int16_t value);
int prepareWrite_RESx_AnOutStts_4(int16_t value);
 
#define ID_TSTx_Tamb 4185
extern int TSTx_Tamb;
int doWrite_TSTx_Tamb(int value);
int prepareWrite_TSTx_Tamb(int value);
 
#define ID_TSTx_RPM 4186
extern int TSTx_RPM;
int doWrite_TSTx_RPM(int value);
int prepareWrite_TSTx_RPM(int value);
 
#define ID_TSTx_FWrevision 4187
extern int TSTx_FWrevision;
int doWrite_TSTx_FWrevision(int value);
int prepareWrite_TSTx_FWrevision(int value);
 
#define ID_TSTx_HWconfig 4188
extern int TSTx_HWconfig;
int doWrite_TSTx_HWconfig(int value);
int prepareWrite_TSTx_HWconfig(int value);
 
#define ID_VALx_Tamb 4189
extern int16_t VALx_Tamb;
int doWrite_VALx_Tamb(int16_t value);
int prepareWrite_VALx_Tamb(int16_t value);
 
#define ID_VALx_RPM 4190
extern u_int16_t VALx_RPM;
int doWrite_VALx_RPM(u_int16_t value);
int prepareWrite_VALx_RPM(u_int16_t value);
 
#define ID_VALx_FWrevision 4191
extern u_int16_t VALx_FWrevision;
int doWrite_VALx_FWrevision(u_int16_t value);
int prepareWrite_VALx_FWrevision(u_int16_t value);
 
#define ID_VALx_HWconfig 4192
extern u_int16_t VALx_HWconfig;
int doWrite_VALx_HWconfig(u_int16_t value);
int prepareWrite_VALx_HWconfig(u_int16_t value);
 
#define ID_RESx_Tamb 4193
extern int16_t RESx_Tamb;
int doWrite_RESx_Tamb(int16_t value);
int prepareWrite_RESx_Tamb(int16_t value);
 
#define ID_RESx_RPM 4194
extern u_int16_t RESx_RPM;
int doWrite_RESx_RPM(u_int16_t value);
int prepareWrite_RESx_RPM(u_int16_t value);
 
#define ID_RESx_FWrevision 4195
extern u_int16_t RESx_FWrevision;
int doWrite_RESx_FWrevision(u_int16_t value);
int prepareWrite_RESx_FWrevision(u_int16_t value);
 
#define ID_RESx_HWconfig 4196
extern u_int16_t RESx_HWconfig;
int doWrite_RESx_HWconfig(u_int16_t value);
int prepareWrite_RESx_HWconfig(u_int16_t value);
 
#define ID_TSTx_RTUS_WR 4197
extern int TSTx_RTUS_WR;
int doWrite_TSTx_RTUS_WR(int value);
int prepareWrite_TSTx_RTUS_WR(int value);
 
#define ID_TSTx_RTUS_RD 4198
extern int TSTx_RTUS_RD;
int doWrite_TSTx_RTUS_RD(int value);
int prepareWrite_TSTx_RTUS_RD(int value);
 
#define ID_TSTx_RTU1_WR 4199
extern int TSTx_RTU1_WR;
int doWrite_TSTx_RTU1_WR(int value);
int prepareWrite_TSTx_RTU1_WR(int value);
 
#define ID_TSTx_RTU1_RD 4200
extern int TSTx_RTU1_RD;
int doWrite_TSTx_RTU1_RD(int value);
int prepareWrite_TSTx_RTU1_RD(int value);
 
#define ID_TSTx_RTU3_WR 4201
extern int TSTx_RTU3_WR;
int doWrite_TSTx_RTU3_WR(int value);
int prepareWrite_TSTx_RTU3_WR(int value);
 
#define ID_TSTx_RTU3_RD 4202
extern int TSTx_RTU3_RD;
int doWrite_TSTx_RTU3_RD(int value);
int prepareWrite_TSTx_RTU3_RD(int value);
 
#define ID_TSTx_CAN1_WR 4203
extern int TSTx_CAN1_WR;
int doWrite_TSTx_CAN1_WR(int value);
int prepareWrite_TSTx_CAN1_WR(int value);
 
#define ID_TSTx_CAN1_RD 4204
extern int TSTx_CAN1_RD;
int doWrite_TSTx_CAN1_RD(int value);
int prepareWrite_TSTx_CAN1_RD(int value);
 
#define ID_VALx_RTUS_WR 4205
extern int VALx_RTUS_WR;
int doWrite_VALx_RTUS_WR(int value);
int prepareWrite_VALx_RTUS_WR(int value);
 
#define ID_VALx_RTUS_RD 4206
extern int VALx_RTUS_RD;
int doWrite_VALx_RTUS_RD(int value);
int prepareWrite_VALx_RTUS_RD(int value);
 
#define ID_VALx_RTU1_WR 4207
extern int VALx_RTU1_WR;
int doWrite_VALx_RTU1_WR(int value);
int prepareWrite_VALx_RTU1_WR(int value);
 
#define ID_VALx_RTU1_RD 4208
extern int VALx_RTU1_RD;
int doWrite_VALx_RTU1_RD(int value);
int prepareWrite_VALx_RTU1_RD(int value);
 
#define ID_VALx_RTU3_WR 4209
extern int VALx_RTU3_WR;
int doWrite_VALx_RTU3_WR(int value);
int prepareWrite_VALx_RTU3_WR(int value);
 
#define ID_VALx_RTU3_RD 4210
extern int VALx_RTU3_RD;
int doWrite_VALx_RTU3_RD(int value);
int prepareWrite_VALx_RTU3_RD(int value);
 
#define ID_VALx_CAN1_WR 4211
extern int VALx_CAN1_WR;
int doWrite_VALx_CAN1_WR(int value);
int prepareWrite_VALx_CAN1_WR(int value);
 
#define ID_VALx_CAN1_RD 4212
extern int VALx_CAN1_RD;
int doWrite_VALx_CAN1_RD(int value);
int prepareWrite_VALx_CAN1_RD(int value);
 
#define ID_RESx_RTUS_WR 4213
extern int RESx_RTUS_WR;
int doWrite_RESx_RTUS_WR(int value);
int prepareWrite_RESx_RTUS_WR(int value);
 
#define ID_RESx_RTUS_RD 4214
extern int RESx_RTUS_RD;
int doWrite_RESx_RTUS_RD(int value);
int prepareWrite_RESx_RTUS_RD(int value);
 
#define ID_RESx_RTU1_WR 4215
extern int RESx_RTU1_WR;
int doWrite_RESx_RTU1_WR(int value);
int prepareWrite_RESx_RTU1_WR(int value);
 
#define ID_RESx_RTU1_RD 4216
extern int RESx_RTU1_RD;
int doWrite_RESx_RTU1_RD(int value);
int prepareWrite_RESx_RTU1_RD(int value);
 
#define ID_RESx_RTU3_WR 4217
extern int RESx_RTU3_WR;
int doWrite_RESx_RTU3_WR(int value);
int prepareWrite_RESx_RTU3_WR(int value);
 
#define ID_RESx_RTU3_RD 4218
extern int RESx_RTU3_RD;
int doWrite_RESx_RTU3_RD(int value);
int prepareWrite_RESx_RTU3_RD(int value);
 
#define ID_RESx_CAN1_WR 4219
extern int RESx_CAN1_WR;
int doWrite_RESx_CAN1_WR(int value);
int prepareWrite_RESx_CAN1_WR(int value);
 
#define ID_RESx_CAN1_RD 4220
extern int RESx_CAN1_RD;
int doWrite_RESx_CAN1_RD(int value);
int prepareWrite_RESx_CAN1_RD(int value);
 
#define ID_STATUSx_LOCAL 4221
extern int STATUSx_LOCAL;
int doWrite_STATUSx_LOCAL(int value);
int prepareWrite_STATUSx_LOCAL(int value);
 
#define ID_STATUSx_REMOTE 4222
extern int STATUSx_REMOTE;
int doWrite_STATUSx_REMOTE(int value);
int prepareWrite_STATUSx_REMOTE(int value);
 
#define ID_STATUSx_DONE 4223
extern int STATUSx_DONE;
int doWrite_STATUSx_DONE(int value);
int prepareWrite_STATUSx_DONE(int value);
 
#define ID_RTU_DigIn_1 5000
extern int RTU_DigIn_1;
int doWrite_RTU_DigIn_1(int value);
int prepareWrite_RTU_DigIn_1(int value);
 
#define ID_RTU_DigIn_2 5001
extern int RTU_DigIn_2;
int doWrite_RTU_DigIn_2(int value);
int prepareWrite_RTU_DigIn_2(int value);
 
#define ID_RTU_DigIn_3 5002
extern int RTU_DigIn_3;
int doWrite_RTU_DigIn_3(int value);
int prepareWrite_RTU_DigIn_3(int value);
 
#define ID_RTU_DigIn_4 5003
extern int RTU_DigIn_4;
int doWrite_RTU_DigIn_4(int value);
int prepareWrite_RTU_DigIn_4(int value);
 
#define ID_RTU_DigIn_5 5004
extern int RTU_DigIn_5;
int doWrite_RTU_DigIn_5(int value);
int prepareWrite_RTU_DigIn_5(int value);
 
#define ID_RTU_DigIn_6 5005
extern int RTU_DigIn_6;
int doWrite_RTU_DigIn_6(int value);
int prepareWrite_RTU_DigIn_6(int value);
 
#define ID_RTU_DigIn_7 5006
extern int RTU_DigIn_7;
int doWrite_RTU_DigIn_7(int value);
int prepareWrite_RTU_DigIn_7(int value);
 
#define ID_RTU_DigIn_8 5007
extern int RTU_DigIn_8;
int doWrite_RTU_DigIn_8(int value);
int prepareWrite_RTU_DigIn_8(int value);
 
#define ID_RTU_DigIn_9 5008
extern int RTU_DigIn_9;
int doWrite_RTU_DigIn_9(int value);
int prepareWrite_RTU_DigIn_9(int value);
 
#define ID_RTU_DigIn_10 5009
extern int RTU_DigIn_10;
int doWrite_RTU_DigIn_10(int value);
int prepareWrite_RTU_DigIn_10(int value);
 
#define ID_RTU_DigIn_11 5010
extern int RTU_DigIn_11;
int doWrite_RTU_DigIn_11(int value);
int prepareWrite_RTU_DigIn_11(int value);
 
#define ID_RTU_DigIn_12 5011
extern int RTU_DigIn_12;
int doWrite_RTU_DigIn_12(int value);
int prepareWrite_RTU_DigIn_12(int value);
 
#define ID_RTU_DigIn_13 5012
extern int RTU_DigIn_13;
int doWrite_RTU_DigIn_13(int value);
int prepareWrite_RTU_DigIn_13(int value);
 
#define ID_RTU_DigIn_14 5013
extern int RTU_DigIn_14;
int doWrite_RTU_DigIn_14(int value);
int prepareWrite_RTU_DigIn_14(int value);
 
#define ID_RTU_DigIn_15 5014
extern int RTU_DigIn_15;
int doWrite_RTU_DigIn_15(int value);
int prepareWrite_RTU_DigIn_15(int value);
 
#define ID_RTU_DigIn_16 5015
extern int RTU_DigIn_16;
int doWrite_RTU_DigIn_16(int value);
int prepareWrite_RTU_DigIn_16(int value);
 
#define ID_RTU_AnIn_1 5016
extern int16_t RTU_AnIn_1;
int doWrite_RTU_AnIn_1(int16_t value);
int prepareWrite_RTU_AnIn_1(int16_t value);
 
#define ID_RTU_AnIn_2 5017
extern int16_t RTU_AnIn_2;
int doWrite_RTU_AnIn_2(int16_t value);
int prepareWrite_RTU_AnIn_2(int16_t value);
 
#define ID_RTU_Tamb 5018
extern int16_t RTU_Tamb;
int doWrite_RTU_Tamb(int16_t value);
int prepareWrite_RTU_Tamb(int16_t value);
 
#define ID_RTU_DigOut_1 5019
extern int RTU_DigOut_1;
int doWrite_RTU_DigOut_1(int value);
int prepareWrite_RTU_DigOut_1(int value);
 
#define ID_RTU_DigOut_2 5020
extern int RTU_DigOut_2;
int doWrite_RTU_DigOut_2(int value);
int prepareWrite_RTU_DigOut_2(int value);
 
#define ID_RTU_DigOut_3 5021
extern int RTU_DigOut_3;
int doWrite_RTU_DigOut_3(int value);
int prepareWrite_RTU_DigOut_3(int value);
 
#define ID_RTU_DigOut_4 5022
extern int RTU_DigOut_4;
int doWrite_RTU_DigOut_4(int value);
int prepareWrite_RTU_DigOut_4(int value);
 
#define ID_RTU_DigOut_5 5023
extern int RTU_DigOut_5;
int doWrite_RTU_DigOut_5(int value);
int prepareWrite_RTU_DigOut_5(int value);
 
#define ID_RTU_DigOut_6 5024
extern int RTU_DigOut_6;
int doWrite_RTU_DigOut_6(int value);
int prepareWrite_RTU_DigOut_6(int value);
 
#define ID_RTU_DigOut_7 5025
extern int RTU_DigOut_7;
int doWrite_RTU_DigOut_7(int value);
int prepareWrite_RTU_DigOut_7(int value);
 
#define ID_RTU_DigOut_8 5026
extern int RTU_DigOut_8;
int doWrite_RTU_DigOut_8(int value);
int prepareWrite_RTU_DigOut_8(int value);
 
#define ID_RTU_DigOut_9 5027
extern int RTU_DigOut_9;
int doWrite_RTU_DigOut_9(int value);
int prepareWrite_RTU_DigOut_9(int value);
 
#define ID_RTU_DigOut_10 5028
extern int RTU_DigOut_10;
int doWrite_RTU_DigOut_10(int value);
int prepareWrite_RTU_DigOut_10(int value);
 
#define ID_RTU_DigOut_11 5029
extern int RTU_DigOut_11;
int doWrite_RTU_DigOut_11(int value);
int prepareWrite_RTU_DigOut_11(int value);
 
#define ID_RTU_DigOut_12 5030
extern int RTU_DigOut_12;
int doWrite_RTU_DigOut_12(int value);
int prepareWrite_RTU_DigOut_12(int value);
 
#define ID_RTU_DigOut_13 5031
extern int RTU_DigOut_13;
int doWrite_RTU_DigOut_13(int value);
int prepareWrite_RTU_DigOut_13(int value);
 
#define ID_RTU_DigOut_14 5032
extern int RTU_DigOut_14;
int doWrite_RTU_DigOut_14(int value);
int prepareWrite_RTU_DigOut_14(int value);
 
#define ID_RTU_DigOut_15 5033
extern int RTU_DigOut_15;
int doWrite_RTU_DigOut_15(int value);
int prepareWrite_RTU_DigOut_15(int value);
 
#define ID_RTU_DigOut_16 5034
extern int RTU_DigOut_16;
int doWrite_RTU_DigOut_16(int value);
int prepareWrite_RTU_DigOut_16(int value);
 
#define ID_RTU_AnOutConf_X 5035
extern int16_t RTU_AnOutConf_X;
int doWrite_RTU_AnOutConf_X(int16_t value);
int prepareWrite_RTU_AnOutConf_X(int16_t value);
 
#define ID_RTU_AnOut_1 5036
extern int16_t RTU_AnOut_1;
int doWrite_RTU_AnOut_1(int16_t value);
int prepareWrite_RTU_AnOut_1(int16_t value);
 
#define ID_RTU_AnOut_2 5037
extern int16_t RTU_AnOut_2;
int doWrite_RTU_AnOut_2(int16_t value);
int prepareWrite_RTU_AnOut_2(int16_t value);
 
#define ID_RTU_AnOut_3 5038
extern int16_t RTU_AnOut_3;
int doWrite_RTU_AnOut_3(int16_t value);
int prepareWrite_RTU_AnOut_3(int16_t value);
 
#define ID_RTU_AnOut_4 5039
extern int16_t RTU_AnOut_4;
int doWrite_RTU_AnOut_4(int16_t value);
int prepareWrite_RTU_AnOut_4(int16_t value);
 
#define ID_RTU_AnOut_5 5040
extern int16_t RTU_AnOut_5;
int doWrite_RTU_AnOut_5(int16_t value);
int prepareWrite_RTU_AnOut_5(int16_t value);
 
#define ID_RTU_AnOut_6 5041
extern int16_t RTU_AnOut_6;
int doWrite_RTU_AnOut_6(int16_t value);
int prepareWrite_RTU_AnOut_6(int16_t value);
 
#define ID_RTU_AnOut_7 5042
extern int16_t RTU_AnOut_7;
int doWrite_RTU_AnOut_7(int16_t value);
int prepareWrite_RTU_AnOut_7(int16_t value);
 
#define ID_RTU_AnOut_8 5043
extern int16_t RTU_AnOut_8;
int doWrite_RTU_AnOut_8(int16_t value);
int prepareWrite_RTU_AnOut_8(int16_t value);
 
#define ID_RTU_AnInConf_1 5044
extern u_int16_t RTU_AnInConf_1;
int doWrite_RTU_AnInConf_1(u_int16_t value);
int prepareWrite_RTU_AnInConf_1(u_int16_t value);
 
#define ID_RTU_AnInConf_2 5045
extern u_int16_t RTU_AnInConf_2;
int doWrite_RTU_AnInConf_2(u_int16_t value);
int prepareWrite_RTU_AnInConf_2(u_int16_t value);
 
#define ID_RTU_HeartBeat 5046
extern u_int32_t RTU_HeartBeat;
int doWrite_RTU_HeartBeat(u_int32_t value);
int prepareWrite_RTU_HeartBeat(u_int32_t value);
 
#define ID_PLC_FWrevision 5300
extern u_int16_t PLC_FWrevision;
int doWrite_PLC_FWrevision(u_int16_t value);
int prepareWrite_PLC_FWrevision(u_int16_t value);
 
#define ID_PLC_HWconfig 5301
extern u_int16_t PLC_HWconfig;
int doWrite_PLC_HWconfig(u_int16_t value);
int prepareWrite_PLC_HWconfig(u_int16_t value);
 
#define ID_PLC_DigDir_1 5302
extern int PLC_DigDir_1;
int doWrite_PLC_DigDir_1(int value);
int prepareWrite_PLC_DigDir_1(int value);
 
#define ID_PLC_DigDir_2 5303
extern int PLC_DigDir_2;
int doWrite_PLC_DigDir_2(int value);
int prepareWrite_PLC_DigDir_2(int value);
 
#define ID_PLC_DigDir_3 5304
extern int PLC_DigDir_3;
int doWrite_PLC_DigDir_3(int value);
int prepareWrite_PLC_DigDir_3(int value);
 
#define ID_PLC_DigDir_4 5305
extern int PLC_DigDir_4;
int doWrite_PLC_DigDir_4(int value);
int prepareWrite_PLC_DigDir_4(int value);
 
#define ID_PLC_DigDir_5 5306
extern int PLC_DigDir_5;
int doWrite_PLC_DigDir_5(int value);
int prepareWrite_PLC_DigDir_5(int value);
 
#define ID_PLC_DigDir_6 5307
extern int PLC_DigDir_6;
int doWrite_PLC_DigDir_6(int value);
int prepareWrite_PLC_DigDir_6(int value);
 
#define ID_PLC_DigDir_7 5308
extern int PLC_DigDir_7;
int doWrite_PLC_DigDir_7(int value);
int prepareWrite_PLC_DigDir_7(int value);
 
#define ID_PLC_DigDir_8 5309
extern int PLC_DigDir_8;
int doWrite_PLC_DigDir_8(int value);
int prepareWrite_PLC_DigDir_8(int value);
 
#define ID_PLC_AnInConf_1 5310
extern u_int16_t PLC_AnInConf_1;
int doWrite_PLC_AnInConf_1(u_int16_t value);
int prepareWrite_PLC_AnInConf_1(u_int16_t value);
 
#define ID_PLC_AnInConf_2 5311
extern u_int16_t PLC_AnInConf_2;
int doWrite_PLC_AnInConf_2(u_int16_t value);
int prepareWrite_PLC_AnInConf_2(u_int16_t value);
 
#define ID_PLC_AnOutConf_1 5312
extern u_int16_t PLC_AnOutConf_1;
int doWrite_PLC_AnOutConf_1(u_int16_t value);
int prepareWrite_PLC_AnOutConf_1(u_int16_t value);
 
#define ID_PLC_AnOutConf_2 5313
extern u_int16_t PLC_AnOutConf_2;
int doWrite_PLC_AnOutConf_2(u_int16_t value);
int prepareWrite_PLC_AnOutConf_2(u_int16_t value);
 
#define ID_PLC_AnOutConf_3 5314
extern u_int16_t PLC_AnOutConf_3;
int doWrite_PLC_AnOutConf_3(u_int16_t value);
int prepareWrite_PLC_AnOutConf_3(u_int16_t value);
 
#define ID_PLC_AnOutConf_4 5315
extern u_int16_t PLC_AnOutConf_4;
int doWrite_PLC_AnOutConf_4(u_int16_t value);
int prepareWrite_PLC_AnOutConf_4(u_int16_t value);
 
#define ID_PLC_DigIn_1 5316
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int prepareWrite_PLC_DigIn_1(int value);
 
#define ID_PLC_DigIn_2 5317
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int prepareWrite_PLC_DigIn_2(int value);
 
#define ID_PLC_DigIn_3 5318
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int prepareWrite_PLC_DigIn_3(int value);
 
#define ID_PLC_DigIn_4 5319
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int prepareWrite_PLC_DigIn_4(int value);
 
#define ID_PLC_DigIn_5 5320
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int prepareWrite_PLC_DigIn_5(int value);
 
#define ID_PLC_DigIn_6 5321
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int prepareWrite_PLC_DigIn_6(int value);
 
#define ID_PLC_DigIn_7 5322
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int prepareWrite_PLC_DigIn_7(int value);
 
#define ID_PLC_DigIn_8 5323
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int prepareWrite_PLC_DigIn_8(int value);
 
#define ID_PLC_DigIn_9 5324
extern int PLC_DigIn_9;
int doWrite_PLC_DigIn_9(int value);
int prepareWrite_PLC_DigIn_9(int value);
 
#define ID_PLC_DigIn_10 5325
extern int PLC_DigIn_10;
int doWrite_PLC_DigIn_10(int value);
int prepareWrite_PLC_DigIn_10(int value);
 
#define ID_PLC_DigIn_11 5326
extern int PLC_DigIn_11;
int doWrite_PLC_DigIn_11(int value);
int prepareWrite_PLC_DigIn_11(int value);
 
#define ID_PLC_DigIn_12 5327
extern int PLC_DigIn_12;
int doWrite_PLC_DigIn_12(int value);
int prepareWrite_PLC_DigIn_12(int value);
 
#define ID_PLC_AnIn_1 5328
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int prepareWrite_PLC_AnIn_1(int16_t value);
 
#define ID_PLC_AnIn_2 5329
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int prepareWrite_PLC_AnIn_2(int16_t value);
 
#define ID_PLC_AnIn_3 5330
extern int16_t PLC_AnIn_3;
int doWrite_PLC_AnIn_3(int16_t value);
int prepareWrite_PLC_AnIn_3(int16_t value);
 
#define ID_PLC_AnIn_4 5331
extern int16_t PLC_AnIn_4;
int doWrite_PLC_AnIn_4(int16_t value);
int prepareWrite_PLC_AnIn_4(int16_t value);
 
#define ID_PLC_AnIn_5 5332
extern int16_t PLC_AnIn_5;
int doWrite_PLC_AnIn_5(int16_t value);
int prepareWrite_PLC_AnIn_5(int16_t value);
 
#define ID_PLC_Tamb 5333
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int prepareWrite_PLC_Tamb(int16_t value);
 
#define ID_PLC_Encoder 5334
extern u_int32_t PLC_Encoder;
int doWrite_PLC_Encoder(u_int32_t value);
int prepareWrite_PLC_Encoder(u_int32_t value);
 
#define ID_PLC_Capture 5335
extern u_int32_t PLC_Capture;
int doWrite_PLC_Capture(u_int32_t value);
int prepareWrite_PLC_Capture(u_int32_t value);
 
#define ID_PLC_DigOut_1 5336
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int prepareWrite_PLC_DigOut_1(int value);
 
#define ID_PLC_DigOut_2 5337
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int prepareWrite_PLC_DigOut_2(int value);
 
#define ID_PLC_DigOut_3 5338
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int prepareWrite_PLC_DigOut_3(int value);
 
#define ID_PLC_DigOut_4 5339
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int prepareWrite_PLC_DigOut_4(int value);
 
#define ID_PLC_DigOut_5 5340
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int prepareWrite_PLC_DigOut_5(int value);
 
#define ID_PLC_DigOut_6 5341
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int prepareWrite_PLC_DigOut_6(int value);
 
#define ID_PLC_DigOut_7 5342
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int prepareWrite_PLC_DigOut_7(int value);
 
#define ID_PLC_DigOut_8 5343
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int prepareWrite_PLC_DigOut_8(int value);
 
#define ID_PLC_AnOut_1 5344
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int prepareWrite_PLC_AnOut_1(int16_t value);
 
#define ID_PLC_AnOut_2 5345
extern int16_t PLC_AnOut_2;
int doWrite_PLC_AnOut_2(int16_t value);
int prepareWrite_PLC_AnOut_2(int16_t value);
 
#define ID_PLC_AnOut_3 5346
extern int16_t PLC_AnOut_3;
int doWrite_PLC_AnOut_3(int16_t value);
int prepareWrite_PLC_AnOut_3(int16_t value);
 
#define ID_PLC_AnOut_4 5347
extern int16_t PLC_AnOut_4;
int doWrite_PLC_AnOut_4(int16_t value);
int prepareWrite_PLC_AnOut_4(int16_t value);
 
#define ID_PLC_EncoderStart 5348
extern u_int16_t PLC_EncoderStart;
int doWrite_PLC_EncoderStart(u_int16_t value);
int prepareWrite_PLC_EncoderStart(u_int16_t value);
 
#define ID_PLC_EncoderReset 5349
extern u_int16_t PLC_EncoderReset;
int doWrite_PLC_EncoderReset(u_int16_t value);
int prepareWrite_PLC_EncoderReset(u_int16_t value);
 
#define ID_PLC_Heartbeat 5350
extern u_int16_t PLC_Heartbeat;
int doWrite_PLC_Heartbeat(u_int16_t value);
int prepareWrite_PLC_Heartbeat(u_int16_t value);
 
#define ID_PLC_StatusReg 5351
extern u_int16_t PLC_StatusReg;
int doWrite_PLC_StatusReg(u_int16_t value);
int prepareWrite_PLC_StatusReg(u_int16_t value);
 
#define ID_PLC_AnIn1Filter 5352
extern u_int16_t PLC_AnIn1Filter;
int doWrite_PLC_AnIn1Filter(u_int16_t value);
int prepareWrite_PLC_AnIn1Filter(u_int16_t value);
 
#define ID_PLC_AnIn2Filter 5353
extern u_int16_t PLC_AnIn2Filter;
int doWrite_PLC_AnIn2Filter(u_int16_t value);
int prepareWrite_PLC_AnIn2Filter(u_int16_t value);
 
#define ID_PLC_time 5390
extern float PLC_time;
int doWrite_PLC_time(float value);
int prepareWrite_PLC_time(float value);
 
#define ID_PLC_timeMin 5391
extern float PLC_timeMin;
int doWrite_PLC_timeMin(float value);
int prepareWrite_PLC_timeMin(float value);
 
#define ID_PLC_timeMax 5392
extern float PLC_timeMax;
int doWrite_PLC_timeMax(float value);
int prepareWrite_PLC_timeMax(float value);
 
#define ID_PLC_timeWin 5393
extern float PLC_timeWin;
int doWrite_PLC_timeWin(float value);
int prepareWrite_PLC_timeWin(float value);
 
#ifdef __cplusplus
}
#endif
#endif
