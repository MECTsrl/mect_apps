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
 
#define ID_START_REMOTE 3999
extern int START_REMOTE;
int doWrite_START_REMOTE(int value);
int addWrite_START_REMOTE(int value);
int getStatus_START_REMOTE();
 
#define ID_START_TEST 4000
extern int START_TEST;
int doWrite_START_TEST(int value);
int addWrite_START_TEST(int value);
int getStatus_START_TEST();
 
#define ID_TST_DigIn_1 4001
extern int TST_DigIn_1;
int doWrite_TST_DigIn_1(int value);
int addWrite_TST_DigIn_1(int value);
int getStatus_TST_DigIn_1();
 
#define ID_TST_DigIn_2 4002
extern int TST_DigIn_2;
int doWrite_TST_DigIn_2(int value);
int addWrite_TST_DigIn_2(int value);
int getStatus_TST_DigIn_2();
 
#define ID_TST_DigIn_3 4003
extern int TST_DigIn_3;
int doWrite_TST_DigIn_3(int value);
int addWrite_TST_DigIn_3(int value);
int getStatus_TST_DigIn_3();
 
#define ID_TST_DigIn_4 4004
extern int TST_DigIn_4;
int doWrite_TST_DigIn_4(int value);
int addWrite_TST_DigIn_4(int value);
int getStatus_TST_DigIn_4();
 
#define ID_TST_DigIn_5 4005
extern int TST_DigIn_5;
int doWrite_TST_DigIn_5(int value);
int addWrite_TST_DigIn_5(int value);
int getStatus_TST_DigIn_5();
 
#define ID_TST_DigIn_6 4006
extern int TST_DigIn_6;
int doWrite_TST_DigIn_6(int value);
int addWrite_TST_DigIn_6(int value);
int getStatus_TST_DigIn_6();
 
#define ID_TST_DigIn_7 4007
extern int TST_DigIn_7;
int doWrite_TST_DigIn_7(int value);
int addWrite_TST_DigIn_7(int value);
int getStatus_TST_DigIn_7();
 
#define ID_TST_DigIn_8 4008
extern int TST_DigIn_8;
int doWrite_TST_DigIn_8(int value);
int addWrite_TST_DigIn_8(int value);
int getStatus_TST_DigIn_8();
 
#define ID_TST_DigIn_9 4009
extern int TST_DigIn_9;
int doWrite_TST_DigIn_9(int value);
int addWrite_TST_DigIn_9(int value);
int getStatus_TST_DigIn_9();
 
#define ID_TST_DigIn_10 4010
extern int TST_DigIn_10;
int doWrite_TST_DigIn_10(int value);
int addWrite_TST_DigIn_10(int value);
int getStatus_TST_DigIn_10();
 
#define ID_TST_DigIn_11 4011
extern int TST_DigIn_11;
int doWrite_TST_DigIn_11(int value);
int addWrite_TST_DigIn_11(int value);
int getStatus_TST_DigIn_11();
 
#define ID_TST_DigIn_12 4012
extern int TST_DigIn_12;
int doWrite_TST_DigIn_12(int value);
int addWrite_TST_DigIn_12(int value);
int getStatus_TST_DigIn_12();
 
#define ID_TST_DigIn_13 4013
extern int TST_DigIn_13;
int doWrite_TST_DigIn_13(int value);
int addWrite_TST_DigIn_13(int value);
int getStatus_TST_DigIn_13();
 
#define ID_TST_DigIn_14 4014
extern int TST_DigIn_14;
int doWrite_TST_DigIn_14(int value);
int addWrite_TST_DigIn_14(int value);
int getStatus_TST_DigIn_14();
 
#define ID_TST_DigIn_15 4015
extern int TST_DigIn_15;
int doWrite_TST_DigIn_15(int value);
int addWrite_TST_DigIn_15(int value);
int getStatus_TST_DigIn_15();
 
#define ID_TST_DigIn_16 4016
extern int TST_DigIn_16;
int doWrite_TST_DigIn_16(int value);
int addWrite_TST_DigIn_16(int value);
int getStatus_TST_DigIn_16();
 
#define ID_VAL_DigIn_1 4017
extern int VAL_DigIn_1;
int doWrite_VAL_DigIn_1(int value);
int addWrite_VAL_DigIn_1(int value);
int getStatus_VAL_DigIn_1();
 
#define ID_VAL_DigIn_2 4018
extern int VAL_DigIn_2;
int doWrite_VAL_DigIn_2(int value);
int addWrite_VAL_DigIn_2(int value);
int getStatus_VAL_DigIn_2();
 
#define ID_VAL_DigIn_3 4019
extern int VAL_DigIn_3;
int doWrite_VAL_DigIn_3(int value);
int addWrite_VAL_DigIn_3(int value);
int getStatus_VAL_DigIn_3();
 
#define ID_VAL_DigIn_4 4020
extern int VAL_DigIn_4;
int doWrite_VAL_DigIn_4(int value);
int addWrite_VAL_DigIn_4(int value);
int getStatus_VAL_DigIn_4();
 
#define ID_VAL_DigIn_5 4021
extern int VAL_DigIn_5;
int doWrite_VAL_DigIn_5(int value);
int addWrite_VAL_DigIn_5(int value);
int getStatus_VAL_DigIn_5();
 
#define ID_VAL_DigIn_6 4022
extern int VAL_DigIn_6;
int doWrite_VAL_DigIn_6(int value);
int addWrite_VAL_DigIn_6(int value);
int getStatus_VAL_DigIn_6();
 
#define ID_VAL_DigIn_7 4023
extern int VAL_DigIn_7;
int doWrite_VAL_DigIn_7(int value);
int addWrite_VAL_DigIn_7(int value);
int getStatus_VAL_DigIn_7();
 
#define ID_VAL_DigIn_8 4024
extern int VAL_DigIn_8;
int doWrite_VAL_DigIn_8(int value);
int addWrite_VAL_DigIn_8(int value);
int getStatus_VAL_DigIn_8();
 
#define ID_VAL_DigIn_9 4025
extern int VAL_DigIn_9;
int doWrite_VAL_DigIn_9(int value);
int addWrite_VAL_DigIn_9(int value);
int getStatus_VAL_DigIn_9();
 
#define ID_VAL_DigIn_10 4026
extern int VAL_DigIn_10;
int doWrite_VAL_DigIn_10(int value);
int addWrite_VAL_DigIn_10(int value);
int getStatus_VAL_DigIn_10();
 
#define ID_VAL_DigIn_11 4027
extern int VAL_DigIn_11;
int doWrite_VAL_DigIn_11(int value);
int addWrite_VAL_DigIn_11(int value);
int getStatus_VAL_DigIn_11();
 
#define ID_VAL_DigIn_12 4028
extern int VAL_DigIn_12;
int doWrite_VAL_DigIn_12(int value);
int addWrite_VAL_DigIn_12(int value);
int getStatus_VAL_DigIn_12();
 
#define ID_VAL_DigIn_13 4029
extern int VAL_DigIn_13;
int doWrite_VAL_DigIn_13(int value);
int addWrite_VAL_DigIn_13(int value);
int getStatus_VAL_DigIn_13();
 
#define ID_VAL_DigIn_14 4030
extern int VAL_DigIn_14;
int doWrite_VAL_DigIn_14(int value);
int addWrite_VAL_DigIn_14(int value);
int getStatus_VAL_DigIn_14();
 
#define ID_VAL_DigIn_15 4031
extern int VAL_DigIn_15;
int doWrite_VAL_DigIn_15(int value);
int addWrite_VAL_DigIn_15(int value);
int getStatus_VAL_DigIn_15();
 
#define ID_VAL_DigIn_16 4032
extern int VAL_DigIn_16;
int doWrite_VAL_DigIn_16(int value);
int addWrite_VAL_DigIn_16(int value);
int getStatus_VAL_DigIn_16();
 
#define ID_RES_DigIn_1 4033
extern int RES_DigIn_1;
int doWrite_RES_DigIn_1(int value);
int addWrite_RES_DigIn_1(int value);
int getStatus_RES_DigIn_1();
 
