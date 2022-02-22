/* File automatically generated by the Crosstable compiler */
/* from the Crosstable file config/Crosstable.csv. */

/* BIT        ->  int       */
/* BYTE_BIT   ->  int       */
/* WORD_BIT   ->  int       */
/* DWORD_BIT  ->  int       */
/* BYTE       ->  u_int8_t  */
/* UINT       ->  u_int16_t */
/* UINTBA     ->  UINTBA    */
/* INT        ->  int16_t   */
/* INTBA      ->  INTBA     */
/* UDINT      ->  u_int32_t */
/* UDINTBADC  ->  UDINTBADC */
/* UDINTCDAB  ->  UDINTCDAB */
/* UDINTDCBA  ->  UDINTDCBA */
/* DINT       ->  int32_t   */
/* DINTBADC   ->  DINTBADC  */
/* DINTCDAB   ->  DINTCDAB  */
/* DINTDCBA   ->  DINTDCBA  */
/* REAL       ->  float     */
/* REALBADC   ->  REALBADC  */
/* REALCDAB   ->  REALCDAB  */
/* REALDCBA   ->  REALDCBA  */

#include "crosstable.h"
#include "cross_table_utility.h"
#include "global_var.h"

/*
 * Variable RTU3_TYPE_PORT
 */

u_int32_t RTU3_TYPE_PORT = 0;


/*
 * Variable RTU3_BAUDRATE
 */

u_int32_t RTU3_BAUDRATE = 0;


/*
 * Variable RTU3_STATUS
 */

u_int32_t RTU3_STATUS = 0;


/*
 * Variable RTU3_READS
 */

u_int32_t RTU3_READS = 0;


/*
 * Variable RTU3_WRITES
 */

u_int32_t RTU3_WRITES = 0;


/*
 * Variable RTU3_TIMEOUTS
 */

u_int32_t RTU3_TIMEOUTS = 0;


/*
 * Variable RTU3_COMM_ERRORS
 */

u_int32_t RTU3_COMM_ERRORS = 0;


/*
 * Variable RTU3_LAST_ERROR
 */

u_int32_t RTU3_LAST_ERROR = 0;


/*
 * Variable RTU3_WRITE_QUEUE
 */

u_int32_t RTU3_WRITE_QUEUE = 0;


/*
 * Variable RTU3_BUS_LOAD
 */

u_int32_t RTU3_BUS_LOAD = 0;


/*
 * Variable NODE_01_DEV_NODE
 */

u_int32_t NODE_01_DEV_NODE = 0;


/*
 * Variable NODE_01_STATUS
 */

u_int32_t NODE_01_STATUS = 0;


/*
 * Variable PLC_FWrevision
 */

u_int16_t PLC_FWrevision = 0;


/*
 * Variable PLC_HWconfig
 */

u_int16_t PLC_HWconfig = 0;


/*
 * Variable PLC_DigDir_1
 */

int PLC_DigDir_1 = 0;


/*
 * Variable PLC_DigDir_2
 */

int PLC_DigDir_2 = 0;


/*
 * Variable PLC_DigDir_3
 */

int PLC_DigDir_3 = 0;


/*
 * Variable PLC_DigDir_4
 */

int PLC_DigDir_4 = 0;


/*
 * Variable PLC_DigDir_5
 */

int PLC_DigDir_5 = 0;


/*
 * Variable PLC_DigDir_6
 */

int PLC_DigDir_6 = 0;


/*
 * Variable PLC_DigDir_7
 */

int PLC_DigDir_7 = 0;


/*
 * Variable PLC_DigDir_8
 */

int PLC_DigDir_8 = 0;


/*
 * Variable PLC_DigOut_1
 */

int PLC_DigOut_1 = 0;


/*
 * Variable PLC_DigOut_2
 */

int PLC_DigOut_2 = 0;


/*
 * Variable PLC_DigOut_3
 */

int PLC_DigOut_3 = 0;


/*
 * Variable PLC_DigOut_4
 */

int PLC_DigOut_4 = 0;


/*
 * Variable PLC_DigOut_5
 */

int PLC_DigOut_5 = 0;


/*
 * Variable PLC_DigOut_6
 */

int PLC_DigOut_6 = 0;


/*
 * Variable PLC_DigOut_7
 */

int PLC_DigOut_7 = 0;


/*
 * Variable PLC_DigOut_8
 */

int PLC_DigOut_8 = 0;


/*
 * Variable PLC_DigIn_1
 */

int PLC_DigIn_1 = 0;


/*
 * Variable PLC_DigIn_2
 */

int PLC_DigIn_2 = 0;


/*
 * Variable PLC_DigIn_3
 */

int PLC_DigIn_3 = 0;


/*
 * Variable PLC_DigIn_4
 */

int PLC_DigIn_4 = 0;


/*
 * Variable PLC_DigIn_5
 */

int PLC_DigIn_5 = 0;


/*
 * Variable PLC_DigIn_6
 */

int PLC_DigIn_6 = 0;


/*
 * Variable PLC_DigIn_7
 */

