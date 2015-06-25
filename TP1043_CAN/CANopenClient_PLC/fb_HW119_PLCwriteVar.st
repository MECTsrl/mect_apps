(*[[
]]*)
FUNCTION_BLOCK fb_HW119_PLCwriteVar
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	VARIABLE:STRING;		(* Mnemonico della variabile da scrivere	*)
	VALUES: ARRAY [0..15] OF DWORD;			(* valori da scrivere		*)
	Nregs:INT;
END_VAR
VAR_OUTPUT
	ERR:BOOL;				(* Segnala un errore nell'esecuzione del blocco funzione	*)			
END_VAR
VAR
	ADDRESS:WORD;
	I:INT;
	tempo1:TIME;
END_VAR
(*
	Blocco funzione per la scrittura di una variabile attraverso  il PLC di controllo

*)
	ERR:=FALSE;
	ADDRESS:=HW119_GetAddr(VARIABLE);
	tempo1:=TIM_Get();


		IF ADDRESS = 16#FFFF 	THEN
			ERR:=TRUE;
		ELSE
			FOR I:=0 TO NRegs-1 DO											(*  calcolo del numero di scritture modbus da effettuare*)
				CrossTable[WORD_TO_INT(ADDRESS)+I].PLCWriteVal:=VALUES[I];
			END_FOR;
			CASE 	CrossTable[WORD_TO_INT(ADDRESS)].Protocol OF
		
				0:	IF RTUProtocol_ON THEN
						LocalRTUQueue[IndexRTUQueuePut]:=ADDRESS;
						RTURequestPLCWrite:=RTURequestPLCWrite+1;
						IndexRTUQueuePut:=IndexRTUQueuePut+1;
						if IndexRTUQueuePut > MaxLocalQueue then
							IndexRTUQueuePut:=0;
						end_if;
						CrossTable[WORD_TO_INT(ADDRESS)].Counter:=Nregs;
					END_IF;
		
				1:	IF TCPProtocol_ON THEN
						LocalTCPQueue[IndexTCPQueuePut]:=ADDRESS;
						TCPRequestPLCWrite:=TCPRequestPLCWrite+1;
						IndexTCPQueuePut:=IndexTCPQueuePut+1;
						if IndexTCPQueuePut > MaxLocalQueue then
							IndexTCPQueuePut:=0;
						end_if;
						CrossTable[WORD_TO_INT(ADDRESS)].Counter:=Nregs;
					END_IF;
				2:	IF TCPRTUProtocol_ON 	THEN
						LocalTCPRTUQueue[IndexTCPRTUQueuePut]:=ADDRESS;
						TCPRTURequestPLCWrite:=TCPRTURequestPLCWrite+1;
						IndexTCPRTUQueuePut:=IndexTCPRTUQueuePut+1;
						if IndexTCPRTUQueuePut > MaxLocalQueue then
							IndexTCPRTUQueuePut:=0;
						end_if;
						CrossTable[WORD_TO_INT(ADDRESS)].Counter:=Nregs;
					END_IF;
				ELSE
					FOR I:=0 TO NRegs-1 DO											(* aggiorno l'array di input con le variabili da scrivere*)
						ARRAY_CROSSTABLE_INPUT[WORD_TO_INT(ADDRESS)+I]:=CrossTable[WORD_TO_INT(ADDRESS)+I].PLCWriteVal;
						CrossTable[WORD_TO_INT(ADDRESS)+I].Error:=0;
					END_FOR;
					TRIGGER01:=1;
			END_CASE;
		END_IF;


END_FUNCTION_BLOCK
