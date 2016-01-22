#include "crosstable.h"

#define abs(v) (((v) > 0)? (v):-(v))

void setup(void)
{
    /* reset all */
    doWrite_START2_REMOTE(false); doWrite_STARTx_REMOTE(false);
    doWrite_START2_TEST(false); doWrite_STARTx_TEST(false);
    /* POWER ON <-- DO3 */
    /* OUTPUT ON <-- DO2 */
    doWrite_PLC_DigDir_3(1);
    doWrite_PLC_DigDir_2(1);
//    doWrite_PLC_DigOut_3(0);
//    doWrite_PLC_DigOut_2(0);
    /* ANALOG OUTPUT THRESHOLD */
    doWrite_RTU_AnOutConf_X(5);
    doWrite_STATUS(0);
}

void ClearResults(void)
{
    doWrite_OK_DigIn_1(false);
    doWrite_OK_DigIn_2(false);
    doWrite_OK_DigIn_3(false);
    doWrite_OK_DigIn_4(false);
    doWrite_OK_DigIn_5(false);
    doWrite_OK_DigIn_6(false);
    doWrite_OK_DigIn_7(false);
    doWrite_OK_DigIn_8(false);
    doWrite_OK_DigIn_9(false);
    doWrite_OK_DigIn_10(false);
    doWrite_OK_DigIn_11(false);
    doWrite_OK_DigIn_12(false);
    doWrite_OK_DigIn_13(false);
    doWrite_OK_DigIn_14(false);
    doWrite_OK_DigIn_15(false);
    doWrite_OK_DigIn_16(false);
    doWrite_OK_DigOut_1(false);
    doWrite_OK_DigOut_2(false);
    doWrite_OK_DigOut_3(false);
    doWrite_OK_DigOut_4(false);
    doWrite_OK_DigOut_5(false);
    doWrite_OK_DigOut_6(false);
    doWrite_OK_DigOut_7(false);
    doWrite_OK_DigOut_8(false);
    doWrite_OK_DigOut_9(false);
    doWrite_OK_DigOut_10(false);
    doWrite_OK_DigOut_11(false);
    doWrite_OK_DigOut_12(false);
    doWrite_OK_DigOut_13(false);
    doWrite_OK_DigOut_14(false);
    doWrite_OK_DigOut_15(false);
    doWrite_OK_DigOut_16(false);
    doWrite_OK_AnIn_1(false);
    doWrite_OK_AnIn_2(false);
    doWrite_OK_AnIn_3(false);
    doWrite_OK_AnIn_4(false);
    doWrite_OK_AnIn_5(false);
    doWrite_OK_AnIn_6(false);
    doWrite_OK_AnIn_7(false);
    doWrite_OK_AnIn_8(false);
    doWrite_OK_AnIn_9(false);
    doWrite_OK_AnIn_10(false);
    doWrite_OK_AnIn_11(false);
    doWrite_OK_AnIn_12(false);
    doWrite_OK_AnOut_1(false);
    doWrite_OK_AnOut_2(false);
    doWrite_OK_AnOut_3(false);
    doWrite_OK_AnOut_4(false);
    doWrite_OK_Tamb(false);
    doWrite_OK_RPM(false);
    doWrite_OK_VCC_set(false);
    doWrite_OK_mA_max(false);
    doWrite_OK_VCC_fbk(false);
    doWrite_OK_mA_fbk(false);
    doWrite_OK_FWrevision(false);
    doWrite_OK_HWconfig(false);
    doWrite_OK_RTUS_WR(false);
    doWrite_OK_RTUS_RD(false);
    doWrite_OK_RTU1_WR(false);
    doWrite_OK_RTU1_RD(false);
    doWrite_OK_RTU3_WR(false);
    doWrite_OK_RTU3_RD(false);
    doWrite_OK_CAN1_WR(false);
    doWrite_OK_CAN1_RD(false);
}

