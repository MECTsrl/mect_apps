(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

 	 PLC_AnInConf_1:= 7;     (* Analog inputs configuration : 0 = not configurated, 1 = current,
			                     2 =  voltage, 3 = TCJ, 4 = TCK,  5 = TCT, 6 = PT100E (NO decimal point),              
							     7 = PT100R (decimal point), 8 = TCS, 9 = TCB, 10 = TCR	*)
     PLC_DigDir_2 := 1;      (* Digital I/O configuration: 0 = input, 1 = output*)
  	 PLC_AnOutConf_1 := 2;   (* Analog outputs configuration: 0 = not configurated, 1 = current, 2 = voltage, 3 = PWM *)
	 PLC_AnIn1Filter := 64;  (* a filter is used to stabilize the signal on analogue input 1 (PLC_AnIn1), it is a power of 2 number (64 = 2^8)*)
END_PROGRAM

