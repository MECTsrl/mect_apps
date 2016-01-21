(*[[
]]*)
FUNCTION Check_DigIn
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	(* Get results *)
	if TST_DigIn_1  then RES_DigIn_1 := RESx_DigIn_1;  end_if;
	if TST_DigIn_2  then RES_DigIn_2 := RESx_DigIn_2;  end_if;
	if TST_DigIn_3  then RES_DigIn_3 := RESx_DigIn_3;  end_if;
	if TST_DigIn_4  then RES_DigIn_4 := RESx_DigIn_4;  end_if;
	if TST_DigIn_5  then RES_DigIn_5 := RESx_DigIn_5;  end_if;
	if TST_DigIn_6  then RES_DigIn_6 := RESx_DigIn_6;  end_if;
	if TST_DigIn_7  then RES_DigIn_7 := RESx_DigIn_7;  end_if;
	if TST_DigIn_8  then RES_DigIn_8 := RESx_DigIn_8;  end_if;
	if TST_DigIn_9  then RES_DigIn_9 := RESx_DigIn_9;  end_if;
	if TST_DigIn_10 then RES_DigIn_10:= RESx_DigIn_10; end_if;
	if TST_DigIn_11 then RES_DigIn_11:= RESx_DigIn_11; end_if;
	if TST_DigIn_12 then RES_DigIn_12:= RESx_DigIn_12; end_if;
	if TST_DigIn_13 then RES_DigIn_13:= RESx_DigIn_13; end_if;
	if TST_DigIn_14 then RES_DigIn_14:= RESx_DigIn_14; end_if;
	if TST_DigIn_15 then RES_DigIn_15:= RESx_DigIn_15; end_if;
	if TST_DigIn_16 then RES_DigIn_16:= RESx_DigIn_16; end_if;

	(* Check values *)
	if TST_DigIn_1  then OK_DigIn_1 := (RES_DigIn_1 = VAL_DigIn_1);  end_if;
	if TST_DigIn_2  then OK_DigIn_2 := (RES_DigIn_2 = VAL_DigIn_2);  end_if;
	if TST_DigIn_3  then OK_DigIn_3 := (RES_DigIn_3 = VAL_DigIn_3);  end_if;
	if TST_DigIn_4  then OK_DigIn_4 := (RES_DigIn_4 = VAL_DigIn_4);  end_if;
	if TST_DigIn_5  then OK_DigIn_5 := (RES_DigIn_5 = VAL_DigIn_5);  end_if;
	if TST_DigIn_6  then OK_DigIn_6 := (RES_DigIn_6 = VAL_DigIn_6);  end_if;
	if TST_DigIn_7  then OK_DigIn_7 := (RES_DigIn_7 = VAL_DigIn_7);  end_if;
	if TST_DigIn_8  then OK_DigIn_8 := (RES_DigIn_8 = VAL_DigIn_8);  end_if;
	if TST_DigIn_9  then OK_DigIn_9 := (RES_DigIn_9 = VAL_DigIn_9);  end_if;
	if TST_DigIn_10 then OK_DigIn_10:= (RES_DigIn_10 = VAL_DigIn_10); end_if;
	if TST_DigIn_11 then OK_DigIn_11:= (RES_DigIn_11 = VAL_DigIn_11); end_if;
	if TST_DigIn_12 then OK_DigIn_12:= (RES_DigIn_12 = VAL_DigIn_12); end_if;
	if TST_DigIn_13 then OK_DigIn_13:= (RES_DigIn_13 = VAL_DigIn_13); end_if;
	if TST_DigIn_14 then OK_DigIn_14:= (RES_DigIn_14 = VAL_DigIn_14); end_if;
	if TST_DigIn_15 then OK_DigIn_15:= (RES_DigIn_15 = VAL_DigIn_15); end_if;
	if TST_DigIn_16 then OK_DigIn_16:= (RES_DigIn_16 = VAL_DigIn_16); end_if;

END_FUNCTION