void Translate_DigIn(void)
{
    /* DigIn 1..16 are on the local TPLC005 */
    doWrite_TSTx_DigIn_1 (TST_DigIn_1);
    doWrite_TSTx_DigIn_2 (TST_DigIn_2);
    doWrite_TSTx_DigIn_3 (TST_DigIn_3);
    doWrite_TSTx_DigIn_4 (TST_DigIn_4);
    doWrite_TSTx_DigIn_5 (TST_DigIn_5);
    doWrite_TSTx_DigIn_6 (TST_DigIn_6);
    doWrite_TSTx_DigIn_7 (TST_DigIn_7);
    doWrite_TSTx_DigIn_8 (TST_DigIn_8);
    doWrite_TSTx_DigIn_9 (TST_DigIn_9);
    doWrite_TSTx_DigIn_10(TST_DigIn_10);
    doWrite_TSTx_DigIn_11(TST_DigIn_11);
    doWrite_TSTx_DigIn_12(TST_DigIn_12);
    doWrite_TSTx_DigIn_13(TST_DigIn_13);
    doWrite_TSTx_DigIn_14(TST_DigIn_14);
    doWrite_TSTx_DigIn_15(TST_DigIn_15);
    doWrite_TSTx_DigIn_16(TST_DigIn_16);

    if (TST_DigIn_1 ) { doWrite_RTU_DigOut_1 (VAL_DigIn_1);  }
    if (TST_DigIn_2 ) { doWrite_RTU_DigOut_2 (VAL_DigIn_2);  }
    if (TST_DigIn_3 ) { doWrite_RTU_DigOut_3 (VAL_DigIn_3);  }
    if (TST_DigIn_4 ) { doWrite_RTU_DigOut_4 (VAL_DigIn_4);  }
    if (TST_DigIn_5 ) { doWrite_RTU_DigOut_5 (VAL_DigIn_5);  }
    if (TST_DigIn_6 ) { doWrite_RTU_DigOut_6 (VAL_DigIn_6);  }
    if (TST_DigIn_7 ) { doWrite_RTU_DigOut_7 (VAL_DigIn_7);  }
    if (TST_DigIn_8 ) { doWrite_RTU_DigOut_8 (VAL_DigIn_8);  }
    if (TST_DigIn_9 ) { doWrite_RTU_DigOut_9 (VAL_DigIn_9);  }
    if (TST_DigIn_10) { doWrite_RTU_DigOut_10(VAL_DigIn_10); }
    if (TST_DigIn_11) { doWrite_RTU_DigOut_11(VAL_DigIn_11); }
    if (TST_DigIn_12) { doWrite_RTU_DigOut_12(VAL_DigIn_12); }
    if (TST_DigIn_13) { doWrite_RTU_DigOut_13(VAL_DigIn_13); }
    if (TST_DigIn_14) { doWrite_RTU_DigOut_14(VAL_DigIn_14); }
    if (TST_DigIn_15) { doWrite_RTU_DigOut_15(VAL_DigIn_15); }
    if (TST_DigIn_16) { doWrite_RTU_DigOut_16(VAL_DigIn_16); }
}

void Translate_DigOut(void)
{
    /* DigOut 1..16 are on the local TPLC005 */
    doWrite_TSTx_DigOut_1 (TST_DigOut_1);
    doWrite_TSTx_DigOut_2 (TST_DigOut_2);
    doWrite_TSTx_DigOut_3 (TST_DigOut_3);
    doWrite_TSTx_DigOut_4 (TST_DigOut_4);
    doWrite_TSTx_DigOut_5 (TST_DigOut_5);
    doWrite_TSTx_DigOut_6 (TST_DigOut_6);
    doWrite_TSTx_DigOut_7 (TST_DigOut_7);
    doWrite_TSTx_DigOut_8 (TST_DigOut_8);
    doWrite_TSTx_DigOut_9 (TST_DigOut_9);
    doWrite_TSTx_DigOut_10(TST_DigOut_10);
    doWrite_TSTx_DigOut_11(TST_DigOut_11);
    doWrite_TSTx_DigOut_12(TST_DigOut_12);
    doWrite_TSTx_DigOut_13(TST_DigOut_13);
    doWrite_TSTx_DigOut_14(TST_DigOut_14);
    doWrite_TSTx_DigOut_15(TST_DigOut_15);
    doWrite_TSTx_DigOut_16(TST_DigOut_16);

    if (TST_DigOut_1 ) { doWrite_VALx_DigOut_1 (VAL_DigOut_1);  }
    if (TST_DigOut_2 ) { doWrite_VALx_DigOut_2 (VAL_DigOut_2);  }
    if (TST_DigOut_3 ) { doWrite_VALx_DigOut_3 (VAL_DigOut_3);  }
    if (TST_DigOut_4 ) { doWrite_VALx_DigOut_4 (VAL_DigOut_4);  }
    if (TST_DigOut_5 ) { doWrite_VALx_DigOut_5 (VAL_DigOut_5);  }
    if (TST_DigOut_6 ) { doWrite_VALx_DigOut_6 (VAL_DigOut_6);  }
    if (TST_DigOut_7 ) { doWrite_VALx_DigOut_7 (VAL_DigOut_7);  }
    if (TST_DigOut_8 ) { doWrite_VALx_DigOut_8 (VAL_DigOut_8);  }
    if (TST_DigOut_9 ) { doWrite_VALx_DigOut_9 (VAL_DigOut_9);  }
    if (TST_DigOut_10) { doWrite_VALx_DigOut_10(VAL_DigOut_10); }
    if (TST_DigOut_11) { doWrite_VALx_DigOut_11(VAL_DigOut_11); }
    if (TST_DigOut_12) { doWrite_VALx_DigOut_12(VAL_DigOut_12); }
    if (TST_DigOut_13) { doWrite_VALx_DigOut_13(VAL_DigOut_13); }
    if (TST_DigOut_14) { doWrite_VALx_DigOut_14(VAL_DigOut_14); }
    if (TST_DigOut_15) { doWrite_VALx_DigOut_15(VAL_DigOut_15); }
    if (TST_DigOut_16) { doWrite_VALx_DigOut_16(VAL_DigOut_16); }
}

