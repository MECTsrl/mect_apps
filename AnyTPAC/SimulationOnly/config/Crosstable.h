/* File automatically generated by the cross table compiler */
/* from the cross table file Crosstable.csv. */

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

#ifndef CROSSTABLE_H__
#define CROSSTABLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include "cross_table_utility.h"


#define ID_AAA 1345
extern int32_t AAA;
int doWrite_AAA(int32_t value);
int addWrite_AAA(int32_t value);
int getStatus_AAA(void);

#define ID_BBB 1346
extern int32_t BBB;
int doWrite_BBB(int32_t value);
int addWrite_BBB(int32_t value);
int getStatus_BBB(void);

#define ID_CCC 1347
extern float CCC;
int doWrite_CCC(float value);
int addWrite_CCC(float value);
int getStatus_CCC(void);

#define ID_DDD 1348
extern float DDD;
int doWrite_DDD(float value);
int addWrite_DDD(float value);
int getStatus_DDD(void);

#define ID_RTU0_TYPE_PORT 5004
extern u_int32_t RTU0_TYPE_PORT;
int doWrite_RTU0_TYPE_PORT(u_int32_t value);
int addWrite_RTU0_TYPE_PORT(u_int32_t value);
int getStatus_RTU0_TYPE_PORT(void);

#define ID_RTU0_BAUDRATE 5005
extern u_int32_t RTU0_BAUDRATE;
int doWrite_RTU0_BAUDRATE(u_int32_t value);
int addWrite_RTU0_BAUDRATE(u_int32_t value);
int getStatus_RTU0_BAUDRATE(void);

#define ID_RTU0_STATUS 5006
extern u_int32_t RTU0_STATUS;
int doWrite_RTU0_STATUS(u_int32_t value);
int addWrite_RTU0_STATUS(u_int32_t value);
int getStatus_RTU0_STATUS(void);

#define ID_RTU0_READS 5007
extern u_int32_t RTU0_READS;
int doWrite_RTU0_READS(u_int32_t value);
int addWrite_RTU0_READS(u_int32_t value);
int getStatus_RTU0_READS(void);

#define ID_RTU0_WRITES 5008
extern u_int32_t RTU0_WRITES;
int doWrite_RTU0_WRITES(u_int32_t value);
int addWrite_RTU0_WRITES(u_int32_t value);
int getStatus_RTU0_WRITES(void);

#define ID_RTU0_TIMEOUTS 5009
extern u_int32_t RTU0_TIMEOUTS;
int doWrite_RTU0_TIMEOUTS(u_int32_t value);
int addWrite_RTU0_TIMEOUTS(u_int32_t value);
int getStatus_RTU0_TIMEOUTS(void);

#define ID_RTU0_COMM_ERRORS 5010
extern u_int32_t RTU0_COMM_ERRORS;
int doWrite_RTU0_COMM_ERRORS(u_int32_t value);
int addWrite_RTU0_COMM_ERRORS(u_int32_t value);
int getStatus_RTU0_COMM_ERRORS(void);

#define ID_RTU0_LAST_ERROR 5011
extern u_int32_t RTU0_LAST_ERROR;
int doWrite_RTU0_LAST_ERROR(u_int32_t value);
int addWrite_RTU0_LAST_ERROR(u_int32_t value);
int getStatus_RTU0_LAST_ERROR(void);

#define ID_RTU0_WRITE_QUEUE 5012
extern u_int32_t RTU0_WRITE_QUEUE;
int doWrite_RTU0_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU0_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU0_WRITE_QUEUE(void);

#define ID_RTU0_BUS_LOAD 5013
extern u_int32_t RTU0_BUS_LOAD;
int doWrite_RTU0_BUS_LOAD(u_int32_t value);
int addWrite_RTU0_BUS_LOAD(u_int32_t value);
int getStatus_RTU0_BUS_LOAD(void);

#define ID_RTU3_TYPE_PORT 5024
extern u_int32_t RTU3_TYPE_PORT;
int doWrite_RTU3_TYPE_PORT(u_int32_t value);
int addWrite_RTU3_TYPE_PORT(u_int32_t value);
int getStatus_RTU3_TYPE_PORT(void);

#define ID_RTU3_BAUDRATE 5025
extern u_int32_t RTU3_BAUDRATE;
int doWrite_RTU3_BAUDRATE(u_int32_t value);
int addWrite_RTU3_BAUDRATE(u_int32_t value);
int getStatus_RTU3_BAUDRATE(void);

#define ID_RTU3_STATUS 5026
extern u_int32_t RTU3_STATUS;
int doWrite_RTU3_STATUS(u_int32_t value);
int addWrite_RTU3_STATUS(u_int32_t value);
int getStatus_RTU3_STATUS(void);

#define ID_RTU3_READS 5027
extern u_int32_t RTU3_READS;
int doWrite_RTU3_READS(u_int32_t value);
int addWrite_RTU3_READS(u_int32_t value);
int getStatus_RTU3_READS(void);

#define ID_RTU3_WRITES 5028
extern u_int32_t RTU3_WRITES;
int doWrite_RTU3_WRITES(u_int32_t value);
int addWrite_RTU3_WRITES(u_int32_t value);
int getStatus_RTU3_WRITES(void);

#define ID_RTU3_TIMEOUTS 5029
extern u_int32_t RTU3_TIMEOUTS;
int doWrite_RTU3_TIMEOUTS(u_int32_t value);
int addWrite_RTU3_TIMEOUTS(u_int32_t value);
int getStatus_RTU3_TIMEOUTS(void);

#define ID_RTU3_COMM_ERRORS 5030
extern u_int32_t RTU3_COMM_ERRORS;
int doWrite_RTU3_COMM_ERRORS(u_int32_t value);
int addWrite_RTU3_COMM_ERRORS(u_int32_t value);
int getStatus_RTU3_COMM_ERRORS(void);

#define ID_RTU3_LAST_ERROR 5031
extern u_int32_t RTU3_LAST_ERROR;
int doWrite_RTU3_LAST_ERROR(u_int32_t value);
int addWrite_RTU3_LAST_ERROR(u_int32_t value);
int getStatus_RTU3_LAST_ERROR(void);

#define ID_RTU3_WRITE_QUEUE 5032
extern u_int32_t RTU3_WRITE_QUEUE;
int doWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU3_WRITE_QUEUE(void);

#define ID_RTU3_BUS_LOAD 5033
extern u_int32_t RTU3_BUS_LOAD;
int doWrite_RTU3_BUS_LOAD(u_int32_t value);
int addWrite_RTU3_BUS_LOAD(u_int32_t value);
int getStatus_RTU3_BUS_LOAD(void);

