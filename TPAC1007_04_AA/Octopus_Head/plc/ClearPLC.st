(*[[
]]*)
FUNCTION ClearPLC
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	MPNC_DigOut_A_1 := FALSE;
	MPNC_DigOut_A_2 := FALSE;
	MPNC_DigOut_A_3 := FALSE;
	MPNC_DigOut_A_4 := FALSE;
	MPNC_DigOut_A_5 := FALSE;
	MPNC_DigOut_A_6 := FALSE;
	MPNC_DigOut_A_7 := FALSE;
	MPNC_DigOut_A_8 := FALSE;
	MPNC_DigOut_A_9 := FALSE;
	MPNC_DigOut_A_10 := FALSE;
	MPNC_DigOut_A_11 := FALSE;
	MPNC_DigOut_A_12 := FALSE;
	MPNC_DigOut_A_13 := FALSE;
	MPNC_DigOut_A_14 := FALSE;
	MPNC_DigOut_A_15 := FALSE;
	MPNC_DigOut_A_16 := FALSE;

	MPNC_DigOut_1 := 0;
	MPNC_DigOut_2 := 0;
	MPNC_DigOut_3 := 0;
	MPNC_DigOut_4 := 0;
	MPNC_DigOut_5 := 0;
	MPNC_DigOut_6 := 0;
	MPNC_DigOut_7 := 0;
	MPNC_DigOut_8 := 0;
	
	MPNC_AnInConf_1 := 0;
	MPNC_AnInConf_2 := 0;

	PLC_DigOut_5 := 0;
	PLC_DigOut_6 := 0;
	PLC_DigOut_7 := 0;
	PLC_DigOut_8 := 0;
	
	PLC_AnOutConf_1 := 2;
	PLC_AnOutConf_2 := 2;
	PLC_AnOut_1 := 0;
	PLC_AnOut_2 := 0;
	
END_FUNCTION
