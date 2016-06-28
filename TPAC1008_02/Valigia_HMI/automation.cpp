#include "crosstable.h"
#include "cross_table_utility.h" // doWrite()

/* put here the initalization */
void setup(void)
{
    
}

/* put here the operation made every 100ms */
void loop(void)
{
    static int counter = 0;

    if (CH1_NETGOOD) {

        int index0 = ID_DOUT0_TE0_00 + ((counter + 0) % 16);
        int index1 = ID_DOUT0_TE1_00 + ((counter + 3) % 16);
        int index2 = ID_DOUT0_TE2_00 + ((counter + 6) % 16);

        int value = ((counter / 16) % 2 == 0) ? 1 : 0;

        doWrite(index0, &value);
        doWrite(index1, &value);
        doWrite(index2, &value);

        ++counter;
    }
}

