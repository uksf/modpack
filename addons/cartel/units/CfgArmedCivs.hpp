
// armed civs
class GVAR(armed_civ_1911) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Armed Civ (1911)";
    uniformClass = "CUP_U_C_Citizen_03";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_C_Tracksuit_02", 1,
        "CUP_U_C_Tracksuit_04", 1,
        "U_BG_Guerilla3_1", 1,
        "U_C_HunterBody_grn", 1,
        "U_I_C_Soldier_Bandit_2_F", 1,
        "U_I_C_Soldier_Bandit_3_F", 1
    };
    weapons[] = { "CUP_hgun_Colt1911","Put","Throw" };
    respawnWeapons[] = { "CUP_hgun_Colt1911","Put","Throw" };
    items[] = {};
    respawnItems[] = {};
    magazines[] = { "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911" };
    respawnMagazines[] = { "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911", "CUP_7Rnd_45ACP_1911" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
};

class GVAR(armed_civ_cz75) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Armed Civ (Cz75)";
    uniformClass = "CUP_U_C_Citizen_03";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_C_Tracksuit_02", 1,
        "CUP_U_C_Tracksuit_04", 1,
        "U_BG_Guerilla3_1", 1,
        "U_C_HunterBody_grn", 1,
        "U_I_C_Soldier_Bandit_2_F", 1,
        "U_I_C_Soldier_Bandit_3_F", 1
    };
    weapons[] = { "CUP_hgun_CZ75","Put","Throw" };
    respawnWeapons[] = { "CUP_hgun_CZ75","Put","Throw" };
    items[] = {};
    respawnItems[] = {};
    magazines[] = { "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75" };
    respawnMagazines[] = { "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75", "CUP_16Rnd_9x19_cz75" };
    linkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "", "", "" };
};

class GVAR(armed_civ_cz550) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Armed Civ (Cz550)";
    uniformClass = "U_C_HunterBody_grn";
    uksf_equipment_randomUniforms[] = {
        "CUP_U_C_Tracksuit_02", 1,
        "CUP_U_C_Tracksuit_04", 1,
        "U_BG_Guerilla3_1", 1,
        "U_C_HunterBody_grn", 1,
        "U_I_C_Soldier_Bandit_2_F", 1,
        "U_I_C_Soldier_Bandit_3_F", 1
    };
    weapons[] = { "CUP_srifle_CZ550","Put","Throw" };
    respawnWeapons[] = { "CUP_srifle_CZ550","Put","Throw" };
    items[] = {};
    respawnItems[] = {};
    magazines[] = { "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M" };
    respawnMagazines[] = { "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M", "CUP_5x_22_LR_17_HMR_M" };
    linkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_C_MAGA_01", "", "" };
    respawnLinkedItems[] = { "ItemMap", "ItemCompass", "CUP_H_C_MAGA_01", "", "" };
};
