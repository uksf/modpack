class CUP_CH47F_base: Helicopter_Base_H {
    maxSpeed = 315;
    cyclicAsideForceCoef = 1;
    cyclicForwardForceCoef = 1;
    fuelCapacity = 40; // 500
    armor = 60;
    memoryPointsGetInDriver = "pos cargo";
    memoryPointsGetInDriverDir = "pos cargo dir";
    driverCanEject = 1;
    class ViewPilot: ViewPilot {
        minFov = 0.25;
        maxFov = 1.25;
        initFov = 0.95;
    };
    class Turrets: Turrets {
        class CopilotTurret: CopilotTurret {
            memoryPointsGetInGunner = "pos cargo";
            memoryPointsGetInGunnerDir = "pos cargo dir";
            CanEject = 1;
            showHMD = 1;
            class Components {
                class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
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
                class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
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
        class MainTurret: MainTurret {
            soundAttenuationTurret = "HeliAttenuationGunner";
        };
        class RightDoorGun: MainTurret {
            soundAttenuationTurret = "HeliAttenuationGunner";
        };
        class BackDoorGun: MainTurret {
            soundAttenuationTurret = "HeliAttenuationGunner";
        };
    };
    attenuationEffectType = "SemiOpenHeliAttenuation";
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
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
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
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
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
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
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class DataLinkSensorComponent: SensorTemplateDataLink {};
            };
        };
    };
    #include "MFDGeneral.hpp"
};
class CUP_B_CH47F_GB: CUP_CH47F_base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7","UKSF_B_Pilot_7","UKSF_B_Pilot_7" };
};
class CUP_CH47F_VIV_Base;
class CUP_B_CH47F_VIV_GB: CUP_CH47F_VIV_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7","UKSF_B_Pilot_7","UKSF_B_Pilot_7" };
};
