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

    class R3F_Famas_G2_HG;
    class R3F_Famas_G2_HG_Aimpoint: R3F_Famas_G2_HG {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_AIMPOINT";
            };
        };
    };
    class R3F_Famas_G2_M203;
    class R3F_Famas_G2_M203_Aimpoint: R3F_Famas_G2_M203 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_AIMPOINT";
            };
        };
    };
    class arifle_SPAR_01_GL_blk_F;
    class arifle_SPAR_01_GL_blk_F_erco: arifle_SPAR_01_GL_blk_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_ERCO_blk_F";
            };
        };
    };
    class R3F_Famas_G2;
    class R3F_Famas_G2_Aimpoint: R3F_Famas_G2 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_AIMPOINT";
            };
        };
    };
    class R3F_Minimi_762;
    class R3F_Minimi_762_Aimpoint: R3F_Minimi_762 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_AIMPOINT";
            };
        };
    };
    class R3F_FRF2_DES;
    class R3F_FRF2_DES_Zeiss: R3F_FRF2_DES {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_ZEISS_DES";
            };
        };
    };
    class R3F_PGM_Hecate_II_DES;
    class R3F_PGM_Hecate_II_DES_Zeiss: R3F_PGM_Hecate_II_DES {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_ZEISS_DES";
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
    class R3F_PGM_Hecate_II_POLY;
    class R3F_PGM_Hecate_II_POLY_J10: R3F_PGM_Hecate_II_POLY {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_J10_MILDOT_DES";
            };
        };
    };
    class R3F_Famas_F1_M203;
    class R3F_Famas_F1_M203_Eotech: R3F_Famas_F1_M203 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_EOTECH";
            };
        };
    };
    class R3F_Famas_F1_HG;
    class R3F_Famas_F1_HG_Eotech: R3F_Famas_F1_HG {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_EOTECH";
            };
        };
    };

    class R3F_MP5A5;
    class R3F_MP5A5_Eotech: R3F_MP5A5 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "R3F_EOTECH";
            };
        };
    };

    class Vest_NoCamo_Base;
    class V_PlateCarrier1_rgr: Vest_NoCamo_Base {
        class ItemInfo;
    };
    class SP_Modular2_Tan: V_PlateCarrier1_rgr {
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            mass = 80;
            hiddenSelections[] = {
                "camo"
            };
            class HitpointsProtectionInfo {
                class Neck {
                    hitpointName = "HitNeck";
                    armor = 25;
                    passThrough = 0.25;
                };
                class Arms {
                    hitpointName = "HitArms";
                    armor = 25;
                    passThrough = 0.25;
                };
                class Chest {
                    hitpointName = "HitChest";
                    armor = 45;
                    passThrough = 0.1;
                };
                class Diaphragm {
                    hitpointName = "HitDiaphragm";
                    armor = 45;
                    passThrough = 0.1;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 45;
                    passThrough = 0.1;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.1;
                };
            };
        };
    };

    class SP_ECHHelmet_ATacsFG1: ItemCore {
        scope = 0;
        class ItemInfo;
    };
    class Inegal_Diablerie_Helmet: SP_ECHHelmet_ATacsFG1 {
        scope = 2;
        class ItemInfo: ItemInfo {
            mass = 50;
            modelSides[] = {0,1,2,3};
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 25;
                    passThrough = 0.1;
                };
            };
        };
    };
};