(*[[
]]*)
FUNCTION ClearPLC
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	RTU_DigOut_1 := FALSE;
	RTU_DigOut_2 := FALSE;
	RTU_DigOut_3 := FALSE;
	RTU_DigOut_4 := FALSE;
	RTU_DigOut_5 := FALSE;
	RTU_DigOut_6 := FALSE;
	RTU_DigOut_7 := FALSE;
	RTU_DigOut_8 := FALSE;
	RTU_DigOut_9 := FALSE;
	RTU_DigOut_10 := FALSE;
	RTU_DigOut_11 := FALSE;
	RTU_DigOut_12 := FALSE;
	RTU_DigOut_13 := FALSE;
	RTU_DigOut_14 := FALSE;
	RTU_DigOut_15 := FALSE;
	RTU_DigOut_16 := FALSE;

	RTU_LocDigOut_1 := 0;
	RTU_LocDigOut_2 := 0;
	RTU_LocDigOut_3 := 0;
	RTU_LocDigOut_4 := 0;
	RTU_LocDigOut_5 := 0;
	RTU_LocDigOut_6 := 0;
	RTU_LocDigOut_7 := 0;
	RTU_LocDigOut_8 := 0;
	
	RTU_AnInConf_1 := 0;
	RTU_AnInConf_2 := 0;

	PLC_DigOut_5 := 0;
	PLC_DigOut_6 := 0;
	PLC_DigOut_7 := 0;
	PLC_DigOut_8 := 0;
	
	PLC_AnOutConf_1 := 2;
	PLC_AnOutConf_2 := 2;
	PLC_AnOut_1 := 0;
	PLC_AnOut_2 := 0;
	
END_FUNCTION
