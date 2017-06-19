(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	PLC_DigDir_5 := 0; (* THE INPUT <-- PLC_DigOut_7  *)
	PLC_DigDir_6 := 1; (* <-- RTUbis_DigOut_4 (RTUbis Latency) *)
	PLC_DigDir_7 := 1; (* Slow moving *)
	PLC_DigDir_8 := 1; (* <-- TPC_DigOut_4 (TCP Latency) *)
	
	PLC_AnInConf_1 := 2; (* 0..10 V *)
	PLC_AnInConf_2 := 2; (* 0..10 V *)
	PLC_AnOutConf_1 := 2; (* 0..10 V *)

END_PROGRAM

