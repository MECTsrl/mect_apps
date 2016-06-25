(*[[
]]*)
PROGRAM Slow 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	timer : TON;
END_VAR

	timer(IN := TRUE, PT := T#5s);
	if timer.Q then
		timer(IN := FALSE);
		PLC_DigOut_1 := not PLC_DigOut_1;
	end_if;

END_PROGRAM
