(*[[
]]*)
PROGRAM trunc_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 10;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of lreal_any_int_T := [
		(input := -7.0, ret_int :=  -7, ret_dint := -7),
		(input := -2.2, ret_int :=  -2, ret_dint := -2),
		(input := 14.0, ret_int := 14, ret_dint := 14),
		(input := 14.11, ret_int := 14, ret_dint := 14),
		(input := 14.88, ret_int := 14, ret_dint := 14)
	];
	ret_int1  : int;
	ret_int2  : int;
	ret_dint1 : dint;
	ret_dint2 : dint;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_10 > TEST_DISABLED and test_loops_10 < Target then

		(* ---------- test action ---------------*)
        ret_int1  := trunc(test_case[index].input);
        ret_dint1 := trunc(test_case[index].input);
        ret_int2  := trunc(lreal_to_real(test_case[index].input));
        ret_dint2 := trunc(lreal_to_real(test_case[index].input));
    
		(* ---------- test condition ---------------*)
        result := (ret_int1 = test_case[index].ret_int)
				  and (ret_dint1 = test_case[index].ret_dint)
				  and (ret_int2 = test_case[index].ret_int)
				  and (ret_dint2 = test_case[index].ret_dint);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int1));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int2));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint1));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint2));
		

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_10, test_counter_10, test_loops_10, test_errors_10);
	end_if;

END_PROGRAM
