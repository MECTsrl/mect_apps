(*[[
]]*)
PROGRAM Slow 
#import "Crosstable.gvl"
#import "Resource1.gvl"

S_LOC_AnIn_1   := PLC_AnIn_1;
S_LOC_AnIn_2   := PLC_AnIn_2;
S_LOC_DigIn_3  := BOOL_TO_UINT(PLC_DigIn_3);
S_LOC_DigOut_4 := BOOL_TO_UINT(PLC_DigOut_4);

S_RTU_AnIn_1   := RTU_AnIn_1;
S_RTU_AnIn_2   := RTU_AnIn_2;
S_RTU_DigIn_3  := BOOL_TO_UINT(RTU_DigIn_3);
S_RTU_DigOut_4 := BOOL_TO_UINT(RTU_DigOut_4);

S_RTUbis_AnIn_1  := RTUbis_AnIn_1;
S_RTUbis_AnIn_2  := RTUbis_AnIn_2;
S_RTUbis_DigIn_3 := BOOL_TO_UINT(RTUbis_DigIn_3);
S_RTUbisDigOut_4 := BOOL_TO_UINT(RTUbis_DigOut_4);

S_TCP_AnIn_1   := TCP_AnIn_1;
S_TCP_AnIn_2   := TCP_AnIn_2;
S_TCP_DigIn_3  := BOOL_TO_UINT(TCP_DigIn_3);
S_TCP_DigOut_4 := BOOL_TO_UINT(TCP_DigOut_4);

END_PROGRAM

