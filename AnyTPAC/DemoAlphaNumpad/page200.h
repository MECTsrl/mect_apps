/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE200_H
#define PAGE200_H

#include "pagebrowser.h"
#include "defines.h"
#include "alphanumpad.h"

namespace Ui {
class page200;
}

class page200 : public page
{
    Q_OBJECT
    
public:
    explicit page200(QWidget *parent = 0);
    ~page200();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    void on_pushButtonEveryTime_clicked();
    void on_pushButtonOnce_clicked();

private:
    Ui::page200 *ui;
    alphanumpad     *myKeyboard;            // alphanumpad object pointer, allocated only once in page creation
    char            myValue[STR_LEN];       // Internal Char Buffer for alphanumpad
};

#endif // PAGE200_H

