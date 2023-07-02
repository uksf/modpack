
class CUP_O_T90_RU;
class GVAR(T_90A) : CUP_O_T90_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "T-90A";
    hiddenSelectionsTextures[] = { "cup\trackedvehicles\cup_trackedvehicles_t90\data\body1_co.paa", "cup\trackedvehicles\cup_trackedvehicles_t90\data\body2_co.paa", "cup\trackedvehicles\cup_trackedvehicles_t90\data\body3_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_T72_RU;
class GVAR(T72) : CUP_O_T72_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "T-72";
    hiddenSelectionsTextures[] = { "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\ru_t72_1_co.paa", "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\ru_t72_2_co.paa", "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\ru_t72_3_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_T55_CHDKZ;
class GVAR(T55) : CUP_O_T55_CHDKZ {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "T-55";
    hiddenSelectionsTextures[] = { "cup\trackedvehicles\cup_trackedvehicles_t55\data\t55_body_olive_co.paa", "cup\trackedvehicles\cup_trackedvehicles_t55\data\t55_tower_olive_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};

class O_T_MBT_04_cannon_F;
class GVAR(T_14_Armata) : O_T_MBT_04_cannon_F {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "T-14 Armata";
    hiddenSelectionsTextures[] = { "a3\armor_f_tank\mbt_04\data\mbt_04_exterior_1_co.paa", "a3\armor_f_tank\mbt_04\data\mbt_04_exterior_2_co.paa", "a3\armor_f\data\camonet_csat_stripe_desert_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};

class B_APC_Tracked_01_rcws_F;
class GVAR(Namer) : B_APC_Tracked_01_rcws_F {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Namer";
    hiddenSelectionsTextures[] = { "a3\armor_f_beta\apc_tracked_01\data\apc_tracked_01_body_co.paa", "a3\armor_f_beta\apc_tracked_01\data\mbt_01_body_co.paa", "a3\data_f\vehicles\turret_co.paa", "a3\armor_f\data\camonet_nato_desert_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};
