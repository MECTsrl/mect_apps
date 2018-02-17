(*[[
]]*)
PROGRAM Fast 
#import "Crosstable.gvl"
#import "Resource1.gvl"

	if (LOC_DigIn_3 = 1 and LOC_DigOut_4 = 0) then
		LOC_DigOut_4 := 1;
	end_if;
	if (LOC_DigIn_3 = 0 and LOC_DigOut_4 = 1) then
		LOC_DigOut_4 := 0;
	end_if;

	if (RTU_DigIn_3 = 1 and RTU_DigOut_4 = 0) then
		RTU_DigOut_4 := 1;
	end_if;
	if (RTU_DigIn_3 = 0 and RTU_DigOut_4 = 1)then
		RTU_DigOut_4 := 0;
	end_if;

	if (CAN_DigIn_3 = 1 and CAN_DigOut_4 = 0)then
		CAN_DigOut_4 := 1;
	end_if;
	if (CAN_DigIn_3 = 0 and CAN_DigOut_4 = 1)then
		CAN_DigOut_4 := 0;
	end_if;

	if (TCP_DigIn_3 = 1 and TCP_DigOut_4 = 0)then
		TCP_DigOut_4 := 1;
	end_if;
	if (TCP_DigIn_3 = 0 and TCP_DigOut_4 = 1)then
		TCP_DigOut_4 := 0;
	end_if;

END_PROGRAM
