(*[[
]]*)
PROGRAM Normal (*An alarm example. Esempio di allarme*)
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR
	(*See LADDER_ALARM program for ladder language / Vedere il programma LADDER_ALARM per il linguaggio ladder*)

     (*EN: Press "Start" to enable digital output 2 (PLC_DigOut_2) and voltage output of analog output 1 will be 6 V (PLC_AnOut_1 set as voltage, see "Init" program in the Task0_Init).  
		   The variable "Average_AnInp1" contains the average of 10 PLC_AnIn_1 set as PT100 (temperature measurement) samples.
		   In the Crosstable (HMI) is set up an alarm (Alarm_temp): if "Average_AnInp1" is bigger than "SetPoint_temp"  value,  there will be an alarm.
		   When an alarm happens,  "Alarm_temp" is true and all the outputs will be disabled.
		   When "Start" is not pushed, all the outputs are disabled.  


	   IT:Quando il bottone "Start" viene premuto si abilita l'uscita digitale 2 (PLC_DigOut_2) e l'uscita analogica 1 genera 6 V (PLC_AnOut_1 configurata 
	   	  in tensione, vedere programma "Init" presente nel Task0_Init). 		  
	      La variabile "Average_AnInp1" contiene la media mobile di 10 campioni dell'ingresso analogico 1 (PLC_AnIn_1 configurata in PT100).
		  Nella Crosstable (HMI) si è configurato un allarme (Alarm_temp): se "Average_AnInp1" è maggiore del valore di soglia "SetPoint_temp" si ha un allarme. 
		  In caso di allarme si ha la variabile "Alarm_temp" uguale a true. In questo caso si disabiliteranno tutte le uscite.
		  Quando il buttone start non è premuto si hanno tutte le uscite disabilitate.*)

	  Average_AnInp1 := AVERAGE((INT_TO_REAL(PLC_AnIn_1) / 10.0), Average_AnInp1,10.0);  (*EN:AVERAGE is a function stored in ATCM_Common library (you need to download it into the project). IT: AVERAGE è una funzione presente nella libreria ATCM_Common (occorre importarla nel progetto)*)
	 if Start then 
      	if Alarm_temp then
            PLC_DigOut_2 := false;(*alarm*)
	   		PLC_AnOut_1 := 0;	
		else
			PLC_DigOut_2 := true; (*no alarm*)
	   		PLC_AnOut_1 := 600;
		end_if;
	  else     
       	PLC_DigOut_2 := false;
	    PLC_AnOut_1 := 0;
 	  end_if;
	
	  
END_PROGRAM

