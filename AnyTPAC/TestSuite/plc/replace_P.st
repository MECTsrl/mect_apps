(*[[ ]]*)
PROGRAM replace_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 49;
	test_cases : int := 3;
END_CONST
VAR
	test_case : array [1..test_cases] of string2_int2_string_T := [
		(input0 := 'stringa_dove_inserire', input1 := 'abc_', input2 := 4,  input3 := 1,  retval := 'abc_nga_dove_inserire'),
		(input0 := 'stringa_dove_inserire', input1 := 'abc_', input2 := 4,  input3 := 8,  retval := 'stringaabc_e_inserire'),
		(input0 := 'stringa_dove_inserire', input1 := 'abc_', input2 := 4,  input3 := 21, retval := 'stringa_dove_inserirabc_')
	];
    retval0   : string;
    retval1   : string;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_49 > TEST_DISABLED and test_loops_49 < Target then

		(* ---------- test action ---------------*)
        retval0 := replace(test_case[index].input0, test_case[index].input1, test_case[index].input2, test_case[index].input3);
        retval1 := replace(test_case[index].input0, test_case[index].input1, int_to_dint(test_case[index].input2), int_to_dint(test_case[index].input3));
    
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
				   index, test_level_49, test_counter_49, test_loops_49, test_errors_49);
	end_if;
END_PROGRAM
