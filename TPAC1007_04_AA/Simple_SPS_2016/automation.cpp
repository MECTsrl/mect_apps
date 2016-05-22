#include "crosstable.h"

static int counter;

/* put here the initalization */
void setup(void)
{
    counter = 0;
    doWrite_PLC_DigDir_1(1); doWrite_PLC_DigOut_1(1);
    doWrite_PLC_DigDir_2(1); doWrite_PLC_DigOut_2(0);
    doWrite_PLC_DigDir_3(1); doWrite_PLC_DigOut_3(1);
    doWrite_PLC_DigDir_4(1); doWrite_PLC_DigOut_4(0);

    doWrite_PLC_DigDir_5(0);
    doWrite_PLC_DigDir_6(0);
    doWrite_PLC_DigDir_7(0);
    doWrite_PLC_DigDir_8(0);

    doWrite_PLC_AnInConf_1(2);
    doWrite_PLC_AnInConf_2(2);

    doWrite_PLC_AnOutConf_1(2); doWrite_PLC_AnOut_1( 500);
    doWrite_PLC_AnOutConf_2(1); doWrite_PLC_AnOut_2(1200);
    doWrite_PLC_AnOutConf_3(2); doWrite_PLC_AnOut_3(1000);
    doWrite_PLC_AnOutConf_4(2); doWrite_PLC_AnOut_4(1000);
    doWrite_PLC_AnOutConf_4(3); doWrite_PLC_AnOut_4(  50);
}

/* put here the operation made every 100ms */
void loop(void)
{
    ++counter;
    if (counter % 10 == 0) {

        if (PLC_AnOutConf_1 != 2) doWrite_PLC_AnOutConf_1(2);
        doWrite_PLC_AnOut_1((000 + (PLC_AnOut_1 - 0 + 100)) % 1100);

        if (PLC_AnOutConf_2 != 1) doWrite_PLC_AnOutConf_2(1);
        doWrite_PLC_AnOut_2((400 + (PLC_AnOut_2 - 4 + 100)) % 2100);

        if (PLC_AnOutConf_3 != 2) doWrite_PLC_AnOutConf_3(2);
        doWrite_PLC_AnOut_3((000 + (PLC_AnOut_3 - 0 + 100)) % 1100);

        if (PLC_AnOutConf_4 != 3) doWrite_PLC_AnOutConf_4(3);
        doWrite_PLC_AnOut_4((000 + (PLC_AnOut_4 - 0 + 10)) % 110);
    }

}

