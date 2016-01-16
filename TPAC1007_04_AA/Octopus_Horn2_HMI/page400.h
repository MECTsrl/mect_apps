/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
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
    
    void on_atcmButton_AnIn_clicked();

    void on_atcmButton_AnOut_clicked();

    void on_atcmButton_VCC_clicked();

    void on_atcmButton_RTU_SRV_clicked();

private:
    Ui::page400 *ui;
};

#endif // PAGE400_H

