(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	
END_VAR
    (* EN: When using a TPAC1008_02 or TPLC100 configuration and initialization should be done here and not in the Task0_Init. 
	   IT: Per i modelli TPAC1008_02 e TPLC100, la configurazione / inizializzazione delle variabili deve essere fatta all'interno di un Task ciclico e non all'interno del Task0_Init*)

	if CH0_01_NODERUN then  (* Device is ready for configuration / Il dispositivo è pronto per la configurazione *)
		
		PLC_AnInConf_1 := 1; (*  analog inputs configuration: 0 = not configurated, 1 = current,
			                     2 = voltage, 3 = TCJ, 4 = TCK,  5 = TCT, 6 = PT100E,              
							     7= PT100R (with decimal point), 8 =  TCS, 9 =  TCB, 10 =  TCR	*)				 
		PLC_AnInConf_2 := 2;
 
	    PLC_AnOutConf_1 := 1; (* analog outputs configuration: 0 not configurated, 1 = current, 2 = voltage. *)
	    PLC_AnOutConf_2 := 2;
	
	    PLC_EnableEnc  := 1; (* encoder configuration: 0 = not enabled, 1 = bidirectional encoder enabled, 2 = counter *)

	end_if;
	
END_PROGRAM

