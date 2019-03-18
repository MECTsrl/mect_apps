(*[[
]]*)
PROGRAM VerySlow 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
END_VAR

	(* XX_AnIn_1 temperatura dell'acqua nel puffer *)
	(* XX_AnIn_2 temperatura dell'acqua nei termosifoni *)
	(* XX_DigOut_5 comando valvola a tre vie del puffer *)

	if (XX_AnIn_1 < 50 or XX_AnIn_1 < 50) then
		(* transitorio all'accensione, teniamo la valvola chiusa *)
		XX_DigOut_5 := false;
	elsif (XX_AnIn_1 > XX_AnIn_2) then
		(* l'acqua nel puffer è più calda di quella nei termosifoni, quindi apriamo la valvola *)  
		XX_DigOut_5 := true;
	else
		(* puffer freddo, teniamo la valvola chiusa *)
		XX_DigOut_5 := false;
	end_if;

END_PROGRAM
