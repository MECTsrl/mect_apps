(*[[ ]]*)
PROGRAM make_word_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 59;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of bit2_bit_T := [
		(input0 := 16#0000, input1 := 16#0000, ret_word := 16#0000, ret_dword := 16#00000000),
		(input0 := 16#00ff, input1 := 16#00ff, ret_word := 16#ffff, ret_dword := 16#00ff00ff),
		(input0 := 16#1234, input1 := 16#abcd, ret_word := 16#cd34, ret_dword := 16#abcd1234),
		(input0 := 16#1122, input1 := 16#3344, ret_word := 16#4422, ret_dword := 16#33441122)
	];
    ret_word   : word;
    ret_dword  : dword;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_59 > TEST_DISABLED and test_loops_59 < Target then

		(* ---------- test action ---------------*)
        ret_dword := make_dword(dword_to_word(test_case[index].input0), dword_to_word(test_case[index].input1));
        ret_word  := make_word( dword_to_byte(test_case[index].input0), dword_to_byte(test_case[index].input1));
    
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
				   index, test_level_59, test_counter_59, test_loops_59, test_errors_59);
	end_if;
END_PROGRAM
