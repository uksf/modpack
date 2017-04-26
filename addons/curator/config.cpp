#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "ModuleCuratorLocal"
        };
        weapons[] = {};
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

#include "ACE_Settings.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
