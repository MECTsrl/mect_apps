#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page300.h"
#include "ui_page300.h"
#include "crosstable.h"

#include "automation.h"

#define SET_PAGE300_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

page300::page300(QWidget *parent) :
    page(parent),
    ui(new Ui::page300)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */

    SET_PAGE300_STYLE();
    translateFontSize(this);

    ui->atcmButton_Heating_2->setEnabled(false);
    ui->atcmButton_XX_01->setEnabled(false);
    ui->atcmButton_XX_02->setEnabled(false);
    ui->atcmButton_XX_03->setEnabled(false);
    ui->atcmButton_XX_04->setEnabled(false);
    ui->atcmButton_XX_05->setEnabled(false);
    ui->atcmButton_XX_06->setEnabled(false);
    ui->atcmButton_XX_07->setEnabled(false);
    ui->atcmButton_XX_08->setEnabled(false);
    ui->atcmButton_XX_09->setEnabled(false);
    ui->atcmButton_XX_10->setEnabled(false);
    ui->atcmButton_XX_11->setEnabled(false);
    ui->atcmButton_XX_12->setEnabled(false);
    ui->atcmButton_XX_13->setEnabled(false);
    ui->atcmButton_XX_14->setEnabled(false);
    ui->atcmButton_XX_15->setEnabled(false);
    ui->atcmButton_XX_16->setEnabled(false);

    ui->atcmButton_XX_01_bis->setEnabled(false);
    ui->atcmButton_XX_02_bis->setEnabled(false);
    ui->atcmButton_XX_03_bis->setEnabled(false);
    ui->atcmButton_XX_04_bis->setEnabled(false);
    ui->atcmButton_XX_05_bis->setEnabled(false);
    ui->atcmButton_XX_06_bis->setEnabled(false);
    ui->atcmButton_XX_07_bis->setEnabled(false);
    ui->atcmButton_XX_08_bis->setEnabled(false);
    ui->atcmButton_XX_09_bis->setEnabled(false);
    ui->atcmButton_XX_10_bis->setEnabled(false);
    ui->atcmButton_XX_11_bis->setEnabled(false);
    ui->atcmButton_XX_12_bis->setEnabled(false);
    ui->atcmButton_XX_13_bis->setEnabled(false);
    ui->atcmButton_XX_14_bis->setEnabled(false);
    ui->atcmButton_XX_15_bis->setEnabled(false);
    ui->atcmButton_XX_16_bis->setEnabled(false);

    //
    switch (AlarmStatus) {
    case ALARM_STATUS_ZERO:
        recoverConfig();
        break;
    case ALARM_STATUS_IDLE:
    case ALARM_STATUS_ARMED:
    case ALARM_STATUS_ENABLED:
    case ALARM_STATUS_RINGING:
    case ALARM_STATUS_MUTED:
    default:
        ;
    }
    enableDisableCommands();
}

