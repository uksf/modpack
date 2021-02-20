class CUP_C130J_Base : Plane_Base_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class GVAR(C130_Base) : CUP_C130J_Base {
    side = 1;
    faction = "CUP_B_GB";
    memoryPointsGetInCargo = "pos cargo";
    memoryPointsGetInCargoDir = "pos cargo dir";
    ace_cookoff_cookoffSelections[] = { "palivo" };
    unitInfoType = "RscUnitInfoAirPlaneNoSpeed";
    unitInfoTypeLite = "RscUnitInfoAirPlaneNoSpeed";
    maximumLoad = 2500;
    altFullForce = 7000;
    altNoForce = 10000;
    wheelSteeringSensitivity = 5;
    stallSpeed = 180;
    stallWarningTreshold = 0.5;
    flapsFrictionCoef = 0.5;
    aileronSensitivity = 1;
    aileronCoef[] = { 0, 0.5, 0.9, 1, 1.05, 1.1, 1.12 };
    elevatorSensitivity = 1.1;
    elevatorCoef[] = { 0, 0.4, 0.9, 1, 1.05, 1.1, 1.15 };
    //rudderInfluence = 1;
    rudderCoef[] = { 0, 0.8, 1.5, 1.9, 2.2, 2.4, 2.5, 2.5, 2.6, 2.6, 2.6 };
    aileronControlsSensitivityCoef = 1;
    elevatorControlsSensitivityCoef = 2;
    rudderControlsSensitivityCoef = 1;
    draconicForceXCoef = 10;
    draconicForceYCoef = 0;
    draconicForceZCoef = 0;
    draconicTorqueXCoef[] = { 22, 21.5, 21, 20.5, 20, 20, 20.5, 21, 22, 23, 24 };
    draconicTorqueYCoef[] = { 1, 1.2, 1.4, 2, 4, 7, 6.8, 6.6, 6.4, 6.2, 5.5, 5, 4.5, 3.9, 3, 1 };
    maxOmega = 2000;
    soundGetIn[] = { QPATHTOF(data\c130\sounds\close),1,1 };
    soundGetOut[] = { QPATHTOF(data\c130\sounds\open),1,1,40 };
    soundDammage[] = { QPATHTOF(data\c130\sounds\int_alarm_loop),0.56234133,1 };
    soundEngineOnInt[] = { QPATHTOF(data\c130\sounds\int_start_1),1,1 };
    soundEngineOnExt[] = { QPATHTOF(data\c130\sounds\ext_start_1),1.41254,1,700 };
    soundEngineOffInt[] = { QPATHTOF(data\c130\sounds\int_stop_1),1,1 };
    soundEngineOffExt[] = { QPATHTOF(data\c130\sounds\ext_stop_1),1.41254,1,700 };
    soundIncommingMissile[] = { "\A3\Sounds_F\weapons\Rockets\locked_3", 1, 1.5 };
    class Sounds {
        class EngineLowOut {
            sound[] = { QPATHTOF(data\c130\sounds\ext_engine_low),2.7782794,1,900 };
            frequency = "1.0 min (rpm + 0.5)";
            volume = "camPos*engineOn*(rpm factor[0.85, 0])";
        };
        class EngineHighOut {
            sound[] = { QPATHTOF(data\c130\sounds\ext_engine_hi),2.7782794,1,1100 };
            frequency = "1";
            volume = "camPos*engineOn*(rpm factor[0.55, 1.0])";
        };
        class ForsageOut {
            sound[] = { QPATHTOF(data\c130\sounds\ext_forsage_1),2.4125376,1,1500 };
            frequency = "1";
            volume = "camPos*engineOn*(thrust factor[0.5, 1.0])";
            cone[] = { 1.14, 3.9200001, 2, 0.4 };
        };
        class WindNoiseOut {
            sound[] = { QPATHTOF(data\c130\sounds\ext_wind1),0.001,0.6,150 };
            frequency = "(0.1+(1.2*(speed factor[1, 100])))";
            volume = "camPos*(speed factor[1, 100])";
        };
        class EngineLowIn {
            sound[] = { QPATHTOF(data\c130\sounds\int_engine_low),1,1 };
            frequency = "1.0 min (rpm + 0.5)";
            volume = "(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
        };
        class EngineHighIn {
            sound[] = { QPATHTOF(data\c130\sounds\int_engine_hi),1,1 };
            frequency = "1";
            volume = "(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
        };
        class ForsageIn {
            sound[] = { QPATHTOF(data\c130\sounds\int_forsage_1),2.4125376,1.1 };
            frequency = "1";
            volume = "(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
        };
        class WindNoiseIn {
            sound[] = { QPATHTOF(data\c130\sounds\int_wind1),0.001,0.6 };
            frequency = "(0.1+(1.2*(speed factor[1, 100])))";
            volume = "(1-camPos)*(speed factor[1, 100])";
        };
    };
    driveOnComponent[] = {};
    class Wheels {
        disableWheelsWhenDestroyed = 1;
        class Wheel_1_1 {
            steering = true;
            side = "left";
            boneName = "Wheel_1_1";
            center = "Wheel_1_1_center";
            boundary = "Wheel_1_1_rim";
            width = 0.16;
            mass = 150;
            MOI = 3;
            dampingRate = 0.1;
            dampingRateDamaged = 1;
            dampingRateDestroyed = 1000;
            maxBrakeTorque = 2000;
            maxHandBrakeTorque = 0;
            suspTravelDirection[] = { 0, -1, 0 };
            suspForceAppPointOffset = "Wheel_1_1_center";
            tireForceAppPointOffset = "Wheel_1_1_center";
            maxCompression = 0.15;
            maxDroop = 0.15;
            sprungMass = 6400;
            springStrength = 120000;
            springDamperRate = 128000;
            longitudinalStiffnessPerUnitGravity = 5000;
            latStiffX = 25;
            latStiffY = 180;
            frictionVsSlipGraph[] = { { 0, 1 }, { 0.5, 1 }, { 1, 1 } };
        };
        class Wheel_1_1_fake : Wheel_1_1 {};
        class Wheel_2_1 : Wheel_1_1 {
            steering = false;
            boneName = "Wheel_2_1";
            center = "Wheel_2_1_center";
            boundary = "Wheel_2_1_rim";
            suspForceAppPointOffset = "Wheel_2_1_center";
            tireForceAppPointOffset = "Wheel_2_1_center";
            width = 0.28;
            maxCompression = 0.15;
            maxDroop = 0.15;
            sprungMass = 3200;
            springDamperRate = 51200;
            springStrength = 1580000;
        };
        class Wheel_2_2 : Wheel_2_1 {
            side = "right";
            boneName = "Wheel_2_2";
            center = "Wheel_2_2_center";
            boundary = "Wheel_2_2_rim";
            suspForceAppPointOffset = "Wheel_2_2_center";
            tireForceAppPointOffset = "Wheel_2_2_center";
        };
        class Wheel_3_1 : Wheel_2_1 {
            boneName = "Wheel_3_1";
            center = "Wheel_3_1_center";
            boundary = "Wheel_3_1_rim";
            suspForceAppPointOffset = "Wheel_3_1_center";
            tireForceAppPointOffset = "Wheel_3_1_center";
        };
        class Wheel_3_2 : Wheel_3_1 {
            side = "right";
            boneName = "Wheel_3_2";
            center = "Wheel_3_2_center";
            boundary = "Wheel_3_2_rim";
            suspForceAppPointOffset = "Wheel_3_2_center";
            tireForceAppPointOffset = "Wheel_3_2_center";
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            primaryGunner = 1;
            isCopilot = 1;
            showHMD = 1;
            class ViewGunner {
                initFov = 1;
                minFov = 0.3;
                maxFov = 1.2;
                initAngleX = 0;
                minAngleX = -75;
                maxAngleX = 85;
                initAngleY = 0;
                minAngleY = -170;
                maxAngleY = 170;
                minMoveX = -0.2;
                maxMoveX = 0.2;
                minMoveY = -0.025;
                maxMoveY = 0.1;
                minMoveZ = -0.2;
                maxMoveZ = 0.2;
                speedZoomMaxSpeed = 0;
                speedZoomMaxFOV = 1;
            };
            class ViewPilot {
                initFov = 1;
                minFov = 0.3;
                maxFov = 1.2;
                initAngleX = 0;
                minAngleX = -75;
                maxAngleX = 85;
                initAngleY = 0;
                minAngleY = -170;
                maxAngleY = 170;
                minMoveX = -0.2;
                maxMoveX = 0.2;
                minMoveY = -0.025;
                maxMoveY = 0.1;
                minMoveZ = -0.2;
                maxMoveZ = 0.2;
                speedZoomMaxSpeed = 0;
                speedZoomMaxFOV = 1;
            };
            class OpticsOut {
                class Monocular {
                    initFov = 1;
                    minFov = 0.3;
                    maxFov = 1.2;
                    initAngleX = 0;
                    minAngleX = -75;
                    maxAngleX = 85;
                    initAngleY = 0;
                    minAngleY = -170;
                    maxAngleY = 170;
                    minMoveX = -0.2;
                    maxMoveX = 0.2;
                    minMoveY = -0.025;
                    maxMoveY = 0.1;
                    minMoveZ = -0.2;
                    maxMoveZ = 0.2;
                    speedZoomMaxSpeed = 0;
                    speedZoomMaxFOV = 1;
                    visionMode[] = { "Normal", "NVG" };
                    gunnerOpticsModel = "";
                    gunnerOpticsEffect[] = {};
                    directionStabilized = 0;
                };
            };
            speedZoomMaxSpeed = 0;
            speedZoomMaxFOV = 1;
#include "MFDC130.hpp"
        };
    };
    delete CarrierOpsCompatability;
    CatapultExclude = 1;
    INVENTORY_AIRCRAFT;
#include "MFDC130.hpp"
};
class GVAR(C130_VIV_Base) : GVAR(C130_Base) {
    displayName = "C-130J (VIV)";
    model = "CUP\AirVehicles\CUP_AirVehicles_C130J\CUP_c130j_Cargo.p3d";
    transportSoldier = 1;
    class VehicleTransport {
        class Carrier {
            cargoBayDimensions[] = { "VTV_limit_1", "VTV_limit_2" };
            disableHeightLimit = 0;
            maxLoadMass = 20000;
            cargoAlignment[] = { "center", "front" };
            cargoSpacing[] = { 0, 0, 0 };
            exits[] = { "VTV_exit_1" };
            unloadingInterval = 3;
            loadingDistance = 10;
            loadingAngle = 60;
            parachuteClassDefault = "B_Parachute_02_F";
            parachuteHeightLimitDefault = 50;
        };
    };
};
class CUP_B_C130J_GB : GVAR(C130_Base) {
    scope = 2;
    editorPreview = "CUP\AirVehicles\CUP_AirVehicles_C130J\Data\preview\CUP_B_C130J_GB.jpg";
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617" };
    hiddenSelectionsTextures[] = {
        "CUP\AirVehicles\CUP_AirVehicles_C130J\data\textures\c130j_body_raf1_co.paa",
        "CUP\AirVehicles\CUP_AirVehicles_C130J\data\textures\c130j_wings_raf1_co.paa"
    };
};
class CUP_B_C130J_Cargo_GB : GVAR(C130_VIV_Base) {
    scope = 2;
    editorPreview = "CUP\AirVehicles\CUP_AirVehicles_C130J\Data\preview\CUP_B_C130J_Cargo_GB.jpg";
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617" };
    hiddenSelectionsTextures[] = {
        "CUP\AirVehicles\CUP_AirVehicles_C130J\data\textures\c130j_body_raf2_co.paa",
        "CUP\AirVehicles\CUP_AirVehicles_C130J\data\textures\c130j_wings_raf2_co.paa"
    };
};
