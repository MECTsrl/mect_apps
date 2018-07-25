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

    if (TST_DigOut_1  ) then ; end_if;
    if (TST_DigOut_2  ) then ; end_if;
    if (TST_DigOut_3  ) then ; end_if;
    if (TST_DigOut_4  ) then ; end_if;
    if (TST_DigOut_5  ) then ; end_if;
    if (TST_DigOut_6  ) then ; end_if;
    if (TST_DigOut_7  ) then ; end_if;
    if (TST_DigOut_8  ) then ; end_if;

    if (TST_DigIn_9   ) then RES_DigIn_9 := YY_DigIn_A_1; end_if;
    if (TST_DigOut_9  ) then ; end_if;

    if (TST_AnIn_1    ) then RES_AnIn_1 := PLC_AnIn_1; end_if;
    if (TST_AnIn_2    ) then RES_AnIn_2 := PLC_AnIn_2; end_if;

    if (TST_Tamb      ) then RES_Tamb := PLC_ColdJunctionT; end_if;
    if (TST_RPM       ) then ; end_if;
    if (TST_FWrevision) then RES_FWrevision := PLC_FirmwareVer; end_if;
    if (TST_HWconfig  ) then RES_HWconfig := PLC_HWconfig; end_if;

	if (TST_RTU1_WR   ) then ; end_if;
	if (TST_RTU1_RD   ) then RES_RTU1_RD := RTU_RTU1_RD; end_if;

END_FUNCTION
