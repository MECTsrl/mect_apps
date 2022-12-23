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
    void on_pushButtonBroker_clicked();
    void on_pushButtonTopic_clicked();
    void on_atcmMQTT_Start_toggled(bool checked);

    void on_pushButtonSubTopic_clicked();

private:
    void        updateIface();

    Ui::page100 *ui;
    QString     mqttBroker;
    QString     mqttSendTopic;
    QString     boardSerialNumber;
    int         mqttConnectionCount;
    int         nUpdateLoop;
    int         nSentMessageCount;
    int         nReceivedMessageCount;

};

#endif // PAGE100_H


