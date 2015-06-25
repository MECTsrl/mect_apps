/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief This class read the errors/event table in order to understand:
 * - wich variable is an error/event,
 * - if it is an error or an event,
 * - wich desriprion is associated,
 * - if you need to log,
 * - which level it have.
 * The other info are not used in the HMI.
 */

#include <QFile>
#ifndef _ISOC99_SOURCE
#define _ISOC99_SOURCE
#endif
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <ftw.h>
#include "main.h"
#include "hmi_logger.h"
#include "app_logprint.h"
#include "cross_table_utility.h"
#include "alarms.h"
#include "common.h"

#if 0
/**
 * @brief this table will filled with the color to be used for each error level:
 * rgb sintax is used (example white is "rgb(255,255,255);")
 * tag INVISIBLE is used to hide the item
 */
char LevelColorTable[nb_of_level_e][DESCR_LEN] =
{
    "rgb(0,0,0);", /* level 0 reserved */
    "rgb(0,0,0);", /* level 1 */
    "rgb(0,0,0);", /* level 2 */
    "rgb(0,0,0);", /* level 3 */
    "rgb(0,0,0);", /* level 4 */
    "rgb(0,0,0);", /* level 5 */
    "rgb(0,0,0);", /* level 6 */
    "rgb(0,0,0);", /* level 7 */
    "rgb(0,0,0);", /* level 8 */
    "rgb(0,0,0);", /* level 9 */
    "rgb(0,0,0);", /* level 10 */
    "rgb(0,0,0);", /* level 11 */
    "rgb(0,0,0);", /* level 12 */
    "rgb(0,0,0);", /* level 13 */
    "rgb(0,0,0);", /* level 14 */
    "rgb(0,0,0);", /* level 15 */
    "rgb(0,0,0);", /* level 16 */
    "rgb(0,0,0);", /* level 17 */
    "rgb(0,0,0);", /* level 18 */
    "rgb(0,0,0);", /* level 19 */
    "rgb(0,0,0);", /* level 20 */
    "rgb(0,0,0);", /* level 21 */
    "rgb(0,0,0);", /* level 22 */
    "rgb(0,0,0);", /* level 23 */
    "rgb(0,0,0);", /* level 24 */
    "rgb(0,0,0);", /* level 25 */
    "rgb(0,0,0);", /* level 26 */
    "rgb(0,0,0);", /* level 27 */
    "rgb(0,0,0);", /* level 28 */
    "rgb(0,0,0);", /* level 29 */
    "rgb(0,0,0);", /* level 30 */
    "rgb(0,0,0);", /* level 31 */
    "rgb(0,0,0);", /* level 32 */
};
#endif

/**
 * @brief this table will filled with the color to be used for each error staatus:
 * rgb sintax is used (example white is "rgb(255,255,255);")
 * tag INVISIBLE is used to hide the item
 */
char StatusColorTable[nb_of_alarm_status_e][DESCR_LEN] =
{
    "rgb(255,  0,  0);", /* active alarm latched not acknowloged */
    "rgb(255,  0,  0);", /* active alarm not latched not acknowloged */
    "rgb(  0,  0,255);", /* active alarm latched acknowloged */
    "rgb(  0,  0,255);", /* active alarm not latched acknowloged */
    "rgb(122,122,122);", /* not active alarm latched not acknowloged */
    INVISIBLE,         /* not active alarm not latched not acknowloged */
    INVISIBLE,         /* not active alarm latched acknowloged */
    INVISIBLE,         /* not active alarm not latched acknowloged */
};

char StatusBannerColorTable[nb_of_alarm_status_e][DESCR_LEN] =
{
    "rgb(255,  0,  0);", /* active alarm latched not acknowloged */
    "rgb(255,  0,  0);", /* active alarm not latched not acknowloged */
    "rgb(  0,  0,255);", /* active alarm latched acknowloged */
    INVISIBLE,         /* active alarm not latched acknowloged */
    "rgb(122,122,122);", /* not active alarm latched not acknowloged */
    INVISIBLE,         /* not active alarm not latched not acknowloged */
    INVISIBLE,         /* not active alarm latched acknowloged */
    INVISIBLE,         /* not active alarm not latched acknowloged */
};

#ifdef ENABLE_ALARMS
QHash<QString, event_t *> EventHash;
#endif

unsigned int total = 0;

