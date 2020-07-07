(*[[
]]*)
PROGRAM xx_TestManager 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	StartTime_cs : UDINT := 0;
END_VAR
	
	case Status of
	
	STATUS_ZERO:
		;

	STATUS_IDLE:
		if BUTTON_START then
			StartTest();
			StartTime_cs := PLC_UPTIME_cs;
			Elapsed_s := 0;
			Status := STATUS_RUNNING;
		elsif BUTTON_RESET then
			SetDefaultValues();
			ResetCounters();
			UpdateCounters();
		else
			;
		end_if;

	STATUS_RUNNING:
		UpdateCounters();
		if BUTTON_STOP then
			StopTest();
			Status := STATUS_DONE;
		else
			Elapsed_s := PLC_UPTIME_cs - StartTime_cs; (* NB: Elapsed_s has decimals = 2 *)
			StepTest();
			if Target > 0 and Loops >= Target then
				StopTest();
				Status := STATUS_DONE;
			end_if;
		end_if;

	STATUS_DONE:
		if BUTTON_START then
			ResetCounters();
			UpdateCounters();
			StartTest();
			StartTime_cs := PLC_UPTIME_cs;
			Elapsed_s := 0;
			Status := STATUS_RUNNING;
		elsif BUTTON_RESET then
			SetDefaultValues();
			ResetCounters();
			UpdateCounters();
			Status := STATUS_IDLE;
		else
			;
		end_if;

	else
		;

	end_case;
	
END_PROGRAM

