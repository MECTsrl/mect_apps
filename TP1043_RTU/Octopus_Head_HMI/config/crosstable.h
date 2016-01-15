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
 
#define ID_GO 193
extern int GO;
int doWrite_GO(int value);
int prepareWrite_GO(int value);
 
#define ID_RESET 3998
extern int RESET;
int doWrite_RESET(int value);
int prepareWrite_RESET(int value);
 
#define ID_START 3999
extern int START;
int doWrite_START(int value);
int prepareWrite_START(int value);
 
#define ID_STOP 4000
extern int STOP;
int doWrite_STOP(int value);
int prepareWrite_STOP(int value);
 
#define ID_TST_DigIn_1 4001
extern int TST_DigIn_1;
int doWrite_TST_DigIn_1(int value);
int prepareWrite_TST_DigIn_1(int value);
 
#define ID_TST_DigIn_2 4002
extern int TST_DigIn_2;
int doWrite_TST_DigIn_2(int value);
int prepareWrite_TST_DigIn_2(int value);
 
#define ID_TST_DigIn_3 4003
extern int TST_DigIn_3;
int doWrite_TST_DigIn_3(int value);
int prepareWrite_TST_DigIn_3(int value);
 
#define ID_TST_DigIn_4 4004
extern int TST_DigIn_4;
int doWrite_TST_DigIn_4(int value);
int prepareWrite_TST_DigIn_4(int value);
 
#define ID_TST_DigIn_5 4005
extern int TST_DigIn_5;
int doWrite_TST_DigIn_5(int value);
int prepareWrite_TST_DigIn_5(int value);
 
#define ID_TST_DigIn_6 4006
extern int TST_DigIn_6;
int doWrite_TST_DigIn_6(int value);
int prepareWrite_TST_DigIn_6(int value);
 
#define ID_TST_DigIn_7 4007
extern int TST_DigIn_7;
int doWrite_TST_DigIn_7(int value);
int prepareWrite_TST_DigIn_7(int value);
 
#define ID_TST_DigIn_8 4008
extern int TST_DigIn_8;
int doWrite_TST_DigIn_8(int value);
int prepareWrite_TST_DigIn_8(int value);
 
#define ID_TST_DigIn_9 4009
extern int TST_DigIn_9;
int doWrite_TST_DigIn_9(int value);
int prepareWrite_TST_DigIn_9(int value);
 
#define ID_TST_DigIn_10 4010
extern int TST_DigIn_10;
int doWrite_TST_DigIn_10(int value);
int prepareWrite_TST_DigIn_10(int value);
 
#define ID_TST_DigIn_11 4011
extern int TST_DigIn_11;
int doWrite_TST_DigIn_11(int value);
int prepareWrite_TST_DigIn_11(int value);
 
#define ID_TST_DigIn_12 4012
extern int TST_DigIn_12;
int doWrite_TST_DigIn_12(int value);
int prepareWrite_TST_DigIn_12(int value);
 
#define ID_TST_DigIn_13 4013
extern int TST_DigIn_13;
int doWrite_TST_DigIn_13(int value);
int prepareWrite_TST_DigIn_13(int value);
 
#define ID_TST_DigIn_14 4014
extern int TST_DigIn_14;
int doWrite_TST_DigIn_14(int value);
int prepareWrite_TST_DigIn_14(int value);
 
#define ID_TST_DigIn_15 4015
extern int TST_DigIn_15;
int doWrite_TST_DigIn_15(int value);
int prepareWrite_TST_DigIn_15(int value);
 
#define ID_TST_DigIn_16 4016
extern int TST_DigIn_16;
int doWrite_TST_DigIn_16(int value);
int prepareWrite_TST_DigIn_16(int value);
 
#define ID_VAL_DigIn_1 4017
extern int VAL_DigIn_1;
int doWrite_VAL_DigIn_1(int value);
int prepareWrite_VAL_DigIn_1(int value);
 
#define ID_VAL_DigIn_2 4018
extern int VAL_DigIn_2;
int doWrite_VAL_DigIn_2(int value);
int prepareWrite_VAL_DigIn_2(int value);
 
#define ID_VAL_DigIn_3 4019
extern int VAL_DigIn_3;
int doWrite_VAL_DigIn_3(int value);
int prepareWrite_VAL_DigIn_3(int value);
 
#define ID_VAL_DigIn_4 4020
extern int VAL_DigIn_4;
int doWrite_VAL_DigIn_4(int value);
int prepareWrite_VAL_DigIn_4(int value);
 
#define ID_VAL_DigIn_5 4021
extern int VAL_DigIn_5;
int doWrite_VAL_DigIn_5(int value);
int prepareWrite_VAL_DigIn_5(int value);
 
#define ID_VAL_DigIn_6 4022
extern int VAL_DigIn_6;
int doWrite_VAL_DigIn_6(int value);
int prepareWrite_VAL_DigIn_6(int value);
 
#define ID_VAL_DigIn_7 4023
extern int VAL_DigIn_7;
int doWrite_VAL_DigIn_7(int value);
int prepareWrite_VAL_DigIn_7(int value);
 
#define ID_VAL_DigIn_8 4024
extern int VAL_DigIn_8;
int doWrite_VAL_DigIn_8(int value);
int prepareWrite_VAL_DigIn_8(int value);
 
#define ID_VAL_DigIn_9 4025
extern int VAL_DigIn_9;
int doWrite_VAL_DigIn_9(int value);
int prepareWrite_VAL_DigIn_9(int value);
 
#define ID_VAL_DigIn_10 4026
extern int VAL_DigIn_10;
int doWrite_VAL_DigIn_10(int value);
int prepareWrite_VAL_DigIn_10(int value);
 
#define ID_VAL_DigIn_11 4027
extern int VAL_DigIn_11;
int doWrite_VAL_DigIn_11(int value);
int prepareWrite_VAL_DigIn_11(int value);
 
#define ID_VAL_DigIn_12 4028
extern int VAL_DigIn_12;
int doWrite_VAL_DigIn_12(int value);
int prepareWrite_VAL_DigIn_12(int value);
 
#define ID_VAL_DigIn_13 4029
extern int VAL_DigIn_13;
int doWrite_VAL_DigIn_13(int value);
int prepareWrite_VAL_DigIn_13(int value);
 
#define ID_VAL_DigIn_14 4030
extern int VAL_DigIn_14;
int doWrite_VAL_DigIn_14(int value);
int prepareWrite_VAL_DigIn_14(int value);
 
#define ID_VAL_DigIn_15 4031
extern int VAL_DigIn_15;
int doWrite_VAL_DigIn_15(int value);
int prepareWrite_VAL_DigIn_15(int value);
 
#define ID_VAL_DigIn_16 4032
extern int VAL_DigIn_16;
int doWrite_VAL_DigIn_16(int value);
int prepareWrite_VAL_DigIn_16(int value);
 
#define ID_RES_DigIn_1 4033
extern int RES_DigIn_1;
int doWrite_RES_DigIn_1(int value);
int prepareWrite_RES_DigIn_1(int value);
 
#define ID_RES_DigIn_2 4034
extern int RES_DigIn_2;
int doWrite_RES_DigIn_2(int value);
int prepareWrite_RES_DigIn_2(int value);
 
#define ID_RES_DigIn_3 4035
extern int RES_DigIn_3;
int doWrite_RES_DigIn_3(int value);
int prepareWrite_RES_DigIn_3(int value);
 
#define ID_RES_DigIn_4 4036
extern int RES_DigIn_4;
int doWrite_RES_DigIn_4(int value);
int prepareWrite_RES_DigIn_4(int value);
 
#define ID_RES_DigIn_5 4037
extern int RES_DigIn_5;
int doWrite_RES_DigIn_5(int value);
int prepareWrite_RES_DigIn_5(int value);
 
#define ID_RES_DigIn_6 4038
extern int RES_DigIn_6;
int doWrite_RES_DigIn_6(int value);
int prepareWrite_RES_DigIn_6(int value);
 
#define ID_RES_DigIn_7 4039
extern int RES_DigIn_7;
int doWrite_RES_DigIn_7(int value);
int prepareWrite_RES_DigIn_7(int value);
 
#define ID_RES_DigIn_8 4040
extern int RES_DigIn_8;
int doWrite_RES_DigIn_8(int value);
int prepareWrite_RES_DigIn_8(int value);
 
