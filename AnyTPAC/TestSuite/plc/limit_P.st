(*[[ ]]*)
PROGRAM limit_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 31;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of num3_num_T := [
		(input0 := 10.0,  input1 := 20.0,  input2 := 30.0,  ret_byte := 20, ret_word := 20, ret_dword := 20, ret_int := 20, ret_dint := 20, 
															ret_time := t#20ms, ret_real := 20.0, ret_lreal := 20.0, ret_string := '20'),
		(input0 := 20.0,  input1 := 10.0,  input2 := 30.0,  ret_byte := 20, ret_word := 20, ret_dword := 20, ret_int := 20, ret_dint := 20, 
															ret_time := t#20ms, ret_real := 20.0, ret_lreal := 20.0, ret_string := '20'),
		(input0 := 10.0,  input1 := 90.0, input2 := 20.0,  ret_byte := 20, ret_word := 20, ret_dword := 20, ret_int := 20, ret_dint := 20,
															ret_time := t#20ms, ret_real := 20.0, ret_lreal := 20.0, ret_string := '20'),
		(input0 := 20.0,  input1 := 90.0, input2 := 20.0,  ret_byte := 20, ret_word := 20, ret_dword := 20, ret_int := 20, ret_dint := 20,
															ret_time := t#20ms, ret_real := 20.0, ret_lreal := 20.0, ret_string := '20')
	];
    ret_byte   : byte;
    ret_word   : word;
    ret_dword  : dword;
    ret_int    : int;
    ret_dint   : dint;
    ret_time   : time;
    ret_real   : real;
    ret_lreal  : lreal;
    ret_string : string;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_31 > TEST_DISABLED and test_loops_31 < Target then

		(* ---------- test action ---------------*)
        ret_byte    := limit(lreal_to_byte(test_case[index].input0), lreal_to_byte(test_case[index].input1), lreal_to_byte(test_case[index].input2));
        ret_word    := limit(lreal_to_word(test_case[index].input0), lreal_to_word(test_case[index].input1), lreal_to_word(test_case[index].input2));
        ret_dword   := limit(lreal_to_dword(test_case[index].input0), lreal_to_dword(test_case[index].input1), lreal_to_dword(test_case[index].input2));
        ret_int     := limit(lreal_to_int(test_case[index].input0), lreal_to_int(test_case[index].input1), lreal_to_int(test_case[index].input2));
        ret_dint    := limit(lreal_to_dint(test_case[index].input0), lreal_to_dint(test_case[index].input1), lreal_to_dint(test_case[index].input2));
        ret_time    := limit(lreal_to_time(test_case[index].input0), lreal_to_time(test_case[index].input1), lreal_to_time(test_case[index].input2));
        ret_real    := limit(lreal_to_real(test_case[index].input0), lreal_to_real(test_case[index].input1), lreal_to_real(test_case[index].input2));
        ret_lreal   := limit(test_case[index].input0, test_case[index].input1, test_case[index].input2);
        ret_string    := limit(lreal_to_string(test_case[index].input0), lreal_to_string(test_case[index].input1), lreal_to_string(test_case[index].input2));
		
		(* ---------- test condition ---------------*)
        result := ((ret_byte = test_case[index].ret_byte)
			  and (ret_word = test_case[index].ret_word)
			  and (ret_dword = test_case[index].ret_dword)
			  and (ret_int = test_case[index].ret_int)
		      and (ret_dint = test_case[index].ret_dint)
		      and (ret_time = test_case[index].ret_time)
		      and (ret_real = test_case[index].ret_real)
		      and (ret_lreal = test_case[index].ret_lreal)
		      and (ret_string = test_case[index].ret_string));

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].ret_time));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, test_case[index].ret_string);
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, time_to_string(ret_time));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, ret_string);

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_31, test_counter_31, test_loops_31, test_errors_31);
	end_if;
END_PROGRAM
