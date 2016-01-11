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
 
#define ID_Potenza 193
extern int16_t Potenza;
int doWrite_Potenza(int16_t value);
int prepareWrite_Potenza(int16_t value);
 
#define ID_Tensione 194
extern int16_t Tensione;
int doWrite_Tensione(int16_t value);
int prepareWrite_Tensione(int16_t value);
 
#define ID_V_L1_N 201
extern int16_t V_L1_N;
int doWrite_V_L1_N(int16_t value);
int prepareWrite_V_L1_N(int16_t value);
 
#define ID_A_L1 202
extern int16_t A_L1;
int doWrite_A_L1(int16_t value);
int prepareWrite_A_L1(int16_t value);
 
#define ID_W_L1 203
extern int16_t W_L1;
int doWrite_W_L1(int16_t value);
int prepareWrite_W_L1(int16_t value);
 
#define ID_VT_RATIO 210
extern int16_t VT_RATIO;
int doWrite_VT_RATIO(int16_t value);
int prepareWrite_VT_RATIO(int16_t value);
 
#define ID_CT_RATIO 211
extern int16_t CT_RATIO;
int doWrite_CT_RATIO(int16_t value);
int prepareWrite_CT_RATIO(int16_t value);
 
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
