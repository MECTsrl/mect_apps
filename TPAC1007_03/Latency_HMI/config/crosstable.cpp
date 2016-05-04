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
int16_t PLC_Tamb = 0;
u_int32_t PLC_Encoder = 0;
int PLC_DigOut_1 = 0;
int PLC_DigOut_2 = 0;
int PLC_DigOut_3 = 0;
int PLC_DigOut_4 = 0;
int PLC_DigOut_5 = 0;
int PLC_DigOut_6 = 0;
int PLC_DigOut_7 = 0;
int PLC_DigOut_8 = 0;
int16_t PLC_AnOut_1 = 0;
u_int16_t PLC_EncEnable = 0;
u_int16_t PLC_EncoderReset = 0;
u_int16_t PLC_Reserved_16 = 0;
u_int16_t PLC_Reserved_17 = 0;
u_int16_t PLC_Reserved_18 = 0;
u_int16_t PLC_Reserved_19 = 0;
u_int16_t PLC_Heartbeat = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;
u_int16_t PLC_Version = 0;
u_int16_t PLC_EngineStatus = 0;
int PLC_ResetValues = 0;


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


int doWrite_PLC_FWrevision(u_int16_t value)
{
return doWrite(ID_PLC_FWrevision,  &value);
}


int addWrite_PLC_FWrevision(u_int16_t value)
{
return addWrite(ID_PLC_FWrevision, &value);
}


int getStatus_PLC_FWrevision()
{
return getStatus(ID_PLC_FWrevision);
}


int doWrite_PLC_HWconfig(u_int16_t value)
{
return doWrite(ID_PLC_HWconfig,  &value);
}


int addWrite_PLC_HWconfig(u_int16_t value)
{
return addWrite(ID_PLC_HWconfig, &value);
}


int getStatus_PLC_HWconfig()
{
return getStatus(ID_PLC_HWconfig);
}


int doWrite_PLC_DigDir_1(int value)
{
return doWrite(ID_PLC_DigDir_1,  &value);
}


int addWrite_PLC_DigDir_1(int value)
{
return addWrite(ID_PLC_DigDir_1, &value);
}


int getStatus_PLC_DigDir_1()
{
return getStatus(ID_PLC_DigDir_1);
}


int doWrite_PLC_DigDir_2(int value)
{
return doWrite(ID_PLC_DigDir_2,  &value);
}


int addWrite_PLC_DigDir_2(int value)
{
return addWrite(ID_PLC_DigDir_2, &value);
}


int getStatus_PLC_DigDir_2()
{
return getStatus(ID_PLC_DigDir_2);
}


int doWrite_PLC_DigDir_3(int value)
{
return doWrite(ID_PLC_DigDir_3,  &value);
}


int addWrite_PLC_DigDir_3(int value)
{
return addWrite(ID_PLC_DigDir_3, &value);
}


int getStatus_PLC_DigDir_3()
{
return getStatus(ID_PLC_DigDir_3);
}


int doWrite_PLC_DigDir_4(int value)
{
return doWrite(ID_PLC_DigDir_4,  &value);
}


int addWrite_PLC_DigDir_4(int value)
{
return addWrite(ID_PLC_DigDir_4, &value);
}


int getStatus_PLC_DigDir_4()
{
return getStatus(ID_PLC_DigDir_4);
}


int doWrite_PLC_DigDir_5(int value)
{
return doWrite(ID_PLC_DigDir_5,  &value);
}


int addWrite_PLC_DigDir_5(int value)
{
return addWrite(ID_PLC_DigDir_5, &value);
}


int getStatus_PLC_DigDir_5()
{
return getStatus(ID_PLC_DigDir_5);
}


int doWrite_PLC_DigDir_6(int value)
{
return doWrite(ID_PLC_DigDir_6,  &value);
}


int addWrite_PLC_DigDir_6(int value)
{
return addWrite(ID_PLC_DigDir_6, &value);
}


int getStatus_PLC_DigDir_6()
{
return getStatus(ID_PLC_DigDir_6);
}


int doWrite_PLC_DigDir_7(int value)
{
return doWrite(ID_PLC_DigDir_7,  &value);
}


int addWrite_PLC_DigDir_7(int value)
{
return addWrite(ID_PLC_DigDir_7, &value);
}


int getStatus_PLC_DigDir_7()
{
return getStatus(ID_PLC_DigDir_7);
}


int doWrite_PLC_DigDir_8(int value)
{
return doWrite(ID_PLC_DigDir_8,  &value);
}


int addWrite_PLC_DigDir_8(int value)
{
return addWrite(ID_PLC_DigDir_8, &value);
}


