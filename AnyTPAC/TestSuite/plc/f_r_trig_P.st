(*[[
]]*)
PROGRAM f_r_trig_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 53;
	test_cases : int := 5;
END_CONST
VAR
	test_case : array [1..test_cases] of bool_bool2_T := [
		(input := false, retval1 := false, retval2 := false),
		(input := true,  retval1 := false, retval2 := true ),
		(input := true,  retval1 := false, retval2 := false),
		(input := false, retval1 := true,  retval2 := false),
		(input := false, retval1 := false, retval2 := false)
	];
    retval1  : bool;
    retval2  : bool;

	F_TRIG_Inst : f_trig;
	R_TRIG_Inst : r_trig;
	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_53 > TEST_DISABLED and test_loops_53 < Target then

		(* ---------- test action ---------------*)
		F_TRIG_Inst(CLK := test_case[index].input, Q => retval1);
		R_TRIG_Inst(CLK := test_case[index].input, Q => retval2);
    
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
				   index, test_level_53, test_counter_53, test_loops_53, test_errors_53);
	end_if;
END_PROGRAM
