(*[[
]]*)
FUNCTION_BLOCK fb_TPAC_tic
	#import "TPACLocaIO.gvl"
VAR_INPUT
	tic:TIME;
END_VAR
VAR
END_VAR
	PLC_time:=PLC_time + 0.001 * TIME_TO_REAL(tic);
	IF PLC_time > 86400.0 THEN
		PLC_time:=0.0;
	END_IF;
	if PLC_time > 10.0 then
		PLC_timeMax := PLC_time;
		PLC_timeMin := PLC_time - 10.0;
	else
		PLC_timeMax := 10.0;
		PLC_timeMin := 0.0;
	end_if;
END_FUNCTION_BLOCK