Logger::Logger(const char * alarms_dir, const char * store_dir, int period_msec, QObject *parent) :
    QThread(parent)
{
    alarmsfp = NULL;
    storefp = NULL;
    _period_msec = period_msec;
    qRegisterMetaType<trend_msg_t>();

    LOG_PRINT(verbose_e,"log period is %d\n", _period_msec);

    if (alarms_dir != NULL)
    {
        strcpy(AlarmsDir, alarms_dir);
    }
    else
    {
        strcpy(AlarmsDir, ALARMS_DIR);
    }
    LOG_PRINT(verbose_e, "Alarm dir: '%s'.\n", AlarmsDir);

    if (store_dir != NULL)
    {
        strcpy(StorageDir, store_dir);
    }
    else
    {
        strcpy(StorageDir, STORE_DIR);
    }
    LOG_PRINT(verbose_e, "Store dir: '%s'.\n", StorageDir);

    time(&Now);
    timeinfo = localtime (&Now);
    strftime (CurrentDate, 32, "%Y_%m_%d", timeinfo);

#ifdef ENABLE_ALARMS
    if (loadErrorTable() <= 0)
    {
        LOG_PRINT(warning_e, "No event/error found.\n");
    }
#endif	
    /* check the available space */
    while (checkSpace() == 1)
    {
        /* if necessary delete the oldest logfile */
        if (removeOldest(StorageDir))
        {
            LOG_PRINT(error_e, "Cannot remove the oldest log\n");
            return;
        }
        /* if necessary delete the oldest logfile */
        if (removeOldest(AlarmsDir))
        {
            LOG_PRINT(error_e, "Cannot remove the oldest log\n");
            return;
        }
    }
#ifdef ENABLE_ALARMS
    if (openAlarmsFile() == false)
    {
        LOG_PRINT(error_e, "Cannot open the log\n");
        return;
    }
#endif
#ifdef ENABLE_STORE
    counterS = 0;
    counterF = 0;
#endif
}

FILE * Logger::openFile(int * newfile, const char * basedir, const char * subdir)
{
    /* create the log name in function of the current date */
    char logFileName[FILENAME_MAX];

    /* if necessary, create the subdir */
    if (subdir != NULL)
    {
        sprintf(logFileName, "%s/%s", basedir, subdir);
        mkdir(logFileName, S_IRWXU | S_IRWXG);
        sprintf(logFileName, "%s/%s/%s.log", basedir, subdir, CurrentDate);
    }
    else
    {
        sprintf(logFileName, "%s/%s.log", basedir, CurrentDate);
    }

    FILE * fp = NULL;

    fp = fopen(logFileName, "r");
    /* if ther log file doesn't exist, create it and dump the header */
    if (fp == NULL)
    {
        *newfile = 1;
        LOG_PRINT(verbose_e, "Opening new file '%s'\n", logFileName);
    }
    /* if ther log file exists, open it */
    else
    {
        *newfile = 0;
        LOG_PRINT(verbose_e, "Opening existing new file '%s'\n", logFileName);
        fclose(fp);
    }
    fp = fopen(logFileName, "a");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "cannot open '%s' [%s]\n", logFileName, strerror(errno));
    }
    return fp;
}

#ifdef ENABLE_ALARMS
bool Logger::openAlarmsFile()
{
    int newfile = 0;
    /*  open the log file */
    alarmsfp = openFile(&newfile, AlarmsDir);
    if (alarmsfp == NULL)
    {
        LOG_PRINT(error_e, "Cannot dump the log\n");
        return false;
    }

    LOG_PRINT(verbose_e, "Opened log file\n");
    return true;
}
#endif

Logger::~Logger()
{
    /* close log file */
    if (alarmsfp != NULL)
    {
        fclose(alarmsfp);
        alarmsfp = NULL;
        LOG_PRINT(verbose_e, "Logfile closed\n");
    }
}

#ifdef ENABLE_ALARMS
bool Logger::connectToPage(QWidget * p)
{
    if (p != NULL)
    {
        return connect(p, SIGNAL(new_ack(event_msg_t *)), this, SLOT(dumpAck(event_msg_t *)));
    }
    return false;
}
#endif

