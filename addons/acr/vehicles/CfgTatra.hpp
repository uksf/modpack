// Transport
class CUP_B_T810_Unarmed_CZ_WDL;
class GVAR(Tatra_Transport): CUP_B_T810_Unarmed_CZ_WDL {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Covered.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "Tatra Transport";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Ammo
class CUP_B_T810_Reammo_CZ_WDL;
class GVAR(Tatra_Ammo): CUP_B_T810_Reammo_CZ_WDL {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Covered.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "Tatra Ammo";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Fuel
class CUP_B_T810_Refuel_CZ_WDL;
class GVAR(Tatra_Fuel): CUP_B_T810_Refuel_CZ_WDL {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Covered.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "Tatra Fuel";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Armed / MG
class CUP_B_T810_Armed_CZ_WDL;
class GVAR(Tatra_MG): CUP_B_T810_Armed_CZ_WDL {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Covered.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "Tatra MG";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Repair
class CUP_B_T810_Repair_CZ_WDL;
class GVAR(Tatra_Repair): CUP_B_T810_Repair_CZ_WDL {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_TRM_Covered.jpg);
    editorSubcategory = QEGVAR(common,support);
    displayName = "Tatra Repair";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };

    INVENTORY_EMPTY;
};
