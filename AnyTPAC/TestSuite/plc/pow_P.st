(*[[ ]]*)
PROGRAM pow_P 
#import "Crosstable.gvl"
#import "Resource1.gvl"
CONST
	this : int := 17;
	test_cases : int := 7;
	xl : lreal := 0.0000000000000001;
	x : real := 0.0000000000000001;
END_CONST
VAR
	test_case : array [1..test_cases] of lreal_lreal4_real4_T :=
[
(input:= 0.4487989505128276, retval1:=  1.5664296956520809, retval2:=-0.8011802632059132, retval3:=-0.3479481673201230, retval4:= 0.6699245856906788, retval5:=  1.5664297018771030, retval6:=-0.8011802543511257, retval7:=-0.3479481634745377, retval8:= 0.6699245886566987),
(input:= 0.8975979010256552, retval1:=  2.4537019914206710, retval2:=-0.1080330826459679, retval3:=-0.0469181716561418, retval4:= 0.9474164348509346, retval5:=  2.4537020109227896, retval6:=-0.1080330737911804, retval7:=-0.0469181678105565, retval8:= 0.9474164390455202),
(input:= 1.3463968515384828, retval1:=  3.8435516636419869, retval2:= 0.2974320254621965, retval3:= 0.1291730873995394, retval4:= 1.1603434196557856, retval5:=  3.8435514803715054, retval6:= 0.2974319900472387, retval7:= 0.1291730720190187, retval8:= 1.1603433991090293),
(input:= 1.7951958020513104, retval1:=  6.0206534627017669, retval2:= 0.5851140979139774, retval3:= 0.2541118240078394, retval4:= 1.3398491713813576, retval5:=  6.0206535584065408, retval6:= 0.5851141067687649, retval7:= 0.2541118278534247, retval8:= 1.3398491773133974),
(input:= 2.2439947525641379, retval1:=  9.4309303712065766, retval2:= 0.8082576492281872, retval3:= 0.3510218370158958, retval4:= 1.4979969134027407, retval5:=  9.4309299964728268, retval6:= 0.8082576315211277, retval7:= 0.3510218293258176, retval8:= 1.4979969001401805),
(input:= 2.6927937030769655, retval1:= 14.7728893910850854, retval2:= 0.9905792060221418, retval3:= 0.4302030830635206, retval4:= 1.6409734010875878, retval5:= 14.7728879822659920, retval6:= 0.9905791706071840, retval7:= 0.4302030676829999, retval8:= 1.6409733720300863),
(input:= 3.1415926535897931, retval1:= 23.1406926327792668, retval2:= 1.1447298858494002, retval3:= 0.4971498726941338, retval4:= 1.7724538509055159, retval5:= 23.1406946558030384, retval6:= 1.1447299136769349, retval7:= 0.4971498847794786, retval8:= 1.7724538755670267)
];
	input_lreal : lreal;
	input_real : real;
	retval1 : lreal;
	retval2 : lreal;
	retval3 : lreal;
	retval4 : lreal;
	retval5 : real;
	retval6 : real;
	retval7 : real;
	retval8 : real;

	index : int := 1;
	expected : string;
	obtained : string;
	result : bool;
END_VAR

	if Status = STATUS_RUNNING AND test_level_17 > TEST_DISABLED and test_loops_17 < Target then

		(* ---------- test action ---------------*)
		input_lreal := test_case[index].input;
		retval1 := exp(input_lreal);
		retval2 := ln(input_lreal);
		retval3 := log(input_lreal);
		retval4 := sqrt(input_lreal);
		input_real := lreal_to_real(test_case[index].input);
		retval5 := exp(input_real);
		retval6 := ln(input_real);
		retval7 := log(input_real);
		retval8 := sqrt(input_real);
    
		(* ---------- test condition ---------------*)
		result := (abs(retval1 - test_case[index].retval1) < xl)
		      and (abs(retval2 - test_case[index].retval2) < xl)
		      and (abs(retval3 - test_case[index].retval3) < xl)
		      and (abs(retval4 - test_case[index].retval4) < xl)
		      and (abs(retval5 - test_case[index].retval5) < x)
		      and (abs(retval6 - test_case[index].retval6) < x)
		      and (abs(retval7 - test_case[index].retval7) < x)
		      and (abs(retval8 - test_case[index].retval8) < x);

		(* ---------- log message ---------------*)
		expected := '';
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].retval1));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].retval2));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].retval3));
		expected := CONCAT(expected, comma_blank, lreal_to_string(test_case[index].retval4));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].retval5));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].retval6));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].retval7));
		expected := CONCAT(expected, comma_blank, real_to_string(test_case[index].retval8));
		obtained := '';
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(retval1));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(retval2));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(retval3));
		obtained := CONCAT(obtained, comma_blank, lreal_to_string(retval4));
		obtained := CONCAT(obtained, comma_blank, real_to_string(retval5));
		obtained := CONCAT(obtained, comma_blank, real_to_string(retval6));
		obtained := CONCAT(obtained, comma_blank, real_to_string(retval7));
		obtained := CONCAT(obtained, comma_blank, real_to_string(retval8));

		(* ---------- cycle ----------*)
		SingleTest(this, result, expected, obtained, test_cases,
				   index, test_level_17, test_counter_17, test_loops_17, test_errors_17);
	end_if;
END_PROGRAM
