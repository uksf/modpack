// TU-16
class pook_tu16_G_BLUFOR;
class GVAR(TU16) : pook_tu16_G_BLUFOR {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Tu-16 Bomber";
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = {
        QGVAR(Jet_Pilot)
    };
    INVENTORY_EMPTY;
};

class GVAR(TU16_Woodland) : GVAR(TU16) {
    displayName = "Tu-16 Bomber (Woodland)";
    crew = QGVAR(Jet_Pilot_Woodland);
    typicalCargo[] = {
        QGVAR(Jet_Pilot_Woodland)
    };
};

// Gripen
class uksf_eug_Gripen;
class GVAR(Gripen) : uksf_eug_Gripen {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Gripen";
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = {
        QGVAR(Jet_Pilot)
    };
    INVENTORY_EMPTY;
};

class GVAR(Gripen_Woodland) : GVAR(Gripen) {
    displayName = "Gripen (Woodland)";
    crew = QGVAR(Jet_Pilot_Woodland);
    typicalCargo[] = {
        QGVAR(Jet_Pilot_Woodland)
    };
};


// Li 2
class uksf_eug_Li_2;
class GVAR(Li2) : uksf_eug_Li_2 {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Li2";
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = {
        QGVAR(Jet_Pilot)
    };
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Jet_A149.jpg);
    hiddenSelectionsTextures[] = { "cup\airvehicles\cup_airvehicles_dc3\data\textures\c47_body_01_sla_co.paa", "cup\airvehicles\cup_airvehicles_dc3\data\textures\c47_body_02_sla_co.paa" };
    INVENTORY_EMPTY;
};

class GVAR(Li2_Woodland) : GVAR(Li2) {
    displayName = "Li2 (Woodland)";
    crew = QGVAR(Jet_Pilot_Woodland);
    typicalCargo[] = {
        QGVAR(Jet_Pilot_Woodland)
    };
};
