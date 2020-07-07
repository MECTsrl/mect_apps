(*[[ ]]*)
PROGRAM and_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 27;
	test_cases : int := 13;
END_CONST
VAR
	test_case : array [1..test_cases] of bit2_bit_T := [
		(input0 := 0, 		    input1 := 0, 	 	   ret_bool := 0, ret_byte := 0, 	 ret_word := 0, 	ret_dword := 0),
		(input0 := 0, 			input1 := 1, 	   	   ret_bool := 0, ret_byte := 0, 	 ret_word := 0, 	ret_dword := 0),
		(input0 := 1, 			input1 := 0, 	   	   ret_bool := 0, ret_byte := 0, 	 ret_word := 0, 	ret_dword := 0),
		(input0 := 1, 			input1 := 1, 	       ret_bool := 1, ret_byte := 1, 	 ret_word := 1, 	ret_dword := 1),
		(input0 := 0, 			input1 := 16#000000ff, ret_bool := 0, ret_byte := 0, 	 ret_word := 0, 	ret_dword := 0),
		(input0 := 16#000000ff, input1 := 16#000000ff, ret_bool := 1, ret_byte := 16#ff, ret_word := 16#00ff, ret_dword := 16#000000ff),
		(input0 := 16#0000000f, input1 := 16#000000f0, ret_bool := 1, ret_byte := 16#00, ret_word := 16#0000, ret_dword := 16#00000000),
		(input0 := 16#0000ffff, input1 := 16#0000ffff, ret_bool := 1, ret_byte := 16#ff, ret_word := 16#ffff, ret_dword := 16#0000ffff),
		(input0 := 16#0000ffff, input1 := 16#000000ff, ret_bool := 1, ret_byte := 16#ff, ret_word := 16#00ff, ret_dword := 16#000000ff),
		(input0 := 16#0000f000, input1 := 16#0000ffff, ret_bool := 1, ret_byte := 16#00, ret_word := 16#f000, ret_dword := 16#0000f000),
		(input0 := 16#000000ff, input1 := 16#0000ff00, ret_bool := 1, ret_byte := 16#00, ret_word := 16#0000, ret_dword := 16#00000000),
		(input0 := 16#abcde012, input1 := 16#ffffffff, ret_bool := 1, ret_byte := 16#12, ret_word := 16#e012, ret_dword := 16#abcde012),
		(input0 := 16#abcdefab, input1 := 16#ff000000, ret_bool := 1, ret_byte := 16#00, ret_word := 16#0000, ret_dword := 16#ab000000)
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

	if Status = STATUS_RUNNING AND test_level_27 > TEST_DISABLED and test_loops_27 < Target then

		(* ---------- test action ---------------*)
        ret_bool   := and(dword_to_bool(test_case[index].input0), dword_to_bool(test_case[index].input1));
        ret_byte   := and(dword_to_byte(test_case[index].input0), dword_to_byte(test_case[index].input1));
        ret_word   := and(dword_to_word(test_case[index].input0), dword_to_word(test_case[index].input1));
        ret_dword  := and(test_case[index].input0, test_case[index].input1);
    
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
				   index, test_level_27, test_counter_27, test_loops_27, test_errors_27);
	end_if;
END_PROGRAM
