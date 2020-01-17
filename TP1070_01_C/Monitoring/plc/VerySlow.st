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

	if HeatingEnable then

		(* piano sopra: termostato "sopra sud" *)
		RegolazioneOnOff(HeatingSetPoint_A, HeatingDelta, XX_AnIn_A_3, XX_DigOut_8);

		(* piano terra: termostato "corridoio" *)
		RegolazioneOnOff(HeatingSetPoint_B, HeatingDelta, XX_AnIn_B_3, XX_DigOut_7);

		(* piano sotto: termostato "scala" *)
		RegolazioneOnOff(HeatingSetPoint_C, HeatingDelta, XX_AnIn_C_3, XX_DigOut_6);

	else

		XX_DigOut_8 := false;
		XX_DigOut_7 := false;
		XX_DigOut_6 := false;

	end_if;

END_PROGRAM
