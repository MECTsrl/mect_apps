(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
VAR
	first: BOOL;
	status: INT;
	timer : TON;
END_VAR
	if first then
		first := FALSE;

		(* reset all *)
		TESTING := TRUE; TESTING1 := TRUE; TESTING2 := TRUE; TESTINGx := TRUE; 
		RESET := TRUE;   RESET1 := TRUE;   RESET2 := TRUE;   RESETx := TRUE;   
		START := FALSE;  START1 := FALSE;  START2 := FALSE;  STARTx := FALSE;  
		STOP := FALSE;   STOP1 := FALSE;   STOP2 := FALSE;   STOPx := FALSE;   
		(* POWER ON <-- Horn1 DO3 *) 
		(* OUTPUT ON <-- Horn1 DO2 *) 
		TST1_DigOut_3 := 1;
		TST1_DigOut_2 := 1;
		VAL1_DigOut_3 := 1;
		VAL1_DigOut_2 := 1;
		status := -1;
		RUNNING := FALSE;
	end_if;

	case status of

	-1: (* BOOTING *)
		timer(IN := TRUE, PT := T#20s);
		if timer.Q then
			timer(IN := FALSE);
			RUNNING := FALSE;
			status := 0;
		end_if;

	0: (* IDLE *)
		if GO then
			RUNNING := TRUE;
			RESET := TRUE;   RESET1 := TRUE;   RESET2 := TRUE;   RESETx := TRUE;   
			status := 1;
		end_if;

	1: (* waiting for reset *)
		timer(IN := TRUE, PT := T#5s);
		if timer.Q then
			timer(IN := FALSE);
			RUNNING := FALSE;
			status := 2;
		end_if;

	2: (* translating TST -> TST1 + TST2 + TSTx *)
		Translate_DigIn();
		Translate_DigOut();
		Translate_AnIn();
		Translate_AnOut();
		Translate_Others();
		status := 3;

	3: (* waiting for propagation *)
		timer(IN := TRUE, PT := T#5s);
		if timer.Q then
			timer(IN := FALSE);
			status := 4;
		end_if;

	4: (* sending START *)
		START := FALSE;  START1 := FALSE;  START2 := FALSE;  STARTx := FALSE;  
		status := 5;

	5: (* waiting for execution *)
		timer(IN := TRUE, PT := T#7s);
		if timer.Q then
			timer(IN := FALSE);
			status := 6;
		end_if;

	6: (* sending STOP *)
		STOP := FALSE;   STOP1 := FALSE;   STOP2 := FALSE;   STOPx := FALSE;   
		status := 7;

	7: (* waiting for results *)
		timer(IN := TRUE, PT := T#3s);
		if timer.Q then
			timer(IN := FALSE);
			status := 8;
		end_if;

	8: (* computing either OK or NG *)
		RESET := TRUE;   RESET1 := TRUE;   RESET2 := TRUE;   RESETx := TRUE;   
		RUNNING := FALSE;
		status := 0;

    else
		RUNNING := FALSE;
		status := 0;
    end_case;
END_PROGRAM
