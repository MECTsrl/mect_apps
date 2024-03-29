#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Start-up code
    doWrite_PLC_AnInConf_1(2);  // 2 = [V] 0..10
    doWrite_PLC_AnInConf_2(2);  // 2 = [V] 0..10

    doWrite_PLC_EncoderStart(2);// 2 = Counter

    doWrite_PLC_AnOutConf_1(2); // 2 = [V] 0..10
    doWrite_PLC_AnOut_1(333);   // 3,33 V

    doWrite_PLC_DigDir_1(1);    // 1 = output
    doWrite_PLC_DigDir_2(1);    // 1 = output
    doWrite_PLC_DigDir_3(1);    // 1 = output
    doWrite_PLC_DigDir_4(1);    // 1 = output

    doWrite_PLC_DigDir_5(0);    // 0 = input
    doWrite_PLC_DigDir_6(0);    // 0 = input
    doWrite_PLC_DigDir_7(0);    // 0 = input
    doWrite_PLC_DigDir_8(0);    // 0 = input
}

/* put here the operation made every 100ms */
void loop(void)
{

}

