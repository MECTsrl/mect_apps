(*[[
]]*)
FUNCTION_BLOCK fb_HW119_PLCsync
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
END_VAR
VAR
	IndexPLC:UINT;
	I:INT;
	RW:WORD;
	addr:INT;
	duster:UINT:=1;
END_VAR
		
		IF duster < DINT_TO_UINT(DimCrossTable) AND duster < maxQueue THEN
			RW:=ARRAY_QUEUE[duster] AND QueueRWMask;
			IF  RW  = 0 AND  ARRAY_QUEUE_OUTPUT[duster]=STATO_BUSY_WRITE  THEN
				ARRAY_QUEUE_OUTPUT[duster]:=0;
			END_IF;
			duster:=duster+1;
		ELSE
			duster:=1;
		END_IF;
		(* Rileva la prima variabile da leggere della cross table*)
		IF IndexPLC < DINT_TO_UINT(DimCrossTable) THEN
			IndexPLC:=IndexPLC+1;
			RW:=ARRAY_QUEUE[IndexPLC] AND QueueRWMask;
			addr:=WORD_TO_INT(ARRAY_QUEUE[IndexPLC] AND QueueAddressMask);	
			IF addr < DINT_TO_INT(DimCrossTable)	THEN
				IF  RW  = 0 AND  ARRAY_QUEUE_OUTPUT[IndexPLC]=STATO_BUSY_WRITE AND CrossTable[addr].Protocol = 100 THEN
					ARRAY_QUEUE_OUTPUT[IndexPLC]:=0;
				ELSIF RW =0 AND addr =0 THEN
					ARRAY_QUEUE_OUTPUT[IndexPLC]:=0;
					IndexPLC:=0;
				ELSIF ( RW  = WRITE OR  RW  = WRITE_RIC_SINGLE OR RW=WRITE_MULTIPLE) AND  ARRAY_QUEUE_OUTPUT[IndexPLC]<>STATO_BUSY_WRITE AND CrossTable[addr].Protocol = 100 THEN
					ARRAY_QUEUE_OUTPUT[IndexPLC]:=STATO_BUSY_WRITE;
					IF (RW  = WRITE) OR (RW  = WRITE_RIC_SINGLE) THEN
						ARRAY_CROSSTABLE_INPUT[addr]:=ARRAY_CROSSTABLE_OUTPUT[addr];
					ELSE
						FOR I:=0 TO CrossTable[addr].NReg - 1 DO			(*	copia dei valori da leggere nel buffer di comunicazione	*)					
							ARRAY_CROSSTABLE_INPUT[addr+I]:=ARRAY_CROSSTABLE_OUTPUT[addr+I];
							CrossTable[addr+I].Error:=0;							(*indica che la variabile è aggiornata*)
						END_FOR;
					END_IF;
				END_IF;
			END_IF;
		ELSE
			IndexPLC:=0;
		END_IF;
		

END_FUNCTION_BLOCK
