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
	BBB := AAA;
	DDD := CCC;

	(* Output Generation *)
	PLC_AnOut_1 := 500 + REAL_TO_INT(500.0 * sin(PLC_time / 1.0));
	timer(IN := true, PT := T#5s);
	if timer.Q then
		timer(IN := false);
		flipflop := not flipflop;
		if (flipflop) then
			PLC_AnOut_2 := 1000;
		else
			PLC_AnOut_2 := 0;
		end_if;
		PLC_DigOut_1 := flipflop;
	else
		PLC_DigOut_1 := PLC_DigIn_1;
	end_if;

	(* I/O replication *)	
	PLC_DigOut_2 := PLC_DigIn_2;
	PLC_DigOut_3 := PLC_DigIn_3;
	PLC_DigOut_4 := PLC_DigIn_4;
	PLC_DigOut_5 := PLC_DigIn_5;
	PLC_DigOut_6 := PLC_DigIn_6;
	PLC_DigOut_7 := PLC_DigIn_7;
	PLC_DigOut_8 := PLC_DigIn_8;
	PLC_DigOut_9 := PLC_DigIn_9;
	PLC_DigOut_10 := PLC_DigIn_10;
	PLC_DigOut_11 := PLC_DigIn_11;
	PLC_DigOut_12 := PLC_DigIn_12;
	PLC_DigOut_13 := PLC_DigIn_13;
	PLC_DigOut_14 := PLC_DigIn_14;
	PLC_DigOut_15 := PLC_DigIn_15;
	PLC_DigOut_16 := PLC_DigIn_16;

	(* Wiring simulation *)
	
	PLC_DigIn_2 := PLC_DigOut_1;
	PLC_DigIn_3 := PLC_DigOut_2;
	PLC_DigIn_4 := PLC_DigOut_3;
	PLC_DigIn_5 := PLC_DigOut_4;
	PLC_DigIn_6 := PLC_DigOut_5;
	PLC_DigIn_7 := PLC_DigOut_6;
	PLC_DigIn_8 := PLC_DigOut_7;
	PLC_DigIn_9 := PLC_DigOut_8;
	PLC_DigIn_10 := PLC_DigOut_9;
	PLC_DigIn_11 := PLC_DigOut_10;
	PLC_DigIn_12 := PLC_DigOut_11;
	PLC_DigIn_13 := PLC_DigOut_12;
	PLC_DigIn_14 := PLC_DigOut_13;
	PLC_DigIn_15 := PLC_DigOut_14;
	PLC_DigIn_16 := PLC_DigOut_15;

END_PROGRAM
