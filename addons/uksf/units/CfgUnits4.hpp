//AI
class CUP_Creatures_Military_BAF_Soldier_Base: SoldierWB {
    identityTypes[] = {"LanguageENGB_F", "Head_NATO", "G_GUERIL_default"};
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    weapons[] = {"UK3CB_BAF_L85A2_RIS","Throw","Put"};
    respawnWeapons[] = {"UK3CB_BAF_L85A2_RIS","Throw","Put"};
    magazines[] = {"UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell"};
    respawnMagazines[] = {"UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell"};
    linkedItems[] = {"ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS"};
};
class CUP_B_BAF_Soldier_01_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 1 - DDPM";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_1.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DDPM";
    //uniformClass = "CUP_U_B_BAF_DDPM_S1_RolledUp";
    //hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\camo_ddpm_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\armour_ddpm_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\top_ddpm_co.paa" };
};
class CUP_B_BAF_Soldier_02_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 2 - DDPM";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_2.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DDPM";
    //uniformClass = "CUP_U_B_BAF_DDPM_S2_UnRolled";
    //hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\camo_ddpm_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\armour_ddpm_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DDPM\top2_ddpm_co.paa" };
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_03_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier Light - DDPM";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_Light.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DDPM";
    //uniformClass = "CUP_U_B_BAF_DDPM_Tshirt";
    //hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\camo_ddpm_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\armour_ddpm_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\ddpm\top3_ddpm_co.paa" };
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_01_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 1 - DPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_1.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_S1_RolledUp";
    hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\camo_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\armour_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\dpm\top_dpm_co.paa" };
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_02_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 2 - DPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_2.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_S2_UnRolled";
    hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\camo_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\armour_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\top2_dpm_co.paa" };
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_03_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier Light - DPM";
    nameSound = "veh_infantry_officer_s";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_Light.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_Tshirt";
    hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\camo_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\armour_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\dpm\top3_dpm_co.paa" };
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_01_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 1 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_1.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    //uniformClass = "CUP_U_B_BAF_MTP_S1_RolledUp";
    //hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\MTP\camo_MTP_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\armour_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\MTP\top_mtp_co.paa" };
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_02_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 2 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_2.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    //uniformClass = "CUP_U_B_BAF_MTP_S2_UnRolled";
    //hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\MTP\camo_MTP_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\armour_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\MTP\top2_mtp_co.paa" };
    icon = "iconManOfficer";
};
class CUP_B_BAF_Soldier_03_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier Light - MTP";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_BAF_Soldier_Light.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    //uniformClass = "CUP_U_B_BAF_MTP_Tshirt";
    //hiddenSelections[] = { "Camo","Camo2","camo3","insignia" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\data\MTP\camo_MTP_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\DPM\armour_DPM_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\data\MTP\top3_mtp_co.paa" };
};
class CUP_B_BAF_Soldier_04_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_USMC_Sniper.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    //uniformClass = "CUP_U_B_BAF_MTP_Ghillie";
    //hiddenSelectionsTextures[] = { "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\data\ghillie_overall1_desert_co.paa" };
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_04_DPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier";
    model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_USMC_Sniper.p3d";
    uniformClass = "CUP_U_B_BAF_DPM_Ghillie";
    hiddenSelectionsTextures[] = { "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\data\ghillie_overall1_co.paa" };
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_04_DDPM : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USMC\CUP_USMC_Sniper.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_DDPM_Ghillie_RM";
    //uniformClass = "CUP_U_B_BAF_DDPM_Ghillie";
    //hiddenSelections[] = { "Camo","Camo2","clan","insignia" };
    //hiddenSelectionsTextures[] = { "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\data\ghillie_overall1_desert_co.paa" };
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_05_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 3 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\RiflemanROLL.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Ghillie_RM";
    //uniformClass = "CUP_U_B_BAF_MTP_S3_RolledUp";
    //hiddenSelections[] = { "Camo1" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\uniform\data\body_co.paa" };
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_06_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 4 - MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\Rifleman.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    //uniformClass = "CUP_U_B_BAF_MTP_S4_UnRolled";
    //hiddenSelections[] = { "Camo1" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\uniform\data\body_co.paa" };
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_07_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 4 - P MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\Rifleman2.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    //uniformClass = "CUP_U_B_BAF_MTP_S5_UnRolled";
    //hiddenSelections[] = { "Camo1" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\uniform\data\body_co.paa" };
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_08_MTP : CUP_Creatures_Military_BAF_Soldier_Base {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 1;
    scopeCurator = 0;
    displayName = "Soldier 5 - G MTP";
    nameSound = "veh_infantry_officer_s";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    //model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\uniform\RiflemanGLV.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP";
    //uniformClass = "CUP_U_B_BAF_MTP_S6_UnRolled";
    //hiddenSelections[] = { "Camo1","Camo2" };
    //hiddenSelectionsTextures[] = { "cup\creatures\people\military\cup_creatures_people_military_baf\uniform\data\body_co.paa","cup\creatures\people\military\cup_creatures_people_military_baf\osprey\data\gear_co.paa" };
    icon = "iconMan";
};
class CUP_B_BAF_Soldier_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman";
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_GL_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Grenadier";
    cost = 60000;
    weapons[] = { "UK3CB_BAF_L85A2_UGL","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_GL_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Night_MTP : CUP_B_BAF_Soldier_05_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman (night)";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Night_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Light_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman (light)";
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Light_MTP.jpg";
};
class CUP_B_BAF_Soldier_Backpack_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Rifleman (backpack)";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Backpack_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAR_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. Automatic Rifleman";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAR_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AMG_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. Machineguner";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AMG_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAT_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. AT Specialist";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAT_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AHAT_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. AT Specialist (Javelin)";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AHAT_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAA_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Asst. AA Specialist";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAA_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Officer_MTP : CUP_B_BAF_Soldier_05_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Officer";
    accuracy = 3.6;
    cost = 750000;
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","UK3CB_BAF_L131A1","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","UK3CB_BAF_L131A1","Throw","Put","Rangefinder" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","HandGrenade","HandGrenade" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Section Leader";
    accuracy = 3.6;
    cost = 500000;
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","SmokeShell","SmokeShellRed","SmokeShellGreen","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","SmokeShell","SmokeShellRed","SmokeShellGreen","HandGrenade","HandGrenade" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_TL_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Team Leader";
    accuracy = 3.6;
    cost = 400000;
    weapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","Rangefinder" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AR_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Automatic Rifleman";
    cost = 115000;
    accuracy = 3.7;
    weapons[] = { "UK3CB_BAF_L110A3","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L110A3","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    threat[] = { 1,0.1,0.3 };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_MG_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Machinegunner";
    cost = 130000;
    accuracy = 3.7;
    weapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    threat[] = { 1,0.1,0.6 };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_MG_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AT_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "AT Specialist";
    camouflage = 2;
    threat[] = { 1,0.8,0.1 };
    cost = 150000;
    accuracy = 3.5;
    weapons[] = { "UK3CB_BAF_NLAW_Launcher","UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_NLAW_Launcher","UK3CB_BAF_L85A2_RIS","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_HAT_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "AT Specialist (Javelin)";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","UK3CB_BAF_Javelin_Slung_Tube" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","UK3CB_BAF_Javelin_Slung_Tube" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade" };
    threat[] = { 1,1,0.1 };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D","UK3CB_BAF_Javelin_CLU" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D","UK3CB_BAF_Javelin_CLU" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AA_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "AA Specialist";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","CUP_launch_FIM92Stinger" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","CUP_launch_FIM92Stinger" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","CUP_Stinger_M" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","CUP_Stinger_M" };
    threat[] = { 1,0.1,1 };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Marksman_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Marksman (LSW)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    weapons[] = { "UK3CB_BAF_L129A1_Grippod","Rangefinder","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod","Rangefinder","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","HandGrenade","HandGrenade","SmokeShell","SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","HandGrenade","HandGrenade","SmokeShell","SmokeShellRed" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_scout_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Marksman (LRR)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen","HandGrenade" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Sniper_MTP : CUP_B_BAF_Soldier_04_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Sniper (LRR)";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    weapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Sniper (AS50)";
    weapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Sniper (AS50 TWS)";
    weapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Spotter";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_MTP.jpg";
};
class CUP_B_BAF_Spotter_L85TWS_MTP : CUP_B_BAF_Spotter_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Spotter (night)";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Rangefinder" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_L85TWS_MTP.jpg";
};
class CUP_B_BAF_Pilot_MTP : CUP_B_BAF_Soldier_06_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.2;
    camouflage = 1.2;
    cost = 20000;
    displayName = "Pilot";
    weapons[] = { "UK3CB_BAF_L22A2","Throw","Put","Binocular" };
    respawnWeapons[] = { "UK3CB_BAF_L22A2","Throw","Put","Binocular" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UKSF_V_Flight","UK3CB_BAF_H_PilotHelmetHeli_A" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UKSF_V_Flight","UK3CB_BAF_H_PilotHelmetHeli_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.4;
    camouflage = 1.4;
    cost = 20000;
    displayName = "Crewman";
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Crew_MTP.jpg";
};
class CUP_B_BAF_Medic_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    displayName = "Medic";
    accuracy = 3.7;
    cost = 100000;
    attendant = 1;
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_JTAC_MTP : CUP_B_BAF_Soldier_07_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.9;
    displayName = "Joint Terminal Attack Controller";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","CUP_SOFLAM" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","CUP_SOFLAM" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","Laserbatteries","Laserbatteries" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","Laserbatteries","Laserbatteries" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_JTAC_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Engineer_MTP : CUP_B_BAF_Soldier_05_MTP {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_MTP";
    editorSubcategory = "EdSubcat_Personnel";
    accuracy = 3.9;
    displayName = "Engineer";
    threat[] = { 1,0.5,0.1 };
    canDeactivateMines = 1;
    engineer = 1;
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Engineer_MTP.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_GL_WDL : CUP_B_BAF_Soldier_03_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Grenadier";
    cost = 60000;
    //weapons[] = { "UK3CB_BAF_L85A2_UGL","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL","Throw","Put" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_GL_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Night_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman (night)";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Night_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Light_WDL : CUP_B_BAF_Soldier_03_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman (light)";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Light_WDL.jpg";
};
class CUP_B_BAF_Soldier_Backpack_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Rifleman (backpack)";
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Backpack_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAR_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. Automatic Rifleman";
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAR_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AMG_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. Machineguner";
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AMG_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAT_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. AT Specialist";
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAT_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AHAT_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. AT Specialist (Javelin)";
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AHAT_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAA_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Asst. AA Specialist";
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAA_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Officer_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Officer";
    accuracy = 3.6;
    cost = 750000;
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","UK3CB_BAF_L131A1","Throw","Put","Rangefinder" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","UK3CB_BAF_L131A1","Throw","Put","Rangefinder" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","HandGrenade","HandGrenade" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","HandGrenade","HandGrenade" };
    //linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Section Leader";
    accuracy = 3.6;
    cost = 500000;
    //weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","SmokeShell","SmokeShellRed","SmokeShellGreen","HandGrenade","HandGrenade" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","SmokeShell","SmokeShellRed","SmokeShellGreen","HandGrenade","HandGrenade" };
    //linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_TL_WDL : CUP_B_BAF_Soldier_03_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Team Leader";
    accuracy = 3.6;
    cost = 400000;
    //weapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","Rangefinder" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","Rangefinder" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AR_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Automatic Rifleman";
    cost = 115000;
    accuracy = 3.7;
    //weapons[] = { "UK3CB_BAF_L110A3","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L110A3","Throw","Put" };
    //magazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    //respawnMagazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    threat[] = { 1,0.1,0.3 };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_MG_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Machinegunner";
    cost = 130000;
    accuracy = 3.7;
    //weapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    //magazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    //respawnMagazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    threat[] = { 1,0.1,0.6 };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AT_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "AT Specialist";
    camouflage = 2;
    threat[] = { 1,0.8,0.1 };
    cost = 150000;
    accuracy = 3.5;
    //weapons[] = { "UK3CB_BAF_NLAW_Launcher","UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_NLAW_Launcher","UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_HAT_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "AT Specialist (Javelin)";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","UK3CB_BAF_Javelin_Slung_Tube" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","UK3CB_BAF_Javelin_Slung_Tube" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade" };
    //threat[] = { 1,1,0.1 };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D","UK3CB_BAF_Javelin_CLU" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D","UK3CB_BAF_Javelin_CLU" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AA_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "AA Specialist";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","CUP_launch_FIM92Stinger" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","CUP_launch_FIM92Stinger" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","CUP_Stinger_M" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","CUP_Stinger_M" };
    threat[] = { 1,0.1,1 };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Marksman_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Marksman (LSW)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    //weapons[] = { "UK3CB_BAF_L129A1_Grippod","Rangefinder","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod","Rangefinder","Throw","Put" };
    //magazines[] = { "UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","HandGrenade","HandGrenade","SmokeShell","SmokeShellRed" };
    //respawnMagazines[] = { "UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","HandGrenade","HandGrenade","SmokeShell","SmokeShellRed" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_scout_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Marksman (LRR)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    //weapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    //respawnWeapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    //magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen","HandGrenade" };
    //respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen","HandGrenade" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Sniper_WDL : CUP_B_BAF_Soldier_04_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Sniper (LRR)";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    //weapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    //respawnWeapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    //magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    //respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    //linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    //respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Sniper (AS50)";
    //weapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    //respawnWeapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    //magazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    //respawnMagazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    //linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    //respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Sniper (AS50 TWS)";
    //weapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    //respawnWeapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Spotter";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    //weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_WDL.jpg";
};
class CUP_B_BAF_Spotter_L85TWS_WDL : CUP_B_BAF_Spotter_WDL {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Spotter (night)";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Rangefinder" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Rangefinder" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_L85TWS_WDL.jpg";
};
class CUP_B_BAF_Pilot_WDL : CUP_B_BAF_Soldier_02_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.2;
    camouflage = 1.2;
    cost = 20000;
    displayName = "Pilot";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Binocular" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Binocular" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UKSF_V_Flight","UK3CB_BAF_H_PilotHelmetHeli_A" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UKSF_V_Flight","UK3CB_BAF_H_PilotHelmetHeli_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.4;
    camouflage = 1.4;
    cost = 20000;
    displayName = "Crewman";
    //weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Crew_WDL.jpg";
};
class CUP_B_BAF_Medic_WDL : CUP_B_BAF_Soldier_03_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    displayName = "Medic";
    accuracy = 3.7;
    cost = 100000;
    attendant = 1;
    //weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_JTAC_WDL : CUP_B_BAF_Soldier_03_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.9;
    displayName = "Joint Terminal Attack Controller";
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    //weapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","CUP_SOFLAM" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","CUP_SOFLAM" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","Laserbatteries","Laserbatteries" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","Laserbatteries","Laserbatteries" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_JTAC_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Engineer_WDL : CUP_B_BAF_Soldier_01_DPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_WDL";
    editorSubcategory = "EdSubcat_Personnel_Camo_Woodland";
    accuracy = 3.9;
    displayName = "Engineer";
    threat[] = { 1,0.5,0.1 };
    canDeactivateMines = 1;
    engineer = 1;
    //weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    //magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell" };
    //respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell" };
    //linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    //backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Engineer_WDL.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman";
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_GL_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Grenadier";
    cost = 60000;
    weapons[] = { "UK3CB_BAF_L85A2_UGL","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_GL_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Night_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman (night)";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Night_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Light_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman (light)";
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Light_DDPM.jpg";
};
class CUP_B_BAF_Soldier_Backpack_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Rifleman (backpack)";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_Backpack_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAR_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. Automatic Rifleman";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAR_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AMG_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. Machineguner";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AMG_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAT_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. AT Specialist";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAT_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AHAT_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. AT Specialist (Javelin)";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AHAT_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AAA_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Asst. AA Specialist";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_AAA_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Officer_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Officer";
    accuracy = 3.6;
    cost = 750000;
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","UK3CB_BAF_L131A1","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","UK3CB_BAF_L131A1","Throw","Put","Rangefinder" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshellyellow","smokeshellpurple","smokeshellgreen","smokeshell","smokeshellred","HandGrenade","HandGrenade" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Section Leader";
    accuracy = 3.6;
    cost = 500000;
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","SmokeShell","SmokeShellRed","SmokeShellGreen","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","SmokeShell","SmokeShellRed","SmokeShellGreen","HandGrenade","HandGrenade" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_TL_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Team Leader";
    accuracy = 3.6;
    cost = 400000;
    weapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","Rangefinder" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AR_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Automatic Rifleman";
    cost = 115000;
    accuracy = 3.7;
    weapons[] = { "UK3CB_BAF_L110A3","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L110A3","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_200Rnd","UK3CB_BAF_556_200Rnd","HandGrenade","HandGrenade","SmokeShell","SmokeShell" };
    threat[] = { 1,0.1,0.3 };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_MG_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Machinegunner";
    cost = 130000;
    accuracy = 3.7;
    weapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L7A2","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_762_100Rnd_T","UK3CB_BAF_762_100Rnd_T","HandGrenade","HandGrenade" };
    threat[] = { 1,0.1,0.6 };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AT_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "AT Specialist";
    camouflage = 2;
    threat[] = { 1,0.8,0.1 };
    cost = 150000;
    accuracy = 3.5;
    weapons[] = { "UK3CB_BAF_NLAW_Launcher","UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_NLAW_Launcher","UK3CB_BAF_L85A2_RIS","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_HAT_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "AT Specialist (Javelin)";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","UK3CB_BAF_Javelin_Slung_Tube" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","UK3CB_BAF_Javelin_Slung_Tube" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade" };
    threat[] = { 1,1,0.1 };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D","UK3CB_BAF_Javelin_CLU" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D","UK3CB_BAF_Javelin_CLU" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_AA_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "AA Specialist";
    camouflage = 2.1;
    cost = 200000;
    accuracy = 3.5;
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","CUP_launch_FIM92Stinger" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","CUP_launch_FIM92Stinger" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","CUP_Stinger_M" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","CUP_Stinger_M" };
    threat[] = { 1,0.1,1 };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_Marksman_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Marksman (LSW)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    weapons[] = { "UK3CB_BAF_L129A1_Grippod","Rangefinder","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L129A1_Grippod","Rangefinder","Throw","Put" };
    magazines[] = { "UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","HandGrenade","HandGrenade","SmokeShell","SmokeShellRed" };
    respawnMagazines[] = { "UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","UK3CB_BAF_762_20Rnd_T","HandGrenade","HandGrenade","SmokeShell","SmokeShellRed" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_scout_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Marksman (LRR)";
    accuracy = 3.9;
    camouflage = 1;
    cost = 250000;
    threat[] = { 1,0.1,0.1 };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen","HandGrenade" };
    respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen","HandGrenade" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Sniper_DDPM : CUP_B_BAF_Soldier_04_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Sniper (LRR)";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    weapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L115A3","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","UK3CB_BAF_338_5Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Sniper (AS50)";
    weapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    magazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    respawnMagazines[] = { "UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","UK3CB_BAF_127_10Rnd","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","16Rnd_9x21_Mag","smokeshell","smokeshellred","smokeshellgreen" };
    linkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
    respawnLinkedItems[] = { "ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Marksman_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Sniper (AS50 TWS)";
    weapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
    respawnWeapons[] = { "UK3CB_BAF_L135A1","Throw","Put","Rangefinder","UK3CB_BAF_L131A1" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Spotter";
    accuracy = 3.9;
    camouflage = 0.5;
    cost = 350000;
    threat[] = { 1,0.3,0.3 };
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put","Rangefinder" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_DDPM.jpg";
};
class CUP_B_BAF_Spotter_L85TWS_DDPM : CUP_B_BAF_Spotter_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Spotter (night)";
    weapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Rangefinder" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS_Green","Throw","Put","Rangefinder" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Spotter_L85TWS_DDPM.jpg";
};
class CUP_B_BAF_Pilot_DDPM : CUP_B_BAF_Soldier_02_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.2;
    camouflage = 1.2;
    cost = 20000;
    displayName = "Pilot";
    weapons[] = { "UK3CB_BAF_L22A2","Throw","Put","Binocular" };
    respawnWeapons[] = { "UK3CB_BAF_L22A2","Throw","Put","Binocular" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UKSF_V_Flight","UK3CB_BAF_H_PilotHelmetHeli_A" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UKSF_V_Flight","UK3CB_BAF_H_PilotHelmetHeli_A" };
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
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.4;
    camouflage = 1.4;
    cost = 20000;
    displayName = "Crewman";
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Crew_DDPM.jpg";
};
class CUP_B_BAF_Medic_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    displayName = "Medic";
    accuracy = 3.7;
    cost = 100000;
    attendant = 1;
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Medic_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
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
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Soldier_JTAC_DDPM : CUP_B_BAF_Soldier_03_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.9;
    displayName = "Joint Terminal Attack Controller";
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    weapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","CUP_SOFLAM" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_UGL_HWS","Throw","Put","CUP_SOFLAM" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","Laserbatteries","Laserbatteries" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","SmokeShell","HandGrenade","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","CUP_1Rnd_Smoke_M203","CUP_1Rnd_Smoke_M203","CUP_1Rnd_SmokeRed_M203","CUP_1Rnd_SmokeGreen_M203","Laserbatteries","Laserbatteries" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_SL_C","UK3CB_BAF_H_Mk7_Camo_D" };
    Icon = "iconMan";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Soldier_JTAC_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};
