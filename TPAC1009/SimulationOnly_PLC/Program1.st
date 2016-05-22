(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
#import "Resource1.gvl"

	(* Input Generation *)
	AnIn_1 := 5000 + REAL_TO_INT(5000.0 * sin(PLC_time));
	AnIn_2 := 5000 + REAL_TO_INT(5000.0 * cos(PLC_time));

END_PROGRAM
