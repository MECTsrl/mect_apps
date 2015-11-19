/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Configuration page
 */
#ifndef OPTIONS_H
#define OPTIONS_H

#include "pagebrowser.h"

namespace Ui {
class options;
}

class options : public page
{
    Q_OBJECT
    
public:
    explicit options(QWidget *parent = 0);
    ~options();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonDateAndTime_clicked();
    
    void on_pushButtonModbus_clicked();
    
    void on_pushButtonPasswords_clicked();
    
    void on_pushButtonErrorsStrategy_clicked();
    
    void on_pushButtonHomePage_clicked();
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonDatalog_clicked();
    
    void on_pushButtonDisplaySettings_clicked();
    
    void on_pushButtonBuzzerSettings_clicked();
    
    void on_pushButtonLanguage_clicked();
    
private:
    Ui::options *ui;
};

#endif // OPTIONS_H




