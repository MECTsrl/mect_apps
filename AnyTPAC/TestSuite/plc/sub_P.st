(*[[ ]]*)
PROGRAM sub_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 24;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of num2_num_T := [
		(input0 := 10.0, input1 := 10.0, ret_int := 0, ret_dint := 0, ret_udint := 0, ret_uint := 0, ret_real := 0.0, ret_lreal := 0.0),
		(input0 := 10.0, input1 := 100.0, ret_int := -90, ret_dint := -90, ret_udint := 4294967206, ret_uint := 65446, ret_real := -90.0, ret_lreal := -90.0),
		(input0 := 100.0, input1 := 10.0, ret_int := 90, ret_dint := 90, ret_udint := 90, ret_uint := 90, ret_real := 90.0, ret_lreal := 90.0),
		(input0 := -10.0, input1 := -40.0, ret_int := 30, ret_dint := 30, ret_udint := 0, ret_uint := 0, ret_real := 30.0, ret_lreal := 30.0)
	];
    ret_int    : int;
    ret_dint   : dint;
    ret_uint   : uint;
    ret_udint  : udint;
    ret_real   : real;
    ret_lreal  : lreal;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_24 > TEST_DISABLED and test_loops_24 < Target then

		(* ---------- test action ---------------*)
        ret_int     := sub(lreal_to_int(test_case[index].input0), lreal_to_int(test_case[index].input1));
        ret_dint    := sub(lreal_to_dint(test_case[index].input0), lreal_to_dint(test_case[index].input1));
        ret_uint    := sub(lreal_to_uint(test_case[index].input0), lreal_to_uint(test_case[index].input1));
        ret_udint   := sub(lreal_to_udint(test_case[index].input0), lreal_to_udint(test_case[index].input1));
        ret_real    := sub(lreal_to_real(test_case[index].input0), lreal_to_real(test_case[index].input1));
        ret_lreal   := sub(test_case[index].input0, test_case[index].input1);
    
		(* ---------- test condition ---------------*)
        result := ((ret_int = test_case[index].ret_int)
		      and (ret_dint = test_case[index].ret_dint)
		      and (ret_uint = test_case[index].ret_uint)
		      and (ret_udint = test_case[index].ret_udint)
		      and (ret_real = test_case[index].ret_real)
		      and (ret_lreal = test_case[index].ret_lreal));

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].ret_int));
		expected := CONCAT(expected, comma_blank, dint_to_string(test_case[index].ret_dint));
		expected := CONCAT(expected, comma_blank, uint_to_string(test_case[index].ret_uint));
		expected := CONCAT(expected, comma_blank, udint_to_string(test_case[index].ret_udint));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, int_to_string(ret_int));
		obtained := CONCAT(obtained, comma_blank, dint_to_string(ret_dint));
		obtained := CONCAT(obtained, comma_blank, uint_to_string(ret_uint));
		obtained := CONCAT(obtained, comma_blank, udint_to_string(ret_udint));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_24, test_counter_24, test_loops_24, test_errors_24);
	end_if;
END_PROGRAM
