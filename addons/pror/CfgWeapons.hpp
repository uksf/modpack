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
    class CUP_arifle_mk18_black;
    class CUP_arifle_mk18_black_acog : CUP_arifle_mk18_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountMk18";
                item = "cup_optic_acog";
            };
            class LinkedItemsAcc {
                slot = "CUP_PicatinnySideMountMk18";
                item = "cup_acc_flashlight_desert";
            };
        };
    };
    class CUP_arifle_mk18_m203_black;
    class CUP_arifle_mk18_m203_black_acog : CUP_arifle_mk18_m203_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountMk18";
                item = "cup_optic_acog";
            };
            class LinkedItemsAcc {
                slot = "CUP_PicatinnySideMountMk18";
                item = "cup_acc_flashlight_desert";
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
    class arifle_SPAR_03_blk_F;
    class arifle_SPAR_03_blk_F_leupold : arifle_SPAR_03_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_leupoldmk4_cq_t";
            };
            class LinkedItemsMuzzle {
                slot = "PointerSlot";
                item = "cup_acc_flashlight";
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
