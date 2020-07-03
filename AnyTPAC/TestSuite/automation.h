#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

void setup(void);
void loop(void);

#define STATUS_ZERO 0
#define STATUS_IDLE 1
#define STATUS_RUNNING 2
#define STATUS_DONE 3

#define LOG_NOTHING      0
#define LOG_FAILED_TESTS 1
#define LOG_PASSED_TESTS 2

#define TEST_DISABLED   0
#define TEST_TESTING    1
#define TEST_PASSED     2
#define TEST_FAILED     3

#endif // AUTOMATION_H

