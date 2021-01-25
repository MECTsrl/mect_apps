#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    // FastIO setup
    doWrite_PLC_FastIO_Ena(0x000000FF);
    doWrite_PLC_FastIO_Dir(0x000000F0);

    // Audio setup
    system("modprobe snd_soc_mxs_devb");
    system("amixer -c 0 -- sset 'Playback' 160");
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

