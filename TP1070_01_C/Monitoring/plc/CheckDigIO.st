(*[[
]]*)
PROGRAM CheckDigIO 
#import "Crosstable.gvl"
#import "Resource1.gvl"

if (AlarmArmed) then

	if (XX_DigOut_A_1 ) then
		if (AlarmEnabled and not XX_DigIn_A_1 ) then OK_DigIn_A_1  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_1 ) then OK_DigIn_B_1  := false; end_if;
	else
		XX_DigOut_A_1  := true;
		OK_DigIn_A_1  := true;
		OK_DigIn_B_1  := true;
	end_if;

	if (XX_DigOut_A_2 ) then
		if (AlarmEnabled and not XX_DigIn_A_2 ) then OK_DigIn_A_2  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_2 ) then OK_DigIn_B_2  := false; end_if;
	else
		XX_DigOut_A_2  := true;
		OK_DigIn_A_2  := true;
		OK_DigIn_B_2  := true;
	end_if;

	if (XX_DigOut_A_3 ) then
		if (AlarmEnabled and not XX_DigIn_A_3 ) then OK_DigIn_A_3  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_3 ) then OK_DigIn_B_3  := false; end_if;
	else
		XX_DigOut_A_3  := true;
		OK_DigIn_A_3  := true;
		OK_DigIn_B_3  := true;
	end_if;

	if (XX_DigOut_A_4 ) then
		if (AlarmEnabled and not XX_DigIn_A_4 ) then OK_DigIn_A_4  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_4 ) then OK_DigIn_B_4  := false; end_if;
	else
		XX_DigOut_A_4  := true;
		OK_DigIn_A_4  := true;
		OK_DigIn_B_4  := true;
	end_if;

	if (XX_DigOut_A_5 ) then
		if (AlarmEnabled and not XX_DigIn_A_5 ) then OK_DigIn_A_5  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_5 ) then OK_DigIn_B_5  := false; end_if;
	else
		XX_DigOut_A_5  := true;
		OK_DigIn_A_5  := true;
		OK_DigIn_B_5  := true;
	end_if;

	if (XX_DigOut_A_6 ) then
		if (AlarmEnabled and not XX_DigIn_A_6 ) then OK_DigIn_A_6  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_6 ) then OK_DigIn_B_6  := false; end_if;
	else
		XX_DigOut_A_6  := true;
		OK_DigIn_A_6  := true;
		OK_DigIn_B_6  := true;
	end_if;

	if (XX_DigOut_A_7 ) then
		if (AlarmEnabled and not XX_DigIn_A_7 ) then OK_DigIn_A_7  := false; end_if;
		(* if (AlarmEnabled and not XX_DigIn_B_7 ) then OK_DigIn_B_7  := false; end_if; *)
	else
		XX_DigOut_A_7  := true;
		OK_DigIn_A_7  := true;
		OK_DigIn_B_7  := true;
	end_if;

	if (XX_DigOut_A_8 ) then
		if (AlarmEnabled and not XX_DigIn_A_8 ) then OK_DigIn_A_8  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_8 ) then OK_DigIn_B_8  := false; end_if;
	else
		XX_DigOut_A_8  := true;
		OK_DigIn_A_8  := true;
		OK_DigIn_B_8  := true;
	end_if;

	if (XX_DigOut_A_9 ) then
		if (AlarmEnabled and not XX_DigIn_A_9 ) then OK_DigIn_A_9  := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_9 ) then OK_DigIn_B_9  := false; end_if;
	else
		XX_DigOut_A_9  := true;
		OK_DigIn_A_9  := true;
		OK_DigIn_B_9  := true;
	end_if;

	if (XX_DigOut_A_10) then
		if (AlarmEnabled and not XX_DigIn_A_10) then OK_DigIn_A_10 := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_10) then OK_DigIn_B_10 := false; end_if;
	else
		XX_DigOut_A_10 := true;
		OK_DigIn_A_10 := true;
		OK_DigIn_B_10 := true;
	end_if;

	if (XX_DigOut_A_11) then
		if (AlarmEnabled and not XX_DigIn_A_11) then OK_DigIn_A_11 := false; end_if;
		(* if (AlarmEnabled and not XX_DigIn_B_11) then OK_DigIn_B_11 := false; end_if; *)
	else
		XX_DigOut_A_11 := true;
		OK_DigIn_A_11 := true;
		OK_DigIn_B_11 := true;
	end_if;

	if (XX_DigOut_A_12) then
		if (AlarmEnabled and not XX_DigIn_A_12) then OK_DigIn_A_12 := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_12) then OK_DigIn_B_12 := false; end_if;
	else
		XX_DigOut_A_12 := true;
		OK_DigIn_A_12 := true;
		OK_DigIn_B_12 := true;
	end_if;

	if (XX_DigOut_A_13) then
		if (AlarmEnabled and not XX_DigIn_A_13) then OK_DigIn_A_13 := false; end_if;
		(* if (AlarmEnabled and not XX_DigIn_B_13) then OK_DigIn_B_13 := false; end_if; *)
	else
		XX_DigOut_A_13 := true;
		OK_DigIn_A_13 := true;
		OK_DigIn_B_13 := true;
	end_if;

	if (XX_DigOut_A_14) then
		if (AlarmEnabled and not XX_DigIn_A_14) then OK_DigIn_A_14 := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_14) then OK_DigIn_B_14 := false; end_if;
	else
		XX_DigOut_A_14 := true;
		OK_DigIn_A_14 := true;
		OK_DigIn_B_14 := true;
	end_if;

	if (XX_DigOut_A_15) then
		if (AlarmEnabled and not XX_DigIn_A_15) then OK_DigIn_A_15 := false; end_if;
		if (AlarmEnabled and not XX_DigIn_B_15) then OK_DigIn_B_15 := false; end_if;
	else
		XX_DigOut_A_15 := true;
		OK_DigIn_A_15 := true;
		OK_DigIn_B_15 := true;
	end_if;

	if (XX_DigOut_A_16) then
		if (AlarmEnabled and not XX_DigIn_A_16) then OK_DigIn_A_16 := false; end_if;
		(* if (AlarmEnabled and not XX_DigIn_B_16) then OK_DigIn_B_16 := false; end_if; *)
	else
		XX_DigOut_A_16 := true;
		OK_DigIn_A_16 := true;
		OK_DigIn_B_16 := true;
	end_if;

