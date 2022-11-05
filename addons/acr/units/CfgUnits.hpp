//Units
class UKSF_ACR_Rifleman: UKSF_ACR_Soldier_Base
{
    scope = 2;
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Rifleman";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_B_CZ_WDL_NoKneepads", 1,
        "CUP_U_B_CZ_WDL_Kneepads_Gloves", 1
    };
    weapons[] = {"UKSF_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","Put","Throw"};
    items[] = {"ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage"};
    respawnItems[] = {"ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage"};
    magazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    respawnMagazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    linkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest04","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest04","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    backpack = "";

};

class UKSF_ACR_Squad_Leader: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Squad Leader";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    weapons[] = {"UKSF_ACR_CUP_arifle_ACRC_EGLM_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_arifle_ACRC_EGLM_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","Put","Throw"};
    magazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell"};
    respawnMagazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell","1Rnd_HE_Grenade_shell"};
    backpack = "UKSF_ACR_Squad_Leader_pack";

};

class UKSF_ACR_Autorifleman: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Autorifleman";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    weapons[] = {"UKSF_ACR_LMG_03_F_CUP_acc_FlashlightACE_optic_MRCO_2D","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_LMG_03_F_CUP_acc_FlashlightACE_optic_MRCO_2D","Put","Throw"};
    magazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249"};
    respawnMagazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249","CUP_100Rnd_TE4_Green_Tracer_556x45_M249"};
    backpack = "UKSF_ACR_Machine_Gunner_pack";

};

class UKSF_ACR_Rifleman_LAT: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Rifleman LAT";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    weapons[] = {"UKSF_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","CUP_launch_RPG7V","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","CUP_launch_RPG7V","Put","Throw"};
    magazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_OG7_M","CUP_PG7V_M","CUP_PG7V_M"};
    respawnMagazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_OG7_M","CUP_PG7V_M","CUP_PG7V_M"};
    backpack = "UKSF_ACR_Rifleman_LAT_pack";

};

class UKSF_ACR_Sharpshooter: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Sharpshooter";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    weapons[] = {"UKSF_ACR_CUP_srifle_SVD_wdl_CUP_optic_PSO_1_1_open","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_srifle_SVD_wdl_CUP_optic_PSO_1_1_open","Put","Throw"};
    magazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M"};
    respawnMagazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M","CUP_10Rnd_762x54_SVD_M"};
    backpack = "UKSF_ACR_Sharpshooter_pack";

};

class UKSF_ACR_Armour_Crewman: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Armour Crewman";
    uniformClass = "CUP_U_B_CZ_WDL_TShirt";
    weapons[] = {"CUP_arifle_ACRC_blk_556","Put","Throw"};
    respawnWeapons[] = {"CUP_arifle_ACRC_blk_556","Put","Throw"};
    magazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    respawnMagazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    linkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","H_Tank_black_F","CUP_V_CZ_vest04","CUP_NVG_PVS15_green_WP"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","H_Tank_black_F","CUP_V_CZ_vest04","CUP_NVG_PVS15_green_WP"};
    backpack = "";
    uksf_equipment_skipRandomization = 1;
};

class UKSF_ACR_Officer: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Officer";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    linkedItems[] = {"ItemMap","ItemCompass","CUP_H_CZ_Patrol_Cap","CUP_V_CZ_NPP2006_co_vz95"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","CUP_H_CZ_Patrol_Cap","CUP_V_CZ_NPP2006_co_vz95"};
    backpack = "";
    uksf_equipment_skipRandomization = 1;
};

class UKSF_ACR_Signaller: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Signaller";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    linkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest04","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest04","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    backpack = "UKSF_ACR_Signaller_pack";

};

class UKSF_ACR_Heli_Pilot: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Heli Pilot";
    uniformClass = "CUP_U_B_CZ_Pilot_WDL";
    weapons[] = {"CUP_arifle_ACRC_blk_556","CUP_hgun_CZ75","Put","Throw"};
    respawnWeapons[] = {"CUP_arifle_ACRC_blk_556","CUP_hgun_CZ75","Put","Throw"};
    magazines[] = {"SmokeShell","SmokeShell","SmokeShell","SmokeShell","SmokeShell","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","ACE_M14","ACE_M14","ACE_M14","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green"};
    respawnMagazines[] = {"SmokeShell","SmokeShell","SmokeShell","SmokeShell","SmokeShell","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","ACE_M14","ACE_M14","ACE_M14","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green"};
    linkedItems[] = {"ItemMap","ItemCompass","ItemWatch","H_PilotHelmetHeli_B","CUP_V_CZ_NPP2006_nk_black"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","ItemWatch","H_PilotHelmetHeli_B","CUP_V_CZ_NPP2006_nk_black"};
    backpack = "";
    uksf_equipment_skipRandomization = 1;
};

