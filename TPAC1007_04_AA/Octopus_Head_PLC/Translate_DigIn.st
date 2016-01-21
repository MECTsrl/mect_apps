(*[[
]]*)
FUNCTION Translate_DigIn
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	(* DigIn 1..16 are on the local TPLC005 *) 
	TSTx_DigIn_1 := TST_DigIn_1;
	TSTx_DigIn_2 := TST_DigIn_2;
	TSTx_DigIn_3 := TST_DigIn_3;
	TSTx_DigIn_4 := TST_DigIn_4;
	TSTx_DigIn_5 := TST_DigIn_5;
	TSTx_DigIn_6 := TST_DigIn_6;
	TSTx_DigIn_7 := TST_DigIn_7;
	TSTx_DigIn_8 := TST_DigIn_8;
	TSTx_DigIn_9 := TST_DigIn_9;
	TSTx_DigIn_10:= TST_DigIn_10;
	TSTx_DigIn_11:= TST_DigIn_11;
	TSTx_DigIn_12:= TST_DigIn_12;
	TSTx_DigIn_13:= TST_DigIn_13;
	TSTx_DigIn_14:= TST_DigIn_14;
	TSTx_DigIn_15:= TST_DigIn_15;
	TSTx_DigIn_16:= TST_DigIn_16;

	if TST_DigIn_1  then RTU_DigOut_1 := VAL_DigIn_1;  end_if;
	if TST_DigIn_2  then RTU_DigOut_2 := VAL_DigIn_2;  end_if;
	if TST_DigIn_3  then RTU_DigOut_3 := VAL_DigIn_3;  end_if;
	if TST_DigIn_4  then RTU_DigOut_4 := VAL_DigIn_4;  end_if;
	if TST_DigIn_5  then RTU_DigOut_5 := VAL_DigIn_5;  end_if;
	if TST_DigIn_6  then RTU_DigOut_6 := VAL_DigIn_6;  end_if;
	if TST_DigIn_7  then RTU_DigOut_7 := VAL_DigIn_7;  end_if;
	if TST_DigIn_8  then RTU_DigOut_8 := VAL_DigIn_8;  end_if;
	if TST_DigIn_9  then RTU_DigOut_9 := VAL_DigIn_9;  end_if;
	if TST_DigIn_10 then RTU_DigOut_10:= VAL_DigIn_10; end_if;
	if TST_DigIn_11 then RTU_DigOut_11:= VAL_DigIn_11; end_if;
	if TST_DigIn_12 then RTU_DigOut_12:= VAL_DigIn_12; end_if;
	if TST_DigIn_13 then RTU_DigOut_13:= VAL_DigIn_13; end_if;
	if TST_DigIn_14 then RTU_DigOut_14:= VAL_DigIn_14; end_if;
	if TST_DigIn_15 then RTU_DigOut_15:= VAL_DigIn_15; end_if;
	if TST_DigIn_16 then RTU_DigOut_16:= VAL_DigIn_16; end_if;

END_FUNCTION
