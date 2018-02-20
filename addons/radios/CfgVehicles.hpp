class CfgVehicles {
    class Helicopter_Base_F;
    class Heli_Attack_01_base_F: Helicopter_Base_F {
        class Turrets;
    };
    class UKSF_Apache_base: Heli_Attack_01_base_F {
        class Turrets: Turrets {
            class MainTurret;
        };
        class CargoTurret;
    };
    class UKSF_Apache_AH1: UKSF_Apache_base {
        class AcreIntercoms {
            class Intercom_1 {
                displayName = "Crew intercom";
                shortName = "Crew";
                allowedPositions[] = {"crew"};
                disabledPositions[] = {{"ffv", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                masterPositions[] = {"driver"};
                connectedByDefault = 1;
            };
        };
        class ACRE {
            class attenuation {
                class Compartment1 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
                class Compartment2 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
                class Compartment3 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
                class Compartment4 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
            };
        };
        attenuationEffectType = "ThickGlassAttenuation";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                soundAttenuationTurret = "ThickGlassAttenuation";                
            };
            class CargoTurret_01: CargoTurret {
                disableSoundAttenuation = 1;
            };
            class CargoTurret_02: CargoTurret_01 {};
        };
        RACKS_AIR
    };
    class Plane_Base_F;
    class CUP_C130J_Base: Plane_Base_F {
        INTERCOM_AIR
        RACKS_AIR
    };
    class B_Plane_Fighter_01_F;
    class USAF_F35A: B_Plane_Fighter_01_F {
        RACKS_AIR
    };
    class Helicopter_Base_H;
    class CUP_CH47F_base: Helicopter_Base_H {
        INTERCOM_AIR
        RACKS_AIR
    };
    class Heli_Transport_02_base_F;
    class UK3CB_BAF_Merlin_Base: Heli_Transport_02_base_F {
        INTERCOM_AIR
        RACKS_AIR
    };
    class Heli_light_03_base_F;
    class UK3CB_BAF_Wildcat_Base: Heli_light_03_base_F {
        INTERCOM_AIR
        RACKS_AIR
    };
    class Car_F;
    class UK3CB_BAF_Jackal_Base_D: Car_F {
        RACKS_GROUND
    };
    class UK3CB_BAF_LandRover_Base: Car_F {
        RACKS_GROUND
    };
    class Wheeled_APC_F;
    class CUP_Mastiff_Base: Wheeled_APC_F {
        INTERCOM_GROUND
        RACKS_GROUND
    };
    class CUP_Ridgback_Base: Wheeled_APC_F {
        INTERCOM_GROUND
        RACKS_GROUND
    };
    class CUP_Wolfhound_Base: Wheeled_APC_F {
        INTERCOM_GROUND
        RACKS_GROUND
    };
    class B_Truck_01_ammo_F;
    class UKSF_Hemtt_Ammo: B_Truck_01_ammo_F {
        RACKS_AIR_GROUND
    };
    class B_Truck_01_fuel_F;
    class UKSF_Hemtt_Fuel: B_Truck_01_fuel_F {
        RACKS_AIR_GROUND
    };
    class B_Truck_01_Repair_F;
    class UKSF_Hemtt_Repair: B_Truck_01_Repair_F {
        RACKS_AIR_GROUND
    };
};
