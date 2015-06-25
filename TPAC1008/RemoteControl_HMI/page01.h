/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE01_H
#define PAGE01_H

#include "pagebrowser.h"

namespace Ui {
class page01;
}

class page01 : public page
{
    Q_OBJECT
    
public:
    explicit page01(QWidget *parent = 0);
    ~page01();
    virtual void reload(void);
    virtual void updateData();
    
private slots:


    void on_atcmTime_clicked();

    void on_atcmDate_clicked();

private:
    Ui::page01 *ui;
};

#endif // PAGE01_H

