#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "CUP_AirVehicles_LoadOrder",
            "CUP_AirVehicles_C130J"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    delete CUP_B_C130J_GB;
    delete CUP_B_C130J_Cargo_GB;
};
