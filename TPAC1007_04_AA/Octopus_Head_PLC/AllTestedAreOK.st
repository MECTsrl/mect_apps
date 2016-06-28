(*[[
]]*)
FUNCTION AllTestedAreOK : BOOL
#import "Crosstable.gvl"
VAR
	retval : BOOL := TRUE;
END_VAR

	if TST_DigIn_1  then retval := retval and OK_DigIn_1;  end_if;
	if TST_DigIn_2  then retval := retval and OK_DigIn_2;  end_if;
	if TST_DigIn_3  then retval := retval and OK_DigIn_3;  end_if;
	if TST_DigIn_4  then retval := retval and OK_DigIn_4;  end_if;
	if TST_DigIn_5  then retval := retval and OK_DigIn_5;  end_if;
	if TST_DigIn_6  then retval := retval and OK_DigIn_6;  end_if;
	if TST_DigIn_7  then retval := retval and OK_DigIn_7;  end_if;
	if TST_DigIn_8  then retval := retval and OK_DigIn_8;  end_if;
	if TST_DigIn_9  then retval := retval and OK_DigIn_9;  end_if;
	if TST_DigIn_10 then retval := retval and OK_DigIn_10; end_if;
	if TST_DigIn_11 then retval := retval and OK_DigIn_11; end_if;
	if TST_DigIn_12 then retval := retval and OK_DigIn_12; end_if;
	if TST_DigIn_13 then retval := retval and OK_DigIn_13; end_if;
	if TST_DigIn_14 then retval := retval and OK_DigIn_14; end_if;
	if TST_DigIn_15 then retval := retval and OK_DigIn_15; end_if;
	if TST_DigIn_16 then retval := retval and OK_DigIn_16; end_if;

	if TST_DigOut_1  then retval := retval and OK_DigOut_1;  end_if;
	if TST_DigOut_2  then retval := retval and OK_DigOut_2;  end_if;
	if TST_DigOut_3  then retval := retval and OK_DigOut_3;  end_if;
	if TST_DigOut_4  then retval := retval and OK_DigOut_4;  end_if;
	if TST_DigOut_5  then retval := retval and OK_DigOut_5;  end_if;
	if TST_DigOut_6  then retval := retval and OK_DigOut_6;  end_if;
	if TST_DigOut_7  then retval := retval and OK_DigOut_7;  end_if;
	if TST_DigOut_8  then retval := retval and OK_DigOut_8;  end_if;
	if TST_DigOut_9  then retval := retval and OK_DigOut_9;  end_if;
	if TST_DigOut_10 then retval := retval and OK_DigOut_10; end_if;
	if TST_DigOut_11 then retval := retval and OK_DigOut_11; end_if;
	if TST_DigOut_12 then retval := retval and OK_DigOut_12; end_if;
	if TST_DigOut_13 then retval := retval and OK_DigOut_13; end_if;
	if TST_DigOut_14 then retval := retval and OK_DigOut_14; end_if;
	if TST_DigOut_15 then retval := retval and OK_DigOut_15; end_if;
	if TST_DigOut_16 then retval := retval and OK_DigOut_16; end_if;

	if TST_AnIn_1  then retval := retval and OK_AnIn_1;  end_if;
	if TST_AnIn_2  then retval := retval and OK_AnIn_2;  end_if;
	if TST_AnIn_3  then retval := retval and OK_AnIn_3;  end_if;
	if TST_AnIn_4  then retval := retval and OK_AnIn_4;  end_if;

	if TST_AnIn_5  then retval := retval and OK_AnIn_5;  end_if;
	if TST_AnIn_6  then retval := retval and OK_AnIn_6;  end_if;
	if TST_AnIn_7  then retval := retval and OK_AnIn_7;  end_if;
	if TST_AnIn_8  then retval := retval and OK_AnIn_8;  end_if;
	if TST_AnIn_9  then retval := retval and OK_AnIn_9;  end_if;
	if TST_AnIn_10 then retval := retval and OK_AnIn_10;  end_if;
	if TST_AnIn_11 then retval := retval and OK_AnIn_11;  end_if;
	if TST_AnIn_12 then retval := retval and OK_AnIn_12;  end_if;

	if TST_AnOut_1  then retval := retval and OK_AnOut_1;  end_if;
	if TST_AnOut_2  then retval := retval and OK_AnOut_2;  end_if;
	if TST_AnOut_3  then retval := retval and OK_AnOut_3;  end_if;
	if TST_AnOut_4  then retval := retval and OK_AnOut_4;  end_if;

	if TST_Tamb  then retval := retval and OK_Tamb;  end_if;
	if TST_RPM   then retval := retval and OK_RPM;  end_if;

	if TST_VCC_set  then retval := retval and OK_VCC_set;  end_if;
	if TST_mA_max  then retval := retval and OK_mA_max;  end_if;

	if TST_VCC_fbk  then retval := retval and OK_VCC_fbk;  end_if;
	if TST_mA_fbk  then retval := retval and OK_mA_fbk;  end_if;

	if TST_FWrevision  then retval := retval and OK_FWrevision; end_if;
	if TST_HWconfig  then retval := retval and OK_HWconfig;  end_if;

	if TST_RTU1_WR  then retval := retval and OK_RTU1_WR; end_if;
	if TST_RTU1_RD  then retval := retval and OK_RTU1_RD; end_if;
	if TST_RTU3_WR  then retval := retval and OK_RTU3_WR; end_if;
	if TST_RTU3_RD  then retval := retval and OK_RTU3_RD; end_if;

	if TST_CAN1_WR  then retval := retval and OK_CAN1_WR; end_if;
	if TST_CAN1_RD  then retval := retval and OK_CAN1_RD; end_if;

	AllTestedAreOK := retval;
END_FUNCTION