#define ID_RES_DigIn_2 4034
extern int RES_DigIn_2;
int doWrite_RES_DigIn_2(int value);
int addWrite_RES_DigIn_2(int value);
int getStatus_RES_DigIn_2();
 
#define ID_RES_DigIn_3 4035
extern int RES_DigIn_3;
int doWrite_RES_DigIn_3(int value);
int addWrite_RES_DigIn_3(int value);
int getStatus_RES_DigIn_3();
 
#define ID_RES_DigIn_4 4036
extern int RES_DigIn_4;
int doWrite_RES_DigIn_4(int value);
int addWrite_RES_DigIn_4(int value);
int getStatus_RES_DigIn_4();
 
#define ID_RES_DigIn_5 4037
extern int RES_DigIn_5;
int doWrite_RES_DigIn_5(int value);
int addWrite_RES_DigIn_5(int value);
int getStatus_RES_DigIn_5();
 
#define ID_RES_DigIn_6 4038
extern int RES_DigIn_6;
int doWrite_RES_DigIn_6(int value);
int addWrite_RES_DigIn_6(int value);
int getStatus_RES_DigIn_6();
 
#define ID_RES_DigIn_7 4039
extern int RES_DigIn_7;
int doWrite_RES_DigIn_7(int value);
int addWrite_RES_DigIn_7(int value);
int getStatus_RES_DigIn_7();
 
#define ID_RES_DigIn_8 4040
extern int RES_DigIn_8;
int doWrite_RES_DigIn_8(int value);
int addWrite_RES_DigIn_8(int value);
int getStatus_RES_DigIn_8();
 
#define ID_RES_DigIn_9 4041
extern int RES_DigIn_9;
int doWrite_RES_DigIn_9(int value);
int addWrite_RES_DigIn_9(int value);
int getStatus_RES_DigIn_9();
 
#define ID_RES_DigIn_10 4042
extern int RES_DigIn_10;
int doWrite_RES_DigIn_10(int value);
int addWrite_RES_DigIn_10(int value);
int getStatus_RES_DigIn_10();
 
#define ID_RES_DigIn_11 4043
extern int RES_DigIn_11;
int doWrite_RES_DigIn_11(int value);
int addWrite_RES_DigIn_11(int value);
int getStatus_RES_DigIn_11();
 
#define ID_RES_DigIn_12 4044
extern int RES_DigIn_12;
int doWrite_RES_DigIn_12(int value);
int addWrite_RES_DigIn_12(int value);
int getStatus_RES_DigIn_12();
 
#define ID_RES_DigIn_13 4045
extern int RES_DigIn_13;
int doWrite_RES_DigIn_13(int value);
int addWrite_RES_DigIn_13(int value);
int getStatus_RES_DigIn_13();
 
#define ID_RES_DigIn_14 4046
extern int RES_DigIn_14;
int doWrite_RES_DigIn_14(int value);
int addWrite_RES_DigIn_14(int value);
int getStatus_RES_DigIn_14();
 
#define ID_RES_DigIn_15 4047
extern int RES_DigIn_15;
int doWrite_RES_DigIn_15(int value);
int addWrite_RES_DigIn_15(int value);
int getStatus_RES_DigIn_15();
 
#define ID_RES_DigIn_16 4048
extern int RES_DigIn_16;
int doWrite_RES_DigIn_16(int value);
int addWrite_RES_DigIn_16(int value);
int getStatus_RES_DigIn_16();
 
#define ID_TST_DigOut_1 4049
extern int TST_DigOut_1;
int doWrite_TST_DigOut_1(int value);
int addWrite_TST_DigOut_1(int value);
int getStatus_TST_DigOut_1();
 
#define ID_TST_DigOut_2 4050
extern int TST_DigOut_2;
int doWrite_TST_DigOut_2(int value);
int addWrite_TST_DigOut_2(int value);
int getStatus_TST_DigOut_2();
 
#define ID_TST_DigOut_3 4051
extern int TST_DigOut_3;
int doWrite_TST_DigOut_3(int value);
int addWrite_TST_DigOut_3(int value);
int getStatus_TST_DigOut_3();
 
#define ID_TST_DigOut_4 4052
extern int TST_DigOut_4;
int doWrite_TST_DigOut_4(int value);
int addWrite_TST_DigOut_4(int value);
int getStatus_TST_DigOut_4();
 
#define ID_TST_DigOut_5 4053
extern int TST_DigOut_5;
int doWrite_TST_DigOut_5(int value);
int addWrite_TST_DigOut_5(int value);
int getStatus_TST_DigOut_5();
 
#define ID_TST_DigOut_6 4054
extern int TST_DigOut_6;
int doWrite_TST_DigOut_6(int value);
int addWrite_TST_DigOut_6(int value);
int getStatus_TST_DigOut_6();
 
#define ID_TST_DigOut_7 4055
extern int TST_DigOut_7;
int doWrite_TST_DigOut_7(int value);
int addWrite_TST_DigOut_7(int value);
int getStatus_TST_DigOut_7();
 
#define ID_TST_DigOut_8 4056
extern int TST_DigOut_8;
int doWrite_TST_DigOut_8(int value);
int addWrite_TST_DigOut_8(int value);
int getStatus_TST_DigOut_8();
 
#define ID_TST_DigOut_9 4057
extern int TST_DigOut_9;
int doWrite_TST_DigOut_9(int value);
int addWrite_TST_DigOut_9(int value);
int getStatus_TST_DigOut_9();
 
#define ID_TST_DigOut_10 4058
extern int TST_DigOut_10;
int doWrite_TST_DigOut_10(int value);
int addWrite_TST_DigOut_10(int value);
int getStatus_TST_DigOut_10();
 
#define ID_TST_DigOut_11 4059
extern int TST_DigOut_11;
int doWrite_TST_DigOut_11(int value);
int addWrite_TST_DigOut_11(int value);
int getStatus_TST_DigOut_11();
 
#define ID_TST_DigOut_12 4060
extern int TST_DigOut_12;
int doWrite_TST_DigOut_12(int value);
int addWrite_TST_DigOut_12(int value);
int getStatus_TST_DigOut_12();
 
#define ID_TST_DigOut_13 4061
extern int TST_DigOut_13;
int doWrite_TST_DigOut_13(int value);
int addWrite_TST_DigOut_13(int value);
int getStatus_TST_DigOut_13();
 
#define ID_TST_DigOut_14 4062
extern int TST_DigOut_14;
int doWrite_TST_DigOut_14(int value);
int addWrite_TST_DigOut_14(int value);
int getStatus_TST_DigOut_14();
 
#define ID_TST_DigOut_15 4063
extern int TST_DigOut_15;
int doWrite_TST_DigOut_15(int value);
int addWrite_TST_DigOut_15(int value);
int getStatus_TST_DigOut_15();
 
#define ID_TST_DigOut_16 4064
extern int TST_DigOut_16;
int doWrite_TST_DigOut_16(int value);
int addWrite_TST_DigOut_16(int value);
int getStatus_TST_DigOut_16();
 
#define ID_VAL_DigOut_1 4065
extern int VAL_DigOut_1;
int doWrite_VAL_DigOut_1(int value);
int addWrite_VAL_DigOut_1(int value);
int getStatus_VAL_DigOut_1();
 
#define ID_VAL_DigOut_2 4066
extern int VAL_DigOut_2;
int doWrite_VAL_DigOut_2(int value);
int addWrite_VAL_DigOut_2(int value);
int getStatus_VAL_DigOut_2();
 
#define ID_VAL_DigOut_3 4067
extern int VAL_DigOut_3;
int doWrite_VAL_DigOut_3(int value);
int addWrite_VAL_DigOut_3(int value);
int getStatus_VAL_DigOut_3();
 
#define ID_VAL_DigOut_4 4068
extern int VAL_DigOut_4;
int doWrite_VAL_DigOut_4(int value);
int addWrite_VAL_DigOut_4(int value);
int getStatus_VAL_DigOut_4();
 
#define ID_VAL_DigOut_5 4069
extern int VAL_DigOut_5;
int doWrite_VAL_DigOut_5(int value);
int addWrite_VAL_DigOut_5(int value);
int getStatus_VAL_DigOut_5();
 
