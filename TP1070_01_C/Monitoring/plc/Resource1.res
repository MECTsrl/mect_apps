(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Crosstable.gvl"
    #IMPORT "Resource1.gvl"
        TASK Task0_Init(EVENT:='4', PRIORITY:=0, AUTOSTART:=TRUE);
        TASK Task1_Alarms(EVENT:='28', PRIORITY:=1, AUTOSTART:=TRUE);
        TASK Task2_Events(EVENT:='27', PRIORITY:=2, AUTOSTART:=TRUE);
        
        TASK Task4_Normal_100ms(INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=TRUE);
        TASK Task5_Slow_1000ms(INTERVAL:=T#1000ms, PRIORITY:=5, AUTOSTART:=TRUE);
        TASK Task6_VerySlow_5minutes(INTERVAL:=T#300s, PRIORITY:=6, AUTOSTART:=TRUE);
        
        PROGRAM Init_Inst1 WITH  Task0_Init: Init;
        PROGRAM Alarms_Inst1 WITH  Task1_Alarms: Alarms;
        PROGRAM Events_Inst1 WITH  Task2_Events: Events;
        
        PROGRAM Normal_Inst1 WITH  Task4_Normal_100ms: Normal;
        PROGRAM Slow_Inst1 WITH  Task5_Slow_1000ms: Slow;
        PROGRAM VerySlow_Inst1 WITH  Task6_VerySlow_5minutes: VerySlow;
        PROGRAM CheckDigIO_Inst1 WITH  Task4_Normal_100ms: CheckDigIO;
        PROGRAM CheckOK_Inst1 WITH  Task5_Slow_1000ms: CheckOK;
        
END_RESOURCE

