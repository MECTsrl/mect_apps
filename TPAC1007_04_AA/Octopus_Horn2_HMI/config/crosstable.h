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
