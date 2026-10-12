#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "rksla3_aw159"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers_base;
class CfgMovesBasic;

class CfgVehicles {
    #include "CfgVehicles.hpp"
};

class CfgMovesMaleSdr : CfgMovesBasic {
    #include "CfgMovesMaleSdr.hpp"
};
