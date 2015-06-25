/*
 * Copyright 2011 Mect s.r.l
 */

/*
 * Filename: keypad.cpp
 */
#include "keypad.h"
#include "app_logprint.h"

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#ifdef BUZZER
#include <linux/mxs-buzzer.h>
#endif
#include <string.h>
#include <time.h>

#include <QWSServer>
#include <QWSMouseHandler>

//#define FC_BEEP_DEBUG
//#define FC_KEYPAD_DEBUG
timeval actual_buzz, last_buzz;
int last_duration_us = KEYBOARD_PERIOD_US;

keypad::keypad(void)
{
    Now = 0;
    timeout = 0;
    
#ifdef KEYBOARD
    /* open the keyboard in non-blocking*/
    kbdfd = open(KEYBOARD, O_RDONLY | O_NONBLOCK);
    
    if (kbdfd < 0) {
        LOG_PRINT( error_e, "can't open keyboard device '%s' [%s]\n", KEYBOARD, strerror(errno));
        assert(0);
    }
#endif
#ifdef TOUCHSCREEN
    /* open the touchscreen in non-blocking */
    if( getenv("TSLIB_TSDEVICE") != NULL ) {
        tsfd = ts_open (getenv("TSLIB_TSDEVICE"), 1);
    } else {
        tsfd = ts_open (TOUCHSCREEN, 1);
    }
    
    if (tsfd < 0) {
        LOG_PRINT( error_e, "can't open touchscreen device '%s' [%s]\n", TOUCHSCREEN, strerror(errno));
        assert(0);
    }
    
    if (ts_config(tsfd)) {
        LOG_PRINT( error_e, "can't config touchscreen device [%s]\n", strerror(errno));
        assert(0);
    }
#endif
    /* opening BUZZER file descriptor */
#ifdef BUZZER
    Buzzerfd = open(BUZZER, O_RDWR);
    
    if (Buzzerfd < 0) {
        LOG_PRINT( error_e, "can't open buzzer device '%s' [%s]\n", BUZZER, strerror(errno));
    }
#else
    LOG_PRINT( verbose_e, "buzzer disabled.\n");
#endif
    
    backlight_level = get_backlight_level();
#ifdef KEYBOARD
    /* initialize key pressed map */
    for (int i = 0; i < KEYNB; i++)
    {
        Tpress[i] = false;
    }
#endif
}

keypad::~keypad(void)
{
#ifdef KEYBOARD
    /* close the keyboard */
    close(kbdfd);
    kbdfd = -1;
#endif
    
#ifdef TOUCHSCREEN
    /* close the touchscreen */
    ts_close(tsfd);
#endif
    
#ifdef BUZZER
    /* close the buzzer */
    if (Buzzerfd != -1)
    {
        close(Buzzerfd);
        Buzzerfd = -1;
    }
#endif
}

void keypad::run(void)
{
#ifdef KEYBOARD
    char keyCode = 0;
#endif
    short pressed  = 0;
#ifdef TOUCHSCREEN
    short x, y;
#endif
    normal_bcklight_level = get_backlight_level();
    
    time(&Now);
    timeout = Now;
    
    while(1)
    {
        time(&Now);
#ifdef KEYBOARD
        /* operation to do */
        if ( readInputKpd(&keyCode, &pressed) == 0)
        {
#ifdef FC_KEYPAD_DEBUG
            LOG_PRINT(info_e, "read %x [%c] %d pressed = %d\n", keyCode, keyCode, keyCode, pressed);
#endif
            Tpress[keyCode - BASE_KEYCODE] = (pressed == 1);
            timeout = Now;
        }
        
        /* poll the key pressed map array */
        for (int i = 0; i < KEYNB; i++)
        {
            if ( Tpress[i] )
            {
                keypressed(BASE_KEYCODE + i);
            }
        }
#endif
#ifdef TOUCHSCREEN
        if ( readInputTS(&x, &y, &pressed) == 0 )
        {
#ifdef FC_KEYPAD_DEBUG
            LOG_PRINT(info_e, "read x = %d [%x]; y = %d [%x] pressed = %d [%x]\n", x, x, y, y, pressed, pressed);
#endif
            timeout = Now;
        }
#endif
        usleep(300000);
    }
}

