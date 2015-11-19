/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef display_settings_H
#define display_settings_H

#include "pagebrowser.h"
#include "screensaver.h"

namespace Ui {
class display_settings;
}

class display_settings : public page
{
    Q_OBJECT
    
public:
    explicit display_settings(QWidget *parent = 0);
    ~display_settings();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void change_brightness();
    
    void on_pushButtonMinus_pressed();
    
    void on_pushButtonMinus_released();
    
    void on_pushButtonPlus_pressed();
    
    void on_pushButtonPlus_released();
    
    void on_horizontalSlider_valueChanged(int value);
    
    void on_pushButton_clicked();
    
    void on_pushButtonON_clicked();
    
    void on_pushButtonOFF_clicked();
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
private:
    Ui::display_settings *ui;
    QTimer * timer;
    int increment;
    int brightness_level;
};

#endif // display_settings_H