int PLC_DigIn_7 = 0;


/*
 * Variable PLC_DigIn_8
 */

int PLC_DigIn_8 = 0;


/*
 * Variable PLC_Heartbeat
 */

u_int16_t PLC_Heartbeat = 0;


/*
 * Variable PLC_time	[ Seconds since boot (reset each 24h) ]
 */

float PLC_time = 0;


/*
 * Variable PLC_timeMin	[ 10 seconds window start ]
 */

float PLC_timeMin = 0;


/*
 * Variable PLC_timeMax	[ 10 seconds window stop ]
 */

float PLC_timeMax = 0;


/*
 * Variable PLC_timeWin	[ Graph display window ]
 */

float PLC_timeWin = 0;


/*
 * Variable PLC_Version	[ Run Time version ]
 */

u_int16_t PLC_Version = 0;


/*
 * Variable PLC_EngineStatus	[ PLC status ]
 */

u_int16_t PLC_EngineStatus = 0;


/*
 * Variable PLC_ResetValues	[ Diagnostic variables reset ]
 */

int PLC_ResetValues = 0;


/*
 * Variable PLC_buzzerOn	[ Buzzer sound (enable = 1 disable = 0) ]
 */

int PLC_buzzerOn = 0;


/*
 * Variable PLC_PLC_Version	[ PLC application version ]
 */

u_int16_t PLC_PLC_Version = 0;


/*
 * Variable PLC_HMI_Version	[ HMI application version ]
 */

u_int16_t PLC_HMI_Version = 0;


/*
 * Variable PLC_Year	[ Currently year ]
 */

u_int16_t PLC_Year = 0;


/*
 * Variable PLC_Month	[ Currently month ]
 */

u_int16_t PLC_Month = 0;


/*
 * Variable PLC_Day	[ Currently day ]
 */

u_int16_t PLC_Day = 0;


/*
 * Variable PLC_Hours	[ Currently hour ]
 */

u_int16_t PLC_Hours = 0;


/*
 * Variable PLC_Minutes	[ Currently minutes ]
 */

u_int16_t PLC_Minutes = 0;


/*
 * Variable PLC_Seconds	[ Currently seconds ]
 */

u_int16_t PLC_Seconds = 0;


/*
 * Variable PLC_UPTIME_s	[ Uptime in seconds (wraps in 136 years) ]
 */

u_int32_t PLC_UPTIME_s = 0;


/*
 * Variable PLC_UPTIME_cs	[ Uptime in centiseconds = 10 ms (wraps in 497 days) ]
 */

u_int32_t PLC_UPTIME_cs = 0;


/*
 * Variable PLC_WATCHDOGEN	[ Enable Watchdog ]
 */

int PLC_WATCHDOGEN = 0;


/*
 * Variable PLC_WATCHDOG_ms	[ Reset Watchdog timer ]
 */

u_int32_t PLC_WATCHDOG_ms = 0;


/*
 * Variable PLC_PRODUCT_ID	[ TP/TPAC/TPLC Product ID (Hex) ]
 */

u_int32_t PLC_PRODUCT_ID = 0;


/*
 * Variable PLC_SERIAL_NUMBER	[ TP/TPAC/TPLC Serial Number ]
 */

u_int32_t PLC_SERIAL_NUMBER = 0;


/*
 * Variable PLC_HMI_PAGE	[ HMI Page (page100=0x00000100) ]
 */

int32_t PLC_HMI_PAGE = 0;


/*
 * Variable PLC_BEEP_VOLUME	[ Beep volume (when buzzerOn) ]
 */

u_int8_t PLC_BEEP_VOLUME = 0;


/*
 * Variable PLC_TOUCH_VOLUME	[ Touch volume ]
 */

u_int8_t PLC_TOUCH_VOLUME = 0;


/*
 * Variable PLC_ALARM_VOLUME	[ Alarm volume (when alarm) ]
 */

u_int8_t PLC_ALARM_VOLUME = 0;


/*
 * Variable PLC_BUZZER	[ Enable dynamic buzzer sound (0x44332211 up=0x11(%) on=0x22(cs) off=0x33(cs) rep=0x44(times)) ]
 */

u_int32_t PLC_BUZZER = 0;

int
doWrite_RTU3_TYPE_PORT(u_int32_t value)
{
	return doWrite(ID_RTU3_TYPE_PORT, &value);
}

int
addWrite_RTU3_TYPE_PORT(u_int32_t value)
{
	return addWrite(ID_RTU3_TYPE_PORT, &value);
}

int
getStatus_RTU3_TYPE_PORT(void)
{
	return getStatus(ID_RTU3_TYPE_PORT);
}

int
doWrite_RTU3_BAUDRATE(u_int32_t value)
{
	return doWrite(ID_RTU3_BAUDRATE, &value);
}

int
addWrite_RTU3_BAUDRATE(u_int32_t value)
{
	return addWrite(ID_RTU3_BAUDRATE, &value);
}

int
getStatus_RTU3_BAUDRATE(void)
{
	return getStatus(ID_RTU3_BAUDRATE);
}

