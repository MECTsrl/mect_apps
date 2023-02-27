#include <QIODevice>
#include <QFile>
#include <QDebug>
#include <QElapsedTimer>

#include "termios.h"
#include "unistd.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "utility.h"            // from Mect Suite utility.h
#include "automation.h"
#include "tagreader.h"

#include "common.h"


//------------------------------------------------------------
// Tag Reader public management variables
//------------------------------------------------------------
int             ttyUSB1 = -1;                   // Handle to device file pointer
bool            cardFound = false;              // True if Card Reader is Open
int             readerStatus = TAG_ERR_NONE;    // reader Status (result of last command)
u_int32_t       readerError = 0;                // reader Last Error
char            lastTag[TAG_ID_LEN];            // Last Read Tag

// #define LINE_SIZE 8192 in common.h of Mect Suite, maybe could be reduced....

//------------------------------------------------------------
// Tag Reader internal management constant and variables
//------------------------------------------------------------
#define  cCR                0x0A
#define  COMMAND_TIMEOUT    1500
#define  BYTE_CHARS         2
#define  UINT16_CHARS       4
#define  UINT32_CHARS       8
#define  MY_BUF_SIZE           256

char        readerCommand[LINE_SIZE];
char        readerAnswer[LINE_SIZE];

//------------------------------------------------------------
// Tag Reader internal management functions
//------------------------------------------------------------
uint32_t reverse_bytes(uint32_t bytes)
{
    uint32_t aux = 0;
    uint8_t byte;
    int i;

    for(i = 0; i < 32; i+=8)
    {
        byte = (bytes >> i) & 0xff;
        aux |= byte << (32 - 8 - i);
    }
    return aux;
}

void reverseString(char *s)
{
   int  length, c;
   char *begin, *end, temp;

   length = strlen(s);
   begin  = s;
   end    = s;

   for (c = 0; c < length - 1; c++)  {
      end++;
    }

   for (c = 0; c < length/2; c++)  {
      temp   = *end;
      *end   = *begin;
      *begin = temp;

      begin++;
      end--;
   }
}

void    clearBuffers(char *commandAnswer, int nAnswerLen)
{
    memset(&readerCommand[0], 0, LINE_SIZE);
    memset(&readerAnswer[0], 0, LINE_SIZE);
    // Clear Answer Buffer if requested
    if (nAnswerLen > 0)  {
        memset(commandAnswer, 0, nAnswerLen);
    }
}

int     getReaderStatus(char *readerAnswer)
// Use the first 2 chars of reader answer to get reader status
// (eg: 00 TAG_ERR_NONE, 01 TAG_ERR_UNKNOWN_FUNCTION and so on)
{
    char numericCode[BYTE_CHARS + 1];

    memset(numericCode, 0, BYTE_CHARS  + 1);
    strncpy(numericCode, readerAnswer, BYTE_CHARS);
    return atoi(numericCode);
}

bool    sendCommand(char *myCommand, char *myAnswer, int nBytes2Read)
// Command sending cycle - waiting for response from reader
// The reader's response always ends with the character CR 0x0D
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
    // Append CR to command
    readerCommand[nChar] = cCR;
    // Send Command
    // qDebug("sendCommand(): Command:[%s]", myCommand);
    watchDogTimer.start();
    nWriteSize = write(ttyUSB1, readerCommand, strlen(readerCommand));
    // qDebug("sendCommand(): Written[%d] bytes", nWriteSize);
    usleep(50000);
    nReadSize = read(ttyUSB1, readerAnswer, LINE_SIZE);
    // Read something, analyze the result
    if (nReadSize > 0)  {
        if (nBytes2Read > 0)  {
            // check response length if defined
            fRes = nReadSize >= nBytes2Read;
        }
        else  {
            // Non empty answer is always ok
            fRes = true;
        }
        // Excludes CR character from response
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

//------------------------------------------------------------
// Tag Reader exported public functions
//------------------------------------------------------------
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

int    getUSBType()
// Get Reader USB Interface Type (should be 1)
// The expected response is 2 + 2 characters
{
    int         nType = -1;
    char        myCommand[5] = "0005";
    char        myAnswer[5] = "";
    char        commandRes[(2 * BYTE_CHARS) + 1] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, (2 * BYTE_CHARS) + 1) &&  readerStatus == TAG_ERR_NONE)  {
            // Skip numeric status code
            if (strlen(myAnswer) >= (2 * BYTE_CHARS) )  {
                strncpy(commandRes,  myAnswer + BYTE_CHARS, BYTE_CHARS);
                nType = atoh(commandRes);
            }
        }
    }
    return nType;
}

