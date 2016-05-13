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
 
#define ID_RTU0_TYPE_PORT 5000
extern u_int32_t RTU0_TYPE_PORT;
int doWrite_RTU0_TYPE_PORT(u_int32_t value);
int addWrite_RTU0_TYPE_PORT(u_int32_t value);
int getStatus_RTU0_TYPE_PORT();
 
#define ID_RTU0_BAUDRATE 5001
extern u_int32_t RTU0_BAUDRATE;
int doWrite_RTU0_BAUDRATE(u_int32_t value);
int addWrite_RTU0_BAUDRATE(u_int32_t value);
int getStatus_RTU0_BAUDRATE();
 
#define ID_RTU0_STATUS 5002
extern u_int32_t RTU0_STATUS;
int doWrite_RTU0_STATUS(u_int32_t value);
int addWrite_RTU0_STATUS(u_int32_t value);
int getStatus_RTU0_STATUS();
 
#define ID_RTU0_READS 5003
extern u_int32_t RTU0_READS;
int doWrite_RTU0_READS(u_int32_t value);
int addWrite_RTU0_READS(u_int32_t value);
int getStatus_RTU0_READS();
 
#define ID_RTU0_WRITES 5004
extern u_int32_t RTU0_WRITES;
int doWrite_RTU0_WRITES(u_int32_t value);
int addWrite_RTU0_WRITES(u_int32_t value);
int getStatus_RTU0_WRITES();
 
#define ID_RTU0_TIMEOUTS 5005
extern u_int32_t RTU0_TIMEOUTS;
int doWrite_RTU0_TIMEOUTS(u_int32_t value);
int addWrite_RTU0_TIMEOUTS(u_int32_t value);
int getStatus_RTU0_TIMEOUTS();
 
#define ID_RTU0_COMM_ERRORS 5006
extern u_int32_t RTU0_COMM_ERRORS;
int doWrite_RTU0_COMM_ERRORS(u_int32_t value);
int addWrite_RTU0_COMM_ERRORS(u_int32_t value);
int getStatus_RTU0_COMM_ERRORS();
 
#define ID_RTU0_LAST_ERROR 5007
extern u_int32_t RTU0_LAST_ERROR;
int doWrite_RTU0_LAST_ERROR(u_int32_t value);
int addWrite_RTU0_LAST_ERROR(u_int32_t value);
int getStatus_RTU0_LAST_ERROR();
 
#define ID_RTU0_WRITE_QUEUE 5008
extern u_int32_t RTU0_WRITE_QUEUE;
int doWrite_RTU0_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU0_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU0_WRITE_QUEUE();
 
#define ID_RTU0_READ_QUEUE 5009
extern u_int32_t RTU0_READ_QUEUE;
int doWrite_RTU0_READ_QUEUE(u_int32_t value);
int addWrite_RTU0_READ_QUEUE(u_int32_t value);
int getStatus_RTU0_READ_QUEUE();
 
#define ID_RTU1_TYPE_PORT 5010
extern u_int32_t RTU1_TYPE_PORT;
int doWrite_RTU1_TYPE_PORT(u_int32_t value);
int addWrite_RTU1_TYPE_PORT(u_int32_t value);
int getStatus_RTU1_TYPE_PORT();
 
#define ID_RTU1_BAUDRATE 5011
extern u_int32_t RTU1_BAUDRATE;
int doWrite_RTU1_BAUDRATE(u_int32_t value);
int addWrite_RTU1_BAUDRATE(u_int32_t value);
int getStatus_RTU1_BAUDRATE();
 
#define ID_RTU1_STATUS 5012
extern u_int32_t RTU1_STATUS;
int doWrite_RTU1_STATUS(u_int32_t value);
int addWrite_RTU1_STATUS(u_int32_t value);
int getStatus_RTU1_STATUS();
 
#define ID_RTU1_READS 5013
extern u_int32_t RTU1_READS;
int doWrite_RTU1_READS(u_int32_t value);
int addWrite_RTU1_READS(u_int32_t value);
int getStatus_RTU1_READS();
 
#define ID_RTU1_WRITES 5014
extern u_int32_t RTU1_WRITES;
int doWrite_RTU1_WRITES(u_int32_t value);
int addWrite_RTU1_WRITES(u_int32_t value);
int getStatus_RTU1_WRITES();
 
#define ID_RTU1_TIMEOUTS 5015
extern u_int32_t RTU1_TIMEOUTS;
int doWrite_RTU1_TIMEOUTS(u_int32_t value);
int addWrite_RTU1_TIMEOUTS(u_int32_t value);
int getStatus_RTU1_TIMEOUTS();
 
#define ID_RTU1_COMM_ERRORS 5016
extern u_int32_t RTU1_COMM_ERRORS;
int doWrite_RTU1_COMM_ERRORS(u_int32_t value);
int addWrite_RTU1_COMM_ERRORS(u_int32_t value);
int getStatus_RTU1_COMM_ERRORS();
 
#define ID_RTU1_LAST_ERROR 5017
extern u_int32_t RTU1_LAST_ERROR;
int doWrite_RTU1_LAST_ERROR(u_int32_t value);
int addWrite_RTU1_LAST_ERROR(u_int32_t value);
int getStatus_RTU1_LAST_ERROR();
 
#define ID_RTU1_WRITE_QUEUE 5018
extern u_int32_t RTU1_WRITE_QUEUE;
int doWrite_RTU1_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU1_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU1_WRITE_QUEUE();
 
#define ID_RTU1_READ_QUEUE 5019
extern u_int32_t RTU1_READ_QUEUE;
int doWrite_RTU1_READ_QUEUE(u_int32_t value);
int addWrite_RTU1_READ_QUEUE(u_int32_t value);
int getStatus_RTU1_READ_QUEUE();
 
#define ID_RTU3_TYPE_PORT 5020
extern u_int32_t RTU3_TYPE_PORT;
int doWrite_RTU3_TYPE_PORT(u_int32_t value);
int addWrite_RTU3_TYPE_PORT(u_int32_t value);
int getStatus_RTU3_TYPE_PORT();
 
#define ID_RTU3_BAUDRATE 5021
extern u_int32_t RTU3_BAUDRATE;
int doWrite_RTU3_BAUDRATE(u_int32_t value);
int addWrite_RTU3_BAUDRATE(u_int32_t value);
int getStatus_RTU3_BAUDRATE();
 
#define ID_RTU3_STATUS 5022
extern u_int32_t RTU3_STATUS;
int doWrite_RTU3_STATUS(u_int32_t value);
int addWrite_RTU3_STATUS(u_int32_t value);
int getStatus_RTU3_STATUS();
 
#define ID_RTU3_READS 5023
extern u_int32_t RTU3_READS;
int doWrite_RTU3_READS(u_int32_t value);
int addWrite_RTU3_READS(u_int32_t value);
int getStatus_RTU3_READS();
 
#define ID_RTU3_WRITES 5024
extern u_int32_t RTU3_WRITES;
int doWrite_RTU3_WRITES(u_int32_t value);
int addWrite_RTU3_WRITES(u_int32_t value);
int getStatus_RTU3_WRITES();
 
#define ID_RTU3_TIMEOUTS 5025
extern u_int32_t RTU3_TIMEOUTS;
int doWrite_RTU3_TIMEOUTS(u_int32_t value);
int addWrite_RTU3_TIMEOUTS(u_int32_t value);
int getStatus_RTU3_TIMEOUTS();
 
#define ID_RTU3_COMM_ERRORS 5026
extern u_int32_t RTU3_COMM_ERRORS;
int doWrite_RTU3_COMM_ERRORS(u_int32_t value);
int addWrite_RTU3_COMM_ERRORS(u_int32_t value);
int getStatus_RTU3_COMM_ERRORS();
 
#define ID_RTU3_LAST_ERROR 5027
extern u_int32_t RTU3_LAST_ERROR;
int doWrite_RTU3_LAST_ERROR(u_int32_t value);
int addWrite_RTU3_LAST_ERROR(u_int32_t value);
int getStatus_RTU3_LAST_ERROR();
 
#define ID_RTU3_WRITE_QUEUE 5028
extern u_int32_t RTU3_WRITE_QUEUE;
int doWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU3_WRITE_QUEUE();
 
