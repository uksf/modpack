class Heli_Transport_02_base_F: Helicopter_Base_H {};
class UK3CB_BAF_Merlin_HC3_Base: Heli_Transport_02_base_F {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    fuelCapacity = 1750; // 2500
    class ViewPilot: ViewOptics {
        minFov = 0.25;
        maxFov = 1.25;
        initFov = 0.95;
    };
    unitInfoType = "RscUnitInfoNoSpeed";
    #include "MFDMerlin.hpp"
    /*landingSoundInt0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int1", 0.25, 1, 50 };
    landingSoundInt1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int2", 0.25, 1, 50 };
    landingSoundInt[] = { "landingSoundInt0", 0.5, "landingSoundInt1", 0.5 };
    landingSoundOut0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1", 0.4, 1, 50 };
    landingSoundOut1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2", 0.4, 1, 50 };
    landingSoundOut[] = { "landingSoundOut0", 0.5, "landingSoundOut1", 0.5 };*/
    class Components: Components {
        class SensorsManagerComponent {
            class Components {
                class IRSensorComponent: SensorTemplateIR {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "mainGun";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class VisualSensorComponent: SensorTemplateVisual {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "mainGun";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class LaserSensorComponent: SensorTemplateLaser {};
                class NVSensorComponent: SensorTemplateNV {};
                class DataLinkSensorComponent: SensorTemplateDataLink {};
            };
        };
    };
    ace_cookoff_cookoffSelections[] = { "palivo" };
};
class UK3CB_BAF_Merlin_HC3_Unarmed_Base: UK3CB_BAF_Merlin_HC3_Base {
};
class UK3CB_BAF_Merlin_HC3_Armed_Base: UK3CB_BAF_Merlin_HC3_Base {
};
class UK3CB_BAF_Merlin_HC3_24: UK3CB_BAF_Merlin_HC3_Unarmed_Base {
    faction = "CUP_B_GB";
    displayname = "Merlin HC3";
};
class UK3CB_BAF_Merlin_HC3_32: UK3CB_BAF_Merlin_HC3_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC3_18: UK3CB_BAF_Merlin_HC3_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC3_Cargo: UK3CB_BAF_Merlin_HC3_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC3_18_GPMG: UK3CB_BAF_Merlin_HC3_Armed_Base {
    faction = "CUP_B_GB";
    displayname = "Merlin HC3 (Armed)";
};
class UK3CB_BAF_Merlin_HC3_CSAR: UK3CB_BAF_Merlin_HC3_Armed_Base {
    faction = "CUP_B_GB";
    displayname = "Merlin HC3 (CSAR)";
};
class UK3CB_BAF_Merlin_HC4_18: UK3CB_BAF_Merlin_HC3_18 {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC4_24: UK3CB_BAF_Merlin_HC3_24 {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC4_32: UK3CB_BAF_Merlin_HC3_32 {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC4_Cargo: UK3CB_BAF_Merlin_HC3_Cargo {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC4_18_GPMG: UK3CB_BAF_Merlin_HC3_18_GPMG {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HC4_CSAR: UK3CB_BAF_Merlin_HC3_CSAR {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HM2_Base: UK3CB_BAF_Merlin_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HM2_Unarmed_Base: UK3CB_BAF_Merlin_HM2_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Merlin_HM2_18: UK3CB_BAF_Merlin_HM2_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
};
