#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(moduleCleanupExclude),
            QGVAR(moduleCleanupInclude)
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

#include "UKSF_Settings.hpp"
#include "CfgEventHandlers.hpp"
#include "Cfg3den.hpp"
#include "CfgVehicles.hpp"