void page300::enableDisableCommands()
{
    switch (AlarmStatus) {
    case ALARM_STATUS_ZERO:
        ui->comboBox_AlarmConfig->setEnabled(false);
        ui->pushButton_AlarmEnable->setText("Enable");
        ui->pushButton_AlarmEnable->setEnabled(false);
        ui->pushButton_AlarmAck->setEnabled(false);
        break;
    case ALARM_STATUS_IDLE:
        ui->comboBox_AlarmConfig->setEnabled(true);
        ui->pushButton_AlarmEnable->setText("Enable");
        ui->pushButton_AlarmEnable->setEnabled(false);
        ui->pushButton_AlarmAck->setEnabled(false);
        break;
    case ALARM_STATUS_ARMED:
        ui->comboBox_AlarmConfig->setEnabled(true);
        ui->pushButton_AlarmEnable->setText("Enable");
        ui->pushButton_AlarmEnable->setEnabled(true);
        ui->pushButton_AlarmAck->setEnabled(false);
        break;
    case ALARM_STATUS_ENABLED:
        ui->comboBox_AlarmConfig->setEnabled(false);
        ui->pushButton_AlarmEnable->setText("Disable");
        ui->pushButton_AlarmEnable->setEnabled(true);
        ui->pushButton_AlarmAck->setEnabled(false);
        break;
    case ALARM_STATUS_RINGING:
        ui->comboBox_AlarmConfig->setEnabled(false);
        ui->pushButton_AlarmEnable->setText("Disable");
        ui->pushButton_AlarmEnable->setEnabled(false);
        ui->pushButton_AlarmAck->setEnabled(true);
        break;
    case ALARM_STATUS_MUTED:
        ui->comboBox_AlarmConfig->setEnabled(false);
        ui->pushButton_AlarmEnable->setText("Disable");
        ui->pushButton_AlarmEnable->setEnabled(true);
        ui->pushButton_AlarmAck->setEnabled(false);
        break;
    default:
        ;
    }

//    // ------- old alarms ack
//    bool found = false;
//    pthread_mutex_lock(&alarmevents_list_mutex);
//    {
//        for (int i = 0; i < _active_alarms_events_.count(); i++)
//        {
//            if (! _active_alarms_events_.at(i)->isack) {
//                found = true;
//                break;
//            }
//        }
//    }
//    pthread_mutex_unlock(&alarmevents_list_mutex);
//    ui->atcmButton_ack->setEnabled(found);
}

void page300::reload()
{
    resetConfig(SavedAlarmConfig);
    enableDisableCommands();
}

void page300::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
    enableDisableCommands();
}

void page300::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

page300::~page300()
{
    delete ui;
}

// ---------------------------------------------------------------------------

void page300::transition(unsigned status, unsigned config)
{
    if (status == ALARM_STATUS_ZERO or status > ALARM_STATUS_MUTED) {
        fprintf(stderr, "%s() wrong status %u\n", __func__, status);
        return;
    }
    beginWrite();

    // status
    addWrite_AlarmStatus(status);
    addWrite_SavedAlarmStatus(status);

    // digout
    int outValue = 0;
    if (status >= ALARM_STATUS_ARMED) {
        outValue = 1;
    }
    addWrite_XX_DigOut_A_1 (outValue);
    addWrite_XX_DigOut_A_2 (outValue);
    addWrite_XX_DigOut_A_3 (outValue);
    addWrite_XX_DigOut_A_4 (outValue);
    addWrite_XX_DigOut_A_5 (outValue);
    addWrite_XX_DigOut_A_6 (outValue);
    addWrite_XX_DigOut_A_7 (outValue);
    addWrite_XX_DigOut_A_8 (outValue);
    addWrite_XX_DigOut_A_9 (outValue);
    addWrite_XX_DigOut_A_10(outValue);
    addWrite_XX_DigOut_A_11(outValue);
    addWrite_XX_DigOut_A_12(outValue);
    addWrite_XX_DigOut_A_13(outValue);
    addWrite_XX_DigOut_A_14(outValue);
    addWrite_XX_DigOut_A_15(outValue);
    addWrite_XX_DigOut_A_16(outValue);

    // config
    resetConfig(config);
    addWrite_SavedAlarmConfig(config);
    addWrite_AlarmArmed_B_1 ((config & 0x00000001) ? 1 : 0);
    addWrite_AlarmArmed_B_2 ((config & 0x00000002) ? 1 : 0);
    addWrite_AlarmArmed_B_3 ((config & 0x00000004) ? 1 : 0);
    addWrite_AlarmArmed_B_4 ((config & 0x00000008) ? 1 : 0);
    addWrite_AlarmArmed_B_5 ((config & 0x00000010) ? 1 : 0);
    addWrite_AlarmArmed_B_6 ((config & 0x00000020) ? 1 : 0);
    addWrite_AlarmArmed_B_7 ((config & 0x00000040) ? 1 : 0);
    addWrite_AlarmArmed_B_8 ((config & 0x00000080) ? 1 : 0);
    addWrite_AlarmArmed_B_9 ((config & 0x00000100) ? 1 : 0);
    addWrite_AlarmArmed_B_10((config & 0x00000200) ? 1 : 0);
    addWrite_AlarmArmed_B_11((config & 0x00000400) ? 1 : 0);
    addWrite_AlarmArmed_B_12((config & 0x00000800) ? 1 : 0);
    addWrite_AlarmArmed_B_13((config & 0x00001000) ? 1 : 0);
    addWrite_AlarmArmed_B_14((config & 0x00002000) ? 1 : 0);
    addWrite_AlarmArmed_B_15((config & 0x00004000) ? 1 : 0);
    addWrite_AlarmArmed_B_16((config & 0x00008000) ? 1 : 0);
    addWrite_AlarmArmed_A_1 ((config & 0x00010000) ? 1 : 0);
    addWrite_AlarmArmed_A_2 ((config & 0x00020000) ? 1 : 0);
    addWrite_AlarmArmed_A_3 ((config & 0x00040000) ? 1 : 0);
    addWrite_AlarmArmed_A_4 ((config & 0x00080000) ? 1 : 0);
    addWrite_AlarmArmed_A_5 ((config & 0x00100000) ? 1 : 0);
    addWrite_AlarmArmed_A_6 ((config & 0x00200000) ? 1 : 0);
    addWrite_AlarmArmed_A_7 ((config & 0x00400000) ? 1 : 0);
    addWrite_AlarmArmed_A_8 ((config & 0x00800000) ? 1 : 0);
    addWrite_AlarmArmed_A_9 ((config & 0x01000000) ? 1 : 0);
    addWrite_AlarmArmed_A_10((config & 0x02000000) ? 1 : 0);
    addWrite_AlarmArmed_A_11((config & 0x04000000) ? 1 : 0);
    addWrite_AlarmArmed_A_12((config & 0x08000000) ? 1 : 0);
    addWrite_AlarmArmed_A_13((config & 0x10000000) ? 1 : 0);
    addWrite_AlarmArmed_A_14((config & 0x20000000) ? 1 : 0);
    addWrite_AlarmArmed_A_15((config & 0x40000000) ? 1 : 0);
    addWrite_AlarmArmed_A_16((config & 0x80000000) ? 1 : 0);

    endWrite();
}