#define ID_VAL_DigOut_6 4070
extern int VAL_DigOut_6;
int doWrite_VAL_DigOut_6(int value);
int addWrite_VAL_DigOut_6(int value);
int getStatus_VAL_DigOut_6();
 
#define ID_VAL_DigOut_7 4071
extern int VAL_DigOut_7;
int doWrite_VAL_DigOut_7(int value);
int addWrite_VAL_DigOut_7(int value);
int getStatus_VAL_DigOut_7();
 
#define ID_VAL_DigOut_8 4072
extern int VAL_DigOut_8;
int doWrite_VAL_DigOut_8(int value);
int addWrite_VAL_DigOut_8(int value);
int getStatus_VAL_DigOut_8();
 
#define ID_VAL_DigOut_9 4073
extern int VAL_DigOut_9;
int doWrite_VAL_DigOut_9(int value);
int addWrite_VAL_DigOut_9(int value);
int getStatus_VAL_DigOut_9();
 
#define ID_VAL_DigOut_10 4074
extern int VAL_DigOut_10;
int doWrite_VAL_DigOut_10(int value);
int addWrite_VAL_DigOut_10(int value);
int getStatus_VAL_DigOut_10();
 
#define ID_VAL_DigOut_11 4075
extern int VAL_DigOut_11;
int doWrite_VAL_DigOut_11(int value);
int addWrite_VAL_DigOut_11(int value);
int getStatus_VAL_DigOut_11();
 
#define ID_VAL_DigOut_12 4076
extern int VAL_DigOut_12;
int doWrite_VAL_DigOut_12(int value);
int addWrite_VAL_DigOut_12(int value);
int getStatus_VAL_DigOut_12();
 
#define ID_VAL_DigOut_13 4077
extern int VAL_DigOut_13;
int doWrite_VAL_DigOut_13(int value);
int addWrite_VAL_DigOut_13(int value);
int getStatus_VAL_DigOut_13();
 
#define ID_VAL_DigOut_14 4078
extern int VAL_DigOut_14;
int doWrite_VAL_DigOut_14(int value);
int addWrite_VAL_DigOut_14(int value);
int getStatus_VAL_DigOut_14();
 
#define ID_VAL_DigOut_15 4079
extern int VAL_DigOut_15;
int doWrite_VAL_DigOut_15(int value);
int addWrite_VAL_DigOut_15(int value);
int getStatus_VAL_DigOut_15();
 
#define ID_VAL_DigOut_16 4080
extern int VAL_DigOut_16;
int doWrite_VAL_DigOut_16(int value);
int addWrite_VAL_DigOut_16(int value);
int getStatus_VAL_DigOut_16();
 
#define ID_RES_DigOut_1 4081
extern int RES_DigOut_1;
int doWrite_RES_DigOut_1(int value);
int addWrite_RES_DigOut_1(int value);
int getStatus_RES_DigOut_1();
 
#define ID_RES_DigOut_2 4082
extern int RES_DigOut_2;
int doWrite_RES_DigOut_2(int value);
int addWrite_RES_DigOut_2(int value);
int getStatus_RES_DigOut_2();
 
#define ID_RES_DigOut_3 4083
extern int RES_DigOut_3;
int doWrite_RES_DigOut_3(int value);
int addWrite_RES_DigOut_3(int value);
int getStatus_RES_DigOut_3();
 
#define ID_RES_DigOut_4 4084
extern int RES_DigOut_4;
int doWrite_RES_DigOut_4(int value);
int addWrite_RES_DigOut_4(int value);
int getStatus_RES_DigOut_4();
 
#define ID_RES_DigOut_5 4085
extern int RES_DigOut_5;
int doWrite_RES_DigOut_5(int value);
int addWrite_RES_DigOut_5(int value);
int getStatus_RES_DigOut_5();
 
#define ID_RES_DigOut_6 4086
extern int RES_DigOut_6;
int doWrite_RES_DigOut_6(int value);
int addWrite_RES_DigOut_6(int value);
int getStatus_RES_DigOut_6();
 
#define ID_RES_DigOut_7 4087
extern int RES_DigOut_7;
int doWrite_RES_DigOut_7(int value);
int addWrite_RES_DigOut_7(int value);
int getStatus_RES_DigOut_7();
 
#define ID_RES_DigOut_8 4088
extern int RES_DigOut_8;
int doWrite_RES_DigOut_8(int value);
int addWrite_RES_DigOut_8(int value);
int getStatus_RES_DigOut_8();
 
#define ID_RES_DigOut_9 4089
extern int RES_DigOut_9;
int doWrite_RES_DigOut_9(int value);
int addWrite_RES_DigOut_9(int value);
int getStatus_RES_DigOut_9();
 
#define ID_RES_DigOut_10 4090
extern int RES_DigOut_10;
int doWrite_RES_DigOut_10(int value);
int addWrite_RES_DigOut_10(int value);
int getStatus_RES_DigOut_10();
 
#define ID_RES_DigOut_11 4091
extern int RES_DigOut_11;
int doWrite_RES_DigOut_11(int value);
int addWrite_RES_DigOut_11(int value);
int getStatus_RES_DigOut_11();
 
#define ID_RES_DigOut_12 4092
extern int RES_DigOut_12;
int doWrite_RES_DigOut_12(int value);
int addWrite_RES_DigOut_12(int value);
int getStatus_RES_DigOut_12();
 
#define ID_RES_DigOut_13 4093
extern int RES_DigOut_13;
int doWrite_RES_DigOut_13(int value);
int addWrite_RES_DigOut_13(int value);
int getStatus_RES_DigOut_13();
 
#define ID_RES_DigOut_14 4094
extern int RES_DigOut_14;
int doWrite_RES_DigOut_14(int value);
int addWrite_RES_DigOut_14(int value);
int getStatus_RES_DigOut_14();
 
#define ID_RES_DigOut_15 4095
extern int RES_DigOut_15;
int doWrite_RES_DigOut_15(int value);
int addWrite_RES_DigOut_15(int value);
int getStatus_RES_DigOut_15();
 
#define ID_RES_DigOut_16 4096
extern int RES_DigOut_16;
int doWrite_RES_DigOut_16(int value);
int addWrite_RES_DigOut_16(int value);
int getStatus_RES_DigOut_16();
 
#define ID_TST_AnIn_1 4097
extern int TST_AnIn_1;
int doWrite_TST_AnIn_1(int value);
int addWrite_TST_AnIn_1(int value);
int getStatus_TST_AnIn_1();
 
#define ID_TST_AnIn_2 4098
extern int TST_AnIn_2;
int doWrite_TST_AnIn_2(int value);
int addWrite_TST_AnIn_2(int value);
int getStatus_TST_AnIn_2();
 
#define ID_TST_AnIn_3 4099
extern int TST_AnIn_3;
int doWrite_TST_AnIn_3(int value);
int addWrite_TST_AnIn_3(int value);
int getStatus_TST_AnIn_3();
 
#define ID_TST_AnIn_4 4100
extern int TST_AnIn_4;
int doWrite_TST_AnIn_4(int value);
int addWrite_TST_AnIn_4(int value);
int getStatus_TST_AnIn_4();
 
#define ID_TST_AnIn_5 4101
extern int TST_AnIn_5;
int doWrite_TST_AnIn_5(int value);
int addWrite_TST_AnIn_5(int value);
int getStatus_TST_AnIn_5();
 
#define ID_TST_AnIn_6 4102
extern int TST_AnIn_6;
int doWrite_TST_AnIn_6(int value);
int addWrite_TST_AnIn_6(int value);
int getStatus_TST_AnIn_6();
 
#define ID_TST_AnIn_7 4103
extern int TST_AnIn_7;
int doWrite_TST_AnIn_7(int value);
int addWrite_TST_AnIn_7(int value);
int getStatus_TST_AnIn_7();
 
#define ID_TST_AnIn_8 4104
extern int TST_AnIn_8;
int doWrite_TST_AnIn_8(int value);
int addWrite_TST_AnIn_8(int value);
int getStatus_TST_AnIn_8();
 
#define ID_TST_AnIn_9 4105
extern int TST_AnIn_9;
int doWrite_TST_AnIn_9(int value);
int addWrite_TST_AnIn_9(int value);
int getStatus_TST_AnIn_9();
 
