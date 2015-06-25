/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Setup MODBUS RTU option page
 */

#ifndef COMMPAR_RTU_H
#define COMMPAR_RTU_H

#include "pagebrowser.h"

namespace Ui {
class commpar_rtu;
}

class commpar_rtu : public page
{
    Q_OBJECT
    
public:
    explicit commpar_rtu(QWidget *parent = 0);
    ~commpar_rtu();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonQueryIntervalRTU_clicked();
    
    void on_pushButtonTimeOutRTU_clicked();
    
    void on_pushButtonOk_clicked();
    
    void on_pushButtonTCP_clicked();
    
    void on_pushButtonTCPRTU_clicked();
    
private:
    Ui::commpar_rtu *ui;
};

#endif // COMMPAR_RTU_H


