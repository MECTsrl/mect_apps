#include "crosstable.h"
#include "automation.h"

#include <QDebug>
#include <QFile>

#define APP_VERSION         23001

/* put here the initalization */
void setup(void)
{    
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    // .....
    beginWrite();
    addWrite_PLC_HMI_Version(APP_VERSION);
    endWrite();
    //----------------------------------------------------
    // FTDI Device Patch: check if your hardware needs it!
    //----------------------------------------------------
    if (QFile::exists(THE_DEVICE))  {
        qDebug("Disconnecting FTDI Device");
        system("modprobe  -r ftdi_sio");
        sleep(2);
        qDebug("Reconnecting FTDI Device");
        system("modprobe  ftdi_sio vendor=0x0403 product=0x6001");
        sleep(2);
    }
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