int    getDeviceType()
// Get Device Type (should be 0x0B 11 dec)
// The expected response is 2 + 2 characters
{
    int         nType = -1;
    char        myCommand[5] = "0006";
    char        myAnswer[(2 * BYTE_CHARS) + 1] = "";
    char        commandRes[BYTE_CHARS + 1] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, (2 * BYTE_CHARS) + 1) &&  readerStatus == TAG_ERR_NONE)  {
            if (strlen(myAnswer) >= (2 * BYTE_CHARS))  {
                // Skip numeric status code
                strncpy(commandRes, myAnswer + BYTE_CHARS, BYTE_CHARS);
                nType = atoh(commandRes);
            }
        }
    }
    return nType;
}

int         getUSBDeviceState()
// Get USB Device Status (should be 03)
// The expected response is 2 + 2 characters
{
    int         nState = -1;
    char        myCommand[5] = "010A";
    char        myAnswer[(2 * BYTE_CHARS) + 1] = "";
    char        commandRes[BYTE_CHARS + 1] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, (2 * BYTE_CHARS) + 1) &&  readerStatus == TAG_ERR_NONE)  {
            if (strlen(myAnswer) >= (2 * BYTE_CHARS))  {
                // Skip numeric status code
                strncpy(commandRes, myAnswer + BYTE_CHARS, BYTE_CHARS);
                nState = atoh(commandRes);
            }
        }
    }
    return nState;
}

bool        searchTag(int &nTagType, int &nTagBits, char *tagID)
// Search Tag: Return true if found, tag Type
{
    bool        tagPresent = false;
    char        myCommand[7] = "050010";
    char        myAnswer[MY_BUF_SIZE] = "";
    char        commandRes[MY_BUF_SIZE] = "";
    char        foundTag[BYTE_CHARS + 1];
    char        tagType[BYTE_CHARS + 1];
    char        tagBits[BYTE_CHARS + 1];
    char        idLen[BYTE_CHARS + 1];
    int         nIdLen = 0;

    nTagType = NOTAG;
    nTagBits = 0;
    strcpy(tagID, "");
    if (ttyUSB1 > 0)  {
        memset(myAnswer, 0, MY_BUF_SIZE);
        memset(commandRes, 0, MY_BUF_SIZE);
        memset(foundTag, 0, BYTE_CHARS + 1);
        memset(tagType, 0, BYTE_CHARS + 1);
        memset(tagBits, 0, BYTE_CHARS + 1);
        memset(idLen, 0, BYTE_CHARS + 1);
        if (sendCommand(myCommand, myAnswer, -1) &&  readerStatus == TAG_ERR_NONE)  {
            // Skip numeric status code
            strcpy(commandRes, myAnswer + BYTE_CHARS);
            // Tag Found
            strncpy(foundTag, commandRes, BYTE_CHARS);
            tagPresent = (atoi(foundTag) > 0);
            if (tagPresent)  {
                // Tag Type
                strncpy(tagType, commandRes + BYTE_CHARS, BYTE_CHARS);
                nTagType = atoh(tagType);
                // Tag Bits
                strncpy(tagBits, commandRes + (2 * BYTE_CHARS), BYTE_CHARS);
                nTagBits = atoh(tagBits);
                // IdLen
                strncpy(idLen, commandRes + (3 * BYTE_CHARS), BYTE_CHARS);
                // Estimate the length of Tag ID
                nIdLen = atoh(idLen);
                int nIdSize = strlen(commandRes) - (4 * BYTE_CHARS);
                nIdLen = (nIdLen <= nIdSize) ? nIdLen : nIdSize;
                // Tag ID
                strncpy(tagID, commandRes + (4 * BYTE_CHARS), nIdLen);
            }
        }
    }
    if (tagPresent)  {
        strncpy(lastTag, tagID, nIdLen);
    }
    else  {
        strcpy(lastTag, "");
    }
    cardFound = tagPresent;
    return tagPresent;
}

u_int32_t     getLastError()
// Get Last Error from reader
// The expected response is 2 + 8 characters

{
    u_int32_t   nError = 0;
    char        myCommand[5] = "000A";
    char        myAnswer[(BYTE_CHARS + UINT32_CHARS) + 1] = "";
    char        commandRes[UINT32_CHARS + 1] = "";

    if (ttyUSB1 > 0)  {
        if (sendCommand(myCommand, myAnswer, (BYTE_CHARS + UINT32_CHARS) + 1) &&  readerStatus == TAG_ERR_NONE)  {
            if (strlen(myAnswer) >= (BYTE_CHARS + UINT32_CHARS))  {
                // Skip numeric status code
                strncpy(commandRes, myAnswer + BYTE_CHARS, UINT32_CHARS);
                reverseString(commandRes);
                qDebug("getLastError(): Result reversed [%s]", commandRes);
                nError = (u_int32_t) atoh(commandRes);
            }
        }
    }
    return nError;
}
