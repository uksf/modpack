//Chinook
class Helicopter;
class Helicopter_Base_F : Helicopter {
    class Turrets {
        class MainTurret;
    };
};
class Helicopter_Base_H : Helicopter_Base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
    };
    class ViewOptics;
    class ViewPilot;
    class HitPoints;
};
class DEGA_BAF_CH47F_Unarmed : Helicopter_Base_H {
    scope = 0;
};
class DEGA_BAF_CH47F_M134 : Helicopter_Base_H {
    scope = 0;
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers {};
    };
};
class DEGA_BAF_CH47F_M134_M240 : Helicopter_Base_H {
    scope = 0;
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers {};
    };
};
class DEGA_US_CH47F_Unarmed : Helicopter_Base_H {
    scope = 0;
};
class DEGA_US_CH47F_M134 : Helicopter_Base_H {
    scope = 0;
};
class DEGA_US_CH47F_M134_M240 : Helicopter_Base_H {
    scope = 0;
};

class UKSF_Chinook_M134 : DEGA_BAF_CH47F_M134 {
    scope = 2;
    displayName = "CH-47 M134";
    faction = "UKSF_Clan";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Chinook_M134.jpg);
    slingLoadMaxCargoMass = 12000;
    armor = 60;
    damageResistance = 0.001;
    cyclicAsideForceCoef = 0.9;
    cyclicForwardForceCoef = 0.9;
    weapons[] = {
        "UK3CB_BAF_CMFlareLauncher",
        "UK3CB_BAF_IRJammer" };
    magazines[] = {
        "120Rnd_CMFlare_Chaff_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine" };
    unitInfoType = "Rsc_UKSF_Air_Limited";
    class HitPoints : HitPoints {
        class HitHull {
            armor = 1;
            material = 51;
            name = "trup";
            visual = "trup";
            passThrough = 1;
        };
        class HitEngine {
            armor = 1;
            material = 51;
            name = "motor";
            visual = "motor";
            passThrough = 1;
        };
        class HitAvionics {
            armor = 0.15000001;
            material = 51;
            name = "elektronika";
            visual = "elektronika";
            passThrough = 1;
        };
        class HitVRotor {
            armor = 0.30000001;
            material = 51;
            name = "mala vrtule";
            visual = "mala vrtule";
            passThrough = 0.30000001;
        };
        class HitHRotor {
            armor = 0.2;
            material = 51;
            name = "velka vrtule";
            visual = "velka vrtule";
            passThrough = 0.1;
        };
    };
    class TransportBackpacks {};
    class TransportItems {};
    class ViewPilot : ViewOptics {
        initFov = 1;
        minFov = 0.30000001;
        maxFov = 1.2;
        initAngleX = 0;
        minAngleX = -75;
        maxAngleX = 85;
        initAngleY = 0;
        minAngleY = -170;
        maxAngleY = 170;
        minMoveX = -0.34999999;
        maxMoveX = 0.34999999;
        minMoveY = -0.025;
        maxMoveY = 0.2;
        minMoveZ = -0.30000001;
        maxMoveZ = 0.55000001;
    };
    class Useractions {
        class Open_Hatch {
            displayName = "<t color='#008000'>Open Hatch</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Hatch"" < 0.5 && (player == (driver this) or player == (gunner this));";
            statement = "[[this,[[""Hatch"",1]],true,[27,28,29,30,31,32,33,34,35,36,37],[]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            priority = 14;
        };
        class Close_Hatch {
            displayName = "<t color='#008000'>Close Hatch</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Hatch"" > 0.5 && (player == (driver this) or player == (gunner this));";
            statement = "[[this,[[""Hatch"",0]],false,[27,28,29,30,31,32,33,34,35,36,37],[]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            priority = 14;
        };
        class COmfdpip1ON {
            displayName = "<t color='#ffff00'>Turn On FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip"" < 0.5 AND (player == (gunner this) && (alive this))";
            statement = "this animate [""copip"",1];";
            priority = 15;
        };
        class COmfdpip1OFF {
            displayName = "<t color='#ffff00'>Turn Off FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip"" > 0.5 AND (player == (gunner this) && (alive this))";
            statement = "this animate [""copip"",0];";
            priority = 15;
        };
        class Pimfdpip1ON {
            displayName = "<t color='#ffff00'>Turn On FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip1"" < 0.5 AND (player == (driver this) && (alive this))";
            statement = "this animate [""copip1"",1];";
            priority = 15;
        };
        class Pimfdpip1OFF {
            displayName = "<t color='#ffff00'>Turn Off FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip1"" > 0.5 AND (player == (driver this) && (alive this))";
            statement = "this animate [""copip1"",0];";
            priority = 15;
        };
        class OpenCargoDoor {
            displayName = "<t color='#FF0000'>Open Ramp</t>";
            position = "actions";
            radius = 12;
            showwindow = 0;
            condition = "this animationPhase ""Ramp"" < 1 and (((player == (driver this) or player == (gunner this))) && (alive this));";
            statement = "this animate [""Ramp"", 1];";
            onlyforplayer = 1;
            priority = 14;
        };
        class CloseCargoDoor {
            displayName = "<t color='#FF0000'>Close Ramp</t>";
            position = "actions";
            radius = 12;
            showwindow = 0;
            condition = "this animationPhase ""Ramp"" > 0 and (((player == (driver this) or player == (gunner this))) && (alive this));";
            statement = "this animate [""Ramp"", 0];";
            onlyforplayer = 1;
            priority = 14;
        };
        class LevelCargoDoor {
            displayName = "<t color='#FF0000'>Level Ramp</t>";
            position = "actions";
            radius = 13;
            condition = "((this animationPhase ""Ramp"" < 0.3) || (this animationPhase ""Ramp"" > 0.5)) && ((this animationPhase ""Ramp"" == 0 || this animationPhase ""Ramp"" == 1)) && (((player == (driver this) or player == (gunner this))) && (alive this))";
            statement = "this animate[""Ramp"",0.640]";
            onlyforplayer = 0;
            priority = 13;
            showWindow = 0;
        };
        class Fold_Seating {
            displayName = "<t color='#008000'>Fold Seats</t>";
            position = "actions";
            radius = 12;
            showwindow = 0;
            condition = "this animationPhase ""Left_LockCargo"" == 0 && ((this getCargoIndex player) isEqualTo 1);";
            statement = "[[this,[[""Left_LockCargo"", 1],[""Right_LockCargo"", 1]],true,[2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25],[]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            onlyforplayer = 1;
            priority = 15;
        };
        class UnFold_Seating {
            displayName = "<t color='#008000'>Unfold Seats</t>";
            position = "actions";
            radius = 12;
            showwindow = 0;
            condition = "this animationPhase ""Left_LockCargo"" > 0 && ((this getCargoIndex player) isEqualTo 1) && ((this animationPhase ""Stretchers_deploy"" == 1));";
            statement = "[[this,[[""Left_LockCargo"", 0],[""Right_LockCargo"", 0]],false,[2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25],[]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            onlyforplayer = 1;
            priority = 15;
        };
        class Remove_PilotDoors {
            displayName = "<t color='#008000'>Remove Pilot Doors</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Pilot_doors"" < 0.5 && ((this getCargoIndex player) isEqualTo 1);";
            statement = "this animate [""Pilot_doors"",1]; this animate [""Pilot_doors_stored"",0];";
            priority = 13;
        };
        class Add_PilotDoors {
            displayName = "<t color='#008000'>Add Pilot Doors</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Pilot_doors"" > 0.5 && ((this getCargoIndex player) isEqualTo 1);";
            statement = "this animate [""Pilot_doors"",0]; this animate [""Pilot_doors_stored"",1];";
            priority = 13;
        };
        class UnDeploy_stretchers {
            displayName = "<t color='#008000'>Remove Stretchers</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Stretchers_deploy"" < 0.5 && ((this getCargoIndex player) isEqualTo 1) && ((this animationPhase ""Left_LockCargo"" == 1)) && ((this animationPhase ""Right_LockCargo"" == 1));";
            statement = "[[this,[[""Stretchers_deploy"",1],[""Stretchers_Undeploy"",0]],true,[],[5,6,7,8]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            priority = 12;
        };
        class Deploy_stretchers {
            displayName = "<t color='#008000'>Deploy Stretchers</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Stretchers_deploy"" > 0.5 && ((this getCargoIndex player) isEqualTo 1) && ((this animationPhase ""Left_LockCargo"" == 1)) && ((this animationPhase ""Right_LockCargo"" == 1));";
            statement = "[[this,[[""Stretchers_deploy"",0],[""Stretchers_Undeploy"",1]],false,[],[5,6,7,8]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            priority = 12;
        };
        class Pilot_Smoke_Grenade {
            displayName = "<t color='#FFFFFF'>Drop Smoke Grenade Right</t>";
            displayNameDefault = "";
            showwindow = 0;
            position = "";
            radius = 2;
            onlyForPlayer = 1;
            condition = "(player == (driver this) && (alive this)) AND this animationPhase ""Pilot_doors"" == 1";
            statement = "[this,""right_copilotsmoke""] spawn DEGA_fnc_dropSmoke;";
            priority = 12;
        };
        class COPilot_Smoke_Grenade {
            displayName = "<t color='#FFFFFF'>Drop Smoke Grenade Left</t>";
            displayNameDefault = "";
            showwindow = 0;
            position = "";
            radius = 2;
            onlyForPlayer = 1;
            condition = "(player == (gunner this) && (alive this)) AND this animationPhase ""Pilot_doors"" == 1";
            statement = "[this,""left_pilotsmoke""] spawn DEGA_fnc_dropSmoke;";
            priority = 12;
        };
    };
    #include "MFDChinook.hpp"
    class pilotCamera {
        class OpticsIn {
            class Wide {
                opticsDisplayName = "W";
                initAngleX = 0;
                minAngleX = 0;
                maxAngleX = 0;
                initAngleY = 0;
                minAngleY = 0;
                maxAngleY = 0;
                initFov = 0.6;
                minFov = 0.6;
                maxFov = 0.6;
                visionMode[] = { "Normal" };
                gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
            };
            showMiniMapInOptics = 1;
            showUAVViewpInOptics = 1;
            showSlingLoadManagerInOptics = 1;
        };
        minTurn = 0;
        maxTurn = 0;
        initTurn = 0;
        minElev = 80;
        maxElev = 80;
        initElev = 80;
        maxXRotSpeed = 0.5;
        maxYRotSpeed = 0.5;
        pilotOpticsShowCursor = 1;
        controllable = 0;
    };
    ace_fastroping_enabled = 1;
    ace_fastroping_ropeOrigins[] = {
        { -0.8, -7.5, 0.95 },
        { 0.8, -7.5, 0.95 } };
    #include "SoundsChinook.hpp"
    class ACRE {
        class CVC {
            hasCVC = 1;
        };
    };
};
class UKSF_Chinook_M134M240 : DEGA_BAF_CH47F_M134_M240 {
    scope = 2;
    displayName = "CH-47 M134/M240";
    faction = "UKSF_Clan";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Chinook_M134M240.jpg);
    slingLoadMaxCargoMass = 12000;
    armor = 60;
    damageResistance = 0.001;
    cyclicAsideForceCoef = 0.9;
    cyclicForwardForceCoef = 0.9;
    weapons[] = {
        "UK3CB_BAF_CMFlareLauncher",
        "UK3CB_BAF_IRJammer" };
    magazines[] = {
        "120Rnd_CMFlare_Chaff_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine",
        "UK3CB_BAF_IRJammer_Magazine"
    };
    unitInfoType = "Rsc_UKSF_Air_Limited";
    class HitPoints : HitPoints {
        class HitHull {
            armor = 1;
            material = 51;
            name = "trup";
            visual = "trup";
            passThrough = 1;
        };
        class HitEngine {
            armor = 1;
            material = 51;
            name = "motor";
            visual = "motor";
            passThrough = 1;
        };
        class HitAvionics {
            armor = 0.15000001;
            material = 51;
            name = "elektronika";
            visual = "elektronika";
            passThrough = 1;
        };
        class HitVRotor {
            armor = 0.30000001;
            material = 51;
            name = "mala vrtule";
            visual = "mala vrtule";
            passThrough = 0.30000001;
        };
        class HitHRotor {
            armor = 0.2;
            material = 51;
            name = "velka vrtule";
            visual = "velka vrtule";
            passThrough = 0.1;
        };
    };
    class TransportBackpacks {};
    class TransportItems {};
    class ViewPilot : ViewOptics {
        initFov = 1;
        minFov = 0.30000001;
        maxFov = 1.2;
        initAngleX = 0;
        minAngleX = -75;
        maxAngleX = 85;
        initAngleY = 0;
        minAngleY = -170;
        maxAngleY = 170;
        minMoveX = -0.34999999;
        maxMoveX = 0.34999999;
        minMoveY = -0.025;
        maxMoveY = 0.2;
        minMoveZ = -0.30000001;
        maxMoveZ = 0.55000001;
    };
    class Useractions {
        class Open_Hatch {
            displayName = "<t color='#008000'>Open Hatch</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Hatch"" < 0.5 && (player == (driver this) or player == (gunner this));";
            statement = "[[this,[[""Hatch"",1]],true,[27,28,29,30,31,32,33,34,35,36,37],[]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            priority = 14;
        };
        class Close_Hatch {
            displayName = "<t color='#008000'>Close Hatch</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Hatch"" > 0.5 && (player == (driver this) or player == (gunner this));";
            statement = "[[this,[[""Hatch"",0]],false,[27,28,29,30,31,32,33,34,35,36,37],[]], ""DEGA_fnc_deploySeats"", this] call BIS_fnc_MP;";
            priority = 14;
        };
        class COmfdpip1ON {
            displayName = "<t color='#ffff00'>Turn On FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip"" < 0.5 AND (player == (gunner this) && (alive this))";
            statement = "this animate [""copip"",1];";
            priority = 15;
        };
        class COmfdpip1OFF {
            displayName = "<t color='#ffff00'>Turn Off FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip"" > 0.5 AND (player == (gunner this) && (alive this))";
            statement = "this animate [""copip"",0];";
            priority = 15;
        };
        class Pimfdpip1ON {
            displayName = "<t color='#ffff00'>Turn On FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip1"" < 0.5 AND (player == (driver this) && (alive this))";
            statement = "this animate [""copip1"",1];";
            priority = 15;
        };
        class Pimfdpip1OFF {
            displayName = "<t color='#ffff00'>Turn Off FLIR MFD</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""copip1"" > 0.5 AND (player == (driver this) && (alive this))";
            statement = "this animate [""copip1"",0];";
            priority = 15;
        };
        class Remove_PilotDoors {
            displayName = "<t color='#008000'>Remove Pilot Doors</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Pilot_doors"" < 0.5 && ((this getCargoIndex player) isEqualTo 0);";
            statement = "this animate [""Pilot_doors"",1]; this animate [""Pilot_doors_stored"",0];";
            priority = 7;
        };
        class Add_PilotDoors {
            displayName = "<t color='#008000'>Add Pilot Doors</t>";
            displayNameDefault = "";
            position = "";
            radius = 3.5999999;
            onlyForplayer = 1;
            condition = "this animationPhase ""Pilot_doors"" > 0.5 && ((this getCargoIndex player) isEqualTo 0);";
            statement = "this animate [""Pilot_doors"",0]; this animate [""Pilot_doors_stored"",1];";
            priority = 7;
        };
        class Pilot_Smoke_Grenade {
            displayName = "<t color='#FFFFFF'>Drop Smoke Grenade Right</t>";
            displayNameDefault = "";
            showwindow = 0;
            position = "";
            radius = 2;
            onlyForPlayer = 1;
            condition = "(player == (driver this) && (alive this)) AND this animationPhase ""Pilot_doors"" == 1";
            statement = "[this,""right_copilotsmoke""] spawn DEGA_fnc_dropSmoke;";
            priority = 7;
        };
        class COPilot_Smoke_Grenade {
            displayName = "<t color='#FFFFFF'>Drop Smoke Grenade Left</t>";
            displayNameDefault = "";
            showwindow = 0;
            position = "";
            radius = 2;
            onlyForPlayer = 1;
            condition = "(player == (gunner this) && (alive this)) AND this animationPhase ""Pilot_doors"" == 1";
            statement = "[this,""left_pilotsmoke""] spawn DEGA_fnc_dropSmoke;";
            priority = 7;
        };
    };
    #include "MFDChinook.hpp"
    class pilotCamera {
        class OpticsIn {
            class Wide {
                opticsDisplayName = "W";
                initAngleX = 0;
                minAngleX = 0;
                maxAngleX = 0;
                initAngleY = 0;
                minAngleY = 0;
                maxAngleY = 0;
                initFov = 0.6;
                minFov = 0.6;
                maxFov = 0.6;
                visionMode[] = { "Normal" };
                gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
            };
            showMiniMapInOptics = 1;
            showUAVViewpInOptics = 1;
            showSlingLoadManagerInOptics = 1;
        };
        minTurn = 0;
        maxTurn = 0;
        initTurn = 0;
        minElev = 80;
        maxElev = 80;
        initElev = 80;
        maxXRotSpeed = 0.5;
        maxYRotSpeed = 0.5;
        pilotOpticsShowCursor = 1;
        controllable = 0;
    };
    ace_fastroping_enabled = 1;
    ace_fastroping_ropeOrigins[] = {
        { -0.9, -7, -0.8 },
        { 0.9, -7, -0.8 } };
    #include "SoundsChinook.hpp"
    class CargoTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            isCopilot = 0;
            CanEject = 1;
            body = "mainTurret";
            gun = "mainGun";
            minElev = -50;
            maxElev = +30;
            initElev = -30;
            minTurn = -3;
            maxTurn = 173;
            initTurn = 0;
            soundServo[] = { , db - 40, 1.0 };
            animationSourceHatch = "";
            stabilizedInAxes = StabilizedInAxesNone;
            gunBeg = "muzzle_1";
            gunEnd = "chamber_1";
            weapons[] = {
                "M134_minigun_1",
                "UK3CB_BAF_CMFlareLauncher",
                "UK3CB_BAF_IRJammer" };
            magazines[] = {
                "5000Rnd_762x51_Belt",
                "120Rnd_CMFlare_Chaff_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine" };
            gunnerName = "Left Door Gunner";
            gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
            gunnerOutOpticsShowCursor = 1;
            gunnerOpticsShowCursor = 1;
            gunnerAction = "CH47_Gunner_EP1";
            gunnerInAction = "CH47_Gunner_EP1";
            commanding = -1;
            primaryGunner = 0;
            class ViewOptics {
                initAngleX = 0;
                minAngleX = -30;
                maxAngleX = +30;
                initAngleY = 0;
                minAngleY = -100;
                maxAngleY = +100;
                initFov = 0.7;
                minFov = 0.25;
                maxFov = 1.1;
            };
            gunnerCompartments = Compartment1;
            memoryPointsGetInGunner = "pos cargo";
            memoryPointsGetInGunnerDir = "pos cargo dir";
        };
        class CopilotTurret : CopilotTurret {
            body = "FLIR_turret";
            gun = "FLIR_gun";
            animationSourceBody = "FLIR_turret";
            animationSourceGun = "FLIR_gun";
            memoryPointGunnerOptics = "FLIR_end";
            gunBeg = "FLIR_end";
            gunEnd = "FLIR_begin";
            memoryPointGun = "FLIR_end";
            stabilizedInAxes = 3;
            inGunnerMayFire = true;
            gunnerOpticsEffect[] = {};
            gunnerOpticsModel = "";
            isCopilot = 1;
            turretInfoType = "RscOptics_UAV_gunner";
            weapons[] = { "Laserdesignator_mounted" };
            magazines[] = { Laserbatteries };
            proxyType = CPGunner;
            minElev = -40;
            maxElev = +20;
            initElev = 0;
            minTurn = -120;
            maxTurn = 120;
            initTurn = 0;
            gunnerForceOptics = false;
            selectionFireAnim = "";
            CanEject = 0;
            gunnerAction = "CH47_Pilot_EP1";
            gunnerInAction = "CH47_Pilot_EP1";
            memoryPointsGetInGunner = "pos cargo";
            memoryPointsGetInGunnerDir = "pos cargo dir";
            gunnerGetInAction = "GetInHeli_Transport_01Cargo";
            gunnerGetOutAction = "GetOutLow";
            gunnerName = "Co-Pilot";
            preciseGetInOut = 0;
            GunnerDoor = "";
            gunnerLeftHandAnimName = "lever_copilot";
            gunnerRightHandAnimName = "stick_copilot";
            gunnerLeftLegAnimName = "";
            gunnerRightLegAnimName = "";
            proxyIndex = 30;
            LODTurnedIn = 1100;
            LODTurnedOut = 1100;
            gunnerCompartments = "Compartment1";
            commanding = -3;
            primaryGunner = 1;
            class OpticsIn {
                class WideNGS {
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
                    visionMode[] = { "Normal", "NVG", "Ti" };
                    thermalMode[] = { 0, 1 };
                    gunnerOpticsColor[] = { 0.15000001, 1, 0.15000001, 1 };
                    gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
                    directionStabilized = 0;
                    opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
                };
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
                    visionMode[] = { "Normal", "NVG", "Ti" };
                    thermalMode[] = { 0, 1 };
                    gunnerOpticsColor[] = { 0.15000001, 1, 0.15000001, 1 };
                    gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
                    //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                    directionStabilized = 1;
                    opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
                    gunnerOpticsEffect[] = { "TankCommanderOptics1" };
                };
                class WideL : Wide {
                    opticsDisplayName = "WL";
                    initFov = 0.2;
                    minFov = 0.2;
                    maxFov = 0.2;
                    //gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
                    //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                    gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
                    gunnerOpticsColor[] = { 0, 0, 0, 1 };
                    directionStabilized = 1; // Camera Stabilizing Boolean
                    opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
                };
                class Medium : Wide {
                    opticsDisplayName = "M";
                    initFov = 0.1;
                    minFov = 0.1;
                    maxFov = 0.1;
                    directionStabilized = 1; // Camera Stabilizing Boolean
                    gunnerOpticsColor[] = { 0, 0, 0, 1 };
                    //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
                    gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
                };
                class Narrow : Wide {
                    opticsDisplayName = "N";
                    gunnerOpticsColor[] = { 0, 0, 0, 1 };
                    gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
                    //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                    directionStabilized = 1; // Camera Stabilizing Boolean
                    initFov = 0.02;
                    minFov = 0.02;
                    maxFov = 0.02;
                };
                class Narrower : Wide {
                    opticsDisplayName = "N";
                    gunnerOpticsColor[] = { 0, 0, 0, 1 };
                    gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
                    //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
                    directionStabilized = 1; // Camera Stabilizing Boolean
                    initFov = 0.01;
                    minFov = 0.01;
                    maxFov = 0.01;
                };
            };
            class OpticsOut {
                class Monocular // 1x-3.5x
                {
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = +30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = +100;
                    initFov = 1.1;
                    minFov = 0.133;
                    maxFov = 1.1;
                    visionMode[] = { "Normal", "NVG" };
                    gunnerOpticsModel = "";
                    gunnerOpticsEffect[] = {};
                };
            };
            gunnerHasFlares = true;
        };
        class RightDoorGun : MainTurret {
            isCopilot = 0;
            CanEject = 1;
            body = "Turret2";
            gun = "Gun_2";

            gunnerCompartments = "Compartment1";

            minElev = -60;
            maxElev = +30;
            initElev = -30;
            minTurn = -173;
            maxTurn = 3;
            initTurn = 0;
            animationSourceBody = "Turret_2";
            animationSourceGun = "Gun_2";
            stabilizedInAxes = StabilizedInAxesNone;
            selectionFireAnim = "zasleh_1";
            proxyIndex = 2;
            gunnerName = "Right Door Gunner";
            commanding = -2;
            weapons[] = {
                "M134_minigun_1",
                "UK3CB_BAF_CMFlareLauncher",
                "UK3CB_BAF_IRJammer" };
            magazines[] = {
                "5000Rnd_762x51_Belt",
                "120Rnd_CMFlare_Chaff_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine" };
            gunBeg = "muzzle_2";  //gunBeg=endpoint of the gun
            gunEnd = "chamber_2"; //gunEnd=chamber of the gun
            primaryGunner = 0;
            memoryPointGun = "machinegun_2";
            memoryPointGunnerOptics = "gunnerview_2";
        };
        class BackDoorGun : MainTurret {
            isCopilot = 0;
            CanEject = 1;
            body = "Turret3";
            gun = "Gun_3";
            minTurn = 90;
            maxTurn = 270;
            initTurn = 180;
            minElev = -50;
            maxElev = +50;
            initElev = 0;
            animationSourceBody = "Turret_3";
            animationSourceGun = "Gun_3";
            stabilizedInAxes = StabilizedInAxesNone;
            selectionFireAnim = "zasleh_3";

            gunnerCompartments = "Compartment1";

            proxyIndex = 3;
            gunnerName = "Rear Gunner";
            gunnerOpticsShowCursor = 0;

            commanding = -1;
            gunnerAction = "CH47_Gunner01_EP1";
            gunnerInAction = "CH47_Gunner01_EP1";

            weapons[] = {
                "M240_delta_chinook",
                "UK3CB_BAF_CMFlareLauncher",
                "UK3CB_BAF_IRJammer" };
            magazines[] = {
                "100Rnd_762x51_M240_delta_chinook",
                "100Rnd_762x51_M240_delta_chinook",
                "100Rnd_762x51_M240_delta_chinook",
                "100Rnd_762x51_M240_delta_chinook",
                "100Rnd_762x51_M240_delta_chinook",
                "120Rnd_CMFlare_Chaff_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine",
                "UK3CB_BAF_IRJammer_Magazine" };

            gunBeg = "muzzle_3";  //gunBeg=endpoint of the gun
            gunEnd = "chamber_3"; //gunEnd=chamber of the gun

            primaryGunner = 0;
            memoryPointGun = "machinegun_3";
            memoryPointGunnerOptics = "gunnerview_3";
            class ACRE {
                class CVC {
                    hasCVC = 1;
                };
            };
        };
        class CargoTurret_03 : CargoTurret {
            gunnerAction = "passenger_inside_4";
            gunnerCompartments = "Compartment1";
            memoryPointsGetInGunner = "pos Cargo 2";
            memoryPointsGetInGunnerDir = "pos Cargo 2 dir";
            gunnerName = "Passenger (Crew Chief)";
            proxyIndex = 39;
            maxElev = 40;
            minElev = -5;
            maxTurn = 90;
            minTurn = -90;
            isPersonTurret = 1;
            ejectDeadGunner = 0;
            enabledByAnimationSource = "";
            usepip = 0;
            gunnerOutOpticsModel = "";
            gunnerOpticsModel = "";
            startEngine = 0;
            commanding = -1;
            outGunnerMayFire = 1;
            inGunnerMayFire = 0;
            soundAttenuationTurret = "";
            disableSoundAttenuation = 0;
            memoryPointGunnerOptics = "";
        };
    };
    class ACRE {
        class CVC {
            hasCVC = 1;
        };
    };
};