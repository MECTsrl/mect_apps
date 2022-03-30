#include "crosstable.h"
#include "automation.h"
#include "page100.h"


#include <QDebug>
#include <QFile>
#include <QDir>

#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "pthread.h"

// Function Keys

#define F01 0x41 // T7  PLC_FastIO_14
#define F02 0x42 // T8  PLC_FastIO_15
#define F03 0x44 // T10 PLC_FastIO_17
#define F04 0x3C // T2  PLC_FastIO_1
#define F05 0x3E // T4  PLC_FastIO_11

#define F06 0x3F // T5  PLC_FastIO_12
#define F07 0x3B // T1  PLC_FastIO_9
#define F08 0x40 // T6  PLC_FastIO_13
#define F09 0x3D // T3  PLC_FastIO_10
#define F10 0x43 // T9  PLC_FastIO_16


#define SDCARD_DEVICE       "/dev/mmcblk0"
#define USB0_DEVICE         "/proc/bus/usb/001/"
#define USB1_DEVICE         "/proc/bus/usb/002/"

extern page100 *TheKeyPage;       // Pointer alla pagina che gestisce i Segnali per hwKeys


// Keyboard Handler
static pthread_t kbThread_id;
static pthread_mutex_t kbThread_mutex;
static int fd;

/* put here the initalization */
void setup(void)
{
    int nSide = 0;
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Start-up code
    beginWrite();
    // Abilitazione dei Fast I/O
    addWrite_PLC_FastIO_Ena(0x0001FF01);
    addWrite_PLC_FastIO_Dir(0x00000000);

    // Marca le porte USB come Unplugged
    addWrite_Usb0_Status(USB_UNPLUGGED);
    addWrite_Usb1_Status(USB_UNPLUGGED);
    // Marca SD Card come EMPTY
    addWrite_SDCard_Status(SDCARD_EMPTY);

    // Buzzer Defaults
    addWrite_Buzzer_Repeat(1);
    addWrite_Buzzer_Off_Time(50);
    addWrite_Buzzer_On_Time(50);

    endWrite();
    // Creazione del Thread per gestione Keyboard fisica
    int retval = pthread_create(&kbThread_id, NULL, keyboardThread, (void *)nSide);
    if (retval != 0) {
        qCritical("Automation Setup: keyboardThread pthread_create fails with %d", retval);
    }

}

/* put here the operation made every 100ms */
void loop(void)
{
    static unsigned loopCounter = 0;

    // Operazioni da fare ogni 2 secondi
    if (loopCounter % 20 == 0)  {
        int nFiles = 0;
        beginWrite();
        // USB 0
        int16_t usb0Status = USB_UNPLUGGED;
        QDir usb0(USB0_DEVICE);
        if (usb0.exists())  {
            nFiles = usb0.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name).count();
            // Se nel Device Path esiste almeno un file OLTRE all'Hub, è presente un Device
            if (nFiles > 1)  {
                // qDebug("Files for USB Device [%s]: [%d]", USB0_DEVICE, nFiles);
                usb0Status = USB_INSERTED;
            }
        }
        addWrite_Usb0_Status(usb0Status);
        // USB 1
        int16_t usb1Status = USB_UNPLUGGED;
        QDir usb1(USB1_DEVICE);
        if (usb1.exists())  {
            nFiles = usb1.entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name).count();
            // Se nel Device Path esiste almeno un file OLTRE all'Hub, è presente un Device
            if (nFiles > 1)  {
                // qDebug("Files for USB Device [%s]: [%d]", USB1_DEVICE, nFiles);
                usb1Status = USB_INSERTED;
            }
        }
        addWrite_Usb1_Status(usb1Status);
        // SD CARD
        int16_t sdCardStatus = SDCARD_EMPTY;
        QFile sdCard(SDCARD_DEVICE);
        if (sdCard.exists())  {
            // qDebug("SD Card is Present as Device:[%s]", SDCARD_DEVICE);
            sdCardStatus = SDCARD_INSERTED;
        }
        addWrite_SDCard_Status(sdCardStatus);
        endWrite();
    }

    // Altre Azioni
    loopCounter++;
}

