#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_timeWin(10.0);
    logStart();
}

/* put here the operation made every 100ms */
void loop(void)
{
}
