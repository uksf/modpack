#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"uksf_main"};
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG_COMMON;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgImprecision.hpp"
#include "CfgVehicles.hpp"