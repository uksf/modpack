#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_compat_cup_weapons",
            "ace_compat_cup_weapons_missileguidance",
            "CUP_Weapons_Ammunition",
            "CUP_Weapons_East_Attachments",
            "CUP_Weapons_LoadOrder",
            "CUP_Weapons_SCAR"
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

class CfgMovesBasic {
    #include "CfgMovesBasic.hpp"
};

class CfgGesturesMale {
    #include "CfgGesturesMale.hpp"
};

class CfgAmmo {
    #include "CfgAmmo.hpp"
};
