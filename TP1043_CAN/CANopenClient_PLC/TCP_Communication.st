(*[[
]]*)
PROGRAM TCP_Communication 
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
	Protocollo:UINT:=TCP;
	time2:TIME;
	zero:TIME;
	RicettaON:BOOL;
	LastID:INT;
	FirstID:INT;
	I:INT;
	Start:ARRAY [0..4] OF BOOL;
	k:dword;
	j:dword;
END_VAR

TON_0(IN := TRUE,PT := INT_TO_TIME(CommParameters[Protocollo+1].Tmin));
				TON_1(IN := TRUE,PT := DINT_TO_TIME(Talta));	
				TON_2(IN := TRUE,PT := DINT_TO_TIME(Tmedia));
				TON_3(IN := TRUE,PT := DINT_TO_TIME(Tbassa));

IF NOT FirstCy THEN
	dummy:=	WD_Disable('Task3_TCP');
	FirstCy:=TRUE;
END_IF;
	
IF 	TON_0.Q THEN																(* controlla se TIMER Tmin scaduto	*)
	TRIGGER02:=1;
	TRIGGER01:=1;

	TON_0(In:=FALSE);	

	IF Reset_TCP =1 THEN
		FOR I:=1 TO 64 DO
			CounterTCP[I]:=0;
		 END_FOR;
		TCPBlackList_ERROR_WORD:=0;
		TCPComm_ERROR_WORD:=0;
		BlackListTCPL:=0;
		BlackListTCPH:=0;
		CommErrTCPL:=0;
		CommErrTCPH:=0;
		ERROR_FLAG:=ERROR_FLAG AND 16#FFFD;

	END_IF;
	IF NOT Retry THEN
		IF TCPRequestPLCWrite > 0 THEN											(* controlla seci sono richieste di scrittura da parte del PLC	*)
			pointer:=4;
			FlagPrimoCiclo:=FALSE;
			IndexProt_i[pointer]:=0;
			HeadAddr:=WORD_TO_INT(LocalRTUQueue[IndexRTUQueueGet]);		(*inizializza i parametri da assegnare al blocco funzione*)
			IF CrossTable[HeadAddr].Counter=1 THEN
				ReadWrite:=WRITE_SINGLE;											(*inizializza i parametri da assegnare al blocco funzione*)
			ELSE
				ReadWrite:=WRITE_MULTIPLE;											(*inizializza i parametri da assegnare al blocco funzione*)
			END_IF;
			TCPRequestPLCWrite:=TCPRequestPLCWrite-1;							(* incrementa il contatore delle scritture effettuate*)
			IndexTCPQueueGet:=IndexTCPQueueGet+1;								(* incrementa il puntatore alla coda *)
			IF IndexTCPQueueGet > MaxLocalQueue THEN
				IndexTCPQueueGet:=0;
			END_IF;
		ELSE
			IF RichiestaScrittura=1 THEN										(* controlla se ci sono richieste di SCRITTURA da parte HMI*)	
				IF FlagPrimoCiclo = FALSE THEN									(* controlla se è il primo ingrsso nel ramo a seguito dell'interrupt*) 
					FlagPrimoCiclo:=TRUE;										(* Prima richiesta di scrittura => azzero l'indice della coda 	*)
					IndexProt_i[3]:=0;											(* per eseguire le scritture nella sequenza di arrivo		  	*)
					pointer:=3;
					zero:=TIM_Get();
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
									time2:=TIM_Get()-zero;
								END_IF;

								EXIT;
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
			ELSE																(* richieste di LETTURE	*)
				IF  RichiestaScrittura=0	THEN
	
					FlagPrimoCiclo:=FALSE;											(* azzera l'akwnoledge dell'interrupt*)
				END_IF;
			END_IF;
			IF  RichiestaScrittura=0	THEN
				IF TON_1.Q OR Enablei[0]=TRUE THEN							(* scaduto il timer ad alta priorità esegue le letture *)
					IF Enablei[0]=FALSE THEN
						TON_1(IN := FALSE);										(* riarma il timer*)
						Start[0]:=TRUE;
					END_IF;
					pointer:=0;
					Enablei[0]:=TRUE;
				ELSIF TON_2.Q OR Enablei[1]=TRUE THEN						(* scaduto il timer ad media priorità esegue le letture *)
					IF Enablei[1]=FALSE THEN
						TON_2(IN := FALSE);										(* riarma il timer*)
						Start[1]:=TRUE;
					END_IF;
					TON_2(IN := FALSE);										(* riarma il timer*)
					pointer:=1;
					Enablei[1]:=TRUE;
				ELSIF TON_3.Q OR Enablei[2]=TRUE THEN						(* scaduto il timer ad media priorità esegue le letture *)
					IF Enablei[2]=FALSE THEN
						TON_3(IN := FALSE);										(* riarma il timer*)
						Start[2]:=TRUE;
					END_IF;
					pointer:=2;
					Enablei[2]:=TRUE;
				END_IF;
		(*		pointer:=0;		*)
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
			IF TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed < 2  THEN			(* controlla se il device non è in blacklist*)
				BusAccess(Protocol:='TCP',Index:=IndexProt_i[pointer],address:=HeadAddr,RdWr:=ReadWrite);		(* effettua l'accesso al bus*)
				TON_0(IN := TRUE,PT := INT_TO_TIME(CommParameters[Protocollo+1].Tmin));						(* riarmo di Tmin*)
				IF BusAccess.Error > 0  THEN																(* controlla sec'è stato un errore di comuicazione*)
					ERROR_FLAG:=ERROR_FLAG OR 16#2;
					CounterTCP[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)]:=UDINT_TO_WORD(WORD_TO_UDINT(CounterTCP[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)])+1);
					IF BusAccess.Error = CommError THEN
						TCPComm_ERROR_WORD:=1;	
						IF BYTE_TO_INT(Crosstable[HeadAddr].NodeId) > 32 THEN
							CommErrTCPH:=CommErrTCPH OR SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
						ELSE
							CommErrTCPL:=CommErrTCPL OR SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
						END_IF;
						Retry:=FALSE;
					ELSIF BusAccess.Error = TimeoutError  THEN		(* controlla se c'è stato un erore di timeout*)
						Retry:=TRUE;							(* imposta il flag retry a TRUE in modo da effettuare le ripetizioni *)
						TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter:=TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter+1;
						IF TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter >= NumberOfFails THEN
							TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed:=TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed+1;
							TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead:=BYTE_TO_INT(FailDivisor);
							Retry:=FALSE;
							IF TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed > 1 THEN
								TCPBlackList_ERROR_WORD:=1;
								TCP_RUN:=FALSE;
								IF BYTE_TO_INT(Crosstable[HeadAddr].NodeId) > 32 THEN
									BlackListTCPH:=BlackListTCPH OR SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
								ELSE
									k:=SHL(16#1,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
									BlackListTCPL:=BlackListTCPL OR k;
								END_IF;
							END_IF;
						END_IF;
					END_IF;
				ELSE

					Retry:=FALSE;
					IF BYTE_TO_INT(Crosstable[HeadAddr].NodeId) > 32 THEN
						CommErrTCPH:=CommErrTCPH AND ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
						BlackListTCPH:=BlackListTCPH AND ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId) -33);
					ELSE
						CommErrTCPL:=CommErrTCPL AND ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
						k:=ROL(16#FFFFFFFE,BYTE_TO_INT(Crosstable[HeadAddr].NodeId)-1 );
						j:=BlackListTCPL;
						j:=j AND k;
						BlackListTCPL:=j;
					END_IF;
					IF CommErrTCPH =0 AND CommErrTCPl = 0 THEN
						TCPComm_ERROR_WORD:=0;	
					END_IF;
					IF BlackListTCPH =0 AND BlackListTCPL = 0 THEN
						TCPBlackList_ERROR_WORD:=0;	
					END_IF;

					TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed:=0;
					TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].RetryCounter:=0;
				END_IF;
			ELSE
				TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead:=TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead-1;
				IF TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].JumpRead <= 0 THEN
					TCPListDevices[BYTE_TO_INT(Crosstable[HeadAddr].NodeId)].BlackListed:=1;
					Retry:=TRUE;
				END_IF;
			END_IF;	
		END_IF;
	END_IF;
END_IF;	

END_PROGRAM
