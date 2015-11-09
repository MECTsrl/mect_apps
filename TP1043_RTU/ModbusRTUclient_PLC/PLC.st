(*[[
]]*)
PROGRAM PLC
#import "Resource1.gvl"
#import "TPACLocaIO.gvl"
VAR
	info : TSK_INFO ;
	fb_HW119_PLCwriteVar_Inst:fb_HW119_PLCwriteVar;
	values : ARRAY [0..15] OF DWORD;
	counter : INT := 0;
	period: INT := 10; (* x 100ms = 1s *)
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
	if (counter mod period = 0) then
		values[0] := INT_TO_DWORD((counter/period) mod 2);
		fb_HW119_PLCwriteVar_Inst(VARIABLE:='TPLC_OUT_1',VALUES:=values,Nregs:=1);
	end_if;

END_PROGRAM

