(*[[
    UserHelpURL= "4cfile:Program1.HTML",
]]*)

PROGRAM Program1
#import "crosstable.gvl"
VAR
(* Revisione 5.31
Corretto baco nel blocco funzione PLCsync
riga 35					FOR I:=0 TO CrossTable[addr].NReg-1 BY STEPS DO			
aggiunto -1 al FOR
*)	

(* Revisione 5.32	
Inserita la misurazione della query pause al termine della risposta dallo slave
solo per protocollo RTU
*)	

(* Revisione 5.33
Modificata policy del device disconnesso. Ora, se un indirizzo non risponde e supera il limite faildivisor
si mette l'indirizzo in una blacklist, quindi le richieste di accessi successivi al device saranno ignorati


Revisione 5.4
Inseriti contatori di errori per ogni protocollo
	ContatoreErroriRTU		
	ContatoreErroriTCP		
	ContatoreErroriTCPRTU	

Inserite variabili di revisione: 
	PLCRevision01
	PLCRevision02

Modificata scrittura in uPLC: Le scritture sono prioritarie rispetto a quelle HMI, sono ammesse le scritture multiple
Inserita la gestione delle variabili intere a 32 bit 
	UDINTDCBA
	UDINTCDAB
	UDINTABCD
	UDINTBADC
	DINTDCBA
	DINTCDAB
	DINTABCD
	DINTBADC

 Revisione 5.42
 	Inserite scritture ad alta priorità da uPLC
	Le scritture sono inserite in tre code (una per protocollo) ed eseguite nella sequenza di arrivo
	tutte le altre operazioni sono ritardate fino a che non sono
	terminate le scritture

Revisione 5.43
	Corretto baco già risolto in 5.31, reintrodotto nella 5.4.
Revisione 5.44
	Corretto baco sulla gestione allarmi: Non veniva effettuato l'aggiornamento dello stato della variabile a error=0
		nel caso di accessi interni (non su strumenti) sia da HMI che da uPLC
		Perciò se la SourceVariable era una variabile interna (non su un device modbus)
		non veniva aggiornato lo stato di variabile disponibile per gli allarmi
		corretto file PLC_sync.st 
		aggiunta alla riga 35 CrossTable[addr+I].Error:=0;
	Corretto baco sulle scritture da PLC:
		non venivano effettuate le scritture multiple se il uPLC le effettuava su variabili interne
		modificato nel blocco funzione fb_HW119_PLCwriteVar il codice 
					FOR I:=0 TO NRegs-1 DO											
						ARRAY_CROSSTABLE_INPUT[WORD_TO_INT(ADDRESS)+I]:=CrossTable[WORD_TO_INT(ADDRESS)+I].PLCWriteVal;
						CrossTable[WORD_TO_INT(ADDRESS)+I].Error:=0;
					END_FOR;
Revisione 5.45
	Corretto baco su scritture multiple

Revisione 5.46
	Corretto baco su scritture singole

Revisione 5.47
	Modificata gestione ricetta
	Aggiunta scrittura in ricetta delle variabili interne 

Revisione 5.48
	Corretta la gestione dei falg di busywrite per le scritture su variabili interne nel blocco funzione PLCsync
Revisione 5.49
	Corretto baco su FB plcsync: non veniva aggiornata la mandata in run del protocollo TCP a seguito di una riconnessione
Revisione 5.50
	Corretta letura Modbus sui bit nei protocolli RTU e TCPRTU
Revisione 5.51
	Corretta la gestione della scrittura a bit da PLC interno
	Corretta la segnalazione di errore nel blocco funzione fb_HW119_PLCwriteVar
	MOdificato blocco fb_HW119_AlarmsMngr: in caso di variabili interne non si controlla se è già avvenuta l'assegnazione
Revisione 5.52
	Corretta gestione fb_HW119_PLCwritevar in caso di errore sulla funzione Gettaddr()
Revisione 5.53
	Aggiunta scrittura multipla delle variabili interne
Revisione 6.00
	Inserita priorità delle letture
	contatori errore e blacklist
	scritture ad interrupt
Revisione 6.01
	Corretti bachi: 
		La variabile Retry non veniuva azzerata se il dispositivo ritornava on line prima dello scadere dei retry
		messa a false la variabile debug
		corretta la revisione sw
		aggiunta variabilie di Error_flag che segnala se c'è stato almeno un errore dall'ultimo reset
Revisione 6.02 
		corretto baco su scrittura da PLC
		aggiunto a Error_flag la segnalazione di errore sulla lettura di una crosstable
Revisione 6.03 
		modificate costanti dei file delle CT: tolti i path per poter essere utilizzati da SD 
		non si tiene conto del  path per le crosstable per il caricamento da Flash o SD card
Revisione 6.04
	Inserito di default NodeId a 1 nel caso di protocollo TCP

Revisione 6.05
	Inserita gestione Canopen in funzione della variabile HardwareType 
	variata la gestione delle scritture e letture nel task RTU
Revisione 6.08
	corretti bachi sui protocolli
Revisione 6.10
	corretti bacho su fb_HW119_MODBUS
Revisione 6.12
	Modificati file gvl delle variabili locali
	creato blocco funzione di sincronizzazione per le variabili locali del tpac1007
	unificate le variabili di IO locale PLC di accesso utente
	inserita la variabile di sistema PLC_time per che si azzera ogni 3600 secondi
 Revisione 6.13
 	Modificate uscite analogiche sui blocchi funzione fb_TPAC1006_LIO_sync e fb_TPAC1007_LIO_sync
*)

	InitComm:fb_HW119_InitComm;
	AlarmMngr:fb_HW119_AlarmsMngr;
	LoadXTable:fb_HW119_LoadCrossTab;
	ErrorMNG:fb_HW119_ErrorMng;
	PLCsync:fb_HW119_PLCsync;
	Reconnect:fb_HW119_Check;
	TPAC1006_LIOsync:fb_TPAC1006_LIOsync;
	TPAC1007_LIOsync:fb_TPAC1007_LIOsync;
	TICtimer:fb_TPAC_tic;
	FunctRes:UINT;
	CommState: UDINT;
	COUNTER:UDINT;
	timer_sync:TON;
	
	(* DEBUG
	errorT1:DINT;
	errorT2:DINT;
	errorT3:DINT;
	errorT4:DINT;
	reterr:WORD;
	*)
