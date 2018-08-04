#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSFModuleRespawnPosition_F"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_3rdperson",
            "3denEnhanced",
            "cba_ui",
            "cfp_o_syarmy"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG_COMMON;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "Cfg3den.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgImprecision.hpp"
#include "CfgMarkerColors.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"

enableDebugConsole[] = { WHITELIST_NOARRAY };
EnableTargetDebug = 1;

class CfgVideoOptions {
    class PiP {
        class Disabled {
            text = "Disabled";
            value = 0;
        };
        class VeryLow {
            text = "Low";
            value = 500;
        };
        class Low {
            text = "Standard";
            value = 800;
        };
        class Normal {
            text = "High";
            value = 1000;
        };
        class High {
            text = "Very High";
            value = 1500;
        };
        class VeryHigh {
            text = "Ultra";
            value = 2000;
        };
        class VeryUltra {
            text = "Very Ultra";
            value = 3000;
        };
        class Extreme {
            text = "Extreme";
            value = 6000;
        };
        class Crazy {
            text = "Crazy";
            value = 10000;
        };
        class YTho {
            text = "Y Tho";
            value = 12000;
        };
    };
};
