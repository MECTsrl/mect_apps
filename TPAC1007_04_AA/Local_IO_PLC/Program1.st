(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
VAR
	first : bool := true;
END_VAR
	(* Initial Configuration *)
	if first then
 	    first := false;
		PLC_AnInConf_1 := 2; (* 0..10V *)
		PLC_AnInConf_2 := 2; (* 0..10V *)
		PLC_AnOutConf_1 := 2; (* 0..10V *)
		PLC_AnOutConf_2 := 2; (* 0..10V *)
		PLC_AnOutConf_3 := 2; (* 0..10V *)
		PLC_AnOutConf_4 := 2; (* 0..10V *)
	end_if;
END_PROGRAM
