#include "crosstable.h"
/* Defines logStart() */
#include "hmi_logger.h"

/* put here the initalization */
void setup(void)
{
    logStart();

    /* RTU */
    doWrite_RTU_ConfAnIn_1(0x2);
    doWrite_RTU_ConfAnIn_2(0x2);
    doWrite_RTU_ConfDigIn_3(0);
    doWrite_RTU_ConfDigOut_4(1);
}

/* put here the operation made every 100ms */
void loop(void)
{
    /* Local */
    if (CH0_NETGOOD) {
        if (PLC_AnInConf != 0x22)
            doWrite_PLC_AnInConf(0x22);
    }
}

