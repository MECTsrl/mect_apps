(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	counter : uint := 0;
	onoff : bool := true;
END_VAR

	(* one round true and one round false *)
	onoff := ((counter / 24) mod 2) = 0;

	(* in each round touch every node *)
	case (counter mod 24) + 1 of
		1: digOUT1_node01 := onoff;
	    2: digOUT1_node02 := onoff;
        3: digOUT1_node03 := onoff;
	    4: digOUT1_node04 := onoff;
	    5: digOUT1_node05 := onoff;
	    6: digOUT1_node06 := onoff;
	    7: digOUT1_node07 := onoff;
	    8: digOUT1_node08 := onoff;
	    9: digOUT1_node09 := onoff;
	   10: digOUT1_node10 := onoff;
	   11: digOUT1_node11 := onoff;
	   12: digOUT1_node12 := onoff;
	   13: digOUT1_node13 := onoff;
	   14: digOUT1_node14 := onoff;
	   15: digOUT1_node15 := onoff;
	   16: digOUT1_node16 := onoff;
	   17: digOUT1_node17 := onoff;
	   18: digOUT1_node18 := onoff;
	   19: digOUT1_node19 := onoff;
	   20: digOUT1_node20 := onoff;
	   21: digOUT1_node21 := onoff;
	   22: digOUT1_node22 := onoff;
	   23: digOUT1_node23 := onoff;
	   24: digOUT1_node24 := onoff;
	end_case;

	(* increment the counter, with overflow *)
	counter := counter + 1; 
	
END_PROGRAM
