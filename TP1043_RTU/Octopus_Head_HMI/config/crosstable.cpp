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
 
int16_t PLC_DigIn_1 = 0;
int16_t PLC_DigIn_2 = 0;
int16_t PLC_DigIn_3 = 0;
int16_t PLC_DigIn_4 = 0;
int16_t PLC_DigIn_5 = 0;
int16_t PLC_DigIn_6 = 0;
int16_t PLC_DigIn_7 = 0;
int16_t PLC_DigIn_8 = 0;
int16_t PLC_DigIn_9 = 0;
int16_t PLC_DigIn_10 = 0;
int16_t PLC_DigIn_11 = 0;
int16_t PLC_DigIn_12 = 0;
int16_t PLC_DigIn_13 = 0;
int16_t PLC_DigIn_14 = 0;
int16_t PLC_DigIn_15 = 0;
int16_t PLC_DigIn_16 = 0;
int16_t PLC_DigOut_1 = 0;
int16_t PLC_DigOut_2 = 0;
int16_t PLC_DigOut_3 = 0;
int16_t PLC_DigOut_4 = 0;
int16_t PLC_DigOut_5 = 0;
int16_t PLC_DigOut_6 = 0;
int16_t PLC_DigOut_7 = 0;
int16_t PLC_DigOut_8 = 0;
int16_t PLC_DigOut_9 = 0;
int16_t PLC_DigOut_10 = 0;
int16_t PLC_DigOut_11 = 0;
int16_t PLC_DigOut_12 = 0;
int16_t PLC_DigOut_13 = 0;
int16_t PLC_DigOut_14 = 0;
int16_t PLC_DigOut_15 = 0;
int16_t PLC_DigOut_16 = 0;
int16_t PLC_DigDir_1 = 0;
int16_t PLC_DigDir_2 = 0;
int16_t PLC_DigDir_3 = 0;
int16_t PLC_DigDir_4 = 0;
int16_t PLC_DigDir_5 = 0;
int16_t PLC_DigDir_6 = 0;
int16_t PLC_DigDir_7 = 0;
int16_t PLC_DigDir_8 = 0;
int16_t PLC_DigDir_9 = 0;
int16_t PLC_DigDir_10 = 0;
int16_t PLC_DigDir_11 = 0;
int16_t PLC_DigDir_12 = 0;
int16_t PLC_DigDir_13 = 0;
int16_t PLC_DigDir_14 = 0;
int16_t PLC_DigDir_15 = 0;
int16_t PLC_DigDir_16 = 0;
int16_t PLC_AnIn_1 = 0;
int16_t PLC_AnIn_2 = 0;
int16_t PLC_AnIn_3 = 0;
int16_t PLC_AnIn_4 = 0;
int16_t PLC_AnIn_5 = 0;
int16_t PLC_AnIn_6 = 0;
int16_t PLC_AnIn_7 = 0;
int16_t PLC_AnIn_8 = 0;
int16_t PLC_AnOut_1 = 0;
int16_t PLC_AnOut_2 = 0;
int16_t PLC_AnOut_3 = 0;
int16_t PLC_AnOut_4 = 0;
int16_t PLC_AnOut_5 = 0;
int16_t PLC_AnOut_6 = 0;
int16_t PLC_AnOut_7 = 0;
int16_t PLC_AnOut_8 = 0;
u_int16_t PLC_AnInConf_1 = 0;
u_int16_t PLC_AnInConf_2 = 0;
u_int16_t PLC_AnInConf_3 = 0;
u_int16_t PLC_AnInConf_4 = 0;
u_int16_t PLC_AnInConf_5 = 0;
u_int16_t PLC_AnInConf_6 = 0;
u_int16_t PLC_AnInConf_7 = 0;
u_int16_t PLC_AnInConf_8 = 0;
u_int16_t PLC_AnOutConf_1 = 0;
u_int16_t PLC_AnOutConf_2 = 0;
u_int16_t PLC_AnOutConf_3 = 0;
u_int16_t PLC_AnOutConf_4 = 0;
u_int16_t PLC_AnOutConf_5 = 0;
u_int16_t PLC_AnOutConf_6 = 0;
u_int16_t PLC_AnOutConf_7 = 0;
u_int16_t PLC_AnOutConf_8 = 0;
int16_t PLC_Tamb = 0;
u_int16_t PLC_EncoderLo = 0;
u_int16_t PLC_EncoderHi = 0;
u_int16_t PLC_StatusReg = 0;
u_int16_t PLC_ControlWord = 0;
u_int16_t PLC_EncPreset_Lo = 0;
u_int16_t PLC_EncPreset_Hi = 0;
u_int16_t PLC_EncoderReset = 0;
u_int16_t PLC_EncEnable = 0;
u_int16_t PLC_RPM = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;


