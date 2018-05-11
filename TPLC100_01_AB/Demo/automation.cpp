#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    
}

/* put here the operation made every 100ms */
void loop(void)
{
    static int counter = 0;

    if ((counter % 20) == 0) {
        // ogni 2 secondi
        doWrite_theHEARTBEAT(theHEARTBEAT + 1);
        doWrite_VAR1(VAR2 + VAR3);
        doWrite_VAR2(VAR2 + 10);
        doWrite_VAR3(VAR3 + 1);
    }
    ++counter;
}

