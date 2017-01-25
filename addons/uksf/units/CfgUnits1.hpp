class B_Soldier_base_F;
class CUP_Creatures_Military_BAF_Soldier_Base : B_Soldier_base_F {
    author = "UKSF";
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    genericNames = "EnglishMen";
    accuracy = 3.9;
    threat[] = { 1,0.3,0.3 };
    minFireTime = 10;
    cost = 100000;
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_1Para";
    weapons[] = { "Throw","Put" };
    respawnWeapons[] = { "Throw","Put" };
    magazines[] = {};
    respawnMagazines[] = {};
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch" };
    Items[] = {};
    RespawnItems[] = {};
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers {};
    };
};

//UKSF


//AI
class CUP_B_BAF_Soldier_01_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 1 - DDPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_1.p3d";
    uniformClass = "CUP_U_B_BAF_DDPM_S1_RolledUp";
};
class CUP_B_BAF_Soldier_02_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 2 - DDPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_2.p3d";
    uniformClass = "CUP_U_B_BAF_DDPM_S2_UnRolled";
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_03_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier Light - DDPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_Light.p3d";
    uniformClass = "CUP_U_B_BAF_DDPM_Tshirt";
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_01_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 1 - DPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_1.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_S1_RolledUp";
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_02_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 2 - DPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_2.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_S2_UnRolled";
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_03_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier Light - DPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_Light.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_Tshirt";
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_01_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 1 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_1.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_S1_RolledUp";
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_02_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 2 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_2.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_S2_UnRolled";
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_03_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier Light - MTP";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_Light.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_Tshirt";
};
class CUP_B_BAF_Soldier_04_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_USMC_Sniper.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_Ghillie";
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_04_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_USMC_Sniper.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_Ghillie";
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_04_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_USMC_Sniper.p3d";
    uniformClass = "CUP_U_B_BAF_DDPM_Ghillie";
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_05_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 3 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\RiflemanROLL.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_S3_RolledUp";
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_06_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 4 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\Rifleman.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_S4_UnRolled";
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_07_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 4 - P MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\Rifleman2.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_S5_UnRolled";
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_08_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 5 - G MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\RiflemanGLV.p3d";
    uniformClass = "CUP_U_B_BAF_MTP_S6_UnRolled";
    icon = "iconMan";
};

