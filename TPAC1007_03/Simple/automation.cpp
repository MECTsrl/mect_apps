#include "crosstable.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_AnInConf_1(2); // 2 = [V] 0..10
    doWrite_PLC_AnInConf_2(2); // 2 = [V] 0..10
    doWrite_PLC_AnOutConf_1(2); // 2 = [V] 0..10
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

