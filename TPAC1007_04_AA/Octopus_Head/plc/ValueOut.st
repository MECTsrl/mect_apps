(*[[
]]*)
FUNCTION ValueOut : INT
VAR_INPUT
    valueIn : INT;
    conf : UINT;
END_VAR

    case conf of
    1: (* 4.000 20.000 mA *)
		ValueOut := valueIn / 10;
	2: (* 0.000 10.000 V *)
		ValueOut := valueIn / 10;
	3: (* TCJ 0  600 C*)
		if valueIn = 300 then ValueOut := 160; (* 300°C --> 1,60 mA *)
		elsif valueIn = 600 then ValueOut := 260; (* 600°C --> 2,60 mA *)
		else ValueOut := 0;
		end_if;
	4: (* TCK 0 1200 C*)
		ValueOut := 0;
	5: (* TCT *)
		ValueOut := 0;
	6: (* PT100E *)
		if valueIn = 100 then ValueOut := 319; (* 100°C --> 3,19 mA *)
		else ValueOut := 0;
		end_if;
	7: (* PT100R *)
		if valueIn = 100 then ValueOut := 319; (* 100°C --> 3,19 mA *)
		else ValueOut := 0;
		end_if;
	8: (* TCS *)
		ValueOut := 0;
	9: (* TCB *)
		ValueOut := 0;
	10: (* TCR *)
		ValueOut := 0;
    else
		ValueOut := 0;
    end_case;

END_FUNCTION
