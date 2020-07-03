(*[[ ]]*)
PROGRAM mod_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 21;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of dint2_dint_int_T := [
		(input0 := 10, input1 := 10, ret_dint := 0, ret_int := 0),
		(input0 := 10, input1 :=  2, ret_dint := 0, ret_int := 0),
		(input0 := 11, input1 :=  2, ret_dint := 1, ret_int := 1),
		(input0 := 13, input1 :=  5, ret_dint := 3, ret_int := 3)
	];
    ret_int  : int;
    ret_dint : dint;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_21 > TEST_DISABLED and test_loops_21 < Target then

		(* ---------- test action ---------------*)
        ret_dint   := mod(test_case[index].input0, test_case[index].input1);
        ret_int    := mod(dint_to_int(test_case[index].input0), dint_to_int(test_case[index].input1));
    
		(* ---------- test condition ---------------*)
        result := ((ret_int = test_case[index].ret_int)
		      and (ret_dint = test_case[index].ret_dint));

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_21, test_counter_21, test_loops_21, test_errors_21);
	end_if;
END_PROGRAM
