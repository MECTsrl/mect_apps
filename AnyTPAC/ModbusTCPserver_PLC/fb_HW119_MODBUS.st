(*[[
]]*)
FUNCTION_BLOCK fb_HW119_MODBUS
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
	RdWr:WORD;
	address:INT;
	Index:int;
	Protocol:STRING;
END_VAR
VAR_OUTPUT
	Error:UINT;
END_VAR
VAR
	FunctRes:UINT;
	HeadAddr:INT;
	I:INT;
	STEPS:INT;
	RW:WORD;
	COUNT_ERR:UDINT:=0;
	addr:INT;
	COUNT_CICLI:UDINT;
	regs:INT;
	LowByte:BYTE;
	BOOL_Data:	ARRAY[0..259]	OF BYTE;
	INT_Data:	ARRAY[0..259]	OF UINT;
	tempo1:TIME;
	tempo2:TIME;
	Index_A:int;
	tmpARRAY_CROSSTABLE_OUTPUT:	ARRAY[0..19] OF DWORD;
END_VAR



	tempo1:=TIM_Get();
(*	TRIGGER02:=1;
	TRIGGER01:=1;
	*)



		RW:=RdWr;
		HeadAddr:=address;		
		addr:=address;
		Index_A:=Index;

	
		IF RW > 0   THEN											(* Variabile abilitata*)
		
			COUNT_CICLI:=COUNT_CICLI+1;	
			FunctRes:= MODBUS_SET_SLAVE(Protocol,CrossTable[HeadAddr].NodeId);	
			IF FunctRes = 0  THEN										(* Funzione andata a buon fine*)
				MODBUS_ERR[10]:=2;
				IF RW = READ	THEN									(* OPERAZIONE DI LETTURA	*)				
					TRIGGER02:=1;
					regs:=0;
					IF Index_A > 0 THEN 
						ARRAY_QUEUE_OUTPUT[Index_A]:=STATO_BUSY_READ;	(* metto busy read l'intero blocco*)
					END_IF;
					FOR I:=0 TO CrossTable[HeadAddr].NReg-1 DO				(*  calcolo del numero di letture modbus da effettuare*)
						
						CASE CrossTable[HeadAddr+I].Types OF
							FLOATABCD,UDINTABCD,DINTABCD:		regs:=regs+2;
							FLOATDCBA,UDINTDCBA,DINTDCBA:		regs:=regs+2;
							FLOATCDAB,UDINTCDAB,DINTCDAB:		regs:=regs+2;
							FLOATBADC,UDINTBADC,DINTBADC:		regs:=regs+2;
						ELSE
							regs:=regs+1;
						END_CASE;
				   	END_FOR;
					IF CrossTable[HeadAddr].Types = BIT THEN			(* richiesta di lettura a bit	*)
						FunctRes:=  MODBUS_READ_BITS (Protocol,CrossTable[HeadAddr].Address,INT_TO_UINT(regs),BOOL_Data);
					ELSE					
						FunctRes:= MODBUS_READ_REGISTERS (Protocol,CrossTable[HeadAddr].Address,INT_TO_UINT(regs),INT_Data);						
					END_IF;
					IF FunctRes = 0  THEN								(* Funzione andata a buon fine*)
						Error:=0;
						MODBUS_ERR[11]:=2;
						ErrorsState:=ErrorsState AND 16#FF7F;
						CrossTable[HeadAddr].Error:=0;						(* segnala valore valido	*)
						I:=0;
						REPEAT 
							CASE CrossTable[HeadAddr].Types OF
								FLOATABCD,UDINTABCD,DINTABCD :		STEPS:=2;
								FLOATDCBA,UDINTDCBA,DINTDCBA:		STEPS:=2;
								FLOATCDAB,UDINTCDAB,DINTCDAB:		STEPS:=2;
								FLOATBADC,UDINTBADC,DINTBADC:		STEPS:=2;
							ELSE
								STEPS:=1;
							END_CASE;
							CASE CrossTable[addr].Types	OF				(* in funzione del tipo di dato sistema la variabile	*)
								FLOATABCD,UDINTABCD,DINTABCD:
									ARRAY_CROSSTABLE_INPUT[addr]:=0;
									ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I]) OR SHL(UINT_TO_DWORD(INT_Data[I+1]),16) ;
							(*		DummyFloat:=DWORD_TO_REAL(ARRAY_CROSSTABLE_INPUT[addr+I]);*)
	
								FLOATDCBA,UDINTDCBA,DINTDCBA:
									ARRAY_CROSSTABLE_INPUT[addr]:=0;
									LowByte:=UINT_TO_BYTE(INT_Data[I]);
									INT_Data[I]:= WORD_TO_UINT(SHR(UINT_TO_WORD(INT_Data[I]),8));
									INT_Data[I]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I]) OR  SHL(BYTE_TO_WORD(LowByte),8));
									LowByte:=UINT_TO_BYTE(INT_Data[I+1]);
									INT_Data[I+1]:= WORD_TO_UINT(SHR(UINT_TO_WORD(INT_Data[I+1]),8));
									INT_Data[I+1]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I+1]) OR  SHL(BYTE_TO_WORD(LowByte),8));
									ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I+1]) OR SHL(UINT_TO_DWORD(INT_Data[I]),16) ;
	
								FLOATCDAB,UDINTCDAB,DINTCDAB:
									ARRAY_CROSSTABLE_INPUT[addr]:=0;
									ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I+1]) OR SHL(UINT_TO_DWORD(INT_Data[I]),16) ;
	
								FLOATBADC,UDINTBADC,DINTBADC:
									ARRAY_CROSSTABLE_INPUT[addr]:=0;
									LowByte:=UINT_TO_BYTE(INT_Data[I]);
									INT_Data[I]:= WORD_TO_UINT(SHR(UINT_TO_WORD(INT_Data[I]),8));
									INT_Data[I]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I]) OR  SHL(BYTE_TO_WORD(LowByte),8));
									LowByte:=UINT_TO_BYTE(INT_Data[I+1]);
									INT_Data[I+1]:= WORD_TO_UINT(SHR(UINT_TO_WORD(INT_Data[I+1]),8));
									INT_Data[I+1]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I+1]) OR  SHL(BYTE_TO_WORD(LowByte),8));
									ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I]) OR SHL(UINT_TO_DWORD(INT_Data[I+1]),16) ;
								UINT16:
									ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I]);
								INT16:
									ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I]);
								BIT:
									ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I]);
							ELSE
								ARRAY_CROSSTABLE_INPUT[addr]:=UINT_TO_DWORD(INT_Data[I]);							
							END_CASE;
							addr:=addr+1;							(* punta alla successiva variabile della crosstable*)
							I:=I+STEPS;
						UNTIL I >= regs
						END_REPEAT;
						FOR I:=0 TO CrossTable[HeadAddr].NReg-1	DO
							ARRAY_STATES[HeadAddr+I]:=STATO_OK;				(* segnala lo stato della comunicazione a OK		*)
							CrossTable[HeadAddr+I].Error:=0;						(* segnala valore valido	*)
						END_FOR;
					ELSIF FunctRes > 0	THEN						(*	segnala lo stato della comunicazione a  ERR		*)
						MODBUS_ERR[11]:=3;
						ErrorsState:=ErrorsState OR 16#0080;
						Error:=FunctRes;
						FOR I:=0 TO CrossTable[HeadAddr].NReg-1	DO
							ARRAY_STATES[HeadAddr+I]:=STATO_ERR;
							CrossTable[HeadAddr+I].Error:=1;					(* segnala valore non valido *)
						END_FOR;
						COUNT_ERR:=COUNT_ERR+1;
					END_IF;
				ELSIF  RW =  WRITE_SINGLE OR RW = WRITE_MULTIPLE OR RW = WRITE_RIC_SINGLE  OR RW = WRITE_RIC_MULTIPLE    THEN												(*	OPERAZIONE DI SCRITTURA	*)
					regs:=0;
					RW:=RW AND 16#B000;
					IF RW=WRITE_SINGLE THEN							(* scrittura singola ingnoro il contenuto di Nreg*)
						IF Index_A > 0 THEN
							ARRAY_QUEUE_OUTPUT[Index_A]:=STATO_BUSY_WRITE;	
							tmpARRAY_CROSSTABLE_OUTPUT[0]:=ARRAY_CROSSTABLE_OUTPUT[HeadAddr];
						ELSE
							tmpARRAY_CROSSTABLE_OUTPUT[0]:=CrossTable[HeadAddr].PLCWriteVal;
						END_IF;
						ARRAY_STATES[HeadAddr]:=STATO_RUN;
						CASE CrossTable[HeadAddr].Types OF
							FLOATABCD,UDINTABCD,DINTABCD:		regs:=2;
							FLOATDCBA,UDINTDCBA,DINTDCBA:		regs:=2;
							FLOATCDAB,UDINTCDAB,DINTCDAB:		regs:=2;
							FLOATBADC,UDINTBADC,DINTBADC:		regs:=2;
						ELSE
							regs:=1;
						END_CASE;
	
					ELSIF RW = WRITE_MULTIPLE THEN
						IF Index_A > 0 THEN
							ARRAY_QUEUE_OUTPUT[Index_A]:=STATO_BUSY_WRITE;	
						END_IF;
						
									
						FOR I:=0 TO CrossTable[HeadAddr].NReg-1 DO				(*  calcolo del numero di letture modbus da effettuare*)
							IF Index_A > 0 THEN
								tmpARRAY_CROSSTABLE_OUTPUT[I]:=ARRAY_CROSSTABLE_OUTPUT[HeadAddr+I];
							ELSE
								tmpARRAY_CROSSTABLE_OUTPUT[I]:=CrossTable[HeadAddr+I].PLCWriteVal;
							END_IF;

							ARRAY_STATES[HeadAddr+I]:=STATO_RUN;	
							CASE CrossTable[HeadAddr+I].Types OF
								FLOATABCD,UDINTABCD,DINTABCD:		regs:=regs+2;
								FLOATDCBA,UDINTDCBA,DINTDCBA:		regs:=regs+2;
								FLOATCDAB,UDINTCDAB,DINTCDAB:		regs:=regs+2;
								FLOATBADC,UDINTBADC,DINTBADC:		regs:=regs+2;
							ELSE
								regs:=regs+1;
							END_CASE;
					   	END_FOR;		
					END_IF;
	
					I:=0;
					REPEAT
						CASE CrossTable[addr].Types OF
							FLOATABCD,UDINTABCD,DINTABCD :		STEPS:=2;
							FLOATDCBA,UDINTDCBA,DINTDCBA:		STEPS:=2;
							FLOATCDAB,UDINTCDAB,DINTCDAB:		STEPS:=2;
							FLOATBADC,UDINTBADC,DINTBADC:		STEPS:=2;
						ELSE
							STEPS:=1;
						END_CASE;
	
						CASE CrossTable[addr].Types	OF				(* in funzione del tipo di dato arrangia la variabile	*)
	
							FLOATDCBA,UDINTDCBA,DINTDCBA:
								INT_Data[I+1]:=DWORD_TO_UINT(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr] AND 16#0000FFFF);
								INT_Data[I]:=DWORD_TO_UINT(SHR(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr],16) AND 16#0000FFFF);
								LowByte:=UINT_TO_BYTE(INT_Data[I]);
								INT_Data[I]:= WORD_TO_UINT(SHR(UINT_TO_WORD(INT_Data[I]),8));
								INT_Data[I]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I]) OR  SHL(BYTE_TO_WORD(LowByte),8));
								LowByte:=UINT_TO_BYTE(INT_Data[I+1]);
								INT_Data[I+1]:= WORD_TO_UINT(SHL(UINT_TO_WORD(INT_Data[I+1]),8));
								INT_Data[I+1]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I+1]) OR  SHL(BYTE_TO_WORD(LowByte),8));
	
							FLOATCDAB,UDINTCDAB,DINTCDAB:
								INT_Data[I+1]:=DWORD_TO_UINT(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr] AND 16#0000FFFF);
								INT_Data[I]:=DWORD_TO_UINT(SHL(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr],16) AND 16#0000FFFF);
	
							FLOATBADC,UDINTBADC,DINTBADC:
								INT_Data[I]:=DWORD_TO_UINT(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr] AND 16#0000FFFF);
								INT_Data[I+1]:=DWORD_TO_UINT(SHR(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr],16) AND 16#0000FFFF);
								LowByte:=UINT_TO_BYTE(INT_Data[I]);
								INT_Data[I]:= WORD_TO_UINT(SHR(UINT_TO_WORD(INT_Data[I]),8));
								INT_Data[I]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I]) OR  SHL(BYTE_TO_WORD(LowByte),8));
								LowByte:=UINT_TO_BYTE(INT_Data[I+1]);
								INT_Data[I+1]:= WORD_TO_UINT(SHL(UINT_TO_WORD(INT_Data[I+1]),8));
								INT_Data[I+1]:=	WORD_TO_UINT(UINT_TO_WORD(INT_Data[I+1]) OR  SHL(BYTE_TO_WORD(LowByte),8));							
	
							UINT16:	INT_Data[I]:=DWORD_TO_UINT(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr] AND 16#0000FFFF);
	
							INT16:	INT_Data[I]:=DWORD_TO_UINT(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr] AND 16#0000FFFF);
	
							BIT:	BOOL_Data[I]:=DWORD_TO_BYTE(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr] AND 16#0000FFFF);
	
						ELSE
							INT_Data[I]:=DWORD_TO_UINT(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr] AND 16#0000FFFF);
							INT_Data[I+1]:=DWORD_TO_UINT(SHR(tmpARRAY_CROSSTABLE_OUTPUT[addr-HeadAddr],16) AND 16#0000FFFF);
							
						END_CASE;
						I:=I+STEPS;
						addr:=addr+1;							(* punta alla successiva variabile della crosstable*)
						
					UNTIL I >= regs
				    END_REPEAT;
	
					IF  CrossTable[HeadAddr].Types = BIT	THEN		(* richiesta scrittura a bit*)
						FunctRes:= MODBUS_WRITE_BITS (Protocol,CrossTable[HeadAddr].Address,INT_TO_UINT(regs),BOOL_Data);
					ELSE												(*riciesta scrittura a word*)
						IF regs = 1	THEN
							FunctRes:= MODBUS_WRITE_REGISTER (Protocol,CrossTable[HeadAddr].Address,INT_Data[0]);
						ELSE
							FunctRes:= MODBUS_WRITE_REGISTERS (Protocol,CrossTable[HeadAddr].Address,regs,INT_Data);
						END_IF;
					END_IF;				
					IF FunctRes = 0  THEN							(*	Funzione andata a buon fine *)
						MODBUS_ERR[12]:=2;
						ErrorsState:=ErrorsState AND 16#FF7F;
						IF RW=WRITE_SINGLE THEN	
							IF Index_A > 0	THEN
								ARRAY_CROSSTABLE_INPUT[HeadAddr]:=ARRAY_CROSSTABLE_OUTPUT[HeadAddr];
							ELSE
								ARRAY_CROSSTABLE_INPUT[HeadAddr]:=CrossTable[HeadAddr].PLCWriteVal;
							END_IF;
							ARRAY_STATES[HeadAddr]:=STATO_OK;				(* segnala lo stato della comunicazione a OK		*)
						ELSE

							FOR I:=0 TO  CrossTable[HeadAddr].NReg-1 DO			(*	copia dei valori da leggere nel buffer di comunicazione	*)					
								IF Index_A > 0	THEN
									ARRAY_CROSSTABLE_INPUT[HeadAddr+I]:=ARRAY_CROSSTABLE_OUTPUT[HeadAddr+I];
								ELSE
									ARRAY_CROSSTABLE_INPUT[HeadAddr+I]:=CrossTable[HeadAddr+I].PLCWriteVal;
								END_IF;
								ARRAY_STATES[HeadAddr+I]:=STATO_OK;				(* segnala lo stato della comunicazione a OK		*)

							END_FOR;
						END_IF;
						Error:=0;
					ELSIF FunctRes > 0	THEN
						Error:=FunctRes;
						MODBUS_ERR[12]:=3;
						COUNT_ERR:=COUNT_ERR+1;
						ErrorsState:=ErrorsState OR 16#0080;
						IF RW = WRITE_SINGLE THEN
							ARRAY_STATES[HeadAddr]:=STATO_ERR;
						ELSE
							FOR I:=0 TO  CrossTable[HeadAddr].NReg-1 DO
								ARRAY_STATES[HeadAddr+I]:=STATO_ERR;
							END_FOR;
						END_IF;
					END_IF;

				END_IF;
			ELSE
				MODBUS_ERR[10]:=3;
			END_IF;
	 	END_IF;
	tempo2:=TIM_Get()-tempo1;




END_FUNCTION_BLOCK
