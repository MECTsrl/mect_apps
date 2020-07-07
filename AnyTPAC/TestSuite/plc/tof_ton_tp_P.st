(*[[
]]*)
PROGRAM tof_ton_tp_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 55;
	test_cases : int := 16;
END_CONST
VAR
	test_case : array [1..test_cases] of bool_time_bool3_time3_T := [

		(* reset all_____________________   TP______________________________  TON_____________________________  TOF_____________________________ *)
		(bool0 := false, time0 := t#000ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := false, time3 := t#000ms),

		(* start, reset TON, wait TP+TOF_   TP______________________________  TON_____________________________  TOF_____________________________ *)
		(bool0 := true,  time0 := t#250ms,  bool1 := true,  time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#000ms),
		(bool0 := false, time0 := t#250ms,  bool1 := true,  time1 := t#100ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#000ms),
		(bool0 := false, time0 := t#250ms,  bool1 := true,  time1 := t#200ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#100ms),
		(bool0 := false, time0 := t#250ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#200ms),
		(bool0 := false, time0 := t#250ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := false, time3 := t#250ms),

		(* reset all_____________________   TP______________________________  TON_____________________________  TOF_____________________________ *)
		(bool0 := false, time0 := t#000ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := false, time3 := t#000ms),
		
		(* start and wait TP+TON_________   TP______________________________  TON_____________________________  TOF_____________________________ *)
		(bool0 := true,  time0 := t#250ms,  bool1 := true,  time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#000ms),
		(bool0 := true,  time0 := t#250ms,  bool1 := true,  time1 := t#100ms, bool2 := false, time2 := t#100ms, bool3 := true,  time3 := t#000ms),
		(bool0 := true,  time0 := t#250ms,  bool1 := true,  time1 := t#200ms, bool2 := false, time2 := t#200ms, bool3 := true,  time3 := t#000ms),
		(bool0 := true,  time0 := t#250ms,  bool1 := false, time1 := t#250ms, bool2 := true,  time2 := t#250ms, bool3 := true,  time3 := t#000ms),

		(* reset all_____________________   TP______________________________  TON_____________________________  TOF_____________________________ *)
		(bool0 := false, time0 := t#250ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#000ms),
		
		(* start and wait TOF____________   TP______________________________  TON_____________________________  TOF_____________________________ *)
		(bool0 := false, time0 := t#250ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#100ms),
		(bool0 := false, time0 := t#250ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := true,  time3 := t#200ms),
		(bool0 := false, time0 := t#250ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := false, time3 := t#250ms),

		(* reset all_____________________   TP______________________________  TON_____________________________  TOF_____________________________ *)
		(bool0 := false, time0 := t#000ms,  bool1 := false, time1 := t#000ms, bool2 := false, time2 := t#000ms, bool3 := false, time3 := t#000ms) 
	];
	
    bool1, bool2, bool3 : bool;
    time1, time2, time3 : time;
	delta1, delta2, delta3: dint;

	TP_Inst : TP;
	TON_Inst : TON;
	TOF_Inst : TOF;
	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
	period_ms : time;
	info : tsk_info;
	retval : word;
END_VAR

	if Status = STATUS_RUNNING AND test_level_55 > TEST_DISABLED and test_loops_55 < Target then

		retval := TSK_GetInfo(TSK_GetMyName(), info);
		period_ms := info.tCycle;
		if period_ms <> t#100ms then
			MSG_SendToEng('ERROR: Program TOF_TON_TP must run @ 100ms: disabled.');
			test_level_55 := 0;
			return;
		end_if;

		(* ---------- test action ---------------*)
		TP_Inst (IN := test_case[index].bool0, PT := test_case[index].time0, Q => bool1, ET => time1);
		TON_Inst(IN := test_case[index].bool0, PT := test_case[index].time0, Q => bool2, ET => time2);
		TOF_Inst(IN := test_case[index].bool0, PT := test_case[index].time0, Q => bool3, ET => time3);

		delta1 := time_to_dint(time1 - test_case[index].time1);
		delta2 := time_to_dint(time2 - test_case[index].time2);
		delta3 := time_to_dint(time3 - test_case[index].time3);

		(* ---------- test condition ---------------*)
        result := (bool1 = test_case[index].bool1) and (abs(delta1) < 10)
		      and (bool2 = test_case[index].bool2) and (abs(delta2) < 10)
		      and (bool3 = test_case[index].bool3) and (abs(delta3) < 10);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].bool1));	
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].time1));	
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].bool2));	
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].time2));	
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].bool3));	
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].time3));	
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(bool1));	
		obtained := CONCAT(obtained, comma_blank, time_to_string(time1));	
		obtained := CONCAT(obtained, comma_blank, bool_to_string(bool2));	
		obtained := CONCAT(obtained, comma_blank, time_to_string(time2));	
		obtained := CONCAT(obtained, comma_blank, bool_to_string(bool3));	
		obtained := CONCAT(obtained, comma_blank, time_to_string(time3));	
		
		(* ---------- cycle ----------*)
		if not result then
			;
		end_if;
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_55, test_counter_55, test_loops_55, test_errors_55);
	end_if;
END_PROGRAM
