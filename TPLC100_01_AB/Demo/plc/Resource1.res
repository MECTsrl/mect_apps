(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Crosstable.gvl"
    #IMPORT "Resource1.gvl"
        TASK Task0_Init(EVENT:='4', PRIORITY:=0, AUTOSTART:=TRUE);
        TASK Task4_Normal_100ms(INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=TRUE);
        TASK Task5_Slow_2000ms(INTERVAL:=T#2000ms, PRIORITY:=5, AUTOSTART:=TRUE);
        PROGRAM Init_Inst1 WITH  Task0_Init: Init;
        
        PROGRAM Slow_Inst1 WITH  Task5_Slow_2000ms: Slow;
        PROGRAM Normal_Inst1 WITH  Task4_Normal_100ms: Normal;
END_RESOURCE