void Logger::run()
{
    char buffer [FILENAME_MAX] = "";
#ifdef ENABLE_ALARMS
    BYTE var;
    QHash<QString, event_t *>::const_iterator i;
#endif

    LOG_PRINT(verbose_e, "Start\n");

    while (1)
    {
        /* get the actual time */
        time(&Now);
        timeinfo = localtime (&Now);
        LOG_PRINT(verbose_e, "Now %ld\n", Now);
        /* check if the actual date is the same of the date described into the logfile name */
        strftime (buffer, FILENAME_MAX, "%Y_%m_%d", timeinfo);
        if (strcmp(CurrentDate, buffer) != 0)
        {
            LOG_PRINT(warning_e, "Data changed: '%s' -> '%s'\n", CurrentDate, buffer);
            strcpy(CurrentDate, buffer);
            /* if is different, close the actual log file then open a new one */
#ifdef ENABLE_ALARMS
            closeAlarmsFile();
            if (openAlarmsFile() == false)
            {
                LOG_PRINT(error_e, "Cannot open the log\n");
                return;
            }
#endif
#ifdef ENABLE_STORE
            if (store_elem_nb_S > 0 || store_elem_nb_F > 0)
            {
                if (LogPeriodSecS > 0 || LogPeriodSecF > 0)
                {
                closeStorageFile();
                if (openStorageFile() == false)
                {
                    LOG_PRINT(error_e, "Cannot open the store\n");
                    return;
                }
            }
            }
#endif
        }

#ifdef ENABLE_STORE
        /* if there is something to dump */
        if (store_elem_nb_S > 0 || store_elem_nb_F > 0)
        {
            /* if a log frequency is not 0 */
            if (LogPeriodSecS > 0 || LogPeriodSecF > 0)
            {
                /* if the file is not open, open it */
                if (openStorageFile() == false)
                {
                    LOG_PRINT(error_e, "Cannot open the store\n");
                    return;
                }
                LOG_PRINT(error_e, "open the store\n");
            }
            else if (LogPeriodSecS <= 0 && LogPeriodSecF <= 0)
            {
                if (closeStorageFile() == true)
                {
                    time_t Now;
                    struct tm * timeinfo;
                    char date_and_time[16];
                    char logFileNameSrc[256];
                    char logFileNameDst[256];
                    time(&Now);
                    timeinfo = localtime (&Now);
                    strftime (date_and_time, 32, "%Y_%m_%d_%H_%M_%S", timeinfo);
                    sprintf(logFileNameSrc, "/local/data/store/%s.log", CurrentDate);
                    sprintf(logFileNameDst, "/local/data/store/%s.log", date_and_time);
                    QFile::rename(logFileNameSrc, logFileNameDst);
                }
            }
        }
#endif

#ifdef ENABLE_ALARMS
        /* check each event */
        for ( i = EventHash.begin(); i != EventHash.end() && i.value() != NULL ; i++)
        {
            if (i.key().length() == 0)
            {
                continue;
            }
            /* if is active, dump if it is necessary and emit the signal */
            LOG_PRINT(verbose_e, "Reading '%s'\n", i.key().toAscii().data());
            if (readFromDb(i.value()->CtIndex, &var) == 0)
            {
                LOG_PRINT(verbose_e, "Reading '%s' 0x%X\n", i.key().toAscii().data(), var);
                /* an event is active */
                /* if it is the first time, set the begin time  */
                if (i.value()->begin == 0)
                {
                    i.value()->begin = Now;
                    LOG_PRINT(verbose_e, "%s - set begin as %ld\n", i.key().toAscii().data(), Now);
                }
                /* if no time filter is set or if the time filter is expired, dump the event */
                if (i.value()->filtertime == 0 || Now >= i.value()->begin + i.value()->filtertime)
                {
                    i.value()->begin = 0;
                    LOG_PRINT(verbose_e, "%s - dumpEvent %d\n", i.key().toAscii().data(), var);
                    dumpEvent(i.key(), i.value(), (var == 1) ? alarm_rise_e : alarm_fall_e);
                }
                else
                {
                    /* wait the time filter expiration to dump the event */
                }
            }
            else
            {
                LOG_PRINT(error_e, "cannot read variable '%s'\n", i.key().toAscii().data());
            }
            /* remove the expired element */
            for (int i = 0; i < _active_alarms_events_.count(); i++)
            {
                int index = getElemAlarmStyleIndex(_active_alarms_events_.at(i));
                if (ISBANNER(index) == 0 && ISSTATUS(index) == 0)
                {
                    LOG_PRINT(verbose_e, "REMOVE '%s'\n", _active_alarms_events_.at(i)->tag);
                    _active_alarms_events_.removeAt(i);
                    i--;
                }
            }
        }
#endif
#ifdef ENABLE_STORE
		LOG_PRINT(info_e, "store_elem_nb_S %d counterS %d LogPeriodSecS %d store_elem_nb_F %d counterF %d LogPeriodSecF %d \n",
				store_elem_nb_S, counterS, LogPeriodSecS, store_elem_nb_F, counterF, LogPeriodSecF);
        if (LogPeriodSecS > 0 || LogPeriodSecF > 0)
        {
        if (
		(store_elem_nb_S > 0 && (counterS * ALARMS_PERIOD_MS) >= (LogPeriodSecS * 1000))
		 ||
		(store_elem_nb_F > 0 && (counterF * ALARMS_PERIOD_MS) >= (LogPeriodSecF * 1000))
	)
        {
            /* log the store variables */
            dumpStorage();
        }
        counterS++;
        counterF++;
        }
#endif
        usleep(ALARMS_PERIOD_MS * 1000);
    }
}

#ifdef ENABLE_ALARMS

