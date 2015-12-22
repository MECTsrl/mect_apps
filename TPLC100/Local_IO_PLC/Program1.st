(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
VAR
	first : bool := true;
END_VAR
	if first then
		first := false;
		PLC_AddressWord := 16#0000;
		PLC_ControlWord := 16#3042;
	end_if;
END_PROGRAM
