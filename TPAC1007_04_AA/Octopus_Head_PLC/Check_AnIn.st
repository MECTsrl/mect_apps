(*[[
]]*)
FUNCTION Check_AnIn
#import "Crosstable.gvl"
VAR_INPUT
END_VAR
VAR 
	Tolleranza : INT := 1; (* 0.001 *)
END_VAR

	(* Get results *)
	if TST_AnIn_1  then RES_AnIn_1  := RESx_AnIn_1;  end_if;
	if TST_AnIn_2  then RES_AnIn_2  := RESx_AnIn_2;  end_if;
	if TST_AnIn_3  then RES_AnIn_3  := RESx_AnIn_3;  end_if;
	if TST_AnIn_4  then RES_AnIn_4  := RESx_AnIn_4;  end_if;

	if TST_AnIn_5  then RES_AnIn_5  := RESx_AnIn_5;  end_if;
	if TST_AnIn_6  then RES_AnIn_6  := RESx_AnIn_6;  end_if;
	if TST_AnIn_7  then RES_AnIn_7  := RESx_AnIn_7;  end_if;
	if TST_AnIn_8  then RES_AnIn_8  := RESx_AnIn_8;  end_if;
	if TST_AnIn_9  then RES_AnIn_9  := RESx_AnIn_9;  end_if;
	if TST_AnIn_10 then RES_AnIn_10 := RESx_AnIn_10;  end_if;
	if TST_AnIn_11 then RES_AnIn_11 := RESx_AnIn_11;  end_if;
	if TST_AnIn_12 then RES_AnIn_12 := RESx_AnIn_12;  end_if;

	(* Check values *)
	if TST_AnIn_1  then OK_AnIn_1  := abs(RES_AnIn_1  - VAL_AnIn_1 ) < Tolleranza; end_if;
	if TST_AnIn_2  then OK_AnIn_2  := abs(RES_AnIn_2  - VAL_AnIn_2 ) < Tolleranza; end_if;
	if TST_AnIn_3  then OK_AnIn_3  := abs(RES_AnIn_3  - VAL_AnIn_3 ) < Tolleranza; end_if;
	if TST_AnIn_4  then OK_AnIn_4  := abs(RES_AnIn_4  - VAL_AnIn_4 ) < Tolleranza; end_if;

	if TST_AnIn_5  then OK_AnIn_5  := abs(RES_AnIn_5  - VAL_AnIn_5 ) < Tolleranza; end_if;
	if TST_AnIn_6  then OK_AnIn_6  := abs(RES_AnIn_6  - VAL_AnIn_6 ) < Tolleranza; end_if;
	if TST_AnIn_7  then OK_AnIn_7  := abs(RES_AnIn_7  - VAL_AnIn_7 ) < Tolleranza; end_if;
	if TST_AnIn_8  then OK_AnIn_8  := abs(RES_AnIn_8  - VAL_AnIn_8 ) < Tolleranza; end_if;
	if TST_AnIn_9  then OK_AnIn_9  := abs(RES_AnIn_9  - VAL_AnIn_9 ) < Tolleranza; end_if;
	if TST_AnIn_10 then OK_AnIn_10 := abs(RES_AnIn_10 - VAL_AnIn_10) < Tolleranza; end_if;
	if TST_AnIn_11 then OK_AnIn_11 := abs(RES_AnIn_11 - VAL_AnIn_11) < Tolleranza; end_if;
	if TST_AnIn_12 then OK_AnIn_12 := abs(RES_AnIn_12 - VAL_AnIn_12) < Tolleranza; end_if;

END_FUNCTION
