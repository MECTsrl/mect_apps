#include "crosstable.h"
#include "automation.h"

bool    mqttPresent = false;                    // Flag globale vero se i driver MQTT sono presenti sul sistema
bool    mqttBrokerConnected = false;            // Flag globale vero se la  connessione al Broker è attiva
struct  mosquitto *mqttClient = NULL;           // Device block mosquitto
bool    mqttNewMessagePending = false;          // Flag globale vero se ci sono messaggi sottoscritti da leggere
QString mqttSubTopic;                           // Topic sottoscritto sul Broker
QStringList mqttReceivedMessages;               // Lista (coda) dei messaggi ricevuti per il topic, gestita come FIFO

//  Crosstable Variables used in interface to handle MQTT Connection
//	MQTT_Broker             BIT		MQTT_Broker connected
//	MQTT_ActiveTopic		BIT		MQTT Topic active
//	MQTT_Status             INT		Stato Connessione MQTT (significato simile ai Nodi Modbus)
//	MQTT_mid				UDINT	MQTT Message Id of a sent message confirmed from Broker (QOS=2)
//	MQTT_LastConnection     UDINT	Uptime Seconds of last Connection
//	MQTT_LastDisconnection	UDINT	Uptime Seconds of last Disconnection


//--------------------------------------------
// MQTT CALLBACKS
// All Code is acting as MQTT v3.x client
// Mosquitto also handles MQTT v5.0 brokers connection with different calls
//--------------------------------------------

/* Callback called when the client receives a CONNACK message from the broker. */
void on_connect(struct mosquitto *myMqttClient, void *obj, int reason_code)
{
    Q_UNUSED(obj);
    /* Print out the connection result. mosquitto_connack_string() produces an
     * appropriate string for MQTT v3.x clients, the equivalent for MQTT v5.0
     * clients is mosquitto_reason_string().
     */
    qDebug("on_connect: %s", mosquitto_connack_string(reason_code));
    if(reason_code != 0){
        /* If the connection fails for any reason, we don't want to keep on
         * retrying in this example, so disconnect. Without this, the client
         * will attempt to reconnect.
         * You must manually reconnect to broker
         */
        mosquitto_disconnect(myMqttClient);
        return;
    }
    //--------------------------------------------
    // Status flags to handle Connection
    //--------------------------------------------
    mqttBrokerConnected = true;
    beginWrite();
    addWrite_MQTT_Status(2);
    addWrite_MQTT_mid(0);
    addWrite_MQTT_Broker(true);
    addWrite_MQTT_LastConnection(PLC_UPTIME_s);
    endWrite();
}

/* This is called when the broker has received the DISCONNECT command and has disconnected the client.
 * or in case of communication errors
 * If Disconnection is asked by client, reason Code is 0, so no mosquitto_reconnect is performed
 */
void on_disconnect(struct mosquitto *myMqttClient, void *obj, int reason_code)
{
    Q_UNUSED(obj);

    int newStatus = 1; // The device was disconnected by user ?
    if (reason_code != 0)  {
        // Put the device in Black List        
        newStatus = 4;
        qWarning("on_disconnect: Trying reconnection");
        // This causes automatic reconnection
        mosquitto_reconnect(myMqttClient);
    }
    //--------------------------------------------
    // Status flags to handle disconnection
    //--------------------------------------------
    beginWrite();
    addWrite_MQTT_Status(newStatus);
    addWrite_MQTT_Broker(false);
    addWrite_MQTT_mid(0);
    addWrite_MQTT_LastDisconnection(PLC_UPTIME_s);
    endWrite();
    mqttBrokerConnected = false;
    qDebug("on_disconnect: Reason[%s] - New Status: [%d]", mosquitto_reason_string(reason_code), newStatus);
}

/* Callback called when the client knows to the best of its abilities that a
 * PUBLISH has been successfully sent. For QoS 0 this means the message has
 * been completely written to the operating system. For QoS 1 this means we
 * have received a PUBACK from the broker. For QoS 2 this means we have
 * received a PUBCOMP from the broker. */
void on_publish(struct mosquitto *myMqttClient, void *obj, int mid)
{
    Q_UNUSED(myMqttClient);
    Q_UNUSED(obj);

    qDebug("Message with mid %d has been published.", mid);
    doWrite_MQTT_mid((u_int32_t) mid);
}

