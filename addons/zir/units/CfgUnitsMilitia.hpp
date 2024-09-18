class GVAR(Militia_akn) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (AKN)";
    uniformClass = "CUP_O_TKI_Khet_Partug_06";
    uksf_equipment_randomUniforms[] = {
        "CUP_O_TKI_Khet_Partug_01", 1,
        "CUP_O_TKI_Khet_Partug_02", 1,
        "CUP_O_TKI_Khet_Partug_03", 1,
        "CUP_O_TKI_Khet_Partug_04", 1,
        "CUP_O_TKI_Khet_Partug_05", 1,
        "CUP_O_TKI_Khet_Partug_06", 1,
        "CUP_O_TKI_Khet_Partug_07", 1,
        "CUP_O_TKI_Khet_Partug_08", 1,

        "CUP_O_TKI_Khet_Jeans_01", 1,
        "CUP_O_TKI_Khet_Jeans_02", 1,
        "CUP_O_TKI_Khet_Jeans_03", 1,
        "CUP_O_TKI_Khet_Jeans_04", 1
    };
    weapons[] = { "CUP_arifle_AK47","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AK47","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_TKI_Lungee_01", "CUP_V_OI_TKI_Jacket4_01" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_TKI_Lungee_01", "CUP_V_OI_TKI_Jacket4_01" };
    backpack = "";
};
class GVAR(Militia_gp25) : GVAR(Militia_akn) {
    displayName = "Militia (GP-25)";
    weapons[] = { "CUP_arifle_AKM_GL_Early","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AKM_GL_Early","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_TKI_Lungee_02", "CUP_V_OI_TKI_Jacket4_05" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_TKI_Lungee_02", "CUP_V_OI_TKI_Jacket4_05" };
};
class GVAR(Militia_MG) : GVAR(Militia_akn) {
    displayName = "Militia (MG)";
    weapons[] = { "CUP_lmg_PKM_B50_vfg","Put","Throw" };
    respawnWeapons[] = { "CUP_lmg_PKM_B50_vfg","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_TKI_Lungee_03", "CUP_V_OI_TKI_Jacket3_03" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_TKI_Lungee_03", "CUP_V_OI_TKI_Jacket3_03" };
    backpack = QGVAR(Machine_Gunner_pack);
    icon = "iconManMG";
};
class GVAR(Militia_LAT) : GVAR(Militia_akn) {
    displayName = "Militia (RPG)";
    weapons[] = { "CUP_launch_RPG7V","Put","Throw" };
    respawnWeapons[] = { "CUP_launch_RPG7V","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    backpack = QGVAR(lat_pack);
    icon = "iconManAT";
};
class GVAR(Militia_sks) : GVAR(Militia_akn) {
    displayName = "Militia (SKS)";
    weapons[] = { "CUP_SKS","Put","Throw" };
    respawnWeapons[] = { "CUP_SKS","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_TKI_Lungee_04", "CUP_V_OI_TKI_Jacket5_03" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_TKI_Lungee_04", "CUP_V_OI_TKI_Jacket5_03" };
};
class GVAR(Militia_aa) : GVAR(Militia_akn) {
    displayName = "Militia (AA)";
    weapons[] = { "CUP_arifle_AK47", "CUP_launch_Igla","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AK47", "CUP_launch_Igla","Put","Throw" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_TKI_Lungee_04", "CUP_V_OI_TKI_Jacket1_05" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_TKI_Lungee_04", "CUP_V_OI_TKI_Jacket1_05" };
    icon = "iconManAT";
};
class GVAR(Militia_enfield) : GVAR(Militia_akn) {
    displayName = "Militia (Enfield)";
    weapons[] = { QGVAR(enfield_burris),"Put","Throw" };
    respawnWeapons[] = { QGVAR(enfield_burris),"Put","Throw" };
    magazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO" };
    respawnMagazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_TKI_Lungee_04", "CUP_V_OI_TKI_Jacket2_05" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_TKI_Lungee_04", "CUP_V_OI_TKI_Jacket2_05" };
};
class GVAR(Militia_sniper) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Militia (Sniper)";
    uniformClass = "CUP_I_B_PMC_Unit_43";
    uksf_equipment_randomUniforms[] = {
        "CUP_I_B_PMC_Unit_15", 1,
        "CUP_I_B_PMC_Unit_32", 1,
        "CUP_I_B_PMC_Unit_16", 1
     };
    weapons[] = { QGVAR(cz750_mr10),"Put","Throw" };
    respawnWeapons[] = { QGVAR(cz750_mr10),"Put","Throw" };
    magazines[] = { "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750" };
    respawnMagazines[] = { "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750", "CUP_10Rnd_762x51_CZ750" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "H_ShemagOpen_tan", "V_Chestrig_khk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "H_ShemagOpen_tan", "V_Chestrig_khk" };
};
