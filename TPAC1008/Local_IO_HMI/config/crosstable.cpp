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
 
int PLC_DigIn_1 = 0;
int PLC_DigIn_2 = 0;
int PLC_DigIn_3 = 0;
int PLC_DigIn_4 = 0;
int PLC_DigIn_5 = 0;
int PLC_DigIn_6 = 0;
int PLC_DigIn_7 = 0;
int PLC_DigIn_8 = 0;
u_int16_t PLC_DigIn_9_16 = 0;
u_int16_t PLC_DigIn_17_24 = 0;
u_int16_t PLC_DigIn_25_32 = 0;
int PLC_DigOut_1 = 0;
int PLC_DigOut_2 = 0;
int PLC_DigOut_3 = 0;
int PLC_DigOut_4 = 0;
int PLC_DigOut_5 = 0;
int PLC_DigOut_6 = 0;
int PLC_DigOut_7 = 0;
int PLC_DigOut_8 = 0;
int PLC_DigOut_9 = 0;
int PLC_DigOut_10 = 0;
int PLC_DigOut_11 = 0;
int PLC_DigOut_12 = 0;
int16_t PLC_AnIn_1 = 0;
int16_t PLC_AnIn_2 = 0;
int16_t PLC_AnIn_3 = 0;
int16_t PLC_AnIn_4 = 0;
int16_t PLC_Tamb = 0;
u_int16_t PLC_EncoderLo = 0;
u_int16_t PLC_EncoderHi = 0;
u_int16_t PLC_StatusReg = 0;
u_int16_t PLC_RPM = 0;
int16_t PLC_AnOut_1 = 0;
int16_t PLC_AnOut_2 = 0;
u_int16_t PLC_AnInConf = 0;
u_int16_t PLC_AnOutConf = 0;
u_int16_t PLC_ControlWord = 0;
u_int16_t PLC_EncPreset_Lo = 0;
u_int16_t PLC_EncPreset_Hi = 0;
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


int doWrite_PLC_DigIn_1(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_1,  &value);
}


int addWrite_PLC_DigIn_1(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_2(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_2,  &value);
}


int addWrite_PLC_DigIn_2(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_3(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_3,  &value);
}


int addWrite_PLC_DigIn_3(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_4(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_4,  &value);
}


int addWrite_PLC_DigIn_4(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_5(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_5,  &value);
}


int addWrite_PLC_DigIn_5(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_6(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_6,  &value);
}


int addWrite_PLC_DigIn_6(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_7(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_7,  &value);
}


int addWrite_PLC_DigIn_7(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_8(int value)
{
return writeVarByCtIndex(ID_PLC_DigIn_8,  &value);
}


int addWrite_PLC_DigIn_8(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_9_16(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_9_16,  &value);
}


int addWrite_PLC_DigIn_9_16(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_9_16, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_17_24(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_17_24,  &value);
}


int addWrite_PLC_DigIn_17_24(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_17_24, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_25_32(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_25_32,  &value);
}


int addWrite_PLC_DigIn_25_32(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_25_32, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_1(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_1,  &value);
}


int addWrite_PLC_DigOut_1(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_2(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_2,  &value);
}


int addWrite_PLC_DigOut_2(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_3(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_3,  &value);
}


int addWrite_PLC_DigOut_3(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_4(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_4,  &value);
}


int addWrite_PLC_DigOut_4(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_5(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_5,  &value);
}


int addWrite_PLC_DigOut_5(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_6(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_6,  &value);
}


int addWrite_PLC_DigOut_6(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_7(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_7,  &value);
}


int addWrite_PLC_DigOut_7(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_8(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_8,  &value);
}


int addWrite_PLC_DigOut_8(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_9(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_9,  &value);
}


int addWrite_PLC_DigOut_9(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_10(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_10,  &value);
}


int addWrite_PLC_DigOut_10(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_11(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_11,  &value);
}


int addWrite_PLC_DigOut_11(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_12(int value)
{
return writeVarByCtIndex(ID_PLC_DigOut_12,  &value);
}


int addWrite_PLC_DigOut_12(int value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_1(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_1,  &value);
}


int addWrite_PLC_AnIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_2(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_2,  &value);
}


int addWrite_PLC_AnIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_3(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_3,  &value);
}


