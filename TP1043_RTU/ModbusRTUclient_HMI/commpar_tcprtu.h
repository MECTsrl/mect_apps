/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Setup MODBUS TCPRTU option page
 */
#ifndef COMMPAR_TCPRTU_H
#define COMMPAR_TCPRTU_H

#include "pagebrowser.h"

namespace Ui {
class commpar_tcprtu;
}

class commpar_tcprtu : public page
{
    Q_OBJECT
    
public:
    explicit commpar_tcprtu(QWidget *parent = 0);
    ~commpar_tcprtu();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonRTU_clicked();
    void on_pushButtonTCP_clicked();
    
    void on_pushButtonTimeOutTCPRTU_clicked();
    
    void on_pushButtonOk_clicked();
    
    void on_pushButtonIpTCPRTU_clicked();
    
    void on_pushButtonPortTCPRTU_clicked();
    
    void on_pushButtonTimeMinTCPRTU_clicked();
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
private:
    Ui::commpar_tcprtu *ui;
};

#endif // COMMPAR_TCPRTU_H


