(*[[
]]*)
FUNCTION ifTST_readPLC_writeRES
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

    if (TST_RTU1_WR   ) then ; end_if;  
  	if (TST_RTU1_RD   ) then RES_RTU1_RD := RTU_RTU_RD; end_if;	
	

END_FUNCTION
