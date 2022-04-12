#include "crosstable.h"
#include "automation.h"

// TEST_STATUS
#define STATUS_LOCAL  0x0000
#define STATUS_REMOTE 0x00D8
#define STATUS_DONE   0x002A

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
    switch (STATUS) {

    case STATUS_LOCAL:
        /* this state is managed in PLC */
        break;

    case STATUS_REMOTE:
        /* this state is managed in PLC */
        break;

    case STATUS_DONE:
        /* this state is managed in PLC */
       break;

    default:
        ;
    }
}

