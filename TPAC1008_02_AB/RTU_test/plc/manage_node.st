(*[[
]]*)
FUNCTION manage_node : BOOL
VAR_INPUT
    DigIn_7_nodexx : BOOL;
    latency_ms : DINT;
	value : BOOL;
END_VAR
VAR_IN_OUT
    latency_xx_ms : DINT;
    min_latency_xx_m : DINT;
    max_latency_xx_m : DINT;
END_VAR

	if latency_xx_ms = -1 and DigIn_7_nodexx = value then
		(* ok arrived *)
	    latency_xx_ms := latency_ms;
		set_min_dint(min_latency_xx_m, latency_ms);
		set_max_dint(max_latency_xx_m, latency_ms);
		manage_node := true;
	else
		manage_node := false;
	end_if;	

END_FUNCTION
