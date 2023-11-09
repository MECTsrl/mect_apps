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
    // print openSSL version on target
    system("openssl version");
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}
