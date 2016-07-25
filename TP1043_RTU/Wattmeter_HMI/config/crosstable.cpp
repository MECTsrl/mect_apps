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
 
u_int16_t Potenza = 0;
u_int16_t Tensione = 0;
int Potenza_Critica = 0;
int Potenza_Distacco = 0;
u_int16_t V_L1_N = 0;
u_int16_t A_L1 = 0;
u_int16_t W_L1 = 0;
u_int16_t VT_RATIO = 0;
u_int16_t CT_RATIO = 0;
u_int32_t RTU0_TYPE_PORT = 0;
u_int32_t RTU0_BAUDRATE = 0;
u_int32_t RTU0_STATUS = 0;
u_int32_t RTU0_READS = 0;
u_int32_t RTU0_WRITES = 0;
u_int32_t RTU0_TIMEOUTS = 0;
u_int32_t RTU0_COMM_ERRORS = 0;
u_int32_t RTU0_LAST_ERROR = 0;
u_int32_t RTU0_WRITE_QUEUE = 0;
u_int32_t RTU0_READ_QUEUE = 0;
u_int32_t TCPS_TYPE_PORT = 0;
u_int32_t TCPS_IP_ADDRESS = 0;
u_int32_t TCPS_STATUS = 0;
u_int32_t TCPS_READS = 0;
u_int32_t TCPS_WRITES = 0;
u_int32_t TCPS_TIMEOUTS = 0;
u_int32_t TCPS_COMM_ERRORS = 0;
u_int32_t TCPS_LAST_ERROR = 0;
u_int32_t TCPS_WRITE_QUEUE = 0;
u_int32_t TCPS_READ_QUEUE = 0;
u_int32_t NODE_01_DEV_NODE = 0;
u_int32_t NODE_01_STATUS = 0;
u_int32_t NODE_02_DEV_NODE = 0;
u_int32_t NODE_02_STATUS = 0;
u_int32_t NODE_03_DEV_NODE = 0;
u_int32_t NODE_03_STATUS = 0;
float PLC_time = 0;
float PLC_timeMin = 0;
float PLC_timeMax = 0;
float PLC_timeWin = 0;
u_int16_t PLC_Version = 0;
u_int16_t PLC_EngineStatus = 0;
int PLC_ResetValues = 0;


int doWrite_Potenza(u_int16_t value)
{
return doWrite(ID_Potenza,  &value);
}


int addWrite_Potenza(u_int16_t value)
{
return addWrite(ID_Potenza, &value);
}


int getStatus_Potenza()
{
return getStatus(ID_Potenza);
}


int doWrite_Tensione(u_int16_t value)
{
return doWrite(ID_Tensione,  &value);
}


int addWrite_Tensione(u_int16_t value)
{
return addWrite(ID_Tensione, &value);
}


int getStatus_Tensione()
{
return getStatus(ID_Tensione);
}


int doWrite_Potenza_Critica(int value)
{
return doWrite(ID_Potenza_Critica,  &value);
}


int addWrite_Potenza_Critica(int value)
{
return addWrite(ID_Potenza_Critica, &value);
}


int getStatus_Potenza_Critica()
{
return getStatus(ID_Potenza_Critica);
}


int doWrite_Potenza_Distacco(int value)
{
return doWrite(ID_Potenza_Distacco,  &value);
}


int addWrite_Potenza_Distacco(int value)
{
return addWrite(ID_Potenza_Distacco, &value);
}


int getStatus_Potenza_Distacco()
{
return getStatus(ID_Potenza_Distacco);
}


int doWrite_V_L1_N(u_int16_t value)
{
return doWrite(ID_V_L1_N,  &value);
}


int addWrite_V_L1_N(u_int16_t value)
{
return addWrite(ID_V_L1_N, &value);
}


int getStatus_V_L1_N()
{
return getStatus(ID_V_L1_N);
}


int doWrite_A_L1(u_int16_t value)
{
return doWrite(ID_A_L1,  &value);
}


int addWrite_A_L1(u_int16_t value)
{
return addWrite(ID_A_L1, &value);
}


int getStatus_A_L1()
{
return getStatus(ID_A_L1);
}


int doWrite_W_L1(u_int16_t value)
{
return doWrite(ID_W_L1,  &value);
}


int addWrite_W_L1(u_int16_t value)
{
return addWrite(ID_W_L1, &value);
}


int getStatus_W_L1()
{
return getStatus(ID_W_L1);
}


