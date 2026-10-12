#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "HAFM_Navy_Config",
            "HAFM_Navy_Core"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers_base;

class CfgVehicles {
    #include "CfgVehicles.hpp"
};

class CfgMagazines {
    #include "CfgMagazines.hpp"
};

class Extended_InitPost_EventHandlers {
    #include "Extended_InitPost_EventHandlers.hpp"
};
