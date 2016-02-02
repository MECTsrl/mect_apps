#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "pagebrowser.h"
#include "crosstable.h"
#include "automation.h"
#include <QDir>

#define STATUS_UNKNOWN  999
#define STATUS_IDLE       0
#define STATUS_STARTING   1
#define STATUS_READY      2
#define STATUS_TESTING    3
#define STATUS_DONE       4
#define STATUS_RESETTING  5
#define STATUS_STOPPING   6
#define STATUS_ERROR      7

#define RESULT_UNKNOWN  -1
#define RESULT_NG       0
#define RESULT_OK       1

#define PLC_PWR_SWITCH PLC_DigIn_1
#define PLC_GO_BUTTON PLC_DigIn_4

#define abs(v) (((v) > 0)? (v):-(v))
static void clearOK(void);
static void clearRES(void);
static void writeTST(void);
static void writeVAL(void);
static void readRES(void);
static void checkOK(void);
static int allTestedOK(void);

static int writeRecipe(int step);
static QStringList recipeList;
static QString dirname;

void setup(void)
{
    doWrite_PLC_DigDir_1(0); // PLC_PWR_SWITCH
    doWrite_PLC_DigDir_2(1); // PLC_VPOT_ON
    doWrite_PLC_DigDir_3(1); // PLC_VCC_ON
    doWrite_PLC_DigDir_4(0); // PLC_GO_BUTTON
    doWrite_RTU_AnOutConf_X(5); // ANALOG OUTPUT THRESHOLD
    // reset 2
    doWrite_START2_REMOTE(false);
    doWrite_START2_TEST(false);
    recipeList.clear();
    // automation entry point
    doWrite_STATUS(STATUS_UNKNOWN);
    doWrite_RESULT(RESULT_UNKNOWN);
}

