#include "crosstable.h"
#include "automation.h"

/* put here the initialization */
void setup(void)
{
    doWrite_PLC_AnInConf_1(1);
    doWrite_PLC_AnInConf_2(2);

    doWrite_PLC_AnOutConf_1(2);
    doWrite_PLC_AnOut_1(220);



    doWrite_PLC_DigDir_1(1);
    doWrite_PLC_DigDir_2(1);
    doWrite_PLC_DigDir_3(1);
    doWrite_PLC_DigDir_4(1);

    doWrite_PLC_DigDir_5(0);
    doWrite_PLC_DigDir_6(0);
    doWrite_PLC_DigDir_7(0);
    doWrite_PLC_DigDir_8(0);
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

