(*[[
]]*)
FUNCTION ifTST_readVAL_writePLC
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

    if (TST_DigIn_9 ) then RES_DigIn_9 := 0; end_if;
    if (TST_DigIn_10) then RES_DigIn_10:= 0; end_if;
    if (TST_DigIn_11) then RES_DigIn_11:= 0; end_if;
    if (TST_DigIn_12) then RES_DigIn_12:= 0; end_if;

    if (TST_DigOut_1) then PLC_DigOut_1 := VAL_DigOut_1; end_if;
    if (TST_DigOut_2) then PLC_DigOut_2 := VAL_DigOut_2; end_if;
    if (TST_DigOut_3) then PLC_DigOut_3 := VAL_DigOut_3; end_if;
    if (TST_DigOut_4) then PLC_DigOut_4 := VAL_DigOut_4; end_if;
    if (TST_DigOut_5) then PLC_DigOut_5 := VAL_DigOut_5; end_if;
    if (TST_DigOut_6) then PLC_DigOut_6 := VAL_DigOut_6; end_if;
    if (TST_DigOut_7) then PLC_DigOut_7 := VAL_DigOut_7; end_if;
    if (TST_DigOut_8) then PLC_DigOut_8 := VAL_DigOut_8; end_if;

    if (TST_AnIn_1  ) then PLC_AnInConf_1 := VAL_AnInConf_1; PLC_AnIn1Filter := VAL_AnInFltr_1; RES_AnIn_1 := 0; end_if; 
    if (TST_AnIn_2  ) then PLC_AnInConf_2 := VAL_AnInConf_2; PLC_AnIn2Filter := VAL_AnInFltr_2; RES_AnIn_2 := 0; end_if;

    if (TST_AnOut_1 ) then PLC_AnOutConf_1 := VAL_AnOutConf_1; PLC_AnOut_1 := VAL_AnOut_1; end_if;
    if (TST_AnOut_2 ) then PLC_AnOutConf_2 := VAL_AnOutConf_2; PLC_AnOut_2 := VAL_AnOut_2; end_if;
	(* NB: se also RPM @ 50.0 Hz generation using DigOut_1 in Testing.st *)		
    if (TST_AnOut_3 ) then PLC_AnOutConf_3 := VAL_AnOutConf_3; PLC_AnOut_3 := VAL_AnOut_3; end_if;
    if (TST_AnOut_4 ) then PLC_AnOutConf_4 := VAL_AnOutConf_4; PLC_AnOut_4 := VAL_AnOut_4; end_if;
	
	if (TST_Tamb      ) then RES_Tamb := 0; end_if;
    if (TST_FWrevision) then RES_FWrevision := 0; end_if;
    if (TST_HWconfig  ) then RES_HWconfig := 0; end_if;

	if (TST_RTUS_WR   ) then RTU_RTUS_WR := VAL_RTUS_WR; end_if;
	if (TST_RTUS_RD   ) then ; end_if;

END_FUNCTION
