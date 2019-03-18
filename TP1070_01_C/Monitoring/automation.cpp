#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_timeWin(300);

    doWrite_XX_AnInConf_1(0x7);// [°C] PT100R ACQUA PUFFER
    doWrite_XX_AnInConf_2(0x7);// [°C] PT100R RITORNO TERMOSIFONE

    doWrite_XX_AnInConf_A(0x0777);// [°C] PT100R
    doWrite_XX_AnInConf_B(0x0777);// [°C] PT100R
    doWrite_XX_AnInConf_C(0x0777);// [°C] PT100R

    doWrite_XX_DigDir_1(1); // Dig I/O ASPEC PHEV
    doWrite_XX_DigDir_2(1); // Dig I/O ASPEC PUFFER 500 W
    doWrite_XX_DigDir_3(1); // Dig I/O ASPEC LAVANDERIA
    doWrite_XX_DigDir_4(1); // Dig I/O ASPEC PUFFER 1500W

    doWrite_XX_DigDir_5(1); // Dig I/O PIANO SOTTO scala
    doWrite_XX_DigDir_6(1); // Dig I/O PIANO TERRA corridoio+soggiorno
    doWrite_XX_DigDir_7(1); // Dig I/O PIANO TERRA sud
    doWrite_XX_DigDir_8(1); // Dig I/O VALVOLA 3 VIE

    // doWrite_openvpn_restart_times(0);

    logStart();
}

bool isUP_ppp0(void)
{
    return system("ip addr show dev ppp0 2>&1 | grep ',UP' >/dev/null ") == 0;
}

bool isUP_tun0(void)
{
    return system("ip addr show dev tun_mrs 2>&1 | grep ',UP' >/dev/null ") == 0;
}

void loop(void)
{
    static unsigned counter = 0;

    ++counter;

    // update the network status, one interface each 500 ms
    switch (counter % 10) {
    case 0:
        if (isUP_ppp0()) {
            if (!is_PPP0_ON)
                doWrite_is_PPP0_ON(1);
        } else {
            if (is_PPP0_ON)
                doWrite_is_PPP0_ON(0);
        }
        break;
    case 5:
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

    // try restarting openvpn each five minutes
    if ((counter % 3000) == 0) {
        if (! is_TUN0_ON) {
            doWrite_openvpn_restart_times(openvpn_restart_times + 1);
            system("/etc/rc.d/init.d/openvpn restart");
        }
    }
}
