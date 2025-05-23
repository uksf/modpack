// Griffon Transport
class CUP_I_412_Mil_Transport_PMC;
class GVAR(CH146_Tpt) : CUP_I_412_Mil_Transport_PMC {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "CH-146 Griffon (Transport)";
    crew = QGVAR(Heli_Pilot);
    typicalCargo[] = {
        QGVAR(Heli_Pilot)
    };
    hiddenSelectionsTextures[] = {
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_main_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_ext_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_ext1_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\stickers\heli_medium01_stickers_ca.paa"
    };
    INVENTORY_EMPTY;
};

class GVAR(CH146_Tpt_Woodland) : GVAR(CH146_Tpt) {
    displayName = "CH-146 Griffon (Transport - Woodland)";
    crew = QGVAR(Heli_Pilot_Woodland);
    typicalCargo[] = {
        QGVAR(Heli_Pilot_Woodland)
    };
};

// Griffon Armed
class CUP_I_412_Military_Armed_PMC;
class GVAR(CH146_Armed) : CUP_I_412_Military_Armed_PMC {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "CH-146 Griffon (Armed)";
    crew = QGVAR(Heli_Pilot);
    typicalCargo[] = {
        QGVAR(Heli_Pilot)
    };
    hiddenSelectionsTextures[] = {
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_main_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_ext_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_ext1_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\stickers\heli_medium01_stickers_ca.paa"
    };
    INVENTORY_EMPTY;
};

class GVAR(CH146_Armed_Woodland) : GVAR(CH146_Armed) {
    displayName = "CH-146 Griffon (Armed - Woodland)";
    crew = QGVAR(Heli_Pilot_Woodland);
    typicalCargo[] = {
        QGVAR(Heli_Pilot_Woodland)
    };
};

// Griffon AT
class CUP_I_412_Military_Armed_AT_PMC;
class GVAR(CH146_AT) : CUP_I_412_Military_Armed_AT_PMC {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "CH-146 Griffon (AT)";
    crew = QGVAR(Heli_Pilot);
    typicalCargo[] = {
        QGVAR(Heli_Pilot)
    };
    hiddenSelectionsTextures[] = {
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_main_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_ext_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\heli_medium01_military_ext1_co.paa",
        "cup\airvehicles\cup_airvehicles_412\data\stickers\heli_medium01_stickers_ca.paa"
    };
    INVENTORY_EMPTY;
};

class GVAR(CH146_AT_Woodland) : GVAR(CH146_AT) {
    displayName = "CH-146 Griffon (AT - Woodland)";
    crew = QGVAR(Heli_Pilot_Woodland);
    typicalCargo[] = {
        QGVAR(Heli_Pilot_Woodland)
    };
};