#define ID_RES_DigIn_9 4041
extern int RES_DigIn_9;
int doWrite_RES_DigIn_9(int value);
int prepareWrite_RES_DigIn_9(int value);
 
#define ID_RES_DigIn_10 4042
extern int RES_DigIn_10;
int doWrite_RES_DigIn_10(int value);
int prepareWrite_RES_DigIn_10(int value);
 
#define ID_RES_DigIn_11 4043
extern int RES_DigIn_11;
int doWrite_RES_DigIn_11(int value);
int prepareWrite_RES_DigIn_11(int value);
 
#define ID_RES_DigIn_12 4044
extern int RES_DigIn_12;
int doWrite_RES_DigIn_12(int value);
int prepareWrite_RES_DigIn_12(int value);
 
#define ID_RES_DigIn_13 4045
extern int RES_DigIn_13;
int doWrite_RES_DigIn_13(int value);
int prepareWrite_RES_DigIn_13(int value);
 
#define ID_RES_DigIn_14 4046
extern int RES_DigIn_14;
int doWrite_RES_DigIn_14(int value);
int prepareWrite_RES_DigIn_14(int value);
 
#define ID_RES_DigIn_15 4047
extern int RES_DigIn_15;
int doWrite_RES_DigIn_15(int value);
int prepareWrite_RES_DigIn_15(int value);
 
#define ID_RES_DigIn_16 4048
extern int RES_DigIn_16;
int doWrite_RES_DigIn_16(int value);
int prepareWrite_RES_DigIn_16(int value);
 
#define ID_OK_DigIn_1 4049
extern int OK_DigIn_1;
int doWrite_OK_DigIn_1(int value);
int prepareWrite_OK_DigIn_1(int value);
 
#define ID_OK_DigIn_2 4050
extern int OK_DigIn_2;
int doWrite_OK_DigIn_2(int value);
int prepareWrite_OK_DigIn_2(int value);
 
#define ID_OK_DigIn_3 4051
extern int OK_DigIn_3;
int doWrite_OK_DigIn_3(int value);
int prepareWrite_OK_DigIn_3(int value);
 
#define ID_OK_DigIn_4 4052
extern int OK_DigIn_4;
int doWrite_OK_DigIn_4(int value);
int prepareWrite_OK_DigIn_4(int value);
 
#define ID_OK_DigIn_5 4053
extern int OK_DigIn_5;
int doWrite_OK_DigIn_5(int value);
int prepareWrite_OK_DigIn_5(int value);
 
#define ID_OK_DigIn_6 4054
extern int OK_DigIn_6;
int doWrite_OK_DigIn_6(int value);
int prepareWrite_OK_DigIn_6(int value);
 
#define ID_OK_DigIn_7 4055
extern int OK_DigIn_7;
int doWrite_OK_DigIn_7(int value);
int prepareWrite_OK_DigIn_7(int value);
 
#define ID_OK_DigIn_8 4056
extern int OK_DigIn_8;
int doWrite_OK_DigIn_8(int value);
int prepareWrite_OK_DigIn_8(int value);
 
#define ID_OK_DigIn_9 4057
extern int OK_DigIn_9;
int doWrite_OK_DigIn_9(int value);
int prepareWrite_OK_DigIn_9(int value);
 
#define ID_OK_DigIn_10 4058
extern int OK_DigIn_10;
int doWrite_OK_DigIn_10(int value);
int prepareWrite_OK_DigIn_10(int value);
 
#define ID_OK_DigIn_11 4059
extern int OK_DigIn_11;
int doWrite_OK_DigIn_11(int value);
int prepareWrite_OK_DigIn_11(int value);
 
#define ID_OK_DigIn_12 4060
extern int OK_DigIn_12;
int doWrite_OK_DigIn_12(int value);
int prepareWrite_OK_DigIn_12(int value);
 
#define ID_OK_DigIn_13 4061
extern int OK_DigIn_13;
int doWrite_OK_DigIn_13(int value);
int prepareWrite_OK_DigIn_13(int value);
 
#define ID_OK_DigIn_14 4062
extern int OK_DigIn_14;
int doWrite_OK_DigIn_14(int value);
int prepareWrite_OK_DigIn_14(int value);
 
#define ID_OK_DigIn_15 4063
extern int OK_DigIn_15;
int doWrite_OK_DigIn_15(int value);
int prepareWrite_OK_DigIn_15(int value);
 
#define ID_OK_DigIn_16 4064
extern int OK_DigIn_16;
int doWrite_OK_DigIn_16(int value);
int prepareWrite_OK_DigIn_16(int value);
 
#define ID_TST_DigOut_1 4065
extern int TST_DigOut_1;
int doWrite_TST_DigOut_1(int value);
int prepareWrite_TST_DigOut_1(int value);
 
#define ID_TST_DigOut_2 4066
extern int TST_DigOut_2;
int doWrite_TST_DigOut_2(int value);
int prepareWrite_TST_DigOut_2(int value);
 
#define ID_TST_DigOut_3 4067
extern int TST_DigOut_3;
int doWrite_TST_DigOut_3(int value);
int prepareWrite_TST_DigOut_3(int value);
 
#define ID_TST_DigOut_4 4068
extern int TST_DigOut_4;
int doWrite_TST_DigOut_4(int value);
int prepareWrite_TST_DigOut_4(int value);
 
#define ID_TST_DigOut_5 4069
extern int TST_DigOut_5;
int doWrite_TST_DigOut_5(int value);
int prepareWrite_TST_DigOut_5(int value);
 
#define ID_TST_DigOut_6 4070
extern int TST_DigOut_6;
int doWrite_TST_DigOut_6(int value);
int prepareWrite_TST_DigOut_6(int value);
 
#define ID_TST_DigOut_7 4071
extern int TST_DigOut_7;
int doWrite_TST_DigOut_7(int value);
int prepareWrite_TST_DigOut_7(int value);
 
#define ID_TST_DigOut_8 4072
extern int TST_DigOut_8;
int doWrite_TST_DigOut_8(int value);
int prepareWrite_TST_DigOut_8(int value);
 
#define ID_TST_DigOut_9 4073
extern int TST_DigOut_9;
int doWrite_TST_DigOut_9(int value);
int prepareWrite_TST_DigOut_9(int value);
 
#define ID_TST_DigOut_10 4074
extern int TST_DigOut_10;
int doWrite_TST_DigOut_10(int value);
int prepareWrite_TST_DigOut_10(int value);
 
#define ID_TST_DigOut_11 4075
extern int TST_DigOut_11;
int doWrite_TST_DigOut_11(int value);
int prepareWrite_TST_DigOut_11(int value);
 
#define ID_TST_DigOut_12 4076
extern int TST_DigOut_12;
int doWrite_TST_DigOut_12(int value);
int prepareWrite_TST_DigOut_12(int value);
 
#define ID_TST_DigOut_13 4077
extern int TST_DigOut_13;
int doWrite_TST_DigOut_13(int value);
int prepareWrite_TST_DigOut_13(int value);
 
#define ID_TST_DigOut_14 4078
extern int TST_DigOut_14;
int doWrite_TST_DigOut_14(int value);
int prepareWrite_TST_DigOut_14(int value);
 
#define ID_TST_DigOut_15 4079
extern int TST_DigOut_15;
int doWrite_TST_DigOut_15(int value);
int prepareWrite_TST_DigOut_15(int value);
 
#define ID_TST_DigOut_16 4080
extern int TST_DigOut_16;
int doWrite_TST_DigOut_16(int value);
int prepareWrite_TST_DigOut_16(int value);
 
#define ID_VAL_DigOut_1 4081
extern int VAL_DigOut_1;
int doWrite_VAL_DigOut_1(int value);
int prepareWrite_VAL_DigOut_1(int value);
 
#define ID_VAL_DigOut_2 4082
extern int VAL_DigOut_2;
int doWrite_VAL_DigOut_2(int value);
int prepareWrite_VAL_DigOut_2(int value);
 
#define ID_VAL_DigOut_3 4083
extern int VAL_DigOut_3;
int doWrite_VAL_DigOut_3(int value);
int prepareWrite_VAL_DigOut_3(int value);
 
#define ID_VAL_DigOut_4 4084
extern int VAL_DigOut_4;
int doWrite_VAL_DigOut_4(int value);
int prepareWrite_VAL_DigOut_4(int value);
 
