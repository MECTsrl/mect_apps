(*[[
]]*)
FUNCTION RegolazioneOnOff
VAR_INPUT
    SetPoint : INT;
    Delta : INT;
    TheTemp : INT;
END_VAR
VAR_IN_OUT
    OnOff : BOOL;
END_VAR

	if TheTemp <= (SetPoint - Delta) then
		OnOff := true;
	elsif (SetPoint + Delta) < TheTemp then
		OnOff := false;
	else
		; (* OnOff rimane com'è *)
    end_if;

END_FUNCTION
