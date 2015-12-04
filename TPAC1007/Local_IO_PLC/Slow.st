(*[[
]]*)
PROGRAM Slow 
#import "Resource1.gvl"
#import "Crosstable.gvl"
VAR
	flip :BOOL := TRUE;
END_VAR;

		flip := not flip;
		(* Arming the Latency Test: see Task2_Alarms *)
		PLC_DigOut_1 := flip; 

END_PROGRAM
