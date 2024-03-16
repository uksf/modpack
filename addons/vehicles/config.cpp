#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "Land_CanisterFuel_F",
            "CargoNet_01_barrels_F",
            "UK3CB_BAF_MAN_HX58_Rearm_Green",
            "UK3CB_BAF_MAN_HX58_Rearm_Sand",
            "UK3CB_BAF_MAN_HX60_Rearm_Green",
            "UK3CB_BAF_MAN_HX60_Rearm_Sand",
            QGVAR(rhicc_green),
            QGVAR(rhicc_grey)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_units",
            "CUP_Vehicles_LoadOrder",
            "CUP_WheeledVehicles_LoadOrder",
            "CUP_WheeledVehicles_LR",
            "CUP_WheeledVehicles_Coyote",
            "CUP_WheeledVehicles_Jackal",
            "CUP_TrackedVehicles_Bulldog",
            "CUP_TrackedVehicles_FV510",
            "CUP_TrackedVehicles_MCV80",
            "UK3CB_BAF_Vehicles_LoadOrder",
            "UK3CB_BAF_Vehicles_LandRover",
            "UK3CB_BAF_Vehicles_Coyote_Jackal",
            "UK3CB_BAF_Vehicles_MAN",
            "UK3CB_BAF_Vehicles_Husky",
            "UK3CB_BAF_Vehicles_Panther",
            "UK3CB_BAF_Vehicles_RHIB",
            "UK3CB_BAF_Vehicles_Warrior_a3",
            "UK3CB_BAF_Vehicles_Weapons",
            "rksla3_aircraft_tug",
            "RHICC",
            QGVAR(prep)
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
