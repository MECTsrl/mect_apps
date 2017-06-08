#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

void setup(void);
void loop(void);


#include "page300.h"
void setTheWidget(page300 *w);

#endif // AUTOMATION_H