#define ID_TCPS_TYPE_PORT 5054
extern u_int32_t TCPS_TYPE_PORT;
int doWrite_TCPS_TYPE_PORT(u_int32_t value);
int addWrite_TCPS_TYPE_PORT(u_int32_t value);
int getStatus_TCPS_TYPE_PORT(void);

#define ID_TCPS_IP_ADDRESS 5055
extern u_int32_t TCPS_IP_ADDRESS;
int doWrite_TCPS_IP_ADDRESS(u_int32_t value);
int addWrite_TCPS_IP_ADDRESS(u_int32_t value);
int getStatus_TCPS_IP_ADDRESS(void);

#define ID_TCPS_STATUS 5056
extern u_int32_t TCPS_STATUS;
int doWrite_TCPS_STATUS(u_int32_t value);
int addWrite_TCPS_STATUS(u_int32_t value);
int getStatus_TCPS_STATUS(void);

#define ID_TCPS_READS 5057
extern u_int32_t TCPS_READS;
int doWrite_TCPS_READS(u_int32_t value);
int addWrite_TCPS_READS(u_int32_t value);
int getStatus_TCPS_READS(void);

#define ID_TCPS_WRITES 5058
extern u_int32_t TCPS_WRITES;
int doWrite_TCPS_WRITES(u_int32_t value);
int addWrite_TCPS_WRITES(u_int32_t value);
int getStatus_TCPS_WRITES(void);

#define ID_TCPS_TIMEOUTS 5059
extern u_int32_t TCPS_TIMEOUTS;
int doWrite_TCPS_TIMEOUTS(u_int32_t value);
int addWrite_TCPS_TIMEOUTS(u_int32_t value);
int getStatus_TCPS_TIMEOUTS(void);

#define ID_TCPS_COMM_ERRORS 5060
extern u_int32_t TCPS_COMM_ERRORS;
int doWrite_TCPS_COMM_ERRORS(u_int32_t value);
int addWrite_TCPS_COMM_ERRORS(u_int32_t value);
int getStatus_TCPS_COMM_ERRORS(void);

#define ID_TCPS_LAST_ERROR 5061
extern u_int32_t TCPS_LAST_ERROR;
int doWrite_TCPS_LAST_ERROR(u_int32_t value);
int addWrite_TCPS_LAST_ERROR(u_int32_t value);
int getStatus_TCPS_LAST_ERROR(void);

#define ID_TCPS_WRITE_QUEUE 5062
extern u_int32_t TCPS_WRITE_QUEUE;
int doWrite_TCPS_WRITE_QUEUE(u_int32_t value);
int addWrite_TCPS_WRITE_QUEUE(u_int32_t value);
int getStatus_TCPS_WRITE_QUEUE(void);

#define ID_TCPS_BUS_LOAD 5063
extern u_int32_t TCPS_BUS_LOAD;
int doWrite_TCPS_BUS_LOAD(u_int32_t value);
int addWrite_TCPS_BUS_LOAD(u_int32_t value);
int getStatus_TCPS_BUS_LOAD(void);

#define ID_TCP0_TYPE_PORT 5064
extern u_int32_t TCP0_TYPE_PORT;
int doWrite_TCP0_TYPE_PORT(u_int32_t value);
int addWrite_TCP0_TYPE_PORT(u_int32_t value);
int getStatus_TCP0_TYPE_PORT(void);

#define ID_TCP0_IP_ADDRESS 5065
extern u_int32_t TCP0_IP_ADDRESS;
int doWrite_TCP0_IP_ADDRESS(u_int32_t value);
int addWrite_TCP0_IP_ADDRESS(u_int32_t value);
int getStatus_TCP0_IP_ADDRESS(void);

#define ID_TCP0_STATUS 5066
extern u_int32_t TCP0_STATUS;
int doWrite_TCP0_STATUS(u_int32_t value);
int addWrite_TCP0_STATUS(u_int32_t value);
int getStatus_TCP0_STATUS(void);

#define ID_TCP0_READS 5067
extern u_int32_t TCP0_READS;
int doWrite_TCP0_READS(u_int32_t value);
int addWrite_TCP0_READS(u_int32_t value);
int getStatus_TCP0_READS(void);

#define ID_TCP0_WRITES 5068
extern u_int32_t TCP0_WRITES;
int doWrite_TCP0_WRITES(u_int32_t value);
int addWrite_TCP0_WRITES(u_int32_t value);
int getStatus_TCP0_WRITES(void);

#define ID_TCP0_TIMEOUTS 5069
extern u_int32_t TCP0_TIMEOUTS;
int doWrite_TCP0_TIMEOUTS(u_int32_t value);
int addWrite_TCP0_TIMEOUTS(u_int32_t value);
int getStatus_TCP0_TIMEOUTS(void);

#define ID_TCP0_COMM_ERRORS 5070
extern u_int32_t TCP0_COMM_ERRORS;
int doWrite_TCP0_COMM_ERRORS(u_int32_t value);
int addWrite_TCP0_COMM_ERRORS(u_int32_t value);
int getStatus_TCP0_COMM_ERRORS(void);

#define ID_TCP0_LAST_ERROR 5071
extern u_int32_t TCP0_LAST_ERROR;
int doWrite_TCP0_LAST_ERROR(u_int32_t value);
int addWrite_TCP0_LAST_ERROR(u_int32_t value);
int getStatus_TCP0_LAST_ERROR(void);

#define ID_TCP0_WRITE_QUEUE 5072
extern u_int32_t TCP0_WRITE_QUEUE;
int doWrite_TCP0_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP0_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP0_WRITE_QUEUE(void);

#define ID_TCP0_BUS_LOAD 5073
extern u_int32_t TCP0_BUS_LOAD;
int doWrite_TCP0_BUS_LOAD(u_int32_t value);
int addWrite_TCP0_BUS_LOAD(u_int32_t value);
int getStatus_TCP0_BUS_LOAD(void);

#define ID_TCP1_TYPE_PORT 5074
extern u_int32_t TCP1_TYPE_PORT;
int doWrite_TCP1_TYPE_PORT(u_int32_t value);
int addWrite_TCP1_TYPE_PORT(u_int32_t value);
int getStatus_TCP1_TYPE_PORT(void);

#define ID_TCP1_IP_ADDRESS 5075
extern u_int32_t TCP1_IP_ADDRESS;
int doWrite_TCP1_IP_ADDRESS(u_int32_t value);
int addWrite_TCP1_IP_ADDRESS(u_int32_t value);
int getStatus_TCP1_IP_ADDRESS(void);

#define ID_TCP1_STATUS 5076
extern u_int32_t TCP1_STATUS;
int doWrite_TCP1_STATUS(u_int32_t value);
int addWrite_TCP1_STATUS(u_int32_t value);
int getStatus_TCP1_STATUS(void);

#define ID_TCP1_READS 5077
extern u_int32_t TCP1_READS;
int doWrite_TCP1_READS(u_int32_t value);
int addWrite_TCP1_READS(u_int32_t value);
int getStatus_TCP1_READS(void);