#define ID_VAL_DigOut_5 4085
extern int VAL_DigOut_5;
int doWrite_VAL_DigOut_5(int value);
int prepareWrite_VAL_DigOut_5(int value);
 
#define ID_VAL_DigOut_6 4086
extern int VAL_DigOut_6;
int doWrite_VAL_DigOut_6(int value);
int prepareWrite_VAL_DigOut_6(int value);
 
#define ID_VAL_DigOut_7 4087
extern int VAL_DigOut_7;
int doWrite_VAL_DigOut_7(int value);
int prepareWrite_VAL_DigOut_7(int value);
 
#define ID_VAL_DigOut_8 4088
extern int VAL_DigOut_8;
int doWrite_VAL_DigOut_8(int value);
int prepareWrite_VAL_DigOut_8(int value);
 
#define ID_VAL_DigOut_9 4089
extern int VAL_DigOut_9;
int doWrite_VAL_DigOut_9(int value);
int prepareWrite_VAL_DigOut_9(int value);
 
#define ID_VAL_DigOut_10 4090
extern int VAL_DigOut_10;
int doWrite_VAL_DigOut_10(int value);
int prepareWrite_VAL_DigOut_10(int value);
 
#define ID_VAL_DigOut_11 4091
extern int VAL_DigOut_11;
int doWrite_VAL_DigOut_11(int value);
int prepareWrite_VAL_DigOut_11(int value);
 
#define ID_VAL_DigOut_12 4092
extern int VAL_DigOut_12;
int doWrite_VAL_DigOut_12(int value);
int prepareWrite_VAL_DigOut_12(int value);
 
#define ID_VAL_DigOut_13 4093
extern int VAL_DigOut_13;
int doWrite_VAL_DigOut_13(int value);
int prepareWrite_VAL_DigOut_13(int value);
 
#define ID_VAL_DigOut_14 4094
extern int VAL_DigOut_14;
int doWrite_VAL_DigOut_14(int value);
int prepareWrite_VAL_DigOut_14(int value);
 
#define ID_VAL_DigOut_15 4095
extern int VAL_DigOut_15;
int doWrite_VAL_DigOut_15(int value);
int prepareWrite_VAL_DigOut_15(int value);
 
#define ID_VAL_DigOut_16 4096
extern int VAL_DigOut_16;
int doWrite_VAL_DigOut_16(int value);
int prepareWrite_VAL_DigOut_16(int value);
 
#define ID_RES_DigOut_1 4097
extern int RES_DigOut_1;
int doWrite_RES_DigOut_1(int value);
int prepareWrite_RES_DigOut_1(int value);
 
#define ID_RES_DigOut_2 4098
extern int RES_DigOut_2;
int doWrite_RES_DigOut_2(int value);
int prepareWrite_RES_DigOut_2(int value);
 
#define ID_RES_DigOut_3 4099
extern int RES_DigOut_3;
int doWrite_RES_DigOut_3(int value);
int prepareWrite_RES_DigOut_3(int value);
 
#define ID_RES_DigOut_4 4100
extern int RES_DigOut_4;
int doWrite_RES_DigOut_4(int value);
int prepareWrite_RES_DigOut_4(int value);
 
#define ID_RES_DigOut_5 4101
extern int RES_DigOut_5;
int doWrite_RES_DigOut_5(int value);
int prepareWrite_RES_DigOut_5(int value);
 
#define ID_RES_DigOut_6 4102
extern int RES_DigOut_6;
int doWrite_RES_DigOut_6(int value);
int prepareWrite_RES_DigOut_6(int value);
 
#define ID_RES_DigOut_7 4103
extern int RES_DigOut_7;
int doWrite_RES_DigOut_7(int value);
int prepareWrite_RES_DigOut_7(int value);
 
#define ID_RES_DigOut_8 4104
extern int RES_DigOut_8;
int doWrite_RES_DigOut_8(int value);
int prepareWrite_RES_DigOut_8(int value);
 
#define ID_RES_DigOut_9 4105
extern int RES_DigOut_9;
int doWrite_RES_DigOut_9(int value);
int prepareWrite_RES_DigOut_9(int value);
 
#define ID_RES_DigOut_10 4106
extern int RES_DigOut_10;
int doWrite_RES_DigOut_10(int value);
int prepareWrite_RES_DigOut_10(int value);
 
#define ID_RES_DigOut_11 4107
extern int RES_DigOut_11;
int doWrite_RES_DigOut_11(int value);
int prepareWrite_RES_DigOut_11(int value);
 
#define ID_RES_DigOut_12 4108
extern int RES_DigOut_12;
int doWrite_RES_DigOut_12(int value);
int prepareWrite_RES_DigOut_12(int value);
 
#define ID_RES_DigOut_13 4109
extern int RES_DigOut_13;
int doWrite_RES_DigOut_13(int value);
int prepareWrite_RES_DigOut_13(int value);
 
#define ID_RES_DigOut_14 4110
extern int RES_DigOut_14;
int doWrite_RES_DigOut_14(int value);
int prepareWrite_RES_DigOut_14(int value);
 
#define ID_RES_DigOut_15 4111
extern int RES_DigOut_15;
int doWrite_RES_DigOut_15(int value);
int prepareWrite_RES_DigOut_15(int value);
 
#define ID_RES_DigOut_16 4112
extern int RES_DigOut_16;
int doWrite_RES_DigOut_16(int value);
int prepareWrite_RES_DigOut_16(int value);
 
#define ID_OK_DigOut_1 4113
extern int OK_DigOut_1;
int doWrite_OK_DigOut_1(int value);
int prepareWrite_OK_DigOut_1(int value);
 
#define ID_OK_DigOut_2 4114
extern int OK_DigOut_2;
int doWrite_OK_DigOut_2(int value);
int prepareWrite_OK_DigOut_2(int value);
 
#define ID_OK_DigOut_3 4115
extern int OK_DigOut_3;
int doWrite_OK_DigOut_3(int value);
int prepareWrite_OK_DigOut_3(int value);
 
#define ID_OK_DigOut_4 4116
extern int OK_DigOut_4;
int doWrite_OK_DigOut_4(int value);
int prepareWrite_OK_DigOut_4(int value);
 
#define ID_OK_DigOut_5 4117
extern int OK_DigOut_5;
int doWrite_OK_DigOut_5(int value);
int prepareWrite_OK_DigOut_5(int value);
 
#define ID_OK_DigOut_6 4118
extern int OK_DigOut_6;
int doWrite_OK_DigOut_6(int value);
int prepareWrite_OK_DigOut_6(int value);
 
#define ID_OK_DigOut_7 4119
extern int OK_DigOut_7;
int doWrite_OK_DigOut_7(int value);
int prepareWrite_OK_DigOut_7(int value);
 
#define ID_OK_DigOut_8 4120
extern int OK_DigOut_8;
int doWrite_OK_DigOut_8(int value);
int prepareWrite_OK_DigOut_8(int value);
 
#define ID_OK_DigOut_9 4121
extern int OK_DigOut_9;
int doWrite_OK_DigOut_9(int value);
int prepareWrite_OK_DigOut_9(int value);
 
#define ID_OK_DigOut_10 4122
extern int OK_DigOut_10;
int doWrite_OK_DigOut_10(int value);
int prepareWrite_OK_DigOut_10(int value);
 
#define ID_OK_DigOut_11 4123
extern int OK_DigOut_11;
int doWrite_OK_DigOut_11(int value);
int prepareWrite_OK_DigOut_11(int value);
 
#define ID_OK_DigOut_12 4124
extern int OK_DigOut_12;
int doWrite_OK_DigOut_12(int value);
int prepareWrite_OK_DigOut_12(int value);
 
#define ID_OK_DigOut_13 4125
extern int OK_DigOut_13;
int doWrite_OK_DigOut_13(int value);
int prepareWrite_OK_DigOut_13(int value);
 
#define ID_OK_DigOut_14 4126
extern int OK_DigOut_14;
int doWrite_OK_DigOut_14(int value);
int prepareWrite_OK_DigOut_14(int value);
 
#define ID_OK_DigOut_15 4127
extern int OK_DigOut_15;
int doWrite_OK_DigOut_15(int value);
int prepareWrite_OK_DigOut_15(int value);
 
#define ID_OK_DigOut_16 4128
extern int OK_DigOut_16;
int doWrite_OK_DigOut_16(int value);
int prepareWrite_OK_DigOut_16(int value);
 
