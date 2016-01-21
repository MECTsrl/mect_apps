(*[[
]]*)
FUNCTION Translate_AnIn
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	if TST_AnIn_1  then
		TSTx_AnIn_1 := TRUE;
		VALx_AnInConf_1 := VAL_AnInConf_1;
		VALx_AnInFltr_1 := VAL_AnInFltr_1;
		(* <-- Head AO1 + DO6 + DO8 *) 
		PLC_AnOutConf_1 := VAL_AnInConf_1;
		PLC_AnOut_1 := VAL_AnIn_1;
		PLC_DigDir_6 := 1;
		PLC_DigDir_8 := 1;
		case VAL_AnInConf_1 of
		1: PLC_DigOut_8 := 1; PLC_DigOut_6 := 0;
		2: PLC_DigOut_8 := 0; PLC_DigOut_6 := 0;
		3, 4, 5, 6, 7: PLC_DigOut_8 := 0; PLC_DigOut_6 := 1;
		else PLC_DigOut_8 := 0; PLC_DigOut_6 := 0;
		end_case;
	end_if;

	if TST_AnIn_2  then
		TSTx_AnIn_2 := TRUE;
		VALx_AnInConf_2 := VAL_AnInConf_2;
		VALx_AnInFltr_2 := VAL_AnInFltr_2;
		(* <-- Head AO2 + DO5 + DO7 *) 
		PLC_AnOutConf_2 := VAL_AnInConf_2;
		PLC_AnOut_2 := VAL_AnIn_2;
		PLC_DigDir_5 := 1;
		PLC_DigDir_7 := 1;
		case VAL_AnInConf_2 of
		1: PLC_DigOut_7 := 1; PLC_DigOut_5 := 0;
		2: PLC_DigOut_7 := 0; PLC_DigOut_5 := 0;
		3, 4, 5, 6, 7: PLC_DigOut_7 := 0; PLC_DigOut_5 := 1;
		else PLC_DigOut_7 := 0; PLC_DigOut_5 := 0;
		end_case;
	end_if;

	if TST_AnIn_3  then
		TSTx_AnIn_3 := TRUE;
		VALx_AnInConf_3 := VAL_AnInConf_3;
		VALx_AnInFltr_3 := VAL_AnInFltr_3;
		(* <-- Horn2 AO1 + DO6 + DO8 *) 
		TST2_AnOut_1 := 1;
		VAL2_AnOutConf_1 := VAL_AnInConf_3;
		VAL2_AnOut_1 := VAL_AnIn_3;
		TST2_DigOut_6 := 1;
		TST2_DigOut_8 := 1;
		case VAL_AnInConf_3 of
		1: VAL2_DigOut_8 := 1; VAL2_DigOut_6 := 0;
		2: VAL2_DigOut_8 := 0; VAL2_DigOut_6 := 0;
		3, 4, 5, 6, 7: VAL2_DigOut_8 := 0; VAL2_DigOut_6 := 1;
		else VAL2_DigOut_8 := 0; VAL2_DigOut_6 := 0;
		end_case;
	end_if;

	if TST_AnIn_4  then
		TSTx_AnIn_4 := TRUE;
		VALx_AnInConf_4 := VAL_AnInConf_4;
		VALx_AnInFltr_4 := VAL_AnInFltr_4;
		(* <-- Horn2 AO2 + DO5 + DO7 *) 
		TST2_AnOut_2 := 1;
		VAL2_AnOutConf_2 := VAL_AnInConf_4;
		VAL2_AnOut_3 := VAL_AnIn_4;
		TST2_DigOut_5 := 1;
		TST2_DigOut_7 := 1;
		case VAL_AnInConf_4 of
		1: VAL2_DigOut_7 := 1; VAL2_DigOut_5 := 0;
		2: VAL2_DigOut_7 := 0; VAL2_DigOut_5 := 0;
		3, 4, 5, 6, 7: VAL2_DigOut_7 := 0; VAL2_DigOut_5 := 1;
		else VAL2_DigOut_7 := 0; VAL2_DigOut_5 := 0;
		end_case;
	end_if;

	if TST_AnIn_5  then
		TSTx_AnIn_5 := TRUE;
		VALx_AnInConf_5 := VAL_AnInConf_5;
		VALx_AnInFltr_5 := VAL_AnInFltr_5;
		(* <-- Head/TPLC005 AO1 *) 
		RTU_AnOut_1 := VAL_AnIn_5;
		(* <-- Horn2 AO4 V : double for TPAC1007_4AB *)
		TST2_AnOut_4 := 1;
		VAL2_AnOutConf_4 := VAL_AnInConf_5;
		VAL2_AnOut_4 := VAL_AnIn_5;
	end_if;
	if TST_AnIn_6  then
		TSTx_AnIn_6 := TRUE;
		VALx_AnInConf_6 := VAL_AnInConf_6;
		VALx_AnInFltr_6 := VAL_AnInFltr_6;
		(* <-- Head/TPLC005 AO2 *) 
		RTU_AnOut_2 := VAL_AnIn_6;
	end_if;
	if TST_AnIn_7  then
		TSTx_AnIn_7 := TRUE;
		VALx_AnInConf_7 := VAL_AnInConf_7;
		VALx_AnInFltr_7 := VAL_AnInFltr_7;
		(* <-- Head/TPLC005 AO3 *) 
		PLC_AnOut_3 := VAL_AnIn_7;
	end_if;
	if TST_AnIn_8  then
		TSTx_AnIn_8 := TRUE;
		VALx_AnInConf_8 := VAL_AnInConf_8;
		VALx_AnInFltr_8 := VAL_AnInFltr_8;
		(* <-- Head/TPLC005 AO4 *) 
		RTU_AnOut_4 := VAL_AnIn_8;
	end_if;
	if TST_AnIn_9  then
		TSTx_AnIn_9 := TRUE;
		VALx_AnInConf_9 := VAL_AnInConf_9;
		VALx_AnInFltr_9 := VAL_AnInFltr_9;
		(* <-- Head/TPLC005 AO5*) 
		RTU_AnOut_5 := VAL_AnIn_9;
	end_if;
	if TST_AnIn_10 then
		TSTx_AnIn_10:= TRUE;
		VALx_AnInConf_10:= VAL_AnInConf_10;
		VALx_AnInFltr_10:= VAL_AnInFltr_10;
		(* <-- Head/TPLC005 AO6*) 
		RTU_AnOut_6 := VAL_AnIn_10;
	end_if;
	if TST_AnIn_11 then
		TSTx_AnIn_11:= TRUE;
		VALx_AnInConf_11:= VAL_AnInConf_11;
		VALx_AnInFltr_11:= VAL_AnInFltr_11;
		(* <-- Head/TPLC005 AO7*) 
		RTU_AnOut_7 := VAL_AnIn_11;
	end_if;
	if TST_AnIn_12 then
		TSTx_AnIn_12:= TRUE;
		VALx_AnInConf_12:= VAL_AnInConf_12;
		VALx_AnInFltr_12:= VAL_AnInFltr_12;
		(* <-- Head/TPLC005 AO8*) 
		RTU_AnOut_8 := VAL_AnIn_12;
	end_if;

END_FUNCTION
