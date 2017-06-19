(*[[
]]*)
PROGRAM Slow 
#import "Crosstable.gvl"
#import "Resource1.gvl"

	(* PLC_DigIn_7 =---> PLC_DigIn_5 *)
	(* PLC_DigIn_5 =---> DigOut_6, RTUbis_DigIn_3, TCP_DigIn_3 *)

	if PLC_DigOut_7 then
		PLC_DigOut_7   := 0;
		RTUbis_DigIn_3 := 0;
		TCP_DigIn_3    := 0;
	else
		PLC_DigOut_7   := 1;
		RTUbis_DigIn_3 := 1;
		TCP_DigIn_3    := 1;
	end_if;

END_PROGRAM