int
doWrite_RTU3_STATUS(u_int32_t value)
{
	return doWrite(ID_RTU3_STATUS, &value);
}

int
addWrite_RTU3_STATUS(u_int32_t value)
{
	return addWrite(ID_RTU3_STATUS, &value);
}

int
getStatus_RTU3_STATUS(void)
{
	return getStatus(ID_RTU3_STATUS);
}

int
doWrite_RTU3_READS(u_int32_t value)
{
	return doWrite(ID_RTU3_READS, &value);
}

int
addWrite_RTU3_READS(u_int32_t value)
{
	return addWrite(ID_RTU3_READS, &value);
}

int
getStatus_RTU3_READS(void)
{
	return getStatus(ID_RTU3_READS);
}

int
doWrite_RTU3_WRITES(u_int32_t value)
{
	return doWrite(ID_RTU3_WRITES, &value);
}

int
addWrite_RTU3_WRITES(u_int32_t value)
{
	return addWrite(ID_RTU3_WRITES, &value);
}

int
getStatus_RTU3_WRITES(void)
{
	return getStatus(ID_RTU3_WRITES);
}

int
doWrite_RTU3_TIMEOUTS(u_int32_t value)
{
	return doWrite(ID_RTU3_TIMEOUTS, &value);
}

int
addWrite_RTU3_TIMEOUTS(u_int32_t value)
{
	return addWrite(ID_RTU3_TIMEOUTS, &value);
}

int
getStatus_RTU3_TIMEOUTS(void)
{
	return getStatus(ID_RTU3_TIMEOUTS);
}

int
doWrite_RTU3_COMM_ERRORS(u_int32_t value)
{
	return doWrite(ID_RTU3_COMM_ERRORS, &value);
}

int
addWrite_RTU3_COMM_ERRORS(u_int32_t value)
{
	return addWrite(ID_RTU3_COMM_ERRORS, &value);
}

int
getStatus_RTU3_COMM_ERRORS(void)
{
	return getStatus(ID_RTU3_COMM_ERRORS);
}

int
doWrite_RTU3_LAST_ERROR(u_int32_t value)
{
	return doWrite(ID_RTU3_LAST_ERROR, &value);
}

int
addWrite_RTU3_LAST_ERROR(u_int32_t value)
{
	return addWrite(ID_RTU3_LAST_ERROR, &value);
}

int
getStatus_RTU3_LAST_ERROR(void)
{
	return getStatus(ID_RTU3_LAST_ERROR);
}

int
doWrite_RTU3_WRITE_QUEUE(u_int32_t value)
{
	return doWrite(ID_RTU3_WRITE_QUEUE, &value);
}

int
addWrite_RTU3_WRITE_QUEUE(u_int32_t value)
{
	return addWrite(ID_RTU3_WRITE_QUEUE, &value);
}

int
getStatus_RTU3_WRITE_QUEUE(void)
{
	return getStatus(ID_RTU3_WRITE_QUEUE);
}

int
doWrite_RTU3_BUS_LOAD(u_int32_t value)
{
	return doWrite(ID_RTU3_BUS_LOAD, &value);
}

int
addWrite_RTU3_BUS_LOAD(u_int32_t value)
{
	return addWrite(ID_RTU3_BUS_LOAD, &value);
}

int
getStatus_RTU3_BUS_LOAD(void)
{
	return getStatus(ID_RTU3_BUS_LOAD);
}

int
doWrite_NODE_01_DEV_NODE(u_int32_t value)
{
	return doWrite(ID_NODE_01_DEV_NODE, &value);
}

int
addWrite_NODE_01_DEV_NODE(u_int32_t value)
{
	return addWrite(ID_NODE_01_DEV_NODE, &value);
}

int
getStatus_NODE_01_DEV_NODE(void)
{
	return getStatus(ID_NODE_01_DEV_NODE);
}

int
doWrite_NODE_01_STATUS(u_int32_t value)
{
	return doWrite(ID_NODE_01_STATUS, &value);
}

int
addWrite_NODE_01_STATUS(u_int32_t value)
{
	return addWrite(ID_NODE_01_STATUS, &value);
}

int
getStatus_NODE_01_STATUS(void)
{
	return getStatus(ID_NODE_01_STATUS);
}

int
doWrite_PLC_FWrevision(u_int16_t value)
{
	return doWrite(ID_PLC_FWrevision, &value);
}

int
addWrite_PLC_FWrevision(u_int16_t value)
{
	return addWrite(ID_PLC_FWrevision, &value);
}

int
getStatus_PLC_FWrevision(void)
{
	return getStatus(ID_PLC_FWrevision);
}

int
doWrite_PLC_HWconfig(u_int16_t value)
{
	return doWrite(ID_PLC_HWconfig, &value);
}

int
addWrite_PLC_HWconfig(u_int16_t value)
{
	return addWrite(ID_PLC_HWconfig, &value);
}

int
getStatus_PLC_HWconfig(void)
{
	return getStatus(ID_PLC_HWconfig);
}

