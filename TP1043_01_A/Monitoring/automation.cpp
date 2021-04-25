#include "crosstable.h"
#include "automation.h"

#include <QElapsedTimer>

#define TCP_UPDATE_ms 500
QElapsedTimer timer;
uint16_t heartbeat;

void setup(void)
{
    doWrite_PLC_timeWin(60);
    logStart();
    timer.restart();
    heartbeat = 65535;
}

void loop(void)
{
    if (P > Pmax) {
        // update the power statistic
        doWrite_Pmax(P);
    }
    if (timer.elapsed() >= TCP_UPDATE_ms) {        
        // update the tcp registers
        beginWrite();
        {
            // old style
            addWrite_TCP_U(U);
            addWrite_TCP_I(I);
            addWrite_TCP_P(P);
            addWrite_TCP_Q(Q);
            addWrite_TCP_C(C);
            addWrite_TCP_Pmax(Pmax);
            addWrite_TCP_Ttotal(Ttotal);
            addWrite_TCP_Tpart(Tpart);
            addWrite_TCP_UPTIME_s(PLC_UPTIME_s);
            addWrite_TCP_HH_MM(PLC_Hours * 100 + PLC_Minutes);

            // new style
            if (heartbeat == 65535) {
                heartbeat = 1; // always non-zero heartbeat
            } else {
                heartbeat += 1;
            }
            addWrite_SRV_EP_heartbeat          (heartbeat                );

            addWrite_SRV_EP_enabled_wattmeters (1                        );
            addWrite_SRV_EP_wattmeter01_U      (U * 100                  );
            addWrite_SRV_EP_wattmeter01_C      (C * 10                   );
            addWrite_SRV_EP_wattmeter01_Texp   (0                        );

            addWrite_SRV_EP_wattmeter01_P      (P * 10                   );
            addWrite_SRV_EP_wattmeter01_Pmax   (Pmax * 10                );
            addWrite_SRV_EP_wattmeter01_T      (Ttotal / 10              );
            addWrite_SRV_EP_wattmeter02_P      (0                        );
            addWrite_SRV_EP_wattmeter02_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter02_T      (0                        );
            addWrite_SRV_EP_wattmeter03_P      (0                        );
            addWrite_SRV_EP_wattmeter03_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter03_T      (0                        );
            addWrite_SRV_EP_wattmeter04_P      (0                        );
            addWrite_SRV_EP_wattmeter04_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter04_T      (0                        );
            addWrite_SRV_EP_wattmeter05_P      (0                        );
            addWrite_SRV_EP_wattmeter05_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter05_T      (0                        );
            addWrite_SRV_EP_wattmeter06_P      (0                        );
            addWrite_SRV_EP_wattmeter06_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter06_T      (0                        );
            addWrite_SRV_EP_wattmeter07_P      (0                        );
            addWrite_SRV_EP_wattmeter07_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter07_T      (0                        );
            addWrite_SRV_EP_wattmeter08_P      (0                        );
            addWrite_SRV_EP_wattmeter08_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter08_T      (0                        );
            addWrite_SRV_EP_wattmeter09_P      (0                        );
            addWrite_SRV_EP_wattmeter09_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter09_T      (0                        );
            addWrite_SRV_EP_wattmeter10_P      (0                        );
            addWrite_SRV_EP_wattmeter10_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter10_T      (0                        );
            addWrite_SRV_EP_wattmeter11_P      (0                        );
            addWrite_SRV_EP_wattmeter11_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter11_T      (0                        );
            addWrite_SRV_EP_wattmeter12_P      (0                        );
            addWrite_SRV_EP_wattmeter12_Pmax   (0                        );
            addWrite_SRV_EP_wattmeter12_T      (0                        );
        }
        endWrite();
        // restart the timer
        timer.restart();
    }
}
