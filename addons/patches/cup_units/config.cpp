#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "CUP_Creatures_Military_Ukraine",
            "CUP_Dubbing_Radio_CZ_ACR_c",
            "CUP_Dubbing_Radio_CZ_c",
            "CUP_Dubbing_Radio_EN_BAF_c",
            "CUP_Dubbing_Radio_EN_c",
            "CUP_Dubbing_Radio_EN_PMC_c",
            "CUP_Dubbing_Radio_RU_c",
            "CUP_Dubbing_Radio_TK_c"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    #include "CfgVehicles.hpp"
};
