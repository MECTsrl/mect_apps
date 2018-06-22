#include "crosstable.h"
#include "automation.h"

static bool configured;

void setup(void)
{
    configured = false;
}

void loop(void)
{
    if (! configured && CH0_NETGOOD)
    {
        // analog inputs configuration
        // analog inputs filtering
        // in PLC application

        // enable logging
        logStart();

        doWrite_PLC_timeWin(60);

        // ok, configured
        configured = true;
    }

    // update the network status, one interface each 500 ms
    static unsigned counter = 0;

    ++counter;
    switch (counter % 15) {
    case 0:
        if (isUP_wlan0()) {
            if (!is_WLAN0_ON)
                doWrite_is_WLAN0_ON(1);
        } else {
            if (is_WLAN0_ON)
                doWrite_is_WLAN0_ON(0);
        }
        break;
    case 5:
        if (isUP_ppp0()) {
            if (!is_PPP0_ON)
                doWrite_is_PPP0_ON(1);
        } else {
            if (is_PPP0_ON)
                doWrite_is_PPP0_ON(0);
        }
        break;
    case 10:
        if (isUP_tun0()) {
            if (!is_TUN0_ON)
                doWrite_is_TUN0_ON(1);
        } else {
            if (is_TUN0_ON)
                doWrite_is_TUN0_ON(0);
        }
        break;
    default:
        ;
    }
}

bool isUP_wlan0(void)
{
    return system("ip addr show dev wlan0 2>&1 | grep ',UP' >/dev/null ") == 0;
}

bool isUP_ppp0(void)
{
    return system("ip addr show dev ppp0 2>&1 | grep ',UP' >/dev/null ") == 0;
}

bool isUP_tun0(void)
{
    return system("ip addr show dev tun_mrs 2>&1 | grep ',UP' >/dev/null ") == 0;
}
