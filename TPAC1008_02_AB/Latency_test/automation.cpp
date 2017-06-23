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
    if (! configured && CH0_NETGOOD)
    {
        // analog inputs configuration
        // analog inputs filtering
        // in PLC application

        // default graph window
        doWrite_PLC_timeWin(15);

        // enable logging
        logStart();

        // ok, configured
        configured = true;
    }
}

bool isUP_wlan0(void)
{
    return system("ip addr show dev wlan0 2>&1 | fgrep -q ',UP,'") == 0;
}

bool isUP_ppp0(void)
{
    return system("ip addr show dev ppp0 2>&1 | fgrep -q ',UP,'") == 0;
}

bool isUP_tun0(void)
{
    return system("ip addr show dev tun0 2>&1 | fgrep -q ',UP,'") == 0;
}
