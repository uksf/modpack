class GVAR(soldier_akn) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Soldier (AKN)";
    uniformClass = "CUP_U_B_BDUv2_desert";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_B_BDUv2_dirty_desert", 1,
        "CUP_U_B_BDUv2_gloves_desert", 1,
        "CUP_U_B_BDUv2_gloves_dirty_desert", 1,
        "CUP_U_B_BDUv2_roll2_dirty_desert", 1,
        "CUP_U_B_BDUv2_roll2_gloves_desert", 1,
        "CUP_U_B_BDUv2_roll2_gloves_dirty_desert", 1,
        "CUP_U_B_BDUv2_roll_dirty_desert", 1,
        "CUP_U_B_BDUv2_roll_gloves_dirty_desert", 1
    };
    weapons[] = { "CUP_arifle_AK47","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AK47","Put","Throw" };
    items[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    respawnItems[] = { "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage" };
    magazines[] = { "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_LWHv2_desert", "CUP_V_I_RACS_Carrier_Rig_2" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_LWHv2_desert", "CUP_V_I_RACS_Carrier_Rig_2" };
    backpack = "";
};
class GVAR(soldier_gp25) : GVAR(soldier_akn) {
    displayName = "Soldier (GP-25)";
    weapons[] = { "CUP_arifle_AKM_GL_Early","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AKM_GL_Early","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M", "CUP_1Rnd_HE_GP25_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_LWHv2_desert", "CUP_V_I_RACS_Carrier_Rig_3" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_LWHv2_desert", "CUP_V_I_RACS_Carrier_Rig_3" };
};
class GVAR(soldier_MG) : GVAR(soldier_akn) {
    displayName = "Soldier (MG)";
    weapons[] = { "CUP_lmg_PKM_B50_vfg","Put","Throw" };
    respawnWeapons[] = { "CUP_lmg_PKM_B50_vfg","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    backpack = QGVAR(Machine_Gunner_pack);
    icon = "iconManMG";
};
class GVAR(soldier_LAT) : GVAR(soldier_akn) {
    displayName = "Soldier (RPG)";
    weapons[] = { "CUP_launch_RPG7V","Put","Throw" };
    respawnWeapons[] = { "CUP_launch_RPG7V","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell" };
    backpack = QGVAR(lat_pack);
    icon = "iconManAT";
};
class GVAR(soldier_sks) : GVAR(soldier_akn) {
    displayName = "Soldier (SKS)";
    weapons[] = { "CUP_SKS","Put","Throw" };
    respawnWeapons[] = { "CUP_SKS","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M" };
};
class GVAR(soldier_aa) : GVAR(soldier_akn) {
    displayName = "Soldier (AA)";
    weapons[] = { "CUP_arifle_AK47", "CUP_launch_Igla","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AK47", "CUP_launch_Igla","Put","Throw" };
    icon = "iconManAT";
};
class GVAR(soldier_enfield) : GVAR(soldier_akn) {
    displayName = "Soldier (Enfield)";
    weapons[] = { QGVAR(enfield_burris),"Put","Throw" };
    respawnWeapons[] = { QGVAR(enfield_burris),"Put","Throw" };
    magazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO" };
    respawnMagazines[] = { "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_10x_303_M", "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO" };
};
class GVAR(officer) : GVAR(soldier_akn) {
    displayName = "Officer";
    weapons[] = { "CUP_SKS","Put","Throw" };
    respawnWeapons[] = { "CUP_SKS","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M", "CUP_10Rnd_762x39_SKS_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_H_US_patrol_cap_desert", "CUP_V_I_RACS_Carrier_Rig_3" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_US_patrol_cap_desert", "CUP_V_I_RACS_Carrier_Rig_3" };
};
