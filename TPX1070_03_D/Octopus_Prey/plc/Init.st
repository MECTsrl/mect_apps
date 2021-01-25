(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

    PLC_FastIO_Ena := 16#000000FF;
    PLC_FastIO_Dir := 16#000000F0;

	MPNC005_DigDir_3 := 0; (* RTU3 RD *)
	MPNC005_DigDir_4 := 1; (* RTU3 WR *)

	TEST_STATUS := STATUS_LOCAL;

END_PROGRAM

