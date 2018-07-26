(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	TEST_STATUS := STATUS_LOCAL;

    PLC_FastIO_Ena := 16#000000FF;
    PLC_FastIO_Dir := 16#0000000F;

END_PROGRAM