#define ID_TCP1_WRITES 5078
extern u_int32_t TCP1_WRITES;
int doWrite_TCP1_WRITES(u_int32_t value);
int addWrite_TCP1_WRITES(u_int32_t value);
int getStatus_TCP1_WRITES(void);

#define ID_TCP1_TIMEOUTS 5079
extern u_int32_t TCP1_TIMEOUTS;
int doWrite_TCP1_TIMEOUTS(u_int32_t value);
int addWrite_TCP1_TIMEOUTS(u_int32_t value);
int getStatus_TCP1_TIMEOUTS(void);

#define ID_TCP1_COMM_ERRORS 5080
extern u_int32_t TCP1_COMM_ERRORS;
int doWrite_TCP1_COMM_ERRORS(u_int32_t value);
int addWrite_TCP1_COMM_ERRORS(u_int32_t value);
int getStatus_TCP1_COMM_ERRORS(void);

#define ID_TCP1_LAST_ERROR 5081
extern u_int32_t TCP1_LAST_ERROR;
int doWrite_TCP1_LAST_ERROR(u_int32_t value);
int addWrite_TCP1_LAST_ERROR(u_int32_t value);
int getStatus_TCP1_LAST_ERROR(void);

#define ID_TCP1_WRITE_QUEUE 5082
extern u_int32_t TCP1_WRITE_QUEUE;
int doWrite_TCP1_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP1_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP1_WRITE_QUEUE(void);

#define ID_TCP1_BUS_LOAD 5083
extern u_int32_t TCP1_BUS_LOAD;
int doWrite_TCP1_BUS_LOAD(u_int32_t value);
int addWrite_TCP1_BUS_LOAD(u_int32_t value);
int getStatus_TCP1_BUS_LOAD(void);

#define ID_TCP2_TYPE_PORT 5084
extern u_int32_t TCP2_TYPE_PORT;
int doWrite_TCP2_TYPE_PORT(u_int32_t value);
int addWrite_TCP2_TYPE_PORT(u_int32_t value);
int getStatus_TCP2_TYPE_PORT(void);

#define ID_TCP2_IP_ADDRESS 5085
extern u_int32_t TCP2_IP_ADDRESS;
int doWrite_TCP2_IP_ADDRESS(u_int32_t value);
int addWrite_TCP2_IP_ADDRESS(u_int32_t value);
int getStatus_TCP2_IP_ADDRESS(void);

#define ID_TCP2_STATUS 5086
extern u_int32_t TCP2_STATUS;
int doWrite_TCP2_STATUS(u_int32_t value);
int addWrite_TCP2_STATUS(u_int32_t value);
int getStatus_TCP2_STATUS(void);

#define ID_TCP2_READS 5087
extern u_int32_t TCP2_READS;
int doWrite_TCP2_READS(u_int32_t value);
int addWrite_TCP2_READS(u_int32_t value);
int getStatus_TCP2_READS(void);

#define ID_TCP2_WRITES 5088
extern u_int32_t TCP2_WRITES;
int doWrite_TCP2_WRITES(u_int32_t value);
int addWrite_TCP2_WRITES(u_int32_t value);
int getStatus_TCP2_WRITES(void);

#define ID_TCP2_TIMEOUTS 5089
extern u_int32_t TCP2_TIMEOUTS;
int doWrite_TCP2_TIMEOUTS(u_int32_t value);
int addWrite_TCP2_TIMEOUTS(u_int32_t value);
int getStatus_TCP2_TIMEOUTS(void);

#define ID_TCP2_COMM_ERRORS 5090
extern u_int32_t TCP2_COMM_ERRORS;
int doWrite_TCP2_COMM_ERRORS(u_int32_t value);
int addWrite_TCP2_COMM_ERRORS(u_int32_t value);
int getStatus_TCP2_COMM_ERRORS(void);

#define ID_TCP2_LAST_ERROR 5091
extern u_int32_t TCP2_LAST_ERROR;
int doWrite_TCP2_LAST_ERROR(u_int32_t value);
int addWrite_TCP2_LAST_ERROR(u_int32_t value);
int getStatus_TCP2_LAST_ERROR(void);

#define ID_TCP2_WRITE_QUEUE 5092
extern u_int32_t TCP2_WRITE_QUEUE;
int doWrite_TCP2_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP2_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP2_WRITE_QUEUE(void);

#define ID_TCP2_BUS_LOAD 5093
extern u_int32_t TCP2_BUS_LOAD;
int doWrite_TCP2_BUS_LOAD(u_int32_t value);
int addWrite_TCP2_BUS_LOAD(u_int32_t value);
int getStatus_TCP2_BUS_LOAD(void);

#define ID_TCP3_TYPE_PORT 5094
extern u_int32_t TCP3_TYPE_PORT;
int doWrite_TCP3_TYPE_PORT(u_int32_t value);
int addWrite_TCP3_TYPE_PORT(u_int32_t value);
int getStatus_TCP3_TYPE_PORT(void);

#define ID_TCP3_IP_ADDRESS 5095
extern u_int32_t TCP3_IP_ADDRESS;
int doWrite_TCP3_IP_ADDRESS(u_int32_t value);
int addWrite_TCP3_IP_ADDRESS(u_int32_t value);
int getStatus_TCP3_IP_ADDRESS(void);

#define ID_TCP3_STATUS 5096
extern u_int32_t TCP3_STATUS;
int doWrite_TCP3_STATUS(u_int32_t value);
int addWrite_TCP3_STATUS(u_int32_t value);
int getStatus_TCP3_STATUS(void);

#define ID_TCP3_READS 5097
extern u_int32_t TCP3_READS;
int doWrite_TCP3_READS(u_int32_t value);
int addWrite_TCP3_READS(u_int32_t value);
int getStatus_TCP3_READS(void);

#define ID_TCP3_WRITES 5098
extern u_int32_t TCP3_WRITES;
int doWrite_TCP3_WRITES(u_int32_t value);
int addWrite_TCP3_WRITES(u_int32_t value);
int getStatus_TCP3_WRITES(void);

#define ID_TCP3_TIMEOUTS 5099
extern u_int32_t TCP3_TIMEOUTS;
int doWrite_TCP3_TIMEOUTS(u_int32_t value);
int addWrite_TCP3_TIMEOUTS(u_int32_t value);
int getStatus_TCP3_TIMEOUTS(void);

#define ID_TCP3_COMM_ERRORS 5100
extern u_int32_t TCP3_COMM_ERRORS;
int doWrite_TCP3_COMM_ERRORS(u_int32_t value);
int addWrite_TCP3_COMM_ERRORS(u_int32_t value);
int getStatus_TCP3_COMM_ERRORS(void);

