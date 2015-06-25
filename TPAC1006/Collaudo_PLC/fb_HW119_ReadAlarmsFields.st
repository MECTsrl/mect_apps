(*[[
]]*)
FUNCTION_BLOCK fb_HW119_ReadAlarmsFields
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
	FunctRes:=HW119_GetCrossTableField(Field);				(*Lettura TIPO 0 : evento, 1 : allarme*)
	IF FunctRes = 0 THEN
		ALCrossTable[index].ALType:=STRING_TO_BOOL(Field);
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);				(* variabile di allarme	*)
	IF FunctRes = 0 THEN
		ALCrossTable[index].ALTag:=Field;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);				(* Variabile di sorgente	*)
	IF FunctRes = 0 THEN
		ALCrossTable[index].ALSource:=Field;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);				(* variabile di confronto	*)
	IF FunctRes = 0 THEN
		ALCrossTable[index].ALCompareVar:=Field;
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);			
	IF FunctRes = 0 THEN
		ALCrossTable[index].ALCompareVal:=STRING_TO_DWORD(Field);
	ELSE
		ERR:=TRUE;
	END_IF;

	FunctRes:=HW119_GetCrossTableField(Field);			
	IF FunctRes = 0 THEN
		ALCrossTable[index].ALOperator:=STRING_TO_UINT(Field);
	ELSE
		ERR:=TRUE;
	END_IF;


	FunctRes:=HW119_GetCrossTableField(Field);		
	IF FunctRes = 0 THEN
		ALCrossTable[index].ALFilterTime:=STRING_TO_UINT(Field);
		ALCrossTable[Index].ALFilterCount:=ALCrossTable[index].ALFilterTime;
	ELSE
		ERR:=TRUE;
	END_IF;

END_FUNCTION_BLOCK
