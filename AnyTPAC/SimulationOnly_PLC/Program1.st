(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	timer : TON;
	flipflop : BOOL := TRUE;
END_VAR;

	(* Local PLC variables *)
	BBB := AAA + 1;
	DDD := CCC + 0.001;

	(* Output Generation *)
	PLC_AnOut_1 := 500 + REAL_TO_INT(500.0 * sin(PLC_time / 1.0));
	timer(IN := true, PT := T#1s);
	if timer.Q then
		timer(IN := false);
		flipflop := not flipflop;
		if (flipflop) then
			PLC_AnOut_2 := 1000;
		else
			PLC_AnOut_2 := 0;
		end_if;
		PLC_DigOut_1 := flipflop;
	end_if;

END_PROGRAM
