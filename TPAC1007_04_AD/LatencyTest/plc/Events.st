(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
#import "Resource1.gvl"

(* --------- signal reaction --------- *)
(* PLC_AnOut_2 is set in Normal.st @ 100ms *)
if InputRising then
	PLC_DigOut_3 := true;
elsif InputFalling then
	PLC_DigOut_3 := false;
end_if;

END_PROGRAM

