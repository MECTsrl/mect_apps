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

    if (TST_DigOut_1  ) then ; end_if;
    if (TST_DigOut_2  ) then ; end_if;
    if (TST_DigOut_3  ) then ; end_if;
    if (TST_DigOut_4  ) then ; end_if;
    if (TST_DigOut_5  ) then ; end_if;
    if (TST_DigOut_6  ) then ; end_if;
    if (TST_DigOut_7  ) then ; end_if;
    if (TST_DigOut_8  ) then ; end_if;

    if (TST_AnIn_1    ) then RES_AnIn_1  := PLC_AnIn_1 ; end_if;
    if (TST_AnIn_2    ) then RES_AnIn_2  := PLC_AnIn_2 ; end_if;
    if (TST_AnIn_3    ) then RES_AnIn_3  := PLC_AnIn_3 ; end_if;
    if (TST_AnIn_4    ) then RES_AnIn_4  := PLC_AnIn_4 ; end_if;

    if (TST_AnIn_5    ) then RES_AnIn_5  := PLC_AnIn_5 ; end_if;
    if (TST_AnIn_6    ) then RES_AnIn_6  := PLC_AnIn_6 ; end_if;
    if (TST_AnIn_7    ) then RES_AnIn_7  := PLC_AnIn_7 ; end_if;
    if (TST_AnIn_8    ) then RES_AnIn_8  := PLC_AnIn_8 ; end_if;
    if (TST_AnIn_9    ) then RES_AnIn_9  := PLC_AnIn_9 ; end_if;
    if (TST_AnIn_10   ) then RES_AnIn_10 := PLC_AnIn_10; end_if;
    if (TST_AnIn_11   ) then RES_AnIn_11 := PLC_AnIn_11; end_if;
    if (TST_AnIn_12   ) then RES_AnIn_12 := PLC_AnIn_12; end_if;

    if (TST_AnOut_1   ) then ; end_if;
    if (TST_AnOut_2   ) then ; end_if;

    if (TST_Tamb      ) then RES_Tamb := PLC_CJT_X12; end_if;

	if (TST_CAN1_RD   ) then RES_CAN1_RD := CAN_DigIn_1; end_if;

END_FUNCTION
