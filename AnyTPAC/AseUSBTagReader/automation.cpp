#include <QFile>
#include <QDebug>
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "crosstable.h"
#include "automation.h"
#include "tagreader.h"

#define APP_VERSION         23001

SerialReader *tagReader = 0;

/* put here the initalization */
void setup(void)
{
    int     i = 0;
    bool    serialOpened = false;
    bool    serialPortFound = false;
    QString serialPortName;

    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    // Searching Serial Device
    if (QFile::exists(THE_DEVICE))  {
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            qDebug("Serial Port [%d/%d] - Name: [%s] Location: [%s] Description: [%s] Manufacturer: [%s]", i+1,
                                QSerialPortInfo::availablePorts().count(),
                                info.portName().toAscii().data(),
                                info.systemLocation().toAscii().data(),
                                info.description().toAscii().data(),
                                info.manufacturer().toAscii().data());
            // Check Device raw file name from /dev
            if (info.systemLocation() == THE_DEVICE)  {
                // tagReaderInfo = info;
                serialPortFound = true;
                serialPortName = info.portName();
                qDebug("Tag Reader Device Found: [%s] Port Name[%s]", THE_DEVICE, serialPortName.toAscii().data());
            }
        }
    }
    // Open Serial Port Object
    if (serialPortFound && ! serialPortName.isEmpty())  {
        QThread* serialThread = new QThread();
        tagReader = new SerialReader(serialPortName);
        tagReader->moveToThread(serialThread);
        QObject::connect(serialThread, SIGNAL(started()), tagReader, SLOT(openSerialPort()));
        serialThread->start();
        int nLoop = 0;
        while (! serialOpened && nLoop < 30)  {
            sleep(1);
            nLoop++;
            serialOpened = tagReader->isOpen();
        }

        if (serialOpened)  {
            ttyUSB1 = tagReader->getSerialDeviceID();
            qDebug("Current Serial Port handle [%d] for Device [%s] Loop [%d]", ttyUSB1, THE_DEVICE, nLoop);
        }
        else  {
            qCritical("setup(): Error opening device [%s]", THE_DEVICE);
            tagReader->deleteLater();
        }
    }
    else {
        qCritical("setup(): Reader Device [%s] not found", THE_DEVICE);
    }

    beginWrite();
    addWrite_PLC_HMI_Version(APP_VERSION);
    addWrite_readerFound(serialOpened);
    endWrite();
}

/* put here the operation made every 100ms */
void loop(void)
{
    static unsigned loopCounter = 1;

    // Un giro ogni 7 s
    if (tagReader != 0 && ttyUSB1 > 0  && (loopCounter % 7 == 0)) {
        tagReader->sendSerialCommand("050010");
    }
    loopCounter++;
}

