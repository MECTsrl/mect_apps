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

#include <QElapsedTimer>

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
    void on_pushButtonShell_clicked();
    void on_pushButtonQProcess_clicked();

private:
    Ui::page100 *ui;
    QElapsedTimer   timeCounter;
    QString         homeDir;
    int             httpsPort;          // https default Port
    int             startTimeOut;
    int             connectPause;
    int             writePause;
    int             commandTimeOut;
    QString         shCommand;
    QString         postResult;
};

#endif // PAGE100_H


