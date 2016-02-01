#include "crosstable.h"
#include <stdio.h>

static void ifTST_readVAL_writePLC(void);
static void ifTST_readPLC_writeRES(void);

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
    static unsigned substatus = 0;

    if (STATUS_LOCAL) {
        if (START_REMOTE) {
            doWrite_STATUS_LOCAL(0);
            doWrite_STATUS_REMOTE(1);
            substatus = 0;
        }
    }
    if (STATUS_REMOTE) {

        if (!START_REMOTE) {
            doWrite_STATUS_LOCAL(1);
            doWrite_STATUS_REMOTE(0);
            doWrite_STATUS_DONE(0);
            substatus = 0;
        }
        if (START_TEST) {
            switch(substatus) {
            case 0:
                ifTST_readVAL_writePLC();
                substatus = 1;
                break;
            case 1:
            case 2:
            case 3:
                ++substatus;
                break;
            case 4:
                ifTST_readPLC_writeRES();
                doWrite_STATUS_REMOTE(0);
                doWrite_STATUS_DONE(1);
                substatus = 0;
                break;
            default:
                ; // FIXME: assert
            }
        }
    }
    if (STATUS_DONE) {
        if (!START_TEST) {
            doWrite_STATUS_DONE(0);
            doWrite_STATUS_LOCAL(1);
            substatus = 0;
        }
    }
}

static void ifTST_readVAL_writePLC(void)
{
    // DigIn 1..8
    if (TST_DigIn_1 ) { doWrite_PLC_DigDir_1(0); }
    if (TST_DigIn_2 ) { doWrite_PLC_DigDir_2(0); }
    if (TST_DigIn_3 ) { doWrite_PLC_DigDir_3(0); }
    if (TST_DigIn_4 ) { doWrite_PLC_DigDir_4(0); }
    if (TST_DigIn_5 ) { doWrite_PLC_DigDir_5(0); }
    if (TST_DigIn_6 ) { doWrite_PLC_DigDir_6(0); }
    if (TST_DigIn_7 ) { doWrite_PLC_DigDir_7(0); }
    if (TST_DigIn_8 ) { doWrite_PLC_DigDir_8(0); }
    // DigIn 9..12
    if (TST_DigIn_9 ) { }
    if (TST_DigIn_10) { }
    if (TST_DigIn_11) { }
    if (TST_DigIn_12) { }

    // DigOut 1..8
    if (TST_DigOut_1 ) { doWrite_PLC_DigDir_1(1); doWrite_PLC_DigOut_1(VAL_DigOut_1); }
    if (TST_DigOut_2 ) { doWrite_PLC_DigDir_2(1); doWrite_PLC_DigOut_2(VAL_DigOut_2); }
    if (TST_DigOut_3 ) { doWrite_PLC_DigDir_3(1); doWrite_PLC_DigOut_3(VAL_DigOut_3); }
    if (TST_DigOut_4 ) { doWrite_PLC_DigDir_4(1); doWrite_PLC_DigOut_4(VAL_DigOut_4); }
    if (TST_DigOut_5 ) { doWrite_PLC_DigDir_5(1); doWrite_PLC_DigOut_5(VAL_DigOut_5); }
    if (TST_DigOut_6 ) { doWrite_PLC_DigDir_6(1); doWrite_PLC_DigOut_6(VAL_DigOut_6); }
    if (TST_DigOut_7 ) { doWrite_PLC_DigDir_7(1); doWrite_PLC_DigOut_7(VAL_DigOut_7); }
    if (TST_DigOut_8 ) { doWrite_PLC_DigDir_8(1); doWrite_PLC_DigOut_8(VAL_DigOut_8); }

    // AnIn 1..2
    if (TST_AnIn_1)  { doWrite_PLC_AnInConf_1(VAL_AnInConf_1); doWrite_PLC_AnIn1Filter(VAL_AnInFltr_1); }
    if (TST_AnIn_2)  { doWrite_PLC_AnInConf_2(VAL_AnInConf_2); doWrite_PLC_AnIn2Filter(VAL_AnInFltr_2); }

    // AnOut 1..4
    if (TST_AnOut_1)  { doWrite_PLC_AnOutConf_1(VAL_AnOutConf_1); doWrite_PLC_AnOut_1(VAL_AnOut_1); }
    if (TST_AnOut_2)  { doWrite_PLC_AnOutConf_2(VAL_AnOutConf_2); doWrite_PLC_AnOut_2(VAL_AnOut_2); }
    if (TST_AnOut_3)  { doWrite_PLC_AnOutConf_3(VAL_AnOutConf_3); doWrite_PLC_AnOut_3(VAL_AnOut_3); }
    if (TST_AnOut_4)  { doWrite_PLC_AnOutConf_4(VAL_AnOutConf_4); doWrite_PLC_AnOut_4(VAL_AnOut_4); }

    // Others
    if (TST_Tamb)  { }
    if (TST_RPM)  { }
    if (TST_FWrevision)  { }
    if (TST_HWconfig) { }
}

static void ifTST_readPLC_writeRES(void)
{
    // DigIn 1..8
    if (TST_DigIn_1 ) { doWrite_RES_DigIn_1(PLC_DigIn_1); }
    if (TST_DigIn_2 ) { doWrite_RES_DigIn_2(PLC_DigIn_2); }
    if (TST_DigIn_3 ) { doWrite_RES_DigIn_3(PLC_DigIn_3); }
    if (TST_DigIn_4 ) { doWrite_RES_DigIn_4(PLC_DigIn_4); }
    if (TST_DigIn_5 ) { doWrite_RES_DigIn_5(PLC_DigIn_5); }
    if (TST_DigIn_6 ) { doWrite_RES_DigIn_6(PLC_DigIn_6); }
    if (TST_DigIn_7 ) { doWrite_RES_DigIn_7(PLC_DigIn_7); }
    if (TST_DigIn_8 ) { doWrite_RES_DigIn_8(PLC_DigIn_8); }
    // DigIn 9..12
    if (TST_DigIn_9 ) { doWrite_RES_DigIn_9(PLC_DigIn_9); }
    if (TST_DigIn_10) { doWrite_RES_DigIn_10(PLC_DigIn_10); }
    if (TST_DigIn_11) { doWrite_RES_DigIn_11(PLC_DigIn_11); }
    if (TST_DigIn_12) { doWrite_RES_DigIn_12(PLC_DigIn_12); }

    // DigOut 1..8
    if (TST_DigOut_1 ) {  }
    if (TST_DigOut_2 ) {  }
    if (TST_DigOut_3 ) {  }
    if (TST_DigOut_4 ) {  }
    if (TST_DigOut_5 ) {  }
    if (TST_DigOut_6 ) {  }
    if (TST_DigOut_7 ) {  }
    if (TST_DigOut_8 ) {  }

    // AnIn 1..2
    if (TST_AnIn_1)  { doWrite_RES_AnIn_1(PLC_AnIn_1); }
    if (TST_AnIn_2)  { doWrite_RES_AnIn_2(PLC_AnIn_2); }

    // AnOut 1..4
    if (TST_AnOut_1)  { }
    if (TST_AnOut_2)  { }
    if (TST_AnOut_3)  { }
    if (TST_AnOut_4)  { }

    // Others
    if (TST_Tamb)  { doWrite_RES_Tamb(PLC_Tamb); }
    if (TST_RPM)   { }
    if (TST_FWrevision) { doWrite_RES_FWrevision(PLC_FWrevision); }
    if (TST_HWconfig)   { doWrite_RES_HWconfig(PLC_HWconfig); }
}