void page300::recoverConfig()
{
    if (AlarmStatus != ALARM_STATUS_ZERO) {
        fprintf(stderr, "%s() spurious call in status %u\n", __func__, AlarmStatus);
        return;
    }
    switch (SavedAlarmStatus) {
    case ALARM_STATUS_ZERO:
    case ALARM_STATUS_IDLE:
        // ready, idle
        transition(ALARM_STATUS_IDLE, ALARM_CONFIG_ZERO);
        break;
    case ALARM_STATUS_ARMED:
        // ready, armed
        transition(ALARM_STATUS_ARMED, SavedAlarmConfig);
        break;
    case ALARM_STATUS_ENABLED:
        // FIXME: must wait for arming
        transition(ALARM_STATUS_ENABLED, SavedAlarmConfig);
        break;
    case ALARM_STATUS_RINGING:
        // FIXME: must wait for arming
        transition(ALARM_STATUS_RINGING, SavedAlarmConfig);
        break;
    case ALARM_STATUS_MUTED:
        // FIXME: must wait for arming
        transition(ALARM_STATUS_MUTED, SavedAlarmConfig);
        break;
    default:
        ;
    }
}

unsigned page300::readConfig(int index)
{
    unsigned config = ALARM_CONFIG_ZERO;

    switch (index) {
    case 0: config = ALARM_CONFIG_ZERO;       break;
    case 1: config = ALARM_CONFIG_ALL;        break;
    case 2: config = ALARM_CONFIG_INSTALLED;  break;
    case 3: config = ALARM_CONFIG_NOIR_P0P1;  break;
    case 4: config = ALARM_CONFIG_NOIR_PALL;  break;
    default: ;
    }
    return config;
}

