(*[[
]]*)
PROGRAM PLC
#import "Resource1.gvl"
#import "TPACLocaIO.gvl"
#import "CANopenClient_CAN.gvl"
VAR
	info : TSK_INFO ;
	counter : INT := 0;
	task_ms : INT := -1;
	square_ms : INT := 1000;
	retval : WORD;
	first : BOOL := true;
END_VAR;
	if first then
		first := false;
		if task_ms < 0 then
			retval := TSK_GetInfo('Task0_Control', info);
			task_ms := TIME_TO_INT(info.tCycle);
		end_if;
	end_if;

	counter := (counter + 1) mod 10000;

	(* CANopen reading inputs *)
	DigitalInput_3 := BOOL_TO_UINT(ch1_CAN1_IN_DIG_8_1_3);
	DigitalInput_4 := BOOL_TO_UINT(ch1_CAN1_IN_DIG_8_1_4);
	AnalogInput_1 := ch1_CAN1_IN_AN_1;
	AnalogInput_2 := ch1_CAN1_IN_AN_2;

	(* CANopen writing output 1 *)
	if (counter mod (2 * square_ms / task_ms)) < (square_ms / task_ms) then
		DigitalOutput_1 := 1;
	else
		DigitalOutput_1 := 0;
	end_if;
	ch1_CAN1_OUT_DIG_8_1_1 := UINT_TO_BOOL(DigitalOutput_1);

	(* CANopen writing output 2 *)
	DigitalOutput_2 := DigitalInput_4;
	ch1_CAN1_OUT_DIG_8_1_2 := UINT_TO_BOOL(DigitalOutput_2);

END_PROGRAM
