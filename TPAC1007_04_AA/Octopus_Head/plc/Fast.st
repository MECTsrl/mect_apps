(*[[
]]*)
PROGRAM Fast 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	if PLC_DigIn_1 and VccDrop then
		(* PowerON and start Vcc drop test *)
		if PLC_DigOut_2 then
			(* first step: drop Vcc *)
			PLC_DigOut_2 := false;
		else
			(* second step: re-enable Vcc and stop the test *)
			PLC_DigOut_2 := true;
			VccDrop := false;
		end_if;
	end_if;

END_PROGRAM

