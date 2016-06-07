(*[[
]]*)
FUNCTION CheckAnIn : BOOL
VAR_INPUT
    res : INT;
    val : INT;
    conf : UINT;
	tamb : INT;
END_VAR

    case conf of
    1: (* 4.000 20.000 mA *)
		CheckAnIn := abs(res  - val ) <= 100; (* 0.10mA *)
	2: (* 0.000 10.000 V *)
		CheckAnIn := abs(res  - val ) <= 100; (* 0.100V *)
	3: (* TCJ 0  600 C*)
		CheckAnIn := abs(res * 10 - tamb) <= 150; (* 15 °C, short => Tamb +/- 15 *)
	4: (* TCK 0 1200 C*)
		CheckAnIn := abs(res * 10 - tamb) <= 150; (* 15 °C, short => Tamb +/- 15 *)
	5: (* TCT *)
		CheckAnIn := abs(res * 10 - tamb) <= 150; (* 15 °C, short => Tamb +/- 15 *)
	6: (* PT100E *)
		CheckAnIn := abs(res  - val ) <= 5; (* 5 °C, 51=46..54 *)
	7: (* PT100R *)
		CheckAnIn := abs(res  - val ) <= 50; (* 5 °C, 510=460..540 *)
	8: (* TCS *)
		CheckAnIn := abs(res * 10 - tamb) <= 150; (* 15 °C, short => Tamb +/- 15 *)
	9: (* TCB *)
		CheckAnIn := abs(res * 10 - tamb) <= 150; (* 15 °C, short => Tamb +/- 15 *)
	10: (* TCR *)
		CheckAnIn := abs(res * 10 - tamb) <= 150; (* 15 °C, short => Tamb +/- 15 *)
    else
    	CheckAnIn := FALSE;
    end_case;

END_FUNCTION
