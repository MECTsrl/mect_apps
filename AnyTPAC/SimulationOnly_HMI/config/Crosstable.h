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
 
#define ID_PLC_DigIn_10 5309
extern int PLC_DigIn_10;
int doWrite_PLC_DigIn_10(int value);
int prepareWrite_PLC_DigIn_10(int value);
 
#define ID_PLC_DigIn_11 5310
extern int PLC_DigIn_11;
int doWrite_PLC_DigIn_11(int value);
int prepareWrite_PLC_DigIn_11(int value);
 
#define ID_PLC_DigIn_12 5311
extern int PLC_DigIn_12;
int doWrite_PLC_DigIn_12(int value);
int prepareWrite_PLC_DigIn_12(int value);
 
#define ID_PLC_DigIn_13 5312
extern int PLC_DigIn_13;
int doWrite_PLC_DigIn_13(int value);
int prepareWrite_PLC_DigIn_13(int value);
 
#define ID_PLC_DigIn_14 5313
extern int PLC_DigIn_14;
int doWrite_PLC_DigIn_14(int value);
int prepareWrite_PLC_DigIn_14(int value);
 
#define ID_PLC_DigIn_15 5314
extern int PLC_DigIn_15;
int doWrite_PLC_DigIn_15(int value);
int prepareWrite_PLC_DigIn_15(int value);
 
#define ID_PLC_DigIn_16 5315
extern int PLC_DigIn_16;
int doWrite_PLC_DigIn_16(int value);
int prepareWrite_PLC_DigIn_16(int value);
 
#define ID_PLC_DigOut_1 5316
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int prepareWrite_PLC_DigOut_1(int value);
 
#define ID_PLC_DigOut_2 5317
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int prepareWrite_PLC_DigOut_2(int value);
 
#define ID_PLC_DigOut_3 5318
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int prepareWrite_PLC_DigOut_3(int value);
 
#define ID_PLC_DigOut_4 5319
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int prepareWrite_PLC_DigOut_4(int value);
 
#define ID_PLC_DigOut_5 5320
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int prepareWrite_PLC_DigOut_5(int value);
 
#define ID_PLC_DigOut_6 5321
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int prepareWrite_PLC_DigOut_6(int value);
 
#define ID_PLC_DigOut_7 5322
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int prepareWrite_PLC_DigOut_7(int value);
 
#define ID_PLC_DigOut_8 5323
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int prepareWrite_PLC_DigOut_8(int value);
 
#define ID_PLC_DigOut_9 5324
extern int PLC_DigOut_9;
int doWrite_PLC_DigOut_9(int value);
int prepareWrite_PLC_DigOut_9(int value);
 
#define ID_PLC_DigOut_10 5325
extern int PLC_DigOut_10;
int doWrite_PLC_DigOut_10(int value);
int prepareWrite_PLC_DigOut_10(int value);
 
#define ID_PLC_DigOut_11 5326
extern int PLC_DigOut_11;
int doWrite_PLC_DigOut_11(int value);
int prepareWrite_PLC_DigOut_11(int value);
 
#define ID_PLC_DigOut_12 5327
extern int PLC_DigOut_12;
int doWrite_PLC_DigOut_12(int value);
int prepareWrite_PLC_DigOut_12(int value);
 
#define ID_PLC_DigOut_13 5328
extern int PLC_DigOut_13;
int doWrite_PLC_DigOut_13(int value);
int prepareWrite_PLC_DigOut_13(int value);
 
#define ID_PLC_DigOut_14 5329
extern int PLC_DigOut_14;
int doWrite_PLC_DigOut_14(int value);
int prepareWrite_PLC_DigOut_14(int value);
 
#define ID_PLC_DigOut_15 5330
extern int PLC_DigOut_15;
int doWrite_PLC_DigOut_15(int value);
int prepareWrite_PLC_DigOut_15(int value);
 
#define ID_PLC_DigOut_16 5331
extern int PLC_DigOut_16;
int doWrite_PLC_DigOut_16(int value);
int prepareWrite_PLC_DigOut_16(int value);
 
#define ID_PLC_DigDir_1 5332
extern int PLC_DigDir_1;
int doWrite_PLC_DigDir_1(int value);
int prepareWrite_PLC_DigDir_1(int value);
 
