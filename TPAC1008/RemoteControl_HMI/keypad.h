#ifndef KEYPAD_H
#define KEYPAD_H
#include <QThread>
#include <QObject>
#include <linux/input.h>
#include <QWSScreenSaver>

//#define KEYBOARD    "/dev/input/event0"
#define TOUCHSCREEN "/dev/input/ts0"
#define BUZZER      "/dev/buzzer"
#define BUZZER_DURATION_MS 120
#define KEYBOARD_PERIOD_US (2 * BUZZER_DURATION_MS * 1000)

/* number of phisical key */
#ifdef TOUCHSCREEN
#include <tslib.h>
#endif

#define KEYNB 10
#define BASE_KEYCODE 59

#define BACKLIGHT_FILE_SYSTEM "/sys/devices/platform/mxs-bl.0/backlight/mxs-bl/brightness"

#define F01 0x41
#define F02 0x00
#define F03 0x00
#define F04 0x00
#define F05 0x00
#define F06 0x3F
#define F07 0x00
#define F08 0x00
#define F09 0x00
#define F10 0x00

int set_backlight_level(int level);
int get_backlight_level(void);

class keypad : public QThread
{
    
public:
    keypad();
    ~keypad();
    virtual void run();
    void play(int msec);
    void setBuzzer(bool status);
    bool getBuzzer(void);
    int getLCDLevel(void);
    int getLastAction(void);
    void resetLastAction(void);
private:
#ifdef TOUCHSCREEN
    struct tsdev *tsfd;
#endif
#ifdef KEYBOARD
    int kbdfd;
    int readInputKpd(char *keyCode, short *pressed);
#endif
#ifdef TOUCHSCREEN
    int readInputTS(short *x, short *y, short *pressed);
#endif
#ifdef BUZZER
    int Buzzerfd;
#endif
    int backlight_level;
private:
#ifdef KEYBOARD
    int keypressed(int keyCode);
    /* phisical key pressed map */
    bool Tpress[KEYNB];
#endif
    bool _buzzer_status;
    time_t timeout;
    time_t Now;
    int normal_bcklight_level;
};

#endif // KEYPAD_H


