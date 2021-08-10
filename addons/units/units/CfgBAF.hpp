// CUP BAF
class CUP_Creatures_Military_BAF_Soldier_Base: SoldierWB {
    author = "$STR_CUP_AUTHOR_STRING";
    faction = "CUP_B_GB";
    identityTypes[] = { "LanguageENGB_F","Head_NATO","G_GUERIL_default" };
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    icon = "iconMan";
    cost = 100000;
    class Wounds {
        tex[] = {};
        mat[] = {
            "A3\Characters_F\BLUFOR\Data\clothing1.rvmat",
            "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
            "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
            "A3\Characters_F\Common\Data\basicbody.rvmat",
            "A3\Characters_F\Common\Data\basicbody_injury.rvmat",
            "A3\Characters_F\Common\Data\basicbody_injury.rvmat",
            "A3\characters_f\common\data\coveralls.rvmat",
            "A3\Characters_F\Common\Data\coveralls_injury.rvmat",
            "A3\Characters_F\Common\Data\coveralls_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_old.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
        };
    };
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        init = "";
    };
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
};

// MTP
class CUP_B_BAF_Soldier_01_MTP: CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 1 - MTP";
    nameSound = "veh_infantry_officer_s";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_02_MTP: CUP_B_BAF_Soldier_01_MTP {
    displayName = "Soldier 2 - MTP";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Ghillie_RM";
    model = "A3\Characters_F_Beta\INDEP\ia_sniper.p3d";
};
class CUP_B_BAF_Soldier_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Rifleman (MTP)";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_GL_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Night_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Light_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Backpack_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAR_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AMG_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAT_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AHAT_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAA_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Officer_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Officer (MTP)";
    accuracy = 3.6;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_officer_s" };
            speechPlural[] = { "veh_infantry_officer_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_officer_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_officer_p";
    nameSound = "veh_infantry_officer_s";
    icon = "iconManOfficer";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Officer_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_SL_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Section Leader";
    accuracy = 3.6;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_officer_s" };
            speechPlural[] = { "veh_infantry_officer_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_officer_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_officer_p";
    nameSound = "veh_infantry_officer_s";
    icon = "iconManLeader";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_SL_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_TL_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AR_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Automatic Rifleman (MTP)";
    threat[] = { 1,0.1,0.3 };
    accuracy = 3.7;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_MG_s" };
            speechPlural[] = { "veh_infantry_MG_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_MG_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_MG_p";
    nameSound = "veh_infantry_MG_s";
    icon = "iconManMG";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AR_MTP.jpg);
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AR";
    weapons[] = { "UK3CB_BAF_L110A3_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L110A3_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_MG_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Machinegunner (MTP)";
    threat[] = { 1,0.1,0.6 };
    accuracy = 3.7;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_MG_s" };
            speechPlural[] = { "veh_infantry_MG_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_MG_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_MG_p";
    nameSound = "veh_infantry_MG_s";
    icon = "iconManMG";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_MG_MTP.jpg);
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_MG";
    weapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_AT_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "AT Specialist (MTP)";
    threat[] = { 1,0.8,0.1 };
    accuracy = 3.5;
    camouflage = 2;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AT_MTP.jpg);
    backpack = "";
    weapons[] = { "launch_NLAW_F","UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "launch_NLAW_F","UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_HAT_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "AT Specialist (Javelin) (MTP)";
    threat[] = { 1,1,0.1 };
    accuracy = 3.5;
    camouflage = 2.1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_HAT_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","UK3CB_BAF_Javelin_Launcher" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","UK3CB_BAF_Javelin_Launcher" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell","UK3CB_BAF_Javelin_Mag" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell","UK3CB_BAF_Javelin_Mag" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_AA_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "AA Specialist (MTP)";
    threat[] = { 1,0.1,1 };
    accuracy = 3.5;
    camouflage = 2.1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AA_MTP.jpg);
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_C_AA";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","CUP_launch_FIM92Stinger" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","CUP_launch_FIM92Stinger" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_Marksman_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Marksman (MTP)";
    threat[] = { 1,0.1,0.1 };
    accuracy = 3.9;
    camouflage = 1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_Marksman_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Rangefinder","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Rangefinder","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_scout_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Sniper_MTP: CUP_B_BAF_Soldier_02_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Sniper (LRR) (MTP)";
    threat[] = { 1,0.3,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Sniper_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L115A3_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L115A3_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
};
class CUP_B_BAF_Sniper_AS50_MTP: CUP_B_BAF_Soldier_02_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Sniper (L135A1) (MTP)";
    threat[] = { 1,0.5,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Sniper_AS50_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L135A1_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L135A1_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
};
class CUP_B_BAF_Sniper_AS50_TWS_MTP: CUP_B_BAF_Sniper_AS50_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Spotter_MTP: CUP_B_BAF_Soldier_02_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Spotter (MTP)";
    threat[] = { 1,0.3,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Spotter_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
};
class CUP_B_BAF_Spotter_L85TWS_MTP: CUP_B_BAF_Spotter_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Pilot_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Crew_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Crewman (MTP)";
    accuracy = 3.4;
    camouflage = 1.4;
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Crew_MTP.jpg);
    weapons[] = { "UK3CB_BAF_L22A2_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L22A2_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_CrewHelmet_A" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_CrewHelmet_A" };
};
class CUP_B_BAF_Medic_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Medic (MTP)";
    accuracy = 3.7;
    attendant = 1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_medic_s" };
            speechPlural[] = { "veh_infantry_medic_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_medic_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_medic_p";
    nameSound = "veh_infantry_medic_s";
    icon = "iconManMedic";
    picture = "pictureHeal";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Medic_MTP.jpg);
    backpack = "UKSF_B_Bergen_Medic";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Soldier_JTAC_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "JTAC (MTP)";
    accuracy = 3.9;
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_JTAC_MTP.jpg);
    backpack = "UK3CB_BAF_B_Bergen_MTP_JTAC_L_A";
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","UK3CB_BAF_Soflam_Laserdesignator" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","UK3CB_BAF_Soflam_Laserdesignator" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","Laserbatteries" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","Laserbatteries" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};
class CUP_B_BAF_Engineer_MTP: CUP_B_BAF_Soldier_01_MTP {
    scope = 2;
    scopeCurator = 2;
    editorSubcategory = QEGVAR(common,mtp);
    displayName = "Engineer (MTP)";
    threat[] = { 1,0.5,0.1 };
    accuracy = 3.9;
    canDeactivateMines = 1;
    engineer = 1;
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Engineer_MTP.jpg);
    backpack = "UK3CB_BAF_B_Bergen_MTP_Engineer_L_A_Toolkit";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_A","UK3CB_BAF_H_Mk7_Camo_D" };
};

