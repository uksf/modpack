class CBA_Extended_EventHandlers;
class CfgVehicles {
    class LandVehicle;
    class Car: LandVehicle {
        class ACE_Actions;
    };
    class Car_F : Car {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
    };
    #include "vehicles\CfgLandRover.hpp"
    //#include "vehicles\CfgRidgeback.hpp"
    //#include "vehicles\CfgFoxhound.hpp"
    #include "vehicles\CfgJackal.hpp"
    #include "vehicles\CfgCoyote.hpp"
    #include "vehicles\CfgHemtt.hpp"
};