int doWrite_VT_RATIO(u_int16_t value)
{
return doWrite(ID_VT_RATIO,  &value);
}


int addWrite_VT_RATIO(u_int16_t value)
{
return addWrite(ID_VT_RATIO, &value);
}


int getStatus_VT_RATIO()
{
return getStatus(ID_VT_RATIO);
}


int doWrite_CT_RATIO(u_int16_t value)
{
return doWrite(ID_CT_RATIO,  &value);
}


int addWrite_CT_RATIO(u_int16_t value)
{
return addWrite(ID_CT_RATIO, &value);
}


int getStatus_CT_RATIO()
{
return getStatus(ID_CT_RATIO);
}


int doWrite_RTU0_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_RTU0_TYPE_PORT,  &value);
}


int addWrite_RTU0_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_RTU0_TYPE_PORT, &value);
}


int getStatus_RTU0_TYPE_PORT()
{
return getStatus(ID_RTU0_TYPE_PORT);
}


int doWrite_RTU0_BAUDRATE(u_int32_t value)
{
return doWrite(ID_RTU0_BAUDRATE,  &value);
}


int addWrite_RTU0_BAUDRATE(u_int32_t value)
{
return addWrite(ID_RTU0_BAUDRATE, &value);
}


int getStatus_RTU0_BAUDRATE()
{
return getStatus(ID_RTU0_BAUDRATE);
}


int doWrite_RTU0_STATUS(u_int32_t value)
{
return doWrite(ID_RTU0_STATUS,  &value);
}


int addWrite_RTU0_STATUS(u_int32_t value)
{
return addWrite(ID_RTU0_STATUS, &value);
}


int getStatus_RTU0_STATUS()
{
return getStatus(ID_RTU0_STATUS);
}


int doWrite_RTU0_READS(u_int32_t value)
{
return doWrite(ID_RTU0_READS,  &value);
}


int addWrite_RTU0_READS(u_int32_t value)
{
return addWrite(ID_RTU0_READS, &value);
}


int getStatus_RTU0_READS()
{
return getStatus(ID_RTU0_READS);
}


int doWrite_RTU0_WRITES(u_int32_t value)
{
return doWrite(ID_RTU0_WRITES,  &value);
}


int addWrite_RTU0_WRITES(u_int32_t value)
{
return addWrite(ID_RTU0_WRITES, &value);
}


int getStatus_RTU0_WRITES()
{
return getStatus(ID_RTU0_WRITES);
}


int doWrite_RTU0_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_RTU0_TIMEOUTS,  &value);
}


int addWrite_RTU0_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_RTU0_TIMEOUTS, &value);
}


int getStatus_RTU0_TIMEOUTS()
{
return getStatus(ID_RTU0_TIMEOUTS);
}


int doWrite_RTU0_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_RTU0_COMM_ERRORS,  &value);
}


int addWrite_RTU0_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_RTU0_COMM_ERRORS, &value);
}


int getStatus_RTU0_COMM_ERRORS()
{
return getStatus(ID_RTU0_COMM_ERRORS);
}


int doWrite_RTU0_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_RTU0_LAST_ERROR,  &value);
}


int addWrite_RTU0_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_RTU0_LAST_ERROR, &value);
}


int getStatus_RTU0_LAST_ERROR()
{
return getStatus(ID_RTU0_LAST_ERROR);
}


int doWrite_RTU0_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU0_WRITE_QUEUE,  &value);
}


int addWrite_RTU0_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU0_WRITE_QUEUE, &value);
}


int getStatus_RTU0_WRITE_QUEUE()
{
return getStatus(ID_RTU0_WRITE_QUEUE);
}


int doWrite_RTU0_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_RTU0_READ_QUEUE,  &value);
}


int addWrite_RTU0_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_RTU0_READ_QUEUE, &value);
}


int getStatus_RTU0_READ_QUEUE()
{
return getStatus(ID_RTU0_READ_QUEUE);
}


int doWrite_TCPS_TYPE_PORT(u_int32_t value)
{
return doWrite(ID_TCPS_TYPE_PORT,  &value);
}


int addWrite_TCPS_TYPE_PORT(u_int32_t value)
{
return addWrite(ID_TCPS_TYPE_PORT, &value);
}


int getStatus_TCPS_TYPE_PORT()
{
return getStatus(ID_TCPS_TYPE_PORT);
}


int doWrite_TCPS_IP_ADDRESS(u_int32_t value)
{
return doWrite(ID_TCPS_IP_ADDRESS,  &value);
}