// WDL
class CUP_B_BAF_Soldier_01_DPM: CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Soldier 1 - DPM";
    nameSound = "veh_infantry_officer_s";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DPMW";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_02_DPM: CUP_B_BAF_Soldier_01_DPM {
    displayName = "Soldier 2 - DPM";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DPMW_Ghillie_RM";
    model = "A3\Characters_F_Beta\INDEP\ia_sniper.p3d";
};
class CUP_B_BAF_Soldier_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Rifleman (DPMW)";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_GL_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Night_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Light_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Backpack_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAR_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AMG_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAT_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AHAT_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAA_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Officer_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Officer (DPMW)";
    accuracy = 3.6;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_officer_s" };
            speechPlural[] = { "veh_infantry_officer_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_officer_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_officer_p";
    nameSound = "veh_infantry_officer_s";
    icon = "iconManOfficer";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Officer_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_SL_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Section Leader (DPMW)";
    accuracy = 3.6;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_officer_s" };
            speechPlural[] = { "veh_infantry_officer_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_officer_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_officer_p";
    nameSound = "veh_infantry_officer_s";
    icon = "iconManLeader";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_SL_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_TL_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AR_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Automatic Rifleman (DPMW)";
    threat[] = { 1,0.1,0.3 };
    accuracy = 3.7;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_MG_s" };
            speechPlural[] = { "veh_infantry_MG_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_MG_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_MG_p";
    nameSound = "veh_infantry_MG_s";
    icon = "iconManMG";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AR_WDL.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AR";
    weapons[] = { "UK3CB_BAF_L110A3_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L110A3_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_MG_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Machinegunner (DPMW)";
    threat[] = { 1,0.1,0.6 };
    accuracy = 3.7;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_MG_s" };
            speechPlural[] = { "veh_infantry_MG_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_MG_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_MG_p";
    nameSound = "veh_infantry_MG_s";
    icon = "iconManMG";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_MG_WDL.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_MG";
    weapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_AT_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "AT Specialist (DPMW)";
    threat[] = { 1,0.8,0.1 };
    accuracy = 3.5;
    camouflage = 2;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AT_WDL.jpg);
    backpack = "";
    weapons[] = { "launch_NLAW_F","UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "launch_NLAW_F","UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_HAT_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "AT Specialist (Javelin) (DPMW)";
    threat[] = { 1,1,0.1 };
    accuracy = 3.5;
    camouflage = 2.1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_HAT_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","UK3CB_BAF_Javelin_Launcher" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","UK3CB_BAF_Javelin_Launcher" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell","UK3CB_BAF_Javelin_Mag" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell","UK3CB_BAF_Javelin_Mag" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_AA_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "AA Specialist (DPMW)";
    threat[] = { 1,0.1,1 };
    accuracy = 3.5;
    camouflage = 2.1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AA_WDL.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_AA";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","CUP_launch_FIM92Stinger" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","CUP_launch_FIM92Stinger" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_Marksman_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Marksman (DPMW)";
    threat[] = { 1,0.1,0.1 };
    accuracy = 3.9;
    camouflage = 1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_Marksman_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Rangefinder","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Rangefinder","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Soldier_scout_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Sniper_WDL: CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Sniper (LRR) (DPMW)";
    threat[] = { 1,0.3,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Sniper_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L115A3_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L115A3_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
};
class CUP_B_BAF_Sniper_AS50_WDL: CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Sniper (L135A1) (DPMW)";
    threat[] = { 1,0.5,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Sniper_AS50_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L135A1_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L135A1_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
};
class CUP_B_BAF_Sniper_AS50_TWS_WDL: CUP_B_BAF_Sniper_AS50_WDL {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Spotter_WDL: CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Spotter (DPMW)";
    threat[] = { 1,0.3,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Spotter_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
};
class CUP_B_BAF_Spotter_L85TWS_WDL: CUP_B_BAF_Spotter_WDL {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Pilot_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Crew_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Crewman (DPMW)";
    accuracy = 3.4;
    camouflage = 1.4;
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Crew_WDL.jpg);
    weapons[] = { "UK3CB_BAF_L22A2_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L22A2_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_CrewHelmet_DPMW_A" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_CrewHelmet_DPMW_A" };
};
class CUP_B_BAF_Medic_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Medic (DPMW)";
    accuracy = 3.7;
    attendant = 1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_medic_s" };
            speechPlural[] = { "veh_infantry_medic_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_medic_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_medic_p";
    nameSound = "veh_infantry_medic_s";
    icon = "iconManMedic";
    picture = "pictureHeal";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Medic_WDL.jpg);
    backpack = "UKSF_B_Bergen_Medic_DPMW";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
};
class CUP_B_BAF_Soldier_JTAC_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "JTAC (DPMW)";
    accuracy = 3.9;
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_JTAC_WDL.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DPMW_SL_A";
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","UK3CB_BAF_Soflam_Laserdesignator" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","UK3CB_BAF_Soflam_Laserdesignator" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","Laserbatteries" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","Laserbatteries" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};
class CUP_B_BAF_Engineer_WDL: CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Engineer (DPMW)";
    threat[] = { 1,0.5,0.1 };
    accuracy = 3.9;
    canDeactivateMines = 1;
    engineer = 1;
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Engineer_WDL.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DPMW_Rifleman_A_Toolkit";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1","UK3CB_BAF_H_Mk6_DPMW_B" };
};

// DDPM
class CUP_B_BAF_Soldier_01_DDPM: CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Soldier 1 - DDPM";
    nameSound = "veh_infantry_officer_s";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DDPM";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_02_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    displayName = "Soldier 2 - DDPM";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DDPM_Ghillie_RM";
    model = "A3\Characters_F_Beta\INDEP\ia_sniper.p3d";
};
class CUP_B_BAF_Soldier_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Rifleman (DDPM)";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_GL_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Night_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Light_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_Backpack_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAR_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AMG_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAT_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AHAT_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AAA_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Officer_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Officer (DDPM)";
    accuracy = 3.6;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_officer_s" };
            speechPlural[] = { "veh_infantry_officer_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_officer_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_officer_p";
    nameSound = "veh_infantry_officer_s";
    icon = "iconManOfficer";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Officer_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_SL_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Section Leader (DDPM)";
    accuracy = 3.6;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_officer_s" };
            speechPlural[] = { "veh_infantry_officer_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_officer_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_officer_p";
    nameSound = "veh_infantry_officer_s";
    icon = "iconManLeader";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_SL_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_TL_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Soldier_AR_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Automatic Rifleman (DDPM)";
    threat[] = { 1,0.1,0.3 };
    accuracy = 3.7;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_MG_s" };
            speechPlural[] = { "veh_infantry_MG_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_MG_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_MG_p";
    nameSound = "veh_infantry_MG_s";
    icon = "iconManMG";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AR_DDPM.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AR";
    weapons[] = { "UK3CB_BAF_L110A3_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L110A3_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_MG_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Machinegunner (DDPM)";
    threat[] = { 1,0.1,0.6 };
    accuracy = 3.7;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_MG_s" };
            speechPlural[] = { "veh_infantry_MG_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_MG_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_MG_p";
    nameSound = "veh_infantry_MG_s";
    icon = "iconManMG";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_MG_DDPM.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_MG";
    weapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_AT_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "AT Specialist (DDPM)";
    threat[] = { 1,0.8,0.1 };
    accuracy = 3.5;
    camouflage = 2;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AT_DDPM.jpg);
    backpack = "";
    weapons[] = { "launch_NLAW_F","UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "launch_NLAW_F","UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_HAT_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "AT Specialist (Javelin) (DDPM)";
    threat[] = { 1,1,0.1 };
    accuracy = 3.5;
    camouflage = 2.1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_HAT_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","UK3CB_BAF_Javelin_Launcher" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","UK3CB_BAF_Javelin_Launcher" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell","UK3CB_BAF_Javelin_Mag" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell","UK3CB_BAF_Javelin_Mag" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_AA_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "AA Specialist (DDPM)";
    threat[] = { 1,0.1,1 };
    accuracy = 3.5;
    camouflage = 2.1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_AT_s" };
            speechPlural[] = { "veh_infantry_AT_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_AT_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_AT_p";
    nameSound = "veh_infantry_AT_s";
    icon = "iconManAT";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_AA_DDPM.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_AA";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","CUP_launch_FIM92Stinger" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put","CUP_launch_FIM92Stinger" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_Marksman_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Marksman (DDPM)";
    threat[] = { 1,0.1,0.1 };
    accuracy = 3.9;
    camouflage = 1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_Marksman_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Rangefinder","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Rangefinder","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_scout_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Sniper_DDPM: CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Sniper (LRR) (DDPM)";
    threat[] = { 1,0.3,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    icon = "iconMan";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Sniper_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L115A3_DE_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L115A3_DE_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DPMW1" };
};
class CUP_B_BAF_Sniper_AS50_DDPM: CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Sniper (L135A1) (DDPM)";
    threat[] = { 1,0.5,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Sniper_AS50_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L135A1_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L135A1_LRPS","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellred","UK3CB_BAF_SmokeShellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1" };
};
class CUP_B_BAF_Sniper_AS50_TWS_DDPM: CUP_B_BAF_Sniper_AS50_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Spotter_DDPM: CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Spotter (DDPM)";
    threat[] = { 1,0.3,0.3 };
    accuracy = 3.9;
    camouflage = 0.5;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Spotter_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod_Acog","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","UK3CB_BAF_762_L42A1_20Rnd_T","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShellRed" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1" };
};
class CUP_B_BAF_Spotter_L85TWS_DDPM: CUP_B_BAF_Spotter_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Pilot_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 1;
    scopeCurator = 1;
};
class CUP_B_BAF_Crew_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Crewman (DDPM)";
    accuracy = 3.4;
    camouflage = 1.4;
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Crew_DDPM.jpg);
    weapons[] = { "UK3CB_BAF_L22A2_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L22A2_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_CrewHelmet_DDPM_A" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_CrewHelmet_DDPM_A" };
};
class CUP_B_BAF_Medic_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Medic (DDPM)";
    accuracy = 3.7;
    attendant = 1;
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_medic_s" };
            speechPlural[] = { "veh_infantry_medic_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_medic_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_medic_p";
    nameSound = "veh_infantry_medic_s";
    icon = "iconManMedic";
    picture = "pictureHeal";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Medic_DDPM.jpg);
    backpack = "UKSF_B_Bergen_Medic_DDPM";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Soldier_JTAC_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "JTAC (DDPM)";
    accuracy = 3.9;
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Soldier_JTAC_DDPM.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DDPM_SL_A";
    weapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","UK3CB_BAF_Soflam_Laserdesignator" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_UGL_Elcan","Throw","Put","UK3CB_BAF_Soflam_Laserdesignator" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","Laserbatteries" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","Laserbatteries" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
class CUP_B_BAF_Engineer_DDPM: CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    displayName = "Engineer (DDPM)";
    threat[] = { 1,0.5,0.1 };
    accuracy = 3.9;
    canDeactivateMines = 1;
    engineer = 1;
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = QPATHTOEF(common,data\previews\CUP_B_BAF_Engineer_DDPM.jpg);
    backpack = "UK3CB_BAF_B_Bergen_DDPM_Rifleman_A_Toolkit";
    weapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A3_Grippod_Elcan","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","UK3CB_BAF_SmokeShell","UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_DDPM1","UK3CB_BAF_H_Mk6_DDPM_B" };
};
