(*[[ ]]*)
PROGRAM find_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 44;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of string2_int_T := [
		(input0 := 'stringa_in_cui_eseguire_la_ricerca', input1 := 'stringa',  retval := 1),
		(input0 := 'stringa_in_cui_eseguire_la_ricerca', input1 := 'in_cui',   retval := 9),
		(input0 := 'stringa_in_cui_eseguire_la_ricerca', input1 := 'ricerca',  retval := 28),
		(input0 := 'stringa_in_cui_eseguire_la_ricerca', input1 := 'stringa_che_non_esiste',  retval := 0)
	];
    retval0   : int;
    retval1   : dint;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_44 > TEST_DISABLED and test_loops_44 < Target then

		(* ---------- test action ---------------*)
        retval0 := find(test_case[index].input0, test_case[index].input1);
        retval1 := find(test_case[index].input0, test_case[index].input1);
    
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
				   index, test_level_44, test_counter_44, test_loops_44, test_errors_44);
	end_if;
END_PROGRAM
