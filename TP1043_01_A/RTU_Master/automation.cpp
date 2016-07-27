#include "crosstable.h"

static u_int16_t command;

void setup(void)
{
    /* initalization */
    command = 0;
}

void loop(void)
{
    /* action @ 100ms */
    if (Auto_COMMAND) {
        ++command;
        doWrite_RTU_COMMAND(command);
        doWrite_TCP_COMMAND(command);
    }
}

u_int16_t get_command(void)
{
    return command;
}
