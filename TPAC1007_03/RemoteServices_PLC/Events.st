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

	if CHANGE_DIG_OUT4 then
		PLC_DigOut_4 := TCP_DigOut_4;
	end_if;
	TCP_DigIn_3 := PLC_DigIn_3;

END_PROGRAM
