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
#include "atcmplugin.h"

#include <QColor>

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
    void updateTestLabel(ATCMlabel *test_label, unsigned test_level);
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page100 *ui;
    QColor colorDisabled;
    QColor colorTesting;
    QColor colorPassed;
    QColor colorFailed;
};

#endif // PAGE100_H


