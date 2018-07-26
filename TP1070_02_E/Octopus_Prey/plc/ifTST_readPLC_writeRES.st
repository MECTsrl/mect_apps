(*[[
]]*)
FUNCTION ifTST_readPLC_writeRES
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

    if (TST_DigIn_1   ) then RES_DigIn_1 := PLC_FastIO_1; end_if;
    if (TST_DigIn_2   ) then RES_DigIn_2 := PLC_FastIO_2; end_if;
    if (TST_DigIn_3   ) then RES_DigIn_3 := PLC_FastIO_3; end_if;
    if (TST_DigIn_4   ) then RES_DigIn_4 := PLC_FastIO_4; end_if;

	if (TST_RTU1_RD   ) then RES_RTU1_RD := RTU_RTU_RD; end_if;	

END_FUNCTION