#define ID_TST_AnIn_1 4129
extern int TST_AnIn_1;
int doWrite_TST_AnIn_1(int value);
int prepareWrite_TST_AnIn_1(int value);
 
#define ID_TST_AnIn_2 4130
extern int TST_AnIn_2;
int doWrite_TST_AnIn_2(int value);
int prepareWrite_TST_AnIn_2(int value);
 
#define ID_TST_AnIn_3 4131
extern int TST_AnIn_3;
int doWrite_TST_AnIn_3(int value);
int prepareWrite_TST_AnIn_3(int value);
 
#define ID_TST_AnIn_4 4132
extern int TST_AnIn_4;
int doWrite_TST_AnIn_4(int value);
int prepareWrite_TST_AnIn_4(int value);
 
#define ID_TST_AnIn_5 4133
extern int TST_AnIn_5;
int doWrite_TST_AnIn_5(int value);
int prepareWrite_TST_AnIn_5(int value);
 
#define ID_TST_AnIn_6 4134
extern int TST_AnIn_6;
int doWrite_TST_AnIn_6(int value);
int prepareWrite_TST_AnIn_6(int value);
 
#define ID_TST_AnIn_7 4135
extern int TST_AnIn_7;
int doWrite_TST_AnIn_7(int value);
int prepareWrite_TST_AnIn_7(int value);
 
#define ID_TST_AnIn_8 4136
extern int TST_AnIn_8;
int doWrite_TST_AnIn_8(int value);
int prepareWrite_TST_AnIn_8(int value);
 
#define ID_TST_AnIn_9 4137
extern int TST_AnIn_9;
int doWrite_TST_AnIn_9(int value);
int prepareWrite_TST_AnIn_9(int value);
 
#define ID_TST_AnIn_10 4138
extern int TST_AnIn_10;
int doWrite_TST_AnIn_10(int value);
int prepareWrite_TST_AnIn_10(int value);
 
#define ID_TST_AnIn_11 4139
extern int TST_AnIn_11;
int doWrite_TST_AnIn_11(int value);
int prepareWrite_TST_AnIn_11(int value);
 
#define ID_TST_AnIn_12 4140
extern int TST_AnIn_12;
int doWrite_TST_AnIn_12(int value);
int prepareWrite_TST_AnIn_12(int value);
 
#define ID_VAL_AnIn_1 4141
extern int16_t VAL_AnIn_1;
int doWrite_VAL_AnIn_1(int16_t value);
int prepareWrite_VAL_AnIn_1(int16_t value);
 
#define ID_VAL_AnIn_2 4142
extern int16_t VAL_AnIn_2;
int doWrite_VAL_AnIn_2(int16_t value);
int prepareWrite_VAL_AnIn_2(int16_t value);
 
#define ID_VAL_AnIn_3 4143
extern int16_t VAL_AnIn_3;
int doWrite_VAL_AnIn_3(int16_t value);
int prepareWrite_VAL_AnIn_3(int16_t value);
 
#define ID_VAL_AnIn_4 4144
extern int16_t VAL_AnIn_4;
int doWrite_VAL_AnIn_4(int16_t value);
int prepareWrite_VAL_AnIn_4(int16_t value);
 
#define ID_VAL_AnIn_5 4145
extern int16_t VAL_AnIn_5;
int doWrite_VAL_AnIn_5(int16_t value);
int prepareWrite_VAL_AnIn_5(int16_t value);
 
#define ID_VAL_AnIn_6 4146
extern int16_t VAL_AnIn_6;
int doWrite_VAL_AnIn_6(int16_t value);
int prepareWrite_VAL_AnIn_6(int16_t value);
 
#define ID_VAL_AnIn_7 4147
extern int16_t VAL_AnIn_7;
int doWrite_VAL_AnIn_7(int16_t value);
int prepareWrite_VAL_AnIn_7(int16_t value);
 
#define ID_VAL_AnIn_8 4148
extern int16_t VAL_AnIn_8;
int doWrite_VAL_AnIn_8(int16_t value);
int prepareWrite_VAL_AnIn_8(int16_t value);
 
#define ID_VAL_AnIn_9 4149
extern int16_t VAL_AnIn_9;
int doWrite_VAL_AnIn_9(int16_t value);
int prepareWrite_VAL_AnIn_9(int16_t value);
 
#define ID_VAL_AnIn_10 4150
extern int16_t VAL_AnIn_10;
int doWrite_VAL_AnIn_10(int16_t value);
int prepareWrite_VAL_AnIn_10(int16_t value);
 
#define ID_VAL_AnIn_11 4151
extern int16_t VAL_AnIn_11;
int doWrite_VAL_AnIn_11(int16_t value);
int prepareWrite_VAL_AnIn_11(int16_t value);
 
#define ID_VAL_AnIn_12 4152
extern int16_t VAL_AnIn_12;
int doWrite_VAL_AnIn_12(int16_t value);
int prepareWrite_VAL_AnIn_12(int16_t value);
 
#define ID_VAL_AnInConf_1 4153
extern u_int16_t VAL_AnInConf_1;
int doWrite_VAL_AnInConf_1(u_int16_t value);
int prepareWrite_VAL_AnInConf_1(u_int16_t value);
 
#define ID_VAL_AnInConf_2 4154
extern u_int16_t VAL_AnInConf_2;
int doWrite_VAL_AnInConf_2(u_int16_t value);
int prepareWrite_VAL_AnInConf_2(u_int16_t value);
 
#define ID_VAL_AnInConf_3 4155
extern u_int16_t VAL_AnInConf_3;
int doWrite_VAL_AnInConf_3(u_int16_t value);
int prepareWrite_VAL_AnInConf_3(u_int16_t value);
 
#define ID_VAL_AnInConf_4 4156
extern u_int16_t VAL_AnInConf_4;
int doWrite_VAL_AnInConf_4(u_int16_t value);
int prepareWrite_VAL_AnInConf_4(u_int16_t value);
 
#define ID_VAL_AnInConf_5 4157
extern u_int16_t VAL_AnInConf_5;
int doWrite_VAL_AnInConf_5(u_int16_t value);
int prepareWrite_VAL_AnInConf_5(u_int16_t value);
 
#define ID_VAL_AnInConf_6 4158
extern u_int16_t VAL_AnInConf_6;
int doWrite_VAL_AnInConf_6(u_int16_t value);
int prepareWrite_VAL_AnInConf_6(u_int16_t value);
 
#define ID_VAL_AnInConf_7 4159
extern u_int16_t VAL_AnInConf_7;
int doWrite_VAL_AnInConf_7(u_int16_t value);
int prepareWrite_VAL_AnInConf_7(u_int16_t value);
 
#define ID_VAL_AnInConf_8 4160
extern u_int16_t VAL_AnInConf_8;
int doWrite_VAL_AnInConf_8(u_int16_t value);
int prepareWrite_VAL_AnInConf_8(u_int16_t value);
 
#define ID_VAL_AnInConf_9 4161
extern u_int16_t VAL_AnInConf_9;
int doWrite_VAL_AnInConf_9(u_int16_t value);
int prepareWrite_VAL_AnInConf_9(u_int16_t value);
 
#define ID_VAL_AnInConf_10 4162
extern u_int16_t VAL_AnInConf_10;
int doWrite_VAL_AnInConf_10(u_int16_t value);
int prepareWrite_VAL_AnInConf_10(u_int16_t value);
 
#define ID_VAL_AnInConf_11 4163
extern u_int16_t VAL_AnInConf_11;
int doWrite_VAL_AnInConf_11(u_int16_t value);
int prepareWrite_VAL_AnInConf_11(u_int16_t value);
 
#define ID_VAL_AnInConf_12 4164
extern u_int16_t VAL_AnInConf_12;
int doWrite_VAL_AnInConf_12(u_int16_t value);
int prepareWrite_VAL_AnInConf_12(u_int16_t value);
 
#define ID_RES_AnIn_1 4165
extern int16_t RES_AnIn_1;
int doWrite_RES_AnIn_1(int16_t value);
int prepareWrite_RES_AnIn_1(int16_t value);
 
#define ID_RES_AnIn_2 4166
extern int16_t RES_AnIn_2;
int doWrite_RES_AnIn_2(int16_t value);
int prepareWrite_RES_AnIn_2(int16_t value);
 
