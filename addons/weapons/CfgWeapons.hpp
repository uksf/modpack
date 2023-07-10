class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class asdg_MuzzleSlot;
class asdg_SlotInfo;
class asdg_OpticRail;
class asdg_OpticRail1913 : asdg_OpticRail {
    class compatibleItems {
        RKSL_optic_PMII_525_NV = 1;
    };
};
class asdg_FrontSideRail : asdg_SlotInfo {
    class compatibleItems {
        UK3CB_BAF_LLM_Flashlight_Far_Black = 1;
    };
};
class asdg_MuzzleSlot_556_3CB_L119 : asdg_MuzzleSlot {
    class compatibleItems {
        UK3CB_BAF_BFA_L85 = 1;
        UK3CB_BAF_SFFH = 1;
        muzzle_snds_M = 1;
    };
};
class UK3CB_MuzzleSlot_900;
class UK3CB_MuzzleSlot_900_L131 : UK3CB_MuzzleSlot_900 {
    class compatibleItems {
        muzzle_snds_L = 1;
        // rhsusf_acc_omega9k = 1; // Fix 3CB's mistakes
    };
};
class CfgWeapons {
    class ItemCore;
    class InventoryOpticsItem_Base_F;
    class UK3CB_BAF_SpecterLDS : ItemCore {
        class ItemInfo : InventoryOpticsItem_Base_F {
            class OpticsModes {
                class UK3CB_BAF_LDS {
                    visionMode[] = {};
                };
            };
        };
    };
    class UK3CB_BAF_SpecterLDS_3D : UK3CB_BAF_SpecterLDS {
        scope = 2;
        scopeCurator = 2;
        class ItemInfo : InventoryOpticsItem_Base_F {
            allowedSlots[] = { 801, 701, 901 };
            mass = 4;
            mountAction = "MountOptic";
            muzzleEnd = "konec hlavne";
            muzzlePos = "usti hlavne";
            optics = 1;
            scope = 0;
            type = 201;
            unmountAction = "DismountOptic";
            modelOptics = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\uk3cb_Elcan_Optic.p3d";
            class OpticsModes {
                class UK3CB_BAF_LDS {
                    cameraDir = "";
                    discreteDistance[] = { 300 };
                    discreteDistanceInitIndex = 0;
                    distanceZoomMax = 300;
                    distanceZoomMin = 300;
                    memoryPointCamera = "opticView";
                    opticsFlare = 1;
                    opticsID = 1;
                    opticsPPEffects[] = { "OpticsCHAbera5", "OpticsBlur5" };
                    opticsZoomInit = 0.09;
                    opticsZoomMax = 0.09;
                    opticsZoomMin = 0.09;
                    visionMode[] = {};
                    useModelOptics = 0;
                    opticsDisablePeripherialVision = 0;
                };
            };
        };
    };
    class UK3CB_BAF_SpecterLDS_Dot;
    class UK3CB_BAF_SpecterLDS_Dot_3D : UK3CB_BAF_SpecterLDS_Dot {
        scope = 2;
        scopeCurator = 2;
        model = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\uk3cb_Elcan_Reflex.p3d";
        modelOptics = "";
        class ItemInfo : InventoryOpticsItem_Base_F {
            allowedSlots[] = { 801, 701, 901 };
            mass = 4;
            mountAction = "MountOptic";
            muzzleEnd = "konec hlavne";
            muzzlePos = "usti hlavne";
            optics = 1;
            scope = 0;
            type = 201;
            unmountAction = "DismountOptic";
            modelOptics = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\uk3cb_Elcan_Optic.p3d";
            class OpticsModes {
                class UK3CB_BAF_LDS {
                    cameraDir = "";
                    discreteDistance[] = { 300 };
                    discreteDistanceInitIndex = 0;
                    distanceZoomMax = 300;
                    distanceZoomMin = 300;
                    memoryPointCamera = "opticView";
                    opticsFlare = 1;
                    opticsID = 1;
                    opticsPPEffects[] = { "OpticsCHAbera5", "OpticsBlur5" };
                    opticsZoomInit = 0.09;
                    opticsZoomMax = 0.09;
                    opticsZoomMin = 0.09;
                    visionMode[] = {};
                    useModelOptics = 0;
                    opticsDisablePeripherialVision = 0;
                };
                class UK3CB_BAF_LDS_Top {
                    cameraDir = "";
                    discreteDistance[] = { 100 };
                    discreteDistanceInitIndex = 0;
                    distanceZoomMax = 100;
                    distanceZoomMin = 100;
                    memoryPointCamera = "eye";
                    opticsFlare = 1;
                    opticsID = 2;
                    opticsPPEffects[] = { "OpticsCHAbera5", "OpticsBlur5" };
                    opticsZoomInit = 0.75;
                    opticsZoomMax = 1.1;
                    opticsZoomMin = 0.375;
                    visionMode[] = {};
                    useModelOptics = 0;
                    opticsDisablePeripherialVision = 0;
                };
            };
        };
    };
    class UK3CB_BAF_TA31F : ItemCore {
        class ItemInfo : InventoryOpticsItem_Base_F {
            class OpticsModes {
                class UK3CB_BAF_ACOG {
                    visionMode[] = {};
                };
            };
        };
    };
    class UK3CB_BAF_TA648 : ItemCore {
        class ItemInfo : InventoryOpticsItem_Base_F {
            class OpticsModes {
                class ACOG_scope {
                    visionMode[] = {};
                };
            };
        };
    };
    class UK3CB_BAF_SUSAT : ItemCore {
        class ItemInfo : InventoryOpticsItem_Base_F {
            class OpticsModes {
                class UK3CB_BAF_SUSAT {
                    visionMode[] = {};
                };
            };
        };
    };
    class RKSL_optic_LDS : ItemCore {
        class ItemInfo : InventoryOpticsItem_Base_F {
            class OpticsModes {
                class LDS {
                    visionMode[] = {};
                };
            };
        };
    };
    class optic_LRPS : ItemCore {
        class ItemInfo : InventoryOpticsItem_Base_F {
            class OpticsModes {
                class Snip {
                    visionMode[] = {};
                };
            };
        };
    };
    class CUP_optic_Elcan_SpecterDR : ItemCore {
        class ItemInfo : InventoryOpticsItem_Base_F {
            class OpticsModes {
                class Specter4x {
                    visionMode[] = {};
                };
            };
        };
    };
    class RKSL_optic_PMII_525 : ItemCore {
        class ItemInfo;
    };
    class RKSL_optic_PMII_525_NV : RKSL_optic_PMII_525 {
        displayName = "S+B 5-25x56 PM II (NV)";
        class ItemInfo : ItemInfo {
            opticType = 2;
            mass = 30;
            class OpticsModes {
                class Snip {
                    opticsID = 1;
                    opticsDisplayName = "WFOV";
                    useModelOptics = 1;
                    opticsPPEffects[] = { "OpticsCHAbera1", "OpticsBlur1" };
                    opticsZoomMin = 0.01;
                    opticsZoomMax = 0.025;
                    opticsZoomInit = 0.05;
                    discretefov[] = { 0.05, 0.025, 0.0167, 0.0125, 0.01 };
                    discreteInitIndex = 0;
                    discreteDistance[] = { 100 };
                    distanceZoomMin = 300;
                    distanceZoomMax = 2500;
                    memoryPointCamera = "opticView";
                    visionMode[] = { "Normal", "NVG" };
                    opticsFlare = 1;
                    opticsDisablePeripherialVision = 1;
                    cameraDir = "";
                    discreteDistanceInitIndex = 0;
                };
            };
        };
    };
    class UK3CB_BAF_LLM_IR_Tan;
    class UK3CB_BAF_LLM_IR_Black : UK3CB_BAF_LLM_IR_Tan {
        mrt_SwitchItemNextClass = "UK3CB_BAF_LLM_Flashlight_Black";
        mrt_SwitchItemPrevClass = "UK3CB_BAF_LLM_Flashlight_Far_Black";
        mrt_SwitchItemHintText = "IR";
        ace_nextModeClass = "UK3CB_BAF_LLM_Flashlight_Black";
        ace_modeDescription = "IR";
        UK3CB_nextItem = "UK3CB_BAF_LLM_Flashlight_Black";
    };
    class UK3CB_BAF_LLM_Flashlight_Tan;
    class UK3CB_BAF_LLM_Flashlight_Black : UK3CB_BAF_LLM_Flashlight_Tan {
        mrt_SwitchItemNextClass = "UK3CB_BAF_LLM_Flashlight_Far_Black";
        mrt_SwitchItemPrevClass = "UK3CB_BAF_LLM_IR_Black";
        mrt_SwitchItemHintText = "Flashlight";
        ace_nextModeClass = "UK3CB_BAF_LLM_Flashlight_Far_Black";
        ace_modeDescription = "Flashlight";
        UK3CB_nextItem = "UK3CB_BAF_LLM_Flashlight_Far_Black";
    };
    class InventoryFlashLightItem_Base_F;
    class UK3CB_BAF_LLM_Flashlight_Far_Black : UK3CB_BAF_LLM_Flashlight_Black {
        displayName = "LLM Mk3 Flashlight Far (Black)";
        mrt_SwitchItemNextClass = "UK3CB_BAF_LLM_IR_Black";
        mrt_SwitchItemPrevClass = "UK3CB_BAF_LLM_Flashlight_Black";
        mrt_SwitchItemHintText = "Flashlight (Far)";
        ace_nextModeClass = "UK3CB_BAF_LLM_IR_Black";
        ace_modeDescription = "Flashlight (Far)";
        UK3CB_nextItem = "UK3CB_BAF_LLM_IR_Black";
        class ItemInfo : InventoryFlashLightItem_Base_F {
            mass = 4;
            class FlashLight {
                color[] = { 180, 156, 120 };
                ambient[] = { 0.9, 0.78, 0.6 };
                intensity = 40;
                size = 1;
                innerAngle = 5;
                outerAngle = 50;
                coneFadeCoef = 10;
                position = "flash dir";
                direction = "flash";
                useFlare = 1;
                flareSize = 1.4;
                flareMaxDistance = "100.0f";
                dayLight = 0;
                class Attenuation {
                    start = 0.5;
                    constant = 0;
                    linear = 0;
                    quadratic = 1.1;
                    hardLimitStart = 100;
                    hardLimitEnd = 150;
                };
                scale[] = { 0 };
            };
        };
    };

