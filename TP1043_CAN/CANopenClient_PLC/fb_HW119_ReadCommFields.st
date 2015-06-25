(*[[
]]*)
FUNCTION_BLOCK fb_HW119_ReadCommFields
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	index:INT;
END_VAR
VAR_OUTPUT
	ERR:BOOL;
END_VAR

VAR
	Field:STRING;
	FunctRes:UINT;
END_VAR

	ERR:=FALSE;
	IF  index = 1 THEN
		FunctRes:=HW119_GetCrossTableField(Field);					(* Number of fails	*)
		IF FunctRes = 0 THEN
			NumberOfFails:=STRING_TO_INT(Field);;
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);
		IF FunctRes = 0 THEN										(* Fail  divisor	*)
			FailDivisor:=STRING_TO_BYTE(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	ELSIF index = 2 THEN

		FunctRes:=HW119_GetCrossTableField(Field);					(* Talta 	*)
		IF FunctRes = 0 THEN
			Talta:=STRING_TO_DINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);
		IF FunctRes = 0 THEN										(* Tmedia	*)
			Tmedia:=STRING_TO_DINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;

		FunctRes:=HW119_GetCrossTableField(Field);
		IF FunctRes = 0 THEN										(* Tbassa	*)
			Tbassa:=STRING_TO_DINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;

	ELSE

		FunctRes:=HW119_GetCrossTableField(Field);					(* Device	*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].Device:=Field;
		ELSE
			ERR:=TRUE;
		END_IF;

		FunctRes:=HW119_GetCrossTableField(Field);					(* Indirizzo IP	*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].IPaddr:=Field;
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);
		IF FunctRes = 0 THEN									(* Port	*)
			CommParameters[index-2].Port:=STRING_TO_UINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);					(* Baudrate	*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].BaudRate:=STRING_TO_UINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);					(* Parità	*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].Parity:=Field;
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);					(* DataBit*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].DataBit:=STRING_TO_UINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);					(* StopBit	*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].StopBit:=STRING_TO_UINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	
	
		FunctRes:=HW119_GetCrossTableField(Field);					(* Tmin	*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].Tmin:=STRING_TO_INT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	
		FunctRes:=HW119_GetCrossTableField(Field);					(* Timeout	*)
		IF FunctRes = 0 THEN
			CommParameters[index-2].TimeOut:=STRING_TO_UINT(Field);
		ELSE
			ERR:=TRUE;
		END_IF;
	END_IF;	

END_FUNCTION_BLOCK