#define ID_TCP3_LAST_ERROR 5101
extern u_int32_t TCP3_LAST_ERROR;
int doWrite_TCP3_LAST_ERROR(u_int32_t value);
int addWrite_TCP3_LAST_ERROR(u_int32_t value);
int getStatus_TCP3_LAST_ERROR(void);

#define ID_TCP3_WRITE_QUEUE 5102
extern u_int32_t TCP3_WRITE_QUEUE;
int doWrite_TCP3_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP3_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP3_WRITE_QUEUE(void);

#define ID_TCP3_BUS_LOAD 5103
extern u_int32_t TCP3_BUS_LOAD;
int doWrite_TCP3_BUS_LOAD(u_int32_t value);
int addWrite_TCP3_BUS_LOAD(u_int32_t value);
int getStatus_TCP3_BUS_LOAD(void);

#define ID_TCP4_TYPE_PORT 5104
extern u_int32_t TCP4_TYPE_PORT;
int doWrite_TCP4_TYPE_PORT(u_int32_t value);
int addWrite_TCP4_TYPE_PORT(u_int32_t value);
int getStatus_TCP4_TYPE_PORT(void);

#define ID_TCP4_IP_ADDRESS 5105
extern u_int32_t TCP4_IP_ADDRESS;
int doWrite_TCP4_IP_ADDRESS(u_int32_t value);
int addWrite_TCP4_IP_ADDRESS(u_int32_t value);
int getStatus_TCP4_IP_ADDRESS(void);

#define ID_TCP4_STATUS 5106
extern u_int32_t TCP4_STATUS;
int doWrite_TCP4_STATUS(u_int32_t value);
int addWrite_TCP4_STATUS(u_int32_t value);
int getStatus_TCP4_STATUS(void);

#define ID_TCP4_READS 5107
extern u_int32_t TCP4_READS;
int doWrite_TCP4_READS(u_int32_t value);
int addWrite_TCP4_READS(u_int32_t value);
int getStatus_TCP4_READS(void);

#define ID_TCP4_WRITES 5108
extern u_int32_t TCP4_WRITES;
int doWrite_TCP4_WRITES(u_int32_t value);
int addWrite_TCP4_WRITES(u_int32_t value);
int getStatus_TCP4_WRITES(void);

#define ID_TCP4_TIMEOUTS 5109
extern u_int32_t TCP4_TIMEOUTS;
int doWrite_TCP4_TIMEOUTS(u_int32_t value);
int addWrite_TCP4_TIMEOUTS(u_int32_t value);
int getStatus_TCP4_TIMEOUTS(void);

#define ID_TCP4_COMM_ERRORS 5110
extern u_int32_t TCP4_COMM_ERRORS;
int doWrite_TCP4_COMM_ERRORS(u_int32_t value);
int addWrite_TCP4_COMM_ERRORS(u_int32_t value);
int getStatus_TCP4_COMM_ERRORS(void);

#define ID_TCP4_LAST_ERROR 5111
extern u_int32_t TCP4_LAST_ERROR;
int doWrite_TCP4_LAST_ERROR(u_int32_t value);
int addWrite_TCP4_LAST_ERROR(u_int32_t value);
int getStatus_TCP4_LAST_ERROR(void);

#define ID_TCP4_WRITE_QUEUE 5112
extern u_int32_t TCP4_WRITE_QUEUE;
int doWrite_TCP4_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP4_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP4_WRITE_QUEUE(void);

#define ID_TCP4_BUS_LOAD 5113
extern u_int32_t TCP4_BUS_LOAD;
int doWrite_TCP4_BUS_LOAD(u_int32_t value);
int addWrite_TCP4_BUS_LOAD(u_int32_t value);
int getStatus_TCP4_BUS_LOAD(void);

#define ID_TCP5_TYPE_PORT 5114
extern u_int32_t TCP5_TYPE_PORT;
int doWrite_TCP5_TYPE_PORT(u_int32_t value);
int addWrite_TCP5_TYPE_PORT(u_int32_t value);
int getStatus_TCP5_TYPE_PORT(void);

#define ID_TCP5_IP_ADDRESS 5115
extern u_int32_t TCP5_IP_ADDRESS;
int doWrite_TCP5_IP_ADDRESS(u_int32_t value);
int addWrite_TCP5_IP_ADDRESS(u_int32_t value);
int getStatus_TCP5_IP_ADDRESS(void);

#define ID_TCP5_STATUS 5116
extern u_int32_t TCP5_STATUS;
int doWrite_TCP5_STATUS(u_int32_t value);
int addWrite_TCP5_STATUS(u_int32_t value);
int getStatus_TCP5_STATUS(void);

#define ID_TCP5_READS 5117
extern u_int32_t TCP5_READS;
int doWrite_TCP5_READS(u_int32_t value);
int addWrite_TCP5_READS(u_int32_t value);
int getStatus_TCP5_READS(void);

#define ID_TCP5_WRITES 5118
extern u_int32_t TCP5_WRITES;
int doWrite_TCP5_WRITES(u_int32_t value);
int addWrite_TCP5_WRITES(u_int32_t value);
int getStatus_TCP5_WRITES(void);

#define ID_TCP5_TIMEOUTS 5119
extern u_int32_t TCP5_TIMEOUTS;
int doWrite_TCP5_TIMEOUTS(u_int32_t value);
int addWrite_TCP5_TIMEOUTS(u_int32_t value);
int getStatus_TCP5_TIMEOUTS(void);

#define ID_TCP5_COMM_ERRORS 5120
extern u_int32_t TCP5_COMM_ERRORS;
int doWrite_TCP5_COMM_ERRORS(u_int32_t value);
int addWrite_TCP5_COMM_ERRORS(u_int32_t value);
int getStatus_TCP5_COMM_ERRORS(void);

#define ID_TCP5_LAST_ERROR 5121
extern u_int32_t TCP5_LAST_ERROR;
int doWrite_TCP5_LAST_ERROR(u_int32_t value);
int addWrite_TCP5_LAST_ERROR(u_int32_t value);
int getStatus_TCP5_LAST_ERROR(void);

#define ID_TCP5_WRITE_QUEUE 5122
extern u_int32_t TCP5_WRITE_QUEUE;
int doWrite_TCP5_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP5_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP5_WRITE_QUEUE(void);

#define ID_TCP5_BUS_LOAD 5123
extern u_int32_t TCP5_BUS_LOAD;
int doWrite_TCP5_BUS_LOAD(u_int32_t value);
int addWrite_TCP5_BUS_LOAD(u_int32_t value);
int getStatus_TCP5_BUS_LOAD(void);

#define ID_TCP6_TYPE_PORT 5124
extern u_int32_t TCP6_TYPE_PORT;
int doWrite_TCP6_TYPE_PORT(u_int32_t value);
int addWrite_TCP6_TYPE_PORT(u_int32_t value);
int getStatus_TCP6_TYPE_PORT(void);