void Translate_AnIn(void)
{

    if (TST_AnIn_1)  {
        doWrite_TSTx_AnIn_1(true);
        doWrite_VALx_AnInConf_1(VAL_AnInConf_1);
        doWrite_VALx_AnInFltr_1(VAL_AnInFltr_1);
        /* <-- Head AO1 + DO6 + DO8 */
        doWrite_PLC_AnOutConf_1(VAL_AnInConf_1);
        doWrite_PLC_AnOut_1(VAL_AnIn_1);
        doWrite_PLC_DigDir_6(1);
        doWrite_PLC_DigDir_8(1);
        switch (VAL_AnInConf_1)
        {
        case 1: doWrite_PLC_DigOut_8(1); doWrite_PLC_DigOut_6(0);
            break;
        case 2: doWrite_PLC_DigOut_8(0); doWrite_PLC_DigOut_6(0);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7: doWrite_PLC_DigOut_8(0); doWrite_PLC_DigOut_6(1);
            break;
        default: doWrite_PLC_DigOut_8(0); doWrite_PLC_DigOut_6(0);
            break;
        }
    }

    if (TST_AnIn_2)  {
        doWrite_TSTx_AnIn_2(true);
        doWrite_VALx_AnInConf_2(VAL_AnInConf_2);
        doWrite_VALx_AnInFltr_2(VAL_AnInFltr_2);
        /* <-- Head AO2 + DO5 + DO7 */
        doWrite_PLC_AnOutConf_2(VAL_AnInConf_2);
        doWrite_PLC_AnOut_2(VAL_AnIn_2);
        doWrite_PLC_DigDir_5(1);
        doWrite_PLC_DigDir_7(1);
        switch (VAL_AnInConf_2)
        {
        case 1: doWrite_PLC_DigOut_7(1); doWrite_PLC_DigOut_5(0);
            break;
        case 2: doWrite_PLC_DigOut_7(0); doWrite_PLC_DigOut_5(0);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7: doWrite_PLC_DigOut_7(0); doWrite_PLC_DigOut_5(1);
            break;
        default: doWrite_PLC_DigOut_7(0); doWrite_PLC_DigOut_5(0);
            break;
        }
    }

    if (TST_AnIn_3)  {
        doWrite_TSTx_AnIn_3(true);
        doWrite_VALx_AnInConf_3(VAL_AnInConf_3);
        doWrite_VALx_AnInFltr_3(VAL_AnInFltr_3);
        /* <-- Horn2 AO1 + DO6 + DO8 */
        doWrite_TST2_AnOut_1(1);
        doWrite_VAL2_AnOutConf_1(VAL_AnInConf_3);
        doWrite_VAL2_AnOut_1(VAL_AnIn_3);
        doWrite_TST2_DigOut_6(1);
        doWrite_TST2_DigOut_8(1);
        switch (VAL_AnInConf_3)
        {
        case 1: doWrite_VAL2_DigOut_8(1); doWrite_VAL2_DigOut_6(0);
            break;
        case 2: doWrite_VAL2_DigOut_8(0); doWrite_VAL2_DigOut_6(0);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7: doWrite_VAL2_DigOut_8(0); doWrite_VAL2_DigOut_6(1);
            break;
        default: doWrite_VAL2_DigOut_8(0); doWrite_VAL2_DigOut_6(0);
            break;
        }
    }

    if (TST_AnIn_4)  {
        doWrite_TSTx_AnIn_4(true);
        doWrite_VALx_AnInConf_4(VAL_AnInConf_4);
        doWrite_VALx_AnInFltr_6(VAL_AnInFltr_4);
        /* <-- Horn2 AO2 + DO5 + DO7 */
        doWrite_TST2_AnOut_2(1);
        doWrite_VAL2_AnOutConf_2(VAL_AnInConf_4);
        doWrite_VAL2_AnOut_3(VAL_AnIn_4);
        doWrite_TST2_DigOut_5(1);
        doWrite_TST2_DigOut_7(1);
        switch (VAL_AnInConf_4)
        {
        case 1: doWrite_VAL2_DigOut_7(1); doWrite_VAL2_DigOut_5(0);
            break;
        case 2: doWrite_VAL2_DigOut_7(0); doWrite_VAL2_DigOut_5(0);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7: doWrite_VAL2_DigOut_7(0); doWrite_VAL2_DigOut_5(1);
            break;
        default: doWrite_VAL2_DigOut_7(0); doWrite_VAL2_DigOut_5(0);
            break;
        }
    }

    if (TST_AnIn_5)  {
        doWrite_TSTx_AnIn_5(true);
        doWrite_VALx_AnInConf_5(VAL_AnInConf_5);
        doWrite_VALx_AnInFltr_5(VAL_AnInFltr_5);
        /* <-- Head/TPLC005 AO1 */
        doWrite_RTU_AnOut_1(VAL_AnIn_5);
        /* <-- Horn2 AO4 V : double for TPAC1007_4AB */
        doWrite_TST2_AnOut_4(1);
        doWrite_VAL2_AnOutConf_4(VAL_AnInConf_5);
        doWrite_VAL2_AnOut_4(VAL_AnIn_5);
    }
    if (TST_AnIn_6)  {
        doWrite_TSTx_AnIn_6(true);
        doWrite_VALx_AnInConf_6(VAL_AnInConf_6);
        doWrite_VALx_AnInFltr_6(VAL_AnInFltr_6);
        /* <-- Head/TPLC005 AO2 */
        doWrite_RTU_AnOut_2(VAL_AnIn_6);
    }
    if (TST_AnIn_7)  {
        doWrite_TSTx_AnIn_7(true);
        doWrite_VALx_AnInConf_7(VAL_AnInConf_7);
        doWrite_VALx_AnInFltr_7(VAL_AnInFltr_7);
        /* <-- Head/TPLC005 AO3 */
        doWrite_PLC_AnOut_3(VAL_AnIn_7);
    }
    if (TST_AnIn_8)  {
        doWrite_TSTx_AnIn_8(true);
        doWrite_VALx_AnInConf_8(VAL_AnInConf_8);
        doWrite_VALx_AnInFltr_8(VAL_AnInFltr_8);
        /* <-- Head/TPLC005 AO4 */
        doWrite_RTU_AnOut_4(VAL_AnIn_8);
    }
    if (TST_AnIn_9)  {
        doWrite_TSTx_AnIn_9(true);
        doWrite_VALx_AnInConf_9(VAL_AnInConf_9);
        doWrite_VALx_AnInFltr_9(VAL_AnInFltr_9);
        /* <-- Head/TPLC005 AO5*/
        doWrite_RTU_AnOut_5(VAL_AnIn_9);
    }
    if (TST_AnIn_10) {
        doWrite_TSTx_AnIn_10(true);
                doWrite_VALx_AnInConf_10(VAL_AnInConf_10);
        doWrite_VALx_AnInFltr_10(VAL_AnInFltr_10);
        /* <-- Head/TPLC005 AO6*/
        doWrite_RTU_AnOut_6(VAL_AnIn_10);
    }
    if (TST_AnIn_11) {
        doWrite_TSTx_AnIn_11(true);
                doWrite_VALx_AnInConf_11(VAL_AnInConf_11);
                doWrite_VALx_AnInFltr_11(VAL_AnInFltr_11);
                /* <-- Head/TPLC005 AO7*/
                doWrite_RTU_AnOut_7(VAL_AnIn_11);
    }
    if (TST_AnIn_12) {
        doWrite_TSTx_AnIn_12(true);
                doWrite_VALx_AnInConf_12(VAL_AnInConf_12);
                doWrite_VALx_AnInFltr_12(VAL_AnInFltr_12);
                /* <-- Head/TPLC005 AO8*/
                doWrite_RTU_AnOut_8(VAL_AnIn_12);
    }
}