#define ID_RES_AnIn_3 4167
extern int16_t RES_AnIn_3;
int doWrite_RES_AnIn_3(int16_t value);
int prepareWrite_RES_AnIn_3(int16_t value);
 
#define ID_RES_AnIn_4 4168
extern int16_t RES_AnIn_4;
int doWrite_RES_AnIn_4(int16_t value);
int prepareWrite_RES_AnIn_4(int16_t value);
 
#define ID_RES_AnIn_5 4169
extern int16_t RES_AnIn_5;
int doWrite_RES_AnIn_5(int16_t value);
int prepareWrite_RES_AnIn_5(int16_t value);
 
#define ID_RES_AnIn_6 4170
extern int16_t RES_AnIn_6;
int doWrite_RES_AnIn_6(int16_t value);
int prepareWrite_RES_AnIn_6(int16_t value);
 
#define ID_RES_AnIn_7 4171
extern int16_t RES_AnIn_7;
int doWrite_RES_AnIn_7(int16_t value);
int prepareWrite_RES_AnIn_7(int16_t value);
 
#define ID_RES_AnIn_8 4172
extern int16_t RES_AnIn_8;
int doWrite_RES_AnIn_8(int16_t value);
int prepareWrite_RES_AnIn_8(int16_t value);
 
#define ID_RES_AnIn_9 4173
extern int16_t RES_AnIn_9;
int doWrite_RES_AnIn_9(int16_t value);
int prepareWrite_RES_AnIn_9(int16_t value);
 
#define ID_RES_AnIn_10 4174
extern int16_t RES_AnIn_10;
int doWrite_RES_AnIn_10(int16_t value);
int prepareWrite_RES_AnIn_10(int16_t value);
 
#define ID_RES_AnIn_11 4175
extern int16_t RES_AnIn_11;
int doWrite_RES_AnIn_11(int16_t value);
int prepareWrite_RES_AnIn_11(int16_t value);
 
#define ID_RES_AnIn_12 4176
extern int16_t RES_AnIn_12;
int doWrite_RES_AnIn_12(int16_t value);
int prepareWrite_RES_AnIn_12(int16_t value);
 
#define ID_OK_AnIn_1 4177
extern int16_t OK_AnIn_1;
int doWrite_OK_AnIn_1(int16_t value);
int prepareWrite_OK_AnIn_1(int16_t value);
 
#define ID_OK_AnIn_2 4178
extern int16_t OK_AnIn_2;
int doWrite_OK_AnIn_2(int16_t value);
int prepareWrite_OK_AnIn_2(int16_t value);
 
#define ID_OK_AnIn_3 4179
extern int16_t OK_AnIn_3;
int doWrite_OK_AnIn_3(int16_t value);
int prepareWrite_OK_AnIn_3(int16_t value);
 
#define ID_OK_AnIn_4 4180
extern int16_t OK_AnIn_4;
int doWrite_OK_AnIn_4(int16_t value);
int prepareWrite_OK_AnIn_4(int16_t value);
 
#define ID_OK_AnIn_5 4181
extern int16_t OK_AnIn_5;
int doWrite_OK_AnIn_5(int16_t value);
int prepareWrite_OK_AnIn_5(int16_t value);
 
#define ID_OK_AnIn_6 4182
extern int16_t OK_AnIn_6;
int doWrite_OK_AnIn_6(int16_t value);
int prepareWrite_OK_AnIn_6(int16_t value);
 
#define ID_OK_AnIn_7 4183
extern int16_t OK_AnIn_7;
int doWrite_OK_AnIn_7(int16_t value);
int prepareWrite_OK_AnIn_7(int16_t value);
 
#define ID_OK_AnIn_8 4184
extern int16_t OK_AnIn_8;
int doWrite_OK_AnIn_8(int16_t value);
int prepareWrite_OK_AnIn_8(int16_t value);
 
#define ID_OK_AnIn_9 4185
extern int16_t OK_AnIn_9;
int doWrite_OK_AnIn_9(int16_t value);
int prepareWrite_OK_AnIn_9(int16_t value);
 
#define ID_OK_AnIn_10 4186
extern int16_t OK_AnIn_10;
int doWrite_OK_AnIn_10(int16_t value);
int prepareWrite_OK_AnIn_10(int16_t value);
 
#define ID_OK_AnIn_11 4187
extern int16_t OK_AnIn_11;
int doWrite_OK_AnIn_11(int16_t value);
int prepareWrite_OK_AnIn_11(int16_t value);
 
#define ID_OK_AnIn_12 4188
extern int16_t OK_AnIn_12;
int doWrite_OK_AnIn_12(int16_t value);
int prepareWrite_OK_AnIn_12(int16_t value);
 
#define ID_TST_AnOut_1 4189
extern int TST_AnOut_1;
int doWrite_TST_AnOut_1(int value);
int prepareWrite_TST_AnOut_1(int value);
 
#define ID_TST_AnOut_2 4190
extern int TST_AnOut_2;
int doWrite_TST_AnOut_2(int value);
int prepareWrite_TST_AnOut_2(int value);
 
#define ID_TST_AnOut_3 4191
extern int TST_AnOut_3;
int doWrite_TST_AnOut_3(int value);
int prepareWrite_TST_AnOut_3(int value);
 
#define ID_TST_AnOut_4 4192
extern int TST_AnOut_4;
int doWrite_TST_AnOut_4(int value);
int prepareWrite_TST_AnOut_4(int value);
 
#define ID_TST_AnOut_5 4193
extern int TST_AnOut_5;
int doWrite_TST_AnOut_5(int value);
int prepareWrite_TST_AnOut_5(int value);
 
#define ID_TST_AnOut_6 4194
extern int TST_AnOut_6;
int doWrite_TST_AnOut_6(int value);
int prepareWrite_TST_AnOut_6(int value);
 
#define ID_TST_AnOut_7 4195
extern int TST_AnOut_7;
int doWrite_TST_AnOut_7(int value);
int prepareWrite_TST_AnOut_7(int value);
 
#define ID_TST_AnOut_8 4196
extern int TST_AnOut_8;
int doWrite_TST_AnOut_8(int value);
int prepareWrite_TST_AnOut_8(int value);
 
#define ID_VAL_AnOut_1 4197
extern int16_t VAL_AnOut_1;
int doWrite_VAL_AnOut_1(int16_t value);
int prepareWrite_VAL_AnOut_1(int16_t value);
 
#define ID_VAL_AnOut_2 4198
extern int16_t VAL_AnOut_2;
int doWrite_VAL_AnOut_2(int16_t value);
int prepareWrite_VAL_AnOut_2(int16_t value);
 
#define ID_VAL_AnOut_3 4199
extern int16_t VAL_AnOut_3;
int doWrite_VAL_AnOut_3(int16_t value);
int prepareWrite_VAL_AnOut_3(int16_t value);
 
#define ID_VAL_AnOut_4 4200
extern int16_t VAL_AnOut_4;
int doWrite_VAL_AnOut_4(int16_t value);
int prepareWrite_VAL_AnOut_4(int16_t value);
 
#define ID_VAL_AnOut_5 4201
extern int16_t VAL_AnOut_5;
int doWrite_VAL_AnOut_5(int16_t value);
int prepareWrite_VAL_AnOut_5(int16_t value);
 
#define ID_VAL_AnOut_6 4202
extern int16_t VAL_AnOut_6;
int doWrite_VAL_AnOut_6(int16_t value);
int prepareWrite_VAL_AnOut_6(int16_t value);
 
#define ID_VAL_AnOut_7 4203
extern int16_t VAL_AnOut_7;
int doWrite_VAL_AnOut_7(int16_t value);
int prepareWrite_VAL_AnOut_7(int16_t value);
 
#define ID_VAL_AnOut_8 4204
extern int16_t VAL_AnOut_8;
int doWrite_VAL_AnOut_8(int16_t value);
int prepareWrite_VAL_AnOut_8(int16_t value);
 
#define ID_VAL_AnOutConf_1 4205
extern u_int16_t VAL_AnOutConf_1;
int doWrite_VAL_AnOutConf_1(u_int16_t value);
int prepareWrite_VAL_AnOutConf_1(u_int16_t value);
 
#define ID_VAL_AnOutConf_2 4206
extern u_int16_t VAL_AnOutConf_2;
int doWrite_VAL_AnOutConf_2(u_int16_t value);
int prepareWrite_VAL_AnOutConf_2(u_int16_t value);
 
