/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Setup MODBUS TCP option page
 */
#ifndef COMMPAR_TCP_H
#define COMMPAR_TCP_H

#include "pagebrowser.h"

namespace Ui {
class commpar_tcp;
}

class commpar_tcp : public page
{
    Q_OBJECT
    
public:
    explicit commpar_tcp(QWidget *parent = 0);
    ~commpar_tcp();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonRTU_clicked();
    
    void on_pushButtonTCPRTU_clicked();
    
    void on_pushButtonTimeOutTCP_clicked();
    
    void on_pushButtonIpTCP_clicked();
    
    void on_pushButtonPortTCP_clicked();
    
    void on_pushButtonTimeMinTCP_clicked();
    
    void on_pushButtonOk_clicked();
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
private:
    Ui::commpar_tcp *ui;
};

#endif // COMMPAR_TCP_H


