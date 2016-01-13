(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Resource1.gvl"
    #IMPORT "Crosstable.gvl"
        TASK Task1(INTERVAL:=T#100ms, PRIORITY:=5, AUTOSTART:=TRUE);
        PROGRAM Program1 WITH Task1: Program1;
END_RESOURCE