#define ID_PLC_DigDir_2 5333
extern int PLC_DigDir_2;
int doWrite_PLC_DigDir_2(int value);
int prepareWrite_PLC_DigDir_2(int value);
 
#define ID_PLC_DigDir_3 5334
extern int PLC_DigDir_3;
int doWrite_PLC_DigDir_3(int value);
int prepareWrite_PLC_DigDir_3(int value);
 
#define ID_PLC_DigDir_4 5335
extern int PLC_DigDir_4;
int doWrite_PLC_DigDir_4(int value);
int prepareWrite_PLC_DigDir_4(int value);
 
#define ID_PLC_DigDir_5 5336
extern int PLC_DigDir_5;
int doWrite_PLC_DigDir_5(int value);
int prepareWrite_PLC_DigDir_5(int value);
 
#define ID_PLC_DigDir_6 5337
extern int PLC_DigDir_6;
int doWrite_PLC_DigDir_6(int value);
int prepareWrite_PLC_DigDir_6(int value);
 
#define ID_PLC_DigDir_7 5338
extern int PLC_DigDir_7;
int doWrite_PLC_DigDir_7(int value);
int prepareWrite_PLC_DigDir_7(int value);
 
#define ID_PLC_DigDir_8 5339
extern int PLC_DigDir_8;
int doWrite_PLC_DigDir_8(int value);
int prepareWrite_PLC_DigDir_8(int value);
 
#define ID_PLC_DigDir_9 5340
extern int PLC_DigDir_9;
int doWrite_PLC_DigDir_9(int value);
int prepareWrite_PLC_DigDir_9(int value);
 
#define ID_PLC_DigDir_10 5341
extern int PLC_DigDir_10;
int doWrite_PLC_DigDir_10(int value);
int prepareWrite_PLC_DigDir_10(int value);
 
#define ID_PLC_DigDir_11 5342
extern int PLC_DigDir_11;
int doWrite_PLC_DigDir_11(int value);
int prepareWrite_PLC_DigDir_11(int value);
 
#define ID_PLC_DigDir_12 5343
extern int PLC_DigDir_12;
int doWrite_PLC_DigDir_12(int value);
int prepareWrite_PLC_DigDir_12(int value);
 
#define ID_PLC_DigDir_13 5344
extern int PLC_DigDir_13;
int doWrite_PLC_DigDir_13(int value);
int prepareWrite_PLC_DigDir_13(int value);
 
#define ID_PLC_DigDir_14 5345
extern int PLC_DigDir_14;
int doWrite_PLC_DigDir_14(int value);
int prepareWrite_PLC_DigDir_14(int value);
 
#define ID_PLC_DigDir_15 5346
extern int PLC_DigDir_15;
int doWrite_PLC_DigDir_15(int value);
int prepareWrite_PLC_DigDir_15(int value);
 
#define ID_PLC_DigDir_16 5347
extern int PLC_DigDir_16;
int doWrite_PLC_DigDir_16(int value);
int prepareWrite_PLC_DigDir_16(int value);
 
#define ID_PLC_AnIn_1 5348
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int prepareWrite_PLC_AnIn_1(int16_t value);
 
#define ID_PLC_AnIn_2 5349
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int prepareWrite_PLC_AnIn_2(int16_t value);
 
#define ID_PLC_AnIn_3 5350
extern int16_t PLC_AnIn_3;
int doWrite_PLC_AnIn_3(int16_t value);
int prepareWrite_PLC_AnIn_3(int16_t value);
 
#define ID_PLC_AnIn_4 5351
extern int16_t PLC_AnIn_4;
int doWrite_PLC_AnIn_4(int16_t value);
int prepareWrite_PLC_AnIn_4(int16_t value);
 
#define ID_PLC_AnIn_5 5352
extern int16_t PLC_AnIn_5;
int doWrite_PLC_AnIn_5(int16_t value);
int prepareWrite_PLC_AnIn_5(int16_t value);
 
#define ID_PLC_AnIn_6 5353
extern int16_t PLC_AnIn_6;
int doWrite_PLC_AnIn_6(int16_t value);
int prepareWrite_PLC_AnIn_6(int16_t value);
 
