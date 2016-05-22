#include "crosstable.h"
#include <math.h>

static int counter;

/* put here the initalization */
void setup(void)
{
    counter = 0;
}

/* put here the operation made every 100ms */
void loop(void)
{
    ++counter;

    if (counter % 10 == 0 && CH0_NETRUN) {

        if (PLC_DigOut_1 != 1) doWrite_PLC_DigOut_1 (1);
        if (PLC_DigOut_2 != 1) doWrite_PLC_DigOut_2 (1);
        if (PLC_DigOut_4 != 1) doWrite_PLC_DigOut_4 (1);
        if (PLC_DigOut_8 != 1) doWrite_PLC_DigOut_8 (1);
        if (PLC_DigOut_12!= 1) doWrite_PLC_DigOut_12(1);
        if (PLC_AnInConf != 0x3322) doWrite_PLC_AnInConf(0x3322);
        if (PLC_AnOutConf != 0x12) doWrite_PLC_AnOutConf(0x12);
        doWrite_PLC_AnOut_1((000 + (PLC_AnOut_1 - 0 + 100)) % 1100);
        doWrite_PLC_AnOut_2((400 + (PLC_AnOut_2 - 4 + 100)) % 2100);
    }
}