void on_message(struct mosquitto *myMqttClient, void *obj, const struct mosquitto_message *msg)
{

    Q_UNUSED(myMqttClient);
    Q_UNUSED(obj);
    QString recvTopic = QString(msg->topic);
    // Il messaggio ricevuto appartiene all'albero di Topic sottoscritti
    if (recvTopic.startsWith(mqttSubTopic))  {
        mqttReceivedMessages.append((char *) msg->payload);
        mqttNewMessagePending = true;
    }
    qDebug("Message with Topic:[%s] Qos:[%d] Payload[%s]", msg->topic, msg->qos, (char *)msg->payload);
}

/* Callback called when the broker sends a SUBACK in response to a SUBSCRIBE. */
void on_subscribe(struct mosquitto *myMqttClient, void *obj, int mid, int qos_count, const int *granted_qos)
{
    int i;

    Q_UNUSED(myMqttClient);
    Q_UNUSED(obj);

    bool mqttActiveTopics = false;
    /* In this example we only subscribe to a single topic at once, but a
     * SUBSCRIBE can contain many topics at once, so this is one way to check
     * them all. */
    for (i=0; i < qos_count; i++){
        qDebug("On_subscribe:[%d] mid:[%d] granted qos:[%d]", i, mid, granted_qos[i]);
        if (granted_qos[i] <= 2){
            mqttActiveTopics = true;
        }
    }
    if (! mqttActiveTopics){
        /* The broker rejected all of our subscriptions, we know we only sent
         * the one SUBSCRIBE, so there is no point remaining connected. */
        qCritical("Error: All subscriptions rejected!");
        // mosquitto_disconnect(mosq);
    }
    doWrite_MQTT_ActiveTopic(mqttActiveTopics);
}

// Verbose MQTT Logging, use it for Debug
void on_mqtt_log(struct mosquitto *myMqttClient, void *obj, int logLevel, const char * logMessage)
{
    Q_UNUSED(myMqttClient);
    Q_UNUSED(obj);

    qDebug("on_mqtt_log: Level:[%d] Msg:[%s]", logLevel, logMessage);
}


/* put here the initalization */
void setup(void)
{    
    qDebug("Open MQTT Ports 1883 and 8883");
    system("iptables -A INPUT -p tcp -m tcp --dport 1883 -j ACCEPT");
    system("iptables -A INPUT -p tcp -m tcp --sport 1883 -j ACCEPT");
    system("iptables -A INPUT -p tcp -m tcp --dport 8883 -j ACCEPT");
    system("iptables -A INPUT -p tcp -m tcp --sport 8883 -j ACCEPT");
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    qDebug("Local PLC Started");
    // Insert your start-up code here
    mqttReceivedMessages.clear();
    /* Required before calling other mosquitto functions */
    if (mosquitto_lib_init() != MOSQ_ERR_SUCCESS)  {
        qCritical("MQTT mosquitto_lib_init failed, MQTT Disabled");
        doWrite_MQTT_Status(5);     // No Hope to use Mosquitto
    }
    else  {
        qDebug("MQTT mosquitto_lib_init success, MQTT Enabled");
        int nMajor, nMinor, nRev;
        char serialNo[STR_LEN];
        sprintf(serialNo, "%u", PLC_SERIAL_NUMBER);
        mosquitto_lib_version(&nMajor, &nMinor, &nRev);
        qDebug("MQTT mosquitto Version: [%d.%d.%d] - S/N:[%u]", nMajor, nMinor, nRev, PLC_SERIAL_NUMBER);
        doWrite_MQTT_Status(1);             // Not Connected
        doWrite_MQTT_Broker(false);
        doWrite_MQTT_ActiveTopic(false);    // No Active Topic
        // Create a new client instance with ID as Panel Serial Number
        mqttClient = mosquitto_new(serialNo, true, NULL);
        if (mqttClient == NULL)  {
            qCritical("Error Creating MQTT Client instance");
        }
        else  {
            qDebug("Created a new MQTT Client instance. ID:[%s]", serialNo);
            mqttPresent = true;
        }
    }
}



/* put here the operation made every 100ms */
void loop(void)
{
    
}

