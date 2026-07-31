class I_E_Truck_02_F;
class GVAR(Kamaz_Covered) : I_E_Truck_02_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Kamaz Covered";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class I_E_Truck_02_Ammo_F;
class GVAR(Kamaz_Ammo) : I_E_Truck_02_Ammo_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Kamaz Ammo";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class I_E_Truck_02_fuel_F;
class GVAR(Kamaz_Refuel) : I_E_Truck_02_fuel_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Kamaz Refuel";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class I_E_Truck_02_Box_F;
class GVAR(Kamaz_Repair) : I_E_Truck_02_Box_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Kamaz Repair";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};
