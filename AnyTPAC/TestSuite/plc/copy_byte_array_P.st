(*[[
]]*)
PROGRAM copy_byte_array_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 57;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of all_T := 
[
(in_bool:=0, in_byte:=0,   in_dint:=0,      in_dword:=0,   in_int:=0,   in_lreal:=0.0,   in_real:=0.0, 
  in_string:='',			in_time:=t#0s, in_word:=0),
(in_bool:=1, in_byte:=1,   in_dint:=1,      in_dword:=1,   in_int:=1,   in_lreal:=1.1,   in_real:=1.1, 
  in_string:='1',			in_time:=t#1s, in_word:=1),
(in_bool:=0, in_byte:=255, in_dint:=254,    in_dword:=253, in_int:=252, in_lreal:=251.0, in_real:=250.0, 
  in_string:='stringa',		in_time:=t#249s, in_word:=16#248),
(in_bool:=0, in_byte:=111, in_dint:=123456, in_dword:=16#abcdef01, in_int:=23871, in_lreal:=0.01, in_real:=0.02, 
  in_string:='stringa_molto_ma_molto_lunga', in_time:=t#249s, in_word:=16#abcd),
(in_bool:=0, in_byte:=16#ff, in_dint:=102030, in_dword:=16#1b0def01, in_int:=2387, in_lreal:=1.01, in_real:=2.02, 
  in_string:='stringa_veramente_molto_ma_molto_ma_molto_ma_molto_lunga', in_time:=t#249ms, in_word:=16#ffbb)
];
	
	ret_bool   : bool;
	ret_byte   : byte;
	ret_dint   : dint;
	ret_dword  : dword;
	ret_int    : int;
	ret_lreal  : lreal;
	ret_real   : real;
	ret_string : string;
	ret_time   : time;
	ret_word   : word;
	byte_array : array[0..800] of byte;

	pos   : dint;
	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_57 > TEST_DISABLED and test_loops_57 < Target then
	
		(* ---------- test action ---------------*)
		pos := 1;
		copy_bool_to_byte_array (test_case[index].in_bool, pos, byte_array);
		copy_byte_to_byte_array (test_case[index].in_byte, pos, byte_array);
		copy_dint_to_byte_array (test_case[index].in_dint, pos, byte_array);
		copy_dword_to_byte_array (test_case[index].in_dword, pos, byte_array);
		copy_int_to_byte_array  (test_case[index].in_int, pos, byte_array);
		copy_lreal_to_byte_array (test_case[index].in_lreal, pos, byte_array);
		copy_real_to_byte_array (test_case[index].in_real, pos, byte_array);
		copy_time_to_byte_array (test_case[index].in_time, pos, byte_array);
		copy_word_to_byte_array (test_case[index].in_word, pos, byte_array);
		copy_string_to_byte_array (test_case[index].in_string, pos, byte_array);
    
		pos := 1;
		ret_bool   := copy_bool_from_byte_array (pos, byte_array);
		ret_byte   := copy_byte_from_byte_array (pos, byte_array);
		ret_dint   := copy_dint_from_byte_array (pos, byte_array);
		ret_dword  := copy_dword_from_byte_array(pos, byte_array);
		ret_int    := copy_int_from_byte_array  (pos, byte_array);
		ret_lreal  := copy_lreal_from_byte_array(pos, byte_array);
		ret_real   := copy_real_from_byte_array (pos, byte_array);
		ret_time   := copy_time_from_byte_array (pos, byte_array);
		ret_word   := copy_word_from_byte_array (pos, byte_array);
		ret_string := copy_string_from_byte_array(pos, byte_array);

		(* NOTA BENE: la copy_string_*_byte_array funziona bene solo se è l'ultima;
		   altrimenti le funzioni successive non funzionano *)

		(* ---------- test condition ---------------*)
		result := (ret_bool   = test_case[index].in_bool)
		      and (ret_byte   = test_case[index].in_byte)
		      and (ret_dint   = test_case[index].in_dint)
		      and (ret_dword  = test_case[index].in_dword)
		      and (ret_int    = test_case[index].in_int)
		      and (ret_lreal  = test_case[index].in_lreal)
		      and (ret_real   = test_case[index].in_real)
		      and (ret_string = test_case[index].in_string)
		      and (ret_time   = test_case[index].in_time)
		      and (ret_word   = test_case[index].in_word);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].in_bool));
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].in_byte));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].in_dint));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].in_dword));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].in_int));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].in_lreal));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].in_real));
		expected := CONCAT(expected, comma_blank, test_case[index].in_string);
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].in_time));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].in_word));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, ret_string);
		obtained := CONCAT(obtained, comma_blank, time_to_string(ret_time));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_57, test_counter_57, test_loops_57, test_errors_57);
	end_if;

END_PROGRAM
