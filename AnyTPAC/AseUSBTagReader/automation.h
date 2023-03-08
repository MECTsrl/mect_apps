#ifndef AUTOMATION_H
#define AUTOMATION_H

#include "main.h"
#include "hmi_logger.h"
#include "global_functions.h"
#include "serialreader.h"

#define THE_DEVICE "/dev/ttyUSB1"
#define MY_NAME_LEN        64
#define codiceDiControllo 0x55aa55aa

// Compiler directive to pack data structures
#pragma pack(push, 1)

struct _RicettaTAG {
    char    TAG_nomeRicetta[MY_NAME_LEN + 1];   // 65 Byte
    float   TAG_TempUgello;                 //  4 Byte
    float   TAG_TempSerbatoi;               //  4 Byte
    float   TAG_P3;                         //  4 Byte
    float   TAG_P5;                         //  4 Byte
    float   TAG_TEMPO1;                     //  4 Byte
    float   TAG_TEMPO2;                     //  4 Byte
    float   TAG_TEMPO3;                     //  4 Byte
    uint16_t TAG_Aspirazione;               //  2 Byte
    uint32_t TAG_Controllo;                 //  4 Byte
};

#pragma pack(pop)
// Compiler directive to avoid further packing of  data structures


extern char    currentRecipeName[];
extern struct _RicettaTAG   RicettaTAG;
extern SerialReader         *tagReader;


void setup(void);
void loop(void);
void        clearVarsAndStruct();
void        struct2Vars();
void        vars2Struct();



#endif // AUTOMATION_H

