// ATGM
class I_LT_01_AT_F;
class GVAR(Wiesel_AT) : I_LT_01_AT_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Wiesel AT";
    hiddenSelectionsTextures[] = {
        "a3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
        "a3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
        "a3\armor_f\data\camonet_aaf_digi_green_co.paa",
        "a3\armor_f\data\cage_olive_co.paa"
    };
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {
        QGVAR(Armour_Crewman)
    };
    INVENTORY_EMPTY;
};

// MK20
class I_LT_01_cannon_F;
class GVAR(Wiesel_MK20) : I_LT_01_cannon_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Wiesel Mk20";
    hiddenSelectionsTextures[] = {
        "a3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
        "a3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
        "a3\armor_f\data\camonet_aaf_digi_green_co.paa",
        "a3\armor_f\data\cage_olive_co.paa"
    };
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {
        QGVAR(Armour_Crewman)
    };
    INVENTORY_EMPTY;
};
