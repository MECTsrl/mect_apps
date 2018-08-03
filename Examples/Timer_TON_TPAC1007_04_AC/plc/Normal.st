(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
  TON_Inst1 : TON;
  TON_Inst2 : TON;
  delay_time: TIME;
END_VAR
(*See Ladder_timer_TON program for ladder language / Vedere il programma Ladder_timer_TON per il linguaggio ladder*)

  (* EN: This example demonstrates the TON timer function. When PLC_DigOut_1 is high(Output_1 button on TPAC screen is pressed), 
         and when PLC_DigIn_2 input is high (switch 2 is ON in STK board), the LED 3 associated to the output PLC_DigOut _3 will
		 continue to be OFF at least for 10 seconds as specified in PT input.then is ON.
		  Now, if PLC_DigIn_2 is low(switch OFF),the LED is OFF.

	 IT: Questo esempio dimostra come funziona il timer TON. Quando il buttone Output_1 sullo schermo del TPAC è premuto, PLC_DigOut_1 diventa alto,
	     poi se l'ingresso PLC_DigIn_2 è alto (lo switch 2 è ON sulla board STK), allora il LED associato a PLC_DigOut_3 continua ad essere inattivo
		 per almeno 10 secondi (come specificato sull'ingresso PT) successivamente si accende.
		 Se la variabile PLC_DigIn_2 è bassa il LED, relativo alla variabile PLC_DigOut_3, si spegne. 
	 *)
  
	   if PLC_DigOut_1 then
        TON_Inst1(IN := PLC_DigIn_2, PT := T#10s);(*T#10s is the time for which the LED 3 continue to be OFF after PLC_DigIn_2 has become low*)
		if TON_Inst1.q then      
			PLC_DigOut_3 := true;
			TON_Inst1(IN := false);
		end_if;
	end_if;

    (* EN : In this example the only difference from the first one is that the PT time is set by the user by
	        Var_to_convert variable ( insert a value, see label time on the TPAC screen). 
            delay_time is a time type variable, so the integer type variable int_time must be multiplied 
			by 1000 (because TPAC works with milleseconds)and converted to a time type variable by the function INT_TO_TIME.

	   IT : In questo esempio l'unica differenza dal primo sta nel fatto che il tempo PT  deve essere stabilito
            dall'utente,tramite la variabile Var_to_convert (se inserisce un valore in label time sullo schermo del TPAC).
            la variabile INTERA Var_to_convert verra moltiplicata per 1000 perché il TPAC lavora con millesecondi, poi 
            convertita dal blocco INT_TO_TIME ad un tipo TIME.
			*)

    if PLC_DigOut_4 then
		delay_time :=  INT_TO_TIME(Var_to_convert*1000);	                                             
        TON_Inst2(IN := PLC_DigIn_5, PT :=delay_time);
		if TON_Inst2.q then
			PLC_DigOut_6 := true;
			TON_Inst2(IN := false);
		end_if;
	end_if;

	
END_PROGRAM

