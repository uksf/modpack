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
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Drone {
                displayName = "MQ-9 Control";
                condition = QUOTE(!((getConnectedUAV _player) isEqualTo objNull) && (getConnectedUAV _player) isKindOf 'CUP_MQ9_Base');
                statement = "";
                showDisabled = 1;
                priority = 1;
                icon = "CUP\AirVehicles\CUP_AirVehicles_MQ9\data\UI\icon_MQ9PredatorB_CA.paa";
                class ACE_Drone_Behaviour {
                    displayName = "Behaviour";
                    condition = "";
                    statement = "";
                    showDisabled = 1;
                    priority = 1;
                    icon = "CUP\AirVehicles\CUP_AirVehicles_MQ9\data\UI\icon_MQ9PredatorB_CA.paa";
                    class UAV_Strike_Mode {
                        displayName = "Strike";
                        condition = QUOTE(!((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(diveMode),false)]));
                        statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),true,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Observer_Mode {
                        displayName = "Observer";
                        condition = QUOTE(!((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(observationMode),false)]));
                        statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),true,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Reset_Mode {
                        displayName = "Reset";
                        condition = QUOTE((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(diveMode),false)] || (getConnectedUAV _player) getVariable [ARR_2(QQGVAR(observationMode),false)]);
                        statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                };
                class ACE_Drone_Altitude {
                    displayName = "Altitude";
                    condition = "";
                    statement = "";
                    showDisabled = 1;
                    priority = 1;
                    icon = "CUP\AirVehicles\CUP_AirVehicles_MQ9\data\UI\icon_MQ9PredatorB_CA.paa";
                    class UAV_Altitude_1000 {
                        displayName = "1000m";
                        condition = QUOTE(((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) != 1000);
                        statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),1000,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Altitude_1500 {
                        displayName = "1500m";
                        condition = QUOTE(((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) != 1500);
                        statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),1500,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Altitude_2000 {
                        displayName = "2000m";
                        condition = QUOTE(((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) != 2000);
                        statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),2000,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Altitude_100_Plus {
                        displayName = "+100m";
                        condition = "";
                        statement = QUOTE(_height = ((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) + 100; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),_height,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Altitude_100_Minus {
                        displayName = "-100m";
                        condition = "";
                        statement = QUOTE(_height = ((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) - 100; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),_height,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Altitude_reset {
                        displayName = "Reset";
                        condition = QUOTE((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(customWaypoint),false)]);
                        statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),false,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                };
                class ACE_Drone_Radius {
                    displayName = "Loiter Radius";
                    condition = QUOTE((waypointType [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) isEqualTo 'LOITER');
                    statement = "";
                    showDisabled = 1;
                    priority = 1;
                    icon = "CUP\AirVehicles\CUP_AirVehicles_MQ9\data\UI\icon_MQ9PredatorB_CA.paa";
                    class UAV_Radius_1000 {
                        displayName = "1000m";
                        condition = QUOTE((waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 1000);
                        statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 1000;);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Radius_1500 {
                        displayName = "1500m";
                        condition = QUOTE((waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 1500);
                        statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 1500;);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Radius_2000 {
                        displayName = "2000m";
                        condition = QUOTE((waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 2000);
                        statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 2000;);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Radius_100_Plus {
                        displayName = "+100m";
                        condition = "";
                        statement = QUOTE(_radius = (waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) + 100; [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 2000;);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Radius_100_Minus {
                        displayName = "-100m";
                        condition = "";
                        statement = QUOTE(_radius = (waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) - 100; [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 2000;);
                        showDisabled = 1;
                        priority = 1;
                    };
                };
                class ACE_Drone_Waypoint {
                    displayName = "Waypoints";
                    condition = QUOTE((count (waypoints group (getConnectedUAV _player))) > 1);
                    statement = "";
                    showDisabled = 1;
                    priority = 1;
                    icon = "CUP\AirVehicles\CUP_AirVehicles_MQ9\data\UI\icon_MQ9PredatorB_CA.paa";
                    class UAV_Waypoint_Loiter {
                        displayName = "Loiter";
                        condition = QUOTE((waypointType [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 'LOITER');
                        statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointType 'LOITER'; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),true,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Waypoint_Move {
                        displayName = "Move";
                        condition = QUOTE((waypointType [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 'MOVE');
                        statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointType 'MOVE'; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Waypoint_MoveToCrosshair {
                        displayName = "Move To Crosshair";
                        condition = "";
                        statement = QUOTE([ARR_2(getConnectedUAV _player, false)] call FUNC(moveTo););
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Waypoint_StrikeCrosshair {
                        displayName = "Strike Crosshair";
                        condition = "";
                        statement = QUOTE([ARR_2(getConnectedUAV _player, true)] call FUNC(moveTo););
                        showDisabled = 1;
                        priority = 1;
                    };
                };
                class ACE_Drone_Compass {
                    displayName = "Compass";
                    condition = "";
                    statement = "";
                    showDisabled = 1;
                    priority = 1;
                    icon = "CUP\AirVehicles\CUP_AirVehicles_MQ9\data\UI\icon_MQ9PredatorB_CA.paa";
                    class UAV_Compass_On {
                        displayName = "On";
                        condition = QUOTE(!((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(compassState),false)]));
                        statement = QUOTE([ARR_2(getConnectedUAV _player, true)] call FUNC(compass););
                        showDisabled = 1;
                        priority = 1;
                    };
                    class UAV_Compass_Off {
                        displayName = "Off";
                        condition = QUOTE((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(compassState),false)]);
                        statement = QUOTE([ARR_2(getConnectedUAV _player, false)] call FUNC(compass););
                        showDisabled = 1;
                        priority = 1;
                    };
                };
            };
        };
    };

    class Plane;
    class UAV: Plane {
        class NewTurret;
        class Components;
    };
    class CUP_MQ9_Base: UAV {
        camouflage = 0;
        class Turrets {
            class MainTurret: NewTurret {
                turretInfoType = "RscOptics_UAV_gunnerClean";
                weapons[] = { "Laserdesignator_mounted", "ace_hellfire_launcher", "ace_hellfire_launcher_N" };
                magazines[] = { "Laserbatteries", "4Rnd_ACE_Hellfire_AGM114K", "4Rnd_ACE_Hellfire_AGM114N" };
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
    };
    class CUP_B_USMC_MQ9;
    class CUP_B_UKSF_MQ9: CUP_B_USMC_MQ9 {
        author = "UKSF";
        faction = "CUP_B_GB";
        hiddenSelections[] = { "camo1" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\UKSF_MQ9_co.paa) };
    };
};