class CUP_B_BAF_Soldier_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_MTP.jpg";
};
class CUP_B_BAF_Soldier_GL_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Grenadier";
    cost = 60000;
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_GL_MTP.jpg";
};
class CUP_B_BAF_Soldier_Night_MTP : CUP_B_BAF_Soldier_05_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman (night)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Night_MTP.jpg";
};
class CUP_B_BAF_Soldier_Light_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman (light)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Light_MTP.jpg";
};
class CUP_B_BAF_Soldier_Backpack_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman (backpack)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Backpack_MTP.jpg";
};
class CUP_B_BAF_Soldier_AAR_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. Automatic Rifleman";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAR_MTP.jpg";
};
class CUP_B_BAF_Soldier_AMG_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. Machineguner";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AMG_MTP.jpg";
};
class CUP_B_BAF_Soldier_AAT_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. AT Specialist";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAT_MTP.jpg";
};
class CUP_B_BAF_Soldier_AHAT_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. AT Specialist (Javelin)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AHAT_MTP.jpg";
};
class CUP_B_BAF_Soldier_AAA_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. AA Specialist";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAA_MTP.jpg";
};
class CUP_B_BAF_Officer_MTP : CUP_B_BAF_Soldier_05_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Officer";
    accuracy = 3.6;
    cost = 750000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Officer_MTP.jpg";
};
class CUP_B_BAF_Soldier_SL_MTP : CUP_B_BAF_Soldier_08_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Section Leader";
    accuracy = 3.6;
    cost = 500000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_SL_MTP.jpg";
};
class CUP_B_BAF_Soldier_TL_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Team Leader";
    accuracy = 3.6;
    cost = 400000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_TL_MTP.jpg";
};
class CUP_B_BAF_Soldier_AR_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Automatic Rifleman";
    cost = 115000;
    accuracy = 3.7;
    threat[] = { 1,0.1,0.3 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AR_MTP.jpg";
};
class CUP_B_BAF_Soldier_MG_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Machinegunner";
    cost = 130000;
    accuracy = 3.7;
    threat[] = { 1,0.1,0.6 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_MG_MTP.jpg";
};
class CUP_B_BAF_Soldier_AT_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "AT Specialist";
    camouflage = 2;
    threat[] = { 1,0.8,0.1 };
    cost = 150000;
    accuracy = 3.5;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AT_MTP.jpg";
};
class CUP_B_BAF_Soldier_HAT_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "AT Specialist (Javelin)";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    threat[] = { 1,1,0.1 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_HAT_MTP.jpg";
};
class CUP_B_BAF_Soldier_AA_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "AA Specialist";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    threat[] = { 1,0.1,1 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AA_MTP.jpg";
};
class CUP_B_BAF_Soldier_Marksman_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Marksman (LSW)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Marksman_MTP.jpg";
};
class CUP_B_BAF_Soldier_scout_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Marksman (LRR)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_scout_MTP.jpg";
};
class CUP_B_BAF_Sniper_MTP : CUP_B_BAF_Soldier_04_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Sniper (LRR)";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_MTP.jpg";
};
class CUP_B_BAF_Sniper_AS50_MTP : CUP_B_BAF_Soldier_04_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Sniper (AS50)";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_AS50_MTP.jpg";
};
class CUP_B_BAF_Sniper_AS50_TWS_MTP : CUP_B_BAF_Sniper_AS50_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Sniper (AS50 TWS)";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_AS50_TWS_MTP.jpg";
};
class CUP_B_BAF_Spotter_MTP : CUP_B_BAF_Soldier_04_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Spotter";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_MTP.jpg";
};
class CUP_B_BAF_Spotter_L85TWS_MTP : CUP_B_BAF_Spotter_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Spotter (night)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_L85TWS_MTP.jpg";
};
class CUP_B_BAF_Pilot_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.2;
    camouflage = 1.2;
    cost = 20000;
    displayName = "Pilot";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_pilot_s" };
            speechPlural[] = { "veh_infantry_pilot_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_pilot_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_pilot_p";
    nameSound = "veh_infantry_pilot_s";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Pilot_MTP.jpg";
};
class CUP_B_BAF_Crew_MTP : CUP_B_BAF_Soldier_06_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.4;
    camouflage = 1.4;
    cost = 20000;
    displayName = "Crewman";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Crew_MTP.jpg";
};
class CUP_B_BAF_Medic_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Medic";
    accuracy = 3.7;
    cost = 100000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Medic_MTP.jpg";
};
class CUP_B_BAF_Soldier_JTAC_MTP : CUP_B_BAF_Soldier_07_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.9;
    displayName = "Joint Terminal Attack Controller";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_JTAC_MTP.jpg";
};
class CUP_B_BAF_Engineer_MTP : CUP_B_BAF_Soldier_05_MTP {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.9;
    displayName = "Engineer";
    threat[] = { 1,0.5,0.1 };
    canDeactivateMines = 1;
    engineer = 1;
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Engineer_MTP.jpg";
};
class CUP_B_BAF_Soldier_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_WDL.jpg";
};
class CUP_B_BAF_Soldier_GL_WDL : CUP_B_BAF_Soldier_03_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Grenadier";
    cost = 60000;
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_GL_WDL.jpg";
};
class CUP_B_BAF_Soldier_Night_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman (night)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Night_WDL.jpg";
};
class CUP_B_BAF_Soldier_Light_WDL : CUP_B_BAF_Soldier_03_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman (light)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Light_WDL.jpg";
};
class CUP_B_BAF_Soldier_Backpack_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman (backpack)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Backpack_WDL.jpg";
};
class CUP_B_BAF_Soldier_AAR_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. Automatic Rifleman";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAR_WDL.jpg";
};
class CUP_B_BAF_Soldier_AMG_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. Machineguner";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AMG_WDL.jpg";
};
class CUP_B_BAF_Soldier_AAT_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. AT Specialist";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAT_WDL.jpg";
};
class CUP_B_BAF_Soldier_AHAT_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. AT Specialist (Javelin)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AHAT_WDL.jpg";
};
class CUP_B_BAF_Soldier_AAA_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. AA Specialist";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAA_WDL.jpg";
};
class CUP_B_BAF_Officer_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Officer";
    accuracy = 3.6;
    cost = 750000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Officer_WDL.jpg";
};
class CUP_B_BAF_Soldier_SL_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Section Leader";
    accuracy = 3.6;
    cost = 500000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_SL_WDL.jpg";
};
class CUP_B_BAF_Soldier_TL_WDL : CUP_B_BAF_Soldier_03_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Team Leader";
    accuracy = 3.6;
    cost = 400000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_TL_WDL.jpg";
};
class CUP_B_BAF_Soldier_AR_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Automatic Rifleman";
    cost = 115000;
    accuracy = 3.7;
    threat[] = { 1,0.1,0.3 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AR_WDL.jpg";
};
class CUP_B_BAF_Soldier_MG_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Machinegunner";
    cost = 130000;
    accuracy = 3.7;
    threat[] = { 1,0.1,0.6 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_MG_WDL.jpg";
};
class CUP_B_BAF_Soldier_AT_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "AT Specialist";
    camouflage = 2;
    threat[] = { 1,0.8,0.1 };
    cost = 150000;
    accuracy = 3.5;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AT_WDL.jpg";
};
class CUP_B_BAF_Soldier_HAT_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "AT Specialist (Javelin)";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    threat[] = { 1,1,0.1 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_HAT_WDL.jpg";
};
class CUP_B_BAF_Soldier_AA_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "AA Specialist";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    threat[] = { 1,0.1,1 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AA_WDL.jpg";
};
class CUP_B_BAF_Soldier_Marksman_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Marksman (LSW)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Marksman_WDL.jpg";
};
class CUP_B_BAF_Soldier_scout_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Marksman (LRR)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_scout_WDL.jpg";
};
class CUP_B_BAF_Sniper_WDL : CUP_B_BAF_Soldier_04_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Sniper (LRR)";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_WDL.jpg";
};
class CUP_B_BAF_Sniper_AS50_WDL : CUP_B_BAF_Soldier_04_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Sniper (AS50)";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_AS50_WDL.jpg";
};
class CUP_B_BAF_Sniper_AS50_TWS_WDL : CUP_B_BAF_Sniper_AS50_WDL {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Sniper (AS50 TWS)";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_AS50_TWS_WDL.jpg";
};
class CUP_B_BAF_Spotter_WDL : CUP_B_BAF_Soldier_04_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Spotter";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_WDL.jpg";
};
class CUP_B_BAF_Spotter_L85TWS_WDL : CUP_B_BAF_Spotter_WDL {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Spotter (night)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_L85TWS_WDL.jpg";
};
class CUP_B_BAF_Pilot_WDL : CUP_B_BAF_Soldier_02_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.2;
    camouflage = 1.2;
    cost = 20000;
    displayName = "Pilot";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_pilot_s" };
            speechPlural[] = { "veh_infantry_pilot_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_pilot_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_pilot_p";
    nameSound = "veh_infantry_pilot_s";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Pilot_WDL.jpg";
};
class CUP_B_BAF_Crew_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.4;
    camouflage = 1.4;
    cost = 20000;
    displayName = "Crewman";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Crew_WDL.jpg";
};
class CUP_B_BAF_Medic_WDL : CUP_B_BAF_Soldier_03_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Medic";
    accuracy = 3.7;
    cost = 100000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Medic_WDL.jpg";
};
class CUP_B_BAF_Soldier_JTAC_WDL : CUP_B_BAF_Soldier_03_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.9;
    displayName = "Joint Terminal Attack Controller";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_JTAC_WDL.jpg";
};
class CUP_B_BAF_Engineer_WDL : CUP_B_BAF_Soldier_01_DPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.9;
    displayName = "Engineer";
    threat[] = { 1,0.5,0.1 };
    canDeactivateMines = 1;
    engineer = 1;
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Engineer_WDL.jpg";
};
class CUP_B_BAF_Soldier_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_DDPM.jpg";
};
class CUP_B_BAF_Soldier_GL_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Grenadier";
    cost = 60000;
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_GL_DDPM.jpg";
};
class CUP_B_BAF_Soldier_Night_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman (night)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Night_DDPM.jpg";
};
class CUP_B_BAF_Soldier_Light_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman (light)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Light_DDPM.jpg";
};
class CUP_B_BAF_Soldier_Backpack_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman (backpack)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Backpack_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AAR_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. Automatic Rifleman";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAR_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AMG_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. Machineguner";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AMG_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AAT_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. AT Specialist";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAT_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AHAT_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. AT Specialist (Javelin)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AHAT_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AAA_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. AA Specialist";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAA_DDPM.jpg";
};
class CUP_B_BAF_Officer_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Officer";
    accuracy = 3.6;
    cost = 750000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Officer_DDPM.jpg";
};
class CUP_B_BAF_Soldier_SL_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Section Leader";
    accuracy = 3.6;
    cost = 500000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_SL_DDPM.jpg";
};
class CUP_B_BAF_Soldier_TL_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Team Leader";
    accuracy = 3.6;
    cost = 400000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_TL_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AR_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Automatic Rifleman";
    cost = 115000;
    accuracy = 3.7;
    threat[] = { 1,0.1,0.3 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AR_DDPM.jpg";
};
class CUP_B_BAF_Soldier_MG_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Machinegunner";
    cost = 130000;
    accuracy = 3.7;
    threat[] = { 1,0.1,0.6 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_MG_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AT_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "AT Specialist";
    camouflage = 2;
    threat[] = { 1,0.8,0.1 };
    cost = 150000;
    accuracy = 3.5;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AT_DDPM.jpg";
};
class CUP_B_BAF_Soldier_HAT_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "AT Specialist (Javelin)";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    threat[] = { 1,1,0.1 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_HAT_DDPM.jpg";
};
class CUP_B_BAF_Soldier_AA_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "AA Specialist";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    threat[] = { 1,0.1,1 };
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AA_DDPM.jpg";
};
class CUP_B_BAF_Soldier_Marksman_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Marksman (LSW)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Marksman_DDPM.jpg";
};
class CUP_B_BAF_Soldier_scout_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Marksman (LRR)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_scout_DDPM.jpg";
};
class CUP_B_BAF_Sniper_DDPM : CUP_B_BAF_Soldier_04_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Sniper (LRR)";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_DDPM.jpg";
};
class CUP_B_BAF_Sniper_AS50_DDPM : CUP_B_BAF_Soldier_04_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Sniper (AS50)";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_AS50_DDPM.jpg";
};
class CUP_B_BAF_Sniper_AS50_TWS_DDPM : CUP_B_BAF_Sniper_AS50_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Sniper (AS50 TWS)";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_sniper_s" };
            speechPlural[] = { "veh_infantry_sniper_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_sniper_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_sniper_p";
    nameSound = "veh_infantry_sniper_s";
    Icon = "IconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Sniper_AS50_TWS_DDPM.jpg";
};
class CUP_B_BAF_Spotter_DDPM : CUP_B_BAF_Soldier_04_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Spotter";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_DDPM.jpg";
};
class CUP_B_BAF_Spotter_L85TWS_DDPM : CUP_B_BAF_Spotter_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Spotter (night)";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_L85TWS_DDPM.jpg";
};
class CUP_B_BAF_Pilot_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.2;
    camouflage = 1.2;
    cost = 20000;
    displayName = "Pilot";
    class SpeechVariants {
        class Default {
            speechSingular[] = { "veh_infantry_pilot_s" };
            speechPlural[] = { "veh_infantry_pilot_p" };
        };
    };
    textSingular = "$STR_A3_nameSound_veh_infantry_pilot_s";
    textPlural = "$STR_A3_nameSound_veh_infantry_pilot_p";
    nameSound = "veh_infantry_pilot_s";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Pilot_DDPM.jpg";
};
class CUP_B_BAF_Crew_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.4;
    camouflage = 1.4;
    cost = 20000;
    displayName = "Crewman";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Crew_DDPM.jpg";
};
class CUP_B_BAF_Medic_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Medic";
    accuracy = 3.7;
    cost = 100000;
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
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Medic_DDPM.jpg";
};
class CUP_B_BAF_Soldier_JTAC_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.9;
    displayName = "Joint Terminal Attack Controller";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_JTAC_DDPM.jpg";
};
class CUP_B_BAF_Engineer_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.9;
    displayName = "Engineer";
    threat[] = { 1,0.5,0.1 };
    canDeactivateMines = 1;
    engineer = 1;
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Engineer_DDPM.jpg";
};