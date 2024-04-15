// BTR80
class CUP_I_BTR80_UN;
class GVAR(BTR80): CUP_I_BTR80_UN {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "BTR80";
    crew = QGVAR(Crewman);
    typicalCargo[] = {QGVAR(Crewman)};
    INVENTORY_EMPTY;
};

class GVAR(BTR80_Woodland): GVAR(BTR80) {
    displayName = "BTR80 (Woodland)";
    crew = QGVAR(Crewman_Woodland);
    typicalCargo[] = {QGVAR(Crewman_Woodland)};
};

// BTR80A
class CUP_I_BTR80A_UN;
class GVAR(BTR80A): CUP_I_BTR80A_UN {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "BTR80-A";
    crew = QGVAR(Crewman);
    typicalCargo[] = {QGVAR(Crewman)};
    INVENTORY_EMPTY;
};

class GVAR(BTR80A_Woodland): GVAR(BTR80A) {
    displayName = "BTR80-A (Woodland)";
    crew = QGVAR(Crewman_Woodland);
    typicalCargo[] = {QGVAR(Crewman_Woodland)};
};
