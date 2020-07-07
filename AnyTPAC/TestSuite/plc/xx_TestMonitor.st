(*[[
]]*)
PROGRAM xx_TestMonitor 
#import "Crosstable.gvl"
#import "Resource1.gvl"
VAR
	stat  : TSK_STAT;
	retval : word;
END_VAR

	retval := TSK_GetStatistic('Task00_TestInit'        , stat);	ETMAX_Task00 := stat.ExecMax;	ETAVG_Task00 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task01_TestManager'     , stat);	ETMAX_Task01 := stat.ExecMax;	ETAVG_Task01 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task02_TestMonitor'     , stat);	ETMAX_Task02 := stat.ExecMax;	ETAVG_Task02 := stat.ExecAverage;

	retval := TSK_GetStatistic('Task03_ATCM_File'       , stat);	ETMAX_Task03 := stat.ExecMax;	ETAVG_Task03 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task04_ATCM_IEC1131_3_A', stat);	ETMAX_Task04 := stat.ExecMax;	ETAVG_Task04 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task05_ATCM_IEC1131_3_B', stat);	ETMAX_Task05 := stat.ExecMax;	ETAVG_Task05 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task06_ATCM_IEC1131_3_C', stat);	ETMAX_Task06 := stat.ExecMax;	ETAVG_Task06 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task07_ATCM_IEC1131_3_D', stat);	ETMAX_Task07 := stat.ExecMax;	ETAVG_Task07 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task08_ATCM_IEC1131_3_E', stat);	ETMAX_Task08 := stat.ExecMax;	ETAVG_Task08 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task09_ATCM_IEC1131_3_F', stat);	ETMAX_Task09 := stat.ExecMax;	ETAVG_Task09 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task10_ATCM_IEC1131_3_G', stat);	ETMAX_Task10 := stat.ExecMax;	ETAVG_Task10 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task11_ATCM_IEC1131_3_H', stat);	ETMAX_Task11 := stat.ExecMax;	ETAVG_Task11 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task12_ATCM_IEC1131_3_I', stat);	ETMAX_Task12 := stat.ExecMax;	ETAVG_Task12 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task13_ATCM_IEC1131_3_J', stat);	ETMAX_Task13 := stat.ExecMax;	ETAVG_Task13 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task14_ATCM_IEC1131_3_K', stat);	ETMAX_Task14 := stat.ExecMax;	ETAVG_Task14 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task15_ATCM_IEC1131_3_L', stat);	ETMAX_Task15 := stat.ExecMax;	ETAVG_Task15 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task16_ATCM_IEC1131_3_M', stat);	ETMAX_Task16 := stat.ExecMax;	ETAVG_Task16 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task17_ATCM_System'     , stat);	ETMAX_Task17 := stat.ExecMax;	ETAVG_Task17 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task18_ATCM_System2'    , stat);	ETMAX_Task18 := stat.ExecMax;	ETAVG_Task18 := stat.ExecAverage;
	retval := TSK_GetStatistic('Task19_ATCM_Utility'    , stat);	ETMAX_Task19 := stat.ExecMax;	ETAVG_Task19 := stat.ExecAverage;

END_PROGRAM
