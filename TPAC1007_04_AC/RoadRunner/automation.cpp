#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_DigDir_1(1);    // 1 = output
    doWrite_PLC_DigDir_2(1);    // 1 = output
    doWrite_PLC_DigDir_3(1);    // 1 = output
    doWrite_PLC_DigDir_4(1);    // 1 = output

    doWrite_PLC_DigDir_5(0);    // 0 = input
    doWrite_PLC_DigDir_6(0);    // 0 = input
    doWrite_PLC_DigDir_7(0);    // 0 = input
    doWrite_PLC_DigDir_8(1);    // 0 = output
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

