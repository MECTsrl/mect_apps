(*[[
]]*)
FUNCTION StopTest
#import "Crosstable.gvl"
#import "Resource1.gvl"

	StopLocalTask('Task03_ATCM_File');
	StopLocalTask('Task04_ATCM_IEC1131_3_A');
	StopLocalTask('Task05_ATCM_IEC1131_3_B');
	StopLocalTask('Task06_ATCM_IEC1131_3_C');
	StopLocalTask('Task07_ATCM_IEC1131_3_D');
	StopLocalTask('Task08_ATCM_IEC1131_3_E');
	StopLocalTask('Task09_ATCM_IEC1131_3_F');
	StopLocalTask('Task10_ATCM_IEC1131_3_G');
	StopLocalTask('Task11_ATCM_IEC1131_3_H');
	StopLocalTask('Task12_ATCM_IEC1131_3_I');
	StopLocalTask('Task13_ATCM_IEC1131_3_J');
	StopLocalTask('Task14_ATCM_IEC1131_3_K');
	StopLocalTask('Task15_ATCM_IEC1131_3_L');
	StopLocalTask('Task16_ATCM_IEC1131_3_M');
	StopLocalTask('Task17_ATCM_System');
	StopLocalTask('Task18_ATCM_System2');
	StopLocalTask('Task19_ATCM_Utility');
	
	if LogLevel > LOG_NOTHING then 
		if not F_SYNC_CLOSEFILE(log_file) then
			(* FIXME: report error *);
		end_if;
	end_if;

END_FUNCTION