void Translate_AnOut(void)
{

    if (TST_AnOut_1)  {
        doWrite_TSTx_AnOut_1(true);
        doWrite_VALx_AnOut_1(VAL_AnOut_1);
                doWrite_VALx_AnOutConf_1(VAL_AnOutConf_1);
                /* --> Horn2 AI1 + DO4 */
                doWrite_TST2_AnIn_1(1);
        doWrite_VAL2_AnInConf_1(VAL_AnOutConf_1);
                doWrite_VAL2_AnInFltr_1(16);
                doWrite_TST2_DigOut_4(1);
        switch (VAL_AnOutConf_1)
        {
        case 1: doWrite_VAL2_DigOut_4(1);
            break;
        case 2: doWrite_VAL2_DigOut_4(0);
            break;
        default:
            break;
        }
    }

    if (TST_AnOut_2)  {
        doWrite_TSTx_AnOut_2(true);
        doWrite_VALx_AnOut_2(VAL_AnOut_2);
                doWrite_VALx_AnOutConf_2(VAL_AnOutConf_2);
                /* --> Horn2 AI2 + DO3 */
                doWrite_TST2_AnIn_2(1);
        doWrite_VAL2_AnInConf_2(VAL_AnOutConf_2);
                doWrite_VAL2_AnInFltr_2(16);
                doWrite_TST2_DigOut_3(1);
        switch (VAL_AnOutConf_2)
        {
        case 1: doWrite_VAL2_DigOut_3(1);
            break;
        case 2: doWrite_VAL2_DigOut_3(0);
            break;
        default:
            break;
        }
    }

    if (TST_AnOut_3)  {
        doWrite_TSTx_AnOut_3(true);
        doWrite_VALx_AnOut_3(VAL_AnOut_3);
                doWrite_VALx_AnOutConf_3(VAL_AnOutConf_3);
                /* --> Head/TPLC005 AI1 */
                doWrite_PLC_AnInConf_1(VAL_AnOutConf_3);
    }

    if (TST_AnOut_4)  {
        doWrite_TSTx_AnOut_4(true);
        doWrite_VALx_AnOut_4(VAL_AnOut_4);
                doWrite_VALx_AnOutConf_4(VAL_AnOutConf_4);
                /* --> Head/TPLC005 AI2 */
                doWrite_PLC_AnInConf_2(VAL_AnOutConf_4);
    }

}

