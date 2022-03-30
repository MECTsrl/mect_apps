#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

void setup(void);
void loop(void);

u_int32_t getMSVersion();   // get MS Version (before 3.3.12)

#endif // AUTOMATION_H

