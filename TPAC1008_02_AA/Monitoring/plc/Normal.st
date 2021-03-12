(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	timer_check_ton : ton;
	stato : int := 0;
END_VAR
	
	CASE stato OF
    	0: PLC_DigOut_12 := true;
			timer_check_ton(IN := true, PT := T#2s);
			if timer_check_ton.q then
				timer_check_ton(IN := false);
				stato := 10;
			end_if;

	   10: PLC_DigOut_12 := false;
			timer_check_ton(IN := true, PT := T#2s);
			if timer_check_ton.q then
				timer_check_ton(IN := false);
				stato := 0;
			end_if;
		   
    END_CASE;	
 
	
END_PROGRAM
