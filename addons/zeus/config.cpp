#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_Module_SmallExplosion",
            "UKSF_Module_LargeExplosion",
            "UKSF_Module_AddAllObjects",
            "Ares_Module_Zeus_Visibility",
            "UKSF_Module_TeleportZeus"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "achilles_modules_f_ares"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
