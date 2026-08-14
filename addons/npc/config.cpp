#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "acre_sys_core"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class RscText;
class RscStructuredText;
class RscCombo;
class RscButton;
class RscControlsGroup;

#include "CfgEventHandlers.hpp"
#include "Cfg3den.hpp"
#include "CfgRscTitles.hpp"
#include "CfgNpcConsole.hpp"
