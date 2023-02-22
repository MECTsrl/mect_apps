#include "crosstable.h"
// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// termios
#include "termios.h"
#include "unistd.h"
// memset
#include "string.h"
//snprintf
#include <stdio.h>
// atoi
#include <stdlib.h>

#define THE_DEVICE "/dev/ttyUSB0"
#define TERM_LINE_SIZE 80
#define WORD_SIZE 8

static int ttyUSB0;
static char readLine[TERM_LINE_SIZE];
static char lastReadLine[TERM_LINE_SIZE];

/* put here the initalization */
void setup(void)
{
    struct termios tios;
    speed_t speed;

    snprintf(lastReadLine, TERM_LINE_SIZE, "%.2f (setup)", PLC_time);
    ttyUSB0 = open(THE_DEVICE, O_RDWR);
    if (ttyUSB0 < 0) {
        return;
    }

    /* Setup the serial line  */
    memset(&tios, 0, sizeof(struct termios));
    tcgetattr(ttyUSB0, &tios);
    speed = B38400;
    if ((cfsetispeed(&tios, speed) < 0) ||
        (cfsetospeed(&tios, speed) < 0)) {
        goto exit_failure;
    }
    tios.c_cflag |= (CREAD | CLOCAL); // enable receiver, local line
    tios.c_cflag |= CS8; // 8 data bits
    tios.c_cflag &=~ CSTOPB; // 1 stop bit
    tios.c_cflag &=~ PARENB; // no parity
    tios.c_lflag |= ICANON; // line oriented
    tios.c_iflag &= ~(IXON | IXOFF | IXANY); // no flow control
    if (tcsetattr(ttyUSB0, TCSANOW, &tios) < 0) {
        goto exit_failure;
    }
    return;

exit_failure:
    close(ttyUSB0);
    ttyUSB0 = -1;
}

/* put here the operation made every 100ms */
void loop(void)
{
    int retval;

    if (ttyUSB0 < 0) {
        snprintf(lastReadLine, TERM_LINE_SIZE, "%.2f (can't open '%s')", PLC_time, THE_DEVICE);
        return;
    }

    memset(readLine, 0, TERM_LINE_SIZE);
    retval = read(ttyUSB0, readLine, TERM_LINE_SIZE);
    if (retval < 0) {
        snprintf(lastReadLine, TERM_LINE_SIZE, "%.2f read = (error %d)", PLC_time, retval);
        doWrite_RS232_INPUT(0xFFFFFFFF);
        return;
    }
    if (retval == 0 || readLine[0] == '\n' || readLine[0] == '\r' ) {
        // snprintf(lastReadLine, TERM_LINE_SIZE, "%.2f read = (empty line)", PLC_time);
        return;
    }
    snprintf(lastReadLine, TERM_LINE_SIZE, "%.2f read(%d) = '%s'", PLC_time, retval, readLine);
    doWrite_RS232_INPUT(atoi(readLine));
}

char *getLastReadLine(void)
{
    return lastReadLine;
}