int
doWrite_PLC_DigDir_1(int value)
{
	return doWrite(ID_PLC_DigDir_1, &value);
}

int
addWrite_PLC_DigDir_1(int value)
{
	return addWrite(ID_PLC_DigDir_1, &value);
}

int
getStatus_PLC_DigDir_1(void)
{
	return getStatus(ID_PLC_DigDir_1);
}

int
doWrite_PLC_DigDir_2(int value)
{
	return doWrite(ID_PLC_DigDir_2, &value);
}

int
addWrite_PLC_DigDir_2(int value)
{
	return addWrite(ID_PLC_DigDir_2, &value);
}

int
getStatus_PLC_DigDir_2(void)
{
	return getStatus(ID_PLC_DigDir_2);
}

int
doWrite_PLC_DigDir_3(int value)
{
	return doWrite(ID_PLC_DigDir_3, &value);
}

int
addWrite_PLC_DigDir_3(int value)
{
	return addWrite(ID_PLC_DigDir_3, &value);
}

int
getStatus_PLC_DigDir_3(void)
{
	return getStatus(ID_PLC_DigDir_3);
}

int
doWrite_PLC_DigDir_4(int value)
{
	return doWrite(ID_PLC_DigDir_4, &value);
}

int
addWrite_PLC_DigDir_4(int value)
{
	return addWrite(ID_PLC_DigDir_4, &value);
}

int
getStatus_PLC_DigDir_4(void)
{
	return getStatus(ID_PLC_DigDir_4);
}

int
doWrite_PLC_DigDir_5(int value)
{
	return doWrite(ID_PLC_DigDir_5, &value);
}

int
addWrite_PLC_DigDir_5(int value)
{
	return addWrite(ID_PLC_DigDir_5, &value);
}

int
getStatus_PLC_DigDir_5(void)
{
	return getStatus(ID_PLC_DigDir_5);
}

int
doWrite_PLC_DigDir_6(int value)
{
	return doWrite(ID_PLC_DigDir_6, &value);
}

int
addWrite_PLC_DigDir_6(int value)
{
	return addWrite(ID_PLC_DigDir_6, &value);
}

int
getStatus_PLC_DigDir_6(void)
{
	return getStatus(ID_PLC_DigDir_6);
}

int
doWrite_PLC_DigDir_7(int value)
{
	return doWrite(ID_PLC_DigDir_7, &value);
}

int
addWrite_PLC_DigDir_7(int value)
{
	return addWrite(ID_PLC_DigDir_7, &value);
}

int
getStatus_PLC_DigDir_7(void)
{
	return getStatus(ID_PLC_DigDir_7);
}

int
doWrite_PLC_DigDir_8(int value)
{
	return doWrite(ID_PLC_DigDir_8, &value);
}

int
addWrite_PLC_DigDir_8(int value)
{
	return addWrite(ID_PLC_DigDir_8, &value);
}

int
getStatus_PLC_DigDir_8(void)
{
	return getStatus(ID_PLC_DigDir_8);
}

int
doWrite_PLC_DigOut_1(int value)
{
	return doWrite(ID_PLC_DigOut_1, &value);
}

int
addWrite_PLC_DigOut_1(int value)
{
	return addWrite(ID_PLC_DigOut_1, &value);
}

int
getStatus_PLC_DigOut_1(void)
{
	return getStatus(ID_PLC_DigOut_1);
}

int
doWrite_PLC_DigOut_2(int value)
{
	return doWrite(ID_PLC_DigOut_2, &value);
}

int
addWrite_PLC_DigOut_2(int value)
{
	return addWrite(ID_PLC_DigOut_2, &value);
}

int
getStatus_PLC_DigOut_2(void)
{
	return getStatus(ID_PLC_DigOut_2);
}

int
doWrite_PLC_DigOut_3(int value)
{
	return doWrite(ID_PLC_DigOut_3, &value);
}

int
addWrite_PLC_DigOut_3(int value)
{
	return addWrite(ID_PLC_DigOut_3, &value);
}

int
getStatus_PLC_DigOut_3(void)
{
	return getStatus(ID_PLC_DigOut_3);
}

int
doWrite_PLC_DigOut_4(int value)
{
	return doWrite(ID_PLC_DigOut_4, &value);
}

int
addWrite_PLC_DigOut_4(int value)
{
	return addWrite(ID_PLC_DigOut_4, &value);
}

int
getStatus_PLC_DigOut_4(void)
{
	return getStatus(ID_PLC_DigOut_4);
}

int
doWrite_PLC_DigOut_5(int value)
{
	return doWrite(ID_PLC_DigOut_5, &value);
}

int
addWrite_PLC_DigOut_5(int value)
{
	return addWrite(ID_PLC_DigOut_5, &value);
}

int
getStatus_PLC_DigOut_5(void)
{
	return getStatus(ID_PLC_DigOut_5);
}

int
doWrite_PLC_DigOut_6(int value)
{
	return doWrite(ID_PLC_DigOut_6, &value);
}

int
addWrite_PLC_DigOut_6(int value)
{
	return addWrite(ID_PLC_DigOut_6, &value);
}