#define ID_RTU3_READ_QUEUE 5029
extern u_int32_t RTU3_READ_QUEUE;
int doWrite_RTU3_READ_QUEUE(u_int32_t value);
int addWrite_RTU3_READ_QUEUE(u_int32_t value);
int getStatus_RTU3_READ_QUEUE();
 
#define ID_CAN0_TYPE_PORT 5030
extern u_int32_t CAN0_TYPE_PORT;
int doWrite_CAN0_TYPE_PORT(u_int32_t value);
int addWrite_CAN0_TYPE_PORT(u_int32_t value);
int getStatus_CAN0_TYPE_PORT();
 
#define ID_CAN0_BAUDRATE 5031
extern u_int32_t CAN0_BAUDRATE;
int doWrite_CAN0_BAUDRATE(u_int32_t value);
int addWrite_CAN0_BAUDRATE(u_int32_t value);
int getStatus_CAN0_BAUDRATE();
 
#define ID_CAN0_STATUS 5032
extern u_int32_t CAN0_STATUS;
int doWrite_CAN0_STATUS(u_int32_t value);
int addWrite_CAN0_STATUS(u_int32_t value);
int getStatus_CAN0_STATUS();
 
#define ID_CAN0_READS 5033
extern u_int32_t CAN0_READS;
int doWrite_CAN0_READS(u_int32_t value);
int addWrite_CAN0_READS(u_int32_t value);
int getStatus_CAN0_READS();
 
#define ID_CAN0_WRITES 5034
extern u_int32_t CAN0_WRITES;
int doWrite_CAN0_WRITES(u_int32_t value);
int addWrite_CAN0_WRITES(u_int32_t value);
int getStatus_CAN0_WRITES();
 
#define ID_CAN0_TIMEOUTS 5035
extern u_int32_t CAN0_TIMEOUTS;
int doWrite_CAN0_TIMEOUTS(u_int32_t value);
int addWrite_CAN0_TIMEOUTS(u_int32_t value);
int getStatus_CAN0_TIMEOUTS();
 
#define ID_CAN0_COMM_ERRORS 5036
extern u_int32_t CAN0_COMM_ERRORS;
int doWrite_CAN0_COMM_ERRORS(u_int32_t value);
int addWrite_CAN0_COMM_ERRORS(u_int32_t value);
int getStatus_CAN0_COMM_ERRORS();
 
#define ID_CAN0_LAST_ERROR 5037
extern u_int32_t CAN0_LAST_ERROR;
int doWrite_CAN0_LAST_ERROR(u_int32_t value);
int addWrite_CAN0_LAST_ERROR(u_int32_t value);
int getStatus_CAN0_LAST_ERROR();
 
#define ID_CAN0_WRITE_QUEUE 5038
extern u_int32_t CAN0_WRITE_QUEUE;
int doWrite_CAN0_WRITE_QUEUE(u_int32_t value);
int addWrite_CAN0_WRITE_QUEUE(u_int32_t value);
int getStatus_CAN0_WRITE_QUEUE();
 
#define ID_CAN0_READ_QUEUE 5039
extern u_int32_t CAN0_READ_QUEUE;
int doWrite_CAN0_READ_QUEUE(u_int32_t value);
int addWrite_CAN0_READ_QUEUE(u_int32_t value);
int getStatus_CAN0_READ_QUEUE();
 
#define ID_CAN1_TYPE_PORT 5040
extern u_int32_t CAN1_TYPE_PORT;
int doWrite_CAN1_TYPE_PORT(u_int32_t value);
int addWrite_CAN1_TYPE_PORT(u_int32_t value);
int getStatus_CAN1_TYPE_PORT();
 
#define ID_CAN1_BAUDRATE 5041
extern u_int32_t CAN1_BAUDRATE;
int doWrite_CAN1_BAUDRATE(u_int32_t value);
int addWrite_CAN1_BAUDRATE(u_int32_t value);
int getStatus_CAN1_BAUDRATE();
 
#define ID_CAN1_STATUS 5042
extern u_int32_t CAN1_STATUS;
int doWrite_CAN1_STATUS(u_int32_t value);
int addWrite_CAN1_STATUS(u_int32_t value);
int getStatus_CAN1_STATUS();
 
#define ID_CAN1_READS 5043
extern u_int32_t CAN1_READS;
int doWrite_CAN1_READS(u_int32_t value);
int addWrite_CAN1_READS(u_int32_t value);
int getStatus_CAN1_READS();
 
#define ID_CAN1_WRITES 5044
extern u_int32_t CAN1_WRITES;
int doWrite_CAN1_WRITES(u_int32_t value);
int addWrite_CAN1_WRITES(u_int32_t value);
int getStatus_CAN1_WRITES();
 
#define ID_CAN1_TIMEOUTS 5045
extern u_int32_t CAN1_TIMEOUTS;
int doWrite_CAN1_TIMEOUTS(u_int32_t value);
int addWrite_CAN1_TIMEOUTS(u_int32_t value);
int getStatus_CAN1_TIMEOUTS();
 
#define ID_CAN1_COMM_ERRORS 5046
extern u_int32_t CAN1_COMM_ERRORS;
int doWrite_CAN1_COMM_ERRORS(u_int32_t value);
int addWrite_CAN1_COMM_ERRORS(u_int32_t value);
int getStatus_CAN1_COMM_ERRORS();
 
#define ID_CAN1_LAST_ERROR 5047
extern u_int32_t CAN1_LAST_ERROR;
int doWrite_CAN1_LAST_ERROR(u_int32_t value);
int addWrite_CAN1_LAST_ERROR(u_int32_t value);
int getStatus_CAN1_LAST_ERROR();
 
#define ID_CAN1_WRITE_QUEUE 5048
extern u_int32_t CAN1_WRITE_QUEUE;
int doWrite_CAN1_WRITE_QUEUE(u_int32_t value);
int addWrite_CAN1_WRITE_QUEUE(u_int32_t value);
int getStatus_CAN1_WRITE_QUEUE();
 
#define ID_CAN1_READ_QUEUE 5049
extern u_int32_t CAN1_READ_QUEUE;
int doWrite_CAN1_READ_QUEUE(u_int32_t value);
int addWrite_CAN1_READ_QUEUE(u_int32_t value);
int getStatus_CAN1_READ_QUEUE();
 
#define ID_TCPS_TYPE_PORT 5050
extern u_int32_t TCPS_TYPE_PORT;
int doWrite_TCPS_TYPE_PORT(u_int32_t value);
int addWrite_TCPS_TYPE_PORT(u_int32_t value);
int getStatus_TCPS_TYPE_PORT();
 
#define ID_TCPS_IP_ADDRESS 5051
extern u_int32_t TCPS_IP_ADDRESS;
int doWrite_TCPS_IP_ADDRESS(u_int32_t value);
int addWrite_TCPS_IP_ADDRESS(u_int32_t value);
int getStatus_TCPS_IP_ADDRESS();
 
#define ID_TCPS_STATUS 5052
extern u_int32_t TCPS_STATUS;
int doWrite_TCPS_STATUS(u_int32_t value);
int addWrite_TCPS_STATUS(u_int32_t value);
int getStatus_TCPS_STATUS();
 
#define ID_TCPS_READS 5053
extern u_int32_t TCPS_READS;
int doWrite_TCPS_READS(u_int32_t value);
int addWrite_TCPS_READS(u_int32_t value);
int getStatus_TCPS_READS();
 
#define ID_TCPS_WRITES 5054
extern u_int32_t TCPS_WRITES;
int doWrite_TCPS_WRITES(u_int32_t value);
int addWrite_TCPS_WRITES(u_int32_t value);
int getStatus_TCPS_WRITES();
 
#define ID_TCPS_TIMEOUTS 5055
extern u_int32_t TCPS_TIMEOUTS;
int doWrite_TCPS_TIMEOUTS(u_int32_t value);
int addWrite_TCPS_TIMEOUTS(u_int32_t value);
int getStatus_TCPS_TIMEOUTS();
 
#define ID_TCPS_COMM_ERRORS 5056
extern u_int32_t TCPS_COMM_ERRORS;
int doWrite_TCPS_COMM_ERRORS(u_int32_t value);
int addWrite_TCPS_COMM_ERRORS(u_int32_t value);
int getStatus_TCPS_COMM_ERRORS();
 
