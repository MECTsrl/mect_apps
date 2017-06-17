(*[[
]]*)
FUNCTION set_min_dint
VAR_IN_OUT
    A : DINT;
END_VAR
VAR_INPUT
    B : DINT;
END_VAR

	if A < 0 or B < A then
		A := B;
	end_if;

END_FUNCTION