#define ID_VAL_AnOutConf_3 4207
extern u_int16_t VAL_AnOutConf_3;
int doWrite_VAL_AnOutConf_3(u_int16_t value);
int prepareWrite_VAL_AnOutConf_3(u_int16_t value);
 
#define ID_VAL_AnOutConf_4 4208
extern u_int16_t VAL_AnOutConf_4;
int doWrite_VAL_AnOutConf_4(u_int16_t value);
int prepareWrite_VAL_AnOutConf_4(u_int16_t value);
 
#define ID_VAL_AnOutConf_5 4209
extern u_int16_t VAL_AnOutConf_5;
int doWrite_VAL_AnOutConf_5(u_int16_t value);
int prepareWrite_VAL_AnOutConf_5(u_int16_t value);
 
#define ID_VAL_AnOutConf_6 4210
extern u_int16_t VAL_AnOutConf_6;
int doWrite_VAL_AnOutConf_6(u_int16_t value);
int prepareWrite_VAL_AnOutConf_6(u_int16_t value);
 
#define ID_VAL_AnOutConf_7 4211
extern u_int16_t VAL_AnOutConf_7;
int doWrite_VAL_AnOutConf_7(u_int16_t value);
int prepareWrite_VAL_AnOutConf_7(u_int16_t value);
 
#define ID_VAL_AnOutConf_8 4212
extern u_int16_t VAL_AnOutConf_8;
int doWrite_VAL_AnOutConf_8(u_int16_t value);
int prepareWrite_VAL_AnOutConf_8(u_int16_t value);
 
#define ID_RES_AnOut_1 4213
extern int16_t RES_AnOut_1;
int doWrite_RES_AnOut_1(int16_t value);
int prepareWrite_RES_AnOut_1(int16_t value);
 
#define ID_RES_AnOut_2 4214
extern int16_t RES_AnOut_2;
int doWrite_RES_AnOut_2(int16_t value);
int prepareWrite_RES_AnOut_2(int16_t value);
 
#define ID_RES_AnOut_3 4215
extern int16_t RES_AnOut_3;
int doWrite_RES_AnOut_3(int16_t value);
int prepareWrite_RES_AnOut_3(int16_t value);
 
#define ID_RES_AnOut_4 4216
extern int16_t RES_AnOut_4;
int doWrite_RES_AnOut_4(int16_t value);
int prepareWrite_RES_AnOut_4(int16_t value);
 
#define ID_RES_AnOut_5 4217
extern int16_t RES_AnOut_5;
int doWrite_RES_AnOut_5(int16_t value);
int prepareWrite_RES_AnOut_5(int16_t value);
 
#define ID_RES_AnOut_6 4218
extern int16_t RES_AnOut_6;
int doWrite_RES_AnOut_6(int16_t value);
int prepareWrite_RES_AnOut_6(int16_t value);
 
#define ID_RES_AnOut_7 4219
extern int16_t RES_AnOut_7;
int doWrite_RES_AnOut_7(int16_t value);
int prepareWrite_RES_AnOut_7(int16_t value);
 
#define ID_RES_AnOut_8 4220
extern int16_t RES_AnOut_8;
int doWrite_RES_AnOut_8(int16_t value);
int prepareWrite_RES_AnOut_8(int16_t value);
 
#define ID_OK_AnOut_1 4221
extern int16_t OK_AnOut_1;
int doWrite_OK_AnOut_1(int16_t value);
int prepareWrite_OK_AnOut_1(int16_t value);
 
#define ID_OK_AnOut_2 4222
extern int16_t OK_AnOut_2;
int doWrite_OK_AnOut_2(int16_t value);
int prepareWrite_OK_AnOut_2(int16_t value);
 
#define ID_OK_AnOut_3 4223
extern int16_t OK_AnOut_3;
int doWrite_OK_AnOut_3(int16_t value);
int prepareWrite_OK_AnOut_3(int16_t value);
 
#define ID_OK_AnOut_4 4224
extern int16_t OK_AnOut_4;
int doWrite_OK_AnOut_4(int16_t value);
int prepareWrite_OK_AnOut_4(int16_t value);
 
#define ID_OK_AnOut_5 4225
extern int16_t OK_AnOut_5;
int doWrite_OK_AnOut_5(int16_t value);
int prepareWrite_OK_AnOut_5(int16_t value);
 
#define ID_OK_AnOut_6 4226
extern int16_t OK_AnOut_6;
int doWrite_OK_AnOut_6(int16_t value);
int prepareWrite_OK_AnOut_6(int16_t value);
 
#define ID_OK_AnOut_7 4227
extern int16_t OK_AnOut_7;
int doWrite_OK_AnOut_7(int16_t value);
int prepareWrite_OK_AnOut_7(int16_t value);
 
#define ID_OK_AnOut_8 4228
extern int16_t OK_AnOut_8;
int doWrite_OK_AnOut_8(int16_t value);
int prepareWrite_OK_AnOut_8(int16_t value);
 
#define ID_TST_Tamb 4229
extern int TST_Tamb;
int doWrite_TST_Tamb(int value);
int prepareWrite_TST_Tamb(int value);
 
#define ID_TST_RPM 4230
extern int TST_RPM;
int doWrite_TST_RPM(int value);
int prepareWrite_TST_RPM(int value);
 
#define ID_TST_VCC_set 4231
extern int TST_VCC_set;
int doWrite_TST_VCC_set(int value);
int prepareWrite_TST_VCC_set(int value);
 
#define ID_TST_VCC_fbk 4232
extern int TST_VCC_fbk;
int doWrite_TST_VCC_fbk(int value);
int prepareWrite_TST_VCC_fbk(int value);
 
#define ID_TST_mA_fbk 4233
extern int TST_mA_fbk;
int doWrite_TST_mA_fbk(int value);
int prepareWrite_TST_mA_fbk(int value);
 
#define ID_TST_FWrevision 4234
extern int TST_FWrevision;
int doWrite_TST_FWrevision(int value);
int prepareWrite_TST_FWrevision(int value);
 
#define ID_TST_HWconfig 4235
extern int TST_HWconfig;
int doWrite_TST_HWconfig(int value);
int prepareWrite_TST_HWconfig(int value);
 
#define ID_VAL_Tamb 4236
extern int16_t VAL_Tamb;
int doWrite_VAL_Tamb(int16_t value);
int prepareWrite_VAL_Tamb(int16_t value);
 
#define ID_VAL_RPM 4237
extern u_int16_t VAL_RPM;
int doWrite_VAL_RPM(u_int16_t value);
int prepareWrite_VAL_RPM(u_int16_t value);
 
#define ID_VAL_VCC_set 4238
extern int16_t VAL_VCC_set;
int doWrite_VAL_VCC_set(int16_t value);
int prepareWrite_VAL_VCC_set(int16_t value);
 
#define ID_VAL_VCC_fbk 4239
extern int16_t VAL_VCC_fbk;
int doWrite_VAL_VCC_fbk(int16_t value);
int prepareWrite_VAL_VCC_fbk(int16_t value);
 
#define ID_VAL_mA_fbk 4240
extern int16_t VAL_mA_fbk;
int doWrite_VAL_mA_fbk(int16_t value);
int prepareWrite_VAL_mA_fbk(int16_t value);
 
#define ID_VAL_FWrevision 4241
extern u_int16_t VAL_FWrevision;
int doWrite_VAL_FWrevision(u_int16_t value);
int prepareWrite_VAL_FWrevision(u_int16_t value);
 
#define ID_VAL_HWconfig 4242
extern u_int16_t VAL_HWconfig;
int doWrite_VAL_HWconfig(u_int16_t value);
int prepareWrite_VAL_HWconfig(u_int16_t value);
 
#define ID_RES_Tamb 4243
extern int16_t RES_Tamb;
int doWrite_RES_Tamb(int16_t value);
int prepareWrite_RES_Tamb(int16_t value);
 
#define ID_RES_RPM 4244
extern u_int16_t RES_RPM;
int doWrite_RES_RPM(u_int16_t value);
int prepareWrite_RES_RPM(u_int16_t value);
 
#define ID_RES_VCC_set 4245
extern int16_t RES_VCC_set;
int doWrite_RES_VCC_set(int16_t value);
int prepareWrite_RES_VCC_set(int16_t value);
 
