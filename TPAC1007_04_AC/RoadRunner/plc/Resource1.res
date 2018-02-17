(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Crosstable.gvl"
    #IMPORT "Resource1.gvl"
        
        
        TASK Task2_Events(EVENT:='27', PRIORITY:=2, AUTOSTART:=TRUE);
        TASK Task3_RoadRunner_1ms(INTERVAL:=T#1ms, PRIORITY:=3, AUTOSTART:=FALSE);
        
        TASK Task4_Normal_100ms(INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=TRUE);
        
        
        
        
        PROGRAM Events_Inst1 WITH  Task2_Events: Events;
        
        PROGRAM Normal_Inst1 WITH  Task4_Normal_100ms: Normal;
        
        PROGRAM RoadRunner_Inst1 WITH  Task3_RoadRunner_1ms: RoadRunner;
        
END_RESOURCE
