(*[[
]]*)
PROGRAM Normal 
#import "Resource1.gvl"
#import "Crosstable.gvl"

VAR
	first : BOOL := TRUE;
	timer : TON;
	flip : BOOL := TRUE;
END_VAR;

	if first then
		(* digital i/o configuration *)
		PLC_DigDir_1 := 1; (* output *)
		PLC_DigDir_2 := 1; (* output *)
		PLC_DigDir_3 := 1; (* output *)
		PLC_DigDir_4 := 1; (* output *)
		PLC_DigDir_5 := 0; (* input *)
		PLC_DigDir_6 := 0; (* input *)
		PLC_DigDir_7 := 0; (* input *)
		PLC_DigDir_8 := 0; (* input *)

		(* analog i/o configuration *)
		PLC_AnInConf_1 := 2; (* voltage *)
		PLC_AnInConf_2 := 2; (* voltage *)
		PLC_AnOutConf_1 := 2; (* voltage *)
	end_if;
	timer(IN := TRUE, PT := T#500ms );
(*
	if timer.Q then
		flip := not flip;
		PLC_DigOut_1 := flip;
		PLC_AnOut_1 := ((PLC_AnIn_1 + PLC_AnIn_2) / 2) / 10;
		timer(IN := FALSE);
		timer(IN := TRUE);
	end_if;
*)
END_PROGRAM
