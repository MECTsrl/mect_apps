#include "crosstable.h"
#include "automation.h"

QString Global_newValue;

/* put here the initalization */
void setup(void)
{    
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    // .....
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

