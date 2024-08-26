class CUP_O_T55_SLA;
class GVAR(T55) : CUP_O_T55_SLA {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "T55";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = { QGVAR(Armour_Crewman) };
    INVENTORY_EMPTY;
};

class GVAR(T55_Woodland) : GVAR(T55) {
    displayName = "T55 (Woodland)";
    crew = QGVAR(Armour_Crewman_Woodland);
    typicalCargo[] = { QGVAR(Armour_Crewman_Woodland) };
    INVENTORY_EMPTY;
};
