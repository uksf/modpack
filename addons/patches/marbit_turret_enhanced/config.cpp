#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "UAV_Turret_Markers"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class Extended_Init_EventHandlers {
    class air;
    class plane: air {
        class Fat_Lurch_plane_eh {
            init = "if (hasInterface) then {(_this select 0) spawn fatLurch_fnc_MPaddaction}";
        };
    };
    class Helicopter: air {
        class Fat_Lurch_Helicopter_eh {
            init = "if (hasInterface) then {(_this select 0) spawn fatLurch_fnc_MPaddaction}";
        };
    };
};
