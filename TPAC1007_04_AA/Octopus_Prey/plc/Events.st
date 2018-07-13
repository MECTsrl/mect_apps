(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
VAR
END_VAR

if SquareWaveBeginning then
	PLC_DigDir_1 := true;
	PLC_DigDir_2 := true;
end_if;

END_PROGRAM
