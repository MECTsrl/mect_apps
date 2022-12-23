#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"

#include "mosquitto.h"
#include "mqtt_protocol.h"

// #include "mosquitto_broker.h"
// #include "mosquitto_plugin.h"

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QDateTime>



void setup(void);
void loop(void);

extern  bool    mqttPresent;                            // Flag globale vero se i driver MQTT sono presenti sul sistema
extern  bool    mqttBrokerConnected;                    // Flag globale vero se la  connessione al Broker è attiva
extern  struct  mosquitto *mqttClient;                  // Device block mosquitto
extern  bool    mqttNewMessagePending;                  // Flag globale vero se ci sono messaggi sottoscritti da leggere
extern  QString mqttSubTopic;                           // Topic sottoscritto sul Broker
extern  QStringList mqttReceivedMessages;               // Lista (coda) dei messaggi ricevuti per il topic, gestita come FIFO

//  Crosstable Variables used in interface to handle MQTT Connection
//	MQTT_Broker             BIT		MQTT_Broker connected
//	MQTT_ActiveTopic		BIT		MQTT Topic active
//	MQTT_Status             INT		Stato Connessione MQTT (significato simile ai Nodi Modbus)
//	MQTT_mid				UDINT	MQTT Message Id of a sent message confirmed from Broker (QOS=2)
//	MQTT_LastConnection     UDINT	Uptime Seconds of last Connection
//	MQTT_LastDisconnection	UDINT	Uptime Seconds of last Disconnection

//--------------------------------------------
// MQTT CALLBACKS
//--------------------------------------------
void on_connect(struct mosquitto *myMqttClient, void *obj, int reason_code);
void on_disconnect(struct mosquitto *myMqttClient, void *obj, int reason_code);
void on_publish(struct mosquitto *myMqttClient, void *obj, int mid);
void on_subscribe(struct mosquitto *myMqttClient, void *obj, int mid, int qos_count, const int *granted_qos);
void on_message(struct mosquitto *myMqttClient, void *obj, const struct mosquitto_message *msg);
void on_mqtt_log(struct mosquitto *myMqttClient, void *obj, int logLevel, const char * logMessage);

#endif // AUTOMATION_H