#define ID_TCPS_LAST_ERROR 5057
extern u_int32_t TCPS_LAST_ERROR;
int doWrite_TCPS_LAST_ERROR(u_int32_t value);
int addWrite_TCPS_LAST_ERROR(u_int32_t value);
int getStatus_TCPS_LAST_ERROR();
 
#define ID_TCPS_WRITE_QUEUE 5058
extern u_int32_t TCPS_WRITE_QUEUE;
int doWrite_TCPS_WRITE_QUEUE(u_int32_t value);
int addWrite_TCPS_WRITE_QUEUE(u_int32_t value);
int getStatus_TCPS_WRITE_QUEUE();
 
#define ID_TCPS_READ_QUEUE 5059
extern u_int32_t TCPS_READ_QUEUE;
int doWrite_TCPS_READ_QUEUE(u_int32_t value);
int addWrite_TCPS_READ_QUEUE(u_int32_t value);
int getStatus_TCPS_READ_QUEUE();
 
#define ID_TCP0_TYPE_PORT 5060
extern u_int32_t TCP0_TYPE_PORT;
int doWrite_TCP0_TYPE_PORT(u_int32_t value);
int addWrite_TCP0_TYPE_PORT(u_int32_t value);
int getStatus_TCP0_TYPE_PORT();
 
#define ID_TCP0_IP_ADDRESS 5061
extern u_int32_t TCP0_IP_ADDRESS;
int doWrite_TCP0_IP_ADDRESS(u_int32_t value);
int addWrite_TCP0_IP_ADDRESS(u_int32_t value);
int getStatus_TCP0_IP_ADDRESS();
 
#define ID_TCP0_STATUS 5062
extern u_int32_t TCP0_STATUS;
int doWrite_TCP0_STATUS(u_int32_t value);
int addWrite_TCP0_STATUS(u_int32_t value);
int getStatus_TCP0_STATUS();
 
#define ID_TCP0_READS 5063
extern u_int32_t TCP0_READS;
int doWrite_TCP0_READS(u_int32_t value);
int addWrite_TCP0_READS(u_int32_t value);
int getStatus_TCP0_READS();
 
#define ID_TCP0_WRITES 5064
extern u_int32_t TCP0_WRITES;
int doWrite_TCP0_WRITES(u_int32_t value);
int addWrite_TCP0_WRITES(u_int32_t value);
int getStatus_TCP0_WRITES();
 
#define ID_TCP0_TIMEOUTS 5065
extern u_int32_t TCP0_TIMEOUTS;
int doWrite_TCP0_TIMEOUTS(u_int32_t value);
int addWrite_TCP0_TIMEOUTS(u_int32_t value);
int getStatus_TCP0_TIMEOUTS();
 
#define ID_TCP0_COMM_ERRORS 5066
extern u_int32_t TCP0_COMM_ERRORS;
int doWrite_TCP0_COMM_ERRORS(u_int32_t value);
int addWrite_TCP0_COMM_ERRORS(u_int32_t value);
int getStatus_TCP0_COMM_ERRORS();
 
#define ID_TCP0_LAST_ERROR 5067
extern u_int32_t TCP0_LAST_ERROR;
int doWrite_TCP0_LAST_ERROR(u_int32_t value);
int addWrite_TCP0_LAST_ERROR(u_int32_t value);
int getStatus_TCP0_LAST_ERROR();
 
#define ID_TCP0_WRITE_QUEUE 5068
extern u_int32_t TCP0_WRITE_QUEUE;
int doWrite_TCP0_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP0_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP0_WRITE_QUEUE();
 
#define ID_TCP0_READ_QUEUE 5069
extern u_int32_t TCP0_READ_QUEUE;
int doWrite_TCP0_READ_QUEUE(u_int32_t value);
int addWrite_TCP0_READ_QUEUE(u_int32_t value);
int getStatus_TCP0_READ_QUEUE();
 
#define ID_TCP1_TYPE_PORT 5070
extern u_int32_t TCP1_TYPE_PORT;
int doWrite_TCP1_TYPE_PORT(u_int32_t value);
int addWrite_TCP1_TYPE_PORT(u_int32_t value);
int getStatus_TCP1_TYPE_PORT();
 
#define ID_TCP1_IP_ADDRESS 5071
extern u_int32_t TCP1_IP_ADDRESS;
int doWrite_TCP1_IP_ADDRESS(u_int32_t value);
int addWrite_TCP1_IP_ADDRESS(u_int32_t value);
int getStatus_TCP1_IP_ADDRESS();
 
#define ID_TCP1_STATUS 5072
extern u_int32_t TCP1_STATUS;
int doWrite_TCP1_STATUS(u_int32_t value);
int addWrite_TCP1_STATUS(u_int32_t value);
int getStatus_TCP1_STATUS();
 
#define ID_TCP1_READS 5073
extern u_int32_t TCP1_READS;
int doWrite_TCP1_READS(u_int32_t value);
int addWrite_TCP1_READS(u_int32_t value);
int getStatus_TCP1_READS();
 
#define ID_TCP1_WRITES 5074
extern u_int32_t TCP1_WRITES;
int doWrite_TCP1_WRITES(u_int32_t value);
int addWrite_TCP1_WRITES(u_int32_t value);
int getStatus_TCP1_WRITES();
 
#define ID_TCP1_TIMEOUTS 5075
extern u_int32_t TCP1_TIMEOUTS;
int doWrite_TCP1_TIMEOUTS(u_int32_t value);
int addWrite_TCP1_TIMEOUTS(u_int32_t value);
int getStatus_TCP1_TIMEOUTS();
 
#define ID_TCP1_COMM_ERRORS 5076
extern u_int32_t TCP1_COMM_ERRORS;
int doWrite_TCP1_COMM_ERRORS(u_int32_t value);
int addWrite_TCP1_COMM_ERRORS(u_int32_t value);
int getStatus_TCP1_COMM_ERRORS();
 
#define ID_TCP1_LAST_ERROR 5077
extern u_int32_t TCP1_LAST_ERROR;
int doWrite_TCP1_LAST_ERROR(u_int32_t value);
int addWrite_TCP1_LAST_ERROR(u_int32_t value);
int getStatus_TCP1_LAST_ERROR();
 
#define ID_TCP1_WRITE_QUEUE 5078
extern u_int32_t TCP1_WRITE_QUEUE;
int doWrite_TCP1_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP1_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP1_WRITE_QUEUE();
 
#define ID_TCP1_READ_QUEUE 5079
extern u_int32_t TCP1_READ_QUEUE;
int doWrite_TCP1_READ_QUEUE(u_int32_t value);
int addWrite_TCP1_READ_QUEUE(u_int32_t value);
int getStatus_TCP1_READ_QUEUE();
 
#define ID_TCP2_TYPE_PORT 5080
extern u_int32_t TCP2_TYPE_PORT;
int doWrite_TCP2_TYPE_PORT(u_int32_t value);
int addWrite_TCP2_TYPE_PORT(u_int32_t value);
int getStatus_TCP2_TYPE_PORT();
 
#define ID_TCP2_IP_ADDRESS 5081
extern u_int32_t TCP2_IP_ADDRESS;
int doWrite_TCP2_IP_ADDRESS(u_int32_t value);
int addWrite_TCP2_IP_ADDRESS(u_int32_t value);
int getStatus_TCP2_IP_ADDRESS();
 
#define ID_TCP2_STATUS 5082
extern u_int32_t TCP2_STATUS;
int doWrite_TCP2_STATUS(u_int32_t value);
int addWrite_TCP2_STATUS(u_int32_t value);
int getStatus_TCP2_STATUS();
 
#define ID_TCP2_READS 5083
extern u_int32_t TCP2_READS;
int doWrite_TCP2_READS(u_int32_t value);
int addWrite_TCP2_READS(u_int32_t value);
int getStatus_TCP2_READS();
 
#define ID_TCP2_WRITES 5084
extern u_int32_t TCP2_WRITES;
int doWrite_TCP2_WRITES(u_int32_t value);
int addWrite_TCP2_WRITES(u_int32_t value);
int getStatus_TCP2_WRITES();
 