#ifdef KEYBOARD
int keypad::readInputKpd(char *keyCode, short *pressed)
{
    *pressed = 0;
    *keyCode = 0;
    int ret = 0;
    struct input_event ev;
    
    ret = read(kbdfd, &ev, sizeof(struct input_event));
    
    if (ret < 0)
    {
#ifdef FC_KEYPAD_DEBUG
        LOG_PRINT(verbose_e, "cannot read: %s.\n", strerror(errno));
#endif
        return -1;
    }
    else if (ret == 0)
    {
        /* nothing to read */
#ifdef FC_KEYPAD_DEBUG
        LOG_PRINT(verbose_e,"nothing to read.\n");
#endif
        return 0;
    }
    
    if (ret != sizeof(struct input_event)) {
#ifdef FC_KEYPAD_DEBUG
        LOG_PRINT(verbose_e,"short key read: %d(%d)\n", ret, sizeof(struct input_event));
#endif
        return -2;
    }
    /* Key pressed */
    if (ev.value == 0 && ev.type && ev.code)
    {
#ifdef FC_KEYPAD_DEBUG
        LOG_PRINT(verbose_e, "### %d - pressed  t:%d v:%d.\n",ev.code, ev.type, ev.value);
#endif
        *pressed = 1;
#ifdef BUZZER
        if ( _buzzer_status == false || Buzzerfd == -1 || ioctl(Buzzerfd, BUZZER_BEEP, BUZZER_DURATION_MS) != 0)
        {
#ifdef FC_KEYPAD_DEBUG
            LOG_PRINT(warning_e, "cannot play the buzzer.\n");
#endif
        }
#ifdef FC_BEEP_DEBUG
        else
        {
            LOG_PRINT(info_e,"K Beeeep 1 !\n");
        }
#endif
#endif
#if 0
    }
    /* Key released */
    if (ev.value == 1 && ev.type && ev.code)
    {
#ifdef FC_KEYPAD_DEBUG
        LOG_PRINT(verbose_e, "### %d - released t:%d v:%d.\n",ev.code, ev.type, ev.value);
#endif
        *pressed = 0;
    }
#endif
    *keyCode = ev.code;
    return 0;
}
#endif

#ifdef TOUCHSCREEN

#define DELTA 1
/* readInputTS:
 * read the input x y pressed from the touchscreen driver
 */
int keypad::readInputTS(short *x, short *y, short *pressed)
{
    static int last_x = 0, last_y = 0;
    //static time_t last = 0;
    static struct ts_sample samp;
    static unsigned int last_pressure = 0;
    int touched = 0;
    
    
    
    if (ts_read(tsfd, &samp, 1) < 0) {
        fprintf(stderr,"ts_read failed \n");
        return 1;
    }
    else
    {
        *x = samp.x;
        *y = samp.y;
        *pressed = samp.pressure;
        //fprintf(stderr,"%ld.%06ld: %6d %6d %6d\n", samp.tv.tv_sec, samp.tv.tv_usec, samp.x, samp.y, samp.pressure);
        
        
        if ((samp.tv.tv_sec != last_buzz.tv_sec || samp.tv.tv_usec - last_buzz.tv_usec > last_duration_us) && samp.pressure == 1 && (samp.pressure != last_pressure))
        {
            if ( _buzzer_status == false ||
                 Buzzerfd == -1 ||
                 ioctl(Buzzerfd, BUZZER_BEEP, BUZZER_DURATION_MS) != 0)
            {
                if (Buzzerfd != -1)
                {
                    close(Buzzerfd);
                    Buzzerfd = open(BUZZER, O_RDWR);
                }
                
#ifdef FC_BEEP_DEBUG
                fprintf(stderr, " %s[%d] cannot play the buzzer.\n",__func__, __LINE__);
#endif
                
            }
#ifdef FC_BEEP_DEBUG
            else
            {
                
                fprintf(stderr, " %s[%d] T Beeeep duration %d!\n",__func__, __LINE__,  BUZZER_DURATION_MS);
            }
#endif
            last_buzz.tv_usec = samp.tv.tv_usec;
            last_buzz.tv_sec  = samp.tv.tv_sec;
            last_duration_us = BUZZER_DURATION_MS * 1000;
            touched = 1;
        }
        last_pressure = samp.pressure;
        last_x = samp.x;
        last_y = samp.y;
        
    }
    //Buzzer handling through QWServer; QT does not expone the pressure event but only the mouse position
#if 0	
    *x = (QWSServer::mouseHandler())->pos().x();
    *y = (QWSServer::mouseHandler())->pos().y();
    
    if ( lastx == 0 && lasty == 0 )
    {
        lastx = *x;
        lasty = *y;
    }
    
    if (*x - lastx > DELTA || *x - lastx < - DELTA || *y - lasty > DELTA || *y - lasty < - DELTA)
    {
#ifdef FC_BEEP_DEBUG
        LOG_PRINT(info_e, "mouse x:%d - y:%d vs lx:%d ly:%d dx:%d dy:%d\n", *x, *y, lastx, lasty, *x - lastx, *y - lasty);
        //fprintf(stderr, " %s[%d] mouse x:%d - y:%d vs lx:%d ly:%d dx:%d dy:%d\n",__func__, __LINE__, *x, *y, lastx, lasty, *x - lastx, *y - lasty);
#endif
#ifdef BUZZER
        gettimeofday(&actual_buzz, NULL);
        if (actual_buzz.tv_sec != last_buzz.tv_sec || actual_buzz.tv_usec - last_buzz.tv_usec > last_duration_us)
        {
            if ( _buzzer_status == false ||
                 Buzzerfd == -1 ||
                 ioctl(Buzzerfd, BUZZER_BEEP, BUZZER_DURATION_MS) != 0)
            {
                if (Buzzerfd != -1)
                {
                    close(Buzzerfd);
                    Buzzerfd = open(BUZZER, O_RDWR);
                }
#ifdef FC_BEEP_DEBUG
                LOG_PRINT(error_e,"cannot play the buzzer.\n");
                //fprintf(stderr, " %s[%d] cannot play the buzzer.\n",__func__, __LINE__);
#endif
            }
            else
            {
#ifdef FC_BEEP_DEBUG
                LOG_PRINT(info_e,"T Beeeep duration %d!\n", BUZZER_DURATION_MS);
                fprintf(stderr, " %s[%d] T Beeeep duration %d!\n",__func__, __LINE__,  BUZZER_DURATION_MS);
#endif
            }
            last_buzz.tv_usec = actual_buzz.tv_usec;
            last_buzz.tv_sec  = actual_buzz.tv_sec;
            last_duration_us = BUZZER_DURATION_MS * 1000;
        }
#ifdef FC_BEEP_DEBUG
        else
        {
            LOG_PRINT(info_e,"SKIP T BEEP %ld %ld vs %d\n", actual_buzz.tv_usec - last_buzz.tv_usec, actual_buzz.tv_sec - last_buzz.tv_sec, KEYBOARD_PERIOD_US);
            //fprintf(stderr,"%s[%d] SKIP T BEEP %ld %ld vs %d\n",__func__, __LINE__, actual_buzz.tv_usec - last_buzz.tv_usec, actual_buzz.tv_sec - last_buzz.tv_sec, KEYBOARD_PERIOD_US);
        }
#endif
        last = Now;
#endif
        *pressed = 1;
        lastx = *x;
        lasty = *y;
        return 0;
    }
    else
    {
#ifdef FC_BEEP_DEBUG
        LOG_PRINT(info_e, " DELTA NOT SATISFIED mouse x:%d - y:%d vs lx:%d ly:%d dx:%d dy:%d\n", *x, *y, lastx, lasty, *x - lastx, *y - lasty);
        //fprintf(stderr, " %s[%d] DELTA NOT SATISFIED mouse x:%d - y:%d vs lx:%d ly:%d dx:%d dy:%d\n",__func__, __LINE__, *x, *y, lastx, lasty, *x - lastx, *y - lasty);
#endif
        *x = lastx;
        *y = lasty;
        *pressed = 0;
        return 1;
    }
#endif // if 0
    return !touched;
}

