(*[[
]]*)
FUNCTION CheckOK
#import "Crosstable.gvl"
VAR_INPUT
END_VAR
VAR 
	Tolleranza_In : INT := 100; (* 20mV = 2 * 10mV *)
	Tolleranza_Out : INT := 10; (* 20mV = 2 x (10V / 4000 = 0.0025V := 0.003 V := 10 mV) *)
	Tolleranza_OutX: INT := 20; (* 30mV = 10 mV + (10V /  800 = 0.0125V := 0.020 V := 20 mV) *)
	Tolleranza_Tamb_min : INT := 10;
	Tolleranza_RPM : INT := 100;
	Tolleranza_VCC_set : INT := 10; (* 0.01 V *)
	Tolleranza_mA_max : INT := 10; (* 0.01 mA *)
	Tolleranza_VCC_fbk : INT := 100; (* 0.1 V *)
	Tolleranza_mA_fbk : INT := 100; (* 0.1 mA *)
END_VAR

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

	if TST_AnIn_1  then OK_AnIn_1  := abs(RES_AnIn_1  - VAL_AnIn_1 ) <= Tolleranza_In; end_if;
	if TST_AnIn_2  then OK_AnIn_2  := abs(RES_AnIn_2  - VAL_AnIn_2 ) <= Tolleranza_In; end_if;
	if TST_AnIn_3  then OK_AnIn_3  := abs(RES_AnIn_3  - VAL_AnIn_3 ) <= Tolleranza_In; end_if;
	if TST_AnIn_4  then OK_AnIn_4  := abs(RES_AnIn_4  - VAL_AnIn_4 ) <= Tolleranza_In; end_if;

	if TST_AnIn_5  then OK_AnIn_5  := abs(RES_AnIn_5  - VAL_AnIn_5 ) <= Tolleranza_In; end_if;
	if TST_AnIn_6  then OK_AnIn_6  := abs(RES_AnIn_6  - VAL_AnIn_6 ) <= Tolleranza_In; end_if;
	if TST_AnIn_7  then OK_AnIn_7  := abs(RES_AnIn_7  - VAL_AnIn_7 ) <= Tolleranza_In; end_if;
	if TST_AnIn_8  then OK_AnIn_8  := abs(RES_AnIn_8  - VAL_AnIn_8 ) <= Tolleranza_In; end_if;
	if TST_AnIn_9  then OK_AnIn_9  := abs(RES_AnIn_9  - VAL_AnIn_9 ) <= Tolleranza_In; end_if;
	if TST_AnIn_10 then OK_AnIn_10 := abs(RES_AnIn_10 - VAL_AnIn_10) <= Tolleranza_In; end_if;
	if TST_AnIn_11 then OK_AnIn_11 := abs(RES_AnIn_11 - VAL_AnIn_11) <= Tolleranza_In; end_if;
	if TST_AnIn_12 then OK_AnIn_12 := abs(RES_AnIn_12 - VAL_AnIn_12) <= Tolleranza_In; end_if;

	(* input on TPAC1007_4AA 12bit *)
	if TST_AnOut_1  then OK_AnOut_1 := abs(RES_AnOut_1 - VAL_AnOut_1) <= Tolleranza_Out; end_if;
	if TST_AnOut_2  then OK_AnOut_2 := abs(RES_AnOut_2 - VAL_AnOut_2) <= Tolleranza_Out; end_if;
	(* input on TPLC005 10bit *)
	if TST_AnOut_3  then OK_AnOut_3 := abs(RES_AnOut_3 - VAL_AnOut_3) <= Tolleranza_OutX; end_if;
	if TST_AnOut_4  then OK_AnOut_4 := abs(RES_AnOut_4 - VAL_AnOut_4) <= Tolleranza_OutX; end_if;

	if TST_Tamb  then OK_Tamb  := (Tolleranza_Tamb_min <= RES_Tamb) and (RES_Tamb <= VAL_Tamb ); end_if;
	if TST_RPM  then OK_RPM  := abs(UINT_TO_INT(RES_RPM) - UINT_TO_INT(VAL_RPM) ) <= Tolleranza_RPM; end_if;

	if TST_VCC_set  then OK_VCC_set  := abs(RES_VCC_set  - VAL_VCC_set ) <= Tolleranza_VCC_set; end_if;
	if TST_mA_max  then OK_mA_max  := abs(RES_mA_max - VAL_mA_max ) <= Tolleranza_mA_max; end_if;

	if TST_VCC_fbk  then OK_VCC_fbk  := abs(RES_VCC_fbk  - VAL_VCC_fbk ) <= Tolleranza_VCC_fbk; end_if;
	if TST_mA_fbk  then OK_mA_fbk := abs(RES_mA_fbk - VAL_mA_fbk ) <= Tolleranza_mA_fbk; end_if;

	if TST_FWrevision  then OK_FWrevision  := (RES_FWrevision = VAL_FWrevision); end_if;
	if TST_HWconfig  then OK_HWconfig  := (RES_HWconfig = VAL_HWconfig); end_if;

END_FUNCTION