#define ID_RES_VCC_fbk 4246
extern int16_t RES_VCC_fbk;
int doWrite_RES_VCC_fbk(int16_t value);
int prepareWrite_RES_VCC_fbk(int16_t value);
 
#define ID_RES_mA_fbk 4247
extern int16_t RES_mA_fbk;
int doWrite_RES_mA_fbk(int16_t value);
int prepareWrite_RES_mA_fbk(int16_t value);
 
#define ID_RES_FWrevision 4248
extern u_int16_t RES_FWrevision;
int doWrite_RES_FWrevision(u_int16_t value);
int prepareWrite_RES_FWrevision(u_int16_t value);
 
#define ID_RES_HWconfig 4249
extern u_int16_t RES_HWconfig;
int doWrite_RES_HWconfig(u_int16_t value);
int prepareWrite_RES_HWconfig(u_int16_t value);
 
#define ID_OK_Tamb 4250
extern int16_t OK_Tamb;
int doWrite_OK_Tamb(int16_t value);
int prepareWrite_OK_Tamb(int16_t value);
 
#define ID_OK_RPM 4251
extern u_int16_t OK_RPM;
int doWrite_OK_RPM(u_int16_t value);
int prepareWrite_OK_RPM(u_int16_t value);
 
#define ID_OK_VCC_set 4252
extern int16_t OK_VCC_set;
int doWrite_OK_VCC_set(int16_t value);
int prepareWrite_OK_VCC_set(int16_t value);
 
#define ID_OK_VCC_fbk 4253
extern int16_t OK_VCC_fbk;
int doWrite_OK_VCC_fbk(int16_t value);
int prepareWrite_OK_VCC_fbk(int16_t value);
 
#define ID_OK_mA_fbk 4254
extern int16_t OK_mA_fbk;
int doWrite_OK_mA_fbk(int16_t value);
int prepareWrite_OK_mA_fbk(int16_t value);
 
#define ID_OK_FWrevision 4255
extern u_int16_t OK_FWrevision;
int doWrite_OK_FWrevision(u_int16_t value);
int prepareWrite_OK_FWrevision(u_int16_t value);
 
#define ID_OK_HWconfig 4256
extern u_int16_t OK_HWconfig;
int doWrite_OK_HWconfig(u_int16_t value);
int prepareWrite_OK_HWconfig(u_int16_t value);
 
#define ID_TST_RTUS_WR 4257
extern int TST_RTUS_WR;
int doWrite_TST_RTUS_WR(int value);
int prepareWrite_TST_RTUS_WR(int value);
 
#define ID_TST_RTUS_RD 4258
extern int TST_RTUS_RD;
int doWrite_TST_RTUS_RD(int value);
int prepareWrite_TST_RTUS_RD(int value);
 
#define ID_TST_RTU1_WR 4259
extern int TST_RTU1_WR;
int doWrite_TST_RTU1_WR(int value);
int prepareWrite_TST_RTU1_WR(int value);
 
#define ID_TST_RTU1_RD 4260
extern int TST_RTU1_RD;
int doWrite_TST_RTU1_RD(int value);
int prepareWrite_TST_RTU1_RD(int value);
 
#define ID_TST_RTU3_WR 4261
extern int TST_RTU3_WR;
int doWrite_TST_RTU3_WR(int value);
int prepareWrite_TST_RTU3_WR(int value);
 
#define ID_TST_RTU3_RD 4262
extern int TST_RTU3_RD;
int doWrite_TST_RTU3_RD(int value);
int prepareWrite_TST_RTU3_RD(int value);
 
#define ID_TST_CAN1_WR 4263
extern int TST_CAN1_WR;
int doWrite_TST_CAN1_WR(int value);
int prepareWrite_TST_CAN1_WR(int value);
 
#define ID_TST_CAN1_RD 4264
extern int TST_CAN1_RD;
int doWrite_TST_CAN1_RD(int value);
int prepareWrite_TST_CAN1_RD(int value);
 
#define ID_VAL_RTUS_WR 4265
extern int VAL_RTUS_WR;
int doWrite_VAL_RTUS_WR(int value);
int prepareWrite_VAL_RTUS_WR(int value);
 
#define ID_VAL_RTUS_RD 4266
extern int VAL_RTUS_RD;
int doWrite_VAL_RTUS_RD(int value);
int prepareWrite_VAL_RTUS_RD(int value);
 
#define ID_VAL_RTU1_WR 4267
extern int VAL_RTU1_WR;
int doWrite_VAL_RTU1_WR(int value);
int prepareWrite_VAL_RTU1_WR(int value);
 
#define ID_VAL_RTU1_RD 4268
extern int VAL_RTU1_RD;
int doWrite_VAL_RTU1_RD(int value);
int prepareWrite_VAL_RTU1_RD(int value);
 
#define ID_VAL_RTU3_WR 4269
extern int VAL_RTU3_WR;
int doWrite_VAL_RTU3_WR(int value);
int prepareWrite_VAL_RTU3_WR(int value);
 
#define ID_VAL_RTU3_RD 4270
extern int VAL_RTU3_RD;
int doWrite_VAL_RTU3_RD(int value);
int prepareWrite_VAL_RTU3_RD(int value);
 
#define ID_VAL_CAN1_WR 4271
extern int VAL_CAN1_WR;
int doWrite_VAL_CAN1_WR(int value);
int prepareWrite_VAL_CAN1_WR(int value);
 
#define ID_VAL_CAN1_RD 4272
extern int VAL_CAN1_RD;
int doWrite_VAL_CAN1_RD(int value);
int prepareWrite_VAL_CAN1_RD(int value);
 
#define ID_RES_RTUS_WR 4273
extern int RES_RTUS_WR;
int doWrite_RES_RTUS_WR(int value);
int prepareWrite_RES_RTUS_WR(int value);
 
#define ID_RES_RTUS_RD 4274
extern int RES_RTUS_RD;
int doWrite_RES_RTUS_RD(int value);
int prepareWrite_RES_RTUS_RD(int value);
 
#define ID_RES_RTU1_WR 4275
extern int RES_RTU1_WR;
int doWrite_RES_RTU1_WR(int value);
int prepareWrite_RES_RTU1_WR(int value);
 
#define ID_RES_RTU1_RD 4276
extern int RES_RTU1_RD;
int doWrite_RES_RTU1_RD(int value);
int prepareWrite_RES_RTU1_RD(int value);
 
#define ID_RES_RTU3_WR 4277
extern int RES_RTU3_WR;
int doWrite_RES_RTU3_WR(int value);
int prepareWrite_RES_RTU3_WR(int value);
 
#define ID_RES_RTU3_RD 4278
extern int RES_RTU3_RD;
int doWrite_RES_RTU3_RD(int value);
int prepareWrite_RES_RTU3_RD(int value);
 
#define ID_RES_CAN1_WR 4279
extern int RES_CAN1_WR;
int doWrite_RES_CAN1_WR(int value);
int prepareWrite_RES_CAN1_WR(int value);
 
#define ID_RES_CAN1_RD 4280
extern int RES_CAN1_RD;
int doWrite_RES_CAN1_RD(int value);
int prepareWrite_RES_CAN1_RD(int value);
 
#define ID_OK_RTUS_WR 4281
extern int OK_RTUS_WR;
int doWrite_OK_RTUS_WR(int value);
int prepareWrite_OK_RTUS_WR(int value);
 
#define ID_OK_RTUS_RD 4282
extern int OK_RTUS_RD;
int doWrite_OK_RTUS_RD(int value);
int prepareWrite_OK_RTUS_RD(int value);
 
#define ID_OK_RTU1_WR 4283
extern int OK_RTU1_WR;
int doWrite_OK_RTU1_WR(int value);
int prepareWrite_OK_RTU1_WR(int value);
 
#define ID_OK_RTU1_RD 4284
extern int OK_RTU1_RD;
int doWrite_OK_RTU1_RD(int value);
int prepareWrite_OK_RTU1_RD(int value);
 
#define ID_OK_RTU3_WR 4285
extern int OK_RTU3_WR;
int doWrite_OK_RTU3_WR(int value);
int prepareWrite_OK_RTU3_WR(int value);
 
#define ID_OK_RTU3_RD 4286
extern int OK_RTU3_RD;
int doWrite_OK_RTU3_RD(int value);
int prepareWrite_OK_RTU3_RD(int value);
 