class CUP_B_BAF_Engineer_DDPM : CUP_B_BAF_Soldier_01_DDPM {
    author = "$STR_CUP_AUTHOR_STRING";
    scope = 2;
    scopeCurator = 2;
    vehicleClass = "CUP_B_Men_GB_DDPM";
    editorSubcategory = "EdSubcat_Personnel_Camo_Desert";
    accuracy = 3.9;
    displayName = "Engineer";
    threat[] = { 1,0.5,0.1 };
    canDeactivateMines = 1;
    engineer = 1;
    weapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    respawnWeapons[] = { "UK3CB_BAF_L85A2_RIS","Throw","Put" };
    magazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell" };
    respawnMagazines[] = { "UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","UK3CB_BAF_556_30Rnd","HandGrenade","HandGrenade","SmokeShell" };
    linkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch","ItemRadio","UK3CB_BAF_HMNVS","UK3CB_BAF_V_Osprey_Rifleman_B","UK3CB_BAF_H_Mk7_Camo_D" };
    backpack = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
    icon = "iconManEngineer";
    picture = "pictureRepair";
    editorPreview = "CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\Data\preview\CUP_B_BAF_Engineer_DDPM.jpg";
    //headgearList[] = { "UK3CB_BAF_H_Mk7_Camo_D",1,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5,"UK3CB_BAF_H_Mk7_Camo_D",0.5 };
};

