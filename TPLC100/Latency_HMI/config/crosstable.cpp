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
 
int RISING_FRONT = 0;
int FALLING_FRONT = 0;
int PLC_DigIn_1 = 0;
int PLC_DigIn_2 = 0;
int PLC_DigIn_3 = 0;
int PLC_DigIn_4 = 0;
int PLC_DigIn_9 = 0;
int PLC_DigOut_1 = 0;
int PLC_DigOut_2 = 0;
int PLC_DigOut_3 = 0;
int PLC_DigOut_4 = 0;
int PLC_DigOut_5 = 0;
int PLC_DigOut_6 = 0;
int PLC_DigOut_7 = 0;
int PLC_DigOut_8 = 0;
int PLC_DigOut_9 = 0;
int16_t PLC_AnIn_1 = 0;
int16_t PLC_AnIn_2 = 0;
int16_t PLC_AnIn_3 = 0;
int16_t PLC_AnIn_4 = 0;
int16_t PLC_AnIn_5 = 0;
int16_t PLC_AnIn_6 = 0;
int16_t PLC_AnIn_7 = 0;
int16_t PLC_AnIn_8 = 0;
int16_t PLC_AnIn_9 = 0;
int16_t PLC_AnIn_10 = 0;
int16_t PLC_AnIn_11 = 0;
int16_t PLC_AnIn_12 = 0;
int16_t PLC_Tamb = 0;
int16_t PLC_Vcc = 0;
u_int16_t PLC_AnInSt_0104 = 0;
u_int16_t PLC_AnInSt_0508 = 0;
u_int16_t PLC_AnInSt_0912 = 0;
u_int16_t PLC_AnOutSt_0104 = 0;
u_int16_t PLC_Counter_Lo = 0;
u_int16_t PLC_Counter_Hi = 0;
u_int16_t PLC_StatusWord = 0;
u_int16_t PLC_LifeCounter = 0;
int16_t PLC_AnOut_1 = 0;
int16_t PLC_AnOut_2 = 0;
int16_t PLC_AnOut_3 = 0;
int16_t PLC_AnOut_4 = 0;
u_int16_t PLC_ControlWord = 0;
u_int16_t PLC_AddressWord = 0;
int CH0_NETRUN = 0;
int CH0_NETGOOD = 0;
u_int32_t CH0_NETERR = 0;
int CH0_NETRST = 0;
int CH0_NETDIS = 0;
int CH0_01_NODERUN = 0;
int CH0_01_NODEGOOD = 0;
u_int32_t CH0_01_NODEERR = 0;
int CH0_01_NODERST = 0;
int CH0_01_NODEDIS = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;


int doWrite_RISING_FRONT(int value)
{
return doWrite(ID_RISING_FRONT,  &value);
}


int addWrite_RISING_FRONT(int value)
{
return addWrite(ID_RISING_FRONT, &value);
}


int getStatus_RISING_FRONT()
{
return getStatus(ID_RISING_FRONT);
}


int doWrite_FALLING_FRONT(int value)
{
return doWrite(ID_FALLING_FRONT,  &value);
}


int addWrite_FALLING_FRONT(int value)
{
return addWrite(ID_FALLING_FRONT, &value);
}


