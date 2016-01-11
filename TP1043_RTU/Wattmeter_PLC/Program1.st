(*[[
]]*)
PROGRAM Program1

#import "Crosstable.gvl"
VAR
	current_ratio : int;
	first : bool := true;
END_VAR;
	if first then
		first := false;
		PLC_timeWin := 60.0;
	end_if;
	current_ratio := CT_RATIO;
	if current_ratio = 0 then
		current_ratio := 4;
	end_if;
	Potenza := W_L1 * (VT_RATIO / 10) * current_ratio; (* P 111.1 *)
	Tensione := V_L1_N * (VT_RATIO / 10); (* VN 111.1 *)

END_PROGRAM
