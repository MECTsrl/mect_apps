(*[[
]]*)
FUNCTION CheckAnOut : BOOL
VAR_INPUT
    res : INT;
    val : INT;
    conf : UINT;
END_VAR

    case conf of
    1: (* 4.00 20.00 mA *)
		CheckAnOut := abs(res  - val ) <= 22; (* 20.00 mA * (0.5% + 0.5% + 0.1%) = 0.22 mA *)
	2: (* 0.00 10.00 V *)
		CheckAnOut := abs(res  - val ) <= 11; (* 10.00 V * (0.5% + 0.5% + 0.1%) = 0.11 V *)
	3: (* PWM  0 100 % --> 0.000 10.000 V +/- 2.500 V *)
		CheckAnOut := abs(res  - (val * 10) ) <= 2500; (* 0% 50% 100% --> 0V 5V 10V +/- 2.5V *)
    else
    	CheckAnOut := FALSE;
    end_case;

END_FUNCTION
