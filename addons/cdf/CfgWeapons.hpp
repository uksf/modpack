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

    class CUP_arifle_M4A1_MOE_winter;
    class GVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS) : CUP_arifle_M4A1_MOE_winter {
        displayName = "M16A4 (Grip)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_HensoldtZO_RDS";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_Flashlight";
            };
        };
    };
    class CUP_arifle_M4A1_BUIS_GL;
    class GVAR(CUP_arifle_M4A1_BUIS_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS) : CUP_arifle_M4A1_BUIS_GL {
        displayName = "M16A4GL";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_HensoldtZO_RDS";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_Flashlight";
            };
        };
    };
    class LMG_Zafir_F;
    class GVAR(LMG_Zafir_F_CUP_optic_HensoldtZO_RDS) : LMG_Zafir_F {
        displayName = "Negev";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_HensoldtZO_RDS";
            };
        };
    };
    class CUP_srifle_M14_DMR;
    class GVAR(CUP_srifle_M14_DMR_CUP_optic_HensoldtZO_RDS) : CUP_srifle_M14_DMR {
        displayName = "M14";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_HensoldtZO_RDS";
            };
        };
    };
    class CUP_srifle_G22_blk;
    class GVAR(CUP_srifle_G22_blk_ACE_optic_LRPS_2D) : CUP_srifle_G22_blk {
        displayName = "G22";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_LRPS_2D";
            };
        };
    };
    class CUP_arifle_HK_M27_VFG;
    class GVAR(CUP_arifle_HK_M27_VFG_CUP_optic_HensoldtZO_RDS_muzzle_snds_M) : CUP_arifle_HK_M27_VFG {
        displayName = "M27 IAR";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_HensoldtZO_RDS";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_M";
            };
        };
    };
};
