(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	LOC_configured : bool := false;
	RTU_configured : bool := false;
END_VAR
	
	if not LOC_configured and CH0_NETGOOD then

		PLC_AnInConf_1 := 2; (* 0..10 V*)
		PLC_AnInConf_2 := 2; (* 0..10 V*)

		PLC_AnOutConf_1 := 2; (* 0..10 V*)
		PLC_AnOutConf_2 := 2; (* 0..10 V*)

		LOC_configured := true;
	end_if;

	if not RTU_configured and RTU3_STATUS = 2 then

		RTU_AnInConf_1 := 2; (* 0..10 V*)
		RTU_AnInConf_2 := 2; (* 0..10 V*)

		RTU_DigDir_3 := 0; (* input *)
		RTU_DigDir_4 := 1; (* output *)

		RTU_configured := true;
	end_if;

	if LOC_configured then
		PLC_AnOut_1 := PLC_AnIn_1;
		PLC_AnOut_2 := PLC_AnIn_2;
	end_if;

END_PROGRAM

