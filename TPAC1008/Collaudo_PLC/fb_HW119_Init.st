(*[[
]]*)
FUNCTION_BLOCK fb_HW119_Init
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	TIPO:UINT;
END_VAR
VAR
	k:WORD;
	i:DINT;
END_VAR
IF TIPO = 0 	THEN
	FOR i:=0 TO DimCrossTable-1	DO

		TRIGGER01 := 0;
		CrossTable[i].Enable:=0;
		CrossTable[i].Plc:=FALSE;
		CrossTable[i].Tag:='';
		CrossTable[i].Types:=0;
		CrossTable[i].Decimal:=0;
		CrossTable[i].Protocol:=0;
		CrossTable[i].IPAddress:='';
		CrossTable[i].Port:=0;
		CrossTable[i].NodeId:=0;
		CrossTable[i].Address:=0;
		CrossTable[i].Block:=0;
		CrossTable[i].NReg:=0;
		CrossTable[i].Handle:=0;	
		CrossTable[i].OldVal:=0;
		CrossTable[i].Error:=1;
		K:=ARRAY_QUEUE[i+1];
		ARRAY_QUEUE_OUTPUT[i+1]:=0;
		ARRAY_STATES[i+1]:=0;		



	END_FOR;
	CrossTableState:=TRUE;
	CommEnabled:=FALSE;
	RTUProtocol_ON:=FALSE;
	TCPProtocol_ON:=FALSE;
	TCPRTUProtocol_ON:=FALSE;

ELSIF  TIPO = 1 	THEN
	FOR i:=0 TO 159	DO

		ALCrossTable[i].ALType:=FALSE;
		ALCrossTable[i].ALTag:='';
		ALCrossTable[i].ALSource:='';
		ALCrossTable[i].ALCompareVar:='';
		ALCrossTable[i].ALCompareVal:=0;
		ALCrossTable[i].ALOperator:=0;
		ALCrossTable[i].ALFilterTime:=0;
	END_FOR;
	ALCrossTableState:=TRUE;
 END_IF;
END_FUNCTION_BLOCK
