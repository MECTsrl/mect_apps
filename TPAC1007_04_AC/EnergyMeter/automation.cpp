#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_timeWin(300);
    logStart();
}

/* put here the operation made every 100ms */
void loop(void)
{
    if (P > Pmax) {
        doWrite_Pmax(P);
    }
}

