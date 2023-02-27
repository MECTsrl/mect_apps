#include <QFile>
#include <QDebug>

#include "crosstable.h"
#include "automation.h"
#include "tagreader.h"

#define APP_VERSION         23001

SerialReader *tagReader = 0;

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
            sleep(4);
            qDebug("Device Type is: [%d]", getDeviceType());
            sleep(4);
            qDebug("USB Device Status: [%d]", getUSBDeviceState());
            sleep(4);
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
    // static bool  askType = true;
    static bool  searchTags = true;

    // Un giro ogni 4.3 s
    if (ttyUSB1 >= 0  && (loopCounter % 43 == 0)) {
        //                if (askType)  {
        //                    qDebug("Loop Counter: [%d] - Detected Device Type is: [%d]", loopCounter, getDeviceType());
        //                    askType = false;
        //                    searchTags = true;
        //                }
        //                else  {
        //                    askType = true;
        //                    searchTags = false;
        //                }
        if (searchTags)  {
            int     tagType = NOTAG;
            int     tagBits = 0;
            char    tagId[256];
            if (searchTag(tagType, tagBits, tagId))  {
                qDebug("Loop Counter: [%d] - Reader Status:[%d] - Found Tag Type:[%d] Tag Bits:[%d] ID:[%s]", loopCounter, readerStatus, tagType, tagBits, tagId);
            }
            else  {
                qWarning("Loop Counter:[%d] - Reader Status:[%d] - No Tag Found", loopCounter, readerStatus);
            }
        }
    }
    loopCounter++;
}

