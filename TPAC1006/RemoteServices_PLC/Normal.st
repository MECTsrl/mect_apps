(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	
END_VAR
	
S_RTU_AnIn_1 := RTU_AnIn_1;
S_RTU_AnIn_2 := RTU_AnIn_2;
S_TCP_AnIn_1 := TCP_AnIn_1;
S_TCP_AnIn_2 := TCP_AnIn_2;
S_CAN_AnIn_1 := CAN_AnIn_1;
S_CAN_AnIn_2 := CAN_AnIn_2;
S_LOC_AnIn_1 := LOC_AnIn_1;
S_LOC_AnIn_2 := LOC_AnIn_2;

if RTU_DigIn_3 then
    S_RTU_DigIn_3  := 1;
else
    S_RTU_DigIn_3  := 0;
end_if;
if RTU_DigOut_4 then
    S_RTU_DigOut_4 := 1;
else
    S_RTU_DigOut_4 := 0;
end_if;
if TCP_DigIn_3 then
    S_TCP_DigIn_3  := 1;
else
    S_TCP_DigIn_3  := 0;
end_if;
if TCP_DigOut_4 then
    S_TCP_DigOut_4 := 1;
else
    S_TCP_DigOut_4 := 0;
end_if;
if CAN_DigIn_3 then
    S_CAN_DigIn_3  := 1;
else
    S_CAN_DigIn_3  := 0;
end_if;
if CAN_DigOut_4 then
    S_CAN_DigOut_4 := 1;
else
    S_CAN_DigOut_4 := 0;
end_if;
if LOC_DigIn_3 then
    S_LOC_DigIn_3  := 1;
else
    S_LOC_DigIn_3  := 0;
end_if;
if LOC_DigOut_4 then
    S_LOC_DigOut_4 := 1;
else
    S_LOC_DigOut_4 := 0;
end_if;

END_PROGRAM
