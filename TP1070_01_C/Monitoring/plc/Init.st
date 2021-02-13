(*[[
]]*)
PROGRAM Init
#import "Crosstable.gvl"
#import "Resource1.gvl"

	AlarmStatus := ALARM_STATUS_ZERO; (* vedi hmi/page300 *)
	XX_WatchDog := 1; (* MPNC DigOut watchdog 1 s (see also hmi/automation.cpp:setup() *)

END_PROGRAM

