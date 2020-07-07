(*[[
]]*)
PROGRAM mux_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 34;
	test_cases : int := 3;
END_CONST
VAR
	test_case : array [1..test_cases] of int_any3_any_T := [
		(input := 0, input0 :=  1.0, input1 :=  2.0, input2 :=  3.0, retval := 1.0),
		(input := 1, input0 :=  1.0, input1 :=  2.0, input2 :=  3.0, retval := 2.0),
		(input := 2, input0 :=  1.0, input1 :=  2.0, input2 :=  3.0, retval := 3.0)
	];
	ret_bool  : bool;
	ret_byte  : byte;
	ret_int   : int;
	ret_word  : word;
	ret_dint  : dint;
	ret_dword : dword;
	ret_time  : time;
	ret_real  : real;
	ret_lreal : lreal;	
	ret_string : string;	

	expected_ret_bool  : bool;
	expected_ret_byte  : byte;
	expected_ret_int   : int;
	expected_ret_word  : word;
	expected_ret_dint  : dint;
	expected_ret_dword : dword;
	expected_ret_time  : time;
	expected_ret_real  : real;
	expected_ret_lreal : lreal;	
	expected_ret_string : string;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_34 > TEST_DISABLED and test_loops_34 < Target then

		(* ---------- test action ---------------*)
        ret_bool  := mux(test_case[index].input, 
						 lreal_to_bool(test_case[index].input0), 
						 lreal_to_bool(test_case[index].input1), 
						 lreal_to_bool(test_case[index].input2));
        ret_byte  := mux(test_case[index].input, 
						 lreal_to_byte(test_case[index].input0), 
						 lreal_to_byte(test_case[index].input1), 
						 lreal_to_byte(test_case[index].input2));
        ret_int  := mux(test_case[index].input, 
						 lreal_to_int(test_case[index].input0), 
						 lreal_to_int(test_case[index].input1), 
						 lreal_to_int(test_case[index].input2));
        ret_word  := mux(test_case[index].input, 
						 lreal_to_word(test_case[index].input0), 
						 lreal_to_word(test_case[index].input1), 
						 lreal_to_word(test_case[index].input2));
        ret_dint  := mux(test_case[index].input, 
						 lreal_to_dint(test_case[index].input0), 
						 lreal_to_dint(test_case[index].input1), 
						 lreal_to_dint(test_case[index].input2));
        ret_dword  := mux(test_case[index].input, 
						 lreal_to_dword(test_case[index].input0), 
						 lreal_to_dword(test_case[index].input1), 
						 lreal_to_dword(test_case[index].input2));
        ret_time  := mux(test_case[index].input, 
						 lreal_to_time(test_case[index].input0), 
						 lreal_to_time(test_case[index].input1), 
						 lreal_to_time(test_case[index].input2));
        ret_real  := mux(test_case[index].input, 
						 lreal_to_real(test_case[index].input0), 
						 lreal_to_real(test_case[index].input1), 
						 lreal_to_real(test_case[index].input2));
        ret_lreal  := mux(test_case[index].input, 
						 test_case[index].input0, 
						 test_case[index].input1, 
						 test_case[index].input2);
        ret_string  := mux(test_case[index].input, 
						 lreal_to_string(test_case[index].input0), 
						 lreal_to_string(test_case[index].input1), 
						 lreal_to_string(test_case[index].input2));

		expected_ret_bool   := lreal_to_bool(test_case[index].retval);
		expected_ret_byte   := lreal_to_byte(test_case[index].retval);
		expected_ret_int    := lreal_to_int(test_case[index].retval);
		expected_ret_word   := lreal_to_word(test_case[index].retval);
		expected_ret_dint   := lreal_to_dint(test_case[index].retval);
		expected_ret_dword  := lreal_to_dword(test_case[index].retval);
		expected_ret_time   := lreal_to_time(test_case[index].retval);
		expected_ret_real   := lreal_to_real(test_case[index].retval);
		expected_ret_lreal  := test_case[index].retval;
		expected_ret_string := lreal_to_string(test_case[index].retval);

    
		(* ---------- test condition ---------------*)
        result := (ret_bool = expected_ret_bool)
				  and (ret_byte = expected_ret_byte)
				  and (ret_int = expected_ret_int)
				  and (ret_word = expected_ret_word)
				  and (ret_dint = expected_ret_dint)
				  and (ret_dword = expected_ret_dword)
				  and (ret_time = expected_ret_time)
				  and (ret_real = expected_ret_real)
				  and (ret_lreal = expected_ret_lreal)
				  and (ret_string = expected_ret_string);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(expected_ret_bool));
		expected := CONCAT(expected, comma_blank, byte_to_string(expected_ret_byte));
		expected := CONCAT(expected, comma_blank, int_to_string(expected_ret_int));
		expected := CONCAT(expected, comma_blank, word_to_string(expected_ret_word));
		expected := CONCAT(expected, comma_blank, dint_to_string(expected_ret_dint));
		expected := CONCAT(expected, comma_blank, dword_to_string(expected_ret_dword));
		expected := CONCAT(expected, comma_blank, time_to_string(expected_ret_time));
		expected := CONCAT(expected, comma_blank, real_to_string(expected_ret_real));
		expected := CONCAT(expected, comma_blank, lreal_to_string(expected_ret_lreal));
		expected := CONCAT(expected, comma_blank, expected_ret_string);
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, time_to_string(ret_time));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, ret_string);

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_34, test_counter_34, test_loops_34, test_errors_34);
	end_if;

END_PROGRAM
