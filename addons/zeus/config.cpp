#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(moduleAddAllObjects),
            QGVAR(moduleExplosionLarge),
            QGVAR(moduleExplosionSmall),
            QGVAR(moduleLoadoutCopy),
            QGVAR(moduleLoadoutPaste),
            QGVAR(moduleSetEngineer),
            QGVAR(moduleTeleportZeus),
            QGVAR(moduleToggleAllowUnconcious)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "achilles_functions_f_achilles",
            "achilles_ui_f",
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
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
#include "RscDisplayCurator.hpp"
