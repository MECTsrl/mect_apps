(*[[
]]*)
PROGRAM RoadRunner 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	timer : TON;
	status : int := 1;
	retval : word;
END_VAR

	case status of
	1:
		(* start the first timer *)
		timer(IN := TRUE, PT := T#2ms);
		if timer.Q then
			timer(IN := FALSE);

			(* set the output high *)
	        PLC_DigOut_8 := false;

			(* start the second timer *)
			status := 2;
		end_if;
    2: 
		(* wait *)
		timer(IN := TRUE, PT := T#2ms);
		if timer.Q then
			timer(IN := FALSE);

			(* set the output low *)
	        PLC_DigOut_8 := true;

			status := 3;
		end_if;
	3:
		(* wait *)
		timer(IN := TRUE, PT := T#2ms);
		if timer.Q then
			timer(IN := FALSE);

			(* set the output low *)
	        PLC_DigOut_8 := false;

			status := 4;
		end_if;
	4: 
		(* auto disabling *)
		status := 1;
		retval := TSK_Stop('Task3_RoadRunner_1ms');
    else
		; (* never reached *)
	end_case;

END_PROGRAM
