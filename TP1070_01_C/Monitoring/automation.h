#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

void setup(void);
void loop(void);

// vedi plc/Resource1.cst

#define ALARM_STATUS_ZERO     0 // not configured yet
#define ALARM_STATUS_IDLE     1
#define ALARM_STATUS_ARMED    2
#define ALARM_STATUS_ENABLED  3
#define ALARM_STATUS_RINGING  4
#define ALARM_STATUS_MUTED    5

                               //BVRGBVRG
                               //AAAABBBB
#define ALARM_CONFIG_ZERO      0x00000000 // not configured yet
#define ALARM_CONFIG_ALL       0xffffffff // all DigIn
#define ALARM_CONFIG_INSTALLED 0xffff6bbf // only installed sensors
#define ALARM_CONFIG_NOIR_P0P1 0xfbfe6bbf // no i.r. sensors p0 and p1
#define ALARM_CONFIG_NOIR_PALL 0xebfe6bbf // no i.r. sensors p0,p1 and p-1
#define ALARM_CONFIG_LASTINDEX 4

#endif // AUTOMATION_H

