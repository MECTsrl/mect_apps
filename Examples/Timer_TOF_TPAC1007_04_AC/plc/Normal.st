(*[[
]]*)
PROGRAM Normal  (* An ST plc program about TOF timer*)
#import "Crosstable.gvl"
#import "Resource1.gvl"
  
VAR
  TOF_Inst1 : TOF;
  TOF_Inst2 : TOF;
  delay_time : TIME;	
END_VAR
	(*See Ladder_timer_TOF program for ladder language / Vedere il programma Ladder_timer_TOF per il linguaggio ladder*)

  (* EN: this example demonstrates the TOF timer function. When PLC_DigOut_1 is high(Output_1 button on TPAC screen is pressed), 
         and when PLC_DigIn_2 input is high (switch 2 is ON in STK board), the LED associated to the output PLC_DigOut _3 is ON.
         Now, if PLC_DigIn_2 is low(switch OFF), the LED  will continue to be high at least for 10 seconds as specified in PT input,then is OFF.

	 IT: Questo esempio dimostra come funziona il timer TOF. Quando il buttone Output_1 sullo schermo del TPAC è premuto, PLC_DigOut_1 diventa alto,
	     poi se l'ingresso PLC_DigIn2 è alto (lo switch 2 è ON sulla board STK), allora il LED associato a PLC_DigOut_3 diventa attivo.
		 Se PLC_DigIn_2 diventa basso (switch OFF), il LED relativo alla variabile PLC_DigOut_3 continua ad essere attivo per almeno 10 secondi 
		 (come specificato sull'ingresso PT) successivamente si spegne.
	 *)
  
  
  
	   if PLC_DigOut_1 then   
 		   TOF_Inst1(IN := PLC_DigIn_2 );
		      if TOF_Inst1.q  then     (* TOF_Inst1.q is true when both PLC_DigIn_2 and q are true *)
                 PLC_DigOut_3 := true;	  
		      end_if;
           TOF_Inst1 (IN := false, PT := T#10s);(* T#10s (PT is a time type input) is the time for which the LED continue to be ON after PLC_DigIn_2 has become low*)
		      if not TOF_Inst1.q then (* q will be false after 10 seconds*)
                  PLC_DigOut_3 := false;
		      end_if;
	   end_if;
	 
    (* EN : In this example the only difference from the first one is that the time in PT input is set by the user by
	        int_time variable (insert a value, see label time on the TPAC screen). 
            delay_time is a time type variable, so the integer type variable int_time must be multiplied 
		    by 1000 (because TPAC works with milleseconds)and converted to a time type variable by the function INT_TO_TIME. 

	   IT : In questo esempio l'unica differenza dal primo sta nel fatto che il tempo sull'ingresso PT deve essere stabilito
            dall'utente,tramite la variabile int_time (si inserisce un valore in label time sullo schermo del TPAC).
            La variabile INTERA int_time verrà moltiplicata per 1000 perche il sistema lavora con millesecondi poi 
            convertita dal blocco INT_TO_TIME ad un tipo TIME.
			*)
      if PLC_DigOut_4 then
		    delay_time := INT_TO_TIME (int_time * 1000);
			                                             
 		    TOF_Inst2(IN := PLC_DigIn_5);
		    if TOF_Inst2.q then
               PLC_DigOut_6 := true; 
		    end_if;

 			  TOF_Inst2(IN := false,PT := delay_time);
			  if not TOF_Inst2.q then
              	 PLC_DigOut_6 := false;
		  end_if;
	  end_if;
	
END_PROGRAM

