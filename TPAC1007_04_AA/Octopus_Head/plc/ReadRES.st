(*[[
]]*)
FUNCTION ReadRES
#import "Crosstable.gvl"

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

	if TST_DigOut_1  then RES_DigOut_1 := MPNC_DigIn_A_1;  end_if;
	if TST_DigOut_2  then RES_DigOut_2 := MPNC_DigIn_A_2;  end_if;
	if TST_DigOut_3  then RES_DigOut_3 := MPNC_DigIn_A_3;  end_if;
	if TST_DigOut_4  then RES_DigOut_4 := MPNC_DigIn_A_4;  end_if;
	if TST_DigOut_5  then RES_DigOut_5 := MPNC_DigIn_A_5;  end_if;
	if TST_DigOut_6  then RES_DigOut_6 := MPNC_DigIn_A_6;  end_if;
	if TST_DigOut_7  then RES_DigOut_7 := MPNC_DigIn_A_7;  end_if;
	if TST_DigOut_8  then RES_DigOut_8 := MPNC_DigIn_A_8;  end_if;
	if TST_DigOut_9  then RES_DigOut_9 := MPNC_DigIn_A_9;  end_if;
	if TST_DigOut_10 then RES_DigOut_10:= MPNC_DigIn_A_10; end_if;
	if TST_DigOut_11 then RES_DigOut_11:= MPNC_DigIn_A_11; end_if;
	if TST_DigOut_12 then RES_DigOut_12:= MPNC_DigIn_A_12; end_if;
	if TST_DigOut_13 then RES_DigOut_13:= MPNC_DigIn_A_13; end_if;
	if TST_DigOut_14 then RES_DigOut_14:= MPNC_DigIn_A_14; end_if;
	if TST_DigOut_15 then RES_DigOut_15:= MPNC_DigIn_A_15; end_if;
	if TST_DigOut_16 then RES_DigOut_16:= MPNC_DigIn_A_16; end_if;

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

	if TST_AnOut_1  then RES_AnOut_1 := RES2_AnIn_1 / 10;  end_if;
	if TST_AnOut_2  then RES_AnOut_2 := RES2_AnIn_2 / 10;  end_if;
	if TST_AnOut_3  then RES_AnOut_3 := MPNC_AnIn_1 / 10;  end_if;
	if TST_AnOut_4  then RES_AnOut_4 := MPNC_AnIn_2 / 10;  end_if;

	if TST_Tamb  then RES_Tamb  := RESx_Tamb;  end_if;
	if TST_RPM   then RES_RPM  := RESx_RPM;  end_if;

	if TST_VCC_set  then RES_VCC_set  := PLC_AnOut_3;  end_if;
	if TST_mA_max  then RES_mA_max  := PLC_AnOut_4;  end_if;

	if TST_VCC_fbk  then RES_VCC_fbk  := PLC_AnIn_1;  end_if;
	if TST_mA_fbk  then RES_mA_fbk  := PLC_AnIn_2;  end_if;

	if TST_FWrevision  then RES_FWrevision  := RESx_FWrevision;  end_if;
	if TST_HWconfig  then RES_HWconfig  := RESx_HWconfig;  end_if;

	(* RTUS: Head.RTU1 --> Prey.RTUS *)
	if TST_RTUS_WR then (* RES_RTUS_WR := RTU_RTU1_RD; *); end_if;
	if TST_RTUS_RD then RES_RTUS_RD := RESx_RTUS_RD; end_if;

	(* RTU1: Prey.RTU1 --> Horn.RTUS *)
	if TST_RTU1_WR then RES_RTU1_WR := RES2_RTUS_RD; end_if;
	if TST_RTU1_RD then RES_RTU1_RD := RESx_RTU1_RD; end_if;

	(* RTU3: Prey.RTU3 <--> MPNC + short-circuit DigOut_1->DigIn_2 *)
	if TST_RTU3_WR then RES_RTU3_WR := VAL_RTU3_WR; end_if; (* short circuit *)
	if TST_RTU3_RD then RES_RTU3_RD := RESx_RTU3_RD; end_if;
	
	(* CAN1: Prey.CAN1 <--> MPNC010 + short-circuit DigOut_1->DigIn_1 *)
	if TST_CAN1_WR then RES_CAN1_WR := VAL_CAN1_WR; end_if; (* short circuit *)
	if TST_CAN1_RD then RES_CAN1_RD := RESx_CAN1_RD; end_if;

END_FUNCTION