int doWrite_PLC_DigIn_1(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_1,  &value);
}


int addWrite_PLC_DigIn_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_2(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_2,  &value);
}


int addWrite_PLC_DigIn_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_3(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_3,  &value);
}


int addWrite_PLC_DigIn_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_4(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_4,  &value);
}


int addWrite_PLC_DigIn_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_5(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_5,  &value);
}


int addWrite_PLC_DigIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_6(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_6,  &value);
}


int addWrite_PLC_DigIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_7(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_7,  &value);
}


int addWrite_PLC_DigIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_8(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_8,  &value);
}


int addWrite_PLC_DigIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_9(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_9,  &value);
}


int addWrite_PLC_DigIn_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_9, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_10(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_10,  &value);
}


int addWrite_PLC_DigIn_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_10, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_11(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_11,  &value);
}


int addWrite_PLC_DigIn_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_11, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_12(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_12,  &value);
}


int addWrite_PLC_DigIn_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_12, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_13(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_13,  &value);
}


int addWrite_PLC_DigIn_13(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_13, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_14(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_14,  &value);
}


int addWrite_PLC_DigIn_14(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_14, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_15(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_15,  &value);
}


int addWrite_PLC_DigIn_15(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_15, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigIn_16(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigIn_16,  &value);
}


int addWrite_PLC_DigIn_16(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigIn_16, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_1(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_1,  &value);
}


int addWrite_PLC_DigOut_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_2(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_2,  &value);
}


int addWrite_PLC_DigOut_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_3(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_3,  &value);
}


int addWrite_PLC_DigOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_4(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_4,  &value);
}


int addWrite_PLC_DigOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_5(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_5,  &value);
}


int addWrite_PLC_DigOut_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_6(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_6,  &value);
}


int addWrite_PLC_DigOut_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_7(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_7,  &value);
}


int addWrite_PLC_DigOut_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_8(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_8,  &value);
}


int addWrite_PLC_DigOut_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_9(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_9,  &value);
}


int addWrite_PLC_DigOut_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_9, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_10(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_10,  &value);
}


int addWrite_PLC_DigOut_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_10, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_11(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_11,  &value);
}


int addWrite_PLC_DigOut_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_11, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_12(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_12,  &value);
}


int addWrite_PLC_DigOut_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_12, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_13(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_13,  &value);
}


int addWrite_PLC_DigOut_13(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_13, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_14(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_14,  &value);
}


int addWrite_PLC_DigOut_14(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_14, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_15(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_15,  &value);
}


int addWrite_PLC_DigOut_15(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_15, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigOut_16(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigOut_16,  &value);
}


int addWrite_PLC_DigOut_16(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigOut_16, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_1(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_1,  &value);
}


int addWrite_PLC_DigDir_1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_2(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_2,  &value);
}


int addWrite_PLC_DigDir_2(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_3(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_3,  &value);
}


int addWrite_PLC_DigDir_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_4(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_4,  &value);
}


int addWrite_PLC_DigDir_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_5(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_5,  &value);
}


int addWrite_PLC_DigDir_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_6(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_6,  &value);
}


int addWrite_PLC_DigDir_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_7(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_7,  &value);
}


int addWrite_PLC_DigDir_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_8(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_8,  &value);
}


int addWrite_PLC_DigDir_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_9(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_9,  &value);
}


int addWrite_PLC_DigDir_9(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_9, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_10(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_10,  &value);
}


int addWrite_PLC_DigDir_10(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_10, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_11(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_11,  &value);
}


int addWrite_PLC_DigDir_11(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_11, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_12(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_12,  &value);
}


int addWrite_PLC_DigDir_12(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_12, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_13(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_13,  &value);
}


int addWrite_PLC_DigDir_13(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_13, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_14(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_14,  &value);
}


int addWrite_PLC_DigDir_14(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_14, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_15(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_15,  &value);
}


int addWrite_PLC_DigDir_15(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_15, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_DigDir_16(int16_t value)
{
return writeVarByCtIndex(ID_PLC_DigDir_16,  &value);
}


int addWrite_PLC_DigDir_16(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_DigDir_16, &value, NULL, 0) == ERROR);
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


int doWrite_PLC_AnIn_5(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_5,  &value);
}


int addWrite_PLC_AnIn_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_6(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_6,  &value);
}


int addWrite_PLC_AnIn_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_7(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_7,  &value);
}


int addWrite_PLC_AnIn_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnIn_8(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnIn_8,  &value);
}


