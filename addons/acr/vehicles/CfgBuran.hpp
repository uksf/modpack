// Tansport
class MM_Buran_Transporter;
class GVAR(Buran_Transporter) : MM_Buran_Transporter {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Buran Transporter";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = { "mm_buran\data\mm_buran_ext_green_co.paa", "mm_buran\data\mm_buran_int_green_co.paa" };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

// Medical
class MM_Buran_Medical;
class GVAR(Buran_Medical) : MM_Buran_Medical {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Buran Medical";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = { "mm_buran\data\mm_buran_ext_green_co.paa", "mm_buran\data\mm_buran_int_green_co.paa" };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

// Cargo
class MM_Buran_Cargo;
class GVAR(Buran_Cargo) : MM_Buran_Cargo {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Buran Cargo";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = { "mm_buran\data\mm_buran_ext_green_co.paa", "mm_buran\data\mm_buran_int_green_co.paa" };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};
