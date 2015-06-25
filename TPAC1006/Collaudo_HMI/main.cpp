/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief HMI Main function
 */
#include <QApplication>
#include <QDate>
#include <QFile>
#include <getopt.h>

#include "common.h"
#include "app_cfg_file.h"
#include "app_logprint.h"
#ifdef ENABLE_USB
#include "app_usb.h"
#endif
#include "app_var_list.h"
#include "cross_table_utility.h"
#include "main.h"
#include "page0.h"

#ifdef TARGET
#include <QWSServer>
#ifdef ENABLE_SCREENSAVER
#include "screensaver.h"
#endif
#endif

/* prototype */
int readCfgFile(void);
int writeCfgFile(void);

/* global variables */
unsigned short int FirstCy = 0;

/** @brief variables used for the change page management */
QStack<page *> History;
QHash<QString, page *> ScreenHash;

/** @brief variables used for the USB interface */
#ifdef ENABLE_USB
int USBfeedback[2];
int USBstatus[APP_USB_MAX + 1];
char usb_mnt_point[FILENAME_MAX] = "";
#endif

#ifdef TRANSLATION
char _language_[3] = DEFAULT_LANGUAGE;
QTranslator* translator;
#endif

/* IO LAYERS */
/** @brief io layer to syncronize the data with the PLC */
io_layer_comm * ioComm;

/* Logger */
#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
Logger * logger;
int LogPeriodSecS = LOG_PERIOD_MS / 1000;
int LogPeriodSecF = LOG_PERIOD_MS / 1000;
int MaxWindowSec = MAX_SAMPLE_NB * ((LogPeriodSecF>LogPeriodSecS)?LogPeriodSecF:LogPeriodSecS);
QDateTime StoreInit;
QDateTime StoreFinal;
int MaxLogUsageMb = DEFAULT_MAX_MB;
bool ForceResetAlarmBanner = false;
#endif
#ifdef ENABLE_ALARMS
QList<event_descr_e *> _active_alarms_events_;
bool HornACK = false;
#endif

char HomePage[PAGE_NAME_LEN] = "";
char StartPage[PAGE_NAME_LEN] = "";

#ifdef ENABLE_STORE
char _actual_store_[FILENAME_MAX] = "";
#endif
#ifdef ENABLE_TREND
QStringList _current_trend_variables_;
char _actual_trend_[FILENAME_MAX] = "";
pen_t pens[PEN_NB + 1];
int actualPen = 0;
char _layout_ = LANDSCAPE;
char _last_layout_ = LANDSCAPE;
bool _online_ = true;
/* first time sample of visible data actually */
QDateTime actualTzero;
/* windows size in seconds of visible data actually */
int actualVisibleWindowSec = 0;
bool _trend_data_reload_ = true;
#endif
#ifdef ENABLE_RECIPE
char _actual_recipe_[FILENAME_MAX] = "";
#endif

QHash<char *, int *> NameMap;

/**
 * @section Serial paramenters
 */
/**
 * @brief Bauderate array
 */
int BaudRateArray[7] =
{
    9600,
    14400,
    19200,
    28800,
    38400,
    57600,
    115200
};

/**
 * @brief Stop bit array
 */
int StopBitArray[2] =
{
    1,
    2
};

/**
 * @brief Bit number array
 */
int BitNbArray[4] =
{
    5,
    6,
    7,
    8
};

/**
 * @brief Parity array
 */
char ParityArray[3][8] =
{
    "none",
    "even", /*pari*/
    "odd",  /*dispari*/
};

/**
 * @brief Parity array
 */
char ParityArrayShort[3] =
{
    'N',
    'E', /*pari*/
    'O',  /*dispari*/
};

int FailNb = MBMAXRETRY_DEFAULT;
int FailDivisor = MBERRORRATE_DEFAULT;
int HighPriorityTimerMsec;
int MediumPriorityTimerMsec;
int LowPriorityTimerMsec;


char RTUDevice[FILENAME_MAX] = RTU_DEVICE;
int BaudRate = MBBAUD_DEFAULT;
char Parity = 'N';
int DataBit = MBBITNB_DEFAULT;
int StopBit = MBSTOP_DEFAULT;
int QueryIntervalRTU = MBDELAY_DEFAULT;
int TimeoutRTU = MBTIMEOUT_DEFAULT;

char IpTCP[32] =  "127.0.0.1";
int PortTCP = 0;
int QueryIntervalTCP = 100;
int TimeoutTCP = MBTIMEOUT_DEFAULT;

char IpTCPRTU[32] = "127.0.0.1";
int PortTCPRTU = 0;
int QueryIntervalTCPRTU = 100;
int TimeoutTCPRTU = MBTIMEOUT_DEFAULT;

