#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_Hemtt_Ammo",
            "UKSF_Hemtt_Fuel",
            "UKSF_Hemtt_Repair"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {             
            "uksf_common",
            "uksf_gear",
            "uksf_units",
            "CUP_WheeledVehicles_LR",
            "CUP_WheeledVehicles_Coyote",
            "CUP_WheeledVehicles_Jackal",
            "CUP_WheeledVehicles_Mastiff",
            "CUP_WheeledVehicles_Ridgeback",
            "CUP_WheeledVehicles_Wolfhound"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class cba_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