void playBuzzer(u_int8_t nReplies, u_int8_t nOffTime, u_int8_t nOnTime, u_int8_t nVolume)
// Emissione di un Beep dal Buzzer
// nVolume:     Valore da 0 a 100
// nOnTime:     Tempo di Buzzer On in cs
// nOffTime:    Tempo di Buzzer Off in cs
// nReplies:    Numero di ripetizioni
{
    u_int32_t BuzzerValue = ((u_int32_t) nReplies << 24);
    BuzzerValue += ((u_int32_t) nOffTime << 16);
    BuzzerValue += ((u_int32_t) nOnTime << 8);
    BuzzerValue += (u_int32_t) nVolume;
//    qDebug() << QString("Buzzer Params: Replies:%1 OffTime:%2 OnTime:%3 Volume:%4. Result Value:%5") .arg(nReplies) .arg(nOffTime) .arg(nOnTime) .arg(nVolume) .arg(QString::number(BuzzerValue, 16));
    // Write value
    doWrite_PLC_BUZZER(BuzzerValue);
}

void hwkeyPressed(int nKey)
{
    qDebug("Pressed [F%d] Key", nKey);
}

void hwkeyReleased(int nKey)
{
    qDebug("Released [F%d] Key", nKey);
}



void *keyboardThread(void *arg)
{
    int nKey = 0;

    pthread_mutex_init(&kbThread_mutex, NULL);
    pthread_mutex_lock(&kbThread_mutex);
    // Apertura del file degli eventi per gestire Keyboard fisica
    qDebug("Started Keyboard handler");
    fd = open("/dev/input/event0", O_RDONLY);
    if (fd < 0) {
        qCritical("error opening event0");
    }

    if (fd >= 0)  {
        for (;;) {
            struct input_event iev;
            int retVal = read(fd, &iev, sizeof(struct input_event));

            if (retVal == sizeof(iev))  {
                if (iev.type == EV_KEY)  {
                    nKey = 0;
                    // Key Press
                    if (iev.value == 0)  {
                        // Play Buzzer allo stesso livello di volume del Touch screen impostato nel DB e in CT
                        playBuzzer(1, 0, 12, PLC_TOUCH_VOLUME);
                    }
                    // Key Release (no Play)
                    else if (iev.value == 1)  {
                    }
                    else {
//                        fprintf(stderr, "key %d unknown value %d\n", iev.code, iev.value);
                        continue;
                    }
                    switch (iev.code)  {
                    case F01:
                        nKey = 1;
                        break;
                    case F02:
                        nKey = 2;
                        break;
                    case F03:
                        nKey = 3;
                        break;
                    case F04:
                        nKey = 4;
                        break;
                    case F05:
                        nKey = 5;
                        break;
                    case F06:
                        nKey = 6;
                        break;
                    case F07:
                        nKey = 7;
                        break;
                    case F08:
                        nKey = 8;
                        break;
                    case F09:
                        nKey = 9;
                        break;
                    case F10:
                        nKey = 10;
                        break;
                    default:
                        nKey = -1;
//                        fputs("TASTO ??\n", stderr);
                    }
                    if (nKey > 0)  {
                        if (iev.value == 0)  {
                            hwkeyPressed(nKey);
                            // Emissione del Signal HWKeyPressed da TheKeyPage (page2)
                            if (TheKeyPage != NULL )
                                TheKeyPage->sendhwKeyPressed(nKey);
                        }
                        else if (iev.value == 1)  {
                            hwkeyReleased(nKey);
                            // Emissione del Signal HWKeyReleased da TheKeyPage (page2)
                            if (TheKeyPage != NULL )
                                TheKeyPage->sendhwKeyReleased(nKey);
                        }
                    }
                }
                else if (iev.type == EV_SYN) {
                    // Event Burst
                    continue;
                }
                else {
                    continue;
                }
            }
        }
    }

// ExitKB:
    fprintf(stderr, "Exit Keyboard handler\n");
    pthread_mutex_unlock(&kbThread_mutex);
    return arg;
}

