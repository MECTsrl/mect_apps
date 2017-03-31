(*[[
]]*)
FUNCTION check_node
VAR_INPUT
    latency_xx_ms : DINT;
    NODE_xx_STATUS : UDINT;
END_VAR
VAR_IN_OUT
    errors_xx : DINT;
    errors_all : DINT;
    min_latency_ms : DINT;
    max_latency_ms : DINT;
END_VAR

	if latency_xx_ms = 0 or NODE_xx_STATUS <> 1 then
		errors_xx := errors_xx + 1;
		errors_all := errors_all + 1;
	end_if;

	set_min_dint(min_latency_ms, latency_xx_ms);
	set_max_dint(max_latency_ms, latency_xx_ms);

END_FUNCTION
