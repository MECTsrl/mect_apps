(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	
END_VAR

(*See LADDER_RETENTIVE program for ladder language / Vedere il programma LADDER_RETENTIVE per il linguaggio ladder*)

   (* EN: retentive variables keep their values even when the TPAC is OFF, in this exemple if PLC_DigOut_1 is true 
	      this value will be assigned to Val_ret (a retentive variable). In this way if one switches off and then on the TPAC , 
	      the output PLC_DigOut_1 will still continue to be true (LED ON).

	  IT: Le variabili "Retentive" mantengono i lori valori anche quando il dispositivo è spento.
	  	  In questo esempio si vuole tenere memoria dei valori dell'uscita analogica 1 (PLC_AnOut_1) e dell'uscita digitale 1 (PLC_DigOut_1). 
		  I valori delle uscite vengono scritte all'interno di variabili ritentive, dichiarazione in Qt -> MectSuite -> Crosstable.
		  Vedere il programma Init, presente nel Task0_Init, per l'assegnazione tra le variabili ritentive e le uscite fisiche; il Task0_Init 
		  verrà eseguito solamente una volta e quando verrà acceso il dispositivo.*)

     Retentive_DigVal := PLC_DigOut_1;	
	 Retentive_AnVal :=PLC_AnOut_1;

END_PROGRAM

