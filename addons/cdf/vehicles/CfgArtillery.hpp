// M119
class CUP_I_M119_RACS;
class GVAR(M119) : CUP_I_M119_RACS {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "M-119";
    crew = QGVAR(Crewman);
    typicalCargo[] = { QGVAR(Crewman) };
    INVENTORY_EMPTY;
};

class GVAR(M119_Woodland) : GVAR(M119) {
    displayName = "M-119 (Woodland)";
    crew = QGVAR(Crewman_Woodland);
    typicalCargo[] = { QGVAR(Crewman_Woodland) };
};

// BM21
class CUP_B_BM21_AFU;
class GVAR(bm21) : CUP_B_BM21_AFU {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "BM 21";
    crew = QGVAR(Crewman);
    typicalCargo[] = { QGVAR(Crewman) };
    INVENTORY_EMPTY;
};

class GVAR(bm21_Woodland) : GVAR(bm21) {
    displayName = "BM 21 (Woodland)";
    crew = QGVAR(Crewman_Woodland);
    typicalCargo[] = { QGVAR(Crewman_Woodland) };
};