#define ID_TCP2_TIMEOUTS 5085
extern u_int32_t TCP2_TIMEOUTS;
int doWrite_TCP2_TIMEOUTS(u_int32_t value);
int addWrite_TCP2_TIMEOUTS(u_int32_t value);
int getStatus_TCP2_TIMEOUTS();
 
#define ID_TCP2_COMM_ERRORS 5086
extern u_int32_t TCP2_COMM_ERRORS;
int doWrite_TCP2_COMM_ERRORS(u_int32_t value);
int addWrite_TCP2_COMM_ERRORS(u_int32_t value);
int getStatus_TCP2_COMM_ERRORS();
 
#define ID_TCP2_LAST_ERROR 5087
extern u_int32_t TCP2_LAST_ERROR;
int doWrite_TCP2_LAST_ERROR(u_int32_t value);
int addWrite_TCP2_LAST_ERROR(u_int32_t value);
int getStatus_TCP2_LAST_ERROR();
 
#define ID_TCP2_WRITE_QUEUE 5088
extern u_int32_t TCP2_WRITE_QUEUE;
int doWrite_TCP2_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP2_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP2_WRITE_QUEUE();
 
#define ID_TCP2_READ_QUEUE 5089
extern u_int32_t TCP2_READ_QUEUE;
int doWrite_TCP2_READ_QUEUE(u_int32_t value);
int addWrite_TCP2_READ_QUEUE(u_int32_t value);
int getStatus_TCP2_READ_QUEUE();
 
#define ID_TCP3_TYPE_PORT 5090
extern u_int32_t TCP3_TYPE_PORT;
int doWrite_TCP3_TYPE_PORT(u_int32_t value);
int addWrite_TCP3_TYPE_PORT(u_int32_t value);
int getStatus_TCP3_TYPE_PORT();
 
#define ID_TCP3_IP_ADDRESS 5091
extern u_int32_t TCP3_IP_ADDRESS;
int doWrite_TCP3_IP_ADDRESS(u_int32_t value);
int addWrite_TCP3_IP_ADDRESS(u_int32_t value);
int getStatus_TCP3_IP_ADDRESS();
 
#define ID_TCP3_STATUS 5092
extern u_int32_t TCP3_STATUS;
int doWrite_TCP3_STATUS(u_int32_t value);
int addWrite_TCP3_STATUS(u_int32_t value);
int getStatus_TCP3_STATUS();
 
#define ID_TCP3_READS 5093
extern u_int32_t TCP3_READS;
int doWrite_TCP3_READS(u_int32_t value);
int addWrite_TCP3_READS(u_int32_t value);
int getStatus_TCP3_READS();
 
#define ID_TCP3_WRITES 5094
extern u_int32_t TCP3_WRITES;
int doWrite_TCP3_WRITES(u_int32_t value);
int addWrite_TCP3_WRITES(u_int32_t value);
int getStatus_TCP3_WRITES();
 
#define ID_TCP3_TIMEOUTS 5095
extern u_int32_t TCP3_TIMEOUTS;
int doWrite_TCP3_TIMEOUTS(u_int32_t value);
int addWrite_TCP3_TIMEOUTS(u_int32_t value);
int getStatus_TCP3_TIMEOUTS();
 
#define ID_TCP3_COMM_ERRORS 5096
extern u_int32_t TCP3_COMM_ERRORS;
int doWrite_TCP3_COMM_ERRORS(u_int32_t value);
int addWrite_TCP3_COMM_ERRORS(u_int32_t value);
int getStatus_TCP3_COMM_ERRORS();
 
#define ID_TCP3_LAST_ERROR 5097
extern u_int32_t TCP3_LAST_ERROR;
int doWrite_TCP3_LAST_ERROR(u_int32_t value);
int addWrite_TCP3_LAST_ERROR(u_int32_t value);
int getStatus_TCP3_LAST_ERROR();
 
#define ID_TCP3_WRITE_QUEUE 5098
extern u_int32_t TCP3_WRITE_QUEUE;
int doWrite_TCP3_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP3_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP3_WRITE_QUEUE();
 
#define ID_TCP3_READ_QUEUE 5099
extern u_int32_t TCP3_READ_QUEUE;
int doWrite_TCP3_READ_QUEUE(u_int32_t value);
int addWrite_TCP3_READ_QUEUE(u_int32_t value);
int getStatus_TCP3_READ_QUEUE();
 
#define ID_TCP4_TYPE_PORT 5100
extern u_int32_t TCP4_TYPE_PORT;
int doWrite_TCP4_TYPE_PORT(u_int32_t value);
int addWrite_TCP4_TYPE_PORT(u_int32_t value);
int getStatus_TCP4_TYPE_PORT();
 
#define ID_TCP4_IP_ADDRESS 5101
extern u_int32_t TCP4_IP_ADDRESS;
int doWrite_TCP4_IP_ADDRESS(u_int32_t value);
int addWrite_TCP4_IP_ADDRESS(u_int32_t value);
int getStatus_TCP4_IP_ADDRESS();
 
#define ID_TCP4_STATUS 5102
extern u_int32_t TCP4_STATUS;
int doWrite_TCP4_STATUS(u_int32_t value);
int addWrite_TCP4_STATUS(u_int32_t value);
int getStatus_TCP4_STATUS();
 
#define ID_TCP4_READS 5103
extern u_int32_t TCP4_READS;
int doWrite_TCP4_READS(u_int32_t value);
int addWrite_TCP4_READS(u_int32_t value);
int getStatus_TCP4_READS();
 
#define ID_TCP4_WRITES 5104
extern u_int32_t TCP4_WRITES;
int doWrite_TCP4_WRITES(u_int32_t value);
int addWrite_TCP4_WRITES(u_int32_t value);
int getStatus_TCP4_WRITES();
 
#define ID_TCP4_TIMEOUTS 5105
extern u_int32_t TCP4_TIMEOUTS;
int doWrite_TCP4_TIMEOUTS(u_int32_t value);
int addWrite_TCP4_TIMEOUTS(u_int32_t value);
int getStatus_TCP4_TIMEOUTS();
 
#define ID_TCP4_COMM_ERRORS 5106
extern u_int32_t TCP4_COMM_ERRORS;
int doWrite_TCP4_COMM_ERRORS(u_int32_t value);
int addWrite_TCP4_COMM_ERRORS(u_int32_t value);
int getStatus_TCP4_COMM_ERRORS();
 
#define ID_TCP4_LAST_ERROR 5107
extern u_int32_t TCP4_LAST_ERROR;
int doWrite_TCP4_LAST_ERROR(u_int32_t value);
int addWrite_TCP4_LAST_ERROR(u_int32_t value);
int getStatus_TCP4_LAST_ERROR();
 
#define ID_TCP4_WRITE_QUEUE 5108
extern u_int32_t TCP4_WRITE_QUEUE;
int doWrite_TCP4_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP4_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP4_WRITE_QUEUE();
 
#define ID_TCP4_READ_QUEUE 5109
extern u_int32_t TCP4_READ_QUEUE;
int doWrite_TCP4_READ_QUEUE(u_int32_t value);
int addWrite_TCP4_READ_QUEUE(u_int32_t value);
int getStatus_TCP4_READ_QUEUE();
 
#define ID_TCP5_TYPE_PORT 5110
extern u_int32_t TCP5_TYPE_PORT;
int doWrite_TCP5_TYPE_PORT(u_int32_t value);
int addWrite_TCP5_TYPE_PORT(u_int32_t value);
int getStatus_TCP5_TYPE_PORT();
 
#define ID_TCP5_IP_ADDRESS 5111
extern u_int32_t TCP5_IP_ADDRESS;
int doWrite_TCP5_IP_ADDRESS(u_int32_t value);
int addWrite_TCP5_IP_ADDRESS(u_int32_t value);
int getStatus_TCP5_IP_ADDRESS();
 
#define ID_TCP5_STATUS 5112
extern u_int32_t TCP5_STATUS;
int doWrite_TCP5_STATUS(u_int32_t value);
int addWrite_TCP5_STATUS(u_int32_t value);
int getStatus_TCP5_STATUS();
 
#define ID_TCP5_READS 5113
extern u_int32_t TCP5_READS;
int doWrite_TCP5_READS(u_int32_t value);
int addWrite_TCP5_READS(u_int32_t value);
int getStatus_TCP5_READS();
 