int addWrite_PLC_AnIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_4(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_4,  &value);
}


int addWrite_PLC_AnIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_Tamb(int16_t value)
{
return writeVarByCtIndex(ID_PLC_Tamb,  &value);
}


int addWrite_PLC_Tamb(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_Tamb, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_EncoderLo(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncoderLo,  &value);
}


int addWrite_PLC_EncoderLo(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncoderLo, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_EncoderHi(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncoderHi,  &value);
}


int addWrite_PLC_EncoderHi(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncoderHi, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_StatusReg(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_StatusReg,  &value);
}


int addWrite_PLC_StatusReg(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_StatusReg, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_RPM,  &value);
}


int addWrite_PLC_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_RPM, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_1(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_1,  &value);
}


int addWrite_PLC_AnOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_2(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_2,  &value);
}


int addWrite_PLC_AnOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf,  &value);
}


int addWrite_PLC_AnInConf(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf,  &value);
}


int addWrite_PLC_AnOutConf(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_ControlWord(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_ControlWord,  &value);
}


int addWrite_PLC_ControlWord(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_ControlWord, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_EncPreset_Lo(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncPreset_Lo,  &value);
}


int addWrite_PLC_EncPreset_Lo(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncPreset_Lo, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_EncPreset_Hi(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncPreset_Hi,  &value);
}


