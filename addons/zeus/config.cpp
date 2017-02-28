#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "Ares_Module_Zeus_Visibility",
            "UKSF_Module_AddAllObjects",
            "UKSF_Module_LargeExplosion",
            "UKSF_Module_SmallExplosion",
            "UKSF_Module_TeleportZeus",
            "UKSF_Module_ToggleAllowUnconcious"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "achilles_modules_f_ares",
            "achilles_modules_f_achilles"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "Cfg3den.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
