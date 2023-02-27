#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"
#include "serialreader.h"

#define THE_DEVICE "/dev/ttyUSB1"


extern SerialReader *tagReader;


void setup(void);
void loop(void);


#endif // AUTOMATION_H

