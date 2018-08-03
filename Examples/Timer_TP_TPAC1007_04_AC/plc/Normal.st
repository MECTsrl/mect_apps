(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
  TP_Inst1 : TP;
  TP_Inst2 : TP;
  delay_time: TIME;	
END_VAR

(*See Ladder_timer_TP program for ladder language / Vedere il programma Ladder_timer_TP per il linguaggio ladder*)
	
    (* EN: this example demonstrates the TP timer function. When PLC_DigOut_1 is high(Output_1 button on TPAC screen is pressed), 
         and when PLC_DigIn_2 input is high (switch 2 is ON in STK board), the LED 3 associated to the output PLC_DigOut _3 will
		  be ON at least for 10 seconds as specified in PT input.then is OFF.
		 

	 IT: Questo esempio dimostra come funziona il timer TP. Quando il buttone Output_1 sullo schermo del TPAC è premuto, PLC_DigOut_1 diventa alto.
	     Se l'ingresso PLC_DigIn_2 è alto (lo switch 2 è ON sulla board STK), allora il LED associato a PLC_DigOut_3 si accende per almeno
		 10 secondi, come specificato sull'ingresso PT, successivamente si spegne. 
  	 *)
	
   if PLC_DigOut_1 then
        TP_Inst1(IN := PLC_DigIn_2, PT := T#10s);
		if TP_Inst1.q then      
			PLC_DigOut_3 := true;
		 else
			PLC_DigOut_3 := false;
		end_if;
    else
			PLC_DigOut_3 := false;
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
        TP_Inst2(IN := PLC_DigIn_5, PT :=delay_time);
		if TP_Inst2.q then
			PLC_DigOut_6 := true;
		else 
			PLC_DigOut_6 := false;
		end_if;
	else 
			PLC_DigOut_6 := false;
	end_if;
	
END_PROGRAM