    class ACE_NVG_Wide;
    class ACE_NVG_Pilot : ACE_NVG_Wide {
        scope = 2;
        scopeArsenal = 2;
        author = "UKSF";
        displayName = "Pilot NVG";
        ace_nightvision_generation = 4;
        ace_nightvision_bluRadius = 0.26;
        ace_nightvision_border = QPATHTOF(data\nvg_mask_binos_large_4096.paa);
        modelOptics = "";
    };
    class ACE_NVG_Pilot_WP : ACE_NVG_Pilot {
        displayName = "Pilot NVG (WP)";
        COLOUR_PRESET_WP;
    };
    class NVGoggles;
    class UK3CB_BAF_HMNVS : NVGoggles {
        ace_nightvision_generation = 3;
        ace_nightvision_bluRadius = 0.20;
        ace_nightvision_border = QPATHTOF(data\nvg_mask_large_4096.paa);
        modelOptics = "";
    };
    class UK3CB_BAF_HMNVS_WP : UK3CB_BAF_HMNVS {
        displayName = "Head-Mounted NV System (WP) [BAF]";
        COLOUR_PRESET_WP;
    };
    class CUP_NVG_PVS15_black;
    class CUP_NVG_PVS15_black_WP : CUP_NVG_PVS15_black {
        displayname = "AN/PVS-15 WP (Black)";
        COLOUR_PRESET_WP;
    };
    class CUP_NVG_PVS15_green;
    class CUP_NVG_PVS15_green_WP : CUP_NVG_PVS15_green {
        displayname = "AN/PVS-15 WP (Green)";
        COLOUR_PRESET_WP;
    };
    class CUP_NVG_PVS15_tan;
    class CUP_NVG_PVS15_tan_WP : CUP_NVG_PVS15_tan {
        displayname = "AN/PVS-15 WP (Tan)";
        COLOUR_PRESET_WP;
    };
    class CUP_NVG_PVS15_winter;
    class CUP_NVG_PVS15_winter_WP : CUP_NVG_PVS15_winter {
        displayname = "AN/PVS-15 WP (Winter)";
        COLOUR_PRESET_WP;
    };
    class CUP_NVG_GPNVG_black : NVGoggles {
        displayname = "GPNVG WP (Black)";
        COLOUR_PRESET_WP;
    };
    class CUP_NVG_GPNVG_green : NVGoggles {
        displayname = "GPNVG WP (Green)";
        COLOUR_PRESET_WP;
    };
    class Integrated_NVG_F : NVGoggles {
        ace_nightvision_generation = 4;
        ace_nightvision_bluRadius = 0.36;
    };

