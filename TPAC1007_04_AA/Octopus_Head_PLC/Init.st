(*[[
]]*)
PROGRAM Init 
#import "Crosstable.gvl"

	PLC_DigDir_1 := 0; (* PLC_PWR_SWITCH input *)
	PLC_DigDir_2 := 1; (* PLC_VPOT_ON output *)
	PLC_DigDir_3 := 1; (* PLC_VCC_ON output *)
	PLC_DigDir_4 := 0; (* PLC_GO_BUTTON input *)
	RTU_AnOutConf_X := 500; (* ANALOG OUTPUT THRESHOLD *)
	TEST2_COMMAND := TEST_STATUS_LOCAL;
	if not PLC_DigIn_1 then
		PLC_DigOut_2 := 0;
		PLC_DigOut_3 := 0;
	end_if;

END_PROGRAM
