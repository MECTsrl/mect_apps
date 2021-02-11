(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"

(* ---- *)

if Enabled_none then
	StopLocalTask('Task3_Fast_50ms');
	StopLocalTask('Task5_Slow_2000ms');
	if (PLC_DigOut_1) then
		PLC_DigOut_1 := false;
	end_if;
	if (PLC_AnOut_1 <> 0) then
		PLC_AnOut_1 := 0; (* 0.00 V *)
	end_if;

elsif Enabled_50ms then
	StopLocalTask('Task5_Slow_2000ms');
	StartLocalTask('Task3_Fast_50ms');

elsif Enabled_2s then
	StopLocalTask('Task3_Fast_50ms');
	StartLocalTask('Task5_Slow_2000ms');

end_if;

(* --------- signal reaction --------- *)
(* PLC_DigOut_3 is set in Events.st @ rising/falling events *)
if Enabled_AnOut then
	PLC_AnOut_2 := PLC_AnIn_1 / 10;
elsif PLC_AnOut_2 <> 0 then
	PLC_AnOut_2 := 0;
end_if;

END_PROGRAM

