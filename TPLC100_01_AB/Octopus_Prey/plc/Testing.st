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

			0:  ifTST_readVAL_writePLC(substatus); (* AnInConf := 0; AnOutConf = x | 2(pwm) *)
				substatus := 1;

	        1:	ifTST_readVAL_writePLC(substatus); (* AnOutConf := 3(pwm) *)
				substatus := 2;

			2:  ifTST_readVAL_writePLC(substatus); (* AnOut := y(pwm) *)
				substatus := 3;

			3:  timer(IN := TRUE, PT := T#2000ms); (* wait for output settling *)
				if timer.Q then
					timer(IN := FALSE);
					ifTST_readVAL_writePLC(substatus); (* AnInConf := x *)
					substatus := 4;
				end_if;

			4:  if allAnalogInputsAreOK() then (* wait for input settling *)
					substatus := 5;
				end_if;

			5:  timer(IN := TRUE, PT := T#2000ms); (* wait a bit *)
				if timer.Q then
					timer(IN := FALSE);
			        ifTST_readPLC_writeRES();
					substatus := 6;
				end_if;

			6:  timer(IN := TRUE, PT := T#1000ms); (* wait for propagation *)
				if timer.Q then
					timer(IN := FALSE);
					substatus := 7;
				end_if;

			 7: (* change status *)
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