else

	if (XX_DigOut_A_1 ) then
		XX_DigOut_A_1  := false;
	end_if;
	OK_DigIn_A_1  := true;
	OK_DigIn_B_1  := true;

	if (XX_DigOut_A_2 ) then
		XX_DigOut_A_2  := false;
	end_if;
	OK_DigIn_A_2  := true;
	OK_DigIn_B_2  := true;

	if (XX_DigOut_A_3 ) then
		XX_DigOut_A_3  := false;
	end_if;
	OK_DigIn_A_3  := true;
	OK_DigIn_B_3  := true;

	if (XX_DigOut_A_4 ) then
		XX_DigOut_A_4  := false;
	end_if;
	OK_DigIn_A_4  := true;
	OK_DigIn_B_4  := true;

	if (XX_DigOut_A_5 ) then
		XX_DigOut_A_5  := false;
	end_if;
	OK_DigIn_A_5  := true;
	OK_DigIn_B_5  := true;

	if (XX_DigOut_A_6 ) then
		XX_DigOut_A_6  := false;
	end_if;
	OK_DigIn_A_6  := true;
	OK_DigIn_B_6  := true;

	if (XX_DigOut_A_7 ) then
		XX_DigOut_A_7  := false;
	end_if;
	OK_DigIn_A_7  := true;
	OK_DigIn_B_7  := true;

	if (XX_DigOut_A_8 ) then
		XX_DigOut_A_8  := false;
	end_if;
	OK_DigIn_A_8  := true;
	OK_DigIn_B_8  := true;

	if (XX_DigOut_A_9 ) then
		XX_DigOut_A_9  := false;
	end_if;
	OK_DigIn_A_9  := true;
	OK_DigIn_B_9  := true;

	if (XX_DigOut_A_10) then
		XX_DigOut_A_10 := false;
	end_if;
	OK_DigIn_A_10 := true;
	OK_DigIn_B_10 := true;

	if (XX_DigOut_A_11) then
		XX_DigOut_A_11 := false;
	end_if;
	OK_DigIn_A_11 := true;
	OK_DigIn_B_11 := true;

	if (XX_DigOut_A_12) then
		XX_DigOut_A_12 := false;
	end_if;
	OK_DigIn_A_12 := true;
	OK_DigIn_B_12 := true;

	if (XX_DigOut_A_13) then
		XX_DigOut_A_13 := false;
	end_if;
	OK_DigIn_A_13 := true;
	OK_DigIn_B_13 := true;

	if (XX_DigOut_A_14) then
		XX_DigOut_A_14 := false;
	end_if;
	OK_DigIn_A_14 := true;
	OK_DigIn_B_14 := true;

	if (XX_DigOut_A_15) then
		XX_DigOut_A_15 := false;
	end_if;
	OK_DigIn_A_15 := true;
	OK_DigIn_B_15 := true;

	if (XX_DigOut_A_16) then
		XX_DigOut_A_16 := false;
	end_if;
	OK_DigIn_A_16 := true;
	OK_DigIn_B_16 := true;

end_if;


END_PROGRAM
