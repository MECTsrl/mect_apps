/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE100_H
#define PAGE100_H

#include "pagebrowser.h"

namespace Ui {
class page100;
}

class page100 : public page
{
    Q_OBJECT
    
public:
    explicit page100(QWidget *parent = 0);
    ~page100();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);

    void on_atcmButton_String_clicked();

private:
    Ui::page100 *ui;

    alphanumpad     *myKeyboard;            // alphanumpad object pointer, allocated only once in page creation
    char            myValue[STR_LEN];       // Internal Char Buffer for alphanumpad
};

#endif // PAGE100_H


