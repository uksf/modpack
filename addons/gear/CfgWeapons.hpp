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

    class LMG_Zafir_F;
    class UK3CB_BAF_L7A2: LMG_Zafir_F {
        magazines[] = {
            "UK3CB_BAF_762_200Rnd_T",
            "UK3CB_BAF_762_200Rnd",
            "UK3CB_BAF_762_200Rnd_Blank",
            "UK3CB_BAF_762_100Rnd_T",
            "UK3CB_BAF_762_100Rnd",
            "UK3CB_BAF_762_100Rnd_Blank",
            "UK3CB_BAF_762_100Rnd_EL",
            "UK3CB_BAF_762_100Rnd_T_EL",
            "UK3CB_BAF_762_200Rnd_EL",
            "UK3CB_BAF_762_200Rnd_T_EL"
        };
    };
    class LMG_RCWS;
    class UK3CB_BAF_L7A2_veh: LMG_RCWS {
        magazines[] = {
            "UK3CB_BAF_762_200Rnd_T",
            "UK3CB_BAF_762_200Rnd",
            "UK3CB_BAF_762_200Rnd_Blank",
            "UK3CB_BAF_762_100Rnd_T",
            "UK3CB_BAF_762_100Rnd",
            "UK3CB_BAF_762_100Rnd_Blank",
            "UK3CB_BAF_762_100Rnd_EL",
            "UK3CB_BAF_762_100Rnd_T_EL",
            "UK3CB_BAF_762_200Rnd_EL",
            "UK3CB_BAF_762_200Rnd_T_EL"
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
    class UK3CB_BAF_L135A1;
    class UK3CB_BAF_L135A1_LRPS: UK3CB_BAF_L135A1 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "asdg_OpticRail_rifles";
                item = "optic_LRPS";
            };
        };
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
            "CUP_8Rnd_AGM114K_Hellfire_II_M",
            "CUP_4Rnd_AGM114K_Hellfire_II_M",
            "CUP_2Rnd_AGM114K_Hellfire_II_M",
            "CUP_1Rnd_AGM114K_Hellfire_II_M"
        };
    };
    class CUP_Vmlauncher_AGM114L_veh: CUP_Vmlauncher_AGM114K_veh {
        displayName = "AGM-114L Hellfire II";
        magazines[] = {
            "CUP_8Rnd_AGM114L_Hellfire_II_M",
            "CUP_4Rnd_AGM114L_Hellfire_II_M",
            "CUP_2Rnd_AGM114L_Hellfire_II_M",
            "CUP_1Rnd_AGM114L_Hellfire_II_M"
        };
    };
    class CUP_AGM114L_Hellfire_II_Launcher_W: CUP_Vmlauncher_AGM114L_veh {};
    class CUP_Vmlauncher_AGM114N_veh: CUP_Vmlauncher_AGM114K_veh {
        displayName = "AGM-114N Hellfire II";
        magazines[] = {
            "CUP_8Rnd_AGM114N_Hellfire_II_M",
            "CUP_4Rnd_AGM114N_Hellfire_II_M"
        };
    };
    class CUP_AGM114N_Hellfire_II_Launcher_W: CUP_Vmlauncher_AGM114N_veh {};

    class RocketPods;
    class GBU12BombLauncher: RocketPods {
        magazines[] = { "1Rnd_GBU12_LGB", "2Rnd_GBU12_LGB", "2Rnd_GBU12_LGB_MI10" };
    };

    #include "CfgWeaponsPrivate.hpp"
};