#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "UK3CB_BAF_Vehicles_Coyote_Jackal",
            "UK3CB_BAF_Vehicles_Husky",
            "UK3CB_BAF_Vehicles_LandRover",
            "UK3CB_BAF_Vehicles_RHIB",
            "uksf_vehicles"
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
