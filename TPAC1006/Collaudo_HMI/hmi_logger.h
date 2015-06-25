/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Thread to dump the events and the alarms
 */
#ifndef HMI_LOGGER_H
#define HMI_LOGGER_H

#include <QMetaType>
#include <QThread>
#include <QHash>
#include <QDateTime>
#include "common.h"
#include "app_cfg_file.h"

#define RECORD_SIZE_BYTE 100
#define MAX_RECORD_PER_DAY (24 * 3600 / 5)
#define ALARMS_PERIOD_MS 500

typedef struct event_msg_e
{
    char tag[TAG_LEN];
    QDateTime time;
    int event;
} event_msg_t;

typedef struct event_descr_e
{
    char tag[TAG_LEN];
    char description[DESCR_LEN];
    int styleindex;
    QDateTime * begin;
    QDateTime * end;
    QDateTime * ack;
    bool status;
    bool isack;
} event_descr_t;

typedef struct trend_msg_e
{
    int CtIndex;
    QDateTime timestamp;
    float value;
} trend_msg_t;
Q_DECLARE_METATYPE(trend_msg_t);

enum alarm_level_e
{
    level_all_e,
    level1_e,
    level2_e,
    level3_e,
    level4_e,
    level5_e,
    level6_e,
    level7_e,
    level8_e,
    level9_e,
    level10_e,
    level11_e,
    level12_e,
    level13_e,
    level14_e,
    level15_e,
    level16_e,
    level17_e,
    level18_e,
    level19_e,
    level20_e,
    level21_e,
    level22_e,
    level23_e,
    level24_e,
    level25_e,
    level26_e,
    level27_e,
    level28_e,
    level29_e,
    level30_e,
    level31_e,
    level32_e,
    nb_of_level_e
};

#if 0
/**
 * @brief this table will filled with the color to be used for each error level:
 * rgb sintax is used (example white is "rgb(255,255,255);")
 * tag "invisible" is used to hide the item
 */
extern char LevelColorTable[nb_of_level_e][DESCR_LEN];
#endif

enum alarm_status_e
{
    alrm_active_latched_nonack_e,
    alrm_active_nonlatched_nonack_e,
    alrm_active_latched_ack_e,
    alrm_active_nonlatched_ack_e,
    alrm_nonactive_latched_nonack_e,
    alrm_nonactive_nonlatched_nonack_e,
    alrm_nonactive_latched_ack_e,
    alrm_nonactive_nonlatched_ack_e,
    nb_of_alarm_status_e
};

/**
 * @brief this table will filled with the color to be used for each error staatus:
 * rgb sintax is used (example white is "rgb(255,255,255);")
 * tag "invisible" is used to hide the item
 */
extern char StatusColorTable[nb_of_alarm_status_e][DESCR_LEN];
extern char StatusBannerColorTable[nb_of_alarm_status_e][DESCR_LEN];

#define INVISIBLE "invisible"
#define ISBANNER(index) (strcasecmp(StatusBannerColorTable[index], INVISIBLE) != 0)
#define ISSTATUS(index) (strcasecmp(StatusColorTable[index], INVISIBLE) != 0)

class Logger : public QThread
{
    Q_OBJECT
public:
    explicit Logger(const char * alarms_dir = NULL, const char * store_dir = NULL, int period_msec = LOG_PERIOD_MS, QObject *parent = 0);
    ~Logger();
    virtual void run();
#ifdef ENABLE_ALARMS
    bool connectToPage(QWidget * p);
#endif
private:
    FILE * openFile(int * newfile, const char * basedir, const char * subdir = NULL);
#ifdef ENABLE_ALARMS
    int getElemAlarmStyleIndex(event_descr_t * event_msg);
    size_t loadErrorTable();
    bool dumpEvent(QString varname, event_t * item, int status);
    bool openAlarmsFile();
    bool closeAlarmsFile();
#endif
#ifdef ENABLE_STORE
    bool dumpStorage();
    bool openStorageFile();
    bool closeStorageFile();
#endif
    int checkSpace( void );
    int removeOldest(const char * dir);
    int getSizeDir(const char *dirname);
private:
    time_t Now;
    struct tm * timeinfo;
    FILE * alarmsfp;
    FILE * storefp;
    int _period_msec;
    char AlarmsDir[FILENAME_MAX];
    char StorageDir[FILENAME_MAX];
    char CurrentDate[DESCR_LEN];
#ifdef ENABLE_STORE
    int counterS;
    int counterF;
#endif
#ifdef ENABLE_ALARMS
private slots:
    bool dumpAck(event_msg_t * info_msg);
#endif
signals:
#ifdef ENABLE_ALARMS
    void new_event(char * tag);
    void new_alarm(char * tag);
#endif
#ifdef ENABLE_TREND
    void new_trend(trend_msg_t msg);
#endif
};

#ifdef ENABLE_ALARMS
extern QHash<QString, event_t *> EventHash;
#endif

#endif // HMI_LOGGER_H


