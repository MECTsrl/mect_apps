(*[[
]]*)
PROGRAM RTU_Communication 
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR
	HeadAddr:INT;
	ReadWrite:WORD;
	IndexProt_i:ARRAY [0..4] OF INT;
	TON_0:TON;	
	TON_1:TON;	
	TON_2:TON;	
	TON_3:TON;	
	BusAccess:fb_HW119_MODBUS;
	FirstCy:BOOL;
	dummy:WORD;
	Enablei: ARRAY [0..3] OF BOOL;
	pointer:INT;
	FlagPrimoCiclo:BOOL;
	Retry:BOOL:=FALSE;
	Protocollo:UINT:=RTU;
	timeCount:ARRAY [0..4] OF UDINT;
	zeroCount:ARRAY [0..4] OF UDINT;
	deltaT: ARRAY [0..4] OF DINT;
	RicettaON:BOOL;
	LastID:INT;
	FirstID:INT;
	I:INT;
	Start:ARRAY [0..4] OF BOOL;
	k:dword;
	j:dword;
	plcCylce:UDINT:=10;
	TIC:UDINT:=0;
	TAC:UDINT:=0;
	tailPoint:INT;
END_VAR
IF NOT FirstCy THEN
	dummy:=	WD_Disable('Task2_RTU');
	timeCount[0]:=0;
	timeCount[1]:=0;
	timeCount[2]:=0;
	deltaT[0]:=0;
	deltaT[1]:=0;
	deltaT[2]:=0;
	FirstCy:=TRUE;
END_IF;
TAC:=TAC+1;
TON_0(IN := TRUE,PT := INT_TO_TIME(CommParameters[Protocollo+1].Tmin));
(*				TON_1(IN := TRUE,PT := DINT_TO_TIME(Talta+deltaT[0]));	
				TON_2(IN := TRUE,PT := DINT_TO_TIME(Tmedia+deltaT[1]));
				TON_3(IN := TRUE,PT := DINT_TO_TIME(Tbassa+deltaT[2]));
*)
				TON_1(IN := TRUE,PT := DINT_TO_TIME(Talta));	
				TON_2(IN := TRUE,PT := DINT_TO_TIME(Tmedia));
				TON_3(IN := TRUE,PT := DINT_TO_TIME(Tbassa));

	
