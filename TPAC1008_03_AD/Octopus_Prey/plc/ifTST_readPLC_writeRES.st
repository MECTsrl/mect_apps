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
	(* only 8 input are tested, due to cabling limits *)

    if (TST_AnIn_1    ) then RES_AnIn_1 := PLC_AnIn_1; end_if;
    if (TST_AnIn_2    ) then RES_AnIn_2 := PLC_AnIn_2; end_if;
	if (TST_AnIn_3    ) then RES_AnIn_3 := PLC_AnIn_3; end_if;
    if (TST_AnIn_4    ) then RES_AnIn_4 := PLC_AnIn_4; end_if;
  
    if (TST_Tamb      ) then RES_Tamb := PLC_Tamb; end_if;
    if (TST_RPM       ) then RES_RPM := PLC_RPM / 10; end_if;
   
	if (TST_RTU1_RD   ) then RES_RTU1_RD := RTU_RTU_RD; end_if;	
	if (TST_RTU3_RD   ) then RES_RTU3_RD := PLC_DigIn_9; end_if;

END_FUNCTION
