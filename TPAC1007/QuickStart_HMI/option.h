/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Configuration page
 */
#ifndef OPTION_H
#define OPTION_H

#include "pagebrowser.h"

namespace Ui {
class option;
}

class option : public page
{
    Q_OBJECT
    
public:
    explicit option(QWidget *parent = 0);
    ~option();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
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
    
private:
    Ui::option *ui;
};

#endif // OPTION_H


