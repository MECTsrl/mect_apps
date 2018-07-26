#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    system("modprobe snd_soc_mxs_devb");
    system("amixer -c 0 -- sset 'Playback' 160");
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