    class arifle_Mk20_F;
    class arifle_Mk20_plain_F : arifle_Mk20_F {
        class Single;
        class FullAuto;
    };
    class UK3CB_BAF_L85A2 : arifle_Mk20_plain_F {
        ace_barrelLength = 518;  // c:441.96, a:518
    };

    class UK3CB_BAF_L119_Base : arifle_Mk20_plain_F {
        ace_barrelLength = 398;  // c:410, a:398
        class WeaponSlotsInfo {
            allowedslots[] = { 901 };
            mass = 84;
            delete asdg_MuzzleSlot_UK3CB_BAF_L85;
            class asdg_MuzzleSlot_UK3CB_BAF_L119 : asdg_MuzzleSlot_556_3CB_L119 {};
            class asdg_OpticRail_UK3CB_BAF_L85 : asdg_OpticRail1913 {};
            class asdg_FrontSideRail_L85 : asdg_FrontSideRail {};
        };
        class Single : Single {
            class BaseSoundModeType;
            class SilencedSound : BaseSoundModeType {
                soundSetShot[] = { "3CB_BAF_M4_Closure_SoundSet", "3CB_BAF_M4_ShotSD_SoundSet", "3CB_BAF_Rifle1_SD_Tail_SoundSet" };
            };
        };
        class FullAuto : FullAuto {
            class BaseSoundModeType;
            class SilencedSound : BaseSoundModeType {
                soundSetShot[] = { "3CB_BAF_M4_Closure_SoundSet", "3CB_BAF_M4_ShotSD_SoundSet", "3CB_BAF_Rifle1_SD_Tail_SoundSet" };
            };
        };
    };
    class UK3CB_BAF_L119A1_CQB : UK3CB_BAF_L119_Base {
        ace_barrelLength = 254;  // c:250, a:250
        class WeaponSlotsInfo {
            allowedslots[] = { 901 };
            mass = 84;
            delete asdg_MuzzleSlot_UK3CB_BAF_L85;
            class asdg_MuzzleSlot_UK3CB_BAF_L119 : asdg_MuzzleSlot_556_3CB_L119 {};
            class asdg_OpticRail_UK3CB_BAF_L85 : asdg_OpticRail1913 {};
        };
    };
    class UK3CB_BAF_L119A1 : UK3CB_BAF_L119_Base {
        class WeaponSlotsInfo {
            allowedslots[] = { 901 };
            mass = 84;
            delete asdg_MuzzleSlot_UK3CB_BAF_L85;
            class asdg_MuzzleSlot_UK3CB_BAF_L119 : asdg_MuzzleSlot_556_3CB_L119 {};
            class asdg_OpticRail_UK3CB_BAF_L85 : asdg_OpticRail1913 {};
            class asdg_FrontSideRail_L85 : asdg_FrontSideRail {};
        };
    };