void Translate_Others(void)
{

    if (TST_Tamb)  {
        doWrite_TSTx_Tamb(true);
    }

    if (TST_RPM)  {
        doWrite_TSTx_RPM(true);
        /* <-- Horn2 AO3 PWM */
        doWrite_TST2_AnOut_3(1);
        doWrite_VAL2_AnOutConf_3(3); /* PWM */
        doWrite_VAL2_AnOut_3((int)(VAL_RPM)); /* FIXME: conversion ? */
    }

    if (TST_FWrevision)  {
        doWrite_TSTx_FWrevision(true);
    }

    if (TST_HWconfig) {
        doWrite_TSTx_HWconfig(true);
    }

    /* only from the testing equipment */
    if (TST_VCC_set) {
        /* --> Head AO3 V */
        doWrite_PLC_AnOutConf_3(2); /* 0..10 V */
        doWrite_PLC_AnOut_3(VAL_VCC_set); /* FIXME: conversion ? */
    }

    if (TST_mA_max) {
        /* --> Head AO4 V */
        doWrite_PLC_AnOutConf_4(2); /* 0..10 V */
        doWrite_PLC_AnOut_4(VAL_mA_max); /* FIXME: conversion ? */
    }

    if (TST_VCC_fbk) {
        /* --> Head AI1 V */
        doWrite_PLC_AnInConf_1(2); /* 0..10 V */
    }

    if (TST_mA_fbk) {
        /* --> Head AI2 V */
        doWrite_PLC_AnInConf_2(2); /* 0..10 V */
    }

}

void Check_DigIn(void)
{
    /* Get results */
    if (TST_DigIn_1 ) { doWrite_RES_DigIn_1(RESx_DigIn_1);  }
    if (TST_DigIn_2 ) { doWrite_RES_DigIn_2(RESx_DigIn_2);  }
    if (TST_DigIn_3 ) { doWrite_RES_DigIn_3(RESx_DigIn_3);  }
    if (TST_DigIn_4 ) { doWrite_RES_DigIn_4(RESx_DigIn_4);  }
    if (TST_DigIn_5 ) { doWrite_RES_DigIn_5(RESx_DigIn_5);  }
    if (TST_DigIn_6 ) { doWrite_RES_DigIn_6(RESx_DigIn_6);  }
    if (TST_DigIn_7 ) { doWrite_RES_DigIn_7(RESx_DigIn_7);  }
    if (TST_DigIn_8 ) { doWrite_RES_DigIn_8(RESx_DigIn_8);  }
    if (TST_DigIn_9 ) { doWrite_RES_DigIn_9(RESx_DigIn_9);  }
    if (TST_DigIn_10) { doWrite_RES_DigIn_10(RESx_DigIn_10); }
    if (TST_DigIn_11) { doWrite_RES_DigIn_11(RESx_DigIn_11); }
    if (TST_DigIn_12) { doWrite_RES_DigIn_12(RESx_DigIn_12); }
    if (TST_DigIn_13) { doWrite_RES_DigIn_13(RESx_DigIn_13); }
    if (TST_DigIn_14) { doWrite_RES_DigIn_14(RESx_DigIn_14); }
    if (TST_DigIn_15) { doWrite_RES_DigIn_15(RESx_DigIn_15); }
    if (TST_DigIn_16) { doWrite_RES_DigIn_16(RESx_DigIn_16); }

    /* Check values */
    if (TST_DigIn_1 ) { doWrite_OK_DigIn_1((RES_DigIn_1 == VAL_DigIn_1));  }
    if (TST_DigIn_2 ) { doWrite_OK_DigIn_2((RES_DigIn_2 == VAL_DigIn_2));  }
    if (TST_DigIn_3 ) { doWrite_OK_DigIn_3((RES_DigIn_3 == VAL_DigIn_3));  }
    if (TST_DigIn_4 ) { doWrite_OK_DigIn_4((RES_DigIn_4 == VAL_DigIn_4));  }
    if (TST_DigIn_5 ) { doWrite_OK_DigIn_5((RES_DigIn_5 == VAL_DigIn_5));  }
    if (TST_DigIn_6 ) { doWrite_OK_DigIn_6((RES_DigIn_6 == VAL_DigIn_6));  }
    if (TST_DigIn_7 ) { doWrite_OK_DigIn_7((RES_DigIn_7 == VAL_DigIn_7));  }
    if (TST_DigIn_8 ) { doWrite_OK_DigIn_8((RES_DigIn_8 == VAL_DigIn_8));  }
    if (TST_DigIn_9 ) { doWrite_OK_DigIn_9((RES_DigIn_9 == VAL_DigIn_9));  }
    if (TST_DigIn_10) { doWrite_OK_DigIn_10((RES_DigIn_10 == VAL_DigIn_10)); }
    if (TST_DigIn_11) { doWrite_OK_DigIn_11((RES_DigIn_11 == VAL_DigIn_11)); }
    if (TST_DigIn_12) { doWrite_OK_DigIn_12((RES_DigIn_12 == VAL_DigIn_12)); }
    if (TST_DigIn_13) { doWrite_OK_DigIn_13((RES_DigIn_13 == VAL_DigIn_13)); }
    if (TST_DigIn_14) { doWrite_OK_DigIn_14((RES_DigIn_14 == VAL_DigIn_14)); }
    if (TST_DigIn_15) { doWrite_OK_DigIn_15((RES_DigIn_15 == VAL_DigIn_15)); }
    if (TST_DigIn_16) { doWrite_OK_DigIn_16((RES_DigIn_16 == VAL_DigIn_16)); }

}

