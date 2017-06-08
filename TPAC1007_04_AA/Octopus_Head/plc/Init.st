(*[[
]]*)
PROGRAM Init 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	PLC_DigDir_1 := False; (* PLC_PWR_SWITCH input *)
	PLC_DigDir_2 := True; (* PLC_VPOT_ON output *)
	PLC_DigDir_3 := True; (* PLC_VCC_ON output *)
	PLC_DigDir_4 := False; (* PLC_GO_BUTTON input *)
	PLC_DigDir_5 := True; (* Analog I/O Test output *)
	PLC_DigDir_6 := True; (* Analog I/O Test output *)
	PLC_DigDir_7 := True; (* Analog I/O Test output *)
	PLC_DigDir_8 := True; (* Analog I/O Test output *)

	RTU_LocDigDir_1 := 1; (* TPLC005 Local Digital as Output *)
	RTU_LocDigDir_2 := 1; (* TPLC005 Local Digital as Output *)
	RTU_LocDigDir_3 := 1; (* TPLC005 Local Digital as Output *)
	RTU_LocDigDir_4 := 1; (* TPLC005 Local Digital as Output *)
	RTU_LocDigDir_5 := 1; (* TPLC005 Local Digital as Output *)
	RTU_LocDigDir_6 := 1; (* TPLC005 Local Digital as Output *)
	RTU_LocDigDir_7 := 1; (* TPLC005 Local Digital as Output *)
	RTU_LocDigDir_8 := 1; (* TPLC005 Local Digital as Output *)
	TEST2_COMMAND := TEST_STATUS_LOCAL;
	STATUS := STATUS_IDLE;
	RESULT := RESULT_UNKNOWN;

	if not PLC_DigIn_1 then
		PLC_DigOut_2 := False;
		PLC_DigOut_3 := False;
	end_if;

	PLC_AnInConf_1 := 2; (* 0..10V = VCC feedback (0..40V) *)
	PLC_AnOutConf_3 := 2; (* 0..10V = Logic Analyzer Trigger *)
	PLC_AnOutConf_4 := 2; (* 0..10V = VCC set (0 --> 24V, 10 --> 12V *)
(*	PLC_AnOut_3 := 0; 
    [CMD]: ERROR V0211: Download Configuration {Invalid parameter.}
    [VMM]: < WARNING >  Task '' is neither cyclic nor event driven!
*)
(* ClearPLC(); 
   [CMD]: ERROR V0308: Download Configuration {To many read/write memory regions.}
*)

END_PROGRAM
