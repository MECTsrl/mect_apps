(*[[
]]*)
FUNCTION_BLOCK fb_TPAC1007_LIOsync
#import "LIO_TPAC1007.gvl"
#import "TPACLocaIO.gvl"
#import "crosstable.gvl"
VAR_INPUT
END_VAR
VAR
	tmp_dig_out: BYTE;
	tmp_dig_outold:BYTE;
	tmp_dig_dir: BYTE;
	tmp_dig_dirold:BYTE;
END_VAR

IF (HardwareType AND 16#00FF0000) >= 16#1 THEN
		PLC_StatusReg:=TP1007_LIO_Revision;
		PLC_DigIn_1:=BOOL_TO_WORD(TP1007_LIO_DigIn_1);
		PLC_DigIn_2:=BOOL_TO_WORD(TP1007_LIO_DigIn_2);
		PLC_DigIn_3:=BOOL_TO_WORD(TP1007_LIO_DigIn_3);
		PLC_DigIn_4:=BOOL_TO_WORD(TP1007_LIO_DigIn_4);
		PLC_DigIn_5:=BOOL_TO_WORD(TP1007_LIO_DigIn_5);
		PLC_DigIn_6:=BOOL_TO_WORD(TP1007_LIO_DigIn_6);
		PLC_DigIn_7:=BOOL_TO_WORD(TP1007_LIO_DigIn_7);
		PLC_DigIn_8:=BOOL_TO_WORD(TP1007_LIO_DigIn_8);
		PLC_DigIn_9:=BOOL_TO_WORD(TP1007_LIO_DigIn_9);
		PLC_DigIn_10:=BOOL_TO_WORD(TP1007_LIO_DigIn_10);
		PLC_DigIn_11:=BOOL_TO_WORD(TP1007_LIO_DigIn_11);
		PLC_DigIn_12:=BOOL_TO_WORD(TP1007_LIO_DigIn_12);

		PLC_Tamb:= TP1007_LIO_Tamb;
		PLC_EncoderLo:= TP1007_LIO_EncoderLo;
		PLC_EncoderHi:= TP1007_LIO_EncoderHi;

		PLC_AnIn_1 := TP1007_LIO_AnIn_1;
		PLC_AnIn_2 := TP1007_LIO_AnIn_2;

(*SCRITTURA 1*)
		tmp_dig_dir := WORD_TO_BYTE(PLC_DigDir_1 OR SHL(PLC_DigDir_2,1) OR SHL(PLC_DigDir_3,2) OR SHL(PLC_DigDir_4,3) OR SHL(PLC_DigDir_5,4) OR SHL(PLC_DigDir_6,5) OR SHL(PLC_DigDir_7,6) OR SHL(PLC_DigDir_8,7) );
		IF tmp_dig_dir <> tmp_dig_dirold THEN
			TP1007_LIO_DigDir_1_8 := tmp_dig_dir; 
		END_IF;
		tmp_dig_dirold := tmp_dig_dir;

(*SCRITTURA 2*)
		tmp_dig_out:= WORD_TO_BYTE(PLC_DigOut_1 OR SHL(PLC_DigOut_2,1) OR SHL(PLC_DigOut_3,2) OR SHL(PLC_DigOut_4,3) OR SHL(PLC_DigOut_5,4) OR SHL(PLC_DigOut_6,5) OR SHL(PLC_DigOut_7,6) OR SHL(PLC_DigOut_8,7) );
		IF tmp_dig_out<> tmp_dig_outold THEN
			TP1007_LIO_DigOut_1_8:= tmp_dig_out; 
		END_IF;
		tmp_dig_outold:=tmp_dig_out;

(*SCRITTURA 3*)
		IF PLC_AnInConf_1 <> TP1007_LIO_AnInConf_1 THEN
			TP1007_LIO_AnInConf_1 := PLC_AnInConf_1 ;
		END_IF;
(*SCRITTURA 4*)
		IF PLC_AnInConf_2 <> TP1007_LIO_AnInConf_2 THEN
			TP1007_LIO_AnInConf_2 := PLC_AnInConf_2 ;
		END_IF;
(*SCRITTURA 5*)
		IF PLC_AnOutConf_1 <> TP1007_LIO_AnOut_Conf THEN
			TP1007_LIO_AnOut_Conf := PLC_AnOutConf_1;
		END_IF;
(*SCRITTURA 6*)
		IF PLC_AnOut_1 <> (TP1007_LIO_AnOut_1) THEN
			TP1007_LIO_AnOut_1 := PLC_AnOut_1;
		END_IF;
(*SCRITTURA 7*)
		IF PLC_EncoderReset <> TP1007_LIO_EncoderReset THEN
			TP1007_LIO_EncoderReset := PLC_EncoderReset;
		END_IF;
(*SCRITTURA 8*)
		IF PLC_EncoderEnable <> TP1007_LIO_EncoderEnable THEN
			TP1007_LIO_EncoderEnable := PLC_EncoderEnable;
		END_IF;

END_IF;
END_FUNCTION_BLOCK
