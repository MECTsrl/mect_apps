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
#include "crosstable.h"
#include "utility.h"
#include "pages.h"

void printVncDisplayString(char * vncString)
{
    sprintf(vncString, "Multi: VNC:0:size=%dx%d Transformed:rot%d", WIDTH, HEIGHT, ROTATION);
    userPageList 
            << "page100"
            << "page200"
            << "page300"
            << "page400"
            << "page401"
            << "page402"
            << "page403"
            << "page404"
            << "page405"
            << "page434"
            << "page444"
            << "page201"
               /* add here the label of the new page */
               ;
    userPageList.removeDuplicates();
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
    case 0x400:
        *p = (page *)(new page400);
        break;
    case 0x401:
        *p = (page *)(new page401);
        break;
    case 0x402:
        *p = (page *)(new page402);
        break;
    case 0x403:
        *p = (page *)(new page403);
        break;
    case 0x404:
        *p = (page *)(new page404);
        break;
    case 0x405:
        *p = (page *)(new page405);
        break;
    case 0x434:
        *p = (page *)(new page434);
        break;
    case 0x444:
        *p = (page *)(new page444);
        break;
    case 0x201:
        *p = (page *)(new page201);
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

