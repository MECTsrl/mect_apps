(*[[
]]*)
PROGRAM Testing 
#import "Crosstable.gvl"
VAR
	substatus : uint := 0;
END_VAR

	case TEST_STATUS of
	
	TEST_STATUS_LOCAL:
		if (TEST_COMMAND = TEST_STATUS_REMOTE) then
			substatus := 0;
			TEST_STATUS := TEST_STATUS_REMOTE;
		end_if;
	
	TEST_STATUS_REMOTE:
	    if (TEST_COMMAND = TEST_STATUS_LOCAL) then
	        TEST_STATUS := TEST_STATUS_LOCAL;
	    end_if;
	    if (TEST_COMMAND = TEST_STATUS_DONE) then
			case substatus of
			0: (* clear i/o and results *)
				clearPLCandRES();
				substatus := 1;
			1: (* for each tested output write the specified value *)
	        	ifTST_readVAL_writePLC();
				substatus := 2;
			2: (* delay *)
				substatus := 3;
			3: (* for each tested input write the actual value *)
		        ifTST_readPLC_writeRES();
		        TEST_STATUS := TEST_STATUS_DONE;
			 end_case;
	    end_if;
	
	TEST_STATUS_DONE:
		if (TEST_COMMAND = TEST_STATUS_REMOTE) then
			substatus := 0;
			TEST_STATUS := TEST_STATUS_REMOTE;
		end_if;
	    if (TEST_COMMAND = TEST_STATUS_LOCAL) then
	        TEST_STATUS := TEST_STATUS_LOCAL;
	    end_if;
	
	else
		;
	end_case;

END_PROGRAM
