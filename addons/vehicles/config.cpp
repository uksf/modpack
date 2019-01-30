#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "Land_CanisterFuel_F",
            "CargoNet_01_barrels_F"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_units",
            "CUP_WheeledVehicles_LR",
            "CUP_WheeledVehicles_Coyote",
            "CUP_WheeledVehicles_Jackal",
            "CUP_WheeledVehicles_Mastiff",
            "CUP_WheeledVehicles_Ridgeback",
            "CUP_WheeledVehicles_Wolfhound",
            "UK3CB_BAF_Vehicles_Coyote_Jackal",
            "UK3CB_BAF_Vehicles_LandRover"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
