(*[[
]]*)
PROGRAM Fast 
#import "Crosstable.gvl"
#import "Resource1.gvl"

flip_flop_10ms := not flip_flop_10ms;

if SquareWave then
	PLC_DigOut_1 := flip_flop_10ms;
	PLC_DigOut_2 := flip_flop_100ms;
end_if;

END_PROGRAM
