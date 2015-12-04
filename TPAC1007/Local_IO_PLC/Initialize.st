(*[[
]]*)
PROGRAM Initialize 
#import "Resource1.gvl"
#import "Crosstable.gvl"

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

END_PROGRAM
