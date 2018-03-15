#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_air",
            "uksf_apache",
            "uksf_common",
            "uksf_lobby",
            "uksf_vehicles"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgChannels.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgSoundEffects.hpp"
#include "CfgVehicles.hpp"
