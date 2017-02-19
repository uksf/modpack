class CfgVehicles {
    class LandVehicle;
    class Car: LandVehicle {
        class ACE_Actions;
    };
    class Car_F: Car {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class Turrets;
    };
    class Wheeled_APC_F: Car_F {
        class NewTurret;
    };

    #include "vehicles\CfgJackal.hpp"
    #include "vehicles\CfgCoyote.hpp"
    #include "vehicles\CfgLandRover.hpp"
    #include "vehicles\CfgMastiff.hpp"
    #include "vehicles\CfgRidgeback.hpp"
    #include "vehicles\CfgWolfhound.hpp"
    #include "vehicles\CfgHemtt.hpp"
};