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
    class UKSF_ACR_U_Base: U_BasicBody {
        author = "UKSF";
        scope = 1;
        displayName = "$STR_A3_Underwear1";
        picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "Inegal_Soldier_Underwear";
            containerClass = "Supply0";
            mass = 5;
        };
    };

    class CUP_arifle_ACRC_blk_556;
    class uksf_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D: CUP_arifle_ACRC_blk_556
    {
        displayName="ACR-C (Black, 5.56x45)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc
            {
                slot="PointerSlot";
                item="CUP_acc_Flashlight";
            };
        };
    };

    class CUP_arifle_ACRC_EGLM_blk_556;
    class uksf_ACR_CUP_arifle_ACRC_EGLM_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D: CUP_arifle_ACRC_EGLM_blk_556
    {
        displayName="ACR-C EGLM (Black, 5.56x45)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc
            {
                slot="PointerSlot";
                item="CUP_acc_Flashlight";
            };
        };
    };

    class LMG_03_F;
    class uksf_ACR_LMG_03_F_CUP_acc_FlashlightACE_optic_MRCO_2D: LMG_03_F
    {
        displayName="FN Minimi SPW";
        scope=1;
        class LinkedItems
            {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc
            {
                slot="PointerSlot";
                item="CUP_acc_Flashlight";
            };
        };
    };

    class CUP_launch_RPG7V;
    class uksf_ACR_CUP_launch_RPG7V: CUP_launch_RPG7V
    {
        displayName="RPG-7V2";
        scope=1;
        class LinkedItems {};
    };

    class CUP_srifle_SVD_wdl;
    class uksf_ACR_CUP_srifle_SVD_wdl_CUP_optic_PSO_1_1_open: CUP_srifle_SVD_wdl
    {
        displayName="SVD (woodland)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="CUP_optic_PSO_1_1_open";
            };
        };
    };

    class uksf_ACR_CUP_arifle_ACRC_blk_556: CUP_arifle_ACRC_blk_556
    {
        displayName="ACR-C (Black, 5.56x45)";
        scope=1;
        class LinkedItems {};
    };

    class uksf_ACR_CUP_arifle_ACRC_blk_556_ACE_optic_MRCO_2D: CUP_arifle_ACRC_blk_556
    {
        displayName="ACR-C (Black, 5.56x45)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="ACE_optic_MRCO_2D";
            };
        };
    };

    class CUP_hgun_CZ75;
    class uksf_ACR_CUP_hgun_CZ75: CUP_hgun_CZ75
    {
        displayName="CZ 75";
        scope=1;
        class LinkedItems {};
    };

    class CUP_srifle_M2010_blk;
    class uksf_ACR_CUP_srifle_M2010_blk_ACE_optic_LRPS_2D: CUP_srifle_M2010_blk
    {
        displayName="M2010 (Black)";
        scope=1;
        class LinkedItems {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="ace_optic_lrps_2d";
            };
        };
    };

    class CUP_launch_FIM92Stinger_Loaded;
    class uksf_ACR_CUP_launch_FIM92Stinger_Loaded: CUP_launch_FIM92Stinger_Loaded
    {
        displayName="FIM-92F Stinger";
        scope=1;
        class LinkedItems {};
    };

    class CUP_lmg_MG3_rail;
    class uksf_ACR_CUP_lmg_MG3_rail_ACE_optic_MRCO_2D: CUP_lmg_MG3_rail
    {
        displayName="MG3 (RIS)";
        scope=1;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="ACE_optic_MRCO_2D";
            };
        };
    };

    class launch_I_Titan_short_F;
    class uksf_ACR_launch_I_Titan_short_F: launch_I_Titan_short_F
    {
        displayName="Titan MPRL Compact (Olive)";
        scope=1;
        class LinkedItems {};
    };

    class CUP_arifle_HK416_Black;
    class UKSF_ACR_CUP_arifle_HK416_Black_ZO_Low_anpeq: CUP_arifle_HK416_Black
    {
        displayName="HK416";
        scope=1;
        class LinkedItems {
            class LinkedItemsOptic
            {
                slot="CowsSlot";
                item="cup_optic_hensoldtzo_low";
            };
            class LinkedItemsAcc
            {
                slot="PointerSlot";
                item="cup_acc_anpeq_15_black";
            };
        };
    };
};
