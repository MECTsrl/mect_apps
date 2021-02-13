/**
 * @file
 * *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE300_H
#define PAGE300_H

#include "pagebrowser.h"

namespace Ui {
class page300;
}

class page300 : public page
{
    Q_OBJECT
    
public:
    explicit page300(QWidget *parent = 0);
    ~page300();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    void on_comboBox_AlarmConfig_currentIndexChanged(int index);
    void on_pushButton_AlarmEnable_clicked();
    void on_pushButton_AlarmAck_clicked();

private:
    void enableDisableCommands();
    void recoverConfig();
    unsigned readConfig(int index);
    void resetConfig(unsigned config);
    void transition(unsigned status, unsigned config);

private:
    Ui::page300 *ui;
};

#endif // PAGE300_H

