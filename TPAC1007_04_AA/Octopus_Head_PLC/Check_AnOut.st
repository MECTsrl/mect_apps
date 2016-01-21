(*[[
]]*)
FUNCTION Check_AnOut
#import "Crosstable.gvl"
VAR_INPUT
END_VAR
VAR 
	Tolleranza : INT := 1; (* 0.01 *)
END_VAR

	(* Get results *)
	if TST_AnOut_1  then RES_AnOut_1 := RES2_AnIn_1;  end_if;
	if TST_AnOut_2  then RES_AnOut_2 := RES2_AnIn_2;  end_if;
	if TST_AnOut_3  then RES_AnOut_3 := RTU_AnIn_1;  end_if;
	if TST_AnOut_4  then RES_AnOut_4 := RTU_AnIn_2;  end_if;

	(* Check values *)
	if TST_AnOut_1  then OK_AnOut_1 := abs(RES_AnOut_1 - VAL_AnOut_1) < Tolleranza; end_if;
	if TST_AnOut_2  then OK_AnOut_2 := abs(RES_AnOut_2 - VAL_AnOut_2) < Tolleranza; end_if;
	if TST_AnOut_3  then OK_AnOut_3 := abs(RES_AnOut_3 - VAL_AnOut_3) < Tolleranza; end_if;
	if TST_AnOut_4  then OK_AnOut_4 := abs(RES_AnOut_4 - VAL_AnOut_4) < Tolleranza; end_if;

END_FUNCTION
