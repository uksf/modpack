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
    class UAV: Plane {
        class NewTurret;
        class Components;
    };
    class CUP_MQ9_Base: UAV {
        camouflage = 0;
        wheelSteeringSensitivity = 1;
        class Turrets {
            class MainTurret: NewTurret {
                turretInfoType = "RscOptics_UAV_gunnerClean";
                weapons[] = { "Laserdesignator_mounted", "ace_hellfire_launcher_drone", "ace_hellfire_launcher_drone_N" };
                magazines[] = { "Laserbatteries", "4Rnd_ACE_Hellfire_AGM114K_drone", "4Rnd_ACE_Hellfire_AGM114N_drone" };
                startEngine = 0;
                maxHorizontalRotSpeed = 1.75;
                maxVerticalRotSpeed = 1.75;
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
                        visionMode[] = { "Normal","NVG","Ti" };
                        thermalMode[] = { 0,1 };
                        gunnerOpticsColor[] = { 0.15,1,0.15,1 };
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                        opticsPPEffects[] = {};
                    };
                    class Medium: Wide {
                        opticsDisplayName = "W";
                        gunnerOpticsColor[] = { 0,0,0,1 };
                        initFov = 0.466;
                        minFov = 0.466;
                        maxFov = 0.466;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrow: Wide {
                        opticsDisplayName = "WM";
                        initFov = 0.2;
                        minFov = 0.2;
                        maxFov = 0.2;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrower: Wide {
                        opticsDisplayName = "M";
                        initFov = 0.1;
                        minFov = 0.1;
                        maxFov = 0.1;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowerer: Wide {
                        opticsDisplayName = "MN";
                        initFov = 0.05;
                        minFov = 0.05;
                        maxFov = 0.05;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowererer: Wide {
                        opticsDisplayName = "WN";
                        initFov = 0.02;
                        minFov = 0.02;
                        maxFov = 0.02;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowerererer: Wide {
                        opticsDisplayName = "N";
                        initFov = 0.01;
                        minFov = 0.01;
                        maxFov = 0.01;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                    class Narrowererererer: Wide {
                        opticsDisplayName = "NN";
                        initFov = 0.005;
                        minFov = 0.005;
                        maxFov = 0.005;
                        directionStabilized = 1;
                        gunnerOpticsModel = QPATHTOF(data\empty.p3d);
                    };
                };
                class Components {
                    class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                        defaultDisplay = "EmptyDisplay";
                        class Components {
                            class MissileDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "Missile";
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
                    class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                        defaultDisplay = "SensorsDisplay";
                        class Components {
                            class MissileDisplay {
                                componentType = "TransportFeedDisplayComponent";
                                source = "Missile";
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
                };
            };
        };
        class Components: Components {
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                defaultDisplay = "EmptyDisplay";
                class Components {
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
                    class MissileDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Missile";
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
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                defaultDisplay = "SensorsDisplay";
                class Components {
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
                    class MissileDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Missile";
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
                    class ActiveRadarComponent: SensorTemplateActiveRadar {
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
                    class IRSensorComponent: SensorTemplateIR {
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
                    class VisualSensorComponent: SensorTemplateVisual {
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
                    class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                    class NVSensorComponent: SensorTemplateNV {
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
                    class LaserSensorComponent: SensorTemplateLaser {
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
                    class DataLinkSensorComponent: SensorTemplateDataLink {};
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
        class ACE_SelfActions {
            class ACE_Drone_Behaviour {
                displayName = "Behaviour";
                condition = "";
                statement = "";
                showDisabled = 1;
                enableInside = 1;
                priority = 1;
                class UAV_Strike_Mode {
                    displayName = "Strike";
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(diveMode),false)]));
                    statement = QUOTE(_target setVariable [ARR_3(QQGVAR(diveMode),true,true)]; _target setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
                };
                class UAV_Observer_Mode {
                    displayName = "Observer";
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(observationMode),false)]));
                    statement = QUOTE(_target setVariable [ARR_3(QQGVAR(diveMode),false,true)]; _target setVariable [ARR_3(QQGVAR(observationMode),true,true)];);
                };
                class UAV_Reset_Mode {
                    displayName = "Reset";
                    condition = QUOTE(_target getVariable [ARR_2(QQGVAR(diveMode),false)] || _target getVariable [ARR_2(QQGVAR(observationMode),false)]);
                    statement = QUOTE(_target setVariable [ARR_3(QQGVAR(diveMode),false,true)]; _target setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
                };
            };
            class ACE_Drone_Altitude {
                displayName = "Altitude";
                condition = "";
                statement = "";
                showDisabled = 1;
                enableInside = 1;
                priority = 1;
                class UAV_Altitude_1000 {
                    displayName = "1000m";
                    condition = QUOTE((_target getVariable QQGVAR(targetHeightASL)) != 1000);
                    statement = QUOTE(_target setVariable [ARR_3(QQGVAR(targetHeightASL),1000,true)]; _target setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
                };
                class UAV_Altitude_1500 {
                    displayName = "1500m";
                    condition = QUOTE((_target getVariable QQGVAR(targetHeightASL)) != 1500);
                    statement = QUOTE(_target setVariable [ARR_3(QQGVAR(targetHeightASL),1500,true)]; _target setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
                };
                class UAV_Altitude_2000 {
                    displayName = "2000m";
                    condition = QUOTE((_target getVariable QQGVAR(targetHeightASL)) != 2000);
                    statement = QUOTE(_target setVariable [ARR_3(QQGVAR(targetHeightASL),2000,true)]; _target setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
                };
                class UAV_Altitude_200_Plus {
                    displayName = "+200m";
                    condition = "";
                    statement = QUOTE(private _height = (_target getVariable QQGVAR(targetHeightASL)) + 200; _target setVariable [ARR_3(QQGVAR(targetHeightASL),_height,true)];);
                };
                class UAV_Altitude_200_Minus {
                    displayName = "-200m";
                    condition = "";
                    statement = QUOTE(private _height = (_target getVariable QQGVAR(targetHeightASL)) - 200; _target setVariable [ARR_3(QQGVAR(targetHeightASL),_height,true)];);
                };
                class UAV_Altitude_reset {
                    displayName = "Reset";
                    condition = QUOTE(_target getVariable [ARR_2(QQGVAR(customWaypoint),false)]);
                    statement = QUOTE(_target setVariable [ARR_3(QQGVAR(customWaypoint),false,true)];);
                };
            };
            class ACE_Drone_Radius {
                displayName = "Loiter Radius";
                condition = QUOTE((waypointType [ARR_2(group _target,currentWaypoint (group _target))]) isEqualTo 'LOITER');
                statement = "";
                showDisabled = 1;
                enableInside = 1;
                priority = 1;
                class UAV_Radius_1000 {
                    displayName = "1000m";
                    condition = QUOTE((waypointLoiterRadius [ARR_2(group _target,currentWaypoint (group _target))]) != 1000);
                    statement = QUOTE([ARR_2(group _target,currentWaypoint (group _target))] setWaypointLoiterRadius 1000;);
                };
                class UAV_Radius_1500 {
                    displayName = "1500m";
                    condition = QUOTE((waypointLoiterRadius [ARR_2(group _target,currentWaypoint (group _target))]) != 1500);
                    statement = QUOTE([ARR_2(group _target,currentWaypoint (group _target))] setWaypointLoiterRadius 1500;);
                };
                class UAV_Radius_2000 {
                    displayName = "2000m";
                    condition = QUOTE((waypointLoiterRadius [ARR_2(group _target,currentWaypoint (group _target))]) != 2000);
                    statement = QUOTE([ARR_2(group _target,currentWaypoint (group _target))] setWaypointLoiterRadius 2000;);
                };
                class UAV_Radius_200_Plus {
                    displayName = "+200m";
                    condition = "";
                    statement = QUOTE(private _radius = (waypointLoiterRadius [ARR_2(group _target,currentWaypoint (group _target))]) + 200; [ARR_2(group _target,currentWaypoint (group _target))] setWaypointLoiterRadius 2000;);
                };
                class UAV_Radius_200_Minus {
                    displayName = "-200m";
                    condition = "";
                    statement = QUOTE(private _radius = (waypointLoiterRadius [ARR_2(group _target,currentWaypoint (group _target))]) - 200; [ARR_2(group _target,currentWaypoint (group _target))] setWaypointLoiterRadius 2000;);
                };
            };
            class ACE_Drone_Waypoint {
                displayName = "Waypoints";
                condition = QUOTE((count (waypoints group _target)) > 1);
                statement = "";
                showDisabled = 1;
                enableInside = 1;
                priority = 1;
                class UAV_Waypoint_Loiter {
                    displayName = "Loiter";
                    condition = QUOTE((waypointType [ARR_2(group _target,currentWaypoint (group _target))]) != 'LOITER');
                    statement = QUOTE([ARR_2(group _target,currentWaypoint (group _target))] setWaypointType 'LOITER'; _target setVariable [ARR_3(QQGVAR(diveMode),false,true)]; _target setVariable [ARR_3(QQGVAR(observationMode),true,true)];);
                };
                class UAV_Waypoint_Move {
                    displayName = "Move";
                    condition = QUOTE((waypointType [ARR_2(group _target,currentWaypoint (group _target))]) != 'MOVE');
                    statement = QUOTE([ARR_2(group _target,currentWaypoint (group _target))] setWaypointType 'MOVE'; _target setVariable [ARR_3(QQGVAR(diveMode),false,true)]; _target setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
                };
                class UAV_Waypoint_Delete {
                    displayName = "Delete";
                    condition = "";
                    statement = QUOTE({deleteWaypoint [ARR_2(group _target,1)];} forEach (waypoints (group _target)););
                };
                class UAV_Waypoint_MoveToCrosshair {
                    displayName = "Move To Crosshair";
                    condition = "";
                    statement = QUOTE([ARR_2(_target,false)] call FUNC(moveTo););
                };
                class UAV_Waypoint_StrikeCrosshair {
                    displayName = "Strike Crosshair";
                    condition = "";
                    statement = QUOTE([ARR_2(_target,true)] call FUNC(moveTo););
                };
            };
            class ACE_Drone_Compass {
                displayName = "Compass";
                condition = "";
                statement = QUOTE(private _state = (_target getVariable [ARR_2(QQGVAR(compassState),false)]); [ARR_2(_target,!_state)] call FUNC(compass););
                showDisabled = 1;
                enableInside = 1;
                priority = 1;
            };
            class ACE_Drone_Immobilise {
                displayName = "Immobilise";
                condition = QUOTE(speed _target < 10 && {!(_target getVariable [ARR_2(QQGVAR(immobilised),false)])});
                statement = QUOTE([ARR_2(_target,true)] call FUNC(immobilise));
                showDisabled = 1;
                enableInside = 1;
                priority = 1;
            };
            class ACE_Drone_Mobilise {
                displayName = "Mobilise";
                condition = QUOTE(speed _target < 10 && {(_target getVariable [ARR_2(QQGVAR(immobilised),false)])});
                statement = QUOTE([ARR_2(_target,false)] call FUNC(immobilise));
                showDisabled = 1;
                enableInside = 1;
                priority = 1;
            };
        };
        class Sounds {
            class EngineLowIn {
                sound[] = { "CUP\AirVehicles\CUP_AirVehicles_AN2\data\sound\AN2_engine_low_int", 0, 1 };
                frequency = "1.0 min (rpm + 0.5)";
                volume = "(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
            };
            class EngineHighIn {
                sound[] = { "CUP\AirVehicles\CUP_AirVehicles_AN2\data\sound\AN2_engine_high_int", 0, 1 };
                frequency = "1";
                volume = "(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
            };
            class ForsageIn {
                sound[] = { "CUP\AirVehicles\CUP_AirVehicles_AN2\data\sound\AN2_engine_high_int", 0, 1.1 };
                frequency = "1";
                volume = "(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
            };
            class WindNoiseIn {
                sound[] = { "CUP\AirVehicles\CUP_AirVehicles_AN2\data\sound\int-wind", 0, 0.6 };
                frequency = "(0.1+(1.2*(speed factor[1, 100])))";
                volume = "(1-camPos)*(speed factor[1, 100])";
            };
        };
    };
    class CUP_B_USMC_MQ9;
    class CUP_B_UKSF_MQ9: CUP_B_USMC_MQ9 {
        author = "UKSF";
        faction = "CUP_B_GB";
        hiddenSelections[] = { "camo1" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\UKSF_MQ9_co.paa) };
    };
};
