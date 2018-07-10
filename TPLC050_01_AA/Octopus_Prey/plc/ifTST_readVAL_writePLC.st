(*[[
]]*)
FUNCTION ifTST_readVAL_writePLC
#import "Crosstable.gvl"
VAR_INPUT
    substatus : UINT;
END_VAR

	if substatus = 0 then 

		if (TST_DigIn_1 ) then PLC_DigDir_1 := 0; RES_DigIn_1 := 0; end_if;
	    if (TST_DigIn_2 ) then PLC_DigDir_2 := 0; RES_DigIn_2 := 0; end_if;
	    if (TST_DigIn_3 ) then PLC_DigDir_3 := 0; RES_DigIn_3 := 0; end_if;
	    if (TST_DigIn_4 ) then PLC_DigDir_4 := 0; RES_DigIn_4 := 0; end_if;
	    if (TST_DigIn_5 ) then PLC_DigDir_5 := 0; RES_DigIn_5 := 0; end_if;
	    if (TST_DigIn_6 ) then PLC_DigDir_6 := 0; RES_DigIn_6 := 0; end_if;
	    if (TST_DigIn_7 ) then PLC_DigDir_7 := 0; RES_DigIn_7 := 0; end_if;
	    if (TST_DigIn_8 ) then PLC_DigDir_8 := 0; RES_DigIn_8 := 0; end_if;
	
	    if (TST_DigOut_1) then PLC_DigDir_1 := 1; PLC_DigOut_1 := VAL_DigOut_1; end_if;
	    if (TST_DigOut_2) then PLC_DigDir_2 := 1; PLC_DigOut_2 := VAL_DigOut_2; end_if;
	    if (TST_DigOut_3) then PLC_DigDir_3 := 1; PLC_DigOut_3 := VAL_DigOut_3; end_if;
	    if (TST_DigOut_4) then PLC_DigDir_4 := 1; PLC_DigOut_4 := VAL_DigOut_4; end_if;
	    if (TST_DigOut_5) then PLC_DigDir_5 := 1; PLC_DigOut_5 := VAL_DigOut_5; end_if;
	    if (TST_DigOut_6) then PLC_DigDir_6 := 1; PLC_DigOut_6 := VAL_DigOut_6; end_if;
	    if (TST_DigOut_7) then PLC_DigDir_7 := 1; PLC_DigOut_7 := VAL_DigOut_7; end_if;
	    if (TST_DigOut_8) then PLC_DigDir_8 := 1; PLC_DigOut_8 := VAL_DigOut_8; end_if;
	
	    if (TST_DigIn_9 ) then RES_DigIn_9 := 0; end_if;
	    if (TST_DigOut_9) then YY_DigOut_A_1 := VAL_DigOut_9; end_if;

		if (TST_AnIn_1  ) then PLC_AnInConf_1 := 0; RES_AnIn_1 := 0; end_if; 
	    if (TST_AnIn_2  ) then PLC_AnInConf_2 := 0; RES_AnIn_2 := 0; end_if;
		
	    if (TST_Tamb      ) then RES_Tamb := 0; end_if;
	    if (TST_FWrevision) then RES_FWrevision := 0; end_if;
	    if (TST_HWconfig  ) then RES_HWconfig := 0; end_if;
	
		if (TST_RTU1_WR   ) then RTU_RTU1_WR := VAL_RTU1_WR; end_if;
		if (TST_RTU1_RD   ) then ; end_if;

	elsif substatus = 1 then

	    (* no AnOut *)
		;

	elsif substatus = 2 then

	    if (TST_AnIn_1  ) then PLC_AnInConf_1 := VAL_AnInConf_1; PLC_AnInFltr_1 := VAL_AnInFltr_1; end_if; 
	    if (TST_AnIn_2  ) then PLC_AnInConf_2 := VAL_AnInConf_2; PLC_AnInFltr_2 := VAL_AnInFltr_2; end_if;

	end_if;
	
END_FUNCTION
