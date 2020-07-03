(*[[ ]]*)
PROGRAM trig_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 15;
	test_cases : int := 7;
	xl : lreal := 0.0000000000000001;
	x : real := 0.0000000000000001;
END_CONST
VAR
	test_case : array [1..test_cases] of lreal_lreal3_real3_T :=
[
(input:= 0.0000000000000000, retval1:= 0.0000000000000000, retval2:= 1.0000000000000000, retval3:= 0.0000000000000000, retval4:= 0.0000000000000000, retval5:= 1.0000000000000000, retval6:= 0.0000000000000000),
(input:= 1.0471975511965976, retval1:= 0.8660254037844386, retval2:= 0.5000000000000001, retval3:= 1.7320508075688767, retval4:= 0.8660254183549017, retval5:= 0.4999999747632170, retval6:= 1.7320509241325899),
(input:= 2.0943951023931953, retval1:= 0.8660254037844387, retval2:=-0.4999999999999998, retval3:=-1.7320508075688783, retval4:= 0.8660253746435105, retval5:=-0.5000000504735648, retval6:=-1.7320505744414876),
(input:= 3.1415926535897931, retval1:= 0.0000000000000001, retval2:=-1.0000000000000000, retval3:=-0.0000000000000001, retval4:=-0.0000000874227800, retval5:=-0.9999999999999962, retval6:= 0.0000000874227800),
(input:= 4.1887902047863905, retval1:=-0.8660254037844384, retval2:=-0.5000000000000004, retval3:= 1.7320508075688754, retval4:=-0.8660254620662861, retval5:=-0.4999998990528655, retval6:= 1.7320512738237981),
(input:= 5.2359877559829879, retval1:=-0.8660254037844390, retval2:= 0.4999999999999993, retval3:=-1.7320508075688805, retval4:=-0.8660254501414079, retval5:= 0.4999999197073655, retval6:=-1.7320511784247199),
(input:= 6.2831853071795862, retval1:=-0.0000000000000002, retval2:= 1.0000000000000000, retval3:=-0.0000000000000002, retval4:= 0.0000001748455600, retval5:= 0.9999999999999847, retval6:= 0.0000001748455600)
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

	if Status = STATUS_RUNNING AND test_level_15 > TEST_DISABLED and test_loops_15 < Target then

		(* ---------- test action ---------------*)
		input_lreal := test_case[index].input;
        retval1 := sin(input_lreal);
        retval2 := cos(input_lreal);
        retval3 := tan(input_lreal);
		input_real := lreal_to_real(test_case[index].input);
        retval4 := sin(input_real);
        retval5 := cos(input_real);
        retval6 := tan(input_real);
    
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
				   index, test_level_15, test_counter_15, test_loops_15, test_errors_15);
	end_if;
END_PROGRAM
