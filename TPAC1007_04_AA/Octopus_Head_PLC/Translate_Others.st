(*[[
]]*)
FUNCTION Translate_Others
#import "Crosstable.gvl"
VAR_INPUT
END_VAR

	if TST_Tamb  then
		TSTx_Tamb := TRUE;
	end_if;

	if TST_RPM  then
		TSTx_RPM := TRUE;
		(* <-- Horn2 AO3 PWM *) 
		TST2_AnOut_3 := 1;
		VAL2_AnOutConf_3 := 3; (* PWM *)
		VAL2_AnOut_3 := UINT_TO_INT(VAL_RPM); (* FIXME: conversion ? *)
	end_if;

	if TST_FWrevision  then
		TSTx_FWrevision := TRUE;
	end_if;

	if TST_HWconfig then
		TSTx_HWconfig := TRUE;
	end_if;

	(* only from the testing equipment *)
	if TST_VCC_set then
		(* --> Head AO3 V *) 
		PLC_AnOutConf_3 := 2; (* 0..10 V *)
		PLC_AnOut_3 := VAL_VCC_set; (* FIXME: conversion ? *)
	end_if;

	if TST_mA_max then
		(* --> Head AO4 V *) 
		PLC_AnOutConf_4 := 2; (* 0..10 V *)
		PLC_AnOut_4 := VAL_mA_max; (* FIXME: conversion ? *)
	end_if;

	if TST_VCC_fbk then
		(* --> Head AI1 V *) 
		PLC_AnInConf_1 := 2; (* 0..10 V *)
	end_if;

	if TST_mA_fbk then
		(* --> Head AI2 V *) 
		PLC_AnInConf_2 := 2; (* 0..10 V *)
	end_if;

END_FUNCTION
