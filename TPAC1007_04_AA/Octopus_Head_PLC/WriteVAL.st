(*[[
]]*)
FUNCTION WriteVAL
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

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
		(* <-- Head AO1 + DO6 + DO8 *) 
		PLC_DigDir_6 := 1;
		PLC_DigDir_8 := 1;
		case VAL_AnInConf_1 of
		1:       PLC_DigOut_8 := 1; PLC_DigOut_6 := 0; PLC_AnOutConf_1 := VAL_AnInConf_1; PLC_AnOut_1 := VAL_AnIn_1 / 10;
		2:       PLC_DigOut_8 := 0; PLC_DigOut_6 := 0; PLC_AnOutConf_1 := VAL_AnInConf_1; PLC_AnOut_1 := VAL_AnIn_1 / 10;
		3, 4, 5: PLC_DigOut_8 := 0; PLC_DigOut_6 := 1; PLC_AnOutConf_1 := 2; PLC_AnOut_1 := 0;
		6, 7:    PLC_DigOut_8 := 0; PLC_DigOut_6 := 1; PLC_AnOutConf_2 := 2; PLC_AnOut_2 := 0;
		else     PLC_DigOut_8 := 0; PLC_DigOut_6 := 0; PLC_AnOutConf_2 := 2; PLC_AnOut_2 := 0;
		end_case;
	end_if;

	if TST_AnIn_2  then
		VALx_AnInConf_2 := VAL_AnInConf_2;
		VALx_AnInFltr_2 := VAL_AnInFltr_2;
		(* <-- Head AO2 + DO5 + DO7 *) 
		PLC_DigDir_5 := 1;
		PLC_DigDir_7 := 1;
		case VAL_AnInConf_2 of
		1:       PLC_DigOut_7 := 1; PLC_DigOut_5 := 0; PLC_AnOutConf_2 := VAL_AnInConf_2; PLC_AnOut_2 := VAL_AnIn_2 / 10;
		2:       PLC_DigOut_7 := 0; PLC_DigOut_5 := 0; PLC_AnOutConf_2 := VAL_AnInConf_2; PLC_AnOut_2 := VAL_AnIn_2 / 10;
		3, 4, 5: PLC_DigOut_7 := 0; PLC_DigOut_5 := 1; PLC_AnOutConf_2 := 2; PLC_AnOut_2 := 0;
		6, 7:    PLC_DigOut_7 := 0; PLC_DigOut_5 := 1; PLC_AnOutConf_2 := 2; PLC_AnOut_2 := 0;
		else     PLC_DigOut_7 := 0; PLC_DigOut_5 := 0; PLC_AnOutConf_2 := 2; PLC_AnOut_2 := 0;
		end_case;
	end_if;

	if TST_AnIn_3  then
		VALx_AnInConf_3 := VAL_AnInConf_3;
		VALx_AnInFltr_3 := VAL_AnInFltr_3;
		(* <-- Horn2 AO1 + DO6 + DO8 *) 
		case VAL_AnInConf_3 of
		1:       VAL2_DigOut_8 := 1; VAL2_DigOut_6 := 0; VAL2_AnOutConf_1 := VAL_AnInConf_3; VAL2_AnOut_1 := VAL_AnIn_3 / 10;
		2:       VAL2_DigOut_8 := 0; VAL2_DigOut_6 := 0; VAL2_AnOutConf_1 := VAL_AnInConf_3; VAL2_AnOut_1 := VAL_AnIn_3 / 10;
		3, 4, 5: VAL2_DigOut_8 := 0; VAL2_DigOut_6 := 1; VAL2_AnOutConf_1 := 2; VAL2_AnOut_1 := 0;
		6, 7:    VAL2_DigOut_8 := 0; VAL2_DigOut_6 := 1; VAL2_AnOutConf_1 := 2; VAL2_AnOut_1 := 0;
		else     VAL2_DigOut_8 := 0; VAL2_DigOut_6 := 0; VAL2_AnOutConf_1 := 2; VAL2_AnOut_1 := 0;
		end_case;
	end_if;

	if TST_AnIn_4  then
		VALx_AnInConf_4 := VAL_AnInConf_4;
		VALx_AnInFltr_4 := VAL_AnInFltr_4;
		(* <-- Horn2 AO2 + DO5 + DO7 *) 
		case VAL_AnInConf_4 of
		1:       VAL2_DigOut_7 := 1; VAL2_DigOut_5 := 0; VAL2_AnOutConf_2 := VAL_AnInConf_4; VAL2_AnOut_2 := VAL_AnIn_4 / 10;
		2:       VAL2_DigOut_7 := 0; VAL2_DigOut_5 := 0; VAL2_AnOutConf_2 := VAL_AnInConf_4; VAL2_AnOut_2 := VAL_AnIn_4 / 10;
		3, 4, 5: VAL2_DigOut_7 := 0; VAL2_DigOut_5 := 1; VAL2_AnOutConf_2 := 2; VAL2_AnOut_2 := 0;
		6, 7:    VAL2_DigOut_7 := 0; VAL2_DigOut_5 := 1; VAL2_AnOutConf_2 := 2; VAL2_AnOut_2 := 0;
		else     VAL2_DigOut_7 := 0; VAL2_DigOut_5 := 0; VAL2_AnOutConf_2 := 2; VAL2_AnOut_2 := 0;
		end_case;
	end_if;

	if TST_AnIn_5  then
		VALx_AnInConf_5 := VAL_AnInConf_5;
		VALx_AnInFltr_5 := VAL_AnInFltr_5;
		(* <-- Head/TPLC005 AO1 *) 
		RTU_AnOut_1 := VAL_AnIn_5 / 10;
		(* <-- Horn2 AO4 V : double for TPAC1007_4AB *)
		VAL2_AnOutConf_4 := VAL_AnInConf_5;
		VAL2_AnOut_4 := VAL_AnIn_5 / 10;
	end_if;
	if TST_AnIn_6  then
		VALx_AnInConf_6 := VAL_AnInConf_6;
		VALx_AnInFltr_6 := VAL_AnInFltr_6;
		(* <-- Head/TPLC005 AO2 *) 
		RTU_AnOut_2 := VAL_AnIn_6 / 10;
	end_if;
	if TST_AnIn_7  then
		VALx_AnInConf_7 := VAL_AnInConf_7;
		VALx_AnInFltr_7 := VAL_AnInFltr_7;
		(* <-- Head/TPLC005 AO3 *) 
		PLC_AnOut_3 := VAL_AnIn_7 / 10;
	end_if;
	if TST_AnIn_8  then
		VALx_AnInConf_8 := VAL_AnInConf_8;
		VALx_AnInFltr_8 := VAL_AnInFltr_8;
		(* <-- Head/TPLC005 AO4 *) 
		RTU_AnOut_4 := VAL_AnIn_8 / 10;
	end_if;
	if TST_AnIn_9  then
		VALx_AnInConf_9 := VAL_AnInConf_9;
		VALx_AnInFltr_9 := VAL_AnInFltr_9;
		(* <-- Head/TPLC005 AO5*) 
		RTU_AnOut_5 := VAL_AnIn_9 / 10;
	end_if;
	if TST_AnIn_10 then
		VALx_AnInConf_10:= VAL_AnInConf_10;
		VALx_AnInFltr_10:= VAL_AnInFltr_10;
		(* <-- Head/TPLC005 AO6*) 
		RTU_AnOut_6 := VAL_AnIn_10 / 10;
	end_if;
	if TST_AnIn_11 then
		VALx_AnInConf_11:= VAL_AnInConf_11;
		VALx_AnInFltr_11:= VAL_AnInFltr_11;
		(* <-- Head/TPLC005 AO7*) 
		RTU_AnOut_7 := VAL_AnIn_11 / 10;
	end_if;
	if TST_AnIn_12 then
		VALx_AnInConf_12:= VAL_AnInConf_12;
		VALx_AnInFltr_12:= VAL_AnInFltr_12;
		(* <-- Head/TPLC005 AO8*) 
		RTU_AnOut_8 := VAL_AnIn_12 / 10;
	end_if;

	if TST_AnOut_1  then
		VALx_AnOut_1 := VAL_AnOut_1;
		VALx_AnOutConf_1 := VAL_AnOutConf_1;
		(* --> Horn2 AI1 + DO4 *) 
		VAL2_AnInConf_1 := VAL_AnOutConf_1;
		VAL2_AnInFltr_1 := 16; 
		case VAL_AnOutConf_1 of
		1: VAL2_DigOut_3 := 1;
		2: VAL2_DigOut_3 := 0;
		end_case;
	end_if;

	if TST_AnOut_2  then
		VALx_AnOut_2 := VAL_AnOut_2;
		VALx_AnOutConf_2 := VAL_AnOutConf_2;
		(* --> Horn2 AI2 + DO3 *) 
		VAL2_AnInConf_2 := VAL_AnOutConf_2;
		VAL2_AnInFltr_2 := 16; 
		case VAL_AnOutConf_2 of
		1: VAL2_DigOut_4 := 1;
		2: VAL2_DigOut_4 := 0;
		end_case;
	end_if;

	if TST_AnOut_3  then
		VALx_AnOut_3 := VAL_AnOut_3;
		VALx_AnOutConf_3 := VAL_AnOutConf_3;
		(* --> Head/TPLC005 AI1 *) 
		PLC_AnInConf_1 := VAL_AnOutConf_3;
	end_if;

	if TST_AnOut_4  then
		VALx_AnOut_4 := VAL_AnOut_4;
		VALx_AnOutConf_4 := VAL_AnOutConf_4;
		(* --> Head/TPLC005 AI2 *) 
		PLC_AnInConf_2 := VAL_AnOutConf_4;
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

	(* RTU3: Prey.RTU3 <--> TPLC005 *)
	if TST_RTU3_WR then VALx_RTU3_WR := VAL_RTU3_WR; end_if;
	if TST_RTU3_RD then ; end_if;

	(* CAN1: Prey.CAN1 <--> MPNC010 *)
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
