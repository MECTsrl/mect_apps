/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Generic page
 */
#include "app_logprint.h"
#include "atcmplugin.h"

#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"
#include "json.h"


#include <QDialog>
#include <QFile>
#include <QDateTime>
#include <QByteArray>
#include <QCoreApplication>

#include "numpad.h"
#include "alphanumpad.h"
#include "automation.h"

#define SERIAL_FILE                 "/etc/serial.conf"
#define BROKER_IP                   "172.16.2.78"
#define PUB_TOPIC_ROOT              "sensors/heartbeat/"
#define SENS_TOPIC_ROOT             "tele/tasmota_A9690C/SENSOR"
#define MQTT_BLACK_LIST_MAXsecs         60

/**
 * @brief this macro is used to set the PAGE100 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page100::page100(QWidget *parent) :
    page(parent),
    ui(new Ui::page100)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE100_STYLE */
    SET_PAGE100_STYLE();
    translateFontSize(this);
    // Board Serial Number
    boardSerialNumber.clear();
    QFile fileSerialNO(SERIAL_FILE);
    // Caricamento del Serial Number della scheda
    if (fileSerialNO.exists() && fileSerialNO.open(QIODevice::ReadOnly | QIODevice::Text))  {
        char buf[STR_LEN];
        if (fileSerialNO.readLine(buf, STR_LEN) > 0) {
            boardSerialNumber = QString(buf).trimmed();
        }
        fileSerialNO.close();
    }
    qDebug("Board Serial No: [%s]", boardSerialNumber.toLatin1().data());
    // Start-up Values
    mqttBroker = QString(BROKER_IP);
    mqttSendTopic  = QString(PUB_TOPIC_ROOT);
    if (! boardSerialNumber.isEmpty())  {
        mqttSendTopic.append(boardSerialNumber);
    }
    mqttSubTopic = QString(SENS_TOPIC_ROOT);
    mqttConnectionCount = 0;
    QtJson::setDateTimeFormat("yyyy-MM-ddThh:mm:ss");
    QtJson::setPrettySerialize(false);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page100::reload()
{
    /*
       H variables initalizations:
         variableList.clear();
         variableList << "VARIABLE1" << "VARIABLE2" << "VARIABLE3"
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
    ui->atcmMQTT_Start->setEnabled(mqttPresent);
    ui->atcmMQTT_Start->setChecked(mqttPresent && mqttBrokerConnected);
    updateIface();
    nUpdateLoop = 0;
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page100::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
    /* To read the cross table variable UINT TEST1:
     *    uint_16 tmp = TEST1;
     */
    /* To write 5 into the the cross table variable UINT TEST1:
     *    doWrite_TEST1(5);
     */
    // Tentativo di invio ogni 1s
    if ((++nUpdateLoop % 2) == 0)  {
        // Broker Connected
        if (mqttBrokerConnected)  {
            //        QString szMessage = QString("HB:[%1]-ConnCount[%2]-Loop[%3]-MsgCount[%4]") .arg(PLC_UPTIME_s)
            //                        .arg(mqttConnectionCount)
            //                        .arg(nUpdateLoop)
            //                        .arg(++nSentMessageCount);
            QString szTopic = ui->pushButtonTopic->text().trimmed();
            QtJson::JsonObject jsonOut;

            // Compose JSON Output
            jsonOut["SensorId"] = boardSerialNumber;
            jsonOut["Time"] = QDateTime::currentDateTime();
            jsonOut["HB"] = PLC_UPTIME_s;
            jsonOut["Connections"] = mqttConnectionCount;
            jsonOut["Loop"] = nUpdateLoop;
            jsonOut["MsgCount"] = ++nSentMessageCount;

            QByteArray data = QtJson::serialize(jsonOut);

            QString szMessage = QString(data);
            ui->lblSentMessage->setText(szMessage);
            // Publish Data without ID and with qos = 2 and no retain
            int nRC = mosquitto_publish(mqttClient, NULL,
                                        szTopic.toLatin1().data(),
                                        data.length(), data,
                                        2, false);
            if (nRC != MOSQ_ERR_SUCCESS)  {
                qWarning("Error publishing Topic[%s] Message[%s] ErrCode[%s]",
                            szTopic.toLatin1().data(),
                            szMessage.toLatin1().data(),
                            mosquitto_strerror(nRC));
            }
            ui->label_MQTT_Sent->setText(QString::number(nSentMessageCount));
            // Aggiornamento eventuali pacchetti ricevuti dal Broker
            if (MQTT_ActiveTopic && mqttNewMessagePending && mqttReceivedMessages.count())  {
                mqttNewMessagePending = false;
                // Pop da lista del primo messaggio in coda
                QString szMessage = mqttReceivedMessages.takeFirst();
                QString szParsed;

                // JSon Parsing
                bool fOk;
                QtJson::JsonObject jResult = QtJson::parse(szMessage, fOk).toMap();

                if(fOk)  {
                    // Parsing Result
                    QtJson::JsonObject objESP32 = jResult["ESP32"].toMap();
                    QtJson::JsonObject objMSP100 = jResult["MPSN100"].toMap();
                    QString recTime = jResult["Time"].toString();
                    QString tempUnit = jResult["TempUnit"].toString();
                    QString stringFIR = objMSP100["FIR"].toString();
                    double  dblTemperature  = objESP32["Temperature"].toDouble();
                    szParsed = QString("Time:[%1] Temperature:[%2] TempUnit:[%3] FIR:[%4]")
                                    .arg(recTime)
                                    .arg(dblTemperature, 5, 'f', 2, QChar('0'))
                                    .arg(tempUnit)
                                    .arg(stringFIR);
                }
                else  {
                    szParsed = QString("Invalid JSON String received");
                }
                ui->lblReceivedMsg->setText(szParsed);
                ui->label_MQTT_Received->setText(QString::number(++nReceivedMessageCount));
            }
        }
    }
    // Topic and broker pushbuttons
    ui->pushButtonBroker->setEnabled(! mqttBrokerConnected);
    ui->pushButtonTopic->setEnabled(! mqttBrokerConnected);
    ui->pushButtonSubTopic->setEnabled(! mqttBrokerConnected);
}