#define ID_TCP5_WRITES 5114
extern u_int32_t TCP5_WRITES;
int doWrite_TCP5_WRITES(u_int32_t value);
int addWrite_TCP5_WRITES(u_int32_t value);
int getStatus_TCP5_WRITES();
 
#define ID_TCP5_TIMEOUTS 5115
extern u_int32_t TCP5_TIMEOUTS;
int doWrite_TCP5_TIMEOUTS(u_int32_t value);
int addWrite_TCP5_TIMEOUTS(u_int32_t value);
int getStatus_TCP5_TIMEOUTS();
 
#define ID_TCP5_COMM_ERRORS 5116
extern u_int32_t TCP5_COMM_ERRORS;
int doWrite_TCP5_COMM_ERRORS(u_int32_t value);
int addWrite_TCP5_COMM_ERRORS(u_int32_t value);
int getStatus_TCP5_COMM_ERRORS();
 
#define ID_TCP5_LAST_ERROR 5117
extern u_int32_t TCP5_LAST_ERROR;
int doWrite_TCP5_LAST_ERROR(u_int32_t value);
int addWrite_TCP5_LAST_ERROR(u_int32_t value);
int getStatus_TCP5_LAST_ERROR();
 
#define ID_TCP5_WRITE_QUEUE 5118
extern u_int32_t TCP5_WRITE_QUEUE;
int doWrite_TCP5_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP5_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP5_WRITE_QUEUE();
 
#define ID_TCP5_READ_QUEUE 5119
extern u_int32_t TCP5_READ_QUEUE;
int doWrite_TCP5_READ_QUEUE(u_int32_t value);
int addWrite_TCP5_READ_QUEUE(u_int32_t value);
int getStatus_TCP5_READ_QUEUE();
 
#define ID_TCP6_TYPE_PORT 5120
extern u_int32_t TCP6_TYPE_PORT;
int doWrite_TCP6_TYPE_PORT(u_int32_t value);
int addWrite_TCP6_TYPE_PORT(u_int32_t value);
int getStatus_TCP6_TYPE_PORT();
 
#define ID_TCP6_IP_ADDRESS 5121
extern u_int32_t TCP6_IP_ADDRESS;
int doWrite_TCP6_IP_ADDRESS(u_int32_t value);
int addWrite_TCP6_IP_ADDRESS(u_int32_t value);
int getStatus_TCP6_IP_ADDRESS();
 
#define ID_TCP6_STATUS 5122
extern u_int32_t TCP6_STATUS;
int doWrite_TCP6_STATUS(u_int32_t value);
int addWrite_TCP6_STATUS(u_int32_t value);
int getStatus_TCP6_STATUS();
 
#define ID_TCP6_READS 5123
extern u_int32_t TCP6_READS;
int doWrite_TCP6_READS(u_int32_t value);
int addWrite_TCP6_READS(u_int32_t value);
int getStatus_TCP6_READS();
 
#define ID_TCP6_WRITES 5124
extern u_int32_t TCP6_WRITES;
int doWrite_TCP6_WRITES(u_int32_t value);
int addWrite_TCP6_WRITES(u_int32_t value);
int getStatus_TCP6_WRITES();
 
#define ID_TCP6_TIMEOUTS 5125
extern u_int32_t TCP6_TIMEOUTS;
int doWrite_TCP6_TIMEOUTS(u_int32_t value);
int addWrite_TCP6_TIMEOUTS(u_int32_t value);
int getStatus_TCP6_TIMEOUTS();
 
#define ID_TCP6_COMM_ERRORS 5126
extern u_int32_t TCP6_COMM_ERRORS;
int doWrite_TCP6_COMM_ERRORS(u_int32_t value);
int addWrite_TCP6_COMM_ERRORS(u_int32_t value);
int getStatus_TCP6_COMM_ERRORS();
 
#define ID_TCP6_LAST_ERROR 5127
extern u_int32_t TCP6_LAST_ERROR;
int doWrite_TCP6_LAST_ERROR(u_int32_t value);
int addWrite_TCP6_LAST_ERROR(u_int32_t value);
int getStatus_TCP6_LAST_ERROR();
 
#define ID_TCP6_WRITE_QUEUE 5128
extern u_int32_t TCP6_WRITE_QUEUE;
int doWrite_TCP6_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP6_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP6_WRITE_QUEUE();
 
#define ID_TCP6_READ_QUEUE 5129
extern u_int32_t TCP6_READ_QUEUE;
int doWrite_TCP6_READ_QUEUE(u_int32_t value);
int addWrite_TCP6_READ_QUEUE(u_int32_t value);
int getStatus_TCP6_READ_QUEUE();
 
#define ID_TCP7_TYPE_PORT 5130
extern u_int32_t TCP7_TYPE_PORT;
int doWrite_TCP7_TYPE_PORT(u_int32_t value);
int addWrite_TCP7_TYPE_PORT(u_int32_t value);
int getStatus_TCP7_TYPE_PORT();
 
#define ID_TCP7_IP_ADDRESS 5131
extern u_int32_t TCP7_IP_ADDRESS;
int doWrite_TCP7_IP_ADDRESS(u_int32_t value);
int addWrite_TCP7_IP_ADDRESS(u_int32_t value);
int getStatus_TCP7_IP_ADDRESS();
 
#define ID_TCP7_STATUS 5132
extern u_int32_t TCP7_STATUS;
int doWrite_TCP7_STATUS(u_int32_t value);
int addWrite_TCP7_STATUS(u_int32_t value);
int getStatus_TCP7_STATUS();
 
#define ID_TCP7_READS 5133
extern u_int32_t TCP7_READS;
int doWrite_TCP7_READS(u_int32_t value);
int addWrite_TCP7_READS(u_int32_t value);
int getStatus_TCP7_READS();
 
#define ID_TCP7_WRITES 5134
extern u_int32_t TCP7_WRITES;
int doWrite_TCP7_WRITES(u_int32_t value);
int addWrite_TCP7_WRITES(u_int32_t value);
int getStatus_TCP7_WRITES();
 
#define ID_TCP7_TIMEOUTS 5135
extern u_int32_t TCP7_TIMEOUTS;
int doWrite_TCP7_TIMEOUTS(u_int32_t value);
int addWrite_TCP7_TIMEOUTS(u_int32_t value);
int getStatus_TCP7_TIMEOUTS();
 
#define ID_TCP7_COMM_ERRORS 5136
extern u_int32_t TCP7_COMM_ERRORS;
int doWrite_TCP7_COMM_ERRORS(u_int32_t value);
int addWrite_TCP7_COMM_ERRORS(u_int32_t value);
int getStatus_TCP7_COMM_ERRORS();
 
#define ID_TCP7_LAST_ERROR 5137
extern u_int32_t TCP7_LAST_ERROR;
int doWrite_TCP7_LAST_ERROR(u_int32_t value);
int addWrite_TCP7_LAST_ERROR(u_int32_t value);
int getStatus_TCP7_LAST_ERROR();
 
#define ID_TCP7_WRITE_QUEUE 5138
extern u_int32_t TCP7_WRITE_QUEUE;
int doWrite_TCP7_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP7_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP7_WRITE_QUEUE();
 
#define ID_TCP7_READ_QUEUE 5139
extern u_int32_t TCP7_READ_QUEUE;
int doWrite_TCP7_READ_QUEUE(u_int32_t value);
int addWrite_TCP7_READ_QUEUE(u_int32_t value);
int getStatus_TCP7_READ_QUEUE();
 
#define ID_TCP8_TYPE_PORT 5140
extern u_int32_t TCP8_TYPE_PORT;
int doWrite_TCP8_TYPE_PORT(u_int32_t value);
int addWrite_TCP8_TYPE_PORT(u_int32_t value);
int getStatus_TCP8_TYPE_PORT();
 
#define ID_TCP8_IP_ADDRESS 5141
extern u_int32_t TCP8_IP_ADDRESS;
int doWrite_TCP8_IP_ADDRESS(u_int32_t value);
int addWrite_TCP8_IP_ADDRESS(u_int32_t value);
int getStatus_TCP8_IP_ADDRESS();
 
#define ID_TCP8_STATUS 5142
extern u_int32_t TCP8_STATUS;
int doWrite_TCP8_STATUS(u_int32_t value);
int addWrite_TCP8_STATUS(u_int32_t value);
int getStatus_TCP8_STATUS();
 
