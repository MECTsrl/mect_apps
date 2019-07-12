#include "crosstable.h"
#include "automation.h"

bool isUP_ppp0(void);
bool isUP_tun0(void);

#define XX_WatchDog_value   1       // MPNC DigOut watchdog = 1 s (see also plc/Init.st)

#define XX_AnInConf_1_value 0x7     // [°C] PT100R ACQUA PUFFER
#define XX_AnInConf_2_value 0x7     // [°C] PT100R RITORNO TERMOSIFONE

#define XX_AnInConf_A_value 0x0777  // [°C] PT100R
#define XX_AnInConf_B_value 0x0777  // [°C] PT100R
#define XX_AnInConf_C_value 0x0777  // [°C] PT100R

#define XX_DigDir_1_value   1       // comando ASPEC PHEV
#define XX_DigDir_2_value   1       // comando ASPEC PUFFER 500 W
#define XX_DigDir_3_value   1       // comando ASPEC LAVANDERIA
#define XX_DigDir_4_value   1       // comando ASPEC PUFFER 1500W

#define XX_DigDir_5_value   1       // comando PIANO SOTTO scala
#define XX_DigDir_6_value   1       // comando PIANO TERRA corridoio+soggiorno
#define XX_DigDir_7_value   1       // comando PIANO TERRA sud
#define XX_DigDir_8_value   1       // comando VALVOLA 3 VIE

void do_config_MPNC006();
bool test_config_MPNC006();

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_timeWin(300);

    do_config_MPNC006();

    // doWrite_openvpn_restart_times(0);

    logStart();
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

    // try reconfiguring MPNC each minute
    if ((counter % 600) == 0) {
        if (! test_config_MPNC006() && NODE_01_STATUS == 1) {
            do_config_MPNC006();
        }
    }
}

void do_config_MPNC006()
{
    beginWrite();

    doWrite_XX_WatchDog(XX_WatchDog_value);

    doWrite_XX_AnInConf_1(XX_AnInConf_1_value);
    doWrite_XX_AnInConf_2(XX_AnInConf_2_value);

    doWrite_XX_AnInConf_A(XX_AnInConf_A_value);
    doWrite_XX_AnInConf_B(XX_AnInConf_B_value);
    doWrite_XX_AnInConf_C(XX_AnInConf_C_value);

    doWrite_XX_DigDir_1(XX_DigDir_1_value);
    doWrite_XX_DigDir_2(XX_DigDir_2_value);
    doWrite_XX_DigDir_3(XX_DigDir_3_value);
    doWrite_XX_DigDir_4(XX_DigDir_4_value);

    doWrite_XX_DigDir_5(XX_DigDir_5_value);
    doWrite_XX_DigDir_6(XX_DigDir_6_value);
    doWrite_XX_DigDir_7(XX_DigDir_7_value);
    doWrite_XX_DigDir_8(XX_DigDir_8_value);

    endWrite();
}

bool test_config_MPNC006()
{
    bool retval;

    retval = XX_WatchDog == XX_WatchDog_value

          && XX_AnInConf_1 == XX_AnInConf_1_value
          && XX_AnInConf_2 == XX_AnInConf_2_value

          && XX_AnInConf_A == XX_AnInConf_A_value
          && XX_AnInConf_B == XX_AnInConf_B_value
          && XX_AnInConf_C == XX_AnInConf_C_value

          && XX_DigDir_1 == XX_DigDir_1_value
          && XX_DigDir_2 == XX_DigDir_2_value
          && XX_DigDir_3 == XX_DigDir_3_value
          && XX_DigDir_4 == XX_DigDir_4_value

          && XX_DigDir_5 == XX_DigDir_5_value
          && XX_DigDir_6 == XX_DigDir_6_value
          && XX_DigDir_7 == XX_DigDir_7_value
          && XX_DigDir_8 == XX_DigDir_8_value;

    return retval;
}

bool isUP_ppp0(void)
{
    return system("ip addr show dev ppp0 2>&1 | grep ',UP' >/dev/null ") == 0;
}

bool isUP_tun0(void)
{
    return system("ip addr show dev tun_mrs 2>&1 | grep ',UP' >/dev/null ") == 0;
}