class UKSF_ACR_Sniper: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Sniper";
    uniformClass = "U_I_FullGhillie_lsh";
    weapons[] = {"UKSF_ACR_CUP_srifle_M2010_blk_ACE_optic_LRPS_2D","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_srifle_M2010_blk_ACE_optic_LRPS_2D","Put","Throw"};
    magazines[] = {"SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M"};
    respawnMagazines[] = {"SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M","CUP_5Rnd_762x67_M2010_M"};
    linkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest02","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest02","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    backpack = "";
    uksf_equipment_skipRandomization = 1;
};

class UKSF_ACR_Crewman: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Crewman";
    uniformClass = "CUP_U_B_CZ_WDL_TShirt";
    weapons[] = {"CUP_arifle_ACRC_blk_556","Put","Throw"};
    respawnWeapons[] = {"CUP_arifle_ACRC_blk_556","Put","Throw"};
    magazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    respawnMagazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    backpack = "";
    uksf_equipment_skipRandomization = 1;
};

class UKSF_ACR_Jet_Pilot: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Jet Pilot";
    uniformClass = "CUP_U_B_CZ_Pilot_WDL";
    weapons[] = {"CUP_arifle_ACRC_blk_556","CUP_hgun_CZ75","Put","Throw"};
    respawnWeapons[] = {"CUP_arifle_ACRC_blk_556","CUP_hgun_CZ75","Put","Throw"};
    magazines[] = {"SmokeShell","SmokeShell","SmokeShell","SmokeShell","SmokeShell","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","ACE_M14","ACE_M14","ACE_M14","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green"};
    respawnMagazines[] = {"SmokeShell","SmokeShell","SmokeShell","SmokeShell","SmokeShell","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","CUP_16Rnd_9x19_cz75","ACE_M14","ACE_M14","ACE_M14","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green","30Rnd_556x45_Stanag_green"};
    linkedItems[] = {"ItemMap","ItemCompass","ItemWatch","H_PilotHelmetFighter_O","CUP_V_CZ_NPP2006_nk_black"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","ItemWatch","H_PilotHelmetFighter_O","CUP_V_CZ_NPP2006_nk_black"};
    backpack = "";
    uksf_equipment_skipRandomization = 1;
};

class UKSF_ACR_Rifleman_AA: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Rifleman AA";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    weapons[] = {"uksf_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","CUP_launch_FIM92Stinger_Loaded","Put","Throw"};
    respawnWeapons[] = {"uksf_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","CUP_launch_FIM92Stinger_Loaded","Put","Throw"};
    magazines[] = {"CUP_30Rnd_556x45_Stanag","SmokeShell","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    respawnMagazines[] = {"CUP_30Rnd_556x45_Stanag","SmokeShell","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","SmokeShell","SmokeShell","CUP_HandGrenade_RGD5","CUP_HandGrenade_RGD5"};
    backpack = "";

};

class UKSF_ACR_Paratrooper: UKSF_ACR_Rifleman
{
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Paratrooper";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    linkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest04","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    respawnLinkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_PVS15_green_WP","CUP_H_CZ_Helmet03","CUP_V_CZ_vest04","G_Bandanna_oli","CUP_NVG_PVS15_green_WP"};
    backpack = "B_Parachute";

};

class UKSF_ACR_Machine_Gunner: UKSF_ACR_Rifleman {
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Machine Gunner";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    weapons[] = {"UKSF_ACR_CUP_lmg_MG3_rail_ACE_optic_MRCO_2D","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_lmg_MG3_rail_ACE_optic_MRCO_2D","Put","Throw"};
    magazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M"};
    respawnMagazines[] = {"CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M","CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M"};
    backpack = "UKSF_ACR_Machine_Gunner_pack";
};

class UKSF_ACR_Rifleman_HAT: UKSF_ACR_Rifleman {
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Rifleman HAT";
    uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
    weapons[] = {"UKSF_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","launch_I_Titan_short_F","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D","launch_I_Titan_short_F","Put","Throw"};
    magazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","Titan_AP","Titan_AP","Titan_AT"};
    respawnMagazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_30Rnd_556x45_Stanag_Tracer_Green","CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell","Titan_AP","Titan_AP","Titan_AT"};
    backpack = "UKSF_ACR_Rifleman_HAT_pack";
};

class UKSF_ACR_Operator: UKSF_ACR_Rifleman {
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Operator";
    uniformClass = "CUP_U_B_CZ_WDL_Kneepads";
    weapons[] = {"UKSF_ACR_CUP_arifle_HK416_Black_ZO_Low_anpeq","Put","Throw"};
    respawnWeapons[] = {"UKSF_ACR_CUP_arifle_HK416_Black_ZO_Low_anpeq","Put","Throw"};
    magazines[] = {"CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell"};
    respawnMagazines[] = {"CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_30Rnd_556x45_PMAG_QP","CUP_HandGrenade_RGO","CUP_HandGrenade_RGO","SmokeShell","SmokeShell","SmokeShell"};
    linkedItems[] = {"ItemMap","ItemCompass","CUP_NVG_GPNVG_black","CUP_H_OpsCore_Black","CUP_V_CZ_NPP2006_ok_black","CUP_G_Scarf_Face_Blk"};
    backpack = "UKSF_ACR_Operator_Pack";
    uksf_equipment_skipRandomization = 1;
}
