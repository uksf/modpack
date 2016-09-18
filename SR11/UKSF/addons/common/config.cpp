#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"uksf_main"};
        author = CSTRING(UKSF);
        authors[] = {"Beswick.T"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG_COMMON;
    };
};



