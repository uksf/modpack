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
    };
    class CUP_MQ9_Base: UAV {
        class Turrets {
            class MainTurret: NewTurret {
                turretInfoType = "RscOptics_UAV_gunnerAdvanced";
                weapons[] = { "Laserdesignator_mounted","CUP_AGM114K_Hellfire_II_Launcher_W","CUP_AGM114N_Hellfire_II_Launcher_W" };
                magazines[] = { "Laserbatteries","CUP_4Rnd_AGM114K_Hellfire_II_M","CUP_4Rnd_AGM114N_Hellfire_II_M" };
                maxHorizontalRotSpeed = 1.75;
                maxVerticalRotSpeed = 1.75;
                class OpticsIn {
                    class Wide {
                        opticsDisplayName = "W";
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
                        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
                        opticsPPEffects[] = { "OpticsCHAbera2","OpticsBlur2" };
                    };
                    class Medium: Wide {
                        gunnerOpticsColor[] = { 0,0,0,1 };
                        initFov = 0.466;
                        minFov = 0.466;
                        maxFov = 0.466;
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
                    };
                    class Narrow: Wide {
                        opticsDisplayName = "WL";
                        initFov = 0.2;
                        minFov = 0.2;
                        maxFov = 0.2;
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
                    };
                    class Narrower: Wide {
                        opticsDisplayName = "M";
                        initFov = 0.1;
                        minFov = 0.1;
                        maxFov = 0.1;
                        directionStabilized = 1;
                    };
                    class Narrowerer: Wide {
                        opticsDisplayName = "N";
                        initFov = 0.02;
                        minFov = 0.02;
                        maxFov = 0.02;
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
                    };
                    class Narrowererer: Wide {
                        opticsDisplayName = "N";
                        initFov = 0.01;
                        minFov = 0.01;
                        maxFov = 0.01;
                        directionStabilized = 1;
                        gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
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
    };
    class CUP_B_USMC_MQ9;
    class CUP_B_UKSF_MQ9: CUP_B_USMC_MQ9 {
        author = "UKSF";
        faction = "CUP_B_GB";
        //editorPreview = QPATHTOEF(common,data\previews\CUP_B_UKSF_MQ9.jpg);
        hiddenSelections[] = { "camo1" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\UKSF_MQ9_co.paa) };
    };
};
