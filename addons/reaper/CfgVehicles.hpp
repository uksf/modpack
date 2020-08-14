class DefaultVehicleSystemsDisplayManagerRight;
class DefaultVehicleSystemsDisplayManagerLeft;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class SensorTemplateDataLink;
class CfgVehicles {
    class Plane;
    class UAV : Plane {
        class NewTurret;
        class Components;
    };
    class CUP_MQ9_Base : UAV {
        camouflage = 0;
        wheelSteeringSensitivity = 1;
        fuelCapacity = 1850;  // 270
        unitInfoType = "RscOptics_AV_airplane_pilot";
        class Turrets {
            class MainTurret : NewTurret {
                turretInfoType = "RscOptics_UAV_gunnerClean";
                startEngine = 0;
                maxHorizontalRotSpeed = 4;
                maxVerticalRotSpeed = 4;
                class OpticsIn {
                    class Wide {
                        opticsDisplayName = "WW";
                        initAngleX = 0;
                        minAngleX = -35;
                        maxAngleX = 10;
                        initAngleY = 0;
                        minAngleY = -100;
                        maxAngleY = 100;
                        initFov = 0.466;
                        minFov = 0.466;
                        maxFov = 0.466;
                        directionStabilized = 0;
                        visionMode[] = { "Normal", "NVG", "Ti" };
                        thermalMode[] = { 0, 1 };
                        gunnerOpticsColor[] = { 0.15, 1, 0.15, 1 };
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                        opticsPPEffects[] = {};
                    };
                    class Medium : Wide {
                        opticsDisplayName = "W";
                        gunnerOpticsColor[] = { 0, 0, 0, 1 };
                        initFov = 0.466;
                        minFov = 0.466;
                        maxFov = 0.466;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrow : Wide {
                        opticsDisplayName = "WM";
                        initFov = 0.2;
                        minFov = 0.2;
                        maxFov = 0.2;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrower : Wide {
                        opticsDisplayName = "M";
                        initFov = 0.1;
                        minFov = 0.1;
                        maxFov = 0.1;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowerer : Wide {
                        opticsDisplayName = "MN";
                        initFov = 0.05;
                        minFov = 0.05;
                        maxFov = 0.05;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowererer : Wide {
                        opticsDisplayName = "WN";
                        initFov = 0.02;
                        minFov = 0.02;
                        maxFov = 0.02;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowerererer : Wide {
                        opticsDisplayName = "N";
                        initFov = 0.01;
                        minFov = 0.01;
                        maxFov = 0.01;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowererererer : Wide {
                        opticsDisplayName = "NN";
                        initFov = 0.005;
                        minFov = 0.005;
                        maxFov = 0.005;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                };
                class Components {
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
        };
        class Components : Components {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                defaultDisplay = "EmptyDisplay";
                class Components {
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
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
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
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
                    class ActiveRadarComponent : SensorTemplateActiveRadar {
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        typeRecognitionDistance = 12000;
                        angleRangeHorizontal = 360;
                        angleRangeVertical = 360;
                        maxGroundNoiseDistance = -1;
                        groundNoiseDistanceCoef = -1;
                        minSpeedThreshold = 0;
                        maxSpeedThreshold = 24;
                    };
                    class IRSensorComponent : SensorTemplateIR {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                    };
                    class VisualSensorComponent : SensorTemplateVisual {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                    };
                    class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                    class NVSensorComponent : SensorTemplateNV {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                    };
                    class LaserSensorComponent : SensorTemplateLaser {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 0;
                            minRange = 0;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                    };
                    class DataLinkSensorComponent : SensorTemplateDataLink {};
                };
            };
        };
        class CamShake {
            power = 0;
            frequency = 0;
            distance = 0;
            minSpeed = 1000;
        };
        class camShakeGForce {
            power = 0;
            frequency = 0;
            distance = 0;
            minSpeed = 1000;
        };
        soundEngineOnInt[] = { "A3\Sounds_F\air\UAV_02\UAV_02_start_ext", 0, 1 };
        soundEngineOffInt[] = { "A3\Sounds_F\air\UAV_02\UAV_02_stop_int", 0, 1 };
        class Sounds {
            class EngineLowIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\UAV_02_low_int", 0, 1 };
                frequency = "1.0 min (rpm + 0.5)";
                volume = "(1-camPos)*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
            };
            class EngineHighIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\UAV_02_high_int", 0, 1 };
                frequency = "(rpm factor[0.5, 1.0])";
                volume = "(1-camPos)*(rpm factor[0.2, 1.0])";
            };
            class ForsageIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\UAV_02_forsage_int", 0, 1 };
                frequency = "1";
                volume = "engineOn*(1-camPos)*(thrust factor[0.6, 1.0])";
            };
            class WindNoiseIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\noise", 0, 1 };
                frequency = "(0.3+(1.005*(speed factor[1, 50])))";
                volume = "(1-camPos)*(speed factor[1, 50])";
            };
            class RainInt {
                sound[] = { "A3\Sounds_F\vehicles\noises\rain2_ext", 0, 1, 100 };
                frequency = 1;
                volume = "(1-camPos)*(rain - rotorSpeed/2)*2";
            };
        };
    };
    class CUP_MQ9_Dyn_Base : CUP_MQ9_Base {};
    class CUP_B_USMC_DYN_MQ9 : CUP_MQ9_Dyn_Base {};

