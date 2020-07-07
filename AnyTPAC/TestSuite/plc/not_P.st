(*[[ ]]*)
PROGRAM not_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 28;
	test_cases : int := 6;
END_CONST
VAR
	test_case : array [1..test_cases] of bit2_bit_T := [
		(input0 := 1, 		    ret_bool := 0, ret_byte := 16#fe, ret_word := 16#fffe, ret_dword := 16#fffffffe),
		(input0 := 0, 		    ret_bool := 1, ret_byte := 16#ff, ret_word := 16#ffff, ret_dword := 16#ffffffff),
		(input0 := 16#000000ff, ret_bool := 0, ret_byte := 16#00, ret_word := 16#ff00, ret_dword := 16#ffffff00),
		(input0 := 16#0000000f, ret_bool := 0, ret_byte := 16#f0, ret_word := 16#fff0, ret_dword := 16#fffffff0),
		(input0 := 16#0000ffff, ret_bool := 0, ret_byte := 16#00, ret_word := 16#0000, ret_dword := 16#ffff0000),
		(input0 := 16#0000f000, ret_bool := 0, ret_byte := 16#ff, ret_word := 16#0fff, ret_dword := 16#ffff0fff)
	];
    ret_bool   : bool;
    ret_byte   : byte;
    ret_word   : word;
    ret_dword  : dword;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_28 > TEST_DISABLED and test_loops_28 < Target then

		(* ---------- test action ---------------*)
        ret_bool   := not(dword_to_bool(test_case[index].input0));
        ret_byte   := not(dword_to_byte(test_case[index].input0));
        ret_word   := not(dword_to_word(test_case[index].input0));
        ret_dword  := not(test_case[index].input0);
    
		(* ---------- test condition ---------------*)
        result := (ret_bool = test_case[index].ret_bool)
		      and (ret_byte = test_case[index].ret_byte)
		      and (ret_word = test_case[index].ret_word)
		      and (ret_dword = test_case[index].ret_dword);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].ret_bool));
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		
		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_28, test_counter_28, test_loops_28, test_errors_28);
	end_if;
END_PROGRAM
