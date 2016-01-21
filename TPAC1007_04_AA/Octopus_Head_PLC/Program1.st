(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
VAR
	first: BOOL;
	(* timer : TON; *)
END_VAR
	if first then
		first := FALSE;

		(* reset all *)
		START2_REMOTE := FALSE;  STARTx_REMOTE := FALSE;  
		START2_TEST := FALSE;  STARTx_TEST := FALSE;  
		(* POWER ON <-- DO3 *) 
		(* OUTPUT ON <-- DO2 *) 
		PLC_DigDir_3 := 1;
		PLC_DigDir_2 := 1;
		PLC_DigOut_3 := 0;
		PLC_DigOut_2 := 0;
		(* ANALOG OUTPUT THRESHOLD *)
		RTU_AnOutConf_X := 5;
		STATUS := 0;
	end_if;

	case STATUS of

	0: (* IDLE *)
		if DO_REMOTE then
			START2_REMOTE := TRUE;  STARTx_REMOTE := TRUE;  
			STATUS := 1;
		end_if;

	1: (* STARTING *)
		if STATUS2_REMOTE AND STATUSx_REMOTE then
			STATUS := 2;
		end_if;

	2: (* READY *)
		if DO_TEST then
			ClearResults();
			Translate_DigIn();
			Translate_DigOut();
			Translate_AnIn();
			Translate_AnOut();
			Translate_Others();
			(* FIXME: delay? *)
			START2_TEST := TRUE;  STARTx_TEST := TRUE;  
			STATUS := 3;
		end_if;
		if not DO_REMOTE then
			START2_REMOTE := FALSE;  STARTx_REMOTE := FALSE;  
			STATUS := 6;
		end_if;

	3: (* TESTING *)
		if STATUS2_DONE AND STATUSx_DONE then
			Check_DigIn();
			Check_DigOut();
			Check_AnIn();
			Check_AnOut();
			Check_Others();
			STATUS := 4;
		end_if;

	4: (* DONE *)
		if not DO_TEST then
			START2_TEST := FALSE;  STARTx_TEST := FALSE;  
			STATUS := 5;
		end_if;

	5: (* RESETTING *)
		if STATUS2_REMOTE and STATUSx_REMOTE then
			STATUS := 2;
		end_if;

	6: (* STOPPING *)
		if not STATUS2_REMOTE and not STATUSx_REMOTE then
			STATUS := 0;
		end_if;

    else
		(* FIXME: assert *)
		;
    end_case;
END_PROGRAM
