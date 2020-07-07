(*[[ ]]*)
PROGRAM mul_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 23;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of num2_num_T := [
		(input0 := 10.0, input1 := 10.0, ret_int := 100, ret_dint := 100, ret_udint := 100, ret_uint := 100, ret_real := 100.0, ret_lreal := 100.0),
		(input0 := 10.0, input1 := 2.0, ret_int := 20, ret_dint := 20, ret_udint := 20, ret_uint := 20, ret_real := 20.0, ret_lreal := 20.0),
		(input0 := -10.0, input1 := -30.0, ret_int := 300, ret_dint := 300, ret_udint := 0, ret_uint := 0, ret_real := 300.0, ret_lreal := 300.0),
		(input0 := -10.0, input1 := 5.0, ret_int := -50, ret_dint := -50, ret_udint := 0, ret_uint := 0, ret_real := -50.0, ret_lreal := -50.0)
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

	if Status = STATUS_RUNNING AND test_level_23 > TEST_DISABLED and test_loops_23 < Target then

		(* ---------- test action ---------------*)
        ret_int     := mul(lreal_to_int(test_case[index].input0), lreal_to_int(test_case[index].input1));
        ret_dint    := mul(lreal_to_dint(test_case[index].input0), lreal_to_dint(test_case[index].input1));
        ret_uint    := mul(lreal_to_uint(test_case[index].input0), lreal_to_uint(test_case[index].input1));
        ret_udint   := mul(lreal_to_udint(test_case[index].input0), lreal_to_udint(test_case[index].input1));
        ret_real    := mul(lreal_to_real(test_case[index].input0), lreal_to_real(test_case[index].input1));
        ret_lreal   := mul(test_case[index].input0, test_case[index].input1);
    
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
				   index, test_level_23, test_counter_23, test_loops_23, test_errors_23);
	end_if;
END_PROGRAM
