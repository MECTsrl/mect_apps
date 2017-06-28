(*[[
]]*)
PROGRAM Slow 
#import "Crosstable.gvl"
#import "Resource1.gvl"

	(* toggle PLC_DigOut_7 =---> PLC_DigIn_5 (short circuit) *)

	if PLC_DigOut_7 then
		PLC_DigOut_7   := 0;
	else
		PLC_DigOut_7   := 1;
	end_if;

END_PROGRAM