    class Rifle;
    class Rifle_Base_F : Rifle {
        class WeaponSlotsInfo;
    };
    class Tavor_base_F : Rifle_Base_F {
        class Single;
        class FullAuto;
    };
    class SSQN_L119A1_Base : Tavor_base_F {
        magazines[] = { "UK3CB_BAF_556_30Rnd", "UK3CB_BAF_556_30Rnd_T", "30Rnd_556x45_Stanag_red", "30Rnd_556x45_Stanag", "30Rnd_556x45_Stanag_Tracer_Red" };
        class Single : Single {
            class BaseSoundModeType;
            class StandardSound : BaseSoundModeType {
                soundSetShot[] = { "L119_Shot_SoundSet", "FRAME_CALIBER_5x56MM", "ALL_DIST_TAIL" };
            };
            class SilencedSound : BaseSoundModeType {
                soundSetShot[] = { "3CB_BAF_M4_Closure_SoundSet", "3CB_BAF_M4_ShotSD_SoundSet", "3CB_BAF_Rifle1_SD_Tail_SoundSet" };
            };
        };
        class FullAuto : FullAuto {
            class BaseSoundModeType;
            class StandardSound : BaseSoundModeType {
                soundSetShot[] = { "L119_Shot_SoundSet", "FRAME_CALIBER_5x56MM", "ALL_DIST_TAIL" };
            };
            class SilencedSound : BaseSoundModeType {
                soundSetShot[] = { "3CB_BAF_M4_Closure_SoundSet", "3CB_BAF_M4_ShotSD_SoundSet", "3CB_BAF_Rifle1_SD_Tail_SoundSet" };
            };
        };
    };

