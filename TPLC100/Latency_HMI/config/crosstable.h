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
int addWrite_RISING_FRONT(int value);
int getStatus_RISING_FRONT();
 
#define ID_FALLING_FRONT 194
extern int FALLING_FRONT;
int doWrite_FALLING_FRONT(int value);
int addWrite_FALLING_FRONT(int value);
int getStatus_FALLING_FRONT();
 
#define ID_PLC_DigIn_1 5300
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int addWrite_PLC_DigIn_1(int value);
int getStatus_PLC_DigIn_1();
 
#define ID_PLC_DigIn_2 5301
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int addWrite_PLC_DigIn_2(int value);
int getStatus_PLC_DigIn_2();
 
#define ID_PLC_DigIn_3 5302
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int addWrite_PLC_DigIn_3(int value);
int getStatus_PLC_DigIn_3();
 
#define ID_PLC_DigIn_4 5303
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int addWrite_PLC_DigIn_4(int value);
int getStatus_PLC_DigIn_4();
 
#define ID_PLC_DigIn_9 5304
extern int PLC_DigIn_9;
int doWrite_PLC_DigIn_9(int value);
int addWrite_PLC_DigIn_9(int value);
int getStatus_PLC_DigIn_9();
 
#define ID_PLC_DigOut_1 5305
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int addWrite_PLC_DigOut_1(int value);
int getStatus_PLC_DigOut_1();
 
#define ID_PLC_DigOut_2 5306
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int addWrite_PLC_DigOut_2(int value);
int getStatus_PLC_DigOut_2();
 
#define ID_PLC_DigOut_3 5307
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int addWrite_PLC_DigOut_3(int value);
int getStatus_PLC_DigOut_3();
 
#define ID_PLC_DigOut_4 5308
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int addWrite_PLC_DigOut_4(int value);
int getStatus_PLC_DigOut_4();
 
#define ID_PLC_DigOut_5 5309
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int addWrite_PLC_DigOut_5(int value);
int getStatus_PLC_DigOut_5();
 
#define ID_PLC_DigOut_6 5310
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int addWrite_PLC_DigOut_6(int value);
int getStatus_PLC_DigOut_6();
 
#define ID_PLC_DigOut_7 5311
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int addWrite_PLC_DigOut_7(int value);
int getStatus_PLC_DigOut_7();
 
#define ID_PLC_DigOut_8 5312
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int addWrite_PLC_DigOut_8(int value);
int getStatus_PLC_DigOut_8();
 
#define ID_PLC_DigOut_9 5313
extern int PLC_DigOut_9;
int doWrite_PLC_DigOut_9(int value);
int addWrite_PLC_DigOut_9(int value);
int getStatus_PLC_DigOut_9();
 
#define ID_PLC_AnIn_1 5314
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int addWrite_PLC_AnIn_1(int16_t value);
int getStatus_PLC_AnIn_1();
 
#define ID_PLC_AnIn_2 5315
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int addWrite_PLC_AnIn_2(int16_t value);
int getStatus_PLC_AnIn_2();
 
#define ID_PLC_AnIn_3 5316
extern int16_t PLC_AnIn_3;
int doWrite_PLC_AnIn_3(int16_t value);
int addWrite_PLC_AnIn_3(int16_t value);
int getStatus_PLC_AnIn_3();
 
#define ID_PLC_AnIn_4 5317
extern int16_t PLC_AnIn_4;
int doWrite_PLC_AnIn_4(int16_t value);
int addWrite_PLC_AnIn_4(int16_t value);
int getStatus_PLC_AnIn_4();
 
#define ID_PLC_AnIn_5 5318
extern int16_t PLC_AnIn_5;
int doWrite_PLC_AnIn_5(int16_t value);
int addWrite_PLC_AnIn_5(int16_t value);
int getStatus_PLC_AnIn_5();
 
#define ID_PLC_AnIn_6 5319
extern int16_t PLC_AnIn_6;
int doWrite_PLC_AnIn_6(int16_t value);
int addWrite_PLC_AnIn_6(int16_t value);
int getStatus_PLC_AnIn_6();
 
