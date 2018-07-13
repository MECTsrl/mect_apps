#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_FastIO_Ena(0x000000FF);
    doWrite_PLC_FastIO_Dir(0x000000F0);
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

