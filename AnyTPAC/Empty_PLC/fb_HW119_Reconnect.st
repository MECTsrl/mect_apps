(*[[
]]*)
FUNCTION_BLOCK fb_HW119_Reconnect
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
END_VAR
VAR
	STATE:UINT;
	FunctRes:UINT;
	TON_Reconnect:TON;
	InitComm:fb_HW119_InitComm;
	
END_VAR

		TON_Reconnect(IN := TRUE,PT := T#4s);
		IF TON_Reconnect.Q 	THEN
			TON_Reconnect(In:=FALSE);
			CASE STATE OF
				10: STATE:=20;
				20:	STATE:=30;
				30:	STATE:=10;
			ELSE
				STATE:=10;
			END_CASE;
		END_IF;

		IF NOT RTU_RUN AND RTUProtocol_ON AND STATE = 10 	THEN		
			InitComm(ENABLE:=TRUE,Interface:='RTU');	(*inizializza comunicazione	*)
			IF InitComm.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK2_RTU'));		(* partenza task RTU*)										
				InitComm(ENABLE:=FALSE);
				RTU_RUN:=TRUE;	
			ELSIF InitComm.ERR THEN
				RTU_RUN:=FALSE;	
			END_IF;
		ELSIF NOT TCP_RUN AND TCPProtocol_ON AND STATE = 20 	THEN	
			TON_Reconnect(In:=FALSE);
			InitComm(ENABLE:=TRUE,Interface:='TCP');	(*inizializza comunicazione	*)
			IF InitComm.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK3_TCP'));		(* partenza task TCP*)										
				InitComm(ENABLE:=FALSE);
				TCP_RUN:=TRUE;	
			ELSIF InitComm.ERR THEN
				TCP_RUN:=FALSE;	
			END_IF;
		ELSIF NOT TCP_RUN AND TCPRTUProtocol_ON AND STATE = 30 	THEN	
			TON_Reconnect(In:=FALSE);
			InitComm(ENABLE:=TRUE,Interface:='RTU');	(*inizializza comunicazione	*)
			IF InitComm.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK4_TCPRTU'));		(* partenza task TCPRTU*)										
				InitComm(ENABLE:=FALSE);
				TCPRTU_RUN:=TRUE;	
			ELSIF InitComm.ERR THEN
				TCPRTU_RUN:=FALSE;	
			END_IF;
		END_IF;

END_FUNCTION_BLOCK
