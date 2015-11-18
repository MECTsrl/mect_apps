/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Error management page
 */
#ifndef SGDD_H
#define SGDD_H

#include "pagebrowser.h"

namespace Ui {
class sgdd;
}

class sgdd : public page
{
    Q_OBJECT
    
public:
    explicit sgdd(QWidget *parent = 0);
    ~sgdd();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonFailNb_clicked();
    
    void on_pushButtonFailDivisor_clicked();
    
    void on_pushButtonOk_clicked();
    
    void on_pushButtonHighPriorityTimer_clicked();
    
    void on_pushButtonMediumPriorityTimer_clicked();
    
    void on_pushButtonLowPriorityTimer_clicked();
    
private:
    Ui::sgdd *ui;
};

#endif // SGDD_H


