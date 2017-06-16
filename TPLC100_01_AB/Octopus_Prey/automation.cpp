#include "crosstable.h"
#include "automation.h"

static bool configured;

/* put here the initalization */
void setup(void)
{
    configured = false;
}

/* put here the operation made every 100ms */
void loop(void)
{
    if (! configured && CH0_NETGOOD) {

        doWrite_PLC_DigOutEn_1(1); // output enable
        doWrite_PLC_DigOutEn_2(1); // output enable
        doWrite_PLC_DigOutEn_3(1); // output enable
        doWrite_PLC_DigOutEn_4(1); // output enable
        doWrite_PLC_DigOutEn_5(1); // output enable
        doWrite_PLC_DigOutEn_6(1); // output enable
        doWrite_PLC_DigOutEn_7(1); // output enable
        doWrite_PLC_DigOutEn_8(1); // output enable

        doWrite_PLC_AnInConf_1(0x32); // 0..10 V
        doWrite_PLC_AnInConf_2(0x32); // 0..10 V
        doWrite_PLC_AnInConf_3(0x32); // 0..10 V
        doWrite_PLC_AnInConf_4(0x32); // 0..10 V

        doWrite_PLC_AnInConf_5(0x16); // PT100 (E)
        doWrite_PLC_AnInConf_6(0x16); // PT100 (E)
        doWrite_PLC_AnInConf_7(0x16); // PT100 (E)
        doWrite_PLC_AnInConf_8(0x16); // PT100 (E)
        doWrite_PLC_AnInConf_9(0x16); // PT100 (E)
        doWrite_PLC_AnInConf_10(0x16); // PT100 (E)
        doWrite_PLC_AnInConf_11(0x16); // PT100 (E)
        doWrite_PLC_AnInConf_12(0x16); // PT100 (E)

        doWrite_PLC_AnOutConf_1(0x02); // 0..10 V
        doWrite_PLC_AnOutConf_2(0x02); // 0..10 V

        configured = true;
    }
}

