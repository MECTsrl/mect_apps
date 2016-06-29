(*[[
]]*)
PROGRAM Slow 
#import "Crosstable.gvl"
#import "Resource1.gvl"

(*
VAR
	timer : TON;
END_VAR

timer(IN := TRUE, PT := T#1s);
if timer.Q then
	timer(IN := FALSE);

	PLC_DigOut_1 := not PLC_DigOut_1;

end_if;
*)

PLC_DigOut_1 := not PLC_DigOut_1;

END_PROGRAM
