(*[[
]]*)
FUNCTION_BLOCK fb_HW119_ReadVarFields
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	Index:INT;
END_VAR
VAR_OUTPUT
	ERR:BOOL;
END_VAR

VAR
	Field:STRING;
	FunctRes:UINT;
END_VAR

	ERR:=FALSE;
	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].Enable:=STRING_TO_INT(Field);
		HW119_ERR[3]:=2;
	ELSE
		HW119_ERR[3]:=3;
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		IF Field = 'P'	THEN
			CrossTable[index].Plc:=TRUE;
		ELSIF Field = 'H'	THEN
			CrossTable[index].Plc:=FALSE;
		END_IF;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].Tag:=Field;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		IF Field = 'UINT'	THEN
			CrossTable[index].Types:=UINT16;
		ELSIF Field = 'INT'	THEN
			CrossTable[index].Types:=INT16;
		ELSIF Field = 'UDINT'	THEN
			CrossTable[index].Types:=UDINT32;
		ELSIF Field = 'DINT'	THEN
			CrossTable[index].Types:=DINT32;
		ELSIF Field = 'FDCBA'	THEN
			CrossTable[index].Types:=FLOATDCBA;
		ELSIF Field = 'FCDAB'	THEN
			CrossTable[index].Types:=FLOATCDAB;
		ELSIF Field = 'FABCD'	THEN
			CrossTable[index].Types:=FLOATABCD;
		ELSIF Field = 'FBADC'	THEN
			CrossTable[index].Types:=FLOATBADC;
		ELSIF Field = 'BIT'	THEN
			CrossTable[index].Types:=BIT;
		ELSIF Field = 'UDINTDCBA'	THEN
			CrossTable[index].Types:=UDINTDCBA;
		ELSIF Field = 'UDINTCDAB'	THEN
			CrossTable[index].Types:=UDINTCDAB;
		ELSIF Field = 'UDINTABCD'	THEN
			CrossTable[index].Types:=UDINTABCD;
		ELSIF Field = 'UDINTBADC'	THEN
			CrossTable[index].Types:=UDINTBADC;
		ELSIF Field = 'DINTDCBA'	THEN
			CrossTable[index].Types:=DINTDCBA;
		ELSIF Field = 'DINTCDAB'	THEN
			CrossTable[index].Types:=DINTCDAB;
		ELSIF Field = 'DINTABCD'	THEN
			CrossTable[index].Types:=DINTABCD;
		ELSIF Field = 'DINTBADC'	THEN
			CrossTable[index].Types:=DINTBADC;
		ELSE
			IF CrossTable[index].Enable > 0 THEN
				CrossTable[index].Types:=100;		(* TIPO NON RICONOSCIUTO*)
				ERROR_FLAG:=ERROR_FLAG OR 16#20;(* SEGNALO L'ERRORE SUL BIT 5*)
			END_IF;
		END_IF;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].Decimal:=STRING_TO_UINT(Field);
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		IF Field = 'RTU' 	THEN
			CrossTable[index].Protocol:=0;
			RTUProtocol_ON:=TRUE;
		ELSIF Field = 'TCP' 	THEN
			CrossTable[index].Protocol:=1;
			TCPProtocol_ON:=TRUE;
		ELSIF Field = 'TCPRTU' 	THEN
			CrossTable[index].Protocol:=2;
			TCPRTUProtocol_ON:=TRUE;
		ELSE
			CrossTable[index].Protocol:=100;		(* PROTOCOLLO NON RICONOSCIUTO*)
		END_IF;

	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].IPAddress:=Field;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].Port:=STRING_TO_UINT(Field);
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		IF CrossTable[index].Protocol = TCP THEN
			CrossTable[index].NodeId:=1;
		ELSE
			CrossTable[index].NodeId:=STRING_TO_BYTE(Field);
		END_IF;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].Address:=STRING_TO_UINT(Field);
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].Block:=STRING_TO_UINT(Field);
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		CrossTable[index].Nreg:=STRING_TO_INT(Field);
	ELSE
		ERR:=TRUE;
	END_IF;
(*
		FunctRes:=HW119_GetCrossTableField(Field);		
		IF FunctRes = 0 THEN
			CrossTable[index].Handle:=STRING_TO_UINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
*)
		

END_FUNCTION_BLOCK