int getStatus_PLC_DigDir_8()
{
return getStatus(ID_PLC_DigDir_8);
}


int doWrite_PLC_AnInConf_1(u_int16_t value)
{
return doWrite(ID_PLC_AnInConf_1,  &value);
}


int addWrite_PLC_AnInConf_1(u_int16_t value)
{
return addWrite(ID_PLC_AnInConf_1, &value);
}


int getStatus_PLC_AnInConf_1()
{
return getStatus(ID_PLC_AnInConf_1);
}


int doWrite_PLC_AnInConf_2(u_int16_t value)
{
return doWrite(ID_PLC_AnInConf_2,  &value);
}


int addWrite_PLC_AnInConf_2(u_int16_t value)
{
return addWrite(ID_PLC_AnInConf_2, &value);
}


int getStatus_PLC_AnInConf_2()
{
return getStatus(ID_PLC_AnInConf_2);
}


int doWrite_PLC_AnOutConf_1(u_int16_t value)
{
return doWrite(ID_PLC_AnOutConf_1,  &value);
}


int addWrite_PLC_AnOutConf_1(u_int16_t value)
{
return addWrite(ID_PLC_AnOutConf_1, &value);
}


int getStatus_PLC_AnOutConf_1()
{
return getStatus(ID_PLC_AnOutConf_1);
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


int doWrite_PLC_DigIn_5(int value)
{
return doWrite(ID_PLC_DigIn_5,  &value);
}


int addWrite_PLC_DigIn_5(int value)
{
return addWrite(ID_PLC_DigIn_5, &value);
}


int getStatus_PLC_DigIn_5()
{
return getStatus(ID_PLC_DigIn_5);
}


int doWrite_PLC_DigIn_6(int value)
{
return doWrite(ID_PLC_DigIn_6,  &value);
}


int addWrite_PLC_DigIn_6(int value)
{
return addWrite(ID_PLC_DigIn_6, &value);
}


int getStatus_PLC_DigIn_6()
{
return getStatus(ID_PLC_DigIn_6);
}


int doWrite_PLC_DigIn_7(int value)
{
return doWrite(ID_PLC_DigIn_7,  &value);
}


int addWrite_PLC_DigIn_7(int value)
{
return addWrite(ID_PLC_DigIn_7, &value);
}


int getStatus_PLC_DigIn_7()
{
return getStatus(ID_PLC_DigIn_7);
}


int doWrite_PLC_DigIn_8(int value)
{
return doWrite(ID_PLC_DigIn_8,  &value);
}


int addWrite_PLC_DigIn_8(int value)
{
return addWrite(ID_PLC_DigIn_8, &value);
}


int getStatus_PLC_DigIn_8()
{
return getStatus(ID_PLC_DigIn_8);
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


int doWrite_PLC_DigIn_10(int value)
{
return doWrite(ID_PLC_DigIn_10,  &value);
}


int addWrite_PLC_DigIn_10(int value)
{
return addWrite(ID_PLC_DigIn_10, &value);
}


int getStatus_PLC_DigIn_10()
{
return getStatus(ID_PLC_DigIn_10);
}


int doWrite_PLC_DigIn_11(int value)
{
return doWrite(ID_PLC_DigIn_11,  &value);
}


int addWrite_PLC_DigIn_11(int value)
{
return addWrite(ID_PLC_DigIn_11, &value);
}


int getStatus_PLC_DigIn_11()
{
return getStatus(ID_PLC_DigIn_11);
}


int doWrite_PLC_DigIn_12(int value)
{
return doWrite(ID_PLC_DigIn_12,  &value);
}


int addWrite_PLC_DigIn_12(int value)
{
return addWrite(ID_PLC_DigIn_12, &value);
}


int getStatus_PLC_DigIn_12()
{
return getStatus(ID_PLC_DigIn_12);
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


int doWrite_PLC_Encoder(u_int32_t value)
{
return doWrite(ID_PLC_Encoder,  &value);
}


int addWrite_PLC_Encoder(u_int32_t value)
{
return addWrite(ID_PLC_Encoder, &value);
}


int getStatus_PLC_Encoder()
{
return getStatus(ID_PLC_Encoder);
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


int doWrite_PLC_EncEnable(u_int16_t value)
{
return doWrite(ID_PLC_EncEnable,  &value);
}


int addWrite_PLC_EncEnable(u_int16_t value)
{
return addWrite(ID_PLC_EncEnable, &value);
}


int getStatus_PLC_EncEnable()
{
return getStatus(ID_PLC_EncEnable);
}


int doWrite_PLC_EncoderReset(u_int16_t value)
{
return doWrite(ID_PLC_EncoderReset,  &value);
}


int addWrite_PLC_EncoderReset(u_int16_t value)
{
return addWrite(ID_PLC_EncoderReset, &value);
}


int getStatus_PLC_EncoderReset()
{
return getStatus(ID_PLC_EncoderReset);
}


int doWrite_PLC_Reserved_16(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_16,  &value);
}


int addWrite_PLC_Reserved_16(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_16, &value);
}


int getStatus_PLC_Reserved_16()
{
return getStatus(ID_PLC_Reserved_16);
}


int doWrite_PLC_Reserved_17(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_17,  &value);
}


int addWrite_PLC_Reserved_17(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_17, &value);
}


