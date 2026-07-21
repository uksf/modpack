class CfgWeapons {
    class arifle_MSBS65_F;
    class arifle_MSBS65_GL_F;
    class arifle_MSBS65_Mark_F;
    class CUP_srifle_M2010_wdl;
    class CUP_arifle_HK416_CQB_Wood;
    class CUP_arifle_HK416_CQB_M203_Wood;
    class LMG_03_F;

    // INFANTRY
    class GVAR(grot) : arifle_MSBS65_F {
        displayName = "MSBS GROT";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Arco_lush_F";
            };
        };
    };

    class GVAR(grot_gl) : arifle_MSBS65_GL_F {
        displayName = "MSBS GROT GL";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Arco_lush_F";
            };
        };
    };

    class GVAR(grot_mr) : arifle_MSBS65_Mark_F {
        displayName = "MSBS GROT MR";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Arco_AK_lush_F";
            };
        };
    };

    // SNIPER
    class GVAR(m2010) : CUP_srifle_M2010_wdl {
        displayName = "M2010";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_LeupoldMk4";
            };
        };
    };


    // SF
    class GVAR(hk416) : CUP_arifle_HK416_CQB_Wood {
        displayName = "HK416 Woodland";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_ACOG_TA31_KF_Wood";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_ANPEQ_15_OD";
            };
        };
    };


    class GVAR(hk416_gl) : CUP_arifle_HK416_CQB_M203_Wood {
        displayName = "HK416 GL Woodland";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_ACOG_TA31_KF_Wood";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_ANPEQ_15_OD";
            };
        };
    };

    class GVAR(minimi) : LMG_03_F {
        displayName = "Minimi";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_ACOG2";
            };
        };
    };
};
