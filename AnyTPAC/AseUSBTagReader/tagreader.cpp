#include <QIODevice>
#include <QFile>
#include <QDebug>
#include <QElapsedTimer>

#include "termios.h"
#include "unistd.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "utility.h"            // from Mect Suite utility.h

#include "tagreader.h"

#include "common.h"

#define  cCR                0x0A
#define  COMMAND_TIMEOUT    1500
#define  NUMERIC_CODE       2

// #define LINE_SIZE 8192 in common.h of Mect Suite

char        readerCommand[LINE_SIZE];
char        readerAnswer[LINE_SIZE];

// Tag Reader management variables
int         ttyUSB1 = -1;
bool        cardFound = false;
int         readerStatus = TAG_ERR_NONE;

bool    openReader()
// Opening the USB device of the reader
{
    bool        fRes = false;
    speed_t     speed;
    struct      termios tios;

    ttyUSB1 = open(THE_DEVICE, O_RDWR);
    if (ttyUSB1 >= 0) {
        memset(&tios, 0, sizeof(struct termios));
        tcgetattr(ttyUSB1, &tios);
        tcgetattr(ttyUSB1, &tios);
        speed = B9600;
        // Speed
        if ((cfsetispeed(&tios, speed) < 0) ||
            (cfsetospeed(&tios, speed) < 0)) {
            qCritical("openReader(): Error Setting Speed [%d]", B9600);
            goto exit_failure;
        }
        // 8, N, 1 no flow Control
        tios.c_cflag |= (CREAD | CLOCAL); // enable receiver, local line
        tios.c_cflag |= CS8; // 8 data bits
        tios.c_cflag &=~ CSTOPB; // 1 stop bit
        tios.c_cflag &=~ PARENB; // no parity
        tios.c_lflag |= ICANON; // line oriented
        // tios.c_iflag |= (IXON | IXOFF ); // no flow control
        tios.c_iflag &= ~(IXON | IXOFF | IXANY); // no flow control
       // tios.c_lflag |=
        if (tcsetattr(ttyUSB1, TCSANOW, &tios) < 0) {
            qCritical("openReader(): Error Setting Com Params");
            goto exit_failure;
        }
        qDebug("openReader(): Opened Device [%s] as Device ID:[%d]", THE_DEVICE, ttyUSB1);
        fRes = true;
    }
    else  {
        qCritical("openReader(): Error opening device [%s]", THE_DEVICE);
    }
    // No Device or Open OK
    return fRes;

exit_failure:
    // Error Reading or setting Params
    if (ttyUSB1 > 0)  {
        close(ttyUSB1);
        ttyUSB1 = -1;
    }
    return fRes;
}

void    clearBuffers(char *commandAnswer, int nAnswerLen)
{
    memset(&readerCommand[0], 0, LINE_SIZE);
    memset(&readerAnswer[0], 0, LINE_SIZE);
    memset(commandAnswer, 0, nAnswerLen);
}

int     getReaderStatus(char *readerAnswer)
// Use the first 2 chars of reader answer to get reader status
// (eg: 00 TAG_ERR_NONE, 01 TAG_ERR_UNKNOWN_FUNCTION and so on)
{
    char numericCode[NUMERIC_CODE + 1];

    memset(numericCode, 0, NUMERIC_CODE  + 1);
    strncpy(numericCode, readerAnswer, NUMERIC_CODE);
    return atoi(numericCode);
}

bool    sendCommand(char *myCommand, char *myAnswer, int nBytes2Read)
// Command sending cycle - waiting for response from reader
{
    bool            fRes = false;
    bool            strippedCR = false;
    unsigned int    nChar = 0;
    int             nWriteSize = 0;
    int             nReadSize = 0;
    // int             retVal = 0;
    // int             nLoop = 0;

    QElapsedTimer   watchDogTimer;
    // Clear Buffers & Flush device
    clearBuffers(myAnswer, nBytes2Read);
    tcflush(ttyUSB1, TCIFLUSH);
    // Preparing Send Buffer
    char *p = myCommand;
    for (nChar = 0; nChar < strlen(myCommand) && nChar < LINE_SIZE - 1; nChar++)  {
        readerCommand[nChar] =  *p;
        p++;
    }
    // Append CR
    readerCommand[nChar] = cCR;
    // Send Command
    qDebug("sendCommand(): Command:[%s]", myCommand);
    watchDogTimer.start();
    nWriteSize = write(ttyUSB1, readerCommand, strlen(readerCommand));
    qDebug("sendCommand(): Written[%d] bytes", nWriteSize);
    usleep(20000);
    nReadSize = read(ttyUSB1, readerAnswer, LINE_SIZE);
    // Letto qualcosa, analisi del risultato
    if (nReadSize > 0)  {
        fRes = nReadSize >= nBytes2Read;
        // Esclude CR dalla risposta
        if (readerAnswer[nReadSize - 1] == cCR) {
            strippedCR = true;
            nReadSize--;
        }
        memcpy(myAnswer, readerAnswer, nReadSize);
        readerStatus = getReaderStatus(myAnswer);
    }
    else  {
        readerStatus = TAG_ERR_UNDEF;
    }
    qDebug("sendCommand(): Command [%s] Answer [%s] Written [%d] Read [%d] Stripped CR [%d] Status [%d] Elapsed [%lli]ms", myCommand, myAnswer, nWriteSize, nReadSize,
                        strippedCR, readerStatus, watchDogTimer.elapsed());
    return fRes;
}

bool    resetReader()
// Reader reset, causes a closure of the Device
{
    bool        fRes = false;
    char        myCommand[5] = "0001";
    char        myAnswer[5] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, 2) &&  readerStatus == TAG_ERR_NONE)  {
            // Chiude il Device
            close(ttyUSB1);
            // Sleep for 2 secs
            sleep(2);
            // Reopen Device
            fRes = openReader();
        }
    }
    return fRes;
}

int    getUSBType()
// Get Reader USB Interface Type (should be 1)
{
    int         nType = -1;
    char        myCommand[5] = "0005";
    char        myAnswer[5] = "";
    char        commandRes[NUMERIC_CODE + 1] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, 5) &&  readerStatus == TAG_ERR_NONE)  {
            // Skip numeric status code
            if (strlen(myAnswer) >= 2 * NUMERIC_CODE)  {
                strncpy(commandRes,  myAnswer + NUMERIC_CODE, NUMERIC_CODE);
                nType = atoh(commandRes);
            }
        }
    }
    return nType;
}

int    getDeviceType()
// Get Device Type (should be 0B 11)
{
    int         nType = -1;
    char        myCommand[5] = "0006";
    char        myAnswer[5] = "";
    char        commandRes[NUMERIC_CODE + 1] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, 5) &&  readerStatus == TAG_ERR_NONE)  {
            if (strlen(myAnswer) >= 2 * NUMERIC_CODE)  {
                // Skip numeric status code
                strncpy(commandRes, myAnswer + NUMERIC_CODE, NUMERIC_CODE);
                nType = atoh(commandRes);
            }
        }
    }
    return nType;
}

int     getLastError()
// Get Last Error from reader
{
    int         nType = 0;
    char        myCommand[5] = "000A";
    char        myAnswer[11] = "";
    char        commandRes[NUMERIC_CODE + 1] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, 4) &&  readerStatus == TAG_ERR_NONE)  {
        // Skip numeric status code
        strncpy(commandRes, myAnswer + 2, 2);
        nType = atoh(commandRes);
        }
    }
    return nType;
}
