(*[[
]]*)
PROGRAM Init 
#import "Crosstable.gvl"

	PLC_DigDir_1 := False; (* PLC_PWR_SWITCH input *)
	PLC_DigDir_2 := True; (* PLC_VPOT_ON output *)
	PLC_DigDir_3 := True; (* PLC_VCC_ON output *)
	PLC_DigDir_4 := False; (* PLC_GO_BUTTON input *)
	PLC_DigDir_5 := True; (* Analog I/O Test output *)
	PLC_DigDir_6 := True; (* Analog I/O Test output *)
	PLC_DigDir_7 := True; (* Analog I/O Test output *)
	PLC_DigDir_8 := True; (* Analog I/O Test output *)

	RTU_AnOutConf_X := 500; (* ANALOG OUTPUT THRESHOLD *)
	TEST2_COMMAND := TEST_STATUS_LOCAL;
	STATUS := STATUS_IDLE;
	RESULT := RESULT_UNKNOWN;
	if not PLC_DigIn_1 then
		PLC_DigOut_2 := False;
		PLC_DigOut_3 := False;
	end_if;

(* ClearPLC(); 
   [CMD]: ERROR V0308: Download Configuration {To many read/write memory regions.}
*)

END_PROGRAM
