#include <QFile>
#include <QDebug>
#include <QThread>
#include <QTime>

#include "crosstable.h"
#include "automation.h"
#include "tagreader.h"

#define APP_VERSION         23001

SerialReader *tagReader = 0;

/* put here the initalization */
void setup(void)
{

    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    beginWrite();
    addWrite_PLC_HMI_Version(APP_VERSION);
    addWrite_readerFound(false);
    addWrite_rawttyDevice(0);
    endWrite();
    int tagFilter = 0;
    tagFilter |= TAGMASK(HFTAG_MIFARE);         // 0x01
    tagFilter |= TAGMASK(HFTAG_ISO15693);       // 0x04
    qDebug("Tag Filter: 0x%X", tagFilter);
}

/* put here the operation made every 100ms */
void loop(void)
{
    static unsigned loopCounter = 1;

    // Un giro ogni 3 s
    if (loopCounter % 29 == 0 && tagReader != 0 && tagReader->isOpen())  {
        if (tagReader->readerStatus() == SerialReader::senderWaiting)  {
                tagReader->sendReaderCommand(SerialReader::cmdSearchTags, "050010");
        }
        else  {
            qDebug("[%s] Automation loop(): Reader Status: [%s]",
                    QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(),
                    tagReader->getStatusDesc(tagReader->readerStatus()).toLatin1().data());
        }
    }
    loopCounter++;
}

