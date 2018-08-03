(*[[
]]*)
PROGRAM Normal (*exemple of a counter*)
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
    little: bool;
END_VAR
    
   (* EN: Here we have an exemple of an up counter that counts the number of times in which the signal PLC_AnIn_1 
          (a voltage signal) goes both down (up) a lower-bound (an upper-bound).
 		  When the number of counting reachs 10,the counter is reset to 0.
		  One can also measure the elapsed time between two events where the counting condition above is verified.

	  IT: Qui abbiamo un esempio di un contatore che conta i numeri delle volte in cui il segnale PLC_AnIn_1
	      (segnale di tensione) va prima sotto una soglia minima,poi sopra una soglia massima.
		  Quando il conteggio raggiunge il numero 10, il contatore è resettato a 0.
		  Si puo anche misurare il tempo trascorso tra due eventi dove si è verificata la condizione di conteggio.
   
   *) 
	if PLC_AnIn_1 < 4900 then
		little := true;
	end_if;

	if PLC_AnIn_1 > 5000 and little then
	   Elapsed_time := PLC_time - Rising_edge;(* to measure the time between two events where the condition is true. *) 
		count := count + 1;
		Rising_edge := PLC_time;(*memorize the first rising edge*)
		little := false;
	end_if;

	if count = 10 then
		count := 0;
	end_if;

	

		 
	
END_PROGRAM

