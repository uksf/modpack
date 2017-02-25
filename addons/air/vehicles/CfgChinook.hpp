class CUP_CH47F_base: Helicopter_Base_H {
    maxSpeed = 315;
    cyclicAsideForceCoef = 0.9;
    cyclicForwardForceCoef = 0.9;
    armor = 60;
    memoryPointsGetInDriver = "pos cargo";
    memoryPointsGetInDriverDir = "pos cargo dir";
    class ViewPilot: ViewPilot {
        minFov = 0.25;
        maxFov = 1.25;
        initFov = 0.95;
    };
    class Turrets: Turrets {
        class CopilotTurret: CopilotTurret {
            memoryPointsGetInGunner = "pos cargo";
            memoryPointsGetInGunnerDir = "pos cargo dir";
        };
    };
    unitInfoType = "Rsc_UKSF_Air_Limited";
    unitInfoTypeLite = "Rsc_UKSF_Air_Limited";
    class Sounds {
        class Engine {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_engine_high_ext", 2, 1.0, 1000 };
            frequency = "rotorSpeed";
            volume = "camPos*((rotorSpeed-0.72)*4)";
        };
        class RotorLowOut {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_ext", 4, 1.0, 2000 };
            frequency = "rotorSpeed";
            volume = "camPos*(0 max (rotorSpeed-0.1))";
            cone[] = { 1.8, 3.14, 2.0, 0.9 };
        };
        class RotorHighOut {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_forsage_ext", 4, 1.0, 2500 };
            frequency = "rotorSpeed";
            volume = "camPos*10*(0 max (rotorThrust-0.95))";
            cone[] = { 1.8, 3.14, 2.0, 0.9 };
        };
        class EngineIn {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_engine_high_int", 2, 1.0 };
            frequency = "rotorSpeed";
            volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
        };
        class RotorLowIn {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_int", 2, 1.0 };
            frequency = "rotorSpeed";
            volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
        };
        class RotorHighIn {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_forsage_int", 2, 1.0 };
            frequency = "rotorSpeed";
            volume = "(1-camPos)*3*(rotorThrust-0.9)";
        };
    };
    #include "MFDGeneral.hpp"
};
class CUP_B_CH47F_GB: CUP_CH47F_base {
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617","UKSF_B_Pilot_7","UKSF_B_Pilot_7" };
};
class CUP_CH47F_VIV_Base;
class CUP_B_CH47F_VIV_GB: CUP_CH47F_VIV_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7","UKSF_B_Pilot_7","UKSF_B_Pilot_7" };
};
