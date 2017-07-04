(*[[
]]*)
PROGRAM Fast 
#import "Crosstable.gvl"
#import "Resource1.gvl"

	(* PLC_DigIn_5 =---> RTUbis_DigIn_3, TCP_DigIn_3 *)

	if PLC_DigIn_5 then
		if not RTUbis_DigIn_3 then RTUbis_DigIn_3 := 1; end_if;
		if not TCP_DigIn_3	  then TCP_DigIn_3    := 1; end_if;
	else
		if RTUbis_DigIn_3 then RTUbis_DigIn_3 := 0; end_if;
		if TCP_DigIn_3    then TCP_DigIn_3    := 0; end_if;
	end_if;

	(* RTUbis_DigOut_4 =---> PLC_DigOut_6 *)

	if RTUbis_DigOut_4 and not PLC_DigOut_6 then
		PLC_DigOut_6 := 1;
	elsif not RTUbis_DigOut_4 and PLC_DigOut_6 then
		PLC_DigOut_6 := 0;
	end_if;

	(* TCP_DigOut_4 =---> PLC_DigOut_8 *)

	if TCP_DigOut_4 and not PLC_DigOut_8 then
		PLC_DigOut_8 := 1;
	elsif not TCP_DigOut_4 and PLC_DigOut_8 then
		PLC_DigOut_8 := 0;
	end_if;

END_PROGRAM