#ifdef ENABLE_SCREENSAVER
int ScreenSaverSec = 0;
#endif

int Buzzerfd = -1;
bool BuzzerTouch = true;
bool BuzzerAlarm = true;
struct timespec LastTouch = { 0 ,0 };

/**
 * @brief value and description Passwords array and actual password level
 */
int passwords[PASSWORD_NB + 1] = {0,0,0,0};
char PasswordsString[PASSWORD_NB + 1][TAG_LEN] = {"Admin", "SuperUser", "User", "None"};
int active_password = pwd_operator_e;

int PwdTimeoutSec = 0;
char PwdLogoutPage[PAGE_NAME_LEN] = "";

QHash<QString, QString> TagTable;

/* Long options */
static struct option long_options[] = {
    {"version", no_argument,        NULL, 'v'},
    {"qt", no_argument,        NULL, 'q'},
    {"qt", no_argument,        NULL, 'w'},
    {"qt", no_argument,        NULL, 's'},
    {"qt", no_argument,        NULL, 'd'},
    {"qt", no_argument,        NULL, 'i'},
    {"qt", no_argument,        NULL, 'p'},
    {"qt", no_argument,        NULL, 'l'},
    {"qt", no_argument,        NULL, 'a'},
    {"qt", no_argument,        NULL, 'y'},
    {NULL,      no_argument,        NULL,  0}
};

/*
 * Short options.
 * FIXME: KEEP THEIR LETTERS IN SYNC WITH THE RETURN VALUE
 * FROM THE LONG OPTIONS!
 */
static char short_options[] = "vqwsdiplay";

