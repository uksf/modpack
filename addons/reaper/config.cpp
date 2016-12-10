#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_MQ9"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"uksf_main", "uksf_common", "uksf_mq9", "JSRSAPEX_UAV_2"};
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgRscUI.hpp"
#include "CfgVehicles.hpp"