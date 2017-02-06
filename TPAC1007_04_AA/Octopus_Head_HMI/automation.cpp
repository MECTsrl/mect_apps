#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "pagebrowser.h"
#include "crosstable.h"
#include "automation.h"
#include <QMessageBox>

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
#define PRODUCT_MAX 21
static char product_name[][15] = {
    /*00*/ "-",
    /*01*/ "TP1043_01_A",
    /*02*/ "TP1043_01_B",
    /*03*/ "TP1043_01_C",
    /*04*/ "TP1057_01_A",
    /*05*/ "TP1057_01_B",
    /*06*/ "TP1070_01_A",
    /*07*/ "TP1070_01_B",
    /*08*/ "TP1070_01_C",
    /*09*/ "TP1070_01_D",
    /*10*/ "TPAC1006",
    /*11*/ "TPAC1007_03",
    /*12*/ "TPAC1007_04_AA",
    /*13*/ "TPAC1007_04_AB",
    /*14*/ "TPAC1007_04_AC",
    /*15*/ "TPAC1007_LV",
    /*16*/ "TPAC1008_01",
    /*17*/ "TPAC1008_02_AA",
    /*18*/ "TPAC1008_02_AB",
    /*19*/ "TPAC1008_02_AC",
    /*20*/ "TPAC1008_02_AD",
    /*21*/ "TPAC1008_02_AE",
    /*22*/ "TPAC1008_02_AF"
};
#define RECIPE_MAX 2
static char recipe_name[][3] = {"-", "1", "2"};

#define abs(v) (((v) > 0)? (v):-(v))

// TST_... (Zeroes)
QList<u_int16_t> zeroesIndexes;
QList<u_int32_t> zeroesTable[MAX_RCP_STEP];
// TST_...
QList<u_int16_t> testsIndexes;
QList<u_int32_t> testsTable[MAX_RCP_STEP];
// VAL_...
QList<u_int16_t> valuesIndexes;
QList<u_int32_t> valuesTable[MAX_RCP_STEP];

static void doReload();
extern int checkRecipe(int step, QList<u_int16_t> *indexes, QList<u_int32_t> table[]);

static u_int16_t previous_PLC_Heartbeat;
static float previous_PLC_time;
static float last_PLC_time;
static page300 *thePage = NULL;

void setup(void)
{
    doWrite_RESULT(RESULT_UNKNOWN);
    previous_PLC_Heartbeat = PLC_Heartbeat;
    previous_PLC_time = PLC_time;
    last_PLC_time = PLC_time;
}

void setTheWidget(page300 *p)
{
    thePage = p;
}

