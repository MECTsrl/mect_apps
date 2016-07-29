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
	onoff := ((counter / 12) mod 2) = 0;

	(* in each round touch every node *)
	case (counter mod 12) + 1 of
		1: DigOut_5_node01 := onoff; DigOut_5_node13 := onoff;
	    2: DigOut_5_node02 := onoff; DigOut_5_node14 := onoff;
        3: DigOut_5_node03 := onoff; DigOut_5_node15 := onoff;
	    4: DigOut_5_node04 := onoff; DigOut_5_node16 := onoff;
	    5: DigOut_5_node05 := onoff; DigOut_5_node17 := onoff;
	    6: DigOut_5_node06 := onoff; DigOut_5_node18 := onoff;
	    7: DigOut_5_node07 := onoff; DigOut_5_node19 := onoff;
	    8: DigOut_5_node08 := onoff; DigOut_5_node20 := onoff;
	    9: DigOut_5_node09 := onoff; DigOut_5_node21 := onoff;
	   10: DigOut_5_node10 := onoff; DigOut_5_node22 := onoff;
	   11: DigOut_5_node11 := onoff; DigOut_5_node23 := onoff;
	   12: DigOut_5_node12 := onoff; DigOut_5_node24 := onoff;
    else
	   ;
	end_case;

	(* increment the counter, with overflow *)
	counter := counter + 1; 

	(* latency from DigIn_7 to DigOut_8 *)
	if (DigIn_7_node01 <> DigOut_8_node01) then DigOut_8_node01 := DigIn_7_node01; end_if;
	if (DigIn_7_node02 <> DigOut_8_node02) then DigOut_8_node02 := DigIn_7_node02; end_if;
	if (DigIn_7_node03 <> DigOut_8_node03) then DigOut_8_node03 := DigIn_7_node03; end_if;
	if (DigIn_7_node04 <> DigOut_8_node04) then DigOut_8_node04 := DigIn_7_node04; end_if;
	if (DigIn_7_node05 <> DigOut_8_node05) then DigOut_8_node05 := DigIn_7_node05; end_if;
	if (DigIn_7_node06 <> DigOut_8_node06) then DigOut_8_node06 := DigIn_7_node06; end_if;
	if (DigIn_7_node07 <> DigOut_8_node07) then DigOut_8_node07 := DigIn_7_node07; end_if;
	if (DigIn_7_node08 <> DigOut_8_node08) then DigOut_8_node08 := DigIn_7_node08; end_if;
	if (DigIn_7_node09 <> DigOut_8_node09) then DigOut_8_node09 := DigIn_7_node09; end_if;
	if (DigIn_7_node10 <> DigOut_8_node10) then DigOut_8_node10 := DigIn_7_node10; end_if;
	if (DigIn_7_node11 <> DigOut_8_node11) then DigOut_8_node11 := DigIn_7_node11; end_if;
	if (DigIn_7_node12 <> DigOut_8_node12) then DigOut_8_node12 := DigIn_7_node12; end_if;
	if (DigIn_7_node13 <> DigOut_8_node13) then DigOut_8_node13 := DigIn_7_node13; end_if;
	if (DigIn_7_node14 <> DigOut_8_node14) then DigOut_8_node14 := DigIn_7_node14; end_if;
	if (DigIn_7_node15 <> DigOut_8_node15) then DigOut_8_node15 := DigIn_7_node15; end_if;
	if (DigIn_7_node16 <> DigOut_8_node16) then DigOut_8_node16 := DigIn_7_node16; end_if;
	if (DigIn_7_node17 <> DigOut_8_node17) then DigOut_8_node17 := DigIn_7_node17; end_if;
	if (DigIn_7_node18 <> DigOut_8_node18) then DigOut_8_node18 := DigIn_7_node18; end_if;
	if (DigIn_7_node19 <> DigOut_8_node19) then DigOut_8_node19 := DigIn_7_node19; end_if;
	if (DigIn_7_node20 <> DigOut_8_node20) then DigOut_8_node20 := DigIn_7_node20; end_if;
	if (DigIn_7_node21 <> DigOut_8_node21) then DigOut_8_node21 := DigIn_7_node21; end_if;
	if (DigIn_7_node22 <> DigOut_8_node22) then DigOut_8_node22 := DigIn_7_node22; end_if;
	if (DigIn_7_node23 <> DigOut_8_node23) then DigOut_8_node23 := DigIn_7_node23; end_if;
	if (DigIn_7_node24 <> DigOut_8_node24) then DigOut_8_node24 := DigIn_7_node24; end_if;
	
END_PROGRAM
