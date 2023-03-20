#include <QFile>
#include <QDebug>
#include <QThread>
#include <QTime>

#include "crosstable.h"
#include "automation.h"

#define APP_VERSION         23001

char    currentRecipeName[MY_NAME_LEN + 1];
struct _RicettaTAG  RicettaTAG;
SerialReader        *tagReader = 0;

/* put here the initalization */
void setup(void)
{

    // Wait PLC Engine gets ready
    while (PLC_EngineStatus < 2) {
        fputc('*', stderr);
        sleep(1);
    }
    // Insert your start-up code here
    memset(currentRecipeName, 0, MY_NAME_LEN + 1);
    beginWrite();
    addWrite_PLC_HMI_Version(APP_VERSION);
    addWrite_readerFound(false);
    addWrite_rawttyDevice(0);
    endWrite();
    qDebug("Ricetta Tag Total Byte Size:        [%d]", sizeof(RicettaTAG));
}

void        struct2Vars()
{
    strncpy(currentRecipeName, RicettaTAG.TAG_nomeRicetta, MY_NAME_LEN);
    beginWrite();
    addWrite_Tmp_TempUgello     ( RicettaTAG.TAG_TempUgello);
    addWrite_Tmp_TempSerbatoi   ( RicettaTAG.TAG_TempSerbatoi);
    addWrite_Tmp_P3             ( RicettaTAG.TAG_P3);
    addWrite_Tmp_P5             ( RicettaTAG.TAG_P5);
    addWrite_Tmp_TEMPO1         ( RicettaTAG.TAG_TEMPO1);
    addWrite_Tmp_TEMPO2         ( RicettaTAG.TAG_TEMPO2);
    addWrite_Tmp_TEMPO3         ( RicettaTAG.TAG_TEMPO3);
    addWrite_Tmp_Aspirazione    ( RicettaTAG.TAG_Aspirazione);
    endWrite();
}

void        vars2Struct()
{
    strncpy(RicettaTAG.TAG_nomeRicetta, currentRecipeName, MY_NAME_LEN);
    RicettaTAG.TAG_Controllo        = 0;
    RicettaTAG.TAG_TempUgello       = Tmp_TempUgello    ;
    RicettaTAG.TAG_TempSerbatoi     = Tmp_TempSerbatoi  ;
    RicettaTAG.TAG_P3               = Tmp_P3            ;
    RicettaTAG.TAG_P5               = Tmp_P5            ;
    RicettaTAG.TAG_TEMPO1           = Tmp_TEMPO1        ;
    RicettaTAG.TAG_TEMPO2           = Tmp_TEMPO2        ;
    RicettaTAG.TAG_TEMPO3           = Tmp_TEMPO3        ;
    RicettaTAG.TAG_Aspirazione      = Tmp_Aspirazione   ;
    RicettaTAG.TAG_Controllo        = codiceDiControllo ;
}

void        clearVarsAndStruct()
{
    memset(RicettaTAG.TAG_nomeRicetta, 0, MY_NAME_LEN);
    memset(currentRecipeName, 0, MY_NAME_LEN + 1);
    RicettaTAG.TAG_TempUgello       = 0.0;
    RicettaTAG.TAG_TempSerbatoi     = 0.0;
    RicettaTAG.TAG_P3               = 0.0;
    RicettaTAG.TAG_P5               = 0.0;
    RicettaTAG.TAG_TEMPO1           = 0.0;
    RicettaTAG.TAG_TEMPO2           = 0.0;
    RicettaTAG.TAG_TEMPO3           = 0.0;
    RicettaTAG.TAG_Aspirazione      = 0   ;
    RicettaTAG.TAG_Controllo        = codiceDiControllo;
    struct2Vars();
}

/* put here the operation made every 100ms */
void loop(void)
{
    static unsigned loopCounter = 1;

    //    // Tag Search Polling
    //    if (loopCounter % 29 == 0 && tagReader != 0 && tagReader->isOpen())  {
    //        if (tagReader->readerStatus() == SerialReader::senderWaitingCommand  &&
    //            ! tagReader->isBusy())  {
    //            tagReader->searchTag();
    //        }
    //        else  {
    //            qDebug("[%s] Automation loop(): Reader Status: [%s] Reader Busy: [%d]",
    //                    QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(),
    //                    tagReader->getStatusDesc(tagReader->readerStatus()).toLatin1().data(),
    //                    tagReader->isBusy());
    //        }
    //    }
    loopCounter++;
}