#define ID_TCP6_IP_ADDRESS 5125
extern u_int32_t TCP6_IP_ADDRESS;
int doWrite_TCP6_IP_ADDRESS(u_int32_t value);
int addWrite_TCP6_IP_ADDRESS(u_int32_t value);
int getStatus_TCP6_IP_ADDRESS(void);

#define ID_TCP6_STATUS 5126
extern u_int32_t TCP6_STATUS;
int doWrite_TCP6_STATUS(u_int32_t value);
int addWrite_TCP6_STATUS(u_int32_t value);
int getStatus_TCP6_STATUS(void);

#define ID_TCP6_READS 5127
extern u_int32_t TCP6_READS;
int doWrite_TCP6_READS(u_int32_t value);
int addWrite_TCP6_READS(u_int32_t value);
int getStatus_TCP6_READS(void);

#define ID_TCP6_WRITES 5128
extern u_int32_t TCP6_WRITES;
int doWrite_TCP6_WRITES(u_int32_t value);
int addWrite_TCP6_WRITES(u_int32_t value);
int getStatus_TCP6_WRITES(void);

#define ID_TCP6_TIMEOUTS 5129
extern u_int32_t TCP6_TIMEOUTS;
int doWrite_TCP6_TIMEOUTS(u_int32_t value);
int addWrite_TCP6_TIMEOUTS(u_int32_t value);
int getStatus_TCP6_TIMEOUTS(void);

#define ID_TCP6_COMM_ERRORS 5130
extern u_int32_t TCP6_COMM_ERRORS;
int doWrite_TCP6_COMM_ERRORS(u_int32_t value);
int addWrite_TCP6_COMM_ERRORS(u_int32_t value);
int getStatus_TCP6_COMM_ERRORS(void);

#define ID_TCP6_LAST_ERROR 5131
extern u_int32_t TCP6_LAST_ERROR;
int doWrite_TCP6_LAST_ERROR(u_int32_t value);
int addWrite_TCP6_LAST_ERROR(u_int32_t value);
int getStatus_TCP6_LAST_ERROR(void);

#define ID_TCP6_WRITE_QUEUE 5132
extern u_int32_t TCP6_WRITE_QUEUE;
int doWrite_TCP6_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP6_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP6_WRITE_QUEUE(void);

#define ID_TCP6_BUS_LOAD 5133
extern u_int32_t TCP6_BUS_LOAD;
int doWrite_TCP6_BUS_LOAD(u_int32_t value);
int addWrite_TCP6_BUS_LOAD(u_int32_t value);
int getStatus_TCP6_BUS_LOAD(void);

#define ID_TCP7_TYPE_PORT 5134
extern u_int32_t TCP7_TYPE_PORT;
int doWrite_TCP7_TYPE_PORT(u_int32_t value);
int addWrite_TCP7_TYPE_PORT(u_int32_t value);
int getStatus_TCP7_TYPE_PORT(void);

#define ID_TCP7_IP_ADDRESS 5135
extern u_int32_t TCP7_IP_ADDRESS;
int doWrite_TCP7_IP_ADDRESS(u_int32_t value);
int addWrite_TCP7_IP_ADDRESS(u_int32_t value);
int getStatus_TCP7_IP_ADDRESS(void);

#define ID_TCP7_STATUS 5136
extern u_int32_t TCP7_STATUS;
int doWrite_TCP7_STATUS(u_int32_t value);
int addWrite_TCP7_STATUS(u_int32_t value);
int getStatus_TCP7_STATUS(void);

#define ID_TCP7_READS 5137
extern u_int32_t TCP7_READS;
int doWrite_TCP7_READS(u_int32_t value);
int addWrite_TCP7_READS(u_int32_t value);
int getStatus_TCP7_READS(void);

#define ID_TCP7_WRITES 5138
extern u_int32_t TCP7_WRITES;
int doWrite_TCP7_WRITES(u_int32_t value);
int addWrite_TCP7_WRITES(u_int32_t value);
int getStatus_TCP7_WRITES(void);

#define ID_TCP7_TIMEOUTS 5139
extern u_int32_t TCP7_TIMEOUTS;
int doWrite_TCP7_TIMEOUTS(u_int32_t value);
int addWrite_TCP7_TIMEOUTS(u_int32_t value);
int getStatus_TCP7_TIMEOUTS(void);

#define ID_TCP7_COMM_ERRORS 5140
extern u_int32_t TCP7_COMM_ERRORS;
int doWrite_TCP7_COMM_ERRORS(u_int32_t value);
int addWrite_TCP7_COMM_ERRORS(u_int32_t value);
int getStatus_TCP7_COMM_ERRORS(void);

#define ID_TCP7_LAST_ERROR 5141
extern u_int32_t TCP7_LAST_ERROR;
int doWrite_TCP7_LAST_ERROR(u_int32_t value);
int addWrite_TCP7_LAST_ERROR(u_int32_t value);
int getStatus_TCP7_LAST_ERROR(void);

#define ID_TCP7_WRITE_QUEUE 5142
extern u_int32_t TCP7_WRITE_QUEUE;
int doWrite_TCP7_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP7_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP7_WRITE_QUEUE(void);

#define ID_TCP7_BUS_LOAD 5143
extern u_int32_t TCP7_BUS_LOAD;
int doWrite_TCP7_BUS_LOAD(u_int32_t value);
int addWrite_TCP7_BUS_LOAD(u_int32_t value);
int getStatus_TCP7_BUS_LOAD(void);

#define ID_TCP8_TYPE_PORT 5144
extern u_int32_t TCP8_TYPE_PORT;
int doWrite_TCP8_TYPE_PORT(u_int32_t value);
int addWrite_TCP8_TYPE_PORT(u_int32_t value);
int getStatus_TCP8_TYPE_PORT(void);

#define ID_TCP8_IP_ADDRESS 5145
extern u_int32_t TCP8_IP_ADDRESS;
int doWrite_TCP8_IP_ADDRESS(u_int32_t value);
int addWrite_TCP8_IP_ADDRESS(u_int32_t value);
int getStatus_TCP8_IP_ADDRESS(void);

#define ID_TCP8_STATUS 5146
extern u_int32_t TCP8_STATUS;
int doWrite_TCP8_STATUS(u_int32_t value);
int addWrite_TCP8_STATUS(u_int32_t value);
int getStatus_TCP8_STATUS(void);

#define ID_TCP8_READS 5147
extern u_int32_t TCP8_READS;
int doWrite_TCP8_READS(u_int32_t value);
int addWrite_TCP8_READS(u_int32_t value);
int getStatus_TCP8_READS(void);

