/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE400_H
#define PAGE400_H

#include "pagebrowser.h"

namespace Ui {
class page400;
}

class page400 : public page
{
    Q_OBJECT
    
public:
    explicit page400(QWidget *parent = 0);
    ~page400();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);    
    void on_atcmButton_SaveList_clicked();
    void on_atcmButton_1_clicked();
    void on_atcmButton_2_clicked();
    void on_atcmButton_3_clicked();
    void on_atcmButton_4_clicked();
    void on_atcmButton_5_clicked();

private:
    Ui::page400 *ui;
};

#endif // PAGE400_H

