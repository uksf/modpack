class CUP_B_MTVR_USA;
class GVAR(MTVR_Transport) : CUP_B_MTVR_USA {
    side = 2;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "MTVR Transport";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body2_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_interier_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_tarp_desert_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_B_MTVR_Ammo_USA;
class GVAR(MTVR_Ammo) : CUP_B_MTVR_Ammo_USA {
    side = 2;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "MTVR Ammo";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body2_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_interier_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_tarp_desert_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_B_MTVR_Refuel_USA;
class GVAR(MTVR_Fuel) : CUP_B_MTVR_Refuel_USA {
    side = 2;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "MTVR Fuel";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body2_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_interier_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_fuel_desert_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_B_MTVR_Repair_USA;
class GVAR(MTVR_Repair) : CUP_B_MTVR_Repair_USA {
    side = 2;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "MTVR Repair";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_body2_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\mtvr_interier_desert_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_mtvr\data\ural_repair_desert_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};
