// Unarmed
class CUP_B_LR_Transport_CZ_W;
class Inegal_LandRover_Unarmed: CUP_B_LR_Transport_CZ_W {
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "Land Rover";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Inegal_LandRover_FDF_Unarmed: Inegal_LandRover_Unarmed {
    displayName = "Land Rover (FDF)";
    crew = "Inegal_FDF_Se";
    typicalCargo[] = {
        "Inegal_FDF_Se"
    };
};

// MG
class CUP_B_LR_MG_CZ_W;
class Inegal_LandRover_MG: CUP_B_LR_MG_CZ_W {
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
class CUP_B_LR_Special_CZ_W;
class Inegal_LandRover_GL: CUP_B_LR_Special_CZ_W {
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
