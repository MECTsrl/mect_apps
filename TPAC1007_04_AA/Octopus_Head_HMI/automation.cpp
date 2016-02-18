#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "pagebrowser.h"
#include "crosstable.h"
#include "automation.h"

// OCTOPUS STATUS
#define STATUS_IDLE       0
#define STATUS_STARTING   1
#define STATUS_READY      2
#define STATUS_TESTING    3
#define STATUS_DONE       4
#define STATUS_RESETTING  5
#define STATUS_STOPPING   6
#define STATUS_ERROR      7

// TEST_STATUS
#define TEST_STATUS_LOCAL  0x0000
#define TEST_STATUS_REMOTE 0x00D8
#define TEST_STATUS_DONE   0x002A

// RESULT VALUES
#define RESULT_UNKNOWN  -1
#define RESULT_NG       0
#define RESULT_OK       1

// LOCAL DIGITAL INPUTS
#define PLC_PWR_SWITCH PLC_DigIn_1
#define PLC_GO_BUTTON PLC_DigIn_4

// PRODUCT_NAMES <-- PRODUCT_ID
#define PRODUCT_MAX 10
static char product_name[][20] = {
    "-",
    "TPAC1007_4AA", "TPAC1007_3", "TPLC100", "TPAC1006", "TPAC1008",
    "TP1043_485", "TP1043_232", "TP1043_CAN", "9"
};
#define RECIPE_MAX 2
static char recipe_name[][3] = {"-", "1", "2"};

#define abs(v) (((v) > 0)? (v):-(v))
#define MAX_STEP 64
QList<u_int16_t> ctIndexList;
QList<u_int32_t> valuesTable[MAX_STEP];

static void loadRecipe(void);
static void clearTST(void);
static int writeRecipe(int step);

void setup(void)
{
    doWrite_RESULT(RESULT_UNKNOWN);
}

void loop(void)
{
    switch (STATUS) {   // OCTOPUS STATE MACHINE

    case STATUS_IDLE:
        /* this state is managed in PLC */
        if (DO_RELOAD) {
            loadRecipe();
            doWrite_DO_RELOAD(0);
            sleep(1); // just for viewing the led change
        }
        break;

    case STATUS_STARTING:
        /* this state is managed in PLC */
        break;

    case STATUS_READY:
        if (!PLC_PWR_SWITCH) {
            doWrite_STATUS(STATUS_STOPPING);
            return;
        }
        if (DO_RELOAD) {
            loadRecipe();
            sleep(1); // just for viewing the led change
            doWrite_DO_RELOAD(0);
        }
        if (TEST2_STATUS != TEST_STATUS_REMOTE || TESTx_STATUS != TEST_STATUS_REMOTE) {
            doWrite_STATUS(STATUS_STARTING);
            return;
        }
        if (AUTOMATIC || PLC_GO_BUTTON) {
            int next_step;
            if (TEST_STEP_MAX == 0) {
                return;
            }
            // next step
            next_step = TEST_STEP;
            if (next_step >= TEST_STEP_MAX) {
                if (DO_REPEAT) {
                    next_step = 1;
                } else {
                    return;
                }
            } else {
                ++next_step;
            }
            doWrite_TEST_STEP(next_step);
            // no sleep, we change state
            clearTST();
            if (writeRecipe(next_step - 1) != 0) {
                doWrite_STATUS(STATUS_ERROR);
                sleep(1); // FIXME: HMI/PLC protocol
                return;
            }
            doWrite_STATUS(STATUS_TESTING);
            sleep(1); // FIXME: HMI/PLC protocol
            return;
        }
        break;

    case STATUS_ERROR:
        if (!PLC_PWR_SWITCH) {
            doWrite_STATUS(STATUS_STOPPING);
            sleep(1); // FIXME: HMI/PLC protocol
            return;
        }
        if (PLC_GO_BUTTON) {
            doWrite_TEST2_COMMAND(TEST_STATUS_LOCAL);
            doWrite_TESTx_COMMAND(TEST_STATUS_LOCAL);
            doWrite_RESULT(RESULT_UNKNOWN);
            doWrite_STATUS(STATUS_RESETTING);
            sleep(1); // FIXME: HMI/PLC protocol
            return;
        }
        break;

    case STATUS_TESTING:
        /* this state is managed in PLC */
        break;

    case STATUS_DONE:
        /* this state is managed in PLC */
        break;

    case STATUS_RESETTING:
        /* this state is managed in PLC */
        break;

    case STATUS_STOPPING:
        /* this state is managed in PLC */
        break;

    default:
        ;
    }
}

/*
 * tag1; val1; val2 ... valn
 * ...
 * tagm; val1; val2 ... valn
 */
