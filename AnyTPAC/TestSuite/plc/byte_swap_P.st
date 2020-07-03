(*[[ ]]*)
PROGRAM byte_swap_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 56;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of bit_bit_T := [
		(input := 0, 		   ret_word := 16#0000, ret_dword := 16#00000000),
		(input := 16#000000ff, ret_word := 16#ff00, ret_dword := 16#ff000000),
		(input := 16#11223344, ret_word := 16#4433, ret_dword := 16#44332211),
		(input := 16#0000ffff, ret_word := 16#ffff, ret_dword := 16#ffff0000),
		(input := 16#12131415, ret_word := 16#1514, ret_dword := 16#15141312)
	];
    ret_word   : word;
    ret_dword  : dword;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_56 > TEST_DISABLED and test_loops_56 < Target then

		(* ---------- test action ---------------*)
        ret_word   := byte_swap_word(dword_to_word(test_case[index].input));
        ret_dword  := byte_swap_dword(test_case[index].input);
    
		(* ---------- test condition ---------------*)
        result := (ret_word = test_case[index].ret_word)
		      and (ret_dword = test_case[index].ret_dword);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		
		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_56, test_counter_56, test_loops_56, test_errors_56);
	end_if;
END_PROGRAM
