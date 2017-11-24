#include "crosstable.h"
#include "automation.h"

#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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

static int fd;

/* put here the initalization */
void setup(void)
{
    doWrite_PLC_FastIO_Ena(0x0003FF01);
    doWrite_PLC_FastIO_Dir(0x00020000); // PLC_FastIO_18 --> GPIO(2,9) PIN275(SSP0_DETECT) [R77]

    fd = open("/dev/input/event0", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "error opening event0\n");
    }
}

/* put here the operation made every 100ms */
void loop(void)
{
    if (fd >= 0)  {
        struct input_event iev;
        int retVal = read(fd, &iev, sizeof(struct input_event));

        if (retVal == sizeof(iev))  {
            if (iev.type == EV_KEY)  {
                if (iev.value == 0)  {
                    fprintf(stderr, "key %d pressed ", iev.code);
                }
                else if (iev.value == 1)  {
                    fprintf(stderr, "key %d released ", iev.code);
                }
                else {
                    fprintf(stderr, "key %d unknown value %d\n", iev.code, iev.value);
                    return;
                }
                switch (iev.code)  {
                case F01: fputs("TASTO 1\n", stderr); break;
                case F02: fputs("TASTO 2\n", stderr); break;
                case F03: fputs("TASTO 3\n", stderr); break;
                case F04: fputs("TASTO 4\n", stderr); break;
                case F05: fputs("TASTO 5\n", stderr); break;
                case F06: fputs("TASTO 6\n", stderr); break;
                case F07: fputs("TASTO 7\n", stderr); break;
                case F08: fputs("TASTO 8\n", stderr); break;
                case F09: fputs("TASTO 9\n", stderr); break;
                case F10: fputs("TASTO 10\n", stderr); break;
                default: fputs("TASTO ??\n", stderr);
                }
            } else if (iev.type == EV_SYN) {
                return;
            } else {
                fprintf(stderr, "unknown event type:%d\n", iev.type);
            }
        }
    }
}

