(*[[
]]*)
PROGRAM hi_byte_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 58;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of bit_bit2_T := [
		(input := 0, 			ret_byte := 16#00, ret_word := 16#0000, ret_byte2 := 16#00, ret_word2 := 16#0000),
		(input := 16#ffffffff, 	ret_byte := 16#ff, ret_word := 16#ffff, ret_byte2 := 16#ff, ret_word2 := 16#ffff),
		(input := 16#5678, 		ret_byte := 16#56, ret_word := 16#0000, ret_byte2 := 16#78, ret_word2 := 16#5678),
		(input := 16#12345678, 	ret_byte := 16#56, ret_word := 16#1234, ret_byte2 := 16#78, ret_word2 := 16#5678)
	];
    ret_byte   : byte;
    ret_word   : word;
    ret_byte2  : byte;
    ret_word2  : word;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_58 > TEST_DISABLED and test_loops_58 < Target then

		(* ---------- test action ---------------*)
        ret_byte   := hi_byte(dword_to_word(test_case[index].input));
        ret_word   := hi_word(test_case[index].input);
        ret_byte2  := lo_byte(dword_to_word(test_case[index].input));
        ret_word2  := lo_word(test_case[index].input);
		    
		(* ---------- test condition ---------------*)
        result := (ret_byte = test_case[index].ret_byte)
			  and (ret_word = test_case[index].ret_word)
			  and (ret_byte2 = test_case[index].ret_byte2)
			  and (ret_word2 = test_case[index].ret_word2);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte2));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word2));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte2));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word2));
		
		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_58, test_counter_58, test_loops_58, test_errors_58);
	end_if;
END_PROGRAM
