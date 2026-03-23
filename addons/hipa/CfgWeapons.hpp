class CfgWeapons {
    class CUP_arifle_G36C_VFG;
    class CUP_arifle_G36K_RIS_AG36;
    class CUP_lmg_MG3;
    class arifle_SPAR_03_blk_F;
    class srifle_DMR_02_camo_F;
    class CUP_arifle_G36C;
    class CUP_glaunch_M32;
    class CUP_arifle_MG36;

    // INFANTRY
    class GVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight) : CUP_arifle_G36C_VFG {
        displayName = "G36C VFG (5.56x45)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
        };
    };

    class GVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight_suppressed) : CUP_arifle_G36C_VFG {
        displayName = "G36C VFG (Suppressed)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "CUP_muzzle_snds_G36_black";
            };
        };
    };

    class GVAR(CUP_arifle_G36K_RIS_AG36_ACE_optic_MRCO_2D_acc_flashlight) : CUP_arifle_G36K_RIS_AG36 {
        displayName = "G36K AG36 (5.56x45)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
        };
    };

    class GVAR(arifle_SPAR_03_blk_F_optic_AMS) : arifle_SPAR_03_blk_F {
        displayName = "HK417 (7.62x51)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_AMS";
            };
        };
    };

    // SNIPER
    class GVAR(srifle_DMR_02_camo_F_optic_KHS_old) : srifle_DMR_02_camo_F {
        displayName = "Noreen (7.62x51)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_KHS_old";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_SPS_AI_G_H";
            };
        };
    };


    // SF
    class GVAR(CUP_arifle_MG36_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed) : CUP_arifle_MG36 {
        displayName = "MG36 (5.56x45)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_HensoldtZO_low_RDS";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_ANPEQ_15_Black";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "CUP_muzzle_snds_G36_black";
            };
        };
    };


    class GVAR(CUP_arifle_G36C_VFG_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed) : CUP_arifle_G36C_VFG {
        displayName = "G36C VFG (Suppressed)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_HensoldtZO_low_RDS";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_ANPEQ_15_Black";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "CUP_muzzle_snds_G36_black";
            };
        };
    };
};
