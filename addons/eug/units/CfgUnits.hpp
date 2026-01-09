// Units
class GVAR(Rifleman) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Rifleman";
    uniformClass = "CUP_U_B_BDUv2_gloves_desert";
    weapons[] = { QGVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG2),"CUP_hgun_M9","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_M16A4_Base_CUP_optic_ACOG2", "CUP_hgun_M9", "Put", "Throw" };
    items[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShell", "SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    backpack = "";
};
class GVAR(Squad_Leader) : GVAR(Rifleman) {
    displayName = "Squad Leader";
    weapons[] = { QGVAR(CUP_arifle_M16A4_GL_Aimpoint_5000),"CUP_hgun_M9","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_M16A4_GL_Aimpoint_5000),"CUP_hgun_M9","Put","Throw" };
    magazines[] = { "1Rnd_HE_Grenade_shell", "1Rnd_HE_Grenade_shell", "1Rnd_HE_Grenade_shell", "1Rnd_HE_Grenade_shell", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "1Rnd_HE_Grenade_shell", "1Rnd_HE_Grenade_shell", "1Rnd_HE_Grenade_shell", "1Rnd_HE_Grenade_shell", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "SmokeShell", "SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_co_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_co_des", "NVGoggles" };
    icon = "iconManLeader";
};
class GVAR(Officer) : GVAR(Rifleman) {
    displayName = "Officer";
    uniformClass = "CUP_U_B_BDUv2_desert";
    weapons[] = { "Binocular", "CUP_arifle_M16A4_Base", "CUP_hgun_M9", "Put", "Throw" };
    respawnWeapons[] = { "Binocular", "CUP_arifle_M16A4_Base", "CUP_hgun_M9", "Put", "Throw" };
    items[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "SmokeShell", "SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemGPS", "Binocular", "CUP_H_SLA_BeretRed", "V_TacVest_brn" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemGPS", "Binocular", "CUP_H_SLA_BeretRed", "V_TacVest_brn" };
    icon = "iconManOfficer";
};
class GVAR(LMG_Gunner) : GVAR(Rifleman) {
    displayName = "LMG Gunner";
    weapons[] = { QGVAR(LMG_Mk200_black_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk),"Put","Throw" };
    respawnWeapons[] = { QGVAR(LMG_Mk200_black_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk),"Put","Throw" };
    magazines[] = { "200Rnd_65x39_cased_Box", "200Rnd_65x39_cased_Box", "HandGrenade", "HandGrenade", "SmokeShell", "SmokeShell", "200Rnd_65x39_cased_Box", "200Rnd_65x39_cased_Box", "200Rnd_65x39_cased_Box" };
    respawnMagazines[] = { "200Rnd_65x39_cased_Box", "200Rnd_65x39_cased_Box", "HandGrenade", "HandGrenade", "SmokeShell", "SmokeShell", "200Rnd_65x39_cased_Box", "200Rnd_65x39_cased_Box", "200Rnd_65x39_cased_Box" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_ok_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_ok_des", "NVGoggles" };
    backpack = QGVAR(LMG_Gunner_pack);
    icon = "iconManMG";
};
class GVAR(HMG_Gunner) : GVAR(Rifleman) {
    displayName = "HMG Gunner";
    weapons[] = { QGVAR(MMG_01_tan_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk),"Put","Throw" };
    respawnWeapons[] = { QGVAR(MMG_01_tan_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk),"Put","Throw" };
    magazines[] = { "HandGrenade", "HandGrenade", "SmokeShell", "SmokeShell", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag" };
    respawnMagazines[] = { "HandGrenade", "HandGrenade", "SmokeShell", "SmokeShell", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag", "150Rnd_93x64_Mag" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_ok_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_ok_des", "NVGoggles" };
    backpack = QGVAR(HMG_Gunner_pack);
    icon = "iconManMG";
};
class GVAR(Rifleman_Light_AT) : GVAR(Rifleman) {
    displayName = "Rifleman Light AT";
    weapons[] = { GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black), "launch_RPG32_F", "CUP_hgun_M9", "Put", "Throw" };
    respawnWeapons[] = { GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black), "launch_RPG32_F", "CUP_hgun_M9", "Put", "Throw" };
    magazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "RPG32_F", "RPG32_F", "RPG32_F", "RPG32_HE_F", "RPG32_HE_F" };
    respawnMagazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "RPG32_F", "RPG32_F", "RPG32_F", "RPG32_HE_F", "RPG32_HE_F" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    backpack = QGVAR(Rifleman_Light_AT_pack);
    icon = "iconManAT";
};
class GVAR(Rifleman_Heavy_AT) : GVAR(Rifleman) {
    displayName = "Rifleman Heavy AT";
    weapons[] = { GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black), "launch_O_Vorona_brown_F", "CUP_hgun_M9", "Put", "Throw" };
    respawnWeapons[] = { GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black), "launch_O_Vorona_brown_F", "CUP_hgun_M9", "Put", "Throw" };
    magazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "Vorona_HEAT" };
    respawnMagazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "Vorona_HEAT" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    backpack = QGVAR(Rifleman_Heavy_AT_pack);
    icon = "iconManAT";
};
class GVAR(Rifleman_AA) : GVAR(Rifleman) {
    displayName = "Rifleman AA";
    weapons[] = { GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black), "CUP_launch_Igla_Loaded", "CUP_hgun_M9", "Put", "Throw" };
    respawnWeapons[] = { GVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black), "CUP_launch_Igla_Loaded", "CUP_hgun_M9", "Put", "Throw" };
    magazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShell", "SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_co_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_co_des", "NVGoggles" };
};
class GVAR(Radio_Operator) : GVAR(Rifleman) {
    displayName = "Radio Operator";
    weapons[] = { QGVAR(CUP_arifle_Colt727_M203_CUP_optic_ACOG_TA01B_RMR_Black),"Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_Colt727_M203_CUP_optic_ACOG_TA01B_RMR_Black),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67" };
    respawnMagazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeRed_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_SmokeGreen_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "1Rnd_Smoke_Grenade_shell", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_co_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetSpecB_sand", "CUP_V_CZ_NPP2006_co_des", "NVGoggles" };
    backpack = "B_RadioBag_01_wdl_F";
};
class GVAR(Combat_Medic) : GVAR(Rifleman) {
    displayName = "Combat Medic";
    weapons[] = { QGVAR(CUP_arifle_Colt727),"CUP_hgun_M9","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_Colt727),"CUP_hgun_M9","Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_surgicalKit", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV", "ACE_salineIV" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_surgicalKit", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV", "ACE_salineIV" };
    magazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShellYellow", "SmokeShellYellow", "SmokeShell", "SmokeShell", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    respawnMagazines[] = { "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShellYellow", "SmokeShellYellow", "SmokeShell", "SmokeShell", "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    backpack = QGVAR(Combat_Medic_pack);
    icon = "iconManMedic";
    attendant = 1;
    picture = "pictureHeal";
};

