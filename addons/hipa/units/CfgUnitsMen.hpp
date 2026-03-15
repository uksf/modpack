// Regular infantry units (Men category)
class GVAR(Rifleman) : GVAR(Soldier_Base) {
    scope = 2;
    scopeCurator = 2;
    displayName = "Rifleman";
    backpack = "";
};

class GVAR(Squad_Leader) : GVAR(Rifleman) {
    displayName = "Squad Leader";
    weapons[] = {QGVAR(CUP_arifle_G36K_RIS_AG36_ACE_optic_MRCO_2D_acc_flashlight)};
    respawnWeapons[] = {QGVAR(CUP_arifle_G36K_RIS_AG36_ACE_optic_MRCO_2D_acc_flashlight)};
    backpack = QGVAR(sl_backpack);
};

class GVAR(Machine_Gunner) : GVAR(Rifleman) {
    displayName = "Machine Gunner";
    weapons[] = {CUP_lmg_MG3};
    respawnWeapons[] = {CUP_lmg_MG3};
    magazines[] = {"CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M", "CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M", "SmokeShell", "SmokeShell"};
    respawnMagazines[] = {"CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M", "CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M", "SmokeShell", "SmokeShell"};
    backpack = QGVAR(mg_backpack);
};

class GVAR(Rifleman_LAT) : GVAR(Rifleman) {
    displayName = "Rifleman (LAT)";
    weapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "CUP_launch_Mk153Mod0", "Put", "Throw"};
    respawnWeapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "CUP_launch_Mk153Mod0", "Put", "Throw"};
    magazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
        "SmokeShell", "HandGrenade", "HandGrenade", "CUP_SMAW_HEDP_M"
    };
    respawnMagazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
        "SmokeShell", "HandGrenade", "HandGrenade", "CUP_SMAW_HEDP_M"
    };
    backpack = QGVAR(lat_backpack);
};

class GVAR(Rifleman_HAT) : GVAR(Rifleman) {
    displayName = "Rifleman (HAT)";
    weapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "launch_RPG32_green_F", "Put", "Throw"};
    respawnWeapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "launch_RPG32_green_F", "Put", "Throw"};
    magazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
        "SmokeShell", "HandGrenade", "HandGrenade", "RPG32_F"
    };
    respawnMagazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
        "SmokeShell", "HandGrenade", "HandGrenade", "RPG32_F"
    };
    backpack = QGVAR(hat_backpack);
};

class GVAR(Sharpshooter) : GVAR(Rifleman) {
    displayName = "Sharpshooter";
    weapons[] = {QGVAR(arifle_SPAR_03_blk_F_optic_AMS)};
    respawnWeapons[] = {QGVAR(arifle_SPAR_03_blk_F_optic_AMS)};
    magazines[] = {
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417",
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417",
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417",
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417"
    };
    respawnMagazines[] = {
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417",
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417",
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417",
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417",
        "CUP_20Rnd_762x51_HK417", "CUP_20Rnd_762x51_HK417"
    };
};

class GVAR(Rifleman_AA) : GVAR(Rifleman) {
    displayName = "Rifleman (AA)";
    weapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "launch_B_Titan_olive_F", "Put", "Throw"};
    respawnWeapons[] = {QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight), "launch_B_Titan_olive_F", "Put", "Throw"};
    magazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
        "SmokeShell", "HandGrenade", "HandGrenade", "Titan_AA"
    };
    respawnMagazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8", "CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
        "SmokeShell", "HandGrenade", "HandGrenade", "Titan_AA"
    };
    backpack = QGVAR(aa_backpack);
};

class GVAR(Officer) : GVAR(Rifleman) {
    displayName = "Combat Officer";
    linkedItems[] = {"CUP_V_B_PASGT", "CUP_H_US_patrol_cap_WDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"CUP_V_B_PASGT", "CUP_H_US_patrol_cap_WDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};
