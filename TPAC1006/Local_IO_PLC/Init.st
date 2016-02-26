(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"

	PLC_AnInConf := 16#2222; (* 0..10V *)		
	PLC_AnOutConf := 16#22; (* 0..10V *)

	TEST_STATUS := STATUS_LOCAL;

END_PROGRAM
