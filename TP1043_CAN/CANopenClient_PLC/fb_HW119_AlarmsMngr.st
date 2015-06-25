(*[[
]]*)
FUNCTION_BLOCK fb_HW119_AlarmsMngr
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
END_VAR
VAR
	Index:DINT;			(* indice di scansione della CT degli allarmi	*)
	SourceAddr:INT;		(* indirizzo della variabile sorgente	*)
	CompareAdddr:INT;	(* indirizzo della variabile di confronto	*)
	CompareVal:DWORD;	(* valore di confronto	*)
	TagAddr:INT;		(* indirizzo della variabile di allarme	*)
	ERRFlag:BOOL;		(* flag d segnalazione errore nell'esecuzioe di una funzione	*)
	ERRORVAL:DWORD:=16#00000001;	(* *)
	tmp:DWORD;			(* variabile di appoggio	*)
	tmpOld:DWORD;		(* variabile di appoggio	*)
END_VAR
(*
	Blocco funzione per la gestione degli alalrmi/eventi



*)

	IF Index < DimAlarmsCT AND ALCrossTable[Index].ALTag <> '' THEN
		SourceAddr:=WORD_TO_INT(HW119_GetAddr(ALCrossTable[Index].ALSource));		(* ricava l'indirizzo della varibile sorgente*)		
		IF SourceAddr = WORD_TO_INT(16#FFFF)  OR SourceAddr > DINT_TO_INT(DimCrossTable) OR SourceAddr = 0  THEN									(* controlla il risultato della funzione*)
			ERRFlag:=TRUE;			
		ELSE
			IF	CrossTable[SourceAddr].Error > 0 AND CrossTable[SourceAddr].Protocol<>100 THEN			(* verifica che il valore sia stato aggiornato	*)
				ERRFlag:=TRUE;			
			ELSE
				CompareAdddr:=-1;
				IF ALCrossTable[Index].ALCompareVar = '' THEN						
					CompareVal:=ALCrossTable[Index].ALCompareVaL;					(* variabile di confronto nulla -> rileva il valore di confronto*)
				ELSE
					CompareAdddr:=WORD_TO_INT(HW119_GetAddr(ALCrossTable[Index].ALCompareVar));	(* ricava l'indirizzo della varibile di confronto *)

					IF CompareAdddr = WORD_TO_INT(16#FFFF) OR CompareAdddr > DINT_TO_INT(DimCrossTable) OR CompareAdddr = 0 THEN					(* controlla se la variable di controllo corretta*)
						ERRFlag:=TRUE;
					ELSE
						IF CrossTable[CompareAdddr].Error > 0 AND CrossTable[CompareAdddr].Protocol<>100 THEN	(* verifica  se la variabile di controllo è nella CT*)
							ERRFlag:=TRUE;			
						ELSE
							CompareVal:=ARRAY_CROSSTABLE_INPUT[CompareAdddr];		
						END_IF;
					END_IF;
				END_IF;
				TagAddr:=WORD_TO_INT(HW119_GetAddr(ALCrossTable[Index].ALTag));		(* ricavo l'indirizzo della varibile destinazione*)
				IF TagAddr = WORD_TO_INT(16#FFFF) OR TagAddr > DINT_TO_INT(DimCrossTable) OR TagAddr = 0 THEN  
					ERRFlag:=TRUE;			
				END_IF;
			END_IF;
		END_IF;

		IF NOT ERRFlag	THEN						(* Se i valori letti da CT sono corenti effettua il check di allarme	*)
			tmp:=UINT_TO_DWORD(ALCrossTable[Index].ALOperator)	AND 16#FF00	;	(* controlla l'operazione da eseguire *)
			CASE DWORD_TO_INT(tmp) OF
(*  operatore >	*)		16#100 :	
							IF ARRAY_CROSSTABLE_INPUT[SourceAddr] > CompareVal	 THEN
								IF  ALCrossTable[Index].ALFilterCount=0  THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;	
								ELSE
									ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterCount-1;
								END_IF;
							ELSE
								ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;
								ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterTime;
							END_IF;
(*  operatore >=	*)	16#200 :
							IF ARRAY_CROSSTABLE_INPUT[SourceAddr] >= CompareVal	 THEN
								IF  ALCrossTable[Index].ALFilterCount=0  THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;	
								ELSE
									ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterCount-1;
								END_IF;
							ELSE
								ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;
								
							END_IF;
(*  operatore <	*)		16#300 :
							IF ARRAY_CROSSTABLE_INPUT[SourceAddr] < CompareVal	 THEN
								IF  ALCrossTable[Index].ALFilterCount=0  THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;	
								
								ELSE
									ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterCount-1;
								END_IF;
							ELSE
								ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;
								ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterTime;
							END_IF;
(*  operatore <=	*)	16#400 :
							IF ARRAY_CROSSTABLE_INPUT[SourceAddr] <= CompareVal	 THEN
								IF  ALCrossTable[Index].ALFilterCount=0  THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;	
								
								ELSE
									ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterCount-1;
								END_IF;
							ELSE
								ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;
								ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterTime;
							END_IF;
(*  operatore =	*)		16#500 :
							IF ARRAY_CROSSTABLE_INPUT[SourceAddr] = CompareVal	 THEN
								IF  ALCrossTable[Index].ALFilterCount=0  THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;	
								
								ELSE
									ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterCount-1;
								END_IF;
							ELSE
								ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;
								ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterTime;
							END_IF;
(*  operatore <>	*)	16#600 :
							IF ARRAY_CROSSTABLE_INPUT[SourceAddr] <> CompareVal	 THEN
								IF  ALCrossTable[Index].ALFilterCount=0  THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;	

								ELSE
									ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterCount-1;
								END_IF;
							ELSE
								ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;
								ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterTime;
							END_IF;

						ELSE
(*controllo a bit *)
							
							tmp:= SHR(ARRAY_CROSSTABLE_INPUT[SourceAddr], WORD_TO_INT ( UINT_TO_WORD ( ALCrossTable[Index].ALOperator) AND 16#00FF)-1 );
							tmp:=tmp AND 16#1;							
							(*controllo a bit sui livelli*)	

							IF CompareAdddr = -1 THEN		
								
								IF tmp = CompareVal	THEN
									IF  ALCrossTable[Index].ALFilterCount=0  THEN
										ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;	

									ELSE
										ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterCount-1;
									END_IF;	
								ELSE					
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;	
									ALCrossTable[Index].ALFilterCount:=ALCrossTable[Index].ALFilterTime;
								END_IF;
(* controllo  transizioni*)
							ELSIF CompareAdddr=SourceAddr 	THEN	
(* allarme su fronte di salita*)
								tmpOld:= SHR(CrossTable[SourceAddr].OldVal, WORD_TO_INT ( UINT_TO_WORD ( ALCrossTable[Index].ALOperator) AND 16#00FF)-1 );
								tmpOld:=tmpOld AND 16#1;													
								IF		tmp = 16#01 AND 	tmpOld=16#00 AND ALCrossTable[Index].ALCompareVal =  FRONTE_SALITA	THEN
								 	ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;
(* allarme su fronte di discesa*)
								ELSIF	tmp = 16#00  AND 	tmpOld=16#01 AND ALCrossTable[Index].ALCompareVal =  FRONTE_DISCESA	THEN
								 	ARRAY_CROSSTABLE_INPUT[TagAddr]:=ERRORVAL;
								ELSIF ALCrossTable[Index].ALCompareVal =  FRONTE_SALITA AND tmp=16#00 THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;									
								ELSIF ALCrossTable[Index].ALCompareVal =  FRONTE_DISCESA AND tmp= 16#01 THEN
									ARRAY_CROSSTABLE_INPUT[TagAddr]:=0;									
								END_IF;
								IF tmp = 0 THEN
									tmp:=16#FFFFFFFE;
									CrossTable[SourceAddr].OldVal:=CrossTable[SourceAddr].OldVal AND ROL(tmp, WORD_TO_INT ( UINT_TO_WORD ( ALCrossTable[Index].ALOperator) AND 16#00FF)-1 );
								ELSE
									CrossTable[SourceAddr].OldVal:=CrossTable[SourceAddr].OldVal OR ROL(tmp, WORD_TO_INT ( UINT_TO_WORD ( ALCrossTable[Index].ALOperator) AND 16#00FF)-1 );
								END_IF;
							END_IF;
								
			END_CASE;
		END_IF;
		Index:=Index+1;
		ERRFlag:=FALSE;
	ELSE
		Index:=1;
	END_IF;


END_FUNCTION_BLOCK
