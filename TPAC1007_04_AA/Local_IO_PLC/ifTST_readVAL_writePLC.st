(*[[
]]*)
FUNCTION ifTST_readVAL_writePLC
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	if (TST_DigIn_1 ) then PLC_DigDir_1 := 0; RES_DigIn_1 := 0; end_if;
    if (TST_DigIn_2 ) then PLC_DigDir_2 := 0; RES_DigIn_2 := 0; end_if;
    if (TST_DigIn_3 ) then PLC_DigDir_3 := 0; RES_DigIn_3 := 0; end_if;
    if (TST_DigIn_4 ) then PLC_DigDir_4 := 0; RES_DigIn_4 := 0; end_if;
    if (TST_DigIn_5 ) then PLC_DigDir_5 := 0; RES_DigIn_5 := 0; end_if;
    if (TST_DigIn_6 ) then PLC_DigDir_6 := 0; RES_DigIn_6 := 0; end_if;
    if (TST_DigIn_7 ) then PLC_DigDir_7 := 0; RES_DigIn_7 := 0; end_if;
    if (TST_DigIn_8 ) then PLC_DigDir_8 := 0; RES_DigIn_8 := 0; end_if;

    if (TST_DigIn_9 ) then RES_DigIn_9 := 0; end_if;
    if (TST_DigIn_10) then RES_DigIn_10:= 0; end_if;
    if (TST_DigIn_11) then RES_DigIn_11:= 0; end_if;
    if (TST_DigIn_12) then RES_DigIn_12:= 0; end_if;

    if (TST_DigOut_1) then PLC_DigDir_1 := 1; PLC_DigOut_1 := VAL_DigOut_1; end_if;
    if (TST_DigOut_2) then PLC_DigDir_2 := 1; PLC_DigOut_2 := VAL_DigOut_2; end_if;
    if (TST_DigOut_3) then PLC_DigDir_3 := 1; PLC_DigOut_3 := VAL_DigOut_3; end_if;
    if (TST_DigOut_4) then PLC_DigDir_4 := 1; PLC_DigOut_4 := VAL_DigOut_4; end_if;
    if (TST_DigOut_5) then PLC_DigDir_5 := 1; PLC_DigOut_5 := VAL_DigOut_5; end_if;
    if (TST_DigOut_6) then PLC_DigDir_6 := 1; PLC_DigOut_6 := VAL_DigOut_6; end_if;
    if (TST_DigOut_7) then PLC_DigDir_7 := 1; PLC_DigOut_7 := VAL_DigOut_7; end_if;
    if (TST_DigOut_8) then PLC_DigDir_8 := 1; PLC_DigOut_8 := VAL_DigOut_8; end_if;

    if (TST_AnIn_1  ) then PLC_AnInConf_1 := VAL_AnInConf_1; PLC_AnIn1Filter := VAL_AnInFltr_1; RES_AnIn_1 := 0; end_if; 
    if (TST_AnIn_2  ) then PLC_AnInConf_2 := VAL_AnInConf_2; PLC_AnIn2Filter := VAL_AnInFltr_2; RES_AnIn_2 := 0; end_if;

    if (TST_AnOut_1 ) then PLC_AnOutConf_1 := VAL_AnOutConf_1; PLC_AnOut_1 := VAL_AnOut_1; end_if;
    if (TST_AnOut_2 ) then PLC_AnOutConf_2 := VAL_AnOutConf_2; PLC_AnOut_2 := VAL_AnOut_2; end_if;
    if (TST_AnOut_3 ) then PLC_AnOutConf_3 := VAL_AnOutConf_3; PLC_AnOut_3 := VAL_AnOut_3; end_if;
    if (TST_AnOut_4 ) then PLC_AnOutConf_4 := VAL_AnOutConf_4; PLC_AnOut_4 := VAL_AnOut_4; end_if;

    if (TST_Tamb      ) then RES_Tamb := 0; end_if;
    if (TST_FWrevision) then RES_FWrevision := 0; end_if;
    if (TST_HWconfig  ) then RES_HWconfig := 0; end_if;

END_FUNCTION
