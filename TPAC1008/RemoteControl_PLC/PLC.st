(*[[
]]*)
PROGRAM PLC 
#import "crosstable.gvl"
#import "Resource1.gvl"
#import "LIO_TPAC1006.gvl"
#import "TPACLocaIO.gvl"
VAR
	FIRST_CYCLE:BOOL;
	LAST_BUTTON :UINT;
	TMP1:REAL;
	TMP2:REAL;
END_VAR;
	IF NOT FIRST_CYCLE THEN
		IF Selection > 0 THEN
(*
			ISI_S1_GRU:=4000;
			FSI_S1_GRU:=20000;
			ISI_S2_GRU:=4000;
			FSI_S2_GRU:=20000;
			ISI_S3_GRU:=4000;
			FSI_S3_GRU:=20000;
			ISI_S1_ESC:=4000;
			FSI_S1_ESC:=20000;
			ISI_S2_ESC:=4000;
			FSI_S2_ESC:=20000;
			ISI_S3_ESC:=4000;
			FSI_S3_ESC:=20000;
	
			ISL_S1_GRU:=0;
			FSL_S1_GRU:=3600;
			ISL_S2_GRU:=0;
			FSL_S2_GRU:=3600;
			ISL_S3_GRU:=-900;
			FSL_S3_GRU:=900;
			ISL_S1_ESC:=0;
			FSL_S1_ESC:=3000;
			ISL_S2_ESC:=0;
			FSL_S2_ESC:=3600;
			ISL_S3_ESC:=-900;
			FSL_S3_ESC:=900;
	*) 
			FIRST_CYCLE:=TRUE;
		END_IF;
	ELSE
		IF Selection =1 THEN
			PLC_AnInConf_1:=1;
			PLC_AnInConf_2:=1;
			PLC_AnInConf_3:=2;
			PLC_AnInConf_4:=0;
		ELSE
			PLC_AnInConf_1:=1;
			PLC_AnInConf_2:=1;
			PLC_AnInConf_3:=1;
			PLC_AnInConf_4:=0;
		END_IF;
		IF SetZ_gru1 =1 THEN
			ZERO_S1_GRU:=PLC_AnIn_1;
		END_IF;

		IF SetZ_gru2 = 1 THEN
			ZERO_S2_GRU:=PLC_AnIn_2;
		END_IF;

		IF SetZ_gru3 = 1 THEN
			ZERO_S3_GRU:=PLC_AnIn_3;
		END_IF;

		IF SetZ_esc1  = 1 THEN
			ZERO_S1_ESC:=PLC_AnIn_1;
		END_IF;

		IF SetZ_esc2  = 1 THEN
			ZERO_S2_ESC:=PLC_AnIn_2;
		END_IF;

		IF SetZ_esc3  = 1 THEN
			ZERO_S3_ESC:=PLC_AnIn_3;
		END_IF;

		IF Selection = 2 THEN
			IF Tasto1 =1 THEN
				IF LAST_BUTTON <> 1 THEN
					PLC_DigOut_1:=0;
					PLC_DigOut_2:=0;
					LAST_BUTTON:=1;
				ELSE
					PLC_DigOut_1:=1;
					PLC_DigOut_2:=0;
					PLC_DigOut_3:=0;
				END_IF;
			ELSIF Tasto2 =1 THEN
				IF LAST_BUTTON <> 2 THEN
					PLC_DigOut_1:=0;
					PLC_DigOut_2:=0;
					LAST_BUTTON:=2;
				ELSE
					PLC_DigOut_1:=0;
					PLC_DigOut_2:=1;
					PLC_DigOut_3:=1;
				END_IF;
			ELSIF Tasto3 =1 THEN
				IF LAST_BUTTON <> 3 THEN
					PLC_DigOut_4:=0;
					PLC_DigOut_5:=0;
					LAST_BUTTON:=3;
				ELSE
					PLC_DigOut_4:=1;
					PLC_DigOut_5:=0;
					PLC_DigOut_6:=0;
				END_IF;
			ELSIF Tasto4 =1 THEN
				IF LAST_BUTTON <> 4 THEN
					PLC_DigOut_4:=0;
					PLC_DigOut_5:=0;
					LAST_BUTTON:=4;
				ELSE
					PLC_DigOut_4:=0;
					PLC_DigOut_5:=1;
					PLC_DigOut_6:=1;
				END_IF;
			ELSIF Tasto5 =1 THEN
				IF LAST_BUTTON <> 5 THEN
					PLC_DigOut_7:=0;
					PLC_DigOut_8:=0;
					LAST_BUTTON:=5;
				ELSE
					PLC_DigOut_7:=1;
					PLC_DigOut_8:=0;
					PLC_DigOut_9:=0;
				END_IF;
			ELSIF Tasto6 =1 THEN
				IF LAST_BUTTON <> 6 THEN
					PLC_DigOut_7:=0;
					PLC_DigOut_8:=0;
					LAST_BUTTON:=6;
				ELSE
					PLC_DigOut_7:=0;
					PLC_DigOut_8:=1;
					PLC_DigOut_9:=1;
				END_IF;
			ELSIF Tasto1=0 AND Tasto2=0 AND Tasto3=0 AND Tasto4=0 AND Tasto5=0 AND Tasto6=0 THEN
				PLC_DigOut_1:=0;
				PLC_DigOut_2:=0;
				PLC_DigOut_4:=0;
				PLC_DigOut_5:=0;
				PLC_DigOut_7:=0;
				PLC_DigOut_8:=0;
			END_IF;

			IF(FSI_S1_ESC-ISI_S1_ESC) > 0 THEN
				TMP1:=INT_TO_REAL((ZERO_S1_ESC-ISI_S1_ESC))*int_to_real((FSL_S1_ESC-ISL_S1_ESC))/INT_TO_REAL((FSI_S1_ESC-ISI_S1_ESC))+INT_TO_REAL(ISL_S1_ESC);
				TMP2:=INT_TO_REAL((PLC_AnIn_1-ISI_S1_ESC))*int_to_real((FSL_S1_ESC-ISL_S1_ESC))/INT_TO_REAL((FSI_S1_ESC-ISI_S1_ESC))+INT_TO_REAL(ISL_S1_ESC);
				Mesaure_ESC1:=REAL_TO_INT(TMP2-TMP1);
			END_IF;
			IF(FSI_S2_ESC-ISI_S2_ESC) > 0 THEN
				TMP1:=INT_TO_REAL((ZERO_S2_ESC-ISI_S2_ESC))*int_to_real((FSL_S2_ESC-ISL_S2_ESC))/INT_TO_REAL((FSI_S2_ESC-ISI_S2_ESC))+INT_TO_REAL(ISL_S2_ESC);
				TMP2:=INT_TO_REAL((PLC_AnIn_2-ISI_S2_ESC))*int_to_real((FSL_S2_ESC-ISL_S2_ESC))/INT_TO_REAL((FSI_S2_ESC-ISI_S2_ESC))+INT_TO_REAL(ISL_S2_ESC);
				Mesaure_ESC2:=REAL_TO_INT(TMP2-TMP1);
			END_IF;
			IF(FSI_S3_ESC-ISI_S3_ESC) > 0 THEN
				TMP1:=INT_TO_REAL((ZERO_S3_ESC-ISI_S3_ESC))*int_to_real((FSL_S3_ESC-ISL_S3_ESC))/INT_TO_REAL((FSI_S3_ESC-ISI_S3_ESC))+INT_TO_REAL(ISL_S3_ESC);
				TMP2:=INT_TO_REAL((PLC_AnIn_3-ISI_S3_ESC))*int_to_real((FSL_S3_ESC-ISL_S3_ESC))/INT_TO_REAL((FSI_S3_ESC-ISI_S3_ESC))+INT_TO_REAL(ISL_S3_ESC);
				Mesaure_ESC3:=REAL_TO_INT(TMP2-TMP1);


			END_IF;

		ELSIF Selection = 1 THEN
			IF Tasto1 =1 THEN
				IF LAST_BUTTON <> 1 THEN
					PLC_DigOut_1:=0;
					PLC_DigOut_2:=0;
					LAST_BUTTON:=1;
				ELSE
					PLC_DigOut_1:=1;
					PLC_DigOut_2:=0;
				END_IF;
			ELSIF Tasto2 =1 THEN
				IF LAST_BUTTON <> 2 THEN
					PLC_DigOut_1:=0;
					PLC_DigOut_2:=0;
					LAST_BUTTON:=2;
				ELSE
					PLC_DigOut_1:=0;
					PLC_DigOut_2:=1;
				END_IF;
			ELSIF Tasto3 =1 THEN
				IF LAST_BUTTON <> 3 THEN
					PLC_DigOut_3:=0;
					PLC_DigOut_4:=0;
					LAST_BUTTON:=3;
				ELSE
					PLC_DigOut_3:=1;
					PLC_DigOut_4:=0;
				END_IF;
			ELSIF Tasto4 =1 THEN
				IF LAST_BUTTON <> 4 THEN
					PLC_DigOut_3:=0;
					PLC_DigOut_4:=0;
					LAST_BUTTON:=4;
				ELSE
					PLC_DigOut_3:=0;
					PLC_DigOut_4:=1;
				END_IF;
			ELSIF Tasto1=0 AND Tasto2=0 AND Tasto3=0 AND Tasto4=0 AND Tasto5=0 AND Tasto6=0 THEN
				PLC_DigOut_1:=0;
				PLC_DigOut_2:=0;
				PLC_DigOut_3:=0;
				PLC_DigOut_4:=0;
				PLC_DigOut_7:=0;
				PLC_DigOut_8:=0;
			END_IF;

			IF(FSI_S1_GRU-ISI_S1_GRU) > 0 THEN
				TMP1:=INT_TO_REAL((ZERO_S1_GRU-ISI_S1_GRU))*int_to_real((FSL_S1_GRU-ISL_S1_GRU))/INT_TO_REAL((FSI_S1_GRU-ISI_S1_GRU))+INT_TO_REAL(ISL_S1_GRU);
				TMP2:=INT_TO_REAL((PLC_AnIn_1-ISI_S1_GRU))*int_to_real((FSL_S1_GRU-ISL_S1_GRU))/INT_TO_REAL((FSI_S1_GRU-ISI_S1_GRU))+INT_TO_REAL(ISL_S1_GRU);
				Mesaure_gru1:=REAL_TO_INT(TMP2-TMP1);
			END_IF;
			IF(FSI_S2_GRU-ISI_S2_GRU) > 0 THEN
				TMP1:=INT_TO_REAL((ZERO_S2_GRU-ISI_S2_GRU))*int_to_real((FSL_S2_GRU-ISL_S2_GRU))/INT_TO_REAL((FSI_S2_GRU-ISI_S2_GRU))+INT_TO_REAL(ISL_S2_GRU);
				TMP2:=INT_TO_REAL((PLC_AnIn_2-ISI_S2_GRU))*int_to_real((FSL_S2_GRU-ISL_S2_GRU))/INT_TO_REAL((FSI_S2_GRU-ISI_S2_GRU))+INT_TO_REAL(ISL_S2_GRU);
				Mesaure_gru2:=REAL_TO_INT(TMP2-TMP1);
			END_IF;
			IF(FSI_S3_GRU-ISI_S3_GRU) > 0 THEN
				TMP1:=INT_TO_REAL((ZERO_S3_GRU-ISI_S3_GRU))*int_to_real((FSL_S3_GRU-ISL_S3_GRU))/INT_TO_REAL((FSI_S3_GRU-ISI_S3_GRU))+INT_TO_REAL(ISL_S3_GRU);
				TMP2:=INT_TO_REAL((PLC_AnIn_3-ISI_S3_GRU))*int_to_real((FSL_S3_GRU-ISL_S3_GRU))/INT_TO_REAL((FSI_S3_GRU-ISI_S3_GRU))+INT_TO_REAL(ISL_S3_GRU);
				Mesaure_gru3:=REAL_TO_INT(TMP2-TMP1);
			END_IF;


		END_IF;
		IF manual = 0 THEN
			IF Selection=1 THEN
				
		;
				
			ELSIF Selection=2 THEN
		
		;
		
			END_IF;

			
		END_IF;
	END_IF;
END_PROGRAM
