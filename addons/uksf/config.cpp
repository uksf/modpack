#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_Clan_R",
            "UKSF_Clan_O",
            "UKSF_Clan_SL",
            "UKSF_Clan_MG",
            "UKSF_Clan_AT",
            "UKSF_Clan_MED",
            "UKSF_Clan_Sniper",
            "UKSF_Clan_P",

            /*"UKSF_LandRover_Unarmed",
            "UKSF_LandRover_MG",
            "UKSF_LandRover_MG_Desert",
            "UKSF_LandRover_GL",
            "UKSF_LandRover_GL_Desert",
            "UKSF_LandRover_Medical",
            "UKSF_ridgback_HMG_D",
            "UKSF_ridgback_HMG_W",
            "UKSF_ridgback_AMB_D",
            "UKSF_ridgback_AMB_W",
            "burnes_foxhound",
            "burnes_foxhound_w",
            "burnes_foxhound_d_a",
            "burnes_foxhound_w_a",
            "UKSF_Jackal_HMG_D",
            "UKSF_Jackal_HMG_W",
            "UKSF_Jackal_GMG_D",
            "UKSF_Jackal_GMG_W",
            "UKSF_Coyote_Passenger_HMG_D",
            "UKSF_Coyote_Passenger_HMG_W",
            "UKSF_Coyote_Passenger_GMG_D",
            "UKSF_Coyote_Passenger_GMG_W",
            "UKSF_Coyote_Logistics_HMG_D",
            "UKSF_Coyote_Logistics_HMG_W",
            "UKSF_Coyote_Logistics_GMG_D",
            "UKSF_Coyote_Logistics_GMG_W",*/
            "UKSF_Hemtt_Ammo",
            "UKSF_Hemtt_Fuel",
            "UKSF_Hemtt_Repair"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main", 
            "uksf_common",
            "uksf_gear"
            //"uksf_genfor",
            //"blx_ridgback",
            //"burnes_foxhound",
            //"UK3CB_BAF_Vehicles",
            //"UK3CB_BAF_Vehicles_Coyote_Jackal"
        };
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
