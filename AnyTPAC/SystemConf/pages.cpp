/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Selector of the new pages
 */
#include <math.h>

#include "app_logprint.h"
#include "pages.h"
#include "pagebrowser.h"
#include "commpar_rtu.h"
#include "commpar_tcp.h"
#include "commpar_tcprtu.h"
#include "comm_status.h"
#include "buzzer_settings.h"
#include "data_manager.h"
#include "display_settings.h"
#include "info.h"
#include "menu.h"
#include "options.h"
#include "page0.h"
#include "sgdd.h"
#include "time_set.h"
#include "utility.h"

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

int create_page_nb(page ** p, int pageNb)
{
    switch (pageNb)
    {
    case 0x0:
        *p = (page *)(new page0);
        break;
    case 0x100:
        *p = (page *)(new page100);
        break;
        /* add here the case labeled with the HEX id of the new pages */
    default:
        //printf ("Fatal error: cannot find page %d\n", pageNb);
        *p = NULL;
        return 1;
        break;
    }
    return 0;
}


