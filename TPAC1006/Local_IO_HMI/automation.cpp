#include "crosstable.h"
#include <stdio.h>

// TEST_STATUS
#define STATUS_LOCAL  0x0000
#define STATUS_REMOTE 0x00D8
#define STATUS_DONE   0x002A

static void clearPLCandRES(void);
static void ifTST_readVAL_writePLC(void);
static void ifTST_readPLC_writeRES(void);

void setup(void)
{
    doWrite_PLC_AnInConf(0x3322);  /* 0..10V */
    doWrite_PLC_AnOutConf(0x22);  /* 0..10V */

    doWrite_TEST_STATUS(STATUS_LOCAL);
}

void loop(void)
{
    static unsigned substatus = 0;

    switch (TEST_STATUS) {

    case STATUS_LOCAL:
        if (TEST_COMMAND == STATUS_REMOTE) {
            clearPLCandRES();
            doWrite_TEST_STATUS(STATUS_REMOTE);
            substatus = 0;
            return;
        }
        break;

    case STATUS_REMOTE:
        if (TEST_COMMAND == STATUS_LOCAL) {
            doWrite_TEST_STATUS(STATUS_LOCAL);
            substatus = 0;
            return;
        }
        if (TEST_COMMAND == STATUS_DONE) {
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
                doWrite_TEST_STATUS(STATUS_DONE);
                substatus = 5;
                return;
            case 5:
                // waiting STATUS_DONE
                break;
            default:
                ;
            }
        }
        break;

    case STATUS_DONE:
        if (TEST_COMMAND == STATUS_LOCAL) {
            clearPLCandRES();
            doWrite_TEST_STATUS(STATUS_LOCAL);
            substatus = 0;
            return;
    }
        if (TEST_COMMAND == STATUS_REMOTE) {
            clearPLCandRES();
            doWrite_TEST_STATUS(STATUS_REMOTE);
            substatus = 0;
            return;
        }
        break;

    default:
        ;
        }
    }

static void clearPLCandRES(void)
{
    doWrite_PLC_DigOut_1(0);
    doWrite_PLC_DigOut_2(0);
    doWrite_PLC_DigOut_3(0);
    doWrite_PLC_DigOut_4(0);
    doWrite_PLC_DigOut_5(0);
    doWrite_PLC_DigOut_6(0);
    doWrite_PLC_DigOut_7(0);
    doWrite_PLC_DigOut_8(0);
    doWrite_PLC_DigOut_9(0);
    doWrite_PLC_DigOut_10(0);
    doWrite_PLC_DigOut_11(0);
    doWrite_PLC_DigOut_12(0);

    doWrite_RES_DigIn_1(0);
    doWrite_RES_DigIn_2(0);
    doWrite_RES_DigIn_3(0);
    doWrite_RES_DigIn_4(0);
    doWrite_RES_DigIn_5(0);
    doWrite_RES_DigIn_6(0);
    doWrite_RES_DigIn_7(0);
    doWrite_RES_DigIn_8(0);

    doWrite_RES_AnIn_1(0);
    doWrite_RES_AnIn_2(0);
    doWrite_RES_AnIn_3(0);
    doWrite_RES_AnIn_4(0);

    doWrite_RES_Tamb(0);
    doWrite_RES_RPM(0);
    doWrite_RES_FWrevision(0);
    doWrite_RES_HWconfig(0);

    doWrite_RES_RTUS_WR(0);
    doWrite_RES_RTUS_RD(0);
}

