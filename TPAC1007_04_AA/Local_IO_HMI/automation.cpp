#include "crosstable.h"

void setup(void)
{
    doWrite_PLC_AnInConf_1(2);  /* 0..10V */
    doWrite_PLC_AnInConf_2(2);  /* 0..10V */
    doWrite_PLC_AnOutConf_1(2); /* 0..10V */
    doWrite_PLC_AnOutConf_2(2); /* 0..10V */
    doWrite_PLC_AnOutConf_3(2); /* 0..10V */
    doWrite_PLC_AnOutConf_4(2); /* 0..10V */

    doWrite_STATUS_LOCAL(1);
    doWrite_STATUS_REMOTE(0);
    doWrite_STATUS_DONE(0);
}

void loop(void)
{
    if (STATUS_LOCAL)
    {
        if (START_REMOTE)
        {
            doWrite_STATUS_LOCAL(0);
            doWrite_STATUS_REMOTE(1);
        }
    }
    if (STATUS_REMOTE)
    {
        if (!START_REMOTE)
        {
            doWrite_STATUS_LOCAL(1);
            doWrite_STATUS_REMOTE(0);
            doWrite_STATUS_DONE(0);
        }
        if (START_TEST)
        {
            doWrite_STATUS_REMOTE(0);
            /* TODO: do test */
            /* TCP_SRV -> PLC_ */
            doWrite_STATUS_DONE(0);
        }
    }
    if (STATUS_DONE)
    {
        if (!START_TEST)
        {
            doWrite_STATUS_DONE(0);
            doWrite_STATUS_LOCAL(1);
        }
    }
}
