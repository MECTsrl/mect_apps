(*[[
]]*)
FUNCTION StartTest
#import "Crosstable.gvl"
#import "Resource1.gvl"

	if LogLevel > LOG_NOTHING then 
		log_file.filename := concat(
			'/local/root/TestSuite_',
			time_to_string(getTimeSinceSystemBoot()),
			'.csv');
		log_file.mode := CF_READ_WRITE;
		if not F_SYNC_OPENFILE(log_file) then
			(* FIXME: report error *);
		end_if;
	end_if;

	StartLocalTask('Task03_ATCM_File');
	StartLocalTask('Task04_ATCM_IEC1131_3_A');
	StartLocalTask('Task05_ATCM_IEC1131_3_B');
	StartLocalTask('Task06_ATCM_IEC1131_3_C');
	StartLocalTask('Task07_ATCM_IEC1131_3_D');
	StartLocalTask('Task08_ATCM_IEC1131_3_E');
	StartLocalTask('Task09_ATCM_IEC1131_3_F');
	StartLocalTask('Task10_ATCM_IEC1131_3_G');
	StartLocalTask('Task11_ATCM_IEC1131_3_H');
	StartLocalTask('Task12_ATCM_IEC1131_3_I');
	StartLocalTask('Task13_ATCM_IEC1131_3_J');
	StartLocalTask('Task14_ATCM_IEC1131_3_K');
	StartLocalTask('Task15_ATCM_IEC1131_3_L');
	StartLocalTask('Task16_ATCM_IEC1131_3_M');
	StartLocalTask('Task17_ATCM_System');
	StartLocalTask('Task18_ATCM_System2');
	StartLocalTask('Task19_ATCM_Utility');

END_FUNCTION