/**
 * @brief This is the event slot to detect new language translation.
 */
void page100::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page100::~page100()
{
    delete ui;
}



void page100::on_pushButtonBroker_clicked()
{

    char value [32];
    numpad ipNumpad(value, IPADDR, ui->pushButtonBroker->text().toAscii().data());

    ipNumpad.showFullScreen();
    if (ipNumpad.exec() == QDialog::Accepted && checkNetAddr(value))  {
        // TODO: Gestire Disconnessione a precedente Broker
        QString newValue = QString(value);
        if (newValue != mqttBroker)  {
            mqttBroker = newValue;
            updateIface();
        }
    }
}

void page100::on_pushButtonTopic_clicked()
{
    char value [64];
    alphanumpad tastiera_alfanum(value,ui->pushButtonTopic->text().toAscii().data());
    tastiera_alfanum.showFullScreen();
    if (tastiera_alfanum.exec() == QDialog::Accepted)
    {
        // TODO: Gestire Cambio Topic se broker connesso
        QString newValue = QString(value);
        if (newValue != mqttSendTopic)  {
            mqttSendTopic = newValue;
            updateIface();
        }
    }
}

void page100::on_pushButtonSubTopic_clicked()
{
    char value [64];
    alphanumpad tastiera_alfanum(value,ui->pushButtonSubTopic->text().toAscii().data());
    tastiera_alfanum.showFullScreen();
    if (tastiera_alfanum.exec() == QDialog::Accepted)
    {
        // TODO: Gestire Cambio Topic se broker connesso
        QString newValue = QString(value);
        if (newValue != mqttSubTopic)  {
            mqttSubTopic = newValue;
            updateIface();
        }
    }
}

