(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Resource1.gvl"
    #IMPORT "Crosstable.gvl"
        
        
        TASK Task3_Events(EVENT:='27,28', PRIORITY:=3, AUTOSTART:=TRUE);
        
        TASK Task7_Normal(INTERVAL:=T#100ms, PRIORITY:=7, AUTOSTART:=TRUE);
        
        
        PROGRAM Events_1 WITH  Task3_Events: Events;
        
        
        
        
        PROGRAM Normal_1 WITH  Task7_Normal: Normal;
        
END_RESOURCE
