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
        authors[] = { "Bridg" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgDisplay.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgSounds.hpp"
