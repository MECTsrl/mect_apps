(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	
END_VAR

	theHEARTBEAT := theHEARTBEAT + 1; 
	if PLC_DigIn_1 then
		theBUTTON := 1;
	else
		theBUTTON := 0;
	end_if;
	if theLED = 0 and PLC_DigOut_2 then
		PLC_DigOut_2 := false;
	elsif theLED <> 0 and not PLC_DigOut_2 then
		PLC_DigOut_2 := true;
	end_if;

END_PROGRAM

