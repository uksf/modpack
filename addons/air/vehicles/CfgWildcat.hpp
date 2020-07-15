class Heli_light_03_base_F : Helicopter_Base_F {
    class Components;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class UK3CB_BAF_Wildcat_Base : Heli_light_03_base_F {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    fuelCapacity = 400;  // 742
    startDuration = 30;
    mainRotorSpeed = 1;
    bodyFrictionCoef = 0.5;  // 1
    liftForceCoef = 0.95;    // 1
    maxFordingDepth = 1.2;   // 0.7
    cyclicAsideForceCoef = 1.2; // 1
    cyclicForwardForceCoef = 1.1; // 1
    unitInfoType = "RscUnitInfoNoSpeed";
    attenuationEffectType = "SemiOpenHeliAttenuation";
#include "MFDCAS.hpp"
    class Components : Components {
        class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000, 8000, 4000, 2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
            defaultDisplay = "SensorsDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000, 8000, 4000, 2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class SensorsManagerComponent {
            class Components {
                class IRSensorComponent : SensorTemplateIR {
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
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class VisualSensorComponent : SensorTemplateVisual {
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
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class ActiveRadarSensorComponent : SensorTemplateActiveRadar {
                    class AirTarget {
                        minRange = 5000;
                        maxRange = 5000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 4000;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    maxTrackableSpeed = 125;
                    angleRangeVertical = 90;
                    groundNoiseDistanceCoef = -1;
                    maxGroundNoiseDistance = -1;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 0;
                    aimDown = 30;
                    animDirection = "";
                };
                class NVSensorComponent : SensorTemplateNV {
                    animDirection = "flir_gun";
                };
                class LaserSensorComponent : SensorTemplateLaser {
                    animDirection = "flir_gun";
                };
                class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                class DataLinkSensorComponent : SensorTemplateDataLink {};
            };
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class OpticsIn {
                class WideNGS {
                    opticsDisplayName = "WNGS";
                    initAngleX = 0;
                    minAngleX = -35;
                    maxAngleX = 10;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = 0.5;
                    minFov = 0.5;
                    maxFov = 0.5;
                    visionMode[] = { "Normal", "NVG", "Ti" };
                    thermalMode[] = { 0, 1 };
                    gunnerOpticsColor[] = { 0, 0, 0, 1 };
                    gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
                    opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
                    directionStabilized = 0;
                };
                class Wide : WideNGS {
                    opticsDisplayName = "W";
                    initFov = 0.466;
                    minFov = 0.466;
                    maxFov = 0.466;
                    gunnerOpticsEffect[] = { "TankCommanderOptics1" };
                    directionStabilized = 1;
                    horizontallyStabilized = 1;
                    stabilizedInAxes = 3;
                };
                class WideL : Wide {
                    opticsDisplayName = "WL";
                    initFov = 0.094;
                    minFov = 0.094;
                    maxFov = 0.094;
                };
                class Medium : Wide {
                    opticsDisplayName = "M";
                    initFov = 0.019;
                    minFov = 0.019;
                    maxFov = 0.019;
                };
                class Narrow : Wide {
                    opticsDisplayName = "N";
                    initFov = 0.006;
                    minFov = 0.006;
                    maxFov = 0.006;
                };
            };
            class OpticsOut {
                class Monocular {
                    minAngleX = -65;
                    maxAngleX = 85;
                    initAngleX = 0;
                    minAngleY = -150;
                    maxAngleY = 150;
                    initAngleY = 0;
                    minFov = 0.25;
                    maxFov = 1.25;
                    initFov = 0.75;
                    visionMode[] = { "Normal", "NVG" };
                    gunnerOpticsModel = "";
                    gunnerOpticsEffect[] = {};
                    directionStabilized = 0;
                };
            };
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                defaultDisplay = "EmptyDisplay";
                class Components {
                    class SensorsDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        resource = "RscCustomInfoSensors";
                    };
                    class CrewDisplay {
                        componentType = "CrewDisplayComponent";
                        resource = "RscCustomInfoCrew";
                    };
                    class MinimapDisplay {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
                    class EmptyDisplay {
                        componentType = "EmptyDisplayComponent";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
                defaultDisplay = "SensorsDisplay";
                class Components {
                    class SensorsDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        resource = "RscCustomInfoSensors";
                    };
                    class CrewDisplay {
                        componentType = "CrewDisplayComponent";
                        resource = "RscCustomInfoCrew";
                    };
                    class MinimapDisplay {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
                    class EmptyDisplay {
                        componentType = "EmptyDisplayComponent";
                    };
                };
            };
        };
    };
    ace_cookoff_cookoffSelections[] = { "motor" };
    INVENTORY_AIRCRAFT
};
class UK3CB_BAF_Wildcat_AH1_Base : UK3CB_BAF_Wildcat_Base {
};
class UK3CB_BAF_Wildcat_AH1_6_Base : UK3CB_BAF_Wildcat_AH1_Base {
    class TransportBackpacks {};
};
class UK3CB_BAF_Wildcat_AH1_8_Base : UK3CB_BAF_Wildcat_AH1_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    class TransportBackpacks {};
};
class UK3CB_BAF_Wildcat_AH1_TRN_8A : UK3CB_BAF_Wildcat_AH1_8_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_Wildcat_AH1_CAS_6A : UK3CB_BAF_Wildcat_AH1_6_Base {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_656";
    typicalCargo[] = { "UKSF_B_Pilot_656" };
};
class UK3CB_BAF_Wildcat_AH1_CAS_6B : UK3CB_BAF_Wildcat_AH1_CAS_6A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_AH1_CAS_6C : UK3CB_BAF_Wildcat_AH1_CAS_6A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_AH1_CAS_6D : UK3CB_BAF_Wildcat_AH1_CAS_6A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_AH1_CAS_8A : UK3CB_BAF_Wildcat_AH1_8_Base {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_656";
    typicalCargo[] = { "UKSF_B_Pilot_656" };
};
class UK3CB_BAF_Wildcat_AH1_CAS_8B : UK3CB_BAF_Wildcat_AH1_CAS_8A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_AH1_CAS_8C : UK3CB_BAF_Wildcat_AH1_CAS_8A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_AH1_CAS_8D : UK3CB_BAF_Wildcat_AH1_CAS_8A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_AH1_HEL_6A : UK3CB_BAF_Wildcat_AH1_6_Base {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_AH1_HEL_8A : UK3CB_BAF_Wildcat_AH1_8_Base {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_Wildcat_HMA2_Base : UK3CB_BAF_Wildcat_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    class TransportBackpacks {};
};
class UK3CB_BAF_Wildcat_HMA2_8_Base : UK3CB_BAF_Wildcat_HMA2_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
};
class UK3CB_BAF_Wildcat_HMA2_TRN_8A : UK3CB_BAF_Wildcat_HMA2_8_Base {
    faction = "CUP_B_GB";
};
