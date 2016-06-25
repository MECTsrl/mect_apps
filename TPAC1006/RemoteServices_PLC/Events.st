(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	if LOC_Rising then
		LOC_DigOut_4 := 1;
	end_if;
	if LOC_Falling then
		LOC_DigOut_4 := 0;
	end_if;

	if RTU_Rising then
		RTU_DigOut_4 := 1;
	end_if;
	if RTU_Falling then
		RTU_DigOut_4 := 0;
	end_if;

	if CAN_Rising then
		CAN_DigOut_4 := 1;
	end_if;
	if CAN_Falling then
		CAN_DigOut_4 := 0;
	end_if;

	if TCP_Rising then
		TCP_DigOut_4 := 1;
	end_if;
	if TCP_Falling then
		TCP_DigOut_4 := 0;
	end_if;

END_PROGRAM
