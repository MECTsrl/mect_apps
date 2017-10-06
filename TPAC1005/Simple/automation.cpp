#include "crosstable.h"
#include "automation.h"
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// Function Keys
#define F01 0x41
#define F02 0x42
#define F03 0x44
#define F04 0x3C
#define F05 0x3E
#define F06 0x3F
#define F07 0x3B
#define F08 0x40
#define F09 0x3D
#define F10 0x43


static int fd;

/* put here the initalization */
void setup(void)
{
    fd = open("/dev/input/event0", O_RDONLY);
}

/* put here the operation made every 100ms */
void loop(void)
{
    struct input_event iev;
    int value;

    int retVal = 0;
    if (fd >= 0)  {
        retVal = read(fd, &iev, sizeof(struct input_event));
        if (retVal == sizeof(iev))  {
            if (iev.type == EV_KEY)  {
                if (iev.value == 0)  {
                    fprintf(stderr, "Key Pressed: %d\n", iev.code);
                    value = 1;
                }
                else if (iev.value == 1)  {
                    fprintf(stderr, "Key Released: %d\n", iev.code);
                    value = 0;
                }
                else {
                    return;
                }
                switch (iev.code)  {
                case F01: doWrite_PLC_Key_01(value); break;
                case F02: doWrite_PLC_Key_02(value); break;
                case F03: doWrite_PLC_Key_03(value); break;
                case F04: doWrite_PLC_Key_04(value); break;
                case F05: doWrite_PLC_Key_05(value); break;
                case F06: doWrite_PLC_Key_06(value); break;
                case F07: doWrite_PLC_Key_07(value); break;
                case F08: doWrite_PLC_Key_08(value); break;
                case F09: doWrite_PLC_Key_09(value); break;
                case F10: doWrite_PLC_Key_10(value); break;
                default:;
                }
            }
        }
    }
}