#define ID_OK_CAN1_WR 4287
extern int OK_CAN1_WR;
int doWrite_OK_CAN1_WR(int value);
int prepareWrite_OK_CAN1_WR(int value);
 
#define ID_OK_CAN1_RD 4288
extern int OK_CAN1_RD;
int doWrite_OK_CAN1_RD(int value);
int prepareWrite_OK_CAN1_RD(int value);
 
#define ID_PLC_HeartBeat 5300
extern u_int16_t PLC_HeartBeat;
int doWrite_PLC_HeartBeat(u_int16_t value);
int prepareWrite_PLC_HeartBeat(u_int16_t value);
 
#define ID_PLC_DigIn_1 5301
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int prepareWrite_PLC_DigIn_1(int value);
 
#define ID_PLC_DigIn_2 5302
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int prepareWrite_PLC_DigIn_2(int value);
 
#define ID_PLC_DigIn_3 5303
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int prepareWrite_PLC_DigIn_3(int value);
 
#define ID_PLC_DigIn_4 5304
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int prepareWrite_PLC_DigIn_4(int value);
 
#define ID_PLC_DigIn_5 5305
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int prepareWrite_PLC_DigIn_5(int value);
 
#define ID_PLC_DigIn_6 5306
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int prepareWrite_PLC_DigIn_6(int value);
 
#define ID_PLC_DigIn_7 5307
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int prepareWrite_PLC_DigIn_7(int value);
 
#define ID_PLC_DigIn_8 5308
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int prepareWrite_PLC_DigIn_8(int value);
 
#define ID_PLC_DigIn_9 5309
extern int PLC_DigIn_9;
int doWrite_PLC_DigIn_9(int value);
int prepareWrite_PLC_DigIn_9(int value);
 
#define ID_PLC_DigIn_10 5310
extern int PLC_DigIn_10;
int doWrite_PLC_DigIn_10(int value);
int prepareWrite_PLC_DigIn_10(int value);
 
#define ID_PLC_DigIn_11 5311
extern int PLC_DigIn_11;
int doWrite_PLC_DigIn_11(int value);
int prepareWrite_PLC_DigIn_11(int value);
 
#define ID_PLC_DigIn_12 5312
extern int PLC_DigIn_12;
int doWrite_PLC_DigIn_12(int value);
int prepareWrite_PLC_DigIn_12(int value);
 
#define ID_PLC_DigIn_13 5313
extern int PLC_DigIn_13;
int doWrite_PLC_DigIn_13(int value);
int prepareWrite_PLC_DigIn_13(int value);
 
#define ID_PLC_DigIn_14 5314
extern int PLC_DigIn_14;
int doWrite_PLC_DigIn_14(int value);
int prepareWrite_PLC_DigIn_14(int value);
 
#define ID_PLC_DigIn_15 5315
extern int PLC_DigIn_15;
int doWrite_PLC_DigIn_15(int value);
int prepareWrite_PLC_DigIn_15(int value);
 
#define ID_PLC_DigIn_16 5316
extern int PLC_DigIn_16;
int doWrite_PLC_DigIn_16(int value);
int prepareWrite_PLC_DigIn_16(int value);
 
#define ID_PLC_AnIn_1 5317
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int prepareWrite_PLC_AnIn_1(int16_t value);
 
#define ID_PLC_AnIn_2 5318
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int prepareWrite_PLC_AnIn_2(int16_t value);
 
#define ID_PLC_Tamb 5319
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int prepareWrite_PLC_Tamb(int16_t value);
 
#define ID_PLC_DigOut_1 5320
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int prepareWrite_PLC_DigOut_1(int value);
 
#define ID_PLC_DigOut_2 5321
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int prepareWrite_PLC_DigOut_2(int value);
 
#define ID_PLC_DigOut_3 5322
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int prepareWrite_PLC_DigOut_3(int value);
 
#define ID_PLC_DigOut_4 5323
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int prepareWrite_PLC_DigOut_4(int value);
 
#define ID_PLC_DigOut_5 5324
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int prepareWrite_PLC_DigOut_5(int value);
 
#define ID_PLC_DigOut_6 5325
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int prepareWrite_PLC_DigOut_6(int value);
 
#define ID_PLC_DigOut_7 5326
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int prepareWrite_PLC_DigOut_7(int value);
 
#define ID_PLC_DigOut_8 5327
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int prepareWrite_PLC_DigOut_8(int value);
 
#define ID_PLC_DigOut_9 5328
extern int PLC_DigOut_9;
int doWrite_PLC_DigOut_9(int value);
int prepareWrite_PLC_DigOut_9(int value);
 
#define ID_PLC_DigOut_10 5329
extern int PLC_DigOut_10;
int doWrite_PLC_DigOut_10(int value);
int prepareWrite_PLC_DigOut_10(int value);
 
#define ID_PLC_DigOut_11 5330
extern int PLC_DigOut_11;
int doWrite_PLC_DigOut_11(int value);
int prepareWrite_PLC_DigOut_11(int value);
 
#define ID_PLC_DigOut_12 5331
extern int PLC_DigOut_12;
int doWrite_PLC_DigOut_12(int value);
int prepareWrite_PLC_DigOut_12(int value);
 
#define ID_PLC_DigOut_13 5332
extern int PLC_DigOut_13;
int doWrite_PLC_DigOut_13(int value);
int prepareWrite_PLC_DigOut_13(int value);
 
#define ID_PLC_DigOut_14 5333
extern int PLC_DigOut_14;
int doWrite_PLC_DigOut_14(int value);
int prepareWrite_PLC_DigOut_14(int value);
 
#define ID_PLC_DigOut_15 5334
extern int PLC_DigOut_15;
int doWrite_PLC_DigOut_15(int value);
int prepareWrite_PLC_DigOut_15(int value);
 
#define ID_PLC_DigOut_16 5335
extern int PLC_DigOut_16;
int doWrite_PLC_DigOut_16(int value);
int prepareWrite_PLC_DigOut_16(int value);
 
#define ID_PLC_AnOutConf_X 5336
extern int16_t PLC_AnOutConf_X;
int doWrite_PLC_AnOutConf_X(int16_t value);
int prepareWrite_PLC_AnOutConf_X(int16_t value);
 
#define ID_PLC_AnOut_1 5337
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int prepareWrite_PLC_AnOut_1(int16_t value);
 
#define ID_PLC_AnOut_2 5338
extern int16_t PLC_AnOut_2;
int doWrite_PLC_AnOut_2(int16_t value);
int prepareWrite_PLC_AnOut_2(int16_t value);
 
#define ID_PLC_AnOut_3 5339
extern int16_t PLC_AnOut_3;
int doWrite_PLC_AnOut_3(int16_t value);
int prepareWrite_PLC_AnOut_3(int16_t value);
 
#define ID_PLC_AnOut_4 5340
extern int16_t PLC_AnOut_4;
int doWrite_PLC_AnOut_4(int16_t value);
int prepareWrite_PLC_AnOut_4(int16_t value);
 
#define ID_PLC_AnOut_5 5341
extern int16_t PLC_AnOut_5;
int doWrite_PLC_AnOut_5(int16_t value);
int prepareWrite_PLC_AnOut_5(int16_t value);
 
#define ID_PLC_AnOut_6 5342
extern int16_t PLC_AnOut_6;
int doWrite_PLC_AnOut_6(int16_t value);
int prepareWrite_PLC_AnOut_6(int16_t value);
 
#define ID_PLC_AnOut_7 5343
extern int16_t PLC_AnOut_7;
int doWrite_PLC_AnOut_7(int16_t value);
int prepareWrite_PLC_AnOut_7(int16_t value);
 
#define ID_PLC_AnOut_8 5344
extern int16_t PLC_AnOut_8;
int doWrite_PLC_AnOut_8(int16_t value);
int prepareWrite_PLC_AnOut_8(int16_t value);
 
#define ID_PLC_AnInConf_1 5345
extern u_int16_t PLC_AnInConf_1;
int doWrite_PLC_AnInConf_1(u_int16_t value);
int prepareWrite_PLC_AnInConf_1(u_int16_t value);
 
#define ID_PLC_AnInConf_2 5346
extern u_int16_t PLC_AnInConf_2;
int doWrite_PLC_AnInConf_2(u_int16_t value);
int prepareWrite_PLC_AnInConf_2(u_int16_t value);
 
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
