(*[[
]]*)
FUNCTION ifTST_readVAL_writePLC
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	if (TST_DigIn_1 ) then RES_DigIn_1 := 0; end_if;
    if (TST_DigIn_2 ) then RES_DigIn_2 := 0; end_if;
    if (TST_DigIn_3 ) then RES_DigIn_3 := 0; end_if;
    if (TST_DigIn_4 ) then RES_DigIn_4 := 0; end_if;

    if (TST_DigOut_1) then PLC_DigOut_1 := VAL_DigOut_1; end_if;
    if (TST_DigOut_2) then PLC_DigOut_2 := VAL_DigOut_2; end_if;
    if (TST_DigOut_3) then PLC_DigOut_3 := VAL_DigOut_3; end_if;
    if (TST_DigOut_4) then PLC_DigOut_4 := VAL_DigOut_4; end_if;
    if (TST_DigOut_5) then PLC_DigOut_5 := VAL_DigOut_5; end_if;
    if (TST_DigOut_6) then PLC_DigOut_6 := VAL_DigOut_6; end_if;
    if (TST_DigOut_7) then PLC_DigOut_7 := VAL_DigOut_7; end_if;
    if (TST_DigOut_8) then PLC_DigOut_8 := VAL_DigOut_8; end_if;

    if (TST_AnIn_1  ) then configAnIn(1 , VAL_AnInConf_1 , VAL_AnInFltr_1 ); RES_AnIn_1  := 0; end_if; 
    if (TST_AnIn_2  ) then configAnIn(2 , VAL_AnInConf_2 , VAL_AnInFltr_2 ); RES_AnIn_2  := 0; end_if;
    if (TST_AnIn_3  ) then configAnIn(3 , VAL_AnInConf_3 , VAL_AnInFltr_3 ); RES_AnIn_3  := 0; end_if; 
    if (TST_AnIn_4  ) then configAnIn(4 , VAL_AnInConf_4 , VAL_AnInFltr_4 ); RES_AnIn_4  := 0; end_if;

    if (TST_AnIn_5  ) then configAnIn(5 , VAL_AnInConf_5 , VAL_AnInFltr_5 ); RES_AnIn_5  := 0; end_if; 
    if (TST_AnIn_6  ) then configAnIn(6 , VAL_AnInConf_6 , VAL_AnInFltr_6 ); RES_AnIn_6  := 0; end_if;
    if (TST_AnIn_7  ) then configAnIn(7 , VAL_AnInConf_7 , VAL_AnInFltr_7 ); RES_AnIn_7  := 0; end_if; 
    if (TST_AnIn_8  ) then configAnIn(8 , VAL_AnInConf_8 , VAL_AnInFltr_8 ); RES_AnIn_8  := 0; end_if;
    if (TST_AnIn_9  ) then configAnIn(9 , VAL_AnInConf_9 , VAL_AnInFltr_9 ); RES_AnIn_9  := 0; end_if; 
    if (TST_AnIn_10 ) then configAnIn(10, VAL_AnInConf_10, VAL_AnInFltr_10); RES_AnIn_10 := 0; end_if;
    if (TST_AnIn_11 ) then configAnIn(11, VAL_AnInConf_11, VAL_AnInFltr_11); RES_AnIn_11 := 0; end_if; 
    if (TST_AnIn_12 ) then configAnIn(12, VAL_AnInConf_12, VAL_AnInFltr_12); RES_AnIn_12 := 0; end_if;

    if (TST_AnOut_1 ) then configAnOut(1, VAL_AnOutConf_1); PLC_AnOut_1 := VAL_AnOut_1; end_if;
    if (TST_AnOut_2 ) then configAnOut(2, VAL_AnOutConf_2); PLC_AnOut_2 := VAL_AnOut_2; end_if;

    if (TST_Tamb      ) then RES_Tamb := 0; end_if;
	(* Vcc *)

	if (TST_RTUS_WR   ) then FBS_RTUS_WR := VAL_RTUS_WR; end_if;
	if (TST_RTUS_RD   ) then ; end_if;
	if (TST_RTU1_WR   ) then FBS_RTU1_WR := VAL_RTU1_WR; end_if;
	if (TST_RTU1_RD   ) then ; end_if;
	if (TST_RTU3_WR   ) then FBS_RTU3_WR := VAL_RTU3_WR; end_if;
	if (TST_RTU3_RD   ) then ; end_if;
	if (TST_CAN1_WR   ) then FBS_CAN1_WR := VAL_CAN1_WR; end_if;
	if (TST_CAN1_RD   ) then ; end_if;

END_FUNCTION
