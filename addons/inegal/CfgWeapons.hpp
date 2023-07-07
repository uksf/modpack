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
    class Inegal_U_Base: U_BasicBody {
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

    class CUP_arifle_Mk16_STD_FG_black;
    class CUP_arifle_Mk16_STD_FG_black_Aimpoint: CUP_arifle_Mk16_STD_FG_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountSCAR";
                item = "CUP_optic_CompM2_Black";
            };
        };
    };
    class CUP_arifle_Mk16_STD_EGLM_black;
    class CUP_arifle_Mk16_STD_EGLM_black_Aimpoint: CUP_arifle_Mk16_STD_EGLM_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountSCAR";
                item = "CUP_optic_CompM2_Black";
            };
        };
    };
    class CUP_arifle_Mk16_CQC_EGLM_black;
    class CUP_arifle_Mk16_CQC_EGLM_black_Aimpoint: CUP_arifle_Mk16_CQC_EGLM_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountSCAR";
                item = "CUP_optic_CompM2_Black";
            };
        };
    };
    class CUP_arifle_Mk16_STD_black;
    class CUP_arifle_Mk16_STD_black_Aimpoint: CUP_arifle_Mk16_STD_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountSCAR";
                item = "CUP_optic_CompM2_Black";
            };
        };
    };
    class CUP_lmg_Mk48_des;
    class CUP_lmg_Mk48_des_Aimpoint: CUP_lmg_Mk48_des {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountMk48";
                item = "CUP_optic_CompM2_Desert";
            };
        };
    };
    class CUP_srifle_M110;
    class CUP_srifle_M110_Leupold: CUP_srifle_M110 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM110";
                item = "CUP_optic_LeupoldMk4_MRT_tan";
            };
            class LinkedItemsAcc {
                slot = "CUP_PicatinnySideMountM110";
                item = "CUP_acc_ANPEQ_15";
            };
            class LinkedItemsUnder {
                slot = "CUP_PicatinnyUnderMountM110";
                item = "CUP_bipod_VLTOR_Modpod";
            };
        };
    };
    class srifle_DMR_02_F;
    class srifle_DMR_02_F_PMII: srifle_DMR_02_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "RKSL_optic_PMII_312";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };
    class arifle_SPAR_01_blk_F;
    class arifle_SPAR_01_blk_F_eotech_lamp_bipod: arifle_SPAR_01_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "UK3CB_BAF_Eotech";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };
    class arifle_SPAR_01_GL_blk_F;
    class arifle_SPAR_01_GL_blk_F_eotech: arifle_SPAR_01_GL_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "UK3CB_BAF_Eotech";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
        };
    };
    class arifle_SPAR_03_blk_F;
    class arifle_SPAR_03_blk_F_dms_bipod: arifle_SPAR_03_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_DMS";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };
    class arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor: arifle_SPAR_01_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_ERCO_blk_F";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_M";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };
    class arifle_SPAR_01_GL_blk_F_erco_laser_suppressor: arifle_SPAR_01_GL_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_ERCO_blk_F";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_M";
            };
        };
    };
    class arifle_SPAR_03_blk_F_dms_bipod_suppressor_laser: arifle_SPAR_03_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_DMS";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_pointer_IR";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_B";
            };
            class LinkedItemsUnder {
                slot = "UnderBarrelSlot";
                item = "bipod_01_F_blk";
            };
        };
    };
    class CUP_srifle_M107_Base;
    class CUP_srifle_M107_Base_PMII: CUP_srifle_M107_Base {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM107";
                item = "RKSL_optic_PMII_525";
            };
        };
    };
    class CUP_arifle_Mk16_CQC_EGLM_black_Eotech: CUP_arifle_Mk16_CQC_EGLM_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountSCAR";
                item = "optic_Holosight_blk_F";
            };
        };
    };
    class CUP_arifle_Mk16_CQC_black;
    class CUP_arifle_Mk16_CQC_black_Eotech: CUP_arifle_Mk16_CQC_black {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountSCAR";
                item = "optic_Holosight_blk_F";
            };
        };
    };
    class CUP_launch_MAAWS;
    class CUP_launch_MAAWS_Scope: CUP_launch_MAAWS {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "CUP_optic_MAAWS_Scope";
            };
        };
    };

    class SMG_05_F;
    class SMG_05_F_Aco: SMG_05_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Aco";
            };
        };
    };

    class V_PlateCarrier2_rgr;
    class V_PlateCarrier2_rgr_noflag_F: V_PlateCarrier2_rgr {
        class ItemInfo;
    };
    class Inegal_Diablerie_Vest: V_PlateCarrier2_rgr_noflag_F {
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            mass = 80;
            hiddenSelections[] = { "camo" };
            class HitpointsProtectionInfo {
                class Neck {
                    hitpointName = "HitNeck";
                    armor = 15; // ..., 25, 15
                    passThrough = 0.3; // ..., 0.4, 0.3
                };
                class Arms {
                    hitpointName = "HitArms";
                    armor = 15; // ..., 25, 15
                    passThrough = 0.3; // ..., 0.4, 0.3
                };
                class Chest {
                    hitpointName = "HitChest";
                    armor = 35; // 20, 45, 35
                    passThrough = 0.15; // 0.2, 0.1, 0.15
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 35; // 20, 45, 35
                    passThrough = 0.15; // 0.2, 0.1, 0.15
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 35; // 20, 45, 35
                    passThrough = 0.15; // 0.2, 0.1, 0.15
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.15; // 0.2, 0.1, 0.15
                };
            };
        };
    };

    class H_HelmetB;
    class H_HelmetB_TI_tna_F: H_HelmetB {
        class ItemInfo;
    };
    class Inegal_Diablerie_Helmet: H_HelmetB_TI_tna_F {
        class ItemInfo: ItemInfo {
            mass = 50;
            modelSides[] = { 0, 1, 2 ,3 };
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 25; // 6, 25, 25
                    passThrough = 0.1; // 0.5, 0.1, 0.2
                };
                class Face {
                    hitpointName = "HitFace";
                    armor = 20; // 4, ..., 20
                    passThrough = 0.1; // 0.5, ..., 0.1
                };
            };
        };
    };
};
