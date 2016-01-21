(*[[
]]*)
FUNCTION Translate_AnOut
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	if TST_AnOut_1  then
		TSTx_AnOut_1 := TRUE;
		VALx_AnOut_1 := VAL_AnOut_1;
		VALx_AnOutConf_1 := VAL_AnOutConf_1;
		(* --> Horn2 AI1 + DO4 *) 
		TST2_AnIn_1 := 1;
		VAL2_AnInConf_1 := VAL_AnOutConf_1;
		VAL2_AnInFltr_1 := 16; 
		TST2_DigOut_4 := 1;
		case VAL_AnOutConf_1 of
		1: VAL2_DigOut_4 := 1;
		2: VAL2_DigOut_4 := 0;
		end_case;
	end_if;

	if TST_AnOut_2  then
		TSTx_AnOut_2 := TRUE;
		VALx_AnOut_2 := VAL_AnOut_2;
		VALx_AnOutConf_2 := VAL_AnOutConf_2;
		(* --> Horn2 AI2 + DO3 *) 
		TST2_AnIn_2 := 1;
		VAL2_AnInConf_2 := VAL_AnOutConf_2;
		VAL2_AnInFltr_2 := 16; 
		TST2_DigOut_3 := 1;
		case VAL_AnOutConf_2 of
		1: VAL2_DigOut_3 := 1;
		2: VAL2_DigOut_3 := 0;
		end_case;
	end_if;

	if TST_AnOut_3  then
		TSTx_AnOut_3 := TRUE;
		VALx_AnOut_3 := VAL_AnOut_3;
		VALx_AnOutConf_3 := VAL_AnOutConf_3;
		(* --> Head/TPLC005 AI1 *) 
		PLC_AnInConf_1 := VAL_AnOutConf_3;
	end_if;

	if TST_AnOut_4  then
		TSTx_AnOut_4 := TRUE;
		VALx_AnOut_4 := VAL_AnOut_4;
		VALx_AnOutConf_4 := VAL_AnOutConf_4;
		(* --> Head/TPLC005 AI2 *) 
		PLC_AnInConf_2 := VAL_AnOutConf_4;
	end_if;

END_FUNCTION
