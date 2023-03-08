/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE100_H
#define PAGE100_H

#include "pagebrowser.h"
#include <QString>
#include <QThread>
#include "alphanumpad.h"

namespace Ui {
class page100;
}

class page100 : public page
{
    Q_OBJECT
    
public:
    explicit page100(QWidget *parent = 0);
    ~page100();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);    
    void on_pushButtonText_clicked();
    void on_atcmButtonClear_clicked();
    void on_atcmButtonRead_clicked();
    void on_atcmButtonWrite_clicked();

private:
    Ui::page100 *ui;
    bool        firstTime;
    bool        serialOpened;
    bool        serialPortFound;
    QString     serialPortName;
    // QThread*    serialThread;
    alphanumpad *myKeyboard;                   // User Keyboard Pointer
};

#endif // PAGE100_H


