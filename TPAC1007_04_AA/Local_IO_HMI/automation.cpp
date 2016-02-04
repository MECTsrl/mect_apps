#include "crosstable.h"
#include <stdio.h>

// TEST_STATUS
#define STATUS_LOCAL  0x0000
#define STATUS_REMOTE 0x00D8
#define STATUS_DONE   0x002A

void setup(void)
{
}

void loop(void)
{
    switch (TEST_STATUS) {

    case STATUS_LOCAL:
        break;

    case STATUS_REMOTE:
        break;

    case STATUS_DONE:
       break;

    default:
        ;
    }
}
