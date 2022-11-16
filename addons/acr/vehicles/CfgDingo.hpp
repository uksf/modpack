// MG
class CUP_B_Dingo_CZ_Wdl;
class GVAR(Dingo_Mg): CUP_B_Dingo_CZ_Wdl {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Dingo MG";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = {
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\acr_karosse_wdl_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\a_teile_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\flw100_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\flw200_co.paa"
    };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };

    INVENTORY_EMPTY;
};

// GL
class CUP_B_Dingo_GL_CZ_Wdl;
class GVAR(Dingo_GL): CUP_B_Dingo_GL_CZ_Wdl {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Dingo GL";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = {
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\acr_karosse_wdl_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\a_teile_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\flw100_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_dingo\data\flw200_co.paa"
    };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };

    INVENTORY_EMPTY;
};