int addWrite_PLC_AnIn_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnIn_8, &value, NULL, 0) == ERROR);
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


int doWrite_PLC_AnOut_3(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_3,  &value);
}


int addWrite_PLC_AnOut_3(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_4(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_4,  &value);
}


int addWrite_PLC_AnOut_4(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_5(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_5,  &value);
}


int addWrite_PLC_AnOut_5(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_6(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_6,  &value);
}


int addWrite_PLC_AnOut_6(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_7(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_7,  &value);
}


int addWrite_PLC_AnOut_7(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOut_8(int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOut_8,  &value);
}


int addWrite_PLC_AnOut_8(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOut_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_1,  &value);
}


int addWrite_PLC_AnInConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_2,  &value);
}


int addWrite_PLC_AnInConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_3,  &value);
}


int addWrite_PLC_AnInConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_4,  &value);
}


int addWrite_PLC_AnInConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_5(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_5,  &value);
}


int addWrite_PLC_AnInConf_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_6(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_6,  &value);
}


int addWrite_PLC_AnInConf_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_7(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_7,  &value);
}


int addWrite_PLC_AnInConf_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnInConf_8(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnInConf_8,  &value);
}


int addWrite_PLC_AnInConf_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnInConf_8, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_1(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_1,  &value);
}


int addWrite_PLC_AnOutConf_1(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_1, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_2(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_2,  &value);
}


int addWrite_PLC_AnOutConf_2(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_2, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_3(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_3,  &value);
}


int addWrite_PLC_AnOutConf_3(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_3, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_4(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_4,  &value);
}


int addWrite_PLC_AnOutConf_4(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_4, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_5(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_5,  &value);
}


int addWrite_PLC_AnOutConf_5(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_5, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_6(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_6,  &value);
}


int addWrite_PLC_AnOutConf_6(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_6, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_7(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_7,  &value);
}


int addWrite_PLC_AnOutConf_7(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_7, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_AnOutConf_8(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_AnOutConf_8,  &value);
}


int addWrite_PLC_AnOutConf_8(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_AnOutConf_8, &value, NULL, 0) == ERROR);
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


int doWrite_PLC_EncoderReset(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncoderReset,  &value);
}


int addWrite_PLC_EncoderReset(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncoderReset, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_EncEnable(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_EncEnable,  &value);
}


int addWrite_PLC_EncEnable(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_EncEnable, &value, NULL, 0) == ERROR);
}


int doWrite_PLC_RPM(u_int16_t value)
{
return writeVarByCtIndex(ID_PLC_RPM,  &value);
}


