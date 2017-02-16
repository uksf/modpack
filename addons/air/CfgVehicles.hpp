class CBA_Extended_EventHandlers;
class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F: Helicopter {
        class ACE_Actions;
        class Turrets;
    };
    class Helicopter_Base_H : Helicopter_Base_F {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class ViewPilot;
        class Turrets: Turrets {
            class CopilotTurret;
        };
    };
    
    #include "vehicles\CfgChinook.hpp"
    #include "vehicles\CfgMerlin.hpp"
    #include "vehicles\CfgWildcat.hpp"
};