END_VAR
(*	DEBUG
	errorT1:=GetLocalTaskErrno ('Task1');
	errorT2:=GetLocalTaskErrno ('Task2_RTU'	);
	errorT3:=GetLocalTaskState ('Task1');
	errorT4:=GetLocalTaskState('Task2_RTU');
	PLCRevision01:=5;
	PLCRevision02:=4;
*)



	IF CommState = 0	THEN
		FunctRes:=HW119_CloseCrossTable();
		LoadXTable(ENABLE:=FALSE);	
		InitComm(ENABLE:=FALSE);
		ErrorsState:=0;
		CommState:=10;
		COUNTER:=0;
		RTU_RUN:=FALSE;
		TCP_RUN:=FALSE;
		TCPRTU_RUN:=FALSE;
		ERROR_FLAG:=0;
	ELSIF CommState = 10	THEN			(* Lettura crosstable allarmi	*)
		LoadXTable(ENABLE:=TRUE,CTFile:=ALcrossTableFile,CTDimension:=DimAlarmsCT,CTType:=1);		
		IF LoadXTable.ERR  	THEN
			CommState:=20;					(* Fallita lettura crosstable allrmi -> prosegue con lettura cross table variabili*)
			ALCrossTableState:=FALSE;
			LoadXTable(ENABLE:=FALSE);	
			ERROR_FLAG:=ERROR_FLAG OR 16#10;(* SEGNALO L'ERRORE SUL BIT 4*)
		ELSE
			IF LoadXTable.END THEN
				CommState:=20;				(*lettura crosstable  Allarmi  OK  -> prosegue*)
				FunctRes:=HW119_CloseCrossTable();
				LoadXTable(ENABLE:=FALSE);	
			END_IF;
		END_IF;

	ELSIF CommState = 20	THEN			(* Lettura crosstable variabili	*)
		LoadXTable(ENABLE:=TRUE,CTFile:=VARcrossTableFile,CTDimension:=DimCrossTable,CTType:=0);		
		IF LoadXTable.ERR  	THEN
			CommState:=1000;
			CrossTableState:=FALSE;			(* Fallita lettura crosstable  variabili: FINE*)
			ERROR_FLAG:=ERROR_FLAG OR 16#20;(* SEGNALO L'ERRORE SUL BIT 5*)
		ELSE
			IF LoadXTable.END THEN
				CommState:=30;				(*lettura crosstable  variabili  OK ->  prosegue*)
				LoadXTable(ENABLE:=FALSE);	
			END_IF;
		END_IF;

	ELSIF CommState = 30	THEN			(* Lettura crosstable parametri di comunicazione	*)
		LoadXTable(ENABLE:=TRUE,CTFile:=CommParFile,CTDimension:=5,CTType:=2);		
		IF LoadXTable.ERR  	THEN			
			CommState:=1000;				(* Fallita lettura crosstable  parametri di comunicazione: FINE*)
			ERROR_FLAG:=ERROR_FLAG OR 16#08;(* SEGNALO L'ERRORE SUL BIT 3*)
		ELSE
			IF LoadXTable.END THEN
				CommState:=40;				(*lettura crosstable  variabili  OK ->  prosegue*)
				LoadXTable(ENABLE:=FALSE);	
			END_IF;
		END_IF;



	(* Abilitazione protocollo RTU se almeno una entry della crosstable supporta questo protocollo*)
	ELSIF CommState = 40	THEN			
		IF 	RTUProtocol_ON	AND CommParameters[1].State THEN
			InitComm(ENABLE:=TRUE,Interface:='RTU');	(*inizializza comunicazione	*)
			IF InitComm.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK2_RTU'));		(* partenza task RTU*)	
				ERROR_FLAG:=ERROR_FLAG OR 16#80;(* SEGNALO CHE IL TASK RTU è PARTITO*)			
				CommState:=50;
				InitComm(ENABLE:=FALSE);
				RTU_RUN:=TRUE;
			ELSIF InitComm.ERR THEN
				CommState:=50;		
				InitComm(ENABLE:=FALSE);
				RTU_RUN:=FALSE;
			END_IF;
		ELSE
			CommState:=50;
		END_IF;

	(* Abilitazione protocollo TCP se almeno una entry della crosstable supporta questo protocollo*)
	ELSIF CommState = 50	THEN	
		IF 	TCPProtocol_ON	AND CommParameters[2].State THEN
			InitComm(ENABLE:=TRUE,Interface:='TCP');	(*inizializza comunicazione	*)
			IF InitComm.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK3_TCP'));		(* partenza task TCP*)									
				ERROR_FLAG:=ERROR_FLAG OR 16#100;(* SEGNALO CHE IL TASK TCP è PARTITO*)					
				CommState:=60;
				InitComm(ENABLE:=FALSE);
				TCP_RUN:=TRUE;
			ELSIF InitComm.ERR THEN
				CommState:=60;		
				InitComm(ENABLE:=FALSE);
				TCP_RUN:=FALSE;	
			END_IF;		
		ELSE
			CommState:=60;
		END_IF;

	(* Abilitazione protocollo TCPRTU se almeno una entry della crosstable supporta questo protocollo*)
	ELSIF CommState = 60 	THEN
		
		IF 	TCPRTUProtocol_ON	AND CommParameters[3].State THEN
			InitComm(ENABLE:=TRUE,Interface:='TCPRTU');	(*inizializza comunicazione	*)
			IF InitComm.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK4_TCPRTU'));		(* partenza task TCPRTU*)									
				ERROR_FLAG:=ERROR_FLAG OR 16#200;(* SEGNALO CHE IL TASK TCPRTU è PARTITO*)					
				CommState:=70;
				InitComm(ENABLE:=FALSE);
				TCPRTU_RUN:=TRUE;
			ELSIF InitComm.ERR THEN
				TCPRTU_RUN:=FALSE;
				CommState:=70;	
				InitComm(ENABLE:=FALSE);	
			END_IF;		
		ELSE
			CommState:=70;
		END_IF;

	ELSIF CommState = 70	THEN
		ERROR_FLAG:=ERROR_FLAG OR 16#40;	(* SEGNALA SUL BIT 6 CHE HA TERMINATO L'INIZIALIZZAZIONE DELLE CT*)
		TRIGGER02:=TRIGGER02;
		TRIGGER01:=TRIGGER01;
		IF  ALCrossTableState THEN
			CommEnabled:=TRUE;
		END_IF;
		FunctRes:=WORD_TO_UINT(TSK_Start('TASK0_Control'));		(* partenza task PLC*)									
		CommState:=80;

	ELSIF CommState = 80	THEN
		TRIGGER02:=TRIGGER02;
		TRIGGER01:=TRIGGER01;
		IF CommEnabled THEN
			AlarmMngr();					(* Gestione allarmi*)	
		END_IF;	
		Reconnect();						(* Riconnessione per protocolli TCP e TCPRTU	*)
		PLCsync();							(* sincronizzazione tra variabili PLC e HMI	*)
		timer_sync(IN:=TRUE,PT:=T#50ms);
		IF timer_sync.Q THEN	
			timer_sync(IN:=FALSE);
			TICtimer(tic:=T#50ms);
			IF (HardwareType AND 16#000000FF) >= 16#01 THEN
				TPAC1006_LIOsync();
			END_IF;
			IF (HardwareType AND 16#00FF0000) >= 16#01 THEN
				TPAC1007_LIOsync();
			END_IF;
		END_IF;
	ELSIF CommState = 1000	THEN
		TRIGGER02:=TRIGGER02;
		ERROR_FLAG:=ERROR_FLAG OR 16#40;	(* SEGNALA SUL BIT 6 CHE HA TERMINATO L'INIZIALIZZAZIONE DELLE CT*)
		ErrorMNG();							(* Gestione errori	*)
	END_IF;				
END_PROGRAM
