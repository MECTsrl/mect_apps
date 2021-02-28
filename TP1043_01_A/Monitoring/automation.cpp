#include "crosstable.h"
#include "automation.h"

#include <QElapsedTimer>

#define TCP_UPDATE_ms 1000
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
        endWrite();
        // restart the timer
        timer.restart();
    }
}