size_t Logger::loadErrorTable()
{
    FILE * fp;
    int elem_nb = 0;
    char line[LINE_SIZE];
    char token[LINE_SIZE] = "";
    char tag[LINE_SIZE] = "";
    char * p = NULL;

    /* read the error cross table */
    fp = fopen(ERROR_TABLE, "r");
    if (fp == NULL)
    {
        sprintf(CrossTableErrorMsg, "Cannot open The error cross table '%s': [%s]", ERROR_TABLE, strerror(errno));
        LOG_PRINT(error_e, "%s\n", CrossTableErrorMsg);
        return -1;
    }

    EventHash.clear();

    while (fgets(line, LINE_SIZE, fp) != NULL)
    {
        event_t * item = (event_t*)calloc(1, sizeof(event_t));
        LOG_PRINT(verbose_e, "%s\n", line);
        /* extract the Event type field */
        p = line;
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element Type");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }
        if (atoi(token) == ALARM)
        {
            item->type = ALARM;
        }
        else if (atoi(token) == EVENT)
        {
            item->type = EVENT;
        }
        else
        {
            sprintf(CrossTableErrorMsg, "Invalid field Type: Expected'%d'|'%d' vs %d\n", ALARM, EVENT, atoi(token));
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }

        /* extract the Tag of the alarm/event variable */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL || token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element alarm/event");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }
        strcpy(tag, token);
        LOG_PRINT(verbose_e, "FOUND ALARM '%s'\n", token);

        /* Check if the variable is present and enabled into the crosstable */
        if (Tag2CtIndex(tag, &(item->CtIndex)) != 0)
        {
            sprintf(CrossTableErrorMsg, "'%s' not found into DataVector", tag);
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }

        /* skip - source tag */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element source");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }

        /* skip - reference tag */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element reference");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }

        /* skip - fix value */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element fix-value");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }

        /* skip - operator */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element operator");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }

        /* extract the time filter before sho the alarm/event */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element Time filter");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }
        item->filtertime = atoi(token);

        /* extract the description of the alarm/event */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element description");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }
        strcpy(item->description, token);

        /* extract the level of the alarm/event */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element priority");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }
        item->level = atoi(token);

        /* extract the persistence of the alarm/event */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element persistence");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }
        item->persistence = atoi(token);

        /* extract the dump flag of the alarm/event */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            sprintf(CrossTableErrorMsg, "Malformed element save");
            LOG_PRINT(error_e, "%s at line %d.\n", CrossTableErrorMsg, elem_nb);
            free(item);
            fclose(fp);
            return elem_nb;
        }
        item->dump = atoi(token);
        LOG_PRINT(verbose_e, "record DUMP %d\n", item->dump);

        EventHash.insert(tag, item);
        elem_nb++;
    }
    fclose(fp);
    LOG_PRINT(verbose_e, "Loaded %d record\n", elem_nb);

    return elem_nb;
}

/**
 * @brief return false if the alarm is tagged as INVISIBLE into the LevelColorTable or into the StatusColorTable
 */
