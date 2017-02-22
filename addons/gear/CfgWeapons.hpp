class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons {
    class ItemCore;
    class Uniform_Base;
    class UniformItem;
    class HeadgearItem;
    class VestItem;

    class U_I_CombatUniform;
    class U_I_CombatUniform_shortsleeve;
    class U_B_HeliPilotCoveralls;
    class UK3CB_BAF_U_CombatUniform_MTP_RM: U_I_CombatUniform {
        scope = 2;
    };
    class UK3CB_BAF_U_CombatUniform_MTP_ShortSleeve_RM: U_I_CombatUniform_shortsleeve {
        scope = 2;
    };
    class UK3CB_BAF_U_CombatUniform_MTP_TShirt_RM: U_I_CombatUniform {
        scope = 2;
    };
    class UK3CB_BAF_U_CombatUniform_MTP: U_I_CombatUniform {
        scope = 2;
    };
    class UK3CB_BAF_U_CombatUniform_MTP_ShortSleeve: U_I_CombatUniform_shortsleeve {
        scope = 2;
    };
    class UK3CB_BAF_U_HeliPilotCoveralls_RN: U_B_HeliPilotCoveralls {
        scope = 2;
    };
    class UK3CB_BAF_U_CombatUniform_MTP_Ghillie_RM: Uniform_Base {
        scope = 2;
    };
    class UK3CB_BAF_U_CombatUniform_MTP_TShirt: UK3CB_BAF_U_CombatUniform_MTP_TShirt_RM {
        scope = 2;
        author = "UKSF";
        displayName = "Combat T-Shirt MTP";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_Tshirt_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_1Para: U_I_CombatUniform {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP 1Para";
        descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_1para_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_1Para_ShortSleeve: U_I_CombatUniform_shortsleeve {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP 1Para Rolled";
        descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_1para_rolledup_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_CSMR: U_I_CombatUniform {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP CSMR";
        descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_csmr_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_CSMR_LongSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_CSMR_ShortSleeve: U_I_CombatUniform_shortsleeve {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP CSMR Rolled";
        descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_csmr_rolledup_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_CSMR_ShortSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_Path: U_I_CombatUniform {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP Pathfinder";
        descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_path_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_Path_LongSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve: U_I_CombatUniform_shortsleeve {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP Pathfinder Rolled";
        descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_path_rolledup_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_Path_ShortSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_Sig: U_I_CombatUniform {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP Signals";
        descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_sig_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_Sig_LongSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP_Sig_ShortSleeve: U_I_CombatUniform_shortsleeve {
        scope = 2;
        author = "UKSF";
        DLC = "UK3CB_BAF_Equipment";
        displayName = "Combat Uniform MTP Signals Rolled";
        descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
        picture = QPATHTOF(UI\icon_uniform_mtp_sig_rolledup_ca.paa);
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_Soldier_MTP_Sig_ShortSleeve_base";
            containerClass = "Supply40";
            mass = 40;
        };
    };
    class UK3CB_BAF_U_HeliPilotCoveralls_RAF: U_B_HeliPilotCoveralls {
        scope = 2;
        author = "UKSF";
        displayName = "Heli Pilot Flight Suit RAF [BAF]";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_civilian_F.p3d";
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\helipilot_coveralls_raf.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_HeliPilot_RAF_base";
            containerClass = "Supply40";
            mass = 60;
        };
    };
    class UKSF_U_ATC: Uniform_Base {
        scope = 2;
        author = "UKSF";
        displayName = "ATC Blues";
        picture = QPATHTOF(UI\icon_uniform_atc_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UKSF_Soldier_ATC_base";
            containerClass = "Supply100";
            mass = 20;
        };
    };
    class U_O_Soldier_VR;
    class UKSF_U_VR: U_O_Soldier_VR {
        scope = 2;
        scopeArsenal = 1;
        displayName = "VR Battle Suit";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_original_F.p3d";
        picture = "\A3\characters_f_bootcamp\data\ui\icon_u_o_protagonist_vr_ca.paa";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)" };
        class ItemInfo: UniformItem {
            modelSides[] = {0, 3};
            uniformModel = "-";
            uniformClass = "UKSF_O_Rifleman";
            containerClass = "Supply1000";
            mass = 0;
        };
    };

    class H_Beret_02;
    class UKSF_H_RAFBeret: H_Beret_02 {
        scope = 2;
        author = "UKSF";
        displayName = "RAF Beret";
        picture = QPATHTOF(UI\icon_beret_raf_ca.paa);
        model = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\hats\RAF_Beret.paa) };
        hiddenSelectionsMaterials[] = { QPATHTOF(data\hats\Beret.rvmat) };
        class ItemInfo: HeadgearItem {
            mass = 5;
            uniformmodel = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
            modelSides[] = { 6 };
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 0;
                    passThrough = 0.5;
                };
            };
            hiddenSelectionsTextures[] = { QPATHTOF(data\hats\RAF_Beret.paa) };
            hiddenSelections[] = { "Camo" };
        };
    };
    class UKSF_H_AACBeret: H_Beret_02 {
        scope = 2;
        author = "UKSF";
        displayName = "AAC Beret";
        picture = QPATHTOF(UI\icon_beret_aac_ca.paa);
        model = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\hats\AAC_Beret.paa) };
        hiddenSelectionsMaterials[] = { QPATHTOF(data\hats\Beret.rvmat) };
        class ItemInfo: HeadgearItem {
            mass = 5;
            uniformmodel = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
            modelSides[] = { 6 };
            class HitpointsProtectionInfo {
                class Head {
                    hitpointName = "HitHead";
                    armor = 0;
                    passThrough = 0.5;
                };
            };
            hiddenSelectionsTextures[] = { QPATHTOF(data\hats\AAC_Beret.paa) };
            hiddenSelections[] = { "Camo" };
        };
    };

    class V_TacVest_oli;
    class UKSF_V_Pilot: V_TacVest_oli {
        scope = 2;
        author = "UKSF";
        displayName = "Pilot vest";
        picture = QPATHTOF(UI\icon_v_tacvest_khk_ca.paa);
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\vests\tacticalvest_olive_co.paa) };
        class ItemInfo: VestItem {
            uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
            containerClass = "Supply200";
            mass = 40;
            armor = 20;
            passThrough = 1;
            hiddenSelections[] = { "camo" };
        };
    };
    class Vest_Camo_Base: ItemCore {
        class ItemInfo;
    };
    class UKSF_V_Flight: Vest_Camo_Base {
        scope = 2;
        author = "UKSF";
        displayName = "Pilot Survival Vest";
        picture = QPATHTOF(UI\pilotvest_pic_ca.paa);
        model = QPATHTOF(data\vests\FIR_pilot_vest.p3d);
        class ItemInfo: ItemInfo {
            uniformModel = QPATHTOF(data\vests\FIR_pilot_vest.p3d);
            containerClass = "Supply200";
            mass = 40;
            armor = 40;
            passThrough = 0.4;
        };
    };

    class InventoryOpticsItem_Base_F;
    class UK3CB_BAF_SpecterLDS_Dot;
    class UK3CB_BAF_SpecterLDS: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class UK3CB_BAF_LDS {
                    visionMode[] = {};
                };
            };
        };
    };
    class UK3CB_BAF_SpecterLDS_3D: UK3CB_BAF_SpecterLDS {
        scope = 2;
        scopeCUrator = 2;
        class ItemInfo: InventoryOpticsItem_Base_F {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountOptic";
            muzzleEnd = "konec hlavne";
            muzzlePos = "usti hlavne";
            optics = 1;
            scope = 0;
            type = 201;
            unmountAction = "DismountOptic";
            modelOptics = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\Elcan_Optic.p3d";
            class OpticsModes {
                class UK3CB_BAF_LDS {
                    cameraDir = "";
                    discreteDistance[] = {300};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMax = 300;
                    distanceZoomMin = 300;
                    memoryPointCamera = "opticView";
                    opticsFlare = 1;
                    opticsID = 1;
                    opticsPPEffects[] = { "OpticsCHAbera5","OpticsBlur5" };
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
    class UK3CB_BAF_SpecterLDS_Dot_3D: UK3CB_BAF_SpecterLDS_Dot {
        scope = 2;
        scopeCUrator = 2;
        model = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\Elcan_Reflex.p3d";
        modelOptics = "";
        class ItemInfo: InventoryOpticsItem_Base_F {
            allowedSlots[] = {801,701,901};
            mass = 4;
            mountAction = "MountOptic";
            muzzleEnd = "konec hlavne";
            muzzlePos = "usti hlavne";
            optics = 1;
            scope = 0;
            type = 201;
            unmountAction = "DismountOptic";
            modelOptics = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\Elcan_Optic.p3d";
            class OpticsModes {
                class UK3CB_BAF_LDS {
                    cameraDir = "";
                    discreteDistance[] = {300};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMax = 300;
                    distanceZoomMin = 300;
                    memoryPointCamera = "opticView";
                    opticsFlare = 1;
                    opticsID = 1;
                    opticsPPEffects[] = { "OpticsCHAbera5","OpticsBlur5" };
                    opticsZoomInit = 0.09;
                    opticsZoomMax = 0.09;
                    opticsZoomMin = 0.09;
                    visionMode[] = {};
                    useModelOptics = 0;
                    opticsDisablePeripherialVision = 0;
                };
                class UK3CB_BAF_LDS_Top {
                    cameraDir = "";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMax = 100;
                    distanceZoomMin = 100;
                    memoryPointCamera = "eye";
                    opticsFlare = 1;
                    opticsID = 2;
                    opticsPPEffects[] = { "OpticsCHAbera5","OpticsBlur5" };
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
    class UK3CB_BAF_TA31F: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class UK3CB_BAF_ACOG {
                    visionMode[] = {};
                };
            };
        };
    };
    class UK3CB_BAF_TA648: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class ACOG_scope {
                    visionMode[] = {};
                };
            };
        };
    };
    class UK3CB_BAF_SUSAT: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class UK3CB_BAF_SUSAT {
                    visionMode[] = {};
                };
            };
        };
    };
    class optic_LRPS: ItemCore {
        class ItemInfo: InventoryOpticsItem_Base_F {
            class OpticsModes {
                class Snip {
                    visionMode[] = {};
                };
            };
        };
    };
    class ACE_NVG_Wide;
    class ACE_NVG_Pilot: ACE_NVG_Wide {
        scope = 2;
        scopeArsenal = 2;
        author = "UKSF";
        displayName = "Pilot NVG";
        ACE_NightVision_grain = 0;
        ACE_NightVision_blur = 0;
        ACE_NightVision_radBlur = 0;
    };

    class arifle_Mk20_plain_F;
    class UGL_F;
    class UK3CB_BAF_L85A2: arifle_Mk20_plain_F {
        class UK3CB_BAF_L123A2: UGL_F {
            magazines[] = { "1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","UK3CB_BAF_1Rnd_HEDP_Grenade_shell","ACE_HuntIR_M203" };
        };
        class UK3CB_BAF_L123A3_V2: UGL_F {
            magazines[] = { "1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","UK3CB_BAF_1Rnd_HEDP_Grenade_shell","ACE_HuntIR_M203" };
        };
        class EGLM: UGL_F {
            magazines[] = { "1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","ACE_HuntIR_M203" };
        };
    };
    class LMG_Zafir_F;
    class UK3CB_BAF_L7A2: LMG_Zafir_F {
        magazines[] = {
            "UK3CB_BAF_762_200Rnd_T","UK3CB_BAF_762_200Rnd","UK3CB_BAF_762_200Rnd_Blank","UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd","UK3CB_BAF_762_100Rnd_Blank","UK3CB_BAF_762_100Rnd_EL","UK3CB_BAF_762_100Rnd_T_EL","UK3CB_BAF_762_200Rnd_EL","UK3CB_BAF_762_200Rnd_T_EL"
        };
        class Single: Mode_SemiAuto {
            sounds[] = { "StandardSound" };
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "DS_CoaxMG_Closure_SoundSet","DS_CoaxMG_Shot_SoundSet","DS_mmg1_Tail_SoundSet" };
            };
        };
        class FullAuto: Mode_FullAuto {
            sounds[] = { "StandardSound" };
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "DS_CoaxMG_Closure_SoundSet","DS_CoaxMG_Shot_SoundSet","DS_mmg1_Tail_SoundSet" };
            };
        };
        class WeaponSlotsInfo;
    };
    class UK3CB_BAF_L7A2_FIST: UK3CB_BAF_L7A2 {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 240;
        };
    };    
    class UK3CB_BAF_L110A2: LMG_Zafir_F {
        class Single: Mode_SemiAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {     "DS_zafir_Closure_SoundSet","DS_zafir_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {     "DS_zafir_Closure_SoundSet","DS_zafir_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
    };
    class Rifle_Long_Base_F;
    class UK3CB_BAF_L110_Base: Rifle_Long_Base_F {
        class Single: Mode_SemiAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {     "DS_zafir_Closure_SoundSet","DS_zafir_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {     "DS_zafir_Closure_SoundSet","DS_zafir_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
    };
    class UK3CB_BAF_L110_556_Base: UK3CB_BAF_L110_Base {
        class Single: Mode_SemiAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {     "DS_zafir_Closure_SoundSet","DS_zafir_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {     "DS_zafir_Closure_SoundSet","DS_zafir_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
    };
    class UK3CB_BAF_L110_762_Base: UK3CB_BAF_L110_Base {
        class Single: Mode_SemiAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "DS_CoaxMG_Closure_SoundSet","DS_CoaxMG_Shot_SoundSet","DS_mmg1_Tail_SoundSet" };
            };
        };
        class FullAuto: Mode_FullAuto {
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "DS_CoaxMG_Closure_SoundSet","DS_CoaxMG_Shot_SoundSet","DS_mmg1_Tail_SoundSet" };
            };
        };
    };
    class LMG_RCWS;
    class MGun;
    class UK3CB_BAF_L7A2_veh: LMG_RCWS {
        magazines[] = {
            "UK3CB_BAF_762_200Rnd_T","UK3CB_BAF_762_200Rnd","UK3CB_BAF_762_200Rnd_Blank","UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd","UK3CB_BAF_762_100Rnd_Blank","UK3CB_BAF_762_100Rnd_EL","UK3CB_BAF_762_100Rnd_T_EL","UK3CB_BAF_762_200Rnd_EL","UK3CB_BAF_762_200Rnd_T_EL"
        };
        class manual: MGun {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_CoaxMG_Closure_SoundSet","DS_CoaxMG_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
    };
    class GM6_base_F;
    class srifle_GM6_F: GM6_base_F {
        class Single;
    };
    class UK3CB_BAF_L135A1: srifle_GM6_F {
        class Single: Single {
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "DS_sniper1_crackling_SoundSet","DS_lrr_Shot_SoundSet","DS_sniper1_Tail_SoundSet" };
            };
        };
    };

    class UK3CB_BAF_L85A2_RIS;
    class UK3CB_BAF_L85A2_RIS_Elcan: UK3CB_BAF_L85A2_RIS {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L85";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };
    class UK3CB_BAF_L22A2;
    class UK3CB_BAF_L22A2_Elcan: UK3CB_BAF_L22A2 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L85";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };
    class UK3CB_BAF_L85A2_UGL;
    class UK3CB_BAF_L85A2_UGL_Elcan: UK3CB_BAF_L85A2_UGL {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L85";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };
    class UK3CB_BAF_L110A3;
    class UK3CB_BAF_L110A3_Elcan: UK3CB_BAF_L110A3 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L110A2";
                item = "UK3CB_BAF_SpecterLDS_Dot_3D";
            };
        };
    };
    class UK3CB_BAF_L129A1_Grippod;
    class UK3CB_BAF_L129A1_Grippod_Acog: UK3CB_BAF_L129A1_Grippod {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L129A1";
                item = "UK3CB_BAF_TA31F";
            };
        };
    };
    class UK3CB_BAF_L115A3;
    class UK3CB_BAF_L115A3_LRPS: UK3CB_BAF_L115A3 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L115";
                item = "optic_LRPS";
            };
        };
    };
    class UK3CB_BAF_L115A3_DE;
    class UK3CB_BAF_L115A3_DE_LRPS: UK3CB_BAF_L115A3_DE {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_UK3CB_BAF_L115";
                item = "optic_LRPS";
            };
        };
    };
    class UK3CB_BAF_L135A1_LRPS: UK3CB_BAF_L135A1 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_rifles";
                item = "optic_LRPS";
            };
        };
    };

    class Default;
    class CUP_weapon_mastersafe: Default {
        displayName = "Safe";
        displayNameMagazine = "Safe";
        shortNameMagazine = "Safe";
        nameSound = "cannon";
        cursor = "EmptyCursor";
        cursorAim = "EmptyCursor";
        magazines[] = { "FakeMagazine" };
        reloadMagazineSound[] = { "", 1, 1 };
        canLock = 0;
        burst = 0;
        reloadTime = 0.01;
        magazineReloadTime = 0.1;
    };
    class MissileLauncher;
    class CUP_Vmlauncher_AGM114K_veh: MissileLauncher {
        displayName = "AGM-114K Hellfire II";
        reloadMagazineSound[] = { "", 1, 1 };
        sounds[] = { "StandardSound" };
        class StandardSound {
            begin1[] = { "a3\sounds_f\weapons\rockets\missile_2", 5, 1.3, 1000 };
            soundBegin[] = { "begin1", 1 };
            weaponSoundEffect = "DefaultRifle";
        };
        soundFly[] = { QPATHTOF(data\sounds\hellfire.ogg), 1, 1.5, 700 };
        lockingTargetSound[] = { "\a3\sounds_f\weapons\rockets\locked_1", 0.31622776, 1 };
        lockedTargetSound[] = { "\a3\sounds_f\weapons\rockets\locked_3", 0.31622776, 2.5 };
        weaponLockDelay = 0.5;
        magazines[] = {
            "CUP_8Rnd_AGM114K_Hellfire_II_M","CUP_4Rnd_AGM114K_Hellfire_II_M","CUP_2Rnd_AGM114K_Hellfire_II_M","CUP_1Rnd_AGM114K_Hellfire_II_M"
        };
    };
    class CUP_Vmlauncher_AGM114L_veh: CUP_Vmlauncher_AGM114K_veh {
        displayName = "AGM-114L Hellfire II";
        magazines[] = {
            "CUP_8Rnd_AGM114L_Hellfire_II_M","CUP_4Rnd_AGM114L_Hellfire_II_M","CUP_2Rnd_AGM114L_Hellfire_II_M","CUP_1Rnd_AGM114L_Hellfire_II_M"
        };
    };
    class CUP_AGM114L_Hellfire_II_Launcher_W: CUP_Vmlauncher_AGM114L_veh {};
    class CUP_Vmlauncher_AGM114N_veh: CUP_Vmlauncher_AGM114K_veh {
        displayName = "AGM-114N Hellfire II";
        magazines[] = {
            "CUP_8Rnd_AGM114N_Hellfire_II_M","CUP_4Rnd_AGM114N_Hellfire_II_M"
        };
    };
    class CUP_AGM114N_Hellfire_II_Launcher_W: CUP_Vmlauncher_AGM114N_veh {};
    class RocketPods;
    class GBU12BombLauncher: RocketPods {
        magazines[] = { "1Rnd_GBU12_LGB","2Rnd_GBU12_LGB","2Rnd_GBU12_LGB_MI10" };
    };
    class CannonCore;
    class gatling_30mm: CannonCore {
        class LowROF;
        class close;
        class near;
        class short;
        class medium;
        class far;
    };
    class CUP_Vacannon_M230_veh_Enhanced: gatling_30mm {
        scope = 1;
        author = "UKSF";
        displayName = "Chain Gun M230 30mm";
        magazines[] = { "CUP_1200Rnd_TE1_Red_Tracer_30x113mm_M789_HEDP_M","CUP_1200Rnd_TE1_Green_Tracer_30x113mm_M789_HEDP_M","CUP_1200Rnd_TE1_Yellow_Tracer_30x113mm_M789_HEDP_M","CUP_1200Rnd_TE1_White_Tracer_30x113mm_M789_HEDP_M" };
        canLock = 2;
        ballisticsComputer = 1;
        reloadMagazineSound[] = { "", 1, 1};
        modes[] = { "Burst10","Burst20","Burst50","close","near","short","medium","far" };
        cursorAim = "EmptyCursor";        
        class GunParticles {
            class EffectSmokeLeft {
                effectName = "MachineGun2";
                positionName = "usti hlavne";
                directionName = "gun_smoke_left";
            };
            class EffectSmokeRight {
                effectName = "MachineGun2";
                positionName = "usti hlavne";
                directionName = "gun_smoke_right";
            };
            class EffectCartridge
            {
                positionName = "gun_eject";
                directionName = "gun_eject_dir";
                effectName = "MachineGunCartridge1";
            };
        };
        class Burst10: Mode_FullAuto {
            displayName = "Burst 10";
            textureType = "semi";
            reloadTime = 0.096;
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
            };
            autoFire = 1;
            burst = 10;
            minRange = 1000;
            minRangeProbab = 0.03;
            midRange = 2000;
            midRangeProbab = 0.02;
            maxRange = 3000;
            maxRangeProbab = 0.01;
            showToPlayer = 1;
        };
        class Burst20: Burst10 {
            displayName = "20 Burst";
            textureType = "burst";
            burst = 20;
        };
        class Burst50: Burst20 {
            displayName = "Full";
            textureType = "fullAuto";
            burst = 1;
        };
        class close: close {
            reloadTime = 0.096;
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
            };
        };
        class near: near {
            reloadTime = 0.096;
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
            };
        };
        class short: short{
            reloadTime = 0.096;
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
            };
        };
        class medium: medium {
            reloadTime = 0.096;
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
            };
        };
        class far: far {
            reloadTime = 0.096;
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
            };
        };
    };
    class CUP_Vacannon_M621_AW159_veh: CannonCore {
        class GunParticles {
            class FirstEffect {
                effectName = "machinegun1";
                positionName = "muzzle_1";
                directionName = "chamber_1";
            };
            class EffectCartridge {
                positionName = "eject_1";
                directionName = "eject_1_dir";
                effectName = "MachineGunCartridge";
            };
        };
        cartridgePos = "eject_1";
        cartridgeVel = "eject_1_dir";
        class manual: MGun {
            class StandardSound {
                soundSetShot[] = { "DS_20mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
                begin1[] = { "A3\Sounds_F\arsenal\weapons_vehicles\gatling_20mm\20mm_01_burst", 3.98107, 1, 1300, {2, 35740} };
                soundBegin[] = { "begin1", 1 };
                closure1[] = { "A3\Sounds_F\weapons\Closure\sfx10", 0.63095737, 1, 20 };
                closure2[] = { "A3\sounds_f\weapons\closure\sfx11", 0.63095737, 1.2, 20 };
                soundClosure[] = { "closure1", 0.5, "closure2", 0.5 };
            };
        };
    };
    class CUP_Vmlauncher_FFAR_veh;
    class CUP_Vmlauncher_CRV7_FAT_veh: CUP_Vmlauncher_FFAR_veh {
        class Far_AI: RocketPods {
            soundFly[] = { QPATHTOF(data\sounds\crv7.ogg), 100, 0.8, 800 };
        };
        class Single: Mode_SemiAuto {
            soundFly[] = { QPATHTOF(data\sounds\crv7.ogg), 100, 0.8, 800 };
        };
        class Double: Single {
            displayname = "Ripple 2";
        };
        class Quadruple: Single {
            displayname = "Ripple 4";
        };
    };
    class CUP_Vmlauncher_CRV7_HEISAP_veh: CUP_Vmlauncher_CRV7_FAT_veh {
        magazines[] = { "CUP_12Rnd_CRV7_HEISAP_M","CUP_14Rnd_CRV7_HEISAP_M","CUP_19Rnd_CRV7_HEISAP_M","CUP_24Rnd_CRV7_HEISAP_M","CUP_38Rnd_CRV7_HEISAP_M","CUP_48Rnd_CRV7_HEISAP_M","CUP_76Rnd_CRV7_HEISAP_M","CUP_114Rnd_CRV7_HEISAP_M" };
    };
    class CUP_Vlmg_M240_veh: MGun {
        displayName = "L7A2";
        magazines[] = { "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M","CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M","CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M","CUP_200Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M","CUP_1200Rnd_TE4_White_Tracer_762x51_M240_M","CUP_100Rnd_TE4_White_Tracer_762x51_M240_M","CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M",,"UK3CB_BAF_762_200Rnd_T","UK3CB_BAF_762_200Rnd","UK3CB_BAF_762_200Rnd_Blank","UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd","UK3CB_BAF_762_100Rnd_Blank","UK3CB_BAF_762_100Rnd_EL","UK3CB_BAF_762_100Rnd_T_EL","UK3CB_BAF_762_200Rnd_EL","UK3CB_BAF_762_200Rnd_T_EL" };
        class manual: MGun {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_CoaxMG_Closure_SoundSet","DS_CoaxMG_Shot_SoundSet","DS_lmg1_Tail_SoundSet" };
            };
        };
    };
    class HMG_M2;
    class CUP_Vhmg_M2_veh: HMG_M2 {
        displayName = "L111A1";
        magazines[] = { "CUP_100Rnd_127x99_M","CUP_100Rnd_TE4_Red_Tracer_127x99_M","CUP_100Rnd_TE4_Green_Tracer_127x99_M","CUP_100Rnd_TE4_Yellow_Tracer_127x99_M","CUP_100Rnd_TE4_White_Tracer_127x99_M","CUP_100Rnd_TE1_Red_Tracer_127x99_M","CUP_100Rnd_TE1_Green_Tracer_127x99_M","CUP_100Rnd_TE1_Yellow_Tracer_127x99_M","CUP_100Rnd_TE1_White_Tracer_127x99_M","CUP_200Rnd_TE1_Red_Tracer_127x99_M","UK3CB_BAF_127_100Rnd" };
        class manual: MGun {
            class StandardSound {
                soundSetShot[] = { "DS_HMG_Shot_SoundSet","DS_sniper1_Tail_SoundSet" };
            };
        };
    };
    class GMG_20mm;
    class GMG_F;
    class CUP_Vhmg_AGS30_veh: GMG_20mm {
        class manual: GMG_F {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_GMG_Shot_SoundSet","DS_mmg1_Tail_SoundSet" };
            };
        };
    };
    class CUP_Vgmg_MK19_veh: CUP_Vhmg_AGS30_veh {
        displayName = "L134A1";
        magazines[] = { "CUP_48Rnd_40mm_MK19_M","CUP_32Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","UK3CB_BAF_32Rnd_40mm_G_Box" };
    };
    class MGunCore;
    class CUP_Vlmg_M134_veh: MGunCore {
        class LowROF: Mode_FullAuto {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_Minigun762_Shot_SoundSet","DS_mmg1_Tail_SoundSet" };
            };
        };
        class HighROF: LowROF {
            sounds[] = { "StandardSound" };
            class StandardSound {
                soundSetShot[] = { "DS_Minigun762_Shot_SoundSet","DS_mmg1_Tail_SoundSet" };
            };
        };
    };

    //Rubber weapons for virtual army faction
    class CUP_arifle_M4A1;
    class CUP_arifle_M4A1_Acog: CUP_arifle_M4A1 {
        scopeArsenal = 1;
        magazines[] = { "30Rnd_556x45_Stanag_Rubber" };
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM4";
                item = "CUP_optic_RCO";
            };
        };
    };
    class CUP_lmg_M240;
    class CUP_lmg_M240_LDS: CUP_lmg_M240 {
        scopeArsenal = 1;
        magazines[] = { "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M_Rubber" };
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CUP_PicatinnyTopMountM4";
                item = "UK3CB_BAF_SpecterLDS";
            };
        };
    };
    class CUP_launch_Mk153Mod0;
    class CUP_launch_Mk153Mod0_Rubber: CUP_launch_Mk153Mod0 {
        scopeArsenal = 1;
        magazines[] = { "CUP_SMAW_HEAT_M_Rubber" };
        ace_overpressure_damage = 0;
    };
    class CUP_launch_FIM92Stinger;
    class CUP_launch_FIM92Stinger_Rubber: CUP_launch_FIM92Stinger {
        scopeArsenal = 1;
        magazines[] = { "CUP_Stinger_M_Rubber" };
        ace_overpressure_damage = 0;
    };
    class CUP_Vhmg_M2_veh_rubber: CUP_Vhmg_M2_veh {
        displayName = "M2 Rubber";
        magazines[] = { "CUP_100Rnd_TE4_White_Tracer_127x99_M_Rubber" };
    };
    class CUP_Vcannon_M256_M1Abrams;
    class CUP_Vcannon_M256_M1Abrams_Rubber: CUP_Vcannon_M256_M1Abrams {
        displayName = "M256 Rubber";
        magazines[] = { "CUP_20Rnd_TE1_White_Tracer_120mmSABOT_M256_Cannon_M_Rubber", "CUP_20Rnd_TE1_White_Tracer_120mmHE_M256_Cannon_M_Rubber" };
    };
    class CUP_Vlmg_M240_M1Abrams_Coax;
    class CUP_Vlmg_M240_M1Abrams_Coax_Rubber: CUP_Vlmg_M240_M1Abrams_Coax {
        displayName = "M240 Rubber";
        magazines[] = { "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M_Rubber" };
    };
    class CUP_Vhmg_M2_M1Abrams_Commander;
    class CUP_Vhmg_M2_M1Abrams_Commander_Rubber: CUP_Vhmg_M2_M1Abrams_Commander {
        displayName = "M2 Rubber";
        magazines[] = { "CUP_100Rnd_TE4_White_Tracer_127x99_M_Rubber" };
    };
    class CUP_Vlmg_M240_M1Abrams_Loader;
    class CUP_Vlmg_M240_M1Abrams_Loader_Rubber: CUP_Vlmg_M240_M1Abrams_Loader {
        displayName = "M240 Rubber";
        magazines[] = { "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M_Rubber" };
    };
    class CUP_Vacannon_M242_veh;
    class CUP_Vacannon_M242_veh_Rubber: CUP_Vacannon_M242_veh {
         displayName = "M242 Bushmaster 25mm Rubber";
        magazines[] = { "CUP_210Rnd_TE1_White_Tracer_25mm_M242_APFSDS_Rubber", "CUP_210Rnd_TE1_White_Tracer_25mm_M242_HE_Rubber" };
    };
    class CUP_Vlmg_M240_veh_Rubber: CUP_Vlmg_M240_veh {
        displayName = "M240 Rubber";
        magazines[] = { "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M_Rubber" };
    };
    class CUP_Vmlauncher_Stinger_vehicle_veh;
    class CUP_Vmlauncher_Stinger_vehicle_veh_Rubber: CUP_Vmlauncher_Stinger_vehicle_veh {
        magazines[] = { "CUP_4Rnd_Stinger_M_Rubber" };
    };
    
    #include "CfgWeaponsPrivate.hpp"
};
