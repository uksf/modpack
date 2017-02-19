class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F: Helicopter {
        class ACE_Actions;
        class Turrets;
    };
    class Helicopter_Base_H: Helicopter_Base_F {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class ViewPilot;
        class Turrets: Turrets {
            class CopilotTurret;
        };
    };
    class Plane_Base_F;
    
    #include "vehicles\CfgChinook.hpp"
    #include "vehicles\CfgMerlin.hpp"
    #include "vehicles\CfgWildcat.hpp"
    #include "vehicles\CfgC130.hpp"
};