(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	retval : word;
END_VAR

	if RisingEvent then
	    PLC_DigOut_8 := true;
		retval := TSK_Start('Task3_RoadRunner_1ms');
	end_if;
END_PROGRAM