#define ID_TCP8_WRITES 5148
extern u_int32_t TCP8_WRITES;
int doWrite_TCP8_WRITES(u_int32_t value);
int addWrite_TCP8_WRITES(u_int32_t value);
int getStatus_TCP8_WRITES(void);

#define ID_TCP8_TIMEOUTS 5149
extern u_int32_t TCP8_TIMEOUTS;
int doWrite_TCP8_TIMEOUTS(u_int32_t value);
int addWrite_TCP8_TIMEOUTS(u_int32_t value);
int getStatus_TCP8_TIMEOUTS(void);

#define ID_TCP8_COMM_ERRORS 5150
extern u_int32_t TCP8_COMM_ERRORS;
int doWrite_TCP8_COMM_ERRORS(u_int32_t value);
int addWrite_TCP8_COMM_ERRORS(u_int32_t value);
int getStatus_TCP8_COMM_ERRORS(void);

#define ID_TCP8_LAST_ERROR 5151
extern u_int32_t TCP8_LAST_ERROR;
int doWrite_TCP8_LAST_ERROR(u_int32_t value);
int addWrite_TCP8_LAST_ERROR(u_int32_t value);
int getStatus_TCP8_LAST_ERROR(void);

#define ID_TCP8_WRITE_QUEUE 5152
extern u_int32_t TCP8_WRITE_QUEUE;
int doWrite_TCP8_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP8_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP8_WRITE_QUEUE(void);

#define ID_TCP8_BUS_LOAD 5153
extern u_int32_t TCP8_BUS_LOAD;
int doWrite_TCP8_BUS_LOAD(u_int32_t value);
int addWrite_TCP8_BUS_LOAD(u_int32_t value);
int getStatus_TCP8_BUS_LOAD(void);

#define ID_TCP9_TYPE_PORT 5154
extern u_int32_t TCP9_TYPE_PORT;
int doWrite_TCP9_TYPE_PORT(u_int32_t value);
int addWrite_TCP9_TYPE_PORT(u_int32_t value);
int getStatus_TCP9_TYPE_PORT(void);

#define ID_TCP9_IP_ADDRESS 5155
extern u_int32_t TCP9_IP_ADDRESS;
int doWrite_TCP9_IP_ADDRESS(u_int32_t value);
int addWrite_TCP9_IP_ADDRESS(u_int32_t value);
int getStatus_TCP9_IP_ADDRESS(void);

#define ID_TCP9_STATUS 5156
extern u_int32_t TCP9_STATUS;
int doWrite_TCP9_STATUS(u_int32_t value);
int addWrite_TCP9_STATUS(u_int32_t value);
int getStatus_TCP9_STATUS(void);

#define ID_TCP9_READS 5157
extern u_int32_t TCP9_READS;
int doWrite_TCP9_READS(u_int32_t value);
int addWrite_TCP9_READS(u_int32_t value);
int getStatus_TCP9_READS(void);

#define ID_TCP9_WRITES 5158
extern u_int32_t TCP9_WRITES;
int doWrite_TCP9_WRITES(u_int32_t value);
int addWrite_TCP9_WRITES(u_int32_t value);
int getStatus_TCP9_WRITES(void);

#define ID_TCP9_TIMEOUTS 5159
extern u_int32_t TCP9_TIMEOUTS;
int doWrite_TCP9_TIMEOUTS(u_int32_t value);
int addWrite_TCP9_TIMEOUTS(u_int32_t value);
int getStatus_TCP9_TIMEOUTS(void);

#define ID_TCP9_COMM_ERRORS 5160
extern u_int32_t TCP9_COMM_ERRORS;
int doWrite_TCP9_COMM_ERRORS(u_int32_t value);
int addWrite_TCP9_COMM_ERRORS(u_int32_t value);
int getStatus_TCP9_COMM_ERRORS(void);

#define ID_TCP9_LAST_ERROR 5161
extern u_int32_t TCP9_LAST_ERROR;
int doWrite_TCP9_LAST_ERROR(u_int32_t value);
int addWrite_TCP9_LAST_ERROR(u_int32_t value);
int getStatus_TCP9_LAST_ERROR(void);

#define ID_TCP9_WRITE_QUEUE 5162
extern u_int32_t TCP9_WRITE_QUEUE;
int doWrite_TCP9_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP9_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP9_WRITE_QUEUE(void);

#define ID_TCP9_BUS_LOAD 5163
extern u_int32_t TCP9_BUS_LOAD;
int doWrite_TCP9_BUS_LOAD(u_int32_t value);
int addWrite_TCP9_BUS_LOAD(u_int32_t value);
int getStatus_TCP9_BUS_LOAD(void);

#define ID_NODE_01_DEV_NODE 5176
extern u_int32_t NODE_01_DEV_NODE;
int doWrite_NODE_01_DEV_NODE(u_int32_t value);
int addWrite_NODE_01_DEV_NODE(u_int32_t value);
int getStatus_NODE_01_DEV_NODE(void);

#define ID_NODE_01_STATUS 5177
extern u_int32_t NODE_01_STATUS;
int doWrite_NODE_01_STATUS(u_int32_t value);
int addWrite_NODE_01_STATUS(u_int32_t value);
int getStatus_NODE_01_STATUS(void);

#define ID_NODE_02_DEV_NODE 5178
extern u_int32_t NODE_02_DEV_NODE;
int doWrite_NODE_02_DEV_NODE(u_int32_t value);
int addWrite_NODE_02_DEV_NODE(u_int32_t value);
int getStatus_NODE_02_DEV_NODE(void);

#define ID_NODE_02_STATUS 5179
extern u_int32_t NODE_02_STATUS;
int doWrite_NODE_02_STATUS(u_int32_t value);
int addWrite_NODE_02_STATUS(u_int32_t value);
int getStatus_NODE_02_STATUS(void);

#define ID_NODE_03_DEV_NODE 5180
extern u_int32_t NODE_03_DEV_NODE;
int doWrite_NODE_03_DEV_NODE(u_int32_t value);
int addWrite_NODE_03_DEV_NODE(u_int32_t value);
int getStatus_NODE_03_DEV_NODE(void);

#define ID_NODE_03_STATUS 5181
extern u_int32_t NODE_03_STATUS;
int doWrite_NODE_03_STATUS(u_int32_t value);
int addWrite_NODE_03_STATUS(u_int32_t value);
int getStatus_NODE_03_STATUS(void);

#define ID_NODE_04_DEV_NODE 5182
extern u_int32_t NODE_04_DEV_NODE;
int doWrite_NODE_04_DEV_NODE(u_int32_t value);
int addWrite_NODE_04_DEV_NODE(u_int32_t value);
int getStatus_NODE_04_DEV_NODE(void);

#define ID_NODE_04_STATUS 5183
extern u_int32_t NODE_04_STATUS;
int doWrite_NODE_04_STATUS(u_int32_t value);
int addWrite_NODE_04_STATUS(u_int32_t value);
int getStatus_NODE_04_STATUS(void);

