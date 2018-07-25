(*[[
]]*)

FUNCTION allAnalogInputsAreOK : BOOL
#import "Crosstable.gvl"

allAnalogInputsAreOK := true;

if (TST_AnIn_1  and ((UINT_TO_WORD(PLC_AnInST_1_4 ) AND 16#000F) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_2  and ((UINT_TO_WORD(PLC_AnInST_1_4 ) AND 16#00F0) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_3  and ((UINT_TO_WORD(PLC_AnInST_1_4 ) AND 16#0F00) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_4  and ((UINT_TO_WORD(PLC_AnInST_1_4 ) AND 16#F000) = 4)) then allAnalogInputsAreOK := false; end_if; 

if (TST_AnIn_5  and ((UINT_TO_WORD(PLC_AnInST_5_8 ) AND 16#000F) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_6  and ((UINT_TO_WORD(PLC_AnInST_5_8 ) AND 16#00F0) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_7  and ((UINT_TO_WORD(PLC_AnInST_5_8 ) AND 16#0F00) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_8  and ((UINT_TO_WORD(PLC_AnInST_5_8 ) AND 16#F000) = 4)) then allAnalogInputsAreOK := false; end_if; 

if (TST_AnIn_9  and ((UINT_TO_WORD(PLC_AnInST_9_12) AND 16#000F) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_10 and ((UINT_TO_WORD(PLC_AnInST_9_12) AND 16#00F0) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_11 and ((UINT_TO_WORD(PLC_AnInST_9_12) AND 16#0F00) = 4)) then allAnalogInputsAreOK := false; end_if; 
if (TST_AnIn_12 and ((UINT_TO_WORD(PLC_AnInST_9_12) AND 16#F000) = 4)) then allAnalogInputsAreOK := false; end_if; 


END_FUNCTION
