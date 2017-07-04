(*[[
]]*)
PROGRAM Fast 
#import "Crosstable.gvl"
#import "Resource1.gvl"

	if PLC_DigIn_3 and not PLC_DigOut_4 then
		PLC_DigOut_4 := 1;
	elsif not PLC_DigIn_3 and PLC_DigOut_4 then
		PLC_DigOut_4 := 0;
	end_if;

	if RTU_DigIn_3 and not RTU_DigOut_4 then
		RTU_DigOut_4 := 1;
	elsif not RTU_DigIn_3 and RTU_DigOut_4 then
		RTU_DigOut_4 := 0;
	end_if;

	if Rtubis_DigIn_3 and not RTUbis_DigOut_4 then
		RTUbis_DigOut_4 := 1;
	elsif not RTUbis_DigIn_3 and RTUbis_DigOut_4 then
		RTUbis_DigOut_4 := 0;
	end_if;

	if TCP_DigIn_3 and not TCP_DigOut_4 then
		TCP_DigOut_4 := 1;
	elsif not TCP_DigIn_3 and TCP_DigOut_4 then
		TCP_DigOut_4 := 0;
	end_if;

END_PROGRAM

