class CfgWeapons {
    class U_BasicBody;
    class UniformItem;
    class PROR_U_Base : U_BasicBody {
        author = "UKSF";
        scope = 1;
        displayName = "$STR_A3_Underwear1";
        picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
        class ItemInfo : UniformItem {
            uniformModel = "-";
            uniformClass = "PROR_Soldier_Underwear";
            containerClass = "Supply0";
            mass = 5;
        };
    };

    class arifle_CTAR_blk_F;
    class arifle_CTAR_blk_F_aco_grn : arifle_CTAR_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_aco_grn";
            };
        };
    };
    class arifle_CTAR_GL_blk_F;
    class arifle_CTAR_GL_blk_F_aco_grn : arifle_CTAR_GL_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_aco_grn";
            };
        };
    };
    class arifle_CTARS_blk_F;
    class arifle_CTARS_blk_F_aimpoint : arifle_CTARS_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_compm4";
            };
        };
    };
    class srifle_DMR_06_olive_F;
    class srifle_DMR_06_olive_F_khs : srifle_DMR_06_olive_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_khs_old";
            };
        };
    };
    class mmg_02_black_f;
    class mmg_02_black_f_sig_bravo4 : mmg_02_black_f {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_erco_blk_f";
            };
        };
    };
    class SMA_MK18MOE;
    class SMA_MK18MOEOD_CCO_LLCTop_blk : SMA_MK18MOE {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_SMAAssault";
                item = "cup_optic_compm2_black";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "SMA_SFPEQ_MK18TOP_BLK";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "sma_gemtech_one_wdl";
            };
        };
    };
    class SMA_MK18OD_GL;
    class SMA_MK18OD_GL_CCO_LLCTop_blk : SMA_MK18OD_GL {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_SMAAssault";
                item = "cup_optic_compm2_black";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "SMA_SFPEQ_MK18TOP_BLK";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "sma_gemtech_one_wdl";
            };
        };
    };
    class CUP_lmg_m249_SQuantoon;
    class CUP_lmg_m249_SQuantoon_LDS : CUP_lmg_m249_SQuantoon {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "uk3cb_baf_specterlds_dot_3d";
            };
        };
    };
    class SMA_HK417_16in;
    class SMA_HK417_16in_ACOG : SMA_HK417_16in {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_SMAAssault";
                item = "uk3cb_baf_ta648";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "sma_supp_762";
            };
        };
    };
    class srifle_LRR_tna_F;
    class srifle_LRR_tna_F_NXS : srifle_LRR_tna_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_lrps_tna_f";
            };
        };
    };
};
