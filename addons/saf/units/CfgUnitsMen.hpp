// Regular infantry units (Men category)
class GVAR(Rifleman) : GVAR(Soldier_Base) {
    scope = 2;
    scopeCurator = 2;
    displayName = "Rifleman";
    backpack = "";
};

class GVAR(Squad_Leader) : GVAR(Rifleman) {
    displayName = "Squad Leader";
    weapons[] = {QGVAR(grot_gl), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(grot_gl), "Put", "Throw"};
    backpack = "CUP_B_Kombat_Radio_Olive";
};

class GVAR(Grenadier) : GVAR(Rifleman) {
    displayName = "Grenadier";
    backpack = QGVAR(grenadier_backpack);
};

class GVAR(Machine_Gunner) : GVAR(Rifleman) {
    displayName = "Machine Gunner";
    weapons[] = {"CUP_lmg_M240_B", "Put", "Throw"};
    respawnWeapons[] = {"CUP_lmg_M240_B", "Put", "Throw"};
    magazines[] = {"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "SmokeShell", "SmokeShell"};
    respawnMagazines[] = {"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "SmokeShell", "SmokeShell"};
    backpack = QGVAR(mg_backpack);
};

class GVAR(Rifleman_LAT) : GVAR(Rifleman) {
    displayName = "Rifleman (LAT)";
    weapons[] = {QGVAR(grot), "CUP_launch_RPG7V", "Put", "Throw"};
    respawnWeapons[] = {QGVAR(grot), "CUP_launch_RPG7V", "Put", "Throw"};
    magazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer",
        "SmokeShell", "HandGrenade", "HandGrenade", "CUP_PG7V_M"
    };
    respawnMagazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer",
        "SmokeShell", "HandGrenade", "HandGrenade", "CUP_PG7V_M"
    };
    backpack = QGVAR(lat_backpack);
};

class GVAR(Rifleman_HAT) : GVAR(Rifleman) {
    displayName = "Rifleman (HAT)";
    weapons[] = {QGVAR(grot), "CUP_launch_MAAWS", "Put", "Throw"};
    respawnWeapons[] = {QGVAR(grot), "CUP_launch_MAAWS", "Put", "Throw"};
    magazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer",
        "SmokeShell", "HandGrenade", "HandGrenade", "CUP_MAAWS_HEDP_M"
    };
    respawnMagazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer", "30Rnd_65x39_caseless_msbs_mag_Tracer",
        "SmokeShell", "HandGrenade", "HandGrenade", "CUP_MAAWS_HEDP_M"
    };
    backpack = QGVAR(hat_backpack);
};

class GVAR(Sharpshooter) : GVAR(Rifleman) {
    displayName = "Sharpshooter";
    weapons[] = {QGVAR(grot_mr), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(grot_mr), "Put", "Throw"};
};

class GVAR(Rifleman_AA) : GVAR(Rifleman) {
    displayName = "Rifleman (AA)";
    weapons[] = {QGVAR(grot), "CUP_launch_FIM92Stinger", "Put", "Throw"};
    respawnWeapons[] = {QGVAR(grot), "CUP_launch_FIM92Stinger", "Put", "Throw"};
};

class GVAR(Officer) : GVAR(Rifleman) {
    displayName = "Combat Officer";
    linkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F", "CUP_H_US_patrol_cap_ERDL_highland", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"V_CarrierRigKBT_01_light_Olive_F", "CUP_H_US_patrol_cap_ERDL_highland", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};