void page300::resetConfig(unsigned config)
{
    int index = 0; // default 0

    switch (config) {
    case ALARM_CONFIG_ZERO     : index = 0;  break;
    case ALARM_CONFIG_ALL      : index = 1;  break;
    case ALARM_CONFIG_INSTALLED: index = 2;  break;
    case ALARM_CONFIG_NOIR_P0P1: index = 3;  break;
    case ALARM_CONFIG_NOIR_PALL: index = 4;  break;
    default: ;
    }
    disconnect( ui->comboBox_AlarmConfig, SIGNAL( currentIndexChanged(int) ), this, SLOT( on_comboBox_AlarmConfig_currentIndexChanged(int) ) );
    ui->comboBox_AlarmConfig->setCurrentIndex(index);
    connect( ui->comboBox_AlarmConfig, SIGNAL( currentIndexChanged(int) ), this, SLOT( on_comboBox_AlarmConfig_currentIndexChanged(int) ) );
}

// ---------------------------------------------------------------------------

void page300::on_pushButton_AlarmEnable_clicked()
{
    switch (AlarmStatus) {
    case ALARM_STATUS_ZERO:
    case ALARM_STATUS_IDLE:
        fprintf(stderr, "%s() spurious call in status %u\n", __func__, AlarmStatus);
        break;
    case ALARM_STATUS_ARMED:
        transition(ALARM_STATUS_ENABLED, SavedAlarmConfig);
        break;
    case ALARM_STATUS_ENABLED:
        transition(ALARM_STATUS_IDLE, ALARM_CONFIG_ZERO);
        break;
    case ALARM_STATUS_RINGING:
        fprintf(stderr, "%s() spurious call in status %u\n", __func__, AlarmStatus);
        break;
    case ALARM_STATUS_MUTED:
        transition(ALARM_STATUS_IDLE, ALARM_CONFIG_ZERO);
        break;
    default:
        ;
    }
    enableDisableCommands();
}

void page300::on_pushButton_AlarmAck_clicked()
{
    switch (AlarmStatus) {
    case ALARM_STATUS_ZERO:
    case ALARM_STATUS_IDLE:
    case ALARM_STATUS_ARMED:
    case ALARM_STATUS_ENABLED:
        fprintf(stderr, "%s() spurious call in status %u\n", __func__, AlarmStatus);
        break;
    case ALARM_STATUS_RINGING:
        ui->pushButton_AlarmAck->setEnabled(false);
        pthread_mutex_lock(&alarmevents_list_mutex);
        {
            for (int i = 0; i < _active_alarms_events_.count(); i++)
            {
                if (! _active_alarms_events_.at(i)->isack) {
                    _active_alarms_events_.at(i)->isack = true;
                    _active_alarms_events_.at(i)->ack = QDateTime::currentDateTime();
                }
            }
        }
        pthread_mutex_unlock(&alarmevents_list_mutex);
        transition(ALARM_STATUS_MUTED, SavedAlarmConfig);
        break;
    case ALARM_STATUS_MUTED:
        fprintf(stderr, "%s() spurious call in status %u\n", __func__, AlarmStatus);
        break;
    default:
        ;
    }
    enableDisableCommands();
}

void page300::on_comboBox_AlarmConfig_currentIndexChanged(int index)
{
    if (index < 0 or index > ALARM_CONFIG_LASTINDEX) {
        // wrong index (should never happen)
        resetConfig(ALARM_CONFIG_ZERO);

    } else {
        //
        unsigned config = readConfig(index);

        switch (AlarmStatus) {
        case ALARM_STATUS_ZERO:
            // wrong status (should never happen)
            resetConfig(ALARM_CONFIG_ZERO);
            break;
        case ALARM_STATUS_IDLE:
            transition(ALARM_STATUS_ARMED, config); // anche ALARM_CONFIG_ZERO
            break;
        case ALARM_STATUS_ARMED:
            if (config == ALARM_CONFIG_ZERO) {
                transition(ALARM_STATUS_IDLE, ALARM_CONFIG_ZERO);
            } else {
                transition(ALARM_STATUS_ARMED, config);
            }
            break;
        case ALARM_STATUS_ENABLED:
        case ALARM_STATUS_RINGING:
        case ALARM_STATUS_MUTED:
            // wrong status (should never happen)
            resetConfig(ALARM_CONFIG_ZERO);
            break;
        default:
            ;
        }
    }
    enableDisableCommands();
}
