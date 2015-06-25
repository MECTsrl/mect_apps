(*[[
]]*)
FUNCTION_BLOCK fb_HW119_PLCreadVar
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	ReadVar:STRING;			(*	Mnemonico della variabile da leggere	*)
END_VAR
VAR_OUTPUT
	ERR:BOOL;				(*	Segnala errore nell'esecuzione del blocco funzione	*)
	VarValue:DWORD;			(*	Valore letto	*)
END_VAR
VAR
	ReadingAddr:WORD;
	
END_VAR
(*
		Blocco funzione per la lettura di una variabile attraverso il PLC di controllo

*)

	ReadingAddr:=HW119_GetAddr(ReadVar);
	IF ReadingAddr =16#FFFF THEN
		ERR:=TRUE;
		HW119_ERR[4]:=3;
	ELSE
		VarValue:=ARRAY_CROSSTABLE_INPUT[WORD_TO_INT(ReadingAddr)];
		ARRAY_STATES[WORD_TO_INT(ReadingAddr)]=0;
		HW119_ERR[4]:=2;
	END_IF;
END_FUNCTION_BLOCK
