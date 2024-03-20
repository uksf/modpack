#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "uksf_resupply",
            "uksf_diving",
            "uksf_air_atc"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "Cfg3den.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgLoadouts.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "ui\RscAttributes.hpp"
#include "ui\RscDisplayMain.hpp"
