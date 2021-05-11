#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            QGVAR(marker)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "uksf_radios"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "Cfg3den.hpp"
#include "CfgAmmo.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "RscCommon.hpp"
#include "RscDisplayMainMap.hpp"
