/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Alarm page
 */
#ifndef ALARMS_H
#define ALARMS_H

#include "pagebrowser.h"
#include "hmi_logger.h"

namespace Ui {
class alarms;
}

class alarms : public page
{
    Q_OBJECT
    
public:
    explicit alarms(QWidget *parent = 0);
    ~alarms();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void addEvent(char * line, bool visibility, char * id, char * style = NULL);
    
    void addEvent(event_descr_e * msg, bool visibility);
    
    void on_pushButtonHistory_clicked();
    
    void on_comboBoxLevel_currentIndexChanged(int index);
    
    void on_comboBoxType_currentIndexChanged(int index);
    
    void on_pushButtonACK_clicked();
    
    void on_pushButtonACKall_clicked();
    
    void receiveEvent(char * msg);
    
    void on_pushButtonHornACK_clicked();
    
signals:
    void new_ack(event_msg_t * msg);
    
private:
    void refreshEvent();
private:
    Ui::alarms *ui;
    bool _alarm;
    bool _event;
    int _level;
};

#define ALARM_FIRST_TO_LAST
#define DATETIME_IS_ALARM_RISE

#endif // ALARMS_H


