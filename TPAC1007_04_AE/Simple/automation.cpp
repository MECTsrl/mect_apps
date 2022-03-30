#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Node_01 disabled for testing purposes, should be started with doWrite_NODE_01_STATUS(1)
    // Starting Node 01 (RTU3)
    // sleep(2);
    // qDebug("Starting Node 01");
    // doWrite_NODE_01_STATUS(1);
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

