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
            "3denEnhanced"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG_COMMON;
    };
};

class cba_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "Cfg3den.hpp"
#include "CfgEditorCategories.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgImprecision.hpp"
#include "CfgMarkerColors.hpp"
#include "CfgVehicles.hpp"

enableDebugConsole[] = { "76561198041153310" };