int Logger::getElemAlarmStyleIndex(event_descr_t * event_msg)
{
    QHash<QString, event_t *>::const_iterator item = EventHash.find(event_msg->tag);
    if (item == EventHash.end())
    {
        LOG_PRINT(error_e, "FATAL: cannot find '%s' into hash table\n", event_msg->tag);
        return false;
    }

    event_t * event = item.value();
#if 0
    if (strcasecmp(LevelColorTable[event->level], INVISIBLE) == 0)
    {
        strcpy(event_msg->style, LevelColorTable[event->level]);
        return false;
    }
#endif
    /* active */
    if (event_msg->status == alarm_rise_e)
    {
        /* latched */
        if (event->persistence == 1)
        {
            /* aknowloged */
            if (event_msg->isack == 1)
            {
                event_msg->styleindex = alrm_active_latched_ack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_active_latched_ack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
            /* not aknowloged */
            else
            {
                event_msg->styleindex = alrm_active_latched_nonack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_active_latched_nonack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
        }
        /* not latched */
        else
        {
            /* aknowloged */
            if (event_msg->isack == 1)
            {
                event_msg->styleindex = alrm_active_nonlatched_ack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_active_nonlatched_ack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
            /* not aknowloged */
            else
            {
                event_msg->styleindex = alrm_active_nonlatched_nonack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_active_nonlatched_nonack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
        }
    }
    /* not active */
    else
    {
        /* latched */
        if (event->persistence == 1)
        {
            /* aknowloged */
            if (event_msg->isack == 1)
            {
                event_msg->styleindex = alrm_nonactive_latched_ack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_nonactive_latched_ack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
            /* not aknowloged */
            else
            {
                event_msg->styleindex = alrm_nonactive_latched_nonack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_nonactive_latched_nonack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
        }
        /* not latched */
        else
        {
            /* aknowloged */
            if (event_msg->isack == 1)
            {
                event_msg->styleindex = alrm_nonactive_nonlatched_ack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_nonactive_nonlatched_ack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
            /* not aknowloged */
            else
            {
                event_msg->styleindex = alrm_nonactive_nonlatched_nonack_e;
                LOG_PRINT(verbose_e, "STYLE: alrm_nonactive_nonlatched_nonack_e: '%s' status %d persistance %d ACK %d\n", event_msg->tag, event_msg->status, event->persistence, event_msg->isack);
            }
        }
    }
    LOG_PRINT(verbose_e, "EVENT %s color %d\n", event_msg->tag, event_msg->styleindex);
    return event_msg->styleindex;
}

bool Logger::dumpEvent(QString varname, event_t * item, int status)
{
    bool todump = false;
    bool toemit = false;
    char msg[LINE_SIZE];
    char buffer [FILENAME_MAX] = "";
    event_descr_e * info_descr = NULL;

    strftime (buffer, FILENAME_MAX, "%Y/%m/%d,%H:%M:%S", timeinfo);

    /* check if the alarm associated to the actual event is still into the _active_alarms_events_ */
    for (int i = 0; i < _active_alarms_events_.count(); i++)
    {
        /* if found, update the alarm with the last event */
        if (strcmp(_active_alarms_events_.at(i)->tag, varname.toAscii().data()) == 0)
        {
            info_descr = _active_alarms_events_.at(i);
            LOG_PRINT(info_e, "Update existing event for %s\n", info_descr->tag);
            break;
        }
    }

    if (status == alarm_fall_e && info_descr == NULL)
    {
        LOG_PRINT(info_e, "Nothing interesting to dump...\n");
        return true;
    }

    if (info_descr == NULL)
    {
        info_descr = new event_descr_e;

        strcpy(info_descr->tag, varname.toAscii().data());
        info_descr->description[0] = '\0';
        info_descr->styleindex = nb_of_alarm_status_e;
        info_descr->isack = false;
        info_descr->begin = NULL;
        info_descr->end = NULL;
        info_descr->ack = NULL;
        info_descr->status = alarm_fall_e;
        _active_alarms_events_.append(info_descr);

        LOG_PRINT(verbose_e, "New event for %s\n", info_descr->tag);
    }

    if (status == alarm_rise_e)
    {
        toemit = true;
        if (info_descr->status == alarm_fall_e)
        {
            LOG_PRINT(info_e, "Rising event for %s\n", info_descr->tag);
            HornACK = false;
            todump = true;
            if (info_descr->begin == NULL)
            {
                info_descr->begin = new QDateTime();
            }
            *(info_descr->begin) = QDateTime().fromString(buffer,"yyyy/MM/dd,HH:mm:ss");
        }
        else if (info_descr->begin == NULL)
        {
            info_descr->begin = new QDateTime();
            *(info_descr->begin) = QDateTime().fromString(buffer,"yyyy/MM/dd,HH:mm:ss");
        }
        info_descr->status = alarm_rise_e;
    }
    else if (status == alarm_fall_e)
    {
        if (info_descr->status == alarm_rise_e)
        {
            LOG_PRINT(info_e, "Falling event for %s\n", info_descr->tag);
            toemit = true;
            todump = true;
            if (info_descr->end == NULL)
            {
                info_descr->end = new QDateTime();
            }
            *(info_descr->end) = QDateTime().fromString(buffer,"yyyy/MM/dd,HH:mm:ss");
            //info_descr->isack = false;
        }
        else if (info_descr->end == NULL)
        {
            info_descr->end = new QDateTime();
            *(info_descr->end) = QDateTime().fromString(buffer,"yyyy/MM/dd,HH:mm:ss");
        }
        info_descr->status = alarm_fall_e;
    }

    if (toemit)
    {
        getElemAlarmStyleIndex(info_descr);
        ForceResetAlarmBanner = true;
        /* emit a signal to the hmi with the new item to display */
        if (item->type == EVENT)
        {
            LOG_PRINT(info_e, "Emit New event for %s status %d\n", info_descr->tag, info_descr->status);
            emit new_event(info_descr->tag);
        }
        else
        {
            LOG_PRINT(info_e, "Emit New alarm for %s status %d\n", info_descr->tag, info_descr->status);
            emit new_alarm(info_descr->tag);
        }
    }
    if (todump && item->dump == 1)
    {
        /* before dump a new event, check the available space */
        if (checkSpace() == 1)
        {
            /* if necessary delete the oldest logfile */
            if (removeOldest(AlarmsDir))
            {
                LOG_PRINT(error_e, "Cannot remove the oldest log\n");
                return false;
            }
        }

        char event[TAG_LEN];
        if (info_descr->isack == true)
        {
            strcpy(event, TAG_ACK);
        }
        else if (info_descr->status == alarm_rise_e)
        {
            strcpy(event, TAG_RISE);
        }
        else if (info_descr->status == alarm_fall_e)
        {
            strcpy(event, TAG_FALL);
        }
        else
        {
            strcpy(event, "UNK");
            LOG_PRINT(warning_e, "Unknown event\n");
        }

        /* prepare the event item */
        /* type;level;tag;event;YYYY/MM/DD,HH:mm:ss;description */
        sprintf(msg, "%d;%d;%s;%s;%s;%s\n",
                item->type,
                item->level,
                varname.toAscii().data(),
                event,
                buffer,
                item->description
                );

        /* dump the item into log file */
        if (alarmsfp != NULL)
        {
            fprintf(alarmsfp, "%s", msg);
            fflush(alarmsfp);
            sync();
            LOG_PRINT(verbose_e, "DUMP: '%s'\n", msg);
            return true;
        }
        else
        {
            LOG_PRINT(error_e, "the log file is not open\n");
            return false;
        }
    }
    else
    {
        LOG_PRINT(verbose_e, "NOT DUMPING %d %d\n", todump, item->dump == 1);
    }
    return true;
}

bool Logger::closeAlarmsFile()
{
    if (alarmsfp != NULL)
    {
        fclose(alarmsfp);
        alarmsfp = NULL;
    }
    return true;
}

bool Logger::dumpAck(event_msg_e * info_msg)
{
    char msg[LINE_SIZE];

    /* before dump a new event, check the available space */
    if (checkSpace() == 1)
    {
        /* if necessary delete the oldest logfile */
        if (removeOldest(AlarmsDir))
        {
            LOG_PRINT(error_e, "Cannot remove the oldest log\n");
            return false;
        }
    }

    /* ACK ALL */
    if (info_msg == NULL)
    {
        for (int i = 0; i < _active_alarms_events_.count(); i++)
        {
            LOG_PRINT(verbose_e, "ACK to : '%d/%d'\n", i, _active_alarms_events_.count());
            /* prepare the event item */
            QHash<QString, event_t *>::const_iterator item = EventHash.find(_active_alarms_events_.at(i)->tag);
            if (item == EventHash.end())
            {
                LOG_PRINT(error_e, "FATAL: cannot find '%s' into hash table\n", _active_alarms_events_.at(i)->tag);
                return false;
            }

            event_t * event = item.value();

            getElemAlarmStyleIndex(_active_alarms_events_.at(i));

            /* type;level;tag;event;YYYY/MM/DD,HH:mm:ss;description */
            sprintf(msg, "%d;%d;%s;%s;%s;%s\n",
                    event->type,
                    event->level,
                    _active_alarms_events_.at(i)->tag,
                    TAG_ACK,
                    _active_alarms_events_.at(i)->ack->toString("yyyy/MM/dd,HH:mm:ss").toAscii().data(),
                    event->description
                    );

            /* dump the event into log file */
            if (alarmsfp != NULL)
            {
                fprintf(alarmsfp, "%s", msg);
                fflush(alarmsfp);
                sync();
                LOG_PRINT(verbose_e, "DUMP: '%s'\n", msg);
            }
            else
            {
                LOG_PRINT(error_e, "the log file is not open\n");
                return false;
            }
        }
	return true;
    }
    /* ACK SINGLE EVENT */
    else
    {
        int i;
        /* prepare the event item */
        QHash<QString, event_t *>::const_iterator item = EventHash.find(info_msg->tag);
        if (item == EventHash.end())
        {
            LOG_PRINT(error_e, "FATAL: cannot find '%s' into hash table\n", info_msg->tag);
            return false;
        }

        event_t * event = item.value();

        for (i = 0; i < _active_alarms_events_.count(); i++)
        {
            /* if found, update the alarm with the last event */
            if (strcmp(_active_alarms_events_.at(i)->tag, info_msg->tag) == 0)
            {
                LOG_PRINT(verbose_e, "Update existing event for %s\n", info_msg->tag);
                getElemAlarmStyleIndex(_active_alarms_events_.at(i));
                break;
            }
        }

        /* type;level;tag;event;YYYY/MM/DD,HH:mm:ss;description */
        sprintf(msg, "%d;%d;%s;%s;%s;%s\n",
                event->type,
                event->level,
                _active_alarms_events_.at(i)->tag,
                TAG_ACK,
                _active_alarms_events_.at(i)->ack->toString("yyyy/MM/dd,HH:mm:ss").toAscii().data(),
                event->description
                );

        /* dump the event into log file */
        if (alarmsfp != NULL)
        {
            fprintf(alarmsfp, "%s", msg);
            fflush(alarmsfp);
            sync();
            LOG_PRINT(verbose_e, "DUMP: '%s'\n", msg);
            return true;
        }
        else
        {
            LOG_PRINT(error_e, "the log file is not open\n");
            return false;
        }
    }
    return false;
}
#endif

#ifdef ENABLE_STORE
bool Logger::openStorageFile()
{
    int newfile;
    if (storefp != NULL)
    {
        LOG_PRINT(info_e, "the log file is already open\n");
        return true;
    }
    /*  open the log file */
    storefp = openFile(&newfile, StorageDir);
    if (storefp == NULL)
    {
        LOG_PRINT(error_e, "Cannot dump the log\n");
        return false;
    }

    if (newfile)
    {
        LOG_PRINT(verbose_e, "NEW log file\n");
        int nb_of_char = fprintf(storefp, "date; time");
        if (nb_of_char != (int)strlen("date; time"))
        {
            LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", "date; time", nb_of_char, (int)strlen("date; time"));
            return false;
        }

        for ( int i = 0; StoreArrayS[i].tag[0] != '\0'; i++)
        {
            LOG_PRINT(verbose_e, "dumping title %s\n", StoreArrayS[i].tag);
            nb_of_char = fprintf(storefp, "; %s", StoreArrayS[i].tag);
            if (nb_of_char != (int)strlen(StoreArrayS[i].tag) + 2)
            {
                LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", StoreArrayS[i].tag, nb_of_char, (int)strlen(StoreArrayS[i].tag) + 2);
                return false;
            }
        }
        for ( int i = 0; StoreArrayF[i].tag[0] != '\0'; i++)
        {
            LOG_PRINT(verbose_e, "dumping title %s\n", StoreArrayF[i].tag);
            nb_of_char = fprintf(storefp, "; %s", StoreArrayF[i].tag);
            if (nb_of_char != (int)strlen(StoreArrayF[i].tag) + 2)
            {
                LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", StoreArrayF[i].tag, nb_of_char, (int)strlen(StoreArrayF[i].tag) + 2);
                return false;
            }
        }

        if (fprintf(storefp, "\n") != 1)
        {
            LOG_PRINT(error_e, "Cannot dump: '%s'\n", strerror(errno));
            return false;
        }
        fflush(storefp);
    }
    LOG_PRINT(verbose_e, "Opened log file\n");
    return true;
}

bool Logger::closeStorageFile()
{
    if (storefp != NULL)
    {
        fclose(storefp);
        storefp = NULL;
        return true;
    }
    else
    {
        return false;
    }
}

bool Logger::dumpStorage()
{
    char buffer [FILENAME_MAX] = "";
    char value [TAG_LEN] = "";
    int iF, iS;
#ifdef ENABLE_TREND
    trend_msg_t info_msg;
#endif

    if (storefp == NULL)
    {
        LOG_PRINT(error_e, "Cannot dump: (storefp is null).\n");
        return false;
    }

    /* before dump a new event, check the available space */
    if (checkSpace() == 1)
    {
        /* if necessary delete the oldest logfile */
        if (removeOldest(StorageDir))
        {
            LOG_PRINT(error_e, "Cannot remove the oldest log\n");
            return false;
        }
    }

    /* prepare the event item */
    strftime (buffer, FILENAME_MAX, "%Y/%m/%d; %H:%M:%S", timeinfo);

    LOG_PRINT(verbose_e, "dumping a new line '%s'\n", buffer);
    int nb_of_char = fprintf(storefp, "%s", buffer);
    if (nb_of_char != (int)strlen(buffer))
    {
        LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", buffer, nb_of_char, (int)strlen(buffer));
        return false;
    }

    if (store_elem_nb_S > 0  && (counterS * ALARMS_PERIOD_MS) >= (LogPeriodSecS * 1000))
    {
        counterS = 0;
        for ( iS = 0; StoreArrayS[iS].tag[0] != '\0'; iS++)
        {
            /* if is active, dump if it is necessary and emit the signal */
            LOG_PRINT(verbose_e, "Reading '%s'\n", StoreArrayS[iS].tag);
            if (formattedReadFromDb(StoreArrayS[iS].CtIndex, value) != 0)
            {
                LOG_PRINT(error_e, "cannot read variable '%s'\n", StoreArrayS[iS].tag );
                strcpy(value, TAG_NAN);
            }

            nb_of_char = fprintf(storefp, "; %s", value);
            if (nb_of_char != (int)strlen(value) + 2)
            {
                LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", value, nb_of_char, (int)strlen(value) + 2);
                return false;
            }

#ifdef ENABLE_TREND
            /* emit a signal to the hmi with the new item to display */
            info_msg.CtIndex = StoreArrayS[iS].CtIndex;
            info_msg.timestamp = QDateTime::fromString(buffer,"yyyy/MM/dd; HH:mm:ss");
            if (strcmp(value, TAG_NAN) == 0)
            {
                    info_msg.value = NAN;
                    LOG_PRINT(warning_e, "INVALID VALUE!!!!!!!!!!!!!!!!!\n");
            }
            else
            {
                info_msg.value = atof(value);
            }
            emit new_trend(info_msg);
            LOG_PRINT(verbose_e, "emitted '%d' at '%s'(%s) value %s(%f)\n", info_msg.CtIndex, info_msg.timestamp.toString("yy/MM/dd HH:mm:ss").toAscii().data(), buffer, value, info_msg.value);
#endif
        }
    }
    else
    {
        for ( iS = 0; StoreArrayS[iS].tag[0] != '\0'; iS++)
        {
            nb_of_char = fprintf(storefp, "; %s", "-");
            if (nb_of_char != (int)strlen("-") + 2)
            {
                LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", "-", nb_of_char, (int)strlen("-") + 2);
                return false;
            }
        }
        iS = 0;
    }

    if (store_elem_nb_F > 0  && (counterF * ALARMS_PERIOD_MS) >= (LogPeriodSecF * 1000))
    {
        counterF = 0;
        for ( iF = 0; StoreArrayF[iF].tag[0] != '\0'; iF++)
        {
            /* if is active, dump if it is necessary and emit the signal */
            LOG_PRINT(verbose_e, "Reading '%s'\n", StoreArrayF[iF].tag);
            if (formattedReadFromDb(StoreArrayF[iF].CtIndex, value) != 0)
            {
                LOG_PRINT(error_e, "cannot read variable '%s'\n", StoreArrayF[iF].tag );
                strcpy(value, TAG_NAN);
            }

            nb_of_char = fprintf(storefp, "; %s", value);
            if (nb_of_char != (int)strlen(value) + 2)
            {
                LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", value, nb_of_char, (int)strlen(value) + 2);
                return false;
            }

#ifdef ENABLE_TREND
            /* emit a signal to the hmi with the new item to display */
            info_msg.CtIndex = StoreArrayF[iF].CtIndex;
            info_msg.timestamp = QDateTime::fromString(buffer,"yyyy/MM/dd; HH:mm:ss");
            if (strcmp(value, TAG_NAN) == 0)
            {
                    info_msg.value = NAN;
                    LOG_PRINT(warning_e, "INVALID VALUE!!!!!!!!!!!!!!!!!\n");
            }
            else
            {
                info_msg.value = atof(value);
            }
            emit new_trend(info_msg);
            LOG_PRINT(verbose_e, "emitted '%d' at '%s'(%s) value %s(%f)\n", info_msg.CtIndex, info_msg.timestamp.toString("yy/MM/dd HH:mm:ss").toAscii().data(), buffer, value, info_msg.value);
#endif
        }
    }
    else
    {
        for ( iF = 0; StoreArrayF[iF].tag[0] != '\0'; iF++)
        {
            nb_of_char = fprintf(storefp, "; %s", "-");
            if (nb_of_char != (int)strlen("-") + 2)
            {
                LOG_PRINT(error_e, "Cannot dump '%s' %d vs %d\n", "-", nb_of_char, (int)strlen("-") + 2);
                return false;
            }
        }
        iF = 0;
    }

    if (iF == 0 && iS == 0)
    {
        LOG_PRINT(warning_e, "No signal emitted\n");
#if 0
#ifndef LOG_DISABLED
        for ( int i = 0; i < 10; i++)
        {
            LOG_PRINT(error_e, "StoreArray[%d] = '%s'\n",i, StoreArray[i].tag );
        }
#endif
#endif
    }
    if (fprintf(storefp, "\n") != 1)
    {
        LOG_PRINT(error_e, "Cannot dump\n");
        return false;
    }
    fflush(storefp);
    LOG_PRINT(verbose_e, "dumped\n");
    return true;
}
#endif

int sum(__attribute__((unused)) const char *fpath, const struct stat *sb, __attribute__((unused)) int typeflag) {
	    total += sb->st_size;
		    return 0;
}

int Logger::checkSpace( void )
{
    struct statvfs fiData;

    if((statvfs(LOCAL_ROOT_DIR,&fiData)) < 0 )
    {
        LOG_PRINT(error_e,"Failed to stat %s:\n", LOCAL_ROOT_DIR);
        return -1;
    }

	if (fiData.f_bfree * fiData.f_bsize < 1024)
	{
        LOG_PRINT(info_e,"Free %ld [minimum free %d]\n", fiData.f_bfree * fiData.f_bsize, 1024);
		return 1;
	}

	total = 0;
	if (getSizeDir(STORE_DIR) != 0)
	{
		LOG_PRINT(error_e,"Failed to get size of %s:\n", LOCAL_ROOT_DIR);
		return -1;
	}

	LOG_PRINT(info_e, "total %ld limit %d avaliable %ld free %ld used %d%%\n",
			fiData.f_blocks - fiData.f_bavail,
			MaxLogUsageMb,
			fiData.f_bavail,
			fiData.f_bfree,
			(unsigned int)( (float)(fiData.f_blocks - fiData.f_bavail) / fiData.f_blocks * 100)
			);

	if (total >= (unsigned int)MaxLogUsageMb * 1024 * 1024)
	{
        LOG_PRINT(info_e,"total %d > MaxLogUsageMb %d\n", total, MaxLogUsageMb * 1024 * 1024);
		return 1;
	}
	return 0;
}

int Logger::getSizeDir(const char *dirname) {
	if (access(dirname, R_OK)) {
		return 1;
	}
	if (ftw(dirname, &sum, 1)) {
		perror("ftw");
		return 2;
	}
	LOG_PRINT(info_e, "%s: %u\n", dirname, total);
	return 0;
}

int Logger::removeOldest( const char * dir)
{
    struct dirent **filelist = {0};
    int fcount = -1;
    int i = 0;
    char filename[FILENAME_MAX];
    int retval = 0;

    fcount = scandir(dir, &filelist, 0, alphasort);

    if(fcount < 0) {
		LOG_PRINT (error_e, "No file to remove\n");
        perror(dir);
        return 1;
    }
    if(fcount == 1) {
		LOG_PRINT (error_e, " Only the actual file is available to remove.\n");
        perror(dir);
        return 1;
    }
    for(i = 0; i < fcount; i++)
    {
        if (strcmp(filelist[i]->d_name, ".") != 0 && strcmp(filelist[i]->d_name, "..") != 0)
        {
            sprintf(filename, "%s/%s", dir, filelist[i]->d_name);
            LOG_PRINT (info_e, "Removing oldest log file '%s'\n", filelist[i]->d_name);
            if (remove(filename) != 0)
            {
                LOG_PRINT (error_e, "Cannot remove oldest log file '%s'\n", filelist[i]->d_name);
            }
            else
            {
                retval++;
            }
            free(filelist[i]);
            break;
        }
    }

    free(filelist);
    return (retval == 0);
}

