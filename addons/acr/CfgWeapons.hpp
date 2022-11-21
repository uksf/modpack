class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons {
    class U_BasicBody;
    class UniformItem;
    class GVAR(U_Base) : U_BasicBody {
        author = "UKSF";
        scope = 1;
        displayName = "$STR_A3_Underwear1";
        picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
        class ItemInfo : UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(Soldier_Underwear);
            containerClass = "Supply0";
            mass = 5;
        };
    };

    class CUP_arifle_ACRC_blk_556;
    class GVAR(CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D) : CUP_arifle_ACRC_blk_556 {
        displayName = "ACR-C (Black, 5.56x45)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_Flashlight";
            };
        };
    };
    class CUP_arifle_ACRC_EGLM_blk_556;
    class GVAR(CUP_arifle_ACRC_EGLM_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D) : CUP_arifle_ACRC_EGLM_blk_556 {
        displayName = "ACR-C EGLM (Black, 5.56x45)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_Flashlight";
            };
        };
    };
    class LMG_03_F;
    class GVAR(LMG_03_F_CUP_acc_FlashlightACE_optic_MRCO_2D) : LMG_03_F {
        displayName = "FN Minimi SPW";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_Flashlight";
            };
        };
    };
    class CUP_srifle_SVD_wdl;
    class GVAR(CUP_srifle_SVD_wdl_CUP_optic_PSO_1_1_open) : CUP_srifle_SVD_wdl {
        displayName = "SVD (woodland)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_PSO_1_1_open";
            };
        };
    };
    class GVAR(CUP_arifle_ACRC_blk_556_ACE_optic_MRCO_2D) : CUP_arifle_ACRC_blk_556 {
        displayName = "ACR-C (Black, 5.56x45)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
        };
    };
    class CUP_srifle_M2010_blk;
    class GVAR(CUP_srifle_M2010_blk_ACE_optic_LRPS_2D) : CUP_srifle_M2010_blk {
        displayName = "M2010 (Black)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ace_optic_lrps_2d";
            };
        };
    };
    class CUP_lmg_MG3_rail;
    class GVAR(CUP_lmg_MG3_rail_ACE_optic_MRCO_2D) : CUP_lmg_MG3_rail {
        displayName = "MG3 (RIS)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
        };
    };
    class CUP_arifle_HK416_Black;
    class GVAR(CUP_arifle_HK416_Black_ZO_Low_anpeq) : CUP_arifle_HK416_Black {
        displayName = "HK416";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_hensoldtzo_low";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "cup_acc_anpeq_15_black";
            };
        };
    };
};