#define ID_PLC_AnIn_7 5354
extern int16_t PLC_AnIn_7;
int doWrite_PLC_AnIn_7(int16_t value);
int prepareWrite_PLC_AnIn_7(int16_t value);
 
#define ID_PLC_AnIn_8 5355
extern int16_t PLC_AnIn_8;
int doWrite_PLC_AnIn_8(int16_t value);
int prepareWrite_PLC_AnIn_8(int16_t value);
 
#define ID_PLC_AnOut_1 5356
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int prepareWrite_PLC_AnOut_1(int16_t value);
 
#define ID_PLC_AnOut_2 5357
extern int16_t PLC_AnOut_2;
int doWrite_PLC_AnOut_2(int16_t value);
int prepareWrite_PLC_AnOut_2(int16_t value);
 
#define ID_PLC_AnOut_3 5358
extern int16_t PLC_AnOut_3;
int doWrite_PLC_AnOut_3(int16_t value);
int prepareWrite_PLC_AnOut_3(int16_t value);
 
#define ID_PLC_AnOut_4 5359
extern int16_t PLC_AnOut_4;
int doWrite_PLC_AnOut_4(int16_t value);
int prepareWrite_PLC_AnOut_4(int16_t value);
 
#define ID_PLC_AnOut_5 5360
extern int16_t PLC_AnOut_5;
int doWrite_PLC_AnOut_5(int16_t value);
int prepareWrite_PLC_AnOut_5(int16_t value);
 
#define ID_PLC_AnOut_6 5361
extern int16_t PLC_AnOut_6;
int doWrite_PLC_AnOut_6(int16_t value);
int prepareWrite_PLC_AnOut_6(int16_t value);
 
#define ID_PLC_AnOut_7 5362
extern int16_t PLC_AnOut_7;
int doWrite_PLC_AnOut_7(int16_t value);
int prepareWrite_PLC_AnOut_7(int16_t value);
 
#define ID_PLC_AnOut_8 5363
extern int16_t PLC_AnOut_8;
int doWrite_PLC_AnOut_8(int16_t value);
int prepareWrite_PLC_AnOut_8(int16_t value);
 
#define ID_PLC_AnInConf_1 5364
extern u_int16_t PLC_AnInConf_1;
int doWrite_PLC_AnInConf_1(u_int16_t value);
int prepareWrite_PLC_AnInConf_1(u_int16_t value);
 
#define ID_PLC_AnInConf_2 5365
extern u_int16_t PLC_AnInConf_2;
int doWrite_PLC_AnInConf_2(u_int16_t value);
int prepareWrite_PLC_AnInConf_2(u_int16_t value);
 
#define ID_PLC_AnInConf_3 5366
extern u_int16_t PLC_AnInConf_3;
int doWrite_PLC_AnInConf_3(u_int16_t value);
int prepareWrite_PLC_AnInConf_3(u_int16_t value);
 
#define ID_PLC_AnInConf_4 5367
extern u_int16_t PLC_AnInConf_4;
int doWrite_PLC_AnInConf_4(u_int16_t value);
int prepareWrite_PLC_AnInConf_4(u_int16_t value);
 
#define ID_PLC_AnInConf_5 5368
extern u_int16_t PLC_AnInConf_5;
int doWrite_PLC_AnInConf_5(u_int16_t value);
int prepareWrite_PLC_AnInConf_5(u_int16_t value);
 
#define ID_PLC_AnInConf_6 5369
extern u_int16_t PLC_AnInConf_6;
int doWrite_PLC_AnInConf_6(u_int16_t value);
int prepareWrite_PLC_AnInConf_6(u_int16_t value);
 
#define ID_PLC_AnInConf_7 5370
extern u_int16_t PLC_AnInConf_7;
int doWrite_PLC_AnInConf_7(u_int16_t value);
int prepareWrite_PLC_AnInConf_7(u_int16_t value);
 
#define ID_PLC_AnInConf_8 5371
extern u_int16_t PLC_AnInConf_8;
int doWrite_PLC_AnInConf_8(u_int16_t value);
int prepareWrite_PLC_AnInConf_8(u_int16_t value);
 
#define ID_PLC_AnOutConf_1 5372
extern u_int16_t PLC_AnOutConf_1;
int doWrite_PLC_AnOutConf_1(u_int16_t value);
int prepareWrite_PLC_AnOutConf_1(u_int16_t value);
 
