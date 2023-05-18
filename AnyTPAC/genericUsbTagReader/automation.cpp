#include "crosstable.h"
#include "automation.h"

#define APP_VERSION         23001

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
    beginWrite();
    addWrite_PLC_HMI_Version(APP_VERSION);
    endWrite();
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

