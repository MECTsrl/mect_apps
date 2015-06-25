(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Resource1.gvl"
    #IMPORT "crosstable.gvl"
    #IMPORT "TPACLocaIO.gvl"
    #IMPORT "LIO_TPAC1006.gvl"
    #IMPORT "LIO_TPAC1007.gvl"
    #IMPORT "CANopenClient_CAN.gvl"
        TASK Task1(INTERVAL:=T#25ms, PRIORITY:=5, AUTOSTART:=TRUE, WATCHDOG:=100000);
        TASK Task2_RTU(INTERVAL:=T#10ms, PRIORITY:=4, AUTOSTART:=FALSE,WATCHDOG:=100000);
        TASK Task3_TCP(INTERVAL:=T#25ms, PRIORITY:=4, AUTOSTART:=FALSE,WATCHDOG:=100000);
        TASK Task4_TCPRTU(INTERVAL:=T#25ms, PRIORITY:=4, AUTOSTART:=FALSE,WATCHDOG:=100000);
        TASK Task0_Control(INTERVAL:=T#100ms, PRIORITY:=6, AUTOSTART:=FALSE);
        PROGRAM HW119_Engine WITH Task1: Program1;
        PROGRAM RTU_Communication WITH  Task2_RTU: RTU_Communication;
        PROGRAM TPC_Communication WITH  Task3_TCP: TCP_Communication;
        PROGRAM TCPRTU_Communication WITH  Task4_TCPRTU: TCPRTU_Communication;
        PROGRAM ProgramInst1 WITH  Task0_Control: PLC;
        
END_RESOURCE
