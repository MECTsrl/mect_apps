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

#include "page0.h"
#include "common.h"
#include "main.h"
#include "app_logprint.h"
#include "utility.h"
#include "global_var.h"

#include "commpar_rtu.h"
#include "commpar_tcp.h"
#include "commpar_tcprtu.h"
#include "comm_status.h"
#include "cross_table_utility.h"
#include "buzzer_settings.h"
#include "data_manager.h"
#include "display_settings.h"
#include "info.h"
#include "main.h"
#include "menu.h"
#include "options.h"
#include "page0.h"
#include "pages.h"
#include "sgdd.h"
#include "time_set.h"
#include "app_cfg_file.h"

#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
#include "datalog_set.h"
#endif

#ifdef ENABLE_ALARMS
#include "alarms.h"
#include "alarms_history.h"
#endif

#ifdef ENABLE_STORE
#include "store.h"
#include "store_filter.h"
#endif

#ifdef ENABLE_TREND
#include "trend.h"
#include "trend_other.h"
#include "trend_option.h"
#include "trend_range.h"
#endif

#ifdef ENABLE_RECIPE
#include "recipe.h"
#include "recipe_select.h"
#endif

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
    /* parse the command line option */
    if (application_options(argc, argv) != 0) {
        LOG_PRINT(error_e, "%s: command line option error.\n", __func__);
        return 1;
    }
    
    /* print the version */
    LOG_PRINT_NO_INFO(info_e, "#######################\n");
    LOG_PRINT_NO_INFO(info_e, "# Version: %10s #\n", VERSION);
    LOG_PRINT_NO_INFO(info_e, "#######################\n");
    
    /* instantiate the GUI application object */
    QApplication app(argc, argv);
    
    /* load the library icons */
    Q_INIT_RESOURCE(atcmicons);
    
    /* initialize the application (load configurations and start threads) */
    initialize();
    
    /* start page 0 (the splash screen) */
    page0 w;
    w.SHOW();
    w.reload();
    
    /* start the buzzer event filter */
    app.installEventFilter(new MyEventFilter());
    
    /* start the GUI application */
    app.exec();
    
    /* finalize the application (stop threads) */
    finalize();
    
    return 0;
}

/**
 * @brief create a new page
 */
bool create_next_page(page ** p, const char * t)
{
    *p = NULL;
    /* special pages */
    if (strncmp(t, PAGE_PREFIX, strlen(PAGE_PREFIX)) != 0)
    {
        if (strcmp(t, "commpar_rtu") == 0)
        {
            *p = (page *)(new commpar_rtu);
        }
        else if (strcmp(t, "commpar_tcp") == 0)
        {
            *p = (page *)(new commpar_tcp);
        }
        else if (strcmp(t, "commpar_tcprtu") == 0)
        {
            *p = (page *)(new commpar_tcprtu);
        }
        else if (strcmp(t, "comm_status") == 0)
        {
            *p = (page *)(new comm_status);
        }
        else if (strcmp(t, "info") == 0)
        {
            *p = (page *)(new info);
        }
        else if (strcmp(t, "buzzer_settings") == 0)
        {
            *p = (page *)(new buzzer_settings);
        }
        else if (strcmp(t, "data_manager") == 0)
        {
            *p = (page *)(new data_manager);
        }
        else if (strcmp(t, "display_settings") == 0)
        {
            *p = (page *)(new display_settings);
        }
        else if (strcmp(t, "menu") == 0)
        {
            *p = (page *)(new menu);
        }
        else if (strcmp(t, "options") == 0)
        {
            *p = (page *)(new options);
        }
        else if (strcmp(t, "sgdd") == 0)
        {
            *p = (page *)(new sgdd);
        }
        else if (strcmp(t, "time_set") == 0)
        {
            *p = (page *)(new time_set);
        }
#if defined(ENABLE_ALARMS) || defined(ENABLE_TREND) || defined(ENABLE_STORE)
        else if (strcmp(t, "datalog_set") == 0)
        {
            *p = (page *)(new datalog_set);
        }
#endif
#ifdef ENABLE_ALARMS
        else if (strcmp(t, "alarms") == 0)
        {
            *p = (page *)(new alarms);
        }
        else if (strcmp(t, "alarms_history") == 0)
        {
            *p = (page *)(new alarms_history);
        }
#endif
#ifdef ENABLE_STORE
        else if (strcmp(t, "store") == 0)
        {
            *p = (page *)(new store);
        }
        else if (strcmp(t, "store_filter") == 0)
        {
            *p = (page *)(new store_filter);
        }
#endif
#ifdef ENABLE_TREND
        else if (strcmp(t, "trend") == 0)
        {
            *p = (page *)(new trend);
        }
        else if (strcmp(t, "trend_other") == 0)
        {
            *p = (page *)(new trend_other);
        }
        else if (strcmp(t, "trend_option") == 0)
        {
            *p = (page *)(new trend_option);
        }
        else if (strcmp(t, "trend_range") == 0)
        {
            *p = (page *)(new trend_range);
        }
#endif
#ifdef ENABLE_RECIPE
        else if (strcmp(t, "recipe") == 0)
        {
            *p = (page *)(new recipe);
        }
        else if (strcmp(t, "recipe_select") == 0)
        {
            *p = (page *)(new recipe_select);
        }
#endif
        else
        {
            LOG_PRINT(error_e, "cannot create special page %s\n", t);
            return false;
        }
    }
    /* it is a ordinary pages */
    else
    {
        int pageNb = atoh(&(t[strlen(PAGE_PREFIX)]));
        
        if (create_page_nb(p, pageNb)!= 0)
        {
            LOG_PRINT(error_e, "cannot create ordinary page %d (%s)\n", pageNb, t);
            return false;
        }
    }
    return true;
}


