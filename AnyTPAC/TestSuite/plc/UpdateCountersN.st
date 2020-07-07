(*[[
]]*)
FUNCTION UpdateCountersN
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR_INPUT
	test_level_N : UINT;
END_VAR

	CASE test_level_N OF
	TEST_DISABLED:
		DisabledTests := DisabledTests + 1;
	TEST_UNKNOWN:
		TestingTests := TestingTests + 1;
	TEST_PASSED:
		PassedTests := PassedTests + 1;
	TEST_FAILED:
		FailedTests := FailedTests + 1;
	ELSE
    	;
    END_CASE;
END_FUNCTION