#define ID_TST_AnIn_10 4106
extern int TST_AnIn_10;
int doWrite_TST_AnIn_10(int value);
int addWrite_TST_AnIn_10(int value);
int getStatus_TST_AnIn_10();
 
#define ID_TST_AnIn_11 4107
extern int TST_AnIn_11;
int doWrite_TST_AnIn_11(int value);
int addWrite_TST_AnIn_11(int value);
int getStatus_TST_AnIn_11();
 
#define ID_TST_AnIn_12 4108
extern int TST_AnIn_12;
int doWrite_TST_AnIn_12(int value);
int addWrite_TST_AnIn_12(int value);
int getStatus_TST_AnIn_12();
 
#define ID_VAL_AnIn_1 4109
extern int16_t VAL_AnIn_1;
int doWrite_VAL_AnIn_1(int16_t value);
int addWrite_VAL_AnIn_1(int16_t value);
int getStatus_VAL_AnIn_1();
 
#define ID_VAL_AnIn_2 4110
extern int16_t VAL_AnIn_2;
int doWrite_VAL_AnIn_2(int16_t value);
int addWrite_VAL_AnIn_2(int16_t value);
int getStatus_VAL_AnIn_2();
 
#define ID_VAL_AnIn_3 4111
extern int16_t VAL_AnIn_3;
int doWrite_VAL_AnIn_3(int16_t value);
int addWrite_VAL_AnIn_3(int16_t value);
int getStatus_VAL_AnIn_3();
 
#define ID_VAL_AnIn_4 4112
extern int16_t VAL_AnIn_4;
int doWrite_VAL_AnIn_4(int16_t value);
int addWrite_VAL_AnIn_4(int16_t value);
int getStatus_VAL_AnIn_4();
 
#define ID_VAL_AnIn_5 4113
extern int16_t VAL_AnIn_5;
int doWrite_VAL_AnIn_5(int16_t value);
int addWrite_VAL_AnIn_5(int16_t value);
int getStatus_VAL_AnIn_5();
 
#define ID_VAL_AnIn_6 4114
extern int16_t VAL_AnIn_6;
int doWrite_VAL_AnIn_6(int16_t value);
int addWrite_VAL_AnIn_6(int16_t value);
int getStatus_VAL_AnIn_6();
 
#define ID_VAL_AnIn_7 4115
extern int16_t VAL_AnIn_7;
int doWrite_VAL_AnIn_7(int16_t value);
int addWrite_VAL_AnIn_7(int16_t value);
int getStatus_VAL_AnIn_7();
 
#define ID_VAL_AnIn_8 4116
extern int16_t VAL_AnIn_8;
int doWrite_VAL_AnIn_8(int16_t value);
int addWrite_VAL_AnIn_8(int16_t value);
int getStatus_VAL_AnIn_8();
 
#define ID_VAL_AnIn_9 4117
extern int16_t VAL_AnIn_9;
int doWrite_VAL_AnIn_9(int16_t value);
int addWrite_VAL_AnIn_9(int16_t value);
int getStatus_VAL_AnIn_9();
 
#define ID_VAL_AnIn_10 4118
extern int16_t VAL_AnIn_10;
int doWrite_VAL_AnIn_10(int16_t value);
int addWrite_VAL_AnIn_10(int16_t value);
int getStatus_VAL_AnIn_10();
 
#define ID_VAL_AnIn_11 4119
extern int16_t VAL_AnIn_11;
int doWrite_VAL_AnIn_11(int16_t value);
int addWrite_VAL_AnIn_11(int16_t value);
int getStatus_VAL_AnIn_11();
 
#define ID_VAL_AnIn_12 4120
extern int16_t VAL_AnIn_12;
int doWrite_VAL_AnIn_12(int16_t value);
int addWrite_VAL_AnIn_12(int16_t value);
int getStatus_VAL_AnIn_12();
 
#define ID_VAL_AnInConf_1 4121
extern u_int16_t VAL_AnInConf_1;
int doWrite_VAL_AnInConf_1(u_int16_t value);
int addWrite_VAL_AnInConf_1(u_int16_t value);
int getStatus_VAL_AnInConf_1();
 
#define ID_VAL_AnInConf_2 4122
extern u_int16_t VAL_AnInConf_2;
int doWrite_VAL_AnInConf_2(u_int16_t value);
int addWrite_VAL_AnInConf_2(u_int16_t value);
int getStatus_VAL_AnInConf_2();
 
#define ID_VAL_AnInConf_3 4123
extern u_int16_t VAL_AnInConf_3;
int doWrite_VAL_AnInConf_3(u_int16_t value);
int addWrite_VAL_AnInConf_3(u_int16_t value);
int getStatus_VAL_AnInConf_3();
 
#define ID_VAL_AnInConf_4 4124
extern u_int16_t VAL_AnInConf_4;
int doWrite_VAL_AnInConf_4(u_int16_t value);
int addWrite_VAL_AnInConf_4(u_int16_t value);
int getStatus_VAL_AnInConf_4();
 
#define ID_VAL_AnInConf_5 4125
extern u_int16_t VAL_AnInConf_5;
int doWrite_VAL_AnInConf_5(u_int16_t value);
int addWrite_VAL_AnInConf_5(u_int16_t value);
int getStatus_VAL_AnInConf_5();
 
#define ID_VAL_AnInConf_6 4126
extern u_int16_t VAL_AnInConf_6;
int doWrite_VAL_AnInConf_6(u_int16_t value);
int addWrite_VAL_AnInConf_6(u_int16_t value);
int getStatus_VAL_AnInConf_6();
 
#define ID_VAL_AnInConf_7 4127
extern u_int16_t VAL_AnInConf_7;
int doWrite_VAL_AnInConf_7(u_int16_t value);
int addWrite_VAL_AnInConf_7(u_int16_t value);
int getStatus_VAL_AnInConf_7();
 
#define ID_VAL_AnInConf_8 4128
extern u_int16_t VAL_AnInConf_8;
int doWrite_VAL_AnInConf_8(u_int16_t value);
int addWrite_VAL_AnInConf_8(u_int16_t value);
int getStatus_VAL_AnInConf_8();
 
#define ID_VAL_AnInConf_9 4129
extern u_int16_t VAL_AnInConf_9;
int doWrite_VAL_AnInConf_9(u_int16_t value);
int addWrite_VAL_AnInConf_9(u_int16_t value);
int getStatus_VAL_AnInConf_9();
 
#define ID_VAL_AnInConf_10 4130
extern u_int16_t VAL_AnInConf_10;
int doWrite_VAL_AnInConf_10(u_int16_t value);
int addWrite_VAL_AnInConf_10(u_int16_t value);
int getStatus_VAL_AnInConf_10();
 
#define ID_VAL_AnInConf_11 4131
extern u_int16_t VAL_AnInConf_11;
int doWrite_VAL_AnInConf_11(u_int16_t value);
int addWrite_VAL_AnInConf_11(u_int16_t value);
int getStatus_VAL_AnInConf_11();
 
#define ID_VAL_AnInConf_12 4132
extern u_int16_t VAL_AnInConf_12;
int doWrite_VAL_AnInConf_12(u_int16_t value);
int addWrite_VAL_AnInConf_12(u_int16_t value);
int getStatus_VAL_AnInConf_12();
 
#define ID_VAL_AnInFltr_1 4133
extern u_int16_t VAL_AnInFltr_1;
int doWrite_VAL_AnInFltr_1(u_int16_t value);
int addWrite_VAL_AnInFltr_1(u_int16_t value);
int getStatus_VAL_AnInFltr_1();
 
#define ID_VAL_AnInFltr_2 4134
extern u_int16_t VAL_AnInFltr_2;
int doWrite_VAL_AnInFltr_2(u_int16_t value);
int addWrite_VAL_AnInFltr_2(u_int16_t value);
int getStatus_VAL_AnInFltr_2();
 
#define ID_VAL_AnInFltr_3 4135
extern u_int16_t VAL_AnInFltr_3;
int doWrite_VAL_AnInFltr_3(u_int16_t value);
int addWrite_VAL_AnInFltr_3(u_int16_t value);
int getStatus_VAL_AnInFltr_3();
 
