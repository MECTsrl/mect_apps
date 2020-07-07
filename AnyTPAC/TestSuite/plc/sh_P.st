(*[[ ]]*)
PROGRAM sh_P (* gestisce sia shl che shr *)
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 26;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of bit2_bit2_T := [
		(input0 := 16#abcdef11, input1 := 0, ret_bool := 1, ret_byte := 16#11, ret_word := 16#ef11, ret_dword := 16#abcdef11,
											 ret_bool2 := 1, ret_byte2 := 16#11, ret_word2 := 16#ef11, ret_dword2 := 16#abcdef11),
		(input0 := 16#abcdef11, input1 := 1, ret_bool := 0, ret_byte := 16#22, ret_word := 16#de22, ret_dword := 16#579bde22,
											 ret_bool2 := 0, ret_byte2 := 16#08, ret_word2 := 16#7788, ret_dword2 := 16#55e6f788),
		(input0 := 16#abcdef12, input1 := 2, ret_bool := 0, ret_byte := 16#48, ret_word := 16#bc48, ret_dword := 16#af37bc48,
											 ret_bool2 := 0, ret_byte2 := 16#04, ret_word2 := 16#3bc4, ret_dword2 := 16#2af37bc4),
		(input0 := 16#abcdef12, input1 := 4, ret_bool := 0, ret_byte := 16#20, ret_word := 16#f120, ret_dword := 16#bcdef120,
											 ret_bool2 := 0, ret_byte2 := 16#01, ret_word2 := 16#0ef1, ret_dword2 := 16#0abcdef1),
		(input0 := 16#abcdef12, input1 := 7, ret_bool := 0, ret_byte := 16#00, ret_word := 16#8900, ret_dword := 16#e6f78900,
											 ret_bool2 := 0, ret_byte2 := 16#00, ret_word2 := 16#01de, ret_dword2 := 16#01579bde)
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

	if Status = STATUS_RUNNING AND test_level_26 > TEST_DISABLED and test_loops_26 < Target then

		(* ---------- test action ---------------*)
        ret_bool   := shl(dword_to_bool(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_byte   := shl(dword_to_byte(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_word   := shl(dword_to_word(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_dword  := shl(test_case[index].input0, dword_to_int(test_case[index].input1));
        ret_bool2  := shr(dword_to_bool(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_byte2  := shr(dword_to_byte(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_word2  := shr(dword_to_word(test_case[index].input0), dword_to_int(test_case[index].input1));
        ret_dword2 := shr(test_case[index].input0, dword_to_int(test_case[index].input1));
    
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
				   index, test_level_26, test_counter_26, test_loops_26, test_errors_26);
	end_if;
END_PROGRAM
