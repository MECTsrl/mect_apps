(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
  first : bool := true;	(*local variable*)
END_VAR

  (* EN: TPAC1008_02 uses CAN protocol and it is enabled by CH0_01_NODERUN. The i/o configuration and initialization should be 
        done here and not in the Task0_Init.
		this is an exemple about retentive variables, if CH0_01_NODERUN (CAN enabled) is true, first is also true and PLC_DigOut_1 is true 
		 this value ( PLC_DigOut_1) will be assigned to Retentive_DigVal (a retentive variable). In this way if one switches off and then
		 on the TPAC, the output PLC_DigOut_1 will still continue to be true (LED ON). the same with PLC_AnOut_1.

	  IT: I TPAC1008_02 usano internamente il protocollo CAN ed è abilitato da CH0_01_NODERUN. La configurazione e l'inizializazzione vanno fatte qui 
	      e non nel Task0_Init.
          Questo è un esempio di variabili "retentive" (mantengono il valore allo spegnimento), se CH0_01_NODERUN è vero (CAN abilitato) si memorizza
		  il valore di alcune uscite. I valori delle uscite possono essere inseriti da HMI. In questo modo se si spegne e poi si accende il 
		  dispositivo le uscite avranno il valore precedentemente memorizzato.
		*)

	if CH0_01_NODERUN then (*CAN protocol configuration*)
    	if first then
			PLC_AnOutConf_1 := 2; (*configuration analog output 1*)
			PLC_DigOut_1 := Retentive_DigVal;
	  		PLC_AnOut_1 := Retentive_AnVal;
			first := false; (*it runs once*)
    	else 
		    Retentive_DigVal := PLC_DigOut_1;	
	     	Retentive_AnVal := PLC_AnOut_1; 
		end_if;

    end_if;	
END_PROGRAM

