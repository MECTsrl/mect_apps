/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE403_H
#define PAGE403_H

#include "pagebrowser.h"

namespace Ui {
class page403;
}

class page403 : public page
{
    Q_OBJECT
    
public:
    explicit page403(QWidget *parent = 0);
    ~page403();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page403 *ui;
};

#endif // PAGE403_H