int addWrite_TCPS_IP_ADDRESS(u_int32_t value)
{
return addWrite(ID_TCPS_IP_ADDRESS, &value);
}


int getStatus_TCPS_IP_ADDRESS()
{
return getStatus(ID_TCPS_IP_ADDRESS);
}


int doWrite_TCPS_STATUS(u_int32_t value)
{
return doWrite(ID_TCPS_STATUS,  &value);
}


int addWrite_TCPS_STATUS(u_int32_t value)
{
return addWrite(ID_TCPS_STATUS, &value);
}


int getStatus_TCPS_STATUS()
{
return getStatus(ID_TCPS_STATUS);
}


int doWrite_TCPS_READS(u_int32_t value)
{
return doWrite(ID_TCPS_READS,  &value);
}


int addWrite_TCPS_READS(u_int32_t value)
{
return addWrite(ID_TCPS_READS, &value);
}


int getStatus_TCPS_READS()
{
return getStatus(ID_TCPS_READS);
}


int doWrite_TCPS_WRITES(u_int32_t value)
{
return doWrite(ID_TCPS_WRITES,  &value);
}


int addWrite_TCPS_WRITES(u_int32_t value)
{
return addWrite(ID_TCPS_WRITES, &value);
}


int getStatus_TCPS_WRITES()
{
return getStatus(ID_TCPS_WRITES);
}


int doWrite_TCPS_TIMEOUTS(u_int32_t value)
{
return doWrite(ID_TCPS_TIMEOUTS,  &value);
}


int addWrite_TCPS_TIMEOUTS(u_int32_t value)
{
return addWrite(ID_TCPS_TIMEOUTS, &value);
}


int getStatus_TCPS_TIMEOUTS()
{
return getStatus(ID_TCPS_TIMEOUTS);
}


int doWrite_TCPS_COMM_ERRORS(u_int32_t value)
{
return doWrite(ID_TCPS_COMM_ERRORS,  &value);
}


int addWrite_TCPS_COMM_ERRORS(u_int32_t value)
{
return addWrite(ID_TCPS_COMM_ERRORS, &value);
}


int getStatus_TCPS_COMM_ERRORS()
{
return getStatus(ID_TCPS_COMM_ERRORS);
}


int doWrite_TCPS_LAST_ERROR(u_int32_t value)
{
return doWrite(ID_TCPS_LAST_ERROR,  &value);
}


int addWrite_TCPS_LAST_ERROR(u_int32_t value)
{
return addWrite(ID_TCPS_LAST_ERROR, &value);
}


int getStatus_TCPS_LAST_ERROR()
{
return getStatus(ID_TCPS_LAST_ERROR);
}


int doWrite_TCPS_WRITE_QUEUE(u_int32_t value)
{
return doWrite(ID_TCPS_WRITE_QUEUE,  &value);
}


int addWrite_TCPS_WRITE_QUEUE(u_int32_t value)
{
return addWrite(ID_TCPS_WRITE_QUEUE, &value);
}


int getStatus_TCPS_WRITE_QUEUE()
{
return getStatus(ID_TCPS_WRITE_QUEUE);
}


int doWrite_TCPS_READ_QUEUE(u_int32_t value)
{
return doWrite(ID_TCPS_READ_QUEUE,  &value);
}


int addWrite_TCPS_READ_QUEUE(u_int32_t value)
{
return addWrite(ID_TCPS_READ_QUEUE, &value);
}


int getStatus_TCPS_READ_QUEUE()
{
return getStatus(ID_TCPS_READ_QUEUE);
}


int doWrite_NODE_01_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_01_DEV_NODE,  &value);
}


int addWrite_NODE_01_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_01_DEV_NODE, &value);
}


int getStatus_NODE_01_DEV_NODE()
{
return getStatus(ID_NODE_01_DEV_NODE);
}


int doWrite_NODE_01_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_01_STATUS,  &value);
}


int addWrite_NODE_01_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_01_STATUS, &value);
}


int getStatus_NODE_01_STATUS()
{
return getStatus(ID_NODE_01_STATUS);
}


int doWrite_NODE_02_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_02_DEV_NODE,  &value);
}


int addWrite_NODE_02_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_02_DEV_NODE, &value);
}


int getStatus_NODE_02_DEV_NODE()
{
return getStatus(ID_NODE_02_DEV_NODE);
}


int doWrite_NODE_02_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_02_STATUS,  &value);
}


int addWrite_NODE_02_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_02_STATUS, &value);
}


