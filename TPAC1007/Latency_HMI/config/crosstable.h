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
 
#define ID_RISING_FRONT 193
extern int RISING_FRONT;
int doWrite_RISING_FRONT(int value);
int prepareWrite_RISING_FRONT(int value);
 
#define ID_FALLING_FRONT 194
extern int FALLING_FRONT;
int doWrite_FALLING_FRONT(int value);
int prepareWrite_FALLING_FRONT(int value);
 
#define ID_AAA 1345
extern int32_t AAA;
int doWrite_AAA(int32_t value);
int prepareWrite_AAA(int32_t value);
 
#define ID_BBB 1346
extern int32_t BBB;
int doWrite_BBB(int32_t value);
int prepareWrite_BBB(int32_t value);
 
#define ID_CCC 1347
extern float CCC;
int doWrite_CCC(float value);
int prepareWrite_CCC(float value);
 
#define ID_DDD 1348
extern float DDD;
int doWrite_DDD(float value);
int prepareWrite_DDD(float value);
 
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
 
#define ID_PLC_DigIn_1 5313
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int prepareWrite_PLC_DigIn_1(int value);
 
#define ID_PLC_DigIn_2 5314
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int prepareWrite_PLC_DigIn_2(int value);
 
#define ID_PLC_DigIn_3 5315
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int prepareWrite_PLC_DigIn_3(int value);
 
#define ID_PLC_DigIn_4 5316
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int prepareWrite_PLC_DigIn_4(int value);
 
#define ID_PLC_DigIn_5 5317
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int prepareWrite_PLC_DigIn_5(int value);
 
#define ID_PLC_DigIn_6 5318
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int prepareWrite_PLC_DigIn_6(int value);
 
#define ID_PLC_DigIn_7 5319
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int prepareWrite_PLC_DigIn_7(int value);
 
#define ID_PLC_DigIn_8 5320
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int prepareWrite_PLC_DigIn_8(int value);
 
#define ID_PLC_DigIn_9 5321
extern int PLC_DigIn_9;
int doWrite_PLC_DigIn_9(int value);
int prepareWrite_PLC_DigIn_9(int value);
 
#define ID_PLC_DigIn_10 5322
extern int PLC_DigIn_10;
int doWrite_PLC_DigIn_10(int value);
int prepareWrite_PLC_DigIn_10(int value);
 
#define ID_PLC_DigIn_11 5323
extern int PLC_DigIn_11;
int doWrite_PLC_DigIn_11(int value);
int prepareWrite_PLC_DigIn_11(int value);
 
#define ID_PLC_DigIn_12 5324
extern int PLC_DigIn_12;
int doWrite_PLC_DigIn_12(int value);
int prepareWrite_PLC_DigIn_12(int value);
 
#define ID_PLC_AnIn_1 5325
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int prepareWrite_PLC_AnIn_1(int16_t value);
 
#define ID_PLC_AnIn_2 5326
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int prepareWrite_PLC_AnIn_2(int16_t value);
 
#define ID_PLC_Tamb 5327
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int prepareWrite_PLC_Tamb(int16_t value);
 
#define ID_PLC_Encoder 5328
extern u_int32_t PLC_Encoder;
int doWrite_PLC_Encoder(u_int32_t value);
int prepareWrite_PLC_Encoder(u_int32_t value);
 
#define ID_PLC_DigOut_1 5329
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int prepareWrite_PLC_DigOut_1(int value);
 
#define ID_PLC_DigOut_2 5330
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int prepareWrite_PLC_DigOut_2(int value);
 
#define ID_PLC_DigOut_3 5331
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int prepareWrite_PLC_DigOut_3(int value);
 
#define ID_PLC_DigOut_4 5332
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int prepareWrite_PLC_DigOut_4(int value);
 
#define ID_PLC_DigOut_5 5333
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int prepareWrite_PLC_DigOut_5(int value);
 
#define ID_PLC_DigOut_6 5334
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int prepareWrite_PLC_DigOut_6(int value);
 
#define ID_PLC_DigOut_7 5335
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int prepareWrite_PLC_DigOut_7(int value);
 
#define ID_PLC_DigOut_8 5336
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int prepareWrite_PLC_DigOut_8(int value);
 
#define ID_PLC_AnOut_1 5337
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int prepareWrite_PLC_AnOut_1(int16_t value);
 
#define ID_PLC_EncEnable 5338
extern u_int16_t PLC_EncEnable;
int doWrite_PLC_EncEnable(u_int16_t value);
int prepareWrite_PLC_EncEnable(u_int16_t value);
 
#define ID_PLC_EncoderReset 5339
extern u_int16_t PLC_EncoderReset;
int doWrite_PLC_EncoderReset(u_int16_t value);
int prepareWrite_PLC_EncoderReset(u_int16_t value);
 
#define ID_PLC_Reserved_16 5340
extern u_int16_t PLC_Reserved_16;
int doWrite_PLC_Reserved_16(u_int16_t value);
int prepareWrite_PLC_Reserved_16(u_int16_t value);
 
#define ID_PLC_Reserved_17 5341
extern u_int16_t PLC_Reserved_17;
int doWrite_PLC_Reserved_17(u_int16_t value);
int prepareWrite_PLC_Reserved_17(u_int16_t value);
 
#define ID_PLC_Reserved_18 5342
extern u_int16_t PLC_Reserved_18;
int doWrite_PLC_Reserved_18(u_int16_t value);
int prepareWrite_PLC_Reserved_18(u_int16_t value);
 
#define ID_PLC_Reserved_19 5343
extern u_int16_t PLC_Reserved_19;
int doWrite_PLC_Reserved_19(u_int16_t value);
int prepareWrite_PLC_Reserved_19(u_int16_t value);
 
#define ID_PLC_Heartbeat 5344
extern u_int16_t PLC_Heartbeat;
int doWrite_PLC_Heartbeat(u_int16_t value);
int prepareWrite_PLC_Heartbeat(u_int16_t value);
 
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
 
#ifdef __cplusplus
}
#endif
#endif
