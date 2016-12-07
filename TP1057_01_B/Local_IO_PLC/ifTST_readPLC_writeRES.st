(*[[
]]*)
FUNCTION ifTST_readPLC_writeRES
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

      
	if (TST_RTU1_RD   ) then RES_RTU1_RD := RTU_RTU_RD; end_if;	
	
	if (TST_CAN1_WR   ) then ; end_if;
	if (TST_CAN1_RD   ) then RES_CAN1_RD := CAN_DigIn_1; end_if;

END_FUNCTION
