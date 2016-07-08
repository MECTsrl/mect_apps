(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"

	PLC_AnInConf_1 := 2; (* 0..10V *)
	PLC_AnInConf_2 := 2; (* 0..10V *)
	PLC_AnInConf_3 := 2; (* 0..10V *)
	PLC_AnInConf_4 := 2; (* 0..10V *)

	PLC_AnOutConf_1 := 2; (* 0..10V *)
	PLC_AnOutConf_2 := 2; (* 0..10V *)

	TPLC005_DigDir_3 := 0; (* RTU3 RD *)
	TPLC005_DigDir_4 := 1; (* RTU3 WR *)

	TEST_STATUS := STATUS_LOCAL;

END_PROGRAM