void loop(void)
{
    static unsigned substatus = 0;

    /*************************/
    /* OCTOPUS STATE MACHINE */
    /*************************/

    switch (STATUS) {

    case STATUS_UNKNOWN:
        if (!PLC_PWR_SWITCH) {
            doWrite_START2_REMOTE(false);
            doWrite_STARTx_REMOTE(false);
            doWrite_STATUS(STATUS_STOPPING);
            break;
        }
        doWrite_STATUS(STATUS_IDLE);
        break;

    case STATUS_IDLE:
        if (PLC_PWR_SWITCH) {
            doWrite_PLC_DigOut_2(1); // PLC_VPOT_ON
            doWrite_PLC_DigOut_3(1); // PLC_VCC_ON
            doWrite_START2_REMOTE(true);
            doWrite_STARTx_REMOTE(true);
            doWrite_START2_TEST(false);
            doWrite_STARTx_TEST(false);
            doWrite_TEST_STEP(0);
            doWrite_STATUS(STATUS_STARTING);
        }
        break;

    case STATUS_STARTING:
        if (!PLC_PWR_SWITCH) {
            doWrite_START2_REMOTE(false);
            doWrite_STARTx_REMOTE(false);
            doWrite_STATUS(STATUS_STOPPING);
            break;
        }
        if (STATUS2_REMOTE && STATUSx_REMOTE) {
            doWrite_STATUS(STATUS_READY);
            break;
        }
        // do repeat write: TPAC still booting
        doWrite_STARTx_REMOTE(true);
        doWrite_STARTx_TEST(false);
        break;

    case STATUS_READY:
        if (!PLC_PWR_SWITCH) {
            doWrite_START2_REMOTE(false);
            doWrite_STARTx_REMOTE(false);
            doWrite_STATUS(STATUS_STOPPING);
            break;
        }
        if (AUTOMATIC || PLC_GO_BUTTON) {
            // trivial case
            if (TEST_STEP_MAX == 0) {
                // Nothing to do
                break;
            }
            // next step
            int next_step = TEST_STEP + 1;
            if (next_step > TEST_STEP_MAX) {
                if (!REPEAT) {
                    break;
                }
                next_step = 1;
            }
            doWrite_TEST_STEP(next_step);
            if (writeRecipe(next_step - 1) != 0)
            {
                doWrite_STATUS(STATUS_ERROR);
                break;
            }

            // prepare data
            clearOK();
            clearRES();
            writeTST();
            writeVAL();
            // change state
            doWrite_START2_TEST(true);
            doWrite_STARTx_TEST(true);
            doWrite_STATUS(STATUS_TESTING);
            substatus = 0;
        }
        break;

    case STATUS_TESTING:
        if (!PLC_PWR_SWITCH) {
            doWrite_START2_REMOTE(false);
            doWrite_STARTx_REMOTE(false);
            doWrite_STATUS(STATUS_STOPPING);
            break;
        }
        if (!START2_TEST) {
            doWrite_START2_TEST(true);
        }
        if (!STARTx_TEST) {
            doWrite_STARTx_TEST(true);
        }
        if (STATUS2_DONE && STATUSx_DONE) {
            switch(substatus) {
            case 0:
                readRES();
                substatus = 1;
                break;
            case 1:
            case 2:
                ++substatus;
                break;
            case 3:
                checkOK();
                if (allTestedOK()) {
                    doWrite_RESULT(RESULT_OK);
                } else {
                    doWrite_RESULT(RESULT_NG);
                }
                doWrite_STATUS(STATUS_DONE);
                break;
            default:
                ; // FIXME: assert
            }
        }
        break;

    case STATUS_ERROR:
        if (!PLC_PWR_SWITCH) {
            doWrite_START2_REMOTE(false);
            doWrite_STARTx_REMOTE(false);
            doWrite_RESULT(RESULT_UNKNOWN);
            doWrite_STATUS(STATUS_STOPPING);
            break;
        }
        if (PLC_GO_BUTTON) {
            doWrite_START2_TEST(false);
            doWrite_STARTx_TEST(false);
            doWrite_RESULT(RESULT_UNKNOWN);
            doWrite_STATUS(STATUS_RESETTING);
        }
        break;

    case STATUS_DONE:
        if (!PLC_PWR_SWITCH) {
            doWrite_START2_REMOTE(false);
            doWrite_STARTx_REMOTE(false);
            doWrite_RESULT(RESULT_UNKNOWN);
            doWrite_STATUS(STATUS_STOPPING);
            break;
        }
        if (AUTOMATIC || PLC_GO_BUTTON) {
            doWrite_START2_TEST(false);
            doWrite_STARTx_TEST(false);
            doWrite_RESULT(RESULT_UNKNOWN);
            doWrite_STATUS(STATUS_RESETTING);
        }
        break;

    case STATUS_RESETTING:
        if (!PLC_PWR_SWITCH) {
            doWrite_START2_REMOTE(false);
            doWrite_STARTx_REMOTE(false);
            doWrite_STATUS(STATUS_STOPPING);
            break;
        }
        if (STATUS2_REMOTE && STATUSx_REMOTE) {
            doWrite_STATUS(STATUS_READY);
        }
        break;

    case STATUS_STOPPING:
        if (!STATUSx_REMOTE) {
            doWrite_PLC_DigOut_2(0); // PLC_VPOT_ON
            doWrite_PLC_DigOut_3(0); // PLC_VCC_ON
        }
        if (!STATUS2_REMOTE && !STATUSx_REMOTE) {
            doWrite_STATUS(STATUS_IDLE);
        }
        break;

    default:
        ; /* FIXME: assert */
    }
}

void setProduct(char *name)
{
    dirname = QString(RECIPE_DIR) + QString("/") + QString(name);
    QDir recipeDir(dirname, "*.csv");
    recipeList = recipeDir.entryList(QDir::Files);
    doWrite_TEST_STEP(0);
    doWrite_TEST_STEP_MAX(recipeList.count());
    if (recipeList.count() <= 0)
    {
        doWrite_STATUS(STATUS_ERROR);
    }
    // load recipe
    else if (loadRecipe(dirname + QString("/") + recipeList.at(TEST_ID - 1)) < 0) {
        doWrite_STATUS(STATUS_ERROR);
    }
}

#define MAX_STEP 64
QList<u_int16_t> ctIndexList;
QList<u_int32_t> valuesTable[MAX_STEP];

/*
 * tag1; val1; val2 ... valn
 * ...
 * tagm; val1; val2 ... valn
 */
