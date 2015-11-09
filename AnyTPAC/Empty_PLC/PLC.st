(*[[
]]*)
PROGRAM PLC
#import "Resource1.gvl"
#import "TPACLocaIO.gvl"
VAR
	info : TSK_INFO ;
	counter : INT := 0;
	task_ms : INT := -1;
	retval : WORD;
	first : BOOL := true;
END_VAR;
	if first then
		first := false;
		if task_ms < 0 then
			retval := TSK_GetInfo('Task0_Control', info);
			task_ms := TIME_TO_INT(info.tCycle);
		end_if;
	end_if;

	counter := (counter + 1) mod 10000;

END_PROGRAM
