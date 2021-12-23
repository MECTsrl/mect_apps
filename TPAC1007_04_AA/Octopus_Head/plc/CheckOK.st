(*[[
]]*)
FUNCTION CheckOK
#import "Crosstable.gvl"
VAR_INPUT
END_VAR
VAR 
	Tolleranza_Tamb : INT := 200; (* 30.0°C +/- 20.0°C *)
	Tolleranza_RPM : INT := 10; (* 1.0 rpm *) 

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

	if TST_AnIn_1  then OK_AnIn_1  := CheckAnIn(RES_AnIn_1 , VAL_AnIn_1 , VAL_AnInConf_1 , RES_Tamb); end_if;
	if TST_AnIn_2  then OK_AnIn_2  := CheckAnIn(RES_AnIn_2 , VAL_AnIn_2 , VAL_AnInConf_2 , RES_Tamb); end_if;
	if TST_AnIn_3  then OK_AnIn_3  := CheckAnIn(RES_AnIn_3 , VAL_AnIn_3 , VAL_AnInConf_3 , RES_Tamb); end_if;
	if TST_AnIn_4  then OK_AnIn_4  := CheckAnIn(RES_AnIn_4 , VAL_AnIn_4 , VAL_AnInConf_4 , RES_Tamb); end_if;

	if TST_AnIn_5  then
		if VAL_AnInConf_5 = 2 then 
			(* TPAC1007_04_AB with Decimals=3 *)
			OK_AnIn_5  := CheckAnIn(RES_AnIn_5 , VAL_AnIn_5 , VAL_AnInConf_5 , RES_Tamb);
		elsif VAL_AnInConf_5 = 7 then 
			(* TPLC100_01_AB with Decimals=3 but fixed point=1 *)
			OK_AnIn_5  := CheckAnIn(RES_AnIn_5 / 100, VAL_AnIn_5 /100, VAL_AnInConf_5 , RES_Tamb);
		else
			OK_AnIn_5 := false;
		end_if;
	end_if;


	if TST_AnIn_6  then OK_AnIn_6  := CheckAnIn(RES_AnIn_6 , VAL_AnIn_6 , VAL_AnInConf_6 , RES_Tamb); end_if;
	if TST_AnIn_7  then OK_AnIn_7  := CheckAnIn(RES_AnIn_7 , VAL_AnIn_7 , VAL_AnInConf_7 , RES_Tamb); end_if;
	if TST_AnIn_8  then OK_AnIn_8  := CheckAnIn(RES_AnIn_8 , VAL_AnIn_8 , VAL_AnInConf_8 , RES_Tamb); end_if;
	if TST_AnIn_9  then OK_AnIn_9  := CheckAnIn(RES_AnIn_9 , VAL_AnIn_9 , VAL_AnInConf_9 , RES_Tamb); end_if;
	if TST_AnIn_10 then OK_AnIn_10 := CheckAnIn(RES_AnIn_10, VAL_AnIn_10, VAL_AnInConf_10, RES_Tamb); end_if;
	if TST_AnIn_11 then OK_AnIn_11 := CheckAnIn(RES_AnIn_11, VAL_AnIn_11, VAL_AnInConf_11, RES_Tamb); end_if;
	if TST_AnIn_12 then OK_AnIn_12 := CheckAnIn(RES_AnIn_12, VAL_AnIn_12, VAL_AnInConf_12, RES_Tamb); end_if;

	if TST_AnOut_1  then OK_AnOut_1 := CheckAnOut(RES_AnOut_1, VAL_AnOut_1, VAL_AnOutConf_1); end_if;
	if TST_AnOut_2  then OK_AnOut_2 := CheckAnOut(RES_AnOut_2, VAL_AnOut_2, VAL_AnOutConf_2); end_if;
	if TST_AnOut_3  then OK_AnOut_3 := CheckAnOut(RES_AnOut_3, VAL_AnOut_3, VAL_AnOutConf_3); end_if;
	if TST_AnOut_4  then OK_AnOut_4 := CheckAnOut(RES_AnOut_4, VAL_AnOut_4, VAL_AnOutConf_4); end_if;

	if TST_Tamb  then OK_Tamb  := abs(RES_Tamb - VAL_Tamb) <= Tolleranza_Tamb; end_if;
	if TST_RPM  then OK_RPM  := abs(UINT_TO_INT(RES_RPM) - UINT_TO_INT(VAL_RPM) ) <= Tolleranza_RPM; end_if;

	if TST_VCC_set  then OK_VCC_set  := abs(RES_VCC_set  - VAL_VCC_set ) <= Tolleranza_VCC_set; end_if;
	if TST_mA_max  then OK_mA_max  := abs(RES_mA_max - VAL_mA_max ) <= Tolleranza_mA_max; end_if;

	if TST_VCC_fbk  then OK_VCC_fbk  := abs(RES_VCC_fbk  - VAL_VCC_fbk ) <= Tolleranza_VCC_fbk; end_if;
	if TST_mA_fbk  then OK_mA_fbk := abs(RES_mA_fbk - VAL_mA_fbk ) <= Tolleranza_mA_fbk; end_if;

	if TST_FWrevision  then OK_FWrevision  := (RES_FWrevision = VAL_FWrevision); end_if;
	if TST_HWconfig  then OK_HWconfig  := (RES_HWconfig = VAL_HWconfig); end_if;
	
	(* RTUS: Head.RTU1 --> Prey.RTUS *)
	if TST_RTUS_WR  then OK_RTUS_WR  := (RES_RTUS_WR = VAL_RTUS_WR); end_if;
	if TST_RTUS_RD  then OK_RTUS_RD  := (RES_RTUS_RD = VAL_RTUS_RD); end_if;

	(* RTU1: Prey.RTU1 --> Horn.RTUS *)
	if TST_RTU1_WR  then OK_RTU1_WR  := (RES_RTU1_WR = VAL_RTU1_WR); end_if;
	if TST_RTU1_RD  then OK_RTU1_RD  := (RES_RTU1_RD = VAL_RTU1_RD); end_if;

	(* RTU3: Prey.RTU3 <--> MPNC + short-circuit DigOut_1->DigIn_2 *)
	if TST_RTU3_WR  then OK_RTU3_WR  := (RES_RTU3_WR = VAL_RTU3_WR); end_if;
	if TST_RTU3_RD  then OK_RTU3_RD  := (RES_RTU3_RD = VAL_RTU3_RD); end_if;

	(* CAN1: Prey.CAN1 <--> MPNC010 + short-circuit DigOut_1->DigIn_1 *)
	if TST_CAN1_WR  then OK_CAN1_WR  := (RES_CAN1_WR = VAL_CAN1_WR); end_if;
	if TST_CAN1_RD  then OK_CAN1_RD  := (RES_CAN1_RD = VAL_CAN1_RD); end_if;

END_FUNCTION
