/** 
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief HMI Main function
 */
#ifndef _MAIN_H_
#define _MAIN_H_

#include <QHash>
#include <QStack>
#include <QDateTime>
#include <QApplication>
#ifdef TRANSLATION
#include <QTranslator>
#endif

#include "common.h"

#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
#include "hmi_logger.h"
#include "qwt_plot_curve.h"
#define DEFAULT_MAX_MB 5
#endif
#include "app_var_list.h"
#include "pagebrowser.h"
#include "io_layer_comm.h"

#define VERSION ( \
    (QDate::fromString(__DATE__, "MMM dd yyyy").toString("yyyyMMdd").length() != 0) \
    ? \
    QDate::fromString(__DATE__, "MMM dd yyyy").toString("yyyyMMdd").toAscii().data() \
    : \
    QDate::fromString(__DATE__, "MMM  d yyyy").toString("yyyyMMdd").toAscii().data() \
    )

#define DEFAULT_LANGUAGE "it"
#define REFRESH_MS 500
#define SPLASH_TIMEOUT_MS 2000
#define BACKGROUND_FILE ""
#define SPLASH_FILE LOCAL_ETC_DIR"/img/splash.png"
#define MOUNT_POINT "/tmp/mnt"
#define BACKING_FILE "/local/root/backing_file"

#define STORAGE_PERMISSION "extrastorage"
#define APPLICATION_PERMISSION "application"
#define LICENCE_FILE ".licence"
#define SD_MOUNT_POINT "/local/sd_card"

/* IO LAYERS */
/** @brief io layer to syncronize the data with the PLC */
extern io_layer_comm * ioComm;

#define HOME "HomePage:"
#define STARTPAGE "StartPage:"
#define LOG_PERIOD_SLOW "LogPeriodSecS:"
#define LOG_PERIOD_FAST "LogPeriodSecF:"
#define WINDOW_SEC "WindowSizeSec:"
#define PWD1 "Password1:"
#define PWD2 "Password2:"
#define PWD3 "Password3:"
#define SCREENSAVER "ScreenSaverSec:"
#define BUZZER_ALARM "BuzzerAlarm:"
#define BUZZER_TOUCH "BuzzerTouch:"
#define USB_MODE "USBmode:"
#define DEVICE_TAG "Device"
#define HOST_TAG "Host"
#define PWD_TIMEOUT_SEC "PwdTimeoutSec:"
#define PWD_LOGOUT_PAGE "PwdLogoutPage:"
#define MAX_SPACE_AVAILABLE_TAG "SpaceAvailableMb:"

#define MBBAUD_DEFAULT      9600
#define MBBITNB_DEFAULT     8
#define MBPARITY_DEFAULT    "none"
#define MBSTOP_DEFAULT      0

#define MBMAXRETRY_DEFAULT  3
#define MBERRORRATE_DEFAULT 10
#define MBTIMEOUT_DEFAULT  1000
#define MBDELAY_DEFAULT     1000

#define MAX_PRIORITY_NUMBER 3

extern QHash<QString, page *> ScreenHash;
extern QStack<page *> History;

#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
extern Logger * logger;
extern int LogPeriodSecS;
extern int LogPeriodSecF;
extern QDateTime StoreInit;
extern QDateTime StoreFinal;
extern int MaxLogUsageMb;
extern bool ForceResetAlarmBanner;
#endif
#ifdef ENABLE_ALARMS
extern QList<event_descr_e *> _active_alarms_events_;
extern bool HornACK;
#endif

#ifdef TRANSLATION
extern char _language_[3];
extern QTranslator* translator;
#endif

#ifdef ENABLE_SCREENSAVER
extern int ScreenSaverSec;
#endif

#define BUZZER      "/dev/buzzer"
#include <linux/mxs-buzzer.h>
#define BUZZER_DURATION_MS 120

extern int Buzzerfd;
extern bool BuzzerTouch;
extern bool BuzzerAlarm;
extern struct timespec LastTouch;

#define BAUDRATE_NB 7
#define STOPBIT_NB 2
#define BITNB_NB 4
#define PARITY_NB 3

#define RTU_DEVICE "/dev/ttySP0"

extern int FailNb;
extern int FailDivisor;
extern int PriorityCounter[MAX_PRIORITY_NUMBER];
extern int HighPriorityTimerMsec;
extern int MediumPriorityTimerMsec;
extern int LowPriorityTimerMsec;