#define ID_NODE_05_DEV_NODE 5184
extern u_int32_t NODE_05_DEV_NODE;
int doWrite_NODE_05_DEV_NODE(u_int32_t value);
int addWrite_NODE_05_DEV_NODE(u_int32_t value);
int getStatus_NODE_05_DEV_NODE(void);

#define ID_NODE_05_STATUS 5185
extern u_int32_t NODE_05_STATUS;
int doWrite_NODE_05_STATUS(u_int32_t value);
int addWrite_NODE_05_STATUS(u_int32_t value);
int getStatus_NODE_05_STATUS(void);

#define ID_NODE_06_DEV_NODE 5186
extern u_int32_t NODE_06_DEV_NODE;
int doWrite_NODE_06_DEV_NODE(u_int32_t value);
int addWrite_NODE_06_DEV_NODE(u_int32_t value);
int getStatus_NODE_06_DEV_NODE(void);

#define ID_NODE_06_STATUS 5187
extern u_int32_t NODE_06_STATUS;
int doWrite_NODE_06_STATUS(u_int32_t value);
int addWrite_NODE_06_STATUS(u_int32_t value);
int getStatus_NODE_06_STATUS(void);

#define ID_NODE_07_DEV_NODE 5188
extern u_int32_t NODE_07_DEV_NODE;
int doWrite_NODE_07_DEV_NODE(u_int32_t value);
int addWrite_NODE_07_DEV_NODE(u_int32_t value);
int getStatus_NODE_07_DEV_NODE(void);

#define ID_NODE_07_STATUS 5189
extern u_int32_t NODE_07_STATUS;
int doWrite_NODE_07_STATUS(u_int32_t value);
int addWrite_NODE_07_STATUS(u_int32_t value);
int getStatus_NODE_07_STATUS(void);

#define ID_NODE_08_DEV_NODE 5190
extern u_int32_t NODE_08_DEV_NODE;
int doWrite_NODE_08_DEV_NODE(u_int32_t value);
int addWrite_NODE_08_DEV_NODE(u_int32_t value);
int getStatus_NODE_08_DEV_NODE(void);

#define ID_NODE_08_STATUS 5191
extern u_int32_t NODE_08_STATUS;
int doWrite_NODE_08_STATUS(u_int32_t value);
int addWrite_NODE_08_STATUS(u_int32_t value);
int getStatus_NODE_08_STATUS(void);

#define ID_NODE_09_DEV_NODE 5192
extern u_int32_t NODE_09_DEV_NODE;
int doWrite_NODE_09_DEV_NODE(u_int32_t value);
int addWrite_NODE_09_DEV_NODE(u_int32_t value);
int getStatus_NODE_09_DEV_NODE(void);

#define ID_NODE_09_STATUS 5193
extern u_int32_t NODE_09_STATUS;
int doWrite_NODE_09_STATUS(u_int32_t value);
int addWrite_NODE_09_STATUS(u_int32_t value);
int getStatus_NODE_09_STATUS(void);

#define ID_NODE_10_DEV_NODE 5194
extern u_int32_t NODE_10_DEV_NODE;
int doWrite_NODE_10_DEV_NODE(u_int32_t value);
int addWrite_NODE_10_DEV_NODE(u_int32_t value);
int getStatus_NODE_10_DEV_NODE(void);

#define ID_NODE_10_STATUS 5195
extern u_int32_t NODE_10_STATUS;
int doWrite_NODE_10_STATUS(u_int32_t value);
int addWrite_NODE_10_STATUS(u_int32_t value);
int getStatus_NODE_10_STATUS(void);

#define ID_NODE_11_DEV_NODE 5196
extern u_int32_t NODE_11_DEV_NODE;
int doWrite_NODE_11_DEV_NODE(u_int32_t value);
int addWrite_NODE_11_DEV_NODE(u_int32_t value);
int getStatus_NODE_11_DEV_NODE(void);

#define ID_NODE_11_STATUS 5197
extern u_int32_t NODE_11_STATUS;
int doWrite_NODE_11_STATUS(u_int32_t value);
int addWrite_NODE_11_STATUS(u_int32_t value);
int getStatus_NODE_11_STATUS(void);

#define ID_NODE_12_DEV_NODE 5198
extern u_int32_t NODE_12_DEV_NODE;
int doWrite_NODE_12_DEV_NODE(u_int32_t value);
int addWrite_NODE_12_DEV_NODE(u_int32_t value);
int getStatus_NODE_12_DEV_NODE(void);

#define ID_NODE_12_STATUS 5199
extern u_int32_t NODE_12_STATUS;
int doWrite_NODE_12_STATUS(u_int32_t value);
int addWrite_NODE_12_STATUS(u_int32_t value);
int getStatus_NODE_12_STATUS(void);

#define ID_NODE_13_DEV_NODE 5200
extern u_int32_t NODE_13_DEV_NODE;
int doWrite_NODE_13_DEV_NODE(u_int32_t value);
int addWrite_NODE_13_DEV_NODE(u_int32_t value);
int getStatus_NODE_13_DEV_NODE(void);

#define ID_NODE_13_STATUS 5201
extern u_int32_t NODE_13_STATUS;
int doWrite_NODE_13_STATUS(u_int32_t value);
int addWrite_NODE_13_STATUS(u_int32_t value);
int getStatus_NODE_13_STATUS(void);

#define ID_NODE_14_DEV_NODE 5202
extern u_int32_t NODE_14_DEV_NODE;
int doWrite_NODE_14_DEV_NODE(u_int32_t value);
int addWrite_NODE_14_DEV_NODE(u_int32_t value);
int getStatus_NODE_14_DEV_NODE(void);

#define ID_NODE_14_STATUS 5203
extern u_int32_t NODE_14_STATUS;
int doWrite_NODE_14_STATUS(u_int32_t value);
int addWrite_NODE_14_STATUS(u_int32_t value);
int getStatus_NODE_14_STATUS(void);

#define ID_NODE_15_DEV_NODE 5204
extern u_int32_t NODE_15_DEV_NODE;
int doWrite_NODE_15_DEV_NODE(u_int32_t value);
int addWrite_NODE_15_DEV_NODE(u_int32_t value);
int getStatus_NODE_15_DEV_NODE(void);

#define ID_NODE_15_STATUS 5205
extern u_int32_t NODE_15_STATUS;
int doWrite_NODE_15_STATUS(u_int32_t value);
int addWrite_NODE_15_STATUS(u_int32_t value);
int getStatus_NODE_15_STATUS(void);

#define ID_NODE_16_DEV_NODE 5206
extern u_int32_t NODE_16_DEV_NODE;
int doWrite_NODE_16_DEV_NODE(u_int32_t value);
int addWrite_NODE_16_DEV_NODE(u_int32_t value);
int getStatus_NODE_16_DEV_NODE(void);

