(*[[
]]*)
FUNCTION_BLOCK fb_Thermoregulator_PID
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR_INPUT
	Start : bool;
END_VAR
VAR_OUTPUT
	Command_Out : bool := false; 
END_VAR
VAR
	PID_Inst : PID;
	PWM_Inst : PWM;
END_VAR

	PID_Inst(CONTROL := (int_to_real(PLC_AnIn_1)/ 10.0)(*REAL*),
             KP_in := KP (*REAL*),
             KI_in := KI (*REAL*),
             KD_in := KD (*REAL*),
             SETPOINT := Set_Temperature (*REAL*),
             CYCLE := 10000 (*UDINT*),
             CUT_BACK := Cutback(*REAL*),
             START := Start(*BOOL*)
             (*COMMAND => REAL
               ERROR => BOOL
               NEWVAL => BOOL*));

    PWM_Inst(DC := real_to_int(PID_Inst.COMMAND)(*INT*),
            PERIOD := 10(*INT*), (*s*)
            START := Start(*BOOL*)
            (*Q => BOOL*));

	Command_Out := PWM_Inst.Q;

END_FUNCTION_BLOCK