#define ID_PLC_AnIn_7 5320
extern int16_t PLC_AnIn_7;
int doWrite_PLC_AnIn_7(int16_t value);
int addWrite_PLC_AnIn_7(int16_t value);
int getStatus_PLC_AnIn_7();
 
#define ID_PLC_AnIn_8 5321
extern int16_t PLC_AnIn_8;
int doWrite_PLC_AnIn_8(int16_t value);
int addWrite_PLC_AnIn_8(int16_t value);
int getStatus_PLC_AnIn_8();
 
#define ID_PLC_AnIn_9 5322
extern int16_t PLC_AnIn_9;
int doWrite_PLC_AnIn_9(int16_t value);
int addWrite_PLC_AnIn_9(int16_t value);
int getStatus_PLC_AnIn_9();
 
#define ID_PLC_AnIn_10 5323
extern int16_t PLC_AnIn_10;
int doWrite_PLC_AnIn_10(int16_t value);
int addWrite_PLC_AnIn_10(int16_t value);
int getStatus_PLC_AnIn_10();
 
#define ID_PLC_AnIn_11 5324
extern int16_t PLC_AnIn_11;
int doWrite_PLC_AnIn_11(int16_t value);
int addWrite_PLC_AnIn_11(int16_t value);
int getStatus_PLC_AnIn_11();
 
#define ID_PLC_AnIn_12 5325
extern int16_t PLC_AnIn_12;
int doWrite_PLC_AnIn_12(int16_t value);
int addWrite_PLC_AnIn_12(int16_t value);
int getStatus_PLC_AnIn_12();
 
#define ID_PLC_Tamb 5326
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int addWrite_PLC_Tamb(int16_t value);
int getStatus_PLC_Tamb();
 
#define ID_PLC_Vcc 5327
extern int16_t PLC_Vcc;
int doWrite_PLC_Vcc(int16_t value);
int addWrite_PLC_Vcc(int16_t value);
int getStatus_PLC_Vcc();
 
#define ID_PLC_AnInSt_0104 5328
extern u_int16_t PLC_AnInSt_0104;
int doWrite_PLC_AnInSt_0104(u_int16_t value);
int addWrite_PLC_AnInSt_0104(u_int16_t value);
int getStatus_PLC_AnInSt_0104();
 
#define ID_PLC_AnInSt_0508 5329
extern u_int16_t PLC_AnInSt_0508;
int doWrite_PLC_AnInSt_0508(u_int16_t value);
int addWrite_PLC_AnInSt_0508(u_int16_t value);
int getStatus_PLC_AnInSt_0508();
 
#define ID_PLC_AnInSt_0912 5330
extern u_int16_t PLC_AnInSt_0912;
int doWrite_PLC_AnInSt_0912(u_int16_t value);
int addWrite_PLC_AnInSt_0912(u_int16_t value);
int getStatus_PLC_AnInSt_0912();
 
#define ID_PLC_AnOutSt_0104 5331
extern u_int16_t PLC_AnOutSt_0104;
int doWrite_PLC_AnOutSt_0104(u_int16_t value);
int addWrite_PLC_AnOutSt_0104(u_int16_t value);
int getStatus_PLC_AnOutSt_0104();
 
#define ID_PLC_Counter_Lo 5332
extern u_int16_t PLC_Counter_Lo;
int doWrite_PLC_Counter_Lo(u_int16_t value);
int addWrite_PLC_Counter_Lo(u_int16_t value);
int getStatus_PLC_Counter_Lo();
 
#define ID_PLC_Counter_Hi 5333
extern u_int16_t PLC_Counter_Hi;
int doWrite_PLC_Counter_Hi(u_int16_t value);
int addWrite_PLC_Counter_Hi(u_int16_t value);
int getStatus_PLC_Counter_Hi();
 
#define ID_PLC_StatusWord 5334
extern u_int16_t PLC_StatusWord;
int doWrite_PLC_StatusWord(u_int16_t value);
int addWrite_PLC_StatusWord(u_int16_t value);
int getStatus_PLC_StatusWord();
 
