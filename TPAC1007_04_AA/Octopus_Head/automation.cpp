#include "app_logprint.h"
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

// LOCAL DIGITAL INPUTS
#define PLC_PWR_SWITCH PLC_DigIn_1
#define PLC_GO_BUTTON PLC_DigIn_4

// PRODUCT_NAMES <-- PRODUCT_ID
static char product_name[][15] = {
    /*00*/ "-",
    /*01*/ "TP1043_01_A"   ,
    /*02*/ "TP1043_01_B"   ,
    /*03*/ "TP1043_02_A"   ,
    /*04*/ "TP1043_02_B"   ,
    /*05*/ "TP1057_01_A"   ,
    /*06*/ "TP1057_01_B"   ,
    /*07*/ "TP1070_01_A"   ,
    /*08*/ "TP1070_01_B"   ,
    /*09*/ "TP1070_01_C"   ,
    /*10*/ "TPAC1005"      ,
    /*11*/ "TPAC1006"      ,
    /*12*/ "TPAC1007_03"   ,
    /*13*/ "TPAC1007_04_AA",
    /*14*/ "TPAC1007_04_AB",
    /*15*/ "TPAC1007_04_AC",
    /*16*/ "TPAC1007_LV"   ,
    /*17*/ "TPAC1008_01"   ,
    /*18*/ "TPAC1008_02_AA",
    /*19*/ "TPAC1008_02_AB",
    /*20*/ "TPAC1008_02_AD",
    /*21*/ "TPAC1008_02_AE",
    /*22*/ "TPAC1008_02_AF",
    /*23*/ "TPAC1008_03_AC",
    /*24*/ "TPLC050_01_AA" ,
    /*25*/ "TPLC100_01_AA" ,
    /*26*/ "TPLC100_01_AB" ,
    /*27*/
};
#define RECIPE_MAX 3
static char recipe_name[][RECIPE_MAX] = {"-", "1", "2", "3"};

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
static u_int16_t previous_RTU_Heartbeat;
static float previous_PLC_time;
static float last_PLC_time;
static page300 *thePage = NULL;

void setup(void)
{
    doWrite_RESULT(RESULT_UNKNOWN);
    previous_PLC_time = PLC_time;
    last_PLC_time = PLC_time;
    previous_PLC_Heartbeat = PLC_Heartbeat;
    previous_RTU_Heartbeat = RTU_HeartBeat;
}

void setTheWidget(page300 *p)
{
    thePage = p;
}

static int failed_writeRecipe = 0;
static int failed_checkRecipe = 0;
static int failed_doWrite = 0;

void update_message()
{
    char msg[255];

    sprintf(msg, "#%u@%u,%u: writeRecipe=%d, checkRecipe=%d, doWrite=%d",
            TEST_STEP, RESULTS_OK, RESULTS_NG,
            failed_writeRecipe, failed_checkRecipe, failed_doWrite);
    thePage->setMessage(msg);
}

