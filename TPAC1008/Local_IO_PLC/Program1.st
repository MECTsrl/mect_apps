(*[[
]]*)
PROGRAM Program1
#import "Crosstable.gvl"
VAR
	first: BOOL := true;
END_VAR
	if first then
		first := false;
		PLC_AnInConf := 16#2222;
		PLC_AnOutConf := 16#0022;
	end_if;
END_PROGRAM
