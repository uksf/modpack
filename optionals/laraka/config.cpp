#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "Laraka_L",
            "Laraka_AK",
            "Laraka_PKM",
            "Laraka_PKP",
            "Laraka_RPG",
            "Laraka_SVD",
            "Laraka_Warlord",
            "Laraka_Special_HVT",
            "Laraka_Special_Suicide",
            "Laraka_Special_SuicideDeadman",
            "Laraka_Special_SuicideDiscrete",
            "Laraka_Special_SuicideDiscreteDeadman",
            "Azaadi_L",
            "Azaadi_AK",
            "Azaadi_PKM",
            "Azaadi_PKP",
            "Azaadi_RPG",
            "Azaadi_SVD",
            "Azaadi_Warlord",
            "Azaadi_Special_HVT",
            "Azaadi_Special_Suicide",
            "Azaadi_Special_SuicideDeadman",
            "Azaadi_Special_SuicideDiscrete",
            "Azaadi_Special_SuicideDiscreteDeadman",
            
            "Tban_O_Offroad_01_F",
            "Laraka_Hilux_Unarmed",
            "Laraka_Hilux_Unarmed_Populated",
            "Laraka_Hilux_DSHKM",
            "Laraka_Uaz_DSHKM",
            "Laraka_Uaz_Unarmed",
            "Laraka_Uaz_Unarmed_Populated",
            "Laraka_Static_ZU23",
            "Laraka_Static_DSHKM",
            "Laraka_Static_KORD",
            "Laraka_Static_TOW",
            "Laraka_Static_SPG9",
            "Laraka_Static_Igla",
            "Laraka_Static_2B14",
            "Laraka_CarBomb",
            "Laraka_CarBomb_Empty",
            "Laraka_CarBomb_Deadman",
            "Azaadi_Hilux_Unarmed",
            "Azaadi_Hilux_Unarmed_Populated",
            "Azaadi_Hilux_DSHKM",
            "Azaadi_Uaz_DSHKM",
            "Azaadi_Uaz_Unarmed",
            "Azaadi_Uaz_Unarmed_Populated",
            "Azaadi_Static_ZU23",
            "Azaadi_Static_DSHKM",
            "Azaadi_Static_KORD",
            "Azaadi_Static_TOW",
            "Azaadi_Static_SPG9",
            "Azaadi_Static_Igla",
            "Azaadi_Static_2B14",
            "Azaadi_CarBomb",
            "Azaadi_CarBomb_Empty",
            "Azaadi_CarBomb_Deadman",     

            "Laraka_B_PKM",
            "Laraka_B_RPG",
            "Laraka_B_AA"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main", 
            "uksf_common",
            "uksf_genfor",
            "Taliban_fighters"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"