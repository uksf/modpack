// AA
class I_LT_01_AA_F;
class GVAR(Wiesel_AA) : I_LT_01_AA_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Wiesel AA";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
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

// Radar
class I_LT_01_scout_F;
class GVAR(Wiesel_Radar) : I_LT_01_scout_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Wiesel Radar";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
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