#define ID_TCP8_READS 5143
extern u_int32_t TCP8_READS;
int doWrite_TCP8_READS(u_int32_t value);
int addWrite_TCP8_READS(u_int32_t value);
int getStatus_TCP8_READS();
 
#define ID_TCP8_WRITES 5144
extern u_int32_t TCP8_WRITES;
int doWrite_TCP8_WRITES(u_int32_t value);
int addWrite_TCP8_WRITES(u_int32_t value);
int getStatus_TCP8_WRITES();
 
#define ID_TCP8_TIMEOUTS 5145
extern u_int32_t TCP8_TIMEOUTS;
int doWrite_TCP8_TIMEOUTS(u_int32_t value);
int addWrite_TCP8_TIMEOUTS(u_int32_t value);
int getStatus_TCP8_TIMEOUTS();
 
#define ID_TCP8_COMM_ERRORS 5146
extern u_int32_t TCP8_COMM_ERRORS;
int doWrite_TCP8_COMM_ERRORS(u_int32_t value);
int addWrite_TCP8_COMM_ERRORS(u_int32_t value);
int getStatus_TCP8_COMM_ERRORS();
 
#define ID_TCP8_LAST_ERROR 5147
extern u_int32_t TCP8_LAST_ERROR;
int doWrite_TCP8_LAST_ERROR(u_int32_t value);
int addWrite_TCP8_LAST_ERROR(u_int32_t value);
int getStatus_TCP8_LAST_ERROR();
 
#define ID_TCP8_WRITE_QUEUE 5148
extern u_int32_t TCP8_WRITE_QUEUE;
int doWrite_TCP8_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP8_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP8_WRITE_QUEUE();
 
#define ID_TCP8_READ_QUEUE 5149
extern u_int32_t TCP8_READ_QUEUE;
int doWrite_TCP8_READ_QUEUE(u_int32_t value);
int addWrite_TCP8_READ_QUEUE(u_int32_t value);
int getStatus_TCP8_READ_QUEUE();
 
#define ID_TCP9_TYPE_PORT 5150
extern u_int32_t TCP9_TYPE_PORT;
int doWrite_TCP9_TYPE_PORT(u_int32_t value);
int addWrite_TCP9_TYPE_PORT(u_int32_t value);
int getStatus_TCP9_TYPE_PORT();
 
#define ID_TCP9_IP_ADDRESS 5151
extern u_int32_t TCP9_IP_ADDRESS;
int doWrite_TCP9_IP_ADDRESS(u_int32_t value);
int addWrite_TCP9_IP_ADDRESS(u_int32_t value);
int getStatus_TCP9_IP_ADDRESS();
 
#define ID_TCP9_STATUS 5152
extern u_int32_t TCP9_STATUS;
int doWrite_TCP9_STATUS(u_int32_t value);
int addWrite_TCP9_STATUS(u_int32_t value);
int getStatus_TCP9_STATUS();
 
#define ID_TCP9_READS 5153
extern u_int32_t TCP9_READS;
int doWrite_TCP9_READS(u_int32_t value);
int addWrite_TCP9_READS(u_int32_t value);
int getStatus_TCP9_READS();
 
#define ID_TCP9_WRITES 5154
extern u_int32_t TCP9_WRITES;
int doWrite_TCP9_WRITES(u_int32_t value);
int addWrite_TCP9_WRITES(u_int32_t value);
int getStatus_TCP9_WRITES();
 
#define ID_TCP9_TIMEOUTS 5155
extern u_int32_t TCP9_TIMEOUTS;
int doWrite_TCP9_TIMEOUTS(u_int32_t value);
int addWrite_TCP9_TIMEOUTS(u_int32_t value);
int getStatus_TCP9_TIMEOUTS();
 
#define ID_TCP9_COMM_ERRORS 5156
extern u_int32_t TCP9_COMM_ERRORS;
int doWrite_TCP9_COMM_ERRORS(u_int32_t value);
int addWrite_TCP9_COMM_ERRORS(u_int32_t value);
int getStatus_TCP9_COMM_ERRORS();
 
#define ID_TCP9_LAST_ERROR 5157
extern u_int32_t TCP9_LAST_ERROR;
int doWrite_TCP9_LAST_ERROR(u_int32_t value);
int addWrite_TCP9_LAST_ERROR(u_int32_t value);
int getStatus_TCP9_LAST_ERROR();
 
#define ID_TCP9_WRITE_QUEUE 5158
extern u_int32_t TCP9_WRITE_QUEUE;
int doWrite_TCP9_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP9_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP9_WRITE_QUEUE();
 
#define ID_TCP9_READ_QUEUE 5159
extern u_int32_t TCP9_READ_QUEUE;
int doWrite_TCP9_READ_QUEUE(u_int32_t value);
int addWrite_TCP9_READ_QUEUE(u_int32_t value);
int getStatus_TCP9_READ_QUEUE();
 
#define ID_NODE_01_DEV_NODE 5172
extern u_int32_t NODE_01_DEV_NODE;
int doWrite_NODE_01_DEV_NODE(u_int32_t value);
int addWrite_NODE_01_DEV_NODE(u_int32_t value);
int getStatus_NODE_01_DEV_NODE();
 
#define ID_NODE_01_STATUS 5173
extern u_int32_t NODE_01_STATUS;
int doWrite_NODE_01_STATUS(u_int32_t value);
int addWrite_NODE_01_STATUS(u_int32_t value);
int getStatus_NODE_01_STATUS();
 
#define ID_NODE_02_DEV_NODE 5174
extern u_int32_t NODE_02_DEV_NODE;
int doWrite_NODE_02_DEV_NODE(u_int32_t value);
int addWrite_NODE_02_DEV_NODE(u_int32_t value);
int getStatus_NODE_02_DEV_NODE();
 
#define ID_NODE_02_STATUS 5175
extern u_int32_t NODE_02_STATUS;
int doWrite_NODE_02_STATUS(u_int32_t value);
int addWrite_NODE_02_STATUS(u_int32_t value);
int getStatus_NODE_02_STATUS();
 
#define ID_NODE_03_DEV_NODE 5176
extern u_int32_t NODE_03_DEV_NODE;
int doWrite_NODE_03_DEV_NODE(u_int32_t value);
int addWrite_NODE_03_DEV_NODE(u_int32_t value);
int getStatus_NODE_03_DEV_NODE();
 
#define ID_NODE_03_STATUS 5177
extern u_int32_t NODE_03_STATUS;
int doWrite_NODE_03_STATUS(u_int32_t value);
int addWrite_NODE_03_STATUS(u_int32_t value);
int getStatus_NODE_03_STATUS();
 
#define ID_NODE_04_DEV_NODE 5178
extern u_int32_t NODE_04_DEV_NODE;
int doWrite_NODE_04_DEV_NODE(u_int32_t value);
int addWrite_NODE_04_DEV_NODE(u_int32_t value);
int getStatus_NODE_04_DEV_NODE();
 
#define ID_NODE_04_STATUS 5179
extern u_int32_t NODE_04_STATUS;
int doWrite_NODE_04_STATUS(u_int32_t value);
int addWrite_NODE_04_STATUS(u_int32_t value);
int getStatus_NODE_04_STATUS();
 
#define ID_NODE_05_DEV_NODE 5180
extern u_int32_t NODE_05_DEV_NODE;
int doWrite_NODE_05_DEV_NODE(u_int32_t value);
int addWrite_NODE_05_DEV_NODE(u_int32_t value);
int getStatus_NODE_05_DEV_NODE();
 
#define ID_NODE_05_STATUS 5181
extern u_int32_t NODE_05_STATUS;
int doWrite_NODE_05_STATUS(u_int32_t value);
int addWrite_NODE_05_STATUS(u_int32_t value);
int getStatus_NODE_05_STATUS();
 
#define ID_NODE_06_DEV_NODE 5182
extern u_int32_t NODE_06_DEV_NODE;
int doWrite_NODE_06_DEV_NODE(u_int32_t value);
int addWrite_NODE_06_DEV_NODE(u_int32_t value);
int getStatus_NODE_06_DEV_NODE();
 
