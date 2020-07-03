(*[[ ]]*)
PROGRAM len_P
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 47;
	test_cases : int := 3;
END_CONST
VAR
	test_case : array [1..test_cases] of string_int_T := [
		(input := '', retval := 0),
		(input := 'stringa_in_cui_eseguire_la_ricerca', retval := 34),
		(input := 'Buzz, Woody e Jessie', retval := 20)
	];
    retval0   : int;
    retval1   : dint;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_47 > TEST_DISABLED and test_loops_47 < Target then

		(* ---------- test action ---------------*)
        retval0 := len(test_case[index].input);
        retval1 := len(test_case[index].input);
    
		(* ---------- test condition ---------------*)
        result := (retval0 = test_case[index].retval)
		      and (retval1 = int_to_dint(test_case[index].retval));

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].retval));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].retval));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, int_to_string(retval0));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(retval1));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_47, test_counter_47, test_loops_47, test_errors_47);
	end_if;
END_PROGRAM
