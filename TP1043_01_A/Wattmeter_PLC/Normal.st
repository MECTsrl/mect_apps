(*[[
]]*)
PROGRAM Normal
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	current_ratio : UINT;
END_VAR;

	current_ratio := CT_RATIO;
	if current_ratio = 0 then
		current_ratio := 4;
	end_if;

	Potenza := W_L1 * (VT_RATIO / 10) * current_ratio; (* P 111.1 *)
	Tensione := V_L1_N * (VT_RATIO / 10); (* VN 111.1 *)

END_PROGRAM