int addWrite_PLC_EncPreset_Hi(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncPreset_Hi, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_NETRUN(int value)
{
return writeVarByCtIndex(ID_CH0_NETRUN,  &value);
}


int addWrite_CH0_NETRUN(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_NETRUN, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_NETGOOD(int value)
{
return writeVarByCtIndex(ID_CH0_NETGOOD,  &value);
}


int addWrite_CH0_NETGOOD(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_NETGOOD, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_NETERR(u_int32_t value)
{
return writeVarByCtIndex(ID_CH0_NETERR,  &value);
}


int addWrite_CH0_NETERR(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_CH0_NETERR, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_NETRST(int value)
{
return writeVarByCtIndex(ID_CH0_NETRST,  &value);
}


int addWrite_CH0_NETRST(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_NETRST, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_NETDIS(int value)
{
return writeVarByCtIndex(ID_CH0_NETDIS,  &value);
}


int addWrite_CH0_NETDIS(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_NETDIS, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_01_NODERUN(int value)
{
return writeVarByCtIndex(ID_CH0_01_NODERUN,  &value);
}


int addWrite_CH0_01_NODERUN(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_01_NODERUN, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_01_NODEGOOD(int value)
{
return writeVarByCtIndex(ID_CH0_01_NODEGOOD,  &value);
}


int addWrite_CH0_01_NODEGOOD(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_01_NODEGOOD, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_01_NODEERR(u_int32_t value)
{
return writeVarByCtIndex(ID_CH0_01_NODEERR,  &value);
}


int addWrite_CH0_01_NODEERR(u_int32_t value)
{
return (prepareWriteVarByCtIndex(ID_CH0_01_NODEERR, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_01_NODERST(int value)
{
return writeVarByCtIndex(ID_CH0_01_NODERST,  &value);
}


int addWrite_CH0_01_NODERST(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_01_NODERST, &value, NULL, 0) == ERROR);
}


int doWrite_CH0_01_NODEDIS(int value)
{
return writeVarByCtIndex(ID_CH0_01_NODEDIS,  &value);
}


int addWrite_CH0_01_NODEDIS(int value)
{
return (prepareWriteVarByCtIndex(ID_CH0_01_NODEDIS, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_time(float value)
{
return writeVarByCtIndex(ID_PLC_time,  &value);
}


int addWrite_PLC_time(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_time, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_timeMin(float value)
{
return writeVarByCtIndex(ID_PLC_timeMin,  &value);
}


int addWrite_PLC_timeMin(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_timeMin, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_timeMax(float value)
{
return writeVarByCtIndex(ID_PLC_timeMax,  &value);
}


int addWrite_PLC_timeMax(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_timeMax, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_timeWin(float value)
{
return writeVarByCtIndex(ID_PLC_timeWin,  &value);
}


int addWrite_PLC_timeWin(float value)
{
return (prepareWriteVarByCtIndex(ID_PLC_timeWin, &value, NULL, 0) == ERROR);
}


int update_all(void)
{
int retval = 0;
retval += readFromDb(ID_PLC_DigIn_1, &PLC_DigIn_1);
retval += readFromDb(ID_PLC_DigIn_2, &PLC_DigIn_2);
retval += readFromDb(ID_PLC_DigIn_3, &PLC_DigIn_3);
retval += readFromDb(ID_PLC_DigIn_4, &PLC_DigIn_4);
retval += readFromDb(ID_PLC_DigIn_5, &PLC_DigIn_5);
retval += readFromDb(ID_PLC_DigIn_6, &PLC_DigIn_6);
retval += readFromDb(ID_PLC_DigIn_7, &PLC_DigIn_7);
retval += readFromDb(ID_PLC_DigIn_8, &PLC_DigIn_8);
retval += readFromDb(ID_PLC_DigIn_9_16, &PLC_DigIn_9_16);
retval += readFromDb(ID_PLC_DigIn_17_24, &PLC_DigIn_17_24);
retval += readFromDb(ID_PLC_DigIn_25_32, &PLC_DigIn_25_32);
retval += readFromDb(ID_PLC_DigOut_1, &PLC_DigOut_1);
retval += readFromDb(ID_PLC_DigOut_2, &PLC_DigOut_2);
retval += readFromDb(ID_PLC_DigOut_3, &PLC_DigOut_3);
retval += readFromDb(ID_PLC_DigOut_4, &PLC_DigOut_4);
retval += readFromDb(ID_PLC_DigOut_5, &PLC_DigOut_5);
retval += readFromDb(ID_PLC_DigOut_6, &PLC_DigOut_6);
retval += readFromDb(ID_PLC_DigOut_7, &PLC_DigOut_7);
retval += readFromDb(ID_PLC_DigOut_8, &PLC_DigOut_8);
retval += readFromDb(ID_PLC_DigOut_9, &PLC_DigOut_9);
retval += readFromDb(ID_PLC_DigOut_10, &PLC_DigOut_10);
retval += readFromDb(ID_PLC_DigOut_11, &PLC_DigOut_11);
retval += readFromDb(ID_PLC_DigOut_12, &PLC_DigOut_12);
retval += readFromDb(ID_PLC_AnIn_1, &PLC_AnIn_1);
retval += readFromDb(ID_PLC_AnIn_2, &PLC_AnIn_2);
retval += readFromDb(ID_PLC_AnIn_3, &PLC_AnIn_3);
retval += readFromDb(ID_PLC_AnIn_4, &PLC_AnIn_4);
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
retval += readFromDb(ID_PLC_EncoderLo, &PLC_EncoderLo);
retval += readFromDb(ID_PLC_EncoderHi, &PLC_EncoderHi);
retval += readFromDb(ID_PLC_StatusReg, &PLC_StatusReg);
retval += readFromDb(ID_PLC_RPM, &PLC_RPM);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_AnOut_2, &PLC_AnOut_2);
retval += readFromDb(ID_PLC_AnInConf, &PLC_AnInConf);
retval += readFromDb(ID_PLC_AnOutConf, &PLC_AnOutConf);
retval += readFromDb(ID_PLC_ControlWord, &PLC_ControlWord);
retval += readFromDb(ID_PLC_EncPreset_Lo, &PLC_EncPreset_Lo);
retval += readFromDb(ID_PLC_EncPreset_Hi, &PLC_EncPreset_Hi);
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
