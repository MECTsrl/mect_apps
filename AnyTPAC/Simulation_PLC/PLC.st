(*[[
]]*)
PROGRAM PLC
#import "Resource1.gvl"
#import "TPACLocaIO.gvl"
VAR
	info : TSK_INFO ;
	counter : INT := 0;
	task_ms : INT := -1;
	square_ms : INT := 1000;
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

	(* Input Simulation *)
	PLC_DigIn_1 := PLC_DigOut_1;
	PLC_DigIn_2 := PLC_DigOut_2;
	PLC_DigIn_3 := PLC_DigOut_3;
	PLC_DigIn_4 := PLC_DigOut_4;
	PLC_DigIn_5 := PLC_DigOut_5;
	PLC_DigIn_6 := PLC_DigOut_6;
	PLC_DigIn_7 := PLC_DigOut_7;
	PLC_DigIn_8 := PLC_DigOut_8;
	PLC_AnIn_1 := 5000 + REAL_TO_INT(5000.0 * sin(PLC_time / 1.0));
	PLC_AnIn_2 := 10000 * WORD_TO_INT(PLC_DigOut_1);

	(* Output Simulation *)
	if (REAL_TO_INT(PLC_time) mod 2) = 0 then 
		PLC_DigOut_1 := 1;
		PLC_DigOut_2 := 0;
		PLC_DigOut_3 := 1;
		PLC_DigOut_4 := 0;
		PLC_DigOut_5 := 0;
		PLC_DigOut_6 := 1;
		PLC_DigOut_7 := 0;
		PLC_DigOut_8 := 1;
	else
		PLC_DigOut_1 := 0;
		PLC_DigOut_2 := 1;
		PLC_DigOut_3 := 0;
		PLC_DigOut_4 := 1;
		PLC_DigOut_5 := 1;
		PLC_DigOut_6 := 0;
		PLC_DigOut_7 := 1;
		PLC_DigOut_8 := 0;
	end_if;

END_PROGRAM
