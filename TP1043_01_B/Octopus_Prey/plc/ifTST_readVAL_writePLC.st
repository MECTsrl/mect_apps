(*[[
]]*)
FUNCTION ifTST_readVAL_writePLC
#import "Crosstable.gvl"
VAR_INPUT
	substatus : uint;
END_VAR

	if substatus = 0 then 

		if (TST_CAN1_WR   ) then CAN_DigOut_1 := VAL_CAN1_WR; end_if;
		if (TST_CAN1_RD   ) then ; end_if;

	elsif substatus = 1 then

		;

	elsif substatus = 2 then

	    ;

	end_if;
	
END_FUNCTION
