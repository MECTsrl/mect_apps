(*[[
]]*)
FUNCTION_BLOCK fb_HW119_Check
#import "Resource1.gvl"
#import "crosstable.gvl"
VAR_INPUT
END_VAR
VAR
	STATE:UINT;
	FunctRes:UINT;
	TON_Reconnect:TON;
	InitCommunication:fb_HW119_InitComm;

END_VAR


		TON_Reconnect(IN := TRUE,PT := T#4s);

		IF TON_Reconnect.Q 	THEN
			CASE STATE OF
				10: STATE:=20;
				20:	STATE:=30;
				30:	STATE:=10;
			ELSE
				STATE:=10;
			END_CASE;
		END_IF;

		IF NOT RTU_RUN AND RTUProtocol_ON AND STATE = 10 AND TON_Reconnect.Q THEN
			InitCommunication(ENABLE:=TRUE,Interface:='RTU');	(*inizializza comunicazione	*)
			IF InitCommunication.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK2_RTU'));		(* partenza task RTU*)										
				InitCommunication(ENABLE:=FALSE);
				STATE:=20;
				RTU_RUN:=TRUE;	
				TON_Reconnect(In:=FALSE);
			ELSIF InitCommunication.ERR THEN
				TON_Reconnect(In:=FALSE);
				InitCommunication(ENABLE:=FALSE);
				RTU_RUN:=FALSE;	
				STATE:=20;
			END_IF;
		ELSIF NOT TCP_RUN AND TCPProtocol_ON AND STATE = 20 AND TON_Reconnect.Q 	THEN	
			InitCommunication(ENABLE:=TRUE,Interface:='TCP');	(*inizializza comunicazione	*)
			IF InitCommunication.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK3_TCP'));		(* partenza task TCP*)										
				InitCommunication(ENABLE:=FALSE);
				STATE:=30;
				TCP_RUN:=TRUE;	
				TON_Reconnect(In:=FALSE);
			ELSIF InitCommunication.ERR THEN
				TON_Reconnect(In:=FALSE);
				InitCommunication(ENABLE:=FALSE);
				TCP_RUN:=FALSE;	
				STATE:=30;
			END_IF;
		ELSIF NOT TCPRTU_RUN AND TCPRTUProtocol_ON AND STATE = 30	AND TON_Reconnect.Q 	 	THEN	
			TON_Reconnect(In:=FALSE);
			InitCommunication(ENABLE:=TRUE,Interface:='TCPRTU');	(*inizializza comunicazione	*)
			IF InitCommunication.END THEN
				FunctRes:=WORD_TO_UINT(TSK_Start('TASK4_TCPRTU'));		(* partenza task TCPRTU*)										
				InitCommunication(ENABLE:=FALSE);
				STATE:=10;
				TCPRTU_RUN:=TRUE;	
				TON_Reconnect(In:=FALSE);
			ELSIF InitCommunication.ERR THEN
				TON_Reconnect(In:=FALSE);
				InitCommunication(ENABLE:=FALSE);
				TCPRTU_RUN:=FALSE;	
				STATE:=10;

			END_IF;
		END_IF;


END_FUNCTION_BLOCK
