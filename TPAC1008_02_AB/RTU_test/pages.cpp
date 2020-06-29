/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Selector of the new pages
 */
#include <math.h>

#include "app_logprint.h"
#include "crosstable.h"
#include "global_var.h"
#include "utility.h"
#include "pages.h"

void printVncDisplayString(char * vncString)
{
#if 1
    sprintf(vncString, "Multi: VNC:0:size=%dx%d Transformed:rot%d", WIDTH, HEIGHT, ROTATION);
#else
    sprintf(vncString,        "VNC:0:size=%dx%d"                  , WIDTH, HEIGHT          );
#endif
    fprintf(stderr, "vncString='%s'\n", vncString);
    userPageList 
            << "system_ini"
            << "page100"
            << "page200"
            << "page300"
               /* add here the label of the new page */
               ;
    userPageList.removeDuplicates();
    
#ifdef GIT_TAG
    HMIversion = GIT_TAG;
#endif
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
    case 0x200:
        *p = (page *)(new page200);
        break;
    case 0x300:
        *p = (page *)(new page300);
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


