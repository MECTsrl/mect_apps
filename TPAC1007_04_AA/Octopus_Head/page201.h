/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE201_H
#define PAGE201_H

#include "pagebrowser.h"

namespace Ui {
class page201;
}

class page201 : public page
{
    Q_OBJECT
    
public:
    explicit page201(QWidget *parent = 0);
    ~page201();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page201 *ui;
};

#endif // PAGE201_H