//UKSF
class UKSF_Clan_R : CUP_B_BAF_Soldier_MTP {
    author = "UKSF";
    scope = 2;
    displayName = "Rifleman";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_R.jpg);
    editorSubcategory = QEGVAR(common,uksf);
    cost = 100000;
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_1Para";
    backpack = "";
    weapons[] = { "Throw", "Put" };
    respawnWeapons[] = { "Throw", "Put" };
    magazines[] = {};
    respawnMagazines[] = {};
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch" };
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
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers {};
    };
};
class UKSF_Clan_O : UKSF_Clan_R {
    displayName = "Officer";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_O.jpg);
    icon = "iconManOfficer";
    cost = 100000;
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "UK3CB_BAF_H_Beret_PR" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "UK3CB_BAF_H_Beret_PR" };
};
class UKSF_Clan_SL : UKSF_Clan_R {
    displayName = "Section Leader";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_SL.jpg);
    icon = "iconManLeader";
};
class UKSF_Clan_MG : UKSF_Clan_R {
    displayName = "Machinegunner";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_MG.jpg);
    icon = "iconManMG";
};
class UKSF_Clan_AT : UKSF_Clan_R {
    displayName = "Rifleman (AT)";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_AT.jpg);
    icon = "iconManAT";
    threat[] = {1, 0.9, 0.3};
};
class UKSF_Clan_MED : UKSF_Clan_R {
    displayName = "Combat Medic";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_MED.jpg);
    icon = "iconManMedic";
    picture = "pictureHeal";
    attendant = 1;
    backpack = "UKSF_B_Medic";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR";
};
class UKSF_Clan_Sniper : UKSF_Clan_R {
    displayName = "Sniper";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_Sniper.jpg);
    camouflage = 0.6;
};
class UKSF_Clan_P : UKSF_Clan_R {
    author = "UKSF";
    displayName = "Pilot";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_HP.jpg);
    attendant = 1;
    threat[] = {1, 1, 1};
    uniformClass = "UK3CB_BAF_U_HeliPilotCoveralls_RAF";
};
