/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE404_H
#define PAGE404_H

#include "pagebrowser.h"

namespace Ui {
class page404;
}

class page404 : public page
{
    Q_OBJECT
    
public:
    explicit page404(QWidget *parent = 0);
    ~page404();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page404 *ui;
};

#endif // PAGE404_H

