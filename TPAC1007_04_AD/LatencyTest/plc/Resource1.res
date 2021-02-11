(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Crosstable.gvl"
    #IMPORT "Resource1.gvl"
        TASK Task0_Init(EVENT:='4', PRIORITY:=0, AUTOSTART:=TRUE);
        TASK Task1_Alarms(EVENT:='28', PRIORITY:=1, AUTOSTART:=TRUE);
        TASK Task2_Events(EVENT:='27', PRIORITY:=2, AUTOSTART:=TRUE);
        TASK Task3_Fast_10ms(INTERVAL:=T#10ms, PRIORITY:=3, AUTOSTART:=FALSE);
        TASK Task4_Normal_100ms(INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=TRUE);
        TASK Task5_Slow_1001ms(INTERVAL:=T#1001ms, PRIORITY:=5, AUTOSTART:=TRUE);
        
        PROGRAM Init WITH  Task0_Init: Init;
        PROGRAM Alarms WITH  Task1_Alarms: Alarms;
        PROGRAM Events WITH  Task2_Events: Events;
        
        PROGRAM Normal WITH  Task4_Normal_100ms: Normal;
        PROGRAM Slow WITH  Task5_Slow_1001ms: Slow;
        PROGRAM Fast WITH  Task3_Fast_10ms: Fast;
        
END_RESOURCE

