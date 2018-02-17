(*[[
]]*)
PROGRAM Slow 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

S_LOC_AnIn_1 := LOC_AnIn_1;
S_RTU_AnIn_1 := RTU_AnIn_1;
S_CAN_AnIn_1 := CAN_AnIn_1;
S_TCP_AnIn_1 := TCP_AnIn_1;

S_LOC_AnIn_2 := LOC_AnIn_2;
S_RTU_AnIn_2 := RTU_AnIn_2;
S_CAN_AnIn_2 := CAN_AnIn_2;
S_TCP_AnIn_2 := TCP_AnIn_2;

S_LOC_DigIn_3  := BOOL_TO_UINT(LOC_DigIn_3);
S_RTU_DigIn_3  := BOOL_TO_UINT(RTU_DigIn_3);
S_CAN_DigIn_3  := BOOL_TO_UINT(CAN_DigIn_3);
S_TCP_DigIn_3  := BOOL_TO_UINT(TCP_DigIn_3);

S_LOC_DigOut_4  := BOOL_TO_UINT(LOC_DigOut_4);
S_RTU_DigOut_4  := BOOL_TO_UINT(RTU_DigOut_4);
S_CAN_DigOut_4  := BOOL_TO_UINT(CAN_DigOut_4);
S_TCP_DigOut_4  := BOOL_TO_UINT(TCP_DigOut_4);

END_PROGRAM
