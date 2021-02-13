(*[[
]]*)
PROGRAM CheckDigIO 
#import "Crosstable.gvl"
#import "Resource1.gvl"

if (AlarmStatus = ALARM_STATUS_ZERO) then
    (* ... *)
	;

elsif (AlarmStatus = ALARM_STATUS_IDLE) then
	(* all ok *)

	OK_DigIn_A_1  := true; OK_DigIn_B_1  := true;
	OK_DigIn_A_2  := true; OK_DigIn_B_2  := true;
	OK_DigIn_A_3  := true; OK_DigIn_B_3  := true;
	OK_DigIn_A_4  := true; OK_DigIn_B_4  := true;
	OK_DigIn_A_5  := true; OK_DigIn_B_5  := true;
	OK_DigIn_A_6  := true; OK_DigIn_B_6  := true;
	OK_DigIn_A_7  := true; OK_DigIn_B_7  := true;
	OK_DigIn_A_8  := true; OK_DigIn_B_8  := true;
	OK_DigIn_A_9  := true; OK_DigIn_B_9  := true;
	OK_DigIn_A_10 := true; OK_DigIn_B_10 := true;
	OK_DigIn_A_11 := true; OK_DigIn_B_11 := true;
	OK_DigIn_A_12 := true; OK_DigIn_B_12 := true;
	OK_DigIn_A_13 := true; OK_DigIn_B_13 := true;
	OK_DigIn_A_14 := true; OK_DigIn_B_14 := true;
	OK_DigIn_A_15 := true; OK_DigIn_B_15 := true;
	OK_DigIn_A_16 := true; OK_DigIn_B_16 := true;

elsif (AlarmStatus = ALARM_STATUS_ARMED or AlarmStatus = ALARM_STATUS_ENABLED) then
	(* check DigIn, without memory *)

	OK_DigIn_A_1  := not AlarmArmed_A_1  or (XX_DigIn_A_1  = XX_DigOut_A_1 ); OK_DigIn_B_1  := not AlarmArmed_B_1  or (XX_DigIn_B_1  = XX_DigOut_A_1 );
	OK_DigIn_A_2  := not AlarmArmed_A_2  or (XX_DigIn_A_2  = XX_DigOut_A_2 ); OK_DigIn_B_2  := not AlarmArmed_B_2  or (XX_DigIn_B_2  = XX_DigOut_A_2 );
	OK_DigIn_A_3  := not AlarmArmed_A_3  or (XX_DigIn_A_3  = XX_DigOut_A_3 ); OK_DigIn_B_3  := not AlarmArmed_B_3  or (XX_DigIn_B_3  = XX_DigOut_A_3 );
	OK_DigIn_A_4  := not AlarmArmed_A_4  or (XX_DigIn_A_4  = XX_DigOut_A_4 ); OK_DigIn_B_4  := not AlarmArmed_B_4  or (XX_DigIn_B_4  = XX_DigOut_A_4 );
	OK_DigIn_A_5  := not AlarmArmed_A_5  or (XX_DigIn_A_5  = XX_DigOut_A_5 ); OK_DigIn_B_5  := not AlarmArmed_B_5  or (XX_DigIn_B_5  = XX_DigOut_A_5 );
	OK_DigIn_A_6  := not AlarmArmed_A_6  or (XX_DigIn_A_6  = XX_DigOut_A_6 ); OK_DigIn_B_6  := not AlarmArmed_B_6  or (XX_DigIn_B_6  = XX_DigOut_A_6 );
	OK_DigIn_A_7  := not AlarmArmed_A_7  or (XX_DigIn_A_7  = XX_DigOut_A_7 ); OK_DigIn_B_7  := not AlarmArmed_B_7  or (XX_DigIn_B_7  = XX_DigOut_A_7 );
	OK_DigIn_A_8  := not AlarmArmed_A_8  or (XX_DigIn_A_8  = XX_DigOut_A_8 ); OK_DigIn_B_8  := not AlarmArmed_B_8  or (XX_DigIn_B_8  = XX_DigOut_A_8 );
	OK_DigIn_A_9  := not AlarmArmed_A_9  or (XX_DigIn_A_9  = XX_DigOut_A_9 ); OK_DigIn_B_9  := not AlarmArmed_B_9  or (XX_DigIn_B_9  = XX_DigOut_A_9 );
	OK_DigIn_A_10 := not AlarmArmed_A_10 or (XX_DigIn_A_10 = XX_DigOut_A_10); OK_DigIn_B_10 := not AlarmArmed_B_10 or (XX_DigIn_B_10 = XX_DigOut_A_10);
	OK_DigIn_A_11 := not AlarmArmed_A_11 or (XX_DigIn_A_11 = XX_DigOut_A_11); OK_DigIn_B_11 := not AlarmArmed_B_11 or (XX_DigIn_B_11 = XX_DigOut_A_11);
	OK_DigIn_A_12 := not AlarmArmed_A_12 or (XX_DigIn_A_12 = XX_DigOut_A_12); OK_DigIn_B_12 := not AlarmArmed_B_12 or (XX_DigIn_B_12 = XX_DigOut_A_12);
	OK_DigIn_A_13 := not AlarmArmed_A_13 or (XX_DigIn_A_13 = XX_DigOut_A_13); OK_DigIn_B_13 := not AlarmArmed_B_13 or (XX_DigIn_B_13 = XX_DigOut_A_13);
	OK_DigIn_A_14 := not AlarmArmed_A_14 or (XX_DigIn_A_14 = XX_DigOut_A_14); OK_DigIn_B_14 := not AlarmArmed_B_14 or (XX_DigIn_B_14 = XX_DigOut_A_14);
	OK_DigIn_A_15 := not AlarmArmed_A_15 or (XX_DigIn_A_15 = XX_DigOut_A_15); OK_DigIn_B_15 := not AlarmArmed_B_15 or (XX_DigIn_B_15 = XX_DigOut_A_15);
	OK_DigIn_A_16 := not AlarmArmed_A_16 or (XX_DigIn_A_16 = XX_DigOut_A_16); OK_DigIn_B_16 := not AlarmArmed_B_16 or (XX_DigIn_B_16 = XX_DigOut_A_16);

