class I_mas_cars_UAZ_Base;

//DSHKM
class I_mas_cars_UAZ_MG: I_mas_cars_UAZ_Base {
    scope = 0;
};
class O_mas_cars_UAZ_MG: I_mas_cars_UAZ_MG {
    scope = 0;
};
class Genfor_Uaz_DSHKM: O_mas_cars_UAZ_MG {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "UAZ DSHKM";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Uaz_DSHKM.jpg);
    editorSubcategory = QEGVAR(common,uaz);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

//.50 cal
class I_mas_cars_UAZ_M2: I_mas_cars_UAZ_MG {
    scope = 0;
};
class Genfor_Uaz_50cal: I_mas_cars_UAZ_M2 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "UAZ .50cal";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Uaz_50cal.jpg);
    editorSubcategory = QEGVAR(common,uaz);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

//GL
class I_mas_cars_UAZ_AGS30: I_mas_cars_UAZ_Base {
    scope = 0;
};
class O_mas_cars_UAZ_AGS30: I_mas_cars_UAZ_AGS30 {
    scope = 0;
};
class Genfor_Uaz_GL: O_mas_cars_UAZ_AGS30 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "UAZ GL";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Uaz_GL.jpg);
    editorSubcategory = QEGVAR(common,uaz);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

//Unarmed
class I_mas_cars_UAZ_Unarmed: I_mas_cars_UAZ_Base {
    scope = 0;
};
class O_mas_cars_UAZ_Unarmed: I_mas_cars_UAZ_Unarmed {
    scope = 0;
};
class Genfor_Uaz_Unarmed: O_mas_cars_UAZ_Unarmed {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "UAZ Unarmed";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Uaz_Unarmed.jpg);
    editorSubcategory = QEGVAR(common,uaz);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_Uaz_Unarmed_Populated: Genfor_Uaz_Unarmed {
    displayName = "UAZ Unarmed (Populated)";
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

//Med
class I_mas_cars_UAZ_Med: I_mas_cars_UAZ_Unarmed {
    scope = 0;
};
class O_mas_cars_UAZ_Med: O_mas_cars_UAZ_Unarmed {
    scope = 0;
};
class Genfor_Uaz_Medical: O_mas_cars_UAZ_Med {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "UAZ Medical";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Uaz_Medical.jpg);
    editorSubcategory = QEGVAR(common,uaz);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_MED"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

//SPG9
class I_mas_cars_UAZ_SPG9: I_mas_cars_UAZ_Base {
    scope = 0;
};
class O_mas_cars_UAZ_SPG9: I_mas_cars_UAZ_SPG9 {
    scope = 0;
};
class Genfor_Uaz_SPG9: O_mas_cars_UAZ_SPG9 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "UAZ SPG9";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Uaz_SPG9.jpg);
    editorSubcategory = QEGVAR(common,uaz);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