void Check_DigOut(void)
{

    /* Get results */
    if (TST_DigOut_1 ) { doWrite_RES_DigOut_1(RTU_DigIn_1);  }
    if (TST_DigOut_2 ) { doWrite_RES_DigOut_2(RTU_DigIn_2);  }
    if (TST_DigOut_3 ) { doWrite_RES_DigOut_3(RTU_DigIn_3);  }
    if (TST_DigOut_4 ) { doWrite_RES_DigOut_4(RTU_DigIn_4);  }
    if (TST_DigOut_5 ) { doWrite_RES_DigOut_5(RTU_DigIn_5);  }
    if (TST_DigOut_6 ) { doWrite_RES_DigOut_6(RTU_DigIn_6);  }
    if (TST_DigOut_7 ) { doWrite_RES_DigOut_7(RTU_DigIn_7);  }
    if (TST_DigOut_8 ) { doWrite_RES_DigOut_8(RTU_DigIn_8);  }
    if (TST_DigOut_9 ) { doWrite_RES_DigOut_9(RTU_DigIn_9);  }
    if (TST_DigOut_10) { doWrite_RES_DigOut_10(RTU_DigIn_10); }
    if (TST_DigOut_11) { doWrite_RES_DigOut_11(RTU_DigIn_11); }
    if (TST_DigOut_12) { doWrite_RES_DigOut_12(RTU_DigIn_12); }
    if (TST_DigOut_13) { doWrite_RES_DigOut_13(RTU_DigIn_13); }
    if (TST_DigOut_14) { doWrite_RES_DigOut_14(RTU_DigIn_14); }
    if (TST_DigOut_15) { doWrite_RES_DigOut_15(RTU_DigIn_15); }
    if (TST_DigOut_16) { doWrite_RES_DigOut_16(RTU_DigIn_16); }

    /* Check values */
    if (TST_DigOut_1 ) { doWrite_OK_DigOut_1((RES_DigOut_1 == VAL_DigOut_1));  }
    if (TST_DigOut_2 ) { doWrite_OK_DigOut_2((RES_DigOut_2 == VAL_DigOut_2));  }
    if (TST_DigOut_3 ) { doWrite_OK_DigOut_3((RES_DigOut_3 == VAL_DigOut_3));  }
    if (TST_DigOut_4 ) { doWrite_OK_DigOut_4((RES_DigOut_4 == VAL_DigOut_4));  }
    if (TST_DigOut_5 ) { doWrite_OK_DigOut_5((RES_DigOut_5 == VAL_DigOut_5));  }
    if (TST_DigOut_6 ) { doWrite_OK_DigOut_6((RES_DigOut_6 == VAL_DigOut_6));  }
    if (TST_DigOut_7 ) { doWrite_OK_DigOut_7((RES_DigOut_7 == VAL_DigOut_7));  }
    if (TST_DigOut_8 ) { doWrite_OK_DigOut_8((RES_DigOut_8 == VAL_DigOut_8));  }
    if (TST_DigOut_9 ) { doWrite_OK_DigOut_9((RES_DigOut_9 == VAL_DigOut_9));  }
    if (TST_DigOut_10) { doWrite_OK_DigOut_10((RES_DigOut_10 == VAL_DigOut_10)); }
    if (TST_DigOut_11) { doWrite_OK_DigOut_11((RES_DigOut_11 == VAL_DigOut_11)); }
    if (TST_DigOut_12) { doWrite_OK_DigOut_12((RES_DigOut_12 == VAL_DigOut_12)); }
    if (TST_DigOut_13) { doWrite_OK_DigOut_13((RES_DigOut_13 == VAL_DigOut_13)); }
    if (TST_DigOut_14) { doWrite_OK_DigOut_14((RES_DigOut_14 == VAL_DigOut_14)); }
    if (TST_DigOut_15) { doWrite_OK_DigOut_15((RES_DigOut_15 == VAL_DigOut_15)); }
    if (TST_DigOut_16) { doWrite_OK_DigOut_16((RES_DigOut_16 == VAL_DigOut_16)); }

}

