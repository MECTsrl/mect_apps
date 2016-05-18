(*[[
]]*)
FUNCTION ifTST_readPLC_writeRES
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

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

    if (TST_AnIn_1    ) then RES_AnIn_1 := PLC_AnIn_1; end_if;
    if (TST_AnIn_2    ) then RES_AnIn_2 := PLC_AnIn_2; end_if;

    if (TST_AnOut_1   ) then ; end_if;
    if (TST_AnOut_2   ) then ; end_if;
    if (TST_AnOut_3   ) then ; end_if;
    if (TST_AnOut_4   ) then ; end_if;

    if (TST_Tamb      ) then RES_Tamb := PLC_Tamb; end_if;
    if (TST_FWrevision) then RES_FWrevision := PLC_FWrevision; end_if;
    if (TST_HWconfig  ) then RES_HWconfig := PLC_HWconfig; end_if;

	if (TST_RTUS_WR   ) then ; end_if;
	if (TST_RTUS_RD   ) then RES_RTUS_RD := RTU_RTUS_RD; end_if;

END_FUNCTION
