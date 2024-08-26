// Transport
class B_Truck_01_covered_F;
class GVAR(HEMTT_Transport) : B_Truck_01_covered_F {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "HEMTT Transport";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

class GVAR(HEMTT_Transport_Woodland) : GVAR(HEMTT_Transport) {
    displayName = "HEMTT Transport (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// Ammo
class B_Truck_01_ammo_F;
class GVAR(HEMTT_Ammo) : B_Truck_01_ammo_F {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "HEMTT Ammo";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

class GVAR(HEMTT_Ammo_Woodland) : GVAR(HEMTT_Ammo) {
    displayName = "HEMTT Ammo (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// Fuel
class B_Truck_01_fuel_F;
class GVAR(HEMTT_Fuel) : B_Truck_01_fuel_F {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "HEMTT Fuel";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

class GVAR(HEMTT_Fuel_Woodland) : GVAR(HEMTT_Fuel) {
    displayName = "HEMTT Fuel (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// Repair
class B_Truck_01_Repair_F;
class GVAR(HEMTT_Repair) : B_Truck_01_Repair_F {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    editorSubcategory = QEGVAR(common,support);
    displayName = "HEMTT Repair";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

class GVAR(HEMTT_Repair_Woodland) : GVAR(HEMTT_Repair) {
    displayName = "HEMTT Repair (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};