void Check_AnIn(void)
{

    int Tolleranza = 1; /* 0.001 */

    /* Get results */
    if (TST_AnIn_1)  { doWrite_RES_AnIn_1 (RESx_AnIn_1);  }
    if (TST_AnIn_2)  { doWrite_RES_AnIn_2 (RESx_AnIn_2);  }
    if (TST_AnIn_3)  { doWrite_RES_AnIn_3 (RESx_AnIn_3);  }
    if (TST_AnIn_4)  { doWrite_RES_AnIn_4 (RESx_AnIn_4);  }

    if (TST_AnIn_5 ) { doWrite_RES_AnIn_5 (RESx_AnIn_5);  }
    if (TST_AnIn_6 ) { doWrite_RES_AnIn_6 (RESx_AnIn_6);  }
    if (TST_AnIn_7 ) { doWrite_RES_AnIn_7 (RESx_AnIn_7);  }
    if (TST_AnIn_8 ) { doWrite_RES_AnIn_8 (RESx_AnIn_8);  }
    if (TST_AnIn_9 ) { doWrite_RES_AnIn_9 (RESx_AnIn_9);  }
    if (TST_AnIn_10) { doWrite_RES_AnIn_10(RESx_AnIn_10);  }
    if (TST_AnIn_11) { doWrite_RES_AnIn_11(RESx_AnIn_11);  }
    if (TST_AnIn_12) { doWrite_RES_AnIn_12(RESx_AnIn_12);  }

    /* Check values */
    if (TST_AnIn_1 ) { doWrite_OK_AnIn_1 (abs(RES_AnIn_1  - VAL_AnIn_1 ) < Tolleranza); }
    if (TST_AnIn_2 ) { doWrite_OK_AnIn_2 (abs(RES_AnIn_2  - VAL_AnIn_2 ) < Tolleranza); }
    if (TST_AnIn_3 ) { doWrite_OK_AnIn_3 (abs(RES_AnIn_3  - VAL_AnIn_3 ) < Tolleranza); }
    if (TST_AnIn_4 ) { doWrite_OK_AnIn_4 (abs(RES_AnIn_4  - VAL_AnIn_4 ) < Tolleranza); }

    if (TST_AnIn_5 ) { doWrite_OK_AnIn_5 (abs(RES_AnIn_5  - VAL_AnIn_5 ) < Tolleranza); }
    if (TST_AnIn_6 ) { doWrite_OK_AnIn_6 (abs(RES_AnIn_6  - VAL_AnIn_6 ) < Tolleranza); }
    if (TST_AnIn_7 ) { doWrite_OK_AnIn_7 (abs(RES_AnIn_7  - VAL_AnIn_7 ) < Tolleranza); }
    if (TST_AnIn_8 ) { doWrite_OK_AnIn_8 (abs(RES_AnIn_8  - VAL_AnIn_8 ) < Tolleranza); }
    if (TST_AnIn_9 ) { doWrite_OK_AnIn_9 (abs(RES_AnIn_9  - VAL_AnIn_9 ) < Tolleranza); }
    if (TST_AnIn_10) { doWrite_OK_AnIn_10(abs(RES_AnIn_10 - VAL_AnIn_10) < Tolleranza); }
    if (TST_AnIn_11) { doWrite_OK_AnIn_11(abs(RES_AnIn_11 - VAL_AnIn_11) < Tolleranza); }
    if (TST_AnIn_12) { doWrite_OK_AnIn_12(abs(RES_AnIn_12 - VAL_AnIn_12) < Tolleranza); }

}

void Check_AnOut(void)
{
int Tolleranza = 1; /* 0.01 */

    /* Get results */
    if (TST_AnOut_1)  { doWrite_RES_AnOut_1(RES2_AnIn_1);  }
    if (TST_AnOut_2)  { doWrite_RES_AnOut_2(RES2_AnIn_2);  }
    if (TST_AnOut_3)  { doWrite_RES_AnOut_3(RTU_AnIn_1);  }
    if (TST_AnOut_4)  { doWrite_RES_AnOut_4(RTU_AnIn_2);  }

    /* Check values */
    if (TST_AnOut_1)  { doWrite_OK_AnOut_1(abs(RES_AnOut_1 - VAL_AnOut_1) < Tolleranza); }
    if (TST_AnOut_2)  { doWrite_OK_AnOut_2(abs(RES_AnOut_2 - VAL_AnOut_2) < Tolleranza); }
    if (TST_AnOut_3)  { doWrite_OK_AnOut_3(abs(RES_AnOut_3 - VAL_AnOut_3) < Tolleranza); }
    if (TST_AnOut_4)  { doWrite_OK_AnOut_4(abs(RES_AnOut_4 - VAL_AnOut_4) < Tolleranza); }

}

