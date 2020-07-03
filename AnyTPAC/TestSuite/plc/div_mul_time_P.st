(*[[ ]]*)
PROGRAM div_mul_time_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 51;
	test_cases : int := 4;
END_CONST
VAR
	test_case : array [1..test_cases] of time_num_time2_T := [
		(input0 := t#10ms, input1 := 1.0, retval0 := t#10ms,  retval1 := t#10ms),
		(input0 := t#20ms, input1 := 2.0, retval0 := t#10ms,  retval1 := t#40ms),
		(input0 := t#10s,  input1 := 1.0, retval0 := t#10s,   retval1 := t#10s),
		(input0 := t#20s,  input1 := 2.0, retval0 := t#10s,   retval1 := t#40s)
	];
    retval0  : time;
    retval1  : time;
    retval2  : time;
    retval3  : time;
    retval4  : time;
    retval5  : time;
    retval6  : time;
    retval7  : time;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_51 > TEST_DISABLED and test_loops_51 < Target then

		(* ---------- test action ---------------*)
        retval0   := divtime(test_case[index].input0, lreal_to_int(test_case[index].input1));
        retval1   := divtime(test_case[index].input0, lreal_to_dint(test_case[index].input1));
        retval2   := divtime(test_case[index].input0, lreal_to_real(test_case[index].input1));
        retval3   := divtime(test_case[index].input0, test_case[index].input1);

        retval4   := multime(test_case[index].input0, lreal_to_int(test_case[index].input1));
        retval5   := multime(test_case[index].input0, lreal_to_dint(test_case[index].input1));
        retval6   := multime(test_case[index].input0, lreal_to_real(test_case[index].input1));
        retval7   := multime(test_case[index].input0, test_case[index].input1);
    
		(* ---------- test condition ---------------*)
        result := ((retval0 = test_case[index].retval0)
		       and (retval1 = test_case[index].retval0)
		       and (retval2 = test_case[index].retval0)
		       and (retval3 = test_case[index].retval0)
			   and (retval4 = test_case[index].retval1)
			   and (retval5 = test_case[index].retval1)
			   and (retval6 = test_case[index].retval1)
			   and (retval7 = test_case[index].retval1));

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval0));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval0));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval0));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval0));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, time_to_string(test_case[index].retval1));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval0));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval1));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval2));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval3));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval4));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval5));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval6));
		obtained := CONCAT(obtained, comma_blank, time_to_string(retval7));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_51, test_counter_51, test_loops_51, test_errors_51);
	end_if;
END_PROGRAM
