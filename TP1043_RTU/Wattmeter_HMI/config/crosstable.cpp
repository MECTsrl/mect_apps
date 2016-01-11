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
 
int16_t Potenza = 0;
int16_t Tensione = 0;
int16_t V_L1_N = 0;
int16_t A_L1 = 0;
int16_t W_L1 = 0;
int16_t VT_RATIO = 0;
int16_t CT_RATIO = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;


int doWrite_Potenza(int16_t value)
{
return writeVarByCtIndex(ID_Potenza,  &value);
}


int addWrite_Potenza(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_Potenza, &value, NULL, 0) == ERROR);
}


int doWrite_Tensione(int16_t value)
{
return writeVarByCtIndex(ID_Tensione,  &value);
}


int addWrite_Tensione(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_Tensione, &value, NULL, 0) == ERROR);
}


int doWrite_V_L1_N(int16_t value)
{
return writeVarByCtIndex(ID_V_L1_N,  &value);
}


int addWrite_V_L1_N(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_V_L1_N, &value, NULL, 0) == ERROR);
}


int doWrite_A_L1(int16_t value)
{
return writeVarByCtIndex(ID_A_L1,  &value);
}


int addWrite_A_L1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_A_L1, &value, NULL, 0) == ERROR);
}


int doWrite_W_L1(int16_t value)
{
return writeVarByCtIndex(ID_W_L1,  &value);
}


int addWrite_W_L1(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_W_L1, &value, NULL, 0) == ERROR);
}


int doWrite_VT_RATIO(int16_t value)
{
return writeVarByCtIndex(ID_VT_RATIO,  &value);
}


int addWrite_VT_RATIO(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_VT_RATIO, &value, NULL, 0) == ERROR);
}


int doWrite_CT_RATIO(int16_t value)
{
return writeVarByCtIndex(ID_CT_RATIO,  &value);
}


int addWrite_CT_RATIO(int16_t value)
{
return (prepareWriteVarByCtIndex(ID_CT_RATIO, &value, NULL, 0) == ERROR);
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
retval += readFromDb(ID_Potenza, &Potenza);
retval += readFromDb(ID_Tensione, &Tensione);
retval += readFromDb(ID_V_L1_N, &V_L1_N);
retval += readFromDb(ID_A_L1, &A_L1);
retval += readFromDb(ID_W_L1, &W_L1);
retval += readFromDb(ID_VT_RATIO, &VT_RATIO);
retval += readFromDb(ID_CT_RATIO, &CT_RATIO);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
return retval;
}
