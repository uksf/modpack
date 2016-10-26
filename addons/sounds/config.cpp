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
            "JSRSAPEX_Zafir",
            "JSRSAPEX_AK12",
            "JSRSAPEX_AKM",
            "JSRSAPEX_SPMG"
        };
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgSoundSets.hpp"
#include "CfgSoundShaders.hpp"