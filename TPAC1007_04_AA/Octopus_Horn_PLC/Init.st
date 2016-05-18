(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"

	PLC_DigDir_1 := True; (* output for RPM 24V @ 5Hz *)
	PLC_DigDir_2 := False;(* free *)
	PLC_DigDir_3 := True; (* output for Analog I/O Test *)
	PLC_DigDir_4 := True; (* output for Analog I/O Test *)
	PLC_DigDir_5 := True; (* output for Analog I/O Test *)
	PLC_DigDir_6 := True; (* output for Analog I/O Test *)
	PLC_DigDir_7 := True; (* output for Analog I/O Test *)
	PLC_DigDir_8 := True; (* output for Analog I/O Test *)

	PLC_AnInConf_1 := 2; (* 0..10V *)
	PLC_AnInConf_2 := 2; (* 0..10V *)
	PLC_AnOutConf_1 := 2; (* 0..10V *)
	PLC_AnOutConf_2 := 2; (* 0..10V *)
	PLC_AnOutConf_3 := 2; (* 0..10V *)
	PLC_AnOutConf_4 := 2; (* 0..10V *)

	TEST_STATUS := STATUS_LOCAL;

END_PROGRAM
