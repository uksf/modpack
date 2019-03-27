#include "script_component.hpp"

class CfgPatches {
    class PROP {
        name = COMPONENT_NAME;
        units[] = {
            // Units
            "PROR_R",
			"PROR_MG",
			"PROR_AR",
			"PROR_AT_L",
			"PROR_Officer",
			"PROR_FOO",
			"PROR_JTAC",
			"PROR_Marksman",
			"PROR_Medic",
			"PROR_SL",
			"PROR_AT_H",

            // Vehicles
            "PROR_VAB_Unarmed"
        };
        weapons[] = {
            "arifle_CTAR_blk_F_Eotech"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
//#include "CfgAmmo.hpp"
//#include "CfgEventHandlers.hpp"
#include "CfgGroups.hpp"
//#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