int
getStatus_PLC_DigOut_6(void)
{
	return getStatus(ID_PLC_DigOut_6);
}

int
doWrite_PLC_DigOut_7(int value)
{
	return doWrite(ID_PLC_DigOut_7, &value);
}

int
addWrite_PLC_DigOut_7(int value)
{
	return addWrite(ID_PLC_DigOut_7, &value);
}

int
getStatus_PLC_DigOut_7(void)
{
	return getStatus(ID_PLC_DigOut_7);
}

int
doWrite_PLC_DigOut_8(int value)
{
	return doWrite(ID_PLC_DigOut_8, &value);
}

int
addWrite_PLC_DigOut_8(int value)
{
	return addWrite(ID_PLC_DigOut_8, &value);
}

int
getStatus_PLC_DigOut_8(void)
{
	return getStatus(ID_PLC_DigOut_8);
}

int
doWrite_PLC_DigIn_1(int value)
{
	return doWrite(ID_PLC_DigIn_1, &value);
}

int
addWrite_PLC_DigIn_1(int value)
{
	return addWrite(ID_PLC_DigIn_1, &value);
}

int
getStatus_PLC_DigIn_1(void)
{
	return getStatus(ID_PLC_DigIn_1);
}

int
doWrite_PLC_DigIn_2(int value)
{
	return doWrite(ID_PLC_DigIn_2, &value);
}

int
addWrite_PLC_DigIn_2(int value)
{
	return addWrite(ID_PLC_DigIn_2, &value);
}

int
getStatus_PLC_DigIn_2(void)
{
	return getStatus(ID_PLC_DigIn_2);
}

int
doWrite_PLC_DigIn_3(int value)
{
	return doWrite(ID_PLC_DigIn_3, &value);
}

int
addWrite_PLC_DigIn_3(int value)
{
	return addWrite(ID_PLC_DigIn_3, &value);
}

int
getStatus_PLC_DigIn_3(void)
{
	return getStatus(ID_PLC_DigIn_3);
}

int
doWrite_PLC_DigIn_4(int value)
{
	return doWrite(ID_PLC_DigIn_4, &value);
}

int
addWrite_PLC_DigIn_4(int value)
{
	return addWrite(ID_PLC_DigIn_4, &value);
}

int
getStatus_PLC_DigIn_4(void)
{
	return getStatus(ID_PLC_DigIn_4);
}

int
doWrite_PLC_DigIn_5(int value)
{
	return doWrite(ID_PLC_DigIn_5, &value);
}

int
addWrite_PLC_DigIn_5(int value)
{
	return addWrite(ID_PLC_DigIn_5, &value);
}

int
getStatus_PLC_DigIn_5(void)
{
	return getStatus(ID_PLC_DigIn_5);
}

int
doWrite_PLC_DigIn_6(int value)
{
	return doWrite(ID_PLC_DigIn_6, &value);
}

int
addWrite_PLC_DigIn_6(int value)
{
	return addWrite(ID_PLC_DigIn_6, &value);
}

int
getStatus_PLC_DigIn_6(void)
{
	return getStatus(ID_PLC_DigIn_6);
}

int
doWrite_PLC_DigIn_7(int value)
{
	return doWrite(ID_PLC_DigIn_7, &value);
}

int
addWrite_PLC_DigIn_7(int value)
{
	return addWrite(ID_PLC_DigIn_7, &value);
}

int
getStatus_PLC_DigIn_7(void)
{
	return getStatus(ID_PLC_DigIn_7);
}

int
doWrite_PLC_DigIn_8(int value)
{
	return doWrite(ID_PLC_DigIn_8, &value);
}

int
addWrite_PLC_DigIn_8(int value)
{
	return addWrite(ID_PLC_DigIn_8, &value);
}

int
getStatus_PLC_DigIn_8(void)
{
	return getStatus(ID_PLC_DigIn_8);
}

int
doWrite_PLC_Heartbeat(u_int16_t value)
{
	return doWrite(ID_PLC_Heartbeat, &value);
}

int
addWrite_PLC_Heartbeat(u_int16_t value)
{
	return addWrite(ID_PLC_Heartbeat, &value);
}

int
getStatus_PLC_Heartbeat(void)
{
	return getStatus(ID_PLC_Heartbeat);
}

int
doWrite_PLC_time(float value)
{
	return doWrite(ID_PLC_time, &value);
}

int
addWrite_PLC_time(float value)
{
	return addWrite(ID_PLC_time, &value);
}

int
getStatus_PLC_time(void)
{
	return getStatus(ID_PLC_time);
}

int
doWrite_PLC_timeMin(float value)
{
	return doWrite(ID_PLC_timeMin, &value);
}

int
addWrite_PLC_timeMin(float value)
{
	return addWrite(ID_PLC_timeMin, &value);
}

int
getStatus_PLC_timeMin(void)
{
	return getStatus(ID_PLC_timeMin);
}

int
doWrite_PLC_timeMax(float value)
{
	return doWrite(ID_PLC_timeMax, &value);
}

