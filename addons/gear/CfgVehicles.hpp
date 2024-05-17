class CfgVehicles {
    class UK3CB_BAF_B_Bergen_MTP_Medic_L_A;
    class UK3CB_BAF_B_Bergen_MTP_Radio_L_B;
    class UKSF_B_Bergen_Medic : UK3CB_BAF_B_Bergen_MTP_Medic_L_A {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen MTP Medic [BAF]";
        class TransportItems {
            MACRO_ADDITEM(ACE_elasticBandage,50);
            MACRO_ADDITEM(ACE_packingBandage,50);
            MACRO_ADDITEM(ACE_tourniquet,5);
            MACRO_ADDITEM(ACE_atropine,6);
            MACRO_ADDITEM(ACE_adenosine,6);
            MACRO_ADDITEM(ACE_morphine,25);
            MACRO_ADDITEM(ACE_epinephrine,25);
            MACRO_ADDITEM(ACE_bloodIV_500,5);
            MACRO_ADDITEM(ACE_bloodIV,5);
            MACRO_ADDITEM(ACE_personalAidKit,1);
            MACRO_ADDITEM(ACE_surgicalKit,1);
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C;
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR : UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen MTP AR [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_556_200Rnd,2);
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_MG : UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR {
        displayName = "Bergen MTP MG [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,2);
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AA : UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR {
        displayName = "Bergen MTP AA [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_Stinger_M,1);
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_Engineer_L_A;
    class UK3CB_BAF_B_Bergen_MTP_Engineer_L_A_Toolkit : UK3CB_BAF_B_Bergen_MTP_Engineer_L_A {
        displayName = "Bergen MTP Toolkit [BAF]";
        class TransportItems {
            MACRO_ADDITEM(ToolKit,1);
        };
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A;
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR : UK3CB_BAF_B_Bergen_DPMW_Rifleman_A {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen DPM Wdl AR [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_556_200Rnd,2);
        };
    };
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_MG : UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl MG [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,2);
        };
    };
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AA : UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl AA [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_Stinger_M,1);
        };
    };
    class UKSF_B_Bergen_Medic_DPMW : UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl Medic [BAF]";
        class TransportItems {
            MACRO_ADDITEM(ACE_elasticBandage,50);
            MACRO_ADDITEM(ACE_packingBandage,50);
            MACRO_ADDITEM(ACE_tourniquet,5);
            MACRO_ADDITEM(ACE_atropine,6);
            MACRO_ADDITEM(ACE_adenosine,6);
            MACRO_ADDITEM(ACE_morphine,25);
            MACRO_ADDITEM(ACE_epinephrine,25);
            MACRO_ADDITEM(ACE_bloodIV_500,5);
            MACRO_ADDITEM(ACE_bloodIV,5);
            MACRO_ADDITEM(ACE_personalAidKit,1);
            MACRO_ADDITEM(ACE_surgicalKit,1);
        };
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_Toolkit : UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR {
        displayName = "Bergen DPM Wdl Toolkit [BAF]";
        class TransportItems {
            MACRO_ADDITEM(ToolKit,1);
        };
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A;
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR : UK3CB_BAF_B_Bergen_DDPM_Rifleman_A {
        scope = 1;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Bergen DDPM AR [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_556_200Rnd,2);
        };
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_MG : UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR {
        displayName = "Bergen DDPM MG [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,2);
        };
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AA : UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR {
        displayName = "Bergen DDPM AA [BAF]";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_Stinger_M,1);
        };
    };
    class UKSF_B_Bergen_Medic_DDPM : UK3CB_BAF_B_Bergen_DDPM_Rifleman_A {
        displayName = "Bergen DDPM Medic [BAF]";
        class TransportItems {
            MACRO_ADDITEM(ACE_elasticBandage,50);
            MACRO_ADDITEM(ACE_packingBandage,50);
            MACRO_ADDITEM(ACE_tourniquet,5);
            MACRO_ADDITEM(ACE_atropine,6);
            MACRO_ADDITEM(ACE_adenosine,6);
            MACRO_ADDITEM(ACE_morphine,25);
            MACRO_ADDITEM(ACE_epinephrine,25);
            MACRO_ADDITEM(ACE_bloodIV_500,5);
            MACRO_ADDITEM(ACE_bloodIV,5);
            MACRO_ADDITEM(ACE_personalAidKit,1);
            MACRO_ADDITEM(ACE_surgicalKit,1);
        };
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_Toolkit : UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR {
        displayName = "Bergen DDPM Toolkit [BAF]";
        class TransportItems {
            MACRO_ADDITEM(ToolKit,1);
        };
        class TransportMagazines {};
    };
    class UK3CB_BAF_B_Carryall_MTP;
    class UKSF_B_Carryall_Mortar_MTP : UK3CB_BAF_B_Carryall_MTP {
        displayName = "Carryall MTP (Mortar)";
        maximumLoad = 400;
        mass = 75;
    };
    class VSM_Multicam_carryall;
    class GVAR(bag_sniper) : VSM_Multicam_carryall {
        author = "UKSF";
        displayName = "Sniper Bag (AXMC)";
        maximumLoad = 500;
        mass = 75;
    };

    class I_soldier_F;
    class I_Soldier_02_F;
    class B_Helipilot_F;
    class UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base : I_soldier_F {
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
    class UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base : I_Soldier_02_F {
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
    class UK3CB_BAF_Soldier_MTP_CSMR_LongSleeve_base : UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
        displayName = "Base Soldier MTP CSMR";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_CSMR_ShortSleeve_base : UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
        displayName = "Base Soldier MTP CSMR Rolled";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR_ShortSleeve";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Path_LongSleeve_base : UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
        displayName = "Base Soldier MTP Pathfinder";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Path_ShortSleeve_base : UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
        displayName = "Base Soldier MTP Pathfinder Rolled";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Sig_LongSleeve_base : UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
        displayName = "Base Soldier MTP Signals";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
    };
    class UK3CB_BAF_Soldier_MTP_Sig_ShortSleeve_base : UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
        displayName = "Base Soldier MTP Signals Rolled";
        uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve";
        hiddenSelections[] = { "Camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
    };
    class UKSF_B_ATC_base : B_Helipilot_F {
        scope = 1;
        scopeCurator = 0;
        author = "UKSF";
        side = 1;
        faction = "CUP_B_GB";
        identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
        displayName = "ATC Base";
        genericNames = "EnglishMen";
        nakedUniform = "U_BasicBody";
        uniformClass = "UKSF_U_RAF_Blues";
        model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
        hiddenSelections[] = { "camo", "insignia" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\ATC.paa) };
    };

    class Bag_Base;
    class tfw_ilbe_b : Bag_Base {
        maximumLoad = 270;  // Original: 240, Kitbag: 280 (Slightly smaller)
        mass = 60;          // Original: 80, Kitbag: 50 (Slightly heavier due to aerial)
    };

    class Supply500;
    class Supply1000 : Supply500 {
        author = "Bohemia Interactive";
        maximumLoad = 1000;
    };

    class B_Messenger_IDAP_Medical_F;
    class GVAR(trauma_bag) : B_Messenger_IDAP_Medical_F {
        scope = 2;
        scopeArsenal = 0;
        author = "UKSF";
        displayName = "Trauma Bag";
        maximumLoad = 315;
        class TransportItems {
            MACRO_ADDITEM(ACE_elasticBandage,60);
            MACRO_ADDITEM(ACE_packingBandage,60);
            MACRO_ADDITEM(ACE_adenosine,5);
            MACRO_ADDITEM(ACE_morphine,5);
            MACRO_ADDITEM(ACE_epinephrine,5);
            MACRO_ADDITEM(ACE_bloodIV,10);
            MACRO_ADDITEM(ACE_bloodIV_500,10);
            MACRO_ADDITEM(ACE_bloodIV_250,10);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(ACE_painkillers,5);
        };
    };
};
