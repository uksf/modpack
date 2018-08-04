class CfgWeapons {
    class Uniform_Base;
    class UniformItem;
    class HeadgearItem;
    class VestItem;

    class UK3CB_BAF_U_CombatUniform_MTP_TShirt_RM;
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
    class U_I_CombatUniform;
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
    class U_I_CombatUniform_shortsleeve;
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
    
    class U_B_HeliPilotCoveralls;
    class UK3CB_BAF_U_HeliPilotCoveralls_RAF: U_B_HeliPilotCoveralls {
        scope = 2;
        author = "UKSF";
        displayName = "Pilot Coveralls [BAF]";
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_civilian_F.p3d";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\pilot_coveralls_raf.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UK3CB_BAF_HeliPilot_RAF_base";
            containerClass = "Supply40";
            mass = 60;
        };
    };
    class UKSF_U_PilotCoveralls_7: UK3CB_BAF_U_HeliPilotCoveralls_RAF {
        displayName = "Pilot Coveralls (7 Sqn.)";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\pilot_coveralls_7.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UKSF_B_Pilot_7";
            containerClass = "Supply40";
            mass = 50;
        };
    };
    class UK3CB_BAF_U_CombatUniform_MTP;
    class UKSF_U_PilotUniform_656: UK3CB_BAF_U_CombatUniform_MTP {
        displayName = "Pilot Uniform (656 Sqn.)";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\pilot_uniform_656.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UKSF_B_Pilot_656";
            containerClass = "Supply100";
            mass = 50;
        };
    };
    class U_I_pilotCoveralls;
    class UKSF_U_PilotGSuit_617: U_I_pilotCoveralls {
        author = "UKSF";
        displayName = "Pilot G-Suit (617 Sqn.)";
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\pilot_gsuit_617.paa) };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UKSF_B_Pilot_617";
            containerClass = "Supply150";
            mass = 80;
        };
        ACE_GForceCoef = 0.2;
    };
    class UKSF_U_RAF_Blues: Uniform_Base {
        scope = 2;
        author = "UKSF";
        displayName = "RAF Blues";
        picture = QPATHTOF(UI\icon_uniform_atc_ca.paa);
        model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "UKSF_B_ATC_base";
            containerClass = "Supply40";
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
            containerClass = "Supply100";
            mass = 40;
            armor = 20;
            passThrough = 1;
            hiddenSelections[] = { "camo" };
        };
    };
    class Vest_NoCamo_Base;
    class V_PlateCarrier1_rgr: Vest_NoCamo_Base {
        class ItemInfo;
    };
    class V_PlateCarrier2_rgr: V_PlateCarrier1_rgr {};
    class UK3CB_BAF_V_Osprey_Base: V_PlateCarrier2_rgr {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 16; // 12
                    PassThrough = 0.4;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 30; // 26, 20
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 30; // 26, 20
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 26; // 20
                    passThrough = 0.2; // 0.3
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2; // 0.3
                };
            };
        };
    };    
    class V_PlateCarrierL_CTRG: V_PlateCarrier1_rgr {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 12;
                    PassThrough = 0.4;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 26; // 16
                    PassThrough = 0.3;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 26; // 16
                    PassThrough = 0.3;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 22; // 16
                    passThrough = 0.3;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.3;
                };
            };
        };
    };    
    class V_PlateCarrierH_CTRG: V_PlateCarrier2_rgr {
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Neck {
                    HitpointName = "HitNeck";
                    armor = 18;
                    PassThrough = 0.3;
                };
                class Chest {
                    HitpointName = "HitChest";
                    armor = 34; // 20
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 34; // 20
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 34; // 20
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };

	class AFG_1996Leaf_BattleDressUniform : Uniform_Base {};
};
