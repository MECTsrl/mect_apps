/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE405_H
#define PAGE405_H

#include "pagebrowser.h"

namespace Ui {
class page405;
}

class page405 : public page
{
    Q_OBJECT
    
public:
    explicit page405(QWidget *parent = 0);
    ~page405();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page405 *ui;
};

#endif // PAGE405_H

