class I_E_Truck_02_MRL_F;
class GVAR(kamaz_MRL) : I_E_Truck_02_MRL_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Kamaz MRL";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class CUP_B_RM70_CZ;
class GVAR(RM70) : CUP_B_RM70_CZ {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "RM70";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};