void loop(void)
{
    static int substatus = 0;
    static int next_step = 0;

    if (previous_PLC_Heartbeat == PLC_Heartbeat) {
        if ((PLC_time - last_PLC_time) > 1.0) {
            if (thePage) {
                thePage->messageBox("RTU3 hangup :(", "What happened?");
            }
        }
    } else {
        previous_PLC_Heartbeat = PLC_Heartbeat;
        last_PLC_time = PLC_time;
        if (previous_PLC_time == PLC_time) {
            if (thePage) {
                thePage->messageBox("PLC_time hangup :(", "What happened?");
            }
        } else {
            previous_PLC_time = PLC_time;
        }
    }

    switch (STATUS) {   // OCTOPUS STATE MACHINE

    case STATUS_IDLE:
        /* this state is managed in PLC */
        logStop();
        if (DO_RELOAD) {
            doReload();
            sleep(1); // just for viewing the led change
        }
        substatus = 0;
        break;

    case STATUS_STARTING:
        /* this state is managed in PLC */
        logStop();
        substatus = 0;
        break;

    case STATUS_READY:
        if (!PLC_PWR_SWITCH) {
            doWrite_STATUS(STATUS_STOPPING);
            return;
        }
        if (DO_RELOAD) {
            doReload();
            substatus = 0;
            return;
        }
        if (TEST2_STATUS != TEST_STATUS_REMOTE || TESTx_STATUS != TEST_STATUS_REMOTE) {
            doWrite_STATUS(STATUS_STARTING);
            substatus = 0;
            return;
        }
        switch (substatus) {
        case 0:
            if (AUTOMATIC || PLC_GO_BUTTON) {
                if (TEST_STEP_MAX == 0) {
                    return;
                }
                // next step
                next_step = TEST_STEP;
                if (next_step >= TEST_STEP_MAX) {
                    if (DO_REPEAT) {
                        next_step = 1;
                    } else {
                        logStop();
                        if (RESULTS_OK == TEST_STEP_MAX && RESULTS_NG == 0) {
                            if (thePage) {
                                thePage->messageBox("TEST RESULT", "RESULT = OK\n\nnow PWR_OFF then touch OK");
                            }
                        }
                        return;
                    }
                } else {
                    ++next_step;
                }
                logStart();
                doWrite_TEST_STEP(next_step);
                substatus = 1;
            }
            break;
        case 1:
            if (writeRecipe(next_step - 1, &zeroesIndexes, zeroesTable) != 0) {
                fprintf(stderr, "writeRecipe(zeroes) failed, retry after 100ms\n");
            } else {
                substatus = 101;
            }
            break;
        case 101:
            substatus = 102;
            break;
        case 102:
            if (! checkRecipe(next_step - 1, &zeroesIndexes, zeroesTable)) {
                fprintf(stderr, "checkRecipe(zeroes) failed, retry writeRecipe()\n");
                substatus = 1;
            } else {
                substatus = 2;
            }
            break;
        case 2:
            if (writeRecipe(next_step - 1, &testsIndexes, testsTable) != 0) {
                fprintf(stderr, "writeRecipe(tests) failed, retry after 100ms\n");
            } else {
                substatus = 201;
            }
            break;
        case 201:
            substatus = 202;
            break;
        case 202:
            if (! checkRecipe(next_step - 1, &testsIndexes, testsTable)) {
                fprintf(stderr, "checkRecipe(tests) failed, retry writeRecipe()\n");
                substatus = 2;
            } else {
                substatus = 3;
            }
            break;
        case 3:
            if (writeRecipe(next_step - 1, &valuesIndexes, valuesTable) != 0) {
                fprintf(stderr, "writeRecipe(values) failed, retry after 100ms\n");
            } else {
                substatus = 301;
            }
            break;
        case 301:
            substatus = 302;
            break;
        case 302:
            if (! checkRecipe(next_step - 1, &valuesIndexes, valuesTable)) {
                fprintf(stderr, "checkRecipe(values) failed, retry writeRecipe()\n");
                substatus = 3;
            } else {
                substatus = 4;
            }
            break;
        case 4:
            doWrite_STATUS(STATUS_TESTING);
            substatus = 401;
            break;
        case 401:
            substatus = 402;
        case 402:
            fprintf(stderr, "check (STATUS==STATUS_TESTING) failed, retry doWrite()\n");
            substatus = 4;
            break;
        case 5:
            break;
        default:
            substatus = 0;
        }
        break;

    case STATUS_ERROR:
        if (!PLC_PWR_SWITCH) {
            doWrite_STATUS(STATUS_STOPPING);
            return;
        }
        if (PLC_GO_BUTTON) {
            doWrite_TEST2_COMMAND(TEST_STATUS_LOCAL);
            doWrite_TESTx_COMMAND(TEST_STATUS_LOCAL);
            doWrite_RESULT(RESULT_UNKNOWN);
            doWrite_STATUS(STATUS_RESETTING);
            return;
        }
        substatus = 0;
        break;

    case STATUS_TESTING:
        /* this state is managed in PLC */
        substatus = 0;
        break;

    case STATUS_DONE:
        /* this state is managed in PLC */
        substatus = 0;
        break;

    case STATUS_RESETTING:
        /* this state is managed in PLC */
        substatus = 0;
        break;

    case STATUS_STOPPING:
        /* this state is managed in PLC */
        logStop();
        substatus = 0;
        break;

    default:
        substatus = 0;
    }
}

static void doReload()
{
    char filename[256];
    int t, v;

    // file: /local/data/recipe/Zeroes/0.csv
    snprintf(filename, 256, "%s/%s/%s.csv", RECIPE_DIR, "Zeroes", "0");
    t = loadRecipe(filename, &zeroesIndexes, zeroesTable);

    // file: /local/data/recipe/TPAC1007_4AA/2.csv
    snprintf(filename, 256, "%s/%s/%s.csv", RECIPE_DIR, product_name[PRODUCT_ID], recipe_name[TEST_ID]);
    t = loadRecipe(filename, &testsIndexes, testsTable);

    // file: /local/data/recipe/Values/2.csv
    snprintf(filename, 256, "%s/Values/%s.csv", RECIPE_DIR, recipe_name[TEST_ID]);
    v = loadRecipe(filename, &valuesIndexes, valuesTable);

    if (t == v && t > 0 && v > 0) {
        doWrite_TEST_STEP_MAX(t);
        doWrite_DO_RELOAD(0);
    } else {
        doWrite_TEST_STEP_MAX(0);
    }
}
