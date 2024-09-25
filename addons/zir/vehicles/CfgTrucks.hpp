// Praga Covered
class CUP_O_V3S_Covered_TKM;
class GVAR(praga_covered_full) : CUP_O_V3S_Covered_TKM {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Praga Covered (Full)";
    crew = QGVAR(Militia_sks);
    typicalCargo[] = {
        QGVAR(Militia_akn)
    };
    INVENTORY_EMPTY;
};

// Praga
class CUP_O_V3S_Open_TKM;
class GVAR(praga_full) : CUP_O_V3S_Open_TKM {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Praga (Full)";
    crew = QGVAR(Militia_sks);
    typicalCargo[] = {
        QGVAR(Militia_akn)
    };
    INVENTORY_EMPTY;
};
