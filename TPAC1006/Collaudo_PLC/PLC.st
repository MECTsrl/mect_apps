(*[[
]]*)
PROGRAM PLC 
#import "Resource1.gvl"
#import "crosstable.gvl"
#import "TPACLocaIO.gvl" (* <---= *)
#import "Collaudo_CAN.gvl"
#import "LIO_TPAC1006.gvl"
VAR
	fb_HW119_PLCwriteVar_Inst : fb_HW119_PLCwriteVar;
	counter : UDINT := 0;
	divisor : UDINT := 10;
	values : ARRAY [0..15] OF DWORD;
	TIMER1:TON;
	TIMER2:TON;
END_VAR;
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

END_PROGRAM
