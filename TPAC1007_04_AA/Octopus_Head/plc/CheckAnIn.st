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
		CheckAnIn := abs(res - val ) <= 220; (* 20.000 mA * (0.5% + 0.5% + 0.1%) = 0.220 mA *)
	2: (* 0.000 10.000 V *)
		CheckAnIn := abs(res - val ) <= 110; (* 10.000 V * (0.5% + 0.5% + 0.1%) = 0.110 V *)
	3: (* TCJ 0  600 C*)
		CheckAnIn := abs(res * 10 - tamb - val * 10) <= 750; (* 75 30 °C, short => Tamb +/- 15 *)
	4: (* TCK 0 1200 C*)
		CheckAnIn := abs(res * 10 - tamb - val * 10) <= 300; (* 30 °C, short => Tamb +/- 15 *)
	5: (* TCT *)
		CheckAnIn := abs(res * 10 - tamb - val * 10) <= 300; (* 30 °C, short => Tamb +/- 15 *)
	6: (* PT100E *)
		CheckAnIn := abs(res  - val ) <= 4; (* 4°C = 800°C * 0.5% fs *)
	7: (* PT100R *)
		CheckAnIn := abs(res  - val ) <= 5; (* 0.5°C = 200.0°C * 0.25% fs *)
	8: (* TCS *)
		CheckAnIn := abs(res * 10 - tamb - val * 10) <= 300; (* 30 °C, short => Tamb +/- 15 *)
	9: (* TCB *)
		CheckAnIn := abs(res * 10 - tamb - val * 10) <= 300; (* 30 °C, short => Tamb +/- 15 *)
	10: (* TCR *)
		CheckAnIn := abs(res * 10 - tamb - val * 10) <= 300; (* 30 °C, short => Tamb +/- 15 *)
    else
    	CheckAnIn := FALSE;
    end_case;

END_FUNCTION
