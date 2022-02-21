#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            QGVAR(airSupply)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_diving",
            "mas_usa_lite_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridg" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgSounds.hpp"
#include "CfgWeapons.hpp"