    class arifle_SPAR_01_blk_F;
    class arifle_L119A2_F : arifle_SPAR_01_blk_F {
        magazines[] = { "UK3CB_BAF_556_30Rnd", "UK3CB_BAF_556_30Rnd_T", "30Rnd_556x45_Stanag_red", "30Rnd_556x45_Stanag", "30Rnd_556x45_Stanag_Tracer_Red" };
        magazineWell[] = {};
        class Single : Mode_SemiAuto {
            class BaseSoundModeType;
            class StandardSound : BaseSoundModeType {
                soundSetShot[] = { "L119_Shot_SoundSet", "FRAME_CALIBER_5x56MM", "ALL_DIST_TAIL" };
            };
            class SilencedSound : BaseSoundModeType {
                soundSetShot[] = { "3CB_BAF_M4_Closure_SoundSet", "L119A2_ShotSD_SoundSet", "3CB_BAF_Rifle1_SD_Tail_SoundSet" };
            };
        };
        class FullAuto : Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound : BaseSoundModeType {
                soundSetShot[] = { "L119_Shot_SoundSet", "FRAME_CALIBER_5x56MM", "ALL_DIST_TAIL" };
            };
            class SilencedSound : BaseSoundModeType {
                soundSetShot[] = { "3CB_BAF_M4_Closure_SoundSet", "L119A2_ShotSD_SoundSet", "3CB_BAF_Rifle1_SD_Tail_SoundSet" };
            };
        };
        ACE_barrelTwist = 178;
        ACE_barrelLength = 398;
    };
    class arifle_L119A2_S_F : arifle_L119A2_F {
        ACE_barrelLength = 262;
    };

    class srifle_EBR_F;
    class UK3CB_BAF_L129A1 : srifle_EBR_F {
        ace_barrelLength = 410;
    };
    class UK3CB_BAF_L128A1 : srifle_EBR_F {
        magazineWell[] = {};
    };

    class UK3CB_BAF_L110_Base;
    class UK3CB_BAF_L110_556_Base : UK3CB_BAF_L110_Base {
        magazines[] = { "UK3CB_BAF_556_200Rnd", "UK3CB_BAF_556_200Rnd_Blank", "UK3CB_BAF_556_200Rnd_T", "UK3CB_BAF_556_100Rnd", "UK3CB_BAF_556_100Rnd_Blank", "UK3CB_BAF_556_100Rnd_T", "UK3CB_BAF_556_30Rnd", "UK3CB_BAF_556_30Rnd_T" };
        class FullAuto : Mode_FullAuto {
            class BaseSoundModeType;
            class SilencedSound : BaseSoundModeType {
                SoundSetShot[] = { "DS_lim_Closure_SoundSet", "DS_lim_ShotSD_SoundSet", "DS_rifle1_SD_Tail_SoundSet" };
            };
        };
    };
    class UK3CB_BAF_L110_762_Base : UK3CB_BAF_L110_Base {
        class FullAuto : Mode_FullAuto {
            class BaseSoundModeType;
            class SilencedSound : BaseSoundModeType {
                SoundSetShot[] = { "DS_lim_Closure_SoundSet", "DS_lim_ShotSD_SoundSet", "DS_rifle1_SD_Tail_SoundSet" };
            };
        };
    };

    class LMG_03_base_F;
    class SSQN_L110A1 : LMG_03_base_F {
        magazines[] = { "UK3CB_BAF_556_200Rnd", "UK3CB_BAF_556_200Rnd_Blank", "UK3CB_BAF_556_200Rnd_T", "UK3CB_BAF_556_100Rnd", "UK3CB_BAF_556_100Rnd_Blank", "UK3CB_BAF_556_100Rnd_T", "UK3CB_BAF_556_30Rnd", "UK3CB_BAF_556_30Rnd_T" };
        magazineWell[] = {};
        modes[] = { "FullAuto", "close", "short", "medium", "far_optic1", "far_optic2" };
        class FullAuto : Mode_FullAuto {
            sounds[] = { "StandardSound", "SilencedSound" };
            class BaseSoundModeType;
            class StandardSound : BaseSoundModeType {
                soundSetShot[] = { "L110_Shot_SoundSet", "FRAME_CALIBER_5x56MM", "ALL_DIST_TAIL" };
            };
            class SilencedSound : BaseSoundModeType {
                SoundSetShot[] = { "DS_lim_Closure_SoundSet", "DS_lim_ShotSD_SoundSet", "DS_rifle1_SD_Tail_SoundSet" };
            };
            reloadTime = 0.08278;
            dispersion = 0.0012;
            minRange = 0;
            minRangeProbab = 0.9;
            midRange = 15;
            midRangeProbab = 0.7;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
        };
    };

    class LMG_Zafir_F;
    class UK3CB_BAF_L7A2 : LMG_Zafir_F {
        magazines[] = {
            "UK3CB_BAF_762_200Rnd_T", "UK3CB_BAF_762_200Rnd", "UK3CB_BAF_762_200Rnd_Blank", "UK3CB_BAF_762_100Rnd_T", "UK3CB_BAF_762_100Rnd", "UK3CB_BAF_762_100Rnd_Blank", "UK3CB_BAF_762_100Rnd_EL", "UK3CB_BAF_762_100Rnd_T_EL", "UK3CB_BAF_762_200Rnd_EL", "UK3CB_BAF_762_200Rnd_T_EL"
        };
        class WeaponSlotsInfo;
        class FullAuto : Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound : BaseSoundModeType {
                soundSetShot[] = { "DS_zafir_Closure_SoundSet", "DS_zafir_Shot_SoundSet", "DS_lmg1_Tail_SoundSet" };
            };
        };
    };
    class UK3CB_BAF_L7A2_FIST : UK3CB_BAF_L7A2 {
        class WeaponSlotsInfo : WeaponSlotsInfo {
            mass = 240;
        };
    };
    class LMG_RCWS;
    class UK3CB_BAF_L7A2_veh : LMG_RCWS {
        magazines[] = {
            "UK3CB_BAF_762_200Rnd_T", "UK3CB_BAF_762_200Rnd", "UK3CB_BAF_762_200Rnd_Blank", "UK3CB_BAF_762_100Rnd_T", "UK3CB_BAF_762_100Rnd", "UK3CB_BAF_762_100Rnd_Blank", "UK3CB_BAF_762_100Rnd_EL", "UK3CB_BAF_762_100Rnd_T_EL", "UK3CB_BAF_762_200Rnd_EL", "UK3CB_BAF_762_200Rnd_T_EL"
        };
    };
    class UK3CB_BAF_L85A3_Grippod;
    class UK3CB_BAF_L85A3_Grippod_Elcan : UK3CB_BAF_L85A3_Grippod {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L85A3";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };
    class UK3CB_BAF_L22A2;
    class UK3CB_BAF_L22A2_Elcan : UK3CB_BAF_L22A2 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L85";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };
    class UK3CB_BAF_L85A3_UGL;
    class UK3CB_BAF_L85A3_UGL_Elcan : UK3CB_BAF_L85A3_UGL {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L85A3";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };

    class UK3CB_BAF_L110A3;
    class UK3CB_BAF_L110A3_Elcan : UK3CB_BAF_L110A3 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L110A2";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };

    class UK3CB_BAF_L129A1_Grippod;
    class UK3CB_BAF_L129A1_Grippod_Acog : UK3CB_BAF_L129A1_Grippod {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L129A1";
                item = "UK3CB_BAF_TA31F";
            };
        };
    };

    class UK3CB_BAF_L115A3;
    class UK3CB_BAF_L115A3_LRPS : UK3CB_BAF_L115A3 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L115";
                item = "optic_LRPS";
            };
        };
    };
    class UK3CB_BAF_L115A3_DE;
    class UK3CB_BAF_L115A3_DE_LRPS : UK3CB_BAF_L115A3_DE {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L115";
                item = "optic_LRPS";
            };
        };
    };
    class UK3CB_BAF_L115_Base;
    class UK3CB_BAF_L118A1_Covert : UK3CB_BAF_L115_Base {
        magazines[] = { "UK3CB_BAF_338_5Rnd", "UK3CB_BAF_338_5Rnd_Blank", "UK3CB_BAF_338_5Rnd_Tracer" };
    };

    class srifle_GM6_F;
    class UK3CB_BAF_L135A1 : srifle_GM6_F {
        magazines[] = { "UK3CB_BAF_127_10Rnd", "UK3CB_BAF_127_10Rnd_AP", "UK3CB_BAF_127_10Rnd_T" };
    };
    class UK3CB_BAF_L135A1_LRPS : UK3CB_BAF_L135A1 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_rifles";
                item = "optic_LRPS";
            };
        };
    };

    class CUP_arifle_M4_Base;
    class CUP_arifle_M4A1_BUIS_Base : CUP_arifle_M4_Base {
        class WeaponSlotsInfo;
    };
    class CUP_arifle_mk18_black : CUP_arifle_M4A1_BUIS_Base {
        magazines[] = { "UK3CB_BAF_556_30Rnd", "UK3CB_BAF_556_30Rnd_T", "30Rnd_556x45_Stanag_red", "30Rnd_556x45_Stanag", "30Rnd_556x45_Stanag_Tracer_Red" };
        magazineWell[] = {};
        class WeaponSlotsInfo : WeaponSlotsInfo {
            delete MuzzleSlot;
            class asdg_MuzzleSlot_UK3CB_BAF_L119 : asdg_MuzzleSlot_556_3CB_L119 {};
        };
    };

    class Launcher;
    class Launcher_Base_F : Launcher {
        class WeaponSlotsInfo;
    };
    class launch_NLAW_F : Launcher_Base_F {
        modes[] = { "Overfly", "Single" };
        descriptionShort = "Short-range fire-and-forget anti-tank missile system";
        class Library {
            libTextDesc = "The NLAW is a short-range fire-and-forget anti-tank missile system.";
        };
    };
    class CBA_MiscItem;
    class CBA_MiscItem_ItemInfo;
    class UK3CB_BAF_Javelin_CLU : CBA_MiscItem {
        scope = 2;
        displayName = "Javelin CLU";
        descriptionShort = "Mid-range fire-and-forget anti-tank missile system<br/>by www.3commandobrigade.com";
        model = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Launchers\UK3CB_Javelin_CLU.p3d";
        picture = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Launchers\data\clu_javelin_ca.paa";
        icon = "iconObject_circle";
        delete OpticsModes;
        delete WeaponSlotsInfo;
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 141;
            allowedSlots[] = { 901 };
        };
    };
    class launch_Titan_base;
    class launch_Titan_short_base : launch_Titan_base {
        class OpticsModes;
    };
    class launch_B_Titan_short_F : launch_Titan_short_base {
        class WeaponSlotsInfo;
        class OpticsModes : OpticsModes {
            class StepScope;
        };
    };
    class UK3CB_BAF_Javelin_Launcher : launch_B_Titan_short_F {
        modes[] = { "TopDown", "Single" };
        class WeaponSlotsInfo : WeaponSlotsInfo {
            mass = 231;
        };
        class OpticsModes : OpticsModes {
            class StepScope : StepScope {
                thermalMode[] = { 0, 1 };
            };
        };
    };
    class UK3CB_BAF_Javelin_Slung_Tube : Launcher_Base_F {
        class WeaponSlotsInfo : WeaponSlotsInfo {
            mass = 350;
        };
    };
    class UK3CB_BAF_Javelin_Slung_Tube_Used : UK3CB_BAF_Javelin_Slung_Tube {
        class WeaponSlotsInfo : WeaponSlotsInfo {
            mass = 90;
        };
    };
    class launch_MRAWS_base_F : Launcher_Base_F {
        class WeaponSlotsInfo : WeaponSlotsInfo {
            mass = 150;
        };
    };

    class Default;
    class Put : Default {
        muzzles[] += { "BreachChargeMuzzle" };
        class DemoChargeMuzzle;
        class BreachChargeMuzzle : DemoChargeMuzzle {
            displayName = "Breach Charge";
            magazines[] = { "BreachCharge_Remote_Mag" };
        };
    };

    class MGun;
    class CUP_Vlmg_M240_veh : MGun {
        displayName = "L7A2";
        magazines[] = { "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M", "CUP_200Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M", "CUP_1200Rnd_TE4_White_Tracer_762x51_M240_M", "CUP_100Rnd_TE4_White_Tracer_762x51_M240_M", "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M", , "UK3CB_BAF_762_200Rnd_T", "UK3CB_BAF_762_200Rnd", "UK3CB_BAF_762_200Rnd_Blank", "UK3CB_BAF_762_100Rnd_T", "UK3CB_BAF_762_100Rnd", "UK3CB_BAF_762_100Rnd_Blank", "UK3CB_BAF_762_100Rnd_EL", "UK3CB_BAF_762_100Rnd_T_EL", "UK3CB_BAF_762_200Rnd_EL", "UK3CB_BAF_762_200Rnd_T_EL" };
        class manual : MGun {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_CoaxMG_Closure_SoundSet", "DS_CoaxMG_Shot_SoundSet", "DS_lmg1_Tail_SoundSet" };
            };
        };
    };
    class HMG_M2;
    class CUP_Vhmg_M2_veh : HMG_M2 {
        displayName = "L111A1";
        magazines[] = { "CUP_100Rnd_127x99_M", "CUP_100Rnd_TE4_Red_Tracer_127x99_M", "CUP_100Rnd_TE4_Green_Tracer_127x99_M", "CUP_100Rnd_TE4_Yellow_Tracer_127x99_M", "CUP_100Rnd_TE4_White_Tracer_127x99_M", "CUP_100Rnd_TE1_Red_Tracer_127x99_M", "CUP_100Rnd_TE1_Green_Tracer_127x99_M", "CUP_100Rnd_TE1_Yellow_Tracer_127x99_M", "CUP_100Rnd_TE1_White_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "UK3CB_BAF_127_100Rnd" };
        class manual : MGun {
            class StandardSound {
                soundSetShot[] = { "DS_HMG_Shot_SoundSet", "DS_sniper1_Tail_SoundSet" };
            };
        };
    };
    class GMG_20mm;
    class GMG_F;
    class CUP_Vhmg_AGS30_veh : GMG_20mm {
        class manual : GMG_F {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_GMG_Shot_SoundSet", "DS_mmg1_Tail_SoundSet" };
            };
        };
    };
    class CUP_Vgmg_MK19_veh : CUP_Vhmg_AGS30_veh {
        displayName = "L134A1";
        magazines[] = { "CUP_48Rnd_40mm_MK19_M", "CUP_32Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "UK3CB_BAF_32Rnd_40mm_G_Box" };
    };
    class MGunCore;
    class CUP_Vlmg_M134_veh : MGunCore {
        class LowROF : Mode_FullAuto {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_Minigun762_Shot_SoundSet", "DS_mmg1_Tail_SoundSet" };
            };
        };
        class HighROF : LowROF {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_Minigun762_Shot_SoundSet", "DS_mmg1_Tail_SoundSet" };
            };
        };
    };

    class Binocular;
    class UK3CB_BAF_Soflam_Laserdesignator : Binocular {
        distanceZoomMax = 10000;
    };

    class CannonCore;
    class mortar_82mm : CannonCore {
        class Single1;
        class Single2;
        class Single3;
    };
    class UK3CB_BAF_L16_veh : mortar_82mm {
        modes[] = { "Single1", "Single2", "Single3", "Single4", "Single5", "Single6", "Single7", "Burst1", "Burst2", "Burst3" };
        class Single1 : Single1 {
            // Charge 0 -> 14/61
            displayName = "Charge 0";
            artilleryCharge = 0.2295;
        };
        class Single2 : Single2 {
            // Charge 1 -> 28/61
            displayName = "Charge 1";
            artilleryCharge = 0.459;
        };
        class Single3 : Single3 {
            // Charge 2 -> 40/61
            displayName = "Charge 2";
            artilleryCharge = 0.6557;
        };
        class Single4 : Single3 {
            // Charge 3 -> 46/61
            displayName = "Charge 3";
            artilleryCharge = 0.7541;
        };
        class Single5 : Single3 {
            // Charge 4 -> 51/61
            displayName = "Charge 4";
            artilleryCharge = 0.836;
        };
        class Single6 : Single3 {
            // Charge 5 -> 56/61
            displayName = "Charge 5";
            artilleryCharge = 0.918;
        };
        class Single7 : Single3 {
            // Charge 6 -> 1
            displayName = "Charge 6";
            artilleryCharge = 1;
        };
    };

    class Rifle_Long_Base_F;
    class SPS_AI_AXMC_base_F;

#include "weaponSets\CUP.hpp"
#include "weaponSets\SPS.hpp"

#include "CfgWeaponsPrivate.hpp"
};
