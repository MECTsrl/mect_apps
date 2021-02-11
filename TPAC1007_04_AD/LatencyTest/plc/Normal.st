(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"

(* --------- signal reaction --------- *)
(* PLC_DigOut_3 is set in Events.st @ rising/falling events *)
if EnabledBis then
	PLC_AnOut_2 := PLC_AnIn_1 / 10;
elsif PLC_AnOut_2 <> 0 then
	PLC_AnOut_2 := 0;
end_if;

END_PROGRAM

