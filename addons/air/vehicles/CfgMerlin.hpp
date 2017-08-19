class CUP_Merlin_HC3_Base: Helicopter_Base_H {
    maxspeed = 311;
    fuelCapacity = 40; // 1000
    cyclicAsideForceCoef = 0.8;
    cyclicForwardForceCoef = 0.8;
    class ViewPilot: ViewPilot {
        minFov = 0.25;
        maxFov = 1.25;
        initFov = 0.95;
    };
    driverCanEject = 1;
    landingSoundInt0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int1", 0.25, 1, 50 };
    landingSoundInt1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int2", 0.25, 1, 50 };
    landingSoundInt[] = { "landingSoundInt0", 0.5, "landingSoundInt1", 0.5 };
    landingSoundOut0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1", 0.4, 1, 50 };
    landingSoundOut1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2", 0.4, 1, 50 };
    landingSoundOut[] = { "landingSoundOut0", 0.5, "landingSoundOut1", 0.5 };
    class Sounds {
        class EngineExt {
            sound[] = { "A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_engine", 1.5, 1, 1500 };
            frequency = "rotorSpeed";
            volume = "camPos*(rotorSpeed-0.72)*4";
        };
        class RotorExt {
            sound[] = { "A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_rotor", 2, 1, 2500 };
            frequency = "rotorSpeed * rotorSpeed * (1 - rotorThrust/6)";
            volume = "camPos*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
            cone[] = { 1.6, 3.14, 1.6, 0.95 };
        };
        class RotorNoiseExt {
            sound[] = { "A3\Sounds_F\vehicles\air\Heli_Transport_02\rotor_swist", 1, 1, 1000 };
            frequency = 1;
            volume = "camPos * (rotorThrust factor [0.7, 0.9])";
            cone[] = { 0.7, 1.3, 1, 0 };
        };
        class EngineInt {
            sound[] = { "A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_engine", 1, 1 };
            frequency = "rotorSpeed";
            volume = "(1-camPos)*(rotorSpeed-0.75)*4";
        };
        class RotorInt {
            sound[] = { "A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_rotor", 1.5, 1 };
            frequency = "rotorSpeed * rotorSpeed * (1 - rotorThrust/6)";
            volume = "(1-camPos)*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
        };
    };
    attenuationEffectType = "SemiOpenHeliAttenuation";
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
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
    #include "MFDMerlin.hpp"
    class ACE_Actions: ACE_Actions {
        class ACE_MainActions: ACE_MainActions {
            position = "[0,0,1.5]";
        };
    };
    class EventHandlers: EventHandlers {
        init = "if (local (_this select 0)) then {[(_this select 0), """""""", [], false] call bis_fnc_initVehicle;};";
        getIn = "";
    };
};
class CUP_Merlin_HC3A_Base: CUP_Merlin_HC3_Base {};
class CUP_Merlin_HC3_VIV_Base: CUP_Merlin_HC3_Base {};
class CUP_Merlin_HC3_Armed_Base: CUP_Merlin_HC3_Base {};
class CUP_Merlin_HC3A_Armed_Base: CUP_Merlin_HC3_Base {};
class CUP_Merlin_HM2_Base: CUP_Merlin_HC3_Base {};
class CUP_B_Merlin_HC3_GB: CUP_Merlin_HC3_Base {
    scope = 2;
    scopeCurator = 2;
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7","UKSF_B_Pilot_7" };
};
class CUP_B_Merlin_HC3_VIV_GB: CUP_Merlin_HC3_VIV_Base {
    scope = 2;
    scopeCurator = 2;
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7","UKSF_B_Pilot_7" };
};
class CUP_B_Merlin_HC3A_GB: CUP_Merlin_HC3A_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_Merlin_HC3_Armed_GB: CUP_Merlin_HC3_Armed_Base {
    scope = 2;
    scopeCurator = 2;
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7","UKSF_B_Pilot_7" };
};
class CUP_B_Merlin_HC3A_Armed_GB: CUP_Merlin_HC3A_Armed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_Merlin_HC4_GB: CUP_Merlin_HM2_Base {
    scope = 1;
    scopeCurator = 0;
};
