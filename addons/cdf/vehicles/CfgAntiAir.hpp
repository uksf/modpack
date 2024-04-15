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

class GVAR(Wiesel_AA_Woodland) : class GVAR(Wiesel_AA) {
    displayName = "Wiesel AA (Woodland)";
    crew = QGVAR(Armour_Crewman_Woodland);
    typicalCargo[] = {
        QGVAR(Armour_Crewman_Woodland)
    };
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

class GVAR(Wiesel_Radar_Woodland) : class GVAR(Wiesel_Radar) {
    displayName = "Wiesel Radar (Woodland)";
    crew = QGVAR(Armour_Crewman_Woodland);
    typicalCargo[] = {
        QGVAR(Armour_Crewman_Woodland)
    };
};

// Patriot
class B_SAM_System_03_F;
class GVAR(PatriotLauncher) : B_SAM_System_03_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Patriot Launcher";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {
        QGVAR(Armour_Crewman)
    };
    INVENTORY_EMPTY;
};

// Patriot Radar
class B_Radar_System_01_F;
class GVAR(PatriotRadar) : B_Radar_System_01_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Patriot Radar";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {
        QGVAR(Armour_Crewman)
    };
    INVENTORY_EMPTY;
};

// Praetorian
class B_AAA_System_01_F;
class GVAR(Praetorian) : B_AAA_System_01_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Praetorian";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {
        QGVAR(Armour_Crewman)
    };
    INVENTORY_EMPTY;
};

// Shilka
class CUP_O_ZSU23_SLA;
class GVAR(Shilka) : CUP_O_ZSU23_SLA {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Shilka";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {
        QGVAR(Armour_Crewman)
    };
    INVENTORY_EMPTY;
};

class GVAR(Shilka_Woodland) : class GVAR(Shilka) {
    displayName = "Shilka (Woodland)";
    crew = QGVAR(Armour_Crewman_Woodland);
    typicalCargo[] = {
        QGVAR(Armour_Crewman_Woodland)
    };
};

