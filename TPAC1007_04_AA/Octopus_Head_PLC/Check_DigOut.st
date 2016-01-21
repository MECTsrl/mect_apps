(*[[
]]*)
FUNCTION Check_DigOut
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	(* Get results *)
	if TST_DigOut_1  then RES_DigOut_1 := RTU_DigIn_1;  end_if;
	if TST_DigOut_2  then RES_DigOut_2 := RTU_DigIn_2;  end_if;
	if TST_DigOut_3  then RES_DigOut_3 := RTU_DigIn_3;  end_if;
	if TST_DigOut_4  then RES_DigOut_4 := RTU_DigIn_4;  end_if;
	if TST_DigOut_5  then RES_DigOut_5 := RTU_DigIn_5;  end_if;
	if TST_DigOut_6  then RES_DigOut_6 := RTU_DigIn_6;  end_if;
	if TST_DigOut_7  then RES_DigOut_7 := RTU_DigIn_7;  end_if;
	if TST_DigOut_8  then RES_DigOut_8 := RTU_DigIn_8;  end_if;
	if TST_DigOut_9  then RES_DigOut_9 := RTU_DigIn_9;  end_if;
	if TST_DigOut_10 then RES_DigOut_10:= RTU_DigIn_10; end_if;
	if TST_DigOut_11 then RES_DigOut_11:= RTU_DigIn_11; end_if;
	if TST_DigOut_12 then RES_DigOut_12:= RTU_DigIn_12; end_if;
	if TST_DigOut_13 then RES_DigOut_13:= RTU_DigIn_13; end_if;
	if TST_DigOut_14 then RES_DigOut_14:= RTU_DigIn_14; end_if;
	if TST_DigOut_15 then RES_DigOut_15:= RTU_DigIn_15; end_if;
	if TST_DigOut_16 then RES_DigOut_16:= RTU_DigIn_16; end_if;

	(* Check values *)
	if TST_DigOut_1  then OK_DigOut_1 := (RES_DigOut_1 = VAL_DigOut_1);  end_if;
	if TST_DigOut_2  then OK_DigOut_2 := (RES_DigOut_2 = VAL_DigOut_2);  end_if;
	if TST_DigOut_3  then OK_DigOut_3 := (RES_DigOut_3 = VAL_DigOut_3);  end_if;
	if TST_DigOut_4  then OK_DigOut_4 := (RES_DigOut_4 = VAL_DigOut_4);  end_if;
	if TST_DigOut_5  then OK_DigOut_5 := (RES_DigOut_5 = VAL_DigOut_5);  end_if;
	if TST_DigOut_6  then OK_DigOut_6 := (RES_DigOut_6 = VAL_DigOut_6);  end_if;
	if TST_DigOut_7  then OK_DigOut_7 := (RES_DigOut_7 = VAL_DigOut_7);  end_if;
	if TST_DigOut_8  then OK_DigOut_8 := (RES_DigOut_8 = VAL_DigOut_8);  end_if;
	if TST_DigOut_9  then OK_DigOut_9 := (RES_DigOut_9 = VAL_DigOut_9);  end_if;
	if TST_DigOut_10 then OK_DigOut_10:= (RES_DigOut_10 = VAL_DigOut_10); end_if;
	if TST_DigOut_11 then OK_DigOut_11:= (RES_DigOut_11 = VAL_DigOut_11); end_if;
	if TST_DigOut_12 then OK_DigOut_12:= (RES_DigOut_12 = VAL_DigOut_12); end_if;
	if TST_DigOut_13 then OK_DigOut_13:= (RES_DigOut_13 = VAL_DigOut_13); end_if;
	if TST_DigOut_14 then OK_DigOut_14:= (RES_DigOut_14 = VAL_DigOut_14); end_if;
	if TST_DigOut_15 then OK_DigOut_15:= (RES_DigOut_15 = VAL_DigOut_15); end_if;
	if TST_DigOut_16 then OK_DigOut_16:= (RES_DigOut_16 = VAL_DigOut_16); end_if;

END_FUNCTION
