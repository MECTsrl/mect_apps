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

		STATUS_LOCAL := TRUE;
	end_if;

	if STATUS_LOCAL then
		if START_REMOTE then
			STATUS_LOCAL := FALSE;
			STATUS_REMOTE := TRUE;
		end_if;
	end_if;
	if STATUS_REMOTE then
		if not START_REMOTE then
			STATUS_REMOTE := FALSE;
			STATUS_LOCAL := TRUE;
		end_if;
		if START_TEST then
			(* do test *)
			(* TCP_SRV -> PLC_ *)
			STATUS_DONE := TRUE;
		end_if;
	end_if;
	if STATUS_DONE then
		if not START_TEST then
			STATUS_DONE := FALSE;
			STATUS_LOCAL := TRUE;
		end_if;
	end_if;

END_PROGRAM
