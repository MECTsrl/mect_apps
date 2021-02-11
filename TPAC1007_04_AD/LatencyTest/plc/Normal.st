(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"

(* --------- Dig_I/O config --------- *)
if PLC_DigDir_1 = false then
	PLC_DigDir_1 := true;
end_if;
if PLC_DigDir_2 = true then
	PLC_DigDir_2 := false;
end_if;
if PLC_DigDir_3 = false then
	PLC_DigDir_3 := true;
end_if;

(* --------- An_I/O config --------- *)
if PLC_AnInConf_1 <> 2 then
	PLC_AnInConf_1 := 2;
end_if;
if PLC_AnOutConf_1 <> 2 then
	PLC_AnOutConf_1 := 2;
end_if;
if PLC_AnOutConf_2 <> 2 then
	PLC_AnOutConf_2 := 2;
end_if;

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

