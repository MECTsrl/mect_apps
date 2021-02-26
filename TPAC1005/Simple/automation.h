#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

#define USB_UNPLUGGED           0
#define USB_INSERTED            1

#define SDCARD_EMPTY            0
#define SDCARD_INSERTED         1



void setup(void);
void loop(void);
void *keyboardThread(void *arg);

void        playBuzzer(u_int8_t nReplies, u_int8_t nOffTime, u_int8_t nOnTime, u_int8_t nVolume);
void        hwkeyPressed(int nKey);
void        hwkeyReleased(int nKey);

#endif // AUTOMATION_H

