(*[[ ]]*)
PROGRAM ro_P (* gestisce sia rol che ror *)
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 25;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of bit2_bit2_T := [
		(input0 := 16#abcdef11, input1 := 0, ret_bool := 1, ret_byte := 16#11, ret_word := 16#ef11, ret_dword := 16#abcdef11,
											 ret_bool2 := 1, ret_byte2 := 16#11, ret_word2 := 16#ef11, ret_dword2 := 16#abcdef11),
		(input0 := 16#abcdef11, input1 := 1, ret_bool := 1, ret_byte := 16#22, ret_word := 16#de23, ret_dword := 16#579bde23,
											 ret_bool2 := 1, ret_byte2 := 16#88, ret_word2 := 16#f788, ret_dword2 := 16#d5e6f788),
		(input0 := 16#abcdef12, input1 := 2, ret_bool := 1, ret_byte := 16#48, ret_word := 16#bc4b, ret_dword := 16#af37bc4a,
											 ret_bool2 := 1, ret_byte2 := 16#84, ret_word2 := 16#bbc4, ret_dword2 := 16#aaf37bc4),
		(input0 := 16#abcdef12, input1 := 4, ret_bool := 1, ret_byte := 16#21, ret_word := 16#f12e, ret_dword := 16#bcdef12a,
											 ret_bool2 := 1, ret_byte2 := 16#21, ret_word2 := 16#2ef1, ret_dword2 := 16#2abcdef1),
		(input0 := 16#abcdef12, input1 := 7, ret_bool := 1, ret_byte := 16#09, ret_word := 16#8977, ret_dword := 16#e6f78955,
											 ret_bool2 := 1, ret_byte2 := 16#24, ret_word2 := 16#25de, ret_dword2 := 16#25579bde)
	];
    ret_bool   : bool;
    ret_byte   : byte;
    ret_word   : word;
    ret_dword  : dword;
    ret_bool2  : bool;
    ret_byte2  : byte;
    ret_word2  : word;
    ret_dword2 : dword;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_25 > TEST_DISABLED and test_loops_25 < Target then

		(* ---------- test action ---------------*)
        ret_bool   := rol(dword_to_bool(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_byte   := rol(dword_to_byte(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_word   := rol(dword_to_word(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_dword  := rol(test_case[index].input0, dword_to_int(test_case[index].input1));
        ret_bool2  := ror(dword_to_bool(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_byte2  := ror(dword_to_byte(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_word2  := ror(dword_to_word(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_dword2 := ror(test_case[index].input0, dword_to_int(test_case[index].input1));
    
		(* ---------- test condition ---------------*)
        result := (ret_bool = test_case[index].ret_bool)
		      and (ret_byte = test_case[index].ret_byte)
		      and (ret_word = test_case[index].ret_word)
		      and (ret_dword = test_case[index].ret_dword)
			  and (ret_bool2 = test_case[index].ret_bool2)
		      and (ret_byte2 = test_case[index].ret_byte2)
		      and (ret_word2 = test_case[index].ret_word2)
		      and (ret_dword2 = test_case[index].ret_dword2);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].ret_bool));
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword));
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].ret_bool2));
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte2));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word2));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword2));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool2));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte2));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word2));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword2));
		
		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_25, test_counter_25, test_loops_25, test_errors_25);
	end_if;
END_PROGRAM
