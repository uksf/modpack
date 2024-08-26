// M-777
class pook_M777;
class GVAR(M777) : pook_M777 {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "M-777";
    crew = QGVAR(Crewman);
    typicalCargo[] = { QGVAR(Crewman) };
    INVENTORY_EMPTY;
};

class GVAR(M777_Woodland) : GVAR(M777) {
    displayName = "M-777 (Woodland)";
    crew = QGVAR(Crewman_Woodland);
    typicalCargo[] = { QGVAR(Crewman_Woodland) };
};

// SMERCH
class pook_9K58_BLUFOR;
class GVAR(SMERCH) : pook_9K58_BLUFOR {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "Smerch";
    crew = QGVAR(Crewman);
    typicalCargo[] = { QGVAR(Crewman) };
    INVENTORY_EMPTY;
};

class GVAR(SMERCH_Woodland) : GVAR(SMERCH) {
    displayName = "Smerch (Woodland)";
    crew = QGVAR(Crewman_Woodland);
    typicalCargo[] = { QGVAR(Crewman_Woodland) };
};

// 2S7M
class pook_2S7_CDF;
class GVAR(2S7M) : pook_2S7_CDF {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "2S7M";
    crew = QGVAR(Crewman);
    typicalCargo[] = { QGVAR(Crewman) };
    INVENTORY_EMPTY;
};

class GVAR(2S7M_Woodland) : GVAR(2S7M) {
    displayName = "2S7M (Woodland)";
    crew = QGVAR(Crewman_Woodland);
    typicalCargo[] = { QGVAR(Crewman_Woodland) };
};
