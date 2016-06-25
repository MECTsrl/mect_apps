(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	
END_VAR

TCP_AnIn_1 := PLC_AnIn_1;
TCP_AnIn_2 := PLC_AnIn_2;
TCP_DigIn_3 := PLC_DigIn_3;
if (PLC_DigOut_4 <> TCP_DigOut_4) then
	PLC_DigOut_4 := TCP_DigOut_4;
end_if;

END_PROGRAM
