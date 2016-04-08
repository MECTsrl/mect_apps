(*[[
]]*)
PROGRAM Events 

#import "Resource1.gvl"
#import "Crosstable.gvl"

	(* Latency Test *)
	if RISING_FRONT then
		PLC_DigOut_3 := TRUE;
	end_if;
	if FALLING_FRONT then
		PLC_DigOut_3 := FALSE;
	end_if;
END_PROGRAM
