(*[[
]]*)
PROGRAM Events 
#import "Crosstable.gvl"
#import "Resource1.gvl"

	if LOC_Rising then
		PLC_DigOut_4 := 1;
	end_if;
	if LOC_Falling then
		PLC_DigOut_4 := 0;
	end_if;

	if RTU_Rising then
		RTU_DigOut_4 := 1;
	end_if;
	if RTU_Falling then
		RTU_DigOut_4 := 0;
	end_if;

	if RTUbis_Rising then
		RTUbis_DigOut_4 := 1;
	end_if;
	if RTUbis_Falling then
		RTUbis_DigOut_4 := 0;
	end_if;

	if TCP_Rising then
		TCP_DigOut_4 := 1;
	end_if;
	if TCP_Falling then
		TCP_DigOut_4 := 0;
	end_if;

END_PROGRAM
