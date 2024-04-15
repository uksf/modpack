// Tansport
class MM_Buran_Transporter;
class GVAR(Buran_Transporter) : MM_Buran_Transporter {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Buran Transporter";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = { "mm_buran\data\mm_buran_ext_co.paa", "mm_buran\data\mm_buran_int_co.paa" };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

class GVAR(Buran_Transporter_Woodland) : GVAR(Buran_Transporter) {
    displayName = "Buran Transporter (Woodland)";
    hiddenSelectionsTextures[] = { "mm_buran\data\MM_Buran_ext_green_co.paa", "mm_buran\data\MM_Buran_ext_green_co.paa" };
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// Medical
class MM_Buran_Medical;
class GVAR(Buran_Medical) : MM_Buran_Medical {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Buran Medical";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = { "mm_buran\data\mm_buran_ext_co.paa", "mm_buran\data\mm_buran_int_co.paa" };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

class GVAR(Buran_Medical_Woodland) : GVAR(Buran_Medical) {
    displayName = "Buran Medical (Woodland)";
    hiddenSelectionsTextures[] = { "mm_buran\data\MM_Buran_ext_green_co.paa", "mm_buran\data\MM_Buran_ext_green_co.paa" };
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// Cargo
class MM_Buran_Cargo;
class GVAR(Buran_Cargo) : MM_Buran_Cargo {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Buran Cargo";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_LandRover_Unarmed.jpg);
    hiddenSelectionsTextures[] = { "mm_buran\data\mm_buran_ext_co.paa", "mm_buran\data\mm_buran_int_co.paa" };
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
    INVENTORY_EMPTY;
};

class GVAR(Buran_Cargo_Woodland) : GVAR(MM_Buran_Cargo) {
    displayName = "Buran Cargo (Woodland)";
    hiddenSelectionsTextures[] = { "mm_buran\data\MM_Buran_ext_green_co.paa", "mm_buran\data\MM_Buran_ext_green_co.paa" };
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};
