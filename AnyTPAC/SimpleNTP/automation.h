#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

void setup(void);
void loop(void);

// -------------------------------------------------------------------------

#include "page100.h"

void syncTime(page100 *pagePtr);

// -------------------------------------------------------------------------

#endif // AUTOMATION_H

