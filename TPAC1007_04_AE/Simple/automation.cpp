#include "crosstable.h"
#include "automation.h"

#include <QDebug>

/* put here the initalization */
void setup(void)
{
    // Waiting PLC Engine
    qDebug("Waiting PLC Engine");
    while (PLC_EngineStatus < 2)  {
        fprintf(stderr, "*");
        sleep(1);
    }
    fprintf(stderr, "$");
// Node_01 disabled for testing purposes, should be started with doWrite_NODE_01_STATUS(1)
//    // Starting Node 01 (RTU3)
//    sleep(2);
//    qDebug("Starting Node 01");
//    doWrite_NODE_01_STATUS(1);
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

