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

    class CUP_arifle_M16A4_GL;
    class GVAR(CUP_arifle_M16A4_GL_SSQN_AR_ACOG) : CUP_arifle_M16A4_GL {
        displayName = "M16A4 M203";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM16";
                item = "ssqn_ar_acog";
            };
        };
    };

    class CUP_arifle_M16A4_Base;
    class GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG2) : CUP_arifle_M16A4_Base {
        displayName = "M16A4";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM16";
                item = "cup_optic_acog2";
            };
        };
    };

    class GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black) : CUP_arifle_M16A4_Base {
        displayName = "M16A4";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM16";
                item = "CUP_optic_ACOG_TA01B_Black";
            };
        };
    };

    class CUP_arifle_Colt727_M203;
    class GVAR(CUP_arifle_Colt727_M203_CUP_optic_ACOG_TA01B_RMR_Black) : CUP_arifle_Colt727_M203 {
        displayName = "M16A2 Carbine M203";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM16";
                item = "CUP_optic_ACOG_TA01B_RMR_Black";
            };
        };
    };

    class CUP_arifle_Colt727;
    class GVAR(CUP_arifle_Colt727) : CUP_arifle_Colt727 {
        displayName = "M16A2 Carbine";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM16";
                item = "CUP_optic_ACOG_TA01B_RMR_Black";
            };
        };
    };

    class LMG_Mk200_black_F;
    class GVAR(LMG_Mk200_black_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk) : LMG_Mk200_black_F {
        displayName = "Stoner 99 LMG (Black)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_ACOG_TA01B_RMR_Black";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_02_F_blk";
            };
        };
    };

    class MMG_01_tan_F;
    class GVAR(MMG_01_tan_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk) : MMG_01_tan_F {
        displayName = "HK121 (Tan)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_ACOG_TA01B_RMR_Black";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_02_F_blk";
            };
        };
    };

    class CUP_arifle_AKMN_railed_desert;
    class GVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert) : CUP_arifle_AKMN_railed_desert {
        displayName = "AKMN (Zenitco/RIS/Desert)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountAK";
                item = "cup_optic_hensoldtzo_low_rds_desert";
            };
            class LinkedItemsMuzzle {
                slot = "CUP_EastMuzzleSlotAK";
                item = "cup_muzzle_snds_kzrzp_ak762_desert";
            };
        };
    };

    class CUP_arifle_AKS74U_railed;
    class GVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS) : CUP_arifle_AKS74U_railed {
        displayName = "AKS-74U (Zenitco/RIS)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountAK";
                item = "cup_optic_hensoldtzo_low_rds";
            };
            class LinkedItemsMuzzle {
                slot = "CUP_EastMuzzleSlotAK";
                item = "cup_muzzle_tgpa";
            };
        };
    };

    class CUP_launch_MAAWS;
    class GVAR(CUP_launch_MAAWS_CUP_optic_MAAWS_Scope) : CUP_launch_MAAWS {
        displayName = "MAAWS";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_MAAWS_Scope";
            };
        };
    };

    class CUP_arifle_RPK74M_railed;
    class GVAR(CUP_arifle_RPK74M_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS) : CUP_arifle_RPK74M_railed {
        displayName = "RPK-74M (Zenitco/RIS)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountAK";
                item = "cup_optic_hensoldtzo_low_rds";
            };
            class LinkedItemsMuzzle {
                slot = "CUP_EastMuzzleSlotAK";
                item = "cup_muzzle_tgpa";
            };
        };
    };

    class srifle_DMR_05_tan_f;
    class GVAR(srifle_DMR_05_tan_f_muzzle_snds_93mmg_tanACE_optic_LRPS_2Dbipod_02_F_arid) : srifle_DMR_05_tan_f {
        displayName = "Cyrus (Tan)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_93mmg_tan";
            };
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_LRPS_2D";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_02_F_arid";
            };
        };
    };
};
