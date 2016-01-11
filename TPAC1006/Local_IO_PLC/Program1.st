(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
VAR
	d: DINT;
END_VAR
	d := d + 1;
(*
	if (d mod 10) = 0 then
		PLC_DigOut_12 := 1;
	end_if;
	if (d mod 10) = 5 then
		PLC_DigOut_12 := 0;
	end_if;
*)
END_PROGRAM
