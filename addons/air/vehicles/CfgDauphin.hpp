class MEA_Pantera_Base : Helicopter_Base_H {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    cyclicAsideForceCoef = 0.9;
    cyclicForwardForceCoef = 0.7;
    fuelCapacity = 250;  // 500
    camouflage = 10;
    audible = 25;
    radarTargetSize = 0.5;
    visualTargetSize = 0.7;
    irTargetSize = 0.5;
    class Wheels {
        class Wheel_f {
            boneName = "wheel_f";
            steering = 1;
            side = "right";
            center = "wheel_f_center";
            boundary = "wheel_f_bound";
            width = 0.28;
            mass = 51.429;
            MOI = 0.5;
            dampingRate = 0.1;
            dampingRateDamaged = 1;
            dampingRateDestroyed = 1000;
            maxBrakeTorque = 3000;
            maxHandBrakeTorque = 0;
            suspTravelDirection[] = { 0, -1, 0 };
            suspForceAppPointOffset = "wheel_f_center";
            tireForceAppPointOffset = "wheel_f_center";
            maxCompression = 0.0125;
            maxDroop = 0.0125;
            sprungMass = 1000;
            springStrength = 80000;
            springDamperRate = 4000;
            longitudinalStiffnessPerUnitGravity = 4000;
            latStiffX = 3;
            latStiffY = 20;
            frictionVsSlipGraph[] = { { 0, 1 }, { 0.5, 1 }, { 1, 1 } };
        };
        class Wheel_r : Wheel_f {
            boneName = "wheel_r";
            steering = 0;
            center = "wheel_r_center";
            boundary = "wheel_r_bound";
            width = 0.16;
            mass = 34.286;
            maxCompression = 0.00625;
            maxDroop = 0.00625;
            sprungMass = 2500;
            springStrength = 160000;
            springDamperRate = 6075;
            suspForceAppPointOffset = "wheel_r_center";
            tireForceAppPointOffset = "wheel_r_center";
        };
        class Wheel_l : Wheel_r {
            boneName = "wheel_l";
            side = "left";
            center = "wheel_l_center";
            boundary = "wheel_l_bound";
            suspForceAppPointOffset = "wheel_l_center";
            tireForceAppPointOffset = "wheel_l_center";
        };
    };
    extCameraPosition[] = { 0, 0, -15 };
    ace_fastroping_enabled = 1;
    ace_fastroping_ropeOrigins[] = { { 1.4, 1.15, 0.5 } };
    INVENTORY_AIRCRAFT
#include "MFDGeneral.hpp"
};
class GVAR(dauphin) : MEA_Pantera_Base {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "AS365N3 Dauphin II";
    editorPreview = QPATHTOEF(common,data\previews\GVAR(dauphin).jpg);
    class TransportBackpacks {};
    hiddenSelections[] = { "decals" };
    hiddenSelectionsTextures[] = { "" };
    startDuration = 45;
};