static int application_options(int argc, char *argv[])
{
    int option_index = 0;
    int c = 0;
    
    if (argc <= 0)
        return 0;
    
    if (argv == NULL)
        return 1;
    
    while ((c = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (c) {
        case 'v':
            printf("%s version: %s\n", argv[0], VERSION);
            exit(0);
            break;
        default:
            break;
        }
    }
    
    return 0;
}

/**
 * @brief main
 */
int main(int argc, char *argv[])
{
    if (application_options(argc, argv) != 0) {
        LOG_PRINT(error_e, "%s: command line option error.\n", __func__);
        
        return 1;
    }
    
    /* print the version */
    LOG_PRINT_NO_INFO(info_e, "#######################\n");
    LOG_PRINT_NO_INFO(info_e, "# Version: %10s #\n", VERSION);
    LOG_PRINT_NO_INFO(info_e, "#######################\n");
    
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(atcmicons);
    
#ifdef TARGET
    /* set the cursor as invisible */
    QWSServer::setCursorVisible(false);
    
    /* load the background to show at QWS */
    QPixmap background;
    
    background.load(BACKGROUND_FILE);
    QWSServer::setBackground(background);
#endif
    
    /* prepare the directory tree */
#ifdef ENABLE_ALARMS
    mkdir(ALARMS_DIR, S_IRWXU | S_IRWXG);
#endif
#if defined(ENABLE_TREND) || defined(ENABLE_STORE)
    mkdir(STORE_DIR, S_IRWXU | S_IRWXG);
    mkdir(CUSTOM_STORE_DIR, S_IRWXU | S_IRWXG);
    mkdir(CUSTOM_TREND_DIR, S_IRWXU | S_IRWXG);
#endif
#if defined(ENABLE_TREND)
    mkdir(SCREENSHOT_DIR, S_IRWXU | S_IRWXG);
#endif
#ifdef RECIPE_DIR
    mkdir(RECIPE_DIR, S_IRWXU | S_IRWXG);
#endif
    
    /* load the saved configuration value */
    readCfgFile();
    /* dump the value (if is the first time write the default value */
    writeCfgFile();
    
    /* initialize the usb API */
#ifdef ENABLE_USB
    app_usb_init();
#endif
    
#if defined(TARGET) && defined(ENABLE_SCREENSAVER)
    /* Set up screen saver */
    QWSServer::setScreenSaver( new ScreenSaver );
    QWSServer::setScreenSaverInterval(ScreenSaverSec * 1000); //msec
    QWSServer::setScreenSaverBlockLevel(0);
#endif
#ifdef TRANSLATION
    /* if a language is not set, set italian as default */
    if (strlen(_language_) == 0)
    {
        strcpy(_language_, "it");
    }
    
    /* load the language selected */
    if (translator == NULL)
    {
        translator = new QTranslator();
    }
    
    if(translator->load(QString(":/translations/languages_%1.qm").arg(_language_)))
    {
        /* install the selected language */
        qApp->installTranslator(translator);
    }
    else
    {
        LOG_PRINT(error_e, "loading language file\n");
    }
#endif
    
    /* start page 0 (the splash screen) */
    page0 w;
    w.SHOW();
    w.reload();
    
    app.installEventFilter(new MyEventFilter());
    app.exec();
    
#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
    /* finalyze and free the logger */
    logger->exit();
    delete logger;
#endif
    
    /* finalyze and free the io Layers */
    ioComm->finalize();
    ioComm->exit();
    delete ioComm;
    
    return 0;
}

/**
 * @brief readCfgFile: read the config file and fill the service area into the ioLayer
 */
int readCfgFile(void)
{
    char value[32];
    
    LOG_PRINT(info_e, "Reading configuration...\n");
    
    if (readCfgVal(CONFIG_FILE, HOME, value) != 0)
    {
        strcpy(HomePage, HOMEPAGE);
        LOG_PRINT(warning_e, "Cannot read '%s' setting default '%s'\n", HOME, HomePage);
    }
    else
    {
        strcpy(HomePage, value);
        LOG_PRINT(info_e, "'%s' = %s\n", HOME, HomePage);
    }
    
    if (readCfgVal(CONFIG_FILE, STARTPAGE, value) != 0)
    {
        strcpy(StartPage, HOMEPAGE);
        LOG_PRINT(warning_e, "Cannot read '%s' setting default '%s'\n", STARTPAGE, StartPage);
    }
    else
    {
        strcpy(StartPage, value);
        LOG_PRINT(info_e, "'%s' = %s\n", STARTPAGE, StartPage);
    }
    
    if (readCfgVal(CONFIG_FILE, BUZZER_ALARM, value) != 0)
    {
        BuzzerAlarm = true;
        LOG_PRINT(warning_e, "Cannot read '%s' setting default %d\n", BUZZER_ALARM, BuzzerAlarm);
    }
    else
    {
        BuzzerAlarm = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", BUZZER_ALARM, BuzzerAlarm);
    }
    
    if (readCfgVal(CONFIG_FILE, BUZZER_TOUCH, value) != 0)
    {
        BuzzerTouch = true;
        LOG_PRINT(warning_e, "Cannot read '%s' setting default %d\n", BUZZER_TOUCH, BuzzerTouch);
    }
    else
    {
        BuzzerTouch = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", BUZZER_TOUCH, BuzzerTouch);
    }
    
#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
    if (readCfgVal(CONFIG_FILE, LOG_PERIOD_SLOW, value) != 0)
    {
        LogPeriodSecS = LOG_PERIOD_MS/1000;
        LOG_PRINT(warning_e, "Cannot read '%s' setting default %d\n", LOG_PERIOD_SLOW, LogPeriodSecS);
    }
    else
    {
        LogPeriodSecS = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", LOG_PERIOD_SLOW, LogPeriodSecS);
    }
    
    if (readCfgVal(CONFIG_FILE, LOG_PERIOD_FAST, value) != 0)
    {
        LogPeriodSecF = LOG_PERIOD_MS/1000;
        LOG_PRINT(warning_e, "Cannot read '%s' setting default %d\n", LOG_PERIOD_FAST, LogPeriodSecF);
    }
    else
    {
        LogPeriodSecF = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", LOG_PERIOD_FAST, LogPeriodSecF);
    }
    
    if (readCfgVal(CONFIG_FILE, WINDOW_SEC, value) != 0)
    {
        MaxWindowSec = MAX_SAMPLE_NB * ((LogPeriodSecF>LogPeriodSecS)?LogPeriodSecF:LogPeriodSecS);
        LOG_PRINT(warning_e, "Cannot read '%s' setting default %d\n", WINDOW_SEC, MaxWindowSec);
    }
    else
    {
        MaxWindowSec = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", WINDOW_SEC, MaxWindowSec);
    }
    
    if (readCfgVal(CONFIG_FILE, MAX_SPACE_AVAILABLE_TAG, value) != 0)
    {
        MaxLogUsageMb = DEFAULT_MAX_MB;
        LOG_PRINT(warning_e, "Cannot read '%s' setting default '%d'\n", MAX_SPACE_AVAILABLE_TAG, MaxLogUsageMb);
    }
    else
    {
        MaxLogUsageMb = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", MAX_SPACE_AVAILABLE_TAG, MaxLogUsageMb);
    }
#endif
#ifdef ENABLE_SCREENSAVER
    if (readCfgVal(CONFIG_FILE, SCREENSAVER, value) != 0)
    {
        ScreenSaverSec = SCREENSAVER_DEFAULT_TIME/1000;
        LOG_PRINT(warning_e, "Cannot read '%s' setting default %d\n", SCREENSAVER, ScreenSaverSec);
    }
    else
    {
        ScreenSaverSec = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", SCREENSAVER, ScreenSaverSec);
    }
#endif
    
    if (readCfgVal(CONFIG_FILE, PWD_TIMEOUT_SEC, value) != 0)
    {
        PwdTimeoutSec = 0;
        LOG_PRINT(warning_e, "Cannot read '%s' setting default %d\n", PWD_TIMEOUT_SEC, PwdTimeoutSec);
    }
    else
    {
        PwdTimeoutSec = atoi(value);
        LOG_PRINT(info_e, "'%s' = %d\n", PWD_TIMEOUT_SEC, PwdTimeoutSec);
    }
    
    if (readCfgVal(CONFIG_FILE, PWD_LOGOUT_PAGE, value) != 0)
    {
        PwdLogoutPage[0] = '\0';
        LOG_PRINT(warning_e, "Cannot read '%s' setting default '%s'\n", PWD_LOGOUT_PAGE, PwdLogoutPage);
    }
    else
    {
        strcpy(PwdLogoutPage, value);
        LOG_PRINT(info_e, "'%s' = %s\n", PWD_LOGOUT_PAGE, PwdLogoutPage);
    }
    
    return 0;
}

/**
 * @brief writeCfgFile: write into the config file the data into the ioLayer service area
 */
int writeCfgFile(void)
{
    char value[32] = "";
    
    LOG_PRINT(info_e, "Dumping configuration...\n");
    
    if (writeCfgVal(CONFIG_FILE, HOME, HomePage) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", HOME, HomePage);
    }
    
    if (writeCfgVal(CONFIG_FILE, STARTPAGE, StartPage) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", STARTPAGE, StartPage);
    }
    
    sprintf(value, "%d", BuzzerAlarm);
    if (writeCfgVal(CONFIG_FILE, BUZZER_ALARM, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", BUZZER_ALARM, value);
    }
    
    sprintf(value, "%d", BuzzerTouch);
    if (writeCfgVal(CONFIG_FILE, BUZZER_TOUCH, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", BUZZER_TOUCH, value);
    }
    
#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
    sprintf(value, "%d", LogPeriodSecS);
    if (writeCfgVal(CONFIG_FILE, LOG_PERIOD_SLOW, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", LOG_PERIOD_SLOW, LogPeriodSecS);
    }
    
    sprintf(value, "%d", LogPeriodSecF);
    if (writeCfgVal(CONFIG_FILE, LOG_PERIOD_FAST, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", LOG_PERIOD_FAST, LogPeriodSecF);
    }
    
    sprintf(value, "%d", MaxWindowSec);
    if (writeCfgVal(CONFIG_FILE, WINDOW_SEC, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", WINDOW_SEC, MaxWindowSec);
    }
    
    sprintf(value, "%d", MaxLogUsageMb);
    if (writeCfgVal(CONFIG_FILE, MAX_SPACE_AVAILABLE_TAG, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", MAX_SPACE_AVAILABLE_TAG, value);
    }
    
#endif
#ifdef ENABLE_SCREENSAVER
    sprintf(value, "%d", ScreenSaverSec);
    if (writeCfgVal(CONFIG_FILE, SCREENSAVER, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", SCREENSAVER, ScreenSaverSec);
    }
    
#endif
    
    sprintf(value, "%d", PwdTimeoutSec);
    if (writeCfgVal(CONFIG_FILE, PWD_TIMEOUT_SEC, value) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", PWD_TIMEOUT_SEC, value);
    }
    
    if (writeCfgVal(CONFIG_FILE, PWD_LOGOUT_PAGE, PwdLogoutPage) < 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %s\n", PWD_LOGOUT_PAGE, PwdLogoutPage);
    }
    
    return 0;
}

bool loadTagTable()
{
    FILE * fp;
    char line[LINE_SIZE] = "";
    char token[LINE_SIZE] = "";
    char reference[LINE_SIZE] = "";
    char * p;
    
    fp = fopen(TAG_TABLE, "r");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'\n", TAG_TABLE);
        return false;
    }
    LOG_PRINT(info_e, "opened '%s'\n", TAG_TABLE);
    /*
     * the file is formatted as
     *   Page's Type;ID Page;Tag Reference;Chars num;Description
     */
    while (fgets(line, LINE_SIZE, fp) != NULL)
    {
        p = line;
        /* Page's Type */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        
        /* ID Page */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        
        /* Tag Reference */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        strcpy(reference, token);
        
        /* Chars num */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        
        /* Description */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        TagTable.insert(reference,token);
        LOG_PRINT(verbose_e, "New tag '%s' - '%s'\n", reference,token);
    }
    LOG_PRINT(error_e, "Loaded '%d' Tag\n", TagTable.count());
    return true;
}