extern char RTUDevice[FILENAME_MAX];
extern int BaudRate;
extern char Parity;
extern int DataBit;
extern int StopBit;
extern int QueryIntervalRTU;
extern int TimeoutRTU;

extern char IpTCP[32];
extern int PortTCP;
extern int QueryIntervalTCP;
extern int TimeoutTCP;

extern char IpTCPRTU[32];
extern int PortTCPRTU;
extern int QueryIntervalTCPRTU;
extern int TimeoutTCPRTU;

extern int MaxWindowSec;

enum parity_e
{
    parity_none_e,
    parity_even_e,
    parity_odd_e
};

extern int BaudRateArray[7];
extern int StopBitArray[2];
extern int BitNbArray[4];
extern char ParityArray[3][8];
extern char ParityArrayShort[3];

#define PASSWORD_NB 3
extern char PasswordsString[PASSWORD_NB + 1][TAG_LEN];

enum password_level_e
{
    pwd_admin_e,
    pwd_super_user_e,
    pwd_user_e,
    pwd_operator_e
};

extern int passwords[PASSWORD_NB + 1];
extern int active_password;
extern QHash<QString, QString> TagTable;

extern int PwdTimeoutSec;

#define HOMEPAGE "menu"

#define PAGE_NAME_LEN 32
extern char StartPage[PAGE_NAME_LEN];
extern char HomePage[PAGE_NAME_LEN];
extern char PwdLogoutPage[PAGE_NAME_LEN];

#ifdef ENABLE_STORE
extern char _actual_store_[FILENAME_MAX];
#endif
#ifdef ENABLE_TREND
typedef struct pen_s
{
    int visible;
    int CtIndex;
    char tag[TAG_LEN];
    char color[TAG_LEN];
    char description[DESCR_LEN];
    float yMin;
    float yMax;
    float yMinActual;
    float yMaxActual;
    double *y;
    double *x;
    int sample;
    QwtPlotCurve * curve;
} pen_t;

extern QStringList _current_trend_variables_;
extern char _actual_trend_[FILENAME_MAX];
extern pen_t pens[PEN_NB + 1];
extern int actualPen;
extern char _layout_;
extern char _last_layout_;
extern bool _online_;
/* first time sample of visible data actually */
extern QDateTime actualTzero;
/* windows size in seconds of visible data actually */
extern int actualVisibleWindowSec;
extern bool _trend_data_reload_;
#endif
#ifdef ENABLE_RECIPE
extern char _actual_recipe_[FILENAME_MAX];
#endif

#ifdef ENABLE_USB
extern char usb_mnt_point[FILENAME_MAX];
#endif

extern unsigned short int FirstCy;
#define KINDOFUPDATE_FILE "/local/kindofupdate.lck"
#define MAX_LEN_UPDATE_MSG 5
#define STR_LEN 128
#define WAIT_COMM_RETRY_NB 20

/**
 * @brief write/update the config file with the actual value
 *
 * @return 0 success, error otherwise
 */
int writeCfgFile(void);

/**
 * @brief read all data from config file
 *
 * @return 0 success, error otherwise
 */
int readCfgFile(void);

bool loadTagTable();

class MyEventFilter: public QObject
{
public:
    MyEventFilter():QObject()
    {
        Buzzerfd = open(BUZZER, O_RDWR);

        if (Buzzerfd < 0) {
            fprintf(stderr,"can't open buzzer device '%s'\n", BUZZER);
        }
    };
    ~MyEventFilter()
    {
       if (Buzzerfd != -1)
       {
         close(Buzzerfd);
       }
    };

    bool eventFilter(QObject* object,QEvent* event)
    {
        Q_UNUSED(object);

        if (event->type() == QEvent::MouseButtonPress)
        {
            struct timespec oldTouch = LastTouch;
            clock_gettime(CLOCK_REALTIME, &LastTouch);
            unsigned delay_ms = (LastTouch.tv_sec - oldTouch.tv_sec) * 1000;
            delay_ms += (LastTouch.tv_nsec - oldTouch.tv_nsec) / 1000000;
            if (delay_ms > BUZZER_DURATION_MS)
            {
                if (BuzzerTouch == true && Buzzerfd != -1)
                {
                    ioctl(Buzzerfd, BUZZER_BEEP, BUZZER_DURATION_MS);
                }
            }
        }
        return false;
    }
};

#endif