// SF
class GVAR(SF_Rifleman) : GVAR(Rifleman) {
    editorSubcategory = QEGVAR(common,sf);
    displayName = "SF Rifleman";
    uniformClass = "CUP_U_CRYE_G3C_AOR1";
    weapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"CUP_launch_RPG18_Loaded","Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"CUP_launch_RPG18_Loaded","Put","Throw" };
    items[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    respawnItems[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    magazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_tlbelt_coy", "CUP_G_Scarf_Face_Tan", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_tlbelt_coy", "CUP_G_Scarf_Face_Tan", "CUP_NVG_GPNVG_Hide" };
};
class GVAR(SF_Teamlead) : GVAR(SF_Rifleman) {
    displayName = "SF Teamlead";
    weapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    magazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_communicationsbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_communicationsbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
};
class GVAR(SF_Medic) : GVAR(SF_Rifleman) {
    displayName = "SF Medic";
    weapons[] = { "Laserdesignator", GVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS), "Put", "Throw" };
    respawnWeapons[] = { "Laserdesignator", GVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS), "Put", "Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_epinephrine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet" };
    magazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_PVS14_Hide", "Laserdesignator", "CUP_H_FR_ECH", "CUP_V_CPC_medicalbelt_coy", "CUP_TK_NeckScarf", "CUP_NVG_PVS14_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_PVS14_Hide", "Laserdesignator", "CUP_H_FR_ECH", "CUP_V_CPC_medicalbelt_coy", "CUP_TK_NeckScarf", "CUP_NVG_PVS14_Hide" };
    backpack = QGVAR(SF_Medic_pack);
    icon = "iconManMedic";
    attendant = 1;
    picture = "pictureHeal";
};
class GVAR(SF_AT) : GVAR(SF_Rifleman) {
    displayName = "SF AT";
    weapons[] = { "Laserdesignator",GVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),QGVAR(CUP_launch_MAAWS_CUP_optic_MAAWS_Scope),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",GVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),QGVAR(CUP_launch_MAAWS_CUP_optic_MAAWS_Scope),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    magazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_MAAWS_HEDP_M", "CUP_MAAWS_HEDP_M" };
    respawnMagazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_MAAWS_HEDP_M", "CUP_MAAWS_HEDP_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_Fastbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_Fastbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
    backpack = QGVAR(SF_AT_pack);
    icon = "iconManAT";
};
class GVAR(SF_LMG) : GVAR(SF_Rifleman) {
    displayName = "SF LMG";
    weapons[] = { "Laserdesignator",QGVAR(CUP_arifle_RPK74M_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(CUP_arifle_RPK74M_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    magazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_weaponsbelt_coy", "CUP_G_ESS_KHK_Scarf_Tan", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_weaponsbelt_coy", "CUP_G_ESS_KHK_Scarf_Tan", "CUP_NVG_GPNVG_Hide" };
    backpack = QGVAR(SF_LMG_pack);
    icon = "iconManMG";
};
class GVAR(SF_Comms) : GVAR(SF_Rifleman) {
    displayName = "SF Comms";
    weapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    magazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_communicationsbelt_coy", "CUP_G_ESS_KHK_Facewrap_Tan", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_communicationsbelt_coy", "CUP_G_ESS_KHK_Facewrap_Tan", "CUP_NVG_GPNVG_Hide" };
    backpack = QGVAR(SF_Comms_pack);
};
class GVAR(SF_Sniper) : GVAR(SF_Rifleman) {
    displayName = "SF Sniper";
    weapons[] = { "Laserdesignator",QGVAR(srifle_DMR_05_tan_f_muzzle_snds_93mmg_tanACE_optic_LRPS_2Dbipod_02_F_arid),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(srifle_DMR_05_tan_f_muzzle_snds_93mmg_tanACE_optic_LRPS_2Dbipod_02_F_arid),"Put","Throw" };
    items[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_EarPlugs", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag" };
    respawnMagazines[] = { "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag", "10Rnd_93x64_DMR_05_Mag" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemGPS", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "H_Booniehat_khk_hs", "CUP_V_CPC_lightbelt_coy", "CUP_G_ESS_KHK_Facewrap_Tan", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemGPS", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "H_Booniehat_khk_hs", "CUP_V_CPC_lightbelt_coy", "CUP_G_ESS_KHK_Facewrap_Tan", "CUP_NVG_GPNVG_Hide" };
    backpack = QGVAR(SF_Sniper_pack);
};

// SF Para
class GVAR(SF_Rifleman_Para) : GVAR(SF_Rifleman) {
    editorSubcategory = QEGVAR(common,para);
    displayName = "SF Rifleman (Para)";
    weapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"CUP_launch_RPG18_Loaded","Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"CUP_launch_RPG18_Loaded","Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    magazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_tlbelt_coy", "CUP_G_Scarf_Face_Tan", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_tlbelt_coy", "CUP_G_Scarf_Face_Tan", "CUP_NVG_GPNVG_Hide" };
    backpack = "B_Parachute";
};
class GVAR(SF_Teamlead_Para) : GVAR(SF_Rifleman_Para) {
    displayName = "SF Teamlead (Para)";
    weapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet" };
    magazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_30Rnd_762x39_AKM_bakelite_desert_M", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_communicationsbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_communicationsbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
    icon = "iconManLeader";
};
class GVAR(SF_AT_Para) : GVAR(SF_Rifleman_Para) {
    displayName = "SF AT (Para)";
    weapons[] = { "Laserdesignator",GVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),QGVAR(CUP_launch_MAAWS_CUP_optic_MAAWS_Scope),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",GVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),QGVAR(CUP_launch_MAAWS_CUP_optic_MAAWS_Scope),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    magazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_Fastbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_Fastbelt_coy", "CUP_G_ESS_KHK_Scarf_Face_Tan_GPS", "CUP_NVG_GPNVG_Hide" };
    icon = "iconManAT";
};
class GVAR(SF_LMG_Para) : GVAR(SF_Rifleman_Para) {
    displayName = "SF LMG (Para)";
    weapons[] = { "Laserdesignator",QGVAR(CUP_arifle_RPK74M_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),"Put","Throw" };
    respawnWeapons[] = { "Laserdesignator",QGVAR(CUP_arifle_RPK74M_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),"Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_splint", "ACE_splint", "ACE_tourniquet", "ACE_tourniquet", "ACE_EarPlugs" };
    magazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "ACE_M84", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M", "CUP_60Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_weaponsbelt_coy", "CUP_G_ESS_KHK_Scarf_Tan", "CUP_NVG_GPNVG_Hide" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "CUP_NVG_GPNVG_Hide", "Laserdesignator", "CUP_H_USArmy_Helmet_ECH1_Sand", "CUP_V_CPC_weaponsbelt_coy", "CUP_G_ESS_KHK_Scarf_Tan", "CUP_NVG_GPNVG_Hide" };
    icon = "iconManMG";
};