int getStatus_PLC_Reserved_17()
{
return getStatus(ID_PLC_Reserved_17);
}


int doWrite_PLC_Reserved_18(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_18,  &value);
}


int addWrite_PLC_Reserved_18(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_18, &value);
}


int getStatus_PLC_Reserved_18()
{
return getStatus(ID_PLC_Reserved_18);
}


int doWrite_PLC_Reserved_19(u_int16_t value)
{
return doWrite(ID_PLC_Reserved_19,  &value);
}


int addWrite_PLC_Reserved_19(u_int16_t value)
{
return addWrite(ID_PLC_Reserved_19, &value);
}


int getStatus_PLC_Reserved_19()
{
return getStatus(ID_PLC_Reserved_19);
}


int doWrite_PLC_Heartbeat(u_int16_t value)
{
return doWrite(ID_PLC_Heartbeat,  &value);
}


int addWrite_PLC_Heartbeat(u_int16_t value)
{
return addWrite(ID_PLC_Heartbeat, &value);
}


int getStatus_PLC_Heartbeat()
{
return getStatus(ID_PLC_Heartbeat);
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


int doWrite_PLC_Version(u_int16_t value)
{
return doWrite(ID_PLC_Version,  &value);
}


int addWrite_PLC_Version(u_int16_t value)
{
return addWrite(ID_PLC_Version, &value);
}


int getStatus_PLC_Version()
{
return getStatus(ID_PLC_Version);
}


int doWrite_PLC_EngineStatus(u_int16_t value)
{
return doWrite(ID_PLC_EngineStatus,  &value);
}


int addWrite_PLC_EngineStatus(u_int16_t value)
{
return addWrite(ID_PLC_EngineStatus, &value);
}


int getStatus_PLC_EngineStatus()
{
return getStatus(ID_PLC_EngineStatus);
}


int doWrite_PLC_ResetValues(int value)
{
return doWrite(ID_PLC_ResetValues,  &value);
}


int addWrite_PLC_ResetValues(int value)
{
return addWrite(ID_PLC_ResetValues, &value);
}


int getStatus_PLC_ResetValues()
{
return getStatus(ID_PLC_ResetValues);
}


int update_all(void)
{
int retval = 0;
retval += readFromDb(ID_RISING_FRONT, &RISING_FRONT);
retval += readFromDb(ID_FALLING_FRONT, &FALLING_FRONT);
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
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
retval += readFromDb(ID_PLC_Encoder, &PLC_Encoder);
retval += readFromDb(ID_PLC_DigOut_1, &PLC_DigOut_1);
retval += readFromDb(ID_PLC_DigOut_2, &PLC_DigOut_2);
retval += readFromDb(ID_PLC_DigOut_3, &PLC_DigOut_3);
retval += readFromDb(ID_PLC_DigOut_4, &PLC_DigOut_4);
retval += readFromDb(ID_PLC_DigOut_5, &PLC_DigOut_5);
retval += readFromDb(ID_PLC_DigOut_6, &PLC_DigOut_6);
retval += readFromDb(ID_PLC_DigOut_7, &PLC_DigOut_7);
retval += readFromDb(ID_PLC_DigOut_8, &PLC_DigOut_8);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_EncEnable, &PLC_EncEnable);
retval += readFromDb(ID_PLC_EncoderReset, &PLC_EncoderReset);
retval += readFromDb(ID_PLC_Reserved_16, &PLC_Reserved_16);
retval += readFromDb(ID_PLC_Reserved_17, &PLC_Reserved_17);
retval += readFromDb(ID_PLC_Reserved_18, &PLC_Reserved_18);
retval += readFromDb(ID_PLC_Reserved_19, &PLC_Reserved_19);
retval += readFromDb(ID_PLC_Heartbeat, &PLC_Heartbeat);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
retval += readFromDb(ID_PLC_Version, &PLC_Version);
retval += readFromDb(ID_PLC_EngineStatus, &PLC_EngineStatus);
retval += readFromDb(ID_PLC_ResetValues, &PLC_ResetValues);
return retval;
}
