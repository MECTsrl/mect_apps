(*[[
]]*)
PROGRAM rs_sr_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 52;
	test_cases : int := 11;
END_CONST
VAR
	test_case : array [1..test_cases] of bool2_bool2_T := [

		(input1 := false, input2 := false, retval1 := false, retval2 := false),
		(input1 := true,  input2 := false, retval1 := true,  retval2 := true),
		(input1 := false, input2 := false, retval1 := true,  retval2 := true),

		(input1 := false, input2 := false, retval1 := true,  retval2 := true),
		(input1 := false, input2 := true,  retval1 := false, retval2 := false),
		(input1 := false, input2 := false, retval1 := false, retval2 := false),

		(input1 := true,  input2 := true,  retval1 := false, retval2 := true),
		(input1 := false, input2 := false, retval1 := false, retval2 := true),
		(input1 := false, input2 := false, retval1 := false, retval2 := true),

		(input1 := false, input2 := true,  retval1 := false, retval2 := false),
		(input1 := false, input2 := false, retval1 := false, retval2 := false)
		];

    retval1  : bool;
    retval2  : bool;

	RS_Inst : RS;
	SR_Inst : SR;
	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_52 > TEST_DISABLED and test_loops_52 < Target then

		(* ---------- test action ---------------*)
		RS_Inst(S := test_case[index].input1, R1 := test_case[index].input2, Q1 => retval1);
		SR_Inst(S1 := test_case[index].input1, R := test_case[index].input2, Q1 => retval2);

		(* ---------- test condition ---------------*)
        result := (retval1 = test_case[index].retval1)
		      and (retval2 = test_case[index].retval2);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].retval2));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(retval1));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(retval2));
		
		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_52, test_counter_52, test_loops_52, test_errors_52);
	end_if;
END_PROGRAM
