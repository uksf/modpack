#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T", "Bridgford.A" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
