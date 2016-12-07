(*[[
]]*)
FUNCTION ifTST_readPLC_writeRES
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

     
	if (TST_RTU1_RD   ) then RES_RTU1_RD := RTU_RTU_RD; end_if;	
	if (TST_RTU3_RD   ) then RES_RTU3_RD := TPLC005_DigIn_3; end_if;	

END_FUNCTION
