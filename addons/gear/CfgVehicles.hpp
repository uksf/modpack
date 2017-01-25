class CBA_Extended_EventHandlers;
class CfgVehicles {
    class UK3CB_BAF_B_Bergen_MTP_Medic_L_A;
    class UK3CB_BAF_B_Bergen_MTP_Radio_L_B;
    class Bag_Base;
    class UKSF_B_Medic: UK3CB_BAF_B_Bergen_MTP_Medic_L_A {
        scope = 2;
        scopeArsenal = 2;
        author = "UKSF";
        displayName = "Medic Pack";
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 50;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 50;
            };
            class _xx_ACE_tourniquet {
                name = "ACE_tourniquet";
                count = 5;
            };
            class _xx_ACE_ACE_atropine {
                name = "ACE_atropine";
                count = 6;
            };
            class _xx_ACE_ACE_adenosinee {
                name = "ACE_adenosine";
                count = 6;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 25;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 25;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 5;
            };
            class _xx_ACE_bloodIV {
                name = "ACE_bloodIV";
                count = 5;
            };
            class _xx_ACE_personalAidKit {
                name = "ACE_personalAidKit";
                count = 1;
            };
            class _xx_ACE_surgicalKit {
                name = "ACE_surgicalKit";
                count = 1;
            };
        };
    };
    class UKSF_B_ATC: UK3CB_BAF_B_Bergen_MTP_Radio_L_B {
        scope = 2;
        scopeArsenal = 2;
        author = "UKSF";
        displayName = "ATC Pack";
        maximumLoad = 400;
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 10;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 10;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 5;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 2;
            };
            class _xx_ACE_personalAidKit {
                name = "ACE_personalAidKit";
                count = 1;
            };
            class _xx_ACE_surgicalKit {
                name = "ACE_surgicalKit";
                count = 1;
            };
            class _xx_ACRE_PRC117F_ID_1 {
                name = "ACRE_PRC117F_ID_1";
                count = 1;
            };
            class _xx_ACRE_PRC117F_ID_2 {
                name = "ACRE_PRC117F_ID_2";
                count = 1;
            };
        };
    };
    class B_Parachute: Bag_Base {
        mapSize = 0.55;
        _generalMacro = "B_Parachute";
        scope = 2;
        displayName = "$STR_A3_Bag_ParachuteSteerable0";
        picture = "\A3\Characters_F\data\ui\icon_b_parachute_ca.paa";
        model = "\A3\Weapons_F\Ammoboxes\Bags\Backpack_Parachute";
        backpackSimulation = "ParachuteSteerable";
        ParachuteClass = "Steerable_Parachute_F";
        maximumLoad = 320;
    };

    class I_soldier_F;
    class I_Soldier_02_F;
    class B_Helipilot_F;
    class UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base: I_soldier_F {
        scope = 1;
        scopeCurator = 0;
        author = "UKSF";
        side = 1;
        faction = "UKSF_Clan";
        identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
        displayName = "Base Soldier MTP 1Para";
        genericNames = "EnglishMen";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_1Para";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base: I_Soldier_02_F {
        scope = 1;
        scopeCurator = 0;
        author = "UKSF";
        side = 1;
        faction = "UKSF_Clan";
        identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
        displayName = "Base Soldier MTP 1Para Rolled";
        genericNames = "EnglishMen";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_1Para_ShortSleeve";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_CSMR_LongSleeve_base: UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
        displayName = "Base Soldier MTP CSMR";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_CSMR_ShortSleeve_base: UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
        displayName = "Base Soldier MTP CSMR Rolled";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR_ShortSleeve";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Path_LongSleeve_base: UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
        displayName = "Base Soldier MTP Pathfinder";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Path_ShortSleeve_base: UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
        displayName = "Base Soldier MTP Pathfinder Rolled";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Sig_LongSleeve_base: UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
        displayName = "Base Soldier MTP Signals";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Sig_ShortSleeve_base: UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
        displayName = "Base Soldier MTP Signals Rolled";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
    };
    class UK3CB_BAF_HeliPilot_RAF_base: B_Helipilot_F {
        scope = 1;
        scopeCurator = 0;
        author = "UKSF";
        side = 1;
        faction = "UKSF_Clan";
        identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
        displayName = "Base Helicopter Pilot RAF";
        genericNames = "EnglishMen";
        uniformClass = "UK3CB_BAF_U_HeliPilotCoveralls_RAF";
        model = "\A3\Characters_F\Common\coveralls.p3d";
        modelSides[] = { 3,1 };
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\helipilot_coveralls_raf.paa) };
    };
    class UKSF_Soldier_ATC_base: B_Helipilot_F {
        scope = 1;
        scopeCurator = 0;
        author = "UKSF";
        side = 1;
        faction = "UKSF_Clan";
        identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
        displayName = "ATC Base";
        genericNames = "EnglishMen";
        nakedUniform = "U_BasicBody";
        uniformClass = "UKSF_ATC";
        model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\ATC.paa) };
    };

    class CargoNet_01_ammo_base_F;
    class Land_CargoBox_V1_F;
    class UKSF_S_Empty: CargoNet_01_ammo_base_F {
        author = "UKSF";
        faction = "UKSF_Clan";
        scope = 2;
        scopeCurator = 2;
        displayName = "Resupply Crate (Empty)";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_Crate.jpg);
        maximumLoad = 100000;
        hiddenSelectionsTextures[] = { "\A3\Weapons_F\Ammoboxes\Data\AmmoBox_CO.paa","\A3\Weapons_F\Ammoboxes\Data\AmmoBox_signs_CA.paa" };
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        class TransportBackpacks {};
    };
    class UKSF_S_Ammo: UKSF_S_Empty {
        author = "UKSF";
        scope = 2;
        scopeCurator = 2;
        displayName = "Resupply Crate (Ammo)";
        class TransportMagazines {
            class _xx_UK3CB_BAF_556_30Rnd {
                magazine = "UK3CB_BAF_556_30Rnd";
                count = 50;
            };
            class _xx_UK3CB_BAF_556_30Rnd_T {
                magazine = "UK3CB_BAF_556_30Rnd_T";
                count = 50;
            };
            class _xx_UK3CB_BAF_556_200Rnd {
                magazine = "UK3CB_BAF_556_200Rnd";
                count = 15;
            };
            class _xx_UK3CB_BAF_556_200Rnd_T {
                magazine = "UK3CB_BAF_556_200Rnd_T";
                count = 15;
            };
            class _xx_UK3CB_BAF_762_100Rnd {
                magazine = "UK3CB_BAF_762_100Rnd";
                count = 15;
            };
            class _xx_UK3CB_BAF_762_100Rnd_T {
                magazine = "UK3CB_BAF_762_100Rnd_T";
                count = 15;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd";
                count = 20;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd_T {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_338_5Rnd {
                magazine = "UK3CB_BAF_338_5Rnd";
                count = 10;
            };
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 40;
            };
            class _xx_HandGrenade {
                magazine = "HandGrenade";
                count = 20;
            };
            class _xx_SmokeShell {
                magazine = "SmokeShell";
                count = 20;
            };
            class _xx_SmokeShellRed {
                magazine = "SmokeShellRed";
                count = 20;
            };
            class _xx_SmokeShellGreen {
                magazine = "SmokeShellGreen";
                count = 20;
            };
        };
        class TransportWeapons {
            class _xx_UK3CB_BAF_NLAW_Launcher {
                weapon = "UK3CB_BAF_NLAW_Launcher";
                count = 5;
            };
            class _xx_UK3CB_BAF_AT4_CS_AT_Launcher {
                weapon = "UK3CB_BAF_AT4_CS_AT_Launcher";
                count = 5;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 5;
            };
        };
    };
    class UKSF_S_Medic: UKSF_S_Empty {
        author = "UKSF";
        scope = 2;
        scopeCurator = 2;
        displayName = "Resupply Crate (Medical)";
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 50;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 50;
            };
            class _xx_ACE_quikclot {
                name = "ACE_quikclot";
                count = 50;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 30;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 30;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 20;
            };
            class _xx_ACE_tourniquet {
                name = "ACE_tourniquet";
                count = 10;
            };
            class _xx_ACE_ACE_atropine {
                name = "ACE_atropine";
                count = 20;
            };
            class _xx_ACE_ACE_adenosinee {
                name = "ACE_adenosine";
                count = 20;
            };
            class _xx_ACE_bloodIV {
                name = "ACE_bloodIV";
                count = 20;
            };
            class _xx_ACE_personalAidKit {
                name = "ACE_personalAidKit";
                count = 1;
            };
            class _xx_ACE_surgicalKit {
                name = "ACE_surgicalKit";
                count = 1;
            };
        };
    };
    class UKSF_S_AmmoMedic: UKSF_S_Empty {
        author = "UKSF";
        scope = 2;
        scopeCurator = 2;
        displayName = "Resupply Crate (Ammo & Medical)";
        class TransportMagazines {
            class _xx_UK3CB_BAF_556_30Rnd {
                magazine = "UK3CB_BAF_556_30Rnd";
                count = 30;
            };
            class _xx_UK3CB_BAF_556_30Rnd_T {
                magazine = "UK3CB_BAF_556_30Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_556_200Rnd {
                magazine = "UK3CB_BAF_556_200Rnd";
                count = 10;
            };
            class _xx_UK3CB_BAF_556_200Rnd_T {
                magazine = "UK3CB_BAF_556_200Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_100Rnd {
                magazine = "UK3CB_BAF_762_100Rnd";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_100Rnd_T {
                magazine = "UK3CB_BAF_762_100Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd_T {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_338_5Rnd {
                magazine = "UK3CB_BAF_338_5Rnd";
                count = 10;
            };
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 30;
            };
            class _xx_HandGrenade {
                magazine = "HandGrenade";
                count = 20;
            };
            class _xx_SmokeShell {
                magazine = "SmokeShell";
                count = 10;
            };
            class _xx_SmokeShellRed {
                magazine = "SmokeShellRed";
                count = 10;
            };
            class _xx_SmokeShellGreen {
                magazine = "SmokeShellGreen";
                count = 10;
            };
        };
        class TransportWeapons {
            class _xx_UK3CB_BAF_NLAW_Launcher {
                weapon = "UK3CB_BAF_NLAW_Launcher";
                count = 3;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 3;
            };
        };
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 30;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 30;
            };
            class _xx_ACE_quikclot {
                name = "ACE_quikclot";
                count = 30;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 10;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 15;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 10;
            };
            class _xx_ACE_ACE_atropine {
                name = "ACE_atropine";
                count = 10;
            };
            class _xx_ACE_ACE_adenosinee {
                name = "ACE_adenosine";
                count = 10;
            };
        };
    };
    class UKSF_S_Radios: UKSF_S_Empty {
        author = "UKSF";
        scope = 2;
        scopeCurator = 2;
        displayName = "ACRE Radios";
        class eventhandlers {
            init = "this addItemCargoGlobal [""ACRE_PRC117F"", 10]";
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {
            class _xx_ACRE_PRC177F {
                name = "ACRE_PRC117F";
                count = 10;
            };
            class _xx_ACRE_PRC152 {
                name = "ACRE_PRC152";
                count = 25;
            };
            class _xx_ACRE_PRC343 {
                name = "ACRE_PRC343";
                count = 25;
            };
        };
        class TransportBackpacks {
            class _xx_UKSF_RadioPack {
                backpack = "B_Parachute";
                count = 5;
            };
        };
    };
    class UK3CB_BAF_Vehicles_Servicing_Aircraft_Point: Land_CargoBox_V1_F {
        scope = 2;
        scopeCurator = 2;
        faction = "UKSF_Clan";
        displayName = "Aircraft Servicing Point";
        editorPreview = QPATHTOEF(common,data\previews\UK3CB_BAF_Vehicles_Servicing_Aircraft_Point.jpg);
    };

    class TargetP_Inf_F;
    class UKSF_Target_Nopopup: TargetP_Inf_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Figure 11 Target - No Popup";
        class EventHandlers {
            hitPart = "";
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };
};