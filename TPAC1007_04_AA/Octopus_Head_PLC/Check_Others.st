(*[[
]]*)
FUNCTION Check_Others
#import "Crosstable.gvl"
VAR_INPUT
END_VAR
VAR
	Tolleranza_Tamb_min : INT := 10;
	Tolleranza_RPM : INT := 100;
	Tolleranza_VCC_set : INT := 10; (* 0.01 V *)
	Tolleranza_mA_max : INT := 10; (* 0.01 mA *)
	Tolleranza_VCC_fbk : INT := 100; (* 0.1 V *)
	Tolleranza_mA_fbk : INT := 100; (* 0.1 mA *)
END_VAR

	(* Get results *)
	if TST_Tamb  then RES_Tamb  := RESx_Tamb;  end_if;
	if TST_RPM   then RES_RPM  := RESx_RPM;  end_if;

	if TST_VCC_set  then RES_VCC_set  := PLC_AnOut_3;  end_if;
	if TST_mA_max  then RES_mA_max  := PLC_AnOut_4;  end_if;

	if TST_VCC_fbk  then RES_VCC_fbk  := PLC_AnIn_1;  end_if;
	if TST_mA_fbk  then RES_mA_fbk  := PLC_AnIn_2;  end_if;

	if TST_FWrevision  then RES_FWrevision  := RESx_FWrevision;  end_if;
	if TST_HWconfig  then RES_HWconfig  := RESx_HWconfig;  end_if;

	(* Check values *)
	if TST_Tamb  then OK_Tamb  := (Tolleranza_Tamb_min <= RES_Tamb) and (RES_Tamb < VAL_Tamb ); end_if;
	if TST_RPM  then OK_RPM  := abs(UINT_TO_INT(RES_RPM) - UINT_TO_INT(VAL_RPM) ) < Tolleranza_RPM; end_if;

	if TST_VCC_set  then OK_VCC_set  := abs(RES_VCC_set  - VAL_VCC_set ) < Tolleranza_VCC_set; end_if;
	if TST_mA_max  then OK_mA_max  := abs(RES_mA_max - VAL_mA_max ) < Tolleranza_mA_max; end_if;

	if TST_VCC_fbk  then OK_VCC_fbk  := abs(RES_VCC_fbk  - VAL_VCC_fbk ) < Tolleranza_VCC_fbk; end_if;
	if TST_mA_fbk  then OK_mA_fbk := abs(RES_mA_fbk - VAL_mA_fbk ) < Tolleranza_mA_fbk; end_if;

	if TST_FWrevision  then OK_FWrevision  := (RES_FWrevision  = VAL_FWrevision); end_if;
	if TST_HWconfig  then OK_HWconfig  := (RES_HWconfig = VAL_HWconfig); end_if;

END_FUNCTION
