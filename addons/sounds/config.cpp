#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main", 
            "uksf_common",
            "UK3CB_BAF_Weapons",
            "JPEX_FrameWork",
            "JSRSAPEX_ReloadingSoundsApex",
            "JSRSAPEX_Navid",
            "JSRSAPEX_Zafir"
        };
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"