(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	
END_VAR
	
(* Input Generation *)
	AnIn_1 := 5000 + REAL_TO_INT(5000.0 * sin(PLC_time / 2.0));
	AnIn_2 := 5000 + REAL_TO_INT(5000.0 * cos(PLC_time / 2.0));
	
	
	


	
END_PROGRAM