static void loadRecipe(void)
{
    char filename[256];
    FILE * fp;

    // clear lists
    ctIndexList.clear();
    for (int n = 0; n < MAX_STEP; ++n) {
        valuesTable[n].clear();
    }
    if (PRODUCT_ID == 0 || PRODUCT_ID >= PRODUCT_MAX
      || TEST_ID == 0 || TEST_ID > RECIPE_MAX) {
        return;
    }
    snprintf(filename, 256, "%s/%s/%s.csv", RECIPE_DIR, product_name[PRODUCT_ID], recipe_name[TEST_ID]);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        LOG_PRINT(info_e, "Cannot open '%s'\n", filename.toAscii().data());
        return;
    }
    char varname[TAG_LEN] = "";
    char token[LINE_SIZE] = "";
    char line[LINE_SIZE] = "";
    char * p;
    int step = 0;
    for (int line_nb = 0; fgets(line, LINE_SIZE, fp) != NULL; line_nb++)
    {
        p = line;
        if (line[0] == '\n' || line[0] == '\r' || line[0] == 0) {
            continue;
        }
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
        step = 0;
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
                    float val_float = atof(token);
                    for (int n = 0; n < varNameArray[ctIndex].decimal; ++n) {
                        val_float = val_float * 10;
                    }
                    int16_t val_int16 = (u_int16_t)val_float;
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
                    float val_float = atof(token);
                    for (int n = 0; n < varNameArray[ctIndex].decimal; ++n) {
                        val_float = val_float * 10;
                    }
                    int32_t val_int32 = atoi(token);
                    memcpy(&value, &val_int32, sizeof(u_int32_t));
                    break;
                }
                case fabcd_e:
                case fbadc_e:
                case fcdab_e:
                case fdcba_e:
                {
                    float val_float = atof(token);
                    memcpy(&value, &val_float, sizeof(u_int32_t));
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
    doWrite_TEST_STEP_MAX(step);
}

static int writeRecipe(int step)
{
    int errors = 0;

    if (step >= MAX_STEP)
    {
        errors = -1;
    }
    else
    {
        beginWrite();
        for (int i = 0; i < valuesTable[step].count(); i++)
        {
            u_int16_t addr = ctIndexList.at(i);
            u_int32_t value = valuesTable[step].at(i);
            errors += addWrite(addr, &value);
        }
        endWrite();
        sleep(1); // FIXME: HMI/PLC protocol
    }
    return errors;
}

static void clearTST(void)
{
    beginWrite();

    addWrite_TST_DigIn_1(0);
    addWrite_TST_DigIn_2(0);
    addWrite_TST_DigIn_3(0);
    addWrite_TST_DigIn_4(0);
    addWrite_TST_DigIn_5(0);
    addWrite_TST_DigIn_6(0);
    addWrite_TST_DigIn_7(0);
    addWrite_TST_DigIn_8(0);
    addWrite_TST_DigIn_9(0);
    addWrite_TST_DigIn_10(0);
    addWrite_TST_DigIn_11(0);
    addWrite_TST_DigIn_12(0);
    addWrite_TST_DigIn_13(0);
    addWrite_TST_DigIn_14(0);
    addWrite_TST_DigIn_15(0);
    addWrite_TST_DigIn_16(0);

    addWrite_TST_DigOut_1(0);
    addWrite_TST_DigOut_2(0);
    addWrite_TST_DigOut_3(0);
    addWrite_TST_DigOut_4(0);
    addWrite_TST_DigOut_5(0);
    addWrite_TST_DigOut_6(0);
    addWrite_TST_DigOut_7(0);
    addWrite_TST_DigOut_8(0);
    addWrite_TST_DigOut_9(0);
    addWrite_TST_DigOut_10(0);
    addWrite_TST_DigOut_11(0);
    addWrite_TST_DigOut_12(0);
    addWrite_TST_DigOut_13(0);
    addWrite_TST_DigOut_14(0);
    addWrite_TST_DigOut_15(0);
    addWrite_TST_DigOut_16(0);

    addWrite_TST_AnIn_1(0);
    addWrite_TST_AnIn_2(0);
    addWrite_TST_AnIn_3(0);
    addWrite_TST_AnIn_4(0);
    addWrite_TST_AnIn_5(0);
    addWrite_TST_AnIn_6(0);
    addWrite_TST_AnIn_7(0);
    addWrite_TST_AnIn_8(0);
    addWrite_TST_AnIn_9(0);
    addWrite_TST_AnIn_10(0);
    addWrite_TST_AnIn_11(0);
    addWrite_TST_AnIn_12(0);

    addWrite_TST_AnOut_1(0);
    addWrite_TST_AnOut_2(0);
    addWrite_TST_AnOut_3(0);
    addWrite_TST_AnOut_4(0);

    addWrite_TST_Tamb(0);
    addWrite_TST_RPM(0);
    addWrite_TST_VCC_set(0);
    addWrite_TST_mA_max(0);
    addWrite_TST_VCC_fbk(0);
    addWrite_TST_mA_fbk(0);
    addWrite_TST_FWrevision(0);
    addWrite_TST_HWconfig(0);

    addWrite_TST_RTUS_WR(0);
    addWrite_TST_RTUS_RD(0);
    addWrite_TST_RTU1_WR(0);
    addWrite_TST_RTU1_RD(0);
    addWrite_TST_RTU3_WR(0);
    addWrite_TST_RTU3_RD(0);
    addWrite_TST_CAN1_WR(0);
    addWrite_TST_CAN1_RD(0);

    endWrite();
    sleep(1); // FIXME: HMI/PLC protocol
}
