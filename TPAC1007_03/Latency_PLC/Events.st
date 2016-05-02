(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
VAR
END_VAR

	if RISING_FRONT then
		PLC_DigOut_6 := TRUE;
	end_if;
	if FALLING_FRONT then
		PLC_DigOut_6 := FALSE;
	end_if;

END_PROGRAM
