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
 
#define ID_PLC_DigIn_1 5300
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int prepareWrite_PLC_DigIn_1(int value);
 
#define ID_PLC_DigIn_2 5301
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int prepareWrite_PLC_DigIn_2(int value);
 
#define ID_PLC_DigIn_3 5302
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int prepareWrite_PLC_DigIn_3(int value);
 
#define ID_PLC_DigIn_4 5303
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int prepareWrite_PLC_DigIn_4(int value);
 
#define ID_PLC_DigIn_5 5304
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int prepareWrite_PLC_DigIn_5(int value);
 
#define ID_PLC_DigIn_6 5305
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int prepareWrite_PLC_DigIn_6(int value);
 
#define ID_PLC_DigIn_7 5306
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int prepareWrite_PLC_DigIn_7(int value);
 
#define ID_PLC_DigIn_8 5307
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int prepareWrite_PLC_DigIn_8(int value);
 
#define ID_PLC_DigIn_9 5308
extern int PLC_DigIn_9;
int doWrite_PLC_DigIn_9(int value);
int prepareWrite_PLC_DigIn_9(int value);
 
#define ID_PLC_DigIn_17 5309
extern int PLC_DigIn_17;
int doWrite_PLC_DigIn_17(int value);
int prepareWrite_PLC_DigIn_17(int value);
 
#define ID_PLC_DigIn_25 5310
extern int PLC_DigIn_25;
int doWrite_PLC_DigIn_25(int value);
int prepareWrite_PLC_DigIn_25(int value);
 
#define ID_PLC_DigOut_1 5311
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int prepareWrite_PLC_DigOut_1(int value);
 
#define ID_PLC_DigOut_2 5312
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int prepareWrite_PLC_DigOut_2(int value);
 
#define ID_PLC_DigOut_3 5313
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int prepareWrite_PLC_DigOut_3(int value);
 
#define ID_PLC_DigOut_4 5314
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int prepareWrite_PLC_DigOut_4(int value);
 
#define ID_PLC_DigOut_5 5315
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int prepareWrite_PLC_DigOut_5(int value);
 
#define ID_PLC_DigOut_6 5316
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int prepareWrite_PLC_DigOut_6(int value);
 
#define ID_PLC_DigOut_7 5317
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int prepareWrite_PLC_DigOut_7(int value);
 
#define ID_PLC_DigOut_8 5318
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int prepareWrite_PLC_DigOut_8(int value);
 
#define ID_PLC_DigOut_9 5319
extern int PLC_DigOut_9;
int doWrite_PLC_DigOut_9(int value);
int prepareWrite_PLC_DigOut_9(int value);
 
#define ID_PLC_DigOut_10 5320
extern int PLC_DigOut_10;
int doWrite_PLC_DigOut_10(int value);
int prepareWrite_PLC_DigOut_10(int value);
 
#define ID_PLC_DigOut_11 5321
extern int PLC_DigOut_11;
int doWrite_PLC_DigOut_11(int value);
int prepareWrite_PLC_DigOut_11(int value);
 
#define ID_PLC_DigOut_12 5322
extern int PLC_DigOut_12;
int doWrite_PLC_DigOut_12(int value);
int prepareWrite_PLC_DigOut_12(int value);
 
#define ID_PLC_AnIn_1 5323
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int prepareWrite_PLC_AnIn_1(int16_t value);
 
#define ID_PLC_AnIn_2 5324
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int prepareWrite_PLC_AnIn_2(int16_t value);
 
#define ID_PLC_AnIn_3 5325
extern int16_t PLC_AnIn_3;
int doWrite_PLC_AnIn_3(int16_t value);
int prepareWrite_PLC_AnIn_3(int16_t value);
 
#define ID_PLC_AnIn_4 5326
extern int16_t PLC_AnIn_4;
int doWrite_PLC_AnIn_4(int16_t value);
int prepareWrite_PLC_AnIn_4(int16_t value);
 
#define ID_PLC_Tamb 5327
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int prepareWrite_PLC_Tamb(int16_t value);
 
#define ID_PLC_EncoderLo 5328
extern u_int16_t PLC_EncoderLo;
int doWrite_PLC_EncoderLo(u_int16_t value);
int prepareWrite_PLC_EncoderLo(u_int16_t value);
 
