#include "crosstable.h"
#include "automation.h"

#include <QElapsedTimer>

#define TCP_UPDATE_ms 500
QElapsedTimer timer;

void setup(void)
{
    doWrite_PLC_timeWin(60);
    logStart();
    timer.restart();
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
        endWrite();
        // restart the timer
        timer.restart();
    }
}
