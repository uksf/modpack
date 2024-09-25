class GVAR(pg_soldier) : GVAR(Soldier_Base_Puritan_Guard) {
    scope = 2;
    displayName = "Soldier";
    uniformClass = "CUP_O_TKI_Khet_Partug_04";
    uksf_equipment_randomUniforms[] = {
        "CUP_O_TKI_Khet_Partug_04", 1,
    };
    weapons[] = { "CUP_arifle_AKS74U","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AKS74U","Put","Throw" };
    items[] = {};
    respawnItems[] = {};
    magazines[] = { "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "30Rnd_545x39_Mag_F", "CUP_HandGrenade_RGD5", "CUP_HandGrenade_RGD5" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "", "CUP_V_I_RACS_Carrier_Rig_wdl_2", "CUP_RUS_Balaclava_blk" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "CUP_V_I_RACS_Carrier_Rig_wdl_2", "CUP_RUS_Balaclava_blk" };
    backpack = "";
};
class GVAR(pg_commander) : GVAR(pg_soldier) {
    displayName = "Commander";
    weapons[] = { "CUP_arifle_AKS","Put","Throw" };
    respawnWeapons[] = { "CUP_arifle_AKS","Put","Throw" };
    magazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M" };
    respawnMagazines[] = { "CUP_HandGrenade_RGO", "CUP_HandGrenade_RGO", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M", "CUP_30Rnd_762x39_AK47_M" };
};
