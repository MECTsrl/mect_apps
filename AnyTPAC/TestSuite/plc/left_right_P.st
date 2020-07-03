(*[[ ]]*)
PROGRAM left_right_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 46;
	test_cases : int := 3;
END_CONST
VAR
	test_case : array [1..test_cases] of string_int_string2_T := [
		(input0 := 'stringa_di_partenza', input1 := 0, retval0 := '', retval1 := ''),
		(input0 := 'stringa_di_partenza', input1 := 2, retval0 := 'st', retval1 := 'za'),
		(input0 := 'stringa_di_partenza', input1 := 7, retval0 := 'stringa', retval1 := 'artenza')
	];
    retval0   : string;
    retval1   : string;
    retval2   : string;
    retval3   : string;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_46 > TEST_DISABLED and test_loops_46 < Target then

		(* ---------- test action ---------------*)
        retval0 := left(test_case[index].input0, test_case[index].input1);
        retval1 := left(test_case[index].input0, int_to_dint(test_case[index].input1));
        retval2 := right(test_case[index].input0, test_case[index].input1);
        retval3 := right(test_case[index].input0, int_to_dint(test_case[index].input1));
    
		(* ---------- test condition ---------------*)
        result := (retval0 = test_case[index].retval0)
		      and (retval1 = test_case[index].retval0)
		      and (retval2 = test_case[index].retval1)
		      and (retval3 = test_case[index].retval1);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, test_case[index].retval0);
		expected := CONCAT(expected, comma_blank, test_case[index].retval0);
		expected := CONCAT(expected, comma_blank, test_case[index].retval1);
		expected := CONCAT(expected, comma_blank, test_case[index].retval1);
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, retval0);
		obtained := CONCAT(obtained, comma_blank, retval1);
		obtained := CONCAT(obtained, comma_blank, retval2);
		obtained := CONCAT(obtained, comma_blank, retval3);

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_46, test_counter_46, test_loops_46, test_errors_46);
	end_if;
END_PROGRAM
