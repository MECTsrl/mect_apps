(*[[
]]*)
PROGRAM ct_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 54;
	test_cases : int := 12;
END_CONST
VAR
	test_case : array [1..test_cases] of bool2_bool_int2_T := [
		(input1 := false, input2 := true,  retval1 := false, retval2 := 3, retval3 := 0),
		(input1 := false, input2 := false, retval1 := false, retval2 := 3, retval3 := 0),
		(input1 := true,  input2 := false, retval1 := false, retval2 := 2, retval3 := 1),

		(input1 := false, input2 := false, retval1 := false, retval2 := 2, retval3 := 1),
		(input1 := true,  input2 := false, retval1 := false, retval2 := 1, retval3 := 2),
		(input1 := true,  input2 := false, retval1 := false, retval2 := 1, retval3 := 2),

		(input1 := false, input2 := false, retval1 := false, retval2 := 1, retval3 := 2),
		(input1 := true,  input2 := false, retval1 := true,  retval2 := 0, retval3 := 3),
		(input1 := true,  input2 := false, retval1 := true,  retval2 := 0, retval3 := 3),

		(input1 := false, input2 := true,  retval1 := false, retval2 := 3, retval3 := 0),
		(input1 := false, input2 := false, retval1 := false, retval2 := 3, retval3 := 0),
		(input1 := true,  input2 := false, retval1 := false, retval2 := 2, retval3 := 1)
	];
    retval1  : bool;
    retval1bis : bool;
    retval2  : int;
    retval3  : int;

	CTD_Inst : CTD;
	CTU_Inst : CTU;
	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_54 > TEST_DISABLED and test_loops_54 < Target then

		(* ---------- test action ---------------*)
		CTD_Inst(
			CD := test_case[index].input1, LD := test_case[index].input2, PV := 3,
			Q => retval1, CV => retval2);
		CTU_Inst(
			CU := test_case[index].input1, R := test_case[index].input2, PV := 3,
			Q => retval1bis, CV => retval3);

		(* ---------- test condition ---------------*)
        result := (retval1 = test_case[index].retval1)
		      and (retval1bis = test_case[index].retval1)
		      and (retval2 = test_case[index].retval2)
			  and (retval3 = test_case[index].retval3);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, bool_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].retval2));
		expected := CONCAT(expected, comma_blank, int_to_string(test_case[index].retval3));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, bool_to_string(retval1));
		obtained := CONCAT(obtained, comma_blank, bool_to_string(retval1bis));
		obtained := CONCAT(obtained, comma_blank, int_to_string(retval2));
		obtained := CONCAT(obtained, comma_blank, int_to_string(retval3));
		
		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_54, test_counter_54, test_loops_54, test_errors_54);
	end_if;
END_PROGRAM