int getStatus_FALLING_FRONT()
{
return getStatus(ID_FALLING_FRONT);
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


int doWrite_PLC_DigOut_9(int value)
{
return doWrite(ID_PLC_DigOut_9,  &value);
}


int addWrite_PLC_DigOut_9(int value)
{
return addWrite(ID_PLC_DigOut_9, &value);
}


int getStatus_PLC_DigOut_9()
{
return getStatus(ID_PLC_DigOut_9);
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


int doWrite_PLC_AnIn_3(int16_t value)
{
return doWrite(ID_PLC_AnIn_3,  &value);
}


int addWrite_PLC_AnIn_3(int16_t value)
{
return addWrite(ID_PLC_AnIn_3, &value);
}


int getStatus_PLC_AnIn_3()
{
return getStatus(ID_PLC_AnIn_3);
}


int doWrite_PLC_AnIn_4(int16_t value)
{
return doWrite(ID_PLC_AnIn_4,  &value);
}


int addWrite_PLC_AnIn_4(int16_t value)
{
return addWrite(ID_PLC_AnIn_4, &value);
}


int getStatus_PLC_AnIn_4()
{
return getStatus(ID_PLC_AnIn_4);
}


int doWrite_PLC_AnIn_5(int16_t value)
{
return doWrite(ID_PLC_AnIn_5,  &value);
}


int addWrite_PLC_AnIn_5(int16_t value)
{
return addWrite(ID_PLC_AnIn_5, &value);
}


int getStatus_PLC_AnIn_5()
{
return getStatus(ID_PLC_AnIn_5);
}


int doWrite_PLC_AnIn_6(int16_t value)
{
return doWrite(ID_PLC_AnIn_6,  &value);
}


int addWrite_PLC_AnIn_6(int16_t value)
{
return addWrite(ID_PLC_AnIn_6, &value);
}


int getStatus_PLC_AnIn_6()
{
return getStatus(ID_PLC_AnIn_6);
}


int doWrite_PLC_AnIn_7(int16_t value)
{
return doWrite(ID_PLC_AnIn_7,  &value);
}


int addWrite_PLC_AnIn_7(int16_t value)
{
return addWrite(ID_PLC_AnIn_7, &value);
}


int getStatus_PLC_AnIn_7()
{
return getStatus(ID_PLC_AnIn_7);
}


int doWrite_PLC_AnIn_8(int16_t value)
{
return doWrite(ID_PLC_AnIn_8,  &value);
}


int addWrite_PLC_AnIn_8(int16_t value)
{
return addWrite(ID_PLC_AnIn_8, &value);
}


int getStatus_PLC_AnIn_8()
{
return getStatus(ID_PLC_AnIn_8);
}


int doWrite_PLC_AnIn_9(int16_t value)
{
return doWrite(ID_PLC_AnIn_9,  &value);
}


int addWrite_PLC_AnIn_9(int16_t value)
{
return addWrite(ID_PLC_AnIn_9, &value);
}


int getStatus_PLC_AnIn_9()
{
return getStatus(ID_PLC_AnIn_9);
}


int doWrite_PLC_AnIn_10(int16_t value)
{
return doWrite(ID_PLC_AnIn_10,  &value);
}


int addWrite_PLC_AnIn_10(int16_t value)
{
return addWrite(ID_PLC_AnIn_10, &value);
}


int getStatus_PLC_AnIn_10()
{
return getStatus(ID_PLC_AnIn_10);
}


int doWrite_PLC_AnIn_11(int16_t value)
{
return doWrite(ID_PLC_AnIn_11,  &value);
}


int addWrite_PLC_AnIn_11(int16_t value)
{
return addWrite(ID_PLC_AnIn_11, &value);
}


int getStatus_PLC_AnIn_11()
{
return getStatus(ID_PLC_AnIn_11);
}


int doWrite_PLC_AnIn_12(int16_t value)
{
return doWrite(ID_PLC_AnIn_12,  &value);
}


int addWrite_PLC_AnIn_12(int16_t value)
{
return addWrite(ID_PLC_AnIn_12, &value);
}


int getStatus_PLC_AnIn_12()
{
return getStatus(ID_PLC_AnIn_12);
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


int doWrite_PLC_Vcc(int16_t value)
{
return doWrite(ID_PLC_Vcc,  &value);
}


int addWrite_PLC_Vcc(int16_t value)
{
return addWrite(ID_PLC_Vcc, &value);
}


int getStatus_PLC_Vcc()
{
return getStatus(ID_PLC_Vcc);
}


int doWrite_PLC_AnInSt_0104(u_int16_t value)
{
return doWrite(ID_PLC_AnInSt_0104,  &value);
}


int addWrite_PLC_AnInSt_0104(u_int16_t value)
{
return addWrite(ID_PLC_AnInSt_0104, &value);
}


int getStatus_PLC_AnInSt_0104()
{
return getStatus(ID_PLC_AnInSt_0104);
}


int doWrite_PLC_AnInSt_0508(u_int16_t value)
{
return doWrite(ID_PLC_AnInSt_0508,  &value);
}


int addWrite_PLC_AnInSt_0508(u_int16_t value)
{
return addWrite(ID_PLC_AnInSt_0508, &value);
}


int getStatus_PLC_AnInSt_0508()
{
return getStatus(ID_PLC_AnInSt_0508);
}


int doWrite_PLC_AnInSt_0912(u_int16_t value)
{
return doWrite(ID_PLC_AnInSt_0912,  &value);
}


int addWrite_PLC_AnInSt_0912(u_int16_t value)
{
return addWrite(ID_PLC_AnInSt_0912, &value);
}


int getStatus_PLC_AnInSt_0912()
{
return getStatus(ID_PLC_AnInSt_0912);
}


int doWrite_PLC_AnOutSt_0104(u_int16_t value)
{
return doWrite(ID_PLC_AnOutSt_0104,  &value);
}


int addWrite_PLC_AnOutSt_0104(u_int16_t value)
{
return addWrite(ID_PLC_AnOutSt_0104, &value);
}


int getStatus_PLC_AnOutSt_0104()
{
return getStatus(ID_PLC_AnOutSt_0104);
}


int doWrite_PLC_Counter_Lo(u_int16_t value)
{
return doWrite(ID_PLC_Counter_Lo,  &value);
}


int addWrite_PLC_Counter_Lo(u_int16_t value)
{
return addWrite(ID_PLC_Counter_Lo, &value);
}


int getStatus_PLC_Counter_Lo()
{
return getStatus(ID_PLC_Counter_Lo);
}


int doWrite_PLC_Counter_Hi(u_int16_t value)
{
return doWrite(ID_PLC_Counter_Hi,  &value);
}


int addWrite_PLC_Counter_Hi(u_int16_t value)
{
return addWrite(ID_PLC_Counter_Hi, &value);
}


int getStatus_PLC_Counter_Hi()
{
return getStatus(ID_PLC_Counter_Hi);
}


int doWrite_PLC_StatusWord(u_int16_t value)
{
return doWrite(ID_PLC_StatusWord,  &value);
}


int addWrite_PLC_StatusWord(u_int16_t value)
{
return addWrite(ID_PLC_StatusWord, &value);
}


int getStatus_PLC_StatusWord()
{
return getStatus(ID_PLC_StatusWord);
}


int doWrite_PLC_LifeCounter(u_int16_t value)
{
return doWrite(ID_PLC_LifeCounter,  &value);
}


int addWrite_PLC_LifeCounter(u_int16_t value)
{
return addWrite(ID_PLC_LifeCounter, &value);
}


int getStatus_PLC_LifeCounter()
{
return getStatus(ID_PLC_LifeCounter);
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


int doWrite_PLC_AnOut_2(int16_t value)
{
return doWrite(ID_PLC_AnOut_2,  &value);
}


int addWrite_PLC_AnOut_2(int16_t value)
{
return addWrite(ID_PLC_AnOut_2, &value);
}


int getStatus_PLC_AnOut_2()
{
return getStatus(ID_PLC_AnOut_2);
}


int doWrite_PLC_AnOut_3(int16_t value)
{
return doWrite(ID_PLC_AnOut_3,  &value);
}


int addWrite_PLC_AnOut_3(int16_t value)
{
return addWrite(ID_PLC_AnOut_3, &value);
}


int getStatus_PLC_AnOut_3()
{
return getStatus(ID_PLC_AnOut_3);
}


int doWrite_PLC_AnOut_4(int16_t value)
{
return doWrite(ID_PLC_AnOut_4,  &value);
}


int addWrite_PLC_AnOut_4(int16_t value)
{
return addWrite(ID_PLC_AnOut_4, &value);
}


int getStatus_PLC_AnOut_4()
{
return getStatus(ID_PLC_AnOut_4);
}


int doWrite_PLC_ControlWord(u_int16_t value)
{
return doWrite(ID_PLC_ControlWord,  &value);
}


int addWrite_PLC_ControlWord(u_int16_t value)
{
return addWrite(ID_PLC_ControlWord, &value);
}


int getStatus_PLC_ControlWord()
{
return getStatus(ID_PLC_ControlWord);
}


int doWrite_PLC_AddressWord(u_int16_t value)
{
return doWrite(ID_PLC_AddressWord,  &value);
}


int addWrite_PLC_AddressWord(u_int16_t value)
{
return addWrite(ID_PLC_AddressWord, &value);
}


int getStatus_PLC_AddressWord()
{
return getStatus(ID_PLC_AddressWord);
}


int doWrite_CH0_NETRUN(int value)
{
return doWrite(ID_CH0_NETRUN,  &value);
}


int addWrite_CH0_NETRUN(int value)
{
return addWrite(ID_CH0_NETRUN, &value);
}


int getStatus_CH0_NETRUN()
{
return getStatus(ID_CH0_NETRUN);
}


int doWrite_CH0_NETGOOD(int value)
{
return doWrite(ID_CH0_NETGOOD,  &value);
}


int addWrite_CH0_NETGOOD(int value)
{
return addWrite(ID_CH0_NETGOOD, &value);
}


int getStatus_CH0_NETGOOD()
{
return getStatus(ID_CH0_NETGOOD);
}


int doWrite_CH0_NETERR(u_int32_t value)
{
return doWrite(ID_CH0_NETERR,  &value);
}


int addWrite_CH0_NETERR(u_int32_t value)
{
return addWrite(ID_CH0_NETERR, &value);
}


int getStatus_CH0_NETERR()
{
return getStatus(ID_CH0_NETERR);
}


int doWrite_CH0_NETRST(int value)
{
return doWrite(ID_CH0_NETRST,  &value);
}


int addWrite_CH0_NETRST(int value)
{
return addWrite(ID_CH0_NETRST, &value);
}


int getStatus_CH0_NETRST()
{
return getStatus(ID_CH0_NETRST);
}


int doWrite_CH0_NETDIS(int value)
{
return doWrite(ID_CH0_NETDIS,  &value);
}


int addWrite_CH0_NETDIS(int value)
{
return addWrite(ID_CH0_NETDIS, &value);
}


int getStatus_CH0_NETDIS()
{
return getStatus(ID_CH0_NETDIS);
}


int doWrite_CH0_01_NODERUN(int value)
{
return doWrite(ID_CH0_01_NODERUN,  &value);
}


int addWrite_CH0_01_NODERUN(int value)
{
return addWrite(ID_CH0_01_NODERUN, &value);
}


int getStatus_CH0_01_NODERUN()
{
return getStatus(ID_CH0_01_NODERUN);
}


int doWrite_CH0_01_NODEGOOD(int value)
{
return doWrite(ID_CH0_01_NODEGOOD,  &value);
}


int addWrite_CH0_01_NODEGOOD(int value)
{
return addWrite(ID_CH0_01_NODEGOOD, &value);
}


int getStatus_CH0_01_NODEGOOD()
{
return getStatus(ID_CH0_01_NODEGOOD);
}


int doWrite_CH0_01_NODEERR(u_int32_t value)
{
return doWrite(ID_CH0_01_NODEERR,  &value);
}


int addWrite_CH0_01_NODEERR(u_int32_t value)
{
return addWrite(ID_CH0_01_NODEERR, &value);
}


int getStatus_CH0_01_NODEERR()
{
return getStatus(ID_CH0_01_NODEERR);
}


int doWrite_CH0_01_NODERST(int value)
{
return doWrite(ID_CH0_01_NODERST,  &value);
}


int addWrite_CH0_01_NODERST(int value)
{
return addWrite(ID_CH0_01_NODERST, &value);
}


int getStatus_CH0_01_NODERST()
{
return getStatus(ID_CH0_01_NODERST);
}


int doWrite_CH0_01_NODEDIS(int value)
{
return doWrite(ID_CH0_01_NODEDIS,  &value);
}


int addWrite_CH0_01_NODEDIS(int value)
{
return addWrite(ID_CH0_01_NODEDIS, &value);
}


int getStatus_CH0_01_NODEDIS()
{
return getStatus(ID_CH0_01_NODEDIS);
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
retval += readFromDb(ID_RISING_FRONT, &RISING_FRONT);
retval += readFromDb(ID_FALLING_FRONT, &FALLING_FRONT);
retval += readFromDb(ID_PLC_DigIn_1, &PLC_DigIn_1);
retval += readFromDb(ID_PLC_DigIn_2, &PLC_DigIn_2);
retval += readFromDb(ID_PLC_DigIn_3, &PLC_DigIn_3);
retval += readFromDb(ID_PLC_DigIn_4, &PLC_DigIn_4);
retval += readFromDb(ID_PLC_DigIn_9, &PLC_DigIn_9);
retval += readFromDb(ID_PLC_DigOut_1, &PLC_DigOut_1);
retval += readFromDb(ID_PLC_DigOut_2, &PLC_DigOut_2);
retval += readFromDb(ID_PLC_DigOut_3, &PLC_DigOut_3);
retval += readFromDb(ID_PLC_DigOut_4, &PLC_DigOut_4);
retval += readFromDb(ID_PLC_DigOut_5, &PLC_DigOut_5);
retval += readFromDb(ID_PLC_DigOut_6, &PLC_DigOut_6);
retval += readFromDb(ID_PLC_DigOut_7, &PLC_DigOut_7);
retval += readFromDb(ID_PLC_DigOut_8, &PLC_DigOut_8);
retval += readFromDb(ID_PLC_DigOut_9, &PLC_DigOut_9);
retval += readFromDb(ID_PLC_AnIn_1, &PLC_AnIn_1);
retval += readFromDb(ID_PLC_AnIn_2, &PLC_AnIn_2);
retval += readFromDb(ID_PLC_AnIn_3, &PLC_AnIn_3);
retval += readFromDb(ID_PLC_AnIn_4, &PLC_AnIn_4);
retval += readFromDb(ID_PLC_AnIn_5, &PLC_AnIn_5);
retval += readFromDb(ID_PLC_AnIn_6, &PLC_AnIn_6);
retval += readFromDb(ID_PLC_AnIn_7, &PLC_AnIn_7);
retval += readFromDb(ID_PLC_AnIn_8, &PLC_AnIn_8);
retval += readFromDb(ID_PLC_AnIn_9, &PLC_AnIn_9);
retval += readFromDb(ID_PLC_AnIn_10, &PLC_AnIn_10);
retval += readFromDb(ID_PLC_AnIn_11, &PLC_AnIn_11);
retval += readFromDb(ID_PLC_AnIn_12, &PLC_AnIn_12);
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
retval += readFromDb(ID_PLC_Vcc, &PLC_Vcc);
retval += readFromDb(ID_PLC_AnInSt_0104, &PLC_AnInSt_0104);
retval += readFromDb(ID_PLC_AnInSt_0508, &PLC_AnInSt_0508);
retval += readFromDb(ID_PLC_AnInSt_0912, &PLC_AnInSt_0912);
retval += readFromDb(ID_PLC_AnOutSt_0104, &PLC_AnOutSt_0104);
retval += readFromDb(ID_PLC_Counter_Lo, &PLC_Counter_Lo);
retval += readFromDb(ID_PLC_Counter_Hi, &PLC_Counter_Hi);
retval += readFromDb(ID_PLC_StatusWord, &PLC_StatusWord);
retval += readFromDb(ID_PLC_LifeCounter, &PLC_LifeCounter);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_AnOut_2, &PLC_AnOut_2);
retval += readFromDb(ID_PLC_AnOut_3, &PLC_AnOut_3);
retval += readFromDb(ID_PLC_AnOut_4, &PLC_AnOut_4);
retval += readFromDb(ID_PLC_ControlWord, &PLC_ControlWord);
retval += readFromDb(ID_PLC_AddressWord, &PLC_AddressWord);
retval += readFromDb(ID_CH0_NETRUN, &CH0_NETRUN);
retval += readFromDb(ID_CH0_NETGOOD, &CH0_NETGOOD);
retval += readFromDb(ID_CH0_NETERR, &CH0_NETERR);
retval += readFromDb(ID_CH0_NETRST, &CH0_NETRST);
retval += readFromDb(ID_CH0_NETDIS, &CH0_NETDIS);
retval += readFromDb(ID_CH0_01_NODERUN, &CH0_01_NODERUN);
retval += readFromDb(ID_CH0_01_NODEGOOD, &CH0_01_NODEGOOD);
retval += readFromDb(ID_CH0_01_NODEERR, &CH0_01_NODEERR);
retval += readFromDb(ID_CH0_01_NODERST, &CH0_01_NODERST);
retval += readFromDb(ID_CH0_01_NODEDIS, &CH0_01_NODEDIS);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
return retval;
}
