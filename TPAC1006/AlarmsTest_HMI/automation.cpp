#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    
}

/* put here the operation made every 100ms */
void loop(void)
{
    if (CH0_NETGOOD && PLC_AnInConf != 0x2222) {
        doWrite_PLC_AnInConf(0x2222);
    }
}

