#include "crosstable.h"
#include "automation.h"

#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>


#define PT100CONF 7 // PT100_R
#define PT100FILT 64 // sample filtering
#define ANTIGELO 8.0
#define HYSTERESIS 0.5

static bool configured = false;

void setup(void)
{
    doWrite_PLC_HMI_Version(5678); // v5.678
    configured = false;
    doWrite_is_WLAN0_ON(0);
    doWrite_is_PPP0_ON(0);
    doWrite_is_TUN0_ON(0);
    //    doWrite_SogliaAntigelo(ANTIGELO);
    doWrite_is_Convettore1_ON(0);
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
        // Test delle varie interfaccie di rete ogni 60 secondi
        if ((counter % 600) == 0)  {
            // WLAN0
            if (isUP_wlan0()) {
                if (! is_WLAN0_ON)  {
                    doWrite_is_WLAN0_ON(1);
                }
            } else {
                if (is_WLAN0_ON)  {
                    doWrite_is_WLAN0_ON(0);
                }
            }

            // PPP0
            if (isUP_ppp0()) {
                if (!is_PPP0_ON)  {
                    doWrite_is_PPP0_ON(1);
                }
            } else {
                if (is_PPP0_ON)  {
                    doWrite_is_PPP0_ON(0);
                }
            }
            // VPN Tunnel
            if (isUP_tun0()) {
                if (!is_TUN0_ON)  {
                    doWrite_is_TUN0_ON(1);
                }
            } else {
                if (is_TUN0_ON)  {
                    doWrite_is_TUN0_ON(0);
                }
            }
        }
        // Controlli da fare ogni 300s
		if ((counter % 3000) == 0) {

            // try restarting openvpn each five minutes
            if (! is_TUN0_ON) {
                doWrite_openvpn_restart_times(openvpn_restart_times + 1);
				system("/etc/rc.d/init.d/openvpn restart");
			}

            // Controllo della T1
            int    iValue = PLC_AnIn_1 * 10;
            double value = (((double) iValue) + 0.5) / 100.0;

            fprintf(stderr, "Value of T1: %.2f\n", value);
            // Superata Soglia, Spegne Convettore
            if (value > (SogliaAntigelo + HYSTERESIS))  {
                // Accende resistenza stop per convettore 1
                if (! PLC_DigOut_1)  {
                    doWrite_PLC_DigOut_1(1);
                    doWrite_is_Convettore1_ON(0);
                    fprintf(stderr, "STOP Convettore\n");
                }
            }

            // Valore sotto Soglia, Accende Convettore
            if (value < (SogliaAntigelo - HYSTERESIS))  {
                // Spegne resistenza stop per convettore 1
                if (PLC_DigOut_1)  {
                    doWrite_PLC_DigOut_1(0);
                    doWrite_is_Convettore1_ON(1);
                    fprintf(stderr, "START Convettore\n");
                }
            }
            // Reset Counter
            counter = 0;
        }
        // Increment Counter if configured
        ++counter;
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
