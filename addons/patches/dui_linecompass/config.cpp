#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "diwako_dui_linecompass"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class Extended_PostInit_EventHandlers {
    class diwako_dui_linecompass {
        init = "if (hasInterface) then {call compileScript ['\z\diwako_dui\addons\linecompass\XEH_postInit.sqf']}";
    };
};
