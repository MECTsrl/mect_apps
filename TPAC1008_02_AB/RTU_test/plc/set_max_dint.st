(*[[
]]*)
FUNCTION set_max_dint
VAR_IN_OUT
    A : DINT;
END_VAR
VAR_INPUT
    B : DINT;
END_VAR

	if A < 0 or A < B then
		A := B;
	end_if;

END_FUNCTION
