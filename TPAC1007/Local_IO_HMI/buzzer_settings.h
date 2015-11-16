/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef BUZZER_SETTINGS_H
#define BUZZER_SETTINGS_H

#include "pagebrowser.h"

namespace Ui {
class buzzer_settings;
}

class buzzer_settings : public page
{
    Q_OBJECT
    
public:
    explicit buzzer_settings(QWidget *parent = 0);
    ~buzzer_settings();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonTouchBuzzer_toggled(bool checked);
    
    void on_pushButtonAlarmBuzzer_toggled(bool checked);
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
private:
    Ui::buzzer_settings *ui;
};

#endif // BUZZER_SETTINGS_H


