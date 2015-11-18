/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef MENU_H
#define MENU_H

#include "pagebrowser.h"

namespace Ui {
class menu;
}

class menu : public page
{
    Q_OBJECT
    
public:
    explicit menu(QWidget *parent = 0);
    ~menu();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonLogin_clicked();
    
    void on_pushButtonData_clicked();
    
    void on_pushButtonConfigurations_clicked();
    
    void on_pushButtonInfo_clicked();
    
    void on_pushButtonPages1_clicked();
    
    void on_pushButtonPages2_clicked();
    
    void on_pushButtonPages3_clicked();
    
    void on_pushButtonPages4_clicked();
    
#ifdef DEMO
    void on_pushButton_clicked();
#endif
    
private:
    Ui::menu *ui;
};

#endif // MENU_H


