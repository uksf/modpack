#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_Hemtt_Ammo",
            "UKSF_Hemtt_Fuel",
            "UKSF_Hemtt_Repair",
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
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class cba_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
