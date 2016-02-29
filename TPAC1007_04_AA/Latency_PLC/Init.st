(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"

	PLC_DigDir_5 := 0; (* Latency Input *)
	PLC_DigDir_6 := 1; (* Latency Output *)

	PLC_AnInConf_1 := 2; (* 0..10V *)
	PLC_AnInConf_2 := 2; (* 0..10V *)
	PLC_AnOutConf_1 := 2; (* 0..10V *)
	PLC_AnOutConf_2 := 2; (* 0..10V *)
	PLC_AnOutConf_3 := 2; (* 0..10V *)
	PLC_AnOutConf_4 := 2; (* 0..10V *)

END_PROGRAM
