#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = { "ItemcTab", "ItemAndroid", "ItemMicroDAGR", "ItemcTabHCam" };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "acre_sys_mpu5",
            "comspec_atak_native_main"
        };
        skipWhenMissingDependencies = 1;
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        clientInit = QUOTE(call COMPILE_FILE(XEH_postInitClient));
    };
};

#include "CfgWeapons.hpp"
