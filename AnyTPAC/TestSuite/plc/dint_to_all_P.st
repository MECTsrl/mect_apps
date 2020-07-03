(*[[
]]*)
PROGRAM dint_to_all_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 3;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of dint_all_T := [
		(input := 0, ret_bool := 0, ret_byte := 0, ret_dword := 0, ret_int := 0, ret_lreal := 0.0, ret_real := 0.0, 
		   ret_string := '0', ret_time := t#0ms, ret_udint := 0, ret_uint := 0, ret_word := 0),
		(input := 1, ret_bool := 1, ret_byte := 1, ret_dword := 1, ret_int := 1, ret_lreal := 1.0, ret_real := 1.0, 
		   ret_string := '1', ret_time := t#1ms, ret_udint := 1, ret_uint := 1, ret_word := 1),
		(input := -1, ret_bool := 1, ret_byte := 255, ret_dword := 4294967295, ret_int := -1, ret_lreal := -1.0, ret_real := -1.0, 
		   ret_string := '-1', ret_time := t#-1ms, ret_udint := 4294967295, ret_uint := 65535, ret_word := 65535),
		(input := 255, ret_bool := 1, ret_byte := 255, ret_dword := 255, ret_int := 255, ret_lreal := 255.0, ret_real := 255.0, 
		   ret_string := '255', ret_time := t#255ms, ret_udint := 255, ret_uint := 255, ret_word := 255),
		(input := 400, ret_bool := 1, ret_byte := 144, ret_dword := 400, ret_int := 400, ret_lreal := 400.0, ret_real := 400.0, 
		   ret_string := '400', ret_time := t#400ms, ret_udint := 400, ret_uint := 400, ret_word := 400)
	];
    ret_bool   : bool;
    ret_byte   : byte;
    ret_dword  : dword;
    ret_int    : int;
    ret_lreal  : lreal;
    ret_real   : real;
    ret_string : string;
    ret_time   : time;
    ret_udint  : udint;
    ret_uint   : uint;
    ret_word   : word;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_03 > TEST_DISABLED and test_loops_03 < Target then

		(* ---------- test action ---------------*)
        ret_bool   := dint_to_bool(test_case[index].input);
        ret_byte   := dint_to_byte(test_case[index].input);
        ret_dword  := dint_to_dword(test_case[index].input);
        ret_int    := dint_to_int(test_case[index].input);
        ret_lreal  := dint_to_lreal(test_case[index].input);
        ret_real   := dint_to_real(test_case[index].input);
        ret_string := dint_to_string(test_case[index].input);
        ret_time   := dint_to_time(test_case[index].input);
        ret_udint  := dint_to_udint(test_case[index].input);
        ret_uint   := dint_to_uint(test_case[index].input);
        ret_word   := dint_to_word(test_case[index].input);
    
		(* ---------- test condition ---------------*)
        result := (ret_bool = test_case[index].ret_bool)
		      and (ret_byte = test_case[index].ret_byte)
		      and (ret_dword = test_case[index].ret_dword)
		      and (ret_int = test_case[index].ret_int)
		      and (ret_lreal = test_case[index].ret_lreal)
		      and (ret_real = test_case[index].ret_real)
		      and (ret_string = test_case[index].ret_string)
		      and (ret_time = test_case[index].ret_time)
		      and (ret_udint = test_case[index].ret_udint)
		      and (ret_uint = test_case[index].ret_uint)
		      and (ret_word = test_case[index].ret_word);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].ret_bool));
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, test_case[index].ret_string);
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].ret_time));
		expected := CONCAT(expected, comma_blank, udint_to_string(test_case[index].ret_udint));
		expected := CONCAT(expected, comma_blank, uint_to_string(test_case[index].ret_uint));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, ret_string);
		obtained := CONCAT(obtained, comma_blank, udint_to_string(ret_udint));
		obtained := CONCAT(obtained, comma_blank, time_to_string(ret_time));
		obtained := CONCAT(obtained, comma_blank, uint_to_string(ret_uint));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_03, test_counter_03, test_loops_03, test_errors_03);
	end_if;

END_PROGRAM
