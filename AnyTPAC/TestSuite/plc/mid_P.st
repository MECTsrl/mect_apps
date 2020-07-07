(*[[ ]]*)
PROGRAM mid_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 48;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of string_int2_string_T := [
		(input0 := 'stringa_di_test', input1 := 3,   input2 := 8, retval := '_di'),
		(input0 := 'stringa_di_test', input1 := 11,  input2 := 0, retval := 'stringa_di_'),
		(input0 := 'stringa_di_test', input1 := 8,   input2 := 8, retval := '_di_test'),
		(input0 := 'stringa_di_test', input1 := 100, input2 := 8, retval := '_di_test')
	];
    retval0   : string;
    retval1   : string;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_48 > TEST_DISABLED and test_loops_48 < Target then

		(* ---------- test action ---------------*)
        retval0 := mid(test_case[index].input0, test_case[index].input1, test_case[index].input2);
        retval1 := mid(test_case[index].input0, int_to_dint(test_case[index].input1), int_to_dint(test_case[index].input2));
    
		(* ---------- test condition ---------------*)
        result := (retval0 = test_case[index].retval)
		      and (retval1 = test_case[index].retval);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, test_case[index].retval);
		expected := CONCAT(expected, comma_blank, test_case[index].retval);
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, retval0);
		obtained := CONCAT(obtained, comma_blank, retval1);

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_48, test_counter_48, test_loops_48, test_errors_48);
	end_if;
END_PROGRAM
