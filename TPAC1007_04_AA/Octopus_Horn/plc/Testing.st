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
	        	ifTST_readVAL_writePLC(TRUE);
				substatus := 1;
			1: (* wait for the relais and for Prey *)
				timer(IN := TRUE, PT := T#2000ms); 
				if timer.Q then
					timer(IN := FALSE);
	        		ifTST_readVAL_writePLC(FALSE);
					substatus := 2;
				end_if;
			2: (* wait for the analog inputs *)
				timer(IN := TRUE, PT := T#3000ms); 
				if timer.Q then
					timer(IN := FALSE);
	        		(* for each tested input write the actual value *)
			        ifTST_readPLC_writeRES();
					substatus := 3;
				end_if;
			3: (* wait for propagation *)
				timer(IN := TRUE, PT := T#1000ms); (* Modbus/TCP *)
				if timer.Q then
					timer(IN := FALSE);
					substatus := 4;
				end_if;
			 4: (* change status *)
				STATUS := STATUS_DONE;
				TEST_STATUS := STATUS;
			end_case;
			(* RPM output @ 50.0 Hz (instead of PWM 50%) *)
 	        if (TST_AnOut_3 AND VAL_AnOut_3 > 0) then PLC_DigOut_1 := not PLC_DigOut_1; end_if;
	    end_if;
	
	STATUS_DONE:
		(* RPM output @ 50.0 Hz *)
        if (TST_AnOut_3 AND VAL_AnOut_3 > 0) then PLC_DigOut_1 := not PLC_DigOut_1; end_if;
		if (TEST_COMMAND = STATUS_REMOTE) then
			substatus := 0;
			ClearPLC();
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
