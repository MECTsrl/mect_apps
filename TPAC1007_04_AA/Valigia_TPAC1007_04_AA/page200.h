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
    
private:
    Ui::page200 *ui;
};

#endif // PAGE200_H

