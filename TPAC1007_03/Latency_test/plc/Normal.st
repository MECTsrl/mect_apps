(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	
END_VAR
	
	TCP_AnIn_1 := PLC_AnIn_1;
	TCP_AnIn_2 := PLC_AnIn_2;
	(* TCP_DigIn_3 and TCP_DigOut_4 are managed in the Events program *)
	
	RTUbis_AnIn_1 := PLC_AnIn_1;
	RTUbis_AnIn_2 := PLC_AnIn_2;
	(* RTUbis_DigIn_3 and RTUbis_DigOut_4 are managed in the Events program *)

END_PROGRAM

