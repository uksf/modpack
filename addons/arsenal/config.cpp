#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_arsenal",
            "uksf_common",
            "uksf_gear"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
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
