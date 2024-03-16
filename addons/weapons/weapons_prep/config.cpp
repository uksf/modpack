#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class UK3CB_MuzzleSlot_900;
class UK3CB_MuzzleSlot_900_L131 : UK3CB_MuzzleSlot_900 {
    delete compatibleItems;
};