void Check_Others(void)
{
    int Tolleranza_Tamb_min = 10;
    int Tolleranza_RPM = 100;
    int Tolleranza_VCC_set = 10; /* 0.01 V */
    int Tolleranza_mA_max = 10; /* 0.01 mA */
    int Tolleranza_VCC_fbk = 100; /* 0.1 V */
    int Tolleranza_mA_fbk = 100; /* 0.1 mA */

    /* Get results */
    if (TST_Tamb)  { doWrite_RES_Tamb (RESx_Tamb);  }
    if (TST_RPM)   { doWrite_RES_RPM (RESx_RPM);  }

    if (TST_VCC_set)  { doWrite_RES_VCC_set (PLC_AnOut_3);  }
    if (TST_mA_max)  { doWrite_RES_mA_max (PLC_AnOut_4);  }

    if (TST_VCC_fbk)  { doWrite_RES_VCC_fbk (PLC_AnIn_1);  }
    if (TST_mA_fbk)  { doWrite_RES_mA_fbk (PLC_AnIn_2);  }

    if (TST_FWrevision)  { doWrite_RES_FWrevision (RESx_FWrevision);  }
    if (TST_HWconfig)  { doWrite_RES_HWconfig (RESx_HWconfig);  }

    /* Check values */
    if (TST_Tamb)  { doWrite_OK_Tamb ((Tolleranza_Tamb_min <= RES_Tamb) and (RES_Tamb < VAL_Tamb )); }
    if (TST_RPM)  { doWrite_OK_RPM (abs((int)(RES_RPM) - (int)(VAL_RPM) ) < Tolleranza_RPM); }

    if (TST_VCC_set)  { doWrite_OK_VCC_set (abs(RES_VCC_set  - VAL_VCC_set ) < Tolleranza_VCC_set); }
    if (TST_mA_max)  { doWrite_OK_mA_max (abs(RES_mA_max - VAL_mA_max ) < Tolleranza_mA_max); }

    if (TST_VCC_fbk)  { doWrite_OK_VCC_fbk (abs(RES_VCC_fbk  - VAL_VCC_fbk ) < Tolleranza_VCC_fbk); }
    if (TST_mA_fbk)  { doWrite_OK_mA_fbk(abs(RES_mA_fbk - VAL_mA_fbk ) < Tolleranza_mA_fbk); }

    if (TST_FWrevision)  { doWrite_OK_FWrevision ((RES_FWrevision  == VAL_FWrevision)); }
    if (TST_HWconfig)  { doWrite_OK_HWconfig ((RES_HWconfig == VAL_HWconfig)); }

}

void loop(void)
{
    switch (STATUS)
    {

    case 0: /* IDLE */
        if (DO_REMOTE)
        {
            doWrite_START2_REMOTE(true);  doWrite_STARTx_REMOTE(true);
            doWrite_START2_TEST(false);  doWrite_STARTx_TEST(false);
            doWrite_STATUS(1);
        }
        break;

    case 1: /* STARTING */
        if (STATUS2_REMOTE && STATUSx_REMOTE)
        {
            doWrite_STATUS(2);
        }
        break;

    case 2: /* READY */
        if (DO_TEST)
        {
            ClearResults();
            Translate_DigIn();
            Translate_DigOut();
            Translate_AnIn();
            Translate_AnOut();
            Translate_Others();
            /* FIXME: delay? */
            doWrite_START2_TEST(true);  doWrite_STARTx_TEST(true);
            doWrite_STATUS(3);
        }
        if (!DO_REMOTE)
        {
            doWrite_START2_REMOTE(false);  doWrite_STARTx_REMOTE(false);
            doWrite_STATUS(6);
        }
        break;

    case 3: /* TESTING */
        if (STATUS2_DONE && STATUSx_DONE)
        {
            Check_DigIn();
            Check_DigOut();
            Check_AnIn();
            Check_AnOut();
            Check_Others();
            doWrite_STATUS(4);
        }
        break;

    case 4: /* DONE */
        if (!DO_TEST)
        {
            doWrite_START2_TEST(false);  doWrite_STARTx_TEST(false);
            doWrite_STATUS(5);
        }
        break;

    case 5: /* RESETTING */
        if (STATUS2_REMOTE && STATUSx_REMOTE)
        {
            doWrite_STATUS(2);
        }
        break;

    case 6: /* STOPPING */
        if (!STATUS2_REMOTE && !STATUSx_REMOTE)
        {
            doWrite_STATUS(0);
        }
        break;

    default:
        /* FIXME: assert */
        break;
    }
}