    class UAV_02_dynamicLoadout_base_F;
    class UK3CB_BAF_MQ9_Reaper_Base : UAV_02_dynamicLoadout_base_F {
        class Turrets {
            class MainTurret;
        };
        class Components;
    };
    class UK3CB_BAF_MQ9_Reaper : UK3CB_BAF_MQ9_Reaper_Base {
        faction = "CUP_B_GB";
        editorPreview = QPATHTOEF(common,data\previews\UK3CB_BAF_MQ9_Reaper.jpg);
        radarTargetSize = 0.001;
        radarTarget = 0;
        visualTarget = 0;
        nvTarget = 0;
        irTarget = 0;
        camouflage = 0;
        aileronSensitivity = 1;
        elevatorSensitivity = 1;
        wheelSteeringSensitivity = 1;
        fuelCapacity = 1850;  // 270
        unitInfoType = "RscOptics_AV_airplane_pilot";
        class Turrets : Turrets {
            class MainTurret : MainTurret {
                turretInfoType = "RscOptics_UAV_gunnerClean";
                maxHorizontalRotSpeed = 4;
                maxVerticalRotSpeed = 4;
                class OpticsIn {
                    class Wide {
                        opticsDisplayName = "WW";
                        initAngleX = 0;
                        minAngleX = -35;
                        maxAngleX = 10;
                        initAngleY = 0;
                        minAngleY = -100;
                        maxAngleY = 100;
                        initFov = 0.5;
                        minFov = 0.5;
                        maxFov = 0.5;
                        directionStabilized = 0;
                        visionMode[] = { "Normal", "NVG", "Ti" };
                        thermalMode[] = { 0, 1 };
                        gunnerOpticsColor[] = { 0.15, 1, 0.15, 1 };
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                        opticsPPEffects[] = {};
                    };
                    class Medium : Wide {
                        opticsDisplayName = "W";
                        gunnerOpticsColor[] = { 0, 0, 0, 1 };
                        initFov = 0.5;
                        minFov = 0.5;
                        maxFov = 0.5;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrow : Wide {
                        opticsDisplayName = "WM";
                        initFov = 0.25;
                        minFov = 0.25;
                        maxFov = 0.25;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrower : Wide {
                        opticsDisplayName = "M";
                        initFov = 0.1;
                        minFov = 0.1;
                        maxFov = 0.1;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowerer : Wide {
                        opticsDisplayName = "MN";
                        initFov = 0.05;
                        minFov = 0.05;
                        maxFov = 0.05;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowererer : Wide {
                        opticsDisplayName = "WN";
                        initFov = 0.02;
                        minFov = 0.02;
                        maxFov = 0.02;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowerererer : Wide {
                        opticsDisplayName = "N";
                        initFov = 0.01;
                        minFov = 0.01;
                        maxFov = 0.01;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowererererer : Wide {
                        opticsDisplayName = "NN";
                        initFov = 0.005;
                        minFov = 0.005;
                        maxFov = 0.005;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                };
                class Components {
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
        };
        class Components : Components {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                defaultDisplay = "EmptyDisplay";
                class Components {
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
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
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
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
                    class ActiveRadarComponent : SensorTemplateActiveRadar {
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        typeRecognitionDistance = 12000;
                        angleRangeHorizontal = 360;
                        angleRangeVertical = 360;
                        maxGroundNoiseDistance = -1;
                        groundNoiseDistanceCoef = -1;
                        minSpeedThreshold = 0;
                        maxSpeedThreshold = 24;
                    };
                    class IRSensorComponent : SensorTemplateIR {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                    };
                    class VisualSensorComponent : SensorTemplateVisual {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                    };
                    class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                    class NVSensorComponent : SensorTemplateNV {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                    };
                    class LaserSensorComponent : SensorTemplateLaser {
                        aimDown = 0;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 30;
                        angleRangeVertical = 30;
                        maxTrackableSpeed = 110;
                        class AirTarget {
                            maxRange = 0;
                            minRange = 0;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            maxRange = 12000;
                            minRange = 12000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                    };
                    class DataLinkSensorComponent : SensorTemplateDataLink {};
                };
            };
            class TransportPylonsComponent {
                UIPicture = "\CUP\AirVehicles\CUP_AirVehicles_MQ9\data\ui\CUP_MQ9_3DEN_ca.paa";
                class presets {
                    class Default {
                        attachment[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone" };
                        displayName = "Mixed";
                    };
                    class AT {
                        attachment[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone" };
                        displayName = "Anti-Tank";
                    };
                    class AP {
                        attachment[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone", "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone" };
                        displayName = "Anti-Personnel";
                    };
                };
                class pylons {
                    class Pylons1 {
                        attachment = "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone";
                        hardpoints[] = { "B_HELLFIRE_DRONE" };
                        maxweight = 800;
                        priority = 0;
                        bay = -1;
                        UIposition[] = { 0.1, 0.4 };
                        turret[] = { 0 };
                    };
                    class Pylons2 : Pylons1 {
                        attachment = "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone";
                        UIposition[] = { 0.2, 0.45 };
                    };
                    class Pylons3 : Pylons2 {
                        attachment = "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone";
                        UIposition[] = { 0.45, 0.45 };
                        mirroredMissilePos = 2;
                    };
                    class Pylons4 : Pylons1 {
                        attachment = "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone";
                        UIposition[] = { 0.5, 0.4 };
                        mirroredMissilePos = 1;
                    };
                };
            };
        };
        class CamShake {
            power = 0;
            frequency = 0;
            distance = 0;
            minSpeed = 1000;
        };
        class camShakeGForce {
            power = 0;
            frequency = 0;
            distance = 0;
            minSpeed = 1000;
        };
        soundEngineOnInt[] = { "A3\Sounds_F\air\UAV_02\UAV_02_start_ext", 0, 1 };
        soundEngineOffInt[] = { "A3\Sounds_F\air\UAV_02\UAV_02_stop_int", 0, 1 };
        class Sounds {
            class EngineLowIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\UAV_02_low_int", 0, 1 };
                frequency = "1.0 min (rpm + 0.5)";
                volume = "(1-camPos)*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
            };
            class EngineHighIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\UAV_02_high_int", 0, 1 };
                frequency = "(rpm factor[0.5, 1.0])";
                volume = "(1-camPos)*(rpm factor[0.2, 1.0])";
            };
            class ForsageIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\UAV_02_forsage_int", 0, 1 };
                frequency = "1";
                volume = "engineOn*(1-camPos)*(thrust factor[0.6, 1.0])";
            };
            class WindNoiseIn {
                sound[] = { "A3\Sounds_F\air\UAV_02\noise", 0, 1 };
                frequency = "(0.3+(1.005*(speed factor[1, 50])))";
                volume = "(1-camPos)*(speed factor[1, 50])";
            };
            class RainInt {
                sound[] = { "A3\Sounds_F\vehicles\noises\rain2_ext", 0, 1, 100 };
                frequency = 1;
                volume = "(1-camPos)*(rain - rotorSpeed/2)*2";
            };
        };
    };
    class CUP_B_UKSF_MQ9 : UK3CB_BAF_MQ9_Reaper {
        scope = 1;
        scopeCurator = 1;
    };
};