int
addWrite_PLC_timeMax(float value)
{
	return addWrite(ID_PLC_timeMax, &value);
}

int
getStatus_PLC_timeMax(void)
{
	return getStatus(ID_PLC_timeMax);
}

int
doWrite_PLC_timeWin(float value)
{
	return doWrite(ID_PLC_timeWin, &value);
}

int
addWrite_PLC_timeWin(float value)
{
	return addWrite(ID_PLC_timeWin, &value);
}

int
getStatus_PLC_timeWin(void)
{
	return getStatus(ID_PLC_timeWin);
}

int
doWrite_PLC_Version(u_int16_t value)
{
	return doWrite(ID_PLC_Version, &value);
}

int
addWrite_PLC_Version(u_int16_t value)
{
	return addWrite(ID_PLC_Version, &value);
}

int
getStatus_PLC_Version(void)
{
	return getStatus(ID_PLC_Version);
}

int
doWrite_PLC_EngineStatus(u_int16_t value)
{
	return doWrite(ID_PLC_EngineStatus, &value);
}

int
addWrite_PLC_EngineStatus(u_int16_t value)
{
	return addWrite(ID_PLC_EngineStatus, &value);
}

int
getStatus_PLC_EngineStatus(void)
{
	return getStatus(ID_PLC_EngineStatus);
}

int
doWrite_PLC_ResetValues(int value)
{
	return doWrite(ID_PLC_ResetValues, &value);
}

int
addWrite_PLC_ResetValues(int value)
{
	return addWrite(ID_PLC_ResetValues, &value);
}

int
getStatus_PLC_ResetValues(void)
{
	return getStatus(ID_PLC_ResetValues);
}

int
doWrite_PLC_buzzerOn(int value)
{
	return doWrite(ID_PLC_buzzerOn, &value);
}

int
addWrite_PLC_buzzerOn(int value)
{
	return addWrite(ID_PLC_buzzerOn, &value);
}

int
getStatus_PLC_buzzerOn(void)
{
	return getStatus(ID_PLC_buzzerOn);
}

int
doWrite_PLC_PLC_Version(u_int16_t value)
{
	return doWrite(ID_PLC_PLC_Version, &value);
}

int
addWrite_PLC_PLC_Version(u_int16_t value)
{
	return addWrite(ID_PLC_PLC_Version, &value);
}

int
getStatus_PLC_PLC_Version(void)
{
	return getStatus(ID_PLC_PLC_Version);
}

int
doWrite_PLC_HMI_Version(u_int16_t value)
{
	return doWrite(ID_PLC_HMI_Version, &value);
}

int
addWrite_PLC_HMI_Version(u_int16_t value)
{
	return addWrite(ID_PLC_HMI_Version, &value);
}

int
getStatus_PLC_HMI_Version(void)
{
	return getStatus(ID_PLC_HMI_Version);
}

int
doWrite_PLC_Year(u_int16_t value)
{
	return doWrite(ID_PLC_Year, &value);
}

int
addWrite_PLC_Year(u_int16_t value)
{
	return addWrite(ID_PLC_Year, &value);
}

int
getStatus_PLC_Year(void)
{
	return getStatus(ID_PLC_Year);
}

int
doWrite_PLC_Month(u_int16_t value)
{
	return doWrite(ID_PLC_Month, &value);
}

int
addWrite_PLC_Month(u_int16_t value)
{
	return addWrite(ID_PLC_Month, &value);
}

int
getStatus_PLC_Month(void)
{
	return getStatus(ID_PLC_Month);
}

int
doWrite_PLC_Day(u_int16_t value)
{
	return doWrite(ID_PLC_Day, &value);
}

int
addWrite_PLC_Day(u_int16_t value)
{
	return addWrite(ID_PLC_Day, &value);
}

int
getStatus_PLC_Day(void)
{
	return getStatus(ID_PLC_Day);
}

int
doWrite_PLC_Hours(u_int16_t value)
{
	return doWrite(ID_PLC_Hours, &value);
}

int
addWrite_PLC_Hours(u_int16_t value)
{
	return addWrite(ID_PLC_Hours, &value);
}

int
getStatus_PLC_Hours(void)
{
	return getStatus(ID_PLC_Hours);
}

int
doWrite_PLC_Minutes(u_int16_t value)
{
	return doWrite(ID_PLC_Minutes, &value);
}

int
addWrite_PLC_Minutes(u_int16_t value)
{
	return addWrite(ID_PLC_Minutes, &value);
}

int
getStatus_PLC_Minutes(void)
{
	return getStatus(ID_PLC_Minutes);
}

int
doWrite_PLC_Seconds(u_int16_t value)
{
	return doWrite(ID_PLC_Seconds, &value);
}

int
addWrite_PLC_Seconds(u_int16_t value)
{
	return addWrite(ID_PLC_Seconds, &value);
}

int
getStatus_PLC_Seconds(void)
{
	return getStatus(ID_PLC_Seconds);
}

int
doWrite_PLC_UPTIME_s(u_int32_t value)
{
	return doWrite(ID_PLC_UPTIME_s, &value);
}

