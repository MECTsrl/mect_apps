(*[[ ]]*)
PROGRAM trig_inv_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 16;
	test_cases : int := 7;
	xl : lreal := 0.0000000000000010;
	x : real :=   0.0000000000000001;
END_CONST
VAR
	test_case : array [1..test_cases] of lreal_lreal3_real3_T :=
[
(input:= -1.0000000000000000, retval1:=-1.5707963267948966, retval2:= 3.1415926535897931, retval3:=-0.7853981633974483, retval4:=-1.5707963267948966, retval5:= 3.1415926535897931, retval6:=-0.7853981633974483),
(input:= -0.6666666666666667, retval1:=-0.7297276562269664, retval2:= 2.3005239830218631, retval3:=-0.5880026035475676, retval4:=-0.7297276828829742, retval5:= 2.3005240096778707, retval6:=-0.5880026173024855),
(input:= -0.3333333333333334, retval1:=-0.3398369094541220, retval2:= 1.9106332362490186, retval3:=-0.3217505543966422, retval4:=-0.3398369199908341, retval5:= 1.9106332467857308, retval6:=-0.3217505633373389),
(input:=  0.0000000000000000, retval1:= 0.0000000000000000, retval2:= 1.5707963267948966, retval3:= 0.0000000000000000, retval4:= 0.0000000000000000, retval5:= 1.5707963267948966, retval6:= 0.0000000000000000),
(input:=  0.3333333333333333, retval1:= 0.3398369094541219, retval2:= 1.2309594173407747, retval3:= 0.3217505543966421, retval4:= 0.3398369199908341, retval5:= 1.2309594068040626, retval6:= 0.3217505633373389),
(input:=  0.6666666666666665, retval1:= 0.7297276562269661, retval2:= 0.8410686705679304, retval3:= 0.5880026035475675, retval4:= 0.7297276828829742, retval5:= 0.8410686439119225, retval6:= 0.5880026173024855),
(input:=  1.0000000000000000, retval1:= 1.5707963267948966, retval2:= 0.0000000000000000, retval3:= 0.7853981633974483, retval4:= 1.5707963267948966, retval5:= 0.0000000000000000, retval6:= 0.7853981633974483)
];
	input_lreal : lreal;
	input_real : real;
	retval1 : lreal;
	retval2 : lreal;
	retval3 : lreal;
	retval4 : real;
	retval5 : real;
	retval6 : real;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_16 > TEST_DISABLED and test_loops_16 < Target then

		(* ---------- test action ---------------*)
		input_lreal := test_case[index].input;
        retval1 := asin(input_lreal);
        retval2 := acos(input_lreal);
        retval3 := atan(input_lreal);
		input_real := lreal_to_real(test_case[index].input);
        retval4 := asin(input_real);
        retval5 := acos(input_real);
        retval6 := atan(input_real);
    
		(* ---------- test condition ---------------*)
        result := (abs(retval1 - test_case[index].retval1) < xl)
		      and (abs(retval2 - test_case[index].retval2) < xl)
		      and (abs(retval3 - test_case[index].retval3) < xl)
		      and (abs(retval4 - test_case[index].retval4) < x)
		      and (abs(retval5 - test_case[index].retval5) < x)
		      and (abs(retval6 - test_case[index].retval6) < x);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].retval2));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].retval3));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].retval4));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].retval5));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].retval6));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(retval1));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(retval2));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(retval3));
		obtained := CONCAT(obtained, comma_blank, real_to_string(retval4));
		obtained := CONCAT(obtained, comma_blank, real_to_string(retval5));
		obtained := CONCAT(obtained, comma_blank, real_to_string(retval6));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_16, test_counter_16, test_loops_16, test_errors_16);
	end_if;
END_PROGRAM
