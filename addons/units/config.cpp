#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_B_Rifleman",
            "UKSF_B_Officer",
            "UKSF_B_SectionLeader",
            "UKSF_B_Medic",
            "UKSF_B_Sniper",
            "UKSF_B_SAS",
            "UKSF_B_Pilot",
            "UKSF_B_Pilot_7",
            "UKSF_B_Pilot_656",
            "UKSF_B_Pilot_617"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
