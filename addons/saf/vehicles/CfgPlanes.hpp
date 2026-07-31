class CUP_I_AV8B_DYN_AAF;
class GVAR(harrier) : CUP_I_AV8B_DYN_AAF {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Harrier";
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = { QGVAR(Jet_Pilot) };
    INVENTORY_EMPTY;
};

class uksf_vaf_C130J;
class GVAR(c130) : uksf_vaf_C130J {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "C130";
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = { QGVAR(Jet_Pilot) };
    INVENTORY_EMPTY;
};

class B_Plane_Fighter_01_F;
class GVAR(blackwasp) : B_Plane_Fighter_01_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Blackwasp";
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = { QGVAR(Jet_Pilot) };
    INVENTORY_EMPTY;
};