int loadRecipe(const QString filename)
{
    FILE * fp = fopen(filename.toAscii().data(), "r");
    if (fp == NULL)
    {
        LOG_PRINT(info_e, "Cannot open '%s'\n", filename.toAscii().data());
        return -1;
    }
    char varname[TAG_LEN] = "";
    char token[LINE_SIZE] = "";
    char line[MAX_LINE] = "";
    char * p;
    for (int line_nb = 0; fgets(line, LINE_SIZE, fp) != NULL; line_nb++)
    {
        p = line;
        /* tag */
        p = mystrtok(p, varname, SEPARATOR);
        if (p == NULL || varname[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s' at line %d\n", line, line_nb);
            continue;
        }
        int ctIndex;
        if (Tag2CtIndex(varname, &ctIndex))
        {
            LOG_PRINT(error_e, "Invalid variable '%s' at line %d\n", varname, line_nb);
            continue;
        }
        ctIndexList << (u_int16_t)ctIndex;

        /* values */
        int step = 0;
        do
        {
            u_int32_t value;
            p = mystrtok(p, token, SEPARATOR);
            if (token[0] != '\0')
            {
                switch (varNameArray[ctIndex].type)
                {
                case uintab_e:
                case uintba_e:
                case intab_e:
                case intba_e:
                {
                    u_int16_t val_int16 = atoi(token);
                    value = (u_int32_t)val_int16;
                    break;
                }
                case udint_abcd_e:
                case udint_badc_e:
                case udint_cdab_e:
                case udint_dcba_e:
                case dint_abcd_e:
                case dint_badc_e:
                case dint_cdab_e:
                case dint_dcba_e:
                {
                    u_int32_t val_int32 = atoi(token);
                    value = (u_int32_t)val_int32;
                    break;
                }
                case fabcd_e:
                case fbadc_e:
                case fcdab_e:
                case fdcba_e:
                {
                    float val_float = atof(token);
                    value = (u_int32_t)val_float;
                    break;
                }
                case bytebit_e:
                case wordbit_e:
                case dwordbit_e:
                case bit_e:
                {
                    u_int8_t val_bit = atoi(token);
                    value = (u_int32_t)val_bit;
                    break;
                }
                default:
                    /* unknown type */
                    break;
                }
            }
            (valuesTable[step]) << value;
            step++;
        }
        while(p != NULL);
    }
    fclose(fp);
    return 0;
}

static int writeRecipe(int step)
{
    int errors = 0;
    for (int i = 0; i < valuesTable[step].count(); i++)
    {
        int ctIndex = ctIndexList.at(i);
        errors += doWrite(ctIndex, &(valuesTable[step][ctIndex]));
    }
    return errors;
}

static void clearOK(void)
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

static void clearRES(void)
{
    doWrite_RES_DigIn_1(-1);
    doWrite_RES_DigIn_2(-1);
    doWrite_RES_DigIn_3(-1);
    doWrite_RES_DigIn_4(-1);
    doWrite_RES_DigIn_5(-1);
    doWrite_RES_DigIn_6(-1);
    doWrite_RES_DigIn_7(-1);
    doWrite_RES_DigIn_8(-1);
    doWrite_RES_DigIn_9(-1);
    doWrite_RES_DigIn_10(-1);
    doWrite_RES_DigIn_11(-1);
    doWrite_RES_DigIn_12(-1);
    doWrite_RES_DigIn_13(-1);
    doWrite_RES_DigIn_14(-1);
    doWrite_RES_DigIn_15(-1);
    doWrite_RES_DigIn_16(-1);

    doWrite_RES_DigOut_1(-1);
    doWrite_RES_DigOut_2(-1);
    doWrite_RES_DigOut_3(-1);
    doWrite_RES_DigOut_4(-1);
    doWrite_RES_DigOut_5(-1);
    doWrite_RES_DigOut_6(-1);
    doWrite_RES_DigOut_7(-1);
    doWrite_RES_DigOut_8(-1);
    doWrite_RES_DigOut_9(-1);
    doWrite_RES_DigOut_10(-1);
    doWrite_RES_DigOut_11(-1);
    doWrite_RES_DigOut_12(-1);
    doWrite_RES_DigOut_13(-1);
    doWrite_RES_DigOut_14(-1);
    doWrite_RES_DigOut_15(-1);
    doWrite_RES_DigOut_16(-1);

    doWrite_RES_AnIn_1(-32768);
    doWrite_RES_AnIn_2(-32768);
    doWrite_RES_AnIn_3(-32768);
    doWrite_RES_AnIn_4(-32768);
    doWrite_RES_AnIn_5(-32768);
    doWrite_RES_AnIn_6(-32768);
    doWrite_RES_AnIn_7(-32768);
    doWrite_RES_AnIn_8(-32768);
    doWrite_RES_AnIn_9(-32768);
    doWrite_RES_AnIn_10(-32768);
    doWrite_RES_AnIn_11(-32768);
    doWrite_RES_AnIn_12(-32768);

    doWrite_RES_AnOut_1(-32768);
    doWrite_RES_AnOut_2(-32768);
    doWrite_RES_AnOut_3(-32768);
    doWrite_RES_AnOut_4(-32768);

    doWrite_RES_Tamb(-32768);
    doWrite_RES_RPM(-32768);
    doWrite_RES_VCC_set(-32768);
    doWrite_RES_mA_max(32767);
    doWrite_RES_VCC_fbk(-32768);
    doWrite_RES_mA_fbk(32767);
    doWrite_RES_FWrevision(32767);
    doWrite_RES_HWconfig(32767);

    doWrite_RES_RTUS_WR(-1);
    doWrite_RES_RTUS_RD(-1);
    doWrite_RES_RTU1_WR(-1);
    doWrite_RES_RTU1_RD(-1);
    doWrite_RES_RTU3_WR(-1);
    doWrite_RES_RTU3_RD(-1);
    doWrite_RES_CAN1_WR(-1);
    doWrite_RES_CAN1_RD(-1);
}

static void writeTST(void)
{
    // we test the DigIn 1..16 by the TPLC005 16DO module
    doWrite_TSTx_DigIn_1 (TST_DigIn_1 );
    doWrite_TSTx_DigIn_2 (TST_DigIn_2 );
    doWrite_TSTx_DigIn_3 (TST_DigIn_3 );
    doWrite_TSTx_DigIn_4 (TST_DigIn_4 );
    doWrite_TSTx_DigIn_5 (TST_DigIn_5 );
    doWrite_TSTx_DigIn_6 (TST_DigIn_6 );
    doWrite_TSTx_DigIn_7 (TST_DigIn_7 );
    doWrite_TSTx_DigIn_8 (TST_DigIn_8 );
    doWrite_TSTx_DigIn_9 (TST_DigIn_9 );
    doWrite_TSTx_DigIn_10(TST_DigIn_10);
    doWrite_TSTx_DigIn_11(TST_DigIn_11);
    doWrite_TSTx_DigIn_12(TST_DigIn_12);
    doWrite_TSTx_DigIn_13(TST_DigIn_13);
    doWrite_TSTx_DigIn_14(TST_DigIn_14);
    doWrite_TSTx_DigIn_15(TST_DigIn_15);
    doWrite_TSTx_DigIn_16(TST_DigIn_16);
    // no doWrite_TST2_DigIn_*

    // we test the DigOut 1..16 by the TPLC005 16DI module
    doWrite_TSTx_DigOut_1 (TST_DigOut_1 );
    doWrite_TSTx_DigOut_2 (TST_DigOut_2 );
    doWrite_TSTx_DigOut_3 (TST_DigOut_3 );
    doWrite_TSTx_DigOut_4 (TST_DigOut_4 );
    doWrite_TSTx_DigOut_5 (TST_DigOut_5 );
    doWrite_TSTx_DigOut_6 (TST_DigOut_6 );
    doWrite_TSTx_DigOut_7 (TST_DigOut_7 );
    doWrite_TSTx_DigOut_8 (TST_DigOut_8 );
    doWrite_TSTx_DigOut_9 (TST_DigOut_9 );
    doWrite_TSTx_DigOut_10(TST_DigOut_10);
    doWrite_TSTx_DigOut_11(TST_DigOut_11);
    doWrite_TSTx_DigOut_12(TST_DigOut_12);
    doWrite_TSTx_DigOut_13(TST_DigOut_13);
    doWrite_TSTx_DigOut_14(TST_DigOut_14);
    doWrite_TSTx_DigOut_15(TST_DigOut_15);
    doWrite_TSTx_DigOut_16(TST_DigOut_16);
    // no doWrite_TST2_DigOut_*

    // we test the AnIn 1..2 by the local AnOut 1..2 and local DigOut 5..8
    doWrite_TSTx_AnIn_1(TST_AnIn_1);
    doWrite_TSTx_AnIn_2(TST_AnIn_2);

    // we test the AnIn 3..4 by the Horn TPAC1007_4AA AnOut 1..2 and local DigOut 5..8
    doWrite_TSTx_AnIn_3(TST_AnIn_3);
    doWrite_TST2_AnOut_1(TST_AnIn_3);
    doWrite_TST2_DigOut_6(TST_AnIn_3);
    doWrite_TST2_DigOut_8(TST_AnIn_3);

    doWrite_TSTx_AnIn_4(TST_AnIn_4);
    doWrite_TST2_AnOut_2(TST_AnIn_4);
    doWrite_TST2_DigOut_5(TST_AnIn_4);
    doWrite_TST2_DigOut_7(TST_AnIn_4);

    // we test the AnIn 5..12 (PT100 only) by the TPLC005 8AO module (actually internal 8DO)
    doWrite_TST2_AnOut_4(TST_AnIn_5); // only TPAC1007_AB
    doWrite_TSTx_AnIn_5(TST_AnIn_5);
    doWrite_TSTx_AnIn_6(TST_AnIn_6);
    doWrite_TSTx_AnIn_7(TST_AnIn_7);
    doWrite_TSTx_AnIn_8(TST_AnIn_8);
    doWrite_TSTx_AnIn_9(TST_AnIn_9);
    doWrite_TSTx_AnIn_10(TST_AnIn_10);
    doWrite_TSTx_AnIn_11(TST_AnIn_11);
    doWrite_TSTx_AnIn_12(TST_AnIn_12);

    // we test the AnOut 1..2 by both the local AnIn 1..2 and the Horn TPAC1007_4AA AnIn 1..2 and local DigOut 3..4
    doWrite_TSTx_AnOut_1(TST_AnOut_1);
    doWrite_TST2_AnIn_1(TST_AnOut_1);
    doWrite_TST2_DigOut_4(TST_AnOut_1);

    doWrite_TSTx_AnOut_2(TST_AnOut_2);
    doWrite_TST2_AnIn_2(TST_AnOut_2);
    doWrite_TST2_DigOut_3(TST_AnOut_2);

    // we test the AnOut 3..4 by the by the TPLC005 internal 2AI
    doWrite_TSTx_AnOut_3(TST_AnOut_3);
    doWrite_TSTx_AnOut_4(TST_AnOut_4);

    // we test the Others I/O ...
    doWrite_TSTx_Tamb(TSTx_Tamb);
    doWrite_TSTx_RPM(TSTx_RPM);
    doWrite_TSTx_FWrevision(TSTx_FWrevision);
    doWrite_TSTx_HWconfig(TSTx_HWconfig);
    doWrite_TST2_AnOut_3(TST_RPM);
}

static void writeVAL(void)
{
    // DigIn 1..16 are on the TPLC005 in local RTU
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

    // DigOut 1..16 are on the local TPLC005
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
    if (TST_AnIn_1)  {
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
        }
    }
    if (TST_AnIn_2)  {
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
        }
    }
    if (TST_AnIn_3)  {
        doWrite_VALx_AnInConf_3(VAL_AnInConf_3);
        doWrite_VALx_AnInFltr_3(VAL_AnInFltr_3);
        /* <-- Horn2 AO1 + DO6 + DO8 */
        doWrite_VAL2_AnOutConf_1(VAL_AnInConf_3);
        doWrite_VAL2_AnOut_1(VAL_AnIn_3);
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
        }
    }
    if (TST_AnIn_4)  {
        doWrite_VALx_AnInConf_4(VAL_AnInConf_4);
        doWrite_VALx_AnInFltr_6(VAL_AnInFltr_4);
        /* <-- Horn2 AO2 + DO5 + DO7 */
        doWrite_VAL2_AnOutConf_2(VAL_AnInConf_4);
        doWrite_VAL2_AnOut_3(VAL_AnIn_4);
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
        doWrite_VALx_AnInConf_5(VAL_AnInConf_5);
        doWrite_VALx_AnInFltr_5(VAL_AnInFltr_5);
        /* <-- Head/TPLC005 AO1 */
        doWrite_RTU_AnOut_1(VAL_AnIn_5);
        /* <-- Horn2 AO4 V : double for TPAC1007_4AB */
        doWrite_VAL2_AnOutConf_4(VAL_AnInConf_5);
        doWrite_VAL2_AnOut_4(VAL_AnIn_5);
    }
    if (TST_AnIn_6)  {
        doWrite_VALx_AnInConf_6(VAL_AnInConf_6);
        doWrite_VALx_AnInFltr_6(VAL_AnInFltr_6);
        /* <-- Head/TPLC005 AO2 */
        doWrite_RTU_AnOut_2(VAL_AnIn_6);
    }
    if (TST_AnIn_7)  {
        doWrite_VALx_AnInConf_7(VAL_AnInConf_7);
        doWrite_VALx_AnInFltr_7(VAL_AnInFltr_7);
        /* <-- Head/TPLC005 AO3 */
        doWrite_PLC_AnOut_3(VAL_AnIn_7);
    }
    if (TST_AnIn_8)  {
        doWrite_VALx_AnInConf_8(VAL_AnInConf_8);
        doWrite_VALx_AnInFltr_8(VAL_AnInFltr_8);
        /* <-- Head/TPLC005 AO4 */
        doWrite_RTU_AnOut_4(VAL_AnIn_8);
    }
    if (TST_AnIn_9)  {
        doWrite_VALx_AnInConf_9(VAL_AnInConf_9);
        doWrite_VALx_AnInFltr_9(VAL_AnInFltr_9);
        /* <-- Head/TPLC005 AO5*/
        doWrite_RTU_AnOut_5(VAL_AnIn_9);
    }
    if (TST_AnIn_10) {
        doWrite_VALx_AnInConf_10(VAL_AnInConf_10);
        doWrite_VALx_AnInFltr_10(VAL_AnInFltr_10);
        /* <-- Head/TPLC005 AO6*/
        doWrite_RTU_AnOut_6(VAL_AnIn_10);
    }
    if (TST_AnIn_11) {
        doWrite_VALx_AnInConf_11(VAL_AnInConf_11);
        doWrite_VALx_AnInFltr_11(VAL_AnInFltr_11);
        /* <-- Head/TPLC005 AO7*/
        doWrite_RTU_AnOut_7(VAL_AnIn_11);
    }
    if (TST_AnIn_12) {
        doWrite_VALx_AnInConf_12(VAL_AnInConf_12);
        doWrite_VALx_AnInFltr_12(VAL_AnInFltr_12);
        /* <-- Head/TPLC005 AO8*/
        doWrite_RTU_AnOut_8(VAL_AnIn_12);
    }

    if (TST_AnOut_1)  {
        doWrite_VALx_AnOut_1(VAL_AnOut_1);
        doWrite_VALx_AnOutConf_1(VAL_AnOutConf_1);
        /* --> Horn2 AI1 + DO4 */
        doWrite_VAL2_AnInConf_1(VAL_AnOutConf_1);
        doWrite_VAL2_AnInFltr_1(16);
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
        doWrite_VALx_AnOut_2(VAL_AnOut_2);
        doWrite_VALx_AnOutConf_2(VAL_AnOutConf_2);
        /* --> Horn2 AI2 + DO3 */
        doWrite_VAL2_AnInConf_2(VAL_AnOutConf_2);
        doWrite_VAL2_AnInFltr_2(16);
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
        doWrite_VALx_AnOut_3(VAL_AnOut_3);
        doWrite_VALx_AnOutConf_3(VAL_AnOutConf_3);
        /* --> Head/TPLC005 AI1 */
        doWrite_PLC_AnInConf_1(VAL_AnOutConf_3);
    }
    if (TST_AnOut_4)  {
        doWrite_VALx_AnOut_4(VAL_AnOut_4);
        doWrite_VALx_AnOutConf_4(VAL_AnOutConf_4);
        /* --> Head/TPLC005 AI2 */
        doWrite_PLC_AnInConf_2(VAL_AnOutConf_4);
    }

    if (TST_Tamb)  {
    }
    if (TST_RPM)  {
        /* <-- Horn2 AO3 PWM */
        doWrite_VAL2_AnOutConf_3(3); /* PWM */
        doWrite_VAL2_AnOut_3((int)(VAL_RPM)); /* FIXME: conversion ? */
    }
    if (TST_FWrevision)  {
    }
    if (TST_HWconfig) {
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

static void readRES(void)
{
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

    if (TST_AnOut_1)  { doWrite_RES_AnOut_1(RES2_AnIn_1);  }
    if (TST_AnOut_2)  { doWrite_RES_AnOut_2(RES2_AnIn_2);  }

    if (TST_AnOut_3)  { doWrite_RES_AnOut_3(RTU_AnIn_1);  }
    if (TST_AnOut_4)  { doWrite_RES_AnOut_4(RTU_AnIn_2);  }

    if (TST_Tamb)  { doWrite_RES_Tamb (RESx_Tamb);  }
    if (TST_RPM)   { doWrite_RES_RPM (RESx_RPM);  }

    if (TST_VCC_set)  { doWrite_RES_VCC_set (PLC_AnOut_3);  }
    if (TST_mA_max)  { doWrite_RES_mA_max (PLC_AnOut_4);  }

    if (TST_VCC_fbk)  { doWrite_RES_VCC_fbk (PLC_AnIn_1);  }
    if (TST_mA_fbk)  { doWrite_RES_mA_fbk (PLC_AnIn_2);  }

    if (TST_FWrevision)  { doWrite_RES_FWrevision (RESx_FWrevision);  }
    if (TST_HWconfig)  { doWrite_RES_HWconfig (RESx_HWconfig);  }}

static void checkOK(void)
{
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

    int Tolleranza_AnIn = 1; /* 0.001 */

    if (TST_AnIn_1 ) { doWrite_OK_AnIn_1 (abs(RES_AnIn_1  - VAL_AnIn_1 ) < Tolleranza_AnIn); }
    if (TST_AnIn_2 ) { doWrite_OK_AnIn_2 (abs(RES_AnIn_2  - VAL_AnIn_2 ) < Tolleranza_AnIn); }
    if (TST_AnIn_3 ) { doWrite_OK_AnIn_3 (abs(RES_AnIn_3  - VAL_AnIn_3 ) < Tolleranza_AnIn); }
    if (TST_AnIn_4 ) { doWrite_OK_AnIn_4 (abs(RES_AnIn_4  - VAL_AnIn_4 ) < Tolleranza_AnIn); }

    if (TST_AnIn_5 ) { doWrite_OK_AnIn_5 (abs(RES_AnIn_5  - VAL_AnIn_5 ) < Tolleranza_AnIn); }
    if (TST_AnIn_6 ) { doWrite_OK_AnIn_6 (abs(RES_AnIn_6  - VAL_AnIn_6 ) < Tolleranza_AnIn); }
    if (TST_AnIn_7 ) { doWrite_OK_AnIn_7 (abs(RES_AnIn_7  - VAL_AnIn_7 ) < Tolleranza_AnIn); }
    if (TST_AnIn_8 ) { doWrite_OK_AnIn_8 (abs(RES_AnIn_8  - VAL_AnIn_8 ) < Tolleranza_AnIn); }
    if (TST_AnIn_9 ) { doWrite_OK_AnIn_9 (abs(RES_AnIn_9  - VAL_AnIn_9 ) < Tolleranza_AnIn); }
    if (TST_AnIn_10) { doWrite_OK_AnIn_10(abs(RES_AnIn_10 - VAL_AnIn_10) < Tolleranza_AnIn); }
    if (TST_AnIn_11) { doWrite_OK_AnIn_11(abs(RES_AnIn_11 - VAL_AnIn_11) < Tolleranza_AnIn); }
    if (TST_AnIn_12) { doWrite_OK_AnIn_12(abs(RES_AnIn_12 - VAL_AnIn_12) < Tolleranza_AnIn); }

    int Tolleranza_AnOut = 1; /* 0.01 */

    if (TST_AnOut_1)  { doWrite_OK_AnOut_1(abs(RES_AnOut_1 - VAL_AnOut_1) < Tolleranza_AnOut); }
    if (TST_AnOut_2)  { doWrite_OK_AnOut_2(abs(RES_AnOut_2 - VAL_AnOut_2) < Tolleranza_AnOut); }

    if (TST_AnOut_3)  { doWrite_OK_AnOut_3(abs(RES_AnOut_3 - VAL_AnOut_3) < Tolleranza_AnOut); }
    if (TST_AnOut_4)  { doWrite_OK_AnOut_4(abs(RES_AnOut_4 - VAL_AnOut_4) < Tolleranza_AnOut); }

    int Tolleranza_Tamb_min = 10;
    int Tolleranza_RPM = 100;
    int Tolleranza_VCC_set = 10; /* 0.01 V */
    int Tolleranza_mA_max = 10; /* 0.01 mA */
    int Tolleranza_VCC_fbk = 100; /* 0.1 V */
    int Tolleranza_mA_fbk = 100; /* 0.1 mA */

    if (TST_Tamb)  { doWrite_OK_Tamb ((Tolleranza_Tamb_min <= RES_Tamb) and (RES_Tamb < VAL_Tamb )); }
    if (TST_RPM)  { doWrite_OK_RPM (abs((int)(RES_RPM) - (int)(VAL_RPM) ) < Tolleranza_RPM); }

    if (TST_VCC_set)  { doWrite_OK_VCC_set (abs(RES_VCC_set  - VAL_VCC_set ) < Tolleranza_VCC_set); }
    if (TST_mA_max)  { doWrite_OK_mA_max (abs(RES_mA_max - VAL_mA_max ) < Tolleranza_mA_max); }

    if (TST_VCC_fbk)  { doWrite_OK_VCC_fbk (abs(RES_VCC_fbk  - VAL_VCC_fbk ) < Tolleranza_VCC_fbk); }
    if (TST_mA_fbk)  { doWrite_OK_mA_fbk(abs(RES_mA_fbk - VAL_mA_fbk ) < Tolleranza_mA_fbk); }

    if (TST_FWrevision)  { doWrite_OK_FWrevision ((RES_FWrevision  == VAL_FWrevision)); }
    if (TST_HWconfig)  { doWrite_OK_HWconfig ((RES_HWconfig == VAL_HWconfig)); }

}

static int allTestedOK(void)
{
    int result = true;

    if (TST_DigIn_1 ) { result &=  OK_DigIn_1; }
    if (TST_DigIn_2 ) { result &=  OK_DigIn_2; }
    if (TST_DigIn_3 ) { result &=  OK_DigIn_3; }
    if (TST_DigIn_4 ) { result &=  OK_DigIn_4; }
    if (TST_DigIn_5 ) { result &=  OK_DigIn_5; }
    if (TST_DigIn_6 ) { result &=  OK_DigIn_6; }
    if (TST_DigIn_7 ) { result &=  OK_DigIn_7; }
    if (TST_DigIn_8 ) { result &=  OK_DigIn_8; }
    if (TST_DigIn_9 ) { result &=  OK_DigIn_9; }
    if (TST_DigIn_10) { result &=  OK_DigIn_10; }
    if (TST_DigIn_11) { result &=  OK_DigIn_11; }
    if (TST_DigIn_12) { result &=  OK_DigIn_12; }
    if (TST_DigIn_13) { result &=  OK_DigIn_13; }
    if (TST_DigIn_14) { result &=  OK_DigIn_14; }
    if (TST_DigIn_15) { result &=  OK_DigIn_15; }
    if (TST_DigIn_16) { result &=  OK_DigIn_16; }

    if (TST_DigOut_1 ) { result &=  OK_DigOut_1; }
    if (TST_DigOut_2 ) { result &=  OK_DigOut_2; }
    if (TST_DigOut_3 ) { result &=  OK_DigOut_3; }
    if (TST_DigOut_4 ) { result &=  OK_DigOut_4; }
    if (TST_DigOut_5 ) { result &=  OK_DigOut_5; }
    if (TST_DigOut_6 ) { result &=  OK_DigOut_6; }
    if (TST_DigOut_7 ) { result &=  OK_DigOut_7; }
    if (TST_DigOut_8 ) { result &=  OK_DigOut_8; }
    if (TST_DigOut_9 ) { result &=  OK_DigOut_9; }
    if (TST_DigOut_10) { result &=  OK_DigOut_10; }
    if (TST_DigOut_11) { result &=  OK_DigOut_11; }
    if (TST_DigOut_12) { result &=  OK_DigOut_12; }
    if (TST_DigOut_13) { result &=  OK_DigOut_13; }
    if (TST_DigOut_14) { result &=  OK_DigOut_14; }
    if (TST_DigOut_15) { result &=  OK_DigOut_15; }
    if (TST_DigOut_16) { result &=  OK_DigOut_16; }

    if (TST_AnIn_1 ) { result &=  OK_AnIn_1; }
    if (TST_AnIn_2 ) { result &=  OK_AnIn_2; }
    if (TST_AnIn_3 ) { result &=  OK_AnIn_3; }
    if (TST_AnIn_4 ) { result &=  OK_AnIn_4; }
    if (TST_AnIn_5 ) { result &=  OK_AnIn_5; }
    if (TST_AnIn_6 ) { result &=  OK_AnIn_6; }
    if (TST_AnIn_7 ) { result &=  OK_AnIn_7; }
    if (TST_AnIn_8 ) { result &=  OK_AnIn_8; }
    if (TST_AnIn_9 ) { result &=  OK_AnIn_9; }
    if (TST_AnIn_10) { result &=  OK_AnIn_10; }
    if (TST_AnIn_11) { result &=  OK_AnIn_11; }
    if (TST_AnIn_12) { result &=  OK_AnIn_12; }

    if (TST_AnOut_1 ) { result &=  OK_AnOut_1; }
    if (TST_AnOut_2 ) { result &=  OK_AnOut_2; }
    if (TST_AnOut_3 ) { result &=  OK_AnOut_3; }
    if (TST_AnOut_4 ) { result &=  OK_AnOut_4; }

    if (TST_Tamb ) { result &=  OK_Tamb; }
    if (TST_RPM ) { result &=  OK_RPM; }
    if (TST_VCC_set ) { result &=  OK_VCC_set; }
    if (TST_mA_fbk ) { result &=  OK_mA_fbk; }
    if (TST_FWrevision ) { result &=  OK_FWrevision; }
    if (TST_HWconfig ) { result &=  OK_HWconfig; }

    return result;
}