#define ID_VAL_AnInFltr_4 4136
extern u_int16_t VAL_AnInFltr_4;
int doWrite_VAL_AnInFltr_4(u_int16_t value);
int addWrite_VAL_AnInFltr_4(u_int16_t value);
int getStatus_VAL_AnInFltr_4();
 
#define ID_VAL_AnInFltr_5 4137
extern u_int16_t VAL_AnInFltr_5;
int doWrite_VAL_AnInFltr_5(u_int16_t value);
int addWrite_VAL_AnInFltr_5(u_int16_t value);
int getStatus_VAL_AnInFltr_5();
 
#define ID_VAL_AnInFltr_6 4138
extern u_int16_t VAL_AnInFltr_6;
int doWrite_VAL_AnInFltr_6(u_int16_t value);
int addWrite_VAL_AnInFltr_6(u_int16_t value);
int getStatus_VAL_AnInFltr_6();
 
#define ID_VAL_AnInFltr_7 4139
extern u_int16_t VAL_AnInFltr_7;
int doWrite_VAL_AnInFltr_7(u_int16_t value);
int addWrite_VAL_AnInFltr_7(u_int16_t value);
int getStatus_VAL_AnInFltr_7();
 
#define ID_VAL_AnInFltr_8 4140
extern u_int16_t VAL_AnInFltr_8;
int doWrite_VAL_AnInFltr_8(u_int16_t value);
int addWrite_VAL_AnInFltr_8(u_int16_t value);
int getStatus_VAL_AnInFltr_8();
 
#define ID_VAL_AnInFltr_9 4141
extern u_int16_t VAL_AnInFltr_9;
int doWrite_VAL_AnInFltr_9(u_int16_t value);
int addWrite_VAL_AnInFltr_9(u_int16_t value);
int getStatus_VAL_AnInFltr_9();
 
#define ID_VAL_AnInFltr_10 4142
extern u_int16_t VAL_AnInFltr_10;
int doWrite_VAL_AnInFltr_10(u_int16_t value);
int addWrite_VAL_AnInFltr_10(u_int16_t value);
int getStatus_VAL_AnInFltr_10();
 
#define ID_VAL_AnInFltr_11 4143
extern u_int16_t VAL_AnInFltr_11;
int doWrite_VAL_AnInFltr_11(u_int16_t value);
int addWrite_VAL_AnInFltr_11(u_int16_t value);
int getStatus_VAL_AnInFltr_11();
 
#define ID_VAL_AnInFltr_12 4144
extern u_int16_t VAL_AnInFltr_12;
int doWrite_VAL_AnInFltr_12(u_int16_t value);
int addWrite_VAL_AnInFltr_12(u_int16_t value);
int getStatus_VAL_AnInFltr_12();
 
#define ID_RES_AnIn_1 4145
extern int16_t RES_AnIn_1;
int doWrite_RES_AnIn_1(int16_t value);
int addWrite_RES_AnIn_1(int16_t value);
int getStatus_RES_AnIn_1();
 
#define ID_RES_AnIn_2 4146
extern int16_t RES_AnIn_2;
int doWrite_RES_AnIn_2(int16_t value);
int addWrite_RES_AnIn_2(int16_t value);
int getStatus_RES_AnIn_2();
 
#define ID_RES_AnIn_3 4147
extern int16_t RES_AnIn_3;
int doWrite_RES_AnIn_3(int16_t value);
int addWrite_RES_AnIn_3(int16_t value);
int getStatus_RES_AnIn_3();
 
#define ID_RES_AnIn_4 4148
extern int16_t RES_AnIn_4;
int doWrite_RES_AnIn_4(int16_t value);
int addWrite_RES_AnIn_4(int16_t value);
int getStatus_RES_AnIn_4();
 
#define ID_RES_AnIn_5 4149
extern int16_t RES_AnIn_5;
int doWrite_RES_AnIn_5(int16_t value);
int addWrite_RES_AnIn_5(int16_t value);
int getStatus_RES_AnIn_5();
 
#define ID_RES_AnIn_6 4150
extern int16_t RES_AnIn_6;
int doWrite_RES_AnIn_6(int16_t value);
int addWrite_RES_AnIn_6(int16_t value);
int getStatus_RES_AnIn_6();
 
#define ID_RES_AnIn_7 4151
extern int16_t RES_AnIn_7;
int doWrite_RES_AnIn_7(int16_t value);
int addWrite_RES_AnIn_7(int16_t value);
int getStatus_RES_AnIn_7();
 
#define ID_RES_AnIn_8 4152
extern int16_t RES_AnIn_8;
int doWrite_RES_AnIn_8(int16_t value);
int addWrite_RES_AnIn_8(int16_t value);
int getStatus_RES_AnIn_8();
 
#define ID_RES_AnIn_9 4153
extern int16_t RES_AnIn_9;
int doWrite_RES_AnIn_9(int16_t value);
int addWrite_RES_AnIn_9(int16_t value);
int getStatus_RES_AnIn_9();
 
#define ID_RES_AnIn_10 4154
extern int16_t RES_AnIn_10;
int doWrite_RES_AnIn_10(int16_t value);
int addWrite_RES_AnIn_10(int16_t value);
int getStatus_RES_AnIn_10();
 
#define ID_RES_AnIn_11 4155
extern int16_t RES_AnIn_11;
int doWrite_RES_AnIn_11(int16_t value);
int addWrite_RES_AnIn_11(int16_t value);
int getStatus_RES_AnIn_11();
 
#define ID_RES_AnIn_12 4156
extern int16_t RES_AnIn_12;
int doWrite_RES_AnIn_12(int16_t value);
int addWrite_RES_AnIn_12(int16_t value);
int getStatus_RES_AnIn_12();
 
#define ID_RES_AnInStts_1 4157
extern int16_t RES_AnInStts_1;
int doWrite_RES_AnInStts_1(int16_t value);
int addWrite_RES_AnInStts_1(int16_t value);
int getStatus_RES_AnInStts_1();
 
#define ID_RES_AnInStts_2 4158
extern int16_t RES_AnInStts_2;
int doWrite_RES_AnInStts_2(int16_t value);
int addWrite_RES_AnInStts_2(int16_t value);
int getStatus_RES_AnInStts_2();
 
#define ID_RES_AnInStts_3 4159
extern int16_t RES_AnInStts_3;
int doWrite_RES_AnInStts_3(int16_t value);
int addWrite_RES_AnInStts_3(int16_t value);
int getStatus_RES_AnInStts_3();
 
#define ID_RES_AnInStts_4 4160
extern int16_t RES_AnInStts_4;
int doWrite_RES_AnInStts_4(int16_t value);
int addWrite_RES_AnInStts_4(int16_t value);
int getStatus_RES_AnInStts_4();
 
#define ID_RES_AnInStts_5 4161
extern int16_t RES_AnInStts_5;
int doWrite_RES_AnInStts_5(int16_t value);
int addWrite_RES_AnInStts_5(int16_t value);
int getStatus_RES_AnInStts_5();
 
#define ID_RES_AnInStts_6 4162
extern int16_t RES_AnInStts_6;
int doWrite_RES_AnInStts_6(int16_t value);
int addWrite_RES_AnInStts_6(int16_t value);
int getStatus_RES_AnInStts_6();
 
#define ID_RES_AnInStts_7 4163
extern int16_t RES_AnInStts_7;
int doWrite_RES_AnInStts_7(int16_t value);
int addWrite_RES_AnInStts_7(int16_t value);
int getStatus_RES_AnInStts_7();
 
#define ID_RES_AnInStts_8 4164
extern int16_t RES_AnInStts_8;
int doWrite_RES_AnInStts_8(int16_t value);
int addWrite_RES_AnInStts_8(int16_t value);
int getStatus_RES_AnInStts_8();
 
#define ID_RES_AnInStts_9 4165
extern int16_t RES_AnInStts_9;
int doWrite_RES_AnInStts_9(int16_t value);
int addWrite_RES_AnInStts_9(int16_t value);
int getStatus_RES_AnInStts_9();
 
