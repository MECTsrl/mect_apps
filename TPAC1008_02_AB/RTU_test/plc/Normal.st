(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	counter : uint := 0;
	onoff : bool := true;
	configured : bool := false;
	first : bool := true;
	timer : TON;
	value : bool := true;
	latency_ms : DINT := 0;
	period_ms : DINT := 0;
	do_second_loop : bool := false;
	nodes_ok : int;

    INFO : TASKINFO;
END_VAR

	if not configured then

		(* waiting for CAN0 startup *)
		if not CH0_01_NODERUN then
			return;
		end_if;

		(* init analog outputs *)

		PLC_AnOutConf_1 := 2; (* 0.00 10.00 V *)
		PLC_AnOut_1 := 0;

		PLC_AnOutConf_2 := 2; (* 0.00 10.00 V *)
		PLC_AnOut_2 := 0;

		(* init analog inputs *)

		PLC_AnInConf_1 := 3; (* TCJ 0 600 °C *)
		PLC_FiltAnIn_1 := 32;

		PLC_AnInConf_2 := 3; (* TCJ 0 600 °C *)
		PLC_FiltAnIn_2 := 32;

		PLC_AnInConf_3 := 2; (* 0.000 10.000 V, wired to PLC_AnOut_1 *)
		PLC_FiltAnIn_3 := 0;

		PLC_AnInConf_4 := 2; (* 0.000 10.000 V, wired to PLC_AnOut_2 *)		
		PLC_FiltAnIn_4 := 0;

		(* init error counter *)
		errors_can := 0;

		configured := true;
    end_if;

	(* check can status *)
	if configured and not CH0_01_NODERUN then
		errors_can := errors_can + 1;
 	    return;
	end_if;

	(* init *)
	if first then
		first := false;
		
		(* 1. reset latency errors *)
		errors_all := 0;
		errors_01 := 0;
		errors_02 := 0;
		errors_03 := 0;
		errors_04 := 0;
		errors_05 := 0;
		errors_06 := 0;
		errors_07 := 0;
		errors_08 := 0;
		errors_09 := 0;
		errors_10 := 0;
		errors_11 := 0;
		errors_12 := 0;
		errors_13 := 0;
		errors_14 := 0;
		errors_15 := 0;
		errors_16 := 0;
		errors_17 := 0;
		errors_18 := 0;
		errors_19 := 0;
		errors_20 := 0;
		errors_21 := 0;
		errors_22 := 0;
		errors_23 := 0;
		errors_24 := 0;
	
		(* 2. reset latency and rearm timer *)
		latency_ms := 0;
		timer (IN := false);
	
		(* 3. reset latencies, ... *)
		latency_01_ms := -1;
		latency_02_ms := -1;
		latency_03_ms := -1;
		latency_04_ms := -1;
		latency_05_ms := -1;
		latency_06_ms := -1;
		latency_07_ms := -1;
		latency_08_ms := -1;
		latency_09_ms := -1;
		latency_10_ms := -1;
		latency_11_ms := -1;
		latency_12_ms := -1;
		latency_13_ms := -1;
		latency_14_ms := -1;
		latency_15_ms := -1;
		latency_16_ms := -1;
		latency_17_ms := -1;
		latency_18_ms := -1;
		latency_19_ms := -1;
		latency_20_ms := -1;
		latency_21_ms := -1;
		latency_22_ms := -1;
		latency_23_ms := -1;
		latency_24_ms := -1;

		min_latency_ms := -1;
		min_latency_01_m := -1;
		min_latency_02_m := -1;
		min_latency_03_m := -1;
		min_latency_04_m := -1;
		min_latency_05_m := -1;
		min_latency_06_m := -1;
		min_latency_07_m := -1;
		min_latency_08_m := -1;
		min_latency_09_m := -1;
		min_latency_10_m := -1;
		min_latency_11_m := -1;
		min_latency_12_m := -1;
		min_latency_13_m := -1;
		min_latency_14_m := -1;
		min_latency_15_m := -1;
		min_latency_16_m := -1;
		min_latency_17_m := -1;
		min_latency_18_m := -1;
		min_latency_19_m := -1;
		min_latency_20_m := -1;
		min_latency_21_m := -1;
		min_latency_22_m := -1;
		min_latency_23_m := -1;
		min_latency_24_m := -1;
		
		max_latency_ms := -1;
		max_latency_01_m := -1;
		max_latency_02_m := -1;
		max_latency_03_m := -1;
		max_latency_04_m := -1;
		max_latency_05_m := -1;
		max_latency_06_m := -1;
		max_latency_07_m := -1;
		max_latency_08_m := -1;
		max_latency_09_m := -1;
		max_latency_10_m := -1;
		max_latency_11_m := -1;
		max_latency_12_m := -1;
		max_latency_13_m := -1;
		max_latency_14_m := -1;
		max_latency_15_m := -1;
		max_latency_16_m := -1;
		max_latency_17_m := -1;
		max_latency_18_m := -1;
		max_latency_19_m := -1;
		max_latency_20_m := -1;
		max_latency_21_m := -1;
		max_latency_22_m := -1;
		max_latency_23_m := -1;
		max_latency_24_m := -1;

		(* 4. set first output values *)
		value := true;
		PLC_DigOut_1 := true;
		PLC_AnOut_1 := 900;
		PLC_AnOut_2 := 0;

		(* 5. get the task info *)
		GetLocalTaskInfo('Task4_Normal_50ms', INFO);
		period_ms := TIME_TO_DINT(INFO.CYCLE);
		OutputDebugString(CONCAT('period_ms = ', DINT_TO_STRING(period_ms), ' ms'));
	end_if;

	(* increment latency value *)
	latency_ms := latency_ms + period_ms;

	(* touch the timer *)
	timer (IN := true, PT := T#4s);

	(* FIRST/LAST STEP *)
	if timer.q = true then

		(* 0. rearm timer *)
		timer (IN := false);
	
		(* 1. check latency errors *)
		check_node(latency_01_ms, NODE_01_STATUS, errors_01, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_02_ms, NODE_02_STATUS, errors_02, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_03_ms, NODE_03_STATUS, errors_03, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_04_ms, NODE_04_STATUS, errors_04, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_05_ms, NODE_05_STATUS, errors_05, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_06_ms, NODE_06_STATUS, errors_06, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_07_ms, NODE_07_STATUS, errors_07, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_08_ms, NODE_08_STATUS, errors_08, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_09_ms, NODE_09_STATUS, errors_09, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_10_ms, NODE_10_STATUS, errors_10, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_11_ms, NODE_11_STATUS, errors_11, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_12_ms, NODE_12_STATUS, errors_12, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_13_ms, NODE_13_STATUS, errors_13, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_14_ms, NODE_14_STATUS, errors_14, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_15_ms, NODE_15_STATUS, errors_15, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_16_ms, NODE_16_STATUS, errors_16, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_17_ms, NODE_17_STATUS, errors_17, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_18_ms, NODE_18_STATUS, errors_18, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_19_ms, NODE_19_STATUS, errors_19, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_20_ms, NODE_20_STATUS, errors_20, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_21_ms, NODE_21_STATUS, errors_21, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_22_ms, NODE_22_STATUS, errors_22, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_23_ms, NODE_23_STATUS, errors_23, errors_all, min_latency_ms, max_latency_ms);
		check_node(latency_24_ms, NODE_24_STATUS, errors_24, errors_all, min_latency_ms, max_latency_ms);

		(* 2. reset latency timer *)
		latency_ms := 0;

		(* 3. reset latencies, ... *)
	    latency_01_ms := -1;
		latency_02_ms := -1;
		latency_03_ms := -1;
		latency_04_ms := -1;
		latency_05_ms := -1;
		latency_06_ms := -1;
		latency_07_ms := -1;
		latency_08_ms := -1;
		latency_09_ms := -1;
		latency_10_ms := -1;
		latency_11_ms := -1;
		latency_12_ms := -1;
		latency_13_ms := -1;
		latency_14_ms := -1;
		latency_15_ms := -1;
		latency_16_ms := -1;
		latency_17_ms := -1;
		latency_18_ms := -1;
		latency_19_ms := -1;
		latency_20_ms := -1;
		latency_21_ms := -1;
		latency_22_ms := -1;
		latency_23_ms := -1;
		latency_24_ms := -1;

		(* 4. set new output value *)
		value := not value;
		PLC_DigOut_1 := value;
		if value then
			PLC_AnOut_1 := 900;
		else
			PLC_AnOut_1 := 100;
		end_if;

		(* output is proportional to the number of reached nodes *)
		nodes_ok := 0;
		PLC_AnOut_2 := 0;

	(* OTHER STEPS *)
	else
		
		(* for each node: latency from TPAC:DigOut_1 to NODE:DigIn_7 to NODE:DigOut_8 *)

		if manage_node(DigIn_7_node01, latency_ms, value, latency_01_ms, min_latency_01_m, max_latency_01_m) then DigOut_8_node01 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node02, latency_ms, value, latency_02_ms, min_latency_02_m, max_latency_02_m) then DigOut_8_node02 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node03, latency_ms, value, latency_03_ms, min_latency_03_m, max_latency_03_m) then DigOut_8_node03 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node04, latency_ms, value, latency_04_ms, min_latency_04_m, max_latency_04_m) then DigOut_8_node04 := value; nodes_ok := nodes_ok + 1; end_if;

		if manage_node(DigIn_7_node05, latency_ms, value, latency_05_ms, min_latency_05_m, max_latency_05_m) then DigOut_8_node05 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node06, latency_ms, value, latency_06_ms, min_latency_06_m, max_latency_06_m) then DigOut_8_node06 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node07, latency_ms, value, latency_07_ms, min_latency_07_m, max_latency_07_m) then DigOut_8_node07 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node08, latency_ms, value, latency_08_ms, min_latency_08_m, max_latency_08_m) then DigOut_8_node08 := value; nodes_ok := nodes_ok + 1; end_if;

		if manage_node(DigIn_7_node09, latency_ms, value, latency_09_ms, min_latency_09_m, max_latency_09_m) then DigOut_8_node09 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node10, latency_ms, value, latency_10_ms, min_latency_10_m, max_latency_10_m) then DigOut_8_node10 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node11, latency_ms, value, latency_11_ms, min_latency_11_m, max_latency_11_m) then DigOut_8_node11 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node12, latency_ms, value, latency_12_ms, min_latency_12_m, max_latency_12_m) then DigOut_8_node12 := value; nodes_ok := nodes_ok + 1; end_if;

		if manage_node(DigIn_7_node13, latency_ms, value, latency_13_ms, min_latency_13_m, max_latency_13_m) then DigOut_8_node13 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node14, latency_ms, value, latency_14_ms, min_latency_14_m, max_latency_14_m) then DigOut_8_node14 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node15, latency_ms, value, latency_15_ms, min_latency_15_m, max_latency_15_m) then DigOut_8_node15 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node16, latency_ms, value, latency_16_ms, min_latency_16_m, max_latency_16_m) then DigOut_8_node16 := value; nodes_ok := nodes_ok + 1; end_if;

		if manage_node(DigIn_7_node17, latency_ms, value, latency_17_ms, min_latency_17_m, max_latency_17_m) then DigOut_8_node17 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node18, latency_ms, value, latency_18_ms, min_latency_18_m, max_latency_18_m) then DigOut_8_node18 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node19, latency_ms, value, latency_19_ms, min_latency_19_m, max_latency_19_m) then DigOut_8_node19 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node20, latency_ms, value, latency_20_ms, min_latency_20_m, max_latency_20_m) then DigOut_8_node20 := value; nodes_ok := nodes_ok + 1; end_if;

		if manage_node(DigIn_7_node21, latency_ms, value, latency_21_ms, min_latency_21_m, max_latency_21_m) then DigOut_8_node21 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node22, latency_ms, value, latency_22_ms, min_latency_22_m, max_latency_22_m) then DigOut_8_node22 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node23, latency_ms, value, latency_23_ms, min_latency_23_m, max_latency_23_m) then DigOut_8_node23 := value; nodes_ok := nodes_ok + 1; end_if;
		if manage_node(DigIn_7_node24, latency_ms, value, latency_24_ms, min_latency_24_m, max_latency_24_m) then DigOut_8_node24 := value; nodes_ok := nodes_ok + 1; end_if;	

		(* output is proportional to the number of reached nodes *)

		PLC_AnOut_2 := nodes_ok * 41; (* max 41 * 24 = 984 (9.84 V) *)

	end_if;

	if do_second_loop then
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

	end_if;

END_PROGRAM