int
addWrite_PLC_UPTIME_s(u_int32_t value)
{
	return addWrite(ID_PLC_UPTIME_s, &value);
}

int
getStatus_PLC_UPTIME_s(void)
{
	return getStatus(ID_PLC_UPTIME_s);
}

int
doWrite_PLC_UPTIME_cs(u_int32_t value)
{
	return doWrite(ID_PLC_UPTIME_cs, &value);
}

int
addWrite_PLC_UPTIME_cs(u_int32_t value)
{
	return addWrite(ID_PLC_UPTIME_cs, &value);
}

int
getStatus_PLC_UPTIME_cs(void)
{
	return getStatus(ID_PLC_UPTIME_cs);
}

int
doWrite_PLC_WATCHDOGEN(int value)
{
	return doWrite(ID_PLC_WATCHDOGEN, &value);
}

int
addWrite_PLC_WATCHDOGEN(int value)
{
	return addWrite(ID_PLC_WATCHDOGEN, &value);
}

int
getStatus_PLC_WATCHDOGEN(void)
{
	return getStatus(ID_PLC_WATCHDOGEN);
}

int
doWrite_PLC_WATCHDOG_ms(u_int32_t value)
{
	return doWrite(ID_PLC_WATCHDOG_ms, &value);
}

int
addWrite_PLC_WATCHDOG_ms(u_int32_t value)
{
	return addWrite(ID_PLC_WATCHDOG_ms, &value);
}

int
getStatus_PLC_WATCHDOG_ms(void)
{
	return getStatus(ID_PLC_WATCHDOG_ms);
}

int
doWrite_PLC_PRODUCT_ID(u_int32_t value)
{
	return doWrite(ID_PLC_PRODUCT_ID, &value);
}

int
addWrite_PLC_PRODUCT_ID(u_int32_t value)
{
	return addWrite(ID_PLC_PRODUCT_ID, &value);
}

int
getStatus_PLC_PRODUCT_ID(void)
{
	return getStatus(ID_PLC_PRODUCT_ID);
}

int
doWrite_PLC_SERIAL_NUMBER(u_int32_t value)
{
	return doWrite(ID_PLC_SERIAL_NUMBER, &value);
}

int
addWrite_PLC_SERIAL_NUMBER(u_int32_t value)
{
	return addWrite(ID_PLC_SERIAL_NUMBER, &value);
}

int
getStatus_PLC_SERIAL_NUMBER(void)
{
	return getStatus(ID_PLC_SERIAL_NUMBER);
}

int
doWrite_PLC_HMI_PAGE(int32_t value)
{
	return doWrite(ID_PLC_HMI_PAGE, &value);
}

int
addWrite_PLC_HMI_PAGE(int32_t value)
{
	return addWrite(ID_PLC_HMI_PAGE, &value);
}

int
getStatus_PLC_HMI_PAGE(void)
{
	return getStatus(ID_PLC_HMI_PAGE);
}

int
doWrite_PLC_BEEP_VOLUME(u_int8_t value)
{
	return doWrite(ID_PLC_BEEP_VOLUME, &value);
}

int
addWrite_PLC_BEEP_VOLUME(u_int8_t value)
{
	return addWrite(ID_PLC_BEEP_VOLUME, &value);
}

int
getStatus_PLC_BEEP_VOLUME(void)
{
	return getStatus(ID_PLC_BEEP_VOLUME);
}

int
doWrite_PLC_TOUCH_VOLUME(u_int8_t value)
{
	return doWrite(ID_PLC_TOUCH_VOLUME, &value);
}

int
addWrite_PLC_TOUCH_VOLUME(u_int8_t value)
{
	return addWrite(ID_PLC_TOUCH_VOLUME, &value);
}

int
getStatus_PLC_TOUCH_VOLUME(void)
{
	return getStatus(ID_PLC_TOUCH_VOLUME);
}

int
doWrite_PLC_ALARM_VOLUME(u_int8_t value)
{
	return doWrite(ID_PLC_ALARM_VOLUME, &value);
}

int
addWrite_PLC_ALARM_VOLUME(u_int8_t value)
{
	return addWrite(ID_PLC_ALARM_VOLUME, &value);
}

int
getStatus_PLC_ALARM_VOLUME(void)
{
	return getStatus(ID_PLC_ALARM_VOLUME);
}

int
doWrite_PLC_BUZZER(u_int32_t value)
{
	return doWrite(ID_PLC_BUZZER, &value);
}

int
addWrite_PLC_BUZZER(u_int32_t value)
{
	return addWrite(ID_PLC_BUZZER, &value);
}

int
getStatus_PLC_BUZZER(void)
{
	return getStatus(ID_PLC_BUZZER);
}


