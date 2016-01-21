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

		STATUS_LOCAL := 1;
		STATUS_REMOTE := 0;
		STATUS_DONE := 0;
	end_if;

	if STATUS_LOCAL then
		if START_REMOTE then
			STATUS_LOCAL := 0;
			STATUS_REMOTE := 1;
		end_if;
	end_if;
	if STATUS_REMOTE then
		if not START_REMOTE then
			STATUS_LOCAL := 1;
			STATUS_REMOTE := 0;
		end_if;
		if START_TEST then
			STATUS_REMOTE := 0;
			(* do test *)
			(* TCP_SRV -> PLC_ *)
			STATUS_DONE := 1;
		end_if;
	end_if;
	if STATUS_DONE then
		if not START_TEST then
			STATUS_DONE := 0;
			STATUS_LOCAL := 1;
		end_if;
	end_if;

END_PROGRAM
