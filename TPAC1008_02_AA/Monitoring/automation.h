#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

void setup(void);
void loop(void);

bool isUP_wlan0(void);
bool isUP_ppp0(void);
bool isUP_tun0(void);

#endif // AUTOMATION_H

