(*[[
]]*)
PROGRAM Testing 
#import "Crosstable.gvl"
VAR
	substatus : uint := 0;
	timer : TON;
END_VAR

	case STATUS of
	
	STATUS_LOCAL:
		if (TEST_COMMAND = STATUS_REMOTE) then
			substatus := 0;
			STATUS := STATUS_REMOTE;
			TEST_STATUS := STATUS;
		end_if;
	
	STATUS_REMOTE:
	    if (TEST_COMMAND = STATUS_LOCAL) then
			STATUS := STATUS_LOCAL;
			TEST_STATUS := STATUS;
	    end_if;
	    if (TEST_COMMAND = STATUS_DONE) then
			case substatus of
			0: (* for each tested output write the specified value *)
	        	ifTST_readVAL_writePLC(substatus);
				substatus := 1;
	        1:	ifTST_readVAL_writePLC(substatus);
				substatus := 2;
			2:  ifTST_readVAL_writePLC(substatus);
				substatus := 3;
			3:  (* wait for output settling *)
				timer(IN := TRUE, PT := T#2000ms); (* TPLC100 AnIn *)
				if timer.Q then
					timer(IN := FALSE);
					ifTST_readVAL_writePLC(substatus);
					substatus := 4;
				end_if;
			4: (* wait for input settling *)
		        timer(IN := TRUE, PT := T#3000ms); (* TPAC1006 AnIn *)
				if timer.Q then
					timer(IN := FALSE);
					(* for each tested input read the actual value *)
		        ifTST_readPLC_writeRES();
					substatus := 5;
				end_if;
			5: (* wait for propagation *)
				timer(IN := TRUE, PT := T#1000ms);
				if timer.Q then
					timer(IN := FALSE);
					substatus := 6;
				end_if;
			 6: (* change status *)
				STATUS := STATUS_DONE;
				TEST_STATUS := STATUS;
			 else
				;
			 end_case;
	    end_if;
	
	STATUS_DONE:
		if (TEST_COMMAND = STATUS_REMOTE) then
			substatus := 0;
			STATUS := STATUS_REMOTE;
			TEST_STATUS := STATUS;
		end_if;
	    if (TEST_COMMAND = STATUS_LOCAL) then
			STATUS := STATUS_LOCAL;
			TEST_STATUS := STATUS;
	    end_if;
	
	else
		;
	end_case;

END_PROGRAM
