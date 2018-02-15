class CfgVehicles {
    class UKSF_Apache_base;
    class UKSF_Apache_AH1: UKSF_Apache_base {
        class AcreIntercoms {
            class Intercom_1 {
                displayName = "Crew intercom";
                shortName = "Crew";
                allowedPositions[] = {"driver", "copilot"};
                disabledPositions[] = {{"ffv", "all"}};
                limitedPositions[] = {};
                numLimitedPositions = 0;
                masterPositions[] = {"driver"};
                connectedByDefault = 1;
            };
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
        RACKS_GROUND
    };
    class CUP_Ridgback_Base: Wheeled_APC_F {
        RACKS_GROUND
    };
    class CUP_Wolfhound_Base: Wheeled_APC_F {
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
