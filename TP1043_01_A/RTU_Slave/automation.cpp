#include "crosstable.h"
#include "automation.h"

static u_int16_t heartbeat;

void setup(void)
{
    // initalization
    heartbeat = 0;
    doWrite_RTU_HEARTBEAT(heartbeat);
    doWrite_RTU_REPLY(0);
}

void loop(void)
{
    // action @ 100ms
    ++heartbeat;

    // update the heartbeats (both RTU_SRV and TCP_SRV)
    doWrite_RTU_HEARTBEAT(heartbeat);
    doWrite_TCP_HEARTBEAT(heartbeat);

    // reply to commands
    doWrite_RTU_REPLY(-RTU_COMMAND);
    doWrite_TCP_REPLY(-TCP_COMMAND);
}

