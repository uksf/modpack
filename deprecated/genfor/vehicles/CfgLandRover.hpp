class B_mas_cars_LR_BASE;

// Unarmed
class B_mas_cars_LR_Unarmed: B_mas_cars_LR_BASE {
    scope = 0;
};
class Genfor_LandRover_Unarmed: B_mas_cars_LR_Unarmed {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "Land Rover Unarmed";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Unarmed.jpg);
    editorSubcategory = QEGVAR(common,lr);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_LandRover_Unarmed_Para: Genfor_LandRover_Unarmed {
    displayName = "Land Rover Unarmed (para)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Unarmed_Para.jpg);
    crew = "GENFOR_P_R";
    typicalCargo[] = {
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R"
    };
};
class Genfor_LandRover_Unarmed_Populated: Genfor_LandRover_Unarmed {
    displayName = "Land Rover Unarmed (Populated)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Unarmed_Populated.jpg);
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};
class Genfor_LandRover_Unarmed_Para_Populated: Genfor_LandRover_Unarmed_Para {
    displayName = "Land Rover Unarmed (Para) (Populated)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Unarmed_Para_Populated.jpg);
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};

// Medical
class B_mas_cars_LR_Med: B_mas_cars_LR_Unarmed {
    scope = 0;
};
class Genfor_LandRover_Medical: B_mas_cars_LR_Med {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "Land Rover Medical";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Medical.jpg);
    editorSubcategory = QEGVAR(common,lr);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_MED",
        "GENFOR_MED",
        "GENFOR_MED"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_LandRover_Medical_Para: Genfor_LandRover_Medical {
    displayName = "Land Rover Medical (para)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Medical_Para.jpg);
    crew = "GENFOR_P_R";
    typicalCargo[] = {
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_MED",
        "GENFOR_MED",
        "GENFOR_MED"
    };
};

// MG
class B_mas_cars_LR_M2: B_mas_cars_LR_BASE {
    scope = 0;
};
class Genfor_LandRover_MG: B_mas_cars_LR_M2 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "Land Rover MG";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_MG.jpg);
    editorSubcategory = QEGVAR(common,lr);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_LandRover_MG_Para: Genfor_LandRover_MG {
    displayName = "Land Rover MG (para)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_MG_Para.jpg);
    crew = "GENFOR_P_R";
    typicalCargo[] = {
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R"
    };
};

// GL
class B_mas_cars_LR_Mk19: B_mas_cars_LR_M2 {
    scope = 0;
};
class Genfor_LandRover_GL: B_mas_cars_LR_Mk19 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "Land Rover GL";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_GL.jpg);
    editorSubcategory = QEGVAR(common,lr);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_LandRover_GL_Para: Genfor_LandRover_GL {
    displayName = "Land Rover GL (para)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_GL_Para.jpg);
    crew = "GENFOR_P_R";
    typicalCargo[] = {
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R"
    };
};

// TOW
class B_mas_cars_LR_TOW: B_mas_cars_LR_M2 {
    scope = 0;
};
class Genfor_LandRover_TOW: B_mas_cars_LR_TOW {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "Land Rover TOW";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_TOW.jpg);
    editorSubcategory = QEGVAR(common,lr);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_LandRover_TOW_Para: Genfor_LandRover_TOW {
    displayName = "Land Rover TOW (para)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_TOW_Para.jpg);
    crew = "GENFOR_P_R";
    typicalCargo[] = {
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R"
    };
};

// Stinger
class B_mas_cars_LR_Stinger: B_mas_cars_LR_M2 {
    scope = 0;
};
class Genfor_LandRover_Stinger: B_mas_cars_LR_Stinger {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "Land Rover Stinger";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Stinger.jpg);
    editorSubcategory = QEGVAR(common,lr);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_LandRover_Stinger_Para: Genfor_LandRover_Stinger {
    displayName = "Land Rover Stinger (para)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_Stinger_Para.jpg);
    crew = "GENFOR_P_R";
    typicalCargo[] = {
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R"
    };
};

// SPG9
class B_mas_cars_LR_SPG9: B_mas_cars_LR_TOW {
    scope = 0;
};
class Genfor_LandRover_SPG9: B_mas_cars_LR_SPG9 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "Land Rover SPG9";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_SPG9.jpg);
    editorSubcategory = QEGVAR(common,lr);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R",
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_LandRover_SPG9_Para: Genfor_LandRover_SPG9 {
    displayName = "Land Rover SPG9 (para)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_SPG9_Para.jpg);
    crew = "GENFOR_P_R";
    typicalCargo[] = {
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R",
        "GENFOR_P_R"
    };
};


class I_mas_cars_LR_soft_Unarmed: B_mas_cars_LR_Unarmed {
    scope = 0;
};
class I_mas_cars_LR_soft_Med: B_mas_cars_LR_Med {
    scope = 0;
};
class I_mas_cars_LR_soft_M2: B_mas_cars_LR_M2 {
    scope = 0;
};
class I_mas_cars_LR_soft_Mk19: B_mas_cars_LR_Mk19 {
    scope = 0;
};
class I_mas_cars_LR_soft_TOW: B_mas_cars_LR_TOW {
    scope = 0;
};
class I_mas_cars_LR_soft_Stinger: B_mas_cars_LR_Stinger {
    scope = 0;
};
class I_mas_cars_LR_soft_SPG9: B_mas_cars_LR_SPG9 {
    scope = 0;
};