#define ID_PLC_EncoderHi 5329
extern u_int16_t PLC_EncoderHi;
int doWrite_PLC_EncoderHi(u_int16_t value);
int prepareWrite_PLC_EncoderHi(u_int16_t value);
 
#define ID_PLC_StatusReg 5330
extern u_int16_t PLC_StatusReg;
int doWrite_PLC_StatusReg(u_int16_t value);
int prepareWrite_PLC_StatusReg(u_int16_t value);
 
#define ID_PLC_RPM 5331
extern u_int16_t PLC_RPM;
int doWrite_PLC_RPM(u_int16_t value);
int prepareWrite_PLC_RPM(u_int16_t value);
 
#define ID_PLC_AnOut_1 5332
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int prepareWrite_PLC_AnOut_1(int16_t value);
 
#define ID_PLC_AnOut_2 5333
extern int16_t PLC_AnOut_2;
int doWrite_PLC_AnOut_2(int16_t value);
int prepareWrite_PLC_AnOut_2(int16_t value);
 
#define ID_PLC_AnInConf 5334
extern u_int16_t PLC_AnInConf;
int doWrite_PLC_AnInConf(u_int16_t value);
int prepareWrite_PLC_AnInConf(u_int16_t value);
 
#define ID_PLC_AnOutConf 5335
extern u_int16_t PLC_AnOutConf;
int doWrite_PLC_AnOutConf(u_int16_t value);
int prepareWrite_PLC_AnOutConf(u_int16_t value);
 
#define ID_PLC_ControlWord 5336
extern u_int16_t PLC_ControlWord;
int doWrite_PLC_ControlWord(u_int16_t value);
int prepareWrite_PLC_ControlWord(u_int16_t value);
 
#define ID_PLC_EncPreset_Lo 5337
extern u_int16_t PLC_EncPreset_Lo;
int doWrite_PLC_EncPreset_Lo(u_int16_t value);
int prepareWrite_PLC_EncPreset_Lo(u_int16_t value);
 
#define ID_PLC_EncPreset_Hi 5338
extern u_int16_t PLC_EncPreset_Hi;
int doWrite_PLC_EncPreset_Hi(u_int16_t value);
int prepareWrite_PLC_EncPreset_Hi(u_int16_t value);
 
#define ID_CH0_NETRUN 5345
extern int CH0_NETRUN;
int doWrite_CH0_NETRUN(int value);
int prepareWrite_CH0_NETRUN(int value);
 
#define ID_CH0_NETGOOD 5346
extern int CH0_NETGOOD;
int doWrite_CH0_NETGOOD(int value);
int prepareWrite_CH0_NETGOOD(int value);
 
#define ID_CH0_NETERR 5347
extern u_int32_t CH0_NETERR;
int doWrite_CH0_NETERR(u_int32_t value);
int prepareWrite_CH0_NETERR(u_int32_t value);
 
#define ID_CH0_NETRST 5348
extern int CH0_NETRST;
int doWrite_CH0_NETRST(int value);
int prepareWrite_CH0_NETRST(int value);
 
#define ID_CH0_NETDIS 5349
extern int CH0_NETDIS;
int doWrite_CH0_NETDIS(int value);
int prepareWrite_CH0_NETDIS(int value);
 
#define ID_CH0_01_NODERUN 5350
extern int CH0_01_NODERUN;
int doWrite_CH0_01_NODERUN(int value);
int prepareWrite_CH0_01_NODERUN(int value);
 
#define ID_CH0_01_NODEGOOD 5351
extern int CH0_01_NODEGOOD;
int doWrite_CH0_01_NODEGOOD(int value);
int prepareWrite_CH0_01_NODEGOOD(int value);
 
#define ID_CH0_01_NODEERR 5352
extern u_int32_t CH0_01_NODEERR;
int doWrite_CH0_01_NODEERR(u_int32_t value);
int prepareWrite_CH0_01_NODEERR(u_int32_t value);
 
#define ID_CH0_01_NODERST 5353
extern int CH0_01_NODERST;
int doWrite_CH0_01_NODERST(int value);
int prepareWrite_CH0_01_NODERST(int value);
 
#define ID_CH0_01_NODEDIS 5354
extern int CH0_01_NODEDIS;
int doWrite_CH0_01_NODEDIS(int value);
int prepareWrite_CH0_01_NODEDIS(int value);
 
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
