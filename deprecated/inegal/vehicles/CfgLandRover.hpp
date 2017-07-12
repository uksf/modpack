// Unarmed
class Genfor_LandRover_Unarmed;
class Inegal_LandRover_Unarmed: Genfor_LandRover_Unarmed {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "Land Rover Unarmed";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
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
class Inegal_LandRover_FDF_Unarmed: Inegal_LandRover_Unarmed {
    displayName = "Land Rover Unarmed (FDF)";
    crew = "Inegal_FDF_Se";
    typicalCargo[] = {
        "Inegal_FDF_Se"
    };
};

// MG
class Genfor_LandRover_MG;
class Inegal_LandRover_MG: Genfor_LandRover_MG {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "Land Rover MG";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_MG.jpg);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
};
class Inegal_LandRover_FDF_MG: Inegal_LandRover_MG {
    displayName = "Land Rover MG (FDF)";
    crew = "Inegal_FDF_Se";
    typicalCargo[] = {
        "Inegal_FDF_Se"
    };
};

// GL
class Genfor_LandRover_GL;
class Inegal_LandRover_GL: Genfor_LandRover_GL {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "Land Rover GL";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_GL.jpg);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
};
class Inegal_LandRover_FDF_GL: Inegal_LandRover_GL {
    displayName = "Land Rover GL (FDF)";
    crew = "Inegal_FDF_Se";
    typicalCargo[] = {
        "Inegal_FDF_Se"
    };
};
