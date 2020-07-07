(*[[
]]*)
RESOURCE Resource1
    #IMPORT "Crosstable.gvl"
    #IMPORT "Resource1.gvl"
        TASK Task00_TestInit           (EVENT:='4,12', PRIORITY:=0, AUTOSTART:=TRUE);
        TASK Task01_TestManager        (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=TRUE);
        TASK Task02_TestMonitor        (INTERVAL:=T#1000ms, PRIORITY:=5, AUTOSTART:=TRUE);

        TASK Task03_ATCM_File        (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task04_ATCM_IEC1131_3_A (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task05_ATCM_IEC1131_3_B (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task06_ATCM_IEC1131_3_C (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task07_ATCM_IEC1131_3_D (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task08_ATCM_IEC1131_3_E (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task09_ATCM_IEC1131_3_F (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task10_ATCM_IEC1131_3_G (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task11_ATCM_IEC1131_3_H (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task12_ATCM_IEC1131_3_I (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task13_ATCM_IEC1131_3_J (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task14_ATCM_IEC1131_3_K (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task15_ATCM_IEC1131_3_L (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task16_ATCM_IEC1131_3_M (INTERVAL:=T#100ms, PRIORITY:=3, AUTOSTART:=FALSE); (* <---= higher priority *)
        TASK Task17_ATCM_System      (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task18_ATCM_System2     (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);
        TASK Task19_ATCM_Utility     (INTERVAL:=T#100ms, PRIORITY:=4, AUTOSTART:=FALSE);

       
        PROGRAM Init WITH  Task00_TestInit: xx_TestInit;
        PROGRAM TestManager WITH  Task01_TestManager: xx_TestManager;
        PROGRAM TestMonitor WITH  Task02_TestMonitor: xx_TestMonitor;

        PROGRAM xx_no_test_P1 WITH  Task03_ATCM_File: xx_no_test_P;

        PROGRAM bool_to_all_P WITH  Task04_ATCM_IEC1131_3_A: bool_to_all_P;
        PROGRAM byte_to_all_P WITH  Task04_ATCM_IEC1131_3_A: byte_to_all_P;
        PROGRAM dint_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: dint_to_all_P;
        PROGRAM dword_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: dword_to_all_P;
        PROGRAM int_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: int_to_all_P;
        PROGRAM lreal_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: lreal_to_all_P;
        PROGRAM real_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: real_to_all_P;
        PROGRAM string_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: string_to_all_P;
        PROGRAM time_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: time_to_all_P;
        PROGRAM trunc_P WITH  Task04_ATCM_IEC1131_3_A: trunc_P;
        PROGRAM udint_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: udint_to_all_P;
        PROGRAM uint_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: uint_to_all_P;
        PROGRAM word_to_all_P_Inst1 WITH  Task04_ATCM_IEC1131_3_A: word_to_all_P;

        PROGRAM abs_P WITH  Task05_ATCM_IEC1131_3_B: abs_P;
        PROGRAM trig_P WITH  Task05_ATCM_IEC1131_3_B: trig_P;
        PROGRAM trig_inv_P WITH  Task05_ATCM_IEC1131_3_B: trig_inv_P;
        PROGRAM pow_P WITH  Task05_ATCM_IEC1131_3_B: pow_P;

        PROGRAM add_P WITH  Task06_ATCM_IEC1131_3_C: add_P;
        PROGRAM div_P WITH  Task06_ATCM_IEC1131_3_C: div_P;
        PROGRAM expt_P WITH  Task06_ATCM_IEC1131_3_C: expt_P;
        PROGRAM mod_P WITH  Task06_ATCM_IEC1131_3_C: mod_P;
        PROGRAM move_P WITH  Task06_ATCM_IEC1131_3_C: move_P;
        PROGRAM mul_P WITH  Task06_ATCM_IEC1131_3_C: mul_P;
        PROGRAM sub_P WITH  Task06_ATCM_IEC1131_3_C: sub_P;

        PROGRAM ro_P WITH  Task07_ATCM_IEC1131_3_D: ro_P;
        PROGRAM sh_P WITH  Task07_ATCM_IEC1131_3_D: sh_P;

        PROGRAM and_P WITH  Task08_ATCM_IEC1131_3_E: and_P;
        PROGRAM not_P WITH  Task08_ATCM_IEC1131_3_E: not_P;
        PROGRAM or_P WITH  Task08_ATCM_IEC1131_3_E: or_P;
        PROGRAM xor_P WITH  Task08_ATCM_IEC1131_3_E: xor_P;

        PROGRAM limit_P WITH  Task09_ATCM_IEC1131_3_F: limit_P;
        PROGRAM max_P WITH  Task09_ATCM_IEC1131_3_F: max_P;
        PROGRAM min_P WITH  Task09_ATCM_IEC1131_3_F: min_P;
        PROGRAM mux_P WITH  Task09_ATCM_IEC1131_3_F: mux_P;
        PROGRAM sel_P WITH  Task09_ATCM_IEC1131_3_F: sel_P;

        PROGRAM eq_P WITH  Task10_ATCM_IEC1131_3_G: eq_P;
        PROGRAM ge_P WITH  Task10_ATCM_IEC1131_3_G: ge_P;
        PROGRAM gt_P WITH  Task10_ATCM_IEC1131_3_G: gt_P;
        PROGRAM le_P WITH  Task10_ATCM_IEC1131_3_G: le_P;
        PROGRAM lt_P WITH  Task10_ATCM_IEC1131_3_G: lt_P;
        PROGRAM ne_P WITH  Task10_ATCM_IEC1131_3_G: ne_P;

        PROGRAM concat_P WITH  Task11_ATCM_IEC1131_3_H: concat_P;
        PROGRAM delete_P WITH  Task11_ATCM_IEC1131_3_H: delete_P;
        PROGRAM find_P WITH  Task11_ATCM_IEC1131_3_H: find_P;
        PROGRAM insert_P WITH  Task11_ATCM_IEC1131_3_H: insert_P;
        PROGRAM left_right_P WITH  Task11_ATCM_IEC1131_3_H: left_right_P;
        PROGRAM len_P WITH  Task11_ATCM_IEC1131_3_H: len_P;
        PROGRAM mid_P WITH  Task11_ATCM_IEC1131_3_H: mid_P;
        PROGRAM replace_P WITH  Task11_ATCM_IEC1131_3_H: replace_P;

        PROGRAM add_sub_time_P WITH  Task12_ATCM_IEC1131_3_I: add_sub_time_P;
        PROGRAM div_mul_time_P WITH  Task12_ATCM_IEC1131_3_I: div_mul_time_P;

        PROGRAM rs_sr_P WITH  Task13_ATCM_IEC1131_3_J: rs_sr_P;

        PROGRAM f_r_trig_P WITH  Task14_ATCM_IEC1131_3_K: f_r_trig_P;

        PROGRAM ct_P WITH  Task15_ATCM_IEC1131_3_L: ct_P;

        PROGRAM tof_ton_tp_P WITH  Task16_ATCM_IEC1131_3_M: tof_ton_tp_P;

        PROGRAM xx_no_test_P2 WITH  Task18_ATCM_System2: xx_no_test_P;

        PROGRAM xx_no_test_P3 WITH  Task17_ATCM_System: xx_no_test_P;

        PROGRAM byte_swap_P WITH  Task19_ATCM_Utility: byte_swap_P;
        PROGRAM copy_byte_array_P WITH  Task19_ATCM_Utility: copy_byte_array_P;
        PROGRAM hi_byte_P WITH  Task19_ATCM_Utility: hi_byte_P;
        PROGRAM make_word_P WITH  Task19_ATCM_Utility: make_word_P;

        
END_RESOURCE

