(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Resource1.gvl"
    #IMPORT "Crosstable.gvl"
        TASK Task0_Initialize(EVENT:='23', PRIORITY:=0, AUTOSTART:=TRUE);
        TASK Task1_Alarms(EVENT:='28', PRIORITY:=1, AUTOSTART:=TRUE);
        TASK Task3_Events(EVENT:='27', PRIORITY:=3, AUTOSTART:=TRUE);
        TASK Task5_Fast(INTERVAL:=T#10ms, PRIORITY:=5, AUTOSTART:=TRUE);
        TASK Task7_Normal(INTERVAL:=T#100ms, PRIORITY:=7, AUTOSTART:=TRUE);
        TASK Task9_Slow(INTERVAL:=T#1000ms, PRIORITY:=9, AUTOSTART:=TRUE);
        
        PROGRAM Events_1 WITH  Task3_Events: Events;
        PROGRAM Alarms_1 WITH  Task1_Alarms: Alarms;
        PROGRAM Fast_1 WITH  Task5_Fast: Fast;
        
        PROGRAM Slow_1 WITH  Task9_Slow: Slow;
        PROGRAM Normal_1 WITH  Task7_Normal: Normal;
        PROGRAM Initialize_1 WITH  Task0_Initialize: Initialize;
END_RESOURCE
