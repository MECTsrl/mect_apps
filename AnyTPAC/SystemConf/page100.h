/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
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
    
    void on_pushButton_Save_clicked();

    void on_pushButton_PwdLogoutPage_clicked();

    void on_pushButton_StartPage_clicked();

    void on_pushButton_HomePage_clicked();

private:
    Ui::page100 *ui;
    void save_all();
};

#endif // PAGE100_H


