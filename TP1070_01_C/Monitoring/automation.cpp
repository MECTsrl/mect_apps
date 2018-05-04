#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_timeWin(300);

    doWrite_XX_AnInConf_1(0x07);// [°C] PT100R
    doWrite_XX_AnInConf_2(0x07);// [°C] PT100R

    doWrite_XX_AnInConf_A(0x7777);// [°C] PT100R
    doWrite_XX_AnInConf_B(0x7777);// [°C] PT100R
    doWrite_XX_AnInConf_C(0x7777);// [°C] PT100R
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