// Crew
class GVAR(Tank_Crew) : GVAR(Rifleman) {
    editorSubcategory = QEGVAR(common,crew);
    displayName = "Tank Crew";
    uniformClass = "CUP_U_B_CZ_Pilot_WDL";
    weapons[] = { "CUP_arifle_AKS74U", "hgun_Rook40_F", "Put", "Throw" };
    respawnWeapons[] = { "CUP_arifle_AKS74U", "hgun_Rook40_F", "Put", "Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_NVG_PVS15_black", "H_HelmetCrew_I_E", "CUP_V_CPC_light_coy", "CUP_NVG_PVS15_black" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_NVG_PVS15_black", "H_HelmetCrew_I_E", "CUP_V_CPC_light_coy", "CUP_NVG_PVS15_black" };
};
class GVAR(Vehicle_Crew) : GVAR(Rifleman) {
    editorSubcategory = QEGVAR(common,crew);
    displayName = "Vehicle Crew";
    uniformClass = "CUP_U_B_BDUv2_gloves_desert";
    weapons[] = { QGVAR(CUP_arifle_Colt727),"CUP_hgun_M9","Put","Throw" };
    respawnWeapons[] = { QGVAR(CUP_arifle_Colt727),"CUP_hgun_M9","Put","Throw" };
    items[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShell", "SmokeShell", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag" };
    respawnMagazines[] = { "CUP_15Rnd_9x19_M9", "CUP_15Rnd_9x19_M9", "CUP_HandGrenade_M67", "CUP_HandGrenade_M67", "SmokeShell", "SmokeShell", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag", "ACE_30Rnd_556x45_Stanag_Mk318_mag" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemAndroid", "NVGoggles", "H_HelmetB_light_sand", "CUP_V_CZ_NPP2006_nk_des", "NVGoggles" };
};
class GVAR(Heli_Crew) : GVAR(Rifleman) {
    editorSubcategory = QEGVAR(common,crew);
    displayName = "Heli Crew";
    uniformClass = "CUP_U_I_RACS_PilotOverall";
    weapons[] = { "CUP_arifle_AKS74U", "hgun_Rook40_F", "Put", "Throw" };
    respawnWeapons[] = { "CUP_arifle_AKS74U", "hgun_Rook40_F", "Put", "Throw" };
    items[] = { "FirstAidKit" };
    respawnItems[] = { "FirstAidKit" };
    magazines[] = { "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "SmokeShellOrange", "Chemlight_green", "Chemlight_green", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    respawnMagazines[] = { "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "SmokeShellOrange", "Chemlight_green", "Chemlight_green", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M", "CUP_30Rnd_545x39_AK74M_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_PilotHelmetHeli_B", "V_TacVest_khk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_PilotHelmetHeli_B", "V_TacVest_khk" };
};
class GVAR(Jet_Pilot) : GVAR(Rifleman) {
    editorSubcategory = QEGVAR(common,crew);
    displayName = "Jet Pilot";
    uniformClass = "U_O_PilotCoveralls";
    weapons[] = { "hgun_Rook40_F", "Put", "Throw" };
    respawnWeapons[] = { "hgun_Rook40_F", "Put", "Throw" };
    items[] = { "FirstAidKit" };
    respawnItems[] = { "FirstAidKit" };
    magazines[] = { "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "SmokeShellOrange", "Chemlight_green", "Chemlight_green" };
    respawnMagazines[] = { "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "16Rnd_9x21_Mag", "SmokeShellOrange", "Chemlight_green", "Chemlight_green" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_PilotHelmetFighter_O" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "H_PilotHelmetFighter_O" };
    backpack = "B_Parachute";
};
