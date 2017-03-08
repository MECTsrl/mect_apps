(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

PLC_DigDir_5 := 1; (* --> PLC_DigIn_7  *)
PLC_DigDir_6 := 1; (* Latency <-- PLC_DigIn_7  *)
PLC_DigDir_7 := 0; (* --> TPC_DigIn_3  *)
PLC_DigDir_8 := 1; (* <-- TPC_DigOut_4 *)

PLC_AnInConf_1 := 2; (* 0..10 V *)
PLC_AnInConf_2 := 2; (* 0..10 V *)
PLC_AnOutConf_1 := 2; (* 0..10 V *)

END_PROGRAM
