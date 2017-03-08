(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	if LOC_Rising then
		PLC_DigOut_6 := 1;
		TCP_DigIn_3 := 1; (*PLC_DigIn_7*)
	end_if;
	if LOC_Falling then
		PLC_DigOut_6 := 0;
		TCP_DigIn_3 := 0; (*PLC_DigIn_7*)
	end_if;

	if CHANGE_DIG_OUT4 then
		PLC_DigOut_8 := TCP_DigOut_4;
	end_if;

END_PROGRAM
