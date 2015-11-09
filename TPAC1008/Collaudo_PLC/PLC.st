(*[[
]]*)
PROGRAM PLC 
#import "Resource1.gvl"
#import "TPACLocaIO.gvl" (* <---= *)
#import "Collaudo_CAN.gvl"
VAR
	fb_HW119_PLCwriteVar_Inst : fb_HW119_PLCwriteVar;
	counter : UDINT := 0;
	divisor : UDINT := 10;
	values : ARRAY [0..15] OF DWORD;
	TIMER1:TON;
	TIMER2:TON;
END_VAR;
if Parti = 1 then 
	TIMER2(IN:=TRUE,PT:=T#1s);
	IF TIMER2.Q THEN
	TIMER2(IN:=FALSE,PT:=T#1s);
		if counter = 0 * divisor then
			PLC_DigOut_1:=0;
			PLC_DigOut_2:=0;
			PLC_DigOut_3:=0;
			PLC_DigOut_4:=0;
			PLC_DigOut_5:=0;
			PLC_DigOut_6:=0;
			PLC_DigOut_7:=0;
			PLC_DigOut_8:=0;
			PLC_DigOut_9:=0;
			PLC_DigOut_10:=0;
			PLC_DigOut_11:=0;
			PLC_DigOut_12:=0;
			PLC_DigOut_13:=0;
			PLC_DigOut_14:=0;
			PLC_DigOut_15:=0;
			PLC_DigOut_16:=0;
		elsif counter = 1  then
			PLC_DigOut_1 := 1;
		elsif counter = 2  then
			PLC_DigOut_1 := 0;
			PLC_DigOut_2 := 1;
		elsif counter = 3 then
			PLC_DigOut_2 := 0;
			PLC_DigOut_3 := 1;
		elsif counter = 4 then
			PLC_DigOut_3 := 0;
			PLC_DigOut_4 := 1;
		elsif counter = 5 then
			PLC_DigOut_4 := 0;
			PLC_DigOut_5 := 1;
		elsif counter = 6 then
			PLC_DigOut_5 := 0;
			PLC_DigOut_6 := 1;
		elsif counter = 7 then
			PLC_DigOut_6 := 0;
			PLC_DigOut_7 := 1;
		elsif counter = 8 then
			PLC_DigOut_7 := 0;
			PLC_DigOut_8 := 1;
		elsif counter = 9 then
			PLC_DigOut_8 := 0;
			PLC_DigOut_9 := 1;
		elsif counter = 10 then
			PLC_DigOut_9 := 0;
			PLC_DigOut_10 := 1;
		elsif counter = 11 then
			PLC_DigOut_10 := 0;
			PLC_DigOut_11 := 1;
		elsif counter = 12  then
			PLC_DigOut_11 := 0;
			PLC_DigOut_12 := 1;
		end_if;

		counter := counter + 1;

		if counter > 13  then
			counter := 0;
		end_if;
	end_if;

values[0]:=1;
fb_HW119_PLCwriteVar_Inst(VARIABLE := 'Modbus_1', VALUES := values, Nregs := 1);
IF FALSE THEN
	ch1_CAN1_OUT_DIG_8_1:=0;
END_IF;
TIMER1(in:=TRUE,PT:=T#1s);
IF TIMER1.Q THEN
	TIMER1(in:=FALSE,PT:=T#1s);
	IF ch1_CAN1_OUT_DIG_8_1 = 16#01 THEN
		ch1_CAN1_OUT_DIG_8_1:=16#01;
	ELSE
		ch1_CAN1_OUT_DIG_8_1:=16#00;
	END_IF;
END_IF;
end_if;
PLC_CAN1_IN_AN_1:=ch1_CAN1_IN_AN_1;
PLC_CAN1_IN_AN_2:=ch1_CAN1_IN_AN_2;
PLC_CAN1_IN_AN_3:=ch1_CAN1_IN_AN_3;
PLC_CAN1_IN_AN_4:=ch1_CAN1_IN_AN_4;
PLC_CAN1_IN_AN_5:=ch1_CAN1_IN_AN_5;
PLC_CAN1_IN_AN_6:=ch1_CAN1_IN_AN_6;
PLC_CAN1_IN_AN_7:=ch1_CAN1_IN_AN_7;
PLC_CAN1_IN_AN_8:=ch1_CAN1_IN_AN_8;
PLC_CAN1_IN_AN_9:=ch1_CAN1_IN_AN_9;
PLC_CAN1_IN_AN_10:=ch1_CAN1_IN_AN_10;
PLC_CAN1_IN_AN_11:=ch1_CAN1_IN_AN_11;
PLC_CAN1_IN_AN_12:=ch1_CAN1_IN_AN_12;
PLC_CAN1_IN_AN_13:=ch1_CAN1_IN_AN_13;
PLC_CAN1_IN_AN_14:=ch1_CAN1_IN_AN_14;
PLC_CAN1_IN_AN_15:=ch1_CAN1_IN_AN_15;
PLC_CAN1_IN_AN_16:=ch1_CAN1_IN_AN_16;
if  PLC_AnOutConf_1 <> UINT_TO_WORD(RET_AnOutConf_1)then
	PLC_AnOut_1 := 0;
	PLC_AnOutConf_1 := UINT_TO_WORD(RET_AnOutConf_1);
end_if;
if  PLC_AnOutConf_2 <> UINT_TO_WORD(RET_AnOutConf_2)then
	PLC_AnOut_2 := 0;
	PLC_AnOutConf_2 := UINT_TO_WORD(RET_AnOutConf_2);
end_if;

PLC_AnInConf_1 := UINT_TO_WORD(RET_AnInConf_1);
PLC_AnInConf_2 := UINT_TO_WORD(RET_AnInConf_2);
PLC_AnInConf_3 := UINT_TO_WORD(RET_AnInConf_3);
PLC_AnInConf_4 := UINT_TO_WORD(RET_AnInConf_4);

(* limits the overflow value *)
IF (INT_TO_WORD(TP1006_LIO_AnOut_Conf) AND 16#01) = 16#01 THEN
	IF PLC_AnOut_1 > 2000 then
		PLC_AnOut_1:=2000;
	END_IF;
	IF PLC_AnOut_1 < 0 then
		PLC_AnOut_1:=0;
	END_IF;
END_IF;
IF (INT_TO_WORD(TP1006_LIO_AnOut_Conf) AND 16#02) = 16#02 THEN
	IF PLC_AnOut_1 > 1000 then
		PLC_AnOut_1:=1000;
	END_IF;
	IF PLC_AnOut_1 < 0 then
		PLC_AnOut_1:=0;
	END_IF;
END_IF;
IF (INT_TO_WORD(TP1006_LIO_AnOut_Conf) AND 16#10)  = 16#10 THEN
	IF PLC_AnOut_2 > 2000 then
		PLC_AnOut_2:=2000;
	END_IF;
	IF PLC_AnOut_2 < 0 then
		PLC_AnOut_2:=0;
	END_IF;
END_IF;
IF (INT_TO_WORD(TP1006_LIO_AnOut_Conf) AND 16#20)  = 16#20 THEN
	IF PLC_AnOut_2 > 1000 then
		PLC_AnOut_2:=1000;
	END_IF;
	IF PLC_AnOut_2 < 0 then
		PLC_AnOut_2:=0;
	END_IF;
END_IF;
END_PROGRAM