#define ID_PLC_LifeCounter 5335
extern u_int16_t PLC_LifeCounter;
int doWrite_PLC_LifeCounter(u_int16_t value);
int addWrite_PLC_LifeCounter(u_int16_t value);
int getStatus_PLC_LifeCounter();
 
#define ID_PLC_AnOut_1 5336
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int addWrite_PLC_AnOut_1(int16_t value);
int getStatus_PLC_AnOut_1();
 
#define ID_PLC_AnOut_2 5337
extern int16_t PLC_AnOut_2;
int doWrite_PLC_AnOut_2(int16_t value);
int addWrite_PLC_AnOut_2(int16_t value);
int getStatus_PLC_AnOut_2();
 
#define ID_PLC_AnOut_3 5338
extern int16_t PLC_AnOut_3;
int doWrite_PLC_AnOut_3(int16_t value);
int addWrite_PLC_AnOut_3(int16_t value);
int getStatus_PLC_AnOut_3();
 
#define ID_PLC_AnOut_4 5339
extern int16_t PLC_AnOut_4;
int doWrite_PLC_AnOut_4(int16_t value);
int addWrite_PLC_AnOut_4(int16_t value);
int getStatus_PLC_AnOut_4();
 
#define ID_PLC_ControlWord 5340
extern u_int16_t PLC_ControlWord;
int doWrite_PLC_ControlWord(u_int16_t value);
int addWrite_PLC_ControlWord(u_int16_t value);
int getStatus_PLC_ControlWord();
 
#define ID_PLC_AddressWord 5341
extern u_int16_t PLC_AddressWord;
int doWrite_PLC_AddressWord(u_int16_t value);
int addWrite_PLC_AddressWord(u_int16_t value);
int getStatus_PLC_AddressWord();
 
#define ID_CH0_NETRUN 5342
extern int CH0_NETRUN;
int doWrite_CH0_NETRUN(int value);
int addWrite_CH0_NETRUN(int value);
int getStatus_CH0_NETRUN();
 
#define ID_CH0_NETGOOD 5343
extern int CH0_NETGOOD;
int doWrite_CH0_NETGOOD(int value);
int addWrite_CH0_NETGOOD(int value);
int getStatus_CH0_NETGOOD();
 
#define ID_CH0_NETERR 5344
extern u_int32_t CH0_NETERR;
int doWrite_CH0_NETERR(u_int32_t value);
int addWrite_CH0_NETERR(u_int32_t value);
int getStatus_CH0_NETERR();
 
#define ID_CH0_NETRST 5345
extern int CH0_NETRST;
int doWrite_CH0_NETRST(int value);
int addWrite_CH0_NETRST(int value);
int getStatus_CH0_NETRST();
 
#define ID_CH0_NETDIS 5346
extern int CH0_NETDIS;
int doWrite_CH0_NETDIS(int value);
int addWrite_CH0_NETDIS(int value);
int getStatus_CH0_NETDIS();
 
#define ID_CH0_01_NODERUN 5347
extern int CH0_01_NODERUN;
int doWrite_CH0_01_NODERUN(int value);
int addWrite_CH0_01_NODERUN(int value);
int getStatus_CH0_01_NODERUN();
 
#define ID_CH0_01_NODEGOOD 5348
extern int CH0_01_NODEGOOD;
int doWrite_CH0_01_NODEGOOD(int value);
int addWrite_CH0_01_NODEGOOD(int value);
int getStatus_CH0_01_NODEGOOD();
 
#define ID_CH0_01_NODEERR 5349
extern u_int32_t CH0_01_NODEERR;
int doWrite_CH0_01_NODEERR(u_int32_t value);
int addWrite_CH0_01_NODEERR(u_int32_t value);
int getStatus_CH0_01_NODEERR();
 
#define ID_CH0_01_NODERST 5350
extern int CH0_01_NODERST;
int doWrite_CH0_01_NODERST(int value);
int addWrite_CH0_01_NODERST(int value);
int getStatus_CH0_01_NODERST();
 
#define ID_CH0_01_NODEDIS 5351
extern int CH0_01_NODEDIS;
int doWrite_CH0_01_NODEDIS(int value);
int addWrite_CH0_01_NODEDIS(int value);
int getStatus_CH0_01_NODEDIS();
 
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
