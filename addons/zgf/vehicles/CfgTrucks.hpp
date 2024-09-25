// Transport
class CUP_B_T810_Armed_CZ_WDL;
class GVAR(tatra_transport) : CUP_B_T810_Armed_CZ_WDL {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tatra (Transport)";
    crew = QGVAR(soldier_sks);
    typicalCargo[] = {
        QGVAR(soldier_akn)
    };
    INVENTORY_EMPTY;
};

// Transport Full
class GVAR(tatra_transport_full) : CUP_B_T810_Armed_CZ_WDL {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tatra (Transport Full)";
    crew = QGVAR(soldier_sks);
    typicalCargo[] = {
        QGVAR(soldier_akn)
    };
    INVENTORY_EMPTY;
};

// Ammo
class CUP_B_T810_Reammo_CZ_WDL;
class GVAR(tatra_ammo) : CUP_B_T810_Reammo_CZ_WDL {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tatra (Ammo)";
    crew = QGVAR(soldier_sks);
    typicalCargo[] = {
        QGVAR(soldier_akn)
    };
    INVENTORY_EMPTY;
};

// Fuel
class CUP_B_T810_Refuel_CZ_WDL;
class GVAR(tatra_fuel) : CUP_B_T810_Refuel_CZ_WDL {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Tatra (Fuel)";
    crew = QGVAR(soldier_sks);
    typicalCargo[] = {
        QGVAR(soldier_akn)
    };
    INVENTORY_EMPTY;
};
