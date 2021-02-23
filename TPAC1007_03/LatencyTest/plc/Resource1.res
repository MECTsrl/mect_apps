(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Crosstable.gvl"
    #IMPORT "Resource1.gvl"
        TASK Task0_Init(EVENT:='4', PRIORITY:=0, AUTOSTART:=TRUE);
        TASK Task1_Alarms(EVENT:='28', PRIORITY:=1, AUTOSTART:=TRUE);
        TASK Task2_Events(EVENT:='27', PRIORITY:=2, AUTOSTART:=TRUE);
        TASK Task3_Fast_50ms(INTERVAL:=T#50ms, PRIORITY:=3, AUTOSTART:=FALSE);
        TASK Task4_Normal_100ms(INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=TRUE);
        TASK Task5_Slow_2000ms(INTERVAL:=T#2000ms, PRIORITY:=5, AUTOSTART:=FALSE);
        
        PROGRAM Init WITH  Task0_Init: Init;
        PROGRAM Alarms WITH  Task1_Alarms: Alarms;
        PROGRAM Events WITH  Task2_Events: Events;
        
        PROGRAM Normal WITH  Task4_Normal_100ms: Normal;
        
        
        PROGRAM SlowWriter WITH  Task5_Slow_2000ms: Writer;
        PROGRAM FastWriter WITH  Task3_Fast_50ms: Writer;
        
END_RESOURCE

