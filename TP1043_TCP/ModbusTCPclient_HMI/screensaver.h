#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QWSScreenSaver>
#include "app_cfg_file.h"

#define BACKLIGHT_FILE_LOCAL  LOCAL_ETC_DIR"/brightness"
#define BACKLIGHT_FILE_SYSTEM "/sys/devices/platform/mxs-bl.0/backlight/mxs-bl/brightness"

#define MIN_BACKLIGHT_LEVEL 20
#define MAX_BACKLIGHT_LEVEL 70
#define DEF_BACKLIGHT_LEVEL 60

#define SCREENSAVER_DEFAULT_TIME 30000 //defalt time before the screensaver becomes active. Expressed in msec


class ScreenSaver : public QWSScreenSaver
{
    
public:
    void restore();
    bool save(int level);
private:
    
};

#endif // SCREENSAVER_H