#define ID_RES_AnInStts_10 4166
extern int16_t RES_AnInStts_10;
int doWrite_RES_AnInStts_10(int16_t value);
int addWrite_RES_AnInStts_10(int16_t value);
int getStatus_RES_AnInStts_10();
 
#define ID_RES_AnInStts_11 4167
extern int16_t RES_AnInStts_11;
int doWrite_RES_AnInStts_11(int16_t value);
int addWrite_RES_AnInStts_11(int16_t value);
int getStatus_RES_AnInStts_11();
 
#define ID_RES_AnInStts_12 4168
extern int16_t RES_AnInStts_12;
int doWrite_RES_AnInStts_12(int16_t value);
int addWrite_RES_AnInStts_12(int16_t value);
int getStatus_RES_AnInStts_12();
 
#define ID_TST_AnOut_1 4169
extern int TST_AnOut_1;
int doWrite_TST_AnOut_1(int value);
int addWrite_TST_AnOut_1(int value);
int getStatus_TST_AnOut_1();
 
#define ID_TST_AnOut_2 4170
extern int TST_AnOut_2;
int doWrite_TST_AnOut_2(int value);
int addWrite_TST_AnOut_2(int value);
int getStatus_TST_AnOut_2();
 
#define ID_TST_AnOut_3 4171
extern int TST_AnOut_3;
int doWrite_TST_AnOut_3(int value);
int addWrite_TST_AnOut_3(int value);
int getStatus_TST_AnOut_3();
 
#define ID_TST_AnOut_4 4172
extern int TST_AnOut_4;
int doWrite_TST_AnOut_4(int value);
int addWrite_TST_AnOut_4(int value);
int getStatus_TST_AnOut_4();
 
#define ID_VAL_AnOut_1 4173
extern int16_t VAL_AnOut_1;
int doWrite_VAL_AnOut_1(int16_t value);
int addWrite_VAL_AnOut_1(int16_t value);
int getStatus_VAL_AnOut_1();
 
#define ID_VAL_AnOut_2 4174
extern int16_t VAL_AnOut_2;
int doWrite_VAL_AnOut_2(int16_t value);
int addWrite_VAL_AnOut_2(int16_t value);
int getStatus_VAL_AnOut_2();
 
#define ID_VAL_AnOut_3 4175
extern int16_t VAL_AnOut_3;
int doWrite_VAL_AnOut_3(int16_t value);
int addWrite_VAL_AnOut_3(int16_t value);
int getStatus_VAL_AnOut_3();
 
#define ID_VAL_AnOut_4 4176
extern int16_t VAL_AnOut_4;
int doWrite_VAL_AnOut_4(int16_t value);
int addWrite_VAL_AnOut_4(int16_t value);
int getStatus_VAL_AnOut_4();
 
#define ID_VAL_AnOutConf_1 4177
extern u_int16_t VAL_AnOutConf_1;
int doWrite_VAL_AnOutConf_1(u_int16_t value);
int addWrite_VAL_AnOutConf_1(u_int16_t value);
int getStatus_VAL_AnOutConf_1();
 
#define ID_VAL_AnOutConf_2 4178
extern u_int16_t VAL_AnOutConf_2;
int doWrite_VAL_AnOutConf_2(u_int16_t value);
int addWrite_VAL_AnOutConf_2(u_int16_t value);
int getStatus_VAL_AnOutConf_2();
 
#define ID_VAL_AnOutConf_3 4179
extern u_int16_t VAL_AnOutConf_3;
int doWrite_VAL_AnOutConf_3(u_int16_t value);
int addWrite_VAL_AnOutConf_3(u_int16_t value);
int getStatus_VAL_AnOutConf_3();
 
#define ID_VAL_AnOutConf_4 4180
extern u_int16_t VAL_AnOutConf_4;
int doWrite_VAL_AnOutConf_4(u_int16_t value);
int addWrite_VAL_AnOutConf_4(u_int16_t value);
int getStatus_VAL_AnOutConf_4();
 
#define ID_RES_AnOutStts_1 4181
extern int16_t RES_AnOutStts_1;
int doWrite_RES_AnOutStts_1(int16_t value);
int addWrite_RES_AnOutStts_1(int16_t value);
int getStatus_RES_AnOutStts_1();
 
#define ID_RES_AnOutStts_2 4182
extern int16_t RES_AnOutStts_2;
int doWrite_RES_AnOutStts_2(int16_t value);
int addWrite_RES_AnOutStts_2(int16_t value);
int getStatus_RES_AnOutStts_2();
 
#define ID_RES_AnOutStts_3 4183
extern int16_t RES_AnOutStts_3;
int doWrite_RES_AnOutStts_3(int16_t value);
int addWrite_RES_AnOutStts_3(int16_t value);
int getStatus_RES_AnOutStts_3();
 
#define ID_RES_AnOutStts_4 4184
extern int16_t RES_AnOutStts_4;
int doWrite_RES_AnOutStts_4(int16_t value);
int addWrite_RES_AnOutStts_4(int16_t value);
int getStatus_RES_AnOutStts_4();
 
#define ID_TST_Tamb 4185
extern int TST_Tamb;
int doWrite_TST_Tamb(int value);
int addWrite_TST_Tamb(int value);
int getStatus_TST_Tamb();
 
#define ID_TST_RPM 4186
extern int TST_RPM;
int doWrite_TST_RPM(int value);
int addWrite_TST_RPM(int value);
int getStatus_TST_RPM();
 
#define ID_TST_FWrevision 4187
extern int TST_FWrevision;
int doWrite_TST_FWrevision(int value);
int addWrite_TST_FWrevision(int value);
int getStatus_TST_FWrevision();
 
#define ID_TST_HWconfig 4188
extern int TST_HWconfig;
int doWrite_TST_HWconfig(int value);
int addWrite_TST_HWconfig(int value);
int getStatus_TST_HWconfig();
 
#define ID_VAL_Tamb 4189
extern int16_t VAL_Tamb;
int doWrite_VAL_Tamb(int16_t value);
int addWrite_VAL_Tamb(int16_t value);
int getStatus_VAL_Tamb();
 
#define ID_VAL_RPM 4190
extern u_int16_t VAL_RPM;
int doWrite_VAL_RPM(u_int16_t value);
int addWrite_VAL_RPM(u_int16_t value);
int getStatus_VAL_RPM();
 
#define ID_VAL_FWrevision 4191
extern u_int16_t VAL_FWrevision;
int doWrite_VAL_FWrevision(u_int16_t value);
int addWrite_VAL_FWrevision(u_int16_t value);
int getStatus_VAL_FWrevision();
 
#define ID_VAL_HWconfig 4192
extern u_int16_t VAL_HWconfig;
int doWrite_VAL_HWconfig(u_int16_t value);
int addWrite_VAL_HWconfig(u_int16_t value);
int getStatus_VAL_HWconfig();
 
#define ID_RES_Tamb 4193
extern int16_t RES_Tamb;
int doWrite_RES_Tamb(int16_t value);
int addWrite_RES_Tamb(int16_t value);
int getStatus_RES_Tamb();
 
#define ID_RES_RPM 4194
extern u_int16_t RES_RPM;
int doWrite_RES_RPM(u_int16_t value);
int addWrite_RES_RPM(u_int16_t value);
int getStatus_RES_RPM();
 
#define ID_RES_FWrevision 4195
extern u_int16_t RES_FWrevision;
int doWrite_RES_FWrevision(u_int16_t value);
int addWrite_RES_FWrevision(u_int16_t value);
int getStatus_RES_FWrevision();
 
#define ID_RES_HWconfig 4196
extern u_int16_t RES_HWconfig;
int doWrite_RES_HWconfig(u_int16_t value);
int addWrite_RES_HWconfig(u_int16_t value);
int getStatus_RES_HWconfig();
 
#define ID_TST_RTUS_WR 4197
extern int TST_RTUS_WR;
int doWrite_TST_RTUS_WR(int value);
int addWrite_TST_RTUS_WR(int value);
int getStatus_TST_RTUS_WR();
 
#define ID_TST_RTUS_RD 4198
extern int TST_RTUS_RD;
int doWrite_TST_RTUS_RD(int value);
int addWrite_TST_RTUS_RD(int value);
int getStatus_TST_RTUS_RD();
 
