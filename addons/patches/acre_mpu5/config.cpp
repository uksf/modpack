#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "acre_sys_mpu5"
        };
        skipWhenMissingDependencies = 1;
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    class ACRE_BaseRadio;
    class ACRE_MPU5: ACRE_BaseRadio {
        ctab_devicetype = 2;
    };
};
