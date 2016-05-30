(*[[
]]*)
FUNCTION CheckAnIn : BOOL
VAR_INPUT
    res : INT;
    val : INT;
    conf : UINT;
END_VAR

    case conf of
    1: (* 4.000 20.000 mA *)
		CheckAnIn := abs(res  - val ) <= 100; (* 0.10mA *)
	2: (* 0.000 10.000 V *)
		CheckAnIn := abs(res  - val ) <= 100; (* 0.100V *)
	3: (* TCJ 0  600 C*)
		CheckAnIn := abs(res  - val ) <= 10; (* 10 C, 35=25..45 *)
	4: (* TCK 0 1200 C*)
		CheckAnIn := abs(res  - val ) <= 1; (* 1 C *)
	5: (* TCT *)
		CheckAnIn := abs(res  - val ) <= 1; (* 1 C *)
	6: (* PT100E *)
		CheckAnIn := abs(res  - val ) <= 5; (* 5 C, 51=46..54 *)
	7: (* PT100R *)
		CheckAnIn := abs(res  - val ) <= 50; (* 5 C, 510=460..540 *)
	8: (* TCS *)
		CheckAnIn := abs(res  - val ) <= 1; (* 1 C *)
	9: (* TCB *)
		CheckAnIn := abs(res  - val ) <= 1; (* 1 C *)
	10: (* TCR *)
		CheckAnIn := abs(res  - val ) <= 1; (* 1 C *)
    else
    	CheckAnIn := FALSE;
    end_case;

END_FUNCTION
