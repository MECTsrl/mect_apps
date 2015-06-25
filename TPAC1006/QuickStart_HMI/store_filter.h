/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef STORE_FILTER_H
#define STORE_FILTER_H

#include "pagebrowser.h"

namespace Ui {
class store_filter;
}

class store_filter : public page
{
    Q_OBJECT
    
public:
    explicit store_filter(QWidget *parent = 0);
    ~store_filter();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonCancel_clicked();
    
    void on_pushButtonOk_clicked();
    
    void on_pushButtonReset_clicked();
    
private:
    Ui::store_filter *ui;
};

#endif // STORE_FILTER_H


