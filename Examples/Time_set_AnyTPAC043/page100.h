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

    void on_pushButtonHome_clicked();
    void on_pushButtonBack_clicked();
    void on_pushButtonSetManual_clicked();
    void on_pushButtonTime_clicked();
    void on_pushButtonCalendar_clicked();
    void on_pushButtonNTPSync_clicked();
    void on_pushButtonNTPServer_clicked();
    void on_pushButtonNTPOffset_clicked();
    void on_pushButtonNTPTimeOut_clicked();
    void on_pushButtonNTPPeriod_clicked();
    void on_pushButtonNTPSet_clicked();
    void on_pushButtonNTPDefualts_clicked();
    void ntpSyncDone(bool timeOut);
    void ntpManualSetDone(bool setOk);
    void lockUI(bool setLocked);
    
private:
    void        updateIface();

    Ui::page100 *ui;
    int             nOffset;
    int             nTimeOut;
    int             nPeriod;
    QString         szTimeServer;
    bool            lockInterface;
    bool            ntpSyncRunning;
    QElapsedTimer   syncElapsed;
    QDateTime       datetimeTarget;
};

#endif // PAGE100_H


