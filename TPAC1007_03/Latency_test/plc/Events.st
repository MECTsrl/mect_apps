(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
#import "Resource1.gvl"

	(* RTUbis_DigOut_4 =---> PLC_DigOut_6 *)

	if RTUbis_Rising then
		if PLC_DigOut_6 = 0 then PLC_DigOut_6 := 1; end_if;
	end_if;
	if RTUbis_Falling then
		if PLC_DigOut_6 = 1 then PLC_DigOut_6 := 0; end_if;
	end_if;


	(* TCP_DigOut_4 =---> PLC_DigOut_8 *)

	if TCP_Rising then
		if PLC_DigOut_8 = 0 then PLC_DigOut_8 := 1; end_if;
	end_if;
	if TCP_Falling then
		if PLC_DigOut_8 = 1 then PLC_DigOut_8 := 0; end_if;
	end_if;

END_PROGRAM