#endif

int set_backlight_level(int level)
{
    int _level;
    char command[256];
    
    if (level < 0)
    {
        _level = 0;
    }
    else if ( level > 100)
    {
        _level = 100;
    }
    else
    {
        _level = level;
    }
    
    sprintf (command, "echo %d > %s", level, BACKLIGHT_FILE_SYSTEM);
    system(command);
    
    //printf("level set to: %d", level);
    return level;
}

int get_backlight_level(void)
{
    int level;
    FILE * fp = fopen(BACKLIGHT_FILE_SYSTEM, "r");
    if (fp != NULL)
    {
        fscanf(fp, "%d", &level);
    }
    fclose(fp);
    return level;
}

#ifdef KEYBOARD
/* funtion to implement the operation */
int keypad::keypressed(int keyCode)
{
#ifdef FC_KEYPAD_DEBUG
    LOG_PRINT(verbose_e, "keyCode %d \n", keyCode);
#endif
    /* if it is a lcd level key, manage the backlight */
    if (keyCode == F01)
    {
        /* plus one */
        backlight_level = set_backlight_level( backlight_level + 1 );
    }
    if (keyCode == F06)
    {
        /* minus one */
        backlight_level = set_backlight_level( backlight_level - 1 );
    }
}
#endif

void keypad::play(int msec)
{
#ifdef BUZZER
    if ( /*_buzzer_status == false ||*/ Buzzerfd == -1 || ioctl(Buzzerfd, BUZZER_BEEP, msec) != 0)
    {
#ifdef FC_KEYPAD_DEBUG
        LOG_PRINT(error_e,"cannot play the buzzer.\n");
#endif
    }
#ifdef FC_BEEP_DEBUG
    else
    {
        LOG_PRINT(info_e,"Play Beeeep!\n");
    }
#endif
#endif
}

void keypad::setBuzzer(bool status)
{
    _buzzer_status = status;
}

bool keypad::getBuzzer(void)
{
    return _buzzer_status;
}

/*TODO da migliorare */
int keypad::getLCDLevel(void)
{
    return backlight_level;
}

void keypad::resetLastAction(void)
{
    timeout = Now;
    return;
}

int keypad::getLastAction(void)
{
    return Now - timeout;
}


