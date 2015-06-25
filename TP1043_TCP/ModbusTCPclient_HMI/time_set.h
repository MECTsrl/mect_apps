/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Setup date and time page
 */
#ifndef TIME_SET_H
#define TIME_SET_H

#include "pagebrowser.h"

namespace Ui {
class time_set;
}

class time_set : public page
{
    Q_OBJECT
    
public:
    explicit time_set(QWidget *parent = 0);
    ~time_set();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonOk_clicked();
    
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();
    
private:
    Ui::time_set *ui;
};

#endif // TIME_SET_H


