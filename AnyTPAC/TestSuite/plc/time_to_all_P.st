(*[[
]]*)
PROGRAM time_to_all_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 9;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of time_all_T := [
		(input := t#0ms, ret_dint := 0,  ret_int := 0, ret_lreal := 0.0, ret_real := 0.0, ret_string := 't#0ms'),
		(input := t#1ms, ret_dint := 1, ret_int := 1, ret_lreal := 1.0, ret_real := 1.0, ret_string := 't#1ms'),
		(input := t#-1ms, ret_dint := -1, ret_int := -1, ret_lreal := -1.0, ret_real := -1.0, ret_string := 't#-1ms'),
		(input := t#255ms, ret_dint := 255, ret_int := 255, ret_lreal := 255.0, ret_real := 255.0, ret_string := 't#255ms'),
		(input := t#400ms, ret_dint := 400, ret_int := 400, ret_lreal := 400.0, ret_real := 400.0, ret_string := 't#400ms')
	];
    ret_dint   : dint;
    ret_int    : int;
    ret_lreal  : lreal;
    ret_real   : real;
    ret_string : string;

	index : int := 1;
	expected: string;
	obtained: string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_09 > TEST_DISABLED and test_loops_09 < Target then

		(* ---------- test action ---------------*)
        ret_dint   := time_to_dint(test_case[index].input);
        ret_int    := time_to_int(test_case[index].input);
        ret_lreal  := time_to_lreal(test_case[index].input);
        ret_real   := time_to_real(test_case[index].input);
        ret_string := time_to_string(test_case[index].input);
    
		(* ---------- test condition ---------------*)
        result := (ret_dint = test_case[index].ret_dint)
		      and (ret_int = test_case[index].ret_int)
		      and (ret_lreal = test_case[index].ret_lreal)
		      and (ret_real = test_case[index].ret_real)
		      and (ret_string = test_case[index].ret_string);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, test_case[index].ret_string);
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, ret_string);

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_09, test_counter_09, test_loops_09, test_errors_09);
	end_if;
END_PROGRAM
