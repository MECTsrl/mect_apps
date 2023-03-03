#include <QFile>
#include <QDebug>
#include <QThread>

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
}

/* put here the operation made every 100ms */
void loop(void)
{
    static unsigned loopCounter = 1;

    // Un giro ogni 7 s
    if (tagReader != 0 && tagReader->isOpen()  && tagReader->readerStatus() > SerialReader::senderZero && tagReader->readerStatus() <= SerialReader::senderWaiting && (loopCounter % 11 == 0)) {
        tagReader->sendReaderCommand(SerialReader::cmdSearchTags, "050010");
    }
    loopCounter++;
}

