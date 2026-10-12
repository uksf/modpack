#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_acr",
            "uksf_aug",
            "uksf_cartel",
            "uksf_cdf",
            "uksf_common",
            "uksf_eug",
            "uksf_inegal",
            "uksf_radios",
            "uksf_saf",
            "uksf_vaf",
            "uksf_vehicles",
            "uksf_zgf"
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
