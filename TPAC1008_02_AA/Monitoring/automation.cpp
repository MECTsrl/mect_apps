#include "crosstable.h"
#include "automation.h"

#define PT100CONF 7 // PT100_R
#define PT100FILT 64 // sample filtering

static bool configured;

void setup(void)
{
    doWrite_PLC_HMI_Version(5678); // v5.678
    configured = false;
}

void loop(void)
{
    if (! configured && CH0_NETGOOD)
    {
        // analog inputs configuration
        doWrite_PLC_AnInConf_1(PT100CONF);
        doWrite_PLC_AnInConf_2(PT100CONF);
        doWrite_PLC_AnInConf_3(PT100CONF);
        doWrite_PLC_AnInConf_4(PT100CONF);

        // analog inputs filtering
        doWrite_PLC_FiltAnIn_1(PT100FILT);
        doWrite_PLC_FiltAnIn_2(PT100FILT);
        doWrite_PLC_FiltAnIn_3(PT100FILT);
        doWrite_PLC_FiltAnIn_4(PT100FILT);

        // default graph window
        doWrite_PLC_timeWin(120);

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