#define ID_NODE_06_STATUS 5183
extern u_int32_t NODE_06_STATUS;
int doWrite_NODE_06_STATUS(u_int32_t value);
int addWrite_NODE_06_STATUS(u_int32_t value);
int getStatus_NODE_06_STATUS();
 
#define ID_NODE_07_DEV_NODE 5184
extern u_int32_t NODE_07_DEV_NODE;
int doWrite_NODE_07_DEV_NODE(u_int32_t value);
int addWrite_NODE_07_DEV_NODE(u_int32_t value);
int getStatus_NODE_07_DEV_NODE();
 
#define ID_NODE_07_STATUS 5185
extern u_int32_t NODE_07_STATUS;
int doWrite_NODE_07_STATUS(u_int32_t value);
int addWrite_NODE_07_STATUS(u_int32_t value);
int getStatus_NODE_07_STATUS();
 
#define ID_NODE_08_DEV_NODE 5186
extern u_int32_t NODE_08_DEV_NODE;
int doWrite_NODE_08_DEV_NODE(u_int32_t value);
int addWrite_NODE_08_DEV_NODE(u_int32_t value);
int getStatus_NODE_08_DEV_NODE();
 
#define ID_NODE_08_STATUS 5187
extern u_int32_t NODE_08_STATUS;
int doWrite_NODE_08_STATUS(u_int32_t value);
int addWrite_NODE_08_STATUS(u_int32_t value);
int getStatus_NODE_08_STATUS();
 
#define ID_NODE_09_DEV_NODE 5188
extern u_int32_t NODE_09_DEV_NODE;
int doWrite_NODE_09_DEV_NODE(u_int32_t value);
int addWrite_NODE_09_DEV_NODE(u_int32_t value);
int getStatus_NODE_09_DEV_NODE();
 
#define ID_NODE_09_STATUS 5189
extern u_int32_t NODE_09_STATUS;
int doWrite_NODE_09_STATUS(u_int32_t value);
int addWrite_NODE_09_STATUS(u_int32_t value);
int getStatus_NODE_09_STATUS();
 
#define ID_NODE_10_DEV_NODE 5190
extern u_int32_t NODE_10_DEV_NODE;
int doWrite_NODE_10_DEV_NODE(u_int32_t value);
int addWrite_NODE_10_DEV_NODE(u_int32_t value);
int getStatus_NODE_10_DEV_NODE();
 
#define ID_NODE_10_STATUS 5191
extern u_int32_t NODE_10_STATUS;
int doWrite_NODE_10_STATUS(u_int32_t value);
int addWrite_NODE_10_STATUS(u_int32_t value);
int getStatus_NODE_10_STATUS();
 
#define ID_NODE_11_DEV_NODE 5192
extern u_int32_t NODE_11_DEV_NODE;
int doWrite_NODE_11_DEV_NODE(u_int32_t value);
int addWrite_NODE_11_DEV_NODE(u_int32_t value);
int getStatus_NODE_11_DEV_NODE();
 
#define ID_NODE_11_STATUS 5193
extern u_int32_t NODE_11_STATUS;
int doWrite_NODE_11_STATUS(u_int32_t value);
int addWrite_NODE_11_STATUS(u_int32_t value);
int getStatus_NODE_11_STATUS();
 
#define ID_NODE_12_DEV_NODE 5194
extern u_int32_t NODE_12_DEV_NODE;
int doWrite_NODE_12_DEV_NODE(u_int32_t value);
int addWrite_NODE_12_DEV_NODE(u_int32_t value);
int getStatus_NODE_12_DEV_NODE();
 
#define ID_NODE_12_STATUS 5195
extern u_int32_t NODE_12_STATUS;
int doWrite_NODE_12_STATUS(u_int32_t value);
int addWrite_NODE_12_STATUS(u_int32_t value);
int getStatus_NODE_12_STATUS();
 
#define ID_NODE_13_DEV_NODE 5196
extern u_int32_t NODE_13_DEV_NODE;
int doWrite_NODE_13_DEV_NODE(u_int32_t value);
int addWrite_NODE_13_DEV_NODE(u_int32_t value);
int getStatus_NODE_13_DEV_NODE();
 
#define ID_NODE_13_STATUS 5197
extern u_int32_t NODE_13_STATUS;
int doWrite_NODE_13_STATUS(u_int32_t value);
int addWrite_NODE_13_STATUS(u_int32_t value);
int getStatus_NODE_13_STATUS();
 
#define ID_NODE_14_DEV_NODE 5198
extern u_int32_t NODE_14_DEV_NODE;
int doWrite_NODE_14_DEV_NODE(u_int32_t value);
int addWrite_NODE_14_DEV_NODE(u_int32_t value);
int getStatus_NODE_14_DEV_NODE();
 
#define ID_NODE_14_STATUS 5199
extern u_int32_t NODE_14_STATUS;
int doWrite_NODE_14_STATUS(u_int32_t value);
int addWrite_NODE_14_STATUS(u_int32_t value);
int getStatus_NODE_14_STATUS();
 
#define ID_NODE_15_DEV_NODE 5200
extern u_int32_t NODE_15_DEV_NODE;
int doWrite_NODE_15_DEV_NODE(u_int32_t value);
int addWrite_NODE_15_DEV_NODE(u_int32_t value);
int getStatus_NODE_15_DEV_NODE();
 
#define ID_NODE_15_STATUS 5201
extern u_int32_t NODE_15_STATUS;
int doWrite_NODE_15_STATUS(u_int32_t value);
int addWrite_NODE_15_STATUS(u_int32_t value);
int getStatus_NODE_15_STATUS();
 
#define ID_NODE_16_DEV_NODE 5202
extern u_int32_t NODE_16_DEV_NODE;
int doWrite_NODE_16_DEV_NODE(u_int32_t value);
int addWrite_NODE_16_DEV_NODE(u_int32_t value);
int getStatus_NODE_16_DEV_NODE();
 
#define ID_NODE_16_STATUS 5203
extern u_int32_t NODE_16_STATUS;
int doWrite_NODE_16_STATUS(u_int32_t value);
int addWrite_NODE_16_STATUS(u_int32_t value);
int getStatus_NODE_16_STATUS();
 
#define ID_PLC_FWrevision 5300
extern u_int16_t PLC_FWrevision;
int doWrite_PLC_FWrevision(u_int16_t value);
int addWrite_PLC_FWrevision(u_int16_t value);
int getStatus_PLC_FWrevision();
 
#define ID_PLC_HWconfig 5301
extern u_int16_t PLC_HWconfig;
int doWrite_PLC_HWconfig(u_int16_t value);
int addWrite_PLC_HWconfig(u_int16_t value);
int getStatus_PLC_HWconfig();
 
#define ID_PLC_DigDir_1 5302
extern int PLC_DigDir_1;
int doWrite_PLC_DigDir_1(int value);
int addWrite_PLC_DigDir_1(int value);
int getStatus_PLC_DigDir_1();
 
#define ID_PLC_DigDir_2 5303
extern int PLC_DigDir_2;
int doWrite_PLC_DigDir_2(int value);
int addWrite_PLC_DigDir_2(int value);
int getStatus_PLC_DigDir_2();
 
#define ID_PLC_DigDir_3 5304
extern int PLC_DigDir_3;
int doWrite_PLC_DigDir_3(int value);
int addWrite_PLC_DigDir_3(int value);
int getStatus_PLC_DigDir_3();
 
#define ID_PLC_DigDir_4 5305
extern int PLC_DigDir_4;
int doWrite_PLC_DigDir_4(int value);
int addWrite_PLC_DigDir_4(int value);
int getStatus_PLC_DigDir_4();
 
#define ID_PLC_DigDir_5 5306
extern int PLC_DigDir_5;
int doWrite_PLC_DigDir_5(int value);
int addWrite_PLC_DigDir_5(int value);
int getStatus_PLC_DigDir_5();
 
#define ID_PLC_DigDir_6 5307
extern int PLC_DigDir_6;
int doWrite_PLC_DigDir_6(int value);
int addWrite_PLC_DigDir_6(int value);
int getStatus_PLC_DigDir_6();
 
#define ID_PLC_DigDir_7 5308
extern int PLC_DigDir_7;
int doWrite_PLC_DigDir_7(int value);
int addWrite_PLC_DigDir_7(int value);
int getStatus_PLC_DigDir_7();
 
