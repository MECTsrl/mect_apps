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
		1: DigOut_5_node01 := onoff;
	    2: DigOut_5_node02 := onoff;
        3: DigOut_5_node03 := onoff;
	    4: DigOut_5_node04 := onoff;
	    5: DigOut_5_node05 := onoff;
	    6: DigOut_5_node06 := onoff;
	    7: DigOut_5_node07 := onoff;
	    8: DigOut_5_node08 := onoff;
	    9: DigOut_5_node09 := onoff;
	   10: DigOut_5_node10 := onoff;
	   11: DigOut_5_node11 := onoff;
	   12: DigOut_5_node12 := onoff;
	   13: DigOut_5_node13 := onoff;
	   14: DigOut_5_node14 := onoff;
	   15: DigOut_5_node15 := onoff;
	   16: DigOut_5_node16 := onoff;
	   17: DigOut_5_node17 := onoff;
	   18: DigOut_5_node18 := onoff;
	   19: DigOut_5_node19 := onoff;
	   20: DigOut_5_node20 := onoff;
	   21: DigOut_5_node21 := onoff;
	   22: DigOut_5_node22 := onoff;
	   23: DigOut_5_node23 := onoff;
	   24: DigOut_5_node24 := onoff;
	end_case;

	(* increment the counter, with overflow *)
	counter := counter + 1; 
	
END_PROGRAM
