(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

PLC_DigDir_1 := 1; (* --> PLC_DigIn_3  *)
PLC_DigDir_2 := 1; (* Latency <-- PLC_DigIn_3  *)
PLC_DigDir_3 := 0; (* TPC_DigIn_3  *)
PLC_DigDir_4 := 1; (* TPC_DigOut_4 *)

END_PROGRAM