#define ID_NODE_16_STATUS 5207
extern u_int32_t NODE_16_STATUS;
int doWrite_NODE_16_STATUS(u_int32_t value);
int addWrite_NODE_16_STATUS(u_int32_t value);
int getStatus_NODE_16_STATUS(void);

#define ID_PLC_time 5394
extern float PLC_time;	/* Seconds since boot (reset each 24h) */
int doWrite_PLC_time(float value);
int addWrite_PLC_time(float value);
int getStatus_PLC_time(void);

#define ID_PLC_timeMin 5395
extern float PLC_timeMin;	/* 10 seconds window start */
int doWrite_PLC_timeMin(float value);
int addWrite_PLC_timeMin(float value);
int getStatus_PLC_timeMin(void);

#define ID_PLC_timeMax 5396
extern float PLC_timeMax;	/* 10 seconds window stop */
int doWrite_PLC_timeMax(float value);
int addWrite_PLC_timeMax(float value);
int getStatus_PLC_timeMax(void);

#define ID_PLC_timeWin 5397
extern float PLC_timeWin;	/* Graph display window */
int doWrite_PLC_timeWin(float value);
int addWrite_PLC_timeWin(float value);
int getStatus_PLC_timeWin(void);

#define ID_PLC_Version 5398
extern u_int16_t PLC_Version;	/* Run Time version */
int doWrite_PLC_Version(u_int16_t value);
int addWrite_PLC_Version(u_int16_t value);
int getStatus_PLC_Version(void);

#define ID_PLC_EngineStatus 5399
extern u_int16_t PLC_EngineStatus;	/* PLC status */
int doWrite_PLC_EngineStatus(u_int16_t value);
int addWrite_PLC_EngineStatus(u_int16_t value);
int getStatus_PLC_EngineStatus(void);

#define ID_PLC_ResetValues 5400
extern int PLC_ResetValues;	/* Diagnostic variables reset */
int doWrite_PLC_ResetValues(int value);
int addWrite_PLC_ResetValues(int value);
int getStatus_PLC_ResetValues(void);

#define ID_PLC_buzzerOn 5401
extern int PLC_buzzerOn;	/* Buzzer sound (enable = 1 disable = 0) */
int doWrite_PLC_buzzerOn(int value);
int addWrite_PLC_buzzerOn(int value);
int getStatus_PLC_buzzerOn(void);

#define ID_PLC_PLC_Version 5402
extern u_int16_t PLC_PLC_Version;	/* PLC application version */
int doWrite_PLC_PLC_Version(u_int16_t value);
int addWrite_PLC_PLC_Version(u_int16_t value);
int getStatus_PLC_PLC_Version(void);

#define ID_PLC_HMI_Version 5403
extern u_int16_t PLC_HMI_Version;	/* HMI application version */
int doWrite_PLC_HMI_Version(u_int16_t value);
int addWrite_PLC_HMI_Version(u_int16_t value);
int getStatus_PLC_HMI_Version(void);

#define ID_PLC_Year 5414
extern u_int16_t PLC_Year;	/* Currently year */
int doWrite_PLC_Year(u_int16_t value);
int addWrite_PLC_Year(u_int16_t value);
int getStatus_PLC_Year(void);

#define ID_PLC_Month 5415
extern u_int16_t PLC_Month;	/* Currently month */
int doWrite_PLC_Month(u_int16_t value);
int addWrite_PLC_Month(u_int16_t value);
int getStatus_PLC_Month(void);

#define ID_PLC_Day 5416
extern u_int16_t PLC_Day;	/* Currently day */
int doWrite_PLC_Day(u_int16_t value);
int addWrite_PLC_Day(u_int16_t value);
int getStatus_PLC_Day(void);

#define ID_PLC_Hours 5417
extern u_int16_t PLC_Hours;	/* Currently hour */
int doWrite_PLC_Hours(u_int16_t value);
int addWrite_PLC_Hours(u_int16_t value);
int getStatus_PLC_Hours(void);

#define ID_PLC_Minutes 5418
extern u_int16_t PLC_Minutes;	/* Currently minutes */
int doWrite_PLC_Minutes(u_int16_t value);
int addWrite_PLC_Minutes(u_int16_t value);
int getStatus_PLC_Minutes(void);

#define ID_PLC_Seconds 5419
extern u_int16_t PLC_Seconds;	/* Currently seconds */
int doWrite_PLC_Seconds(u_int16_t value);
int addWrite_PLC_Seconds(u_int16_t value);
int getStatus_PLC_Seconds(void);

#define ID_PLC_WATCHDOGEN 5422
extern int PLC_WATCHDOGEN;	/* Enable Watchdog */
int doWrite_PLC_WATCHDOGEN(int value);
int addWrite_PLC_WATCHDOGEN(int value);
int getStatus_PLC_WATCHDOGEN(void);

#define ID_PLC_WATCHDOG_ms 5423
extern u_int32_t PLC_WATCHDOG_ms;	/* Reset Watchdog timer */
int doWrite_PLC_WATCHDOG_ms(u_int32_t value);
int addWrite_PLC_WATCHDOG_ms(u_int32_t value);
int getStatus_PLC_WATCHDOG_ms(void);

#define ID_PLC_BEEP_VOLUME 5439
extern u_int8_t PLC_BEEP_VOLUME;	/* Beep volume (when buzzerOn) */
int doWrite_PLC_BEEP_VOLUME(u_int8_t value);
int addWrite_PLC_BEEP_VOLUME(u_int8_t value);
int getStatus_PLC_BEEP_VOLUME(void);

#define ID_PLC_TOUCH_VOLUME 5440
extern u_int8_t PLC_TOUCH_VOLUME;	/* Touch volume */
int doWrite_PLC_TOUCH_VOLUME(u_int8_t value);
int addWrite_PLC_TOUCH_VOLUME(u_int8_t value);
int getStatus_PLC_TOUCH_VOLUME(void);

#define ID_PLC_ALARM_VOLUME 5441
extern u_int8_t PLC_ALARM_VOLUME;	/* Alarm volume (when alarm) */
int doWrite_PLC_ALARM_VOLUME(u_int8_t value);
int addWrite_PLC_ALARM_VOLUME(u_int8_t value);
int getStatus_PLC_ALARM_VOLUME(void);

#define ID_PLC_BUZZER 5442
extern u_int32_t PLC_BUZZER;	/* Enable dynamic buzzer sound (0x44332211 up=0x11(%) on=0x22(cs) off=0x33(cs) rep=0x44(times)) */
int doWrite_PLC_BUZZER(u_int32_t value);
int addWrite_PLC_BUZZER(u_int32_t value);
int getStatus_PLC_BUZZER(void);

#ifdef __cplusplus
}
#endif
#endif
