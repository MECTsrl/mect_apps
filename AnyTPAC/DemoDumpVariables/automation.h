#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

void setup(void);
void loop(void);

bool dumpVariables(int nStart, int nVariables, QString &szFile2Dump);
bool restoreVariables(int nStart, int nVariables, QString &szFile2Restore);

#endif // AUTOMATION_H

