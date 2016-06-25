(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	if LOC_Rising then
		PLC_DigOut_2 := 1;
	end_if;
	if LOC_Falling then
		PLC_DigOut_2 := 0;
	end_if;


END_PROGRAM
