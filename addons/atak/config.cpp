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
            "comspec_atak_native_main",
            "comspec_overwatch_main",
            "comspec_overwatch_connect",
            "zen_context_menu"
        };
        skipWhenMissingDependencies = 1;
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        clientInit = QUOTE(call COMPILE_FILE(XEH_postInitClient));
    };
};

#include "CfgComspec.hpp"
#include "CfgEnglish.hpp"
#include "CfgWeapons.hpp"
