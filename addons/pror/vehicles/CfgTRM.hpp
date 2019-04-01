// Transport
class B_Truck_01_covered_F;
class PROR_TRM_Covered: B_Truck_01_covered_F {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    editorPreview = QPATHTOEF(common,data\previews\PROR_TRM_Covered.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "TRM Covered";
    crew = "PROR_R";
    typicalCargo[] = {
        "PROR_F"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Transport open
class B_Truck_01_transport_F;
class PROR_TRM_Open: B_Truck_01_transport_F {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    editorPreview = QPATHTOEF(common,data\previews\PROR_TRM_Open.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "TRM Open";
    crew = "PROR_R";
    typicalCargo[] = {
        "PROR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};


// Ammo
class B_Truck_01_ammo_F;
class PROR_TRM_Ammo: B_Truck_01_ammo_F {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    displayName = "TRM Ammo";
    editorPreview = QPATHTOEF(common,data\previews\PROR_TRM_Ammo.jpg);
    editorSubcategory = QEGVAR(common,support);
    crew = "PROR_R";
    typicalCargo[] = {
        "PROR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Repair
class B_Truck_01_Repair_F;
class PROR_TRM_Repair: B_Truck_01_Repair_F {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    displayName = "TRM Repair";
    editorPreview = QPATHTOEF(common,data\previews\PROR_TRM_Repair.jpg);
    editorSubcategory = QEGVAR(common,support);
    crew = "PROR_R";
    typicalCargo[] = {
        "PROR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Refuel
class B_Truck_01_fuel_F;
class PROR_TRM_Fuel: B_Truck_01_fuel_F {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    displayName = "TRM Fuel";
    editorPreview = QPATHTOEF(common,data\previews\PROR_TRM_Fuel.jpg);
    editorSubcategory = QEGVAR(common,support);
    crew = "PROR_R";
    typicalCargo[] = {
        "PROR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
