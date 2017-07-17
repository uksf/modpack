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
class CfgVehicles {
    class Plane;
    class Plane_Base_F: Plane {
        class Components;
    };
    class USAF_F35A: Plane_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "F-35A";
        faction = "CUP_B_GB";
        crew = "UKSF_B_Pilot_617";
        typicalCargo[] = { "UKSF_B_Pilot_617" };
        editorPreview = QPATHTOEF(common,data\previews\USAF_F35A.jpg);
        hiddenSelections[] = { "rendertarget0", "screen_1", "screen_2", "screen_3", "screen_4", "screen_5", "screen_6", "camo1", "camo2", "camo3", "camo4" };
        hiddenSelectionsTextures[] = { "#(rgb,8,8,3)color(0,0,0,0)", "", "", "", "", "", "", QPATHTOF(data\F-35Auk.paa), QPATHTOF(data\f_35c_ext_2_co.paa), QPATHTOF(data\f_35c_ext_3_co.paa), QPATHTOF(data\f35_glass_ca.paa) };
        weapons[] = {
            "USAF_F35A_CMFlareLauncher",
            "USAF_F35A_Master_Arm_Switch",
            "USAF_F35A_CANNON_W",
            "USAF_AIM9X_Launcher",
            "USAF_AIM120I_Launcher",
            "USAF_GBU12_Launcher",
            "USAF_F35A_GBU53_int_W",
            "USAF_AGM154A1_Launcher"
        };
        magazines[] = {
            "300Rnd_CMFlare_Chaff_Magazine",
            "USAF_F35A_CANNON_M",
            "USAF_1Rnd_StationR",
            "USAF_1Rnd_StationL",
            "USAF_1Rnd_Station2",
            "USAF_1Rnd_Station2",
            "USAF_1Rnd_Station1",
            "USAF_1Rnd_Station1",
            "USAF_1Rnd_AIM9X",
            "USAF_1Rnd_AIM9X",
            "USAF_1Rnd_AGM154A1",
            "USAF_1Rnd_AGM154A1",
            "USAF_Empty",
            "USAF_Empty",
            "USAF_Empty",
            "USAF_Empty",
            "USAF_1Rnd_GBU12",
            "USAF_1Rnd_GBU12",
            "USAF_1Rnd_AIM120I",
            "USAF_1Rnd_AIM120I",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty"
        };
        maxSpeed = 1930;
        /*soundEngineOnInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_start_int", 1, 1 };
        soundEngineOnExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_start_ext", 5, 1, 500 };
        soundEngineOffInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_shut_int", 1, 1 };
        soundEngineOffExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_shut_ext", 4, 1, 400 };
        class sounds {
            soundSets[] = {
                "Plane_Fighter_01_EngineLowExt_SoundSet",
                "Plane_Fighter_01_EngineHighExt_SoundSet",
                "Plane_Fighter_01_ForsageExt_SoundSet",
                "Plane_Fighter_01_WindNoiseExt_SoundSet",
                "Plane_Fighter_01_EngineExt_Dist_Front_SoundSet",
                "Plane_Fighter_01_EngineExt_Middle_SoundSet",
                "Plane_Fighter_01_EngineExt_Dist_Rear_SoundSet",
                "Plane_Fighter_01_EngineLowInt_SoundSet",
                "Plane_Fighter_01_EngineHighInt_SoundSet",
                "Plane_Fighter_01_ForsageInt_SoundSet",
                "Plane_Fighter_01_WindNoiseInt_SoundSet",
                "Plane_Fighter_01_VelocityInt_SoundSet"
            };
        };*/
        class UserActions {
            class F35_afterburner_on {
                displayName = "<t color = '#fb7904'>Afterburner On</t>";
                priority = 100;
                shortcut = "User1";
                condition = "((this animationPhase ""switch_afterburner"") isEqualTo 0) && (player in this) && (isEngineOn this) && (speed this > 5)";
                statement = QUOTE([this] call FUNC(afterburner););
                position = "pilotcontrol";
                radius = 10;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
            };            
            class F35_afterburner_off {
                displayName = "<t color = '#fb7904'>Afterburner Off</t>";
                shortcut = "User1";
                condition = QUOTE(((this animationPhase 'switch_afterburner') isEqualTo 1) && player in this);
                statement = "this animate [""switch_afterburner"",0];";
                position = "pilotcontrol";
                radius = 10;
                priority = 99;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
            };
            class DAS_ON {
                displayName = "(DAS) AESA OFF";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && (This getVariable [""USAF_DAS_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\DAS.sqf"";";
                onlyforplayer = "False";
            };
            class DAS_OFF: DAS_ON {
                displayName = "(DAS) AESA ON";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && !(this getVariable [""USAF_DAS_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\DAS.sqf"";";
                onlyforplayer = "False";
            };
            class VRD_ON {
                displayName = "(DAS) Spherical Coverage OFF";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && (This getVariable [""USAF_VRD_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\VRD.sqf"";";
                onlyforplayer = "False";
            };
            class VRD_OFF: VRD_ON {
                displayName = "(DAS) Spherical Coverage ON";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && !(this getVariable [""USAF_VRD_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\VRD.sqf"";";
                onlyforplayer = "False";
            };
            class ECM {
                displayName = "(EWS) Electronic Warfare System";
                onlyforplayer = 0;
                position = "pilotcontrol";
                radius = 25;
                showWindow = 0;
                condition = "player isEqualTo driver this";
                statement = "[this] execvm ""\USAF_F35A\scripts\ECM_INIT.sqf""";
            };
            class service_menu {
                displayName = "<t color = '#739eff'>Service Menu</t>";
                position = "pilotcontrol";
                onlyforplayer = 1;
                showWindow = 0;
                shortcut = "User4";
                priority = 100;
                hideOnUse = 1;
                radius = 5;
                condition = QUOTE([this] call FUNC(serviceCheck));
                statement = QUOTE(call FUNC(loadoutMenu));
            };
            class USAF_F35A_GPS_targeting_system {
                displayName = "(EOTS) Electro-Optical Targeting System";
                shortcut = "User3";
                position = "pilotcontrol";
                radius = 10;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
                condition = "player in this and ((""USAF_F35A_8Rnd_GBU53_M"" in magazines this) or (""USAF_1Rnd_GBU31"" in magazines this) or (""USAF_1Rnd_GBU32"" in magazines this) or (""USAF_1Rnd_AGM154A"" in magazines this) or (""USAF_1Rnd_GBU12"" in magazines this))";
                statement = "[this] spawn USAF_F35A_fnc_USAF_F35A_GPS_TARGETING_INIT";
            };
            class SEAD {
                displayName = "(SEAD) System";
                onlyforplayer = 0;
                position = "pilotcontrol";
                radius = 25;
                showWindow = 0;
                condition = "('USAF_1Rnd_AGM88' in magazines this)";
                statement = QUOTE([this] call FUNC(AGM88));
            };
            class formationLights {
                displayName = "Formation Lights On";
                position = "pilot";
                priority = 4;
                radius = 20;
                showWindow = 0;
                hideOnUse = 1;
                onlyforplayer = 1;
                condition = "player in this and this animationPhase ""FormationLights"" > 0.5";
                statement = "this animate [""FormationLights"",0];";
            };
            class unFormationLights {
                displayName = "Formation Lights Off";
                position = "pilot";
                priority = 4;
                radius = 20;
                showWindow = 0;
                hideOnUse = 1;
                onlyforplayer = 1;
                condition = "player in this and this animationPhase ""FormationLights"" < 0.5";
                statement = "this animate [""FormationLights"",1];";
            };
            delete retractrefueling;
            delete extendrefueling;
        };
        class EjectionSystem {
            EjectionSeatEnabled = 1;
            EjectionDual = 0;
            EjectionSeatClass = "USAF_F35A_ejection_seat";
            CanopyClass = "Plane_Fighter_01_Canopy_F";
            EjectionSeatHideAnim = "ejection_seat_hide";
            EjectionSeatRailAnim = "ejection_seat_motion";
            CanopyHideAnim = "canopy_hide";
            EjectionSeatPos = "eject_pos";
            CanopyPos = "eject_pos";
            EjectionSoundExt = "Plane_Fighter_01_ejection_ext_sound";
            EjectionSoundInt = "Plane_Fighter_01_ejection_in_sound";
            EjectionParachute = "Steerable_Parachute_F";
            EjectionSeatForce = 50;
            CanopyForce = 30;
        };
        // Wait until USAF release
        /*class Components: Components {
            class SensorsManagerComponent {
                class Components {
                    class IRSensorComponent: SensorTemplateIR {
                        class AirTarget {
                            minRange = 500;
                            maxRange = 2500;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            minRange = 500;
                            maxRange = 2000;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        angleRangeHorizontal = 360;
                        angleRangeVertical = 90;
                        maxTrackableSpeed = 400;
                    };
                    class VisualSensorComponent: SensorTemplateVisual {
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
                        angleRangeHorizontal = 26;
                        angleRangeVertical = 20;
                        maxTrackableSpeed = 100;
                        aimDown = 1;
                        animDirection = "mainGun";
                    };
                    class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {
                    };
                    class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
                        class AirTarget {
                            minRange = 15000;
                            maxRange = 15000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            minRange = 8000;
                            maxRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        typeRecognitionDistance = 8000;
                        angleRangeHorizontal = 45;
                        angleRangeVertical = 45;
                        groundNoiseDistanceCoef = 0.2;
                    };
                    class LaserSensorComponent: SensorTemplateLaser {
                    };
                    class NVSensorComponent: SensorTemplateNV {
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class EmptyDisplay {
                        componentType = "EmptyDisplayComponent";
                    };
                    class MinimapDisplay {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
                    class UAVDisplay {
                        componentType = "UAVFeedDisplayComponent";
                    };
                    class VehicleDriverDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Driver";
                    };
                    class VehicleMissileDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Missile";
                    };
                    class SensorDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        resource = "RscCustomInfoSensors";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                defaultDisplay = "SensorDisplay";
                class Components {
                    class EmptyDisplay {
                        componentType = "EmptyDisplayComponent";
                    };
                    class MinimapDisplay {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
                    class UAVDisplay {
                        componentType = "UAVFeedDisplayComponent";
                    };
                    class VehicleDriverDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Driver";
                    };
                    class VehicleMissileDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Missile";
                    };
                    class SensorDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        resource = "RscCustomInfoSensors";
                    };
                };
            };
            class TransportPylonsComponent {
                UIPicture = "\A3\Air_F_Jets\Plane_Fighter_01\Data\UI\Fighter_01_3DEN_CA.paa";
                class pylons {
                    class pylon1 {
                        hardpoints[] = { "B_BIM9X_RAIL", "B_BIM9X_DUAL_RAIL", "B_AMRAAM_D_RAIL", "B_AMRAAM_D_DUAL_RAIL", "B_AGM65_RAIL", "B_GBU12" };
                        attachment = "PylonRack_Missile_AMRAAM_D_x1";
                        priority = 12;
                        maxweight = 300;
                        UIposition[] = { 0.6, 0.45 };
                    };
                    class pylon2: pylon1 {
                        UIposition[] = { 0.05, 0.45 };
                        mirroredMissilePos = 1;
                    };
                    class pylon3 {
                        hardpoints[] = { "B_BIM9X_RAIL", "B_BIM9X_DUAL_RAIL", "B_AMRAAM_D_RAIL", "B_AMRAAM_D_DUAL_RAIL", "B_AGM65_RAIL", "B_AGM65_DUAL_RAIL", "B_GBU12", "B_GBU12_DUAL_RAIL" };
                        priority = 11;
                        attachment = "PylonRack_Missile_AGM_02_x2";
                        maxweight = 1050;
                        UIposition[] = { 0.55, 0.35 };
                    };
                    class pylon4: pylon3 {
                        UIposition[] = { 0.1, 0.35 };
                        mirroredMissilePos = 3;
                    };
                    class pylonBayRight1 {
                        hardpoints[] = { "B_BIM9X" };
                        priority = 10;
                        attachment = "PylonMissile_Missile_BIM9X_x1";
                        maxweight = 1200;
                        UIposition[] = { 0.5, 0.25 };
                        bay = 2;
                    };
                    class pylonBayLeft1: pylonBayRight1 {
                        UIposition[] = { 0.16, 0.25 };
                        mirroredMissilePos = 5;
                        bay = 1;
                    };
                    class pylonBayCenter1 {
                        hardpoints[] = { "B_AMRAAM_D_INT" };
                        priority = 9;
                        attachment = "PylonMissile_Missile_AMRAAM_D_INT_x1";
                        maxweight = 1200;
                        UIposition[] = { 0.33, 0.3 };
                        bay = 3;
                    };
                    class pylonBayCenter2: pylonBayCenter1 {
                        UIposition[] = { 0.33, 0.35 };
                        mirroredMissilePos = 7;
                    };
                    class pylonBayCenter3 {
                        hardpoints[] = { "B_AMRAAM_D_INT" };
                        priority = 7;
                        attachment = "";
                        maxweight = 1200;
                        UIposition[] = { 0.33, 0.4 };
                        bay = 3;
                    };
                    class pylonBayCenter4: pylonBayCenter3 {
                        UIposition[] = { 0.33, 0.45 };
                        mirroredMissilePos = 9;
                    };
                    class pylonBayCenter5 {
                        hardpoints[] = { "B_AMRAAM_D_INT", "B_GBU12" };
                        priority = 5;
                        attachment = "PylonMissile_Bomb_GBU12_x1";
                        maxweight = 1200;
                        UIposition[] = { 0.33, 0.5 };
                        bay = 3;
                    };
                    class pylonBayCenter6: pylonBayCenter5 {
                        UIposition[] = { 0.33, 0.55 };
                        mirroredMissilePos = 11;
                    };
                };
                class Bays {
                    class BayLeft1 {
                        bayOpenTime = 0.5;
                        openBayWhenWeaponSelected = 0;
                        autoCloseWhenEmptyDelay = 2;
                    };
                    class BayRight1 {
                        bayOpenTime = 0.5;
                        openBayWhenWeaponSelected = 0;
                        autoCloseWhenEmptyDelay = 2;
                    };
                    class BayCenter1 {
                        bayOpenTime = 0.5;
                        openBayWhenWeaponSelected = 0;
                        autoCloseWhenEmptyDelay = 4.5;
                    };
                };
                class Presets {
                    class Empty {
                        displayName = "Empty";
                        attachment[] = {};
                    };
                    class Default {
                        displayName = "Default";
                        attachment[] = { "PylonRack_Missile_AMRAAM_D_x1", "PylonRack_Missile_AMRAAM_D_x1", "PylonRack_Missile_AGM_02_x2", "PylonRack_Missile_AGM_02_x2", "PylonMissile_Missile_BIM9X_x1", "PylonMissile_Missile_BIM9X_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "", "", "PylonMissile_Bomb_GBU12_x1", "PylonMissile_Bomb_GBU12_x1" };
                    };
                    class AA {
                        displayName = "AA";
                        attachment[] = { "PylonRack_Missile_AMRAAM_D_x2", "PylonRack_Missile_AMRAAM_D_x2", "PylonRack_Missile_AMRAAM_D_x2", "PylonRack_Missile_AMRAAM_D_x2", "PylonMissile_Missile_BIM9X_x1", "PylonMissile_Missile_BIM9X_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1" };
                    };
                    class CAS {
                        displayName = "CAS";
                        attachment[] = { "PylonRack_Missile_AGM_02_x1", "PylonRack_Missile_AGM_02_x1", "PylonRack_Missile_AGM_02_x2", "PylonRack_Missile_AGM_02_x2", "PylonMissile_Missile_BIM9X_x1", "PylonMissile_Missile_BIM9X_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "PylonMissile_Missile_AMRAAM_D_INT_x1", "", "", "PylonMissile_Bomb_GBU12_x1", "PylonMissile_Bomb_GBU12_x1" };
                    };
                };
            };
        };*/
    };
    class B_Ejection_Seat_Plane_Fighter_01_F;
    class USAF_F35A_ejection_seat: B_Ejection_Seat_Plane_Fighter_01_F {
        faction = "CUP_B_GB";
        crew = "UKSF_B_Pilot_617";
        // model = "\usaf_f35A\usaf_f35A_ejection_seat.p3d";
    };
    class StaticAmmocart;
    class Missilecart_base: StaticAmmocart {
        faction = "CUP_B_GB";
        crew = "";
        editorSubcategory = QEGVAR(common,objects);
        class EventHandlers {
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
        };
    };
    class USAF_editorMissileObjects;
    class USAF_MK77: USAF_editorMissileObjects {
        icon = "";
    };
    class LaserTarget;
    class USAF_F35A_GPSTarget: LaserTarget {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        editorSubcategory = QEGVAR(common,objects);
    };
    class CUP_F35B_base: Plane {
        maxSpeed = 1930;
        envelope[] = { 0, 1.75, 5.9, 7, 9.8, 10.3, 10.5, 10.9, 9.2, 7.8, 5, 3.8, 0.5, 0 };
        aileronSensitivity = 1.2;
        armor = 90;
        damageResistance = 0.004;
        unitInfoType = "Rsc_UKSF_F35_Limited";
        unitInfoTypeLite = "Rsc_UKSF_F35_Limited";
        attenuationEffectType = "PlaneAttenuation";
        soundEngineOnInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_start_int", 1, 1 };
        soundEngineOnExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_start_ext", 5, 1, 500 };
        soundEngineOffInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_shut_int", 1, 1 };
        soundEngineOffExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_shut_ext", 4, 1, 400 };
        class sounds {
            soundSets[] = {
                "Plane_Fighter_01_EngineLowExt_SoundSet",
                "Plane_Fighter_01_EngineHighExt_SoundSet",
                "Plane_Fighter_01_ForsageExt_SoundSet",
                "Plane_Fighter_01_WindNoiseExt_SoundSet",
                "Plane_Fighter_01_EngineExt_Dist_Front_SoundSet",
                "Plane_Fighter_01_EngineExt_Middle_SoundSet",
                "Plane_Fighter_01_EngineExt_Dist_Rear_SoundSet",
                "Plane_Fighter_01_EngineLowInt_SoundSet",
                "Plane_Fighter_01_EngineHighInt_SoundSet",
                "Plane_Fighter_01_ForsageInt_SoundSet",
                "Plane_Fighter_01_WindNoiseInt_SoundSet",
                "Plane_Fighter_01_VelocityInt_SoundSet"
            };
        };
        class EjectionSystem {
            EjectionSeatEnabled = 1;
            EjectionDual = 0;
            EjectionSeatClass = "USAF_F35A_ejection_seat";
            CanopyClass = "Plane_Fighter_01_Canopy_F";
            EjectionSeatHideAnim = "ejection_seat_hide";
            EjectionSeatRailAnim = "ejection_seat_motion";
            CanopyHideAnim = "canopy_hide";
            EjectionSeatPos = "eject_pos";
            CanopyPos = "eject_pos";
            EjectionSoundExt = "Plane_Fighter_01_ejection_ext_sound";
            EjectionSoundInt = "Plane_Fighter_01_ejection_in_sound";
            EjectionParachute = "Steerable_Parachute_F";
            EjectionSeatForce = 50;
            CanopyForce = 30;
        };
    };
};
