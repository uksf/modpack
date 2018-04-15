#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = { 
            "UKSF_ATC_Core", 
            "UKSF_ATC_Station"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
