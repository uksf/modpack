class H135_Juno_HT1_ZM521 : Helicopter_Base_H {
    displayName = "Juno HT1";
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    unitInfoType = "RscUnitInfoNoSpeed";
    attenuationEffectType = "SemiOpenHeliAttenuation";
    liftForceCoef = 1;         // 1.5
    cyclicAsideForceCoef = 1;  // 1.6
    cyclicForwardForceCoef = 1;  // 1.1
    fuelCapacity = 300;          // 960
    startDuration = 30;
    weapons[] = { "UK3CB_BAF_CMFlareLauncher", "UK3CB_BAF_IRJammer" };
    magazines[] = { "120Rnd_CMFlare_Chaff_Magazine", "UK3CB_BAF_IRJammer_Magazine" };
    class ViewPilot : ViewPilot {
        minFov = 0.25;
        maxFov = 1.25;
        initFov = 0.95;
        initAngleX = 0;
        minAngleX = -65;
        maxAngleX = 85;
        initAngleY = 0;
        minAngleY = -150;
        maxAngleY = 150;
        minMoveX = -0.3;
        maxMoveX = 0.3;
        minMoveY = -0.025;
        maxMoveY = 0.05;
        minMoveZ = -0.2;
        maxMoveZ = 0.2;
        speedZoomMaxSpeed = 0;
        speedZoomMaxFOV = 0.95;
    };
    INVENTORY_AIRCRAFT
#include "MFDGeneral.hpp"
};
