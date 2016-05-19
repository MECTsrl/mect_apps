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
	if (TST_DigOut_9  ) then ; end_if;
    if (TST_DigOut_10 ) then ; end_if;
    if (TST_DigOut_11 ) then ; end_if;
    if (TST_DigOut_12 ) then ; end_if;

    if (TST_AnIn_1    ) then RES_AnIn_1 := PLC_AnIn_1; end_if;
    if (TST_AnIn_2    ) then RES_AnIn_2 := PLC_AnIn_2; end_if;
	if (TST_AnIn_3    ) then RES_AnIn_3 := PLC_AnIn_3; end_if;
    if (TST_AnIn_4    ) then RES_AnIn_4 := PLC_AnIn_4; end_if;

    if (TST_AnOut_1   ) then ; end_if;
    if (TST_AnOut_2   ) then ; end_if;
   
    if (TST_Tamb      ) then RES_Tamb := PLC_Tamb; end_if;
    if (TST_RPM       ) then RES_RPM := PLC_RPM / 10; end_if;
   
	if (TST_RTUS_WR   ) then ; end_if;
	if (TST_RTUS_RD   ) then ; end_if;	
	if (TST_RTU1_WR   ) then RES_RTU1_WR := RTU_RTU_WR; end_if;
	if (TST_RTU1_RD   ) then RES_RTU1_RD := RTU_RTU_RD; end_if;	
	if (TST_RTU3_WR   ) then ; end_if;
	if (TST_RTU3_RD   ) then ; end_if;	
	if (TST_CAN1_WR   ) then RES_CAN1_WR := CAN_DigOut_1; end_if;
	if (TST_CAN1_RD   ) then RES_CAN1_RD := CAN_DigIn_1; end_if;	

END_FUNCTION
