(*[[
]]*)
PROGRAM CheckOK 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
END_VAR

Alarm := not (
	OK_DigIn_A_1  and
	OK_DigIn_A_2  and
	OK_DigIn_A_3  and
	OK_DigIn_A_4  and
	OK_DigIn_A_5  and
	OK_DigIn_A_6  and
	OK_DigIn_A_7  and
	OK_DigIn_A_8  and
	OK_DigIn_A_9  and
	OK_DigIn_A_10 and
	OK_DigIn_A_11 and
	OK_DigIn_A_12 and
	OK_DigIn_A_13 and
	OK_DigIn_A_14 and
	OK_DigIn_A_15 and
	OK_DigIn_A_16 and

	OK_DigIn_B_1  and
	OK_DigIn_B_2  and
	OK_DigIn_B_3  and
	OK_DigIn_B_4  and
	OK_DigIn_B_5  and
	OK_DigIn_B_6  and
	OK_DigIn_B_7  and
	OK_DigIn_B_8  and
	OK_DigIn_B_9  and
	OK_DigIn_B_10 and
	OK_DigIn_B_11 and
	OK_DigIn_B_12 and
	OK_DigIn_B_13 and
	OK_DigIn_B_14 and
	OK_DigIn_B_15 and
	OK_DigIn_B_16 );

END_PROGRAM