IF 	TON_0.Q THEN																(* controlla se TIMER Tmin scaduto	*)
	TRIGGER02:=1;
	TRIGGER01:=1;
	TIC:=TIC+1;
	TON_0(In:=FALSE);	

	IF Reset_RTU =1 THEN
		FOR I:=1 TO 64 DO
			CounterRTU[I]:=0;
		 END_FOR;
		RTUBlackList_ERROR_WORD:=0;
		RTUComm_ERROR_WORD:=0;
		BlackListRTUL:=0;
		BlackListRTUH:=0;
		CommErrRTUL:=0;
		CommErrRTUH:=0;
		ERROR_FLAG:=ERROR_FLAG AND 16#FFFE;
	END_IF;
	IF NOT Retry THEN
		IF RTURequestPLCWrite > 0 (*AND
			(MOD(TIC ,3)=0  OR (mod(tic,3)=1 and RichiestaScrittura=0))*) THEN											(* controlla seci sono richieste di scrittura da parte del PLC	*)

			pointer:=4;
			FlagPrimoCiclo:=FALSE;
			IndexProt_i[pointer]:=0;
			HeadAddr:=WORD_TO_INT(LocalRTUQueue[IndexRTUQueueGet]);		(*inizializza i parametri da assegnare al blocco funzione*)
			IF CrossTable[HeadAddr].Counter=1 THEN
				ReadWrite:=WRITE_SINGLE;											(*inizializza i parametri da assegnare al blocco funzione*)
			ELSE
				ReadWrite:=WRITE_MULTIPLE;											(*inizializza i parametri da assegnare al blocco funzione*)
			END_IF;

			RTURequestPLCWrite:=RTURequestPLCWrite-1;							(* incrementa il contatore delle scritture effettuate*)
			IndexRTUQueueGet:=IndexRTUQueueGet+1;								(* incrementa il puntatore alla coda *)
			IF IndexRTUQueueGet > MaxLocalQueue THEN
				IndexRTUQueueGet:=0;
			END_IF;
		ELSE
			IF  (RichiestaScrittura=1 (*AND MOD(TIC ,7)< 6*)) THEN										(* controlla se ci sono richieste di SCRITTURA da parte HMI*)	

				IF FlagPrimoCiclo = FALSE THEN									(* controlla se è il primo ingrsso nel ramo a seguito dell'interrupt*) 
					FlagPrimoCiclo:=TRUE;										(* Prima richiesta di scrittura => azzero l'indice della coda 	*)
					IndexProt_i[3]:=0;											(* per eseguire le scritture nella sequenza di arrivo		  	*)
					pointer:=3;				
				END_IF;
				REPEAT 															(* Rileva la succssiva variabile a cui accedere nella coda			*)
					IF IndexProt_i[3] < DINT_TO_INT(DimCrossTable) THEN
						IndexProt_i[3]:=IndexProt_i[3]+1;
						ReadWrite:=ARRAY_QUEUE[IndexProt_i[3]] AND QueueRWMask;	
						HeadAddr:=WORD_TO_INT(ARRAY_QUEUE[IndexProt_i[3]] AND QueueAddressMask);	
						IF HeadAddr < DINT_TO_INT(DimCrossTable) 	THEN		
							IF  (ReadWrite = 0  ) OR ( (CrossTable[HeadAddr].Protocol = Protocollo) AND ReadWrite>=WRITE AND (ARRAY_QUEUE_OUTPUT[IndexProt_i[3]]<>STATO_BUSY_WRITE) )   THEN
					
								IF ReadWrite = 0 THEN	
									ARRAY_QUEUE_OUTPUT[IndexProt_i[3]]:=0;
									IF HeadAddr = 0 THEN
										IndexProt_i[3]:=0;
									END_IF;

								ELSIF ReadWrite = WRITE_RIC_SINGLE  OR ReadWrite = WRITE_RIC_MULTIPLE  THEN	
									IF NOT RicettaON THEN
										FirstID:=IndexProt_i[3];
										RicettaON:=TRUE;
									END_IF;

									LastID:=IndexProt_i[3];
								END_IF;
								IF ReadWrite>=WRITE THEN
									timeCount[4]:=TIC -zeroCount[4];
									zeroCount[4]:=TIC;
									tailPoint:=IndexProt_i[3];
								END_IF;

								EXIT;
							ELSIF ReadWrite = 0 and HeadAddr>0 THEN
								ARRAY_QUEUE_OUTPUT[IndexProt_i[3]]:=0;
							END_IF;
						END_IF;
					ELSE
						IndexProt_i[3]:=0;
					END_IF;	
				UNTIL  FALSE	 
				END_REPEAT;
			ELSIF RicettaON AND RichiestaScrittura=0 THEN
				RicettaON:=FALSE;
				FlagPrimoCiclo:=FALSE;	
				FOR I:=1 TO  LastID DO
 					ARRAY_QUEUE_OUTPUT[I]:=0;
				END_FOR;
			ELSE																			(* richieste di LETTURE	*)
				IF  RichiestaScrittura=0	THEN
					FlagPrimoCiclo:=FALSE;										(* azzera l'akwnoledge dell'interrupt*)
					IF tailPoint> 0 THEN
						FOR I:=tailPoint TO 0 by -1 do
							ARRAY_QUEUE_OUTPUT[tailPoint]:=0;
							IF (ARRAY_QUEUE[tailPoint] AND QueueRWMask) > 0 THEN
								EXIT;
							END_IF;
						END_FOR;
					 	tailPoint:=0;
					END_IF;
					
				END_IF;
			END_IF;
			IF  RichiestaScrittura=0 (*or   (RichiestaScrittura=1 and ReadWrite=0) *) then
				IF TON_1.Q OR Enablei[0]=TRUE THEN							(* scaduto il timer ad alta priorità esegue le letture *)
					IF Enablei[0]=FALSE THEN
						TON_1(IN := FALSE);									(* riarma il timer*)
						Start[0]:=TRUE;
						zeroCount[0]:=TAC;	
						deltaT[0]:=UDINT_TO_DINT(timeCount[0]*plcCylce)-Talta;
						IF deltaT[0] <= 0 THEN
							deltaT[0]:=0;
						ELSE
							deltaT[0]:=REAL_TO_DINT(DINT_TO_REAL(deltaT[0])*1.2);
						END_IF;
					END_IF;
					pointer:=0;
					Enablei[0]:=TRUE;
				ELSIF TON_2.Q OR Enablei[1]=TRUE THEN						(* scaduto il timer ad media priorità esegue le letture *)
					IF Enablei[1]=FALSE THEN
						TON_2(IN := FALSE);									(* riarma il timer*)
						Start[1]:=TRUE;
						zeroCount[1]:=TAC;
						deltaT[1]:=UDINT_TO_DINT(timeCount[1]*plcCylce)-Tmedia;
						IF deltaT[1] < 0 THEN
							deltaT[1]:=0;
						ELSE
							deltaT[1]:=REAL_TO_DINT(DINT_TO_REAL(deltaT[1])*1.2);
						END_IF;
					END_IF;
					TON_2(IN := FALSE);										(* riarma il timer*)
					pointer:=1;
					Enablei[1]:=TRUE;
				ELSIF TON_3.Q OR Enablei[2]=TRUE THEN						(* scaduto il timer ad media priorità esegue le letture *)
					IF Enablei[2]=FALSE THEN
						TON_3(IN := FALSE);										(* riarma il timer*)
						Start[2]:=TRUE;
						zeroCount[2]:=TAC;
						deltaT[2]:=UDINT_TO_DINT(timeCount[2]*plcCylce)-Tbassa;
						IF deltaT[2] < 0 THEN
							deltaT[2]:=0;
						ELSE
							deltaT[2]:=REAL_TO_DINT(DINT_TO_REAL(deltaT[2])*1.2);
						END_IF;
					END_IF;
					pointer:=2;
					Enablei[2]:=TRUE;
				END_IF;
				IF Enablei[0] OR Enablei[1] OR Enablei[2] THEN
					REPEAT 															(* Rileva la prima variabile da leggere della cross table*)
						IF IndexProt_i[pointer] < DINT_TO_INT(DimCrossTable) THEN
							IndexProt_i[pointer]:=IndexProt_i[pointer]+1;
							ReadWrite:=ARRAY_QUEUE[IndexProt_i[pointer]] AND QueueRWMask;
							HeadAddr:=WORD_TO_INT(ARRAY_QUEUE[IndexProt_i[pointer]] AND QueueAddressMask);	
							IF HeadAddr < DINT_TO_INT(DimCrossTable) 	THEN
								IF ((ReadWrite = 0) OR (CrossTable[HeadAddr].Protocol = Protocollo) AND (CrossTable[HeadAddr].Enable = pointer+1) )    THEN
									IF ReadWrite = 0 THEN
										Enablei[pointer]:=FALSE;
										timeCount[pointer]:=TAC-zeroCount[pointer];
										ARRAY_QUEUE_OUTPUT[IndexProt_i[pointer]]:=0;
										IF HeadAddr = 0 THEN
											IndexProt_i[pointer]:=0;
										END_IF;
									END_IF;
									EXIT;
								END_IF;
							END_IF;
						ELSE
							IndexProt_i[pointer]:=0;
						END_IF;	
					UNTIL  FALSE	 
					END_REPEAT;
				ELSE
					ReadWrite:=0;
				END_IF;

			END_IF;	
		END_IF;	
	END_IF;
	IF ReadWrite > 0 THEN
		IF Crosstable[HeadAddr].NodeId > 0 AND Crosstable[HeadAddr].NodeId < 64 THEN

			IF RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed < 2  THEN			(* controlla se il device non è in blacklist*)
				BusAccess(Protocol:='RTU',Index:=IndexProt_i[pointer],address:=HeadAddr,RdWr:=ReadWrite);		(* effettua l'accesso al bus*)
				TON_0(IN := TRUE,PT := INT_TO_TIME(CommParameters[Protocollo+1].Tmin));						(* riarmo di Tmin*)
				IF BusAccess.Error > 0  THEN																(* controlla sec'è stato un errore di comuicazione*)
					ERROR_FLAG:=ERROR_FLAG OR 16#1;
					CounterRTU[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)]:=UDINT_TO_WORD(WORD_TO_UDINT(CounterRTU[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)])+1);
					IF BusAccess.Error = CommError THEN
						RTUComm_ERROR_WORD:=1;					
						IF BYTE_TO_INT(Crosstable[HeadAddr].NodeId) > 32 THEN
							CommErrRTUH:=CommErrRTUH OR SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
						ELSE
							CommErrRTUL:=CommErrRTUL OR SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
						END_IF;
						Retry:=FALSE;
					ELSIF BusAccess.Error = TimeoutError  THEN		(* controlla se c'è stato un erore di timeout*)
						Retry:=TRUE;							(* imposta il flag retry a TRUE in modo da effettuare le ripetizioni *)
						RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter:=RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter+1;
						IF RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter >= NumberOfFails THEN
							RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed:=RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed+1;
							RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead:=BYTE_TO_INT(FailDivisor);
							Retry:=FALSE;
							IF RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed > 1 THEN
								RTUBlackList_ERROR_WORD:=1;

								IF BYTE_TO_INT(Crosstable[HeadAddr].NodeId) > 32 THEN
									BlackListRTUH:=BlackListRTUH OR SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
								ELSE
									k:=SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
									BlackListRTUL:=BlackListRTUL OR k;
								END_IF;
							END_IF;
						END_IF;
					END_IF;
				ELSE

					Retry:=FALSE;
					IF BYTE_TO_INT(Crosstable[HeadAddr].NodeId) > 32 THEN
						CommErrRTUH:=CommErrRTUH AND ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
						BlackListRTUH:=BlackListRTUH AND ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
					ELSE
						CommErrRTUL:=CommErrRTUL AND ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
						k:=ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
						j:=BlackListRTUL;
						j:=j AND k;
						BlackListRTUL:=j;
					END_IF;
					IF CommErrRTUH =0 AND CommErrRTUl = 0 THEN
						RTUComm_ERROR_WORD:=0;	
					END_IF;
					IF BlackListRTUH =0 AND BlackListRTUL = 0 THEN
						RTUBlackList_ERROR_WORD:=0;	
					END_IF;

					RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed:=0;
					RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter:=0;
				END_IF;
			ELSE
				RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead:=RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead-1;
				IF RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead <= 0 THEN
					RTUListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed:=1;
					Retry:=TRUE;
				END_IF;
			END_IF;	
		END_IF;
	END_IF;
END_IF;	
END_PROGRAM