static void ifTST_readVAL_writePLC(void)
{
    // DigIn 1..8
    if (TST_DigIn_1 ) {  }
    if (TST_DigIn_2 ) {  }
    if (TST_DigIn_3 ) {  }
    if (TST_DigIn_4 ) {  }
    if (TST_DigIn_5 ) {  }
    if (TST_DigIn_6 ) {  }
    if (TST_DigIn_7 ) {  }
    if (TST_DigIn_8 ) {  }

    // DigOut 1..12
    if (TST_DigOut_1 ) { doWrite_PLC_DigOut_1 (VAL_DigOut_1);  }
    if (TST_DigOut_2 ) { doWrite_PLC_DigOut_2 (VAL_DigOut_2);  }
    if (TST_DigOut_3 ) { doWrite_PLC_DigOut_3 (VAL_DigOut_3);  }
    if (TST_DigOut_4 ) { doWrite_PLC_DigOut_4 (VAL_DigOut_4);  }
    if (TST_DigOut_5 ) { doWrite_PLC_DigOut_5 (VAL_DigOut_5);  }
    if (TST_DigOut_6 ) { doWrite_PLC_DigOut_6 (VAL_DigOut_6);  }
    if (TST_DigOut_7 ) { doWrite_PLC_DigOut_7 (VAL_DigOut_7);  }
    if (TST_DigOut_8 ) { doWrite_PLC_DigOut_8 (VAL_DigOut_8);  }
    if (TST_DigOut_9 ) { doWrite_PLC_DigOut_9 (VAL_DigOut_9);  }
    if (TST_DigOut_10) { doWrite_PLC_DigOut_10(VAL_DigOut_10); }
    if (TST_DigOut_11) { doWrite_PLC_DigOut_11(VAL_DigOut_11); }
    if (TST_DigOut_12) { doWrite_PLC_DigOut_12(VAL_DigOut_12); }

    // AnIn 1..4
    u_int16_t AnInConf = 0;
    if (TST_AnIn_1)  { AnInConf |= (VAL_AnInConf_1 << 0); }
    if (TST_AnIn_2)  { AnInConf |= (VAL_AnInConf_2 << 4); }
    if (TST_AnIn_3)  { AnInConf |= (VAL_AnInConf_3 << 8); }
    if (TST_AnIn_4)  { AnInConf |= (VAL_AnInConf_4 << 12); }
    doWrite_PLC_AnInConf(AnInConf);

    // AnOut 1..2
    u_int16_t AnOutConf = 0;
    if (TST_AnOut_1)  {
        AnOutConf |= (VAL_AnOutConf_1 << 0);
        doWrite_PLC_AnOut_1(VAL_AnOut_1);
    }
    if (TST_AnOut_2)  {
        AnOutConf |= (VAL_AnOutConf_2 << 4);
        doWrite_PLC_AnOut_2(VAL_AnOut_2);
    }
    doWrite_PLC_AnOutConf(AnOutConf);

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

    // DigOut 1..12
    if (TST_DigOut_1 ) {  }
    if (TST_DigOut_2 ) {  }
    if (TST_DigOut_3 ) {  }
    if (TST_DigOut_4 ) {  }
    if (TST_DigOut_5 ) {  }
    if (TST_DigOut_6 ) {  }
    if (TST_DigOut_7 ) {  }
    if (TST_DigOut_8 ) {  }
    if (TST_DigOut_9 ) {  }
    if (TST_DigOut_10) {  }
    if (TST_DigOut_11) {  }
    if (TST_DigOut_12) {  }

    // AnIn 1..4
    if (TST_AnIn_1)  { doWrite_RES_DigIn_1(PLC_DigIn_1); }
    if (TST_AnIn_2)  { doWrite_RES_DigIn_1(PLC_DigIn_1); }
    if (TST_AnIn_3)  { doWrite_RES_DigIn_1(PLC_DigIn_1); }
    if (TST_AnIn_4)  { doWrite_RES_DigIn_1(PLC_DigIn_1); }

    // AnOut 1..2
    if (TST_AnOut_1)  { }
    if (TST_AnOut_2)  { }

    // Others
    if (TST_Tamb)  { doWrite_RES_Tamb(PLC_Tamb); }
    if (TST_RPM)   { doWrite_RES_RPM(PLC_RPM); }
    if (TST_FWrevision)  { }
    if (TST_HWconfig) { }
}
