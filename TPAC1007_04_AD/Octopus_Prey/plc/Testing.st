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
			2: (* wait for output settling *)
				timer(IN := TRUE, PT := T#1000ms);
				if timer.Q then
					timer(IN := FALSE);
					ifTST_readVAL_writePLC(substatus);
					substatus := 3;
				end_if;
			3: (* wait for input settling, higher for temperature measurements *)
				if ((TST_AnIn_1 and (VAL_AnInConf_1 > 2))
					or (TST_AnIn_2 and (VAL_AnInConf_2 > 2))
					or (TST_AnIn_3 and (VAL_AnInConf_3 > 2))) then
			        timer(IN := TRUE, PT := T#3000ms);
				else
			        timer(IN := TRUE, PT := T#1000ms);
				end_if;
				if timer.Q then
					timer(IN := FALSE);
					(* for each tested input read the actual value *)
					ifTST_readPLC_writeRES();
					substatus := 4;
				end_if;
			4: (* wait for propagation *)
				timer(IN := TRUE, PT := T#1000ms);
				if timer.Q then
					timer(IN := FALSE);
					substatus := 5;
				end_if;
			 5: (* change status *)
				STATUS := STATUS_DONE;
				TEST_STATUS := STATUS;
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
