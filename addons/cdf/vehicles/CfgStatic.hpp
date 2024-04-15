// MK6
class B_T_Mortar_01_F;
class GVAR(MK6) : B_T_Mortar_01_F {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "MK6";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
};

class GVAR(MK6_Woodland) : GVAR(MK6) {
    displayName = "MK6 (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// RBS70
class CUP_B_RBS70_HIL;
class GVAR(RBS70) : CUP_B_RBS70_HIL {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "RBS70";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
};

class GVAR(RBS70_Woodland) : GVAR(RBS70) {
    displayName = "RBS70 (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// M134A
class CUP_B_M134_A_GB;
class GVAR(M134A) : CUP_B_M134_A_GB {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "M134A";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
};

class GVAR(M134A_Woodland) : GVAR(M134A) {
    displayName = "M134A (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// SPG9
class CUP_B_SPG9_CDF;
class GVAR(SPG9) : CUP_B_SPG9_CDF {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "SPG-9";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
};

class GVAR(SPG9_Woodland) : GVAR(SPG9) {
    displayName = "SPG-9 (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// ZU-23
class CUP_B_ZU23_CDF;
class GVAR(ZU23) : CUP_B_ZU23_CDF {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "ZU-23-2";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
};

class GVAR(ZU23_Woodland) : GVAR(ZU23) {
    displayName = "ZU-23-2";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};

// Searchlight
class CUP_B_SearchLight_static_BAF_MPT;
class GVAR(Searchlight) : CUP_B_SearchLight_static_BAF_MPT {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Searchlight";
    crew = QGVAR(Rifleman);
    typicalCargo[] = {
        QGVAR(Rifleman)
    };
};

class GVAR(Searchlight_Woodland) : GVAR(Searchlight) {
    displayName = "ZU-23-2 (Woodland)";
    crew = QGVAR(Rifleman_Woodland);
    typicalCargo[] = {
        QGVAR(Rifleman_Woodland)
    };
};
