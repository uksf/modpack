class CfgVehicles {
    /*class Man;
    class CAManBase : Man {
        class ACE_SelfActions {
            class ACE_Drone {
                displayName = "MQ-9 Control";
                condition = QUOTE(!((getConnectedUAV _player) isEqualTo objNull) && (getConnectedUAV _player) isKindOf 'USAF_MQ9');
                statement = "";
                showDisabled = 1;
                priority = 1;
                icon = "USAF_MQ9\Data\icon_USAF_MQ9.paa";
                class ACE_Drone_Behaviour {
                    displayName = "Behaviour";
                    condition = "";
                    statement = "";
                    showDisabled = 1;
                    priority = 1;
                    icon = "USAF_MQ9\Data\icon_USAF_MQ9.paa";
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
                    icon = "USAF_MQ9\Data\icon_USAF_MQ9.paa";
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
                    condition = QUOTE((waypointType [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) == 'LOITER');
                    statement = "";
                    showDisabled = 1;
                    priority = 1;
                    icon = "USAF_MQ9\Data\icon_USAF_MQ9.paa";
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
                    icon = "USAF_MQ9\Data\icon_USAF_MQ9.paa";
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
                    icon = "USAF_MQ9\Data\icon_USAF_MQ9.paa";
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
    };*/

    /*class Plane;
    class UAV : Plane {
        class NewTurret;
        class ViewPilot;
        class ViewOptics;
        class AnimationSources;
    };
    class USAF_MQ9 : UAV {
        author = "UKSF";
        displayName = "MQ-9 Reaper";
        faction = "UKSF_Clan";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_MQ9.jpg);
        hiddenSelections[] = { "camo1" };
        hiddenSelectionsTextures[] = { QPATHTOF(data\UKSF_MQ9_co.paa) };
        class Turrets {
            class MainTurret : NewTurret {
                showAllTargets = 4;
                weapons[] = { "Laserdesignator_mounted", "UK3CB_BAF_HellfireLauncher_K", "UK3CB_BAF_HellfireLauncher_N" };
                magazines[] = { "Laserbatteries", "UK3CB_BAF_4Rnd_Hellfire_K", "UK3CB_BAF_4Rnd_Hellfire_N" };
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
        class camShakeDamage {
            power = 0;
            frequency = 0;
            distance = 0;
            minSpeed = 1;
            attenuation = 0;
            duration = 0;
        };
    };*/
};