int getStatus_NODE_02_STATUS()
{
return getStatus(ID_NODE_02_STATUS);
}


int doWrite_NODE_03_DEV_NODE(u_int32_t value)
{
return doWrite(ID_NODE_03_DEV_NODE,  &value);
}


int addWrite_NODE_03_DEV_NODE(u_int32_t value)
{
return addWrite(ID_NODE_03_DEV_NODE, &value);
}


int getStatus_NODE_03_DEV_NODE()
{
return getStatus(ID_NODE_03_DEV_NODE);
}


int doWrite_NODE_03_STATUS(u_int32_t value)
{
return doWrite(ID_NODE_03_STATUS,  &value);
}


int addWrite_NODE_03_STATUS(u_int32_t value)
{
return addWrite(ID_NODE_03_STATUS, &value);
}


int getStatus_NODE_03_STATUS()
{
return getStatus(ID_NODE_03_STATUS);
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
retval += readFromDb(ID_Potenza, &Potenza);
retval += readFromDb(ID_Tensione, &Tensione);
retval += readFromDb(ID_Potenza_Critica, &Potenza_Critica);
retval += readFromDb(ID_Potenza_Distacco, &Potenza_Distacco);
retval += readFromDb(ID_V_L1_N, &V_L1_N);
retval += readFromDb(ID_A_L1, &A_L1);
retval += readFromDb(ID_W_L1, &W_L1);
retval += readFromDb(ID_VT_RATIO, &VT_RATIO);
retval += readFromDb(ID_CT_RATIO, &CT_RATIO);
retval += readFromDb(ID_RTU0_TYPE_PORT, &RTU0_TYPE_PORT);
retval += readFromDb(ID_RTU0_BAUDRATE, &RTU0_BAUDRATE);
retval += readFromDb(ID_RTU0_STATUS, &RTU0_STATUS);
retval += readFromDb(ID_RTU0_READS, &RTU0_READS);
retval += readFromDb(ID_RTU0_WRITES, &RTU0_WRITES);
retval += readFromDb(ID_RTU0_TIMEOUTS, &RTU0_TIMEOUTS);
retval += readFromDb(ID_RTU0_COMM_ERRORS, &RTU0_COMM_ERRORS);
retval += readFromDb(ID_RTU0_LAST_ERROR, &RTU0_LAST_ERROR);
retval += readFromDb(ID_RTU0_WRITE_QUEUE, &RTU0_WRITE_QUEUE);
retval += readFromDb(ID_RTU0_READ_QUEUE, &RTU0_READ_QUEUE);
retval += readFromDb(ID_TCPS_TYPE_PORT, &TCPS_TYPE_PORT);
retval += readFromDb(ID_TCPS_IP_ADDRESS, &TCPS_IP_ADDRESS);
retval += readFromDb(ID_TCPS_STATUS, &TCPS_STATUS);
retval += readFromDb(ID_TCPS_READS, &TCPS_READS);
retval += readFromDb(ID_TCPS_WRITES, &TCPS_WRITES);
retval += readFromDb(ID_TCPS_TIMEOUTS, &TCPS_TIMEOUTS);
retval += readFromDb(ID_TCPS_COMM_ERRORS, &TCPS_COMM_ERRORS);
retval += readFromDb(ID_TCPS_LAST_ERROR, &TCPS_LAST_ERROR);
retval += readFromDb(ID_TCPS_WRITE_QUEUE, &TCPS_WRITE_QUEUE);
retval += readFromDb(ID_TCPS_READ_QUEUE, &TCPS_READ_QUEUE);
retval += readFromDb(ID_NODE_01_DEV_NODE, &NODE_01_DEV_NODE);
retval += readFromDb(ID_NODE_01_STATUS, &NODE_01_STATUS);
retval += readFromDb(ID_NODE_02_DEV_NODE, &NODE_02_DEV_NODE);
retval += readFromDb(ID_NODE_02_STATUS, &NODE_02_STATUS);
retval += readFromDb(ID_NODE_03_DEV_NODE, &NODE_03_DEV_NODE);
retval += readFromDb(ID_NODE_03_STATUS, &NODE_03_STATUS);
retval += readFromDb(ID_PLC_time, &PLC_time);
retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
retval += readFromDb(ID_PLC_Version, &PLC_Version);
retval += readFromDb(ID_PLC_EngineStatus, &PLC_EngineStatus);
retval += readFromDb(ID_PLC_ResetValues, &PLC_ResetValues);
return retval;
}