#define ID_TST_RTU_WR 4199
extern int TST_RTU_WR;
int doWrite_TST_RTU_WR(int value);
int addWrite_TST_RTU_WR(int value);
int getStatus_TST_RTU_WR();
 
#define ID_TST_RTU_RD 4200
extern int TST_RTU_RD;
int doWrite_TST_RTU_RD(int value);
int addWrite_TST_RTU_RD(int value);
int getStatus_TST_RTU_RD();
 
#define ID_TST_RTU3_WR 4201
extern int TST_RTU3_WR;
int doWrite_TST_RTU3_WR(int value);
int addWrite_TST_RTU3_WR(int value);
int getStatus_TST_RTU3_WR();
 
#define ID_TST_RTU3_RD 4202
extern int TST_RTU3_RD;
int doWrite_TST_RTU3_RD(int value);
int addWrite_TST_RTU3_RD(int value);
int getStatus_TST_RTU3_RD();
 
#define ID_TST_CAN_WR 4203
extern int TST_CAN_WR;
int doWrite_TST_CAN_WR(int value);
int addWrite_TST_CAN_WR(int value);
int getStatus_TST_CAN_WR();
 
#define ID_TST_CAN_RD 4204
extern int TST_CAN_RD;
int doWrite_TST_CAN_RD(int value);
int addWrite_TST_CAN_RD(int value);
int getStatus_TST_CAN_RD();
 
#define ID_VAL_RTUS_WR 4205
extern int VAL_RTUS_WR;
int doWrite_VAL_RTUS_WR(int value);
int addWrite_VAL_RTUS_WR(int value);
int getStatus_VAL_RTUS_WR();
 
#define ID_VAL_RTUS_RD 4206
extern int VAL_RTUS_RD;
int doWrite_VAL_RTUS_RD(int value);
int addWrite_VAL_RTUS_RD(int value);
int getStatus_VAL_RTUS_RD();
 
#define ID_VAL_RTU_WR 4207
extern int VAL_RTU_WR;
int doWrite_VAL_RTU_WR(int value);
int addWrite_VAL_RTU_WR(int value);
int getStatus_VAL_RTU_WR();
 
#define ID_VAL_RTU_RD 4208
extern int VAL_RTU_RD;
int doWrite_VAL_RTU_RD(int value);
int addWrite_VAL_RTU_RD(int value);
int getStatus_VAL_RTU_RD();
 
#define ID_VAL_RTU3_WR 4209
extern int VAL_RTU3_WR;
int doWrite_VAL_RTU3_WR(int value);
int addWrite_VAL_RTU3_WR(int value);
int getStatus_VAL_RTU3_WR();
 
#define ID_VAL_RTU3_RD 4210
extern int VAL_RTU3_RD;
int doWrite_VAL_RTU3_RD(int value);
int addWrite_VAL_RTU3_RD(int value);
int getStatus_VAL_RTU3_RD();
 
#define ID_VAL_CAN_WR 4211
extern int VAL_CAN_WR;
int doWrite_VAL_CAN_WR(int value);
int addWrite_VAL_CAN_WR(int value);
int getStatus_VAL_CAN_WR();
 
#define ID_VAL_CAN_RD 4212
extern int VAL_CAN_RD;
int doWrite_VAL_CAN_RD(int value);
int addWrite_VAL_CAN_RD(int value);
int getStatus_VAL_CAN_RD();
 
#define ID_RES_RTUS_WR 4213
extern int RES_RTUS_WR;
int doWrite_RES_RTUS_WR(int value);
int addWrite_RES_RTUS_WR(int value);
int getStatus_RES_RTUS_WR();
 
#define ID_RES_RTUS_RD 4214
extern int RES_RTUS_RD;
int doWrite_RES_RTUS_RD(int value);
int addWrite_RES_RTUS_RD(int value);
int getStatus_RES_RTUS_RD();
 
#define ID_RES_RTU_WR 4215
extern int RES_RTU_WR;
int doWrite_RES_RTU_WR(int value);
int addWrite_RES_RTU_WR(int value);
int getStatus_RES_RTU_WR();
 
#define ID_RES_RTU_RD 4216
extern int RES_RTU_RD;
int doWrite_RES_RTU_RD(int value);
int addWrite_RES_RTU_RD(int value);
int getStatus_RES_RTU_RD();
 
#define ID_RES_RTU3_WR 4217
extern int RES_RTU3_WR;
int doWrite_RES_RTU3_WR(int value);
int addWrite_RES_RTU3_WR(int value);
int getStatus_RES_RTU3_WR();
 
#define ID_RES_RTU3_RD 4218
extern int RES_RTU3_RD;
int doWrite_RES_RTU3_RD(int value);
int addWrite_RES_RTU3_RD(int value);
int getStatus_RES_RTU3_RD();
 
#define ID_RES_CAN_WR 4219
extern int RES_CAN_WR;
int doWrite_RES_CAN_WR(int value);
int addWrite_RES_CAN_WR(int value);
int getStatus_RES_CAN_WR();
 
#define ID_RES_CAN_RD 4220
extern int RES_CAN_RD;
int doWrite_RES_CAN_RD(int value);
int addWrite_RES_CAN_RD(int value);
int getStatus_RES_CAN_RD();
 
#define ID_STATUS_LOCAL 4221
extern int STATUS_LOCAL;
int doWrite_STATUS_LOCAL(int value);
int addWrite_STATUS_LOCAL(int value);
int getStatus_STATUS_LOCAL();
 
#define ID_STATUS_REMOTE 4222
extern int STATUS_REMOTE;
int doWrite_STATUS_REMOTE(int value);
int addWrite_STATUS_REMOTE(int value);
int getStatus_STATUS_REMOTE();
 
#define ID_STATUS_DONE 4223
extern int STATUS_DONE;
int doWrite_STATUS_DONE(int value);
int addWrite_STATUS_DONE(int value);
int getStatus_STATUS_DONE();
 
#define ID_PLC_FWrevision 5300
extern u_int16_t PLC_FWrevision;
int doWrite_PLC_FWrevision(u_int16_t value);
int addWrite_PLC_FWrevision(u_int16_t value);
int getStatus_PLC_FWrevision();
 
#define ID_PLC_HWconfig 5301
extern u_int16_t PLC_HWconfig;
int doWrite_PLC_HWconfig(u_int16_t value);
int addWrite_PLC_HWconfig(u_int16_t value);
int getStatus_PLC_HWconfig();
 
#define ID_PLC_DigDir_1 5302
extern int PLC_DigDir_1;
int doWrite_PLC_DigDir_1(int value);
int addWrite_PLC_DigDir_1(int value);
int getStatus_PLC_DigDir_1();
 
#define ID_PLC_DigDir_2 5303
extern int PLC_DigDir_2;
int doWrite_PLC_DigDir_2(int value);
int addWrite_PLC_DigDir_2(int value);
int getStatus_PLC_DigDir_2();
 
#define ID_PLC_DigDir_3 5304
extern int PLC_DigDir_3;
int doWrite_PLC_DigDir_3(int value);
int addWrite_PLC_DigDir_3(int value);
int getStatus_PLC_DigDir_3();
 
#define ID_PLC_DigDir_4 5305
extern int PLC_DigDir_4;
int doWrite_PLC_DigDir_4(int value);
int addWrite_PLC_DigDir_4(int value);
int getStatus_PLC_DigDir_4();
 
#define ID_PLC_DigDir_5 5306
extern int PLC_DigDir_5;
int doWrite_PLC_DigDir_5(int value);
int addWrite_PLC_DigDir_5(int value);
int getStatus_PLC_DigDir_5();
 
#define ID_PLC_DigDir_6 5307
extern int PLC_DigDir_6;
int doWrite_PLC_DigDir_6(int value);
int addWrite_PLC_DigDir_6(int value);
int getStatus_PLC_DigDir_6();
 
#define ID_PLC_DigDir_7 5308
extern int PLC_DigDir_7;
int doWrite_PLC_DigDir_7(int value);
int addWrite_PLC_DigDir_7(int value);
int getStatus_PLC_DigDir_7();
 
