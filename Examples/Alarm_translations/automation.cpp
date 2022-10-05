#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{    
    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    // .....
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

void setEventDescription(QString name, QString description)
{
    event_t * event = EventHash.find(name).value();

    if (event) {
        strncpy(event->description, description.toLatin1().data(), DESCR_LEN);
    } else {
        qDebug("unknown event/alarm '%s'", name.toLatin1().data());
    }
}

void Translate_IT(){
    setEventDescription("Allarme_Tmax_P", "Tempo massimo - riscaldamento P");
    setEventDescription("Allarme_Tmax_C", "Tempo massimo - riscaldamento C");
}

void Translate_EN(){
    setEventDescription("Allarme_Tmax_P", "MAXIMUM TIME HEATING P");
    setEventDescription("Allarme_Tmax_C", "MAXIMUM TIME HEATING C");
}
