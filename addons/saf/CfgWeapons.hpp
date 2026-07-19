class CfgWeapons {
    class arifle_MSBS65_F;
    class arifle_MSBS65_GL_F;
    class arifle_MSBS65_Mark_F;
    class CUP_srifle_M2010_wdl;

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


    // // SF
    // class GVAR(CUP_arifle_MG36_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed) : CUP_arifle_MG36 {
    //     displayName = "MG36 (5.56x45)";
    //     scope = 1;
    //     class LinkedItems {
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "CUP_optic_HensoldtZO_low_RDS";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "CUP_acc_ANPEQ_15_Black";
    //         };
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "CUP_muzzle_snds_G36_black";
    //         };
    //     };
    // };


    // class GVAR(CUP_arifle_G36C_VFG_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed) : CUP_arifle_G36C_VFG {
    //     displayName = "G36C VFG (Suppressed)";
    //     scope = 1;
    //     class LinkedItems {
    //         class LinkedItemsOptic {
    //             slot = "CowsSlot";
    //             item = "CUP_optic_HensoldtZO_low_RDS";
    //         };
    //         class LinkedItemsAcc {
    //             slot = "PointerSlot";
    //             item = "CUP_acc_ANPEQ_15_Black";
    //         };
    //         class LinkedItemsMuzzle {
    //             slot = "MuzzleSlot";
    //             item = "CUP_muzzle_snds_G36_black";
    //         };
    //     };
    // };
};
