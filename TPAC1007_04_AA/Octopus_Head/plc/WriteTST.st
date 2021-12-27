(*[[
]]*)
FUNCTION WriteTST
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	(* we test the DigIn 1..16 by the MPNC 16DO module *)
 	TSTx_DigIn_1 := TST_DigIn_1;
	TSTx_DigIn_2 := TST_DigIn_2;
	TSTx_DigIn_3 := TST_DigIn_3;
	TSTx_DigIn_4 := TST_DigIn_4;
	TSTx_DigIn_5 := TST_DigIn_5;
	TSTx_DigIn_6 := TST_DigIn_6;
	TSTx_DigIn_7 := TST_DigIn_7;
	TSTx_DigIn_8 := TST_DigIn_8;
	TSTx_DigIn_9 := TST_DigIn_9;
	TSTx_DigIn_10:= TST_DigIn_10;
	TSTx_DigIn_11:= TST_DigIn_11;
	TSTx_DigIn_12:= TST_DigIn_12;
	TSTx_DigIn_13:= TST_DigIn_13;
	TSTx_DigIn_14:= TST_DigIn_14;
	TSTx_DigIn_15:= TST_DigIn_15;
	TSTx_DigIn_16:= TST_DigIn_16;
    (* no TST2_DigIn_* *)

    (* we test the DigOut 1..16 by the MPNC 16DI module *)
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
    (* no TST2_DigOut_* *)

	(* Prey AnIn_1 <-- Head AnOut_1 + DigOut_5,8 + MPNC_DigOut_3,4 *) 
	(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_1,2,3,4        *) 
	TSTx_AnIn_1 := TST_AnIn_1;

    (* Prey AnIn_2 <-- Head AnOut_2 + DigOut_6,7 + MPNC_DigOut_1,2 *) 
	(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_5,6,7,8        *) 
	TSTx_AnIn_2 := TST_AnIn_2;

    (* Prey AnIn_3 <-- Horn2 AnOut_1 + DigOut_5,8 + MPNC_DigOut_7,8  *) 
	(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_9,10,11,12     *) 
	TSTx_AnIn_3 := TST_AnIn_3;
    TST2_AnOut_1 := TST_AnIn_3;
    TST2_DigOut_5 := TRUE;
    TST2_DigOut_8 := TRUE;

	(* Prey AnIn_4 <-- Horn2 AnOut_2 + DigOut_6,7 + MPNC_DigOut_5,6  *) 
	(*    (Pt100)  <-- resistenze   + MPNC_DigOut_B_13,14,15,16    *) 
	TSTx_AnIn_4 := TST_AnIn_4;
    TST2_AnOut_2 := TST_AnIn_4;
    TST2_DigOut_6 := TRUE;
    TST2_DigOut_7 := TRUE;

	(* Prey AnIn_5 <-- Horn2 AnOut_4 (only TPAC1007_04_AB) *)
	TSTx_AnIn_5 := TST_AnIn_5;
    TST2_AnOut_4:= TST_AnIn_5;

	(* TPLC100 AnIn_5..12 *)
	TSTx_AnIn_5 := TST_AnIn_5;
	TSTx_AnIn_6 := TST_AnIn_6;
	TSTx_AnIn_7 := TST_AnIn_7;
	TSTx_AnIn_8 := TST_AnIn_8;
	TSTx_AnIn_9 := TST_AnIn_9;
	TSTx_AnIn_10:= TST_AnIn_10;
	TSTx_AnIn_11:= TST_AnIn_11;
	TSTx_AnIn_12:= TST_AnIn_12;

    (* we test the AnOut 1..2 by both the local AnIn 1..2 and the Horn TPAC1007_4AA AnIn 1..2 and local DigOut 3..4 *)
    TSTx_AnOut_1 := TST_AnOut_1;
    TST2_AnIn_1 := TST_AnOut_1;
    TST2_DigOut_3 := TRUE;

    TSTx_AnOut_2 := TST_AnOut_2;
    TST2_AnIn_2 := TST_AnOut_2;
    TST2_DigOut_4 := TRUE;

    (* we test the AnOut 3..4 by the by the MPNC internal 2AI *)
    TSTx_AnOut_3 := TST_AnOut_3;
    TSTx_AnOut_4 := TST_AnOut_4;

    (* we test the Others I/O ...  *)
    TSTx_Tamb := TST_Tamb; (* or (TST_AnIn_x and VAL_AnInConf_x = 3) =---> in the recipes !! *)
    TSTx_RPM := TST_RPM;
    TSTx_FWrevision := TST_FWrevision;
    TSTx_HWconfig := TST_HWconfig;
    TST2_AnOut_3 := TST_RPM;

	(* RTUS: Head.RTU1 --> Prey.RTUS *)
    TSTx_RTUS_WR := TST_RTUS_WR;
    TSTx_RTUS_RD := TST_RTUS_RD;

	(* RTU1: Prey.RTU1 --> Horn.RTUS *)
    TSTx_RTU1_WR := TST_RTU1_WR;
	TST2_RTUS_RD := TST_RTU1_WR;

    TSTx_RTU1_RD := TST_RTU1_RD;
	TST2_RTUS_WR := TST_RTU1_RD;

	(* RTU3: Prey.RTU3 <--> MPNC + short-circuit DigOut_1->DigIn_2 *)
	TSTx_RTU3_WR := TST_RTU3_WR;
	TSTx_RTU3_RD := TST_RTU3_RD;

	(* CAN1: Prey.CAN1 <--> MPNC010 + short-circuit DigOut_1->DigIn_1 *)
    TSTx_CAN1_WR := TST_CAN1_WR;
    TSTx_CAN1_RD := TST_CAN1_RD;

END_FUNCTION
