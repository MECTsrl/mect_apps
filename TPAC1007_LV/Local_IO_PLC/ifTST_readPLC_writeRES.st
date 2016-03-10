(*[[
]]*)
FUNCTION ifTST_readPLC_writeRES
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

    if (TST_DigIn_1   ) then RES_DigIn_1 := PLC_DigIn_1; end_if;
    if (TST_DigIn_2   ) then RES_DigIn_2 := PLC_DigIn_2; end_if;
    if (TST_DigIn_3   ) then RES_DigIn_3 := PLC_DigIn_3; end_if;
    if (TST_DigIn_4   ) then RES_DigIn_4 := PLC_DigIn_4; end_if;
    if (TST_DigIn_5   ) then RES_DigIn_5 := PLC_DigIn_5; end_if;
    if (TST_DigIn_6   ) then RES_DigIn_6 := PLC_DigIn_6; end_if;
    if (TST_DigIn_7   ) then RES_DigIn_7 := PLC_DigIn_7; end_if;
    if (TST_DigIn_8   ) then RES_DigIn_8 := PLC_DigIn_8; end_if;

    if (TST_DigIn_9   ) then RES_DigIn_9 := PLC_DigIn_9; end_if;
    if (TST_DigIn_10  ) then RES_DigIn_10 := PLC_DigIn_10; end_if;
    if (TST_DigIn_11  ) then RES_DigIn_11 := PLC_DigIn_11; end_if;
    if (TST_DigIn_12  ) then RES_DigIn_12 := PLC_DigIn_12; end_if;

    if (TST_DigOut_1  ) then ; end_if;
    if (TST_DigOut_2  ) then ; end_if;
    if (TST_DigOut_3  ) then ; end_if;
    if (TST_DigOut_4  ) then ; end_if;
    if (TST_DigOut_5  ) then ; end_if;
    if (TST_DigOut_6  ) then ; end_if;
    if (TST_DigOut_7  ) then ; end_if;
    if (TST_DigOut_8  ) then ; end_if;

   
    if (TST_FWrevision) then RES_FWrevision := PLC_FWrevision; end_if;
    if (TST_HWconfig  ) then RES_HWconfig := PLC_HWconfig; end_if;

	if (TST_RTU1_WR   ) then RES_RTU1_WR := UINT_TO_BOOL(RTU_RTU1_RD); end_if;
	if (TST_RTU1_RD   ) then RES_RTU1_RD := UINT_TO_BOOL(RTU_RTU1_RD); end_if;

	if (TST_RTU3_WR   ) then RES_RTU3_WR := UINT_TO_BOOL(RTU_RTU3_RD); end_if;
	if (TST_RTU3_RD   ) then RES_RTU3_RD := UINT_TO_BOOL(RTU_RTU3_RD); end_if;

END_FUNCTION
