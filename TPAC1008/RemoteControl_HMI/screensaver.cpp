#include "screensaver.h"
#include "app_logprint.h"

#include <string.h>
#include "common.h"




void ScreenSaver::restore()
{
    //turn backlight on
    
    int brightness_level;
    char command[256]="";
    
    
    //get current settings for backlight
    FILE * fp = fopen(BACKLIGHT_FILE_LOCAL, "r");
    
    if (fp == NULL)
    {
        LOG_PRINT(warning_e, "no local configuration file for screensaver found using defaults \n");
        brightness_level = DEF_BACKLIGHT_LEVEL;
    }
    else
    {
        while(fgets(command,256,fp)!=NULL)
        {
            LOG_PRINT(verbose_e, "BACKLIGHT: %s\n", command);
            sscanf(command,"echo %d > /sys/devices/platform/mxs-bl.0/backlight/mxs-bl/brightness", &brightness_level );
        }
        fclose(fp);
    }
    
    if (brightness_level < MIN_BACKLIGHT_LEVEL)
    {
        brightness_level = MIN_BACKLIGHT_LEVEL;
    }
    else if ( brightness_level > MAX_BACKLIGHT_LEVEL)
    {
        brightness_level = 100;
    }
    
    sprintf (command, "echo %d > %s", brightness_level, BACKLIGHT_FILE_SYSTEM);
    system(command);
    
    LOG_PRINT(info_e, "EXITING SCREENSAVER\n");
    
    
}

bool ScreenSaver::save(__attribute__((unused)) int level)
{
    //turn backlight off
    int brightness_level = 10;
    char command[256]="";
    
    sprintf (command, "echo %d > %s", brightness_level, BACKLIGHT_FILE_SYSTEM);
    system(command);
    
    LOG_PRINT(info_e, "ENTERING SCREENSAVER\n");
    return true;
    
}

