(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR

END_VAR

	(*I/O configuration*)
   	PLC_DigDir_1 := 1; (* Digital I/O configuration : 0 = input, 1 = output*)
	PLC_AnOutConf_1 := 2; (* Analog outputs configuration: 0 not configurated, 1 = current, 2 = voltage. *)

	(* assignment *)
	PLC_DigOut_1 := Retentive_DigVal; 
  	PLC_AnOut_1  := Retentive_AnVal; 

END_PROGRAM

