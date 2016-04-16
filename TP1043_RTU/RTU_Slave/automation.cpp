#include "crosstable.h"

static u_int16_t heartbeat;
/* put here the initalization */
void setup(void)
{
    heartbeat = 0;
    doWrite_RTU_HEARTBEAT(heartbeat);
    doWrite_RTU_REPLY(0);
}

/* put here the operation made every 100ms */
void loop(void)
{
    ++heartbeat;
    doWrite_RTU_HEARTBEAT(heartbeat);
    doWrite_RTU_REPLY(-RTU_COMMAND);
}
