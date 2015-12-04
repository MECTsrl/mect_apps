(*[[
]]*)
PROGRAM Normal 
#import "Resource1.gvl"
#import "Crosstable.gvl"

	PLC_AnOut_1 := ((PLC_AnIn_1 + PLC_AnIn_2) / 2) / 10;

END_PROGRAM