#define ID_PLC_DigDir_8 5309
extern int PLC_DigDir_8;
int doWrite_PLC_DigDir_8(int value);
int addWrite_PLC_DigDir_8(int value);
int getStatus_PLC_DigDir_8();
 
#define ID_PLC_AnInConf_1 5310
extern u_int16_t PLC_AnInConf_1;
int doWrite_PLC_AnInConf_1(u_int16_t value);
int addWrite_PLC_AnInConf_1(u_int16_t value);
int getStatus_PLC_AnInConf_1();
 
#define ID_PLC_AnInConf_2 5311
extern u_int16_t PLC_AnInConf_2;
int doWrite_PLC_AnInConf_2(u_int16_t value);
int addWrite_PLC_AnInConf_2(u_int16_t value);
int getStatus_PLC_AnInConf_2();
 
#define ID_PLC_AnOutConf_1 5312
extern u_int16_t PLC_AnOutConf_1;
int doWrite_PLC_AnOutConf_1(u_int16_t value);
int addWrite_PLC_AnOutConf_1(u_int16_t value);
int getStatus_PLC_AnOutConf_1();
 
#define ID_PLC_DigIn_1 5313
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int addWrite_PLC_DigIn_1(int value);
int getStatus_PLC_DigIn_1();
 
#define ID_PLC_DigIn_2 5314
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int addWrite_PLC_DigIn_2(int value);
int getStatus_PLC_DigIn_2();
 
#define ID_PLC_DigIn_3 5315
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int addWrite_PLC_DigIn_3(int value);
int getStatus_PLC_DigIn_3();
 
#define ID_PLC_DigIn_4 5316
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int addWrite_PLC_DigIn_4(int value);
int getStatus_PLC_DigIn_4();
 
#define ID_PLC_DigIn_5 5317
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int addWrite_PLC_DigIn_5(int value);
int getStatus_PLC_DigIn_5();
 
#define ID_PLC_DigIn_6 5318
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int addWrite_PLC_DigIn_6(int value);
int getStatus_PLC_DigIn_6();
 
#define ID_PLC_DigIn_7 5319
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int addWrite_PLC_DigIn_7(int value);
int getStatus_PLC_DigIn_7();
 
#define ID_PLC_DigIn_8 5320
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int addWrite_PLC_DigIn_8(int value);
int getStatus_PLC_DigIn_8();
 
#define ID_PLC_DigIn_9 5321
extern int PLC_DigIn_9;
int doWrite_PLC_DigIn_9(int value);
int addWrite_PLC_DigIn_9(int value);
int getStatus_PLC_DigIn_9();
 
#define ID_PLC_DigIn_10 5322
extern int PLC_DigIn_10;
int doWrite_PLC_DigIn_10(int value);
int addWrite_PLC_DigIn_10(int value);
int getStatus_PLC_DigIn_10();
 
#define ID_PLC_DigIn_11 5323
extern int PLC_DigIn_11;
int doWrite_PLC_DigIn_11(int value);
int addWrite_PLC_DigIn_11(int value);
int getStatus_PLC_DigIn_11();
 
#define ID_PLC_DigIn_12 5324
extern int PLC_DigIn_12;
int doWrite_PLC_DigIn_12(int value);
int addWrite_PLC_DigIn_12(int value);
int getStatus_PLC_DigIn_12();
 
#define ID_PLC_AnIn_1 5325
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int addWrite_PLC_AnIn_1(int16_t value);
int getStatus_PLC_AnIn_1();
 
#define ID_PLC_AnIn_2 5326
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int addWrite_PLC_AnIn_2(int16_t value);
int getStatus_PLC_AnIn_2();
 
#define ID_PLC_Tamb 5327
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int addWrite_PLC_Tamb(int16_t value);
int getStatus_PLC_Tamb();
 
#define ID_PLC_Encoder 5328
extern u_int32_t PLC_Encoder;
int doWrite_PLC_Encoder(u_int32_t value);
int addWrite_PLC_Encoder(u_int32_t value);
int getStatus_PLC_Encoder();
 
#define ID_PLC_DigOut_1 5329
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int addWrite_PLC_DigOut_1(int value);
int getStatus_PLC_DigOut_1();
 
#define ID_PLC_DigOut_2 5330
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int addWrite_PLC_DigOut_2(int value);
int getStatus_PLC_DigOut_2();
 
#define ID_PLC_DigOut_3 5331
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int addWrite_PLC_DigOut_3(int value);
int getStatus_PLC_DigOut_3();
 
#define ID_PLC_DigOut_4 5332
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int addWrite_PLC_DigOut_4(int value);
int getStatus_PLC_DigOut_4();
 
#define ID_PLC_DigOut_5 5333
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int addWrite_PLC_DigOut_5(int value);
int getStatus_PLC_DigOut_5();
 
#define ID_PLC_DigOut_6 5334
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int addWrite_PLC_DigOut_6(int value);
int getStatus_PLC_DigOut_6();
 
#define ID_PLC_DigOut_7 5335
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int addWrite_PLC_DigOut_7(int value);
int getStatus_PLC_DigOut_7();
 
#define ID_PLC_DigOut_8 5336
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int addWrite_PLC_DigOut_8(int value);
int getStatus_PLC_DigOut_8();
 
#define ID_PLC_AnOut_1 5337
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int addWrite_PLC_AnOut_1(int16_t value);
int getStatus_PLC_AnOut_1();
 
#define ID_PLC_EncEnable 5338
extern u_int16_t PLC_EncEnable;
int doWrite_PLC_EncEnable(u_int16_t value);
int addWrite_PLC_EncEnable(u_int16_t value);
int getStatus_PLC_EncEnable();
 
#define ID_PLC_EncoderReset 5339
extern u_int16_t PLC_EncoderReset;
int doWrite_PLC_EncoderReset(u_int16_t value);
int addWrite_PLC_EncoderReset(u_int16_t value);
int getStatus_PLC_EncoderReset();
 
#define ID_PLC_Reserved_16 5340
extern u_int16_t PLC_Reserved_16;
int doWrite_PLC_Reserved_16(u_int16_t value);
int addWrite_PLC_Reserved_16(u_int16_t value);
int getStatus_PLC_Reserved_16();
 
#define ID_PLC_Reserved_17 5341
extern u_int16_t PLC_Reserved_17;
int doWrite_PLC_Reserved_17(u_int16_t value);
int addWrite_PLC_Reserved_17(u_int16_t value);
int getStatus_PLC_Reserved_17();
 
#define ID_PLC_Reserved_18 5342
extern u_int16_t PLC_Reserved_18;
int doWrite_PLC_Reserved_18(u_int16_t value);
int addWrite_PLC_Reserved_18(u_int16_t value);
int getStatus_PLC_Reserved_18();
 
#define ID_PLC_Reserved_19 5343
extern u_int16_t PLC_Reserved_19;
int doWrite_PLC_Reserved_19(u_int16_t value);
int addWrite_PLC_Reserved_19(u_int16_t value);
int getStatus_PLC_Reserved_19();
 
#define ID_PLC_Heartbeat 5344
extern u_int16_t PLC_Heartbeat;
int doWrite_PLC_Heartbeat(u_int16_t value);
int addWrite_PLC_Heartbeat(u_int16_t value);
int getStatus_PLC_Heartbeat();
 
#define ID_PLC_time 5390
extern float PLC_time;
int doWrite_PLC_time(float value);
int addWrite_PLC_time(float value);
int getStatus_PLC_time();
 
#define ID_PLC_timeMin 5391
extern float PLC_timeMin;
int doWrite_PLC_timeMin(float value);
int addWrite_PLC_timeMin(float value);
int getStatus_PLC_timeMin();
 
#define ID_PLC_timeMax 5392
extern float PLC_timeMax;
int doWrite_PLC_timeMax(float value);
int addWrite_PLC_timeMax(float value);
int getStatus_PLC_timeMax();
 
#define ID_PLC_timeWin 5393
extern float PLC_timeWin;
int doWrite_PLC_timeWin(float value);
int addWrite_PLC_timeWin(float value);
int getStatus_PLC_timeWin();
 
#ifdef __cplusplus
}
#endif
#endif
