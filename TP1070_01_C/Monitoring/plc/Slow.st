(*[[
]]*)
PROGRAM Slow 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	ActivePower : REAL;
	OtherPowers : REAL;
END_VAR

	ActivePower := SysActivePower_0 (* PRINCIPALE     *) + SysActivePower_1 (* FOTOVOLTAICO    *);

	OtherPowers := SysActivePower_2 (* ESTERNI        *) + SysActivePower_3 (* PIANO SOPRA     *)
				 + SysActivePower_4 (* PIANO TERRA    *) + SysActivePower_5 (* PIANO SOTTO     *)
				 + SysActivePower_6 (* AUTO ELETTRICA *) + SysActivePower_7 (* DEUMIDIFICATORE *)
				 + SysActivePower_8 (* LAVANDERIA     *) + SysActivePower_9 (* UPS             *)
				 + SysActivePower_10(* PUFFER         *)                                         ;

	SysActivePower_11 (* CALDAIA *) := ActivePower - OtherPowers;

END_PROGRAM
