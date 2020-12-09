(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	a : int;
END_VAR
	
	if ContinuousWritingPLC then
		a := PLC_AnOut_1;
		a := (a + 1) mod 1000;
		PLC_AnOut_1 := a;
    end_if;
	
END_PROGRAM

