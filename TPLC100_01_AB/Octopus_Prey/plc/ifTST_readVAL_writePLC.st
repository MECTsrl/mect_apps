(*[[
]]*)
FUNCTION ifTST_readVAL_writePLC
#import "Crosstable.gvl"
VAR_INPUT
	substatus : uint;
END_VAR

	if substatus = 0 then

		if (TST_DigIn_1 ) then RES_DigIn_1 := 0; end_if;
	    if (TST_DigIn_2 ) then RES_DigIn_2 := 0; end_if;
	    if (TST_DigIn_3 ) then RES_DigIn_3 := 0; end_if;
	    if (TST_DigIn_4 ) then RES_DigIn_4 := 0; end_if;
		if (TST_DigIn_5 ) then RES_DigIn_5 := 0; end_if;
	    if (TST_DigIn_6 ) then RES_DigIn_6 := 0; end_if;
	    if (TST_DigIn_7 ) then RES_DigIn_7 := 0; end_if;
	    if (TST_DigIn_8 ) then RES_DigIn_8 := 0; end_if;

		if (TST_DigIn_9 ) then RES_DigIn_9 := 0; end_if;
	    if (TST_DigIn_10) then RES_DigIn_10:= 0; end_if;
	    if (TST_DigIn_11) then RES_DigIn_11:= 0; end_if;
	    if (TST_DigIn_12) then RES_DigIn_12:= 0; end_if;
		if (TST_DigIn_13) then RES_DigIn_13:= 0; end_if;
	    if (TST_DigIn_14) then RES_DigIn_14:= 0; end_if;
	    if (TST_DigIn_15) then RES_DigIn_15:= 0; end_if;
	    if (TST_DigIn_16) then RES_DigIn_16:= 0; end_if;

	    if (TST_DigOut_1) then PLC_DigOutEn_1 := 1; PLC_DigOut_1 := VAL_DigOut_1; else PLC_DigOutEn_1 := 0; end_if;
	    if (TST_DigOut_2) then PLC_DigOutEn_2 := 1; PLC_DigOut_2 := VAL_DigOut_2; else PLC_DigOutEn_2 := 0; end_if;
	    if (TST_DigOut_3) then PLC_DigOutEn_3 := 1; PLC_DigOut_3 := VAL_DigOut_3; else PLC_DigOutEn_3 := 0; end_if;
	    if (TST_DigOut_4) then PLC_DigOutEn_4 := 1; PLC_DigOut_4 := VAL_DigOut_4; else PLC_DigOutEn_4 := 0; end_if;
	    if (TST_DigOut_5) then PLC_DigOutEn_5 := 1; PLC_DigOut_5 := VAL_DigOut_5; else PLC_DigOutEn_5 := 0; end_if;
	    if (TST_DigOut_6) then PLC_DigOutEn_6 := 1; PLC_DigOut_6 := VAL_DigOut_6; else PLC_DigOutEn_6 := 0; end_if;
	    if (TST_DigOut_7) then PLC_DigOutEn_7 := 1; PLC_DigOut_7 := VAL_DigOut_7; else PLC_DigOutEn_7 := 0; end_if;
	    if (TST_DigOut_8) then PLC_DigOutEn_8 := 1; PLC_DigOut_8 := VAL_DigOut_8; else PLC_DigOutEn_8 := 0; end_if;

		if (TST_AnIn_1  ) then PLC_AnInConf_1 := 0; RES_AnIn_1 := 0; end_if; 
	    if (TST_AnIn_2  ) then PLC_AnInConf_2 := 0; RES_AnIn_2 := 0; end_if;
		if (TST_AnIn_3  ) then PLC_AnInConf_3 := 0; RES_AnIn_3 := 0; end_if; 
	    if (TST_AnIn_4  ) then PLC_AnInConf_4 := 0; RES_AnIn_4 := 0; end_if;

	    if (TST_AnIn_5  ) then PLC_AnInConf_5 := 0; RES_AnIn_5 := 0; end_if;
	    if (TST_AnIn_6  ) then PLC_AnInConf_6 := 0; RES_AnIn_6 := 0; end_if;
	    if (TST_AnIn_7  ) then PLC_AnInConf_7 := 0; RES_AnIn_7 := 0; end_if;
	    if (TST_AnIn_8  ) then PLC_AnInConf_8 := 0; RES_AnIn_8 := 0; end_if;
	    if (TST_AnIn_9  ) then PLC_AnInConf_9 := 0; RES_AnIn_9 := 0; end_if;
	    if (TST_AnIn_10 ) then PLC_AnInConf_10:= 0; RES_AnIn_10:= 0; end_if;
	    if (TST_AnIn_11 ) then PLC_AnInConf_11:= 0; RES_AnIn_11:= 0; end_if;
	    if (TST_AnIn_12 ) then PLC_AnInConf_12:= 0; RES_AnIn_12:= 0; end_if;

	    if (TST_AnOut_1 ) then
			if (VAL_AnOutConf_1 = 3) then
				PLC_AnOutConf_1 := 2; PLC_AnOut_1 := 1000; (* 10.00 V is the PWM amplitude *)
		    else 
				PLC_AnOutConf_1 := VAL_AnOutConf_1;
			end_if;
		end_if;
	    if (TST_AnOut_2 ) then 
			if (VAL_AnOutConf_2 = 3) then
				PLC_AnOutConf_2 := 2; PLC_AnOut_2 := 1000; (* 10.00 V is the PWM amplitude *)
		    else 
				PLC_AnOutConf_2 := VAL_AnOutConf_2;
			end_if;
		end_if;

	    if (TST_Tamb      ) then RES_Tamb := 0; end_if;
	   
		if (TST_RTU1_WR   ) then RTU_RTU_WR := VAL_RTU1_WR; end_if;
		if (TST_RTU1_RD   ) then RES_RTU1_RD := 0; end_if;

	elsif substatus = 1 then

	    if (TST_AnOut_1 ) then
			if (VAL_AnOutConf_1 = 3) then
				PLC_AnOutConf_1 := 3; (* [%] PWM *)
		    else 
				PLC_AnOut_1 := VAL_AnOut_1;
			end_if;
		end_if;
	    if (TST_AnOut_2 ) then 
			if (VAL_AnOutConf_2 = 3) then
				PLC_AnOutConf_2 := 3; (* [%] PWM *)
		    else 
				PLC_AnOut_2 := VAL_AnOut_2;
			end_if;
		end_if;

	elsif substatus = 2 then

	    if (TST_AnOut_1 ) then
			if (VAL_AnOutConf_1 = 3) then
				PLC_AnOut_1 := VAL_AnOut_1; (* [%] PWM *)
			end_if;
		end_if;
	    if (TST_AnOut_2 ) then 
			if (VAL_AnOutConf_2 = 3) then
				PLC_AnOut_2 := VAL_AnOut_2; (* [%] PWM *)
			end_if;
		end_if;

	elsif substatus = 3 then

		if (TST_AnIn_1  ) then PLC_AnInConf_1 := VAL_AnInConf_1 ; end_if; 
	    if (TST_AnIn_2  ) then PLC_AnInConf_2 := VAL_AnInConf_2 ; end_if;
		if (TST_AnIn_3  ) then PLC_AnInConf_3 := VAL_AnInConf_3 ; end_if; 
	    if (TST_AnIn_4  ) then PLC_AnInConf_4 := VAL_AnInConf_4 ; end_if;

	    if (TST_AnIn_5  ) then PLC_AnInConf_5 := VAL_AnInConf_5 ; end_if;
	    if (TST_AnIn_6  ) then PLC_AnInConf_6 := VAL_AnInConf_6 ; end_if;
	    if (TST_AnIn_7  ) then PLC_AnInConf_7 := VAL_AnInConf_7 ; end_if;
	    if (TST_AnIn_8  ) then PLC_AnInConf_8 := VAL_AnInConf_8 ; end_if;
	    if (TST_AnIn_9  ) then PLC_AnInConf_9 := VAL_AnInConf_9 ; end_if;
	    if (TST_AnIn_10 ) then PLC_AnInConf_10:= VAL_AnInConf_10; end_if;
	    if (TST_AnIn_11 ) then PLC_AnInConf_11:= VAL_AnInConf_11; end_if;
	    if (TST_AnIn_12 ) then PLC_AnInConf_12:= VAL_AnInConf_12; end_if;

	end_if;

END_FUNCTION
