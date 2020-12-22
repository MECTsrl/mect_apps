(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	PLC_AnInConf_1 := 2; (* 0..10V *)
	PLC_AnInConf_2 := 2; (* 0..10V *)
	PLC_AnInConf_3 := 2; (* 0..10V *)

	PLC_AnOutConf_1 := 2; (* 0..10V *)
	PLC_AnOutConf_2 := 2; (* 0..10V *)

	TEST_STATUS := STATUS_LOCAL;

END_PROGRAM

