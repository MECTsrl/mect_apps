#include "crosstable.h"
#include "automation.h"

#define PT100CONF 7 // PT100_R
#define PT100FILT 64 // sample filtering

static bool configured = false;

void setup(void)
{
    doWrite_PLC_HMI_Version(5678); // v5.678
    configured = false;
}

void loop(void)
{

    static unsigned counter = 0;

    // Scrittura configurazione se il CAN interno è OK
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
    // Loop continuo a configurazione avvenuta
	if (configured)  {
		++counter;

		// try restarting openvpn each five minutes
		if ((counter % 3000) == 0) {
            if (! isUP_tun0()) {
                //	doWrite_openvpn_restart_times(openvpn_restart_times + 1);
				system("/etc/rc.d/init.d/openvpn restart");
			}
		}
		
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
