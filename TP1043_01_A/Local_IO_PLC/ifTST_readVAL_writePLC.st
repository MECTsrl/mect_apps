(*[[
]]*)
FUNCTION ifTST_readVAL_writePLC
#import "Crosstable.gvl"
VAR_INPUT
	substatus : uint;
END_VAR

	if substatus = 0 then 

		if (TST_RTU1_WR   ) then RTU_RTU1_WR := VAL_RTU1_WR; end_if;
		if (TST_RTU1_RD   ) then ; end_if;

	elsif substatus = 1 then

		;

	elsif substatus = 2 then

	    ;

	end_if;
	
END_FUNCTION
