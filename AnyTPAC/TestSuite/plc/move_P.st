(*[[
]]*)
PROGRAM move_P
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 22;
	test_cases : int := 2;
END_CONST
VAR
	test_case : array [1..test_cases] of dint_dint_T := [
		(input := 42, retval := 42),
		(input := -42, retval := -42)
	];
    ret_dint : dint;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_22 > TEST_DISABLED and test_loops_22 < Target then

		(* ---------- test action ---------------*)
        ret_dint   := move(test_case[index].input);
    
		(* ---------- test condition ---------------*)
        result := (ret_dint = test_case[index].retval);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].retval));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_22, test_counter_22, test_loops_22, test_errors_22);
   end_if;
END_PROGRAM
