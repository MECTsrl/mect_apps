(*[[
]]*)
FUNCTION WriteVAL
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	if TST_DigIn_1  then MPNC_DigOut_A_1 := VAL_DigIn_1;  else MPNC_DigOut_A_1 := 0; end_if;
	if TST_DigIn_2  then MPNC_DigOut_A_2 := VAL_DigIn_2;  else MPNC_DigOut_A_2 := 0; end_if;
	if TST_DigIn_3  then MPNC_DigOut_A_3 := VAL_DigIn_3;  else MPNC_DigOut_A_3 := 0; end_if;
	if TST_DigIn_4  then MPNC_DigOut_A_4 := VAL_DigIn_4;  else MPNC_DigOut_A_4 := 0; end_if;
	if TST_DigIn_5  then MPNC_DigOut_A_5 := VAL_DigIn_5;  else MPNC_DigOut_A_5 := 0; end_if;
	if TST_DigIn_6  then MPNC_DigOut_A_6 := VAL_DigIn_6;  else MPNC_DigOut_A_6 := 0; end_if;
	if TST_DigIn_7  then MPNC_DigOut_A_7 := VAL_DigIn_7;  else MPNC_DigOut_A_7 := 0; end_if;
	if TST_DigIn_8  then MPNC_DigOut_A_8 := VAL_DigIn_8;  else MPNC_DigOut_A_8 := 0; end_if;
	if TST_DigIn_9  then MPNC_DigOut_A_9 := VAL_DigIn_9;  else MPNC_DigOut_A_9 := 0; end_if;
	if TST_DigIn_10 then MPNC_DigOut_A_10:= VAL_DigIn_10; else MPNC_DigOut_A_10:= 0; end_if;
	if TST_DigIn_11 then MPNC_DigOut_A_11:= VAL_DigIn_11; else MPNC_DigOut_A_11:= 0; end_if;
	if TST_DigIn_12 then MPNC_DigOut_A_12:= VAL_DigIn_12; else MPNC_DigOut_A_12:= 0; end_if;
	if TST_DigIn_13 then MPNC_DigOut_A_13:= VAL_DigIn_13; else MPNC_DigOut_A_13:= 0; end_if;
	if TST_DigIn_14 then MPNC_DigOut_A_14:= VAL_DigIn_14; else MPNC_DigOut_A_14:= 0; end_if;
	if TST_DigIn_15 then MPNC_DigOut_A_15:= VAL_DigIn_15; else MPNC_DigOut_A_15:= 0; end_if;
	if TST_DigIn_16 then MPNC_DigOut_A_16:= VAL_DigIn_16; else MPNC_DigOut_A_16:= 0; end_if;

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

	if TST_AnIn_1  then
		VALx_AnInConf_1 := VAL_AnInConf_1;
		VALx_AnInFltr_1 := VAL_AnInFltr_1;
		if VAL_AnInConf_1 <> 6 and VAL_AnInConf_1 <> 7 then
			(* Prey AnIn_1 <-- Head AnOut_1 + DigOut_5,8 + MPNC_DigOut_3,4 *) 
			case VAL_AnInConf_1 of
			1:       PLC_DigOut_8 := 1; PLC_DigOut_5 := 0; MPNC_DigOut_3 := 0; MPNC_DigOut_4 := 0; PLC_AnOutConf_1 := 1;
			2:       PLC_DigOut_8 := 0; PLC_DigOut_5 := 0; MPNC_DigOut_3 := 0; MPNC_DigOut_4 := 0; PLC_AnOutConf_1 := 2;
			3, 4, 5,
			8, 9,10: PLC_DigOut_8 := 0; PLC_DigOut_5 := 1; MPNC_DigOut_3 := 1; MPNC_DigOut_4 := 0; PLC_AnOutConf_1 := 1;
		(*	6, 7:    PLC_DigOut_8 := 0; PLC_DigOut_5 := 1; MPNC_DigOut_3 := 0; MPNC_DigOut_4 := 1; PLC_AnOutConf_1 := 1; *)
			else     PLC_DigOut_8 := 0; PLC_DigOut_5 := 0; MPNC_DigOut_3 := 0; MPNC_DigOut_4 := 0; PLC_AnOutConf_1 := 2;
			end_case;
			PLC_AnOut_1 := ValueOut(Val_AnIn_1, VAL_AnInConf_1);
			MPNC_DigOut_B_1 := false; MPNC_DigOut_B_2 := false; MPNC_DigOut_B_3 := false; MPNC_DigOut_B_4 := false;
		else 
			(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_1,2,3,4        *) 
			PLC_DigOut_8 := 0; PLC_DigOut_5 := 0; MPNC_DigOut_3 := 1; MPNC_DigOut_4 := 1; PLC_AnOutConf_1 := 2; PLC_AnOut_1 := 0;
			if VAL_AnInConf_1 = 7 and Val_AnIn_1 = 0 then
				MPNC_DigOut_B_1 := true;  MPNC_DigOut_B_2 := false; MPNC_DigOut_B_3 := false; MPNC_DigOut_B_4 := true;
			elsif VAL_AnInConf_1 = 7 and Val_AnIn_1 = 1040 then
				MPNC_DigOut_B_1 := false; MPNC_DigOut_B_2 := true;  MPNC_DigOut_B_3 := false; MPNC_DigOut_B_4 := true;
			elsif VAL_AnInConf_1 = 6 and Val_AnIn_1 = 409 then
				MPNC_DigOut_B_1 := false; MPNC_DigOut_B_2 := false; MPNC_DigOut_B_3 := true;  MPNC_DigOut_B_4 := true;
			else
				MPNC_DigOut_B_1 := false; MPNC_DigOut_B_2 := false; MPNC_DigOut_B_3 := false; MPNC_DigOut_B_4 := false;
			end_if;
		end_if;
	end_if;

	if TST_AnIn_2  then
		VALx_AnInConf_2 := VAL_AnInConf_2;
		VALx_AnInFltr_2 := VAL_AnInFltr_2;
		if VAL_AnInConf_2 <> 6 and VAL_AnInConf_2 <> 7 then
			(* Prey AnIn_2 <-- Head AnOut_2 + DigOut_6,7 + MPNC_DigOut_1,2 *) 
			case VAL_AnInConf_2 of
			1:       PLC_DigOut_7 := 1; PLC_DigOut_6 := 0; MPNC_DigOut_1 := 0; MPNC_DigOut_2 := 0; PLC_AnOutConf_2 := 1;
			2:       PLC_DigOut_7 := 0; PLC_DigOut_6 := 0; MPNC_DigOut_1 := 0; MPNC_DigOut_2 := 0; PLC_AnOutConf_2 := 2;
			3, 4, 5,
			8, 9,10: PLC_DigOut_7 := 0; PLC_DigOut_6 := 1; MPNC_DigOut_1 := 1; MPNC_DigOut_2 := 0; PLC_AnOutConf_2 := 1;
		(*	6, 7:    PLC_DigOut_7 := 0; PLC_DigOut_6 := 1; MPNC_DigOut_1 := 0; MPNC_DigOut_2 := 1; PLC_AnOutConf_2 := 1; *)
			else     PLC_DigOut_7 := 0; PLC_DigOut_6 := 0; MPNC_DigOut_1 := 0; MPNC_DigOut_2 := 0; PLC_AnOutConf_2 := 2;
			end_case;
			PLC_AnOut_2 := ValueOut(Val_AnIn_2, VAL_AnInConf_2);
			MPNC_DigOut_B_5 := false; MPNC_DigOut_B_6 := false; MPNC_DigOut_B_7 := false; MPNC_DigOut_B_8 := false;
		else
			(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_5,6,7,8        *) 
			PLC_DigOut_7 := 0; PLC_DigOut_6 := 0; MPNC_DigOut_1 := 1; MPNC_DigOut_2 := 1; PLC_AnOutConf_2 := 2; PLC_AnOut_2 := 0;
			if VAL_AnInConf_2 = 7 and Val_AnIn_2 = 0 then
				MPNC_DigOut_B_5 := true;  MPNC_DigOut_B_6 := false; MPNC_DigOut_B_7 := false; MPNC_DigOut_B_8 := true;
			elsif VAL_AnInConf_2 = 7 and Val_AnIn_2 = 1040 then
				MPNC_DigOut_B_5 := false; MPNC_DigOut_B_6 := true;  MPNC_DigOut_B_7 := false; MPNC_DigOut_B_8 := true;
			elsif VAL_AnInConf_2 = 6 and Val_AnIn_2 = 409 then
				MPNC_DigOut_B_5 := false; MPNC_DigOut_B_6 := false; MPNC_DigOut_B_7 := true;  MPNC_DigOut_B_8 := true;
			else
				MPNC_DigOut_B_5 := false; MPNC_DigOut_B_6 := false; MPNC_DigOut_B_7 := false; MPNC_DigOut_B_8 := false;
			end_if;
		end_if;
	end_if;

	if TST_AnIn_3  then
		VALx_AnInConf_3 := VAL_AnInConf_3;
		VALx_AnInFltr_3 := VAL_AnInFltr_3;
		if VAL_AnInConf_3 <> 6 and VAL_AnInConf_3 <> 7 then
			(* Prey AnIn_3 <-- Horn2 AnOut_1 + DigOut_5,8  MPNC_DigOut_7,8  *) 
			case VAL_AnInConf_3 of
			1:       VAL2_DigOut_8 := 1; VAL2_DigOut_5 := 0; MPNC_DigOut_7 := 0; MPNC_DigOut_8 := 0; VAL2_AnOutConf_1 := 1;
			2:       VAL2_DigOut_8 := 0; VAL2_DigOut_5 := 0; MPNC_DigOut_7 := 0; MPNC_DigOut_8 := 0; VAL2_AnOutConf_1 := 2;
			3, 4, 5,
			8, 9,10: VAL2_DigOut_8 := 0; VAL2_DigOut_5 := 1; MPNC_DigOut_7 := 1; MPNC_DigOut_8 := 0; VAL2_AnOutConf_1 := 1; 
		(*	6, 7:    VAL2_DigOut_8 := 0; VAL2_DigOut_5 := 1; MPNC_DigOut_7 := 0; MPNC_DigOut_8 := 1; VAL2_AnOutConf_1 := 1; *)
			else     VAL2_DigOut_8 := 0; VAL2_DigOut_5 := 0; MPNC_DigOut_7 := 0; MPNC_DigOut_8 := 0; VAL2_AnOutConf_1 := 2;
			end_case;
			VAL2_AnOut_1 := ValueOut(Val_AnIn_3, VAL_AnInConf_3);
			MPNC_DigOut_B_9 := false; MPNC_DigOut_B_10 := false; MPNC_DigOut_B_11 := false; MPNC_DigOut_B_12 := false;
		else
			(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_9,10,11,12     *) 
			VAL2_DigOut_8 := 0; VAL2_DigOut_5 := 0; MPNC_DigOut_7 := 1; MPNC_DigOut_8 := 1; VAL2_AnOutConf_1 := 2; VAL2_AnOut_1 := 0;
			if VAL_AnInConf_3 = 7 and Val_AnIn_3 = 0 then
				MPNC_DigOut_B_9 := true;  MPNC_DigOut_B_10 := false; MPNC_DigOut_B_11 := false; MPNC_DigOut_B_12 := true;
			elsif VAL_AnInConf_3 = 7 and Val_AnIn_3 = 1040 then
				MPNC_DigOut_B_9 := false; MPNC_DigOut_B_10 := true;  MPNC_DigOut_B_11 := false; MPNC_DigOut_B_12 := true;
			elsif VAL_AnInConf_3 = 6 and Val_AnIn_3 = 409 then
				MPNC_DigOut_B_9 := false; MPNC_DigOut_B_10 := false; MPNC_DigOut_B_11 := true;  MPNC_DigOut_B_12 := true;
			else
				MPNC_DigOut_B_9 := false; MPNC_DigOut_B_10 := false; MPNC_DigOut_B_11 := false; MPNC_DigOut_B_12 := false;
			end_if;
		end_if;
	end_if;

	if TST_AnIn_4  then
		VALx_AnInConf_4 := VAL_AnInConf_4;
		VALx_AnInFltr_4 := VAL_AnInFltr_4;
		if VAL_AnInConf_4 <> 6 and VAL_AnInConf_4 <> 7 then
			(* Prey AnIn_4 <-- Horn2 AnOut_2 + DigOut_6,7 + MPNC_DigOut_5,6  *) 
			case VAL_AnInConf_4 of
			1:       VAL2_DigOut_7 := 1; VAL2_DigOut_6 := 0; MPNC_DigOut_5 := 0; MPNC_DigOut_6 := 0; VAL2_AnOutConf_2 := 1;
			2:       VAL2_DigOut_7 := 0; VAL2_DigOut_6 := 0; MPNC_DigOut_5 := 0; MPNC_DigOut_6 := 0; VAL2_AnOutConf_2 := 2;
			3, 4, 5,
			8, 9,10: VAL2_DigOut_7 := 0; VAL2_DigOut_6 := 1; MPNC_DigOut_5 := 1; MPNC_DigOut_6 := 0; VAL2_AnOutConf_2 := 1;
		(*	6, 7:    VAL2_DigOut_7 := 0; VAL2_DigOut_6 := 1; MPNC_DigOut_5 := 0; MPNC_DigOut_6 := 1; VAL2_AnOutConf_2 := 1; *)
			else     VAL2_DigOut_7 := 0; VAL2_DigOut_6 := 0; MPNC_DigOut_5 := 0; MPNC_DigOut_6 := 0; VAL2_AnOutConf_2 := 2;
			end_case;
			VAL2_AnOut_2 := ValueOut(Val_AnIn_4, VAL_AnInConf_4);
			MPNC_DigOut_B_13 := false; MPNC_DigOut_B_14 := false; MPNC_DigOut_B_15 := false; MPNC_DigOut_B_16 := false;
		else
			(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_13,14,15,16    *) 
			VAL2_DigOut_7 := 0; VAL2_DigOut_6 := 0; MPNC_DigOut_5 := 1; MPNC_DigOut_6 := 1; VAL2_AnOutConf_2 := 2; VAL2_AnOut_2 := 0;
			if VAL_AnInConf_4 = 7 and Val_AnIn_4 = 0 then
				MPNC_DigOut_B_13 := true;  MPNC_DigOut_B_14 := false; MPNC_DigOut_B_15 := false; MPNC_DigOut_B_16 := true;
			elsif VAL_AnInConf_4 = 7 and Val_AnIn_4 = 1040 then
				MPNC_DigOut_B_13 := false; MPNC_DigOut_B_14 := true;  MPNC_DigOut_B_15 := false; MPNC_DigOut_B_16 := true;
			elsif VAL_AnInConf_4 = 6 and Val_AnIn_4 = 409 then
				MPNC_DigOut_B_13 := false; MPNC_DigOut_B_14 := false; MPNC_DigOut_B_15 := true;  MPNC_DigOut_B_16 := true;
			else
				MPNC_DigOut_B_13 := false; MPNC_DigOut_B_14 := false; MPNC_DigOut_B_15 := false; MPNC_DigOut_B_16 := false;
			end_if;
		end_if;
	end_if;

	if TST_AnIn_5  then
		VALx_AnInConf_5 := VAL_AnInConf_5;
		VALx_AnInFltr_5 := VAL_AnInFltr_5;
		(* Prey AnIn_5 <-- Horn2 AnOut_4 *) 
		VAL2_AnOutConf_4 := VAL_AnInConf_5;
		VAL2_AnOut_4 := ValueOut(Val_AnIn_5, VAL_AnInConf_5);
	end_if;

	(* TPLC100 AnIn_5..12 *)
	if TST_AnIn_6  then VALx_AnInConf_6  := VAL_AnInConf_6 ; end_if;
	if TST_AnIn_7  then VALx_AnInConf_7  := VAL_AnInConf_7 ; end_if;
	if TST_AnIn_8  then VALx_AnInConf_8  := VAL_AnInConf_8 ; end_if;
	if TST_AnIn_9  then VALx_AnInConf_9  := VAL_AnInConf_9 ; end_if;
	if TST_AnIn_10 then VALx_AnInConf_10 := VAL_AnInConf_10; end_if;
	if TST_AnIn_11 then VALx_AnInConf_11 := VAL_AnInConf_11; end_if;
	if TST_AnIn_12 then VALx_AnInConf_12 := VAL_AnInConf_12; end_if;

	if TST_AnOut_1  then
		VALx_AnOut_1 := VAL_AnOut_1;
		VALx_AnOutConf_1 := VAL_AnOutConf_1;
		(* --> Horn2 AI1 + DO4 *)
		case VAL_AnOutConf_1 of
		1: VAL2_DigOut_3 := 1; VAL2_AnInConf_1 := 1; (* [mA] 4..20 *)
		2: VAL2_DigOut_3 := 0; VAL2_AnInConf_1 := 2; (* [V] 0..10 *)
		3: VAL2_DigOut_3 := 0; VAL2_AnInConf_1 := 2; (* [%] PWM --> [V] *)
		end_case;
		VAL2_AnInFltr_1 := 10;
	end_if;

	if TST_AnOut_2  then
		VALx_AnOut_2 := VAL_AnOut_2;
		VALx_AnOutConf_2 := VAL_AnOutConf_2;
		(* --> Horn2 AI2 + DO3 *)	
		case VAL_AnOutConf_2 of
		1: VAL2_DigOut_4 := 1; VAL2_AnInConf_2 := 1; (* [mA] 4..20 *)
		2: VAL2_DigOut_4 := 0; VAL2_AnInConf_2 := 2; (* [V] 0..10 *)
		3: VAL2_DigOut_4 := 0; VAL2_AnInConf_2 := 2; (* [%] PWM --> [V] *)
		end_case;
		VAL2_AnInFltr_2 := 10;
	end_if;

	if TST_AnOut_3  then
		VALx_AnOut_3 := VAL_AnOut_3;
		VALx_AnOutConf_3 := VAL_AnOutConf_3;
		(* --> Head/MPNC AI1 *) 
		case VAL_AnOutConf_3 of
		1: MPNC_AnInConf_1 := 1; (* [mA] 4..20 *)
		2: MPNC_AnInConf_1 := 2; (* [V] 0..10 *)
		3: MPNC_AnInConf_1 := 2; (* [%] PWM --> [V] *)
		end_case;
	end_if;

	if TST_AnOut_4  then
		VALx_AnOut_4 := VAL_AnOut_4;
		VALx_AnOutConf_4 := VAL_AnOutConf_4;
		(* --> Head/MPNC AI2 *) 
		case VAL_AnOutConf_4 of
		1: MPNC_AnInConf_2 := 1; (* [mA] 4..20 *)
		2: MPNC_AnInConf_2 := 2; (* [V] 0..10 *)
		3: MPNC_AnInConf_2 := 2; (* [%] PWM --> [V] *)
		end_case;
	end_if;


	if TST_Tamb  then
		;
	end_if;

	if TST_RPM  then
		(* <-- Horn2 AO3 PWM *) 
		VAL2_AnOutConf_3 := 3; (* PWM *)
		VAL2_AnOut_3 := UINT_TO_INT(VAL_RPM / 10); (* different fixed points *)
	end_if;

	if TST_FWrevision  then
		;
	end_if;
	if TST_HWconfig then
		;
	end_if;

	(* RTUS: Head.RTU1 --> Prey.RTUS *)
	if TST_RTUS_WR then VALx_RTUS_WR := VAL_RTUS_WR; end_if;
	if TST_RTUS_RD then (* RTU_RTU1_WR := VAL_RTUS_RD; *); end_if;

	(* RTU1: Prey.RTU1 --> Horn.RTUS *)
	if TST_RTU1_WR then VALx_RTU1_WR := VAL_RTU1_WR; end_if;
	if TST_RTU1_RD then VAL2_RTUS_WR := VAL_RTU1_RD; end_if;

	(* RTU3: Prey.RTU3 <--> MPNC + short-circuit DigOut_1->DigIn_2 *)
	if TST_RTU3_WR then VALx_RTU3_WR := VAL_RTU3_WR; end_if;
	if TST_RTU3_RD then ; end_if;

	(* CAN1: Prey.CAN1 <--> MPNC010 + short-circuit DigOut_1->DigIn_1 *)
	if TST_CAN1_WR then VALx_CAN1_WR := VAL_CAN1_WR; end_if;
	if TST_CAN1_RD then ; end_if;

	(* only from the testing equipment *)
	if TST_VCC_set then
		(* --> Head AO3 V *) 
		PLC_AnOutConf_3 := 2; (* 0..10 V *)
		PLC_AnOut_3 := VAL_VCC_set; (* FIXME: conversion ? *)
	end_if;

	if TST_mA_max then
		(* --> Head AO4 V *) 
		PLC_AnOutConf_4 := 2; (* 0..10 V *)
		PLC_AnOut_4 := VAL_mA_max; (* FIXME: conversion ? *)
	end_if;

	if TST_VCC_fbk then
		(* --> Head AI1 V *) 
		PLC_AnInConf_1 := 2; (* 0..10 V *)
	end_if;

	if TST_mA_fbk then
		(* --> Head AI2 V *) 
		PLC_AnInConf_2 := 2; (* 0..10 V *)
	end_if;

END_FUNCTION
