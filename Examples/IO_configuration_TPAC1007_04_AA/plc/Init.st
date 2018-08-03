(*[[
]]*)
PROGRAM Init (*it only runs once / viene eseguito una solamente una volta*)
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

    PLC_DigDir_1 := 1; (* configure digital I/O: 1 as output, 0 as input*)
    PLC_DigDir_2 := 1;
    PLC_DigDir_3 := 1;
    PLC_DigDir_4 := 1;

    PLC_DigDir_5 := 0;
    PLC_DigDir_6 := 0;
    PLC_DigDir_7 := 0;
    PLC_DigDir_8 := 0;

	PLC_AnInConf_1 := 1; (*  configure analog inputs: 0 = not configurated, 1 = current,
		                     2 = voltage, 3 = TCJ, 4 = TCK,  5 = TCT, 6 = PT100E,              
						     7= PT100R (with decimal point), 8 =  TCS, 9 =  TCB, 10 =  TCR	*)				 
	PLC_AnInConf_2 := 2;									
											
	                        
    
    PLC_AnOutConf_1 := 1; (* configure analog outputs: 0 not configurated, 1 = current, 2 = voltage. *)
    PLC_AnOutConf_2 := 2;

    PLC_EncoderStart := 1; (* configure encoder : 0 = not enabled, 1 = bidirectional encoder enabled, 2 = counter *)

END_PROGRAM