#define ID_PLC_AnOutConf_2 5373
extern u_int16_t PLC_AnOutConf_2;
int doWrite_PLC_AnOutConf_2(u_int16_t value);
int prepareWrite_PLC_AnOutConf_2(u_int16_t value);
 
#define ID_PLC_AnOutConf_3 5374
extern u_int16_t PLC_AnOutConf_3;
int doWrite_PLC_AnOutConf_3(u_int16_t value);
int prepareWrite_PLC_AnOutConf_3(u_int16_t value);
 
#define ID_PLC_AnOutConf_4 5375
extern u_int16_t PLC_AnOutConf_4;
int doWrite_PLC_AnOutConf_4(u_int16_t value);
int prepareWrite_PLC_AnOutConf_4(u_int16_t value);
 
#define ID_PLC_AnOutConf_5 5376
extern u_int16_t PLC_AnOutConf_5;
int doWrite_PLC_AnOutConf_5(u_int16_t value);
int prepareWrite_PLC_AnOutConf_5(u_int16_t value);
 
#define ID_PLC_AnOutConf_6 5377
extern u_int16_t PLC_AnOutConf_6;
int doWrite_PLC_AnOutConf_6(u_int16_t value);
int prepareWrite_PLC_AnOutConf_6(u_int16_t value);
 
#define ID_PLC_AnOutConf_7 5378
extern u_int16_t PLC_AnOutConf_7;
int doWrite_PLC_AnOutConf_7(u_int16_t value);
int prepareWrite_PLC_AnOutConf_7(u_int16_t value);
 
#define ID_PLC_AnOutConf_8 5379
extern u_int16_t PLC_AnOutConf_8;
int doWrite_PLC_AnOutConf_8(u_int16_t value);
int prepareWrite_PLC_AnOutConf_8(u_int16_t value);
 
#define ID_PLC_Tamb 5380
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int prepareWrite_PLC_Tamb(int16_t value);
 
#define ID_PLC_EncoderLo 5381
extern u_int16_t PLC_EncoderLo;
int doWrite_PLC_EncoderLo(u_int16_t value);
int prepareWrite_PLC_EncoderLo(u_int16_t value);
 
#define ID_PLC_EncoderHi 5382
extern u_int16_t PLC_EncoderHi;
int doWrite_PLC_EncoderHi(u_int16_t value);
int prepareWrite_PLC_EncoderHi(u_int16_t value);
 
#define ID_PLC_StatusReg 5383
extern u_int16_t PLC_StatusReg;
int doWrite_PLC_StatusReg(u_int16_t value);
int prepareWrite_PLC_StatusReg(u_int16_t value);
 
#define ID_PLC_ControlWord 5384
extern u_int16_t PLC_ControlWord;
int doWrite_PLC_ControlWord(u_int16_t value);
int prepareWrite_PLC_ControlWord(u_int16_t value);
 
#define ID_PLC_EncPreset_Lo 5385
extern u_int16_t PLC_EncPreset_Lo;
int doWrite_PLC_EncPreset_Lo(u_int16_t value);
int prepareWrite_PLC_EncPreset_Lo(u_int16_t value);
 
#define ID_PLC_EncPreset_Hi 5386
extern u_int16_t PLC_EncPreset_Hi;
int doWrite_PLC_EncPreset_Hi(u_int16_t value);
int prepareWrite_PLC_EncPreset_Hi(u_int16_t value);
 
#define ID_PLC_EncoderReset 5387
extern u_int16_t PLC_EncoderReset;
int doWrite_PLC_EncoderReset(u_int16_t value);
int prepareWrite_PLC_EncoderReset(u_int16_t value);
 
#define ID_PLC_EncEnable 5388
extern u_int16_t PLC_EncEnable;
int doWrite_PLC_EncEnable(u_int16_t value);
int prepareWrite_PLC_EncEnable(u_int16_t value);
 
#define ID_PLC_RPM 5389
extern u_int16_t PLC_RPM;
int doWrite_PLC_RPM(u_int16_t value);
int prepareWrite_PLC_RPM(u_int16_t value);
 
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
 
//int update_all(void);
 
#ifdef __cplusplus
}
#endif
#endif