int addWrite_PLC_RPM(u_int16_t value)
{
return (prepareWriteVarByCtIndex(ID_PLC_RPM, &value, NULL, 0) == ERROR);
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
retval += readFromDb(ID_PLC_DigIn_9, &PLC_DigIn_9);
retval += readFromDb(ID_PLC_DigIn_10, &PLC_DigIn_10);
retval += readFromDb(ID_PLC_DigIn_11, &PLC_DigIn_11);
retval += readFromDb(ID_PLC_DigIn_12, &PLC_DigIn_12);
retval += readFromDb(ID_PLC_DigIn_13, &PLC_DigIn_13);
retval += readFromDb(ID_PLC_DigIn_14, &PLC_DigIn_14);
retval += readFromDb(ID_PLC_DigIn_15, &PLC_DigIn_15);
retval += readFromDb(ID_PLC_DigIn_16, &PLC_DigIn_16);
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
retval += readFromDb(ID_PLC_DigOut_13, &PLC_DigOut_13);
retval += readFromDb(ID_PLC_DigOut_14, &PLC_DigOut_14);
retval += readFromDb(ID_PLC_DigOut_15, &PLC_DigOut_15);
retval += readFromDb(ID_PLC_DigOut_16, &PLC_DigOut_16);
retval += readFromDb(ID_PLC_DigDir_1, &PLC_DigDir_1);
retval += readFromDb(ID_PLC_DigDir_2, &PLC_DigDir_2);
retval += readFromDb(ID_PLC_DigDir_3, &PLC_DigDir_3);
retval += readFromDb(ID_PLC_DigDir_4, &PLC_DigDir_4);
retval += readFromDb(ID_PLC_DigDir_5, &PLC_DigDir_5);
retval += readFromDb(ID_PLC_DigDir_6, &PLC_DigDir_6);
retval += readFromDb(ID_PLC_DigDir_7, &PLC_DigDir_7);
retval += readFromDb(ID_PLC_DigDir_8, &PLC_DigDir_8);
retval += readFromDb(ID_PLC_DigDir_9, &PLC_DigDir_9);
retval += readFromDb(ID_PLC_DigDir_10, &PLC_DigDir_10);
retval += readFromDb(ID_PLC_DigDir_11, &PLC_DigDir_11);
retval += readFromDb(ID_PLC_DigDir_12, &PLC_DigDir_12);
retval += readFromDb(ID_PLC_DigDir_13, &PLC_DigDir_13);
retval += readFromDb(ID_PLC_DigDir_14, &PLC_DigDir_14);
retval += readFromDb(ID_PLC_DigDir_15, &PLC_DigDir_15);
retval += readFromDb(ID_PLC_DigDir_16, &PLC_DigDir_16);
retval += readFromDb(ID_PLC_AnIn_1, &PLC_AnIn_1);
retval += readFromDb(ID_PLC_AnIn_2, &PLC_AnIn_2);
retval += readFromDb(ID_PLC_AnIn_3, &PLC_AnIn_3);
retval += readFromDb(ID_PLC_AnIn_4, &PLC_AnIn_4);
retval += readFromDb(ID_PLC_AnIn_5, &PLC_AnIn_5);
retval += readFromDb(ID_PLC_AnIn_6, &PLC_AnIn_6);
retval += readFromDb(ID_PLC_AnIn_7, &PLC_AnIn_7);
retval += readFromDb(ID_PLC_AnIn_8, &PLC_AnIn_8);
retval += readFromDb(ID_PLC_AnOut_1, &PLC_AnOut_1);
retval += readFromDb(ID_PLC_AnOut_2, &PLC_AnOut_2);
retval += readFromDb(ID_PLC_AnOut_3, &PLC_AnOut_3);
retval += readFromDb(ID_PLC_AnOut_4, &PLC_AnOut_4);
retval += readFromDb(ID_PLC_AnOut_5, &PLC_AnOut_5);
retval += readFromDb(ID_PLC_AnOut_6, &PLC_AnOut_6);
retval += readFromDb(ID_PLC_AnOut_7, &PLC_AnOut_7);
retval += readFromDb(ID_PLC_AnOut_8, &PLC_AnOut_8);
retval += readFromDb(ID_PLC_AnInConf_1, &PLC_AnInConf_1);
retval += readFromDb(ID_PLC_AnInConf_2, &PLC_AnInConf_2);
retval += readFromDb(ID_PLC_AnInConf_3, &PLC_AnInConf_3);
retval += readFromDb(ID_PLC_AnInConf_4, &PLC_AnInConf_4);
retval += readFromDb(ID_PLC_AnInConf_5, &PLC_AnInConf_5);
retval += readFromDb(ID_PLC_AnInConf_6, &PLC_AnInConf_6);
retval += readFromDb(ID_PLC_AnInConf_7, &PLC_AnInConf_7);
retval += readFromDb(ID_PLC_AnInConf_8, &PLC_AnInConf_8);
retval += readFromDb(ID_PLC_AnOutConf_1, &PLC_AnOutConf_1);
retval += readFromDb(ID_PLC_AnOutConf_2, &PLC_AnOutConf_2);
retval += readFromDb(ID_PLC_AnOutConf_3, &PLC_AnOutConf_3);
retval += readFromDb(ID_PLC_AnOutConf_4, &PLC_AnOutConf_4);
retval += readFromDb(ID_PLC_AnOutConf_5, &PLC_AnOutConf_5);
retval += readFromDb(ID_PLC_AnOutConf_6, &PLC_AnOutConf_6);
retval += readFromDb(ID_PLC_AnOutConf_7, &PLC_AnOutConf_7);
retval += readFromDb(ID_PLC_AnOutConf_8, &PLC_AnOutConf_8);
retval += readFromDb(ID_PLC_Tamb, &PLC_Tamb);
retval += readFromDb(ID_PLC_EncoderLo, &PLC_EncoderLo);
retval += readFromDb(ID_PLC_EncoderHi, &PLC_EncoderHi);
retval += readFromDb(ID_PLC_StatusReg, &PLC_StatusReg);
retval += readFromDb(ID_PLC_ControlWord, &PLC_ControlWord);
retval += readFromDb(ID_PLC_EncPreset_Lo, &PLC_EncPreset_Lo);
retval += readFromDb(ID_PLC_EncPreset_Hi, &PLC_EncPreset_Hi);
retval += readFromDb(ID_PLC_EncoderReset, &PLC_EncoderReset);
retval += readFromDb(ID_PLC_EncEnable, &PLC_EncEnable);
retval += readFromDb(ID_PLC_RPM, &PLC_RPM);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
return retval;
}
