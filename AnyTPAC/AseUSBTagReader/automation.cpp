#include <QFile>
#include <QDebug>

#include "crosstable.h"
#include "automation.h"
#include "tagreader.h"

#define APP_VERSION         23001


/* put here the initalization */
void setup(void)
{
    bool serialOpened = false;
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    // .....
    beginWrite();
    addWrite_PLC_HMI_Version(APP_VERSION);
    if (QFile::exists(THE_DEVICE))  {
        serialOpened = openReader();
        if (serialOpened)  {
            int usbType = getUSBType();
            qDebug("USB Interface Type is: [%d]", usbType);
        }
    }
    else {
        qCritical("setup(): Reader Device [%s] not found", THE_DEVICE);
    }
    addWrite_readerFound(serialOpened);
    endWrite();
}

/* put here the operation made every 100ms */
void loop(void)
{
    static unsigned loopCounter = 1;
    static bool  askType = true;

    if (ttyUSB1 >= 0  && (loopCounter % 11 == 0)) {
        // qDebug("Loop Counter: [%d]", loopCounter);
        if (askType)  {
            qDebug("Loop Counter: [%d] - Detected Device Type is: [%d]", loopCounter, getDeviceType());
            askType = false;
        }
        else  {
            askType = true;
        }
    }
    loopCounter++;
}

