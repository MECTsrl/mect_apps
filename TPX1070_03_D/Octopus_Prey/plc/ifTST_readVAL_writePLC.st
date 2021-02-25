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
	
	    if (TST_DigOut_1 ) then PLC_FastIO_5  := VAL_DigOut_1 ; end_if;
	    if (TST_DigOut_2 ) then PLC_FastIO_6  := VAL_DigOut_2 ; end_if;
	    if (TST_DigOut_3 ) then PLC_FastIO_7  := VAL_DigOut_3 ; end_if;
	    if (TST_DigOut_4 ) then PLC_FastIO_8  := VAL_DigOut_4 ; end_if;

	    if (TST_AnIn_1  ) then MPNE05_AnInConf_1 := 0; RES_AnIn_1 := 0; end_if; 
	    if (TST_AnIn_2  ) then MPNE05_AnInConf_2 := 0; RES_AnIn_2 := 0; end_if;
	
	    if (TST_AnOut_1 ) then
			if (VAL_AnOutConf_1 = 3) then
				MPNE05_AnOutConf_1 := 2; MPNE05_AnOut_1 := 1000; (* 10.00 V is the PWM amplitude *)
		    else 
				MPNE05_AnOutConf_1 := VAL_AnOutConf_1; MPNE05_AnOut_1 := VAL_AnOut_1;
			end_if;
		end_if;
		   
		if (TST_RTU1_WR   ) then RTU_RTU_WR := VAL_RTU1_WR; end_if;
		if (TST_RTU3_WR   ) then MPNC005_DigOut_4 := VAL_RTU3_WR; end_if;
	
		if (TST_RTU1_RD   ) then RES_RTU1_RD := 0; end_if;
		if (TST_RTU3_RD   ) then RES_RTU3_RD := 0; end_if;


	elsif substatus = 1 then

	    if (TST_AnOut_1 ) then
			if (VAL_AnOutConf_1 = 3) then
				MPNE05_AnOutConf_1 := 3; MPNE05_AnOut_1 := VAL_AnOut_1; (* [%] PWM *)
			elsif (VAL_AnOutConf_1 = 1) then
				MPNE05_AnOut_1 := VAL_AnOut_1;  (* ribadito *)
			end_if;
		end_if;

	elsif substatus = 2 then

	    if (TST_AnIn_1  ) then MPNE05_AnInConf_1 := VAL_AnInConf_1; MPNE05_AnInFilter_1 := VAL_AnInFltr_1; end_if; 
	    if (TST_AnIn_2  ) then MPNE05_AnInConf_2 := VAL_AnInConf_2; MPNE05_AnInFilter_2 := VAL_AnInFltr_2; end_if;

	end_if;
	
END_FUNCTION