void  page100::updateIface()
{
    ui->pushButtonBroker->setText(mqttBroker);
    ui->pushButtonTopic->setText(mqttSendTopic);
    ui->pushButtonSubTopic->setText(mqttSubTopic);
}

void page100::on_atcmMQTT_Start_toggled(bool checked)
{
    int nRes = 0;
    int nQos = 2;
    int nMid = 0;
    QString szTopic = ui->pushButtonSubTopic->text().trimmed();

    qDebug("MQTT_Actual Status: [%d]",  MQTT_Status);
    mqttReceivedMessages.clear();
    mqttNewMessagePending = false;
    doWrite_MQTT_Broker(false);         // Broker OFF
    doWrite_MQTT_ActiveTopic(false);    // No Active Topic
    if (checked)  {
        // Force MQTT Start
        if (mqttPresent && MQTT_Status != 0 && MQTT_Status != 5)  {
            qDebug("MQTT [%d] Start Required", MQTT_Status);
            // Free previous connections resources
            if (mqttConnectionCount > 0)  {
                nRes = mosquitto_reinitialise(mqttClient, NULL, true, NULL);
                if (nRes != MOSQ_ERR_SUCCESS)  {
                    qCritical("Error cleaning previous MQTT Connection");
                    mqttPresent = false;
                    return;
                }
            }
            // Set Callback for mqttClient
            mosquitto_disconnect_callback_set(mqttClient, on_disconnect);
            mosquitto_connect_callback_set(mqttClient, on_connect);
            mosquitto_subscribe_callback_set(mqttClient, on_subscribe);
            mosquitto_message_callback_set(mqttClient, on_message);
            mosquitto_publish_callback_set(mqttClient, on_publish);
            // Enable for Debug
            // mosquitto_log_callback_set(mqttClient, on_mqtt_log);
            // Setting Reconnection Delays
            mosquitto_reconnect_delay_set(mqttClient, 2, MQTT_BLACK_LIST_MAXsecs, true);
            // Starting MQTT Connection
            nRes = mosquitto_connect(mqttClient, ui->pushButtonBroker->text().toLatin1().data(), 1883, 60);
            if(nRes != MOSQ_ERR_SUCCESS)  {
                qCritical("Error opening MQTT Connection to Broker: [%s]", ui->pushButtonBroker->text().toLatin1().data());
                mosquitto_destroy(mqttClient);
                mqttPresent = false;
                return;
            }
            // Subscribe to MQTT Topic
            if (! szTopic.isEmpty())  {
                nRes = mosquitto_subscribe(mqttClient, &nMid, szTopic.toLatin1().data(), nQos);
                if(nRes != MOSQ_ERR_SUCCESS)  {
                    doWrite_MQTT_ActiveTopic(false);    // No Active Topic
                    qCritical("Error Subscribing Topic: [%s]", szTopic.toLatin1().data());
                }
                else {
                    qDebug("Subscribed Topic: [%s]", szTopic.toLatin1().data());
                }
            }
            // Starting MQTT Loop
            nRes = mosquitto_loop_start(mqttClient);
            if(nRes != MOSQ_ERR_SUCCESS)  {
                qCritical("Error starting MQTT Loop");
                mosquitto_destroy(mqttClient);
                mqttPresent = false;
                return;
            }
            // Opening MQTT instance
            mqttConnectionCount++;
            nSentMessageCount = 0;
            nReceivedMessageCount = 0;
            qDebug("MQTT Started");
        }
    }
    else {
        // Force Force MQTT Stop
        if (mqttPresent && mqttBrokerConnected) {
            qDebug("Richiesto Force MQTT Stop");
            nRes = mosquitto_disconnect(mqttClient);
            // Pause Page thread to handle user disconnection in on_disconnect()
            QCoreApplication::processEvents();
            sleep(2);
            // Stop mosquitto thread loop
            mosquitto_loop_stop(mqttClient, true);
            qDebug("MQTT Stopped");
        }
        else  {
            qDebug("MQTT Already Stopped or not Present");
        }
    }
    usleep(800);
}


