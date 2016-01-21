(*[[
]]*)
FUNCTION Translate_DigOut
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	(* DigOut 1..16 are on the local TPLC005 *) 
	TSTx_DigOut_1 := TST_DigOut_1;
	TSTx_DigOut_2 := TST_DigOut_2;
	TSTx_DigOut_3 := TST_DigOut_3;
	TSTx_DigOut_4 := TST_DigOut_4;
	TSTx_DigOut_5 := TST_DigOut_5;
	TSTx_DigOut_6 := TST_DigOut_6;
	TSTx_DigOut_7 := TST_DigOut_7;
	TSTx_DigOut_8 := TST_DigOut_8;
	TSTx_DigOut_9 := TST_DigOut_9;
	TSTx_DigOut_10:= TST_DigOut_10;
	TSTx_DigOut_11:= TST_DigOut_11;
	TSTx_DigOut_12:= TST_DigOut_12;
	TSTx_DigOut_13:= TST_DigOut_13;
	TSTx_DigOut_14:= TST_DigOut_14;
	TSTx_DigOut_15:= TST_DigOut_15;
	TSTx_DigOut_16:= TST_DigOut_16;

	if TST_DigOut_1  then VALx_DigOut_1 := VAL_DigOut_1;  end_if;
	if TST_DigOut_2  then VALx_DigOut_2 := VAL_DigOut_2;  end_if;
	if TST_DigOut_3  then VALx_DigOut_3 := VAL_DigOut_3;  end_if;
	if TST_DigOut_4  then VALx_DigOut_4 := VAL_DigOut_4;  end_if;
	if TST_DigOut_5  then VALx_DigOut_5 := VAL_DigOut_5;  end_if;
	if TST_DigOut_6  then VALx_DigOut_6 := VAL_DigOut_6;  end_if;
	if TST_DigOut_7  then VALx_DigOut_7 := VAL_DigOut_7;  end_if;
	if TST_DigOut_8  then VALx_DigOut_8 := VAL_DigOut_8;  end_if;
	if TST_DigOut_9  then VALx_DigOut_9 := VAL_DigOut_9;  end_if;
	if TST_DigOut_10 then VALx_DigOut_10:= VAL_DigOut_10; end_if;
	if TST_DigOut_11 then VALx_DigOut_11:= VAL_DigOut_11; end_if;
	if TST_DigOut_12 then VALx_DigOut_12:= VAL_DigOut_12; end_if;
	if TST_DigOut_13 then VALx_DigOut_13:= VAL_DigOut_13; end_if;
	if TST_DigOut_14 then VALx_DigOut_14:= VAL_DigOut_14; end_if;
	if TST_DigOut_15 then VALx_DigOut_15:= VAL_DigOut_15; end_if;
	if TST_DigOut_16 then VALx_DigOut_16:= VAL_DigOut_16; end_if;

END_FUNCTION
