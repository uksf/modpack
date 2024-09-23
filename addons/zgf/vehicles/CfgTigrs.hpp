// Transport
class CUP_O_Tigr_233011_RU;
class GVAR(tigr_transport) : CUP_O_Tigr_233011_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tigr (Transport)";
    crew = QGVAR(soldier_akn);
    typicalCargo[] = {
        QGVAR(soldier_akn)
    };
    INVENTORY_EMPTY;
};

// Transport Full
class GVAR(tigr_transport_full) : CUP_O_Tigr_233011_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tigr (Transport Full)";
    crew = QGVAR(soldier_akn);
    typicalCargo[] = {
        QGVAR(soldier_akn)
    };
    INVENTORY_EMPTY;
};

// Command
class CUP_O_Tigr_233014_RU;
class GVAR(tigr_command) : CUP_O_Tigr_233014_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tigr (Command)";
    crew = QGVAR(soldier_sks);
    typicalCargo[] = {
        QGVAR(soldier_sks)
    };
    INVENTORY_EMPTY;
};

// PK
class CUP_O_Tigr_M_233114_PK_RU;
class GVAR(tigr_pk) : CUP_O_Tigr_M_233114_PK_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tigr (PK)";
    crew = QGVAR(soldier_akn);
    typicalCargo[] = {
        QGVAR(soldier_enfield)
    };
    INVENTORY_EMPTY;
};

// kord
class CUP_O_Tigr_M_233114_KORD_RU;
class GVAR(tigr_kord) : CUP_O_Tigr_M_233114_KORD_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tigr (Kord)";
    crew = QGVAR(soldier_akn);
    typicalCargo[] = {
        QGVAR(soldier_sks)
    };
    INVENTORY_EMPTY;
};