int
update_all(void)
{
	int retval = 0;

	retval += readFromDb(ID_RTU3_TYPE_PORT, &RTU3_TYPE_PORT);
	retval += readFromDb(ID_RTU3_BAUDRATE, &RTU3_BAUDRATE);
	retval += readFromDb(ID_RTU3_STATUS, &RTU3_STATUS);
	retval += readFromDb(ID_RTU3_READS, &RTU3_READS);
	retval += readFromDb(ID_RTU3_WRITES, &RTU3_WRITES);
	retval += readFromDb(ID_RTU3_TIMEOUTS, &RTU3_TIMEOUTS);
	retval += readFromDb(ID_RTU3_COMM_ERRORS, &RTU3_COMM_ERRORS);
	retval += readFromDb(ID_RTU3_LAST_ERROR, &RTU3_LAST_ERROR);
	retval += readFromDb(ID_RTU3_WRITE_QUEUE, &RTU3_WRITE_QUEUE);
	retval += readFromDb(ID_RTU3_BUS_LOAD, &RTU3_BUS_LOAD);
	retval += readFromDb(ID_NODE_01_DEV_NODE, &NODE_01_DEV_NODE);
	retval += readFromDb(ID_NODE_01_STATUS, &NODE_01_STATUS);
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
	retval += readFromDb(ID_PLC_DigOut_1, &PLC_DigOut_1);
	retval += readFromDb(ID_PLC_DigOut_2, &PLC_DigOut_2);
	retval += readFromDb(ID_PLC_DigOut_3, &PLC_DigOut_3);
	retval += readFromDb(ID_PLC_DigOut_4, &PLC_DigOut_4);
	retval += readFromDb(ID_PLC_DigOut_5, &PLC_DigOut_5);
	retval += readFromDb(ID_PLC_DigOut_6, &PLC_DigOut_6);
	retval += readFromDb(ID_PLC_DigOut_7, &PLC_DigOut_7);
	retval += readFromDb(ID_PLC_DigOut_8, &PLC_DigOut_8);
	retval += readFromDb(ID_PLC_DigIn_1, &PLC_DigIn_1);
	retval += readFromDb(ID_PLC_DigIn_2, &PLC_DigIn_2);
	retval += readFromDb(ID_PLC_DigIn_3, &PLC_DigIn_3);
	retval += readFromDb(ID_PLC_DigIn_4, &PLC_DigIn_4);
	retval += readFromDb(ID_PLC_DigIn_5, &PLC_DigIn_5);
	retval += readFromDb(ID_PLC_DigIn_6, &PLC_DigIn_6);
	retval += readFromDb(ID_PLC_DigIn_7, &PLC_DigIn_7);
	retval += readFromDb(ID_PLC_DigIn_8, &PLC_DigIn_8);
	retval += readFromDb(ID_PLC_Heartbeat, &PLC_Heartbeat);
	retval += readFromDb(ID_PLC_time, &PLC_time);
	retval += readFromDb(ID_PLC_timeMin, &PLC_timeMin);
	retval += readFromDb(ID_PLC_timeMax, &PLC_timeMax);
	retval += readFromDb(ID_PLC_timeWin, &PLC_timeWin);
	retval += readFromDb(ID_PLC_Version, &PLC_Version);
	retval += readFromDb(ID_PLC_EngineStatus, &PLC_EngineStatus);
	retval += readFromDb(ID_PLC_ResetValues, &PLC_ResetValues);
	retval += readFromDb(ID_PLC_buzzerOn, &PLC_buzzerOn);
	retval += readFromDb(ID_PLC_PLC_Version, &PLC_PLC_Version);
	retval += readFromDb(ID_PLC_HMI_Version, &PLC_HMI_Version);
	retval += readFromDb(ID_PLC_Year, &PLC_Year);
	retval += readFromDb(ID_PLC_Month, &PLC_Month);
	retval += readFromDb(ID_PLC_Day, &PLC_Day);
	retval += readFromDb(ID_PLC_Hours, &PLC_Hours);
	retval += readFromDb(ID_PLC_Minutes, &PLC_Minutes);
	retval += readFromDb(ID_PLC_Seconds, &PLC_Seconds);
	retval += readFromDb(ID_PLC_UPTIME_s, &PLC_UPTIME_s);
	retval += readFromDb(ID_PLC_UPTIME_cs, &PLC_UPTIME_cs);
	retval += readFromDb(ID_PLC_WATCHDOGEN, &PLC_WATCHDOGEN);
	retval += readFromDb(ID_PLC_WATCHDOG_ms, &PLC_WATCHDOG_ms);
	retval += readFromDb(ID_PLC_PRODUCT_ID, &PLC_PRODUCT_ID);
	retval += readFromDb(ID_PLC_SERIAL_NUMBER, &PLC_SERIAL_NUMBER);
	retval += readFromDb(ID_PLC_HMI_PAGE, &PLC_HMI_PAGE);
	retval += readFromDb(ID_PLC_BEEP_VOLUME, &PLC_BEEP_VOLUME);
	retval += readFromDb(ID_PLC_TOUCH_VOLUME, &PLC_TOUCH_VOLUME);
	retval += readFromDb(ID_PLC_ALARM_VOLUME, &PLC_ALARM_VOLUME);
	retval += readFromDb(ID_PLC_BUZZER, &PLC_BUZZER);

	return retval;
}
