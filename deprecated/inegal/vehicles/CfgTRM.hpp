// Transport
class B_Truck_01_covered_F;
class Inegal_TRM_Covered: B_Truck_01_covered_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Covered.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "TRM Covered";
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};
class Inegal_TRM_D_Covered: Inegal_TRM_Covered {
    displayName = "TRM Covered (Diablerie)";
    crew = "Inegal_Diablerie_Se";
    typicalCargo[] = {
        "Inegal_Diablerie_Se"
    };
};
class Inegal_TRM_R_Covered: Inegal_TRM_Covered {
    displayName = "TRM Covered (Recrues)";
    crew = "Inegal_Recrues_R";
    typicalCargo[] = {
        "Inegal_Recrues_R"
    };
};

// Transport open
class B_Truck_01_transport_F;
class Inegal_TRM_Open: B_Truck_01_transport_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Open.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "TRM Open";
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};
class Inegal_TRM_D_Open: Inegal_TRM_Open {
    displayName = "TRM Open (Diablerie)";
    crew = "Inegal_Diablerie_Se";
    typicalCargo[] = {
        "Inegal_Diablerie_Se"
    };
};
class Inegal_TRM_R_Open: Inegal_TRM_Open {
    displayName = "TRM Open (Recrues)";
    crew = "Inegal_Recrues_R";
    typicalCargo[] = {
        "Inegal_Recrues_R"
    };
};

// Ammo
class B_Truck_01_ammo_F;
class Inegal_TRM_Ammo: B_Truck_01_ammo_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "TRM Ammo";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Ammo.jpg);
    editorSubcategory = QEGVAR(common,support);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Repair
class B_Truck_01_Repair_F;
class Inegal_TRM_Repair: B_Truck_01_Repair_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "TRM Repair";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Repair.jpg);
    editorSubcategory = QEGVAR(common,support);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Refuel
class B_Truck_01_fuel_F;
class Inegal_TRM_Fuel: B_Truck_01_fuel_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "TRM Fuel";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Fuel.jpg);
    editorSubcategory = QEGVAR(common,support);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
