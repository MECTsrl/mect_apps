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

	(*******************************************************************************************)

	TCP_is_Caldaia_ON          := is_Caldaia_ON        ;
	TCP_AnIn_A_1               := XX_AnIn_A_1          ;
	TCP_AnIn_A_2               := XX_AnIn_A_2          ;
	TCP_AnIn_A_3               := XX_AnIn_A_3          ;
	TCP_AnIn_A_4               := XX_AnIn_A_4          ;
	TCP_AnIn_B_1               := XX_AnIn_B_1          ;
	TCP_AnIn_B_2               := XX_AnIn_B_2          ;
	TCP_AnIn_B_3               := XX_AnIn_B_3          ;
	TCP_AnIn_B_4               := XX_AnIn_B_4          ;
	TCP_AnIn_C_1               := XX_AnIn_C_1          ;
	TCP_AnIn_C_2               := XX_AnIn_C_2          ;
	TCP_AnIn_C_3               := XX_AnIn_C_3          ;
	TCP_AnIn_C_4               := XX_AnIn_C_4          ;
	TCP_AnIn_1                 := XX_AnIn_1            ;
	TCP_AnIn_2                 := XX_AnIn_2            ;
	TCP_DigIn_1                := XX_DigIn_1           ;
	TCP_DigIn_2                := XX_DigIn_2           ;
	TCP_DigIn_3                := XX_DigIn_3           ;
	TCP_DigIn_4                := XX_DigIn_4           ;
	TCP_DigIn_5                := XX_DigIn_5           ;
	TCP_DigIn_6                := XX_DigIn_6           ;
	TCP_DigIn_7                := XX_DigIn_7           ;
	TCP_DigIn_8                := XX_DigIn_8           ;
	TCP_DigOut_1               := XX_DigOut_1          ;
	TCP_DigOut_2               := XX_DigOut_2          ;
	TCP_DigOut_3               := XX_DigOut_3          ;
	TCP_DigOut_4               := XX_DigOut_4          ;
	TCP_DigOut_5               := XX_DigOut_5          ;
	TCP_DigOut_6               := XX_DigOut_6          ;
	TCP_DigOut_7               := XX_DigOut_7          ;
	TCP_DigOut_8               := XX_DigOut_8          ;
	                                                   ;
	TCP_SystemVoltage_0        := SystemVoltage_0      ;
	TCP_SysPowerFactor_0       := SysPowerFactor_0     ;
	TCP_SysActivePower_0       := SysActivePower_0     ;
	TCP_SysImpActiveEnergy_0   := SysImpActiveEnergy_0 ;
	TCP_SysExpActiveEnergy_0   := SysExpActiveEnergy_0 ;
	TCP_SysActivePower_1       := SysActivePower_1     ;
	TCP_SysImpActiveEnergy_1   := SysImpActiveEnergy_1 ;
	TCP_SysExpActiveEnergy_1   := SysExpActiveEnergy_1 ;
	TCP_SysActivePower_2       := SysActivePower_2     ;
	TCP_SysImpActiveEnergy_2   := SysImpActiveEnergy_2 ;
	TCP_SysActivePower_3       := SysActivePower_3     ;
	TCP_SysImpActiveEnergy_3   := SysImpActiveEnergy_3 ;
	TCP_SysActivePower_4       := SysActivePower_4     ;
	TCP_SysImpActiveEnergy_4   := SysImpActiveEnergy_4 ;
	TCP_SysActivePower_5       := SysActivePower_5     ;
	TCP_SysImpActiveEnergy_5   := SysImpActiveEnergy_5 ;
	TCP_SysActivePower_6       := SysActivePower_6     ;
	TCP_SysImpActiveEnergy_6   := SysImpActiveEnergy_6 ;
	TCP_SysActivePower_7       := SysActivePower_7     ;
	TCP_SysImpActiveEnergy_7   := SysImpActiveEnergy_7 ;
	TCP_SysActivePower_8       := SysActivePower_8     ;
	TCP_SysImpActiveEnergy_8   := SysImpActiveEnergy_8 ;
	TCP_SysActivePower_9       := SysActivePower_9     ;
	TCP_SysApparentPower_9     := SysApparentPower_9   ;
	TCP_SysImpActiveEnergy_9   := SysImpActiveEnergy_9 ;
	TCP_SysActivePower_10      := SysActivePower_10    ;
	TCP_SysImpActiveEnergy_10  := SysImpActiveEnergy_10;
	TCP_SysActivePower_11      := SysActivePower_11    ;
	TCP_SysImpActiveEnergy_11  := SysImpActiveEnergy_11;

END_PROGRAM
