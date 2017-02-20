class CfgVehicles {
    class UK3CB_BAF_B_Bergen_MTP_Medic_L_A;
    class UK3CB_BAF_B_Bergen_MTP_Radio_L_B;
    class Bag_Base;
    class UKSF_B_Bergen_Medic: UK3CB_BAF_B_Bergen_MTP_Medic_L_A {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen MTP Medic [BAF]";
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
    class UKSF_B_Bergen_ATC: UK3CB_BAF_B_Bergen_MTP_Radio_L_B {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen MTP ATC [BAF]";
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
        scope = 2;
        maximumLoad = 320;
    };
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C;
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR: UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen MTP AR [BAF]";
        class TransportMagazines {
            class _xx_UK3CB_BAF_556_200Rnd {
                magazine = "UK3CB_BAF_556_200Rnd";
                count = 2;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_MG: UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR {
        displayName = "Bergen MTP MG [BAF]";
        class TransportMagazines {
            class _xx_UK3CB_BAF_762_100Rnd_T {
                magazine = "UK3CB_BAF_762_100Rnd_T";
                count = 2;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AA: UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR {
        displayName = "Bergen MTP AA [BAF]";
        class TransportMagazines {
            class _xx_CUP_Stinger_M {
                magazine = "CUP_Stinger_M";
                count = 1;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_Engineer_L_A;
    class UK3CB_BAF_B_Bergen_MTP_Engineer_L_A_Toolkit: UK3CB_BAF_B_Bergen_MTP_Engineer_L_A {
        displayName = "Bergen MTP Toolkit [BAF]";
        class TransportItems {
            class _xx_ToolKit {
                name = "ToolKit";
                count = 1;
            };
        };
        class TransportMagazines {};
    }; 
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A;
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR: UK3CB_BAF_B_Bergen_DPMW_Rifleman_A {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen DPM Wdl AR [BAF]";
        class TransportMagazines {
            class _xx_UK3CB_BAF_556_200Rnd {
                magazine = "UK3CB_BAF_556_200Rnd";
                count = 2;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_MG: UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl MG [BAF]";
        class TransportMagazines {
            class _xx_UK3CB_BAF_762_100Rnd_T {
                magazine = "UK3CB_BAF_762_100Rnd_T";
                count = 2;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AA: UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl AA [BAF]";
        class TransportMagazines {
            class _xx_CUP_Stinger_M {
                magazine = "CUP_Stinger_M";
                count = 1;
            };
        };
    };
    class UKSF_B_Bergen_Medic_DPMW: UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl Medic [BAF]";
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
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_Toolkit: UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl Toolkit [BAF]";
        class TransportItems {
            class _xx_ToolKit {
                name = "ToolKit";
                count = 1;
            };
        };
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A;
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR: UK3CB_BAF_B_Bergen_DDPM_Rifleman_A {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen DDPM AR [BAF]";
        class TransportMagazines {
            class _xx_UK3CB_BAF_556_200Rnd {
                magazine = "UK3CB_BAF_556_200Rnd";
                count = 2;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_MG: UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR {
        displayName = "Bergen DDPM MG [BAF]";
        class TransportMagazines {
            class _xx_UK3CB_BAF_762_100Rnd_T {
                magazine = "UK3CB_BAF_762_100Rnd_T";
                count = 2;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AA: UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR {
        displayName = "Bergen DDPM AA [BAF]";
        class TransportMagazines {
            class _xx_CUP_Stinger_M {
                magazine = "CUP_Stinger_M";
                count = 1;
            };
        };
    };    
    class UKSF_B_Bergen_Medic_DDPM: UK3CB_BAF_B_Bergen_DDPM_Rifleman_A {
        displayName = "Bergen DDPM Medic [BAF]";
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
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_Toolkit: UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR {
        displayName = "Bergen DDPM Toolkit [BAF]";
        class TransportItems {
            class _xx_ToolKit {
                name = "ToolKit";
                count = 1;
            };
        };
        class TransportMagazines {};
    };
    class B_AssaultPack_blk;
    class B_AssaultPack_VR_AT: B_AssaultPack_blk {
        scopeArsenal = 1;
        displayName = "AT Pack (VR)";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)" };
        hiddenSelectionsMaterials[] = { "\A3\Characters_F_Bootcamp\Common\Data\O_VR_Soldier_F.rvmat" };
        maximumLoad = 500;
        class TransportMagazines {
            class _xx_CUP_SMAW_HEAT_M_Rubber {
                magazine = "CUP_SMAW_HEAT_M_Rubber";
                count = 2;
            };
        };
    };
    class B_AssaultPack_VR_AA: B_AssaultPack_VR_AT {
        scopeArsenal = 1;
        displayName = "AA Pack (VR)";
        class TransportMagazines {
            class _xx_CUP_Stinger_M_Rubber {
                magazine = "CUP_Stinger_M_Rubber";
                count = 2;
            };
        };
    };

    class I_soldier_F;
    class I_Soldier_02_F;
    class B_Helipilot_F;
    class UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base: I_soldier_F {
        scope = 1;
        scopeCurator = 0;
        author = "UKSF";
        side = 1;
        faction = "CUP_B_GB";
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
        faction = "CUP_B_GB";
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
        faction = "CUP_B_GB";
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
        faction = "CUP_B_GB";
        identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
        displayName = "ATC Base";
        genericNames = "EnglishMen";
        nakedUniform = "U_BasicBody";
        uniformClass = "UKSF_ATC";
        model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
        hiddenSelections[] = { "Camo" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\ATC.paa) };
    };
    class Supply500;
    class Supply1000: Supply500 {
        author = "Bohemia Interactive";
        _generalMacro = "Supply1000";
        maximumLoad = 1000;
    };

    class CargoNet_01_ammo_base_F;
    class Land_CargoBox_V1_F;
    class UKSF_S_Empty: CargoNet_01_ammo_base_F {
        author = "UKSF";
        faction = "CUP_B_GB";
        scope = 2;
        scopeCurator = 2;
        displayName = "Resupply Crate (Empty)";
        //editorPreview = QPATHTOEF(common,data\previews\UKSF_Crate.jpg);
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
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
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

    class TargetP_Inf_F;
    class UKSF_Target_Nopopup: TargetP_Inf_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Figure 11 Target - No Popup";
        class EventHandlers {
            hitPart = "";
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
        };
    };

    class CUP_USBasicAmmunitionBox;
    class CUP_USLaunchersBox: CUP_USBasicAmmunitionBox {
        class TransportMagazines {
            class _xx_M136_M {
                magazine = "CUP_M136_M";
                count = 45;
            };
            class _xx_Stinger_M {
                magazine = "CUP_Stinger_M";
                count = 4;
            };
            class _xx_SMAW_HEAA_M {
                magazine = "CUP_SMAW_HEAA_M";
                count = 3;
            };
            class _xx_SMAW_HEDP_M {
                magazine = "CUP_SMAW_HEDP_M";
                count = 3;
            };
        };
        class TransportWeapons {
            class _xx_M136 {
                weapon = "CUP_M136";
                count = 15;
            };
            class _xx_Stinger {
                weapon = "CUP_Stinger";
                count = 4;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 1;
            };
            class _xx_UK3CB_BAF_Javelin_CLU {
                weapon = "UK3CB_BAF_Javelin_CLU";
                count = 1;
            };
            class _xx_SMAW {
                weapon = "CUP_SMAW";
                count = 2;
            };
        };
    };

    class CUP_ReammoBox_EP1;
    class CUP_USLaunchers_EP1: CUP_ReammoBox_EP1 {
        class TransportMagazines {
            class _xx_M136_M {
                magazine = "CUP_M136_M";
                count = 20;
            };
            class _xx_MAAWS_HEAT_M {
                magazine = "CUP_MAAWS_HEAT_M";
                count = 10;
            };
            class _xx_MAAWS_HEDP_M {
                magazine = "CUP_MAAWS_HEDP_M";
                count = 10;
            };
            class _xx_Stinger_M {
                magazine = "CUP_Stinger_M";
                count = 10;
            };
            class _xx_1Rnd_HE_M203 {
                magazine = "CUP_1Rnd_HE_M203";
                count = 80;
            };
            class _xx_6Rnd_HE_M203 {
                magazine = "CUP_6Rnd_HE_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareWhite_M203 {
                magazine = "CUP_6Rnd_FlareWhite_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareGreen_M203 {
                magazine = "CUP_6Rnd_FlareGreen_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareRed_M203 {
                magazine = "CUP_6Rnd_FlareRed_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareYellow_M203 {
                magazine = "CUP_6Rnd_FlareYellow_M203";
                count = 30;
            };
            class _xx_6Rnd_Smoke_M203 {
                magazine = "CUP_6Rnd_Smoke_M203";
                count = 30;
            };
            class _xx_6Rnd_SmokeRed_M203 {
                magazine = "CUP_6Rnd_SmokeRed_M203";
                count = 30;
            };
            class _xx_6Rnd_SmokeGreen_M203 {
                magazine = "CUP_6Rnd_SmokeGreen_M203";
                count = 30;
            };
            class _xx_6Rnd_SmokeYellow_M203 {
                magazine = "CUP_6Rnd_SmokeYellow_M203";
                count = 30;
            };
            class _xx_1Rnd_StarFlare_White_M203 {
                magazine = "CUP_1Rnd_StarFlare_White_M203";
                count = 10;
            };
            class _xx_1Rnd_StarFlare_Red_M203 {
                magazine = "CUP_1Rnd_StarFlare_Red_M203";
                count = 10;
            };
            class _xx_1Rnd_StarFlare_Green_M203 {
                magazine = "CUP_1Rnd_StarFlare_Green_M203";
                count = 10;
            };
            class _xx_1Rnd_StarCluster_White_M203 {
                magazine = "CUP_1Rnd_StarCluster_White_M203";
                count = 10;
            };
            class _xx_1Rnd_StarCluster_Red_M203 {
                magazine = "CUP_1Rnd_StarCluster_Red_M203";
                count = 10;
            };
            class _xx_1Rnd_StarCluster_Green_M203 {
                magazine = "CUP_1Rnd_StarCluster_Green_M203";
                count = 10;
            };
            class _xx_HandGrenade_M67 {
                magazine = "CUP_HandGrenade_M67";
                count = 50;
            };
        };
        class TransportWeapons {
            class _xx_M136 {
                weapon = "CUP_M136";
                count = 2;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 1;
            };
            class _xx_UK3CB_BAF_Javelin_CLU {
                weapon = "UK3CB_BAF_Javelin_CLU";
                count = 1;
            };
            class _xx_MAAWS {
                weapon = "CUP_MAAWS";
                count = 2;
            };
            class _xx_Stinger {
                weapon = "CUP_Stinger";
                count = 2;
            };
            class _xx_M32_EP1 {
                weapon = "CUP_M32_EP1";
                count = 2;
            };
            class _xx_Mk13_EP1 {
                weapon = "CUP_Mk13_EP1";
                count = 4;
            };
        };
    };

    class StaticWeapon;
    class StaticMGWeapon: StaticWeapon {
        class Turrets;
    };
    class UK3CB_BAF_Static_MG_Base: StaticMGWeapon {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
        typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class UK3CB_BAF_Static_L7A2_Base: UK3CB_BAF_Static_MG_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = { "CUP_Vlmg_M240_veh" };
            };
        };
    };
    class UK3CB_BAF_Static_L7A2_Low;
    class UK3CB_BAF_Static_L7A2_Deployed_Low: UK3CB_BAF_Static_L7A2_Low {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L7A2_Mid;
    class UK3CB_BAF_Static_L7A2_Deployed_Mid: UK3CB_BAF_Static_L7A2_Mid {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L7A2_High;
    class UK3CB_BAF_Static_L7A2_Deployed_High: UK3CB_BAF_Static_L7A2_High {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L111A1_Base: UK3CB_BAF_Static_MG_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = { "CUP_Vhmg_M2_veh" };
            };
        };
    };
    class UK3CB_BAF_Static_L111A1_Low;
    class UK3CB_BAF_Static_L111A1_Deployed_Low: UK3CB_BAF_Static_L111A1_Low {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L111A1_Mid;
    class UK3CB_BAF_Static_L111A1_Deployed_Mid: UK3CB_BAF_Static_L111A1_Mid {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L111A1_High;
    class UK3CB_BAF_Static_L111A1_Deployed_High: UK3CB_BAF_Static_L111A1_High {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L134A1_Base: UK3CB_BAF_Static_MG_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = { "CUP_Vgmg_MK19_veh" };
            };
        };
    };
    class UK3CB_BAF_Static_L134A1_Low;
    class UK3CB_BAF_Static_L134A1_Deployed_Low: UK3CB_BAF_Static_L134A1_Low {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L134A1_Mid;
    class UK3CB_BAF_Static_L134A1_Deployed_Mid: UK3CB_BAF_Static_L134A1_Mid {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L134A1_High;
    class UK3CB_BAF_Static_L134A1_Deployed_High: UK3CB_BAF_Static_L134A1_High {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class Mortar_01_base_F;
    class UK3CB_BAF_Static_Mortar_Base: Mortar_01_base_F {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
        typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    };
    class UK3CB_BAF_Static_L16;
    class UK3CB_BAF_Static_L16_Deployed: UK3CB_BAF_Static_L16 {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_M6;
    class UK3CB_BAF_Static_M6_Deployed: UK3CB_BAF_Static_M6 {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };

    #include "CfgVehiclesPrivate.hpp"
};
