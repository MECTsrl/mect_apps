(*[[
]]*)
FUNCTION_BLOCK fb_Selftuning
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR_INPUT
	Start : bool;
END_VAR
VAR_OUTPUT
	Command_out : bool := false;
END_VAR
VAR
	PID_Selftuning_Inst : PID_Selftuning;
END_VAR

if Start then
	PID_Selftuning_Inst(CONTROL := int_to_real(PLC_AnIn_1) / 10.0(*REAL*),
                        START := true (*BOOL*),
                        SETPOINT := Set_Temperature_SelfTun (*REAL*)
                        (*KP_out => REAL
                          KI_out => REAL
                          KD_out => REAL
                          COMMAND => REAL
                          TUNED => BOOL
                          CUT_BACK => REAL*));

	if PID_Selftuning_Inst.COMMAND  > 0.0 then
		Command_out := true;
	else
		Command_out := false;
	end_if;		

	if PID_Selftuning_Inst.TUNED then (*end process -> see the new PID paramenter*)
		Command_out := false;
		kp_SelfTuning := PID_Selftuning_Inst.KP_out;
		kd_SelfTuning := PID_Selftuning_Inst.KD_out;
		ki_SelfTuning := PID_Selftuning_Inst.KI_out;
		Cutback_SelfTuning := PID_Selftuning_Inst.CUT_BACK;
		Start_Self_Tuning := false;
	end_if;		
else
	PID_Selftuning_Inst(START := false);
end_if;

END_FUNCTION_BLOCK
