(*[[
]]*)
PROGRAM VerySlow 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
END_VAR

	if (XX_AnIn_A_4 < 50) then
		(* transitorio all'accensione *)
		MPT91_Set_point := 50; (* 5.0 °C *)
	else
		(* l'acqua nel puffer, per essere utile, deve essere più calda di quella nei termosifoni *)   
		MPT91_Set_point := XX_AnIn_A_4 + 10; (* T_ritorno + 1.0 °C *)
	end_if;

END_PROGRAM
