#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_timeWin(300);

    doWrite_XX_AnInConf_1(0x07);// [°C] PT100R
    doWrite_XX_AnInConf_2(0x07);// [°C] PT100R

    doWrite_XX_AnInConf_A(0x0777);// [°C] PT100R
    doWrite_XX_AnInConf_B(0x0777);// [°C] PT100R
    doWrite_XX_AnInConf_C(0x0777);// [°C] PT100R

    doWrite_XX_DigDir_1(0); // input ASPEC PHEV
    doWrite_XX_DigDir_2(0); // input ASPEC DEUMIDIFICATORE
    doWrite_XX_DigDir_3(0); // input ASPEC LAVANDERIA
    doWrite_XX_DigDir_4(0); // input ASPEC PUFFER

    doWrite_XX_DigDir_5(1); // output BYPASS ASPEC PHEV
    doWrite_XX_DigDir_6(1); // output BYPASS DEUMIDIFICATORE
    doWrite_XX_DigDir_7(1); // output BYPASS LAVANDERIA
    doWrite_XX_DigDir_8(1); // output BYPASS PUFFER
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

