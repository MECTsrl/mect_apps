(*[[
]]*)
PROGRAM concat_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 42;
	test_cases : int := 3;
END_CONST
VAR
	test_case : array [1..test_cases] of string3_string_T := [
		(input0 := 'prima', input1 := '_seconda', input2 := '_terza',  retval := 'prima_seconda_terza'),
		(input0 := 'testa', input1 := '', input2 := '_coda',  retval := 'testa_coda'),
		(input0 := '', input1 := 'senza', input2 := '_testa', retval := 'senza_testa')
	];
    retval : string;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_42 > TEST_DISABLED and test_loops_42 < Target then

		(* ---------- test action ---------------*)
        retval := concat(test_case[index].input0, test_case[index].input1, test_case[index].input2);
    
		(* ---------- test condition ---------------*)
        result := (retval = test_case[index].retval);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, test_case[index].retval);
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, retval);

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_42, test_counter_42, test_loops_42, test_errors_42);
	end_if;
END_PROGRAM
