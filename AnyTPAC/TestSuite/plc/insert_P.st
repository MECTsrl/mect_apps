(*[[ ]]*)
PROGRAM insert_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 45;
	test_cases : int := 3;
END_CONST
VAR
	test_case : array [1..test_cases] of string2_int_string_T := [
		(input0 := 'stringa_dove_inserire', input1 := 'abc_', input2 := 0,  retval := 'abc_stringa_dove_inserire'),
		(input0 := 'stringa_dove_inserire', input1 := 'abc_', input2 := 8,  retval := 'stringa_abc_dove_inserire'),
		(input0 := 'stringa_dove_inserire', input1 := 'abc_', input2 := 21, retval := 'stringa_dove_inserireabc_')
	];
    retval0   : string;
    retval1   : string;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_45 > TEST_DISABLED and test_loops_45 < Target then

		(* ---------- test action ---------------*)
        retval0 := insert(test_case[index].input0, test_case[index].input1, test_case[index].input2);
        retval1 := insert(test_case[index].input0, test_case[index].input1, int_to_dint(test_case[index].input2));
    
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
				   index, test_level_45, test_counter_45, test_loops_45, test_errors_45);
	end_if;
END_PROGRAM
