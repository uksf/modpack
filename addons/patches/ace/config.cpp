#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "ace_aircraft",
            "ace_cargo",
            "ace_compat_cup_vehicles",
            "ace_compat_cup_vehicles_fastroping",
            "ace_compat_cup_vehicles_refuel",
            "ace_compat_cup_vehicles_repair",
            "ace_compat_cup_vehicles_trenches",
            "ace_hot",
            "ace_hunterkiller",
            "ace_interaction",
            "ace_realisticnames",
            "ace_rearm",
            "ace_refuel",
            "ace_repair",
            "ace_vehicle_damage",
            "ace_vehicles"
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
