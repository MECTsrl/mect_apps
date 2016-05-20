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
		CheckAnOut := abs(res  - val ) <= 12; (* 0.12mA *)
	2: (* 0.00 10.00 V *)
		CheckAnOut := abs(res  - val ) <= 12; (* 0.12V *)
	3: (* PWM  0 100 % *)
		CheckAnOut := abs(res  - (val * 10) ) <= 200; (* 20 % *)
    else
    	CheckAnOut := FALSE;
    end_case;

END_FUNCTION
