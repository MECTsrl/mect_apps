(*[[ ]]*)
PROGRAM uint_to_all_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 12;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of uint_all_T := [
		(input := 0, ret_bool := 0, ret_byte := 0, ret_dint := 0, ret_dword := 0, ret_int := 0, ret_lreal := 0.0, 
		   ret_real := 0.0, ret_string := '0', ret_word := 0),
		(input := 1, ret_bool := 1, ret_byte := 1, ret_dint := 1, ret_dword := 1, ret_int := 1, ret_lreal := 1.0, 
		   ret_real := 1.0, ret_string := '1', ret_word := 1),
		(input := 255, ret_bool := 1, ret_byte := 255, ret_dint := 255, ret_dword := 255, ret_int := 255, ret_lreal := 255.0, 
		   ret_real := 255.0, ret_string := '255', ret_word := 255),
		(input := 2559, ret_bool := 1, ret_byte := 255, ret_dint := 2559, ret_dword := 2559, ret_int := 2559, ret_lreal := 2559.0, 
		   ret_real := 2559.0, ret_string := '2559', ret_word := 2559)
	];
    ret_bool   : bool;
    ret_byte   : byte;
    ret_dint   : dint;
    ret_dword  : dword;
    ret_int    : int;
    ret_lreal  : lreal;
    ret_real   : real;
    ret_string : string;
    ret_word   : word;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR


	if Status = STATUS_RUNNING AND test_level_12 > TEST_DISABLED and test_loops_12 < Target then

		(* ---------- test action ---------------*)
        ret_bool   := uint_to_bool(test_case[index].input);
        ret_byte   := uint_to_byte(test_case[index].input);
        ret_dint   := uint_to_dint(test_case[index].input);
        ret_dword  := uint_to_dword(test_case[index].input);
        ret_int    := uint_to_int(test_case[index].input);
        ret_lreal  := uint_to_lreal(test_case[index].input);
        ret_real   := uint_to_real(test_case[index].input);
        ret_string := uint_to_string(test_case[index].input);
        ret_word   := uint_to_word(test_case[index].input);
    
		(* ---------- test condition ---------------*)
        result := (ret_bool = test_case[index].ret_bool)
		      and (ret_byte = test_case[index].ret_byte)
		      and (ret_dint = test_case[index].ret_dint)
		      and (ret_dword = test_case[index].ret_dword)
		      and (ret_int = test_case[index].ret_int)
		      and (ret_lreal = test_case[index].ret_lreal)
		      and (ret_real = test_case[index].ret_real)
		      and (ret_string = test_case[index].ret_string)
		      and (ret_word = test_case[index].ret_word);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].ret_bool));
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, test_case[index].ret_string);
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(ret_bool));
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, ret_string);
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_12, test_counter_12, test_loops_12, test_errors_12);
	end_if;
END_PROGRAM
