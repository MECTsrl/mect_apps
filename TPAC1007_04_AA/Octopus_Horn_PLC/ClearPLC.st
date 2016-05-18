(*[[
]]*)
FUNCTION ClearPLC
#import "Crosstable.gvl"
VAR_INPUT
END_VAR
	
	PLC_DigOut_1 := 0;

	PLC_DigOut_3 := 0;
	PLC_DigOut_4 := 0;
	PLC_DigOut_5 := 0;
	PLC_DigOut_6 := 0;
	PLC_DigOut_7 := 0;
	PLC_DigOut_8 := 0;

	PLC_AnOutConf_1 := 2;
	PLC_AnOutConf_2 := 2;
	PLC_AnOutConf_3 := 2;
	PLC_AnOutConf_4 := 2;
	PLC_AnOut_1 := 0;
	PLC_AnOut_2 := 0;
	PLC_AnOut_3 := 0;
	PLC_AnOut_4 := 0;

END_FUNCTION
