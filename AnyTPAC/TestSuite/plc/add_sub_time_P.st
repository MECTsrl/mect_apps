(*[[ ]]*)
PROGRAM add_sub_time_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 50;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of time2_time2_T := [
		(input0 := t#10ms, input1 := t#10ms, retval0 := t#20ms,  retval1 := t#0ms),
		(input0 := t#20ms, input1 := t#10ms, retval0 := t#30ms,  retval1 := t#10ms),
		(input0 := t#10s,  input1 := t#10s,  retval0 := t#20s,   retval1 := t#0s),
		(input0 := t#1s,   input1 := t#10ms, retval0 := t#1010ms,retval1 := t#990ms),
		(input0 := t#1s,   input1 := t#2s,   retval0 := t#3s,    retval1 := t#-1s)
	];
    retval0  : time;
    retval1  : time;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_50 > TEST_DISABLED and test_loops_50 < Target then

		(* ---------- test action ---------------*)
        retval0     := add_time(test_case[index].input0, test_case[index].input1);
        retval1     := sub_time(test_case[index].input0, test_case[index].input1);
    
		(* ---------- test condition ---------------*)
        result := ((retval0 = test_case[index].retval0)
		       and (retval1 = test_case[index].retval1));

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval0));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval1));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval0));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval1));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_50, test_counter_50, test_loops_50, test_errors_50);
	end_if;
END_PROGRAM