elsif (AlarmStatus = ALARM_STATUS_RINGING or AlarmStatus = ALARM_STATUS_MUTED) then
	(* check DigIn, with memory *)

        OK_DigIn_A_1  := OK_DigIn_A_1  and (not AlarmArmed_A_1  or (XX_DigIn_A_1  = XX_DigOut_A_1 )); OK_DigIn_B_1  := OK_DigIn_B_1  and (not AlarmArmed_B_1  or (XX_DigIn_B_1  = XX_DigOut_A_1 ));
        OK_DigIn_A_2  := OK_DigIn_A_2  and (not AlarmArmed_A_2  or (XX_DigIn_A_2  = XX_DigOut_A_2 )); OK_DigIn_B_2  := OK_DigIn_B_2  and (not AlarmArmed_B_2  or (XX_DigIn_B_2  = XX_DigOut_A_2 ));
        OK_DigIn_A_3  := OK_DigIn_A_3  and (not AlarmArmed_A_3  or (XX_DigIn_A_3  = XX_DigOut_A_3 )); OK_DigIn_B_3  := OK_DigIn_B_3  and (not AlarmArmed_B_3  or (XX_DigIn_B_3  = XX_DigOut_A_3 ));
        OK_DigIn_A_4  := OK_DigIn_A_4  and (not AlarmArmed_A_4  or (XX_DigIn_A_4  = XX_DigOut_A_4 )); OK_DigIn_B_4  := OK_DigIn_B_4  and (not AlarmArmed_B_4  or (XX_DigIn_B_4  = XX_DigOut_A_4 ));
        OK_DigIn_A_5  := OK_DigIn_A_5  and (not AlarmArmed_A_5  or (XX_DigIn_A_5  = XX_DigOut_A_5 )); OK_DigIn_B_5  := OK_DigIn_B_5  and (not AlarmArmed_B_5  or (XX_DigIn_B_5  = XX_DigOut_A_5 ));
        OK_DigIn_A_6  := OK_DigIn_A_6  and (not AlarmArmed_A_6  or (XX_DigIn_A_6  = XX_DigOut_A_6 )); OK_DigIn_B_6  := OK_DigIn_B_6  and (not AlarmArmed_B_6  or (XX_DigIn_B_6  = XX_DigOut_A_6 ));
        OK_DigIn_A_7  := OK_DigIn_A_7  and (not AlarmArmed_A_7  or (XX_DigIn_A_7  = XX_DigOut_A_7 )); OK_DigIn_B_7  := OK_DigIn_B_7  and (not AlarmArmed_B_7  or (XX_DigIn_B_7  = XX_DigOut_A_7 ));
        OK_DigIn_A_8  := OK_DigIn_A_8  and (not AlarmArmed_A_8  or (XX_DigIn_A_8  = XX_DigOut_A_8 )); OK_DigIn_B_8  := OK_DigIn_B_8  and (not AlarmArmed_B_8  or (XX_DigIn_B_8  = XX_DigOut_A_8 ));
        OK_DigIn_A_9  := OK_DigIn_A_9  and (not AlarmArmed_A_9  or (XX_DigIn_A_9  = XX_DigOut_A_9 )); OK_DigIn_B_9  := OK_DigIn_B_9  and (not AlarmArmed_B_9  or (XX_DigIn_B_9  = XX_DigOut_A_9 ));
        OK_DigIn_A_10 := OK_DigIn_A_10 and (not AlarmArmed_A_10 or (XX_DigIn_A_10 = XX_DigOut_A_10)); OK_DigIn_B_10 := OK_DigIn_B_10 and (not AlarmArmed_B_10 or (XX_DigIn_B_10 = XX_DigOut_A_10));
        OK_DigIn_A_11 := OK_DigIn_A_11 and (not AlarmArmed_A_11 or (XX_DigIn_A_11 = XX_DigOut_A_11)); OK_DigIn_B_11 := OK_DigIn_B_11 and (not AlarmArmed_B_11 or (XX_DigIn_B_11 = XX_DigOut_A_11));
        OK_DigIn_A_12 := OK_DigIn_A_12 and (not AlarmArmed_A_12 or (XX_DigIn_A_12 = XX_DigOut_A_12)); OK_DigIn_B_12 := OK_DigIn_B_12 and (not AlarmArmed_B_12 or (XX_DigIn_B_12 = XX_DigOut_A_12));
        OK_DigIn_A_13 := OK_DigIn_A_13 and (not AlarmArmed_A_13 or (XX_DigIn_A_13 = XX_DigOut_A_13)); OK_DigIn_B_13 := OK_DigIn_B_13 and (not AlarmArmed_B_13 or (XX_DigIn_B_13 = XX_DigOut_A_13));
        OK_DigIn_A_14 := OK_DigIn_A_14 and (not AlarmArmed_A_14 or (XX_DigIn_A_14 = XX_DigOut_A_14)); OK_DigIn_B_14 := OK_DigIn_B_14 and (not AlarmArmed_B_14 or (XX_DigIn_B_14 = XX_DigOut_A_14));
        OK_DigIn_A_15 := OK_DigIn_A_15 and (not AlarmArmed_A_15 or (XX_DigIn_A_15 = XX_DigOut_A_15)); OK_DigIn_B_15 := OK_DigIn_B_15 and (not AlarmArmed_B_15 or (XX_DigIn_B_15 = XX_DigOut_A_15));
        OK_DigIn_A_16 := OK_DigIn_A_16 and (not AlarmArmed_A_16 or (XX_DigIn_A_16 = XX_DigOut_A_16)); OK_DigIn_B_16 := OK_DigIn_B_16 and (not AlarmArmed_B_16 or (XX_DigIn_B_16 = XX_DigOut_A_16));

else
	;

end_if;

END_PROGRAM
