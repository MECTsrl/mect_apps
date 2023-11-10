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
#include <QFile>

void printVncDisplayString(char * vncString)
{
#define VERSATILE_APPLICATION
#ifdef VERSATILE_APPLICATION
    // what the wizard wrote in template.pri?
    int phys_width = WIDTH, phys_height = HEIGHT, rot = ROTATION;
    
    if (rot == 270 || rot == 90) {
        phys_width = HEIGHT;
        phys_height = WIDTH;
    }
    // what the kernel knows? ---> maybe a different display size
    QFile virtual_size("/sys/class/graphics/fb0/virtual_size");
    if (virtual_size.open(QIODevice::ReadOnly)) {
        char buf[42];
        
        if (virtual_size.readLine(buf, 42) > 0) {
            int w = phys_width, h = phys_height;
            
            if (sscanf(buf, "%d,%d", &w, &h) == 2) {
                phys_width = w;
                phys_height = h;
            }
        }
    }
    // what the user set? --> maybe a different orientation
    QSettings *options = new QSettings(HMI_INI_FILE, QSettings::IniFormat);
    if (options) {
        bool ok;
        int r = options->value("rotation", rot).toInt(&ok);
        
        if (ok && r != rot) {
            rot = r;
        }
    }
    // QApplication arguments
    switch (rot) {
    case 0:
    case 180:
        sprintf(vncString, "Multi: VNC:0:size=%dx%d Transformed:rot%d", phys_width, phys_height, rot);
        break;
    case 90:
    case 270:
        sprintf(vncString, "Multi: VNC:0:size=%dx%d Transformed:rot%d", phys_height, phys_width, rot);
        break;
    default:
        ;
    }
#else
    sprintf(vncString, "Multi: VNC:0:size=%dx%d Transformed:rot%d", WIDTH, HEIGHT, ROTATION);
#endif
    userPageList
            << "system_ini"
            << "page100"
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
        /* add here the case labeled with the HEX id of the new pages */
    default:
        //printf ("Fatal error: cannot find page %d\n", pageNb);
        *p = NULL;
        return 1;
        break;
    }
    return 0;
}


