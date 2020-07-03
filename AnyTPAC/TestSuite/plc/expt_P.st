(*[[ ]]*)
PROGRAM expt_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 20;
	test_cases : int := 5;
	xl : lreal := 0.0000000000001;
	x : real := 0.0000000000001;
END_CONST
VAR
	test_case : array [1..test_cases] of num2_num_T := [
		(input0 := 2.0, input1 := 2.0, ret_real := 4.0, ret_lreal := 4.0),
		(input0 := 2.0, input1 := 3.0, ret_real := 8.0, ret_lreal := 8.0),
		(input0 := 10.0, input1 := 2.0, ret_real := 100.0, ret_lreal := 100.0),
		(input0 := 5.0, input1 := 3.0, ret_real := 125.0, ret_lreal := 125.0),
		(input0 := 10.0, input1 := -1.0, ret_real := 0.1, ret_lreal := 0.1)
	];
    ret_real_int    : real;
    ret_real_dint   : real;
    ret_real_real   : real;
    ret_real_lreal  : real;
    ret_lreal_int   : lreal;
    ret_lreal_dint  : lreal;
    ret_lreal_real  : lreal;
    ret_lreal_lreal : lreal;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_20 > TEST_DISABLED and test_loops_20 < Target then

		(* ---------- test action ---------------*)
        ret_real_int   := expt(lreal_to_real(test_case[index].input0), lreal_to_int(test_case[index].input1));
        ret_real_dint  := expt(lreal_to_real(test_case[index].input0), lreal_to_dint(test_case[index].input1));
        ret_real_real  := expt(lreal_to_real(test_case[index].input0), lreal_to_real(test_case[index].input1));
        ret_real_lreal := expt(lreal_to_real(test_case[index].input0), test_case[index].input1);

        ret_lreal_int   := expt(test_case[index].input0, lreal_to_int(test_case[index].input1));
        ret_lreal_dint  := expt(test_case[index].input0, lreal_to_dint(test_case[index].input1));
        ret_lreal_real  := expt(test_case[index].input0, lreal_to_real(test_case[index].input1));
        ret_lreal_lreal := expt(test_case[index].input0, test_case[index].input1);
    
		(* ---------- test condition ---------------*)
        result := ((abs(ret_real_int - test_case[index].ret_real) < x)
		      and (abs(ret_real_dint - test_case[index].ret_real) < x)
		      and (abs(ret_real_real - test_case[index].ret_real) < x)
		      and (abs(ret_real_lreal - test_case[index].ret_real) < x)
			  and (abs(ret_lreal_int - test_case[index].ret_lreal) < xl)
		      and (abs(ret_lreal_dint - test_case[index].ret_lreal) < xl)
		      and (abs(ret_lreal_real - test_case[index].ret_lreal) < xl)
		      and (abs(ret_lreal_lreal - test_case[index].ret_lreal) < xl));

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].ret_real));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].ret_lreal));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real_int));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real_dint));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real_real));
		obtained := CONCAT(obtained, comma_blank, real_to_string(ret_real_lreal));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal_int));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal_dint));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal_real));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(ret_lreal_lreal));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_20, test_counter_20, test_loops_20, test_errors_20);
	end_if;
END_PROGRAM
