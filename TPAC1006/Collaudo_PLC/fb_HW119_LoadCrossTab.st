(*[[
]]*)
FUNCTION_BLOCK fb_HW119_LoadCrossTab
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	ENABLE:BOOL;		(* Abilitazione funzione*)
	CTFile:STRING;		(* file di cross table da aprire	*)
	CTDimension:DINT;	(* dimensione della cross table da leggere	*)
	CTType:UINT;		(* tipo di cross table da leggere	*)
END_VAR
VAR_OUTPUT
	END:BOOL;			(* Fine funzione	*)
	ERR:BOOL;			(* segnalazione errore	*)
END_VAR
VAR
		InitXtable: fb_HW119_Init;
		ReadFields:fb_HW119_ReadVarFields;
		ReadAlarmsFields:fb_HW119_ReadAlarmsFields;
		ReadCommFields:fb_HW119_ReadCommFields;
		FBState: UINT;
		FunctRes:UINT;
		index: DINT;
		STEPS:DINT:=50;
		LowEdge:DINT:=0;
		HiEdge:DINT:=0;
END_VAR
IF ENABLE THEN
	IF FBState = 0 THEN
		InitXtable(TIPO:=CTType);													(* Inizializzazione delle variabili CT*)
		FBState:=10;
		ErrorsState:=ErrorsState AND 16#F0;											(* reset flag di errore*)
		LowEdge:=1;																	
		HiEdge:=STEPS;
		IF HiEdge > CTDimension THEN							
			HiEdge:=CTDimension;
		END_IF;
	ELSIF FBState =10	THEN												(* OPEN CROSS TABLE*)
		FunctRes:=HW119_OpenCrossTable(CTFile);
		IF FunctRes = 0 THEN												(* Operazione andata a buon fine	*)
			FBState:=20;
			HW119_ERR[2]:=2;
		ELSE
			FBState:=1000;													(* Errore -> termina	*)
			ErrorsState:=ErrorsState OR 16#01;
			HW119_ERR[2]:=3;
		END_IF;

	ELSIF FBState =20	THEN												(* LOAD CROSS TABLE RECORDS*)
		FOR index:=LowEdge TO HiEdge	DO									(* lettura di STEPS record di CT	*)
			IF CTType > 0 	THEN											(* Se CT non è quella delle variabili non si aggiunge alla Hash*)
		 		FunctRes:=HW119_ReadCrossTableRecord(TRUE);					(* LEGGE RECORD DELLA CROSSTABLE*)
			ELSE
				FunctRes:=HW119_ReadCrossTableRecord(FALSE);				(* LEGGE RECORD DELLA CROSSTABLE lo aggiunge alla HAsh*)
			END_IF;

			IF FunctRes = 0 THEN
				HW119_ERR[1]:=2;
				CASE CTType OF
					0:		ReadFields(Index:=DINT_TO_INT(index));			(* lettura crosstable variabili	*)	
							IF ReadFields.ERR THEN				
								CrossTable[index].Error:=100;				(* marca la entry della crosstable come errata*)
								ErrorsState:=ErrorsState OR 16#04;
							END_IF;
					1:		ReadAlarmsFields(Index:=DINT_TO_INT(index));	(* lettura crosstable Allarmi	*)
							IF ReadAlarmsFields.ERR 	 THEN
								ALCrossTable[index].ALError:=100;			(* marca la entry della crosstable ALLARMI come errata*)
								ErrorsState:=ErrorsState OR 16#04;
							END_IF;
					ELSE
					ReadCommFields(Index:=DINT_TO_INT(index));				(* lettura CT dei parametri di comunicazione	*)
					IF index > 1 	THEN
						IF ReadCommFields.ERR 	THEN
							CommParameters[index-1].State:=FALSE;
						ELSE
							CommParameters[index-1].State:=TRUE;
						END_IF;
					 END_IF;
				END_CASE;
			ELSE
				HW119_ERR[1]:=3;
				IF CTType = 0	 THEN
					CrossTable[index].Error:=100;						(* marca la entry della crosstable come non ancora aggiornata*)
					ErrorsState:=ErrorsState OR 16#02;
				ELSIF CTType = 1	 THEN
					ALCrossTable[index].ALError:=100;					(* marca la entry della crosstable ALLARMI come non ancora aggiornata*)
					ErrorsState:=ErrorsState OR 16#04;
				END_IF;
			END_IF;

		END_FOR;
		FBState:=30;

	ELSIF FBState = 30	THEN									
		LowEdge:=HiEdge+1;												
		HiEdge:=HiEdge+STEPS;
		IF LowEdge < CTDimension	THEN								(* controlla se è terminata la CT da legere	*)
			IF HiEdge<CTDimension THEN
				FBState:=20;
			ELSIF HiEdge>=CTDimension THEN			
				HiEdge:=CTDimension;
				FBState:=20;
			 END_IF;
		ELSE
			FBState:=40;
		END_IF;

	ELSIF FBState = 40	THEN
		FunctRes:=HW119_CloseCrossTable();											(* CLOSE CrossTable*)		
		IF FunctRes = 0 THEN
			HW119_ERR[0]:=2;				(*debug*)
		 	FBState:= 100;
		ELSE
			FBState:=1000;
			HW119_ERR[0]:=3;				(*debug*)
			ErrorsState:=ErrorsState OR 16#08;
		END_IF;
	ELSIF FBState = 100	THEN														(* TERMINATA LETTURA CROSSTABLE*)
		END:=TRUE;
	ELSIF FBState = 1000 THEN														(* TERMINATA LETTURA CROSSTABLE*)
		FunctRes:=HW119_CloseCrossTable();											(* CLOSE CrossTable*)
		FBState:= 1010;
		ERR:=TRUE;
	END_IF;
ELSE
	END:=FALSE;
	ERR:=FALSE;
	FBState:= 0;
END_IF;
END_FUNCTION_BLOCK
