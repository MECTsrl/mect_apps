(*[[
]]*)
PROGRAM Writer 
#import "Crosstable.gvl"
#import "Resource1.gvl"

(* --------- signal generation --------- *)

if (PLC_DigOut_1) then
	PLC_DigOut_1 := false;
	PLC_AnOut_1 := 222; (* 2.22 V *)
else 
	PLC_DigOut_1 := true;
	PLC_AnOut_1 := 888; (* 8.88 V *)
end_if;

END_PROGRAM

