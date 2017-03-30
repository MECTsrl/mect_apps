(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	counter : uint := 0;
	onoff : bool := true;
	first : bool := true;
	timer : TON;
	value : bool := true;
	timer_ms : UINT := 0;
	period_ms : UINT := 0;
	do_second_loop : bool := false;

    INFO : TASKINFO;
END_VAR

	(* check can status *)
	if CH0_01_NODERUN = false then
		if not first then
			errors_can := errors_can + 1;
		end_if;
 	    return;
	end_if;

	(* init *)
	if first then
		first := false;

		(* 0. init analog outputs *)
		PLC_AnOutConf_1 := 2;
		PLC_AnOutConf_2 := 2;
		PLC_AnOut_1 := 0;
		PLC_AnOut_2 := 0;
		
		errors_can := 0;

		(* 1. reset latency errors *)
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
		timer_ms := 0;
		timer (IN := false);
	
		(* 3. reset latencies, ... *)
		latency_01_ms := 0;
		latency_02_ms := 0;
		latency_03_ms := 0;
		latency_04_ms := 0;
		latency_05_ms := 0;
		latency_06_ms := 0;
		latency_07_ms := 0;
		latency_08_ms := 0;
		latency_09_ms := 0;
		latency_10_ms := 0;
		latency_11_ms := 0;
		latency_12_ms := 0;
		latency_13_ms := 0;
		latency_14_ms := 0;
		latency_15_ms := 0;
		latency_16_ms := 0;
		latency_17_ms := 0;
		latency_18_ms := 0;
		latency_19_ms := 0;
		latency_20_ms := 0;
		latency_21_ms := 0;
		latency_22_ms := 0;
		latency_23_ms := 0;
		latency_24_ms := 0;

		min_latency_01_m := 0;
		min_latency_02_m := 0;
		min_latency_03_m := 0;
		min_latency_04_m := 0;
		min_latency_05_m := 0;
		min_latency_06_m := 0;
		min_latency_07_m := 0;
		min_latency_08_m := 0;
		min_latency_09_m := 0;
		min_latency_10_m := 0;
		min_latency_11_m := 0;
		min_latency_12_m := 0;
		min_latency_13_m := 0;
		min_latency_14_m := 0;
		min_latency_15_m := 0;
		min_latency_16_m := 0;
		min_latency_17_m := 0;
		min_latency_18_m := 0;
		min_latency_19_m := 0;
		min_latency_20_m := 0;
		min_latency_21_m := 0;
		min_latency_22_m := 0;
		min_latency_23_m := 0;
		min_latency_24_m := 0;
		
		max_latency_01_m := 0;
		max_latency_02_m := 0;
		max_latency_03_m := 0;
		max_latency_04_m := 0;
		max_latency_05_m := 0;
		max_latency_06_m := 0;
		max_latency_07_m := 0;
		max_latency_08_m := 0;
		max_latency_09_m := 0;
		max_latency_10_m := 0;
		max_latency_11_m := 0;
		max_latency_12_m := 0;
		max_latency_13_m := 0;
		max_latency_14_m := 0;
		max_latency_15_m := 0;
		max_latency_16_m := 0;
		max_latency_17_m := 0;
		max_latency_18_m := 0;
		max_latency_19_m := 0;
		max_latency_20_m := 0;
		max_latency_21_m := 0;
		max_latency_22_m := 0;
		max_latency_23_m := 0;
		max_latency_24_m := 0;

		(* 4. set first output values *)
		value := true;
		PLC_DigOut_1 := true;
		PLC_AnOut_1 := 900;
		PLC_AnOut_2 := 100;

		(* 5. get the task info *)
		GetLocalTaskInfo('Task4_Normal_50ms', INFO);
		period_ms := INT_TO_UINT(TIME_TO_INT(INFO.CYCLE));
		OutputDebugString(CONCAT('period_ms = ', UINT_TO_STRING(period_ms), ' ms'));
	end_if;

	(* increment latency value *)
	timer_ms := timer_ms + period_ms;

	(* touch the timer *)
	timer (IN := true, PT := T#4s);

	(* FIRST/LAST STEP *)
	if timer.q = true then

		(* 0. rearm timer *)
		timer (IN := false);
	
		(* 1. check latency errors *)
		if latency_01_ms = 0 or NODE_01_STATUS <> 1 then
			errors_01 := errors_01 + 1;
		end_if;
		if latency_02_ms = 0 or NODE_02_STATUS <> 1 then
			errors_02 := errors_02 + 1;
		end_if;
		if latency_03_ms = 0 or NODE_03_STATUS <> 1 then
			errors_03 := errors_03 + 1;
		end_if;
		if latency_04_ms = 0 or NODE_04_STATUS <> 1 then
			errors_04 := errors_04 + 1;
		end_if;
		if latency_05_ms = 0 or NODE_05_STATUS <> 1 then
			errors_05 := errors_05 + 1;
		end_if;
		if latency_06_ms = 0 or NODE_06_STATUS <> 1 then
			errors_06 := errors_06 + 1;
		end_if;
		if latency_07_ms = 0 or NODE_07_STATUS <> 1 then
			errors_07 := errors_07 + 1;
		end_if;
		if latency_08_ms = 0 or NODE_08_STATUS <> 1 then
			errors_08 := errors_08 + 1;
		end_if;
		if latency_09_ms = 0 or NODE_09_STATUS <> 1 then
			errors_09 := errors_09 + 1;
		end_if;
		if latency_10_ms = 0 or NODE_10_STATUS <> 1 then
			errors_10 := errors_10 + 1;
		end_if;
		if latency_11_ms = 0 or NODE_11_STATUS <> 1 then
			errors_11 := errors_11 + 1;
		end_if;
		if latency_12_ms = 0 or NODE_12_STATUS <> 1 then
			errors_12 := errors_12 + 1;
		end_if;
		if latency_13_ms = 0 or NODE_13_STATUS <> 1 then
			errors_13 := errors_13 + 1;
		end_if;
		if latency_14_ms = 0 or NODE_14_STATUS <> 1 then
			errors_14 := errors_14 + 1;
		end_if;
		if latency_15_ms = 0 or NODE_15_STATUS <> 1 then
			errors_15 := errors_15 + 1;
		end_if;
		if latency_16_ms = 0 or NODE_16_STATUS <> 1 then
			errors_16 := errors_16 + 1;
		end_if;
		if latency_17_ms = 0 or NODE_17_STATUS <> 1 then
			errors_17 := errors_17 + 1;
		end_if;
		if latency_18_ms = 0 or NODE_18_STATUS <> 1 then
			errors_18 := errors_18 + 1;
		end_if;
		if latency_19_ms = 0 or NODE_19_STATUS <> 1 then
			errors_19 := errors_19 + 1;
		end_if;
		if latency_20_ms = 0 or NODE_20_STATUS <> 1 then
			errors_20 := errors_20 + 1;
		end_if;
		if latency_21_ms = 0 or NODE_21_STATUS <> 1 then
			errors_21 := errors_21 + 1;
		end_if;
		if latency_22_ms = 0 or NODE_22_STATUS <> 1 then
			errors_22 := errors_22 + 1;
		end_if;
		if latency_23_ms = 0 or NODE_23_STATUS <> 1 then
			errors_23 := errors_23 + 1;
		end_if;
		if latency_24_ms = 0 or NODE_24_STATUS <> 1 then
			errors_24 := errors_24 + 1;
		end_if;

		(* 2. reset latency timer *)
		timer_ms := 0;

		(* 3. reset latencies, ... *)
	    latency_01_ms := 0;
		latency_02_ms := 0;
		latency_03_ms := 0;
		latency_04_ms := 0;
		latency_05_ms := 0;
		latency_06_ms := 0;
		latency_07_ms := 0;
		latency_08_ms := 0;
		latency_09_ms := 0;
		latency_10_ms := 0;
		latency_11_ms := 0;
		latency_12_ms := 0;
		latency_13_ms := 0;
		latency_14_ms := 0;
		latency_15_ms := 0;
		latency_16_ms := 0;
		latency_17_ms := 0;
		latency_18_ms := 0;
		latency_19_ms := 0;
		latency_20_ms := 0;
		latency_21_ms := 0;
		latency_22_ms := 0;
		latency_23_ms := 0;
		latency_24_ms := 0;

		(* 4. set new output value *)
		value := not value;
		PLC_DigOut_1 := value;
		if value then
			PLC_AnOut_1 := 900;
			PLC_AnOut_2 := 100;
		else
			PLC_AnOut_1 := 100;
			PLC_AnOut_2 := 900;
		end_if;

	(* OTHER STEPS *)
	else
		
		(* for each node: latency from TPAC:DigOut_1 to NODE:DigIn_7 to NODE:DigOut_8 *)

		if latency_01_ms = 0 and DigIn_7_node01 = value then
			(* measure the latency *)
		    latency_01_ms := timer_ms;
			if max_latency_01_m < timer_ms then
				max_latency_01_m := timer_ms;
			end_if;
			if min_latency_01_m > timer_ms or min_latency_01_m = 0 then
				min_latency_01_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node01 := value;
		end_if;	
		if latency_02_ms = 0 and DigIn_7_node02 = value then
			(* measure the latency *)
		    latency_02_ms := timer_ms;
			if max_latency_02_m < timer_ms then
				max_latency_02_m := timer_ms;
			end_if;
			if min_latency_02_m > timer_ms or min_latency_02_m = 0 then
				min_latency_02_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node02 := value;
		end_if;	
		if latency_03_ms = 0 and DigIn_7_node03 = value then
			(* measure the latency *)
		    latency_03_ms := timer_ms;
			if max_latency_03_m < timer_ms then
				max_latency_03_m := timer_ms;
			end_if;
			if min_latency_03_m > timer_ms or min_latency_03_m = 0 then
				min_latency_03_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node03 := value;
		end_if;	
		if latency_04_ms = 0 and DigIn_7_node04 = value then
			(* measure the latency *)
		    latency_04_ms := timer_ms;
			if max_latency_04_m < timer_ms then
				max_latency_04_m := timer_ms;
			end_if;
			if min_latency_04_m > timer_ms or min_latency_04_m = 0 then
				min_latency_04_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node04 := value;
		end_if;	
		if latency_05_ms = 0 and DigIn_7_node05 = value then
			(* measure the latency *)
		    latency_05_ms := timer_ms;
			if max_latency_05_m < timer_ms then
				max_latency_05_m := timer_ms;
			end_if;
			if min_latency_05_m > timer_ms or min_latency_05_m = 0 then
				min_latency_05_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node05 := value;
		end_if;	
		if latency_06_ms = 0 and DigIn_7_node06 = value then
			(* measure the latency *)
		    latency_06_ms := timer_ms;
			if max_latency_06_m < timer_ms then
				max_latency_06_m := timer_ms;
			end_if;
			if min_latency_06_m > timer_ms or min_latency_06_m = 0 then
				min_latency_06_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node06 := value;
		end_if;	
		if latency_07_ms = 0 and DigIn_7_node07 = value then
			(* measure the latency *)
		    latency_07_ms := timer_ms;
			if max_latency_07_m < timer_ms then
				max_latency_07_m := timer_ms;
			end_if;
			if min_latency_07_m > timer_ms or min_latency_07_m = 0 then
				min_latency_07_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node07 := value;
		end_if;	
		if latency_08_ms = 0 and DigIn_7_node08 = value then
			(* measure the latency *)
		    latency_08_ms := timer_ms;
			if max_latency_08_m < timer_ms then
				max_latency_08_m := timer_ms;
			end_if;
			if min_latency_08_m > timer_ms or min_latency_08_m = 0 then
				min_latency_08_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node08 := value;
		end_if;	
		if latency_09_ms = 0 and DigIn_7_node09 = value then
			(* measure the latency *)
		    latency_09_ms := timer_ms;
			if max_latency_09_m < timer_ms then
				max_latency_09_m := timer_ms;
			end_if;
			if min_latency_09_m > timer_ms or min_latency_09_m = 0 then
				min_latency_09_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node09 := value;
		end_if;	
		if latency_10_ms = 0 and DigIn_7_node10 = value then
			(* measure the latency *)
		    latency_10_ms := timer_ms;
			if max_latency_10_m < timer_ms then
				max_latency_10_m := timer_ms;
			end_if;
			if min_latency_10_m > timer_ms or min_latency_10_m = 0 then
				min_latency_10_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node10 := value;
		end_if;	
		if latency_11_ms = 0 and DigIn_7_node11 = value then
			(* measure the latency *)
		    latency_11_ms := timer_ms;
			if max_latency_11_m < timer_ms then
				max_latency_11_m := timer_ms;
			end_if;
			if min_latency_11_m > timer_ms or min_latency_11_m = 0 then
				min_latency_11_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node11 := value;
		end_if;	
		if latency_12_ms = 0 and DigIn_7_node12 = value then
			(* measure the latency *)
		    latency_12_ms := timer_ms;
			if max_latency_12_m < timer_ms then
				max_latency_12_m := timer_ms;
			end_if;
			if min_latency_12_m > timer_ms or min_latency_12_m = 0 then
				min_latency_12_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node12 := value;
		end_if;	
		if latency_13_ms = 0 and DigIn_7_node13 = value then
			(* measure the latency *)
		    latency_13_ms := timer_ms;
			if max_latency_13_m < timer_ms then
				max_latency_13_m := timer_ms;
			end_if;
			if min_latency_13_m > timer_ms or min_latency_13_m = 0 then
				min_latency_13_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node13 := value;
		end_if;	
		if latency_14_ms = 0 and DigIn_7_node14 = value then
			(* measure the latency *)
		    latency_14_ms := timer_ms;
			if max_latency_14_m < timer_ms then
				max_latency_14_m := timer_ms;
			end_if;
			if min_latency_14_m > timer_ms or min_latency_14_m = 0 then
				min_latency_14_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node14 := value;
		end_if;	
		if latency_15_ms = 0 and DigIn_7_node15 = value then
			(* measure the latency *)
		    latency_15_ms := timer_ms;
			if max_latency_15_m < timer_ms then
				max_latency_15_m := timer_ms;
			end_if;
			if min_latency_15_m > timer_ms or min_latency_15_m = 0 then
				min_latency_15_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node15 := value;
		end_if;	
		if latency_16_ms = 0 and DigIn_7_node16 = value then
			(* measure the latency *)
		    latency_16_ms := timer_ms;
			if max_latency_16_m < timer_ms then
				max_latency_16_m := timer_ms;
			end_if;
			if min_latency_16_m > timer_ms or min_latency_16_m = 0 then
				min_latency_16_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node16 := value;
		end_if;	
		if latency_17_ms = 0 and DigIn_7_node17 = value then
			(* measure the latency *)
		    latency_17_ms := timer_ms;
			if max_latency_17_m < timer_ms then
				max_latency_17_m := timer_ms;
			end_if;
			if min_latency_17_m > timer_ms or min_latency_17_m = 0 then
				min_latency_17_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node17 := value;
		end_if;	
		if latency_18_ms = 0 and DigIn_7_node18 = value then
			(* measure the latency *)
		    latency_18_ms := timer_ms;
			if max_latency_18_m < timer_ms then
				max_latency_18_m := timer_ms;
			end_if;
			if min_latency_18_m > timer_ms or min_latency_18_m = 0 then
				min_latency_18_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node18 := value;
		end_if;	
		if latency_19_ms = 0 and DigIn_7_node19 = value then
			(* measure the latency *)
		    latency_19_ms := timer_ms;
			if max_latency_19_m < timer_ms then
				max_latency_19_m := timer_ms;
			end_if;
			if min_latency_19_m > timer_ms or min_latency_19_m = 0 then
				min_latency_19_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node19 := value;
		end_if;	
		if latency_20_ms = 0 and DigIn_7_node20 = value then
			(* measure the latency *)
		    latency_20_ms := timer_ms;
			if max_latency_20_m < timer_ms then
				max_latency_20_m := timer_ms;
			end_if;
			if min_latency_20_m > timer_ms or min_latency_20_m = 0 then
				min_latency_20_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node20 := value;
		end_if;	
		if latency_21_ms = 0 and DigIn_7_node21 = value then
			(* measure the latency *)
		    latency_21_ms := timer_ms;
			if max_latency_21_m < timer_ms then
				max_latency_21_m := timer_ms;
			end_if;
			if min_latency_21_m > timer_ms or min_latency_21_m = 0 then
				min_latency_21_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node21 := value;
		end_if;	
		if latency_22_ms = 0 and DigIn_7_node22 = value then
			(* measure the latency *)
		    latency_22_ms := timer_ms;
			if max_latency_22_m < timer_ms then
				max_latency_22_m := timer_ms;
			end_if;
			if min_latency_22_m > timer_ms or min_latency_22_m = 0 then
				min_latency_22_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node22 := value;
		end_if;	
		if latency_23_ms = 0 and DigIn_7_node23 = value then
			(* measure the latency *)
		    latency_23_ms := timer_ms;
			if max_latency_23_m < timer_ms then
				max_latency_23_m := timer_ms;
			end_if;
			if min_latency_23_m > timer_ms or min_latency_23_m = 0 then
				min_latency_23_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node23 := value;
		end_if;	
		if latency_24_ms = 0 and DigIn_7_node24 = value then
			(* measure the latency *)
		    latency_24_ms := timer_ms;
			if max_latency_24_m < timer_ms then
				max_latency_24_m := timer_ms;
			end_if;
			if min_latency_24_m > timer_ms or min_latency_24_m = 0 then
				min_latency_24_m := timer_ms;
			end_if;
			(* write the output *)
			DigOut_8_node24 := value;
		end_if;	

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
