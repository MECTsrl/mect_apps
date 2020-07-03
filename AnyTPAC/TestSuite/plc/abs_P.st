(*[[
]]*)
PROGRAM abs_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 14;
	test_cases : int := 3;
END_CONST
VAR
	test_case : array [1..test_cases] of lreal_any_num_T := 
[
(input:=-3.1415926535897931, ret_dint:= 3, ret_int:= 3, ret_lreal:= 3.1415926535897931, ret_real:= 3.1415926535897931),
(input:= 0.0000000000000000, ret_dint:= 0, ret_int:= 0, ret_lreal:= 0.0000000000000000, ret_real:= 0.0000000000000000),
(input:= 3.1415926535897931, ret_dint:= 3, ret_int:= 3, ret_lreal:= 3.1415926535897931, ret_real:= 3.1415926535897931)
];
	input_dint ,ret_dint   : dint;
	input_int  ,ret_int    : int;
	input_lreal,ret_lreal  : lreal;
	input_real ,ret_real   : real;
(* 
    error C1546: type mismatch: parameter 1 of 'ABS' needs type 'ANY_NUM' but actual is 'BYTE'
    error C1546: type mismatch: parameter 1 of 'ABS' needs type 'ANY_NUM' but actual is 'DWORD'
    error C1562: no implementation found for function overload 'UDINT ABS(UDINT)'
    error C1562: no implementation found for function overload 'UINT ABS(UINT)'
    error C1546: type mismatch: parameter 1 of 'ABS' needs type 'ANY_NUM' but actual is 'WORD'
*)

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_14 > TEST_DISABLED and test_loops_14 < Target then

		(* ---------- test action ---------------*)
		input_dint  := lreal_to_dint (test_case[index].input);
		input_int   := lreal_to_int  (test_case[index].input);
		input_lreal := test_case[index].input;
		input_real  := lreal_to_real (test_case[index].input);

		ret_dint  := abs(input_dint );
		ret_int   := abs(input_int  );
		ret_lreal := abs(input_lreal);
		ret_real  := abs(input_real );
    
		(* ---------- test condition ---------------*)
		result := (ret_dint  = test_case[index].ret_dint )
		      and (ret_int   = test_case[index].ret_int  )
		      and (ret_lreal = test_case[index].ret_lreal)
		      and (ret_real  = test_case[index].ret_real );

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint ));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int  ));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real ));
		obtained := '';
		obtained := CONCAT(expected, comma_blank, dint_to_string(ret_dint ));
		obtained := CONCAT(expected, comma_blank, int_to_string(ret_int  ));
		obtained := CONCAT(expected, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(expected, comma_blank, real_to_string(ret_real ));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_14, test_counter_14, test_loops_14, test_errors_14);
	end_if;

END_PROGRAM