#define ID_PLC_DigDir_8 5309
extern int PLC_DigDir_8;
int doWrite_PLC_DigDir_8(int value);
int addWrite_PLC_DigDir_8(int value);
int getStatus_PLC_DigDir_8();
 
#define ID_PLC_AnInConf_1 5310
extern u_int16_t PLC_AnInConf_1;
int doWrite_PLC_AnInConf_1(u_int16_t value);
int addWrite_PLC_AnInConf_1(u_int16_t value);
int getStatus_PLC_AnInConf_1();
 
#define ID_PLC_AnInConf_2 5311
extern u_int16_t PLC_AnInConf_2;
int doWrite_PLC_AnInConf_2(u_int16_t value);
int addWrite_PLC_AnInConf_2(u_int16_t value);
int getStatus_PLC_AnInConf_2();
 
#define ID_PLC_AnOutConf_1 5312
extern u_int16_t PLC_AnOutConf_1;
int doWrite_PLC_AnOutConf_1(u_int16_t value);
int addWrite_PLC_AnOutConf_1(u_int16_t value);
int getStatus_PLC_AnOutConf_1();
 
#define ID_PLC_DigIn_1 5313
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int addWrite_PLC_DigIn_1(int value);
int getStatus_PLC_DigIn_1();
 
#define ID_PLC_DigIn_2 5314
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int addWrite_PLC_DigIn_2(int value);
int getStatus_PLC_DigIn_2();
 
#define ID_PLC_DigIn_3 5315
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int addWrite_PLC_DigIn_3(int value);
int getStatus_PLC_DigIn_3();
 
#define ID_PLC_DigIn_4 5316
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int addWrite_PLC_DigIn_4(int value);
int getStatus_PLC_DigIn_4();
 
#define ID_PLC_DigIn_5 5317
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int addWrite_PLC_DigIn_5(int value);
int getStatus_PLC_DigIn_5();
 
#define ID_PLC_DigIn_6 5318
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int addWrite_PLC_DigIn_6(int value);
int getStatus_PLC_DigIn_6();
 
#define ID_PLC_DigIn_7 5319
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int addWrite_PLC_DigIn_7(int value);
int getStatus_PLC_DigIn_7();
 
#define ID_PLC_DigIn_8 5320
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int addWrite_PLC_DigIn_8(int value);
int getStatus_PLC_DigIn_8();
 
#define ID_PLC_DigIn_9 5321
extern int PLC_DigIn_9;
int doWrite_PLC_DigIn_9(int value);
int addWrite_PLC_DigIn_9(int value);
int getStatus_PLC_DigIn_9();
 
#define ID_PLC_DigIn_10 5322
extern int PLC_DigIn_10;
int doWrite_PLC_DigIn_10(int value);
int addWrite_PLC_DigIn_10(int value);
int getStatus_PLC_DigIn_10();
 
#define ID_PLC_DigIn_11 5323
extern int PLC_DigIn_11;
int doWrite_PLC_DigIn_11(int value);
int addWrite_PLC_DigIn_11(int value);
int getStatus_PLC_DigIn_11();
 
#define ID_PLC_DigIn_12 5324
extern int PLC_DigIn_12;
int doWrite_PLC_DigIn_12(int value);
int addWrite_PLC_DigIn_12(int value);
int getStatus_PLC_DigIn_12();
 
#define ID_PLC_AnIn_1 5325
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int addWrite_PLC_AnIn_1(int16_t value);
int getStatus_PLC_AnIn_1();
 
#define ID_PLC_AnIn_2 5326
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int addWrite_PLC_AnIn_2(int16_t value);
int getStatus_PLC_AnIn_2();
 
#define ID_PLC_Tamb 5327
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int addWrite_PLC_Tamb(int16_t value);
int getStatus_PLC_Tamb();
 
#define ID_PLC_Encoder 5328
extern u_int32_t PLC_Encoder;
int doWrite_PLC_Encoder(u_int32_t value);
int addWrite_PLC_Encoder(u_int32_t value);
int getStatus_PLC_Encoder();
 
#define ID_PLC_DigOut_1 5329
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int addWrite_PLC_DigOut_1(int value);
int getStatus_PLC_DigOut_1();
 
#define ID_PLC_DigOut_2 5330
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int addWrite_PLC_DigOut_2(int value);
int getStatus_PLC_DigOut_2();
 
#define ID_PLC_DigOut_3 5331
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int addWrite_PLC_DigOut_3(int value);
int getStatus_PLC_DigOut_3();
 
#define ID_PLC_DigOut_4 5332
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int addWrite_PLC_DigOut_4(int value);
int getStatus_PLC_DigOut_4();
 
#define ID_PLC_DigOut_5 5333
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int addWrite_PLC_DigOut_5(int value);
int getStatus_PLC_DigOut_5();
 
#define ID_PLC_DigOut_6 5334
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int addWrite_PLC_DigOut_6(int value);
int getStatus_PLC_DigOut_6();
 
#define ID_PLC_DigOut_7 5335
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int addWrite_PLC_DigOut_7(int value);
int getStatus_PLC_DigOut_7();
 
#define ID_PLC_DigOut_8 5336
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int addWrite_PLC_DigOut_8(int value);
int getStatus_PLC_DigOut_8();
 
#define ID_PLC_AnOut_1 5337
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int addWrite_PLC_AnOut_1(int16_t value);
int getStatus_PLC_AnOut_1();
 
#define ID_PLC_EncEnable 5338
extern u_int16_t PLC_EncEnable;
int doWrite_PLC_EncEnable(u_int16_t value);
int addWrite_PLC_EncEnable(u_int16_t value);
int getStatus_PLC_EncEnable();
 
#define ID_PLC_EncoderReset 5339
extern u_int16_t PLC_EncoderReset;
int doWrite_PLC_EncoderReset(u_int16_t value);
int addWrite_PLC_EncoderReset(u_int16_t value);
int getStatus_PLC_EncoderReset();
 
#define ID_PLC_Reserved_16 5340
extern u_int16_t PLC_Reserved_16;
int doWrite_PLC_Reserved_16(u_int16_t value);
int addWrite_PLC_Reserved_16(u_int16_t value);
int getStatus_PLC_Reserved_16();
 
#define ID_PLC_Reserved_17 5341
extern u_int16_t PLC_Reserved_17;
int doWrite_PLC_Reserved_17(u_int16_t value);
int addWrite_PLC_Reserved_17(u_int16_t value);
int getStatus_PLC_Reserved_17();
 
#define ID_PLC_Reserved_18 5342
extern u_int16_t PLC_Reserved_18;
int doWrite_PLC_Reserved_18(u_int16_t value);
int addWrite_PLC_Reserved_18(u_int16_t value);
int getStatus_PLC_Reserved_18();
 
#define ID_PLC_Reserved_19 5343
extern u_int16_t PLC_Reserved_19;
int doWrite_PLC_Reserved_19(u_int16_t value);
int addWrite_PLC_Reserved_19(u_int16_t value);
int getStatus_PLC_Reserved_19();
 
#define ID_PLC_Heartbeat 5344
extern u_int16_t PLC_Heartbeat;
int doWrite_PLC_Heartbeat(u_int16_t value);
int addWrite_PLC_Heartbeat(u_int16_t value);
int getStatus_PLC_Heartbeat();
 
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
 
#define ID_PLC_Version 5394
extern u_int16_t PLC_Version;
int doWrite_PLC_Version(u_int16_t value);
int addWrite_PLC_Version(u_int16_t value);
int getStatus_PLC_Version();
 
#define ID_PLC_EngineStatus 5395
extern u_int16_t PLC_EngineStatus;
int doWrite_PLC_EngineStatus(u_int16_t value);
int addWrite_PLC_EngineStatus(u_int16_t value);
int getStatus_PLC_EngineStatus();
 
#define ID_PLC_ResetValues 5396
extern int PLC_ResetValues;
int doWrite_PLC_ResetValues(int value);
int addWrite_PLC_ResetValues(int value);
int getStatus_PLC_ResetValues();
 
#define ID_PLC_buzzerOn 5397
extern int PLC_buzzerOn;
int doWrite_PLC_buzzerOn(int value);
int addWrite_PLC_buzzerOn(int value);
int getStatus_PLC_buzzerOn();
 
#ifdef __cplusplus
}
#endif
#endif
