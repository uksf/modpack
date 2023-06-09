class pook_96K6_base;
class GVAR(Pantsir) : pook_96K6_base {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Pantsir";
    hiddenSelectionsTextures[] = { "pook_sam\data\desert_yellow_kab_co.paa", "pook_sam\data\desert_yellow_kuz_co.paa", "pook_sam\data\desert_yellow_turret_co.paa", "pook_sam\logo\emblem_tak.paa", "pook_sam\data\clear_empty.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_ZSU23_ChDKZ;
class GVAR(ZSU_23_4) : CUP_O_ZSU23_ChDKZ {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "ZSU-23-4";
    hiddenSelectionsTextures[] = { "cup\trackedvehicles\cup_trackedvehicles_zsu23\data\zsu_01_tk_co.paa", "cup\trackedvehicles\cup_trackedvehicles_zsu23\data\zsu_02_tk_co.paa", "cup\trackedvehicles\cup_trackedvehicles_zsu23\data\zsu_03_tk_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_UAZ_AA_CSAT;
class GVAR(UAZ_AA) : CUP_O_UAZ_AA_CSAT {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "UAZ AA";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_uaz\data\uaz_main_civil_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_uaz\data\uaz_other_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class B_APC_Tracked_01_AA_F;
class GVAR(Bardelas) : B_APC_Tracked_01_AA_F {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Bardelas";
    hiddenSelectionsTextures[] = { "a3\armor_f_beta\apc_tracked_01\data\apc_tracked_01_aa_body_co.paa", "a3\armor_f_beta\apc_tracked_01\data\mbt_01_body_co.paa", "a3\armor_f_beta\apc_tracked_01\data\apc_tracked_01_aa_tower_co.paa", "a3\armor_f\data\camonet_nato_desert_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};

class pook_SON50_INS;
class GVAR(Ural_Radar) : pook_SON50_INS {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Ural Radar";
    hiddenSelectionsTextures[] = { "pook_p12\data\ural_kabina_khk_co.paa", "pook_sam\logo\emblem_chdkz.paa", "", "pook_p12\data\spec_woodland.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class pook_SON9_INS;
class GVAR(SON_9A_Radar) : pook_SON9_INS {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "SON-9A Radar";
    hiddenSelectionsTextures[] = { "pook_p12\data\ural_kabina_camo_co.paa", "pook_sam\data\clear_empty.paa", "pook_p12\data\camo_greenbrown.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};
