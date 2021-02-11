(*[[
]]*)
PROGRAM Slow 
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

(* --------- signal generation --------- *)

if Enabled then
	if (PLC_DigOut_1) then
		PLC_DigOut_1 := false;
		PLC_AnOut_1 := 222; (* 2.22 V *)
	else 
		PLC_DigOut_1 := true;
		PLC_AnOut_1 := 888; (* 8.88 V *)
	end_if;
else
	if (PLC_DigOut_1) then
		PLC_DigOut_1 := false;
	end_if;
	if (PLC_AnOut_1 <> 0) then
		PLC_AnOut_1 := 0; (* 0.00 V *)
	end_if;
end_if;

END_PROGRAM