void loop(void)
{
    static int substatus = 0;
    static int next_step = 0;

    if (thePage == NULL) {
        previous_PLC_Heartbeat = PLC_Heartbeat;
        last_PLC_time = PLC_time;
        previous_PLC_time = PLC_time;
        previous_RTU_Heartbeat = RTU_HeartBeat;
        return;
    }

    // fcrts UDP communication test @100 ms
    if (PLC_time == previous_PLC_time) {
        thePage->messageBox(RESULT_UNKNOWN, "PLC_time hangup :(\nWhat happened to fcrts?");
    }
    previous_PLC_time = PLC_time;

    // LPC RTU3 communication test @ 100ms
    if (previous_PLC_Heartbeat == PLC_Heartbeat) {
        thePage->messageBox(RESULT_UNKNOWN, "RTU3 hangup :(\nWhat happened to LPC?");
    }
    previous_PLC_Heartbeat = PLC_Heartbeat;

    // TPLC005 RTU0 communication test @ 1s
    if ((PLC_time - last_PLC_time) > 1.5) {
        if (previous_RTU_Heartbeat == RTU_HeartBeat) {
            thePage->messageBox(RESULT_UNKNOWN, "RTU0 hangup :(\nWhat happened to TPLC005?");
        }
        last_PLC_time = PLC_time;
        previous_RTU_Heartbeat = RTU_HeartBeat;
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
        case 1:
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
                        if (substatus == 0) {
                            if (RESULTS_OK == TEST_STEP_MAX && RESULTS_NG == 0) {
                                thePage->messageBox(RESULT_OK, "now PWR_OFF\nthen touch me");
                            } else if (RESULTS_NG > 0) {
                                thePage->messageBox(RESULT_NG, "now PWR_OFF\nthen touch me");
                            } else {
                                thePage->messageBox(RESULT_UNKNOWN, "now PWR_OFF\nthen touch me");
                            }
                        }
                        substatus = 1;
                        return;
                    }
                } else {
                    ++next_step;
                }
                logStart();
                doWrite_TEST_STEP(next_step);
                substatus = 10;
            }
            break;
        case 10:
            if (writeRecipe(0, &zeroesIndexes, zeroesTable) != 0) {
                fprintf(stderr, "writeRecipe(zeroes) failed, retry after 100ms");
                ++failed_writeRecipe;
                update_message();
            } else {
                substatus = 11;
            }
            break;
        case 11:
            substatus = 12;
            break;
        case 12:
            substatus = 13;
            break;
        case 13:
            if (! checkRecipe(0, &zeroesIndexes, zeroesTable)) {
                fprintf(stderr, "checkRecipe(zeroes) failed after 300 ms, rewrite after 100ms\n");
                ++failed_checkRecipe;
                update_message();
                substatus = 10;
            } else {
                substatus = 20;
            }
            break;
        case 20:
            if (writeRecipe(next_step - 1, &testsIndexes, testsTable) != 0) {
                fprintf(stderr, "writeRecipe(tests) failed, retry after 100ms\n");
                ++failed_writeRecipe;
                update_message();
            } else {
                substatus = 21;
            }
            break;
        case 21:
            substatus = 22;
            break;
        case 22:
            substatus = 23;
            break;
        case 23:
            if (! checkRecipe(next_step - 1, &testsIndexes, testsTable)) {
                fprintf(stderr, "checkRecipe(tests) failed after 300 ms, rewrite  after 100ms\n");
                ++failed_checkRecipe;
                update_message();
                substatus = 20;
            } else {
                substatus = 30;
            }
            break;
        case 30:
            if (writeRecipe(next_step - 1, &valuesIndexes, valuesTable) != 0) {
                fprintf(stderr, "writeRecipe(values) failed, retry after 100ms\n");
                ++failed_writeRecipe;
                update_message();
            } else {
                substatus = 31;
            }
            break;
        case 31:
            substatus = 32;
            break;
        case 32:
            substatus = 33;
            break;
        case 33:
            if (! checkRecipe(next_step - 1, &valuesIndexes, valuesTable)) {
                fprintf(stderr, "checkRecipe(values) failed after 300 ms, rewrite after 100ms\n");
                ++failed_checkRecipe;
                update_message();
                substatus = 30;
            } else {
                substatus = 40;
            }
            break;
        case 40:
            doWrite_STATUS(STATUS_TESTING);
            substatus = 41;
            break;
        case 41:
            fprintf(stderr, "check (STATUS==STATUS_TESTING) failed\n");
            ++failed_doWrite;
            update_message();
            substatus = 42;
        case 42:
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
    int z, t, v;

    // file: /local/data/recipe/Zeroes/0.csv
    snprintf(filename, 256, "%s/%s/%s.csv", RECIPE_DIR, "Zeroes", "0");
    z = loadRecipe(filename, &zeroesIndexes, zeroesTable);

    // file: /local/data/recipe/TPAC1007_4AA/2.csv
    snprintf(filename, 256, "%s/%s/%s.csv", RECIPE_DIR, product_name[PRODUCT_ID], recipe_name[TEST_ID]);
    t = loadRecipe(filename, &testsIndexes, testsTable);

    // file: /local/data/recipe/Values/2.csv
    snprintf(filename, 256, "%s/Values/%s.csv", RECIPE_DIR, recipe_name[TEST_ID]);
    v = loadRecipe(filename, &valuesIndexes, valuesTable);

    if (z == 1 && t > 0 && v > 0 && t == v) {
        doWrite_TEST_STEP_MAX(t);
        doWrite_DO_RELOAD(0);
    } else {
        doWrite_TEST_STEP_MAX(0);
    }
}
