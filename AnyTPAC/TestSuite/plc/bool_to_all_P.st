(*[[ ]]*)
PROGRAM bool_to_all_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 1;
	test_cases : int := 2;
END_CONST
VAR
	test_case : array [1..test_cases] of bool_all_T := [
		(input := false, ret_byte := 0, ret_dint := 0, ret_dword := 0, ret_int := 0, ret_lreal := 0.0, ret_real := 0.0, 
		   ret_string := 'false', ret_udint := 0, ret_uint := 0, ret_word := 0),
		(input := true, ret_byte := 1, ret_dint := 1, ret_dword := 1, ret_int := 1, ret_lreal := 1.0, ret_real := 1.0, 
		   ret_string := 'true', ret_udint := 1, ret_uint := 1, ret_word := 1)
	];
    ret_byte   : byte;
    ret_dint   : dint;
    ret_dword  : dword;
    ret_int    : int;
    ret_lreal  : lreal;
    ret_real   : real;
    ret_string : string;
    ret_udint  : udint;
    ret_uint   : uint;
    ret_word   : word;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_01 > TEST_DISABLED and test_loops_01 < Target then

		(* ---------- test action ---------------*)
        ret_byte   := bool_to_byte(test_case[index].input);
        ret_dint   := bool_to_dint(test_case[index].input);
        ret_dword  := bool_to_dword(test_case[index].input);
        ret_int    := bool_to_int(test_case[index].input);
        ret_lreal  := bool_to_lreal(test_case[index].input);
        ret_real   := bool_to_real(test_case[index].input);
        ret_string := bool_to_string(test_case[index].input);
        ret_udint  := bool_to_udint(test_case[index].input);
        ret_uint   := bool_to_uint(test_case[index].input);
        ret_word   := bool_to_word(test_case[index].input);
    
		(* ---------- test condition ---------------*)
        result := (ret_byte = test_case[index].ret_byte)
		      and (ret_dint = test_case[index].ret_dint)
		      and (ret_dword = test_case[index].ret_dword)
		      and (ret_int = test_case[index].ret_int)
		      and (ret_lreal = test_case[index].ret_lreal)
		      and (ret_real = test_case[index].ret_real)
		      and (ret_string = test_case[index].ret_string)
		      and (ret_udint = test_case[index].ret_udint)
		      and (ret_uint = test_case[index].ret_uint)
		      and (ret_word = test_case[index].ret_word);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, byte_to_string(test_case[index].ret_byte));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		expected := CONCAT(expected, comma_blank, dword_to_string(test_case[index].ret_dword));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, test_case[index].ret_string);
		expected := CONCAT(expected, comma_blank, udint_to_string(test_case[index].ret_udint));
		expected := CONCAT(expected, comma_blank, uint_to_string(test_case[index].ret_uint));
		expected := CONCAT(expected, comma_blank, word_to_string(test_case[index].ret_word));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, byte_to_string(ret_byte));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, dword_to_string(ret_dword));
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, ret_string);
		obtained := CONCAT(obtained, comma_blank, udint_to_string(ret_udint));
		obtained := CONCAT(obtained, comma_blank, uint_to_string(ret_uint));
		obtained := CONCAT(obtained, comma_blank, word_to_string(ret_word));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_01, test_counter_01, test_loops_01, test_errors_01);
	end_if;
END_PROGRAM
