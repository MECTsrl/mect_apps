(*[[
]]*)
PROGRAM ne_P
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 41;
	test_cases : int := 6;
END_CONST
VAR
	test_case : array [1..test_cases] of any2_bool_T := [
		(input0 :=  10.0, input1 :=  10.0, retval := false),
		(input0 :=  10.0, input1 :=  20.0, retval := true),
		(input0 :=  10.0, input1 :=  5.0,  retval := true),
		(input0 :=  -100.0, input1 := -100.0,  retval := false),
		(input0 :=  -100.0, input1 := 7.0,  retval := true),
		(input0 :=  -100.0, input1 := 109.0,  retval := true)
	];
	ret_bool   : bool;
	ret_byte   : bool;
	ret_dint   : bool;
	ret_dword  : bool;
	ret_int    : bool;
	ret_lreal  : bool;
	ret_real   : bool;
	ret_string : bool;	
	ret_time   : bool;
	ret_uint   : bool;
	ret_udint  : bool;
	ret_word   : bool;

	expected_ret_bool   : bool;
	expected_ret_byte   : bool;
	expected_ret_dint   : bool;
	expected_ret_dword  : bool;
	expected_ret_int    : bool;
	expected_ret_lreal  : bool;	
	expected_ret_real   : bool;
	expected_ret_string : bool;
	expected_ret_time   : bool;
	expected_ret_uint   : bool;
	expected_ret_udint  : bool;
	expected_ret_word   : bool;

	index : int := 1;
	expected: string;
	obtained: string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_41 > TEST_DISABLED and test_loops_41 < Target then

		(* ---------- test action ---------------*)
        ret_bool   := ne( lreal_to_bool(test_case[index].input0), 
						 lreal_to_bool(test_case[index].input1));
        ret_byte   := ne( lreal_to_byte(test_case[index].input0), 
						 lreal_to_byte(test_case[index].input1));
        ret_dint   := ne( lreal_to_dint(test_case[index].input0), 
						 lreal_to_dint(test_case[index].input1));
        ret_dword  := ne( lreal_to_dword(test_case[index].input0), 
						 lreal_to_dword(test_case[index].input1));
        ret_int    := ne( lreal_to_int(test_case[index].input0), 
						 lreal_to_int(test_case[index].input1));
        ret_lreal  := ne( test_case[index].input0, 
						 test_case[index].input1);
        ret_real   := ne( lreal_to_real(test_case[index].input0), 
						 lreal_to_real(test_case[index].input1));
        ret_string := ne(lreal_to_string(test_case[index].input0), 
						 lreal_to_string(test_case[index].input1));
        ret_time   := ne( lreal_to_time(test_case[index].input0), 
						 lreal_to_time(test_case[index].input1));
        ret_uint   := ne( lreal_to_uint(test_case[index].input0), 
						 lreal_to_uint(test_case[index].input1));
        ret_udint  := ne(lreal_to_udint(test_case[index].input0), 
						 lreal_to_udint(test_case[index].input1));
        ret_word   := ne( lreal_to_word(test_case[index].input0), 
						 lreal_to_word(test_case[index].input1));

		IF (test_case[index].input0 <> 0.0 and test_case[index].input1 <> 0.0)
			or (test_case[index].input0 = 0.0 and test_case[index].input1 = 0.0)THEN
        	expected_ret_bool   := false;
        ELSE
        	expected_ret_bool   := true;
		END_IF;

		expected_ret_byte   := test_case[index].retval;
		expected_ret_dint   := test_case[index].retval;
		expected_ret_dword  := test_case[index].retval;
		expected_ret_int    := test_case[index].retval;
		expected_ret_lreal  := test_case[index].retval;
		expected_ret_real   := test_case[index].retval;
		expected_ret_string := test_case[index].retval;
		expected_ret_time   := test_case[index].retval;
		expected_ret_uint   := test_case[index].retval;
		expected_ret_udint  := test_case[index].retval;
		expected_ret_word   := test_case[index].retval;
    
		(* ---------- test condition ---------------*)
        result := (ret_bool = expected_ret_bool) 
				  and (ret_byte = expected_ret_byte)
				  and (ret_dint = expected_ret_dint)
				  and (ret_dword = expected_ret_dword)
				  and (ret_int = expected_ret_int)
				  and (ret_lreal = expected_ret_lreal)
				  and (ret_real = expected_ret_real)
				  and (ret_string = expected_ret_string)
				  and (ret_time = expected_ret_time)
				  and (ret_uint = expected_ret_uint)
				  and (ret_udint = expected_ret_udint)
				  and (ret_word = expected_ret_word);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_bool));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_byte));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_dint));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_dword));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_int));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_lreal));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_real));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_string));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_time));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_uint));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_udint));
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_word));
		
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_string));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_time));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_uint));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_udint));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_word));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_41, test_counter_41, test_loops_41, test_errors_41);
	end_if;

END_PROGRAM
