class MEA_Pantera_Base : Helicopter_Base_H {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    cyclicAsideForceCoef = 0.9;
    cyclicForwardForceCoef = 0.7;
    fuelCapacity = 50;  // 500
    camouflage = 10;
    audible = 25;
    radarTargetSize = 0.5;
    visualTargetSize = 0.7;
    irTargetSize = 0.5;
    INVENTORY_AIRCRAFT
#include "MFDGeneral.hpp"
};
class GVAR(dauphin) : MEA_Pantera_Base {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "AS365N3 Dauphin II";
    class TransportBackpacks {};
    hiddenSelections[] = { "decals" };
    hiddenSelectionsTextures[] = { "" };
};
