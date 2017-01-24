class B_mas_cars_Hilux_Base;

//Unarmed
class B_mas_cars_Hilux_Unarmed: B_mas_cars_Hilux_Base {
    scope = 0;
};
class Genfor_Hilux_Unarmed: B_mas_cars_Hilux_Unarmed {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Unarmed.jpg);
    editorSubcategory = QEGVAR(common,hilux);
    displayName = "Hilux";
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_Hilux_Unarmed_Reserves: Genfor_Hilux_Unarmed {
    displayName = "Hilux (reserves)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Unarmed_Reserves.jpg);
    crew = "GENFOR_Res";
    typicalCargo[] = {
        "GENFOR_Res_L"
    };
};
class Genfor_Hilux_Unarmed_Populated: Genfor_Hilux_Unarmed {
    displayName = "Hilux (Populated)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Unarmed_Populated.jpg);
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};
class Genfor_Hilux_Unarmed_Reserves_Populated: Genfor_Hilux_Unarmed_Reserves {
    displayName = "Hilux (Reserves) (Populated)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Unarmed_Reserves_Populated.jpg);
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};

//MG
class B_mas_cars_Hilux_MG: B_mas_cars_Hilux_Base {
    scope = 0;
};
class Genfor_Hilux_MG: B_mas_cars_Hilux_MG {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_MG.jpg);
    editorSubcategory = QEGVAR(common,hilux);
    displayName = "Hilux DSHKM";
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_Hilux_MG_Reserves: Genfor_Hilux_MG {
    displayName = "Hilux DSHKM (reserves)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_MG_Reserves.jpg);
    crew = "GENFOR_Res";
    typicalCargo[] = {
        "GENFOR_Res_L"
    };
};

//50 cal
class B_mas_cars_Hilux_M2: B_mas_cars_Hilux_MG {
    scope = 0;
};
class Genfor_Hilux_50: B_mas_cars_Hilux_M2 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_50.jpg);
    editorSubcategory = QEGVAR(common,hilux);
    displayName = "Hilux .50cal";
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_Hilux_50_Reserves: Genfor_Hilux_50 {
    displayName = "Hilux .50cal (reserves)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_50_Reserves.jpg);
    crew = "GENFOR_Res";
    typicalCargo[] = {
        "GENFOR_Res_L"
    };
};

//Grenade launcher
class B_mas_cars_Hilux_AGS30: B_mas_cars_Hilux_Base {
    scope = 0;
};
class Genfor_Hilux_Grenade: B_mas_cars_Hilux_AGS30 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Grenade.jpg);
    editorSubcategory = QEGVAR(common,hilux);
    displayName = "Hilux GL";
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_Hilux_Grenade_Reserves: Genfor_Hilux_Grenade {
    displayName = "Hilux GL (reserves)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Grenade_Reserves.jpg);
    crew = "GENFOR_Res";
    typicalCargo[] = {
        "GENFOR_Res_L"
    };
};

//Medical
class B_mas_cars_Hilux_Med: B_mas_cars_Hilux_Unarmed {
    scope = 0;
};
class Genfor_Hilux_Med: B_mas_cars_Hilux_Med {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Med.jpg);
    editorSubcategory = QEGVAR(common,hilux);
    displayName = "Hilux Medic";
    crew = "GENFOR_MED";
    attendant = "true";
    typicalCargo[] = {
        "GENFOR_MED"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

//SPG9
class B_mas_cars_Hilux_SPG9: B_mas_cars_Hilux_Base {
    scope = 0;
};
class Genfor_Hilux_SPG9: B_mas_cars_Hilux_SPG9 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_SPG9.jpg);
    editorSubcategory = QEGVAR(common,hilux);
    displayName = "Hilux SPG9";
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

//Rockets
class B_mas_cars_Hilux_RKTS: B_mas_cars_Hilux_SPG9 {
    scope = 0;
};
class Genfor_Hilux_Rockets: B_mas_cars_Hilux_RKTS {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Hilux_Rockets.jpg);
    editorSubcategory = QEGVAR(common,hilux);
    displayName = "Hilux Rockets";
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
