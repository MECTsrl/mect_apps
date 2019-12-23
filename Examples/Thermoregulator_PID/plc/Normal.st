(*[[
]]*)
PROGRAM Normal 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	fb_Thermoregulator_PID_Inst : fb_Thermoregulator_PID;
	fb_Selftuning_Inst : fb_Selftuning;
END_VAR
	
	if Start_sw then
		if Automatic_Mode then (******PID mode******)
			fb_Thermoregulator_PID_Inst(Start := Start_sw(*bool*)
			                            (*Command_Out => bool*));
			PLC_DigOut_1 := fb_Thermoregulator_PID_Inst.Command_Out;

		else (*******MANUAL mode - command by HMI button******)
			fb_Thermoregulator_PID_Inst(Start := false);
			PLC_DigOut_1 := ManualCommandOut_1;
		end_if;
		fb_Selftuning_Inst(Start := false); (******reset self tuning*****)

	elsif Start_Self_Tuning then (******Self Tuning******)
		fb_Thermoregulator_PID_Inst(Start := false);
		fb_Selftuning_Inst(Start := Start_Self_Tuning(*bool*)
		                   (*Command_out => bool*));
		PLC_DigOut_1 := fb_Selftuning_Inst.Command_Out;
	else
		fb_Selftuning_Inst(Start := false); (******reset self tuning*****)
		PLC_DigOut_1 := false;
	end_if;
	
	
END_PROGRAM

