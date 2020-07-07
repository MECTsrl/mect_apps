(*[[
]]*)
FUNCTION SetCompletedLoops
VAR_INPUT
	test_level : UINT;
	test_loops : UDINT;
END_VAR
VAR_IN_OUT
	first : BOOL;
	completedLoops : UDINT;
END_VAR

	if test_level > TEST_DISABLED then
		if first then
			first := false;
			completedLoops := test_loops;
		elsif test_loops < completedLoops then
			completedLoops := test_loops;
		end_if;
	end_if;

END_FUNCTION
