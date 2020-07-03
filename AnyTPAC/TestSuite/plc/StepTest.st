(*[[
]]*)
FUNCTION StepTest
#import "Crosstable.gvl"
#import "Resource1.gvl"

VAR
	first : bool := true;
	completedLoops : UDINT := 0;
END_VAR

	if LogLevel > LOG_NOTHING then
		;
	end_if;

	(* minimun common completed loops *)
	first := true;
	completedLoops := 0;

	SetCompletedLoops(test_level_01, test_loops_01, first, completedLoops);
	SetCompletedLoops(test_level_02, test_loops_02, first, completedLoops);
	SetCompletedLoops(test_level_03, test_loops_03, first, completedLoops);
	SetCompletedLoops(test_level_04, test_loops_04, first, completedLoops);
	SetCompletedLoops(test_level_05, test_loops_05, first, completedLoops);
	SetCompletedLoops(test_level_06, test_loops_06, first, completedLoops);
	SetCompletedLoops(test_level_07, test_loops_07, first, completedLoops);
	SetCompletedLoops(test_level_08, test_loops_08, first, completedLoops);
	SetCompletedLoops(test_level_09, test_loops_09, first, completedLoops);
	SetCompletedLoops(test_level_10, test_loops_10, first, completedLoops);
	SetCompletedLoops(test_level_11, test_loops_11, first, completedLoops);
	SetCompletedLoops(test_level_12, test_loops_12, first, completedLoops);
	SetCompletedLoops(test_level_13, test_loops_13, first, completedLoops);
	SetCompletedLoops(test_level_14, test_loops_14, first, completedLoops);
	SetCompletedLoops(test_level_15, test_loops_15, first, completedLoops);
	SetCompletedLoops(test_level_16, test_loops_16, first, completedLoops);
	SetCompletedLoops(test_level_17, test_loops_17, first, completedLoops);
	SetCompletedLoops(test_level_18, test_loops_18, first, completedLoops);
	SetCompletedLoops(test_level_19, test_loops_19, first, completedLoops);
	SetCompletedLoops(test_level_20, test_loops_20, first, completedLoops);
	SetCompletedLoops(test_level_21, test_loops_21, first, completedLoops);
	SetCompletedLoops(test_level_22, test_loops_22, first, completedLoops);
	SetCompletedLoops(test_level_23, test_loops_23, first, completedLoops);
	SetCompletedLoops(test_level_24, test_loops_24, first, completedLoops);
	SetCompletedLoops(test_level_25, test_loops_25, first, completedLoops);
	SetCompletedLoops(test_level_26, test_loops_26, first, completedLoops);
	SetCompletedLoops(test_level_27, test_loops_27, first, completedLoops);
	SetCompletedLoops(test_level_28, test_loops_28, first, completedLoops);
	SetCompletedLoops(test_level_29, test_loops_29, first, completedLoops);
	SetCompletedLoops(test_level_30, test_loops_30, first, completedLoops);
	SetCompletedLoops(test_level_31, test_loops_31, first, completedLoops);
	SetCompletedLoops(test_level_32, test_loops_32, first, completedLoops);
	SetCompletedLoops(test_level_33, test_loops_33, first, completedLoops);
	SetCompletedLoops(test_level_34, test_loops_34, first, completedLoops);
	SetCompletedLoops(test_level_35, test_loops_35, first, completedLoops);
	SetCompletedLoops(test_level_36, test_loops_36, first, completedLoops);
	SetCompletedLoops(test_level_37, test_loops_37, first, completedLoops);
	SetCompletedLoops(test_level_38, test_loops_38, first, completedLoops);
	SetCompletedLoops(test_level_39, test_loops_39, first, completedLoops);
	SetCompletedLoops(test_level_40, test_loops_40, first, completedLoops);
	SetCompletedLoops(test_level_41, test_loops_41, first, completedLoops);
	SetCompletedLoops(test_level_42, test_loops_42, first, completedLoops);
	SetCompletedLoops(test_level_43, test_loops_43, first, completedLoops);
	SetCompletedLoops(test_level_44, test_loops_44, first, completedLoops);
	SetCompletedLoops(test_level_45, test_loops_45, first, completedLoops);
	SetCompletedLoops(test_level_46, test_loops_46, first, completedLoops);
	SetCompletedLoops(test_level_47, test_loops_47, first, completedLoops);
	SetCompletedLoops(test_level_48, test_loops_48, first, completedLoops);
	SetCompletedLoops(test_level_49, test_loops_49, first, completedLoops);
	SetCompletedLoops(test_level_50, test_loops_50, first, completedLoops);
	SetCompletedLoops(test_level_51, test_loops_51, first, completedLoops);
	SetCompletedLoops(test_level_52, test_loops_52, first, completedLoops);
	SetCompletedLoops(test_level_53, test_loops_53, first, completedLoops);
	SetCompletedLoops(test_level_54, test_loops_54, first, completedLoops);
	SetCompletedLoops(test_level_55, test_loops_55, first, completedLoops);
	SetCompletedLoops(test_level_56, test_loops_56, first, completedLoops);
	SetCompletedLoops(test_level_57, test_loops_57, first, completedLoops);
	SetCompletedLoops(test_level_58, test_loops_58, first, completedLoops);
	SetCompletedLoops(test_level_59, test_loops_59, first, completedLoops);
	SetCompletedLoops(test_level_60, test_loops_60, first, completedLoops);
	
	Loops := completedLoops;

END_FUNCTION
