#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "UK3CB_BAF_Weapons_Accessories",
            "UK3CB_BAF_Weapons_L110",
            "UK3CB_BAF_Weapons_L115",
            "UK3CB_BAF_Weapons_L7"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    #include "CfgWeapons.hpp"
};

class CfgGesturesMale {
    #include "CfgGesturesMale.hpp"
};
