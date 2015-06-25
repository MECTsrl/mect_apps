(*[[
]]*)
FUNCTION_BLOCK fb_HW119_InitComm
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	ENABLE:BOOL;		(* Abilitazione del blocco funzione	*)
	Interface:STRING;	(* Canale di comunicazione da abilitare	*) 
END_VAR
VAR_OUTPUT
	END:BOOL;			(*	segnala il completamento dell'inizializzazione	*)
	ERR:BOOL;			(* segnala il verificarsi di un errore durante l'esecuzione del blocco	*)
END_VAR
VAR
	FBState:UINT;
	FunctRes:UINT;
	TaskName:STRING;
	CommID:INT;
END_VAR
(*
	Blocco funzione per init dei canali di comunicazione 	

*)
	IF ENABLE	THEN
		IF FBState = 0 THEN
			FunctRes:=MODBUS_CLOSE (Interface);	
			MODBUS_ERR[0]:=FunctRes+2;
			FunctRes:=MODBUS_FREE (Interface);	
			MODBUS_ERR[1]:=FunctRes+2;
			IF Interface = 'RTU'	THEN
				FunctRes:=MODBUS_NEW_RTU(CommParameters[1].Device,CommParameters[1].BaudRate,CommParameters[1].Parity,CommParameters[1].DataBit,CommParameters[1].StopBit);	(*NEW RTU*)
				TaskName:='Task2_RTU';
				CommID:=1;
				MODBUS_ERR[2]:=FunctRes+2;
			ELSIF Interface = 'TCP'	THEN
				FunctRes:=MODBUS_NEW_TCP(CommParameters[2].IPaddr,CommParameters[2].Port);	(*NEW TCP*)
				TaskName:='Task3_TCP';
				CommID:=2;
				MODBUS_ERR[3]:=FunctRes+2;
			ELSIF Interface = 'TCPRTU'	THEN
				FunctRes:=MODBUS_NEW_TCPRTU(CommParameters[3].IPaddr,CommParameters[3].Port);(*NEW TCPRTU*)
				TaskName:='Task4_TCPRTU';
				CommID:=3;
				MODBUS_ERR[4]:=FunctRes+2;
			END_IF;

			IF FunctRes = 0 	THEN
				FunctRes:=MODBUS_CONNECT (Interface);													(*CONNECT*)
				MODBUS_ERR[5+CommID-1]:=2;
				IF FunctRes = 0 	THEN
					FunctRes:=MODBUS_FLUSH( Interface);													(*FLUSH*)
					IF FunctRes = 0 	THEN
						MODBUS_ERR[8]:=2;
						IF CommParameters[CommID].Timeout = 0 	THEN
							CommParameters[CommID].Timeout:=300;
						END_IF;
						FunctRes:=MODBUS_SET_RESPONSE_TIMEOUT  (Interface,CommParameters[CommID].Timeout);		(*TIMEOUT*)
						IF FunctRes = 0 	THEN
							MODBUS_ERR[9]:=2;
							FBState:=10;
						ELSE
							FBState:=1000;
							MODBUS_ERR[9]:=3;
						END_IF;
					ELSE
						MODBUS_ERR[8]:=2;
						FBState:=1000;
					END_IF;
				ELSE			
					MODBUS_ERR[5+CommID-1]:=3;
					FBState:=1000;
				END_IF;
			ELSE
				FBState:=1000;
			END_IF;
		ELSIF FBState=10	 THEN
			END:=TRUE;
		ELSIF FBState=1000	 THEN
			CASE CommID OF
				1:	ErrorsState:=ErrorsState OR 16#00000010;	(* errore sull'inizalizzaizione RTU	*)
				2:	ErrorsState:=ErrorsState OR 16#00000020;	(* errore sull'inizalizzaizione TCP	*)
				3:	ErrorsState:=ErrorsState OR 16#00000040;	(* errore sull'inizalizzaizione TCPRTU	*)
				
			END_CASE;
			FunctRes:=MODBUS_FREE (Interface);	
			ERR:=TRUE;
		END_IF;
	ELSE
		ERR:=FALSE;
		END:=FALSE;
		FBState:=0;
	END_IF;
END_FUNCTION_BLOCK
