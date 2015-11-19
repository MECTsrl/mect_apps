/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef COMM_STATUS_H
#define COMM_STATUS_H

#include "pagebrowser.h"

namespace Ui {
class comm_status;
}

class comm_status : public page
{
    Q_OBJECT
    
public:
    explicit comm_status(QWidget *parent = 0);
    ~comm_status();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonResetTCP_clicked();
    
    void on_pushButtonResetRTU_clicked();
    
    void on_pushButtonResetTCPRTU_clicked();
    
    void on_pushButtonNodeTCP_clicked();
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
private:
    Ui::comm_status *ui;
};

#endif // COMM_STATUS_H


